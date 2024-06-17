
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

void PE_kernel_QKT_0_0(
  hls::stream< float > &v0 /* v0[64] */,
  hls::stream< float > &v1 /* v1[64] */,
  hls::stream< float > &v2 /* v2[64] */,
  hls::stream< float > &v3 /* v3[64] */,
  float v4[8][8],
  int v5,
  int v6
) {	// L5
  #pragma HLS stream variable=v0 depth=9
  #pragma HLS stream variable=v1 depth=9
  #pragma HLS stream variable=v2 depth=9
  #pragma HLS stream variable=v3 depth=9
  #pragma HLS array_partition variable=v4 complete dim=1
  #pragma HLS array_partition variable=v4 complete dim=2

  float v;	// L8
  v = 0.000000;	// L9
  l_S_k_0_k: for (int k = 0; k < 64; k++) {	// L10
    float v9 = v0.read(); // v0[k];	// L11
    float a;	// L12
    a = v9;	// L13
    float v11 = v1.read(); // v1[k];	// L14
    float b;	// L15
    b = v11;	// L16
    float v13 = a;	// L17
    float v14 = b;	// L18
    float v15 = v13 * v14;	// L19
    float v16 = v;	// L20
    float v17 = v16 + v15;	// L21
    v = v17;	// L22
    float v18 = a;	// L23
    v2.write(v18); // v2[k] = v18;	// L24
    float v19 = b;	// L25
    v3.write(v19); // v3[k] = v19;	// L26
  }
  float v20 = v;	// L28
  v4[v5][v6] = v20;	// L29
}

void PE_kernel_QKT_1_0(
  hls::stream< float > &v21 /* v21[64] */,
  hls::stream< float > &v22 /* v22[64] */,
  hls::stream< float > &v23 /* v23[64] */,
  hls::stream< float > &v24 /* v24[64] */,
  float v25[8][8],
  int v26,
  int v27
) {	// L32
  #pragma HLS stream variable=v21 depth=9
  #pragma HLS stream variable=v22 depth=9
  #pragma HLS stream variable=v23 depth=9
  #pragma HLS stream variable=v24 depth=9
  #pragma HLS array_partition variable=v25 complete dim=1
  #pragma HLS array_partition variable=v25 complete dim=2

  float v1;	// L35
  v1 = 0.000000;	// L36
  l_S_k_0_k1: for (int k1 = 0; k1 < 64; k1++) {	// L37
    float v30 = v21.read(); // v21[k1];	// L38
    float a1;	// L39
    a1 = v30;	// L40
    float v32 = v22.read(); // v22[k1];	// L41
    float b1;	// L42
    b1 = v32;	// L43
    float v34 = a1;	// L44
    float v35 = b1;	// L45
    float v36 = v34 * v35;	// L46
    float v37 = v1;	// L47
    float v38 = v37 + v36;	// L48
    v1 = v38;	// L49
    float v39 = a1;	// L50
    v23.write(v39); // v23[k1] = v39;	// L51
    float v40 = b1;	// L52
    v24.write(v40); // v24[k1] = v40;	// L53
  }
  float v41 = v1;	// L55
  v25[v26][v27] = v41;	// L56
}

void PE_kernel_QKT_2_0(
  hls::stream< float > &v42 /* v42[64] */,
  hls::stream< float > &v43 /* v43[64] */,
  hls::stream< float > &v44 /* v44[64] */,
  hls::stream< float > &v45 /* v45[64] */,
  float v46[8][8],
  int v47,
  int v48
) {	// L59
  #pragma HLS stream variable=v42 depth=9
  #pragma HLS stream variable=v43 depth=9
  #pragma HLS stream variable=v44 depth=9
  #pragma HLS stream variable=v45 depth=9
  #pragma HLS array_partition variable=v46 complete dim=1
  #pragma HLS array_partition variable=v46 complete dim=2

  float v2;	// L62
  v2 = 0.000000;	// L63
  l_S_k_0_k2: for (int k2 = 0; k2 < 64; k2++) {	// L64
    float v51 = v42.read(); // v42[k2];	// L65
    float a2;	// L66
    a2 = v51;	// L67
    float v53 = v43.read(); // v43[k2];	// L68
    float b2;	// L69
    b2 = v53;	// L70
    float v55 = a2;	// L71
    float v56 = b2;	// L72
    float v57 = v55 * v56;	// L73
    float v58 = v2;	// L74
    float v59 = v58 + v57;	// L75
    v2 = v59;	// L76
    float v60 = a2;	// L77
    v44.write(v60); // v44[k2] = v60;	// L78
    float v61 = b2;	// L79
    v45.write(v61); // v45[k2] = v61;	// L80
  }
  float v62 = v2;	// L82
  v46[v47][v48] = v62;	// L83
}

void PE_kernel_QKT_3_0(
  hls::stream< float > &v63 /* v63[64] */,
  hls::stream< float > &v64 /* v64[64] */,
  hls::stream< float > &v65 /* v65[64] */,
  hls::stream< float > &v66 /* v66[64] */,
  float v67[8][8],
  int v68,
  int v69
) {	// L86
  #pragma HLS stream variable=v63 depth=9
  #pragma HLS stream variable=v64 depth=9
  #pragma HLS stream variable=v65 depth=9
  #pragma HLS stream variable=v66 depth=9
  #pragma HLS array_partition variable=v67 complete dim=1
  #pragma HLS array_partition variable=v67 complete dim=2

  float v3;	// L89
  v3 = 0.000000;	// L90
  l_S_k_0_k3: for (int k3 = 0; k3 < 64; k3++) {	// L91
    float v72 = v63.read(); // v63[k3];	// L92
    float a3;	// L93
    a3 = v72;	// L94
    float v74 = v64.read(); // v64[k3];	// L95
    float b3;	// L96
    b3 = v74;	// L97
    float v76 = a3;	// L98
    float v77 = b3;	// L99
    float v78 = v76 * v77;	// L100
    float v79 = v3;	// L101
    float v80 = v79 + v78;	// L102
    v3 = v80;	// L103
    float v81 = a3;	// L104
    v65.write(v81); // v65[k3] = v81;	// L105
    float v82 = b3;	// L106
    v66.write(v82); // v66[k3] = v82;	// L107
  }
  float v83 = v3;	// L109
  v67[v68][v69] = v83;	// L110
}

void PE_kernel_QKT_4_0(
  hls::stream< float > &v84 /* v84[64] */,
  hls::stream< float > &v85 /* v85[64] */,
  hls::stream< float > &v86 /* v86[64] */,
  hls::stream< float > &v87 /* v87[64] */,
  float v88[8][8],
  int v89,
  int v90
) {	// L113
  #pragma HLS stream variable=v84 depth=9
  #pragma HLS stream variable=v85 depth=9
  #pragma HLS stream variable=v86 depth=9
  #pragma HLS stream variable=v87 depth=9
  #pragma HLS array_partition variable=v88 complete dim=1
  #pragma HLS array_partition variable=v88 complete dim=2

  float v4;	// L116
  v4 = 0.000000;	// L117
  l_S_k_0_k4: for (int k4 = 0; k4 < 64; k4++) {	// L118
    float v93 = v84.read(); // v84[k4];	// L119
    float a4;	// L120
    a4 = v93;	// L121
    float v95 = v85.read(); // v85[k4];	// L122
    float b4;	// L123
    b4 = v95;	// L124
    float v97 = a4;	// L125
    float v98 = b4;	// L126
    float v99 = v97 * v98;	// L127
    float v100 = v4;	// L128
    float v101 = v100 + v99;	// L129
    v4 = v101;	// L130
    float v102 = a4;	// L131
    v86.write(v102); // v86[k4] = v102;	// L132
    float v103 = b4;	// L133
    v87.write(v103); // v87[k4] = v103;	// L134
  }
  float v104 = v4;	// L136
  v88[v89][v90] = v104;	// L137
}

void PE_kernel_QKT_5_0(
  hls::stream< float > &v105 /* v105[64] */,
  hls::stream< float > &v106 /* v106[64] */,
  hls::stream< float > &v107 /* v107[64] */,
  hls::stream< float > &v108 /* v108[64] */,
  float v109[8][8],
  int v110,
  int v111
) {	// L140
  #pragma HLS stream variable=v105 depth=9
  #pragma HLS stream variable=v106 depth=9
  #pragma HLS stream variable=v107 depth=9
  #pragma HLS stream variable=v108 depth=9
  #pragma HLS array_partition variable=v109 complete dim=1
  #pragma HLS array_partition variable=v109 complete dim=2

  float v5;	// L143
  v5 = 0.000000;	// L144
  l_S_k_0_k5: for (int k5 = 0; k5 < 64; k5++) {	// L145
    float v114 = v105.read(); // v105[k5];	// L146
    float a5;	// L147
    a5 = v114;	// L148
    float v116 = v106.read(); // v106[k5];	// L149
    float b5;	// L150
    b5 = v116;	// L151
    float v118 = a5;	// L152
    float v119 = b5;	// L153
    float v120 = v118 * v119;	// L154
    float v121 = v5;	// L155
    float v122 = v121 + v120;	// L156
    v5 = v122;	// L157
    float v123 = a5;	// L158
    v107.write(v123); // v107[k5] = v123;	// L159
    float v124 = b5;	// L160
    v108.write(v124); // v108[k5] = v124;	// L161
  }
  float v125 = v5;	// L163
  v109[v110][v111] = v125;	// L164
}

void PE_kernel_QKT_6_0(
  hls::stream< float > &v126 /* v126[64] */,
  hls::stream< float > &v127 /* v127[64] */,
  hls::stream< float > &v128 /* v128[64] */,
  hls::stream< float > &v129 /* v129[64] */,
  float v130[8][8],
  int v131,
  int v132
) {	// L167
  #pragma HLS stream variable=v126 depth=9
  #pragma HLS stream variable=v127 depth=9
  #pragma HLS stream variable=v128 depth=9
  #pragma HLS stream variable=v129 depth=9
  #pragma HLS array_partition variable=v130 complete dim=1
  #pragma HLS array_partition variable=v130 complete dim=2

  float v6;	// L170
  v6 = 0.000000;	// L171
  l_S_k_0_k6: for (int k6 = 0; k6 < 64; k6++) {	// L172
    float v135 = v126.read(); // v126[k6];	// L173
    float a6;	// L174
    a6 = v135;	// L175
    float v137 = v127.read(); // v127[k6];	// L176
    float b6;	// L177
    b6 = v137;	// L178
    float v139 = a6;	// L179
    float v140 = b6;	// L180
    float v141 = v139 * v140;	// L181
    float v142 = v6;	// L182
    float v143 = v142 + v141;	// L183
    v6 = v143;	// L184
    float v144 = a6;	// L185
    v128.write(v144); // v128[k6] = v144;	// L186
    float v145 = b6;	// L187
    v129.write(v145); // v129[k6] = v145;	// L188
  }
  float v146 = v6;	// L190
  v130[v131][v132] = v146;	// L191
}

void PE_kernel_QKT_7_0(
  hls::stream< float > &v147 /* v147[64] */,
  hls::stream< float > &v148 /* v148[64] */,
  hls::stream< float > &v149 /* v149[64] */,
  hls::stream< float > &v150 /* v150[64] */,
  float v151[8][8],
  int v152,
  int v153
) {	// L194
  #pragma HLS stream variable=v147 depth=9
  #pragma HLS stream variable=v148 depth=9
  #pragma HLS stream variable=v149 depth=9
  #pragma HLS stream variable=v150 depth=9
  #pragma HLS array_partition variable=v151 complete dim=1
  #pragma HLS array_partition variable=v151 complete dim=2

  float v7;	// L197
  v7 = 0.000000;	// L198
  l_S_k_0_k7: for (int k7 = 0; k7 < 64; k7++) {	// L199
    float v156 = v147.read(); // v147[k7];	// L200
    float a7;	// L201
    a7 = v156;	// L202
    float v158 = v148.read(); // v148[k7];	// L203
    float b7;	// L204
    b7 = v158;	// L205
    float v160 = a7;	// L206
    float v161 = b7;	// L207
    float v162 = v160 * v161;	// L208
    float v163 = v7;	// L209
    float v164 = v163 + v162;	// L210
    v7 = v164;	// L211
    float v165 = a7;	// L212
    v149.write(v165); // v149[k7] = v165;	// L213
    float v166 = b7;	// L214
    v150.write(v166); // v150[k7] = v166;	// L215
  }
  float v167 = v7;	// L217
  v151[v152][v153] = v167;	// L218
}

void PE_kernel_QKT_0_1(
  hls::stream< float > &v168 /* v168[64] */,
  hls::stream< float > &v169 /* v169[64] */,
  hls::stream< float > &v170 /* v170[64] */,
  hls::stream< float > &v171 /* v171[64] */,
  float v172[8][8],
  int v173,
  int v174
) {	// L221
  #pragma HLS stream variable=v168 depth=9
  #pragma HLS stream variable=v169 depth=9
  #pragma HLS stream variable=v170 depth=9
  #pragma HLS stream variable=v171 depth=9
  #pragma HLS array_partition variable=v172 complete dim=1
  #pragma HLS array_partition variable=v172 complete dim=2

  float v8;	// L224
  v8 = 0.000000;	// L225
  l_S_k_0_k8: for (int k8 = 0; k8 < 64; k8++) {	// L226
    float v177 = v168.read(); // v168[k8];	// L227
    float a8;	// L228
    a8 = v177;	// L229
    float v179 = v169.read(); // v169[k8];	// L230
    float b8;	// L231
    b8 = v179;	// L232
    float v181 = a8;	// L233
    float v182 = b8;	// L234
    float v183 = v181 * v182;	// L235
    float v184 = v8;	// L236
    float v185 = v184 + v183;	// L237
    v8 = v185;	// L238
    float v186 = a8;	// L239
    v170.write(v186); // v170[k8] = v186;	// L240
    float v187 = b8;	// L241
    v171.write(v187); // v171[k8] = v187;	// L242
  }
  float v188 = v8;	// L244
  v172[v173][v174] = v188;	// L245
}

void PE_kernel_QKT_1_1(
  hls::stream< float > &v189 /* v189[64] */,
  hls::stream< float > &v190 /* v190[64] */,
  hls::stream< float > &v191 /* v191[64] */,
  hls::stream< float > &v192 /* v192[64] */,
  float v193[8][8],
  int v194,
  int v195
) {	// L248
  #pragma HLS stream variable=v189 depth=9
  #pragma HLS stream variable=v190 depth=9
  #pragma HLS stream variable=v191 depth=9
  #pragma HLS stream variable=v192 depth=9
  #pragma HLS array_partition variable=v193 complete dim=1
  #pragma HLS array_partition variable=v193 complete dim=2

  float v9;	// L251
  v9 = 0.000000;	// L252
  l_S_k_0_k9: for (int k9 = 0; k9 < 64; k9++) {	// L253
    float v198 = v189.read(); // v189[k9];	// L254
    float a9;	// L255
    a9 = v198;	// L256
    float v200 = v190.read(); // v190[k9];	// L257
    float b9;	// L258
    b9 = v200;	// L259
    float v202 = a9;	// L260
    float v203 = b9;	// L261
    float v204 = v202 * v203;	// L262
    float v205 = v9;	// L263
    float v206 = v205 + v204;	// L264
    v9 = v206;	// L265
    float v207 = a9;	// L266
    v191.write(v207); // v191[k9] = v207;	// L267
    float v208 = b9;	// L268
    v192.write(v208); // v192[k9] = v208;	// L269
  }
  float v209 = v9;	// L271
  v193[v194][v195] = v209;	// L272
}

void PE_kernel_QKT_2_1(
  hls::stream< float > &v210 /* v210[64] */,
  hls::stream< float > &v211 /* v211[64] */,
  hls::stream< float > &v212 /* v212[64] */,
  hls::stream< float > &v213 /* v213[64] */,
  float v214[8][8],
  int v215,
  int v216
) {	// L275
  #pragma HLS stream variable=v210 depth=9
  #pragma HLS stream variable=v211 depth=9
  #pragma HLS stream variable=v212 depth=9
  #pragma HLS stream variable=v213 depth=9
  #pragma HLS array_partition variable=v214 complete dim=1
  #pragma HLS array_partition variable=v214 complete dim=2

  float v10;	// L278
  v10 = 0.000000;	// L279
  l_S_k_0_k10: for (int k10 = 0; k10 < 64; k10++) {	// L280
    float v219 = v210.read(); // v210[k10];	// L281
    float a10;	// L282
    a10 = v219;	// L283
    float v221 = v211.read(); // v211[k10];	// L284
    float b10;	// L285
    b10 = v221;	// L286
    float v223 = a10;	// L287
    float v224 = b10;	// L288
    float v225 = v223 * v224;	// L289
    float v226 = v10;	// L290
    float v227 = v226 + v225;	// L291
    v10 = v227;	// L292
    float v228 = a10;	// L293
    v212.write(v228); // v212[k10] = v228;	// L294
    float v229 = b10;	// L295
    v213.write(v229); // v213[k10] = v229;	// L296
  }
  float v230 = v10;	// L298
  v214[v215][v216] = v230;	// L299
}

void PE_kernel_QKT_3_1(
  hls::stream< float > &v231 /* v231[64] */,
  hls::stream< float > &v232 /* v232[64] */,
  hls::stream< float > &v233 /* v233[64] */,
  hls::stream< float > &v234 /* v234[64] */,
  float v235[8][8],
  int v236,
  int v237
) {	// L302
  #pragma HLS stream variable=v231 depth=9
  #pragma HLS stream variable=v232 depth=9
  #pragma HLS stream variable=v233 depth=9
  #pragma HLS stream variable=v234 depth=9
  #pragma HLS array_partition variable=v235 complete dim=1
  #pragma HLS array_partition variable=v235 complete dim=2

  float v11;	// L305
  v11 = 0.000000;	// L306
  l_S_k_0_k11: for (int k11 = 0; k11 < 64; k11++) {	// L307
    float v240 = v231.read(); // v231[k11];	// L308
    float a11;	// L309
    a11 = v240;	// L310
    float v242 = v232.read(); // v232[k11];	// L311
    float b11;	// L312
    b11 = v242;	// L313
    float v244 = a11;	// L314
    float v245 = b11;	// L315
    float v246 = v244 * v245;	// L316
    float v247 = v11;	// L317
    float v248 = v247 + v246;	// L318
    v11 = v248;	// L319
    float v249 = a11;	// L320
    v233.write(v249); // v233[k11] = v249;	// L321
    float v250 = b11;	// L322
    v234.write(v250); // v234[k11] = v250;	// L323
  }
  float v251 = v11;	// L325
  v235[v236][v237] = v251;	// L326
}

void PE_kernel_QKT_4_1(
  hls::stream< float > &v252 /* v252[64] */,
  hls::stream< float > &v253 /* v253[64] */,
  hls::stream< float > &v254 /* v254[64] */,
  hls::stream< float > &v255 /* v255[64] */,
  float v256[8][8],
  int v257,
  int v258
) {	// L329
  #pragma HLS stream variable=v252 depth=9
  #pragma HLS stream variable=v253 depth=9
  #pragma HLS stream variable=v254 depth=9
  #pragma HLS stream variable=v255 depth=9
  #pragma HLS array_partition variable=v256 complete dim=1
  #pragma HLS array_partition variable=v256 complete dim=2

  float v12;	// L332
  v12 = 0.000000;	// L333
  l_S_k_0_k12: for (int k12 = 0; k12 < 64; k12++) {	// L334
    float v261 = v252.read(); // v252[k12];	// L335
    float a12;	// L336
    a12 = v261;	// L337
    float v263 = v253.read(); // v253[k12];	// L338
    float b12;	// L339
    b12 = v263;	// L340
    float v265 = a12;	// L341
    float v266 = b12;	// L342
    float v267 = v265 * v266;	// L343
    float v268 = v12;	// L344
    float v269 = v268 + v267;	// L345
    v12 = v269;	// L346
    float v270 = a12;	// L347
    v254.write(v270); // v254[k12] = v270;	// L348
    float v271 = b12;	// L349
    v255.write(v271); // v255[k12] = v271;	// L350
  }
  float v272 = v12;	// L352
  v256[v257][v258] = v272;	// L353
}

void PE_kernel_QKT_5_1(
  hls::stream< float > &v273 /* v273[64] */,
  hls::stream< float > &v274 /* v274[64] */,
  hls::stream< float > &v275 /* v275[64] */,
  hls::stream< float > &v276 /* v276[64] */,
  float v277[8][8],
  int v278,
  int v279
) {	// L356
  #pragma HLS stream variable=v273 depth=9
  #pragma HLS stream variable=v274 depth=9
  #pragma HLS stream variable=v275 depth=9
  #pragma HLS stream variable=v276 depth=9
  #pragma HLS array_partition variable=v277 complete dim=1
  #pragma HLS array_partition variable=v277 complete dim=2

  float v13;	// L359
  v13 = 0.000000;	// L360
  l_S_k_0_k13: for (int k13 = 0; k13 < 64; k13++) {	// L361
    float v282 = v273.read(); // v273[k13];	// L362
    float a13;	// L363
    a13 = v282;	// L364
    float v284 = v274.read(); // v274[k13];	// L365
    float b13;	// L366
    b13 = v284;	// L367
    float v286 = a13;	// L368
    float v287 = b13;	// L369
    float v288 = v286 * v287;	// L370
    float v289 = v13;	// L371
    float v290 = v289 + v288;	// L372
    v13 = v290;	// L373
    float v291 = a13;	// L374
    v275.write(v291); // v275[k13] = v291;	// L375
    float v292 = b13;	// L376
    v276.write(v292); // v276[k13] = v292;	// L377
  }
  float v293 = v13;	// L379
  v277[v278][v279] = v293;	// L380
}

void PE_kernel_QKT_6_1(
  hls::stream< float > &v294 /* v294[64] */,
  hls::stream< float > &v295 /* v295[64] */,
  hls::stream< float > &v296 /* v296[64] */,
  hls::stream< float > &v297 /* v297[64] */,
  float v298[8][8],
  int v299,
  int v300
) {	// L383
  #pragma HLS stream variable=v294 depth=9
  #pragma HLS stream variable=v295 depth=9
  #pragma HLS stream variable=v296 depth=9
  #pragma HLS stream variable=v297 depth=9
  #pragma HLS array_partition variable=v298 complete dim=1
  #pragma HLS array_partition variable=v298 complete dim=2

  float v14;	// L386
  v14 = 0.000000;	// L387
  l_S_k_0_k14: for (int k14 = 0; k14 < 64; k14++) {	// L388
    float v303 = v294.read(); // v294[k14];	// L389
    float a14;	// L390
    a14 = v303;	// L391
    float v305 = v295.read(); // v295[k14];	// L392
    float b14;	// L393
    b14 = v305;	// L394
    float v307 = a14;	// L395
    float v308 = b14;	// L396
    float v309 = v307 * v308;	// L397
    float v310 = v14;	// L398
    float v311 = v310 + v309;	// L399
    v14 = v311;	// L400
    float v312 = a14;	// L401
    v296.write(v312); // v296[k14] = v312;	// L402
    float v313 = b14;	// L403
    v297.write(v313); // v297[k14] = v313;	// L404
  }
  float v314 = v14;	// L406
  v298[v299][v300] = v314;	// L407
}

void PE_kernel_QKT_7_1(
  hls::stream< float > &v315 /* v315[64] */,
  hls::stream< float > &v316 /* v316[64] */,
  hls::stream< float > &v317 /* v317[64] */,
  hls::stream< float > &v318 /* v318[64] */,
  float v319[8][8],
  int v320,
  int v321
) {	// L410
  #pragma HLS stream variable=v315 depth=9
  #pragma HLS stream variable=v316 depth=9
  #pragma HLS stream variable=v317 depth=9
  #pragma HLS stream variable=v318 depth=9
  #pragma HLS array_partition variable=v319 complete dim=1
  #pragma HLS array_partition variable=v319 complete dim=2

  float v15;	// L413
  v15 = 0.000000;	// L414
  l_S_k_0_k15: for (int k15 = 0; k15 < 64; k15++) {	// L415
    float v324 = v315.read(); // v315[k15];	// L416
    float a15;	// L417
    a15 = v324;	// L418
    float v326 = v316.read(); // v316[k15];	// L419
    float b15;	// L420
    b15 = v326;	// L421
    float v328 = a15;	// L422
    float v329 = b15;	// L423
    float v330 = v328 * v329;	// L424
    float v331 = v15;	// L425
    float v332 = v331 + v330;	// L426
    v15 = v332;	// L427
    float v333 = a15;	// L428
    v317.write(v333); // v317[k15] = v333;	// L429
    float v334 = b15;	// L430
    v318.write(v334); // v318[k15] = v334;	// L431
  }
  float v335 = v15;	// L433
  v319[v320][v321] = v335;	// L434
}

void PE_kernel_QKT_0_2(
  hls::stream< float > &v336 /* v336[64] */,
  hls::stream< float > &v337 /* v337[64] */,
  hls::stream< float > &v338 /* v338[64] */,
  hls::stream< float > &v339 /* v339[64] */,
  float v340[8][8],
  int v341,
  int v342
) {	// L437
  #pragma HLS stream variable=v336 depth=9
  #pragma HLS stream variable=v337 depth=9
  #pragma HLS stream variable=v338 depth=9
  #pragma HLS stream variable=v339 depth=9
  #pragma HLS array_partition variable=v340 complete dim=1
  #pragma HLS array_partition variable=v340 complete dim=2

  float v16;	// L440
  v16 = 0.000000;	// L441
  l_S_k_0_k16: for (int k16 = 0; k16 < 64; k16++) {	// L442
    float v345 = v336.read(); // v336[k16];	// L443
    float a16;	// L444
    a16 = v345;	// L445
    float v347 = v337.read(); // v337[k16];	// L446
    float b16;	// L447
    b16 = v347;	// L448
    float v349 = a16;	// L449
    float v350 = b16;	// L450
    float v351 = v349 * v350;	// L451
    float v352 = v16;	// L452
    float v353 = v352 + v351;	// L453
    v16 = v353;	// L454
    float v354 = a16;	// L455
    v338.write(v354); // v338[k16] = v354;	// L456
    float v355 = b16;	// L457
    v339.write(v355); // v339[k16] = v355;	// L458
  }
  float v356 = v16;	// L460
  v340[v341][v342] = v356;	// L461
}

void PE_kernel_QKT_1_2(
  hls::stream< float > &v357 /* v357[64] */,
  hls::stream< float > &v358 /* v358[64] */,
  hls::stream< float > &v359 /* v359[64] */,
  hls::stream< float > &v360 /* v360[64] */,
  float v361[8][8],
  int v362,
  int v363
) {	// L464
  #pragma HLS stream variable=v357 depth=9
  #pragma HLS stream variable=v358 depth=9
  #pragma HLS stream variable=v359 depth=9
  #pragma HLS stream variable=v360 depth=9
  #pragma HLS array_partition variable=v361 complete dim=1
  #pragma HLS array_partition variable=v361 complete dim=2

  float v17;	// L467
  v17 = 0.000000;	// L468
  l_S_k_0_k17: for (int k17 = 0; k17 < 64; k17++) {	// L469
    float v366 = v357.read(); // v357[k17];	// L470
    float a17;	// L471
    a17 = v366;	// L472
    float v368 = v358.read(); // v358[k17];	// L473
    float b17;	// L474
    b17 = v368;	// L475
    float v370 = a17;	// L476
    float v371 = b17;	// L477
    float v372 = v370 * v371;	// L478
    float v373 = v17;	// L479
    float v374 = v373 + v372;	// L480
    v17 = v374;	// L481
    float v375 = a17;	// L482
    v359.write(v375); // v359[k17] = v375;	// L483
    float v376 = b17;	// L484
    v360.write(v376); // v360[k17] = v376;	// L485
  }
  float v377 = v17;	// L487
  v361[v362][v363] = v377;	// L488
}

void PE_kernel_QKT_2_2(
  hls::stream< float > &v378 /* v378[64] */,
  hls::stream< float > &v379 /* v379[64] */,
  hls::stream< float > &v380 /* v380[64] */,
  hls::stream< float > &v381 /* v381[64] */,
  float v382[8][8],
  int v383,
  int v384
) {	// L491
  #pragma HLS stream variable=v378 depth=9
  #pragma HLS stream variable=v379 depth=9
  #pragma HLS stream variable=v380 depth=9
  #pragma HLS stream variable=v381 depth=9
  #pragma HLS array_partition variable=v382 complete dim=1
  #pragma HLS array_partition variable=v382 complete dim=2

  float v18;	// L494
  v18 = 0.000000;	// L495
  l_S_k_0_k18: for (int k18 = 0; k18 < 64; k18++) {	// L496
    float v387 = v378.read(); // v378[k18];	// L497
    float a18;	// L498
    a18 = v387;	// L499
    float v389 = v379.read(); // v379[k18];	// L500
    float b18;	// L501
    b18 = v389;	// L502
    float v391 = a18;	// L503
    float v392 = b18;	// L504
    float v393 = v391 * v392;	// L505
    float v394 = v18;	// L506
    float v395 = v394 + v393;	// L507
    v18 = v395;	// L508
    float v396 = a18;	// L509
    v380.write(v396); // v380[k18] = v396;	// L510
    float v397 = b18;	// L511
    v381.write(v397); // v381[k18] = v397;	// L512
  }
  float v398 = v18;	// L514
  v382[v383][v384] = v398;	// L515
}

void PE_kernel_QKT_3_2(
  hls::stream< float > &v399 /* v399[64] */,
  hls::stream< float > &v400 /* v400[64] */,
  hls::stream< float > &v401 /* v401[64] */,
  hls::stream< float > &v402 /* v402[64] */,
  float v403[8][8],
  int v404,
  int v405
) {	// L518
  #pragma HLS stream variable=v399 depth=9
  #pragma HLS stream variable=v400 depth=9
  #pragma HLS stream variable=v401 depth=9
  #pragma HLS stream variable=v402 depth=9
  #pragma HLS array_partition variable=v403 complete dim=1
  #pragma HLS array_partition variable=v403 complete dim=2

  float v19;	// L521
  v19 = 0.000000;	// L522
  l_S_k_0_k19: for (int k19 = 0; k19 < 64; k19++) {	// L523
    float v408 = v399.read(); // v399[k19];	// L524
    float a19;	// L525
    a19 = v408;	// L526
    float v410 = v400.read(); // v400[k19];	// L527
    float b19;	// L528
    b19 = v410;	// L529
    float v412 = a19;	// L530
    float v413 = b19;	// L531
    float v414 = v412 * v413;	// L532
    float v415 = v19;	// L533
    float v416 = v415 + v414;	// L534
    v19 = v416;	// L535
    float v417 = a19;	// L536
    v401.write(v417); // v401[k19] = v417;	// L537
    float v418 = b19;	// L538
    v402.write(v418); // v402[k19] = v418;	// L539
  }
  float v419 = v19;	// L541
  v403[v404][v405] = v419;	// L542
}

void PE_kernel_QKT_4_2(
  hls::stream< float > &v420 /* v420[64] */,
  hls::stream< float > &v421 /* v421[64] */,
  hls::stream< float > &v422 /* v422[64] */,
  hls::stream< float > &v423 /* v423[64] */,
  float v424[8][8],
  int v425,
  int v426
) {	// L545
  #pragma HLS stream variable=v420 depth=9
  #pragma HLS stream variable=v421 depth=9
  #pragma HLS stream variable=v422 depth=9
  #pragma HLS stream variable=v423 depth=9
  #pragma HLS array_partition variable=v424 complete dim=1
  #pragma HLS array_partition variable=v424 complete dim=2

  float v20;	// L548
  v20 = 0.000000;	// L549
  l_S_k_0_k20: for (int k20 = 0; k20 < 64; k20++) {	// L550
    float v429 = v420.read(); // v420[k20];	// L551
    float a20;	// L552
    a20 = v429;	// L553
    float v431 = v421.read(); // v421[k20];	// L554
    float b20;	// L555
    b20 = v431;	// L556
    float v433 = a20;	// L557
    float v434 = b20;	// L558
    float v435 = v433 * v434;	// L559
    float v436 = v20;	// L560
    float v437 = v436 + v435;	// L561
    v20 = v437;	// L562
    float v438 = a20;	// L563
    v422.write(v438); // v422[k20] = v438;	// L564
    float v439 = b20;	// L565
    v423.write(v439); // v423[k20] = v439;	// L566
  }
  float v440 = v20;	// L568
  v424[v425][v426] = v440;	// L569
}

void PE_kernel_QKT_5_2(
  hls::stream< float > &v441 /* v441[64] */,
  hls::stream< float > &v442 /* v442[64] */,
  hls::stream< float > &v443 /* v443[64] */,
  hls::stream< float > &v444 /* v444[64] */,
  float v445[8][8],
  int v446,
  int v447
) {	// L572
  #pragma HLS stream variable=v441 depth=9
  #pragma HLS stream variable=v442 depth=9
  #pragma HLS stream variable=v443 depth=9
  #pragma HLS stream variable=v444 depth=9
  #pragma HLS array_partition variable=v445 complete dim=1
  #pragma HLS array_partition variable=v445 complete dim=2

  float v21;	// L575
  v21 = 0.000000;	// L576
  l_S_k_0_k21: for (int k21 = 0; k21 < 64; k21++) {	// L577
    float v450 = v441.read(); // v441[k21];	// L578
    float a21;	// L579
    a21 = v450;	// L580
    float v452 = v442.read(); // v442[k21];	// L581
    float b21;	// L582
    b21 = v452;	// L583
    float v454 = a21;	// L584
    float v455 = b21;	// L585
    float v456 = v454 * v455;	// L586
    float v457 = v21;	// L587
    float v458 = v457 + v456;	// L588
    v21 = v458;	// L589
    float v459 = a21;	// L590
    v443.write(v459); // v443[k21] = v459;	// L591
    float v460 = b21;	// L592
    v444.write(v460); // v444[k21] = v460;	// L593
  }
  float v461 = v21;	// L595
  v445[v446][v447] = v461;	// L596
}

void PE_kernel_QKT_6_2(
  hls::stream< float > &v462 /* v462[64] */,
  hls::stream< float > &v463 /* v463[64] */,
  hls::stream< float > &v464 /* v464[64] */,
  hls::stream< float > &v465 /* v465[64] */,
  float v466[8][8],
  int v467,
  int v468
) {	// L599
  #pragma HLS stream variable=v462 depth=9
  #pragma HLS stream variable=v463 depth=9
  #pragma HLS stream variable=v464 depth=9
  #pragma HLS stream variable=v465 depth=9
  #pragma HLS array_partition variable=v466 complete dim=1
  #pragma HLS array_partition variable=v466 complete dim=2

  float v22;	// L602
  v22 = 0.000000;	// L603
  l_S_k_0_k22: for (int k22 = 0; k22 < 64; k22++) {	// L604
    float v471 = v462.read(); // v462[k22];	// L605
    float a22;	// L606
    a22 = v471;	// L607
    float v473 = v463.read(); // v463[k22];	// L608
    float b22;	// L609
    b22 = v473;	// L610
    float v475 = a22;	// L611
    float v476 = b22;	// L612
    float v477 = v475 * v476;	// L613
    float v478 = v22;	// L614
    float v479 = v478 + v477;	// L615
    v22 = v479;	// L616
    float v480 = a22;	// L617
    v464.write(v480); // v464[k22] = v480;	// L618
    float v481 = b22;	// L619
    v465.write(v481); // v465[k22] = v481;	// L620
  }
  float v482 = v22;	// L622
  v466[v467][v468] = v482;	// L623
}

void PE_kernel_QKT_7_2(
  hls::stream< float > &v483 /* v483[64] */,
  hls::stream< float > &v484 /* v484[64] */,
  hls::stream< float > &v485 /* v485[64] */,
  hls::stream< float > &v486 /* v486[64] */,
  float v487[8][8],
  int v488,
  int v489
) {	// L626
  #pragma HLS stream variable=v483 depth=9
  #pragma HLS stream variable=v484 depth=9
  #pragma HLS stream variable=v485 depth=9
  #pragma HLS stream variable=v486 depth=9
  #pragma HLS array_partition variable=v487 complete dim=1
  #pragma HLS array_partition variable=v487 complete dim=2

  float v23;	// L629
  v23 = 0.000000;	// L630
  l_S_k_0_k23: for (int k23 = 0; k23 < 64; k23++) {	// L631
    float v492 = v483.read(); // v483[k23];	// L632
    float a23;	// L633
    a23 = v492;	// L634
    float v494 = v484.read(); // v484[k23];	// L635
    float b23;	// L636
    b23 = v494;	// L637
    float v496 = a23;	// L638
    float v497 = b23;	// L639
    float v498 = v496 * v497;	// L640
    float v499 = v23;	// L641
    float v500 = v499 + v498;	// L642
    v23 = v500;	// L643
    float v501 = a23;	// L644
    v485.write(v501); // v485[k23] = v501;	// L645
    float v502 = b23;	// L646
    v486.write(v502); // v486[k23] = v502;	// L647
  }
  float v503 = v23;	// L649
  v487[v488][v489] = v503;	// L650
}

