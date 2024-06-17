import torch
import torch.nn as nn
import torch.nn.functional as F
# from gptneo_transformer_numpy import GPTNeoBlock
# from gptneo_transformer_numpy_replace import GPTNeoBlock
from transformer_numpy_allo import GPTNeo_layer

"GPTNeoBlock is the numpy/fpga part"
""

### PyTorch implements GPTNeoModel and GPTNeoForCausalLM
class GPTNeoModel(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.wte = nn.Embedding(config.vocab_size, config.hidden_size)
        self.wpe = nn.Embedding(config.max_position_embeddings, config.hidden_size)
        self.ln_f = nn.LayerNorm(config.hidden_size, eps=config.layer_norm_epsilon)
        self.n_layers = config.num_layers

    def store_layers_weight(self, layers_weight): 
        self.layers_weight = layers_weight


    def forward(self, input_ids, attention_mask=None):
        with torch.no_grad():
            device = input_ids.device
            input_shape = input_ids.size()
            input_ids = input_ids.view(-1, input_shape[-1])

            if attention_mask is not None:
                position_ids = attention_mask.long().cumsum(-1) - 1
                position_ids.masked_fill_(attention_mask == 0, 1)
            else:
                position_ids = torch.arange(0, input_shape[-1], dtype=torch.long, device=device)
                position_ids = position_ids.unsqueeze(0).view(-1, input_shape[-1])

            inputs_embeds = self.wte(input_ids)
            position_embeds = self.wpe(position_ids)
            hidden_states = inputs_embeds + position_embeds
            # breakpoint()
            # to numpy, then give to transformer block
            attention_mask = attention_mask.cpu().numpy() 
            hidden_states  = hidden_states.cpu().numpy() 
            hidden_states = hidden_states[0] # delete batch dimension
            
            "naive"
            actual_length = attention_mask.sum()
            L=64
            D=768
            H=12
            for layer in range(1, self.n_layers+1):
                ln1_weight = self.layers_weight[layer]["ln1_weight"]
                ln1_bias = self.layers_weight[layer]["ln1_bias"]
                q_proj_weight = self.layers_weight[layer]["q_proj_weight"]
                k_proj_weight = self.layers_weight[layer]["k_proj_weight"]
                v_proj_weight = self.layers_weight[layer]["v_proj_weight"]
                out_proj_weight = self.layers_weight[layer]["out_proj_weight"]
                out_proj_bias = self.layers_weight[layer]["out_proj_bias"]
                ln2_weight = self.layers_weight[layer]["ln2_weight"]
                ln2_bias = self.layers_weight[layer]["ln2_bias"]
                mlp_fc_weight = self.layers_weight[layer]["mlp_fc_weight"]
                mlp_fc_bias = self.layers_weight[layer]["mlp_fc_bias"]
                mlp_proj_weight = self.layers_weight[layer]["mlp_proj_weight"]
                mlp_proj_bias = self.layers_weight[layer]["mlp_proj_bias"]
                #obtain weights, don't read here, read in advance

                hidden_states = GPTNeo_layer(hidden_states, ln1_weight, ln1_bias, q_proj_weight, k_proj_weight, v_proj_weight, out_proj_weight, out_proj_bias,
                ln2_weight, ln2_bias, mlp_fc_weight, mlp_fc_bias, mlp_proj_weight, mlp_proj_bias, H, D, L, actual_length)

            hidden_states = hidden_states[None,:,:]# back batch dimension
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





