
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

void mask_softmax_per_head(
  float *v0,
  int32_t *v1,
  float *v2
) {	// L2
  #pragma HLS interface m_axi port=v0 offset=slave bundle=gmem0
  #pragma HLS interface m_axi port=v1 offset=slave bundle=gmem1
  #pragma HLS interface m_axi port=v2 offset=slave bundle=gmem2
  float buf0[64][64];	//
  l_S_buf0_buf0_l_0: for (int buf0_l_0 = 0; buf0_l_0 < 64; buf0_l_0++) {	//
    l_buf0_l_1: for (int buf0_l_1 = 0; buf0_l_1 < 64; buf0_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v6 = v0[((buf0_l_0 * 64) + buf0_l_1)];	//
      buf0[buf0_l_0][buf0_l_1] = v6;	//
    }
  }
  int32_t buf1[2];	//
  l_S_buf1_buf1_l_0: for (int buf1_l_0 = 0; buf1_l_0 < 2; buf1_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    int32_t v9 = v1[buf1_l_0];	//
    buf1[buf1_l_0] = v9;	//
  }
  float Z[64][64];	// L3
  float E[64][64];	// L4
  float S[64];	// L5
  for (int v13 = 0; v13 < 64; v13++) {	// L7
    S[v13] = 0.000000;	// L7
  }
  float M[64];	// L10
  for (int v15 = 0; v15 < 64; v15++) {	// L11
    M[v15] = -10000.000000;	// L11
  }
  l_row_max_i: for (int i = 0; i < 64; i++) {	// L12
    l_j: for (int j = 0; j < 64; j++) {	// L13
    #pragma HLS pipeline II=1
      bool v18 = i >= j;	// L14
      if (v18) {	// L15
        int32_t v19 = buf1[0];	// L16
        ap_int<33> v20 = v19;	// L19
        ap_int<33> v21 = 64 - v20;	// L20
        ap_int<33> v22 = i;	// L21
        bool v23 = v22 >= v21;	// L22
        if (v23) {	// L23
          int32_t v24 = buf1[0];	// L24
          ap_int<33> v25 = v24;	// L25
          ap_int<33> v26 = 64 - v25;	// L26
          ap_int<33> v27 = j;	// L27
          bool v28 = v27 >= v26;	// L28
          if (v28) {	// L29
            float v29 = buf0[i][j];	// L30
            float v30 = M[i];	// L31
            bool v31 = v29 > v30;	// L32
            if (v31) {	// L33
              float v32 = buf0[i][j];	// L34
              M[i] = v32;	// L35
            }
          }
        }
      }
    }
  }
  l_exp_sum_i1: for (int i1 = 0; i1 < 64; i1++) {	// L42
    l_j1: for (int j1 = 0; j1 < 64; j1++) {	// L43
    #pragma HLS pipeline II=1
      bool v35 = i1 >= j1;	// L44
      if (v35) {	// L45
        int32_t v36 = buf1[0];	// L46
        ap_int<33> v37 = v36;	// L49
        ap_int<33> v38 = 64 - v37;	// L50
        ap_int<33> v39 = i1;	// L51
        bool v40 = v39 >= v38;	// L52
        if (v40) {	// L53
          int32_t v41 = buf1[0];	// L54
          ap_int<33> v42 = v41;	// L55
          ap_int<33> v43 = 64 - v42;	// L56
          ap_int<33> v44 = j1;	// L57
          bool v45 = v44 >= v43;	// L58
          if (v45) {	// L59
            float v46 = buf0[i1][j1];	// L60
            float v47 = M[i1];	// L61
            float v48 = v46 - v47;	// L62
            float v49 = exp(v48);	// L63
            E[i1][j1] = v49;	// L64
            float v50 = E[i1][j1];	// L65
            float v51 = S[i1];	// L66
            float v52 = v51 + v50;	// L67
            S[i1] = v52;	// L68
          }
        }
      }
    }
  }
  l_update_i2: for (int i2 = 0; i2 < 64; i2++) {	// L74
    l_j2: for (int j2 = 0; j2 < 64; j2++) {	// L75
    #pragma HLS pipeline II=1
      bool v55 = i2 >= j2;	// L76
      if (v55) {	// L77
        int32_t v56 = buf1[0];	// L78
        ap_int<33> v57 = v56;	// L81
        ap_int<33> v58 = 64 - v57;	// L82
        ap_int<33> v59 = i2;	// L83
        bool v60 = v59 >= v58;	// L84
        if (v60) {	// L85
          int32_t v61 = buf1[0];	// L86
          ap_int<33> v62 = v61;	// L87
          ap_int<33> v63 = 64 - v62;	// L88
          ap_int<33> v64 = j2;	// L89
          bool v65 = v64 >= v63;	// L90
          if (v65) {	// L91
            float v66 = E[i2][j2];	// L92
            float v67 = S[i2];	// L93
            float v68 = v66 / v67;	// L94
            Z[i2][j2] = v68;	// L95
          } else {
            Z[i2][j2] = 0.000000;	// L99
          }
        } else {
          ap_int<34> v69 = i2;	// L102
          ap_int<34> v70 = v69 + 1;	// L105
          int32_t v71 = buf1[0];	// L106
          ap_int<35> v72 = v70;	// L107
          ap_int<35> v73 = v71;	// L108
          ap_int<35> v74 = v72 + v73;	// L109
          float v75 = v74;	// L110
          float v76 = 1.000000 / v75;	// L112
          Z[i2][j2] = v76;	// L113
        }
      } else {
        int32_t v77 = buf1[0];	// L116
        ap_int<33> v78 = v77;	// L119
        ap_int<33> v79 = 64 - v78;	// L120
        ap_int<33> v80 = i2;	// L121
        bool v81 = v80 < v79;	// L122
        ap_int<33> v82 = j2;	// L123
        bool v83 = v82 >= v79;	// L124
        bool v84 = v81 & v83;	// L125
        if (v84) {	// L126
          ap_int<34> v85 = i2;	// L127
          ap_int<34> v86 = v85 + 1;	// L130
          int32_t v87 = buf1[0];	// L131
          ap_int<35> v88 = v86;	// L132
          ap_int<35> v89 = v87;	// L133
          ap_int<35> v90 = v88 + v89;	// L134
          float v91 = v90;	// L135
          float v92 = 1.000000 / v91;	// L137
          Z[i2][j2] = v92;	// L138
        } else {
          Z[i2][j2] = 0.000000;	// L142
        }
      }
    }
  }
  l_S_result2_result2_l_0: for (int result2_l_0 = 0; result2_l_0 < 64; result2_l_0++) {	//
    l_result2_l_1: for (int result2_l_1 = 0; result2_l_1 < 64; result2_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v95 = Z[result2_l_0][result2_l_1];	//
      v2[((result2_l_0 * 64) + result2_l_1)] = v95;	//
    }
  }
}


} // extern "C"