void PE_kernel_QKT_0_3(
  hls::stream< float > &v504 /* v504[64] */,
  hls::stream< float > &v505 /* v505[64] */,
  hls::stream< float > &v506 /* v506[64] */,
  hls::stream< float > &v507 /* v507[64] */,
  float v508[8][8],
  int v509,
  int v510
) {	// L653
  #pragma HLS stream variable=v504 depth=9
  #pragma HLS stream variable=v505 depth=9
  #pragma HLS stream variable=v506 depth=9
  #pragma HLS stream variable=v507 depth=9
  #pragma HLS array_partition variable=v508 complete dim=1
  #pragma HLS array_partition variable=v508 complete dim=2

  float v24;	// L656
  v24 = 0.000000;	// L657
  l_S_k_0_k24: for (int k24 = 0; k24 < 64; k24++) {	// L658
    float v513 = v504.read(); // v504[k24];	// L659
    float a24;	// L660
    a24 = v513;	// L661
    float v515 = v505.read(); // v505[k24];	// L662
    float b24;	// L663
    b24 = v515;	// L664
    float v517 = a24;	// L665
    float v518 = b24;	// L666
    float v519 = v517 * v518;	// L667
    float v520 = v24;	// L668
    float v521 = v520 + v519;	// L669
    v24 = v521;	// L670
    float v522 = a24;	// L671
    v506.write(v522); // v506[k24] = v522;	// L672
    float v523 = b24;	// L673
    v507.write(v523); // v507[k24] = v523;	// L674
  }
  float v524 = v24;	// L676
  v508[v509][v510] = v524;	// L677
}

void PE_kernel_QKT_1_3(
  hls::stream< float > &v525 /* v525[64] */,
  hls::stream< float > &v526 /* v526[64] */,
  hls::stream< float > &v527 /* v527[64] */,
  hls::stream< float > &v528 /* v528[64] */,
  float v529[8][8],
  int v530,
  int v531
) {	// L680
  #pragma HLS stream variable=v525 depth=9
  #pragma HLS stream variable=v526 depth=9
  #pragma HLS stream variable=v527 depth=9
  #pragma HLS stream variable=v528 depth=9
  #pragma HLS array_partition variable=v529 complete dim=1
  #pragma HLS array_partition variable=v529 complete dim=2

  float v25;	// L683
  v25 = 0.000000;	// L684
  l_S_k_0_k25: for (int k25 = 0; k25 < 64; k25++) {	// L685
    float v534 = v525.read(); // v525[k25];	// L686
    float a25;	// L687
    a25 = v534;	// L688
    float v536 = v526.read(); // v526[k25];	// L689
    float b25;	// L690
    b25 = v536;	// L691
    float v538 = a25;	// L692
    float v539 = b25;	// L693
    float v540 = v538 * v539;	// L694
    float v541 = v25;	// L695
    float v542 = v541 + v540;	// L696
    v25 = v542;	// L697
    float v543 = a25;	// L698
    v527.write(v543); // v527[k25] = v543;	// L699
    float v544 = b25;	// L700
    v528.write(v544); // v528[k25] = v544;	// L701
  }
  float v545 = v25;	// L703
  v529[v530][v531] = v545;	// L704
}

void PE_kernel_QKT_2_3(
  hls::stream< float > &v546 /* v546[64] */,
  hls::stream< float > &v547 /* v547[64] */,
  hls::stream< float > &v548 /* v548[64] */,
  hls::stream< float > &v549 /* v549[64] */,
  float v550[8][8],
  int v551,
  int v552
) {	// L707
  #pragma HLS stream variable=v546 depth=9
  #pragma HLS stream variable=v547 depth=9
  #pragma HLS stream variable=v548 depth=9
  #pragma HLS stream variable=v549 depth=9
  #pragma HLS array_partition variable=v550 complete dim=1
  #pragma HLS array_partition variable=v550 complete dim=2

  float v26;	// L710
  v26 = 0.000000;	// L711
  l_S_k_0_k26: for (int k26 = 0; k26 < 64; k26++) {	// L712
    float v555 = v546.read(); // v546[k26];	// L713
    float a26;	// L714
    a26 = v555;	// L715
    float v557 = v547.read(); // v547[k26];	// L716
    float b26;	// L717
    b26 = v557;	// L718
    float v559 = a26;	// L719
    float v560 = b26;	// L720
    float v561 = v559 * v560;	// L721
    float v562 = v26;	// L722
    float v563 = v562 + v561;	// L723
    v26 = v563;	// L724
    float v564 = a26;	// L725
    v548.write(v564); // v548[k26] = v564;	// L726
    float v565 = b26;	// L727
    v549.write(v565); // v549[k26] = v565;	// L728
  }
  float v566 = v26;	// L730
  v550[v551][v552] = v566;	// L731
}

void PE_kernel_QKT_3_3(
  hls::stream< float > &v567 /* v567[64] */,
  hls::stream< float > &v568 /* v568[64] */,
  hls::stream< float > &v569 /* v569[64] */,
  hls::stream< float > &v570 /* v570[64] */,
  float v571[8][8],
  int v572,
  int v573
) {	// L734
  #pragma HLS stream variable=v567 depth=9
  #pragma HLS stream variable=v568 depth=9
  #pragma HLS stream variable=v569 depth=9
  #pragma HLS stream variable=v570 depth=9
  #pragma HLS array_partition variable=v571 complete dim=1
  #pragma HLS array_partition variable=v571 complete dim=2

  float v27;	// L737
  v27 = 0.000000;	// L738
  l_S_k_0_k27: for (int k27 = 0; k27 < 64; k27++) {	// L739
    float v576 = v567.read(); // v567[k27];	// L740
    float a27;	// L741
    a27 = v576;	// L742
    float v578 = v568.read(); // v568[k27];	// L743
    float b27;	// L744
    b27 = v578;	// L745
    float v580 = a27;	// L746
    float v581 = b27;	// L747
    float v582 = v580 * v581;	// L748
    float v583 = v27;	// L749
    float v584 = v583 + v582;	// L750
    v27 = v584;	// L751
    float v585 = a27;	// L752
    v569.write(v585); // v569[k27] = v585;	// L753
    float v586 = b27;	// L754
    v570.write(v586); // v570[k27] = v586;	// L755
  }
  float v587 = v27;	// L757
  v571[v572][v573] = v587;	// L758
}

void PE_kernel_QKT_4_3(
  hls::stream< float > &v588 /* v588[64] */,
  hls::stream< float > &v589 /* v589[64] */,
  hls::stream< float > &v590 /* v590[64] */,
  hls::stream< float > &v591 /* v591[64] */,
  float v592[8][8],
  int v593,
  int v594
) {	// L761
  #pragma HLS stream variable=v588 depth=9
  #pragma HLS stream variable=v589 depth=9
  #pragma HLS stream variable=v590 depth=9
  #pragma HLS stream variable=v591 depth=9
  #pragma HLS array_partition variable=v592 complete dim=1
  #pragma HLS array_partition variable=v592 complete dim=2

  float v28;	// L764
  v28 = 0.000000;	// L765
  l_S_k_0_k28: for (int k28 = 0; k28 < 64; k28++) {	// L766
    float v597 = v588.read(); // v588[k28];	// L767
    float a28;	// L768
    a28 = v597;	// L769
    float v599 = v589.read(); // v589[k28];	// L770
    float b28;	// L771
    b28 = v599;	// L772
    float v601 = a28;	// L773
    float v602 = b28;	// L774
    float v603 = v601 * v602;	// L775
    float v604 = v28;	// L776
    float v605 = v604 + v603;	// L777
    v28 = v605;	// L778
    float v606 = a28;	// L779
    v590.write(v606); // v590[k28] = v606;	// L780
    float v607 = b28;	// L781
    v591.write(v607); // v591[k28] = v607;	// L782
  }
  float v608 = v28;	// L784
  v592[v593][v594] = v608;	// L785
}

void PE_kernel_QKT_5_3(
  hls::stream< float > &v609 /* v609[64] */,
  hls::stream< float > &v610 /* v610[64] */,
  hls::stream< float > &v611 /* v611[64] */,
  hls::stream< float > &v612 /* v612[64] */,
  float v613[8][8],
  int v614,
  int v615
) {	// L788
  #pragma HLS stream variable=v609 depth=9
  #pragma HLS stream variable=v610 depth=9
  #pragma HLS stream variable=v611 depth=9
  #pragma HLS stream variable=v612 depth=9
  #pragma HLS array_partition variable=v613 complete dim=1
  #pragma HLS array_partition variable=v613 complete dim=2

  float v29;	// L791
  v29 = 0.000000;	// L792
  l_S_k_0_k29: for (int k29 = 0; k29 < 64; k29++) {	// L793
    float v618 = v609.read(); // v609[k29];	// L794
    float a29;	// L795
    a29 = v618;	// L796
    float v620 = v610.read(); // v610[k29];	// L797
    float b29;	// L798
    b29 = v620;	// L799
    float v622 = a29;	// L800
    float v623 = b29;	// L801
    float v624 = v622 * v623;	// L802
    float v625 = v29;	// L803
    float v626 = v625 + v624;	// L804
    v29 = v626;	// L805
    float v627 = a29;	// L806
    v611.write(v627); // v611[k29] = v627;	// L807
    float v628 = b29;	// L808
    v612.write(v628); // v612[k29] = v628;	// L809
  }
  float v629 = v29;	// L811
  v613[v614][v615] = v629;	// L812
}

void PE_kernel_QKT_6_3(
  hls::stream< float > &v630 /* v630[64] */,
  hls::stream< float > &v631 /* v631[64] */,
  hls::stream< float > &v632 /* v632[64] */,
  hls::stream< float > &v633 /* v633[64] */,
  float v634[8][8],
  int v635,
  int v636
) {	// L815
  #pragma HLS stream variable=v630 depth=9
  #pragma HLS stream variable=v631 depth=9
  #pragma HLS stream variable=v632 depth=9
  #pragma HLS stream variable=v633 depth=9
  #pragma HLS array_partition variable=v634 complete dim=1
  #pragma HLS array_partition variable=v634 complete dim=2

  float v30;	// L818
  v30 = 0.000000;	// L819
  l_S_k_0_k30: for (int k30 = 0; k30 < 64; k30++) {	// L820
    float v639 = v630.read(); // v630[k30];	// L821
    float a30;	// L822
    a30 = v639;	// L823
    float v641 = v631.read(); // v631[k30];	// L824
    float b30;	// L825
    b30 = v641;	// L826
    float v643 = a30;	// L827
    float v644 = b30;	// L828
    float v645 = v643 * v644;	// L829
    float v646 = v30;	// L830
    float v647 = v646 + v645;	// L831
    v30 = v647;	// L832
    float v648 = a30;	// L833
    v632.write(v648); // v632[k30] = v648;	// L834
    float v649 = b30;	// L835
    v633.write(v649); // v633[k30] = v649;	// L836
  }
  float v650 = v30;	// L838
  v634[v635][v636] = v650;	// L839
}

void PE_kernel_QKT_7_3(
  hls::stream< float > &v651 /* v651[64] */,
  hls::stream< float > &v652 /* v652[64] */,
  hls::stream< float > &v653 /* v653[64] */,
  hls::stream< float > &v654 /* v654[64] */,
  float v655[8][8],
  int v656,
  int v657
) {	// L842
  #pragma HLS stream variable=v651 depth=9
  #pragma HLS stream variable=v652 depth=9
  #pragma HLS stream variable=v653 depth=9
  #pragma HLS stream variable=v654 depth=9
  #pragma HLS array_partition variable=v655 complete dim=1
  #pragma HLS array_partition variable=v655 complete dim=2

  float v31;	// L845
  v31 = 0.000000;	// L846
  l_S_k_0_k31: for (int k31 = 0; k31 < 64; k31++) {	// L847
    float v660 = v651.read(); // v651[k31];	// L848
    float a31;	// L849
    a31 = v660;	// L850
    float v662 = v652.read(); // v652[k31];	// L851
    float b31;	// L852
    b31 = v662;	// L853
    float v664 = a31;	// L854
    float v665 = b31;	// L855
    float v666 = v664 * v665;	// L856
    float v667 = v31;	// L857
    float v668 = v667 + v666;	// L858
    v31 = v668;	// L859
    float v669 = a31;	// L860
    v653.write(v669); // v653[k31] = v669;	// L861
    float v670 = b31;	// L862
    v654.write(v670); // v654[k31] = v670;	// L863
  }
  float v671 = v31;	// L865
  v655[v656][v657] = v671;	// L866
}

void PE_kernel_QKT_0_4(
  hls::stream< float > &v672 /* v672[64] */,
  hls::stream< float > &v673 /* v673[64] */,
  hls::stream< float > &v674 /* v674[64] */,
  hls::stream< float > &v675 /* v675[64] */,
  float v676[8][8],
  int v677,
  int v678
) {	// L869
  #pragma HLS stream variable=v672 depth=9
  #pragma HLS stream variable=v673 depth=9
  #pragma HLS stream variable=v674 depth=9
  #pragma HLS stream variable=v675 depth=9
  #pragma HLS array_partition variable=v676 complete dim=1
  #pragma HLS array_partition variable=v676 complete dim=2

  float v32;	// L872
  v32 = 0.000000;	// L873
  l_S_k_0_k32: for (int k32 = 0; k32 < 64; k32++) {	// L874
    float v681 = v672.read(); // v672[k32];	// L875
    float a32;	// L876
    a32 = v681;	// L877
    float v683 = v673.read(); // v673[k32];	// L878
    float b32;	// L879
    b32 = v683;	// L880
    float v685 = a32;	// L881
    float v686 = b32;	// L882
    float v687 = v685 * v686;	// L883
    float v688 = v32;	// L884
    float v689 = v688 + v687;	// L885
    v32 = v689;	// L886
    float v690 = a32;	// L887
    v674.write(v690); // v674[k32] = v690;	// L888
    float v691 = b32;	// L889
    v675.write(v691); // v675[k32] = v691;	// L890
  }
  float v692 = v32;	// L892
  v676[v677][v678] = v692;	// L893
}

void PE_kernel_QKT_1_4(
  hls::stream< float > &v693 /* v693[64] */,
  hls::stream< float > &v694 /* v694[64] */,
  hls::stream< float > &v695 /* v695[64] */,
  hls::stream< float > &v696 /* v696[64] */,
  float v697[8][8],
  int v698,
  int v699
) {	// L896
  #pragma HLS stream variable=v693 depth=9
  #pragma HLS stream variable=v694 depth=9
  #pragma HLS stream variable=v695 depth=9
  #pragma HLS stream variable=v696 depth=9
  #pragma HLS array_partition variable=v697 complete dim=1
  #pragma HLS array_partition variable=v697 complete dim=2

  float v33;	// L899
  v33 = 0.000000;	// L900
  l_S_k_0_k33: for (int k33 = 0; k33 < 64; k33++) {	// L901
    float v702 = v693.read(); // v693[k33];	// L902
    float a33;	// L903
    a33 = v702;	// L904
    float v704 = v694.read(); // v694[k33];	// L905
    float b33;	// L906
    b33 = v704;	// L907
    float v706 = a33;	// L908
    float v707 = b33;	// L909
    float v708 = v706 * v707;	// L910
    float v709 = v33;	// L911
    float v710 = v709 + v708;	// L912
    v33 = v710;	// L913
    float v711 = a33;	// L914
    v695.write(v711); // v695[k33] = v711;	// L915
    float v712 = b33;	// L916
    v696.write(v712); // v696[k33] = v712;	// L917
  }
  float v713 = v33;	// L919
  v697[v698][v699] = v713;	// L920
}

void PE_kernel_QKT_2_4(
  hls::stream< float > &v714 /* v714[64] */,
  hls::stream< float > &v715 /* v715[64] */,
  hls::stream< float > &v716 /* v716[64] */,
  hls::stream< float > &v717 /* v717[64] */,
  float v718[8][8],
  int v719,
  int v720
) {	// L923
  #pragma HLS stream variable=v714 depth=9
  #pragma HLS stream variable=v715 depth=9
  #pragma HLS stream variable=v716 depth=9
  #pragma HLS stream variable=v717 depth=9
  #pragma HLS array_partition variable=v718 complete dim=1
  #pragma HLS array_partition variable=v718 complete dim=2

  float v34;	// L926
  v34 = 0.000000;	// L927
  l_S_k_0_k34: for (int k34 = 0; k34 < 64; k34++) {	// L928
    float v723 = v714.read(); // v714[k34];	// L929
    float a34;	// L930
    a34 = v723;	// L931
    float v725 = v715.read(); // v715[k34];	// L932
    float b34;	// L933
    b34 = v725;	// L934
    float v727 = a34;	// L935
    float v728 = b34;	// L936
    float v729 = v727 * v728;	// L937
    float v730 = v34;	// L938
    float v731 = v730 + v729;	// L939
    v34 = v731;	// L940
    float v732 = a34;	// L941
    v716.write(v732); // v716[k34] = v732;	// L942
    float v733 = b34;	// L943
    v717.write(v733); // v717[k34] = v733;	// L944
  }
  float v734 = v34;	// L946
  v718[v719][v720] = v734;	// L947
}

void PE_kernel_QKT_3_4(
  hls::stream< float > &v735 /* v735[64] */,
  hls::stream< float > &v736 /* v736[64] */,
  hls::stream< float > &v737 /* v737[64] */,
  hls::stream< float > &v738 /* v738[64] */,
  float v739[8][8],
  int v740,
  int v741
) {	// L950
  #pragma HLS stream variable=v735 depth=9
  #pragma HLS stream variable=v736 depth=9
  #pragma HLS stream variable=v737 depth=9
  #pragma HLS stream variable=v738 depth=9
  #pragma HLS array_partition variable=v739 complete dim=1
  #pragma HLS array_partition variable=v739 complete dim=2

  float v35;	// L953
  v35 = 0.000000;	// L954
  l_S_k_0_k35: for (int k35 = 0; k35 < 64; k35++) {	// L955
    float v744 = v735.read(); // v735[k35];	// L956
    float a35;	// L957
    a35 = v744;	// L958
    float v746 = v736.read(); // v736[k35];	// L959
    float b35;	// L960
    b35 = v746;	// L961
    float v748 = a35;	// L962
    float v749 = b35;	// L963
    float v750 = v748 * v749;	// L964
    float v751 = v35;	// L965
    float v752 = v751 + v750;	// L966
    v35 = v752;	// L967
    float v753 = a35;	// L968
    v737.write(v753); // v737[k35] = v753;	// L969
    float v754 = b35;	// L970
    v738.write(v754); // v738[k35] = v754;	// L971
  }
  float v755 = v35;	// L973
  v739[v740][v741] = v755;	// L974
}

void PE_kernel_QKT_4_4(
  hls::stream< float > &v756 /* v756[64] */,
  hls::stream< float > &v757 /* v757[64] */,
  hls::stream< float > &v758 /* v758[64] */,
  hls::stream< float > &v759 /* v759[64] */,
  float v760[8][8],
  int v761,
  int v762
) {	// L977
  #pragma HLS stream variable=v756 depth=9
  #pragma HLS stream variable=v757 depth=9
  #pragma HLS stream variable=v758 depth=9
  #pragma HLS stream variable=v759 depth=9
  #pragma HLS array_partition variable=v760 complete dim=1
  #pragma HLS array_partition variable=v760 complete dim=2

  float v36;	// L980
  v36 = 0.000000;	// L981
  l_S_k_0_k36: for (int k36 = 0; k36 < 64; k36++) {	// L982
    float v765 = v756.read(); // v756[k36];	// L983
    float a36;	// L984
    a36 = v765;	// L985
    float v767 = v757.read(); // v757[k36];	// L986
    float b36;	// L987
    b36 = v767;	// L988
    float v769 = a36;	// L989
    float v770 = b36;	// L990
    float v771 = v769 * v770;	// L991
    float v772 = v36;	// L992
    float v773 = v772 + v771;	// L993
    v36 = v773;	// L994
    float v774 = a36;	// L995
    v758.write(v774); // v758[k36] = v774;	// L996
    float v775 = b36;	// L997
    v759.write(v775); // v759[k36] = v775;	// L998
  }
  float v776 = v36;	// L1000
  v760[v761][v762] = v776;	// L1001
}

void PE_kernel_QKT_5_4(
  hls::stream< float > &v777 /* v777[64] */,
  hls::stream< float > &v778 /* v778[64] */,
  hls::stream< float > &v779 /* v779[64] */,
  hls::stream< float > &v780 /* v780[64] */,
  float v781[8][8],
  int v782,
  int v783
) {	// L1004
  #pragma HLS stream variable=v777 depth=9
  #pragma HLS stream variable=v778 depth=9
  #pragma HLS stream variable=v779 depth=9
  #pragma HLS stream variable=v780 depth=9
  #pragma HLS array_partition variable=v781 complete dim=1
  #pragma HLS array_partition variable=v781 complete dim=2

  float v37;	// L1007
  v37 = 0.000000;	// L1008
  l_S_k_0_k37: for (int k37 = 0; k37 < 64; k37++) {	// L1009
    float v786 = v777.read(); // v777[k37];	// L1010
    float a37;	// L1011
    a37 = v786;	// L1012
    float v788 = v778.read(); // v778[k37];	// L1013
    float b37;	// L1014
    b37 = v788;	// L1015
    float v790 = a37;	// L1016
    float v791 = b37;	// L1017
    float v792 = v790 * v791;	// L1018
    float v793 = v37;	// L1019
    float v794 = v793 + v792;	// L1020
    v37 = v794;	// L1021
    float v795 = a37;	// L1022
    v779.write(v795); // v779[k37] = v795;	// L1023
    float v796 = b37;	// L1024
    v780.write(v796); // v780[k37] = v796;	// L1025
  }
  float v797 = v37;	// L1027
  v781[v782][v783] = v797;	// L1028
}

void PE_kernel_QKT_6_4(
  hls::stream< float > &v798 /* v798[64] */,
  hls::stream< float > &v799 /* v799[64] */,
  hls::stream< float > &v800 /* v800[64] */,
  hls::stream< float > &v801 /* v801[64] */,
  float v802[8][8],
  int v803,
  int v804
) {	// L1031
  #pragma HLS stream variable=v798 depth=9
  #pragma HLS stream variable=v799 depth=9
  #pragma HLS stream variable=v800 depth=9
  #pragma HLS stream variable=v801 depth=9
  #pragma HLS array_partition variable=v802 complete dim=1
  #pragma HLS array_partition variable=v802 complete dim=2

  float v38;	// L1034
  v38 = 0.000000;	// L1035
  l_S_k_0_k38: for (int k38 = 0; k38 < 64; k38++) {	// L1036
    float v807 = v798.read(); // v798[k38];	// L1037
    float a38;	// L1038
    a38 = v807;	// L1039
    float v809 = v799.read(); // v799[k38];	// L1040
    float b38;	// L1041
    b38 = v809;	// L1042
    float v811 = a38;	// L1043
    float v812 = b38;	// L1044
    float v813 = v811 * v812;	// L1045
    float v814 = v38;	// L1046
    float v815 = v814 + v813;	// L1047
    v38 = v815;	// L1048
    float v816 = a38;	// L1049
    v800.write(v816); // v800[k38] = v816;	// L1050
    float v817 = b38;	// L1051
    v801.write(v817); // v801[k38] = v817;	// L1052
  }
  float v818 = v38;	// L1054
  v802[v803][v804] = v818;	// L1055
}

void PE_kernel_QKT_7_4(
  hls::stream< float > &v819 /* v819[64] */,
  hls::stream< float > &v820 /* v820[64] */,
  hls::stream< float > &v821 /* v821[64] */,
  hls::stream< float > &v822 /* v822[64] */,
  float v823[8][8],
  int v824,
  int v825
) {	// L1058
  #pragma HLS stream variable=v819 depth=9
  #pragma HLS stream variable=v820 depth=9
  #pragma HLS stream variable=v821 depth=9
  #pragma HLS stream variable=v822 depth=9
  #pragma HLS array_partition variable=v823 complete dim=1
  #pragma HLS array_partition variable=v823 complete dim=2

  float v39;	// L1061
  v39 = 0.000000;	// L1062
  l_S_k_0_k39: for (int k39 = 0; k39 < 64; k39++) {	// L1063
    float v828 = v819.read(); // v819[k39];	// L1064
    float a39;	// L1065
    a39 = v828;	// L1066
    float v830 = v820.read(); // v820[k39];	// L1067
    float b39;	// L1068
    b39 = v830;	// L1069
    float v832 = a39;	// L1070
    float v833 = b39;	// L1071
    float v834 = v832 * v833;	// L1072
    float v835 = v39;	// L1073
    float v836 = v835 + v834;	// L1074
    v39 = v836;	// L1075
    float v837 = a39;	// L1076
    v821.write(v837); // v821[k39] = v837;	// L1077
    float v838 = b39;	// L1078
    v822.write(v838); // v822[k39] = v838;	// L1079
  }
  float v839 = v39;	// L1081
  v823[v824][v825] = v839;	// L1082
}

void PE_kernel_QKT_0_5(
  hls::stream< float > &v840 /* v840[64] */,
  hls::stream< float > &v841 /* v841[64] */,
  hls::stream< float > &v842 /* v842[64] */,
  hls::stream< float > &v843 /* v843[64] */,
  float v844[8][8],
  int v845,
  int v846
) {	// L1085
  #pragma HLS stream variable=v840 depth=9
  #pragma HLS stream variable=v841 depth=9
  #pragma HLS stream variable=v842 depth=9
  #pragma HLS stream variable=v843 depth=9
  #pragma HLS array_partition variable=v844 complete dim=1
  #pragma HLS array_partition variable=v844 complete dim=2

  float v40;	// L1088
  v40 = 0.000000;	// L1089
  l_S_k_0_k40: for (int k40 = 0; k40 < 64; k40++) {	// L1090
    float v849 = v840.read(); // v840[k40];	// L1091
    float a40;	// L1092
    a40 = v849;	// L1093
    float v851 = v841.read(); // v841[k40];	// L1094
    float b40;	// L1095
    b40 = v851;	// L1096
    float v853 = a40;	// L1097
    float v854 = b40;	// L1098
    float v855 = v853 * v854;	// L1099
    float v856 = v40;	// L1100
    float v857 = v856 + v855;	// L1101
    v40 = v857;	// L1102
    float v858 = a40;	// L1103
    v842.write(v858); // v842[k40] = v858;	// L1104
    float v859 = b40;	// L1105
    v843.write(v859); // v843[k40] = v859;	// L1106
  }
  float v860 = v40;	// L1108
  v844[v845][v846] = v860;	// L1109
}

void PE_kernel_QKT_1_5(
  hls::stream< float > &v861 /* v861[64] */,
  hls::stream< float > &v862 /* v862[64] */,
  hls::stream< float > &v863 /* v863[64] */,
  hls::stream< float > &v864 /* v864[64] */,
  float v865[8][8],
  int v866,
  int v867
) {	// L1112
  #pragma HLS stream variable=v861 depth=9
  #pragma HLS stream variable=v862 depth=9
  #pragma HLS stream variable=v863 depth=9
  #pragma HLS stream variable=v864 depth=9
  #pragma HLS array_partition variable=v865 complete dim=1
  #pragma HLS array_partition variable=v865 complete dim=2

  float v41;	// L1115
  v41 = 0.000000;	// L1116
  l_S_k_0_k41: for (int k41 = 0; k41 < 64; k41++) {	// L1117
    float v870 = v861.read(); // v861[k41];	// L1118
    float a41;	// L1119
    a41 = v870;	// L1120
    float v872 = v862.read(); // v862[k41];	// L1121
    float b41;	// L1122
    b41 = v872;	// L1123
    float v874 = a41;	// L1124
    float v875 = b41;	// L1125
    float v876 = v874 * v875;	// L1126
    float v877 = v41;	// L1127
    float v878 = v877 + v876;	// L1128
    v41 = v878;	// L1129
    float v879 = a41;	// L1130
    v863.write(v879); // v863[k41] = v879;	// L1131
    float v880 = b41;	// L1132
    v864.write(v880); // v864[k41] = v880;	// L1133
  }
  float v881 = v41;	// L1135
  v865[v866][v867] = v881;	// L1136
}

void PE_kernel_QKT_2_5(
  hls::stream< float > &v882 /* v882[64] */,
  hls::stream< float > &v883 /* v883[64] */,
  hls::stream< float > &v884 /* v884[64] */,
  hls::stream< float > &v885 /* v885[64] */,
  float v886[8][8],
  int v887,
  int v888
) {	// L1139
  #pragma HLS stream variable=v882 depth=9
  #pragma HLS stream variable=v883 depth=9
  #pragma HLS stream variable=v884 depth=9
  #pragma HLS stream variable=v885 depth=9
  #pragma HLS array_partition variable=v886 complete dim=1
  #pragma HLS array_partition variable=v886 complete dim=2

  float v42;	// L1142
  v42 = 0.000000;	// L1143
  l_S_k_0_k42: for (int k42 = 0; k42 < 64; k42++) {	// L1144
    float v891 = v882.read(); // v882[k42];	// L1145
    float a42;	// L1146
    a42 = v891;	// L1147
    float v893 = v883.read(); // v883[k42];	// L1148
    float b42;	// L1149
    b42 = v893;	// L1150
    float v895 = a42;	// L1151
    float v896 = b42;	// L1152
    float v897 = v895 * v896;	// L1153
    float v898 = v42;	// L1154
    float v899 = v898 + v897;	// L1155
    v42 = v899;	// L1156
    float v900 = a42;	// L1157
    v884.write(v900); // v884[k42] = v900;	// L1158
    float v901 = b42;	// L1159
    v885.write(v901); // v885[k42] = v901;	// L1160
  }
  float v902 = v42;	// L1162
  v886[v887][v888] = v902;	// L1163
}

void PE_kernel_QKT_3_5(
  hls::stream< float > &v903 /* v903[64] */,
  hls::stream< float > &v904 /* v904[64] */,
  hls::stream< float > &v905 /* v905[64] */,
  hls::stream< float > &v906 /* v906[64] */,
  float v907[8][8],
  int v908,
  int v909
) {	// L1166
  #pragma HLS stream variable=v903 depth=9
  #pragma HLS stream variable=v904 depth=9
  #pragma HLS stream variable=v905 depth=9
  #pragma HLS stream variable=v906 depth=9
  #pragma HLS array_partition variable=v907 complete dim=1
  #pragma HLS array_partition variable=v907 complete dim=2

  float v43;	// L1169
  v43 = 0.000000;	// L1170
  l_S_k_0_k43: for (int k43 = 0; k43 < 64; k43++) {	// L1171
    float v912 = v903.read(); // v903[k43];	// L1172
    float a43;	// L1173
    a43 = v912;	// L1174
    float v914 = v904.read(); // v904[k43];	// L1175
    float b43;	// L1176
    b43 = v914;	// L1177
    float v916 = a43;	// L1178
    float v917 = b43;	// L1179
    float v918 = v916 * v917;	// L1180
    float v919 = v43;	// L1181
    float v920 = v919 + v918;	// L1182
    v43 = v920;	// L1183
    float v921 = a43;	// L1184
    v905.write(v921); // v905[k43] = v921;	// L1185
    float v922 = b43;	// L1186
    v906.write(v922); // v906[k43] = v922;	// L1187
  }
  float v923 = v43;	// L1189
  v907[v908][v909] = v923;	// L1190
}

void PE_kernel_QKT_4_5(
  hls::stream< float > &v924 /* v924[64] */,
  hls::stream< float > &v925 /* v925[64] */,
  hls::stream< float > &v926 /* v926[64] */,
  hls::stream< float > &v927 /* v927[64] */,
  float v928[8][8],
  int v929,
  int v930
) {	// L1193
  #pragma HLS stream variable=v924 depth=9
  #pragma HLS stream variable=v925 depth=9
  #pragma HLS stream variable=v926 depth=9
  #pragma HLS stream variable=v927 depth=9
  #pragma HLS array_partition variable=v928 complete dim=1
  #pragma HLS array_partition variable=v928 complete dim=2

  float v44;	// L1196
  v44 = 0.000000;	// L1197
  l_S_k_0_k44: for (int k44 = 0; k44 < 64; k44++) {	// L1198
    float v933 = v924.read(); // v924[k44];	// L1199
    float a44;	// L1200
    a44 = v933;	// L1201
    float v935 = v925.read(); // v925[k44];	// L1202
    float b44;	// L1203
    b44 = v935;	// L1204
    float v937 = a44;	// L1205
    float v938 = b44;	// L1206
    float v939 = v937 * v938;	// L1207
    float v940 = v44;	// L1208
    float v941 = v940 + v939;	// L1209
    v44 = v941;	// L1210
    float v942 = a44;	// L1211
    v926.write(v942); // v926[k44] = v942;	// L1212
    float v943 = b44;	// L1213
    v927.write(v943); // v927[k44] = v943;	// L1214
  }
  float v944 = v44;	// L1216
  v928[v929][v930] = v944;	// L1217
}

void PE_kernel_QKT_5_5(
  hls::stream< float > &v945 /* v945[64] */,
  hls::stream< float > &v946 /* v946[64] */,
  hls::stream< float > &v947 /* v947[64] */,
  hls::stream< float > &v948 /* v948[64] */,
  float v949[8][8],
  int v950,
  int v951
) {	// L1220
  #pragma HLS stream variable=v945 depth=9
  #pragma HLS stream variable=v946 depth=9
  #pragma HLS stream variable=v947 depth=9
  #pragma HLS stream variable=v948 depth=9
  #pragma HLS array_partition variable=v949 complete dim=1
  #pragma HLS array_partition variable=v949 complete dim=2

  float v45;	// L1223
  v45 = 0.000000;	// L1224
  l_S_k_0_k45: for (int k45 = 0; k45 < 64; k45++) {	// L1225
    float v954 = v945.read(); // v945[k45];	// L1226
    float a45;	// L1227
    a45 = v954;	// L1228
    float v956 = v946.read(); // v946[k45];	// L1229
    float b45;	// L1230
    b45 = v956;	// L1231
    float v958 = a45;	// L1232
    float v959 = b45;	// L1233
    float v960 = v958 * v959;	// L1234
    float v961 = v45;	// L1235
    float v962 = v961 + v960;	// L1236
    v45 = v962;	// L1237
    float v963 = a45;	// L1238
    v947.write(v963); // v947[k45] = v963;	// L1239
    float v964 = b45;	// L1240
    v948.write(v964); // v948[k45] = v964;	// L1241
  }
  float v965 = v45;	// L1243
  v949[v950][v951] = v965;	// L1244
}

void PE_kernel_QKT_6_5(
  hls::stream< float > &v966 /* v966[64] */,
  hls::stream< float > &v967 /* v967[64] */,
  hls::stream< float > &v968 /* v968[64] */,
  hls::stream< float > &v969 /* v969[64] */,
  float v970[8][8],
  int v971,
  int v972
) {	// L1247
  #pragma HLS stream variable=v966 depth=9
  #pragma HLS stream variable=v967 depth=9
  #pragma HLS stream variable=v968 depth=9
  #pragma HLS stream variable=v969 depth=9
  #pragma HLS array_partition variable=v970 complete dim=1
  #pragma HLS array_partition variable=v970 complete dim=2

  float v46;	// L1250
  v46 = 0.000000;	// L1251
  l_S_k_0_k46: for (int k46 = 0; k46 < 64; k46++) {	// L1252
    float v975 = v966.read(); // v966[k46];	// L1253
    float a46;	// L1254
    a46 = v975;	// L1255
    float v977 = v967.read(); // v967[k46];	// L1256
    float b46;	// L1257
    b46 = v977;	// L1258
    float v979 = a46;	// L1259
    float v980 = b46;	// L1260
    float v981 = v979 * v980;	// L1261
    float v982 = v46;	// L1262
    float v983 = v982 + v981;	// L1263
    v46 = v983;	// L1264
    float v984 = a46;	// L1265
    v968.write(v984); // v968[k46] = v984;	// L1266
    float v985 = b46;	// L1267
    v969.write(v985); // v969[k46] = v985;	// L1268
  }
  float v986 = v46;	// L1270
  v970[v971][v972] = v986;	// L1271
}

void PE_kernel_QKT_7_5(
  hls::stream< float > &v987 /* v987[64] */,
  hls::stream< float > &v988 /* v988[64] */,
  hls::stream< float > &v989 /* v989[64] */,
  hls::stream< float > &v990 /* v990[64] */,
  float v991[8][8],
  int v992,
  int v993
) {	// L1274
  #pragma HLS stream variable=v987 depth=9
  #pragma HLS stream variable=v988 depth=9
  #pragma HLS stream variable=v989 depth=9
  #pragma HLS stream variable=v990 depth=9
  #pragma HLS array_partition variable=v991 complete dim=1
  #pragma HLS array_partition variable=v991 complete dim=2

  float v47;	// L1277
  v47 = 0.000000;	// L1278
  l_S_k_0_k47: for (int k47 = 0; k47 < 64; k47++) {	// L1279
    float v996 = v987.read(); // v987[k47];	// L1280
    float a47;	// L1281
    a47 = v996;	// L1282
    float v998 = v988.read(); // v988[k47];	// L1283
    float b47;	// L1284
    b47 = v998;	// L1285
    float v1000 = a47;	// L1286
    float v1001 = b47;	// L1287
    float v1002 = v1000 * v1001;	// L1288
    float v1003 = v47;	// L1289
    float v1004 = v1003 + v1002;	// L1290
    v47 = v1004;	// L1291
    float v1005 = a47;	// L1292
    v989.write(v1005); // v989[k47] = v1005;	// L1293
    float v1006 = b47;	// L1294
    v990.write(v1006); // v990[k47] = v1006;	// L1295
  }
  float v1007 = v47;	// L1297
  v991[v992][v993] = v1007;	// L1298
}

