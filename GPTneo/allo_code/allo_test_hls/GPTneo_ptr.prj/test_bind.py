# Copyright Allo authors. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

import numpy as np
import allo
from allo.ir.types import float32
import pytest



"Have a large extend to optimize!!!"
def mask_softmax_per_head_np(x_h, actual_length, fix_length): #apply identical casual and attention mask here
    "Apply identical casual and attention mask here"

    "x_h shape is [fix_length, fix_length], no head dimension"

    x_new = np.zeros((fix_length,fix_length), dtype=np.float32)
    store_x_exp = np.zeros((fix_length,fix_length), dtype=np.float32)
    x_new_row_sum = np.zeros(fix_length, dtype=np.float32)
    x_new_row_max = np.array([-10000000000000000.0] * fix_length, dtype=np.float32) #large enough

    "find max value in meaningful tows"
    for i in range(fix_length):
        for j in range(fix_length):
            if i >= j:
                if i >= fix_length - actual_length: 
                    if j >= fix_length - actual_length: #the right bottom corner
                        x_new_row_max[i] = max(x_new_row_max[i], x_h[i,j])


    "sum"
    for i in range(fix_length):
        for j in range(fix_length):
            if i >= j:
                if i >= fix_length - actual_length: 
                    if j >= fix_length - actual_length: #the right bottom corner
                        store_x_exp[i,j] = np.exp(x_h[i,j] - x_new_row_max[i])
                        x_new_row_sum[i] += store_x_exp[i,j]
                        
                    else:
                        pass # zero
                else:
                    x_new[i,j] = 1 / (i+1+actual_length)
            else:
                if i < fix_length - actual_length and j >= fix_length - actual_length:
                    x_new[i,j] = 1 / (i+1+actual_length)
                else:
                    pass # zero

    
    "update"
    for i in range(fix_length):
        for j in range(fix_length):
            if i >= j:
                if i >= fix_length - actual_length: 
                    if j >= fix_length - actual_length: #the right bottom corner
                        x_new[i,j] = store_x_exp[i,j] / x_new_row_sum[i]
    x = x_new          
    return x


def np_layernorm(inp, gamma, beta):
    mean = inp.mean(axis=1)
    mean2 = (inp**2).mean(axis=1)
    var = mean2 - mean**2
    np_out = gamma * (inp - mean[:, None]) / np.sqrt(var[:, None] + 1e-5) + beta
    return np_out


def causal_sdp(Q, K, V, H, D, L, actual_length):
    "L is the fix length"
    context = np.zeros(Q.shape)
    h_d = D // H
    for i in range(H):
        # split Q, K, V
        Q_h = Q[:, i * h_d : (i + 1) * h_d]
        K_h = K[:, i * h_d : (i + 1) * h_d]
        V_h = V[:, i * h_d : (i + 1) * h_d]
        # compute attention
        attention = np.matmul(Q_h, K_h.T)
        # # don't scale in GPTneo
        # attention = attention / np.sqrt(D // H)
        Y = mask_softmax_per_head_np(attention, actual_length, L)
        context_i = np.matmul(Y, V_h)
        context[:, i * h_d : (i + 1) * h_d] = context_i
    return context


def gelu(x):
    return 0.5 * x * (1 + np.tanh(0.797885 * (x + 0.044715 * x**3)))


