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



def sdp(Q, K, V, H, D, L, actual_length):
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
        Y = mask_softmax_per_head(attention, actual_length, L)
        context_i = np.matmul(Y, V_h)
        context[:, i * h_d : (i + 1) * h_d] = context_i
    return context

def test_sdp():
    from allo.library.nn import scaled_dot_product_attention
    from allo.library.systolic import systolic

    M0, M1 = 2, 2
    H, L, D = 12, 8, 8
    s = allo.customize(
        scaled_dot_product_attention, instantiate=[float32, H, L, D, M0, M1]
    )
    mod = s.build()
    Q = np.random.randn(L, D).astype(np.float32)
    K = np.random.randn(L, D).astype(np.float32)
    V = np.random.randn(L, D).astype(np.float32)
    allo_out = mod(Q, K, V)
    np_out = sdp(Q, K, V, H, D)
    np.testing.assert_allclose(allo_out, np_out, atol=1e-3)
    print("Passed!")
    s.compose(systolic, id="QKT", instantiate=[float32, float32, float32, L, D, D, M0, M1])
    s.compose(systolic, id="YV", instantiate=[float32, float32, float32, L, D, D, M0, M1])
    hls_mod = s.build(target="vitis_hls",mode="csim", project="sdp_small.prj")
    breakpoint()
    csim_C = np.zeros((L , D), dtype=np.float32)
    hls_mod(Q,K,V,csim_C)
    np.testing.assert_allclose(allo_out, csim_C, atol=1e-3)