void PE_kernel_QKT_0_6(
  hls::stream< float > &v1008 /* v1008[64] */,
  hls::stream< float > &v1009 /* v1009[64] */,
  hls::stream< float > &v1010 /* v1010[64] */,
  hls::stream< float > &v1011 /* v1011[64] */,
  float v1012[8][8],
  int v1013,
  int v1014
) {	// L1301
  #pragma HLS stream variable=v1008 depth=9
  #pragma HLS stream variable=v1009 depth=9
  #pragma HLS stream variable=v1010 depth=9
  #pragma HLS stream variable=v1011 depth=9
  #pragma HLS array_partition variable=v1012 complete dim=1
  #pragma HLS array_partition variable=v1012 complete dim=2

  float v48;	// L1304
  v48 = 0.000000;	// L1305
  l_S_k_0_k48: for (int k48 = 0; k48 < 64; k48++) {	// L1306
    float v1017 = v1008.read(); // v1008[k48];	// L1307
    float a48;	// L1308
    a48 = v1017;	// L1309
    float v1019 = v1009.read(); // v1009[k48];	// L1310
    float b48;	// L1311
    b48 = v1019;	// L1312
    float v1021 = a48;	// L1313
    float v1022 = b48;	// L1314
    float v1023 = v1021 * v1022;	// L1315
    float v1024 = v48;	// L1316
    float v1025 = v1024 + v1023;	// L1317
    v48 = v1025;	// L1318
    float v1026 = a48;	// L1319
    v1010.write(v1026); // v1010[k48] = v1026;	// L1320
    float v1027 = b48;	// L1321
    v1011.write(v1027); // v1011[k48] = v1027;	// L1322
  }
  float v1028 = v48;	// L1324
  v1012[v1013][v1014] = v1028;	// L1325
}

void PE_kernel_QKT_1_6(
  hls::stream< float > &v1029 /* v1029[64] */,
  hls::stream< float > &v1030 /* v1030[64] */,
  hls::stream< float > &v1031 /* v1031[64] */,
  hls::stream< float > &v1032 /* v1032[64] */,
  float v1033[8][8],
  int v1034,
  int v1035
) {	// L1328
  #pragma HLS stream variable=v1029 depth=9
  #pragma HLS stream variable=v1030 depth=9
  #pragma HLS stream variable=v1031 depth=9
  #pragma HLS stream variable=v1032 depth=9
  #pragma HLS array_partition variable=v1033 complete dim=1
  #pragma HLS array_partition variable=v1033 complete dim=2

  float v49;	// L1331
  v49 = 0.000000;	// L1332
  l_S_k_0_k49: for (int k49 = 0; k49 < 64; k49++) {	// L1333
    float v1038 = v1029.read(); // v1029[k49];	// L1334
    float a49;	// L1335
    a49 = v1038;	// L1336
    float v1040 = v1030.read(); // v1030[k49];	// L1337
    float b49;	// L1338
    b49 = v1040;	// L1339
    float v1042 = a49;	// L1340
    float v1043 = b49;	// L1341
    float v1044 = v1042 * v1043;	// L1342
    float v1045 = v49;	// L1343
    float v1046 = v1045 + v1044;	// L1344
    v49 = v1046;	// L1345
    float v1047 = a49;	// L1346
    v1031.write(v1047); // v1031[k49] = v1047;	// L1347
    float v1048 = b49;	// L1348
    v1032.write(v1048); // v1032[k49] = v1048;	// L1349
  }
  float v1049 = v49;	// L1351
  v1033[v1034][v1035] = v1049;	// L1352
}

void PE_kernel_QKT_2_6(
  hls::stream< float > &v1050 /* v1050[64] */,
  hls::stream< float > &v1051 /* v1051[64] */,
  hls::stream< float > &v1052 /* v1052[64] */,
  hls::stream< float > &v1053 /* v1053[64] */,
  float v1054[8][8],
  int v1055,
  int v1056
) {	// L1355
  #pragma HLS stream variable=v1050 depth=9
  #pragma HLS stream variable=v1051 depth=9
  #pragma HLS stream variable=v1052 depth=9
  #pragma HLS stream variable=v1053 depth=9
  #pragma HLS array_partition variable=v1054 complete dim=1
  #pragma HLS array_partition variable=v1054 complete dim=2

  float v50;	// L1358
  v50 = 0.000000;	// L1359
  l_S_k_0_k50: for (int k50 = 0; k50 < 64; k50++) {	// L1360
    float v1059 = v1050.read(); // v1050[k50];	// L1361
    float a50;	// L1362
    a50 = v1059;	// L1363
    float v1061 = v1051.read(); // v1051[k50];	// L1364
    float b50;	// L1365
    b50 = v1061;	// L1366
    float v1063 = a50;	// L1367
    float v1064 = b50;	// L1368
    float v1065 = v1063 * v1064;	// L1369
    float v1066 = v50;	// L1370
    float v1067 = v1066 + v1065;	// L1371
    v50 = v1067;	// L1372
    float v1068 = a50;	// L1373
    v1052.write(v1068); // v1052[k50] = v1068;	// L1374
    float v1069 = b50;	// L1375
    v1053.write(v1069); // v1053[k50] = v1069;	// L1376
  }
  float v1070 = v50;	// L1378
  v1054[v1055][v1056] = v1070;	// L1379
}

void PE_kernel_QKT_3_6(
  hls::stream< float > &v1071 /* v1071[64] */,
  hls::stream< float > &v1072 /* v1072[64] */,
  hls::stream< float > &v1073 /* v1073[64] */,
  hls::stream< float > &v1074 /* v1074[64] */,
  float v1075[8][8],
  int v1076,
  int v1077
) {	// L1382
  #pragma HLS stream variable=v1071 depth=9
  #pragma HLS stream variable=v1072 depth=9
  #pragma HLS stream variable=v1073 depth=9
  #pragma HLS stream variable=v1074 depth=9
  #pragma HLS array_partition variable=v1075 complete dim=1
  #pragma HLS array_partition variable=v1075 complete dim=2

  float v51;	// L1385
  v51 = 0.000000;	// L1386
  l_S_k_0_k51: for (int k51 = 0; k51 < 64; k51++) {	// L1387
    float v1080 = v1071.read(); // v1071[k51];	// L1388
    float a51;	// L1389
    a51 = v1080;	// L1390
    float v1082 = v1072.read(); // v1072[k51];	// L1391
    float b51;	// L1392
    b51 = v1082;	// L1393
    float v1084 = a51;	// L1394
    float v1085 = b51;	// L1395
    float v1086 = v1084 * v1085;	// L1396
    float v1087 = v51;	// L1397
    float v1088 = v1087 + v1086;	// L1398
    v51 = v1088;	// L1399
    float v1089 = a51;	// L1400
    v1073.write(v1089); // v1073[k51] = v1089;	// L1401
    float v1090 = b51;	// L1402
    v1074.write(v1090); // v1074[k51] = v1090;	// L1403
  }
  float v1091 = v51;	// L1405
  v1075[v1076][v1077] = v1091;	// L1406
}

void PE_kernel_QKT_4_6(
  hls::stream< float > &v1092 /* v1092[64] */,
  hls::stream< float > &v1093 /* v1093[64] */,
  hls::stream< float > &v1094 /* v1094[64] */,
  hls::stream< float > &v1095 /* v1095[64] */,
  float v1096[8][8],
  int v1097,
  int v1098
) {	// L1409
  #pragma HLS stream variable=v1092 depth=9
  #pragma HLS stream variable=v1093 depth=9
  #pragma HLS stream variable=v1094 depth=9
  #pragma HLS stream variable=v1095 depth=9
  #pragma HLS array_partition variable=v1096 complete dim=1
  #pragma HLS array_partition variable=v1096 complete dim=2

  float v52;	// L1412
  v52 = 0.000000;	// L1413
  l_S_k_0_k52: for (int k52 = 0; k52 < 64; k52++) {	// L1414
    float v1101 = v1092.read(); // v1092[k52];	// L1415
    float a52;	// L1416
    a52 = v1101;	// L1417
    float v1103 = v1093.read(); // v1093[k52];	// L1418
    float b52;	// L1419
    b52 = v1103;	// L1420
    float v1105 = a52;	// L1421
    float v1106 = b52;	// L1422
    float v1107 = v1105 * v1106;	// L1423
    float v1108 = v52;	// L1424
    float v1109 = v1108 + v1107;	// L1425
    v52 = v1109;	// L1426
    float v1110 = a52;	// L1427
    v1094.write(v1110); // v1094[k52] = v1110;	// L1428
    float v1111 = b52;	// L1429
    v1095.write(v1111); // v1095[k52] = v1111;	// L1430
  }
  float v1112 = v52;	// L1432
  v1096[v1097][v1098] = v1112;	// L1433
}

void PE_kernel_QKT_5_6(
  hls::stream< float > &v1113 /* v1113[64] */,
  hls::stream< float > &v1114 /* v1114[64] */,
  hls::stream< float > &v1115 /* v1115[64] */,
  hls::stream< float > &v1116 /* v1116[64] */,
  float v1117[8][8],
  int v1118,
  int v1119
) {	// L1436
  #pragma HLS stream variable=v1113 depth=9
  #pragma HLS stream variable=v1114 depth=9
  #pragma HLS stream variable=v1115 depth=9
  #pragma HLS stream variable=v1116 depth=9
  #pragma HLS array_partition variable=v1117 complete dim=1
  #pragma HLS array_partition variable=v1117 complete dim=2

  float v53;	// L1439
  v53 = 0.000000;	// L1440
  l_S_k_0_k53: for (int k53 = 0; k53 < 64; k53++) {	// L1441
    float v1122 = v1113.read(); // v1113[k53];	// L1442
    float a53;	// L1443
    a53 = v1122;	// L1444
    float v1124 = v1114.read(); // v1114[k53];	// L1445
    float b53;	// L1446
    b53 = v1124;	// L1447
    float v1126 = a53;	// L1448
    float v1127 = b53;	// L1449
    float v1128 = v1126 * v1127;	// L1450
    float v1129 = v53;	// L1451
    float v1130 = v1129 + v1128;	// L1452
    v53 = v1130;	// L1453
    float v1131 = a53;	// L1454
    v1115.write(v1131); // v1115[k53] = v1131;	// L1455
    float v1132 = b53;	// L1456
    v1116.write(v1132); // v1116[k53] = v1132;	// L1457
  }
  float v1133 = v53;	// L1459
  v1117[v1118][v1119] = v1133;	// L1460
}

void PE_kernel_QKT_6_6(
  hls::stream< float > &v1134 /* v1134[64] */,
  hls::stream< float > &v1135 /* v1135[64] */,
  hls::stream< float > &v1136 /* v1136[64] */,
  hls::stream< float > &v1137 /* v1137[64] */,
  float v1138[8][8],
  int v1139,
  int v1140
) {	// L1463
  #pragma HLS stream variable=v1134 depth=9
  #pragma HLS stream variable=v1135 depth=9
  #pragma HLS stream variable=v1136 depth=9
  #pragma HLS stream variable=v1137 depth=9
  #pragma HLS array_partition variable=v1138 complete dim=1
  #pragma HLS array_partition variable=v1138 complete dim=2

  float v54;	// L1466
  v54 = 0.000000;	// L1467
  l_S_k_0_k54: for (int k54 = 0; k54 < 64; k54++) {	// L1468
    float v1143 = v1134.read(); // v1134[k54];	// L1469
    float a54;	// L1470
    a54 = v1143;	// L1471
    float v1145 = v1135.read(); // v1135[k54];	// L1472
    float b54;	// L1473
    b54 = v1145;	// L1474
    float v1147 = a54;	// L1475
    float v1148 = b54;	// L1476
    float v1149 = v1147 * v1148;	// L1477
    float v1150 = v54;	// L1478
    float v1151 = v1150 + v1149;	// L1479
    v54 = v1151;	// L1480
    float v1152 = a54;	// L1481
    v1136.write(v1152); // v1136[k54] = v1152;	// L1482
    float v1153 = b54;	// L1483
    v1137.write(v1153); // v1137[k54] = v1153;	// L1484
  }
  float v1154 = v54;	// L1486
  v1138[v1139][v1140] = v1154;	// L1487
}

void PE_kernel_QKT_7_6(
  hls::stream< float > &v1155 /* v1155[64] */,
  hls::stream< float > &v1156 /* v1156[64] */,
  hls::stream< float > &v1157 /* v1157[64] */,
  hls::stream< float > &v1158 /* v1158[64] */,
  float v1159[8][8],
  int v1160,
  int v1161
) {	// L1490
  #pragma HLS stream variable=v1155 depth=9
  #pragma HLS stream variable=v1156 depth=9
  #pragma HLS stream variable=v1157 depth=9
  #pragma HLS stream variable=v1158 depth=9
  #pragma HLS array_partition variable=v1159 complete dim=1
  #pragma HLS array_partition variable=v1159 complete dim=2

  float v55;	// L1493
  v55 = 0.000000;	// L1494
  l_S_k_0_k55: for (int k55 = 0; k55 < 64; k55++) {	// L1495
    float v1164 = v1155.read(); // v1155[k55];	// L1496
    float a55;	// L1497
    a55 = v1164;	// L1498
    float v1166 = v1156.read(); // v1156[k55];	// L1499
    float b55;	// L1500
    b55 = v1166;	// L1501
    float v1168 = a55;	// L1502
    float v1169 = b55;	// L1503
    float v1170 = v1168 * v1169;	// L1504
    float v1171 = v55;	// L1505
    float v1172 = v1171 + v1170;	// L1506
    v55 = v1172;	// L1507
    float v1173 = a55;	// L1508
    v1157.write(v1173); // v1157[k55] = v1173;	// L1509
    float v1174 = b55;	// L1510
    v1158.write(v1174); // v1158[k55] = v1174;	// L1511
  }
  float v1175 = v55;	// L1513
  v1159[v1160][v1161] = v1175;	// L1514
}

void PE_kernel_QKT_0_7(
  hls::stream< float > &v1176 /* v1176[64] */,
  hls::stream< float > &v1177 /* v1177[64] */,
  hls::stream< float > &v1178 /* v1178[64] */,
  hls::stream< float > &v1179 /* v1179[64] */,
  float v1180[8][8],
  int v1181,
  int v1182
) {	// L1517
  #pragma HLS stream variable=v1176 depth=9
  #pragma HLS stream variable=v1177 depth=9
  #pragma HLS stream variable=v1178 depth=9
  #pragma HLS stream variable=v1179 depth=9
  #pragma HLS array_partition variable=v1180 complete dim=1
  #pragma HLS array_partition variable=v1180 complete dim=2

  float v56;	// L1520
  v56 = 0.000000;	// L1521
  l_S_k_0_k56: for (int k56 = 0; k56 < 64; k56++) {	// L1522
    float v1185 = v1176.read(); // v1176[k56];	// L1523
    float a56;	// L1524
    a56 = v1185;	// L1525
    float v1187 = v1177.read(); // v1177[k56];	// L1526
    float b56;	// L1527
    b56 = v1187;	// L1528
    float v1189 = a56;	// L1529
    float v1190 = b56;	// L1530
    float v1191 = v1189 * v1190;	// L1531
    float v1192 = v56;	// L1532
    float v1193 = v1192 + v1191;	// L1533
    v56 = v1193;	// L1534
    float v1194 = a56;	// L1535
    v1178.write(v1194); // v1178[k56] = v1194;	// L1536
    float v1195 = b56;	// L1537
    v1179.write(v1195); // v1179[k56] = v1195;	// L1538
  }
  float v1196 = v56;	// L1540
  v1180[v1181][v1182] = v1196;	// L1541
}

void PE_kernel_QKT_1_7(
  hls::stream< float > &v1197 /* v1197[64] */,
  hls::stream< float > &v1198 /* v1198[64] */,
  hls::stream< float > &v1199 /* v1199[64] */,
  hls::stream< float > &v1200 /* v1200[64] */,
  float v1201[8][8],
  int v1202,
  int v1203
) {	// L1544
  #pragma HLS stream variable=v1197 depth=9
  #pragma HLS stream variable=v1198 depth=9
  #pragma HLS stream variable=v1199 depth=9
  #pragma HLS stream variable=v1200 depth=9
  #pragma HLS array_partition variable=v1201 complete dim=1
  #pragma HLS array_partition variable=v1201 complete dim=2

  float v57;	// L1547
  v57 = 0.000000;	// L1548
  l_S_k_0_k57: for (int k57 = 0; k57 < 64; k57++) {	// L1549
    float v1206 = v1197.read(); // v1197[k57];	// L1550
    float a57;	// L1551
    a57 = v1206;	// L1552
    float v1208 = v1198.read(); // v1198[k57];	// L1553
    float b57;	// L1554
    b57 = v1208;	// L1555
    float v1210 = a57;	// L1556
    float v1211 = b57;	// L1557
    float v1212 = v1210 * v1211;	// L1558
    float v1213 = v57;	// L1559
    float v1214 = v1213 + v1212;	// L1560
    v57 = v1214;	// L1561
    float v1215 = a57;	// L1562
    v1199.write(v1215); // v1199[k57] = v1215;	// L1563
    float v1216 = b57;	// L1564
    v1200.write(v1216); // v1200[k57] = v1216;	// L1565
  }
  float v1217 = v57;	// L1567
  v1201[v1202][v1203] = v1217;	// L1568
}

void PE_kernel_QKT_2_7(
  hls::stream< float > &v1218 /* v1218[64] */,
  hls::stream< float > &v1219 /* v1219[64] */,
  hls::stream< float > &v1220 /* v1220[64] */,
  hls::stream< float > &v1221 /* v1221[64] */,
  float v1222[8][8],
  int v1223,
  int v1224
) {	// L1571
  #pragma HLS stream variable=v1218 depth=9
  #pragma HLS stream variable=v1219 depth=9
  #pragma HLS stream variable=v1220 depth=9
  #pragma HLS stream variable=v1221 depth=9
  #pragma HLS array_partition variable=v1222 complete dim=1
  #pragma HLS array_partition variable=v1222 complete dim=2

  float v58;	// L1574
  v58 = 0.000000;	// L1575
  l_S_k_0_k58: for (int k58 = 0; k58 < 64; k58++) {	// L1576
    float v1227 = v1218.read(); // v1218[k58];	// L1577
    float a58;	// L1578
    a58 = v1227;	// L1579
    float v1229 = v1219.read(); // v1219[k58];	// L1580
    float b58;	// L1581
    b58 = v1229;	// L1582
    float v1231 = a58;	// L1583
    float v1232 = b58;	// L1584
    float v1233 = v1231 * v1232;	// L1585
    float v1234 = v58;	// L1586
    float v1235 = v1234 + v1233;	// L1587
    v58 = v1235;	// L1588
    float v1236 = a58;	// L1589
    v1220.write(v1236); // v1220[k58] = v1236;	// L1590
    float v1237 = b58;	// L1591
    v1221.write(v1237); // v1221[k58] = v1237;	// L1592
  }
  float v1238 = v58;	// L1594
  v1222[v1223][v1224] = v1238;	// L1595
}

void PE_kernel_QKT_3_7(
  hls::stream< float > &v1239 /* v1239[64] */,
  hls::stream< float > &v1240 /* v1240[64] */,
  hls::stream< float > &v1241 /* v1241[64] */,
  hls::stream< float > &v1242 /* v1242[64] */,
  float v1243[8][8],
  int v1244,
  int v1245
) {	// L1598
  #pragma HLS stream variable=v1239 depth=9
  #pragma HLS stream variable=v1240 depth=9
  #pragma HLS stream variable=v1241 depth=9
  #pragma HLS stream variable=v1242 depth=9
  #pragma HLS array_partition variable=v1243 complete dim=1
  #pragma HLS array_partition variable=v1243 complete dim=2

  float v59;	// L1601
  v59 = 0.000000;	// L1602
  l_S_k_0_k59: for (int k59 = 0; k59 < 64; k59++) {	// L1603
    float v1248 = v1239.read(); // v1239[k59];	// L1604
    float a59;	// L1605
    a59 = v1248;	// L1606
    float v1250 = v1240.read(); // v1240[k59];	// L1607
    float b59;	// L1608
    b59 = v1250;	// L1609
    float v1252 = a59;	// L1610
    float v1253 = b59;	// L1611
    float v1254 = v1252 * v1253;	// L1612
    float v1255 = v59;	// L1613
    float v1256 = v1255 + v1254;	// L1614
    v59 = v1256;	// L1615
    float v1257 = a59;	// L1616
    v1241.write(v1257); // v1241[k59] = v1257;	// L1617
    float v1258 = b59;	// L1618
    v1242.write(v1258); // v1242[k59] = v1258;	// L1619
  }
  float v1259 = v59;	// L1621
  v1243[v1244][v1245] = v1259;	// L1622
}

void PE_kernel_QKT_4_7(
  hls::stream< float > &v1260 /* v1260[64] */,
  hls::stream< float > &v1261 /* v1261[64] */,
  hls::stream< float > &v1262 /* v1262[64] */,
  hls::stream< float > &v1263 /* v1263[64] */,
  float v1264[8][8],
  int v1265,
  int v1266
) {	// L1625
  #pragma HLS stream variable=v1260 depth=9
  #pragma HLS stream variable=v1261 depth=9
  #pragma HLS stream variable=v1262 depth=9
  #pragma HLS stream variable=v1263 depth=9
  #pragma HLS array_partition variable=v1264 complete dim=1
  #pragma HLS array_partition variable=v1264 complete dim=2

  float v60;	// L1628
  v60 = 0.000000;	// L1629
  l_S_k_0_k60: for (int k60 = 0; k60 < 64; k60++) {	// L1630
    float v1269 = v1260.read(); // v1260[k60];	// L1631
    float a60;	// L1632
    a60 = v1269;	// L1633
    float v1271 = v1261.read(); // v1261[k60];	// L1634
    float b60;	// L1635
    b60 = v1271;	// L1636
    float v1273 = a60;	// L1637
    float v1274 = b60;	// L1638
    float v1275 = v1273 * v1274;	// L1639
    float v1276 = v60;	// L1640
    float v1277 = v1276 + v1275;	// L1641
    v60 = v1277;	// L1642
    float v1278 = a60;	// L1643
    v1262.write(v1278); // v1262[k60] = v1278;	// L1644
    float v1279 = b60;	// L1645
    v1263.write(v1279); // v1263[k60] = v1279;	// L1646
  }
  float v1280 = v60;	// L1648
  v1264[v1265][v1266] = v1280;	// L1649
}

void PE_kernel_QKT_5_7(
  hls::stream< float > &v1281 /* v1281[64] */,
  hls::stream< float > &v1282 /* v1282[64] */,
  hls::stream< float > &v1283 /* v1283[64] */,
  hls::stream< float > &v1284 /* v1284[64] */,
  float v1285[8][8],
  int v1286,
  int v1287
) {	// L1652
  #pragma HLS stream variable=v1281 depth=9
  #pragma HLS stream variable=v1282 depth=9
  #pragma HLS stream variable=v1283 depth=9
  #pragma HLS stream variable=v1284 depth=9
  #pragma HLS array_partition variable=v1285 complete dim=1
  #pragma HLS array_partition variable=v1285 complete dim=2

  float v61;	// L1655
  v61 = 0.000000;	// L1656
  l_S_k_0_k61: for (int k61 = 0; k61 < 64; k61++) {	// L1657
    float v1290 = v1281.read(); // v1281[k61];	// L1658
    float a61;	// L1659
    a61 = v1290;	// L1660
    float v1292 = v1282.read(); // v1282[k61];	// L1661
    float b61;	// L1662
    b61 = v1292;	// L1663
    float v1294 = a61;	// L1664
    float v1295 = b61;	// L1665
    float v1296 = v1294 * v1295;	// L1666
    float v1297 = v61;	// L1667
    float v1298 = v1297 + v1296;	// L1668
    v61 = v1298;	// L1669
    float v1299 = a61;	// L1670
    v1283.write(v1299); // v1283[k61] = v1299;	// L1671
    float v1300 = b61;	// L1672
    v1284.write(v1300); // v1284[k61] = v1300;	// L1673
  }
  float v1301 = v61;	// L1675
  v1285[v1286][v1287] = v1301;	// L1676
}

void PE_kernel_QKT_6_7(
  hls::stream< float > &v1302 /* v1302[64] */,
  hls::stream< float > &v1303 /* v1303[64] */,
  hls::stream< float > &v1304 /* v1304[64] */,
  hls::stream< float > &v1305 /* v1305[64] */,
  float v1306[8][8],
  int v1307,
  int v1308
) {	// L1679
  #pragma HLS stream variable=v1302 depth=9
  #pragma HLS stream variable=v1303 depth=9
  #pragma HLS stream variable=v1304 depth=9
  #pragma HLS stream variable=v1305 depth=9
  #pragma HLS array_partition variable=v1306 complete dim=1
  #pragma HLS array_partition variable=v1306 complete dim=2

  float v62;	// L1682
  v62 = 0.000000;	// L1683
  l_S_k_0_k62: for (int k62 = 0; k62 < 64; k62++) {	// L1684
    float v1311 = v1302.read(); // v1302[k62];	// L1685
    float a62;	// L1686
    a62 = v1311;	// L1687
    float v1313 = v1303.read(); // v1303[k62];	// L1688
    float b62;	// L1689
    b62 = v1313;	// L1690
    float v1315 = a62;	// L1691
    float v1316 = b62;	// L1692
    float v1317 = v1315 * v1316;	// L1693
    float v1318 = v62;	// L1694
    float v1319 = v1318 + v1317;	// L1695
    v62 = v1319;	// L1696
    float v1320 = a62;	// L1697
    v1304.write(v1320); // v1304[k62] = v1320;	// L1698
    float v1321 = b62;	// L1699
    v1305.write(v1321); // v1305[k62] = v1321;	// L1700
  }
  float v1322 = v62;	// L1702
  v1306[v1307][v1308] = v1322;	// L1703
}

void PE_kernel_QKT_7_7(
  hls::stream< float > &v1323 /* v1323[64] */,
  hls::stream< float > &v1324 /* v1324[64] */,
  hls::stream< float > &v1325 /* v1325[64] */,
  hls::stream< float > &v1326 /* v1326[64] */,
  float v1327[8][8],
  int v1328,
  int v1329
) {	// L1706
  #pragma HLS stream variable=v1323 depth=9
  #pragma HLS stream variable=v1324 depth=9
  #pragma HLS stream variable=v1325 depth=9
  #pragma HLS stream variable=v1326 depth=9
  #pragma HLS array_partition variable=v1327 complete dim=1
  #pragma HLS array_partition variable=v1327 complete dim=2

  float v63;	// L1709
  v63 = 0.000000;	// L1710
  l_S_k_0_k63: for (int k63 = 0; k63 < 64; k63++) {	// L1711
    float v1332 = v1323.read(); // v1323[k63];	// L1712
    float a63;	// L1713
    a63 = v1332;	// L1714
    float v1334 = v1324.read(); // v1324[k63];	// L1715
    float b63;	// L1716
    b63 = v1334;	// L1717
    float v1336 = a63;	// L1718
    float v1337 = b63;	// L1719
    float v1338 = v1336 * v1337;	// L1720
    float v1339 = v63;	// L1721
    float v1340 = v1339 + v1338;	// L1722
    v63 = v1340;	// L1723
    float v1341 = a63;	// L1724
    v1325.write(v1341); // v1325[k63] = v1341;	// L1725
    float v1342 = b63;	// L1726
    v1326.write(v1342); // v1326[k63] = v1342;	// L1727
  }
  float v1343 = v63;	// L1729
  v1327[v1328][v1329] = v1343;	// L1730
}

