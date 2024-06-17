from transformers import GPT2Tokenizer, GPTNeoForCausalLM as HFGPTNeoForCausalLM
from gptneo_torch_causalLM_interface import GPTNeoForCausalLM
from load_weight_matrix import initialize_model, initialize_model_from_saved_files
import torch
import torch.nn.functional as F

# define model configuration
class GPTNeoConfig:
    vocab_size = 50257
    max_position_embeddings = 2048
    hidden_size = 768
    num_layers = 12
    num_heads = 12
    intermediate_size = 3072
    layer_norm_epsilon = 1e-5

#greedy choose generation
def generate_text(model, tokenizer, input_ids, attention_mask=None, max_length=50, pad_token_id=None):
    generated = input_ids
    input_text = tokenizer.decode(input_ids[0], skip_special_tokens=True)
    print(f"\ninput: {input_text}\n")
    print(f"Generating:")
    print(input_text, end="", flush=True)
    for _ in range(max_length):
        outputs = model(input_ids=input_ids, attention_mask=attention_mask)
        next_token_logits = outputs[:, -1, :]
        next_token = torch.argmax(next_token_logits, dim=-1).unsqueeze(-1)
        next_text = tokenizer.decode(next_token[0], skip_special_tokens=True)
        print(next_text, end="", flush=True)
        generated = torch.cat((generated, next_token), dim=1)

        #update pad with fixed length
        input_ids[0] = torch.cat([input_ids[0][1:], next_token[0]])
        attention_mask[0] = torch.cat([attention_mask[0][1:], torch.tensor([1]).to(device)])
        # print(f"attention_mask length: {attention_mask[0].shape[0]}, input_ids length: {input_ids[0].shape[0]} ")
        if pad_token_id is not None and next_token.item() == pad_token_id:
            break
    print("")
    return generated

# define 
hf_model = HFGPTNeoForCausalLM.from_pretrained('EleutherAI/gpt-neo-125M')
tokenizer = GPT2Tokenizer.from_pretrained('EleutherAI/gpt-neo-125M')

device = torch.device("cpu")#only support cpu for numpy mix torch now!
config = GPTNeoConfig()
#our numpy mix torch model
my_model = GPTNeoForCausalLM(config)
#whether to save weight into binary file
save_weights_and_biases = False
save_path = "/work/zhang-capra/users/ky427/allo/GPTneo/weights_and_biases/"
#initialize our numpy mix torch model with real weight
# my_model = initialize_model(hf_model, my_model, save_weights_and_biases, save_path)
my_model = initialize_model_from_saved_files(my_model, save_path)#test load weight from our saved files
my_model.to(device)

# input tokens
input_text = "FPGA is a great accelerator for deep learning models. It"
inputs = tokenizer(input_text, return_tensors='pt')

if tokenizer.pad_token_id is None:
    tokenizer.pad_token_id = tokenizer.eos_token_id
    
max_length = 128
input_ids = inputs['input_ids']
attention_mask = inputs['attention_mask']

max_length=128
#padding
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

# generate text
outputs = generate_text(my_model, tokenizer, input_ids, attention_mask=attention_mask, max_length=50, pad_token_id=tokenizer.eos_token_id)
