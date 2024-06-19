#include <iostream>
#include <vector>

extern "C" {
    void matrix_multiply(float* A, float* B, float* C, int N) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                C[i * N + j] = 0;
                for (int k = 0; k < N; ++k) {
                    C[i * N + j] += A[i * N + k] * B[k * N + j];
                }
            }
        }
    }
}