void systolic_tile_QKT(
  float v1344[8][64],
  float v1345[64][8],
  float v1346[8][8]
) {	// L1733
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v1344 complete dim=1

  #pragma HLS array_partition variable=v1345 complete dim=2

  #pragma HLS array_partition variable=v1346 complete dim=1
  #pragma HLS array_partition variable=v1346 complete dim=2

  hls::stream< float > A_fifo[8][9] /* A_fifo[8][9][64] */;	// L1734
  #pragma HLS stream variable=A_fifo depth=9
  hls::stream< float > B_fifo[8][9] /* B_fifo[8][9][64] */;	// L1735
  #pragma HLS stream variable=B_fifo depth=9
  float A_drain[8];	// L1736
  float B_drain[8];	// L1737
  l_data_load_k64: for (int k64 = 0; k64 < 64; k64++) {	// L1738
    l_S_m_0_m: for (int m = 0; m < 8; m++) {	// L1739
      float v1353 = v1344[m][k64];	// L1740
      A_fifo[m][0].write(v1353); // A_fifo[m][0][k64] = v1353;	// L1741
    }
    l_S_n_1_n: for (int n = 0; n < 8; n++) {	// L1743
      float v1355 = v1345[k64][n];	// L1744
      B_fifo[n][0].write(v1355); // B_fifo[n][0][k64] = v1355;	// L1745
    }
  }
  hls::stream< float > &v1356 /* v1356[64] */ = A_fifo[0][0];	// L1749
  hls::stream< float > &v1357 /* v1357[64] */ = B_fifo[0][0];	// L1750
  hls::stream< float > &v1358 /* v1358[64] */ = A_fifo[0][1];	// L1756
  hls::stream< float > &v1359 /* v1359[64] */ = B_fifo[0][1];	// L1757
  PE_kernel_QKT_0_0(v1356, v1357, v1358, v1359, v1346, 0, 0);	// L1758
  hls::stream< float > &v1360 /* v1360[64] */ = A_fifo[0][1];	// L1760
  hls::stream< float > &v1361 /* v1361[64] */ = B_fifo[1][0];	// L1761
  hls::stream< float > &v1362 /* v1362[64] */ = A_fifo[0][2];	// L1765
  hls::stream< float > &v1363 /* v1363[64] */ = B_fifo[1][1];	// L1766
  PE_kernel_QKT_1_0(v1360, v1361, v1362, v1363, v1346, 0, 1);	// L1767
  hls::stream< float > &v1364 /* v1364[64] */ = A_fifo[0][2];	// L1769
  hls::stream< float > &v1365 /* v1365[64] */ = B_fifo[2][0];	// L1770
  hls::stream< float > &v1366 /* v1366[64] */ = A_fifo[0][3];	// L1774
  hls::stream< float > &v1367 /* v1367[64] */ = B_fifo[2][1];	// L1775
  PE_kernel_QKT_2_0(v1364, v1365, v1366, v1367, v1346, 0, 2);	// L1776
  hls::stream< float > &v1368 /* v1368[64] */ = A_fifo[0][3];	// L1778
  hls::stream< float > &v1369 /* v1369[64] */ = B_fifo[3][0];	// L1779
  hls::stream< float > &v1370 /* v1370[64] */ = A_fifo[0][4];	// L1783
  hls::stream< float > &v1371 /* v1371[64] */ = B_fifo[3][1];	// L1784
  PE_kernel_QKT_3_0(v1368, v1369, v1370, v1371, v1346, 0, 3);	// L1785
  hls::stream< float > &v1372 /* v1372[64] */ = A_fifo[0][4];	// L1787
  hls::stream< float > &v1373 /* v1373[64] */ = B_fifo[4][0];	// L1788
  hls::stream< float > &v1374 /* v1374[64] */ = A_fifo[0][5];	// L1792
  hls::stream< float > &v1375 /* v1375[64] */ = B_fifo[4][1];	// L1793
  PE_kernel_QKT_4_0(v1372, v1373, v1374, v1375, v1346, 0, 4);	// L1794
  hls::stream< float > &v1376 /* v1376[64] */ = A_fifo[0][5];	// L1796
  hls::stream< float > &v1377 /* v1377[64] */ = B_fifo[5][0];	// L1797
  hls::stream< float > &v1378 /* v1378[64] */ = A_fifo[0][6];	// L1801
  hls::stream< float > &v1379 /* v1379[64] */ = B_fifo[5][1];	// L1802
  PE_kernel_QKT_5_0(v1376, v1377, v1378, v1379, v1346, 0, 5);	// L1803
  hls::stream< float > &v1380 /* v1380[64] */ = A_fifo[0][6];	// L1805
  hls::stream< float > &v1381 /* v1381[64] */ = B_fifo[6][0];	// L1806
  hls::stream< float > &v1382 /* v1382[64] */ = A_fifo[0][7];	// L1810
  hls::stream< float > &v1383 /* v1383[64] */ = B_fifo[6][1];	// L1811
  PE_kernel_QKT_6_0(v1380, v1381, v1382, v1383, v1346, 0, 6);	// L1812
  hls::stream< float > &v1384 /* v1384[64] */ = A_fifo[0][7];	// L1814
  hls::stream< float > &v1385 /* v1385[64] */ = B_fifo[7][0];	// L1815
  hls::stream< float > &v1386 /* v1386[64] */ = A_fifo[0][8];	// L1819
  hls::stream< float > &v1387 /* v1387[64] */ = B_fifo[7][1];	// L1820
  PE_kernel_QKT_7_0(v1384, v1385, v1386, v1387, v1346, 0, 7);	// L1821
  hls::stream< float > &v1388 /* v1388[64] */ = A_fifo[1][0];	// L1822
  hls::stream< float > &v1389 /* v1389[64] */ = B_fifo[0][1];	// L1823
  hls::stream< float > &v1390 /* v1390[64] */ = A_fifo[1][1];	// L1824
  hls::stream< float > &v1391 /* v1391[64] */ = B_fifo[0][2];	// L1825
  PE_kernel_QKT_0_1(v1388, v1389, v1390, v1391, v1346, 1, 0);	// L1826
  hls::stream< float > &v1392 /* v1392[64] */ = A_fifo[1][1];	// L1827
  hls::stream< float > &v1393 /* v1393[64] */ = B_fifo[1][1];	// L1828
  hls::stream< float > &v1394 /* v1394[64] */ = A_fifo[1][2];	// L1829
  hls::stream< float > &v1395 /* v1395[64] */ = B_fifo[1][2];	// L1830
  PE_kernel_QKT_1_1(v1392, v1393, v1394, v1395, v1346, 1, 1);	// L1831
  hls::stream< float > &v1396 /* v1396[64] */ = A_fifo[1][2];	// L1832
  hls::stream< float > &v1397 /* v1397[64] */ = B_fifo[2][1];	// L1833
  hls::stream< float > &v1398 /* v1398[64] */ = A_fifo[1][3];	// L1834
  hls::stream< float > &v1399 /* v1399[64] */ = B_fifo[2][2];	// L1835
  PE_kernel_QKT_2_1(v1396, v1397, v1398, v1399, v1346, 1, 2);	// L1836
  hls::stream< float > &v1400 /* v1400[64] */ = A_fifo[1][3];	// L1837
  hls::stream< float > &v1401 /* v1401[64] */ = B_fifo[3][1];	// L1838
  hls::stream< float > &v1402 /* v1402[64] */ = A_fifo[1][4];	// L1839
  hls::stream< float > &v1403 /* v1403[64] */ = B_fifo[3][2];	// L1840
  PE_kernel_QKT_3_1(v1400, v1401, v1402, v1403, v1346, 1, 3);	// L1841
  hls::stream< float > &v1404 /* v1404[64] */ = A_fifo[1][4];	// L1842
  hls::stream< float > &v1405 /* v1405[64] */ = B_fifo[4][1];	// L1843
  hls::stream< float > &v1406 /* v1406[64] */ = A_fifo[1][5];	// L1844
  hls::stream< float > &v1407 /* v1407[64] */ = B_fifo[4][2];	// L1845
  PE_kernel_QKT_4_1(v1404, v1405, v1406, v1407, v1346, 1, 4);	// L1846
  hls::stream< float > &v1408 /* v1408[64] */ = A_fifo[1][5];	// L1847
  hls::stream< float > &v1409 /* v1409[64] */ = B_fifo[5][1];	// L1848
  hls::stream< float > &v1410 /* v1410[64] */ = A_fifo[1][6];	// L1849
  hls::stream< float > &v1411 /* v1411[64] */ = B_fifo[5][2];	// L1850
  PE_kernel_QKT_5_1(v1408, v1409, v1410, v1411, v1346, 1, 5);	// L1851
  hls::stream< float > &v1412 /* v1412[64] */ = A_fifo[1][6];	// L1852
  hls::stream< float > &v1413 /* v1413[64] */ = B_fifo[6][1];	// L1853
  hls::stream< float > &v1414 /* v1414[64] */ = A_fifo[1][7];	// L1854
  hls::stream< float > &v1415 /* v1415[64] */ = B_fifo[6][2];	// L1855
  PE_kernel_QKT_6_1(v1412, v1413, v1414, v1415, v1346, 1, 6);	// L1856
  hls::stream< float > &v1416 /* v1416[64] */ = A_fifo[1][7];	// L1857
  hls::stream< float > &v1417 /* v1417[64] */ = B_fifo[7][1];	// L1858
  hls::stream< float > &v1418 /* v1418[64] */ = A_fifo[1][8];	// L1859
  hls::stream< float > &v1419 /* v1419[64] */ = B_fifo[7][2];	// L1860
  PE_kernel_QKT_7_1(v1416, v1417, v1418, v1419, v1346, 1, 7);	// L1861
  hls::stream< float > &v1420 /* v1420[64] */ = A_fifo[2][0];	// L1862
  hls::stream< float > &v1421 /* v1421[64] */ = B_fifo[0][2];	// L1863
  hls::stream< float > &v1422 /* v1422[64] */ = A_fifo[2][1];	// L1864
  hls::stream< float > &v1423 /* v1423[64] */ = B_fifo[0][3];	// L1865
  PE_kernel_QKT_0_2(v1420, v1421, v1422, v1423, v1346, 2, 0);	// L1866
  hls::stream< float > &v1424 /* v1424[64] */ = A_fifo[2][1];	// L1867
  hls::stream< float > &v1425 /* v1425[64] */ = B_fifo[1][2];	// L1868
  hls::stream< float > &v1426 /* v1426[64] */ = A_fifo[2][2];	// L1869
  hls::stream< float > &v1427 /* v1427[64] */ = B_fifo[1][3];	// L1870
  PE_kernel_QKT_1_2(v1424, v1425, v1426, v1427, v1346, 2, 1);	// L1871
  hls::stream< float > &v1428 /* v1428[64] */ = A_fifo[2][2];	// L1872
  hls::stream< float > &v1429 /* v1429[64] */ = B_fifo[2][2];	// L1873
  hls::stream< float > &v1430 /* v1430[64] */ = A_fifo[2][3];	// L1874
  hls::stream< float > &v1431 /* v1431[64] */ = B_fifo[2][3];	// L1875
  PE_kernel_QKT_2_2(v1428, v1429, v1430, v1431, v1346, 2, 2);	// L1876
  hls::stream< float > &v1432 /* v1432[64] */ = A_fifo[2][3];	// L1877
  hls::stream< float > &v1433 /* v1433[64] */ = B_fifo[3][2];	// L1878
  hls::stream< float > &v1434 /* v1434[64] */ = A_fifo[2][4];	// L1879
  hls::stream< float > &v1435 /* v1435[64] */ = B_fifo[3][3];	// L1880
  PE_kernel_QKT_3_2(v1432, v1433, v1434, v1435, v1346, 2, 3);	// L1881
  hls::stream< float > &v1436 /* v1436[64] */ = A_fifo[2][4];	// L1882
  hls::stream< float > &v1437 /* v1437[64] */ = B_fifo[4][2];	// L1883
  hls::stream< float > &v1438 /* v1438[64] */ = A_fifo[2][5];	// L1884
  hls::stream< float > &v1439 /* v1439[64] */ = B_fifo[4][3];	// L1885
  PE_kernel_QKT_4_2(v1436, v1437, v1438, v1439, v1346, 2, 4);	// L1886
  hls::stream< float > &v1440 /* v1440[64] */ = A_fifo[2][5];	// L1887
  hls::stream< float > &v1441 /* v1441[64] */ = B_fifo[5][2];	// L1888
  hls::stream< float > &v1442 /* v1442[64] */ = A_fifo[2][6];	// L1889
  hls::stream< float > &v1443 /* v1443[64] */ = B_fifo[5][3];	// L1890
  PE_kernel_QKT_5_2(v1440, v1441, v1442, v1443, v1346, 2, 5);	// L1891
  hls::stream< float > &v1444 /* v1444[64] */ = A_fifo[2][6];	// L1892
  hls::stream< float > &v1445 /* v1445[64] */ = B_fifo[6][2];	// L1893
  hls::stream< float > &v1446 /* v1446[64] */ = A_fifo[2][7];	// L1894
  hls::stream< float > &v1447 /* v1447[64] */ = B_fifo[6][3];	// L1895
  PE_kernel_QKT_6_2(v1444, v1445, v1446, v1447, v1346, 2, 6);	// L1896
  hls::stream< float > &v1448 /* v1448[64] */ = A_fifo[2][7];	// L1897
  hls::stream< float > &v1449 /* v1449[64] */ = B_fifo[7][2];	// L1898
  hls::stream< float > &v1450 /* v1450[64] */ = A_fifo[2][8];	// L1899
  hls::stream< float > &v1451 /* v1451[64] */ = B_fifo[7][3];	// L1900
  PE_kernel_QKT_7_2(v1448, v1449, v1450, v1451, v1346, 2, 7);	// L1901
  hls::stream< float > &v1452 /* v1452[64] */ = A_fifo[3][0];	// L1902
  hls::stream< float > &v1453 /* v1453[64] */ = B_fifo[0][3];	// L1903
  hls::stream< float > &v1454 /* v1454[64] */ = A_fifo[3][1];	// L1904
  hls::stream< float > &v1455 /* v1455[64] */ = B_fifo[0][4];	// L1905
  PE_kernel_QKT_0_3(v1452, v1453, v1454, v1455, v1346, 3, 0);	// L1906
  hls::stream< float > &v1456 /* v1456[64] */ = A_fifo[3][1];	// L1907
  hls::stream< float > &v1457 /* v1457[64] */ = B_fifo[1][3];	// L1908
  hls::stream< float > &v1458 /* v1458[64] */ = A_fifo[3][2];	// L1909
  hls::stream< float > &v1459 /* v1459[64] */ = B_fifo[1][4];	// L1910
  PE_kernel_QKT_1_3(v1456, v1457, v1458, v1459, v1346, 3, 1);	// L1911
  hls::stream< float > &v1460 /* v1460[64] */ = A_fifo[3][2];	// L1912
  hls::stream< float > &v1461 /* v1461[64] */ = B_fifo[2][3];	// L1913
  hls::stream< float > &v1462 /* v1462[64] */ = A_fifo[3][3];	// L1914
  hls::stream< float > &v1463 /* v1463[64] */ = B_fifo[2][4];	// L1915
  PE_kernel_QKT_2_3(v1460, v1461, v1462, v1463, v1346, 3, 2);	// L1916
  hls::stream< float > &v1464 /* v1464[64] */ = A_fifo[3][3];	// L1917
  hls::stream< float > &v1465 /* v1465[64] */ = B_fifo[3][3];	// L1918
  hls::stream< float > &v1466 /* v1466[64] */ = A_fifo[3][4];	// L1919
  hls::stream< float > &v1467 /* v1467[64] */ = B_fifo[3][4];	// L1920
  PE_kernel_QKT_3_3(v1464, v1465, v1466, v1467, v1346, 3, 3);	// L1921
  hls::stream< float > &v1468 /* v1468[64] */ = A_fifo[3][4];	// L1922
  hls::stream< float > &v1469 /* v1469[64] */ = B_fifo[4][3];	// L1923
  hls::stream< float > &v1470 /* v1470[64] */ = A_fifo[3][5];	// L1924
  hls::stream< float > &v1471 /* v1471[64] */ = B_fifo[4][4];	// L1925
  PE_kernel_QKT_4_3(v1468, v1469, v1470, v1471, v1346, 3, 4);	// L1926
  hls::stream< float > &v1472 /* v1472[64] */ = A_fifo[3][5];	// L1927
  hls::stream< float > &v1473 /* v1473[64] */ = B_fifo[5][3];	// L1928
  hls::stream< float > &v1474 /* v1474[64] */ = A_fifo[3][6];	// L1929
  hls::stream< float > &v1475 /* v1475[64] */ = B_fifo[5][4];	// L1930
  PE_kernel_QKT_5_3(v1472, v1473, v1474, v1475, v1346, 3, 5);	// L1931
  hls::stream< float > &v1476 /* v1476[64] */ = A_fifo[3][6];	// L1932
  hls::stream< float > &v1477 /* v1477[64] */ = B_fifo[6][3];	// L1933
  hls::stream< float > &v1478 /* v1478[64] */ = A_fifo[3][7];	// L1934
  hls::stream< float > &v1479 /* v1479[64] */ = B_fifo[6][4];	// L1935
  PE_kernel_QKT_6_3(v1476, v1477, v1478, v1479, v1346, 3, 6);	// L1936
  hls::stream< float > &v1480 /* v1480[64] */ = A_fifo[3][7];	// L1937
  hls::stream< float > &v1481 /* v1481[64] */ = B_fifo[7][3];	// L1938
  hls::stream< float > &v1482 /* v1482[64] */ = A_fifo[3][8];	// L1939
  hls::stream< float > &v1483 /* v1483[64] */ = B_fifo[7][4];	// L1940
  PE_kernel_QKT_7_3(v1480, v1481, v1482, v1483, v1346, 3, 7);	// L1941
  hls::stream< float > &v1484 /* v1484[64] */ = A_fifo[4][0];	// L1942
  hls::stream< float > &v1485 /* v1485[64] */ = B_fifo[0][4];	// L1943
  hls::stream< float > &v1486 /* v1486[64] */ = A_fifo[4][1];	// L1944
  hls::stream< float > &v1487 /* v1487[64] */ = B_fifo[0][5];	// L1945
  PE_kernel_QKT_0_4(v1484, v1485, v1486, v1487, v1346, 4, 0);	// L1946
  hls::stream< float > &v1488 /* v1488[64] */ = A_fifo[4][1];	// L1947
  hls::stream< float > &v1489 /* v1489[64] */ = B_fifo[1][4];	// L1948
  hls::stream< float > &v1490 /* v1490[64] */ = A_fifo[4][2];	// L1949
  hls::stream< float > &v1491 /* v1491[64] */ = B_fifo[1][5];	// L1950
  PE_kernel_QKT_1_4(v1488, v1489, v1490, v1491, v1346, 4, 1);	// L1951
  hls::stream< float > &v1492 /* v1492[64] */ = A_fifo[4][2];	// L1952
  hls::stream< float > &v1493 /* v1493[64] */ = B_fifo[2][4];	// L1953
  hls::stream< float > &v1494 /* v1494[64] */ = A_fifo[4][3];	// L1954
  hls::stream< float > &v1495 /* v1495[64] */ = B_fifo[2][5];	// L1955
  PE_kernel_QKT_2_4(v1492, v1493, v1494, v1495, v1346, 4, 2);	// L1956
  hls::stream< float > &v1496 /* v1496[64] */ = A_fifo[4][3];	// L1957
  hls::stream< float > &v1497 /* v1497[64] */ = B_fifo[3][4];	// L1958
  hls::stream< float > &v1498 /* v1498[64] */ = A_fifo[4][4];	// L1959
  hls::stream< float > &v1499 /* v1499[64] */ = B_fifo[3][5];	// L1960
  PE_kernel_QKT_3_4(v1496, v1497, v1498, v1499, v1346, 4, 3);	// L1961
  hls::stream< float > &v1500 /* v1500[64] */ = A_fifo[4][4];	// L1962
  hls::stream< float > &v1501 /* v1501[64] */ = B_fifo[4][4];	// L1963
  hls::stream< float > &v1502 /* v1502[64] */ = A_fifo[4][5];	// L1964
  hls::stream< float > &v1503 /* v1503[64] */ = B_fifo[4][5];	// L1965
  PE_kernel_QKT_4_4(v1500, v1501, v1502, v1503, v1346, 4, 4);	// L1966
  hls::stream< float > &v1504 /* v1504[64] */ = A_fifo[4][5];	// L1967
  hls::stream< float > &v1505 /* v1505[64] */ = B_fifo[5][4];	// L1968
  hls::stream< float > &v1506 /* v1506[64] */ = A_fifo[4][6];	// L1969
  hls::stream< float > &v1507 /* v1507[64] */ = B_fifo[5][5];	// L1970
  PE_kernel_QKT_5_4(v1504, v1505, v1506, v1507, v1346, 4, 5);	// L1971
  hls::stream< float > &v1508 /* v1508[64] */ = A_fifo[4][6];	// L1972
  hls::stream< float > &v1509 /* v1509[64] */ = B_fifo[6][4];	// L1973
  hls::stream< float > &v1510 /* v1510[64] */ = A_fifo[4][7];	// L1974
  hls::stream< float > &v1511 /* v1511[64] */ = B_fifo[6][5];	// L1975
  PE_kernel_QKT_6_4(v1508, v1509, v1510, v1511, v1346, 4, 6);	// L1976
  hls::stream< float > &v1512 /* v1512[64] */ = A_fifo[4][7];	// L1977
  hls::stream< float > &v1513 /* v1513[64] */ = B_fifo[7][4];	// L1978
  hls::stream< float > &v1514 /* v1514[64] */ = A_fifo[4][8];	// L1979
  hls::stream< float > &v1515 /* v1515[64] */ = B_fifo[7][5];	// L1980
  PE_kernel_QKT_7_4(v1512, v1513, v1514, v1515, v1346, 4, 7);	// L1981
  hls::stream< float > &v1516 /* v1516[64] */ = A_fifo[5][0];	// L1982
  hls::stream< float > &v1517 /* v1517[64] */ = B_fifo[0][5];	// L1983
  hls::stream< float > &v1518 /* v1518[64] */ = A_fifo[5][1];	// L1984
  hls::stream< float > &v1519 /* v1519[64] */ = B_fifo[0][6];	// L1985
  PE_kernel_QKT_0_5(v1516, v1517, v1518, v1519, v1346, 5, 0);	// L1986
  hls::stream< float > &v1520 /* v1520[64] */ = A_fifo[5][1];	// L1987
  hls::stream< float > &v1521 /* v1521[64] */ = B_fifo[1][5];	// L1988
  hls::stream< float > &v1522 /* v1522[64] */ = A_fifo[5][2];	// L1989
  hls::stream< float > &v1523 /* v1523[64] */ = B_fifo[1][6];	// L1990
  PE_kernel_QKT_1_5(v1520, v1521, v1522, v1523, v1346, 5, 1);	// L1991
  hls::stream< float > &v1524 /* v1524[64] */ = A_fifo[5][2];	// L1992
  hls::stream< float > &v1525 /* v1525[64] */ = B_fifo[2][5];	// L1993
  hls::stream< float > &v1526 /* v1526[64] */ = A_fifo[5][3];	// L1994
  hls::stream< float > &v1527 /* v1527[64] */ = B_fifo[2][6];	// L1995
  PE_kernel_QKT_2_5(v1524, v1525, v1526, v1527, v1346, 5, 2);	// L1996
  hls::stream< float > &v1528 /* v1528[64] */ = A_fifo[5][3];	// L1997
  hls::stream< float > &v1529 /* v1529[64] */ = B_fifo[3][5];	// L1998
  hls::stream< float > &v1530 /* v1530[64] */ = A_fifo[5][4];	// L1999
  hls::stream< float > &v1531 /* v1531[64] */ = B_fifo[3][6];	// L2000
  PE_kernel_QKT_3_5(v1528, v1529, v1530, v1531, v1346, 5, 3);	// L2001
  hls::stream< float > &v1532 /* v1532[64] */ = A_fifo[5][4];	// L2002
  hls::stream< float > &v1533 /* v1533[64] */ = B_fifo[4][5];	// L2003
  hls::stream< float > &v1534 /* v1534[64] */ = A_fifo[5][5];	// L2004
  hls::stream< float > &v1535 /* v1535[64] */ = B_fifo[4][6];	// L2005
  PE_kernel_QKT_4_5(v1532, v1533, v1534, v1535, v1346, 5, 4);	// L2006
  hls::stream< float > &v1536 /* v1536[64] */ = A_fifo[5][5];	// L2007
  hls::stream< float > &v1537 /* v1537[64] */ = B_fifo[5][5];	// L2008
  hls::stream< float > &v1538 /* v1538[64] */ = A_fifo[5][6];	// L2009
  hls::stream< float > &v1539 /* v1539[64] */ = B_fifo[5][6];	// L2010
  PE_kernel_QKT_5_5(v1536, v1537, v1538, v1539, v1346, 5, 5);	// L2011
  hls::stream< float > &v1540 /* v1540[64] */ = A_fifo[5][6];	// L2012
  hls::stream< float > &v1541 /* v1541[64] */ = B_fifo[6][5];	// L2013
  hls::stream< float > &v1542 /* v1542[64] */ = A_fifo[5][7];	// L2014
  hls::stream< float > &v1543 /* v1543[64] */ = B_fifo[6][6];	// L2015
  PE_kernel_QKT_6_5(v1540, v1541, v1542, v1543, v1346, 5, 6);	// L2016
  hls::stream< float > &v1544 /* v1544[64] */ = A_fifo[5][7];	// L2017
  hls::stream< float > &v1545 /* v1545[64] */ = B_fifo[7][5];	// L2018
  hls::stream< float > &v1546 /* v1546[64] */ = A_fifo[5][8];	// L2019
  hls::stream< float > &v1547 /* v1547[64] */ = B_fifo[7][6];	// L2020
  PE_kernel_QKT_7_5(v1544, v1545, v1546, v1547, v1346, 5, 7);	// L2021
  hls::stream< float > &v1548 /* v1548[64] */ = A_fifo[6][0];	// L2022
  hls::stream< float > &v1549 /* v1549[64] */ = B_fifo[0][6];	// L2023
  hls::stream< float > &v1550 /* v1550[64] */ = A_fifo[6][1];	// L2024
  hls::stream< float > &v1551 /* v1551[64] */ = B_fifo[0][7];	// L2025
  PE_kernel_QKT_0_6(v1548, v1549, v1550, v1551, v1346, 6, 0);	// L2026
  hls::stream< float > &v1552 /* v1552[64] */ = A_fifo[6][1];	// L2027
  hls::stream< float > &v1553 /* v1553[64] */ = B_fifo[1][6];	// L2028
  hls::stream< float > &v1554 /* v1554[64] */ = A_fifo[6][2];	// L2029
  hls::stream< float > &v1555 /* v1555[64] */ = B_fifo[1][7];	// L2030
  PE_kernel_QKT_1_6(v1552, v1553, v1554, v1555, v1346, 6, 1);	// L2031
  hls::stream< float > &v1556 /* v1556[64] */ = A_fifo[6][2];	// L2032
  hls::stream< float > &v1557 /* v1557[64] */ = B_fifo[2][6];	// L2033
  hls::stream< float > &v1558 /* v1558[64] */ = A_fifo[6][3];	// L2034
  hls::stream< float > &v1559 /* v1559[64] */ = B_fifo[2][7];	// L2035
  PE_kernel_QKT_2_6(v1556, v1557, v1558, v1559, v1346, 6, 2);	// L2036
  hls::stream< float > &v1560 /* v1560[64] */ = A_fifo[6][3];	// L2037
  hls::stream< float > &v1561 /* v1561[64] */ = B_fifo[3][6];	// L2038
  hls::stream< float > &v1562 /* v1562[64] */ = A_fifo[6][4];	// L2039
  hls::stream< float > &v1563 /* v1563[64] */ = B_fifo[3][7];	// L2040
  PE_kernel_QKT_3_6(v1560, v1561, v1562, v1563, v1346, 6, 3);	// L2041
  hls::stream< float > &v1564 /* v1564[64] */ = A_fifo[6][4];	// L2042
  hls::stream< float > &v1565 /* v1565[64] */ = B_fifo[4][6];	// L2043
  hls::stream< float > &v1566 /* v1566[64] */ = A_fifo[6][5];	// L2044
  hls::stream< float > &v1567 /* v1567[64] */ = B_fifo[4][7];	// L2045
  PE_kernel_QKT_4_6(v1564, v1565, v1566, v1567, v1346, 6, 4);	// L2046
  hls::stream< float > &v1568 /* v1568[64] */ = A_fifo[6][5];	// L2047
  hls::stream< float > &v1569 /* v1569[64] */ = B_fifo[5][6];	// L2048
  hls::stream< float > &v1570 /* v1570[64] */ = A_fifo[6][6];	// L2049
  hls::stream< float > &v1571 /* v1571[64] */ = B_fifo[5][7];	// L2050
  PE_kernel_QKT_5_6(v1568, v1569, v1570, v1571, v1346, 6, 5);	// L2051
  hls::stream< float > &v1572 /* v1572[64] */ = A_fifo[6][6];	// L2052
  hls::stream< float > &v1573 /* v1573[64] */ = B_fifo[6][6];	// L2053
  hls::stream< float > &v1574 /* v1574[64] */ = A_fifo[6][7];	// L2054
  hls::stream< float > &v1575 /* v1575[64] */ = B_fifo[6][7];	// L2055
  PE_kernel_QKT_6_6(v1572, v1573, v1574, v1575, v1346, 6, 6);	// L2056
  hls::stream< float > &v1576 /* v1576[64] */ = A_fifo[6][7];	// L2057
  hls::stream< float > &v1577 /* v1577[64] */ = B_fifo[7][6];	// L2058
  hls::stream< float > &v1578 /* v1578[64] */ = A_fifo[6][8];	// L2059
  hls::stream< float > &v1579 /* v1579[64] */ = B_fifo[7][7];	// L2060
  PE_kernel_QKT_7_6(v1576, v1577, v1578, v1579, v1346, 6, 7);	// L2061
  hls::stream< float > &v1580 /* v1580[64] */ = A_fifo[7][0];	// L2062
  hls::stream< float > &v1581 /* v1581[64] */ = B_fifo[0][7];	// L2063
  hls::stream< float > &v1582 /* v1582[64] */ = A_fifo[7][1];	// L2064
  hls::stream< float > &v1583 /* v1583[64] */ = B_fifo[0][8];	// L2065
  PE_kernel_QKT_0_7(v1580, v1581, v1582, v1583, v1346, 7, 0);	// L2066
  hls::stream< float > &v1584 /* v1584[64] */ = A_fifo[7][1];	// L2067
  hls::stream< float > &v1585 /* v1585[64] */ = B_fifo[1][7];	// L2068
  hls::stream< float > &v1586 /* v1586[64] */ = A_fifo[7][2];	// L2069
  hls::stream< float > &v1587 /* v1587[64] */ = B_fifo[1][8];	// L2070
  PE_kernel_QKT_1_7(v1584, v1585, v1586, v1587, v1346, 7, 1);	// L2071
  hls::stream< float > &v1588 /* v1588[64] */ = A_fifo[7][2];	// L2072
  hls::stream< float > &v1589 /* v1589[64] */ = B_fifo[2][7];	// L2073
  hls::stream< float > &v1590 /* v1590[64] */ = A_fifo[7][3];	// L2074
  hls::stream< float > &v1591 /* v1591[64] */ = B_fifo[2][8];	// L2075
  PE_kernel_QKT_2_7(v1588, v1589, v1590, v1591, v1346, 7, 2);	// L2076
  hls::stream< float > &v1592 /* v1592[64] */ = A_fifo[7][3];	// L2077
  hls::stream< float > &v1593 /* v1593[64] */ = B_fifo[3][7];	// L2078
  hls::stream< float > &v1594 /* v1594[64] */ = A_fifo[7][4];	// L2079
  hls::stream< float > &v1595 /* v1595[64] */ = B_fifo[3][8];	// L2080
  PE_kernel_QKT_3_7(v1592, v1593, v1594, v1595, v1346, 7, 3);	// L2081
  hls::stream< float > &v1596 /* v1596[64] */ = A_fifo[7][4];	// L2082
  hls::stream< float > &v1597 /* v1597[64] */ = B_fifo[4][7];	// L2083
  hls::stream< float > &v1598 /* v1598[64] */ = A_fifo[7][5];	// L2084
  hls::stream< float > &v1599 /* v1599[64] */ = B_fifo[4][8];	// L2085
  PE_kernel_QKT_4_7(v1596, v1597, v1598, v1599, v1346, 7, 4);	// L2086
  hls::stream< float > &v1600 /* v1600[64] */ = A_fifo[7][5];	// L2087
  hls::stream< float > &v1601 /* v1601[64] */ = B_fifo[5][7];	// L2088
  hls::stream< float > &v1602 /* v1602[64] */ = A_fifo[7][6];	// L2089
  hls::stream< float > &v1603 /* v1603[64] */ = B_fifo[5][8];	// L2090
  PE_kernel_QKT_5_7(v1600, v1601, v1602, v1603, v1346, 7, 5);	// L2091
  hls::stream< float > &v1604 /* v1604[64] */ = A_fifo[7][6];	// L2092
  hls::stream< float > &v1605 /* v1605[64] */ = B_fifo[6][7];	// L2093
  hls::stream< float > &v1606 /* v1606[64] */ = A_fifo[7][7];	// L2094
  hls::stream< float > &v1607 /* v1607[64] */ = B_fifo[6][8];	// L2095
  PE_kernel_QKT_6_7(v1604, v1605, v1606, v1607, v1346, 7, 6);	// L2096
  hls::stream< float > &v1608 /* v1608[64] */ = A_fifo[7][7];	// L2097
  hls::stream< float > &v1609 /* v1609[64] */ = B_fifo[7][7];	// L2098
  hls::stream< float > &v1610 /* v1610[64] */ = A_fifo[7][8];	// L2099
  hls::stream< float > &v1611 /* v1611[64] */ = B_fifo[7][8];	// L2100
  PE_kernel_QKT_7_7(v1608, v1609, v1610, v1611, v1346, 7, 7);	// L2101
  l_data_drain_k65: for (int k65 = 0; k65 < 64; k65++) {	// L2102
    l_S_m_4_m1: for (int m1 = 0; m1 < 8; m1++) {	// L2103
      float v1614 = A_fifo[m1][8].read(); // A_fifo[m1][8][k65];	// L2104
      A_drain[m1] = v1614;	// L2105
    }
    l_S_n_5_n1: for (int n1 = 0; n1 < 8; n1++) {	// L2107
      float v1616 = B_fifo[n1][8].read(); // B_fifo[n1][8][k65];	// L2108
      B_drain[n1] = v1616;	// L2109
    }
  }
}

void systolic_QKT(
  float v1617[64][64],
  float v1618[64][64],
  float v1619[64][64]
) {	// L2114
  float local_A[8][64];	// L2115
  #pragma HLS array_partition variable=local_A complete dim=1

  float local_B[64][8];	// L2116
  #pragma HLS array_partition variable=local_B complete dim=2

  float local_C[8][8];	// L2117
  #pragma HLS array_partition variable=local_C complete dim=1
  #pragma HLS array_partition variable=local_C complete dim=2

  l_outer_tile_mi: for (int mi = 0; mi < 8; mi++) {	// L2118
    l_ni: for (int ni = 0; ni < 8; ni++) {	// L2119
    #pragma HLS dataflow
      l_load_A_tile_ak: for (int ak = 0; ak < 64; ak++) {	// L2120
        l_ai: for (int ai = 0; ai < 8; ai++) {	// L2121
        #pragma HLS pipeline II=1
          ap_int<33> v1627 = ni;	// L2122
          bool v1628 = v1627 == 0;	// L2125
          if (v1628) {	// L2126
            float v1629 = v1617[((mi * 8) + ai)][ak];	// L2127
            local_A[ai][ak] = v1629;	// L2128
          }
        }
      }
      l_load_B_tile_bk: for (int bk = 0; bk < 64; bk++) {	// L2132
        l_bj: for (int bj = 0; bj < 8; bj++) {	// L2133
        #pragma HLS pipeline II=1
          float v1632 = v1618[bk][((ni * 8) + bj)];	// L2134
          local_B[bk][bj] = v1632;	// L2135
        }
      }
      systolic_tile_QKT(local_A, local_B, local_C);	// L2138
      l_store_C_tile_sj: for (int sj = 0; sj < 8; sj++) {	// L2139
        l_si: for (int si = 0; si < 8; si++) {	// L2140
        #pragma HLS pipeline II=1
          float v1635 = local_C[si][sj];	// L2141
          v1619[((mi * 8) + si)][((ni * 8) + sj)] = v1635;	// L2142
        }
      }
    }
  }
}

void mask_softmax_per_head_sft_Y(
  float v1636[64][64],
  int32_t v1637[2],
  float v1638[64][64]
) {	// L2149
  float E[64][64];	// L2151
  float S[64];	// L2152
  for (int v1641 = 0; v1641 < 64; v1641++) {	// L2154
    S[v1641] = 0.000000;	// L2154
  }
  float M[64];	// L2157
  for (int v1643 = 0; v1643 < 64; v1643++) {	// L2158
    M[v1643] = -10000.000000;	// L2158
  }
  l_row_max_i: for (int i = 0; i < 64; i++) {	// L2159
    l_j: for (int j = 0; j < 64; j++) {	// L2160
    #pragma HLS pipeline II=1
      bool v1646 = i >= j;	// L2161
      if (v1646) {	// L2162
        int32_t v1647 = v1637[0];	// L2163
        ap_int<33> v1648 = v1647;	// L2166
        ap_int<33> v1649 = 64 - v1648;	// L2167
        ap_int<33> v1650 = i;	// L2168
        bool v1651 = v1650 >= v1649;	// L2169
        if (v1651) {	// L2170
          int32_t v1652 = v1637[0];	// L2171
          ap_int<33> v1653 = v1652;	// L2172
          ap_int<33> v1654 = 64 - v1653;	// L2173
          ap_int<33> v1655 = j;	// L2174
          bool v1656 = v1655 >= v1654;	// L2175
          if (v1656) {	// L2176
            float v1657 = v1636[i][j];	// L2177
            float v1658 = M[i];	// L2178
            bool v1659 = v1657 > v1658;	// L2179
            if (v1659) {	// L2180
              float v1660 = v1636[i][j];	// L2181
              M[i] = v1660;	// L2182
            }
          }
        }
      }
    }
  }
  l_exp_sum_i1: for (int i1 = 0; i1 < 64; i1++) {	// L2189
    l_j1: for (int j1 = 0; j1 < 64; j1++) {	// L2190
    #pragma HLS pipeline II=1
      bool v1663 = i1 >= j1;	// L2191
      if (v1663) {	// L2192
        int32_t v1664 = v1637[0];	// L2193
        ap_int<33> v1665 = v1664;	// L2196
        ap_int<33> v1666 = 64 - v1665;	// L2197
        ap_int<33> v1667 = i1;	// L2198
        bool v1668 = v1667 >= v1666;	// L2199
        if (v1668) {	// L2200
          int32_t v1669 = v1637[0];	// L2201
          ap_int<33> v1670 = v1669;	// L2202
          ap_int<33> v1671 = 64 - v1670;	// L2203
          ap_int<33> v1672 = j1;	// L2204
          bool v1673 = v1672 >= v1671;	// L2205
          if (v1673) {	// L2206
            float v1674 = v1636[i1][j1];	// L2207
            float v1675 = M[i1];	// L2208
            float v1676 = v1674 - v1675;	// L2209
            float v1677 = exp(v1676);	// L2210
            E[i1][j1] = v1677;	// L2211
            float v1678 = E[i1][j1];	// L2212
            float v1679 = S[i1];	// L2213
            float v1680 = v1679 + v1678;	// L2214
            S[i1] = v1680;	// L2215
          }
        }
      }
    }
  }
  l_update_i2: for (int i2 = 0; i2 < 64; i2++) {	// L2221
    l_j2: for (int j2 = 0; j2 < 64; j2++) {	// L2222
    #pragma HLS pipeline II=1
      bool v1683 = i2 >= j2;	// L2223
      if (v1683) {	// L2224
        int32_t v1684 = v1637[0];	// L2225
        ap_int<33> v1685 = v1684;	// L2228
        ap_int<33> v1686 = 64 - v1685;	// L2229
        ap_int<33> v1687 = i2;	// L2230
        bool v1688 = v1687 >= v1686;	// L2231
        if (v1688) {	// L2232
          int32_t v1689 = v1637[0];	// L2233
          ap_int<33> v1690 = v1689;	// L2234
          ap_int<33> v1691 = 64 - v1690;	// L2235
          ap_int<33> v1692 = j2;	// L2236
          bool v1693 = v1692 >= v1691;	// L2237
          if (v1693) {	// L2238
            float v1694 = E[i2][j2];	// L2239
            float v1695 = S[i2];	// L2240
            float v1696 = v1694 / v1695;	// L2241
            v1638[i2][j2] = v1696;	// L2242
          } else {
            v1638[i2][j2] = 0.000000;	// L2246
          }
        } else {
          ap_int<34> v1697 = i2;	// L2249
          ap_int<34> v1698 = v1697 + 1;	// L2252
          int32_t v1699 = v1637[0];	// L2253
          ap_int<35> v1700 = v1698;	// L2254
          ap_int<35> v1701 = v1699;	// L2255
          ap_int<35> v1702 = v1700 + v1701;	// L2256
          float v1703 = v1702;	// L2257
          float v1704 = 1.000000 / v1703;	// L2259
          v1638[i2][j2] = v1704;	// L2260
        }
      } else {
        int32_t v1705 = v1637[0];	// L2263
        ap_int<33> v1706 = v1705;	// L2266
        ap_int<33> v1707 = 64 - v1706;	// L2267
        ap_int<33> v1708 = i2;	// L2268
        bool v1709 = v1708 < v1707;	// L2269
        ap_int<33> v1710 = j2;	// L2270
        bool v1711 = v1710 >= v1707;	// L2271
        bool v1712 = v1709 & v1711;	// L2272
        if (v1712) {	// L2273
          ap_int<34> v1713 = i2;	// L2274
          ap_int<34> v1714 = v1713 + 1;	// L2277
          int32_t v1715 = v1637[0];	// L2278
          ap_int<35> v1716 = v1714;	// L2279
          ap_int<35> v1717 = v1715;	// L2280
          ap_int<35> v1718 = v1716 + v1717;	// L2281
          float v1719 = v1718;	// L2282
          float v1720 = 1.000000 / v1719;	// L2284
          v1638[i2][j2] = v1720;	// L2285
        } else {
          v1638[i2][j2] = 0.000000;	// L2289
        }
      }
    }
  }
}

void PE_kernel_YV_0_0(
  hls::stream< float > &v1721 /* v1721[64] */,
  hls::stream< float > &v1722 /* v1722[64] */,
  hls::stream< float > &v1723 /* v1723[64] */,
  hls::stream< float > &v1724 /* v1724[64] */,
  float v1725[8][8],
  int v1726,
  int v1727
) {	// L2296
  #pragma HLS stream variable=v1721 depth=9
  #pragma HLS stream variable=v1722 depth=9
  #pragma HLS stream variable=v1723 depth=9
  #pragma HLS stream variable=v1724 depth=9
  #pragma HLS array_partition variable=v1725 complete dim=1
  #pragma HLS array_partition variable=v1725 complete dim=2

  float v64;	// L2299
  v64 = 0.000000;	// L2300
  l_S_k_0_k66: for (int k66 = 0; k66 < 64; k66++) {	// L2301
    float v1730 = v1721.read(); // v1721[k66];	// L2302
    float a64;	// L2303
    a64 = v1730;	// L2304
    float v1732 = v1722.read(); // v1722[k66];	// L2305
    float b64;	// L2306
    b64 = v1732;	// L2307
    float v1734 = a64;	// L2308
    float v1735 = b64;	// L2309
    float v1736 = v1734 * v1735;	// L2310
    float v1737 = v64;	// L2311
    float v1738 = v1737 + v1736;	// L2312
    v64 = v1738;	// L2313
    float v1739 = a64;	// L2314
    v1723.write(v1739); // v1723[k66] = v1739;	// L2315
    float v1740 = b64;	// L2316
    v1724.write(v1740); // v1724[k66] = v1740;	// L2317
  }
  float v1741 = v64;	// L2319
  v1725[v1726][v1727] = v1741;	// L2320
}

void PE_kernel_YV_1_0(
  hls::stream< float > &v1742 /* v1742[64] */,
  hls::stream< float > &v1743 /* v1743[64] */,
  hls::stream< float > &v1744 /* v1744[64] */,
  hls::stream< float > &v1745 /* v1745[64] */,
  float v1746[8][8],
  int v1747,
  int v1748
) {	// L2323
  #pragma HLS stream variable=v1742 depth=9
  #pragma HLS stream variable=v1743 depth=9
  #pragma HLS stream variable=v1744 depth=9
  #pragma HLS stream variable=v1745 depth=9
  #pragma HLS array_partition variable=v1746 complete dim=1
  #pragma HLS array_partition variable=v1746 complete dim=2

  float v65;	// L2326
  v65 = 0.000000;	// L2327
  l_S_k_0_k67: for (int k67 = 0; k67 < 64; k67++) {	// L2328
    float v1751 = v1742.read(); // v1742[k67];	// L2329
    float a65;	// L2330
    a65 = v1751;	// L2331
    float v1753 = v1743.read(); // v1743[k67];	// L2332
    float b65;	// L2333
    b65 = v1753;	// L2334
    float v1755 = a65;	// L2335
    float v1756 = b65;	// L2336
    float v1757 = v1755 * v1756;	// L2337
    float v1758 = v65;	// L2338
    float v1759 = v1758 + v1757;	// L2339
    v65 = v1759;	// L2340
    float v1760 = a65;	// L2341
    v1744.write(v1760); // v1744[k67] = v1760;	// L2342
    float v1761 = b65;	// L2343
    v1745.write(v1761); // v1745[k67] = v1761;	// L2344
  }
  float v1762 = v65;	// L2346
  v1746[v1747][v1748] = v1762;	// L2347
}

