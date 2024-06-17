# Copyright Allo authors. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

import numpy as np
import allo
from allo.ir.types import float32
import pytest


"pass"
def test_linear_float():
    from allo.library.systolic import systolic

    # L, D = 512, 768
    # M0, M1 = 16, 16
    L, D = 8, 8
    M0, M1 = 2, 2
    W_A = np.random.randn(D, 4 * D).astype(np.float32)
    allo_C = np.zeros((L, 4 * D), dtype=np.float32)

    s = allo.customize(
        systolic, instantiate=[float32, float32, float32, L, D, 4 * D, M0, M1]
    )
    # CPU testing
    # mod = s.build()
    mod = s.build(target="vitis_hls",mode="csim", project="bert_linear_float.prj")
    X = np.random.randn(L, D).astype(np.float32)
    mod(X, W_A, allo_C)
    np_C = X @ W_A
    np.testing.assert_allclose(allo_C, np_C, atol=1e-3)
    print("Passed!")
    # print(s.build(target="vhls"))
    breakpoint()


"Have a large extend to optimize!!!"
def mask_softmax_per_head_np(x_h, actual_length, fix_length): #apply identical casual and attention mask here
    "Apply identical casual and attention mask here"

    "x_h shape is [fix_length, fix_length], no head dimension"

    x_new = np.zeros((fix_length,fix_length), dtype=np.float32)
    store_x_exp = np.zeros((fix_length,fix_length), dtype=np.float32)
    x_new_row_sum = np.zeros(fix_length, dtype=np.float32)
    x_new_row_max = np.array([-10000] * fix_length, dtype=np.float32) #large enough

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

"passed!"
def test_mask_softmax_per_head():
    from allo.library.nn import mask_softmax_per_head
    L=64
    s = allo.customize(mask_softmax_per_head, instantiate=[float32, L])
    mod = s.build()
    inp = np.random.randn(L, L).astype(np.float32)
    actual_length = np.array([12,12],dtype=np.int32) #fake 
    allo_out = mod(inp, actual_length)
    np_out = mask_softmax_per_head_np(inp, 12, L)
    np.testing.assert_allclose(allo_out, np_out, atol=1e-3)
    print("allo Passed!")
    s.compose(mask_softmax_per_head, instantiate=[float32, L])
    hls_mod = s.build(target="vitis_hls",mode="csim", project="mask_softmax_per_head.prj")
    csim_C = np.zeros((L , L), dtype=np.float32)
    hls_mod(inp,actual_length,csim_C)
    np.testing.assert_allclose(np_out, csim_C, atol=1e-3)
    print("Csim Passed!")

"passed!"
def test_bias_add():
    from allo.library.nn import bias_add
    L, D = 64, 768
    s = allo.customize(bias_add, instantiate=[float32, L, D])
    mod = s.build()
    inp = np.random.randn(L, D).astype(np.float32)
    bias = np.random.randn(D).astype(np.float32)
    allo_out = mod(inp, bias)
    np_out = inp + bias
    np.testing.assert_allclose(allo_out, np_out, atol=1e-3)
    print("Passed!")
    hls_mod = s.build(target="vitis_hls",mode="csim", project="bias_add.prj")
    csim_C = np.zeros((L , D), dtype=np.float32)
    hls_mod(inp,bias,csim_C)
    np.testing.assert_allclose(np_out, csim_C, atol=1e-3)
    print("Csim Passed!")

def np_layernorm(inp, gamma, beta):
    mean = inp.mean(axis=1)
    mean2 = (inp**2).mean(axis=1)
    var = mean2 - mean**2
    np_out = gamma * (inp - mean[:, None]) / np.sqrt(var[:, None] + 1e-5) + beta
    return np_out

"pass"
def test_layernorm():
    from allo.library.nn import layer_norm

    L, D = 8, 8
    s = allo.customize(layer_norm, instantiate=[float32, L, D])
    mod = s.build()
    inp = np.random.randn(L, D).astype(np.float32)
    gamma = np.random.randn(D).astype(np.float32)
    beta = np.random.randn(D).astype(np.float32)
    allo_out = mod(inp, gamma, beta)
    np_out = np_layernorm(inp, gamma, beta)
    np.testing.assert_allclose(allo_out, np_out, atol=1e-3)
    print("Passed!")
    print(s.build(target="vhls"))

"pass"
def test_gelu():
    from allo.library.nn import GeLU

    L, D = 8, 8
    s = allo.customize(GeLU, instantiate=[float32, L, D])
    mod = s.build()
    inp = np.random.randn(L, D).astype(np.float32)
    allo_out = mod(inp)
    np_out = 0.5 * inp * (1 + np.tanh(0.797885 * (inp + 0.044715 * inp**3)))
    np.testing.assert_allclose(allo_out, np_out, atol=1e-3)
    print("Passed!")
    print(s.build(target="vhls"))


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

"Passed!"
def test_causal_sdp():
    from allo.library.nn import masked_casual_dot_product_attention, mask_softmax_per_head
    from allo.library.systolic import systolic

    M0, M1 = 8, 8
    H, L, D = 12, 64, 768
    s = allo.customize(
        masked_casual_dot_product_attention, instantiate=[float32, H, L, D, M0, M1]
    )
    mod = s.build()
    Q = np.random.randn(L, D).astype(np.float32)
    K = np.random.randn(L, D).astype(np.float32)
    V = np.random.randn(L, D).astype(np.float32)
    actual_length = np.array([12,12],dtype=np.int32) #fake
    allo_out = mod(Q, K, V, actual_length)
    np_out = causal_sdp(Q, K, V, H, D, L, actual_length[0])
    np.testing.assert_allclose(allo_out, np_out, atol=1e-3)
    print("allo Passed!")
    s.compose(systolic, id="QKT", instantiate=[float32, float32, float32, L, D, D, M0, M1])
    s.compose(systolic, id="YV", instantiate=[float32, float32, float32, L, D, D, M0, M1])
    s.compose(mask_softmax_per_head, id="sft_Y" ,instantiate=[float32, L])
    hls_mod = s.build(target="vitis_hls",mode="csim", project="causal_sdp.prj")
    csim_C = np.zeros((L , D), dtype=np.float32)
    hls_mod(Q,K,V, actual_length,csim_C)
    np.testing.assert_allclose(allo_out, csim_C, atol=1e-3)
    print("Csim Passed!")

def test_GPTneo():
    from allo.library.systolic import systolic
    from allo.library.nn import (
        scaled_dot_product_attention,
        layer_norm,
        GeLU,
        residual_add,
        softmax,
    )

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
        
        attn = linear(attn, out_proj_weight, out_proj_bias)

        # residual
        X = X + attn

        x_ln2 = np_layernorm(X, ln2_weight, ln2_bias)
        mlp_output = linear(x_ln2, mlp_fc_weight, mlp_fc_bias)   
        mlp_output = gelu(mlp_output)  # GELU 
        mlp_output = linear(mlp_output, mlp_proj_weight, mlp_proj_bias)  

        X = X + mlp_output
        return X

if __name__ == "__main__":
    # pytest.main([__file__])
    # test_linear()
    # test_bert()
    # test_mask_softmax_per_head()
    # test_causal_sdp()
    test_bias_add()