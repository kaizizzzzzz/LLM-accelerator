import numpy as np
import warnings

"The transformer block of GPT-Neo implemented in sole numpy"
"Which can be replaced by our fpga accelerator"

def linear(x, weight, bias=None):
    y = np.dot(x, weight.T)  # transpose to conform torch linear
    if bias is not None:
        y += bias
    return y

def layer_norm(x, weight, bias):
    mean = x.mean(-1, keepdims=True)
    std = x.std(-1, keepdims=True)
    # breakpoint()
    return (x - mean) / (std + 1e-5) * weight + bias

def softmax(x, axis=None):
    x = x - np.max(x, axis=axis, keepdims=True)
    # breakpoint()
    exp_x = np.exp(x)
    return exp_x / np.sum(exp_x, axis=axis, keepdims=True)

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

        "can be better replaced with computation more friendly to fpga"
        # causal mask
        causal_mask = np.tril(np.ones((seq_len, seq_len), dtype=bool)).reshape(1, 1, seq_len, seq_len)
        mask_value = np.finfo(attn_weights.dtype).min
        attn_weights = np.where(causal_mask, attn_weights, mask_value)
        # breakpoint()
        # padding mask
        if attention_mask is not None:
            extended_attention_mask = attention_mask[:, None, None, :]
            extended_attention_mask = (1.0 - extended_attention_mask) * mask_value
            with warnings.catch_warnings():
                warnings.filterwarnings("ignore", category=RuntimeWarning, message="overflow encountered in add")
                attn_weights += extended_attention_mask
        # breakpoint()
        attn_weights = softmax(attn_weights, axis=-1)

        "can be better replaced with computation more friendly to fpga"
        
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
        self.mlp_fc_weight = np.random.randn(config.intermediate_size, config.hidden_size).astype(np.float32)
        self.mlp_fc_bias = np.zeros(config.intermediate_size).astype(np.float32)
        self.mlp_proj_weight = np.random.randn(config.hidden_size, config.intermediate_size).astype(np.float32)
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
        mlp_output = mlp_output.reshape(x.shape[0], -1, self.mlp_proj_weight.shape[0])  # restore the shape
        x = x + mlp_output
        return x