void PE_kernel_YV_2_0(
  hls::stream< float > &v1763 /* v1763[64] */,
  hls::stream< float > &v1764 /* v1764[64] */,
  hls::stream< float > &v1765 /* v1765[64] */,
  hls::stream< float > &v1766 /* v1766[64] */,
  float v1767[8][8],
  int v1768,
  int v1769
) {	// L2350
  #pragma HLS stream variable=v1763 depth=9
  #pragma HLS stream variable=v1764 depth=9
  #pragma HLS stream variable=v1765 depth=9
  #pragma HLS stream variable=v1766 depth=9
  #pragma HLS array_partition variable=v1767 complete dim=1
  #pragma HLS array_partition variable=v1767 complete dim=2

  float v66;	// L2353
  v66 = 0.000000;	// L2354
  l_S_k_0_k68: for (int k68 = 0; k68 < 64; k68++) {	// L2355
    float v1772 = v1763.read(); // v1763[k68];	// L2356
    float a66;	// L2357
    a66 = v1772;	// L2358
    float v1774 = v1764.read(); // v1764[k68];	// L2359
    float b66;	// L2360
    b66 = v1774;	// L2361
    float v1776 = a66;	// L2362
    float v1777 = b66;	// L2363
    float v1778 = v1776 * v1777;	// L2364
    float v1779 = v66;	// L2365
    float v1780 = v1779 + v1778;	// L2366
    v66 = v1780;	// L2367
    float v1781 = a66;	// L2368
    v1765.write(v1781); // v1765[k68] = v1781;	// L2369
    float v1782 = b66;	// L2370
    v1766.write(v1782); // v1766[k68] = v1782;	// L2371
  }
  float v1783 = v66;	// L2373
  v1767[v1768][v1769] = v1783;	// L2374
}

void PE_kernel_YV_3_0(
  hls::stream< float > &v1784 /* v1784[64] */,
  hls::stream< float > &v1785 /* v1785[64] */,
  hls::stream< float > &v1786 /* v1786[64] */,
  hls::stream< float > &v1787 /* v1787[64] */,
  float v1788[8][8],
  int v1789,
  int v1790
) {	// L2377
  #pragma HLS stream variable=v1784 depth=9
  #pragma HLS stream variable=v1785 depth=9
  #pragma HLS stream variable=v1786 depth=9
  #pragma HLS stream variable=v1787 depth=9
  #pragma HLS array_partition variable=v1788 complete dim=1
  #pragma HLS array_partition variable=v1788 complete dim=2

  float v67;	// L2380
  v67 = 0.000000;	// L2381
  l_S_k_0_k69: for (int k69 = 0; k69 < 64; k69++) {	// L2382
    float v1793 = v1784.read(); // v1784[k69];	// L2383
    float a67;	// L2384
    a67 = v1793;	// L2385
    float v1795 = v1785.read(); // v1785[k69];	// L2386
    float b67;	// L2387
    b67 = v1795;	// L2388
    float v1797 = a67;	// L2389
    float v1798 = b67;	// L2390
    float v1799 = v1797 * v1798;	// L2391
    float v1800 = v67;	// L2392
    float v1801 = v1800 + v1799;	// L2393
    v67 = v1801;	// L2394
    float v1802 = a67;	// L2395
    v1786.write(v1802); // v1786[k69] = v1802;	// L2396
    float v1803 = b67;	// L2397
    v1787.write(v1803); // v1787[k69] = v1803;	// L2398
  }
  float v1804 = v67;	// L2400
  v1788[v1789][v1790] = v1804;	// L2401
}

void PE_kernel_YV_4_0(
  hls::stream< float > &v1805 /* v1805[64] */,
  hls::stream< float > &v1806 /* v1806[64] */,
  hls::stream< float > &v1807 /* v1807[64] */,
  hls::stream< float > &v1808 /* v1808[64] */,
  float v1809[8][8],
  int v1810,
  int v1811
) {	// L2404
  #pragma HLS stream variable=v1805 depth=9
  #pragma HLS stream variable=v1806 depth=9
  #pragma HLS stream variable=v1807 depth=9
  #pragma HLS stream variable=v1808 depth=9
  #pragma HLS array_partition variable=v1809 complete dim=1
  #pragma HLS array_partition variable=v1809 complete dim=2

  float v68;	// L2407
  v68 = 0.000000;	// L2408
  l_S_k_0_k70: for (int k70 = 0; k70 < 64; k70++) {	// L2409
    float v1814 = v1805.read(); // v1805[k70];	// L2410
    float a68;	// L2411
    a68 = v1814;	// L2412
    float v1816 = v1806.read(); // v1806[k70];	// L2413
    float b68;	// L2414
    b68 = v1816;	// L2415
    float v1818 = a68;	// L2416
    float v1819 = b68;	// L2417
    float v1820 = v1818 * v1819;	// L2418
    float v1821 = v68;	// L2419
    float v1822 = v1821 + v1820;	// L2420
    v68 = v1822;	// L2421
    float v1823 = a68;	// L2422
    v1807.write(v1823); // v1807[k70] = v1823;	// L2423
    float v1824 = b68;	// L2424
    v1808.write(v1824); // v1808[k70] = v1824;	// L2425
  }
  float v1825 = v68;	// L2427
  v1809[v1810][v1811] = v1825;	// L2428
}

void PE_kernel_YV_5_0(
  hls::stream< float > &v1826 /* v1826[64] */,
  hls::stream< float > &v1827 /* v1827[64] */,
  hls::stream< float > &v1828 /* v1828[64] */,
  hls::stream< float > &v1829 /* v1829[64] */,
  float v1830[8][8],
  int v1831,
  int v1832
) {	// L2431
  #pragma HLS stream variable=v1826 depth=9
  #pragma HLS stream variable=v1827 depth=9
  #pragma HLS stream variable=v1828 depth=9
  #pragma HLS stream variable=v1829 depth=9
  #pragma HLS array_partition variable=v1830 complete dim=1
  #pragma HLS array_partition variable=v1830 complete dim=2

  float v69;	// L2434
  v69 = 0.000000;	// L2435
  l_S_k_0_k71: for (int k71 = 0; k71 < 64; k71++) {	// L2436
    float v1835 = v1826.read(); // v1826[k71];	// L2437
    float a69;	// L2438
    a69 = v1835;	// L2439
    float v1837 = v1827.read(); // v1827[k71];	// L2440
    float b69;	// L2441
    b69 = v1837;	// L2442
    float v1839 = a69;	// L2443
    float v1840 = b69;	// L2444
    float v1841 = v1839 * v1840;	// L2445
    float v1842 = v69;	// L2446
    float v1843 = v1842 + v1841;	// L2447
    v69 = v1843;	// L2448
    float v1844 = a69;	// L2449
    v1828.write(v1844); // v1828[k71] = v1844;	// L2450
    float v1845 = b69;	// L2451
    v1829.write(v1845); // v1829[k71] = v1845;	// L2452
  }
  float v1846 = v69;	// L2454
  v1830[v1831][v1832] = v1846;	// L2455
}

void PE_kernel_YV_6_0(
  hls::stream< float > &v1847 /* v1847[64] */,
  hls::stream< float > &v1848 /* v1848[64] */,
  hls::stream< float > &v1849 /* v1849[64] */,
  hls::stream< float > &v1850 /* v1850[64] */,
  float v1851[8][8],
  int v1852,
  int v1853
) {	// L2458
  #pragma HLS stream variable=v1847 depth=9
  #pragma HLS stream variable=v1848 depth=9
  #pragma HLS stream variable=v1849 depth=9
  #pragma HLS stream variable=v1850 depth=9
  #pragma HLS array_partition variable=v1851 complete dim=1
  #pragma HLS array_partition variable=v1851 complete dim=2

  float v70;	// L2461
  v70 = 0.000000;	// L2462
  l_S_k_0_k72: for (int k72 = 0; k72 < 64; k72++) {	// L2463
    float v1856 = v1847.read(); // v1847[k72];	// L2464
    float a70;	// L2465
    a70 = v1856;	// L2466
    float v1858 = v1848.read(); // v1848[k72];	// L2467
    float b70;	// L2468
    b70 = v1858;	// L2469
    float v1860 = a70;	// L2470
    float v1861 = b70;	// L2471
    float v1862 = v1860 * v1861;	// L2472
    float v1863 = v70;	// L2473
    float v1864 = v1863 + v1862;	// L2474
    v70 = v1864;	// L2475
    float v1865 = a70;	// L2476
    v1849.write(v1865); // v1849[k72] = v1865;	// L2477
    float v1866 = b70;	// L2478
    v1850.write(v1866); // v1850[k72] = v1866;	// L2479
  }
  float v1867 = v70;	// L2481
  v1851[v1852][v1853] = v1867;	// L2482
}

void PE_kernel_YV_7_0(
  hls::stream< float > &v1868 /* v1868[64] */,
  hls::stream< float > &v1869 /* v1869[64] */,
  hls::stream< float > &v1870 /* v1870[64] */,
  hls::stream< float > &v1871 /* v1871[64] */,
  float v1872[8][8],
  int v1873,
  int v1874
) {	// L2485
  #pragma HLS stream variable=v1868 depth=9
  #pragma HLS stream variable=v1869 depth=9
  #pragma HLS stream variable=v1870 depth=9
  #pragma HLS stream variable=v1871 depth=9
  #pragma HLS array_partition variable=v1872 complete dim=1
  #pragma HLS array_partition variable=v1872 complete dim=2

  float v71;	// L2488
  v71 = 0.000000;	// L2489
  l_S_k_0_k73: for (int k73 = 0; k73 < 64; k73++) {	// L2490
    float v1877 = v1868.read(); // v1868[k73];	// L2491
    float a71;	// L2492
    a71 = v1877;	// L2493
    float v1879 = v1869.read(); // v1869[k73];	// L2494
    float b71;	// L2495
    b71 = v1879;	// L2496
    float v1881 = a71;	// L2497
    float v1882 = b71;	// L2498
    float v1883 = v1881 * v1882;	// L2499
    float v1884 = v71;	// L2500
    float v1885 = v1884 + v1883;	// L2501
    v71 = v1885;	// L2502
    float v1886 = a71;	// L2503
    v1870.write(v1886); // v1870[k73] = v1886;	// L2504
    float v1887 = b71;	// L2505
    v1871.write(v1887); // v1871[k73] = v1887;	// L2506
  }
  float v1888 = v71;	// L2508
  v1872[v1873][v1874] = v1888;	// L2509
}

void PE_kernel_YV_0_1(
  hls::stream< float > &v1889 /* v1889[64] */,
  hls::stream< float > &v1890 /* v1890[64] */,
  hls::stream< float > &v1891 /* v1891[64] */,
  hls::stream< float > &v1892 /* v1892[64] */,
  float v1893[8][8],
  int v1894,
  int v1895
) {	// L2512
  #pragma HLS stream variable=v1889 depth=9
  #pragma HLS stream variable=v1890 depth=9
  #pragma HLS stream variable=v1891 depth=9
  #pragma HLS stream variable=v1892 depth=9
  #pragma HLS array_partition variable=v1893 complete dim=1
  #pragma HLS array_partition variable=v1893 complete dim=2

  float v72;	// L2515
  v72 = 0.000000;	// L2516
  l_S_k_0_k74: for (int k74 = 0; k74 < 64; k74++) {	// L2517
    float v1898 = v1889.read(); // v1889[k74];	// L2518
    float a72;	// L2519
    a72 = v1898;	// L2520
    float v1900 = v1890.read(); // v1890[k74];	// L2521
    float b72;	// L2522
    b72 = v1900;	// L2523
    float v1902 = a72;	// L2524
    float v1903 = b72;	// L2525
    float v1904 = v1902 * v1903;	// L2526
    float v1905 = v72;	// L2527
    float v1906 = v1905 + v1904;	// L2528
    v72 = v1906;	// L2529
    float v1907 = a72;	// L2530
    v1891.write(v1907); // v1891[k74] = v1907;	// L2531
    float v1908 = b72;	// L2532
    v1892.write(v1908); // v1892[k74] = v1908;	// L2533
  }
  float v1909 = v72;	// L2535
  v1893[v1894][v1895] = v1909;	// L2536
}

void PE_kernel_YV_1_1(
  hls::stream< float > &v1910 /* v1910[64] */,
  hls::stream< float > &v1911 /* v1911[64] */,
  hls::stream< float > &v1912 /* v1912[64] */,
  hls::stream< float > &v1913 /* v1913[64] */,
  float v1914[8][8],
  int v1915,
  int v1916
) {	// L2539
  #pragma HLS stream variable=v1910 depth=9
  #pragma HLS stream variable=v1911 depth=9
  #pragma HLS stream variable=v1912 depth=9
  #pragma HLS stream variable=v1913 depth=9
  #pragma HLS array_partition variable=v1914 complete dim=1
  #pragma HLS array_partition variable=v1914 complete dim=2

  float v73;	// L2542
  v73 = 0.000000;	// L2543
  l_S_k_0_k75: for (int k75 = 0; k75 < 64; k75++) {	// L2544
    float v1919 = v1910.read(); // v1910[k75];	// L2545
    float a73;	// L2546
    a73 = v1919;	// L2547
    float v1921 = v1911.read(); // v1911[k75];	// L2548
    float b73;	// L2549
    b73 = v1921;	// L2550
    float v1923 = a73;	// L2551
    float v1924 = b73;	// L2552
    float v1925 = v1923 * v1924;	// L2553
    float v1926 = v73;	// L2554
    float v1927 = v1926 + v1925;	// L2555
    v73 = v1927;	// L2556
    float v1928 = a73;	// L2557
    v1912.write(v1928); // v1912[k75] = v1928;	// L2558
    float v1929 = b73;	// L2559
    v1913.write(v1929); // v1913[k75] = v1929;	// L2560
  }
  float v1930 = v73;	// L2562
  v1914[v1915][v1916] = v1930;	// L2563
}

void PE_kernel_YV_2_1(
  hls::stream< float > &v1931 /* v1931[64] */,
  hls::stream< float > &v1932 /* v1932[64] */,
  hls::stream< float > &v1933 /* v1933[64] */,
  hls::stream< float > &v1934 /* v1934[64] */,
  float v1935[8][8],
  int v1936,
  int v1937
) {	// L2566
  #pragma HLS stream variable=v1931 depth=9
  #pragma HLS stream variable=v1932 depth=9
  #pragma HLS stream variable=v1933 depth=9
  #pragma HLS stream variable=v1934 depth=9
  #pragma HLS array_partition variable=v1935 complete dim=1
  #pragma HLS array_partition variable=v1935 complete dim=2

  float v74;	// L2569
  v74 = 0.000000;	// L2570
  l_S_k_0_k76: for (int k76 = 0; k76 < 64; k76++) {	// L2571
    float v1940 = v1931.read(); // v1931[k76];	// L2572
    float a74;	// L2573
    a74 = v1940;	// L2574
    float v1942 = v1932.read(); // v1932[k76];	// L2575
    float b74;	// L2576
    b74 = v1942;	// L2577
    float v1944 = a74;	// L2578
    float v1945 = b74;	// L2579
    float v1946 = v1944 * v1945;	// L2580
    float v1947 = v74;	// L2581
    float v1948 = v1947 + v1946;	// L2582
    v74 = v1948;	// L2583
    float v1949 = a74;	// L2584
    v1933.write(v1949); // v1933[k76] = v1949;	// L2585
    float v1950 = b74;	// L2586
    v1934.write(v1950); // v1934[k76] = v1950;	// L2587
  }
  float v1951 = v74;	// L2589
  v1935[v1936][v1937] = v1951;	// L2590
}

void PE_kernel_YV_3_1(
  hls::stream< float > &v1952 /* v1952[64] */,
  hls::stream< float > &v1953 /* v1953[64] */,
  hls::stream< float > &v1954 /* v1954[64] */,
  hls::stream< float > &v1955 /* v1955[64] */,
  float v1956[8][8],
  int v1957,
  int v1958
) {	// L2593
  #pragma HLS stream variable=v1952 depth=9
  #pragma HLS stream variable=v1953 depth=9
  #pragma HLS stream variable=v1954 depth=9
  #pragma HLS stream variable=v1955 depth=9
  #pragma HLS array_partition variable=v1956 complete dim=1
  #pragma HLS array_partition variable=v1956 complete dim=2

  float v75;	// L2596
  v75 = 0.000000;	// L2597
  l_S_k_0_k77: for (int k77 = 0; k77 < 64; k77++) {	// L2598
    float v1961 = v1952.read(); // v1952[k77];	// L2599
    float a75;	// L2600
    a75 = v1961;	// L2601
    float v1963 = v1953.read(); // v1953[k77];	// L2602
    float b75;	// L2603
    b75 = v1963;	// L2604
    float v1965 = a75;	// L2605
    float v1966 = b75;	// L2606
    float v1967 = v1965 * v1966;	// L2607
    float v1968 = v75;	// L2608
    float v1969 = v1968 + v1967;	// L2609
    v75 = v1969;	// L2610
    float v1970 = a75;	// L2611
    v1954.write(v1970); // v1954[k77] = v1970;	// L2612
    float v1971 = b75;	// L2613
    v1955.write(v1971); // v1955[k77] = v1971;	// L2614
  }
  float v1972 = v75;	// L2616
  v1956[v1957][v1958] = v1972;	// L2617
}

void PE_kernel_YV_4_1(
  hls::stream< float > &v1973 /* v1973[64] */,
  hls::stream< float > &v1974 /* v1974[64] */,
  hls::stream< float > &v1975 /* v1975[64] */,
  hls::stream< float > &v1976 /* v1976[64] */,
  float v1977[8][8],
  int v1978,
  int v1979
) {	// L2620
  #pragma HLS stream variable=v1973 depth=9
  #pragma HLS stream variable=v1974 depth=9
  #pragma HLS stream variable=v1975 depth=9
  #pragma HLS stream variable=v1976 depth=9
  #pragma HLS array_partition variable=v1977 complete dim=1
  #pragma HLS array_partition variable=v1977 complete dim=2

  float v76;	// L2623
  v76 = 0.000000;	// L2624
  l_S_k_0_k78: for (int k78 = 0; k78 < 64; k78++) {	// L2625
    float v1982 = v1973.read(); // v1973[k78];	// L2626
    float a76;	// L2627
    a76 = v1982;	// L2628
    float v1984 = v1974.read(); // v1974[k78];	// L2629
    float b76;	// L2630
    b76 = v1984;	// L2631
    float v1986 = a76;	// L2632
    float v1987 = b76;	// L2633
    float v1988 = v1986 * v1987;	// L2634
    float v1989 = v76;	// L2635
    float v1990 = v1989 + v1988;	// L2636
    v76 = v1990;	// L2637
    float v1991 = a76;	// L2638
    v1975.write(v1991); // v1975[k78] = v1991;	// L2639
    float v1992 = b76;	// L2640
    v1976.write(v1992); // v1976[k78] = v1992;	// L2641
  }
  float v1993 = v76;	// L2643
  v1977[v1978][v1979] = v1993;	// L2644
}

void PE_kernel_YV_5_1(
  hls::stream< float > &v1994 /* v1994[64] */,
  hls::stream< float > &v1995 /* v1995[64] */,
  hls::stream< float > &v1996 /* v1996[64] */,
  hls::stream< float > &v1997 /* v1997[64] */,
  float v1998[8][8],
  int v1999,
  int v2000
) {	// L2647
  #pragma HLS stream variable=v1994 depth=9
  #pragma HLS stream variable=v1995 depth=9
  #pragma HLS stream variable=v1996 depth=9
  #pragma HLS stream variable=v1997 depth=9
  #pragma HLS array_partition variable=v1998 complete dim=1
  #pragma HLS array_partition variable=v1998 complete dim=2

  float v77;	// L2650
  v77 = 0.000000;	// L2651
  l_S_k_0_k79: for (int k79 = 0; k79 < 64; k79++) {	// L2652
    float v2003 = v1994.read(); // v1994[k79];	// L2653
    float a77;	// L2654
    a77 = v2003;	// L2655
    float v2005 = v1995.read(); // v1995[k79];	// L2656
    float b77;	// L2657
    b77 = v2005;	// L2658
    float v2007 = a77;	// L2659
    float v2008 = b77;	// L2660
    float v2009 = v2007 * v2008;	// L2661
    float v2010 = v77;	// L2662
    float v2011 = v2010 + v2009;	// L2663
    v77 = v2011;	// L2664
    float v2012 = a77;	// L2665
    v1996.write(v2012); // v1996[k79] = v2012;	// L2666
    float v2013 = b77;	// L2667
    v1997.write(v2013); // v1997[k79] = v2013;	// L2668
  }
  float v2014 = v77;	// L2670
  v1998[v1999][v2000] = v2014;	// L2671
}

void PE_kernel_YV_6_1(
  hls::stream< float > &v2015 /* v2015[64] */,
  hls::stream< float > &v2016 /* v2016[64] */,
  hls::stream< float > &v2017 /* v2017[64] */,
  hls::stream< float > &v2018 /* v2018[64] */,
  float v2019[8][8],
  int v2020,
  int v2021
) {	// L2674
  #pragma HLS stream variable=v2015 depth=9
  #pragma HLS stream variable=v2016 depth=9
  #pragma HLS stream variable=v2017 depth=9
  #pragma HLS stream variable=v2018 depth=9
  #pragma HLS array_partition variable=v2019 complete dim=1
  #pragma HLS array_partition variable=v2019 complete dim=2

  float v78;	// L2677
  v78 = 0.000000;	// L2678
  l_S_k_0_k80: for (int k80 = 0; k80 < 64; k80++) {	// L2679
    float v2024 = v2015.read(); // v2015[k80];	// L2680
    float a78;	// L2681
    a78 = v2024;	// L2682
    float v2026 = v2016.read(); // v2016[k80];	// L2683
    float b78;	// L2684
    b78 = v2026;	// L2685
    float v2028 = a78;	// L2686
    float v2029 = b78;	// L2687
    float v2030 = v2028 * v2029;	// L2688
    float v2031 = v78;	// L2689
    float v2032 = v2031 + v2030;	// L2690
    v78 = v2032;	// L2691
    float v2033 = a78;	// L2692
    v2017.write(v2033); // v2017[k80] = v2033;	// L2693
    float v2034 = b78;	// L2694
    v2018.write(v2034); // v2018[k80] = v2034;	// L2695
  }
  float v2035 = v78;	// L2697
  v2019[v2020][v2021] = v2035;	// L2698
}

void PE_kernel_YV_7_1(
  hls::stream< float > &v2036 /* v2036[64] */,
  hls::stream< float > &v2037 /* v2037[64] */,
  hls::stream< float > &v2038 /* v2038[64] */,
  hls::stream< float > &v2039 /* v2039[64] */,
  float v2040[8][8],
  int v2041,
  int v2042
) {	// L2701
  #pragma HLS stream variable=v2036 depth=9
  #pragma HLS stream variable=v2037 depth=9
  #pragma HLS stream variable=v2038 depth=9
  #pragma HLS stream variable=v2039 depth=9
  #pragma HLS array_partition variable=v2040 complete dim=1
  #pragma HLS array_partition variable=v2040 complete dim=2

  float v79;	// L2704
  v79 = 0.000000;	// L2705
  l_S_k_0_k81: for (int k81 = 0; k81 < 64; k81++) {	// L2706
    float v2045 = v2036.read(); // v2036[k81];	// L2707
    float a79;	// L2708
    a79 = v2045;	// L2709
    float v2047 = v2037.read(); // v2037[k81];	// L2710
    float b79;	// L2711
    b79 = v2047;	// L2712
    float v2049 = a79;	// L2713
    float v2050 = b79;	// L2714
    float v2051 = v2049 * v2050;	// L2715
    float v2052 = v79;	// L2716
    float v2053 = v2052 + v2051;	// L2717
    v79 = v2053;	// L2718
    float v2054 = a79;	// L2719
    v2038.write(v2054); // v2038[k81] = v2054;	// L2720
    float v2055 = b79;	// L2721
    v2039.write(v2055); // v2039[k81] = v2055;	// L2722
  }
  float v2056 = v79;	// L2724
  v2040[v2041][v2042] = v2056;	// L2725
}

void PE_kernel_YV_0_2(
  hls::stream< float > &v2057 /* v2057[64] */,
  hls::stream< float > &v2058 /* v2058[64] */,
  hls::stream< float > &v2059 /* v2059[64] */,
  hls::stream< float > &v2060 /* v2060[64] */,
  float v2061[8][8],
  int v2062,
  int v2063
) {	// L2728
  #pragma HLS stream variable=v2057 depth=9
  #pragma HLS stream variable=v2058 depth=9
  #pragma HLS stream variable=v2059 depth=9
  #pragma HLS stream variable=v2060 depth=9
  #pragma HLS array_partition variable=v2061 complete dim=1
  #pragma HLS array_partition variable=v2061 complete dim=2

  float v80;	// L2731
  v80 = 0.000000;	// L2732
  l_S_k_0_k82: for (int k82 = 0; k82 < 64; k82++) {	// L2733
    float v2066 = v2057.read(); // v2057[k82];	// L2734
    float a80;	// L2735
    a80 = v2066;	// L2736
    float v2068 = v2058.read(); // v2058[k82];	// L2737
    float b80;	// L2738
    b80 = v2068;	// L2739
    float v2070 = a80;	// L2740
    float v2071 = b80;	// L2741
    float v2072 = v2070 * v2071;	// L2742
    float v2073 = v80;	// L2743
    float v2074 = v2073 + v2072;	// L2744
    v80 = v2074;	// L2745
    float v2075 = a80;	// L2746
    v2059.write(v2075); // v2059[k82] = v2075;	// L2747
    float v2076 = b80;	// L2748
    v2060.write(v2076); // v2060[k82] = v2076;	// L2749
  }
  float v2077 = v80;	// L2751
  v2061[v2062][v2063] = v2077;	// L2752
}

void PE_kernel_YV_1_2(
  hls::stream< float > &v2078 /* v2078[64] */,
  hls::stream< float > &v2079 /* v2079[64] */,
  hls::stream< float > &v2080 /* v2080[64] */,
  hls::stream< float > &v2081 /* v2081[64] */,
  float v2082[8][8],
  int v2083,
  int v2084
) {	// L2755
  #pragma HLS stream variable=v2078 depth=9
  #pragma HLS stream variable=v2079 depth=9
  #pragma HLS stream variable=v2080 depth=9
  #pragma HLS stream variable=v2081 depth=9
  #pragma HLS array_partition variable=v2082 complete dim=1
  #pragma HLS array_partition variable=v2082 complete dim=2

  float v81;	// L2758
  v81 = 0.000000;	// L2759
  l_S_k_0_k83: for (int k83 = 0; k83 < 64; k83++) {	// L2760
    float v2087 = v2078.read(); // v2078[k83];	// L2761
    float a81;	// L2762
    a81 = v2087;	// L2763
    float v2089 = v2079.read(); // v2079[k83];	// L2764
    float b81;	// L2765
    b81 = v2089;	// L2766
    float v2091 = a81;	// L2767
    float v2092 = b81;	// L2768
    float v2093 = v2091 * v2092;	// L2769
    float v2094 = v81;	// L2770
    float v2095 = v2094 + v2093;	// L2771
    v81 = v2095;	// L2772
    float v2096 = a81;	// L2773
    v2080.write(v2096); // v2080[k83] = v2096;	// L2774
    float v2097 = b81;	// L2775
    v2081.write(v2097); // v2081[k83] = v2097;	// L2776
  }
  float v2098 = v81;	// L2778
  v2082[v2083][v2084] = v2098;	// L2779
}

void PE_kernel_YV_2_2(
  hls::stream< float > &v2099 /* v2099[64] */,
  hls::stream< float > &v2100 /* v2100[64] */,
  hls::stream< float > &v2101 /* v2101[64] */,
  hls::stream< float > &v2102 /* v2102[64] */,
  float v2103[8][8],
  int v2104,
  int v2105
) {	// L2782
  #pragma HLS stream variable=v2099 depth=9
  #pragma HLS stream variable=v2100 depth=9
  #pragma HLS stream variable=v2101 depth=9
  #pragma HLS stream variable=v2102 depth=9
  #pragma HLS array_partition variable=v2103 complete dim=1
  #pragma HLS array_partition variable=v2103 complete dim=2

  float v82;	// L2785
  v82 = 0.000000;	// L2786
  l_S_k_0_k84: for (int k84 = 0; k84 < 64; k84++) {	// L2787
    float v2108 = v2099.read(); // v2099[k84];	// L2788
    float a82;	// L2789
    a82 = v2108;	// L2790
    float v2110 = v2100.read(); // v2100[k84];	// L2791
    float b82;	// L2792
    b82 = v2110;	// L2793
    float v2112 = a82;	// L2794
    float v2113 = b82;	// L2795
    float v2114 = v2112 * v2113;	// L2796
    float v2115 = v82;	// L2797
    float v2116 = v2115 + v2114;	// L2798
    v82 = v2116;	// L2799
    float v2117 = a82;	// L2800
    v2101.write(v2117); // v2101[k84] = v2117;	// L2801
    float v2118 = b82;	// L2802
    v2102.write(v2118); // v2102[k84] = v2118;	// L2803
  }
  float v2119 = v82;	// L2805
  v2103[v2104][v2105] = v2119;	// L2806
}

void PE_kernel_YV_3_2(
  hls::stream< float > &v2120 /* v2120[64] */,
  hls::stream< float > &v2121 /* v2121[64] */,
  hls::stream< float > &v2122 /* v2122[64] */,
  hls::stream< float > &v2123 /* v2123[64] */,
  float v2124[8][8],
  int v2125,
  int v2126
) {	// L2809
  #pragma HLS stream variable=v2120 depth=9
  #pragma HLS stream variable=v2121 depth=9
  #pragma HLS stream variable=v2122 depth=9
  #pragma HLS stream variable=v2123 depth=9
  #pragma HLS array_partition variable=v2124 complete dim=1
  #pragma HLS array_partition variable=v2124 complete dim=2

  float v83;	// L2812
  v83 = 0.000000;	// L2813
  l_S_k_0_k85: for (int k85 = 0; k85 < 64; k85++) {	// L2814
    float v2129 = v2120.read(); // v2120[k85];	// L2815
    float a83;	// L2816
    a83 = v2129;	// L2817
    float v2131 = v2121.read(); // v2121[k85];	// L2818
    float b83;	// L2819
    b83 = v2131;	// L2820
    float v2133 = a83;	// L2821
    float v2134 = b83;	// L2822
    float v2135 = v2133 * v2134;	// L2823
    float v2136 = v83;	// L2824
    float v2137 = v2136 + v2135;	// L2825
    v83 = v2137;	// L2826
    float v2138 = a83;	// L2827
    v2122.write(v2138); // v2122[k85] = v2138;	// L2828
    float v2139 = b83;	// L2829
    v2123.write(v2139); // v2123[k85] = v2139;	// L2830
  }
  float v2140 = v83;	// L2832
  v2124[v2125][v2126] = v2140;	// L2833
}

void PE_kernel_YV_4_2(
  hls::stream< float > &v2141 /* v2141[64] */,
  hls::stream< float > &v2142 /* v2142[64] */,
  hls::stream< float > &v2143 /* v2143[64] */,
  hls::stream< float > &v2144 /* v2144[64] */,
  float v2145[8][8],
  int v2146,
  int v2147
) {	// L2836
  #pragma HLS stream variable=v2141 depth=9
  #pragma HLS stream variable=v2142 depth=9
  #pragma HLS stream variable=v2143 depth=9
  #pragma HLS stream variable=v2144 depth=9
  #pragma HLS array_partition variable=v2145 complete dim=1
  #pragma HLS array_partition variable=v2145 complete dim=2

  float v84;	// L2839
  v84 = 0.000000;	// L2840
  l_S_k_0_k86: for (int k86 = 0; k86 < 64; k86++) {	// L2841
    float v2150 = v2141.read(); // v2141[k86];	// L2842
    float a84;	// L2843
    a84 = v2150;	// L2844
    float v2152 = v2142.read(); // v2142[k86];	// L2845
    float b84;	// L2846
    b84 = v2152;	// L2847
    float v2154 = a84;	// L2848
    float v2155 = b84;	// L2849
    float v2156 = v2154 * v2155;	// L2850
    float v2157 = v84;	// L2851
    float v2158 = v2157 + v2156;	// L2852
    v84 = v2158;	// L2853
    float v2159 = a84;	// L2854
    v2143.write(v2159); // v2143[k86] = v2159;	// L2855
    float v2160 = b84;	// L2856
    v2144.write(v2160); // v2144[k86] = v2160;	// L2857
  }
  float v2161 = v84;	// L2859
  v2145[v2146][v2147] = v2161;	// L2860
}

void PE_kernel_YV_5_2(
  hls::stream< float > &v2162 /* v2162[64] */,
  hls::stream< float > &v2163 /* v2163[64] */,
  hls::stream< float > &v2164 /* v2164[64] */,
  hls::stream< float > &v2165 /* v2165[64] */,
  float v2166[8][8],
  int v2167,
  int v2168
) {	// L2863
  #pragma HLS stream variable=v2162 depth=9
  #pragma HLS stream variable=v2163 depth=9
  #pragma HLS stream variable=v2164 depth=9
  #pragma HLS stream variable=v2165 depth=9
  #pragma HLS array_partition variable=v2166 complete dim=1
  #pragma HLS array_partition variable=v2166 complete dim=2

  float v85;	// L2866
  v85 = 0.000000;	// L2867
  l_S_k_0_k87: for (int k87 = 0; k87 < 64; k87++) {	// L2868
    float v2171 = v2162.read(); // v2162[k87];	// L2869
    float a85;	// L2870
    a85 = v2171;	// L2871
    float v2173 = v2163.read(); // v2163[k87];	// L2872
    float b85;	// L2873
    b85 = v2173;	// L2874
    float v2175 = a85;	// L2875
    float v2176 = b85;	// L2876
    float v2177 = v2175 * v2176;	// L2877
    float v2178 = v85;	// L2878
    float v2179 = v2178 + v2177;	// L2879
    v85 = v2179;	// L2880
    float v2180 = a85;	// L2881
    v2164.write(v2180); // v2164[k87] = v2180;	// L2882
    float v2181 = b85;	// L2883
    v2165.write(v2181); // v2165[k87] = v2181;	// L2884
  }
  float v2182 = v85;	// L2886
  v2166[v2167][v2168] = v2182;	// L2887
}

void PE_kernel_YV_6_2(
  hls::stream< float > &v2183 /* v2183[64] */,
  hls::stream< float > &v2184 /* v2184[64] */,
  hls::stream< float > &v2185 /* v2185[64] */,
  hls::stream< float > &v2186 /* v2186[64] */,
  float v2187[8][8],
  int v2188,
  int v2189
) {	// L2890
  #pragma HLS stream variable=v2183 depth=9
  #pragma HLS stream variable=v2184 depth=9
  #pragma HLS stream variable=v2185 depth=9
  #pragma HLS stream variable=v2186 depth=9
  #pragma HLS array_partition variable=v2187 complete dim=1
  #pragma HLS array_partition variable=v2187 complete dim=2

  float v86;	// L2893
  v86 = 0.000000;	// L2894
  l_S_k_0_k88: for (int k88 = 0; k88 < 64; k88++) {	// L2895
    float v2192 = v2183.read(); // v2183[k88];	// L2896
    float a86;	// L2897
    a86 = v2192;	// L2898
    float v2194 = v2184.read(); // v2184[k88];	// L2899
    float b86;	// L2900
    b86 = v2194;	// L2901
    float v2196 = a86;	// L2902
    float v2197 = b86;	// L2903
    float v2198 = v2196 * v2197;	// L2904
    float v2199 = v86;	// L2905
    float v2200 = v2199 + v2198;	// L2906
    v86 = v2200;	// L2907
    float v2201 = a86;	// L2908
    v2185.write(v2201); // v2185[k88] = v2201;	// L2909
    float v2202 = b86;	// L2910
    v2186.write(v2202); // v2186[k88] = v2202;	// L2911
  }
  float v2203 = v86;	// L2913
  v2187[v2188][v2189] = v2203;	// L2914
}

void PE_kernel_YV_7_2(
  hls::stream< float > &v2204 /* v2204[64] */,
  hls::stream< float > &v2205 /* v2205[64] */,
  hls::stream< float > &v2206 /* v2206[64] */,
  hls::stream< float > &v2207 /* v2207[64] */,
  float v2208[8][8],
  int v2209,
  int v2210
) {	// L2917
  #pragma HLS stream variable=v2204 depth=9
  #pragma HLS stream variable=v2205 depth=9
  #pragma HLS stream variable=v2206 depth=9
  #pragma HLS stream variable=v2207 depth=9
  #pragma HLS array_partition variable=v2208 complete dim=1
  #pragma HLS array_partition variable=v2208 complete dim=2

  float v87;	// L2920
  v87 = 0.000000;	// L2921
  l_S_k_0_k89: for (int k89 = 0; k89 < 64; k89++) {	// L2922
    float v2213 = v2204.read(); // v2204[k89];	// L2923
    float a87;	// L2924
    a87 = v2213;	// L2925
    float v2215 = v2205.read(); // v2205[k89];	// L2926
    float b87;	// L2927
    b87 = v2215;	// L2928
    float v2217 = a87;	// L2929
    float v2218 = b87;	// L2930
    float v2219 = v2217 * v2218;	// L2931
    float v2220 = v87;	// L2932
    float v2221 = v2220 + v2219;	// L2933
    v87 = v2221;	// L2934
    float v2222 = a87;	// L2935
    v2206.write(v2222); // v2206[k89] = v2222;	// L2936
    float v2223 = b87;	// L2937
    v2207.write(v2223); // v2207[k89] = v2223;	// L2938
  }
  float v2224 = v87;	// L2940
  v2208[v2209][v2210] = v2224;	// L2941
}

