import numpy as np
import os

def save_weights_and_biases(weights, biases, layer_name, save_path, layer_number):
    directory = f"{save_path}/layer{layer_number}"
    if not os.path.exists(directory):
        os.makedirs(directory)
    np.save(f"{directory}/{layer_name}_weights.npy", weights)
    np.save(f"{directory}/{layer_name}_biases.npy", biases)

def initialize_model(hf_model=None, my_model=None, save_model=False, save_path=None):
    assert hf_model != None, "please specify the hf_model to load weight, we only support gptneo rightnow"
    assert my_model != None, "please specify our numpy model to load weight, we only support gptneo rightnow"

    # load model parameters from huggingface's pretrained model 
    my_model.transformer.wte.weight.data = hf_model.transformer.wte.weight.data
    my_model.transformer.wpe.weight.data = hf_model.transformer.wpe.weight.data

    # save_path = "/root/autodl-tmp/weight_bias"
    layer_number = 1
    # save_weights_and_biases = False
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
            save_weights_and_biases(my_layer.attn.q_proj_weight, None, "q_proj_weight", save_path, layer_number)
            save_weights_and_biases(my_layer.attn.k_proj_weight, None, "k_proj_weight", save_path, layer_number)
            save_weights_and_biases(my_layer.attn.v_proj_weight, None, "v_proj_weight", save_path, layer_number)
            save_weights_and_biases(my_layer.attn.out_proj_weight, my_layer.attn.out_proj_bias, "out_proj", save_path, layer_number)
            save_weights_and_biases(my_layer.ln1_weight, my_layer.ln1_bias, "ln1", save_path, layer_number)
            save_weights_and_biases(my_layer.ln2_weight, my_layer.ln2_bias, "ln2", save_path, layer_number)
            save_weights_and_biases(my_layer.mlp_fc_weight, my_layer.mlp_fc_bias, "mlp_fc",save_path, layer_number)
            save_weights_and_biases(my_layer.mlp_proj_weight, my_layer.mlp_proj_bias, "mlp_proj", save_path, layer_number)

        layer_number += 1

    my_model.transformer.ln_f.weight.data = hf_model.transformer.ln_f.weight.data
    my_model.transformer.ln_f.bias.data = hf_model.transformer.ln_f.bias.data
    my_model.lm_head.weight.data = hf_model.lm_head.weight.data

    return my_model