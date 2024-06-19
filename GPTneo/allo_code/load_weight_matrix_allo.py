import numpy as np
import os
import torch
"please get the weight matrix from the saved files in other folder in advance"
"so we can load here"

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
    
def load_all_layers_weights(model_path, n_layers):
    all_weights = {}
    for layer_number in range(1, n_layers + 1):
        layer_weights = {
            'q_proj_weight': np.load(f"{model_path}/layer{layer_number}/q_proj_weights.npy"),
            'k_proj_weight': np.load(f"{model_path}/layer{layer_number}/k_proj_weights.npy"),
            'v_proj_weight': np.load(f"{model_path}/layer{layer_number}/v_proj_weights.npy"),
            'out_proj_weight': np.load(f"{model_path}/layer{layer_number}/out_proj_weights.npy"),
            'out_proj_bias': np.load(f"{model_path}/layer{layer_number}/out_proj_biases.npy"),
            'ln1_weight': np.load(f"{model_path}/layer{layer_number}/ln1_weights.npy"),
            'ln1_bias': np.load(f"{model_path}/layer{layer_number}/ln1_biases.npy"),
            'ln2_weight': np.load(f"{model_path}/layer{layer_number}/ln2_weights.npy"),
            'ln2_bias': np.load(f"{model_path}/layer{layer_number}/ln2_biases.npy"),
            'mlp_fc_weight': np.load(f"{model_path}/layer{layer_number}/mlp_fc_weights.npy"),
            'mlp_fc_bias': np.load(f"{model_path}/layer{layer_number}/mlp_fc_biases.npy"),
            'mlp_proj_weight': np.load(f"{model_path}/layer{layer_number}/mlp_proj_weights.npy"),
            'mlp_proj_bias': np.load(f"{model_path}/layer{layer_number}/mlp_proj_biases.npy"),
        }
        all_weights[layer_number] = layer_weights
    return all_weights

def initialize_model_from_saved_files(my_model=None, model_path=None):
    assert my_model is not None, "please specify our numpy model to load weight"
    assert model_path is not None, "please specify the path where the weights are saved"

    # Load the embedding weights
    my_model.transformer.wte.weight.data = load_weights_and_biases(f"{model_path}/wte_weights.npy", None, to_tensor=True)
    my_model.transformer.wpe.weight.data = load_weights_and_biases(f"{model_path}/wpe_weights.npy", None, to_tensor=True)

    
    # Load transformer weights into a dict
    all_layer_weights = load_all_layers_weights(model_path, 12)

    # Load final layer norm and lm_head weights
    my_model.transformer.ln_f.weight.data, my_model.transformer.ln_f.bias.data = load_weights_and_biases(
        f"{model_path}/ln_f_weights.npy",
        f"{model_path}/ln_f_biases.npy",
        to_tensor=True
    ) 
    
    my_model.lm_head.weight.data = load_weights_and_biases(f"{model_path}/lm_head_weights.npy", None, to_tensor=True)

    return my_model, all_layer_weights