void PE_kernel_YV_0_3(
  hls::stream< float > &v2225 /* v2225[64] */,
  hls::stream< float > &v2226 /* v2226[64] */,
  hls::stream< float > &v2227 /* v2227[64] */,
  hls::stream< float > &v2228 /* v2228[64] */,
  float v2229[8][8],
  int v2230,
  int v2231
) {	// L2944
  #pragma HLS stream variable=v2225 depth=9
  #pragma HLS stream variable=v2226 depth=9
  #pragma HLS stream variable=v2227 depth=9
  #pragma HLS stream variable=v2228 depth=9
  #pragma HLS array_partition variable=v2229 complete dim=1
  #pragma HLS array_partition variable=v2229 complete dim=2

  float v88;	// L2947
  v88 = 0.000000;	// L2948
  l_S_k_0_k90: for (int k90 = 0; k90 < 64; k90++) {	// L2949
    float v2234 = v2225.read(); // v2225[k90];	// L2950
    float a88;	// L2951
    a88 = v2234;	// L2952
    float v2236 = v2226.read(); // v2226[k90];	// L2953
    float b88;	// L2954
    b88 = v2236;	// L2955
    float v2238 = a88;	// L2956
    float v2239 = b88;	// L2957
    float v2240 = v2238 * v2239;	// L2958
    float v2241 = v88;	// L2959
    float v2242 = v2241 + v2240;	// L2960
    v88 = v2242;	// L2961
    float v2243 = a88;	// L2962
    v2227.write(v2243); // v2227[k90] = v2243;	// L2963
    float v2244 = b88;	// L2964
    v2228.write(v2244); // v2228[k90] = v2244;	// L2965
  }
  float v2245 = v88;	// L2967
  v2229[v2230][v2231] = v2245;	// L2968
}

void PE_kernel_YV_1_3(
  hls::stream< float > &v2246 /* v2246[64] */,
  hls::stream< float > &v2247 /* v2247[64] */,
  hls::stream< float > &v2248 /* v2248[64] */,
  hls::stream< float > &v2249 /* v2249[64] */,
  float v2250[8][8],
  int v2251,
  int v2252
) {	// L2971
  #pragma HLS stream variable=v2246 depth=9
  #pragma HLS stream variable=v2247 depth=9
  #pragma HLS stream variable=v2248 depth=9
  #pragma HLS stream variable=v2249 depth=9
  #pragma HLS array_partition variable=v2250 complete dim=1
  #pragma HLS array_partition variable=v2250 complete dim=2

  float v89;	// L2974
  v89 = 0.000000;	// L2975
  l_S_k_0_k91: for (int k91 = 0; k91 < 64; k91++) {	// L2976
    float v2255 = v2246.read(); // v2246[k91];	// L2977
    float a89;	// L2978
    a89 = v2255;	// L2979
    float v2257 = v2247.read(); // v2247[k91];	// L2980
    float b89;	// L2981
    b89 = v2257;	// L2982
    float v2259 = a89;	// L2983
    float v2260 = b89;	// L2984
    float v2261 = v2259 * v2260;	// L2985
    float v2262 = v89;	// L2986
    float v2263 = v2262 + v2261;	// L2987
    v89 = v2263;	// L2988
    float v2264 = a89;	// L2989
    v2248.write(v2264); // v2248[k91] = v2264;	// L2990
    float v2265 = b89;	// L2991
    v2249.write(v2265); // v2249[k91] = v2265;	// L2992
  }
  float v2266 = v89;	// L2994
  v2250[v2251][v2252] = v2266;	// L2995
}

void PE_kernel_YV_2_3(
  hls::stream< float > &v2267 /* v2267[64] */,
  hls::stream< float > &v2268 /* v2268[64] */,
  hls::stream< float > &v2269 /* v2269[64] */,
  hls::stream< float > &v2270 /* v2270[64] */,
  float v2271[8][8],
  int v2272,
  int v2273
) {	// L2998
  #pragma HLS stream variable=v2267 depth=9
  #pragma HLS stream variable=v2268 depth=9
  #pragma HLS stream variable=v2269 depth=9
  #pragma HLS stream variable=v2270 depth=9
  #pragma HLS array_partition variable=v2271 complete dim=1
  #pragma HLS array_partition variable=v2271 complete dim=2

  float v90;	// L3001
  v90 = 0.000000;	// L3002
  l_S_k_0_k92: for (int k92 = 0; k92 < 64; k92++) {	// L3003
    float v2276 = v2267.read(); // v2267[k92];	// L3004
    float a90;	// L3005
    a90 = v2276;	// L3006
    float v2278 = v2268.read(); // v2268[k92];	// L3007
    float b90;	// L3008
    b90 = v2278;	// L3009
    float v2280 = a90;	// L3010
    float v2281 = b90;	// L3011
    float v2282 = v2280 * v2281;	// L3012
    float v2283 = v90;	// L3013
    float v2284 = v2283 + v2282;	// L3014
    v90 = v2284;	// L3015
    float v2285 = a90;	// L3016
    v2269.write(v2285); // v2269[k92] = v2285;	// L3017
    float v2286 = b90;	// L3018
    v2270.write(v2286); // v2270[k92] = v2286;	// L3019
  }
  float v2287 = v90;	// L3021
  v2271[v2272][v2273] = v2287;	// L3022
}

void PE_kernel_YV_3_3(
  hls::stream< float > &v2288 /* v2288[64] */,
  hls::stream< float > &v2289 /* v2289[64] */,
  hls::stream< float > &v2290 /* v2290[64] */,
  hls::stream< float > &v2291 /* v2291[64] */,
  float v2292[8][8],
  int v2293,
  int v2294
) {	// L3025
  #pragma HLS stream variable=v2288 depth=9
  #pragma HLS stream variable=v2289 depth=9
  #pragma HLS stream variable=v2290 depth=9
  #pragma HLS stream variable=v2291 depth=9
  #pragma HLS array_partition variable=v2292 complete dim=1
  #pragma HLS array_partition variable=v2292 complete dim=2

  float v91;	// L3028
  v91 = 0.000000;	// L3029
  l_S_k_0_k93: for (int k93 = 0; k93 < 64; k93++) {	// L3030
    float v2297 = v2288.read(); // v2288[k93];	// L3031
    float a91;	// L3032
    a91 = v2297;	// L3033
    float v2299 = v2289.read(); // v2289[k93];	// L3034
    float b91;	// L3035
    b91 = v2299;	// L3036
    float v2301 = a91;	// L3037
    float v2302 = b91;	// L3038
    float v2303 = v2301 * v2302;	// L3039
    float v2304 = v91;	// L3040
    float v2305 = v2304 + v2303;	// L3041
    v91 = v2305;	// L3042
    float v2306 = a91;	// L3043
    v2290.write(v2306); // v2290[k93] = v2306;	// L3044
    float v2307 = b91;	// L3045
    v2291.write(v2307); // v2291[k93] = v2307;	// L3046
  }
  float v2308 = v91;	// L3048
  v2292[v2293][v2294] = v2308;	// L3049
}

void PE_kernel_YV_4_3(
  hls::stream< float > &v2309 /* v2309[64] */,
  hls::stream< float > &v2310 /* v2310[64] */,
  hls::stream< float > &v2311 /* v2311[64] */,
  hls::stream< float > &v2312 /* v2312[64] */,
  float v2313[8][8],
  int v2314,
  int v2315
) {	// L3052
  #pragma HLS stream variable=v2309 depth=9
  #pragma HLS stream variable=v2310 depth=9
  #pragma HLS stream variable=v2311 depth=9
  #pragma HLS stream variable=v2312 depth=9
  #pragma HLS array_partition variable=v2313 complete dim=1
  #pragma HLS array_partition variable=v2313 complete dim=2

  float v92;	// L3055
  v92 = 0.000000;	// L3056
  l_S_k_0_k94: for (int k94 = 0; k94 < 64; k94++) {	// L3057
    float v2318 = v2309.read(); // v2309[k94];	// L3058
    float a92;	// L3059
    a92 = v2318;	// L3060
    float v2320 = v2310.read(); // v2310[k94];	// L3061
    float b92;	// L3062
    b92 = v2320;	// L3063
    float v2322 = a92;	// L3064
    float v2323 = b92;	// L3065
    float v2324 = v2322 * v2323;	// L3066
    float v2325 = v92;	// L3067
    float v2326 = v2325 + v2324;	// L3068
    v92 = v2326;	// L3069
    float v2327 = a92;	// L3070
    v2311.write(v2327); // v2311[k94] = v2327;	// L3071
    float v2328 = b92;	// L3072
    v2312.write(v2328); // v2312[k94] = v2328;	// L3073
  }
  float v2329 = v92;	// L3075
  v2313[v2314][v2315] = v2329;	// L3076
}

void PE_kernel_YV_5_3(
  hls::stream< float > &v2330 /* v2330[64] */,
  hls::stream< float > &v2331 /* v2331[64] */,
  hls::stream< float > &v2332 /* v2332[64] */,
  hls::stream< float > &v2333 /* v2333[64] */,
  float v2334[8][8],
  int v2335,
  int v2336
) {	// L3079
  #pragma HLS stream variable=v2330 depth=9
  #pragma HLS stream variable=v2331 depth=9
  #pragma HLS stream variable=v2332 depth=9
  #pragma HLS stream variable=v2333 depth=9
  #pragma HLS array_partition variable=v2334 complete dim=1
  #pragma HLS array_partition variable=v2334 complete dim=2

  float v93;	// L3082
  v93 = 0.000000;	// L3083
  l_S_k_0_k95: for (int k95 = 0; k95 < 64; k95++) {	// L3084
    float v2339 = v2330.read(); // v2330[k95];	// L3085
    float a93;	// L3086
    a93 = v2339;	// L3087
    float v2341 = v2331.read(); // v2331[k95];	// L3088
    float b93;	// L3089
    b93 = v2341;	// L3090
    float v2343 = a93;	// L3091
    float v2344 = b93;	// L3092
    float v2345 = v2343 * v2344;	// L3093
    float v2346 = v93;	// L3094
    float v2347 = v2346 + v2345;	// L3095
    v93 = v2347;	// L3096
    float v2348 = a93;	// L3097
    v2332.write(v2348); // v2332[k95] = v2348;	// L3098
    float v2349 = b93;	// L3099
    v2333.write(v2349); // v2333[k95] = v2349;	// L3100
  }
  float v2350 = v93;	// L3102
  v2334[v2335][v2336] = v2350;	// L3103
}

void PE_kernel_YV_6_3(
  hls::stream< float > &v2351 /* v2351[64] */,
  hls::stream< float > &v2352 /* v2352[64] */,
  hls::stream< float > &v2353 /* v2353[64] */,
  hls::stream< float > &v2354 /* v2354[64] */,
  float v2355[8][8],
  int v2356,
  int v2357
) {	// L3106
  #pragma HLS stream variable=v2351 depth=9
  #pragma HLS stream variable=v2352 depth=9
  #pragma HLS stream variable=v2353 depth=9
  #pragma HLS stream variable=v2354 depth=9
  #pragma HLS array_partition variable=v2355 complete dim=1
  #pragma HLS array_partition variable=v2355 complete dim=2

  float v94;	// L3109
  v94 = 0.000000;	// L3110
  l_S_k_0_k96: for (int k96 = 0; k96 < 64; k96++) {	// L3111
    float v2360 = v2351.read(); // v2351[k96];	// L3112
    float a94;	// L3113
    a94 = v2360;	// L3114
    float v2362 = v2352.read(); // v2352[k96];	// L3115
    float b94;	// L3116
    b94 = v2362;	// L3117
    float v2364 = a94;	// L3118
    float v2365 = b94;	// L3119
    float v2366 = v2364 * v2365;	// L3120
    float v2367 = v94;	// L3121
    float v2368 = v2367 + v2366;	// L3122
    v94 = v2368;	// L3123
    float v2369 = a94;	// L3124
    v2353.write(v2369); // v2353[k96] = v2369;	// L3125
    float v2370 = b94;	// L3126
    v2354.write(v2370); // v2354[k96] = v2370;	// L3127
  }
  float v2371 = v94;	// L3129
  v2355[v2356][v2357] = v2371;	// L3130
}

void PE_kernel_YV_7_3(
  hls::stream< float > &v2372 /* v2372[64] */,
  hls::stream< float > &v2373 /* v2373[64] */,
  hls::stream< float > &v2374 /* v2374[64] */,
  hls::stream< float > &v2375 /* v2375[64] */,
  float v2376[8][8],
  int v2377,
  int v2378
) {	// L3133
  #pragma HLS stream variable=v2372 depth=9
  #pragma HLS stream variable=v2373 depth=9
  #pragma HLS stream variable=v2374 depth=9
  #pragma HLS stream variable=v2375 depth=9
  #pragma HLS array_partition variable=v2376 complete dim=1
  #pragma HLS array_partition variable=v2376 complete dim=2

  float v95;	// L3136
  v95 = 0.000000;	// L3137
  l_S_k_0_k97: for (int k97 = 0; k97 < 64; k97++) {	// L3138
    float v2381 = v2372.read(); // v2372[k97];	// L3139
    float a95;	// L3140
    a95 = v2381;	// L3141
    float v2383 = v2373.read(); // v2373[k97];	// L3142
    float b95;	// L3143
    b95 = v2383;	// L3144
    float v2385 = a95;	// L3145
    float v2386 = b95;	// L3146
    float v2387 = v2385 * v2386;	// L3147
    float v2388 = v95;	// L3148
    float v2389 = v2388 + v2387;	// L3149
    v95 = v2389;	// L3150
    float v2390 = a95;	// L3151
    v2374.write(v2390); // v2374[k97] = v2390;	// L3152
    float v2391 = b95;	// L3153
    v2375.write(v2391); // v2375[k97] = v2391;	// L3154
  }
  float v2392 = v95;	// L3156
  v2376[v2377][v2378] = v2392;	// L3157
}

void PE_kernel_YV_0_4(
  hls::stream< float > &v2393 /* v2393[64] */,
  hls::stream< float > &v2394 /* v2394[64] */,
  hls::stream< float > &v2395 /* v2395[64] */,
  hls::stream< float > &v2396 /* v2396[64] */,
  float v2397[8][8],
  int v2398,
  int v2399
) {	// L3160
  #pragma HLS stream variable=v2393 depth=9
  #pragma HLS stream variable=v2394 depth=9
  #pragma HLS stream variable=v2395 depth=9
  #pragma HLS stream variable=v2396 depth=9
  #pragma HLS array_partition variable=v2397 complete dim=1
  #pragma HLS array_partition variable=v2397 complete dim=2

  float v96;	// L3163
  v96 = 0.000000;	// L3164
  l_S_k_0_k98: for (int k98 = 0; k98 < 64; k98++) {	// L3165
    float v2402 = v2393.read(); // v2393[k98];	// L3166
    float a96;	// L3167
    a96 = v2402;	// L3168
    float v2404 = v2394.read(); // v2394[k98];	// L3169
    float b96;	// L3170
    b96 = v2404;	// L3171
    float v2406 = a96;	// L3172
    float v2407 = b96;	// L3173
    float v2408 = v2406 * v2407;	// L3174
    float v2409 = v96;	// L3175
    float v2410 = v2409 + v2408;	// L3176
    v96 = v2410;	// L3177
    float v2411 = a96;	// L3178
    v2395.write(v2411); // v2395[k98] = v2411;	// L3179
    float v2412 = b96;	// L3180
    v2396.write(v2412); // v2396[k98] = v2412;	// L3181
  }
  float v2413 = v96;	// L3183
  v2397[v2398][v2399] = v2413;	// L3184
}

void PE_kernel_YV_1_4(
  hls::stream< float > &v2414 /* v2414[64] */,
  hls::stream< float > &v2415 /* v2415[64] */,
  hls::stream< float > &v2416 /* v2416[64] */,
  hls::stream< float > &v2417 /* v2417[64] */,
  float v2418[8][8],
  int v2419,
  int v2420
) {	// L3187
  #pragma HLS stream variable=v2414 depth=9
  #pragma HLS stream variable=v2415 depth=9
  #pragma HLS stream variable=v2416 depth=9
  #pragma HLS stream variable=v2417 depth=9
  #pragma HLS array_partition variable=v2418 complete dim=1
  #pragma HLS array_partition variable=v2418 complete dim=2

  float v97;	// L3190
  v97 = 0.000000;	// L3191
  l_S_k_0_k99: for (int k99 = 0; k99 < 64; k99++) {	// L3192
    float v2423 = v2414.read(); // v2414[k99];	// L3193
    float a97;	// L3194
    a97 = v2423;	// L3195
    float v2425 = v2415.read(); // v2415[k99];	// L3196
    float b97;	// L3197
    b97 = v2425;	// L3198
    float v2427 = a97;	// L3199
    float v2428 = b97;	// L3200
    float v2429 = v2427 * v2428;	// L3201
    float v2430 = v97;	// L3202
    float v2431 = v2430 + v2429;	// L3203
    v97 = v2431;	// L3204
    float v2432 = a97;	// L3205
    v2416.write(v2432); // v2416[k99] = v2432;	// L3206
    float v2433 = b97;	// L3207
    v2417.write(v2433); // v2417[k99] = v2433;	// L3208
  }
  float v2434 = v97;	// L3210
  v2418[v2419][v2420] = v2434;	// L3211
}

void PE_kernel_YV_2_4(
  hls::stream< float > &v2435 /* v2435[64] */,
  hls::stream< float > &v2436 /* v2436[64] */,
  hls::stream< float > &v2437 /* v2437[64] */,
  hls::stream< float > &v2438 /* v2438[64] */,
  float v2439[8][8],
  int v2440,
  int v2441
) {	// L3214
  #pragma HLS stream variable=v2435 depth=9
  #pragma HLS stream variable=v2436 depth=9
  #pragma HLS stream variable=v2437 depth=9
  #pragma HLS stream variable=v2438 depth=9
  #pragma HLS array_partition variable=v2439 complete dim=1
  #pragma HLS array_partition variable=v2439 complete dim=2

  float v98;	// L3217
  v98 = 0.000000;	// L3218
  l_S_k_0_k100: for (int k100 = 0; k100 < 64; k100++) {	// L3219
    float v2444 = v2435.read(); // v2435[k100];	// L3220
    float a98;	// L3221
    a98 = v2444;	// L3222
    float v2446 = v2436.read(); // v2436[k100];	// L3223
    float b98;	// L3224
    b98 = v2446;	// L3225
    float v2448 = a98;	// L3226
    float v2449 = b98;	// L3227
    float v2450 = v2448 * v2449;	// L3228
    float v2451 = v98;	// L3229
    float v2452 = v2451 + v2450;	// L3230
    v98 = v2452;	// L3231
    float v2453 = a98;	// L3232
    v2437.write(v2453); // v2437[k100] = v2453;	// L3233
    float v2454 = b98;	// L3234
    v2438.write(v2454); // v2438[k100] = v2454;	// L3235
  }
  float v2455 = v98;	// L3237
  v2439[v2440][v2441] = v2455;	// L3238
}

void PE_kernel_YV_3_4(
  hls::stream< float > &v2456 /* v2456[64] */,
  hls::stream< float > &v2457 /* v2457[64] */,
  hls::stream< float > &v2458 /* v2458[64] */,
  hls::stream< float > &v2459 /* v2459[64] */,
  float v2460[8][8],
  int v2461,
  int v2462
) {	// L3241
  #pragma HLS stream variable=v2456 depth=9
  #pragma HLS stream variable=v2457 depth=9
  #pragma HLS stream variable=v2458 depth=9
  #pragma HLS stream variable=v2459 depth=9
  #pragma HLS array_partition variable=v2460 complete dim=1
  #pragma HLS array_partition variable=v2460 complete dim=2

  float v99;	// L3244
  v99 = 0.000000;	// L3245
  l_S_k_0_k101: for (int k101 = 0; k101 < 64; k101++) {	// L3246
    float v2465 = v2456.read(); // v2456[k101];	// L3247
    float a99;	// L3248
    a99 = v2465;	// L3249
    float v2467 = v2457.read(); // v2457[k101];	// L3250
    float b99;	// L3251
    b99 = v2467;	// L3252
    float v2469 = a99;	// L3253
    float v2470 = b99;	// L3254
    float v2471 = v2469 * v2470;	// L3255
    float v2472 = v99;	// L3256
    float v2473 = v2472 + v2471;	// L3257
    v99 = v2473;	// L3258
    float v2474 = a99;	// L3259
    v2458.write(v2474); // v2458[k101] = v2474;	// L3260
    float v2475 = b99;	// L3261
    v2459.write(v2475); // v2459[k101] = v2475;	// L3262
  }
  float v2476 = v99;	// L3264
  v2460[v2461][v2462] = v2476;	// L3265
}

void PE_kernel_YV_4_4(
  hls::stream< float > &v2477 /* v2477[64] */,
  hls::stream< float > &v2478 /* v2478[64] */,
  hls::stream< float > &v2479 /* v2479[64] */,
  hls::stream< float > &v2480 /* v2480[64] */,
  float v2481[8][8],
  int v2482,
  int v2483
) {	// L3268
  #pragma HLS stream variable=v2477 depth=9
  #pragma HLS stream variable=v2478 depth=9
  #pragma HLS stream variable=v2479 depth=9
  #pragma HLS stream variable=v2480 depth=9
  #pragma HLS array_partition variable=v2481 complete dim=1
  #pragma HLS array_partition variable=v2481 complete dim=2

  float v100;	// L3271
  v100 = 0.000000;	// L3272
  l_S_k_0_k102: for (int k102 = 0; k102 < 64; k102++) {	// L3273
    float v2486 = v2477.read(); // v2477[k102];	// L3274
    float a100;	// L3275
    a100 = v2486;	// L3276
    float v2488 = v2478.read(); // v2478[k102];	// L3277
    float b100;	// L3278
    b100 = v2488;	// L3279
    float v2490 = a100;	// L3280
    float v2491 = b100;	// L3281
    float v2492 = v2490 * v2491;	// L3282
    float v2493 = v100;	// L3283
    float v2494 = v2493 + v2492;	// L3284
    v100 = v2494;	// L3285
    float v2495 = a100;	// L3286
    v2479.write(v2495); // v2479[k102] = v2495;	// L3287
    float v2496 = b100;	// L3288
    v2480.write(v2496); // v2480[k102] = v2496;	// L3289
  }
  float v2497 = v100;	// L3291
  v2481[v2482][v2483] = v2497;	// L3292
}

void PE_kernel_YV_5_4(
  hls::stream< float > &v2498 /* v2498[64] */,
  hls::stream< float > &v2499 /* v2499[64] */,
  hls::stream< float > &v2500 /* v2500[64] */,
  hls::stream< float > &v2501 /* v2501[64] */,
  float v2502[8][8],
  int v2503,
  int v2504
) {	// L3295
  #pragma HLS stream variable=v2498 depth=9
  #pragma HLS stream variable=v2499 depth=9
  #pragma HLS stream variable=v2500 depth=9
  #pragma HLS stream variable=v2501 depth=9
  #pragma HLS array_partition variable=v2502 complete dim=1
  #pragma HLS array_partition variable=v2502 complete dim=2

  float v101;	// L3298
  v101 = 0.000000;	// L3299
  l_S_k_0_k103: for (int k103 = 0; k103 < 64; k103++) {	// L3300
    float v2507 = v2498.read(); // v2498[k103];	// L3301
    float a101;	// L3302
    a101 = v2507;	// L3303
    float v2509 = v2499.read(); // v2499[k103];	// L3304
    float b101;	// L3305
    b101 = v2509;	// L3306
    float v2511 = a101;	// L3307
    float v2512 = b101;	// L3308
    float v2513 = v2511 * v2512;	// L3309
    float v2514 = v101;	// L3310
    float v2515 = v2514 + v2513;	// L3311
    v101 = v2515;	// L3312
    float v2516 = a101;	// L3313
    v2500.write(v2516); // v2500[k103] = v2516;	// L3314
    float v2517 = b101;	// L3315
    v2501.write(v2517); // v2501[k103] = v2517;	// L3316
  }
  float v2518 = v101;	// L3318
  v2502[v2503][v2504] = v2518;	// L3319
}

void PE_kernel_YV_6_4(
  hls::stream< float > &v2519 /* v2519[64] */,
  hls::stream< float > &v2520 /* v2520[64] */,
  hls::stream< float > &v2521 /* v2521[64] */,
  hls::stream< float > &v2522 /* v2522[64] */,
  float v2523[8][8],
  int v2524,
  int v2525
) {	// L3322
  #pragma HLS stream variable=v2519 depth=9
  #pragma HLS stream variable=v2520 depth=9
  #pragma HLS stream variable=v2521 depth=9
  #pragma HLS stream variable=v2522 depth=9
  #pragma HLS array_partition variable=v2523 complete dim=1
  #pragma HLS array_partition variable=v2523 complete dim=2

  float v102;	// L3325
  v102 = 0.000000;	// L3326
  l_S_k_0_k104: for (int k104 = 0; k104 < 64; k104++) {	// L3327
    float v2528 = v2519.read(); // v2519[k104];	// L3328
    float a102;	// L3329
    a102 = v2528;	// L3330
    float v2530 = v2520.read(); // v2520[k104];	// L3331
    float b102;	// L3332
    b102 = v2530;	// L3333
    float v2532 = a102;	// L3334
    float v2533 = b102;	// L3335
    float v2534 = v2532 * v2533;	// L3336
    float v2535 = v102;	// L3337
    float v2536 = v2535 + v2534;	// L3338
    v102 = v2536;	// L3339
    float v2537 = a102;	// L3340
    v2521.write(v2537); // v2521[k104] = v2537;	// L3341
    float v2538 = b102;	// L3342
    v2522.write(v2538); // v2522[k104] = v2538;	// L3343
  }
  float v2539 = v102;	// L3345
  v2523[v2524][v2525] = v2539;	// L3346
}

void PE_kernel_YV_7_4(
  hls::stream< float > &v2540 /* v2540[64] */,
  hls::stream< float > &v2541 /* v2541[64] */,
  hls::stream< float > &v2542 /* v2542[64] */,
  hls::stream< float > &v2543 /* v2543[64] */,
  float v2544[8][8],
  int v2545,
  int v2546
) {	// L3349
  #pragma HLS stream variable=v2540 depth=9
  #pragma HLS stream variable=v2541 depth=9
  #pragma HLS stream variable=v2542 depth=9
  #pragma HLS stream variable=v2543 depth=9
  #pragma HLS array_partition variable=v2544 complete dim=1
  #pragma HLS array_partition variable=v2544 complete dim=2

  float v103;	// L3352
  v103 = 0.000000;	// L3353
  l_S_k_0_k105: for (int k105 = 0; k105 < 64; k105++) {	// L3354
    float v2549 = v2540.read(); // v2540[k105];	// L3355
    float a103;	// L3356
    a103 = v2549;	// L3357
    float v2551 = v2541.read(); // v2541[k105];	// L3358
    float b103;	// L3359
    b103 = v2551;	// L3360
    float v2553 = a103;	// L3361
    float v2554 = b103;	// L3362
    float v2555 = v2553 * v2554;	// L3363
    float v2556 = v103;	// L3364
    float v2557 = v2556 + v2555;	// L3365
    v103 = v2557;	// L3366
    float v2558 = a103;	// L3367
    v2542.write(v2558); // v2542[k105] = v2558;	// L3368
    float v2559 = b103;	// L3369
    v2543.write(v2559); // v2543[k105] = v2559;	// L3370
  }
  float v2560 = v103;	// L3372
  v2544[v2545][v2546] = v2560;	// L3373
}

void PE_kernel_YV_0_5(
  hls::stream< float > &v2561 /* v2561[64] */,
  hls::stream< float > &v2562 /* v2562[64] */,
  hls::stream< float > &v2563 /* v2563[64] */,
  hls::stream< float > &v2564 /* v2564[64] */,
  float v2565[8][8],
  int v2566,
  int v2567
) {	// L3376
  #pragma HLS stream variable=v2561 depth=9
  #pragma HLS stream variable=v2562 depth=9
  #pragma HLS stream variable=v2563 depth=9
  #pragma HLS stream variable=v2564 depth=9
  #pragma HLS array_partition variable=v2565 complete dim=1
  #pragma HLS array_partition variable=v2565 complete dim=2

  float v104;	// L3379
  v104 = 0.000000;	// L3380
  l_S_k_0_k106: for (int k106 = 0; k106 < 64; k106++) {	// L3381
    float v2570 = v2561.read(); // v2561[k106];	// L3382
    float a104;	// L3383
    a104 = v2570;	// L3384
    float v2572 = v2562.read(); // v2562[k106];	// L3385
    float b104;	// L3386
    b104 = v2572;	// L3387
    float v2574 = a104;	// L3388
    float v2575 = b104;	// L3389
    float v2576 = v2574 * v2575;	// L3390
    float v2577 = v104;	// L3391
    float v2578 = v2577 + v2576;	// L3392
    v104 = v2578;	// L3393
    float v2579 = a104;	// L3394
    v2563.write(v2579); // v2563[k106] = v2579;	// L3395
    float v2580 = b104;	// L3396
    v2564.write(v2580); // v2564[k106] = v2580;	// L3397
  }
  float v2581 = v104;	// L3399
  v2565[v2566][v2567] = v2581;	// L3400
}

void PE_kernel_YV_1_5(
  hls::stream< float > &v2582 /* v2582[64] */,
  hls::stream< float > &v2583 /* v2583[64] */,
  hls::stream< float > &v2584 /* v2584[64] */,
  hls::stream< float > &v2585 /* v2585[64] */,
  float v2586[8][8],
  int v2587,
  int v2588
) {	// L3403
  #pragma HLS stream variable=v2582 depth=9
  #pragma HLS stream variable=v2583 depth=9
  #pragma HLS stream variable=v2584 depth=9
  #pragma HLS stream variable=v2585 depth=9
  #pragma HLS array_partition variable=v2586 complete dim=1
  #pragma HLS array_partition variable=v2586 complete dim=2

  float v105;	// L3406
  v105 = 0.000000;	// L3407
  l_S_k_0_k107: for (int k107 = 0; k107 < 64; k107++) {	// L3408
    float v2591 = v2582.read(); // v2582[k107];	// L3409
    float a105;	// L3410
    a105 = v2591;	// L3411
    float v2593 = v2583.read(); // v2583[k107];	// L3412
    float b105;	// L3413
    b105 = v2593;	// L3414
    float v2595 = a105;	// L3415
    float v2596 = b105;	// L3416
    float v2597 = v2595 * v2596;	// L3417
    float v2598 = v105;	// L3418
    float v2599 = v2598 + v2597;	// L3419
    v105 = v2599;	// L3420
    float v2600 = a105;	// L3421
    v2584.write(v2600); // v2584[k107] = v2600;	// L3422
    float v2601 = b105;	// L3423
    v2585.write(v2601); // v2585[k107] = v2601;	// L3424
  }
  float v2602 = v105;	// L3426
  v2586[v2587][v2588] = v2602;	// L3427
}

void PE_kernel_YV_2_5(
  hls::stream< float > &v2603 /* v2603[64] */,
  hls::stream< float > &v2604 /* v2604[64] */,
  hls::stream< float > &v2605 /* v2605[64] */,
  hls::stream< float > &v2606 /* v2606[64] */,
  float v2607[8][8],
  int v2608,
  int v2609
) {	// L3430
  #pragma HLS stream variable=v2603 depth=9
  #pragma HLS stream variable=v2604 depth=9
  #pragma HLS stream variable=v2605 depth=9
  #pragma HLS stream variable=v2606 depth=9
  #pragma HLS array_partition variable=v2607 complete dim=1
  #pragma HLS array_partition variable=v2607 complete dim=2

  float v106;	// L3433
  v106 = 0.000000;	// L3434
  l_S_k_0_k108: for (int k108 = 0; k108 < 64; k108++) {	// L3435
    float v2612 = v2603.read(); // v2603[k108];	// L3436
    float a106;	// L3437
    a106 = v2612;	// L3438
    float v2614 = v2604.read(); // v2604[k108];	// L3439
    float b106;	// L3440
    b106 = v2614;	// L3441
    float v2616 = a106;	// L3442
    float v2617 = b106;	// L3443
    float v2618 = v2616 * v2617;	// L3444
    float v2619 = v106;	// L3445
    float v2620 = v2619 + v2618;	// L3446
    v106 = v2620;	// L3447
    float v2621 = a106;	// L3448
    v2605.write(v2621); // v2605[k108] = v2621;	// L3449
    float v2622 = b106;	// L3450
    v2606.write(v2622); // v2606[k108] = v2622;	// L3451
  }
  float v2623 = v106;	// L3453
  v2607[v2608][v2609] = v2623;	// L3454
}

void PE_kernel_YV_3_5(
  hls::stream< float > &v2624 /* v2624[64] */,
  hls::stream< float > &v2625 /* v2625[64] */,
  hls::stream< float > &v2626 /* v2626[64] */,
  hls::stream< float > &v2627 /* v2627[64] */,
  float v2628[8][8],
  int v2629,
  int v2630
) {	// L3457
  #pragma HLS stream variable=v2624 depth=9
  #pragma HLS stream variable=v2625 depth=9
  #pragma HLS stream variable=v2626 depth=9
  #pragma HLS stream variable=v2627 depth=9
  #pragma HLS array_partition variable=v2628 complete dim=1
  #pragma HLS array_partition variable=v2628 complete dim=2

  float v107;	// L3460
  v107 = 0.000000;	// L3461
  l_S_k_0_k109: for (int k109 = 0; k109 < 64; k109++) {	// L3462
    float v2633 = v2624.read(); // v2624[k109];	// L3463
    float a107;	// L3464
    a107 = v2633;	// L3465
    float v2635 = v2625.read(); // v2625[k109];	// L3466
    float b107;	// L3467
    b107 = v2635;	// L3468
    float v2637 = a107;	// L3469
    float v2638 = b107;	// L3470
    float v2639 = v2637 * v2638;	// L3471
    float v2640 = v107;	// L3472
    float v2641 = v2640 + v2639;	// L3473
    v107 = v2641;	// L3474
    float v2642 = a107;	// L3475
    v2626.write(v2642); // v2626[k109] = v2642;	// L3476
    float v2643 = b107;	// L3477
    v2627.write(v2643); // v2627[k109] = v2643;	// L3478
  }
  float v2644 = v107;	// L3480
  v2628[v2629][v2630] = v2644;	// L3481
}

void PE_kernel_YV_4_5(
  hls::stream< float > &v2645 /* v2645[64] */,
  hls::stream< float > &v2646 /* v2646[64] */,
  hls::stream< float > &v2647 /* v2647[64] */,
  hls::stream< float > &v2648 /* v2648[64] */,
  float v2649[8][8],
  int v2650,
  int v2651
) {	// L3484
  #pragma HLS stream variable=v2645 depth=9
  #pragma HLS stream variable=v2646 depth=9
  #pragma HLS stream variable=v2647 depth=9
  #pragma HLS stream variable=v2648 depth=9
  #pragma HLS array_partition variable=v2649 complete dim=1
  #pragma HLS array_partition variable=v2649 complete dim=2

  float v108;	// L3487
  v108 = 0.000000;	// L3488
  l_S_k_0_k110: for (int k110 = 0; k110 < 64; k110++) {	// L3489
    float v2654 = v2645.read(); // v2645[k110];	// L3490
    float a108;	// L3491
    a108 = v2654;	// L3492
    float v2656 = v2646.read(); // v2646[k110];	// L3493
    float b108;	// L3494
    b108 = v2656;	// L3495
    float v2658 = a108;	// L3496
    float v2659 = b108;	// L3497
    float v2660 = v2658 * v2659;	// L3498
    float v2661 = v108;	// L3499
    float v2662 = v2661 + v2660;	// L3500
    v108 = v2662;	// L3501
    float v2663 = a108;	// L3502
    v2647.write(v2663); // v2647[k110] = v2663;	// L3503
    float v2664 = b108;	// L3504
    v2648.write(v2664); // v2648[k110] = v2664;	// L3505
  }
  float v2665 = v108;	// L3507
  v2649[v2650][v2651] = v2665;	// L3508
}

