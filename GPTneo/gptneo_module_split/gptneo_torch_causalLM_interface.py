import torch
import torch.nn as nn
import torch.nn.functional as F
# from gptneo_transformer_numpy import GPTNeoBlock
from gptneo_transformer_numpy_replace import GPTNeoBlock

"GPTNeoBlock is the numpy/fpga part"
""

### PyTorch implements GPTNeoModel and GPTNeoForCausalLM
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





