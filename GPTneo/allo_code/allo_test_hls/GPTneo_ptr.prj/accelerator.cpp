#include "xcl2.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

extern "C" {
void run_gptneo_layer(const char *binaryFilePath, float *input_data,
                      float *ln1_weight, float *ln1_bias, float *q_proj_weight,
                      float *k_proj_weight, float *v_proj_weight,
                      float *out_proj_weight, float *out_proj_bias,
                      float *ln2_weight, float *ln2_bias, float *mlp_fc_weight,
                      float *mlp_fc_bias, float *mlp_proj_weight,
                      float *mlp_proj_bias, int *params, float *output_data) {
  // add this line to suppress the output
  std::ofstream devnull("/dev/null");
  std::streambuf *cout_buf = std::cout.rdbuf();
  std::streambuf *cerr_buf = std::cerr.rdbuf();
  std::cout.rdbuf(devnull.rdbuf());
  std::cerr.rdbuf(devnull.rdbuf());
  cl_int err;
  cl::CommandQueue q;
  cl::Context context;
  cl::Program program;
  cl::Kernel krnl_GPTNEOLayer;

  // Allocate Memory in Host Memory
  size_t size_bytes_in0 = sizeof(float) * 49152;
  size_t size_bytes_in1 = sizeof(float) * 768;
  size_t size_bytes_in2 = sizeof(float) * 768;
  size_t size_bytes_in3 = sizeof(float) * 589824;
  size_t size_bytes_in4 = sizeof(float) * 589824;
  size_t size_bytes_in5 = sizeof(float) * 589824;
  size_t size_bytes_in6 = sizeof(float) * 589824;
  size_t size_bytes_in7 = sizeof(float) * 768;
  size_t size_bytes_in8 = sizeof(float) * 768;
  size_t size_bytes_in9 = sizeof(float) * 768;
  size_t size_bytes_in10 = sizeof(float) * 2359296;
  size_t size_bytes_in11 = sizeof(float) * 3072;
  size_t size_bytes_in12 = sizeof(float) * 2359296;
  size_t size_bytes_in13 = sizeof(float) * 768;
  size_t size_bytes_in14 = sizeof(int) * 2;
  size_t size_bytes_out0 = sizeof(float) * 49152;

  std::vector<float, aligned_allocator<float>> source_in0(input_data,
                                                          input_data + 49152);
  std::vector<float, aligned_allocator<float>> source_in1(ln1_weight,
                                                          ln1_weight + 768);
  std::vector<float, aligned_allocator<float>> source_in2(ln1_bias,
                                                          ln1_bias + 768);
  std::vector<float, aligned_allocator<float>> source_in3(
      q_proj_weight, q_proj_weight + 589824);
  std::vector<float, aligned_allocator<float>> source_in4(
      k_proj_weight, k_proj_weight + 589824);
  std::vector<float, aligned_allocator<float>> source_in5(
      v_proj_weight, v_proj_weight + 589824);
  std::vector<float, aligned_allocator<float>> source_in6(
      out_proj_weight, out_proj_weight + 589824);
  std::vector<float, aligned_allocator<float>> source_in7(out_proj_bias,
                                                          out_proj_bias + 768);
  std::vector<float, aligned_allocator<float>> source_in8(ln2_weight,
                                                          ln2_weight + 768);
  std::vector<float, aligned_allocator<float>> source_in9(ln2_bias,
                                                          ln2_bias + 768);
  std::vector<float, aligned_allocator<float>> source_in10(
      mlp_fc_weight, mlp_fc_weight + 2359296);
  std::vector<float, aligned_allocator<float>> source_in11(mlp_fc_bias,
                                                           mlp_fc_bias + 3072);
  std::vector<float, aligned_allocator<float>> source_in12(
      mlp_proj_weight, mlp_proj_weight + 2359296);
  std::vector<float, aligned_allocator<float>> source_in13(mlp_proj_bias,
                                                           mlp_proj_bias + 768);
  std::vector<int, aligned_allocator<int>> source_in14(params, params + 2);
  std::vector<float, aligned_allocator<float>> source_out0(49152);

  // OPENCL HOST CODE AREA START
  auto devices = xcl::get_xil_devices();
  auto fileBuf = xcl::read_binary_file(binaryFilePath);
  cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
  bool valid_device = false;
  for (unsigned int i = 0; i < devices.size(); i++) {
    auto device = devices[i];
    OCL_CHECK(err,
              context = cl::Context(device, nullptr, nullptr, nullptr, &err));
    OCL_CHECK(err, q = cl::CommandQueue(context, device,
                                        CL_QUEUE_PROFILING_ENABLE, &err));
    std::cout << "Trying to program device[" << i
              << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
    cl::Program program(context, {device}, bins, nullptr, &err);
    if (err != CL_SUCCESS) {
      std::cout << "Failed to program device[" << i << "] with xclbin file!\n";
    } else {
      std::cout << "Device[" << i << "]: program successful!\n";
      OCL_CHECK(err,
                krnl_GPTNEOLayer = cl::Kernel(program, "GPTNEOLayer", &err));
      valid_device = true;
      break;
    }
  }
  if (!valid_device) {
    std::cout << "Failed to program any device found, exit!\n";
    exit(EXIT_FAILURE);
  }

  OCL_CHECK(err, cl::Buffer buffer_in0(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in0, source_in0.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in1(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in1, source_in1.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in2(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in2, source_in2.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in3(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in3, source_in3.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in4(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in4, source_in4.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in5(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in5, source_in5.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in6(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in6, source_in6.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in7(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in7, source_in7.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in8(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in8, source_in8.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in9(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in9, source_in9.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in10(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in10, source_in10.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in11(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in11, source_in11.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in12(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in12, source_in12.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in13(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in13, source_in13.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in14(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in14, source_in14.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_out0(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                     size_bytes_out0, source_out0.data(), &err));

  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(0, buffer_in0));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(1, buffer_in1));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(2, buffer_in2));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(3, buffer_in3));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(4, buffer_in4));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(5, buffer_in5));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(6, buffer_in6));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(7, buffer_in7));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(8, buffer_in8));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(9, buffer_in9));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(10, buffer_in10));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(11, buffer_in11));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(12, buffer_in12));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(13, buffer_in13));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(14, buffer_in14));
  OCL_CHECK(err, err = krnl_GPTNEOLayer.setArg(15, buffer_out0));
  OCL_CHECK(err, err = q.enqueueMigrateMemObjects(
                     {buffer_in0, buffer_in1, buffer_in2, buffer_in3,
                      buffer_in4, buffer_in5, buffer_in6, buffer_in7,
                      buffer_in8, buffer_in9, buffer_in10, buffer_in11,
                      buffer_in12, buffer_in13, buffer_in14},
                     0));

  cl::Event event;
  OCL_CHECK(err, err = q.enqueueTask(krnl_GPTNEOLayer, nullptr, &event));
  OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_out0},
                                                  CL_MIGRATE_MEM_OBJECT_HOST));
  q.finish();

  std::copy(source_out0.begin(), source_out0.end(), output_data);
  // restore the output
  std::cout.rdbuf(cout_buf);
  std::cerr.rdbuf(cerr_buf);
}
}
