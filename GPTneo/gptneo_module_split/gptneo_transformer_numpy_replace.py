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

def layer_norm(x, weight, bias):
    mean = x.mean(-1, keepdims=True)
    std = x.std(-1, keepdims=True)
    # breakpoint()
    return (x - mean) / (std + 1e-5) * weight + bias

# def softmax(x, axis=None):
#     x = x - np.max(x, axis=axis, keepdims=True) #must have
#     # breakpoint()
#     exp_x = np.exp(x)
#     return exp_x / np.sum(exp_x, axis=axis, keepdims=True)

"Have a large extend to optimize!!!"
def mask_softmax(x, actual_length, axis=None): #apply identical casual and attention mask here
    "Apply identical casual and attention mask here"

    fix_length = x.shape[-1]
    x_new = np.zeros_like(x)[0]

    for h in range(x_new.shape[0]): #sequential for head
        x_new_head = x[0][h]
        store_x_head_exp = np.zeros_like(x_new_head)
        x_new_row_sum = np.zeros(fix_length)
        x_new_row_max = np.array([-10000000] * fix_length, dtype=np.float32) #large enough

        "find max value in meaningful tows"
        for i in range(x_new.shape[1]):
            for j in range(x_new.shape[2]):
                if i >= j:
                    if i >= fix_length - actual_length: 
                        if j >= fix_length - actual_length: #the right bottom corner
                            x_new_row_max[i] = max(x_new_row_max[i], x_new_head[i,j])


        "sum"
        for i in range(x_new.shape[1]):
            for j in range(x_new.shape[2]):
                if i >= j:
                    if i >= fix_length - actual_length: 
                        if j >= fix_length - actual_length: #the right bottom corner
                            store_x_head_exp[i,j] = np.exp(x_new_head[i,j] - x_new_row_max[i])
                            x_new_row_sum[i] += store_x_head_exp[i,j]
                            
                        else:
                            pass # zero
                    else:
                        x_new[h,i,j] = 1 / (i+1+actual_length)
                else:
                    if i < fix_length - actual_length and j >= fix_length - actual_length:
                        x_new[h,i,j] = 1 / (i+1+actual_length)
                    else:
                        pass # zero

        
        "update"
        for i in range(x_new.shape[1]):
            for j in range(x_new.shape[2]):
                if i >= j:
                    if i >= fix_length - actual_length: 
                        if j >= fix_length - actual_length: #the right bottom corner
                            if x_new_row_sum[i] == 0:
                                print("denominator is zero!")
                                breakpoint()
                            x_new[h,i,j] = store_x_head_exp[i,j] / x_new_row_sum[i]
    x[0] = x_new          
    return x

def gelu(x):
    return 0.5 * x * (1 + np.tanh(0.797885 * (x + 0.044715 * x**3)))

