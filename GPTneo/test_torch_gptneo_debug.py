import torch
import torch.nn as nn
import torch.nn.functional as F
from transformers import GPT2Tokenizer, GPTNeoForCausalLM

cache_dir = "/work/zhang-capra/users/ky427/allo/allo"


device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print("Using device:", device)

tokenizer = GPT2Tokenizer.from_pretrained('EleutherAI/gpt-neo-125M', cache_dir=cache_dir)
model = GPTNeoForCausalLM.from_pretrained('EleutherAI/gpt-neo-125M', cache_dir=cache_dir)

model.to(device)

# input
# input_text = "Computer vision is a technology that allows computers to understand and label images. It is used to help computers see and understand the world. It is also used for tasks such as image recognition, object detection, and"
input_text = "Cornell University located in"
inputs = tokenizer(input_text, return_tensors='pt')

inputs = {key: value.to(device) for key, value in inputs.items()}

inputs['attention_mask'] = torch.ones_like(inputs['input_ids'])

# add pad
if tokenizer.pad_token_id is None:
    tokenizer.pad_token_id = tokenizer.eos_token_id


# padding to 128//FPGA
max_length = 128
input_ids = inputs['input_ids']
attention_mask = inputs['attention_mask']
real_length = input_ids.shape[1]    

# examine input length
if input_ids.shape[1] > max_length:
    input_ids = input_ids[:, :max_length]
    attention_mask = attention_mask[:, :max_length]
else:
    # left padding
    padding_length = max_length - input_ids.shape[1]
    input_ids = F.pad(input_ids, (padding_length, 0), value=tokenizer.pad_token_id)
    attention_mask = F.pad(attention_mask, (padding_length, 0), value=0)
    position_ids = attention_mask.long().cumsum(-1) - 1
    position_ids.masked_fill_(attention_mask == 0, 1)


# breakpoint()
#manually realize generate
for i in range(max_length - real_length):
    outputs = model(input_ids=input_ids, attention_mask=attention_mask, use_cache=False, position_ids=position_ids)
    next_token_logits = outputs.logits[:, -1, :]

    # sample next token
    next_token = torch.argmax(next_token_logits, dim=-1).unsqueeze(-1)
    

    #fix length update
    input_ids[0] = torch.cat([input_ids[0][1:], next_token[0]])
    # breakpoint()
    attention_mask[0] = torch.cat([attention_mask[0][1:], torch.tensor([1]).to(device)])
    position_ids = attention_mask.long().cumsum(-1) - 1
    position_ids.masked_fill_(attention_mask == 0, 1)

    
    if next_token.item() == tokenizer.eos_token_id:
        break

# to CPU
input_ids = input_ids.cpu()

# decode
generated_text = tokenizer.decode(input_ids[0])

print("Generated text:", generated_text)