import allo
import numpy as np
def test_pybind11():
    H, L, D, Dffn = 12, 64, 768, 3024
    M0, M1 = 8, 8
    Ty = float32

    mod = allo.IPModule(
        top="GPTNEOLayer",
        headers=["kernel.h"],
        impls=["kernel.cpp"],
        signature=[ "float32[49152]",
                    "float32[768]",
                    "float32[768]",
                    "float32[589824]",
                    "float32[589824]",
                    "float32[589824]",
                    "float32[589824]",
                    "float32[768]",
                    "float32[768]",
                    "float32[768]",
                    "float32[2322432]",
                    "float32[3024]",
                    "float32[2322432]",
                    "float32[768]",
                    "int32[2]",
                    "float32[49152]"],
        link_hls="/work/zhang-capra/users/ky427/allo/GPTneo/allo_code/allo_test_hls/GPTneo_ptr.prj",
    )
    "generate input"
    X = np.random.randn(L, D).astype(np.float32)
    ln1_weight = np.random.randn(D).astype(np.float32)
    ln1_bias = np.random.randn(D).astype(np.float32)
    q_proj_weight = np.random.randn(D, D).astype(np.float32)
    k_proj_weight = np.random.randn(D, D).astype(np.float32)
    v_proj_weight = np.random.randn(D, D).astype(np.float32)
    out_proj_weight = np.random.randn(D, D).astype(np.float32)
    out_proj_bias = np.random.randn(D).astype(np.float32)
    ln2_weight = np.random.randn(D).astype(np.float32)
    ln2_bias = np.random.randn(D).astype(np.float32)
    mlp_fc_weight = np.random.randn(D, Dffn).astype(np.float32)
    mlp_fc_bias = np.random.randn(Dffn).astype(np.float32)
    mlp_proj_weight = np.random.randn(Dffn, D).astype(np.float32)
    mlp_proj_bias = np.random.randn(D).astype(np.float32)
    actual_length = np.array([12,12],dtype=np.int32) #fake

    def GPTNeo_layer(X, ln1_weight, ln1_bias, q_proj_weight, k_proj_weight, v_proj_weight, 
                     out_proj_weight, out_proj_bias,ln2_weight, ln2_bias, mlp_fc_weight, mlp_fc_bias, 
                     mlp_proj_weight, mlp_proj_bias, H, D, L, actual_length):
        "x shape is [max_seq_len, hidden_size]"

        X_ln1 = np_layernorm(X, ln1_weight, ln1_bias)
        
        Q = np.matmul(X_ln1, q_proj_weight)
        K = np.matmul(X_ln1, k_proj_weight)
        V = np.matmul(X_ln1, v_proj_weight)
        # breakpoint()

        attn = causal_sdp(Q, K, V, H, D, L, actual_length)
        
        attn = np.matmul(attn, out_proj_weight) + out_proj_bias
        # residual
        X = X + attn

        x_ln2 = np_layernorm(X, ln2_weight, ln2_bias)
        mlp_output = np.matmul(x_ln2, mlp_fc_weight) + mlp_fc_bias
        mlp_output = gelu(mlp_output)  # GELU 
        mlp_output = np.matmul(mlp_output, mlp_proj_weight) + mlp_proj_bias

        X = X + mlp_output
        return X

    np_out = GPTNeo_layer(
        X, ln1_weight, ln1_bias, q_proj_weight, k_proj_weight, v_proj_weight, 
        out_proj_weight, out_proj_bias,ln2_weight, ln2_bias, mlp_fc_weight, mlp_fc_bias, 
        mlp_proj_weight, mlp_proj_bias, H, D, L, actual_length[0]
    )

    X=X.view('float32').reshape(49152)
    ln1_weight=ln1_weight.view('float32').reshape(768)
    ln1_bias=ln1_bias.view('float32').reshape(768)
    q_proj_weight=q_proj_weight.view('float32').reshape(589824)
    k_proj_weight=k_proj_weight.view('float32').reshape(589824)
    v_proj_weight=v_proj_weight.view('float32').reshape(589824)
    out_proj_weight=out_proj_weight.view('float32').reshape(589824)
    out_proj_bias=out_proj_bias.view('float32').reshape(768)
    ln2_weight=ln2_weight.view('float32').reshape(768)
    ln2_bias=ln2_bias.view('float32').reshape(768)
    mlp_fc_weight=mlp_fc_weight.view('float32').reshape(2322432)
    mlp_fc_bias=mlp_fc_bias.view('float32').reshape(3024)
    mlp_proj_weight=mlp_proj_weight.view('float32').reshape(2322432)
    mlp_proj_bias=mlp_proj_bias.view('float32').reshape(768)
    actual_length=actual_length.view('int32').reshape(2)
    csim_C = np.zeros(49152, dtype=np.float32)
    breakpoint()
    mod(
        X,
        ln1_weight,
        ln1_bias,
        q_proj_weight,
        k_proj_weight,
        v_proj_weight,
        out_proj_weight,
        out_proj_bias,
        ln2_weight,
        ln2_bias,
        mlp_fc_weight,
        mlp_fc_bias,
        mlp_proj_weight,
        mlp_proj_bias,
        actual_length,
        csim_C
    )
    breakpoint()
    csim_C = csim_C.reshape(64,96)
    breakpoint()
    np.testing.assert_allclose(csim_C, np_out, atol=1e-2)
    print("Passed!")





if __name__ == "__main__":
    test_pybind11()