class GPTNeoSelfAttention:
    def __init__(self, config):
        self.num_heads = config.num_heads
        self.hidden_size = config.hidden_size
        self.head_dim = self.hidden_size // self.num_heads
        # self.scale = self.head_dim ** -0.5

        self.q_proj_weight = np.random.randn(self.hidden_size, self.hidden_size).astype(np.float32)
        self.k_proj_weight = np.random.randn(self.hidden_size, self.hidden_size).astype(np.float32)
        self.v_proj_weight = np.random.randn(self.hidden_size, self.hidden_size).astype(np.float32)
        self.out_proj_weight = np.random.randn(self.hidden_size, self.hidden_size).astype(np.float32)
        self.out_proj_bias = np.zeros(self.hidden_size).astype(np.float32)

    def forward(self, x, attention_mask=None):
        batch_size, seq_len, hidden_size = x.shape

        q = linear(x, self.q_proj_weight)
        k = linear(x, self.k_proj_weight)
        v = linear(x, self.v_proj_weight)
        # breakpoint()

        q = q.reshape(batch_size, seq_len, self.num_heads, self.head_dim).transpose(0, 2, 1, 3)
        k = k.reshape(batch_size, seq_len, self.num_heads, self.head_dim).transpose(0, 2, 1, 3)
        v = v.reshape(batch_size, seq_len, self.num_heads, self.head_dim).transpose(0, 2, 1, 3)

        attn_weights = np.matmul(q, k.transpose(0, 1, 3, 2)) 

        #don't scale
        # attn_weights = attn_weights / / np.sqrt(self.head_dim)   

        # causal mask
        # causal_mask = np.tril(np.ones((seq_len, seq_len), dtype=bool)).reshape(1, 1, seq_len, seq_len)
        # mask_value = np.finfo(attn_weights.dtype).min
        # attn_weights_true = np.where(causal_mask, attn_weights, mask_value)
        # # breakpoint()
        # # padding mask
        # if attention_mask is not None:
        #     extended_attention_mask = attention_mask[:, None, None, :]
        #     extended_attention_mask = (1.0 - extended_attention_mask) * mask_value
        #     with warnings.catch_warnings():
        #         warnings.filterwarnings("ignore", category=RuntimeWarning, message="overflow encountered in add")
        #         attn_weights_true += extended_attention_mask
        # breakpoint()
        # attn_weights_true = softmax(attn_weights_true, axis=-1)
        # breakpoint()
        "reaplaced with allo and FPGA friendly casual and attention mask"
        actual_length = attention_mask.sum()
        attn_weights = mask_softmax(attn_weights, actual_length, axis=-1)
        "reaplaced with allo and FPGA friendly casual and attention mask"
        # if not np.allclose(attn_weights, attn_weights_true, atol=1e-5):
        #     print("attn_weights and attn_weights_true are not close enough!")
        #     breakpoint()

        
        attn_output = np.matmul(attn_weights, v)
        attn_output = attn_output.transpose(0, 2, 1, 3).reshape(batch_size, seq_len, hidden_size)
        attn_output = linear(attn_output, self.out_proj_weight, self.out_proj_bias)

        return attn_output

class GPTNeoBlock:
    def __init__(self, config):
        self.ln1_weight = np.ones(config.hidden_size, dtype=np.float32)
        self.ln1_bias = np.zeros(config.hidden_size, dtype=np.float32)
        self.attn = GPTNeoSelfAttention(config)
        self.ln2_weight = np.ones(config.hidden_size, dtype=np.float32)
        self.ln2_bias = np.zeros(config.hidden_size, dtype=np.float32)
        "We transpose in advance, pay attention to the unflatten shape!"
        # self.mlp_fc_weight = np.random.randn(config.intermediate_size, config.hidden_size).astype(np.float32)
        self.mlp_fc_weight = np.random.randn(config.hidden_size, config.intermediate_size).astype(np.float32)
        self.mlp_fc_bias = np.zeros(config.intermediate_size).astype(np.float32)
        "We transpose in advance, pay attention to the unflatten shape!"
        # self.mlp_proj_weight = np.random.randn(config.hidden_size, config.intermediate_size).astype(np.float32)
        self.mlp_proj_weight = np.random.randn(config.intermediate_size, config.hidden_size).astype(np.float32)
        self.mlp_proj_bias = np.zeros(config.hidden_size).astype(np.float32)

    def forward(self, x, attention_mask=None):
        x_ln1 = layer_norm(x, self.ln1_weight, self.ln1_bias)
        # breakpoint()
        attn_output = self.attn.forward(x_ln1, attention_mask)
        # breakpoint()
        x = x + attn_output

        x_ln2 = layer_norm(x, self.ln2_weight, self.ln2_bias)
        mlp_output = linear(x_ln2, self.mlp_fc_weight, self.mlp_fc_bias)   
        mlp_output = gelu(mlp_output)  # GELU 
        mlp_output = linear(mlp_output, self.mlp_proj_weight, self.mlp_proj_bias)  
        # breakpoint()
        # mlp_output = mlp_output.reshape(x.shape[0], -1, self.mlp_proj_weight.shape[0])  # restore the shape
        x = x + mlp_output
        return x