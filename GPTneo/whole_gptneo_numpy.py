import torch
import torch.nn as nn
import torch.nn.functional as F
from transformers import GPT2Tokenizer, GPTNeoForCausalLM as HFGPTNeoForCausalLM
import numpy as np
"whole realization in one file"
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
        self.scale = self.head_dim ** -0.5

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
        causal_mask = np.tril(np.ones((seq_len, seq_len), dtype=bool)).reshape(1, 1, seq_len, seq_len)
        mask_value = np.finfo(attn_weights.dtype).min
        attn_weights = np.where(causal_mask, attn_weights, mask_value)
        # breakpoint()
        # padding mask
        if attention_mask is not None:
            extended_attention_mask = attention_mask[:, None, None, :]
            extended_attention_mask = (1.0 - extended_attention_mask) * mask_value
            attn_weights += extended_attention_mask
        # breakpoint()
        attn_weights = softmax(attn_weights, axis=-1)

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

### PyTorch implementation for GPTNeoModel and GPTNeoForCausalLM
class GPTNeoModel(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.wte = nn.Embedding(config.vocab_size, config.hidden_size)
        self.wpe = nn.Embedding(config.max_position_embeddings, config.hidden_size)
        self.h = [GPTNeoBlock(config) for _ in range(config.num_layers)]
        self.ln_f = nn.LayerNorm(config.hidden_size, eps=config.layer_norm_epsilon)

    def forward(self, input_ids, attention_mask=None):
        with torch.no_grad():
            device = input_ids.device
            input_shape = input_ids.size()
            input_ids = input_ids.view(-1, input_shape[-1])
            batch_size = input_ids.size(0)

            position_ids = torch.arange(0, input_shape[-1], dtype=torch.long, device=device)
            position_ids = position_ids.unsqueeze(0).view(-1, input_shape[-1])

            inputs_embeds = self.wte(input_ids)
            position_embeds = self.wpe(position_ids)
            hidden_states = inputs_embeds + position_embeds
            # breakpoint()
            # to numpy, then give to transformer block
            attention_mask = attention_mask.cpu().numpy() 
            hidden_states  = hidden_states.cpu().numpy() 
            for block in self.h:
                hidden_states = block.forward(hidden_states, attention_mask) #numpy return type

            hidden_states = torch.tensor(hidden_states, dtype=torch.float32) # back to torch tensor
            
            hidden_states = self.ln_f(hidden_states)

            return hidden_states

class GPTNeoForCausalLM(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.transformer = GPTNeoModel(config)
        self.lm_head = nn.Linear(config.hidden_size, config.vocab_size, bias=False)

    def forward(self, input_ids, attention_mask=None, labels=None):
        transformer_outputs = self.transformer(input_ids, attention_mask)
        lm_logits = self.lm_head(transformer_outputs)

        return lm_logits

# load pretrained model and tokenizer
hf_model = HFGPTNeoForCausalLM.from_pretrained('EleutherAI/gpt-neo-125M')
tokenizer = GPT2Tokenizer.from_pretrained('EleutherAI/gpt-neo-125M')

# define model configuration
class GPTNeoConfig:
    vocab_size = 50257
    max_position_embeddings = 2048
    hidden_size = 768
    num_layers = 12
    num_heads = 12
    intermediate_size = 3072
    layer_norm_epsilon = 1e-5

device = torch.device("cpu")
config = GPTNeoConfig()
my_model = GPTNeoForCausalLM(config)

# load model parameters from huggingface's pretrained model
my_model.transformer.wte.weight.data = hf_model.transformer.wte.weight.data
my_model.transformer.wpe.weight.data = hf_model.transformer.wpe.weight.data

for my_layer, hf_layer in zip(my_model.transformer.h, hf_model.transformer.h):
    # breakpoint()
    my_layer.attn.q_proj_weight = hf_layer.attn.attention.q_proj.weight.data.numpy()
    my_layer.attn.k_proj_weight = hf_layer.attn.attention.k_proj.weight.data.numpy()
    my_layer.attn.v_proj_weight = hf_layer.attn.attention.v_proj.weight.data.numpy()
    my_layer.attn.out_proj_weight = hf_layer.attn.attention.out_proj.weight.data.numpy()
    my_layer.attn.out_proj_bias = hf_layer.attn.attention.out_proj.bias.data.numpy()
    my_layer.ln1_weight = hf_layer.ln_1.weight.data.numpy()
    my_layer.ln1_bias = hf_layer.ln_1.bias.data.numpy()
    my_layer.ln2_weight = hf_layer.ln_2.weight.data.numpy()
    my_layer.ln2_bias = hf_layer.ln_2.bias.data.numpy()
    my_layer.mlp_fc_weight = hf_layer.mlp.c_fc.weight.data.numpy()
    my_layer.mlp_fc_bias = hf_layer.mlp.c_fc.bias.data.numpy()
    my_layer.mlp_proj_weight = hf_layer.mlp.c_proj.weight.data.numpy()
    my_layer.mlp_proj_bias = hf_layer.mlp.c_proj.bias.data.numpy()

my_model.transformer.ln_f.weight.data = hf_model.transformer.ln_f.weight.data
my_model.transformer.ln_f.bias.data = hf_model.transformer.ln_f.bias.data
my_model.lm_head.weight.data = hf_model.lm_head.weight.data

my_model.to(device)

# input tokens
input_text = "Image classification is one of the technology in computer vision. It"
inputs = tokenizer.encode(input_text, return_tensors='pt')
inputs = inputs.to(device)

# set attention mask
attention_mask = torch.ones_like(inputs).to(device)

def generate_text(model, input_ids, attention_mask=None, max_length=50, pad_token_id=None):
    generated = input_ids
    for _ in range(max_length):
        outputs = model(input_ids=generated, attention_mask=attention_mask)
        next_token_logits = outputs[:, -1, :]
        next_token = torch.argmax(next_token_logits, dim=-1).unsqueeze(-1)
        
        generated = torch.cat((generated, next_token), dim=1)
        attention_mask = F.pad(attention_mask, (0, 1), value=1)
        if pad_token_id is not None and next_token.item() == pad_token_id:
            break
    
    return generated

# generate text
outputs = generate_text(my_model, inputs, attention_mask=attention_mask, max_length=50, pad_token_id=tokenizer.eos_token_id)
breakpoint()
generated_text = tokenizer.decode(outputs[0], skip_special_tokens=True)

print("Generated text:", generated_text)
