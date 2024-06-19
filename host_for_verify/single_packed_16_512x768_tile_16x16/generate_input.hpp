#ifndef GENERATE_INPUT_HPP
#define GENERATE_INPUT_HPP

#include "ap_int.h"
#include <vector>

template <typename Allocator>
void pack_matrix_A(const std::vector<int8_t> &matrixA,
                   std::vector<ap_int<128>, Allocator> &packedA, int rows,
                   int cols)
{
  packedA.clear();
  packedA.resize((rows * cols + 15) /
                 16); // a ap_int<128> can store 16* int8_t

  for (int i = 0; i < rows * cols; ++i)
  {
    int pack_idx = i / 16;
    int offset = i % 16;
    packedA[pack_idx].range((offset + 1) * 8 - 1, offset * 8) = matrixA[i];
  }
}

template <typename Allocator>
void pack_matrix_B(const std::vector<int8_t> &matrixB,
                   std::vector<ap_int<128>, Allocator> &packedB, int rows,
                   int cols)
{
  packedB.clear();
  packedB.resize((rows * cols + 15) /
                 16); // a ap_int<128> can store 16* int8_t

  for (int i = 0; i < rows * cols; ++i)
  {
    int pack_idx = i / 16;
    int offset = i % 16;
    packedB[pack_idx].range((offset + 1) * 8 - 1, offset * 8) = matrixB[i];
  }
}

template <typename Allocator>
void unpack_matrix_C(const std::vector<ap_int<128>, Allocator> &packedC,
                     std::vector<int8_t> &matrixC, int rows, int cols)
{
  matrixC.clear();
  matrixC.resize(rows * cols);

  for (int i = 0; i < rows * cols; ++i)
  {
    int pack_idx = i / 16;
    int offset = i % 16;
    matrixC[i] = static_cast<int8_t>(
        packedC[pack_idx].range((offset + 1) * 8 - 1, offset * 8).to_int());
  }
}

#endif // GENERATE_INPUT_HPP
