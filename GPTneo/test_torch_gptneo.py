import torch
import torch.nn.functional as F
from transformers import GPT2Tokenizer, GPTNeoForCausalLM

cache_dir = "/work/zhang-capra/users/ky427/allo/allo"


device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print("Using device:", device)


tokenizer = GPT2Tokenizer.from_pretrained('EleutherAI/gpt-neo-125M', cache_dir=cache_dir, padding_side='left')
model = GPTNeoForCausalLM.from_pretrained('EleutherAI/gpt-neo-125M', cache_dir=cache_dir)


model.to(device)

# input
# input_text = "Computer vision is a technology that allows computers to understand and label images. It is used to help computers see and understand the world. It is also used for tasks such as image recognition, object detection, and"
input_text = "Golden State worriors is a basketball team that"
inputs = tokenizer(input_text, return_tensors='pt')
breakpoint()
# add pad
if tokenizer.pad_token_id is None:
    tokenizer.pad_token_id = tokenizer.eos_token_id

# pad to 128// FPGA
max_length = 128
input_ids = inputs['input_ids']
attention_mask = inputs['attention_mask']

# examine input length
if input_ids.shape[1] > max_length:
    input_ids = input_ids[:, :max_length]
    attention_mask = attention_mask[:, :max_length]
else:
    # left padding
    padding_length = max_length - input_ids.shape[1]
    input_ids = F.pad(input_ids, (padding_length, 0), value=tokenizer.pad_token_id)
    attention_mask = F.pad(attention_mask, (padding_length, 0), value=0)
    # breakpoint()

#move data to GPU
input_ids = input_ids.to(device)
attention_mask = attention_mask.to(device)
breakpoint()
print("start!")

# inference
outputs = model.generate(
    input_ids=input_ids,
    attention_mask=attention_mask,
    max_length=200,
    num_return_sequences=1,
    # pad_token_id=tokenizer.pad_token_id,
    # eos_token_id=tokenizer.eos_token_id,
    use_cache=False
)

# move result to cpu
outputs = outputs.cpu()

# decode
generated_text = tokenizer.decode(outputs[0], skip_special_tokens=True)

print("Generated text:", generated_text)
