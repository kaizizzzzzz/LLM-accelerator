import torch
import torch.nn as nn
import torch.nn.functional as F
from transformers import GPT2Tokenizer, GPTNeoForCausalLM as HFGPTNeoForCausalLM


# model part
class GPTNeoSelfAttention(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.num_heads = config.num_heads
        self.hidden_size = config.hidden_size
        self.head_dim = self.hidden_size // self.num_heads
        self.scale = self.head_dim ** -0.5

        self.q_proj = nn.Linear(self.hidden_size, self.hidden_size, bias=False)
        self.k_proj = nn.Linear(self.hidden_size, self.hidden_size, bias=False)
        self.v_proj = nn.Linear(self.hidden_size, self.hidden_size, bias=False)
        self.out_proj = nn.Linear(self.hidden_size, self.hidden_size, bias=True)


    def forward(self, x, attention_mask=None):
        batch_size, seq_len, hidden_size = x.size()

        q = self.q_proj(x)
        k = self.k_proj(x)
        v = self.v_proj(x)
        # breakpoint()

        q = q.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        k = k.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        v = v.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)

        attn_weights = torch.matmul(q, k.transpose(-1, -2)) 

        #don't scale in gptneo
        # attn_weights = attn_weights * self.scale

        #casual mask in inference
        casual_mask = torch.tril(torch.ones((seq_len, seq_len), dtype=bool)).view(
            1, 1, seq_len, seq_len
        )
        neg_inf = torch.finfo(attn_weights.dtype).min
        mask_value = torch.tensor(neg_inf, dtype=attn_weights.dtype).to(attn_weights.device)
        attn_weights = torch.where(casual_mask, attn_weights, mask_value)
        # breakpoint()
        #padding mask
        if attention_mask is not None:
            extended_attention_mask = attention_mask[:, None, None, :]
            extended_attention_mask = (1.0 - extended_attention_mask) * neg_inf
            attn_weights = attn_weights + extended_attention_mask

        attn_weights = F.softmax(attn_weights, dim=-1)
        # breakpoint()

        attn_output = torch.matmul(attn_weights, v)
        #merge head
        attn_output = attn_output.transpose(1, 2).contiguous().view(batch_size, seq_len, hidden_size)
        attn_output = self.out_proj(attn_output)

        return attn_output

