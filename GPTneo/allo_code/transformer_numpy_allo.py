import numpy as np
import warnings

"The transformer block of GPT-Neo implemented in sole numpy"
"Which can be replaced by our fpga accelerator"

def linear(x, weight, bias=None):
    # y = np.dot(x, weight.T)
    y = np.dot(x, weight)  # transpose to conform torch linear, we transpose the weight matrix in advance
    if bias is not None:
        y += bias
    return y

def np_layernorm(inp, gamma, beta): #replaced with allo "Right[Yes]"
    mean = inp.mean(axis=1)
    mean2 = (inp**2).mean(axis=1)
    var = mean2 - mean**2
    np_out = gamma * (inp - mean[:, None]) / np.sqrt(var[:, None] + 1e-5) + beta
    return np_out

"Have a large extend to optimize!!!"
def mask_softmax_per_head(x_h, actual_length, fix_length): #apply identical casual and attention mask here
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

"pass"
def gelu(x):
    return 0.5 * x * (1 + np.tanh(0.797885 * (x + 0.044715 * x**3)))
    
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

def GPTNeo_layer(X, ln1_weight, ln1_bias, q_proj_weight, k_proj_weight, v_proj_weight, out_proj_weight, out_proj_bias,
                 ln2_weight, ln2_bias, mlp_fc_weight, mlp_fc_bias, mlp_proj_weight, mlp_proj_bias, H, D, L, actual_length):
    "x shape is [max_seq_len, hidden_size]"

    X_ln1 = np_layernorm(X, ln1_weight, ln1_bias)

    Q = linear(X_ln1, q_proj_weight)
    K = linear(X_ln1, k_proj_weight)
    V = linear(X_ln1, v_proj_weight)
    # breakpoint()

    attn = sdp(Q, K, V, H, D, L, actual_length)
    
    attn = linear(attn, out_proj_weight, out_proj_bias)

    # residual
    X = X + attn

    x_ln2 = np_layernorm(X, ln2_weight, ln2_bias)
    mlp_output = linear(x_ln2, mlp_fc_weight, mlp_fc_bias)   
    mlp_output = gelu(mlp_output)  # GELU 
    mlp_output = linear(mlp_output, mlp_proj_weight, mlp_proj_bias)  

    X = X + mlp_output
    return X
