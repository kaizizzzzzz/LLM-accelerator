import numpy as np
import os
import torch

def save_weights_and_biases(weights, biases, layer_name, save_path, layer_number=None):
    if layer_number == None:
        directory = save_path
    else:
        directory = f"{save_path}/layer{layer_number}"
    if not os.path.exists(directory):
        os.makedirs(directory)
    if weights is not None:
        np.save(f"{directory}/{layer_name}_weights.npy", weights)
    if biases is not None:
        np.save(f"{directory}/{layer_name}_biases.npy", biases)

def initialize_model(hf_model=None, my_model=None, save_model=False, save_path=None):
    assert hf_model != None, "please specify the hf_model to load weight, we only support gptneo rightnow"
    assert my_model != None, "please specify our numpy model to load weight, we only support gptneo rightnow"

    # load model parameters from huggingface's pretrained model 
    my_model.transformer.wte.weight.data = hf_model.transformer.wte.weight.data
    my_model.transformer.wpe.weight.data = hf_model.transformer.wpe.weight.data
    if save_model:
        save_weights_and_biases(my_model.transformer.wte.weight.data.numpy(), None, "wte", save_path)
        save_weights_and_biases(my_model.transformer.wpe.weight.data.numpy(), None, "wpe", save_path)

    layer_number = 1
    #transformer weight
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

        if save_model:
            save_weights_and_biases(my_layer.attn.q_proj_weight, None, "q_proj", save_path, layer_number)
            save_weights_and_biases(my_layer.attn.k_proj_weight, None, "k_proj", save_path, layer_number)
            save_weights_and_biases(my_layer.attn.v_proj_weight, None, "v_proj", save_path, layer_number)
            save_weights_and_biases(my_layer.attn.out_proj_weight, my_layer.attn.out_proj_bias, "out_proj", save_path, layer_number)
            save_weights_and_biases(my_layer.ln1_weight, my_layer.ln1_bias, "ln1", save_path, layer_number)
            save_weights_and_biases(my_layer.ln2_weight, my_layer.ln2_bias, "ln2", save_path, layer_number)
            save_weights_and_biases(my_layer.mlp_fc_weight, my_layer.mlp_fc_bias, "mlp_fc",save_path, layer_number)
            save_weights_and_biases(my_layer.mlp_proj_weight, my_layer.mlp_proj_bias, "mlp_proj", save_path, layer_number)

        layer_number += 1

    my_model.transformer.ln_f.weight.data = hf_model.transformer.ln_f.weight.data
    my_model.transformer.ln_f.bias.data = hf_model.transformer.ln_f.bias.data
    my_model.lm_head.weight.data = hf_model.lm_head.weight.data

    if save_model:
        save_weights_and_biases(my_model.transformer.ln_f.weight.data.numpy(), my_model.transformer.ln_f.bias.data.numpy(), "ln_f", save_path)
        save_weights_and_biases(my_model.lm_head.weight.data.numpy(), None, "lm_head", save_path)

    return my_model

def load_weights_and_biases(weight_path, bias_path=None, to_tensor=False):
    weight = np.load(weight_path)
    bias = np.load(bias_path) if bias_path else None
    if to_tensor:
        weight = torch.tensor(weight, dtype=torch.float32)
        if bias is not None:
            bias = torch.tensor(bias, dtype=torch.float32)
    if bias is not None:
        return weight, bias
    else:
        return weight

def initialize_model_from_saved_files(my_model=None, model_path=None):
    assert my_model is not None, "please specify our numpy model to load weight"
    assert model_path is not None, "please specify the path where the weights are saved"

    # Load the embedding weights
    my_model.transformer.wte.weight.data = load_weights_and_biases(f"{model_path}/wte_weights.npy", None, to_tensor=True)
    my_model.transformer.wpe.weight.data = load_weights_and_biases(f"{model_path}/wpe_weights.npy", None, to_tensor=True)

    layer_number = 1
    # Load transformer weights
    for my_layer in my_model.transformer.h:
        my_layer.attn.q_proj_weight = load_weights_and_biases(f"{model_path}/layer{layer_number}/q_proj_weights.npy")
        my_layer.attn.k_proj_weight = load_weights_and_biases(f"{model_path}/layer{layer_number}/k_proj_weights.npy")
        my_layer.attn.v_proj_weight = load_weights_and_biases(f"{model_path}/layer{layer_number}/v_proj_weights.npy")
        my_layer.attn.out_proj_weight, my_layer.attn.out_proj_bias = load_weights_and_biases(
            f"{model_path}/layer{layer_number}/out_proj_weights.npy",
            f"{model_path}/layer{layer_number}/out_proj_biases.npy"
        )
        my_layer.ln1_weight, my_layer.ln1_bias = load_weights_and_biases(
            f"{model_path}/layer{layer_number}/ln1_weights.npy",
            f"{model_path}/layer{layer_number}/ln1_biases.npy"
        )
        my_layer.ln2_weight, my_layer.ln2_bias = load_weights_and_biases(
            f"{model_path}/layer{layer_number}/ln2_weights.npy",
            f"{model_path}/layer{layer_number}/ln2_biases.npy"
        )
        my_layer.mlp_fc_weight, my_layer.mlp_fc_bias = load_weights_and_biases(
            f"{model_path}/layer{layer_number}/mlp_fc_weights.npy",
            f"{model_path}/layer{layer_number}/mlp_fc_biases.npy"
        )
        my_layer.mlp_proj_weight, my_layer.mlp_proj_bias = load_weights_and_biases(
            f"{model_path}/layer{layer_number}/mlp_proj_weights.npy",
            f"{model_path}/layer{layer_number}/mlp_proj_biases.npy"
        )
        layer_number += 1

    # Load final layer norm and lm_head weights
    my_model.transformer.ln_f.weight.data, my_model.transformer.ln_f.bias.data = load_weights_and_biases(
        f"{model_path}/ln_f_weights.npy",
        f"{model_path}/ln_f_biases.npy",
        to_tensor=True
    ) 
    
    my_model.lm_head.weight.data = load_weights_and_biases(f"{model_path}/lm_head_weights.npy", None, to_tensor=True)

    return my_model