class GPTNeoBlock(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.ln1 = nn.LayerNorm(config.hidden_size, eps=config.layer_norm_epsilon)
        self.attn = GPTNeoSelfAttention(config)
        self.ln2 = nn.LayerNorm(config.hidden_size, eps=config.layer_norm_epsilon)
        self.mlp = nn.Sequential(
            nn.Linear(config.hidden_size, config.intermediate_size, bias=True),
            nn.GELU(),
            nn.Linear(config.intermediate_size, config.hidden_size, bias=True)
        )

    def forward(self, x, attention_mask=None):
        # breakpoint()
        attn_output = self.attn(self.ln1(x), attention_mask)
        # breakpoint()
        x = x + attn_output
        mlp_output = self.mlp(self.ln2(x))
        x = x + mlp_output
        return x

class GPTNeoModel(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.wte = nn.Embedding(config.vocab_size, config.hidden_size)
        self.wpe = nn.Embedding(config.max_position_embeddings, config.hidden_size)
        # breakpoint()
        self.h = nn.ModuleList([GPTNeoBlock(config) for _ in range(config.num_layers)])
        self.ln_f = nn.LayerNorm(config.hidden_size, eps=config.layer_norm_epsilon)

    def forward(self, input_ids, attention_mask=None):
        device = input_ids.device
        input_shape = input_ids.size()
        input_ids = input_ids.view(-1, input_shape[-1])
        batch_size = input_ids.size(0)
        
        if attention_mask is not None:
            position_ids = attention_mask.long().cumsum(-1) - 1
            position_ids.masked_fill_(attention_mask == 0, 1)
        else:
            position_ids = torch.arange(0, input_shape[-1], dtype=torch.long, device=device)
            position_ids = position_ids.unsqueeze(0).view(-1, input_shape[-1])

        inputs_embeds = self.wte(input_ids)
        position_embeds = self.wpe(position_ids)
        # breakpoint()
        hidden_states = inputs_embeds + position_embeds

        for block in self.h:
            hidden_states = block(hidden_states, attention_mask)

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
tokenizer = GPT2Tokenizer.from_pretrained('EleutherAI/gpt-neo-125M', padding_side='left')
# breakpoint()

# define model configuration
class GPTNeoConfig:
    vocab_size = 50257
    max_position_embeddings = 2048
    hidden_size = 768
    num_layers = 12
    num_heads = 12
    intermediate_size = 3072
    layer_norm_epsilon = 1e-5

# device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
device = torch.device("cpu")
config = GPTNeoConfig()
my_model = GPTNeoForCausalLM(config)

# load model parameters from huggingface's pretrained model
my_model.transformer.wte.weight.data = hf_model.transformer.wte.weight.data
my_model.transformer.wpe.weight.data = hf_model.transformer.wpe.weight.data

for my_layer, hf_layer in zip(my_model.transformer.h, hf_model.transformer.h):
    my_layer.ln1.weight.data = hf_layer.ln_1.weight.data
    my_layer.ln1.bias.data = hf_layer.ln_1.bias.data
    my_layer.attn.q_proj.weight.data = hf_layer.attn.attention.q_proj.weight.data
    # my_layer.attn.q_proj.bias.data = hf_layer.attn.attention.q_proj.bias.data
    my_layer.attn.k_proj.weight.data = hf_layer.attn.attention.k_proj.weight.data
    # my_layer.attn.k_proj.bias.data = hf_layer.attn.attention.k_proj.bias.data
    my_layer.attn.v_proj.weight.data = hf_layer.attn.attention.v_proj.weight.data
    # my_layer.attn.v_proj.bias.data = hf_layer.attn.attention.v_proj.bias.data
    my_layer.attn.out_proj.weight.data = hf_layer.attn.attention.out_proj.weight.data
    my_layer.attn.out_proj.bias.data = hf_layer.attn.attention.out_proj.bias.data
    my_layer.ln2.weight.data = hf_layer.ln_2.weight.data
    my_layer.ln2.bias.data = hf_layer.ln_2.bias.data
    my_layer.mlp[0].weight.data = hf_layer.mlp.c_fc.weight.data
    my_layer.mlp[0].bias.data = hf_layer.mlp.c_fc.bias.data
    my_layer.mlp[2].weight.data = hf_layer.mlp.c_proj.weight.data
    my_layer.mlp[2].bias.data = hf_layer.mlp.c_proj.bias.data

my_model.transformer.ln_f.weight.data = hf_model.transformer.ln_f.weight.data
my_model.transformer.ln_f.bias.data = hf_model.transformer.ln_f.bias.data
my_model.lm_head.weight.data = hf_model.lm_head.weight.data

my_model.to(device)


# input tokens
# input_text = "Computer vision is a technology that allows computers to understand and label images. It is used to help computers see and understand the world. It is also used for tasks such as image recognition, object detection, and"
input_text = "Tsinghua university is"
inputs = tokenizer(input_text, return_tensors='pt')

if tokenizer.pad_token_id is None:
    tokenizer.pad_token_id = tokenizer.eos_token_id
    
max_length = 128
input_ids = inputs['input_ids']
attention_mask = inputs['attention_mask']


if input_ids.shape[1] > max_length:
    input_ids = input_ids[:, :max_length]
    attention_mask = attention_mask[:, :max_length]
else:
    # left padding!!!
    padding_length = max_length - input_ids.shape[1]
    input_ids = F.pad(input_ids, (padding_length, 0), value=tokenizer.pad_token_id)
    attention_mask = F.pad(attention_mask, (padding_length, 0), value=0)
    # breakpoint()


input_ids = input_ids.to(device)
attention_mask = attention_mask.to(device)


# set attention mask
def generate_text(model, input_ids, attention_mask=None, max_length=50, pad_token_id=None):
    breakpoint()
    generated = input_ids
    for _ in range(max_length):
        outputs = model(input_ids, attention_mask=attention_mask)
        next_token_logits = outputs[:, -1, :]
        next_token = torch.argmax(next_token_logits, dim=-1).unsqueeze(-1)
        
        generated = torch.cat((generated, next_token), dim=1)
        #update pad with fixed length
        input_ids[0] = torch.cat([input_ids[0][1:], next_token[0]])
        attention_mask[0] = torch.cat([attention_mask[0][1:], torch.tensor([1]).to(device)])
        if pad_token_id is not None and next_token.item() == pad_token_id:
            break
    
    return generated

# generate text
outputs = generate_text(my_model, input_ids, attention_mask=attention_mask, max_length=50, pad_token_id=tokenizer.eos_token_id)
generated_text = tokenizer.decode(outputs[0], skip_special_tokens=True)
breakpoint()
print("Generated text:", generated_text)