
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//
#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
using namespace std;

extern "C" {

void bias_add(
  float *v0,
  float *v1,
  float *v2
) {	// L2
  #pragma HLS interface m_axi port=v0 offset=slave bundle=gmem0
  #pragma HLS interface m_axi port=v1 offset=slave bundle=gmem1
  #pragma HLS interface m_axi port=v2 offset=slave bundle=gmem2
  float buf0[64][768];	//
  l_S_buf0_buf0_l_0: for (int buf0_l_0 = 0; buf0_l_0 < 64; buf0_l_0++) {	//
    l_buf0_l_1: for (int buf0_l_1 = 0; buf0_l_1 < 768; buf0_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v6 = v0[((buf0_l_0 * 768) + buf0_l_1)];	//
      buf0[buf0_l_0][buf0_l_1] = v6;	//
    }
  }
  float buf1[768];	//
  l_S_buf1_buf1_l_0: for (int buf1_l_0 = 0; buf1_l_0 < 768; buf1_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v9 = v1[buf1_l_0];	//
    buf1[buf1_l_0] = v9;	//
  }
  float Z[64][768];	// L3
  l_S_i_j_0_i: for (int i = 0; i < 64; i++) {	// L4
    l_j: for (int j = 0; j < 768; j++) {	// L5
      float v13 = buf0[i][j];	// L6
      float v14 = buf1[j];	// L7
      float v15 = v13 + v14;	// L8
      Z[i][j] = v15;	// L9
    }
  }
  l_S_result2_result2_l_0: for (int result2_l_0 = 0; result2_l_0 < 64; result2_l_0++) {	//
    l_result2_l_1: for (int result2_l_1 = 0; result2_l_1 < 768; result2_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v18 = Z[result2_l_0][result2_l_1];	//
      v2[((result2_l_0 * 768) + result2_l_1)] = v18;	//
    }
  }
}


} // extern "C"