void PE_kernel_YV_5_5(
  hls::stream< float > &v2666 /* v2666[64] */,
  hls::stream< float > &v2667 /* v2667[64] */,
  hls::stream< float > &v2668 /* v2668[64] */,
  hls::stream< float > &v2669 /* v2669[64] */,
  float v2670[8][8],
  int v2671,
  int v2672
) {	// L3511
  #pragma HLS stream variable=v2666 depth=9
  #pragma HLS stream variable=v2667 depth=9
  #pragma HLS stream variable=v2668 depth=9
  #pragma HLS stream variable=v2669 depth=9
  #pragma HLS array_partition variable=v2670 complete dim=1
  #pragma HLS array_partition variable=v2670 complete dim=2

  float v109;	// L3514
  v109 = 0.000000;	// L3515
  l_S_k_0_k111: for (int k111 = 0; k111 < 64; k111++) {	// L3516
    float v2675 = v2666.read(); // v2666[k111];	// L3517
    float a109;	// L3518
    a109 = v2675;	// L3519
    float v2677 = v2667.read(); // v2667[k111];	// L3520
    float b109;	// L3521
    b109 = v2677;	// L3522
    float v2679 = a109;	// L3523
    float v2680 = b109;	// L3524
    float v2681 = v2679 * v2680;	// L3525
    float v2682 = v109;	// L3526
    float v2683 = v2682 + v2681;	// L3527
    v109 = v2683;	// L3528
    float v2684 = a109;	// L3529
    v2668.write(v2684); // v2668[k111] = v2684;	// L3530
    float v2685 = b109;	// L3531
    v2669.write(v2685); // v2669[k111] = v2685;	// L3532
  }
  float v2686 = v109;	// L3534
  v2670[v2671][v2672] = v2686;	// L3535
}

void PE_kernel_YV_6_5(
  hls::stream< float > &v2687 /* v2687[64] */,
  hls::stream< float > &v2688 /* v2688[64] */,
  hls::stream< float > &v2689 /* v2689[64] */,
  hls::stream< float > &v2690 /* v2690[64] */,
  float v2691[8][8],
  int v2692,
  int v2693
) {	// L3538
  #pragma HLS stream variable=v2687 depth=9
  #pragma HLS stream variable=v2688 depth=9
  #pragma HLS stream variable=v2689 depth=9
  #pragma HLS stream variable=v2690 depth=9
  #pragma HLS array_partition variable=v2691 complete dim=1
  #pragma HLS array_partition variable=v2691 complete dim=2

  float v110;	// L3541
  v110 = 0.000000;	// L3542
  l_S_k_0_k112: for (int k112 = 0; k112 < 64; k112++) {	// L3543
    float v2696 = v2687.read(); // v2687[k112];	// L3544
    float a110;	// L3545
    a110 = v2696;	// L3546
    float v2698 = v2688.read(); // v2688[k112];	// L3547
    float b110;	// L3548
    b110 = v2698;	// L3549
    float v2700 = a110;	// L3550
    float v2701 = b110;	// L3551
    float v2702 = v2700 * v2701;	// L3552
    float v2703 = v110;	// L3553
    float v2704 = v2703 + v2702;	// L3554
    v110 = v2704;	// L3555
    float v2705 = a110;	// L3556
    v2689.write(v2705); // v2689[k112] = v2705;	// L3557
    float v2706 = b110;	// L3558
    v2690.write(v2706); // v2690[k112] = v2706;	// L3559
  }
  float v2707 = v110;	// L3561
  v2691[v2692][v2693] = v2707;	// L3562
}

void PE_kernel_YV_7_5(
  hls::stream< float > &v2708 /* v2708[64] */,
  hls::stream< float > &v2709 /* v2709[64] */,
  hls::stream< float > &v2710 /* v2710[64] */,
  hls::stream< float > &v2711 /* v2711[64] */,
  float v2712[8][8],
  int v2713,
  int v2714
) {	// L3565
  #pragma HLS stream variable=v2708 depth=9
  #pragma HLS stream variable=v2709 depth=9
  #pragma HLS stream variable=v2710 depth=9
  #pragma HLS stream variable=v2711 depth=9
  #pragma HLS array_partition variable=v2712 complete dim=1
  #pragma HLS array_partition variable=v2712 complete dim=2

  float v111;	// L3568
  v111 = 0.000000;	// L3569
  l_S_k_0_k113: for (int k113 = 0; k113 < 64; k113++) {	// L3570
    float v2717 = v2708.read(); // v2708[k113];	// L3571
    float a111;	// L3572
    a111 = v2717;	// L3573
    float v2719 = v2709.read(); // v2709[k113];	// L3574
    float b111;	// L3575
    b111 = v2719;	// L3576
    float v2721 = a111;	// L3577
    float v2722 = b111;	// L3578
    float v2723 = v2721 * v2722;	// L3579
    float v2724 = v111;	// L3580
    float v2725 = v2724 + v2723;	// L3581
    v111 = v2725;	// L3582
    float v2726 = a111;	// L3583
    v2710.write(v2726); // v2710[k113] = v2726;	// L3584
    float v2727 = b111;	// L3585
    v2711.write(v2727); // v2711[k113] = v2727;	// L3586
  }
  float v2728 = v111;	// L3588
  v2712[v2713][v2714] = v2728;	// L3589
}

void PE_kernel_YV_0_6(
  hls::stream< float > &v2729 /* v2729[64] */,
  hls::stream< float > &v2730 /* v2730[64] */,
  hls::stream< float > &v2731 /* v2731[64] */,
  hls::stream< float > &v2732 /* v2732[64] */,
  float v2733[8][8],
  int v2734,
  int v2735
) {	// L3592
  #pragma HLS stream variable=v2729 depth=9
  #pragma HLS stream variable=v2730 depth=9
  #pragma HLS stream variable=v2731 depth=9
  #pragma HLS stream variable=v2732 depth=9
  #pragma HLS array_partition variable=v2733 complete dim=1
  #pragma HLS array_partition variable=v2733 complete dim=2

  float v112;	// L3595
  v112 = 0.000000;	// L3596
  l_S_k_0_k114: for (int k114 = 0; k114 < 64; k114++) {	// L3597
    float v2738 = v2729.read(); // v2729[k114];	// L3598
    float a112;	// L3599
    a112 = v2738;	// L3600
    float v2740 = v2730.read(); // v2730[k114];	// L3601
    float b112;	// L3602
    b112 = v2740;	// L3603
    float v2742 = a112;	// L3604
    float v2743 = b112;	// L3605
    float v2744 = v2742 * v2743;	// L3606
    float v2745 = v112;	// L3607
    float v2746 = v2745 + v2744;	// L3608
    v112 = v2746;	// L3609
    float v2747 = a112;	// L3610
    v2731.write(v2747); // v2731[k114] = v2747;	// L3611
    float v2748 = b112;	// L3612
    v2732.write(v2748); // v2732[k114] = v2748;	// L3613
  }
  float v2749 = v112;	// L3615
  v2733[v2734][v2735] = v2749;	// L3616
}

void PE_kernel_YV_1_6(
  hls::stream< float > &v2750 /* v2750[64] */,
  hls::stream< float > &v2751 /* v2751[64] */,
  hls::stream< float > &v2752 /* v2752[64] */,
  hls::stream< float > &v2753 /* v2753[64] */,
  float v2754[8][8],
  int v2755,
  int v2756
) {	// L3619
  #pragma HLS stream variable=v2750 depth=9
  #pragma HLS stream variable=v2751 depth=9
  #pragma HLS stream variable=v2752 depth=9
  #pragma HLS stream variable=v2753 depth=9
  #pragma HLS array_partition variable=v2754 complete dim=1
  #pragma HLS array_partition variable=v2754 complete dim=2

  float v113;	// L3622
  v113 = 0.000000;	// L3623
  l_S_k_0_k115: for (int k115 = 0; k115 < 64; k115++) {	// L3624
    float v2759 = v2750.read(); // v2750[k115];	// L3625
    float a113;	// L3626
    a113 = v2759;	// L3627
    float v2761 = v2751.read(); // v2751[k115];	// L3628
    float b113;	// L3629
    b113 = v2761;	// L3630
    float v2763 = a113;	// L3631
    float v2764 = b113;	// L3632
    float v2765 = v2763 * v2764;	// L3633
    float v2766 = v113;	// L3634
    float v2767 = v2766 + v2765;	// L3635
    v113 = v2767;	// L3636
    float v2768 = a113;	// L3637
    v2752.write(v2768); // v2752[k115] = v2768;	// L3638
    float v2769 = b113;	// L3639
    v2753.write(v2769); // v2753[k115] = v2769;	// L3640
  }
  float v2770 = v113;	// L3642
  v2754[v2755][v2756] = v2770;	// L3643
}

void PE_kernel_YV_2_6(
  hls::stream< float > &v2771 /* v2771[64] */,
  hls::stream< float > &v2772 /* v2772[64] */,
  hls::stream< float > &v2773 /* v2773[64] */,
  hls::stream< float > &v2774 /* v2774[64] */,
  float v2775[8][8],
  int v2776,
  int v2777
) {	// L3646
  #pragma HLS stream variable=v2771 depth=9
  #pragma HLS stream variable=v2772 depth=9
  #pragma HLS stream variable=v2773 depth=9
  #pragma HLS stream variable=v2774 depth=9
  #pragma HLS array_partition variable=v2775 complete dim=1
  #pragma HLS array_partition variable=v2775 complete dim=2

  float v114;	// L3649
  v114 = 0.000000;	// L3650
  l_S_k_0_k116: for (int k116 = 0; k116 < 64; k116++) {	// L3651
    float v2780 = v2771.read(); // v2771[k116];	// L3652
    float a114;	// L3653
    a114 = v2780;	// L3654
    float v2782 = v2772.read(); // v2772[k116];	// L3655
    float b114;	// L3656
    b114 = v2782;	// L3657
    float v2784 = a114;	// L3658
    float v2785 = b114;	// L3659
    float v2786 = v2784 * v2785;	// L3660
    float v2787 = v114;	// L3661
    float v2788 = v2787 + v2786;	// L3662
    v114 = v2788;	// L3663
    float v2789 = a114;	// L3664
    v2773.write(v2789); // v2773[k116] = v2789;	// L3665
    float v2790 = b114;	// L3666
    v2774.write(v2790); // v2774[k116] = v2790;	// L3667
  }
  float v2791 = v114;	// L3669
  v2775[v2776][v2777] = v2791;	// L3670
}

void PE_kernel_YV_3_6(
  hls::stream< float > &v2792 /* v2792[64] */,
  hls::stream< float > &v2793 /* v2793[64] */,
  hls::stream< float > &v2794 /* v2794[64] */,
  hls::stream< float > &v2795 /* v2795[64] */,
  float v2796[8][8],
  int v2797,
  int v2798
) {	// L3673
  #pragma HLS stream variable=v2792 depth=9
  #pragma HLS stream variable=v2793 depth=9
  #pragma HLS stream variable=v2794 depth=9
  #pragma HLS stream variable=v2795 depth=9
  #pragma HLS array_partition variable=v2796 complete dim=1
  #pragma HLS array_partition variable=v2796 complete dim=2

  float v115;	// L3676
  v115 = 0.000000;	// L3677
  l_S_k_0_k117: for (int k117 = 0; k117 < 64; k117++) {	// L3678
    float v2801 = v2792.read(); // v2792[k117];	// L3679
    float a115;	// L3680
    a115 = v2801;	// L3681
    float v2803 = v2793.read(); // v2793[k117];	// L3682
    float b115;	// L3683
    b115 = v2803;	// L3684
    float v2805 = a115;	// L3685
    float v2806 = b115;	// L3686
    float v2807 = v2805 * v2806;	// L3687
    float v2808 = v115;	// L3688
    float v2809 = v2808 + v2807;	// L3689
    v115 = v2809;	// L3690
    float v2810 = a115;	// L3691
    v2794.write(v2810); // v2794[k117] = v2810;	// L3692
    float v2811 = b115;	// L3693
    v2795.write(v2811); // v2795[k117] = v2811;	// L3694
  }
  float v2812 = v115;	// L3696
  v2796[v2797][v2798] = v2812;	// L3697
}

void PE_kernel_YV_4_6(
  hls::stream< float > &v2813 /* v2813[64] */,
  hls::stream< float > &v2814 /* v2814[64] */,
  hls::stream< float > &v2815 /* v2815[64] */,
  hls::stream< float > &v2816 /* v2816[64] */,
  float v2817[8][8],
  int v2818,
  int v2819
) {	// L3700
  #pragma HLS stream variable=v2813 depth=9
  #pragma HLS stream variable=v2814 depth=9
  #pragma HLS stream variable=v2815 depth=9
  #pragma HLS stream variable=v2816 depth=9
  #pragma HLS array_partition variable=v2817 complete dim=1
  #pragma HLS array_partition variable=v2817 complete dim=2

  float v116;	// L3703
  v116 = 0.000000;	// L3704
  l_S_k_0_k118: for (int k118 = 0; k118 < 64; k118++) {	// L3705
    float v2822 = v2813.read(); // v2813[k118];	// L3706
    float a116;	// L3707
    a116 = v2822;	// L3708
    float v2824 = v2814.read(); // v2814[k118];	// L3709
    float b116;	// L3710
    b116 = v2824;	// L3711
    float v2826 = a116;	// L3712
    float v2827 = b116;	// L3713
    float v2828 = v2826 * v2827;	// L3714
    float v2829 = v116;	// L3715
    float v2830 = v2829 + v2828;	// L3716
    v116 = v2830;	// L3717
    float v2831 = a116;	// L3718
    v2815.write(v2831); // v2815[k118] = v2831;	// L3719
    float v2832 = b116;	// L3720
    v2816.write(v2832); // v2816[k118] = v2832;	// L3721
  }
  float v2833 = v116;	// L3723
  v2817[v2818][v2819] = v2833;	// L3724
}

void PE_kernel_YV_5_6(
  hls::stream< float > &v2834 /* v2834[64] */,
  hls::stream< float > &v2835 /* v2835[64] */,
  hls::stream< float > &v2836 /* v2836[64] */,
  hls::stream< float > &v2837 /* v2837[64] */,
  float v2838[8][8],
  int v2839,
  int v2840
) {	// L3727
  #pragma HLS stream variable=v2834 depth=9
  #pragma HLS stream variable=v2835 depth=9
  #pragma HLS stream variable=v2836 depth=9
  #pragma HLS stream variable=v2837 depth=9
  #pragma HLS array_partition variable=v2838 complete dim=1
  #pragma HLS array_partition variable=v2838 complete dim=2

  float v117;	// L3730
  v117 = 0.000000;	// L3731
  l_S_k_0_k119: for (int k119 = 0; k119 < 64; k119++) {	// L3732
    float v2843 = v2834.read(); // v2834[k119];	// L3733
    float a117;	// L3734
    a117 = v2843;	// L3735
    float v2845 = v2835.read(); // v2835[k119];	// L3736
    float b117;	// L3737
    b117 = v2845;	// L3738
    float v2847 = a117;	// L3739
    float v2848 = b117;	// L3740
    float v2849 = v2847 * v2848;	// L3741
    float v2850 = v117;	// L3742
    float v2851 = v2850 + v2849;	// L3743
    v117 = v2851;	// L3744
    float v2852 = a117;	// L3745
    v2836.write(v2852); // v2836[k119] = v2852;	// L3746
    float v2853 = b117;	// L3747
    v2837.write(v2853); // v2837[k119] = v2853;	// L3748
  }
  float v2854 = v117;	// L3750
  v2838[v2839][v2840] = v2854;	// L3751
}

void PE_kernel_YV_6_6(
  hls::stream< float > &v2855 /* v2855[64] */,
  hls::stream< float > &v2856 /* v2856[64] */,
  hls::stream< float > &v2857 /* v2857[64] */,
  hls::stream< float > &v2858 /* v2858[64] */,
  float v2859[8][8],
  int v2860,
  int v2861
) {	// L3754
  #pragma HLS stream variable=v2855 depth=9
  #pragma HLS stream variable=v2856 depth=9
  #pragma HLS stream variable=v2857 depth=9
  #pragma HLS stream variable=v2858 depth=9
  #pragma HLS array_partition variable=v2859 complete dim=1
  #pragma HLS array_partition variable=v2859 complete dim=2

  float v118;	// L3757
  v118 = 0.000000;	// L3758
  l_S_k_0_k120: for (int k120 = 0; k120 < 64; k120++) {	// L3759
    float v2864 = v2855.read(); // v2855[k120];	// L3760
    float a118;	// L3761
    a118 = v2864;	// L3762
    float v2866 = v2856.read(); // v2856[k120];	// L3763
    float b118;	// L3764
    b118 = v2866;	// L3765
    float v2868 = a118;	// L3766
    float v2869 = b118;	// L3767
    float v2870 = v2868 * v2869;	// L3768
    float v2871 = v118;	// L3769
    float v2872 = v2871 + v2870;	// L3770
    v118 = v2872;	// L3771
    float v2873 = a118;	// L3772
    v2857.write(v2873); // v2857[k120] = v2873;	// L3773
    float v2874 = b118;	// L3774
    v2858.write(v2874); // v2858[k120] = v2874;	// L3775
  }
  float v2875 = v118;	// L3777
  v2859[v2860][v2861] = v2875;	// L3778
}

void PE_kernel_YV_7_6(
  hls::stream< float > &v2876 /* v2876[64] */,
  hls::stream< float > &v2877 /* v2877[64] */,
  hls::stream< float > &v2878 /* v2878[64] */,
  hls::stream< float > &v2879 /* v2879[64] */,
  float v2880[8][8],
  int v2881,
  int v2882
) {	// L3781
  #pragma HLS stream variable=v2876 depth=9
  #pragma HLS stream variable=v2877 depth=9
  #pragma HLS stream variable=v2878 depth=9
  #pragma HLS stream variable=v2879 depth=9
  #pragma HLS array_partition variable=v2880 complete dim=1
  #pragma HLS array_partition variable=v2880 complete dim=2

  float v119;	// L3784
  v119 = 0.000000;	// L3785
  l_S_k_0_k121: for (int k121 = 0; k121 < 64; k121++) {	// L3786
    float v2885 = v2876.read(); // v2876[k121];	// L3787
    float a119;	// L3788
    a119 = v2885;	// L3789
    float v2887 = v2877.read(); // v2877[k121];	// L3790
    float b119;	// L3791
    b119 = v2887;	// L3792
    float v2889 = a119;	// L3793
    float v2890 = b119;	// L3794
    float v2891 = v2889 * v2890;	// L3795
    float v2892 = v119;	// L3796
    float v2893 = v2892 + v2891;	// L3797
    v119 = v2893;	// L3798
    float v2894 = a119;	// L3799
    v2878.write(v2894); // v2878[k121] = v2894;	// L3800
    float v2895 = b119;	// L3801
    v2879.write(v2895); // v2879[k121] = v2895;	// L3802
  }
  float v2896 = v119;	// L3804
  v2880[v2881][v2882] = v2896;	// L3805
}

void PE_kernel_YV_0_7(
  hls::stream< float > &v2897 /* v2897[64] */,
  hls::stream< float > &v2898 /* v2898[64] */,
  hls::stream< float > &v2899 /* v2899[64] */,
  hls::stream< float > &v2900 /* v2900[64] */,
  float v2901[8][8],
  int v2902,
  int v2903
) {	// L3808
  #pragma HLS stream variable=v2897 depth=9
  #pragma HLS stream variable=v2898 depth=9
  #pragma HLS stream variable=v2899 depth=9
  #pragma HLS stream variable=v2900 depth=9
  #pragma HLS array_partition variable=v2901 complete dim=1
  #pragma HLS array_partition variable=v2901 complete dim=2

  float v120;	// L3811
  v120 = 0.000000;	// L3812
  l_S_k_0_k122: for (int k122 = 0; k122 < 64; k122++) {	// L3813
    float v2906 = v2897.read(); // v2897[k122];	// L3814
    float a120;	// L3815
    a120 = v2906;	// L3816
    float v2908 = v2898.read(); // v2898[k122];	// L3817
    float b120;	// L3818
    b120 = v2908;	// L3819
    float v2910 = a120;	// L3820
    float v2911 = b120;	// L3821
    float v2912 = v2910 * v2911;	// L3822
    float v2913 = v120;	// L3823
    float v2914 = v2913 + v2912;	// L3824
    v120 = v2914;	// L3825
    float v2915 = a120;	// L3826
    v2899.write(v2915); // v2899[k122] = v2915;	// L3827
    float v2916 = b120;	// L3828
    v2900.write(v2916); // v2900[k122] = v2916;	// L3829
  }
  float v2917 = v120;	// L3831
  v2901[v2902][v2903] = v2917;	// L3832
}

void PE_kernel_YV_1_7(
  hls::stream< float > &v2918 /* v2918[64] */,
  hls::stream< float > &v2919 /* v2919[64] */,
  hls::stream< float > &v2920 /* v2920[64] */,
  hls::stream< float > &v2921 /* v2921[64] */,
  float v2922[8][8],
  int v2923,
  int v2924
) {	// L3835
  #pragma HLS stream variable=v2918 depth=9
  #pragma HLS stream variable=v2919 depth=9
  #pragma HLS stream variable=v2920 depth=9
  #pragma HLS stream variable=v2921 depth=9
  #pragma HLS array_partition variable=v2922 complete dim=1
  #pragma HLS array_partition variable=v2922 complete dim=2

  float v121;	// L3838
  v121 = 0.000000;	// L3839
  l_S_k_0_k123: for (int k123 = 0; k123 < 64; k123++) {	// L3840
    float v2927 = v2918.read(); // v2918[k123];	// L3841
    float a121;	// L3842
    a121 = v2927;	// L3843
    float v2929 = v2919.read(); // v2919[k123];	// L3844
    float b121;	// L3845
    b121 = v2929;	// L3846
    float v2931 = a121;	// L3847
    float v2932 = b121;	// L3848
    float v2933 = v2931 * v2932;	// L3849
    float v2934 = v121;	// L3850
    float v2935 = v2934 + v2933;	// L3851
    v121 = v2935;	// L3852
    float v2936 = a121;	// L3853
    v2920.write(v2936); // v2920[k123] = v2936;	// L3854
    float v2937 = b121;	// L3855
    v2921.write(v2937); // v2921[k123] = v2937;	// L3856
  }
  float v2938 = v121;	// L3858
  v2922[v2923][v2924] = v2938;	// L3859
}

void PE_kernel_YV_2_7(
  hls::stream< float > &v2939 /* v2939[64] */,
  hls::stream< float > &v2940 /* v2940[64] */,
  hls::stream< float > &v2941 /* v2941[64] */,
  hls::stream< float > &v2942 /* v2942[64] */,
  float v2943[8][8],
  int v2944,
  int v2945
) {	// L3862
  #pragma HLS stream variable=v2939 depth=9
  #pragma HLS stream variable=v2940 depth=9
  #pragma HLS stream variable=v2941 depth=9
  #pragma HLS stream variable=v2942 depth=9
  #pragma HLS array_partition variable=v2943 complete dim=1
  #pragma HLS array_partition variable=v2943 complete dim=2

  float v122;	// L3865
  v122 = 0.000000;	// L3866
  l_S_k_0_k124: for (int k124 = 0; k124 < 64; k124++) {	// L3867
    float v2948 = v2939.read(); // v2939[k124];	// L3868
    float a122;	// L3869
    a122 = v2948;	// L3870
    float v2950 = v2940.read(); // v2940[k124];	// L3871
    float b122;	// L3872
    b122 = v2950;	// L3873
    float v2952 = a122;	// L3874
    float v2953 = b122;	// L3875
    float v2954 = v2952 * v2953;	// L3876
    float v2955 = v122;	// L3877
    float v2956 = v2955 + v2954;	// L3878
    v122 = v2956;	// L3879
    float v2957 = a122;	// L3880
    v2941.write(v2957); // v2941[k124] = v2957;	// L3881
    float v2958 = b122;	// L3882
    v2942.write(v2958); // v2942[k124] = v2958;	// L3883
  }
  float v2959 = v122;	// L3885
  v2943[v2944][v2945] = v2959;	// L3886
}

void PE_kernel_YV_3_7(
  hls::stream< float > &v2960 /* v2960[64] */,
  hls::stream< float > &v2961 /* v2961[64] */,
  hls::stream< float > &v2962 /* v2962[64] */,
  hls::stream< float > &v2963 /* v2963[64] */,
  float v2964[8][8],
  int v2965,
  int v2966
) {	// L3889
  #pragma HLS stream variable=v2960 depth=9
  #pragma HLS stream variable=v2961 depth=9
  #pragma HLS stream variable=v2962 depth=9
  #pragma HLS stream variable=v2963 depth=9
  #pragma HLS array_partition variable=v2964 complete dim=1
  #pragma HLS array_partition variable=v2964 complete dim=2

  float v123;	// L3892
  v123 = 0.000000;	// L3893
  l_S_k_0_k125: for (int k125 = 0; k125 < 64; k125++) {	// L3894
    float v2969 = v2960.read(); // v2960[k125];	// L3895
    float a123;	// L3896
    a123 = v2969;	// L3897
    float v2971 = v2961.read(); // v2961[k125];	// L3898
    float b123;	// L3899
    b123 = v2971;	// L3900
    float v2973 = a123;	// L3901
    float v2974 = b123;	// L3902
    float v2975 = v2973 * v2974;	// L3903
    float v2976 = v123;	// L3904
    float v2977 = v2976 + v2975;	// L3905
    v123 = v2977;	// L3906
    float v2978 = a123;	// L3907
    v2962.write(v2978); // v2962[k125] = v2978;	// L3908
    float v2979 = b123;	// L3909
    v2963.write(v2979); // v2963[k125] = v2979;	// L3910
  }
  float v2980 = v123;	// L3912
  v2964[v2965][v2966] = v2980;	// L3913
}

void PE_kernel_YV_4_7(
  hls::stream< float > &v2981 /* v2981[64] */,
  hls::stream< float > &v2982 /* v2982[64] */,
  hls::stream< float > &v2983 /* v2983[64] */,
  hls::stream< float > &v2984 /* v2984[64] */,
  float v2985[8][8],
  int v2986,
  int v2987
) {	// L3916
  #pragma HLS stream variable=v2981 depth=9
  #pragma HLS stream variable=v2982 depth=9
  #pragma HLS stream variable=v2983 depth=9
  #pragma HLS stream variable=v2984 depth=9
  #pragma HLS array_partition variable=v2985 complete dim=1
  #pragma HLS array_partition variable=v2985 complete dim=2

  float v124;	// L3919
  v124 = 0.000000;	// L3920
  l_S_k_0_k126: for (int k126 = 0; k126 < 64; k126++) {	// L3921
    float v2990 = v2981.read(); // v2981[k126];	// L3922
    float a124;	// L3923
    a124 = v2990;	// L3924
    float v2992 = v2982.read(); // v2982[k126];	// L3925
    float b124;	// L3926
    b124 = v2992;	// L3927
    float v2994 = a124;	// L3928
    float v2995 = b124;	// L3929
    float v2996 = v2994 * v2995;	// L3930
    float v2997 = v124;	// L3931
    float v2998 = v2997 + v2996;	// L3932
    v124 = v2998;	// L3933
    float v2999 = a124;	// L3934
    v2983.write(v2999); // v2983[k126] = v2999;	// L3935
    float v3000 = b124;	// L3936
    v2984.write(v3000); // v2984[k126] = v3000;	// L3937
  }
  float v3001 = v124;	// L3939
  v2985[v2986][v2987] = v3001;	// L3940
}

void PE_kernel_YV_5_7(
  hls::stream< float > &v3002 /* v3002[64] */,
  hls::stream< float > &v3003 /* v3003[64] */,
  hls::stream< float > &v3004 /* v3004[64] */,
  hls::stream< float > &v3005 /* v3005[64] */,
  float v3006[8][8],
  int v3007,
  int v3008
) {	// L3943
  #pragma HLS stream variable=v3002 depth=9
  #pragma HLS stream variable=v3003 depth=9
  #pragma HLS stream variable=v3004 depth=9
  #pragma HLS stream variable=v3005 depth=9
  #pragma HLS array_partition variable=v3006 complete dim=1
  #pragma HLS array_partition variable=v3006 complete dim=2

  float v125;	// L3946
  v125 = 0.000000;	// L3947
  l_S_k_0_k127: for (int k127 = 0; k127 < 64; k127++) {	// L3948
    float v3011 = v3002.read(); // v3002[k127];	// L3949
    float a125;	// L3950
    a125 = v3011;	// L3951
    float v3013 = v3003.read(); // v3003[k127];	// L3952
    float b125;	// L3953
    b125 = v3013;	// L3954
    float v3015 = a125;	// L3955
    float v3016 = b125;	// L3956
    float v3017 = v3015 * v3016;	// L3957
    float v3018 = v125;	// L3958
    float v3019 = v3018 + v3017;	// L3959
    v125 = v3019;	// L3960
    float v3020 = a125;	// L3961
    v3004.write(v3020); // v3004[k127] = v3020;	// L3962
    float v3021 = b125;	// L3963
    v3005.write(v3021); // v3005[k127] = v3021;	// L3964
  }
  float v3022 = v125;	// L3966
  v3006[v3007][v3008] = v3022;	// L3967
}

void PE_kernel_YV_6_7(
  hls::stream< float > &v3023 /* v3023[64] */,
  hls::stream< float > &v3024 /* v3024[64] */,
  hls::stream< float > &v3025 /* v3025[64] */,
  hls::stream< float > &v3026 /* v3026[64] */,
  float v3027[8][8],
  int v3028,
  int v3029
) {	// L3970
  #pragma HLS stream variable=v3023 depth=9
  #pragma HLS stream variable=v3024 depth=9
  #pragma HLS stream variable=v3025 depth=9
  #pragma HLS stream variable=v3026 depth=9
  #pragma HLS array_partition variable=v3027 complete dim=1
  #pragma HLS array_partition variable=v3027 complete dim=2

  float v126;	// L3973
  v126 = 0.000000;	// L3974
  l_S_k_0_k128: for (int k128 = 0; k128 < 64; k128++) {	// L3975
    float v3032 = v3023.read(); // v3023[k128];	// L3976
    float a126;	// L3977
    a126 = v3032;	// L3978
    float v3034 = v3024.read(); // v3024[k128];	// L3979
    float b126;	// L3980
    b126 = v3034;	// L3981
    float v3036 = a126;	// L3982
    float v3037 = b126;	// L3983
    float v3038 = v3036 * v3037;	// L3984
    float v3039 = v126;	// L3985
    float v3040 = v3039 + v3038;	// L3986
    v126 = v3040;	// L3987
    float v3041 = a126;	// L3988
    v3025.write(v3041); // v3025[k128] = v3041;	// L3989
    float v3042 = b126;	// L3990
    v3026.write(v3042); // v3026[k128] = v3042;	// L3991
  }
  float v3043 = v126;	// L3993
  v3027[v3028][v3029] = v3043;	// L3994
}

void PE_kernel_YV_7_7(
  hls::stream< float > &v3044 /* v3044[64] */,
  hls::stream< float > &v3045 /* v3045[64] */,
  hls::stream< float > &v3046 /* v3046[64] */,
  hls::stream< float > &v3047 /* v3047[64] */,
  float v3048[8][8],
  int v3049,
  int v3050
) {	// L3997
  #pragma HLS stream variable=v3044 depth=9
  #pragma HLS stream variable=v3045 depth=9
  #pragma HLS stream variable=v3046 depth=9
  #pragma HLS stream variable=v3047 depth=9
  #pragma HLS array_partition variable=v3048 complete dim=1
  #pragma HLS array_partition variable=v3048 complete dim=2

  float v127;	// L4000
  v127 = 0.000000;	// L4001
  l_S_k_0_k129: for (int k129 = 0; k129 < 64; k129++) {	// L4002
    float v3053 = v3044.read(); // v3044[k129];	// L4003
    float a127;	// L4004
    a127 = v3053;	// L4005
    float v3055 = v3045.read(); // v3045[k129];	// L4006
    float b127;	// L4007
    b127 = v3055;	// L4008
    float v3057 = a127;	// L4009
    float v3058 = b127;	// L4010
    float v3059 = v3057 * v3058;	// L4011
    float v3060 = v127;	// L4012
    float v3061 = v3060 + v3059;	// L4013
    v127 = v3061;	// L4014
    float v3062 = a127;	// L4015
    v3046.write(v3062); // v3046[k129] = v3062;	// L4016
    float v3063 = b127;	// L4017
    v3047.write(v3063); // v3047[k129] = v3063;	// L4018
  }
  float v3064 = v127;	// L4020
  v3048[v3049][v3050] = v3064;	// L4021
}

