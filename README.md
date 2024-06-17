1. Now support padding for a fixed length in the framework. Which is the realization of our FPGA.
2. Transpose weight matrix in nn.linear in advance. We don't leave this to FPGA
3. capture the charateristic of casual and attention mask, and replace their code to allo and FPGA friendly
4. Finish allo numpy code for transformer part! Now GPTneo can inference!
5. Mask softmax passed Csim!