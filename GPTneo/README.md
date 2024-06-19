1. Now support padding for a fixed length in the framework. Which is the realization of our FPGA.
2. Transpose weight matrix in nn.linear in advance. We don't leave this to FPGA
3. capture the charateristic of casual and attention mask, and replace their code to allo and FPGA friendly
4. Finish allo numpy code for transformer part! Now GPTneo can inference!
5. Mask softmax passed Csim!
6. Casual sdp passed Csim!
7. bias_add passed Csim!
8. GPTneo passes atol=1e-2 can pass most time, but atol=1e-3 failed
9. GPTneo should run with our accelerator if "make hw" passed!
10. Add some host.cpp template for tesing hw's correctness
11. our FPGA accelerator for GPTneo can output tokens correctly!!!
12. We have our first casual accelerator!!!