void systolic_tile_YV(
  float v3065[8][64],
  float v3066[64][8],
  float v3067[8][8]
) {	// L4024
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v3065 complete dim=1

  #pragma HLS array_partition variable=v3066 complete dim=2

  #pragma HLS array_partition variable=v3067 complete dim=1
  #pragma HLS array_partition variable=v3067 complete dim=2

  hls::stream< float > A_fifo1[8][9] /* A_fifo1[8][9][64] */;	// L4025
  #pragma HLS stream variable=A_fifo1 depth=9
  hls::stream< float > B_fifo1[8][9] /* B_fifo1[8][9][64] */;	// L4026
  #pragma HLS stream variable=B_fifo1 depth=9
  float A_drain1[8];	// L4027
  float B_drain1[8];	// L4028
  l_data_load_k130: for (int k130 = 0; k130 < 64; k130++) {	// L4029
    l_S_m_0_m2: for (int m2 = 0; m2 < 8; m2++) {	// L4030
      float v3074 = v3065[m2][k130];	// L4031
      A_fifo1[m2][0].write(v3074); // A_fifo1[m2][0][k130] = v3074;	// L4032
    }
    l_S_n_1_n2: for (int n2 = 0; n2 < 8; n2++) {	// L4034
      float v3076 = v3066[k130][n2];	// L4035
      B_fifo1[n2][0].write(v3076); // B_fifo1[n2][0][k130] = v3076;	// L4036
    }
  }
  hls::stream< float > &v3077 /* v3077[64] */ = A_fifo1[0][0];	// L4040
  hls::stream< float > &v3078 /* v3078[64] */ = B_fifo1[0][0];	// L4041
  hls::stream< float > &v3079 /* v3079[64] */ = A_fifo1[0][1];	// L4047
  hls::stream< float > &v3080 /* v3080[64] */ = B_fifo1[0][1];	// L4048
  PE_kernel_YV_0_0(v3077, v3078, v3079, v3080, v3067, 0, 0);	// L4049
  hls::stream< float > &v3081 /* v3081[64] */ = A_fifo1[0][1];	// L4051
  hls::stream< float > &v3082 /* v3082[64] */ = B_fifo1[1][0];	// L4052
  hls::stream< float > &v3083 /* v3083[64] */ = A_fifo1[0][2];	// L4056
  hls::stream< float > &v3084 /* v3084[64] */ = B_fifo1[1][1];	// L4057
  PE_kernel_YV_1_0(v3081, v3082, v3083, v3084, v3067, 0, 1);	// L4058
  hls::stream< float > &v3085 /* v3085[64] */ = A_fifo1[0][2];	// L4060
  hls::stream< float > &v3086 /* v3086[64] */ = B_fifo1[2][0];	// L4061
  hls::stream< float > &v3087 /* v3087[64] */ = A_fifo1[0][3];	// L4065
  hls::stream< float > &v3088 /* v3088[64] */ = B_fifo1[2][1];	// L4066
  PE_kernel_YV_2_0(v3085, v3086, v3087, v3088, v3067, 0, 2);	// L4067
  hls::stream< float > &v3089 /* v3089[64] */ = A_fifo1[0][3];	// L4069
  hls::stream< float > &v3090 /* v3090[64] */ = B_fifo1[3][0];	// L4070
  hls::stream< float > &v3091 /* v3091[64] */ = A_fifo1[0][4];	// L4074
  hls::stream< float > &v3092 /* v3092[64] */ = B_fifo1[3][1];	// L4075
  PE_kernel_YV_3_0(v3089, v3090, v3091, v3092, v3067, 0, 3);	// L4076
  hls::stream< float > &v3093 /* v3093[64] */ = A_fifo1[0][4];	// L4078
  hls::stream< float > &v3094 /* v3094[64] */ = B_fifo1[4][0];	// L4079
  hls::stream< float > &v3095 /* v3095[64] */ = A_fifo1[0][5];	// L4083
  hls::stream< float > &v3096 /* v3096[64] */ = B_fifo1[4][1];	// L4084
  PE_kernel_YV_4_0(v3093, v3094, v3095, v3096, v3067, 0, 4);	// L4085
  hls::stream< float > &v3097 /* v3097[64] */ = A_fifo1[0][5];	// L4087
  hls::stream< float > &v3098 /* v3098[64] */ = B_fifo1[5][0];	// L4088
  hls::stream< float > &v3099 /* v3099[64] */ = A_fifo1[0][6];	// L4092
  hls::stream< float > &v3100 /* v3100[64] */ = B_fifo1[5][1];	// L4093
  PE_kernel_YV_5_0(v3097, v3098, v3099, v3100, v3067, 0, 5);	// L4094
  hls::stream< float > &v3101 /* v3101[64] */ = A_fifo1[0][6];	// L4096
  hls::stream< float > &v3102 /* v3102[64] */ = B_fifo1[6][0];	// L4097
  hls::stream< float > &v3103 /* v3103[64] */ = A_fifo1[0][7];	// L4101
  hls::stream< float > &v3104 /* v3104[64] */ = B_fifo1[6][1];	// L4102
  PE_kernel_YV_6_0(v3101, v3102, v3103, v3104, v3067, 0, 6);	// L4103
  hls::stream< float > &v3105 /* v3105[64] */ = A_fifo1[0][7];	// L4105
  hls::stream< float > &v3106 /* v3106[64] */ = B_fifo1[7][0];	// L4106
  hls::stream< float > &v3107 /* v3107[64] */ = A_fifo1[0][8];	// L4110
  hls::stream< float > &v3108 /* v3108[64] */ = B_fifo1[7][1];	// L4111
  PE_kernel_YV_7_0(v3105, v3106, v3107, v3108, v3067, 0, 7);	// L4112
  hls::stream< float > &v3109 /* v3109[64] */ = A_fifo1[1][0];	// L4113
  hls::stream< float > &v3110 /* v3110[64] */ = B_fifo1[0][1];	// L4114
  hls::stream< float > &v3111 /* v3111[64] */ = A_fifo1[1][1];	// L4115
  hls::stream< float > &v3112 /* v3112[64] */ = B_fifo1[0][2];	// L4116
  PE_kernel_YV_0_1(v3109, v3110, v3111, v3112, v3067, 1, 0);	// L4117
  hls::stream< float > &v3113 /* v3113[64] */ = A_fifo1[1][1];	// L4118
  hls::stream< float > &v3114 /* v3114[64] */ = B_fifo1[1][1];	// L4119
  hls::stream< float > &v3115 /* v3115[64] */ = A_fifo1[1][2];	// L4120
  hls::stream< float > &v3116 /* v3116[64] */ = B_fifo1[1][2];	// L4121
  PE_kernel_YV_1_1(v3113, v3114, v3115, v3116, v3067, 1, 1);	// L4122
  hls::stream< float > &v3117 /* v3117[64] */ = A_fifo1[1][2];	// L4123
  hls::stream< float > &v3118 /* v3118[64] */ = B_fifo1[2][1];	// L4124
  hls::stream< float > &v3119 /* v3119[64] */ = A_fifo1[1][3];	// L4125
  hls::stream< float > &v3120 /* v3120[64] */ = B_fifo1[2][2];	// L4126
  PE_kernel_YV_2_1(v3117, v3118, v3119, v3120, v3067, 1, 2);	// L4127
  hls::stream< float > &v3121 /* v3121[64] */ = A_fifo1[1][3];	// L4128
  hls::stream< float > &v3122 /* v3122[64] */ = B_fifo1[3][1];	// L4129
  hls::stream< float > &v3123 /* v3123[64] */ = A_fifo1[1][4];	// L4130
  hls::stream< float > &v3124 /* v3124[64] */ = B_fifo1[3][2];	// L4131
  PE_kernel_YV_3_1(v3121, v3122, v3123, v3124, v3067, 1, 3);	// L4132
  hls::stream< float > &v3125 /* v3125[64] */ = A_fifo1[1][4];	// L4133
  hls::stream< float > &v3126 /* v3126[64] */ = B_fifo1[4][1];	// L4134
  hls::stream< float > &v3127 /* v3127[64] */ = A_fifo1[1][5];	// L4135
  hls::stream< float > &v3128 /* v3128[64] */ = B_fifo1[4][2];	// L4136
  PE_kernel_YV_4_1(v3125, v3126, v3127, v3128, v3067, 1, 4);	// L4137
  hls::stream< float > &v3129 /* v3129[64] */ = A_fifo1[1][5];	// L4138
  hls::stream< float > &v3130 /* v3130[64] */ = B_fifo1[5][1];	// L4139
  hls::stream< float > &v3131 /* v3131[64] */ = A_fifo1[1][6];	// L4140
  hls::stream< float > &v3132 /* v3132[64] */ = B_fifo1[5][2];	// L4141
  PE_kernel_YV_5_1(v3129, v3130, v3131, v3132, v3067, 1, 5);	// L4142
  hls::stream< float > &v3133 /* v3133[64] */ = A_fifo1[1][6];	// L4143
  hls::stream< float > &v3134 /* v3134[64] */ = B_fifo1[6][1];	// L4144
  hls::stream< float > &v3135 /* v3135[64] */ = A_fifo1[1][7];	// L4145
  hls::stream< float > &v3136 /* v3136[64] */ = B_fifo1[6][2];	// L4146
  PE_kernel_YV_6_1(v3133, v3134, v3135, v3136, v3067, 1, 6);	// L4147
  hls::stream< float > &v3137 /* v3137[64] */ = A_fifo1[1][7];	// L4148
  hls::stream< float > &v3138 /* v3138[64] */ = B_fifo1[7][1];	// L4149
  hls::stream< float > &v3139 /* v3139[64] */ = A_fifo1[1][8];	// L4150
  hls::stream< float > &v3140 /* v3140[64] */ = B_fifo1[7][2];	// L4151
  PE_kernel_YV_7_1(v3137, v3138, v3139, v3140, v3067, 1, 7);	// L4152
  hls::stream< float > &v3141 /* v3141[64] */ = A_fifo1[2][0];	// L4153
  hls::stream< float > &v3142 /* v3142[64] */ = B_fifo1[0][2];	// L4154
  hls::stream< float > &v3143 /* v3143[64] */ = A_fifo1[2][1];	// L4155
  hls::stream< float > &v3144 /* v3144[64] */ = B_fifo1[0][3];	// L4156
  PE_kernel_YV_0_2(v3141, v3142, v3143, v3144, v3067, 2, 0);	// L4157
  hls::stream< float > &v3145 /* v3145[64] */ = A_fifo1[2][1];	// L4158
  hls::stream< float > &v3146 /* v3146[64] */ = B_fifo1[1][2];	// L4159
  hls::stream< float > &v3147 /* v3147[64] */ = A_fifo1[2][2];	// L4160
  hls::stream< float > &v3148 /* v3148[64] */ = B_fifo1[1][3];	// L4161
  PE_kernel_YV_1_2(v3145, v3146, v3147, v3148, v3067, 2, 1);	// L4162
  hls::stream< float > &v3149 /* v3149[64] */ = A_fifo1[2][2];	// L4163
  hls::stream< float > &v3150 /* v3150[64] */ = B_fifo1[2][2];	// L4164
  hls::stream< float > &v3151 /* v3151[64] */ = A_fifo1[2][3];	// L4165
  hls::stream< float > &v3152 /* v3152[64] */ = B_fifo1[2][3];	// L4166
  PE_kernel_YV_2_2(v3149, v3150, v3151, v3152, v3067, 2, 2);	// L4167
  hls::stream< float > &v3153 /* v3153[64] */ = A_fifo1[2][3];	// L4168
  hls::stream< float > &v3154 /* v3154[64] */ = B_fifo1[3][2];	// L4169
  hls::stream< float > &v3155 /* v3155[64] */ = A_fifo1[2][4];	// L4170
  hls::stream< float > &v3156 /* v3156[64] */ = B_fifo1[3][3];	// L4171
  PE_kernel_YV_3_2(v3153, v3154, v3155, v3156, v3067, 2, 3);	// L4172
  hls::stream< float > &v3157 /* v3157[64] */ = A_fifo1[2][4];	// L4173
  hls::stream< float > &v3158 /* v3158[64] */ = B_fifo1[4][2];	// L4174
  hls::stream< float > &v3159 /* v3159[64] */ = A_fifo1[2][5];	// L4175
  hls::stream< float > &v3160 /* v3160[64] */ = B_fifo1[4][3];	// L4176
  PE_kernel_YV_4_2(v3157, v3158, v3159, v3160, v3067, 2, 4);	// L4177
  hls::stream< float > &v3161 /* v3161[64] */ = A_fifo1[2][5];	// L4178
  hls::stream< float > &v3162 /* v3162[64] */ = B_fifo1[5][2];	// L4179
  hls::stream< float > &v3163 /* v3163[64] */ = A_fifo1[2][6];	// L4180
  hls::stream< float > &v3164 /* v3164[64] */ = B_fifo1[5][3];	// L4181
  PE_kernel_YV_5_2(v3161, v3162, v3163, v3164, v3067, 2, 5);	// L4182
  hls::stream< float > &v3165 /* v3165[64] */ = A_fifo1[2][6];	// L4183
  hls::stream< float > &v3166 /* v3166[64] */ = B_fifo1[6][2];	// L4184
  hls::stream< float > &v3167 /* v3167[64] */ = A_fifo1[2][7];	// L4185
  hls::stream< float > &v3168 /* v3168[64] */ = B_fifo1[6][3];	// L4186
  PE_kernel_YV_6_2(v3165, v3166, v3167, v3168, v3067, 2, 6);	// L4187
  hls::stream< float > &v3169 /* v3169[64] */ = A_fifo1[2][7];	// L4188
  hls::stream< float > &v3170 /* v3170[64] */ = B_fifo1[7][2];	// L4189
  hls::stream< float > &v3171 /* v3171[64] */ = A_fifo1[2][8];	// L4190
  hls::stream< float > &v3172 /* v3172[64] */ = B_fifo1[7][3];	// L4191
  PE_kernel_YV_7_2(v3169, v3170, v3171, v3172, v3067, 2, 7);	// L4192
  hls::stream< float > &v3173 /* v3173[64] */ = A_fifo1[3][0];	// L4193
  hls::stream< float > &v3174 /* v3174[64] */ = B_fifo1[0][3];	// L4194
  hls::stream< float > &v3175 /* v3175[64] */ = A_fifo1[3][1];	// L4195
  hls::stream< float > &v3176 /* v3176[64] */ = B_fifo1[0][4];	// L4196
  PE_kernel_YV_0_3(v3173, v3174, v3175, v3176, v3067, 3, 0);	// L4197
  hls::stream< float > &v3177 /* v3177[64] */ = A_fifo1[3][1];	// L4198
  hls::stream< float > &v3178 /* v3178[64] */ = B_fifo1[1][3];	// L4199
  hls::stream< float > &v3179 /* v3179[64] */ = A_fifo1[3][2];	// L4200
  hls::stream< float > &v3180 /* v3180[64] */ = B_fifo1[1][4];	// L4201
  PE_kernel_YV_1_3(v3177, v3178, v3179, v3180, v3067, 3, 1);	// L4202
  hls::stream< float > &v3181 /* v3181[64] */ = A_fifo1[3][2];	// L4203
  hls::stream< float > &v3182 /* v3182[64] */ = B_fifo1[2][3];	// L4204
  hls::stream< float > &v3183 /* v3183[64] */ = A_fifo1[3][3];	// L4205
  hls::stream< float > &v3184 /* v3184[64] */ = B_fifo1[2][4];	// L4206
  PE_kernel_YV_2_3(v3181, v3182, v3183, v3184, v3067, 3, 2);	// L4207
  hls::stream< float > &v3185 /* v3185[64] */ = A_fifo1[3][3];	// L4208
  hls::stream< float > &v3186 /* v3186[64] */ = B_fifo1[3][3];	// L4209
  hls::stream< float > &v3187 /* v3187[64] */ = A_fifo1[3][4];	// L4210
  hls::stream< float > &v3188 /* v3188[64] */ = B_fifo1[3][4];	// L4211
  PE_kernel_YV_3_3(v3185, v3186, v3187, v3188, v3067, 3, 3);	// L4212
  hls::stream< float > &v3189 /* v3189[64] */ = A_fifo1[3][4];	// L4213
  hls::stream< float > &v3190 /* v3190[64] */ = B_fifo1[4][3];	// L4214
  hls::stream< float > &v3191 /* v3191[64] */ = A_fifo1[3][5];	// L4215
  hls::stream< float > &v3192 /* v3192[64] */ = B_fifo1[4][4];	// L4216
  PE_kernel_YV_4_3(v3189, v3190, v3191, v3192, v3067, 3, 4);	// L4217
  hls::stream< float > &v3193 /* v3193[64] */ = A_fifo1[3][5];	// L4218
  hls::stream< float > &v3194 /* v3194[64] */ = B_fifo1[5][3];	// L4219
  hls::stream< float > &v3195 /* v3195[64] */ = A_fifo1[3][6];	// L4220
  hls::stream< float > &v3196 /* v3196[64] */ = B_fifo1[5][4];	// L4221
  PE_kernel_YV_5_3(v3193, v3194, v3195, v3196, v3067, 3, 5);	// L4222
  hls::stream< float > &v3197 /* v3197[64] */ = A_fifo1[3][6];	// L4223
  hls::stream< float > &v3198 /* v3198[64] */ = B_fifo1[6][3];	// L4224
  hls::stream< float > &v3199 /* v3199[64] */ = A_fifo1[3][7];	// L4225
  hls::stream< float > &v3200 /* v3200[64] */ = B_fifo1[6][4];	// L4226
  PE_kernel_YV_6_3(v3197, v3198, v3199, v3200, v3067, 3, 6);	// L4227
  hls::stream< float > &v3201 /* v3201[64] */ = A_fifo1[3][7];	// L4228
  hls::stream< float > &v3202 /* v3202[64] */ = B_fifo1[7][3];	// L4229
  hls::stream< float > &v3203 /* v3203[64] */ = A_fifo1[3][8];	// L4230
  hls::stream< float > &v3204 /* v3204[64] */ = B_fifo1[7][4];	// L4231
  PE_kernel_YV_7_3(v3201, v3202, v3203, v3204, v3067, 3, 7);	// L4232
  hls::stream< float > &v3205 /* v3205[64] */ = A_fifo1[4][0];	// L4233
  hls::stream< float > &v3206 /* v3206[64] */ = B_fifo1[0][4];	// L4234
  hls::stream< float > &v3207 /* v3207[64] */ = A_fifo1[4][1];	// L4235
  hls::stream< float > &v3208 /* v3208[64] */ = B_fifo1[0][5];	// L4236
  PE_kernel_YV_0_4(v3205, v3206, v3207, v3208, v3067, 4, 0);	// L4237
  hls::stream< float > &v3209 /* v3209[64] */ = A_fifo1[4][1];	// L4238
  hls::stream< float > &v3210 /* v3210[64] */ = B_fifo1[1][4];	// L4239
  hls::stream< float > &v3211 /* v3211[64] */ = A_fifo1[4][2];	// L4240
  hls::stream< float > &v3212 /* v3212[64] */ = B_fifo1[1][5];	// L4241
  PE_kernel_YV_1_4(v3209, v3210, v3211, v3212, v3067, 4, 1);	// L4242
  hls::stream< float > &v3213 /* v3213[64] */ = A_fifo1[4][2];	// L4243
  hls::stream< float > &v3214 /* v3214[64] */ = B_fifo1[2][4];	// L4244
  hls::stream< float > &v3215 /* v3215[64] */ = A_fifo1[4][3];	// L4245
  hls::stream< float > &v3216 /* v3216[64] */ = B_fifo1[2][5];	// L4246
  PE_kernel_YV_2_4(v3213, v3214, v3215, v3216, v3067, 4, 2);	// L4247
  hls::stream< float > &v3217 /* v3217[64] */ = A_fifo1[4][3];	// L4248
  hls::stream< float > &v3218 /* v3218[64] */ = B_fifo1[3][4];	// L4249
  hls::stream< float > &v3219 /* v3219[64] */ = A_fifo1[4][4];	// L4250
  hls::stream< float > &v3220 /* v3220[64] */ = B_fifo1[3][5];	// L4251
  PE_kernel_YV_3_4(v3217, v3218, v3219, v3220, v3067, 4, 3);	// L4252
  hls::stream< float > &v3221 /* v3221[64] */ = A_fifo1[4][4];	// L4253
  hls::stream< float > &v3222 /* v3222[64] */ = B_fifo1[4][4];	// L4254
  hls::stream< float > &v3223 /* v3223[64] */ = A_fifo1[4][5];	// L4255
  hls::stream< float > &v3224 /* v3224[64] */ = B_fifo1[4][5];	// L4256
  PE_kernel_YV_4_4(v3221, v3222, v3223, v3224, v3067, 4, 4);	// L4257
  hls::stream< float > &v3225 /* v3225[64] */ = A_fifo1[4][5];	// L4258
  hls::stream< float > &v3226 /* v3226[64] */ = B_fifo1[5][4];	// L4259
  hls::stream< float > &v3227 /* v3227[64] */ = A_fifo1[4][6];	// L4260
  hls::stream< float > &v3228 /* v3228[64] */ = B_fifo1[5][5];	// L4261
  PE_kernel_YV_5_4(v3225, v3226, v3227, v3228, v3067, 4, 5);	// L4262
  hls::stream< float > &v3229 /* v3229[64] */ = A_fifo1[4][6];	// L4263
  hls::stream< float > &v3230 /* v3230[64] */ = B_fifo1[6][4];	// L4264
  hls::stream< float > &v3231 /* v3231[64] */ = A_fifo1[4][7];	// L4265
  hls::stream< float > &v3232 /* v3232[64] */ = B_fifo1[6][5];	// L4266
  PE_kernel_YV_6_4(v3229, v3230, v3231, v3232, v3067, 4, 6);	// L4267
  hls::stream< float > &v3233 /* v3233[64] */ = A_fifo1[4][7];	// L4268
  hls::stream< float > &v3234 /* v3234[64] */ = B_fifo1[7][4];	// L4269
  hls::stream< float > &v3235 /* v3235[64] */ = A_fifo1[4][8];	// L4270
  hls::stream< float > &v3236 /* v3236[64] */ = B_fifo1[7][5];	// L4271
  PE_kernel_YV_7_4(v3233, v3234, v3235, v3236, v3067, 4, 7);	// L4272
  hls::stream< float > &v3237 /* v3237[64] */ = A_fifo1[5][0];	// L4273
  hls::stream< float > &v3238 /* v3238[64] */ = B_fifo1[0][5];	// L4274
  hls::stream< float > &v3239 /* v3239[64] */ = A_fifo1[5][1];	// L4275
  hls::stream< float > &v3240 /* v3240[64] */ = B_fifo1[0][6];	// L4276
  PE_kernel_YV_0_5(v3237, v3238, v3239, v3240, v3067, 5, 0);	// L4277
  hls::stream< float > &v3241 /* v3241[64] */ = A_fifo1[5][1];	// L4278
  hls::stream< float > &v3242 /* v3242[64] */ = B_fifo1[1][5];	// L4279
  hls::stream< float > &v3243 /* v3243[64] */ = A_fifo1[5][2];	// L4280
  hls::stream< float > &v3244 /* v3244[64] */ = B_fifo1[1][6];	// L4281
  PE_kernel_YV_1_5(v3241, v3242, v3243, v3244, v3067, 5, 1);	// L4282
  hls::stream< float > &v3245 /* v3245[64] */ = A_fifo1[5][2];	// L4283
  hls::stream< float > &v3246 /* v3246[64] */ = B_fifo1[2][5];	// L4284
  hls::stream< float > &v3247 /* v3247[64] */ = A_fifo1[5][3];	// L4285
  hls::stream< float > &v3248 /* v3248[64] */ = B_fifo1[2][6];	// L4286
  PE_kernel_YV_2_5(v3245, v3246, v3247, v3248, v3067, 5, 2);	// L4287
  hls::stream< float > &v3249 /* v3249[64] */ = A_fifo1[5][3];	// L4288
  hls::stream< float > &v3250 /* v3250[64] */ = B_fifo1[3][5];	// L4289
  hls::stream< float > &v3251 /* v3251[64] */ = A_fifo1[5][4];	// L4290
  hls::stream< float > &v3252 /* v3252[64] */ = B_fifo1[3][6];	// L4291
  PE_kernel_YV_3_5(v3249, v3250, v3251, v3252, v3067, 5, 3);	// L4292
  hls::stream< float > &v3253 /* v3253[64] */ = A_fifo1[5][4];	// L4293
  hls::stream< float > &v3254 /* v3254[64] */ = B_fifo1[4][5];	// L4294
  hls::stream< float > &v3255 /* v3255[64] */ = A_fifo1[5][5];	// L4295
  hls::stream< float > &v3256 /* v3256[64] */ = B_fifo1[4][6];	// L4296
  PE_kernel_YV_4_5(v3253, v3254, v3255, v3256, v3067, 5, 4);	// L4297
  hls::stream< float > &v3257 /* v3257[64] */ = A_fifo1[5][5];	// L4298
  hls::stream< float > &v3258 /* v3258[64] */ = B_fifo1[5][5];	// L4299
  hls::stream< float > &v3259 /* v3259[64] */ = A_fifo1[5][6];	// L4300
  hls::stream< float > &v3260 /* v3260[64] */ = B_fifo1[5][6];	// L4301
  PE_kernel_YV_5_5(v3257, v3258, v3259, v3260, v3067, 5, 5);	// L4302
  hls::stream< float > &v3261 /* v3261[64] */ = A_fifo1[5][6];	// L4303
  hls::stream< float > &v3262 /* v3262[64] */ = B_fifo1[6][5];	// L4304
  hls::stream< float > &v3263 /* v3263[64] */ = A_fifo1[5][7];	// L4305
  hls::stream< float > &v3264 /* v3264[64] */ = B_fifo1[6][6];	// L4306
  PE_kernel_YV_6_5(v3261, v3262, v3263, v3264, v3067, 5, 6);	// L4307
  hls::stream< float > &v3265 /* v3265[64] */ = A_fifo1[5][7];	// L4308
  hls::stream< float > &v3266 /* v3266[64] */ = B_fifo1[7][5];	// L4309
  hls::stream< float > &v3267 /* v3267[64] */ = A_fifo1[5][8];	// L4310
  hls::stream< float > &v3268 /* v3268[64] */ = B_fifo1[7][6];	// L4311
  PE_kernel_YV_7_5(v3265, v3266, v3267, v3268, v3067, 5, 7);	// L4312
  hls::stream< float > &v3269 /* v3269[64] */ = A_fifo1[6][0];	// L4313
  hls::stream< float > &v3270 /* v3270[64] */ = B_fifo1[0][6];	// L4314
  hls::stream< float > &v3271 /* v3271[64] */ = A_fifo1[6][1];	// L4315
  hls::stream< float > &v3272 /* v3272[64] */ = B_fifo1[0][7];	// L4316
  PE_kernel_YV_0_6(v3269, v3270, v3271, v3272, v3067, 6, 0);	// L4317
  hls::stream< float > &v3273 /* v3273[64] */ = A_fifo1[6][1];	// L4318
  hls::stream< float > &v3274 /* v3274[64] */ = B_fifo1[1][6];	// L4319
  hls::stream< float > &v3275 /* v3275[64] */ = A_fifo1[6][2];	// L4320
  hls::stream< float > &v3276 /* v3276[64] */ = B_fifo1[1][7];	// L4321
  PE_kernel_YV_1_6(v3273, v3274, v3275, v3276, v3067, 6, 1);	// L4322
  hls::stream< float > &v3277 /* v3277[64] */ = A_fifo1[6][2];	// L4323
  hls::stream< float > &v3278 /* v3278[64] */ = B_fifo1[2][6];	// L4324
  hls::stream< float > &v3279 /* v3279[64] */ = A_fifo1[6][3];	// L4325
  hls::stream< float > &v3280 /* v3280[64] */ = B_fifo1[2][7];	// L4326
  PE_kernel_YV_2_6(v3277, v3278, v3279, v3280, v3067, 6, 2);	// L4327
  hls::stream< float > &v3281 /* v3281[64] */ = A_fifo1[6][3];	// L4328
  hls::stream< float > &v3282 /* v3282[64] */ = B_fifo1[3][6];	// L4329
  hls::stream< float > &v3283 /* v3283[64] */ = A_fifo1[6][4];	// L4330
  hls::stream< float > &v3284 /* v3284[64] */ = B_fifo1[3][7];	// L4331
  PE_kernel_YV_3_6(v3281, v3282, v3283, v3284, v3067, 6, 3);	// L4332
  hls::stream< float > &v3285 /* v3285[64] */ = A_fifo1[6][4];	// L4333
  hls::stream< float > &v3286 /* v3286[64] */ = B_fifo1[4][6];	// L4334
  hls::stream< float > &v3287 /* v3287[64] */ = A_fifo1[6][5];	// L4335
  hls::stream< float > &v3288 /* v3288[64] */ = B_fifo1[4][7];	// L4336
  PE_kernel_YV_4_6(v3285, v3286, v3287, v3288, v3067, 6, 4);	// L4337
  hls::stream< float > &v3289 /* v3289[64] */ = A_fifo1[6][5];	// L4338
  hls::stream< float > &v3290 /* v3290[64] */ = B_fifo1[5][6];	// L4339
  hls::stream< float > &v3291 /* v3291[64] */ = A_fifo1[6][6];	// L4340
  hls::stream< float > &v3292 /* v3292[64] */ = B_fifo1[5][7];	// L4341
  PE_kernel_YV_5_6(v3289, v3290, v3291, v3292, v3067, 6, 5);	// L4342
  hls::stream< float > &v3293 /* v3293[64] */ = A_fifo1[6][6];	// L4343
  hls::stream< float > &v3294 /* v3294[64] */ = B_fifo1[6][6];	// L4344
  hls::stream< float > &v3295 /* v3295[64] */ = A_fifo1[6][7];	// L4345
  hls::stream< float > &v3296 /* v3296[64] */ = B_fifo1[6][7];	// L4346
  PE_kernel_YV_6_6(v3293, v3294, v3295, v3296, v3067, 6, 6);	// L4347
  hls::stream< float > &v3297 /* v3297[64] */ = A_fifo1[6][7];	// L4348
  hls::stream< float > &v3298 /* v3298[64] */ = B_fifo1[7][6];	// L4349
  hls::stream< float > &v3299 /* v3299[64] */ = A_fifo1[6][8];	// L4350
  hls::stream< float > &v3300 /* v3300[64] */ = B_fifo1[7][7];	// L4351
  PE_kernel_YV_7_6(v3297, v3298, v3299, v3300, v3067, 6, 7);	// L4352
  hls::stream< float > &v3301 /* v3301[64] */ = A_fifo1[7][0];	// L4353
  hls::stream< float > &v3302 /* v3302[64] */ = B_fifo1[0][7];	// L4354
  hls::stream< float > &v3303 /* v3303[64] */ = A_fifo1[7][1];	// L4355
  hls::stream< float > &v3304 /* v3304[64] */ = B_fifo1[0][8];	// L4356
  PE_kernel_YV_0_7(v3301, v3302, v3303, v3304, v3067, 7, 0);	// L4357
  hls::stream< float > &v3305 /* v3305[64] */ = A_fifo1[7][1];	// L4358
  hls::stream< float > &v3306 /* v3306[64] */ = B_fifo1[1][7];	// L4359
  hls::stream< float > &v3307 /* v3307[64] */ = A_fifo1[7][2];	// L4360
  hls::stream< float > &v3308 /* v3308[64] */ = B_fifo1[1][8];	// L4361
  PE_kernel_YV_1_7(v3305, v3306, v3307, v3308, v3067, 7, 1);	// L4362
  hls::stream< float > &v3309 /* v3309[64] */ = A_fifo1[7][2];	// L4363
  hls::stream< float > &v3310 /* v3310[64] */ = B_fifo1[2][7];	// L4364
  hls::stream< float > &v3311 /* v3311[64] */ = A_fifo1[7][3];	// L4365
  hls::stream< float > &v3312 /* v3312[64] */ = B_fifo1[2][8];	// L4366
  PE_kernel_YV_2_7(v3309, v3310, v3311, v3312, v3067, 7, 2);	// L4367
  hls::stream< float > &v3313 /* v3313[64] */ = A_fifo1[7][3];	// L4368
  hls::stream< float > &v3314 /* v3314[64] */ = B_fifo1[3][7];	// L4369
  hls::stream< float > &v3315 /* v3315[64] */ = A_fifo1[7][4];	// L4370
  hls::stream< float > &v3316 /* v3316[64] */ = B_fifo1[3][8];	// L4371
  PE_kernel_YV_3_7(v3313, v3314, v3315, v3316, v3067, 7, 3);	// L4372
  hls::stream< float > &v3317 /* v3317[64] */ = A_fifo1[7][4];	// L4373
  hls::stream< float > &v3318 /* v3318[64] */ = B_fifo1[4][7];	// L4374
  hls::stream< float > &v3319 /* v3319[64] */ = A_fifo1[7][5];	// L4375
  hls::stream< float > &v3320 /* v3320[64] */ = B_fifo1[4][8];	// L4376
  PE_kernel_YV_4_7(v3317, v3318, v3319, v3320, v3067, 7, 4);	// L4377
  hls::stream< float > &v3321 /* v3321[64] */ = A_fifo1[7][5];	// L4378
  hls::stream< float > &v3322 /* v3322[64] */ = B_fifo1[5][7];	// L4379
  hls::stream< float > &v3323 /* v3323[64] */ = A_fifo1[7][6];	// L4380
  hls::stream< float > &v3324 /* v3324[64] */ = B_fifo1[5][8];	// L4381
  PE_kernel_YV_5_7(v3321, v3322, v3323, v3324, v3067, 7, 5);	// L4382
  hls::stream< float > &v3325 /* v3325[64] */ = A_fifo1[7][6];	// L4383
  hls::stream< float > &v3326 /* v3326[64] */ = B_fifo1[6][7];	// L4384
  hls::stream< float > &v3327 /* v3327[64] */ = A_fifo1[7][7];	// L4385
  hls::stream< float > &v3328 /* v3328[64] */ = B_fifo1[6][8];	// L4386
  PE_kernel_YV_6_7(v3325, v3326, v3327, v3328, v3067, 7, 6);	// L4387
  hls::stream< float > &v3329 /* v3329[64] */ = A_fifo1[7][7];	// L4388
  hls::stream< float > &v3330 /* v3330[64] */ = B_fifo1[7][7];	// L4389
  hls::stream< float > &v3331 /* v3331[64] */ = A_fifo1[7][8];	// L4390
  hls::stream< float > &v3332 /* v3332[64] */ = B_fifo1[7][8];	// L4391
  PE_kernel_YV_7_7(v3329, v3330, v3331, v3332, v3067, 7, 7);	// L4392
  l_data_drain_k131: for (int k131 = 0; k131 < 64; k131++) {	// L4393
    l_S_m_4_m3: for (int m3 = 0; m3 < 8; m3++) {	// L4394
      float v3335 = A_fifo1[m3][8].read(); // A_fifo1[m3][8][k131];	// L4395
      A_drain1[m3] = v3335;	// L4396
    }
    l_S_n_5_n3: for (int n3 = 0; n3 < 8; n3++) {	// L4398
      float v3337 = B_fifo1[n3][8].read(); // B_fifo1[n3][8][k131];	// L4399
      B_drain1[n3] = v3337;	// L4400
    }
  }
}

void systolic_YV(
  float v3338[64][64],
  float v3339[64][64],
  float v3340[64][64]
) {	// L4405
  float local_A1[8][64];	// L4406
  #pragma HLS array_partition variable=local_A1 complete dim=1

  float local_B1[64][8];	// L4407
  #pragma HLS array_partition variable=local_B1 complete dim=2

  float local_C1[8][8];	// L4408
  #pragma HLS array_partition variable=local_C1 complete dim=1
  #pragma HLS array_partition variable=local_C1 complete dim=2

  l_outer_tile_mi1: for (int mi1 = 0; mi1 < 8; mi1++) {	// L4409
    l_ni1: for (int ni1 = 0; ni1 < 8; ni1++) {	// L4410
    #pragma HLS dataflow
      l_load_A_tile_ak1: for (int ak1 = 0; ak1 < 64; ak1++) {	// L4411
        l_ai1: for (int ai1 = 0; ai1 < 8; ai1++) {	// L4412
        #pragma HLS pipeline II=1
          ap_int<33> v3348 = ni1;	// L4413
          bool v3349 = v3348 == 0;	// L4416
          if (v3349) {	// L4417
            float v3350 = v3338[((mi1 * 8) + ai1)][ak1];	// L4418
            local_A1[ai1][ak1] = v3350;	// L4419
          }
        }
      }
      l_load_B_tile_bk1: for (int bk1 = 0; bk1 < 64; bk1++) {	// L4423
        l_bj1: for (int bj1 = 0; bj1 < 8; bj1++) {	// L4424
        #pragma HLS pipeline II=1
          float v3353 = v3339[bk1][((ni1 * 8) + bj1)];	// L4425
          local_B1[bk1][bj1] = v3353;	// L4426
        }
      }
      systolic_tile_YV(local_A1, local_B1, local_C1);	// L4429
      l_store_C_tile_sj1: for (int sj1 = 0; sj1 < 8; sj1++) {	// L4430
        l_si1: for (int si1 = 0; si1 < 8; si1++) {	// L4431
        #pragma HLS pipeline II=1
          float v3356 = local_C1[si1][sj1];	// L4432
          v3340[((mi1 * 8) + si1)][((ni1 * 8) + sj1)] = v3356;	// L4433
        }
      }
    }
  }
}

void masked_casual_dot_product_attention(
  float *v3357,
  float *v3358,
  float *v3359,
  int32_t *v3360,
  float *v3361
) {	// L4440
  #pragma HLS interface m_axi port=v3357 offset=slave bundle=gmem0
  #pragma HLS interface m_axi port=v3358 offset=slave bundle=gmem1
  #pragma HLS interface m_axi port=v3359 offset=slave bundle=gmem2
  #pragma HLS interface m_axi port=v3360 offset=slave bundle=gmem3
  #pragma HLS interface m_axi port=v3361 offset=slave bundle=gmem4
  float buf0[64][768];	//
  l_S_buf0_buf0_l_0: for (int buf0_l_0 = 0; buf0_l_0 < 64; buf0_l_0++) {	//
    l_buf0_l_1: for (int buf0_l_1 = 0; buf0_l_1 < 768; buf0_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v3365 = v3357[((buf0_l_0 * 768) + buf0_l_1)];	//
      buf0[buf0_l_0][buf0_l_1] = v3365;	//
    }
  }
  float buf1[64][768];	//
  l_S_buf1_buf1_l_0: for (int buf1_l_0 = 0; buf1_l_0 < 64; buf1_l_0++) {	//
    l_buf1_l_1: for (int buf1_l_1 = 0; buf1_l_1 < 768; buf1_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v3369 = v3358[((buf1_l_0 * 768) + buf1_l_1)];	//
      buf1[buf1_l_0][buf1_l_1] = v3369;	//
    }
  }
  float buf2[64][768];	//
  l_S_buf2_buf2_l_0: for (int buf2_l_0 = 0; buf2_l_0 < 64; buf2_l_0++) {	//
    l_buf2_l_1: for (int buf2_l_1 = 0; buf2_l_1 < 768; buf2_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v3373 = v3359[((buf2_l_0 * 768) + buf2_l_1)];	//
      buf2[buf2_l_0][buf2_l_1] = v3373;	//
    }
  }
  int32_t buf3[2];	//
  l_S_buf3_buf3_l_0: for (int buf3_l_0 = 0; buf3_l_0 < 2; buf3_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    int32_t v3376 = v3360[buf3_l_0];	//
    buf3[buf3_l_0] = v3376;	//
  }
  float Z[64][768];	// L4441
  l_S_h_0_h: for (int h = 0; h < 12; h++) {	// L4442
    float Q_h[64][64];	// L4443
    float K_h[64][64];	// L4444
    float V_h[64][64];	// L4445
    l_mha_split_i3: for (int i3 = 0; i3 < 64; i3++) {	// L4446
      l_j3: for (int j3 = 0; j3 < 64; j3++) {	// L4447
        float v3384 = buf0[i3][((h * 64) + j3)];	// L4448
        Q_h[i3][j3] = v3384;	// L4449
        float v3385 = buf1[i3][((h * 64) + j3)];	// L4450
        K_h[j3][i3] = v3385;	// L4451
        float v3386 = buf2[i3][((h * 64) + j3)];	// L4452
        V_h[i3][j3] = v3386;	// L4453
      }
    }
    float C_h[64][64];	// L4458
    for (int v3388 = 0; v3388 < 64; v3388++) {	// L4459
      for (int v3389 = 0; v3389 < 64; v3389++) {	// L4459
        C_h[v3388][v3389] = 0.000000;	// L4459
      }
    }
    float Y[64][64];	// L4460
    for (int v3391 = 0; v3391 < 64; v3391++) {	// L4461
      for (int v3392 = 0; v3392 < 64; v3392++) {	// L4461
        Y[v3391][v3392] = 0.000000;	// L4461
      }
    }
    systolic_QKT(Q_h, K_h, Y);	// L4462
    float v3393[64][64];
    mask_softmax_per_head_sft_Y(Y, buf3, v3393);	// L4463
    systolic_YV(v3393, V_h, C_h);	// L4464
    l_mha_merge_i4: for (int i4 = 0; i4 < 64; i4++) {	// L4465
      l_j4: for (int j4 = 0; j4 < 64; j4++) {	// L4466
        float v3396 = C_h[i4][j4];	// L4467
        Z[i4][((h * 64) + j4)] = v3396;	// L4468
      }
    }
  }
  l_S_result4_result4_l_0: for (int result4_l_0 = 0; result4_l_0 < 64; result4_l_0++) {	//
    l_result4_l_1: for (int result4_l_1 = 0; result4_l_1 < 768; result4_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v3399 = Z[result4_l_0][result4_l_1];	//
      v3361[((result4_l_0 * 768) + result4_l_1)] = v3399;	//
    }
  }
}


} // extern "C"