def test_bert():
    from allo.library.systolic import systolic
    from allo.library.nn import (
        scaled_dot_product_attention,
        layer_norm,
        GeLU,
        residual_add,
        softmax,
    )

    H, L, D, Dffn = 2, 8, 8, 16
    M0, M1 = 2, 2

    def BertLayer[
        Ty, H, L, D, Dffn, M0, M1
    ](
        X: "Ty[L, D]",
        Wq: "Ty[D, D]",
        Wk: "Ty[D, D]",
        Wv: "Ty[D, D]",
        Wp: "Ty[D, D]",
        W1: "Ty[D, Dffn]",
        W2: "Ty[Dffn, D]",
        gamma1: "Ty[D]",
        beta1: "Ty[D]",
        gamma2: "Ty[D]",
        beta2: "Ty[D]",
    ) -> "Ty[L, D]":
        # 1. Bert Attention
        # 1.0 project Q, K, V
        Q: Ty[L, D] = 0
        K: Ty[L, D] = 0
        V: Ty[L, D] = 0
        systolic[Ty, Ty, Ty, L, D, D, M0, M1, "Q"](X, Wq, Q)
        systolic[Ty, Ty, Ty, L, D, D, M0, M1, "K"](X, Wk, K)
        systolic[Ty, Ty, Ty, L, D, D, M0, M1, "V"](X, Wv, V)
        # 1.1 self attention
        attn = scaled_dot_product_attention[Ty, H, L, D, M0, M1](Q, K, V)
        # 1.2 output dense
        O_proj: Ty[L, D] = 0
        systolic[Ty, Ty, Ty, L, D, D, M0, M1, "P"](attn, Wp, O_proj)
        # 1.3 Residual layer
        res_attn = residual_add[Ty, L, D, "res_attn"](O_proj, X)
        # 1.4 layer norm
        ln = layer_norm[Ty, L, D, "ln1"](res_attn, gamma1, beta1)
        # 2. Feed Forward Network
        # 2.1 ffn dense 1
        ffn1: Ty[L, Dffn] = 0
        systolic[Ty, Ty, Ty, L, D, Dffn, M0, M1, "ffn1"](ln, W1, ffn1)
        # 2.2 gelu layer
        gelu_outp = GeLU[Ty, L, Dffn](ffn1)
        # 2.3 ffn dense 2
        ffn2: Ty[L, D] = 0
        systolic[Ty, Ty, Ty, L, Dffn, D, M0, M1, "ffn2"](gelu_outp, W2, ffn2)
        # 2.4 Residual layer
        res_ffn = residual_add[Ty, L, D, "res_ffn"](ffn2, ln)
        # 2.5 layer norm
        ffn_ln_outp = layer_norm[Ty, L, D, "ln2"](res_ffn, gamma2, beta2)
        return ffn_ln_outp

    s = allo.customize(
        BertLayer,
        instantiate=[float32, H, L, D, Dffn, M0, M1],
    )
    mod = s.build()
    X = np.random.randn(L, D).astype(np.float32)
    # weights are supposed to be transposed
    Wq = np.random.randn(D, D).astype(np.float32)
    Wk = np.random.randn(D, D).astype(np.float32)
    Wv = np.random.randn(D, D).astype(np.float32)
    Wp = np.random.randn(D, D).astype(np.float32)
    W1 = np.random.randn(D, Dffn).astype(np.float32)
    W2 = np.random.randn(Dffn, D).astype(np.float32)
    gamma1 = np.random.randn(D).astype(np.float32)
    beta1 = np.random.randn(D).astype(np.float32)
    gamma2 = np.random.randn(D).astype(np.float32)
    beta2 = np.random.randn(D).astype(np.float32)
    allo_out = mod(X, Wq, Wk, Wv, Wp, W1, W2, gamma1, beta1, gamma2, beta2)
    s.compose(systolic, instantiate=[float32, float32, float32, L, D, D, M0, M1], id="Q")
    s.compose(systolic, instantiate=[float32, float32, float32, L, D, D, M0, M1], id="K")
    s.compose(systolic, instantiate=[float32, float32, float32, L, D, D, M0, M1], id="V")
    s.compose(systolic, instantiate=[float32, float32, float32, L, D, D, M0, M1], id="P")
    s.compose(systolic, instantiate=[float32, float32, float32, L, D, Dffn, M0, M1], id="ffn1")
    s.compose(systolic, instantiate=[float32, float32, float32, L, Dffn, D, M0, M1], id="ffn2")
    s.compose(systolic, id="QKT", instantiate=[float32, float32, float32, L, D, D, M0, M1])
    s.compose(systolic, id="YV", instantiate=[float32, float32, float32, L, D, D, M0, M1])
    s.compose(softmax, id="sft_Y" ,instantiate=[float32, L])
    hls_mod = s.build(target="vitis_hls",mode="csim", project="bert_vitis.prj")
    csim_C = np.zeros((L , D), dtype=np.float32)
    hls_mod(X,Wq,Wk,Wv,Wp,W1,W2,gamma1,beta1,gamma2,beta2,csim_C)
    breakpoint()

    def bert_layer(X, Wq, Wk, Wv, Wp, W1, W2, gamma1, beta1, gamma2, beta2):
        # 1. Bert Attention
        # 1.0 project Q, K, V
        Q = np.matmul(X, Wq)
        K = np.matmul(X, Wk)
        V = np.matmul(X, Wv)
        # 1.1 self attention
        attn = sdp(Q, K, V, H, D)
        # 1.2 output dense
        O_proj = np.matmul(attn, Wp)
        # 1.3 Residual layer
        res_attn = O_proj + X
        # 1.4 layer norm
        ln = np_layernorm(res_attn, gamma1, beta1)
        # 2. Feed Forward Network
        # 2.1 ffn dense 1
        ffn1 = np.matmul(ln, W1)
        # 2.2 gelu layer
        gelu_outp = 0.5 * ffn1 * (1 + np.tanh(0.797885 * (ffn1 + 0.044715 * ffn1**3)))
        # 2.3 ffn dense 2
        ffn2 = np.matmul(gelu_outp, W2)
        # 2.4 Residual layer
        res_ffn = ffn2 + ln
        # 2.5 layer norm
        ffn_ln_outp = np_layernorm(res_ffn, gamma2, beta2)
        return ffn_ln_outp

    np_out = bert_layer(X, Wq, Wk, Wv, Wp, W1, W2, gamma1, beta1, gamma2, beta2)
    breakpoint()
    np.testing.assert_allclose(allo_out, np_out, atol=1e-3)
    print("allo Passed!")
    np.testing.assert_allclose(csim_C, np_out, atol=1e-3)
    breakpoint()
    print("Csim Passed!")
    print(s.build(target="vhls"))


if __name__ == "__main__":
    # pytest.main([__file__])
    # test_linear()
    # test_bert()
    test_mask_softmax_per_head()
