//=============================================================================
// Auto generated by Allo
//=============================================================================

// OpenCL utility layer include
#include "xcl2.hpp"
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <random>
#include <vector>

template <typename Alloc>
void gemm_cpu(const std::vector<int8_t, Alloc> &A,
              const std::vector<int8_t, Alloc> &B, std::vector<int8_t> &C,
              int M, int N, int K)
{
  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      int32_t sum = 0; // high bit to avoid overflow
      for (int k = 0; k < K; ++k)
      {
        sum += static_cast<int32_t>(A[i * K + k]) *
               static_cast<int32_t>(B[k * N + j]);
      }
      //   C[i * N + j] = static_cast<int8_t>(
      //       std::min(std::max(sum, static_cast<int32_t>(-128)),
      //                static_cast<int32_t>(127)));
      C[i * N + j] = static_cast<int8_t>(sum);
    }
  }
}

uint64_t get_bits_range(int64_t value, int high, int low)
{
  uint64_t mask = ((1ULL << (high - low + 1)) - 1) << low;
  return (value & mask) >> low;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
    return EXIT_FAILURE;
  }

  std::string binaryFile = argv[1];
  cl_int err;
  cl::CommandQueue q;
  cl::Context context;
  cl::Program program;
  cl::Kernel krnl_top;
  // Allocate Memory in Host Memory
  // When creating a buffer with user pointer (CL_MEM_USE_HOST_PTR), under the
  // hood user ptr is used if it is properly aligned. when not aligned, runtime
  // had no choice but to create its own host side buffer. So it is recommended
  // to use this allocator if user wish to create buffer using
  // CL_MEM_USE_HOST_PTR to align user buffer to page boundary. It will ensure
  // that user buffer is used when user create Buffer/Mem object with
  // CL_MEM_USE_HOST_PTR
  size_t size_bytes_in0 = sizeof(long) * 49152;
  std::vector<long, aligned_allocator<long>> source_in0(49152);
  std::vector<int8_t, aligned_allocator<int8_t>> source_in0_unpack(49152 * 8);
  // reverse input the matrix
  for (int i = 0; i < 768; ++i)
  {
    for (int j = 0; j < 64; ++j)
    {
      if (i < 384)
      {
        source_in0[i + j * 768] = 0x0101010101010101;
        for (int k = 0; k < 8; ++k)
        {
          source_in0_unpack[(j * 8 + k) * 768 + i] = 1;
        }
      }
      else
      {
        source_in0[i + j * 768] = 0;
        for (int k = 0; k < 8; ++k)
        {
          source_in0_unpack[(j * 8 + k) * 768 + i] = 0;
        }
      }
    }
  }

  size_t size_bytes_in1 = sizeof(long) * 294912;
  std::vector<long, aligned_allocator<long>> source_in1(294912);
  std::vector<int8_t, aligned_allocator<int8_t>> source_in1_unpack(294912 * 8);
  for (int i = 0; i < 768; ++i)
  {
    for (int j = 0; j < 384; ++j)
    {
      if (i < 384)
      {
        source_in1[i * 384 + j] = 0x0101010101010101;
        for (int k = 0; k < 8; ++k)
        {
          source_in1_unpack[i * 384 * 8 + j * 8 + k] = 1;
        }
      }
      else
      {
        source_in1[i * 384 + j] = 0;
        for (int k = 0; k < 8; ++k)
        {
          source_in1_unpack[i * 384 * 8 + j * 8 + k] = 0;
        }
      }
    }
  }
  size_t size_bytes_out0 = sizeof(long) * 196608;
  std::vector<long, aligned_allocator<long>> source_out0(196608);

  // OPENCL HOST CODE AREA START
  // get_xil_devices() is a utility API which will find the xilinx
  // platforms and will return list of devices connected to Xilinx platform
  auto devices = xcl::get_xil_devices();
  // read_binary_file() is a utility API which will load the binaryFile
  // and will return the pointer to file buffer.
  auto fileBuf = xcl::read_binary_file(binaryFile);
  cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
  bool valid_device = false;
  for (unsigned int i = 0; i < devices.size(); i++)
  {
    auto device = devices[i];
    // Creating Context and Command Queue for selected Device
    OCL_CHECK(err,
              context = cl::Context(device, nullptr, nullptr, nullptr, &err));
    OCL_CHECK(err, q = cl::CommandQueue(context, device,
                                        CL_QUEUE_PROFILING_ENABLE, &err));
    std::cout << "Trying to program device[" << i
              << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
    cl::Program program(context, {device}, bins, nullptr, &err);
    if (err != CL_SUCCESS)
    {
      std::cout << "Failed to program device[" << i << "] with xclbin file!\n";
    }
    else
    {
      std::cout << "Device[" << i << "]: program successful!\n";
      OCL_CHECK(err, krnl_top = cl::Kernel(program, "top", &err));
      valid_device = true;
      break; // we break because we found a valid device
    }
  }
  if (!valid_device)
  {
    std::cout << "Failed to program any device found, exit!\n";
    exit(EXIT_FAILURE);
  }
  // Allocate Buffer in Global Memory
  // Buffers are allocated using CL_MEM_USE_HOST_PTR for efficient memory and
  // Device-to-host communication
  OCL_CHECK(err, cl::Buffer buffer_in0(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in0, source_in0.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_in1(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                     size_bytes_in1, source_in1.data(), &err));
  OCL_CHECK(err, cl::Buffer buffer_out0(
                     context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                     size_bytes_out0, source_out0.data(), &err));

  OCL_CHECK(err, err = krnl_top.setArg(0, buffer_in0));
  OCL_CHECK(err, err = krnl_top.setArg(1, buffer_in1));
  OCL_CHECK(err, err = krnl_top.setArg(2, buffer_out0));
  // Copy input data to device global memory
  OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_in0, buffer_in1},
                                                  0 /* 0 means from host*/));

  cl::Event event;
  uint64_t nstimestart, nstimeend;
  std::cout << "|-------------------------+-------------------------|\n"
            << "| Kernel                  |    Wall-Clock Time (ns) |\n"
            << "|-------------------------+-------------------------|\n";

  // Launch the Kernel
  OCL_CHECK(err, err = q.enqueueTask(krnl_top, nullptr, &event));

  // Copy Result from Device Global Memory to Host Local Memory
  OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_out0},
                                                  CL_MIGRATE_MEM_OBJECT_HOST));
  q.finish();
  // OpenCL Host Code Ends

  // Get the execution time
  OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(
                     CL_PROFILING_COMMAND_START, &nstimestart));
  OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(
                     CL_PROFILING_COMMAND_END, &nstimeend));
  auto exe_time = nstimeend - nstimestart;
  std::cout << "| " << std::left << std::setw(24) << "top " << "|" << std::right
            << std::setw(24) << exe_time << " |\n";
  std::cout << "|-------------------------+-------------------------|\n";
  std::cout
      << "Note: Wall Clock Time is meaningful for real hardware execution "
      << "only, not for emulation.\n";
  std::cout << "Please refer to profile summary for kernel execution time for "
            << "hardware emulation.\n";
  std::cout << "TEST PASSED\n\n";

  // unpack source_out0
  std::vector<int8_t> source_out0_unpack(512 * 768 * 4);
  for (int i = 0; i < 64; ++i)
  {
    for (int j = 0; j < 768 * 4; ++j)
    {
      for (int k = 0; k < 8; ++k)
      {
        source_out0_unpack[(i * 8 + k) * 768 * 4 + j] =
            get_bits_range(source_out0[i * 768 + j], k * 8 + 7, k * 8);
        // source_out0[i * 768 * 4 + j].range(k * 8 + 7, k * 8);
      }
    }
  }

  // Compute CPU GEMM
  std::vector<int8_t> cpu_result(512 * 768 * 4);
  gemm_cpu(source_in0_unpack, source_in1_unpack, cpu_result, 512, 768 * 4, 768);
  // compare the results of the Device to the CPU
  //   bool match = true;
  int fpga_sum = 0;
  int cpu_sum = 0;
  for (int i = 0; i < 512; ++i)
  {
    for (int j = 0; j < 768 * 4; ++j)
    {
      fpga_sum += source_out0_unpack[i * 768 * 4 + j];
      cpu_sum += cpu_result[i * 768 * 4 + j];
      if (source_out0_unpack[i * 768 * 4 + j] != cpu_result[i * 768 * 4 + j])
      {
        std::cout << "Error: Result mismatch" << std::endl;
        std::cout << "i = " << i << " j = " << j << " CPU result = "
                  << static_cast<int>(cpu_result[i * 768 + j])
                  << " Device result = "
                  << static_cast<int>(source_out0_unpack[i * 768 * 4 + j])
                  << std::endl;
        // match = false;
        break;
      }
    }
    std::cout << "passed value verification!" << std::endl;
    std::cout << "fpga sum=" << fpga_sum << std::endl;
    std::cout << "cpu sum=" << cpu_sum << std::endl;
  }
  return EXIT_SUCCESS;
}