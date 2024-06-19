
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

void layer_norm(
  float v0[32][48],
  float v1[48],
  float v2[48],
  float v3[32][48]
) {	// L5
  float mean[32];	// L7
  for (int v5 = 0; v5 < 32; v5++) {	// L9
    mean[v5] = 0.000000;	// L9
  }
  float mean2[32];	// L10
  for (int v7 = 0; v7 < 32; v7++) {	// L11
    mean2[v7] = 0.000000;	// L11
  }
  float var[32];	// L12
  l_sum_i: for (int i = 0; i < 32; i++) {	// L13
    l_j: for (int j = 0; j < 48; j++) {	// L14
      float v11 = v0[i][j];	// L15
      float v12 = mean[i];	// L16
      float v13 = v12 + v11;	// L17
      mean[i] = v13;	// L18
      float v14 = v0[i][j];	// L19
      float v15 = v14 * v14;	// L20
      float v16 = mean2[i];	// L21
      float v17 = v16 + v15;	// L22
      mean2[i] = v17;	// L23
    }
  }
  l_mean_var_i1: for (int i1 = 0; i1 < 32; i1++) {	// L26
    float v19 = mean[i1];	// L27
    float v20 = v19 / 48.000000;	// L30
    mean[i1] = v20;	// L31
    float v21 = mean2[i1];	// L32
    float v22 = v21 / 48.000000;	// L33
    mean2[i1] = v22;	// L34
    float v23 = mean2[i1];	// L35
    float v24 = mean[i1];	// L36
    float v25 = v24 * v24;	// L37
    float v26 = v23 - v25;	// L38
    var[i1] = v26;	// L39
  }
  l_norm_i2: for (int i2 = 0; i2 < 32; i2++) {	// L41
    l_j1: for (int j1 = 0; j1 < 48; j1++) {	// L42
      float v29 = v1[j1];	// L43
      float v30 = v0[i2][j1];	// L44
      float v31 = mean[i2];	// L45
      float v32 = v30 - v31;	// L46
      float v33 = v29 * v32;	// L47
      float v34 = var[i2];	// L48
      float v35 = v34 + 0.000010;	// L50
      float v36 = sqrt(v35);	// L51
      float v37 = v33 / v36;	// L52
      float v38 = v2[j1];	// L53
      float v39 = v37 + v38;	// L54
      v3[i2][j1] = v39;	// L55
    }
  }
}

void PE_kernel_Q_0_0(
  hls::stream< float > &v40 /* v40[48] */,
  hls::stream< float > &v41 /* v41[48] */,
  hls::stream< float > &v42 /* v42[48] */,
  hls::stream< float > &v43 /* v43[48] */,
  float v44[4][4],
  int v45,
  int v46
) {	// L60
  #pragma HLS stream variable=v40 depth=5
  #pragma HLS stream variable=v41 depth=5
  #pragma HLS stream variable=v42 depth=5
  #pragma HLS stream variable=v43 depth=5
  #pragma HLS array_partition variable=v44 complete dim=1
  #pragma HLS array_partition variable=v44 complete dim=2

  float v;	// L63
  v = 0.000000;	// L64
  l_S_k_0_k: for (int k = 0; k < 48; k++) {	// L65
    float v49 = v40.read(); // v40[k];	// L66
    float a;	// L67
    a = v49;	// L68
    float v51 = v41.read(); // v41[k];	// L69
    float b;	// L70
    b = v51;	// L71
    float v53 = a;	// L72
    float v54 = b;	// L73
    float v55 = v53 * v54;	// L74
    float v56 = v;	// L75
    float v57 = v56 + v55;	// L76
    v = v57;	// L77
    float v58 = a;	// L78
    v42.write(v58); // v42[k] = v58;	// L79
    float v59 = b;	// L80
    v43.write(v59); // v43[k] = v59;	// L81
  }
  float v60 = v;	// L83
  v44[v45][v46] = v60;	// L84
}

void PE_kernel_Q_1_0(
  hls::stream< float > &v61 /* v61[48] */,
  hls::stream< float > &v62 /* v62[48] */,
  hls::stream< float > &v63 /* v63[48] */,
  hls::stream< float > &v64 /* v64[48] */,
  float v65[4][4],
  int v66,
  int v67
) {	// L87
  #pragma HLS stream variable=v61 depth=5
  #pragma HLS stream variable=v62 depth=5
  #pragma HLS stream variable=v63 depth=5
  #pragma HLS stream variable=v64 depth=5
  #pragma HLS array_partition variable=v65 complete dim=1
  #pragma HLS array_partition variable=v65 complete dim=2

  float v1;	// L90
  v1 = 0.000000;	// L91
  l_S_k_0_k1: for (int k1 = 0; k1 < 48; k1++) {	// L92
    float v70 = v61.read(); // v61[k1];	// L93
    float a1;	// L94
    a1 = v70;	// L95
    float v72 = v62.read(); // v62[k1];	// L96
    float b1;	// L97
    b1 = v72;	// L98
    float v74 = a1;	// L99
    float v75 = b1;	// L100
    float v76 = v74 * v75;	// L101
    float v77 = v1;	// L102
    float v78 = v77 + v76;	// L103
    v1 = v78;	// L104
    float v79 = a1;	// L105
    v63.write(v79); // v63[k1] = v79;	// L106
    float v80 = b1;	// L107
    v64.write(v80); // v64[k1] = v80;	// L108
  }
  float v81 = v1;	// L110
  v65[v66][v67] = v81;	// L111
}

void PE_kernel_Q_2_0(
  hls::stream< float > &v82 /* v82[48] */,
  hls::stream< float > &v83 /* v83[48] */,
  hls::stream< float > &v84 /* v84[48] */,
  hls::stream< float > &v85 /* v85[48] */,
  float v86[4][4],
  int v87,
  int v88
) {	// L114
  #pragma HLS stream variable=v82 depth=5
  #pragma HLS stream variable=v83 depth=5
  #pragma HLS stream variable=v84 depth=5
  #pragma HLS stream variable=v85 depth=5
  #pragma HLS array_partition variable=v86 complete dim=1
  #pragma HLS array_partition variable=v86 complete dim=2

  float v2;	// L117
  v2 = 0.000000;	// L118
  l_S_k_0_k2: for (int k2 = 0; k2 < 48; k2++) {	// L119
    float v91 = v82.read(); // v82[k2];	// L120
    float a2;	// L121
    a2 = v91;	// L122
    float v93 = v83.read(); // v83[k2];	// L123
    float b2;	// L124
    b2 = v93;	// L125
    float v95 = a2;	// L126
    float v96 = b2;	// L127
    float v97 = v95 * v96;	// L128
    float v98 = v2;	// L129
    float v99 = v98 + v97;	// L130
    v2 = v99;	// L131
    float v100 = a2;	// L132
    v84.write(v100); // v84[k2] = v100;	// L133
    float v101 = b2;	// L134
    v85.write(v101); // v85[k2] = v101;	// L135
  }
  float v102 = v2;	// L137
  v86[v87][v88] = v102;	// L138
}

void PE_kernel_Q_3_0(
  hls::stream< float > &v103 /* v103[48] */,
  hls::stream< float > &v104 /* v104[48] */,
  hls::stream< float > &v105 /* v105[48] */,
  hls::stream< float > &v106 /* v106[48] */,
  float v107[4][4],
  int v108,
  int v109
) {	// L141
  #pragma HLS stream variable=v103 depth=5
  #pragma HLS stream variable=v104 depth=5
  #pragma HLS stream variable=v105 depth=5
  #pragma HLS stream variable=v106 depth=5
  #pragma HLS array_partition variable=v107 complete dim=1
  #pragma HLS array_partition variable=v107 complete dim=2

  float v3;	// L144
  v3 = 0.000000;	// L145
  l_S_k_0_k3: for (int k3 = 0; k3 < 48; k3++) {	// L146
    float v112 = v103.read(); // v103[k3];	// L147
    float a3;	// L148
    a3 = v112;	// L149
    float v114 = v104.read(); // v104[k3];	// L150
    float b3;	// L151
    b3 = v114;	// L152
    float v116 = a3;	// L153
    float v117 = b3;	// L154
    float v118 = v116 * v117;	// L155
    float v119 = v3;	// L156
    float v120 = v119 + v118;	// L157
    v3 = v120;	// L158
    float v121 = a3;	// L159
    v105.write(v121); // v105[k3] = v121;	// L160
    float v122 = b3;	// L161
    v106.write(v122); // v106[k3] = v122;	// L162
  }
  float v123 = v3;	// L164
  v107[v108][v109] = v123;	// L165
}

void PE_kernel_Q_0_1(
  hls::stream< float > &v124 /* v124[48] */,
  hls::stream< float > &v125 /* v125[48] */,
  hls::stream< float > &v126 /* v126[48] */,
  hls::stream< float > &v127 /* v127[48] */,
  float v128[4][4],
  int v129,
  int v130
) {	// L168
  #pragma HLS stream variable=v124 depth=5
  #pragma HLS stream variable=v125 depth=5
  #pragma HLS stream variable=v126 depth=5
  #pragma HLS stream variable=v127 depth=5
  #pragma HLS array_partition variable=v128 complete dim=1
  #pragma HLS array_partition variable=v128 complete dim=2

  float v4;	// L171
  v4 = 0.000000;	// L172
  l_S_k_0_k4: for (int k4 = 0; k4 < 48; k4++) {	// L173
    float v133 = v124.read(); // v124[k4];	// L174
    float a4;	// L175
    a4 = v133;	// L176
    float v135 = v125.read(); // v125[k4];	// L177
    float b4;	// L178
    b4 = v135;	// L179
    float v137 = a4;	// L180
    float v138 = b4;	// L181
    float v139 = v137 * v138;	// L182
    float v140 = v4;	// L183
    float v141 = v140 + v139;	// L184
    v4 = v141;	// L185
    float v142 = a4;	// L186
    v126.write(v142); // v126[k4] = v142;	// L187
    float v143 = b4;	// L188
    v127.write(v143); // v127[k4] = v143;	// L189
  }
  float v144 = v4;	// L191
  v128[v129][v130] = v144;	// L192
}

void PE_kernel_Q_1_1(
  hls::stream< float > &v145 /* v145[48] */,
  hls::stream< float > &v146 /* v146[48] */,
  hls::stream< float > &v147 /* v147[48] */,
  hls::stream< float > &v148 /* v148[48] */,
  float v149[4][4],
  int v150,
  int v151
) {	// L195
  #pragma HLS stream variable=v145 depth=5
  #pragma HLS stream variable=v146 depth=5
  #pragma HLS stream variable=v147 depth=5
  #pragma HLS stream variable=v148 depth=5
  #pragma HLS array_partition variable=v149 complete dim=1
  #pragma HLS array_partition variable=v149 complete dim=2

  float v5;	// L198
  v5 = 0.000000;	// L199
  l_S_k_0_k5: for (int k5 = 0; k5 < 48; k5++) {	// L200
    float v154 = v145.read(); // v145[k5];	// L201
    float a5;	// L202
    a5 = v154;	// L203
    float v156 = v146.read(); // v146[k5];	// L204
    float b5;	// L205
    b5 = v156;	// L206
    float v158 = a5;	// L207
    float v159 = b5;	// L208
    float v160 = v158 * v159;	// L209
    float v161 = v5;	// L210
    float v162 = v161 + v160;	// L211
    v5 = v162;	// L212
    float v163 = a5;	// L213
    v147.write(v163); // v147[k5] = v163;	// L214
    float v164 = b5;	// L215
    v148.write(v164); // v148[k5] = v164;	// L216
  }
  float v165 = v5;	// L218
  v149[v150][v151] = v165;	// L219
}

void PE_kernel_Q_2_1(
  hls::stream< float > &v166 /* v166[48] */,
  hls::stream< float > &v167 /* v167[48] */,
  hls::stream< float > &v168 /* v168[48] */,
  hls::stream< float > &v169 /* v169[48] */,
  float v170[4][4],
  int v171,
  int v172
) {	// L222
  #pragma HLS stream variable=v166 depth=5
  #pragma HLS stream variable=v167 depth=5
  #pragma HLS stream variable=v168 depth=5
  #pragma HLS stream variable=v169 depth=5
  #pragma HLS array_partition variable=v170 complete dim=1
  #pragma HLS array_partition variable=v170 complete dim=2

  float v6;	// L225
  v6 = 0.000000;	// L226
  l_S_k_0_k6: for (int k6 = 0; k6 < 48; k6++) {	// L227
    float v175 = v166.read(); // v166[k6];	// L228
    float a6;	// L229
    a6 = v175;	// L230
    float v177 = v167.read(); // v167[k6];	// L231
    float b6;	// L232
    b6 = v177;	// L233
    float v179 = a6;	// L234
    float v180 = b6;	// L235
    float v181 = v179 * v180;	// L236
    float v182 = v6;	// L237
    float v183 = v182 + v181;	// L238
    v6 = v183;	// L239
    float v184 = a6;	// L240
    v168.write(v184); // v168[k6] = v184;	// L241
    float v185 = b6;	// L242
    v169.write(v185); // v169[k6] = v185;	// L243
  }
  float v186 = v6;	// L245
  v170[v171][v172] = v186;	// L246
}

void PE_kernel_Q_3_1(
  hls::stream< float > &v187 /* v187[48] */,
  hls::stream< float > &v188 /* v188[48] */,
  hls::stream< float > &v189 /* v189[48] */,
  hls::stream< float > &v190 /* v190[48] */,
  float v191[4][4],
  int v192,
  int v193
) {	// L249
  #pragma HLS stream variable=v187 depth=5
  #pragma HLS stream variable=v188 depth=5
  #pragma HLS stream variable=v189 depth=5
  #pragma HLS stream variable=v190 depth=5
  #pragma HLS array_partition variable=v191 complete dim=1
  #pragma HLS array_partition variable=v191 complete dim=2

  float v7;	// L252
  v7 = 0.000000;	// L253
  l_S_k_0_k7: for (int k7 = 0; k7 < 48; k7++) {	// L254
    float v196 = v187.read(); // v187[k7];	// L255
    float a7;	// L256
    a7 = v196;	// L257
    float v198 = v188.read(); // v188[k7];	// L258
    float b7;	// L259
    b7 = v198;	// L260
    float v200 = a7;	// L261
    float v201 = b7;	// L262
    float v202 = v200 * v201;	// L263
    float v203 = v7;	// L264
    float v204 = v203 + v202;	// L265
    v7 = v204;	// L266
    float v205 = a7;	// L267
    v189.write(v205); // v189[k7] = v205;	// L268
    float v206 = b7;	// L269
    v190.write(v206); // v190[k7] = v206;	// L270
  }
  float v207 = v7;	// L272
  v191[v192][v193] = v207;	// L273
}

void PE_kernel_Q_0_2(
  hls::stream< float > &v208 /* v208[48] */,
  hls::stream< float > &v209 /* v209[48] */,
  hls::stream< float > &v210 /* v210[48] */,
  hls::stream< float > &v211 /* v211[48] */,
  float v212[4][4],
  int v213,
  int v214
) {	// L276
  #pragma HLS stream variable=v208 depth=5
  #pragma HLS stream variable=v209 depth=5
  #pragma HLS stream variable=v210 depth=5
  #pragma HLS stream variable=v211 depth=5
  #pragma HLS array_partition variable=v212 complete dim=1
  #pragma HLS array_partition variable=v212 complete dim=2

  float v8;	// L279
  v8 = 0.000000;	// L280
  l_S_k_0_k8: for (int k8 = 0; k8 < 48; k8++) {	// L281
    float v217 = v208.read(); // v208[k8];	// L282
    float a8;	// L283
    a8 = v217;	// L284
    float v219 = v209.read(); // v209[k8];	// L285
    float b8;	// L286
    b8 = v219;	// L287
    float v221 = a8;	// L288
    float v222 = b8;	// L289
    float v223 = v221 * v222;	// L290
    float v224 = v8;	// L291
    float v225 = v224 + v223;	// L292
    v8 = v225;	// L293
    float v226 = a8;	// L294
    v210.write(v226); // v210[k8] = v226;	// L295
    float v227 = b8;	// L296
    v211.write(v227); // v211[k8] = v227;	// L297
  }
  float v228 = v8;	// L299
  v212[v213][v214] = v228;	// L300
}

void PE_kernel_Q_1_2(
  hls::stream< float > &v229 /* v229[48] */,
  hls::stream< float > &v230 /* v230[48] */,
  hls::stream< float > &v231 /* v231[48] */,
  hls::stream< float > &v232 /* v232[48] */,
  float v233[4][4],
  int v234,
  int v235
) {	// L303
  #pragma HLS stream variable=v229 depth=5
  #pragma HLS stream variable=v230 depth=5
  #pragma HLS stream variable=v231 depth=5
  #pragma HLS stream variable=v232 depth=5
  #pragma HLS array_partition variable=v233 complete dim=1
  #pragma HLS array_partition variable=v233 complete dim=2

  float v9;	// L306
  v9 = 0.000000;	// L307
  l_S_k_0_k9: for (int k9 = 0; k9 < 48; k9++) {	// L308
    float v238 = v229.read(); // v229[k9];	// L309
    float a9;	// L310
    a9 = v238;	// L311
    float v240 = v230.read(); // v230[k9];	// L312
    float b9;	// L313
    b9 = v240;	// L314
    float v242 = a9;	// L315
    float v243 = b9;	// L316
    float v244 = v242 * v243;	// L317
    float v245 = v9;	// L318
    float v246 = v245 + v244;	// L319
    v9 = v246;	// L320
    float v247 = a9;	// L321
    v231.write(v247); // v231[k9] = v247;	// L322
    float v248 = b9;	// L323
    v232.write(v248); // v232[k9] = v248;	// L324
  }
  float v249 = v9;	// L326
  v233[v234][v235] = v249;	// L327
}

void PE_kernel_Q_2_2(
  hls::stream< float > &v250 /* v250[48] */,
  hls::stream< float > &v251 /* v251[48] */,
  hls::stream< float > &v252 /* v252[48] */,
  hls::stream< float > &v253 /* v253[48] */,
  float v254[4][4],
  int v255,
  int v256
) {	// L330
  #pragma HLS stream variable=v250 depth=5
  #pragma HLS stream variable=v251 depth=5
  #pragma HLS stream variable=v252 depth=5
  #pragma HLS stream variable=v253 depth=5
  #pragma HLS array_partition variable=v254 complete dim=1
  #pragma HLS array_partition variable=v254 complete dim=2

  float v10;	// L333
  v10 = 0.000000;	// L334
  l_S_k_0_k10: for (int k10 = 0; k10 < 48; k10++) {	// L335
    float v259 = v250.read(); // v250[k10];	// L336
    float a10;	// L337
    a10 = v259;	// L338
    float v261 = v251.read(); // v251[k10];	// L339
    float b10;	// L340
    b10 = v261;	// L341
    float v263 = a10;	// L342
    float v264 = b10;	// L343
    float v265 = v263 * v264;	// L344
    float v266 = v10;	// L345
    float v267 = v266 + v265;	// L346
    v10 = v267;	// L347
    float v268 = a10;	// L348
    v252.write(v268); // v252[k10] = v268;	// L349
    float v269 = b10;	// L350
    v253.write(v269); // v253[k10] = v269;	// L351
  }
  float v270 = v10;	// L353
  v254[v255][v256] = v270;	// L354
}

void PE_kernel_Q_3_2(
  hls::stream< float > &v271 /* v271[48] */,
  hls::stream< float > &v272 /* v272[48] */,
  hls::stream< float > &v273 /* v273[48] */,
  hls::stream< float > &v274 /* v274[48] */,
  float v275[4][4],
  int v276,
  int v277
) {	// L357
  #pragma HLS stream variable=v271 depth=5
  #pragma HLS stream variable=v272 depth=5
  #pragma HLS stream variable=v273 depth=5
  #pragma HLS stream variable=v274 depth=5
  #pragma HLS array_partition variable=v275 complete dim=1
  #pragma HLS array_partition variable=v275 complete dim=2

  float v11;	// L360
  v11 = 0.000000;	// L361
  l_S_k_0_k11: for (int k11 = 0; k11 < 48; k11++) {	// L362
    float v280 = v271.read(); // v271[k11];	// L363
    float a11;	// L364
    a11 = v280;	// L365
    float v282 = v272.read(); // v272[k11];	// L366
    float b11;	// L367
    b11 = v282;	// L368
    float v284 = a11;	// L369
    float v285 = b11;	// L370
    float v286 = v284 * v285;	// L371
    float v287 = v11;	// L372
    float v288 = v287 + v286;	// L373
    v11 = v288;	// L374
    float v289 = a11;	// L375
    v273.write(v289); // v273[k11] = v289;	// L376
    float v290 = b11;	// L377
    v274.write(v290); // v274[k11] = v290;	// L378
  }
  float v291 = v11;	// L380
  v275[v276][v277] = v291;	// L381
}

void PE_kernel_Q_0_3(
  hls::stream< float > &v292 /* v292[48] */,
  hls::stream< float > &v293 /* v293[48] */,
  hls::stream< float > &v294 /* v294[48] */,
  hls::stream< float > &v295 /* v295[48] */,
  float v296[4][4],
  int v297,
  int v298
) {	// L384
  #pragma HLS stream variable=v292 depth=5
  #pragma HLS stream variable=v293 depth=5
  #pragma HLS stream variable=v294 depth=5
  #pragma HLS stream variable=v295 depth=5
  #pragma HLS array_partition variable=v296 complete dim=1
  #pragma HLS array_partition variable=v296 complete dim=2

  float v12;	// L387
  v12 = 0.000000;	// L388
  l_S_k_0_k12: for (int k12 = 0; k12 < 48; k12++) {	// L389
    float v301 = v292.read(); // v292[k12];	// L390
    float a12;	// L391
    a12 = v301;	// L392
    float v303 = v293.read(); // v293[k12];	// L393
    float b12;	// L394
    b12 = v303;	// L395
    float v305 = a12;	// L396
    float v306 = b12;	// L397
    float v307 = v305 * v306;	// L398
    float v308 = v12;	// L399
    float v309 = v308 + v307;	// L400
    v12 = v309;	// L401
    float v310 = a12;	// L402
    v294.write(v310); // v294[k12] = v310;	// L403
    float v311 = b12;	// L404
    v295.write(v311); // v295[k12] = v311;	// L405
  }
  float v312 = v12;	// L407
  v296[v297][v298] = v312;	// L408
}

void PE_kernel_Q_1_3(
  hls::stream< float > &v313 /* v313[48] */,
  hls::stream< float > &v314 /* v314[48] */,
  hls::stream< float > &v315 /* v315[48] */,
  hls::stream< float > &v316 /* v316[48] */,
  float v317[4][4],
  int v318,
  int v319
) {	// L411
  #pragma HLS stream variable=v313 depth=5
  #pragma HLS stream variable=v314 depth=5
  #pragma HLS stream variable=v315 depth=5
  #pragma HLS stream variable=v316 depth=5
  #pragma HLS array_partition variable=v317 complete dim=1
  #pragma HLS array_partition variable=v317 complete dim=2

  float v13;	// L414
  v13 = 0.000000;	// L415
  l_S_k_0_k13: for (int k13 = 0; k13 < 48; k13++) {	// L416
    float v322 = v313.read(); // v313[k13];	// L417
    float a13;	// L418
    a13 = v322;	// L419
    float v324 = v314.read(); // v314[k13];	// L420
    float b13;	// L421
    b13 = v324;	// L422
    float v326 = a13;	// L423
    float v327 = b13;	// L424
    float v328 = v326 * v327;	// L425
    float v329 = v13;	// L426
    float v330 = v329 + v328;	// L427
    v13 = v330;	// L428
    float v331 = a13;	// L429
    v315.write(v331); // v315[k13] = v331;	// L430
    float v332 = b13;	// L431
    v316.write(v332); // v316[k13] = v332;	// L432
  }
  float v333 = v13;	// L434
  v317[v318][v319] = v333;	// L435
}

void PE_kernel_Q_2_3(
  hls::stream< float > &v334 /* v334[48] */,
  hls::stream< float > &v335 /* v335[48] */,
  hls::stream< float > &v336 /* v336[48] */,
  hls::stream< float > &v337 /* v337[48] */,
  float v338[4][4],
  int v339,
  int v340
) {	// L438
  #pragma HLS stream variable=v334 depth=5
  #pragma HLS stream variable=v335 depth=5
  #pragma HLS stream variable=v336 depth=5
  #pragma HLS stream variable=v337 depth=5
  #pragma HLS array_partition variable=v338 complete dim=1
  #pragma HLS array_partition variable=v338 complete dim=2

  float v14;	// L441
  v14 = 0.000000;	// L442
  l_S_k_0_k14: for (int k14 = 0; k14 < 48; k14++) {	// L443
    float v343 = v334.read(); // v334[k14];	// L444
    float a14;	// L445
    a14 = v343;	// L446
    float v345 = v335.read(); // v335[k14];	// L447
    float b14;	// L448
    b14 = v345;	// L449
    float v347 = a14;	// L450
    float v348 = b14;	// L451
    float v349 = v347 * v348;	// L452
    float v350 = v14;	// L453
    float v351 = v350 + v349;	// L454
    v14 = v351;	// L455
    float v352 = a14;	// L456
    v336.write(v352); // v336[k14] = v352;	// L457
    float v353 = b14;	// L458
    v337.write(v353); // v337[k14] = v353;	// L459
  }
  float v354 = v14;	// L461
  v338[v339][v340] = v354;	// L462
}

void PE_kernel_Q_3_3(
  hls::stream< float > &v355 /* v355[48] */,
  hls::stream< float > &v356 /* v356[48] */,
  hls::stream< float > &v357 /* v357[48] */,
  hls::stream< float > &v358 /* v358[48] */,
  float v359[4][4],
  int v360,
  int v361
) {	// L465
  #pragma HLS stream variable=v355 depth=5
  #pragma HLS stream variable=v356 depth=5
  #pragma HLS stream variable=v357 depth=5
  #pragma HLS stream variable=v358 depth=5
  #pragma HLS array_partition variable=v359 complete dim=1
  #pragma HLS array_partition variable=v359 complete dim=2

  float v15;	// L468
  v15 = 0.000000;	// L469
  l_S_k_0_k15: for (int k15 = 0; k15 < 48; k15++) {	// L470
    float v364 = v355.read(); // v355[k15];	// L471
    float a15;	// L472
    a15 = v364;	// L473
    float v366 = v356.read(); // v356[k15];	// L474
    float b15;	// L475
    b15 = v366;	// L476
    float v368 = a15;	// L477
    float v369 = b15;	// L478
    float v370 = v368 * v369;	// L479
    float v371 = v15;	// L480
    float v372 = v371 + v370;	// L481
    v15 = v372;	// L482
    float v373 = a15;	// L483
    v357.write(v373); // v357[k15] = v373;	// L484
    float v374 = b15;	// L485
    v358.write(v374); // v358[k15] = v374;	// L486
  }
  float v375 = v15;	// L488
  v359[v360][v361] = v375;	// L489
}

void systolic_tile_Q(
  float v376[4][48],
  float v377[48][4],
  float v378[4][4]
) {	// L492
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v376 complete dim=1

  #pragma HLS array_partition variable=v377 complete dim=2

  #pragma HLS array_partition variable=v378 complete dim=1
  #pragma HLS array_partition variable=v378 complete dim=2

  hls::stream< float > A_fifo[4][5] /* A_fifo[4][5][48] */;	// L493
  #pragma HLS stream variable=A_fifo depth=5
  hls::stream< float > B_fifo[4][5] /* B_fifo[4][5][48] */;	// L494
  #pragma HLS stream variable=B_fifo depth=5
  float A_drain[4];	// L495
  float B_drain[4];	// L496
  l_data_load_k16: for (int k16 = 0; k16 < 48; k16++) {	// L497
    l_S_m_0_m: for (int m = 0; m < 4; m++) {	// L498
      float v385 = v376[m][k16];	// L499
      A_fifo[m][0].write(v385); // A_fifo[m][0][k16] = v385;	// L500
    }
    l_S_n_1_n: for (int n = 0; n < 4; n++) {	// L502
      float v387 = v377[k16][n];	// L503
      B_fifo[n][0].write(v387); // B_fifo[n][0][k16] = v387;	// L504
    }
  }
  hls::stream< float > &v388 /* v388[48] */ = A_fifo[0][0];	// L508
  hls::stream< float > &v389 /* v389[48] */ = B_fifo[0][0];	// L509
  hls::stream< float > &v390 /* v390[48] */ = A_fifo[0][1];	// L515
  hls::stream< float > &v391 /* v391[48] */ = B_fifo[0][1];	// L516
  PE_kernel_Q_0_0(v388, v389, v390, v391, v378, 0, 0);	// L517
  hls::stream< float > &v392 /* v392[48] */ = A_fifo[0][1];	// L519
  hls::stream< float > &v393 /* v393[48] */ = B_fifo[1][0];	// L520
  hls::stream< float > &v394 /* v394[48] */ = A_fifo[0][2];	// L524
  hls::stream< float > &v395 /* v395[48] */ = B_fifo[1][1];	// L525
  PE_kernel_Q_1_0(v392, v393, v394, v395, v378, 0, 1);	// L526
  hls::stream< float > &v396 /* v396[48] */ = A_fifo[0][2];	// L528
  hls::stream< float > &v397 /* v397[48] */ = B_fifo[2][0];	// L529
  hls::stream< float > &v398 /* v398[48] */ = A_fifo[0][3];	// L533
  hls::stream< float > &v399 /* v399[48] */ = B_fifo[2][1];	// L534
  PE_kernel_Q_2_0(v396, v397, v398, v399, v378, 0, 2);	// L535
  hls::stream< float > &v400 /* v400[48] */ = A_fifo[0][3];	// L537
  hls::stream< float > &v401 /* v401[48] */ = B_fifo[3][0];	// L538
  hls::stream< float > &v402 /* v402[48] */ = A_fifo[0][4];	// L542
  hls::stream< float > &v403 /* v403[48] */ = B_fifo[3][1];	// L543
  PE_kernel_Q_3_0(v400, v401, v402, v403, v378, 0, 3);	// L544
  hls::stream< float > &v404 /* v404[48] */ = A_fifo[1][0];	// L545
  hls::stream< float > &v405 /* v405[48] */ = B_fifo[0][1];	// L546
  hls::stream< float > &v406 /* v406[48] */ = A_fifo[1][1];	// L547
  hls::stream< float > &v407 /* v407[48] */ = B_fifo[0][2];	// L548
  PE_kernel_Q_0_1(v404, v405, v406, v407, v378, 1, 0);	// L549
  hls::stream< float > &v408 /* v408[48] */ = A_fifo[1][1];	// L550
  hls::stream< float > &v409 /* v409[48] */ = B_fifo[1][1];	// L551
  hls::stream< float > &v410 /* v410[48] */ = A_fifo[1][2];	// L552
  hls::stream< float > &v411 /* v411[48] */ = B_fifo[1][2];	// L553
  PE_kernel_Q_1_1(v408, v409, v410, v411, v378, 1, 1);	// L554
  hls::stream< float > &v412 /* v412[48] */ = A_fifo[1][2];	// L555
  hls::stream< float > &v413 /* v413[48] */ = B_fifo[2][1];	// L556
  hls::stream< float > &v414 /* v414[48] */ = A_fifo[1][3];	// L557
  hls::stream< float > &v415 /* v415[48] */ = B_fifo[2][2];	// L558
  PE_kernel_Q_2_1(v412, v413, v414, v415, v378, 1, 2);	// L559
  hls::stream< float > &v416 /* v416[48] */ = A_fifo[1][3];	// L560
  hls::stream< float > &v417 /* v417[48] */ = B_fifo[3][1];	// L561
  hls::stream< float > &v418 /* v418[48] */ = A_fifo[1][4];	// L562
  hls::stream< float > &v419 /* v419[48] */ = B_fifo[3][2];	// L563
  PE_kernel_Q_3_1(v416, v417, v418, v419, v378, 1, 3);	// L564
  hls::stream< float > &v420 /* v420[48] */ = A_fifo[2][0];	// L565
  hls::stream< float > &v421 /* v421[48] */ = B_fifo[0][2];	// L566
  hls::stream< float > &v422 /* v422[48] */ = A_fifo[2][1];	// L567
  hls::stream< float > &v423 /* v423[48] */ = B_fifo[0][3];	// L568
  PE_kernel_Q_0_2(v420, v421, v422, v423, v378, 2, 0);	// L569
  hls::stream< float > &v424 /* v424[48] */ = A_fifo[2][1];	// L570
  hls::stream< float > &v425 /* v425[48] */ = B_fifo[1][2];	// L571
  hls::stream< float > &v426 /* v426[48] */ = A_fifo[2][2];	// L572
  hls::stream< float > &v427 /* v427[48] */ = B_fifo[1][3];	// L573
  PE_kernel_Q_1_2(v424, v425, v426, v427, v378, 2, 1);	// L574
  hls::stream< float > &v428 /* v428[48] */ = A_fifo[2][2];	// L575
  hls::stream< float > &v429 /* v429[48] */ = B_fifo[2][2];	// L576
  hls::stream< float > &v430 /* v430[48] */ = A_fifo[2][3];	// L577
  hls::stream< float > &v431 /* v431[48] */ = B_fifo[2][3];	// L578
  PE_kernel_Q_2_2(v428, v429, v430, v431, v378, 2, 2);	// L579
  hls::stream< float > &v432 /* v432[48] */ = A_fifo[2][3];	// L580
  hls::stream< float > &v433 /* v433[48] */ = B_fifo[3][2];	// L581
  hls::stream< float > &v434 /* v434[48] */ = A_fifo[2][4];	// L582
  hls::stream< float > &v435 /* v435[48] */ = B_fifo[3][3];	// L583
  PE_kernel_Q_3_2(v432, v433, v434, v435, v378, 2, 3);	// L584
  hls::stream< float > &v436 /* v436[48] */ = A_fifo[3][0];	// L585
  hls::stream< float > &v437 /* v437[48] */ = B_fifo[0][3];	// L586
  hls::stream< float > &v438 /* v438[48] */ = A_fifo[3][1];	// L587
  hls::stream< float > &v439 /* v439[48] */ = B_fifo[0][4];	// L588
  PE_kernel_Q_0_3(v436, v437, v438, v439, v378, 3, 0);	// L589
  hls::stream< float > &v440 /* v440[48] */ = A_fifo[3][1];	// L590
  hls::stream< float > &v441 /* v441[48] */ = B_fifo[1][3];	// L591
  hls::stream< float > &v442 /* v442[48] */ = A_fifo[3][2];	// L592
  hls::stream< float > &v443 /* v443[48] */ = B_fifo[1][4];	// L593
  PE_kernel_Q_1_3(v440, v441, v442, v443, v378, 3, 1);	// L594
  hls::stream< float > &v444 /* v444[48] */ = A_fifo[3][2];	// L595
  hls::stream< float > &v445 /* v445[48] */ = B_fifo[2][3];	// L596
  hls::stream< float > &v446 /* v446[48] */ = A_fifo[3][3];	// L597
  hls::stream< float > &v447 /* v447[48] */ = B_fifo[2][4];	// L598
  PE_kernel_Q_2_3(v444, v445, v446, v447, v378, 3, 2);	// L599
  hls::stream< float > &v448 /* v448[48] */ = A_fifo[3][3];	// L600
  hls::stream< float > &v449 /* v449[48] */ = B_fifo[3][3];	// L601
  hls::stream< float > &v450 /* v450[48] */ = A_fifo[3][4];	// L602
  hls::stream< float > &v451 /* v451[48] */ = B_fifo[3][4];	// L603
  PE_kernel_Q_3_3(v448, v449, v450, v451, v378, 3, 3);	// L604
  l_data_drain_k17: for (int k17 = 0; k17 < 48; k17++) {	// L605
    l_S_m_4_m1: for (int m1 = 0; m1 < 4; m1++) {	// L606
      float v454 = A_fifo[m1][4].read(); // A_fifo[m1][4][k17];	// L607
      A_drain[m1] = v454;	// L608
    }
    l_S_n_5_n1: for (int n1 = 0; n1 < 4; n1++) {	// L610
      float v456 = B_fifo[n1][4].read(); // B_fifo[n1][4][k17];	// L611
      B_drain[n1] = v456;	// L612
    }
  }
}

void systolic_Q(
  float v457[32][48],
  float *Wq,
  float v459[32][48]
) {	// L617
  float local_A[4][48];	// L618
  #pragma HLS array_partition variable=local_A complete dim=1

  float local_B[48][4];	// L619
  #pragma HLS array_partition variable=local_B complete dim=2

  float local_C[4][4];	// L620
  #pragma HLS array_partition variable=local_C complete dim=1
  #pragma HLS array_partition variable=local_C complete dim=2

  l_outer_tile_mi: for (int mi = 0; mi < 8; mi++) {	// L621
    l_ni: for (int ni = 0; ni < 12; ni++) {	// L622
    #pragma HLS dataflow
      l_load_A_tile_ak: for (int ak = 0; ak < 48; ak++) {	// L623
        l_ai: for (int ai = 0; ai < 4; ai++) {	// L624
        #pragma HLS pipeline II=1
          ap_int<33> v467 = ni;	// L625
          bool v468 = v467 == 0;	// L628
          if (v468) {	// L629
            float v469 = v457[((mi * 4) + ai)][ak];	// L630
            local_A[ai][ak] = v469;	// L631
          }
        }
      }
      l_load_B_tile_bk: for (int bk = 0; bk < 48; bk++) {	// L635
        l_bj: for (int bj = 0; bj < 4; bj++) {	// L636
        #pragma HLS pipeline II=1
          float v472 = Wq[bk*48+((ni * 4) + bj)];	// L637
          // float v472 = v458[bk][((ni * 4) + bj)];	// L637
          local_B[bk][bj] = v472;	// L638
        }
      }
      systolic_tile_Q(local_A, local_B, local_C);	// L641
      l_store_C_tile_sj: for (int sj = 0; sj < 4; sj++) {	// L642
        l_si: for (int si = 0; si < 4; si++) {	// L643
        #pragma HLS pipeline II=1
          float v475 = local_C[si][sj];	// L644
          v459[((mi * 4) + si)][((ni * 4) + sj)] = v475;	// L645
        }
      }
    }
  }
}

void PE_kernel_K_0_0(
  hls::stream< float > &v476 /* v476[48] */,
  hls::stream< float > &v477 /* v477[48] */,
  hls::stream< float > &v478 /* v478[48] */,
  hls::stream< float > &v479 /* v479[48] */,
  float v480[4][4],
  int v481,
  int v482
) {	// L652
  #pragma HLS stream variable=v476 depth=5
  #pragma HLS stream variable=v477 depth=5
  #pragma HLS stream variable=v478 depth=5
  #pragma HLS stream variable=v479 depth=5
  #pragma HLS array_partition variable=v480 complete dim=1
  #pragma HLS array_partition variable=v480 complete dim=2

  float v16;	// L655
  v16 = 0.000000;	// L656
  l_S_k_0_k18: for (int k18 = 0; k18 < 48; k18++) {	// L657
    float v485 = v476.read(); // v476[k18];	// L658
    float a16;	// L659
    a16 = v485;	// L660
    float v487 = v477.read(); // v477[k18];	// L661
    float b16;	// L662
    b16 = v487;	// L663
    float v489 = a16;	// L664
    float v490 = b16;	// L665
    float v491 = v489 * v490;	// L666
    float v492 = v16;	// L667
    float v493 = v492 + v491;	// L668
    v16 = v493;	// L669
    float v494 = a16;	// L670
    v478.write(v494); // v478[k18] = v494;	// L671
    float v495 = b16;	// L672
    v479.write(v495); // v479[k18] = v495;	// L673
  }
  float v496 = v16;	// L675
  v480[v481][v482] = v496;	// L676
}

void PE_kernel_K_1_0(
  hls::stream< float > &v497 /* v497[48] */,
  hls::stream< float > &v498 /* v498[48] */,
  hls::stream< float > &v499 /* v499[48] */,
  hls::stream< float > &v500 /* v500[48] */,
  float v501[4][4],
  int v502,
  int v503
) {	// L679
  #pragma HLS stream variable=v497 depth=5
  #pragma HLS stream variable=v498 depth=5
  #pragma HLS stream variable=v499 depth=5
  #pragma HLS stream variable=v500 depth=5
  #pragma HLS array_partition variable=v501 complete dim=1
  #pragma HLS array_partition variable=v501 complete dim=2

  float v17;	// L682
  v17 = 0.000000;	// L683
  l_S_k_0_k19: for (int k19 = 0; k19 < 48; k19++) {	// L684
    float v506 = v497.read(); // v497[k19];	// L685
    float a17;	// L686
    a17 = v506;	// L687
    float v508 = v498.read(); // v498[k19];	// L688
    float b17;	// L689
    b17 = v508;	// L690
    float v510 = a17;	// L691
    float v511 = b17;	// L692
    float v512 = v510 * v511;	// L693
    float v513 = v17;	// L694
    float v514 = v513 + v512;	// L695
    v17 = v514;	// L696
    float v515 = a17;	// L697
    v499.write(v515); // v499[k19] = v515;	// L698
    float v516 = b17;	// L699
    v500.write(v516); // v500[k19] = v516;	// L700
  }
  float v517 = v17;	// L702
  v501[v502][v503] = v517;	// L703
}

void PE_kernel_K_2_0(
  hls::stream< float > &v518 /* v518[48] */,
  hls::stream< float > &v519 /* v519[48] */,
  hls::stream< float > &v520 /* v520[48] */,
  hls::stream< float > &v521 /* v521[48] */,
  float v522[4][4],
  int v523,
  int v524
) {	// L706
  #pragma HLS stream variable=v518 depth=5
  #pragma HLS stream variable=v519 depth=5
  #pragma HLS stream variable=v520 depth=5
  #pragma HLS stream variable=v521 depth=5
  #pragma HLS array_partition variable=v522 complete dim=1
  #pragma HLS array_partition variable=v522 complete dim=2

  float v18;	// L709
  v18 = 0.000000;	// L710
  l_S_k_0_k20: for (int k20 = 0; k20 < 48; k20++) {	// L711
    float v527 = v518.read(); // v518[k20];	// L712
    float a18;	// L713
    a18 = v527;	// L714
    float v529 = v519.read(); // v519[k20];	// L715
    float b18;	// L716
    b18 = v529;	// L717
    float v531 = a18;	// L718
    float v532 = b18;	// L719
    float v533 = v531 * v532;	// L720
    float v534 = v18;	// L721
    float v535 = v534 + v533;	// L722
    v18 = v535;	// L723
    float v536 = a18;	// L724
    v520.write(v536); // v520[k20] = v536;	// L725
    float v537 = b18;	// L726
    v521.write(v537); // v521[k20] = v537;	// L727
  }
  float v538 = v18;	// L729
  v522[v523][v524] = v538;	// L730
}

void PE_kernel_K_3_0(
  hls::stream< float > &v539 /* v539[48] */,
  hls::stream< float > &v540 /* v540[48] */,
  hls::stream< float > &v541 /* v541[48] */,
  hls::stream< float > &v542 /* v542[48] */,
  float v543[4][4],
  int v544,
  int v545
) {	// L733
  #pragma HLS stream variable=v539 depth=5
  #pragma HLS stream variable=v540 depth=5
  #pragma HLS stream variable=v541 depth=5
  #pragma HLS stream variable=v542 depth=5
  #pragma HLS array_partition variable=v543 complete dim=1
  #pragma HLS array_partition variable=v543 complete dim=2

  float v19;	// L736
  v19 = 0.000000;	// L737
  l_S_k_0_k21: for (int k21 = 0; k21 < 48; k21++) {	// L738
    float v548 = v539.read(); // v539[k21];	// L739
    float a19;	// L740
    a19 = v548;	// L741
    float v550 = v540.read(); // v540[k21];	// L742
    float b19;	// L743
    b19 = v550;	// L744
    float v552 = a19;	// L745
    float v553 = b19;	// L746
    float v554 = v552 * v553;	// L747
    float v555 = v19;	// L748
    float v556 = v555 + v554;	// L749
    v19 = v556;	// L750
    float v557 = a19;	// L751
    v541.write(v557); // v541[k21] = v557;	// L752
    float v558 = b19;	// L753
    v542.write(v558); // v542[k21] = v558;	// L754
  }
  float v559 = v19;	// L756
  v543[v544][v545] = v559;	// L757
}

void PE_kernel_K_0_1(
  hls::stream< float > &v560 /* v560[48] */,
  hls::stream< float > &v561 /* v561[48] */,
  hls::stream< float > &v562 /* v562[48] */,
  hls::stream< float > &v563 /* v563[48] */,
  float v564[4][4],
  int v565,
  int v566
) {	// L760
  #pragma HLS stream variable=v560 depth=5
  #pragma HLS stream variable=v561 depth=5
  #pragma HLS stream variable=v562 depth=5
  #pragma HLS stream variable=v563 depth=5
  #pragma HLS array_partition variable=v564 complete dim=1
  #pragma HLS array_partition variable=v564 complete dim=2

  float v20;	// L763
  v20 = 0.000000;	// L764
  l_S_k_0_k22: for (int k22 = 0; k22 < 48; k22++) {	// L765
    float v569 = v560.read(); // v560[k22];	// L766
    float a20;	// L767
    a20 = v569;	// L768
    float v571 = v561.read(); // v561[k22];	// L769
    float b20;	// L770
    b20 = v571;	// L771
    float v573 = a20;	// L772
    float v574 = b20;	// L773
    float v575 = v573 * v574;	// L774
    float v576 = v20;	// L775
    float v577 = v576 + v575;	// L776
    v20 = v577;	// L777
    float v578 = a20;	// L778
    v562.write(v578); // v562[k22] = v578;	// L779
    float v579 = b20;	// L780
    v563.write(v579); // v563[k22] = v579;	// L781
  }
  float v580 = v20;	// L783
  v564[v565][v566] = v580;	// L784
}

void PE_kernel_K_1_1(
  hls::stream< float > &v581 /* v581[48] */,
  hls::stream< float > &v582 /* v582[48] */,
  hls::stream< float > &v583 /* v583[48] */,
  hls::stream< float > &v584 /* v584[48] */,
  float v585[4][4],
  int v586,
  int v587
) {	// L787
  #pragma HLS stream variable=v581 depth=5
  #pragma HLS stream variable=v582 depth=5
  #pragma HLS stream variable=v583 depth=5
  #pragma HLS stream variable=v584 depth=5
  #pragma HLS array_partition variable=v585 complete dim=1
  #pragma HLS array_partition variable=v585 complete dim=2

  float v21;	// L790
  v21 = 0.000000;	// L791
  l_S_k_0_k23: for (int k23 = 0; k23 < 48; k23++) {	// L792
    float v590 = v581.read(); // v581[k23];	// L793
    float a21;	// L794
    a21 = v590;	// L795
    float v592 = v582.read(); // v582[k23];	// L796
    float b21;	// L797
    b21 = v592;	// L798
    float v594 = a21;	// L799
    float v595 = b21;	// L800
    float v596 = v594 * v595;	// L801
    float v597 = v21;	// L802
    float v598 = v597 + v596;	// L803
    v21 = v598;	// L804
    float v599 = a21;	// L805
    v583.write(v599); // v583[k23] = v599;	// L806
    float v600 = b21;	// L807
    v584.write(v600); // v584[k23] = v600;	// L808
  }
  float v601 = v21;	// L810
  v585[v586][v587] = v601;	// L811
}

void PE_kernel_K_2_1(
  hls::stream< float > &v602 /* v602[48] */,
  hls::stream< float > &v603 /* v603[48] */,
  hls::stream< float > &v604 /* v604[48] */,
  hls::stream< float > &v605 /* v605[48] */,
  float v606[4][4],
  int v607,
  int v608
) {	// L814
  #pragma HLS stream variable=v602 depth=5
  #pragma HLS stream variable=v603 depth=5
  #pragma HLS stream variable=v604 depth=5
  #pragma HLS stream variable=v605 depth=5
  #pragma HLS array_partition variable=v606 complete dim=1
  #pragma HLS array_partition variable=v606 complete dim=2

  float v22;	// L817
  v22 = 0.000000;	// L818
  l_S_k_0_k24: for (int k24 = 0; k24 < 48; k24++) {	// L819
    float v611 = v602.read(); // v602[k24];	// L820
    float a22;	// L821
    a22 = v611;	// L822
    float v613 = v603.read(); // v603[k24];	// L823
    float b22;	// L824
    b22 = v613;	// L825
    float v615 = a22;	// L826
    float v616 = b22;	// L827
    float v617 = v615 * v616;	// L828
    float v618 = v22;	// L829
    float v619 = v618 + v617;	// L830
    v22 = v619;	// L831
    float v620 = a22;	// L832
    v604.write(v620); // v604[k24] = v620;	// L833
    float v621 = b22;	// L834
    v605.write(v621); // v605[k24] = v621;	// L835
  }
  float v622 = v22;	// L837
  v606[v607][v608] = v622;	// L838
}

void PE_kernel_K_3_1(
  hls::stream< float > &v623 /* v623[48] */,
  hls::stream< float > &v624 /* v624[48] */,
  hls::stream< float > &v625 /* v625[48] */,
  hls::stream< float > &v626 /* v626[48] */,
  float v627[4][4],
  int v628,
  int v629
) {	// L841
  #pragma HLS stream variable=v623 depth=5
  #pragma HLS stream variable=v624 depth=5
  #pragma HLS stream variable=v625 depth=5
  #pragma HLS stream variable=v626 depth=5
  #pragma HLS array_partition variable=v627 complete dim=1
  #pragma HLS array_partition variable=v627 complete dim=2

  float v23;	// L844
  v23 = 0.000000;	// L845
  l_S_k_0_k25: for (int k25 = 0; k25 < 48; k25++) {	// L846
    float v632 = v623.read(); // v623[k25];	// L847
    float a23;	// L848
    a23 = v632;	// L849
    float v634 = v624.read(); // v624[k25];	// L850
    float b23;	// L851
    b23 = v634;	// L852
    float v636 = a23;	// L853
    float v637 = b23;	// L854
    float v638 = v636 * v637;	// L855
    float v639 = v23;	// L856
    float v640 = v639 + v638;	// L857
    v23 = v640;	// L858
    float v641 = a23;	// L859
    v625.write(v641); // v625[k25] = v641;	// L860
    float v642 = b23;	// L861
    v626.write(v642); // v626[k25] = v642;	// L862
  }
  float v643 = v23;	// L864
  v627[v628][v629] = v643;	// L865
}

void PE_kernel_K_0_2(
  hls::stream< float > &v644 /* v644[48] */,
  hls::stream< float > &v645 /* v645[48] */,
  hls::stream< float > &v646 /* v646[48] */,
  hls::stream< float > &v647 /* v647[48] */,
  float v648[4][4],
  int v649,
  int v650
) {	// L868
  #pragma HLS stream variable=v644 depth=5
  #pragma HLS stream variable=v645 depth=5
  #pragma HLS stream variable=v646 depth=5
  #pragma HLS stream variable=v647 depth=5
  #pragma HLS array_partition variable=v648 complete dim=1
  #pragma HLS array_partition variable=v648 complete dim=2

  float v24;	// L871
  v24 = 0.000000;	// L872
  l_S_k_0_k26: for (int k26 = 0; k26 < 48; k26++) {	// L873
    float v653 = v644.read(); // v644[k26];	// L874
    float a24;	// L875
    a24 = v653;	// L876
    float v655 = v645.read(); // v645[k26];	// L877
    float b24;	// L878
    b24 = v655;	// L879
    float v657 = a24;	// L880
    float v658 = b24;	// L881
    float v659 = v657 * v658;	// L882
    float v660 = v24;	// L883
    float v661 = v660 + v659;	// L884
    v24 = v661;	// L885
    float v662 = a24;	// L886
    v646.write(v662); // v646[k26] = v662;	// L887
    float v663 = b24;	// L888
    v647.write(v663); // v647[k26] = v663;	// L889
  }
  float v664 = v24;	// L891
  v648[v649][v650] = v664;	// L892
}

void PE_kernel_K_1_2(
  hls::stream< float > &v665 /* v665[48] */,
  hls::stream< float > &v666 /* v666[48] */,
  hls::stream< float > &v667 /* v667[48] */,
  hls::stream< float > &v668 /* v668[48] */,
  float v669[4][4],
  int v670,
  int v671
) {	// L895
  #pragma HLS stream variable=v665 depth=5
  #pragma HLS stream variable=v666 depth=5
  #pragma HLS stream variable=v667 depth=5
  #pragma HLS stream variable=v668 depth=5
  #pragma HLS array_partition variable=v669 complete dim=1
  #pragma HLS array_partition variable=v669 complete dim=2

  float v25;	// L898
  v25 = 0.000000;	// L899
  l_S_k_0_k27: for (int k27 = 0; k27 < 48; k27++) {	// L900
    float v674 = v665.read(); // v665[k27];	// L901
    float a25;	// L902
    a25 = v674;	// L903
    float v676 = v666.read(); // v666[k27];	// L904
    float b25;	// L905
    b25 = v676;	// L906
    float v678 = a25;	// L907
    float v679 = b25;	// L908
    float v680 = v678 * v679;	// L909
    float v681 = v25;	// L910
    float v682 = v681 + v680;	// L911
    v25 = v682;	// L912
    float v683 = a25;	// L913
    v667.write(v683); // v667[k27] = v683;	// L914
    float v684 = b25;	// L915
    v668.write(v684); // v668[k27] = v684;	// L916
  }
  float v685 = v25;	// L918
  v669[v670][v671] = v685;	// L919
}

void PE_kernel_K_2_2(
  hls::stream< float > &v686 /* v686[48] */,
  hls::stream< float > &v687 /* v687[48] */,
  hls::stream< float > &v688 /* v688[48] */,
  hls::stream< float > &v689 /* v689[48] */,
  float v690[4][4],
  int v691,
  int v692
) {	// L922
  #pragma HLS stream variable=v686 depth=5
  #pragma HLS stream variable=v687 depth=5
  #pragma HLS stream variable=v688 depth=5
  #pragma HLS stream variable=v689 depth=5
  #pragma HLS array_partition variable=v690 complete dim=1
  #pragma HLS array_partition variable=v690 complete dim=2

  float v26;	// L925
  v26 = 0.000000;	// L926
  l_S_k_0_k28: for (int k28 = 0; k28 < 48; k28++) {	// L927
    float v695 = v686.read(); // v686[k28];	// L928
    float a26;	// L929
    a26 = v695;	// L930
    float v697 = v687.read(); // v687[k28];	// L931
    float b26;	// L932
    b26 = v697;	// L933
    float v699 = a26;	// L934
    float v700 = b26;	// L935
    float v701 = v699 * v700;	// L936
    float v702 = v26;	// L937
    float v703 = v702 + v701;	// L938
    v26 = v703;	// L939
    float v704 = a26;	// L940
    v688.write(v704); // v688[k28] = v704;	// L941
    float v705 = b26;	// L942
    v689.write(v705); // v689[k28] = v705;	// L943
  }
  float v706 = v26;	// L945
  v690[v691][v692] = v706;	// L946
}

void PE_kernel_K_3_2(
  hls::stream< float > &v707 /* v707[48] */,
  hls::stream< float > &v708 /* v708[48] */,
  hls::stream< float > &v709 /* v709[48] */,
  hls::stream< float > &v710 /* v710[48] */,
  float v711[4][4],
  int v712,
  int v713
) {	// L949
  #pragma HLS stream variable=v707 depth=5
  #pragma HLS stream variable=v708 depth=5
  #pragma HLS stream variable=v709 depth=5
  #pragma HLS stream variable=v710 depth=5
  #pragma HLS array_partition variable=v711 complete dim=1
  #pragma HLS array_partition variable=v711 complete dim=2

  float v27;	// L952
  v27 = 0.000000;	// L953
  l_S_k_0_k29: for (int k29 = 0; k29 < 48; k29++) {	// L954
    float v716 = v707.read(); // v707[k29];	// L955
    float a27;	// L956
    a27 = v716;	// L957
    float v718 = v708.read(); // v708[k29];	// L958
    float b27;	// L959
    b27 = v718;	// L960
    float v720 = a27;	// L961
    float v721 = b27;	// L962
    float v722 = v720 * v721;	// L963
    float v723 = v27;	// L964
    float v724 = v723 + v722;	// L965
    v27 = v724;	// L966
    float v725 = a27;	// L967
    v709.write(v725); // v709[k29] = v725;	// L968
    float v726 = b27;	// L969
    v710.write(v726); // v710[k29] = v726;	// L970
  }
  float v727 = v27;	// L972
  v711[v712][v713] = v727;	// L973
}

void PE_kernel_K_0_3(
  hls::stream< float > &v728 /* v728[48] */,
  hls::stream< float > &v729 /* v729[48] */,
  hls::stream< float > &v730 /* v730[48] */,
  hls::stream< float > &v731 /* v731[48] */,
  float v732[4][4],
  int v733,
  int v734
) {	// L976
  #pragma HLS stream variable=v728 depth=5
  #pragma HLS stream variable=v729 depth=5
  #pragma HLS stream variable=v730 depth=5
  #pragma HLS stream variable=v731 depth=5
  #pragma HLS array_partition variable=v732 complete dim=1
  #pragma HLS array_partition variable=v732 complete dim=2

  float v28;	// L979
  v28 = 0.000000;	// L980
  l_S_k_0_k30: for (int k30 = 0; k30 < 48; k30++) {	// L981
    float v737 = v728.read(); // v728[k30];	// L982
    float a28;	// L983
    a28 = v737;	// L984
    float v739 = v729.read(); // v729[k30];	// L985
    float b28;	// L986
    b28 = v739;	// L987
    float v741 = a28;	// L988
    float v742 = b28;	// L989
    float v743 = v741 * v742;	// L990
    float v744 = v28;	// L991
    float v745 = v744 + v743;	// L992
    v28 = v745;	// L993
    float v746 = a28;	// L994
    v730.write(v746); // v730[k30] = v746;	// L995
    float v747 = b28;	// L996
    v731.write(v747); // v731[k30] = v747;	// L997
  }
  float v748 = v28;	// L999
  v732[v733][v734] = v748;	// L1000
}

void PE_kernel_K_1_3(
  hls::stream< float > &v749 /* v749[48] */,
  hls::stream< float > &v750 /* v750[48] */,
  hls::stream< float > &v751 /* v751[48] */,
  hls::stream< float > &v752 /* v752[48] */,
  float v753[4][4],
  int v754,
  int v755
) {	// L1003
  #pragma HLS stream variable=v749 depth=5
  #pragma HLS stream variable=v750 depth=5
  #pragma HLS stream variable=v751 depth=5
  #pragma HLS stream variable=v752 depth=5
  #pragma HLS array_partition variable=v753 complete dim=1
  #pragma HLS array_partition variable=v753 complete dim=2

  float v29;	// L1006
  v29 = 0.000000;	// L1007
  l_S_k_0_k31: for (int k31 = 0; k31 < 48; k31++) {	// L1008
    float v758 = v749.read(); // v749[k31];	// L1009
    float a29;	// L1010
    a29 = v758;	// L1011
    float v760 = v750.read(); // v750[k31];	// L1012
    float b29;	// L1013
    b29 = v760;	// L1014
    float v762 = a29;	// L1015
    float v763 = b29;	// L1016
    float v764 = v762 * v763;	// L1017
    float v765 = v29;	// L1018
    float v766 = v765 + v764;	// L1019
    v29 = v766;	// L1020
    float v767 = a29;	// L1021
    v751.write(v767); // v751[k31] = v767;	// L1022
    float v768 = b29;	// L1023
    v752.write(v768); // v752[k31] = v768;	// L1024
  }
  float v769 = v29;	// L1026
  v753[v754][v755] = v769;	// L1027
}

void PE_kernel_K_2_3(
  hls::stream< float > &v770 /* v770[48] */,
  hls::stream< float > &v771 /* v771[48] */,
  hls::stream< float > &v772 /* v772[48] */,
  hls::stream< float > &v773 /* v773[48] */,
  float v774[4][4],
  int v775,
  int v776
) {	// L1030
  #pragma HLS stream variable=v770 depth=5
  #pragma HLS stream variable=v771 depth=5
  #pragma HLS stream variable=v772 depth=5
  #pragma HLS stream variable=v773 depth=5
  #pragma HLS array_partition variable=v774 complete dim=1
  #pragma HLS array_partition variable=v774 complete dim=2

  float v30;	// L1033
  v30 = 0.000000;	// L1034
  l_S_k_0_k32: for (int k32 = 0; k32 < 48; k32++) {	// L1035
    float v779 = v770.read(); // v770[k32];	// L1036
    float a30;	// L1037
    a30 = v779;	// L1038
    float v781 = v771.read(); // v771[k32];	// L1039
    float b30;	// L1040
    b30 = v781;	// L1041
    float v783 = a30;	// L1042
    float v784 = b30;	// L1043
    float v785 = v783 * v784;	// L1044
    float v786 = v30;	// L1045
    float v787 = v786 + v785;	// L1046
    v30 = v787;	// L1047
    float v788 = a30;	// L1048
    v772.write(v788); // v772[k32] = v788;	// L1049
    float v789 = b30;	// L1050
    v773.write(v789); // v773[k32] = v789;	// L1051
  }
  float v790 = v30;	// L1053
  v774[v775][v776] = v790;	// L1054
}

void PE_kernel_K_3_3(
  hls::stream< float > &v791 /* v791[48] */,
  hls::stream< float > &v792 /* v792[48] */,
  hls::stream< float > &v793 /* v793[48] */,
  hls::stream< float > &v794 /* v794[48] */,
  float v795[4][4],
  int v796,
  int v797
) {	// L1057
  #pragma HLS stream variable=v791 depth=5
  #pragma HLS stream variable=v792 depth=5
  #pragma HLS stream variable=v793 depth=5
  #pragma HLS stream variable=v794 depth=5
  #pragma HLS array_partition variable=v795 complete dim=1
  #pragma HLS array_partition variable=v795 complete dim=2

  float v31;	// L1060
  v31 = 0.000000;	// L1061
  l_S_k_0_k33: for (int k33 = 0; k33 < 48; k33++) {	// L1062
    float v800 = v791.read(); // v791[k33];	// L1063
    float a31;	// L1064
    a31 = v800;	// L1065
    float v802 = v792.read(); // v792[k33];	// L1066
    float b31;	// L1067
    b31 = v802;	// L1068
    float v804 = a31;	// L1069
    float v805 = b31;	// L1070
    float v806 = v804 * v805;	// L1071
    float v807 = v31;	// L1072
    float v808 = v807 + v806;	// L1073
    v31 = v808;	// L1074
    float v809 = a31;	// L1075
    v793.write(v809); // v793[k33] = v809;	// L1076
    float v810 = b31;	// L1077
    v794.write(v810); // v794[k33] = v810;	// L1078
  }
  float v811 = v31;	// L1080
  v795[v796][v797] = v811;	// L1081
}

void systolic_tile_K(
  float v812[4][48],
  float v813[48][4],
  float v814[4][4]
) {	// L1084
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v812 complete dim=1

  #pragma HLS array_partition variable=v813 complete dim=2

  #pragma HLS array_partition variable=v814 complete dim=1
  #pragma HLS array_partition variable=v814 complete dim=2

  hls::stream< float > A_fifo1[4][5] /* A_fifo1[4][5][48] */;	// L1085
  #pragma HLS stream variable=A_fifo1 depth=5
  hls::stream< float > B_fifo1[4][5] /* B_fifo1[4][5][48] */;	// L1086
  #pragma HLS stream variable=B_fifo1 depth=5
  float A_drain1[4];	// L1087
  float B_drain1[4];	// L1088
  l_data_load_k34: for (int k34 = 0; k34 < 48; k34++) {	// L1089
    l_S_m_0_m2: for (int m2 = 0; m2 < 4; m2++) {	// L1090
      float v821 = v812[m2][k34];	// L1091
      A_fifo1[m2][0].write(v821); // A_fifo1[m2][0][k34] = v821;	// L1092
    }
    l_S_n_1_n2: for (int n2 = 0; n2 < 4; n2++) {	// L1094
      float v823 = v813[k34][n2];	// L1095
      B_fifo1[n2][0].write(v823); // B_fifo1[n2][0][k34] = v823;	// L1096
    }
  }
  hls::stream< float > &v824 /* v824[48] */ = A_fifo1[0][0];	// L1100
  hls::stream< float > &v825 /* v825[48] */ = B_fifo1[0][0];	// L1101
  hls::stream< float > &v826 /* v826[48] */ = A_fifo1[0][1];	// L1107
  hls::stream< float > &v827 /* v827[48] */ = B_fifo1[0][1];	// L1108
  PE_kernel_K_0_0(v824, v825, v826, v827, v814, 0, 0);	// L1109
  hls::stream< float > &v828 /* v828[48] */ = A_fifo1[0][1];	// L1111
  hls::stream< float > &v829 /* v829[48] */ = B_fifo1[1][0];	// L1112
  hls::stream< float > &v830 /* v830[48] */ = A_fifo1[0][2];	// L1116
  hls::stream< float > &v831 /* v831[48] */ = B_fifo1[1][1];	// L1117
  PE_kernel_K_1_0(v828, v829, v830, v831, v814, 0, 1);	// L1118
  hls::stream< float > &v832 /* v832[48] */ = A_fifo1[0][2];	// L1120
  hls::stream< float > &v833 /* v833[48] */ = B_fifo1[2][0];	// L1121
  hls::stream< float > &v834 /* v834[48] */ = A_fifo1[0][3];	// L1125
  hls::stream< float > &v835 /* v835[48] */ = B_fifo1[2][1];	// L1126
  PE_kernel_K_2_0(v832, v833, v834, v835, v814, 0, 2);	// L1127
  hls::stream< float > &v836 /* v836[48] */ = A_fifo1[0][3];	// L1129
  hls::stream< float > &v837 /* v837[48] */ = B_fifo1[3][0];	// L1130
  hls::stream< float > &v838 /* v838[48] */ = A_fifo1[0][4];	// L1134
  hls::stream< float > &v839 /* v839[48] */ = B_fifo1[3][1];	// L1135
  PE_kernel_K_3_0(v836, v837, v838, v839, v814, 0, 3);	// L1136
  hls::stream< float > &v840 /* v840[48] */ = A_fifo1[1][0];	// L1137
  hls::stream< float > &v841 /* v841[48] */ = B_fifo1[0][1];	// L1138
  hls::stream< float > &v842 /* v842[48] */ = A_fifo1[1][1];	// L1139
  hls::stream< float > &v843 /* v843[48] */ = B_fifo1[0][2];	// L1140
  PE_kernel_K_0_1(v840, v841, v842, v843, v814, 1, 0);	// L1141
  hls::stream< float > &v844 /* v844[48] */ = A_fifo1[1][1];	// L1142
  hls::stream< float > &v845 /* v845[48] */ = B_fifo1[1][1];	// L1143
  hls::stream< float > &v846 /* v846[48] */ = A_fifo1[1][2];	// L1144
  hls::stream< float > &v847 /* v847[48] */ = B_fifo1[1][2];	// L1145
  PE_kernel_K_1_1(v844, v845, v846, v847, v814, 1, 1);	// L1146
  hls::stream< float > &v848 /* v848[48] */ = A_fifo1[1][2];	// L1147
  hls::stream< float > &v849 /* v849[48] */ = B_fifo1[2][1];	// L1148
  hls::stream< float > &v850 /* v850[48] */ = A_fifo1[1][3];	// L1149
  hls::stream< float > &v851 /* v851[48] */ = B_fifo1[2][2];	// L1150
  PE_kernel_K_2_1(v848, v849, v850, v851, v814, 1, 2);	// L1151
  hls::stream< float > &v852 /* v852[48] */ = A_fifo1[1][3];	// L1152
  hls::stream< float > &v853 /* v853[48] */ = B_fifo1[3][1];	// L1153
  hls::stream< float > &v854 /* v854[48] */ = A_fifo1[1][4];	// L1154
  hls::stream< float > &v855 /* v855[48] */ = B_fifo1[3][2];	// L1155
  PE_kernel_K_3_1(v852, v853, v854, v855, v814, 1, 3);	// L1156
  hls::stream< float > &v856 /* v856[48] */ = A_fifo1[2][0];	// L1157
  hls::stream< float > &v857 /* v857[48] */ = B_fifo1[0][2];	// L1158
  hls::stream< float > &v858 /* v858[48] */ = A_fifo1[2][1];	// L1159
  hls::stream< float > &v859 /* v859[48] */ = B_fifo1[0][3];	// L1160
  PE_kernel_K_0_2(v856, v857, v858, v859, v814, 2, 0);	// L1161
  hls::stream< float > &v860 /* v860[48] */ = A_fifo1[2][1];	// L1162
  hls::stream< float > &v861 /* v861[48] */ = B_fifo1[1][2];	// L1163
  hls::stream< float > &v862 /* v862[48] */ = A_fifo1[2][2];	// L1164
  hls::stream< float > &v863 /* v863[48] */ = B_fifo1[1][3];	// L1165
  PE_kernel_K_1_2(v860, v861, v862, v863, v814, 2, 1);	// L1166
  hls::stream< float > &v864 /* v864[48] */ = A_fifo1[2][2];	// L1167
  hls::stream< float > &v865 /* v865[48] */ = B_fifo1[2][2];	// L1168
  hls::stream< float > &v866 /* v866[48] */ = A_fifo1[2][3];	// L1169
  hls::stream< float > &v867 /* v867[48] */ = B_fifo1[2][3];	// L1170
  PE_kernel_K_2_2(v864, v865, v866, v867, v814, 2, 2);	// L1171
  hls::stream< float > &v868 /* v868[48] */ = A_fifo1[2][3];	// L1172
  hls::stream< float > &v869 /* v869[48] */ = B_fifo1[3][2];	// L1173
  hls::stream< float > &v870 /* v870[48] */ = A_fifo1[2][4];	// L1174
  hls::stream< float > &v871 /* v871[48] */ = B_fifo1[3][3];	// L1175
  PE_kernel_K_3_2(v868, v869, v870, v871, v814, 2, 3);	// L1176
  hls::stream< float > &v872 /* v872[48] */ = A_fifo1[3][0];	// L1177
  hls::stream< float > &v873 /* v873[48] */ = B_fifo1[0][3];	// L1178
  hls::stream< float > &v874 /* v874[48] */ = A_fifo1[3][1];	// L1179
  hls::stream< float > &v875 /* v875[48] */ = B_fifo1[0][4];	// L1180
  PE_kernel_K_0_3(v872, v873, v874, v875, v814, 3, 0);	// L1181
  hls::stream< float > &v876 /* v876[48] */ = A_fifo1[3][1];	// L1182
  hls::stream< float > &v877 /* v877[48] */ = B_fifo1[1][3];	// L1183
  hls::stream< float > &v878 /* v878[48] */ = A_fifo1[3][2];	// L1184
  hls::stream< float > &v879 /* v879[48] */ = B_fifo1[1][4];	// L1185
  PE_kernel_K_1_3(v876, v877, v878, v879, v814, 3, 1);	// L1186
  hls::stream< float > &v880 /* v880[48] */ = A_fifo1[3][2];	// L1187
  hls::stream< float > &v881 /* v881[48] */ = B_fifo1[2][3];	// L1188
  hls::stream< float > &v882 /* v882[48] */ = A_fifo1[3][3];	// L1189
  hls::stream< float > &v883 /* v883[48] */ = B_fifo1[2][4];	// L1190
  PE_kernel_K_2_3(v880, v881, v882, v883, v814, 3, 2);	// L1191
  hls::stream< float > &v884 /* v884[48] */ = A_fifo1[3][3];	// L1192
  hls::stream< float > &v885 /* v885[48] */ = B_fifo1[3][3];	// L1193
  hls::stream< float > &v886 /* v886[48] */ = A_fifo1[3][4];	// L1194
  hls::stream< float > &v887 /* v887[48] */ = B_fifo1[3][4];	// L1195
  PE_kernel_K_3_3(v884, v885, v886, v887, v814, 3, 3);	// L1196
  l_data_drain_k35: for (int k35 = 0; k35 < 48; k35++) {	// L1197
    l_S_m_4_m3: for (int m3 = 0; m3 < 4; m3++) {	// L1198
      float v890 = A_fifo1[m3][4].read(); // A_fifo1[m3][4][k35];	// L1199
      A_drain1[m3] = v890;	// L1200
    }
    l_S_n_5_n3: for (int n3 = 0; n3 < 4; n3++) {	// L1202
      float v892 = B_fifo1[n3][4].read(); // B_fifo1[n3][4][k35];	// L1203
      B_drain1[n3] = v892;	// L1204
    }
  }
}

void systolic_K(
  float v893[32][48],
  float *Wk,
  float v895[32][48]
) {	// L1209
  float local_A1[4][48];	// L1210
  #pragma HLS array_partition variable=local_A1 complete dim=1

  float local_B1[48][4];	// L1211
  #pragma HLS array_partition variable=local_B1 complete dim=2

  float local_C1[4][4];	// L1212
  #pragma HLS array_partition variable=local_C1 complete dim=1
  #pragma HLS array_partition variable=local_C1 complete dim=2

  l_outer_tile_mi1: for (int mi1 = 0; mi1 < 8; mi1++) {	// L1213
    l_ni1: for (int ni1 = 0; ni1 < 12; ni1++) {	// L1214
    #pragma HLS dataflow
      l_load_A_tile_ak1: for (int ak1 = 0; ak1 < 48; ak1++) {	// L1215
        l_ai1: for (int ai1 = 0; ai1 < 4; ai1++) {	// L1216
        #pragma HLS pipeline II=1
          ap_int<33> v903 = ni1;	// L1217
          bool v904 = v903 == 0;	// L1220
          if (v904) {	// L1221
            float v905 = v893[((mi1 * 4) + ai1)][ak1];	// L1222
            local_A1[ai1][ak1] = v905;	// L1223
          }
        }
      }
      l_load_B_tile_bk1: for (int bk1 = 0; bk1 < 48; bk1++) {	// L1227
        l_bj1: for (int bj1 = 0; bj1 < 4; bj1++) {	// L1228
        #pragma HLS pipeline II=1
          float v908 = Wk[bk1*48+((ni1 * 4) + bj1)];	// L1229
          // float v908 = v894[bk1][((ni1 * 4) + bj1)];	// L1229
          local_B1[bk1][bj1] = v908;	// L1230
        }
      }
      systolic_tile_K(local_A1, local_B1, local_C1);	// L1233
      l_store_C_tile_sj1: for (int sj1 = 0; sj1 < 4; sj1++) {	// L1234
        l_si1: for (int si1 = 0; si1 < 4; si1++) {	// L1235
        #pragma HLS pipeline II=1
          float v911 = local_C1[si1][sj1];	// L1236
          v895[((mi1 * 4) + si1)][((ni1 * 4) + sj1)] = v911;	// L1237
        }
      }
    }
  }
}

void PE_kernel_V_0_0(
  hls::stream< float > &v912 /* v912[48] */,
  hls::stream< float > &v913 /* v913[48] */,
  hls::stream< float > &v914 /* v914[48] */,
  hls::stream< float > &v915 /* v915[48] */,
  float v916[4][4],
  int v917,
  int v918
) {	// L1244
  #pragma HLS stream variable=v912 depth=5
  #pragma HLS stream variable=v913 depth=5
  #pragma HLS stream variable=v914 depth=5
  #pragma HLS stream variable=v915 depth=5
  #pragma HLS array_partition variable=v916 complete dim=1
  #pragma HLS array_partition variable=v916 complete dim=2

  float v32;	// L1247
  v32 = 0.000000;	// L1248
  l_S_k_0_k36: for (int k36 = 0; k36 < 48; k36++) {	// L1249
    float v921 = v912.read(); // v912[k36];	// L1250
    float a32;	// L1251
    a32 = v921;	// L1252
    float v923 = v913.read(); // v913[k36];	// L1253
    float b32;	// L1254
    b32 = v923;	// L1255
    float v925 = a32;	// L1256
    float v926 = b32;	// L1257
    float v927 = v925 * v926;	// L1258
    float v928 = v32;	// L1259
    float v929 = v928 + v927;	// L1260
    v32 = v929;	// L1261
    float v930 = a32;	// L1262
    v914.write(v930); // v914[k36] = v930;	// L1263
    float v931 = b32;	// L1264
    v915.write(v931); // v915[k36] = v931;	// L1265
  }
  float v932 = v32;	// L1267
  v916[v917][v918] = v932;	// L1268
}

void PE_kernel_V_1_0(
  hls::stream< float > &v933 /* v933[48] */,
  hls::stream< float > &v934 /* v934[48] */,
  hls::stream< float > &v935 /* v935[48] */,
  hls::stream< float > &v936 /* v936[48] */,
  float v937[4][4],
  int v938,
  int v939
) {	// L1271
  #pragma HLS stream variable=v933 depth=5
  #pragma HLS stream variable=v934 depth=5
  #pragma HLS stream variable=v935 depth=5
  #pragma HLS stream variable=v936 depth=5
  #pragma HLS array_partition variable=v937 complete dim=1
  #pragma HLS array_partition variable=v937 complete dim=2

  float v33;	// L1274
  v33 = 0.000000;	// L1275
  l_S_k_0_k37: for (int k37 = 0; k37 < 48; k37++) {	// L1276
    float v942 = v933.read(); // v933[k37];	// L1277
    float a33;	// L1278
    a33 = v942;	// L1279
    float v944 = v934.read(); // v934[k37];	// L1280
    float b33;	// L1281
    b33 = v944;	// L1282
    float v946 = a33;	// L1283
    float v947 = b33;	// L1284
    float v948 = v946 * v947;	// L1285
    float v949 = v33;	// L1286
    float v950 = v949 + v948;	// L1287
    v33 = v950;	// L1288
    float v951 = a33;	// L1289
    v935.write(v951); // v935[k37] = v951;	// L1290
    float v952 = b33;	// L1291
    v936.write(v952); // v936[k37] = v952;	// L1292
  }
  float v953 = v33;	// L1294
  v937[v938][v939] = v953;	// L1295
}

void PE_kernel_V_2_0(
  hls::stream< float > &v954 /* v954[48] */,
  hls::stream< float > &v955 /* v955[48] */,
  hls::stream< float > &v956 /* v956[48] */,
  hls::stream< float > &v957 /* v957[48] */,
  float v958[4][4],
  int v959,
  int v960
) {	// L1298
  #pragma HLS stream variable=v954 depth=5
  #pragma HLS stream variable=v955 depth=5
  #pragma HLS stream variable=v956 depth=5
  #pragma HLS stream variable=v957 depth=5
  #pragma HLS array_partition variable=v958 complete dim=1
  #pragma HLS array_partition variable=v958 complete dim=2

  float v34;	// L1301
  v34 = 0.000000;	// L1302
  l_S_k_0_k38: for (int k38 = 0; k38 < 48; k38++) {	// L1303
    float v963 = v954.read(); // v954[k38];	// L1304
    float a34;	// L1305
    a34 = v963;	// L1306
    float v965 = v955.read(); // v955[k38];	// L1307
    float b34;	// L1308
    b34 = v965;	// L1309
    float v967 = a34;	// L1310
    float v968 = b34;	// L1311
    float v969 = v967 * v968;	// L1312
    float v970 = v34;	// L1313
    float v971 = v970 + v969;	// L1314
    v34 = v971;	// L1315
    float v972 = a34;	// L1316
    v956.write(v972); // v956[k38] = v972;	// L1317
    float v973 = b34;	// L1318
    v957.write(v973); // v957[k38] = v973;	// L1319
  }
  float v974 = v34;	// L1321
  v958[v959][v960] = v974;	// L1322
}

void PE_kernel_V_3_0(
  hls::stream< float > &v975 /* v975[48] */,
  hls::stream< float > &v976 /* v976[48] */,
  hls::stream< float > &v977 /* v977[48] */,
  hls::stream< float > &v978 /* v978[48] */,
  float v979[4][4],
  int v980,
  int v981
) {	// L1325
  #pragma HLS stream variable=v975 depth=5
  #pragma HLS stream variable=v976 depth=5
  #pragma HLS stream variable=v977 depth=5
  #pragma HLS stream variable=v978 depth=5
  #pragma HLS array_partition variable=v979 complete dim=1
  #pragma HLS array_partition variable=v979 complete dim=2

  float v35;	// L1328
  v35 = 0.000000;	// L1329
  l_S_k_0_k39: for (int k39 = 0; k39 < 48; k39++) {	// L1330
    float v984 = v975.read(); // v975[k39];	// L1331
    float a35;	// L1332
    a35 = v984;	// L1333
    float v986 = v976.read(); // v976[k39];	// L1334
    float b35;	// L1335
    b35 = v986;	// L1336
    float v988 = a35;	// L1337
    float v989 = b35;	// L1338
    float v990 = v988 * v989;	// L1339
    float v991 = v35;	// L1340
    float v992 = v991 + v990;	// L1341
    v35 = v992;	// L1342
    float v993 = a35;	// L1343
    v977.write(v993); // v977[k39] = v993;	// L1344
    float v994 = b35;	// L1345
    v978.write(v994); // v978[k39] = v994;	// L1346
  }
  float v995 = v35;	// L1348
  v979[v980][v981] = v995;	// L1349
}

void PE_kernel_V_0_1(
  hls::stream< float > &v996 /* v996[48] */,
  hls::stream< float > &v997 /* v997[48] */,
  hls::stream< float > &v998 /* v998[48] */,
  hls::stream< float > &v999 /* v999[48] */,
  float v1000[4][4],
  int v1001,
  int v1002
) {	// L1352
  #pragma HLS stream variable=v996 depth=5
  #pragma HLS stream variable=v997 depth=5
  #pragma HLS stream variable=v998 depth=5
  #pragma HLS stream variable=v999 depth=5
  #pragma HLS array_partition variable=v1000 complete dim=1
  #pragma HLS array_partition variable=v1000 complete dim=2

  float v36;	// L1355
  v36 = 0.000000;	// L1356
  l_S_k_0_k40: for (int k40 = 0; k40 < 48; k40++) {	// L1357
    float v1005 = v996.read(); // v996[k40];	// L1358
    float a36;	// L1359
    a36 = v1005;	// L1360
    float v1007 = v997.read(); // v997[k40];	// L1361
    float b36;	// L1362
    b36 = v1007;	// L1363
    float v1009 = a36;	// L1364
    float v1010 = b36;	// L1365
    float v1011 = v1009 * v1010;	// L1366
    float v1012 = v36;	// L1367
    float v1013 = v1012 + v1011;	// L1368
    v36 = v1013;	// L1369
    float v1014 = a36;	// L1370
    v998.write(v1014); // v998[k40] = v1014;	// L1371
    float v1015 = b36;	// L1372
    v999.write(v1015); // v999[k40] = v1015;	// L1373
  }
  float v1016 = v36;	// L1375
  v1000[v1001][v1002] = v1016;	// L1376
}

void PE_kernel_V_1_1(
  hls::stream< float > &v1017 /* v1017[48] */,
  hls::stream< float > &v1018 /* v1018[48] */,
  hls::stream< float > &v1019 /* v1019[48] */,
  hls::stream< float > &v1020 /* v1020[48] */,
  float v1021[4][4],
  int v1022,
  int v1023
) {	// L1379
  #pragma HLS stream variable=v1017 depth=5
  #pragma HLS stream variable=v1018 depth=5
  #pragma HLS stream variable=v1019 depth=5
  #pragma HLS stream variable=v1020 depth=5
  #pragma HLS array_partition variable=v1021 complete dim=1
  #pragma HLS array_partition variable=v1021 complete dim=2

  float v37;	// L1382
  v37 = 0.000000;	// L1383
  l_S_k_0_k41: for (int k41 = 0; k41 < 48; k41++) {	// L1384
    float v1026 = v1017.read(); // v1017[k41];	// L1385
    float a37;	// L1386
    a37 = v1026;	// L1387
    float v1028 = v1018.read(); // v1018[k41];	// L1388
    float b37;	// L1389
    b37 = v1028;	// L1390
    float v1030 = a37;	// L1391
    float v1031 = b37;	// L1392
    float v1032 = v1030 * v1031;	// L1393
    float v1033 = v37;	// L1394
    float v1034 = v1033 + v1032;	// L1395
    v37 = v1034;	// L1396
    float v1035 = a37;	// L1397
    v1019.write(v1035); // v1019[k41] = v1035;	// L1398
    float v1036 = b37;	// L1399
    v1020.write(v1036); // v1020[k41] = v1036;	// L1400
  }
  float v1037 = v37;	// L1402
  v1021[v1022][v1023] = v1037;	// L1403
}

void PE_kernel_V_2_1(
  hls::stream< float > &v1038 /* v1038[48] */,
  hls::stream< float > &v1039 /* v1039[48] */,
  hls::stream< float > &v1040 /* v1040[48] */,
  hls::stream< float > &v1041 /* v1041[48] */,
  float v1042[4][4],
  int v1043,
  int v1044
) {	// L1406
  #pragma HLS stream variable=v1038 depth=5
  #pragma HLS stream variable=v1039 depth=5
  #pragma HLS stream variable=v1040 depth=5
  #pragma HLS stream variable=v1041 depth=5
  #pragma HLS array_partition variable=v1042 complete dim=1
  #pragma HLS array_partition variable=v1042 complete dim=2

  float v38;	// L1409
  v38 = 0.000000;	// L1410
  l_S_k_0_k42: for (int k42 = 0; k42 < 48; k42++) {	// L1411
    float v1047 = v1038.read(); // v1038[k42];	// L1412
    float a38;	// L1413
    a38 = v1047;	// L1414
    float v1049 = v1039.read(); // v1039[k42];	// L1415
    float b38;	// L1416
    b38 = v1049;	// L1417
    float v1051 = a38;	// L1418
    float v1052 = b38;	// L1419
    float v1053 = v1051 * v1052;	// L1420
    float v1054 = v38;	// L1421
    float v1055 = v1054 + v1053;	// L1422
    v38 = v1055;	// L1423
    float v1056 = a38;	// L1424
    v1040.write(v1056); // v1040[k42] = v1056;	// L1425
    float v1057 = b38;	// L1426
    v1041.write(v1057); // v1041[k42] = v1057;	// L1427
  }
  float v1058 = v38;	// L1429
  v1042[v1043][v1044] = v1058;	// L1430
}

void PE_kernel_V_3_1(
  hls::stream< float > &v1059 /* v1059[48] */,
  hls::stream< float > &v1060 /* v1060[48] */,
  hls::stream< float > &v1061 /* v1061[48] */,
  hls::stream< float > &v1062 /* v1062[48] */,
  float v1063[4][4],
  int v1064,
  int v1065
) {	// L1433
  #pragma HLS stream variable=v1059 depth=5
  #pragma HLS stream variable=v1060 depth=5
  #pragma HLS stream variable=v1061 depth=5
  #pragma HLS stream variable=v1062 depth=5
  #pragma HLS array_partition variable=v1063 complete dim=1
  #pragma HLS array_partition variable=v1063 complete dim=2

  float v39;	// L1436
  v39 = 0.000000;	// L1437
  l_S_k_0_k43: for (int k43 = 0; k43 < 48; k43++) {	// L1438
    float v1068 = v1059.read(); // v1059[k43];	// L1439
    float a39;	// L1440
    a39 = v1068;	// L1441
    float v1070 = v1060.read(); // v1060[k43];	// L1442
    float b39;	// L1443
    b39 = v1070;	// L1444
    float v1072 = a39;	// L1445
    float v1073 = b39;	// L1446
    float v1074 = v1072 * v1073;	// L1447
    float v1075 = v39;	// L1448
    float v1076 = v1075 + v1074;	// L1449
    v39 = v1076;	// L1450
    float v1077 = a39;	// L1451
    v1061.write(v1077); // v1061[k43] = v1077;	// L1452
    float v1078 = b39;	// L1453
    v1062.write(v1078); // v1062[k43] = v1078;	// L1454
  }
  float v1079 = v39;	// L1456
  v1063[v1064][v1065] = v1079;	// L1457
}

void PE_kernel_V_0_2(
  hls::stream< float > &v1080 /* v1080[48] */,
  hls::stream< float > &v1081 /* v1081[48] */,
  hls::stream< float > &v1082 /* v1082[48] */,
  hls::stream< float > &v1083 /* v1083[48] */,
  float v1084[4][4],
  int v1085,
  int v1086
) {	// L1460
  #pragma HLS stream variable=v1080 depth=5
  #pragma HLS stream variable=v1081 depth=5
  #pragma HLS stream variable=v1082 depth=5
  #pragma HLS stream variable=v1083 depth=5
  #pragma HLS array_partition variable=v1084 complete dim=1
  #pragma HLS array_partition variable=v1084 complete dim=2

  float v40;	// L1463
  v40 = 0.000000;	// L1464
  l_S_k_0_k44: for (int k44 = 0; k44 < 48; k44++) {	// L1465
    float v1089 = v1080.read(); // v1080[k44];	// L1466
    float a40;	// L1467
    a40 = v1089;	// L1468
    float v1091 = v1081.read(); // v1081[k44];	// L1469
    float b40;	// L1470
    b40 = v1091;	// L1471
    float v1093 = a40;	// L1472
    float v1094 = b40;	// L1473
    float v1095 = v1093 * v1094;	// L1474
    float v1096 = v40;	// L1475
    float v1097 = v1096 + v1095;	// L1476
    v40 = v1097;	// L1477
    float v1098 = a40;	// L1478
    v1082.write(v1098); // v1082[k44] = v1098;	// L1479
    float v1099 = b40;	// L1480
    v1083.write(v1099); // v1083[k44] = v1099;	// L1481
  }
  float v1100 = v40;	// L1483
  v1084[v1085][v1086] = v1100;	// L1484
}

void PE_kernel_V_1_2(
  hls::stream< float > &v1101 /* v1101[48] */,
  hls::stream< float > &v1102 /* v1102[48] */,
  hls::stream< float > &v1103 /* v1103[48] */,
  hls::stream< float > &v1104 /* v1104[48] */,
  float v1105[4][4],
  int v1106,
  int v1107
) {	// L1487
  #pragma HLS stream variable=v1101 depth=5
  #pragma HLS stream variable=v1102 depth=5
  #pragma HLS stream variable=v1103 depth=5
  #pragma HLS stream variable=v1104 depth=5
  #pragma HLS array_partition variable=v1105 complete dim=1
  #pragma HLS array_partition variable=v1105 complete dim=2

  float v41;	// L1490
  v41 = 0.000000;	// L1491
  l_S_k_0_k45: for (int k45 = 0; k45 < 48; k45++) {	// L1492
    float v1110 = v1101.read(); // v1101[k45];	// L1493
    float a41;	// L1494
    a41 = v1110;	// L1495
    float v1112 = v1102.read(); // v1102[k45];	// L1496
    float b41;	// L1497
    b41 = v1112;	// L1498
    float v1114 = a41;	// L1499
    float v1115 = b41;	// L1500
    float v1116 = v1114 * v1115;	// L1501
    float v1117 = v41;	// L1502
    float v1118 = v1117 + v1116;	// L1503
    v41 = v1118;	// L1504
    float v1119 = a41;	// L1505
    v1103.write(v1119); // v1103[k45] = v1119;	// L1506
    float v1120 = b41;	// L1507
    v1104.write(v1120); // v1104[k45] = v1120;	// L1508
  }
  float v1121 = v41;	// L1510
  v1105[v1106][v1107] = v1121;	// L1511
}

void PE_kernel_V_2_2(
  hls::stream< float > &v1122 /* v1122[48] */,
  hls::stream< float > &v1123 /* v1123[48] */,
  hls::stream< float > &v1124 /* v1124[48] */,
  hls::stream< float > &v1125 /* v1125[48] */,
  float v1126[4][4],
  int v1127,
  int v1128
) {	// L1514
  #pragma HLS stream variable=v1122 depth=5
  #pragma HLS stream variable=v1123 depth=5
  #pragma HLS stream variable=v1124 depth=5
  #pragma HLS stream variable=v1125 depth=5
  #pragma HLS array_partition variable=v1126 complete dim=1
  #pragma HLS array_partition variable=v1126 complete dim=2

  float v42;	// L1517
  v42 = 0.000000;	// L1518
  l_S_k_0_k46: for (int k46 = 0; k46 < 48; k46++) {	// L1519
    float v1131 = v1122.read(); // v1122[k46];	// L1520
    float a42;	// L1521
    a42 = v1131;	// L1522
    float v1133 = v1123.read(); // v1123[k46];	// L1523
    float b42;	// L1524
    b42 = v1133;	// L1525
    float v1135 = a42;	// L1526
    float v1136 = b42;	// L1527
    float v1137 = v1135 * v1136;	// L1528
    float v1138 = v42;	// L1529
    float v1139 = v1138 + v1137;	// L1530
    v42 = v1139;	// L1531
    float v1140 = a42;	// L1532
    v1124.write(v1140); // v1124[k46] = v1140;	// L1533
    float v1141 = b42;	// L1534
    v1125.write(v1141); // v1125[k46] = v1141;	// L1535
  }
  float v1142 = v42;	// L1537
  v1126[v1127][v1128] = v1142;	// L1538
}

void PE_kernel_V_3_2(
  hls::stream< float > &v1143 /* v1143[48] */,
  hls::stream< float > &v1144 /* v1144[48] */,
  hls::stream< float > &v1145 /* v1145[48] */,
  hls::stream< float > &v1146 /* v1146[48] */,
  float v1147[4][4],
  int v1148,
  int v1149
) {	// L1541
  #pragma HLS stream variable=v1143 depth=5
  #pragma HLS stream variable=v1144 depth=5
  #pragma HLS stream variable=v1145 depth=5
  #pragma HLS stream variable=v1146 depth=5
  #pragma HLS array_partition variable=v1147 complete dim=1
  #pragma HLS array_partition variable=v1147 complete dim=2

  float v43;	// L1544
  v43 = 0.000000;	// L1545
  l_S_k_0_k47: for (int k47 = 0; k47 < 48; k47++) {	// L1546
    float v1152 = v1143.read(); // v1143[k47];	// L1547
    float a43;	// L1548
    a43 = v1152;	// L1549
    float v1154 = v1144.read(); // v1144[k47];	// L1550
    float b43;	// L1551
    b43 = v1154;	// L1552
    float v1156 = a43;	// L1553
    float v1157 = b43;	// L1554
    float v1158 = v1156 * v1157;	// L1555
    float v1159 = v43;	// L1556
    float v1160 = v1159 + v1158;	// L1557
    v43 = v1160;	// L1558
    float v1161 = a43;	// L1559
    v1145.write(v1161); // v1145[k47] = v1161;	// L1560
    float v1162 = b43;	// L1561
    v1146.write(v1162); // v1146[k47] = v1162;	// L1562
  }
  float v1163 = v43;	// L1564
  v1147[v1148][v1149] = v1163;	// L1565
}

void PE_kernel_V_0_3(
  hls::stream< float > &v1164 /* v1164[48] */,
  hls::stream< float > &v1165 /* v1165[48] */,
  hls::stream< float > &v1166 /* v1166[48] */,
  hls::stream< float > &v1167 /* v1167[48] */,
  float v1168[4][4],
  int v1169,
  int v1170
) {	// L1568
  #pragma HLS stream variable=v1164 depth=5
  #pragma HLS stream variable=v1165 depth=5
  #pragma HLS stream variable=v1166 depth=5
  #pragma HLS stream variable=v1167 depth=5
  #pragma HLS array_partition variable=v1168 complete dim=1
  #pragma HLS array_partition variable=v1168 complete dim=2

  float v44;	// L1571
  v44 = 0.000000;	// L1572
  l_S_k_0_k48: for (int k48 = 0; k48 < 48; k48++) {	// L1573
    float v1173 = v1164.read(); // v1164[k48];	// L1574
    float a44;	// L1575
    a44 = v1173;	// L1576
    float v1175 = v1165.read(); // v1165[k48];	// L1577
    float b44;	// L1578
    b44 = v1175;	// L1579
    float v1177 = a44;	// L1580
    float v1178 = b44;	// L1581
    float v1179 = v1177 * v1178;	// L1582
    float v1180 = v44;	// L1583
    float v1181 = v1180 + v1179;	// L1584
    v44 = v1181;	// L1585
    float v1182 = a44;	// L1586
    v1166.write(v1182); // v1166[k48] = v1182;	// L1587
    float v1183 = b44;	// L1588
    v1167.write(v1183); // v1167[k48] = v1183;	// L1589
  }
  float v1184 = v44;	// L1591
  v1168[v1169][v1170] = v1184;	// L1592
}

void PE_kernel_V_1_3(
  hls::stream< float > &v1185 /* v1185[48] */,
  hls::stream< float > &v1186 /* v1186[48] */,
  hls::stream< float > &v1187 /* v1187[48] */,
  hls::stream< float > &v1188 /* v1188[48] */,
  float v1189[4][4],
  int v1190,
  int v1191
) {	// L1595
  #pragma HLS stream variable=v1185 depth=5
  #pragma HLS stream variable=v1186 depth=5
  #pragma HLS stream variable=v1187 depth=5
  #pragma HLS stream variable=v1188 depth=5
  #pragma HLS array_partition variable=v1189 complete dim=1
  #pragma HLS array_partition variable=v1189 complete dim=2

  float v45;	// L1598
  v45 = 0.000000;	// L1599
  l_S_k_0_k49: for (int k49 = 0; k49 < 48; k49++) {	// L1600
    float v1194 = v1185.read(); // v1185[k49];	// L1601
    float a45;	// L1602
    a45 = v1194;	// L1603
    float v1196 = v1186.read(); // v1186[k49];	// L1604
    float b45;	// L1605
    b45 = v1196;	// L1606
    float v1198 = a45;	// L1607
    float v1199 = b45;	// L1608
    float v1200 = v1198 * v1199;	// L1609
    float v1201 = v45;	// L1610
    float v1202 = v1201 + v1200;	// L1611
    v45 = v1202;	// L1612
    float v1203 = a45;	// L1613
    v1187.write(v1203); // v1187[k49] = v1203;	// L1614
    float v1204 = b45;	// L1615
    v1188.write(v1204); // v1188[k49] = v1204;	// L1616
  }
  float v1205 = v45;	// L1618
  v1189[v1190][v1191] = v1205;	// L1619
}

void PE_kernel_V_2_3(
  hls::stream< float > &v1206 /* v1206[48] */,
  hls::stream< float > &v1207 /* v1207[48] */,
  hls::stream< float > &v1208 /* v1208[48] */,
  hls::stream< float > &v1209 /* v1209[48] */,
  float v1210[4][4],
  int v1211,
  int v1212
) {	// L1622
  #pragma HLS stream variable=v1206 depth=5
  #pragma HLS stream variable=v1207 depth=5
  #pragma HLS stream variable=v1208 depth=5
  #pragma HLS stream variable=v1209 depth=5
  #pragma HLS array_partition variable=v1210 complete dim=1
  #pragma HLS array_partition variable=v1210 complete dim=2

  float v46;	// L1625
  v46 = 0.000000;	// L1626
  l_S_k_0_k50: for (int k50 = 0; k50 < 48; k50++) {	// L1627
    float v1215 = v1206.read(); // v1206[k50];	// L1628
    float a46;	// L1629
    a46 = v1215;	// L1630
    float v1217 = v1207.read(); // v1207[k50];	// L1631
    float b46;	// L1632
    b46 = v1217;	// L1633
    float v1219 = a46;	// L1634
    float v1220 = b46;	// L1635
    float v1221 = v1219 * v1220;	// L1636
    float v1222 = v46;	// L1637
    float v1223 = v1222 + v1221;	// L1638
    v46 = v1223;	// L1639
    float v1224 = a46;	// L1640
    v1208.write(v1224); // v1208[k50] = v1224;	// L1641
    float v1225 = b46;	// L1642
    v1209.write(v1225); // v1209[k50] = v1225;	// L1643
  }
  float v1226 = v46;	// L1645
  v1210[v1211][v1212] = v1226;	// L1646
}

void PE_kernel_V_3_3(
  hls::stream< float > &v1227 /* v1227[48] */,
  hls::stream< float > &v1228 /* v1228[48] */,
  hls::stream< float > &v1229 /* v1229[48] */,
  hls::stream< float > &v1230 /* v1230[48] */,
  float v1231[4][4],
  int v1232,
  int v1233
) {	// L1649
  #pragma HLS stream variable=v1227 depth=5
  #pragma HLS stream variable=v1228 depth=5
  #pragma HLS stream variable=v1229 depth=5
  #pragma HLS stream variable=v1230 depth=5
  #pragma HLS array_partition variable=v1231 complete dim=1
  #pragma HLS array_partition variable=v1231 complete dim=2

  float v47;	// L1652
  v47 = 0.000000;	// L1653
  l_S_k_0_k51: for (int k51 = 0; k51 < 48; k51++) {	// L1654
    float v1236 = v1227.read(); // v1227[k51];	// L1655
    float a47;	// L1656
    a47 = v1236;	// L1657
    float v1238 = v1228.read(); // v1228[k51];	// L1658
    float b47;	// L1659
    b47 = v1238;	// L1660
    float v1240 = a47;	// L1661
    float v1241 = b47;	// L1662
    float v1242 = v1240 * v1241;	// L1663
    float v1243 = v47;	// L1664
    float v1244 = v1243 + v1242;	// L1665
    v47 = v1244;	// L1666
    float v1245 = a47;	// L1667
    v1229.write(v1245); // v1229[k51] = v1245;	// L1668
    float v1246 = b47;	// L1669
    v1230.write(v1246); // v1230[k51] = v1246;	// L1670
  }
  float v1247 = v47;	// L1672
  v1231[v1232][v1233] = v1247;	// L1673
}

void systolic_tile_V(
  float v1248[4][48],
  float v1249[48][4],
  float v1250[4][4]
) {	// L1676
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v1248 complete dim=1

  #pragma HLS array_partition variable=v1249 complete dim=2

  #pragma HLS array_partition variable=v1250 complete dim=1
  #pragma HLS array_partition variable=v1250 complete dim=2

  hls::stream< float > A_fifo2[4][5] /* A_fifo2[4][5][48] */;	// L1677
  #pragma HLS stream variable=A_fifo2 depth=5
  hls::stream< float > B_fifo2[4][5] /* B_fifo2[4][5][48] */;	// L1678
  #pragma HLS stream variable=B_fifo2 depth=5
  float A_drain2[4];	// L1679
  float B_drain2[4];	// L1680
  l_data_load_k52: for (int k52 = 0; k52 < 48; k52++) {	// L1681
    l_S_m_0_m4: for (int m4 = 0; m4 < 4; m4++) {	// L1682
      float v1257 = v1248[m4][k52];	// L1683
      A_fifo2[m4][0].write(v1257); // A_fifo2[m4][0][k52] = v1257;	// L1684
    }
    l_S_n_1_n4: for (int n4 = 0; n4 < 4; n4++) {	// L1686
      float v1259 = v1249[k52][n4];	// L1687
      B_fifo2[n4][0].write(v1259); // B_fifo2[n4][0][k52] = v1259;	// L1688
    }
  }
  hls::stream< float > &v1260 /* v1260[48] */ = A_fifo2[0][0];	// L1692
  hls::stream< float > &v1261 /* v1261[48] */ = B_fifo2[0][0];	// L1693
  hls::stream< float > &v1262 /* v1262[48] */ = A_fifo2[0][1];	// L1699
  hls::stream< float > &v1263 /* v1263[48] */ = B_fifo2[0][1];	// L1700
  PE_kernel_V_0_0(v1260, v1261, v1262, v1263, v1250, 0, 0);	// L1701
  hls::stream< float > &v1264 /* v1264[48] */ = A_fifo2[0][1];	// L1703
  hls::stream< float > &v1265 /* v1265[48] */ = B_fifo2[1][0];	// L1704
  hls::stream< float > &v1266 /* v1266[48] */ = A_fifo2[0][2];	// L1708
  hls::stream< float > &v1267 /* v1267[48] */ = B_fifo2[1][1];	// L1709
  PE_kernel_V_1_0(v1264, v1265, v1266, v1267, v1250, 0, 1);	// L1710
  hls::stream< float > &v1268 /* v1268[48] */ = A_fifo2[0][2];	// L1712
  hls::stream< float > &v1269 /* v1269[48] */ = B_fifo2[2][0];	// L1713
  hls::stream< float > &v1270 /* v1270[48] */ = A_fifo2[0][3];	// L1717
  hls::stream< float > &v1271 /* v1271[48] */ = B_fifo2[2][1];	// L1718
  PE_kernel_V_2_0(v1268, v1269, v1270, v1271, v1250, 0, 2);	// L1719
  hls::stream< float > &v1272 /* v1272[48] */ = A_fifo2[0][3];	// L1721
  hls::stream< float > &v1273 /* v1273[48] */ = B_fifo2[3][0];	// L1722
  hls::stream< float > &v1274 /* v1274[48] */ = A_fifo2[0][4];	// L1726
  hls::stream< float > &v1275 /* v1275[48] */ = B_fifo2[3][1];	// L1727
  PE_kernel_V_3_0(v1272, v1273, v1274, v1275, v1250, 0, 3);	// L1728
  hls::stream< float > &v1276 /* v1276[48] */ = A_fifo2[1][0];	// L1729
  hls::stream< float > &v1277 /* v1277[48] */ = B_fifo2[0][1];	// L1730
  hls::stream< float > &v1278 /* v1278[48] */ = A_fifo2[1][1];	// L1731
  hls::stream< float > &v1279 /* v1279[48] */ = B_fifo2[0][2];	// L1732
  PE_kernel_V_0_1(v1276, v1277, v1278, v1279, v1250, 1, 0);	// L1733
  hls::stream< float > &v1280 /* v1280[48] */ = A_fifo2[1][1];	// L1734
  hls::stream< float > &v1281 /* v1281[48] */ = B_fifo2[1][1];	// L1735
  hls::stream< float > &v1282 /* v1282[48] */ = A_fifo2[1][2];	// L1736
  hls::stream< float > &v1283 /* v1283[48] */ = B_fifo2[1][2];	// L1737
  PE_kernel_V_1_1(v1280, v1281, v1282, v1283, v1250, 1, 1);	// L1738
  hls::stream< float > &v1284 /* v1284[48] */ = A_fifo2[1][2];	// L1739
  hls::stream< float > &v1285 /* v1285[48] */ = B_fifo2[2][1];	// L1740
  hls::stream< float > &v1286 /* v1286[48] */ = A_fifo2[1][3];	// L1741
  hls::stream< float > &v1287 /* v1287[48] */ = B_fifo2[2][2];	// L1742
  PE_kernel_V_2_1(v1284, v1285, v1286, v1287, v1250, 1, 2);	// L1743
  hls::stream< float > &v1288 /* v1288[48] */ = A_fifo2[1][3];	// L1744
  hls::stream< float > &v1289 /* v1289[48] */ = B_fifo2[3][1];	// L1745
  hls::stream< float > &v1290 /* v1290[48] */ = A_fifo2[1][4];	// L1746
  hls::stream< float > &v1291 /* v1291[48] */ = B_fifo2[3][2];	// L1747
  PE_kernel_V_3_1(v1288, v1289, v1290, v1291, v1250, 1, 3);	// L1748
  hls::stream< float > &v1292 /* v1292[48] */ = A_fifo2[2][0];	// L1749
  hls::stream< float > &v1293 /* v1293[48] */ = B_fifo2[0][2];	// L1750
  hls::stream< float > &v1294 /* v1294[48] */ = A_fifo2[2][1];	// L1751
  hls::stream< float > &v1295 /* v1295[48] */ = B_fifo2[0][3];	// L1752
  PE_kernel_V_0_2(v1292, v1293, v1294, v1295, v1250, 2, 0);	// L1753
  hls::stream< float > &v1296 /* v1296[48] */ = A_fifo2[2][1];	// L1754
  hls::stream< float > &v1297 /* v1297[48] */ = B_fifo2[1][2];	// L1755
  hls::stream< float > &v1298 /* v1298[48] */ = A_fifo2[2][2];	// L1756
  hls::stream< float > &v1299 /* v1299[48] */ = B_fifo2[1][3];	// L1757
  PE_kernel_V_1_2(v1296, v1297, v1298, v1299, v1250, 2, 1);	// L1758
  hls::stream< float > &v1300 /* v1300[48] */ = A_fifo2[2][2];	// L1759
  hls::stream< float > &v1301 /* v1301[48] */ = B_fifo2[2][2];	// L1760
  hls::stream< float > &v1302 /* v1302[48] */ = A_fifo2[2][3];	// L1761
  hls::stream< float > &v1303 /* v1303[48] */ = B_fifo2[2][3];	// L1762
  PE_kernel_V_2_2(v1300, v1301, v1302, v1303, v1250, 2, 2);	// L1763
  hls::stream< float > &v1304 /* v1304[48] */ = A_fifo2[2][3];	// L1764
  hls::stream< float > &v1305 /* v1305[48] */ = B_fifo2[3][2];	// L1765
  hls::stream< float > &v1306 /* v1306[48] */ = A_fifo2[2][4];	// L1766
  hls::stream< float > &v1307 /* v1307[48] */ = B_fifo2[3][3];	// L1767
  PE_kernel_V_3_2(v1304, v1305, v1306, v1307, v1250, 2, 3);	// L1768
  hls::stream< float > &v1308 /* v1308[48] */ = A_fifo2[3][0];	// L1769
  hls::stream< float > &v1309 /* v1309[48] */ = B_fifo2[0][3];	// L1770
  hls::stream< float > &v1310 /* v1310[48] */ = A_fifo2[3][1];	// L1771
  hls::stream< float > &v1311 /* v1311[48] */ = B_fifo2[0][4];	// L1772
  PE_kernel_V_0_3(v1308, v1309, v1310, v1311, v1250, 3, 0);	// L1773
  hls::stream< float > &v1312 /* v1312[48] */ = A_fifo2[3][1];	// L1774
  hls::stream< float > &v1313 /* v1313[48] */ = B_fifo2[1][3];	// L1775
  hls::stream< float > &v1314 /* v1314[48] */ = A_fifo2[3][2];	// L1776
  hls::stream< float > &v1315 /* v1315[48] */ = B_fifo2[1][4];	// L1777
  PE_kernel_V_1_3(v1312, v1313, v1314, v1315, v1250, 3, 1);	// L1778
  hls::stream< float > &v1316 /* v1316[48] */ = A_fifo2[3][2];	// L1779
  hls::stream< float > &v1317 /* v1317[48] */ = B_fifo2[2][3];	// L1780
  hls::stream< float > &v1318 /* v1318[48] */ = A_fifo2[3][3];	// L1781
  hls::stream< float > &v1319 /* v1319[48] */ = B_fifo2[2][4];	// L1782
  PE_kernel_V_2_3(v1316, v1317, v1318, v1319, v1250, 3, 2);	// L1783
  hls::stream< float > &v1320 /* v1320[48] */ = A_fifo2[3][3];	// L1784
  hls::stream< float > &v1321 /* v1321[48] */ = B_fifo2[3][3];	// L1785
  hls::stream< float > &v1322 /* v1322[48] */ = A_fifo2[3][4];	// L1786
  hls::stream< float > &v1323 /* v1323[48] */ = B_fifo2[3][4];	// L1787
  PE_kernel_V_3_3(v1320, v1321, v1322, v1323, v1250, 3, 3);	// L1788
  l_data_drain_k53: for (int k53 = 0; k53 < 48; k53++) {	// L1789
    l_S_m_4_m5: for (int m5 = 0; m5 < 4; m5++) {	// L1790
      float v1326 = A_fifo2[m5][4].read(); // A_fifo2[m5][4][k53];	// L1791
      A_drain2[m5] = v1326;	// L1792
    }
    l_S_n_5_n5: for (int n5 = 0; n5 < 4; n5++) {	// L1794
      float v1328 = B_fifo2[n5][4].read(); // B_fifo2[n5][4][k53];	// L1795
      B_drain2[n5] = v1328;	// L1796
    }
  }
}

void systolic_V(
  float v1329[32][48],
  float *Wv,
  float v1331[32][48]
) {	// L1801
  float local_A2[4][48];	// L1802
  #pragma HLS array_partition variable=local_A2 complete dim=1

  float local_B2[48][4];	// L1803
  #pragma HLS array_partition variable=local_B2 complete dim=2

  float local_C2[4][4];	// L1804
  #pragma HLS array_partition variable=local_C2 complete dim=1
  #pragma HLS array_partition variable=local_C2 complete dim=2

  l_outer_tile_mi2: for (int mi2 = 0; mi2 < 8; mi2++) {	// L1805
    l_ni2: for (int ni2 = 0; ni2 < 12; ni2++) {	// L1806
    #pragma HLS dataflow
      l_load_A_tile_ak2: for (int ak2 = 0; ak2 < 48; ak2++) {	// L1807
        l_ai2: for (int ai2 = 0; ai2 < 4; ai2++) {	// L1808
        #pragma HLS pipeline II=1
          ap_int<33> v1339 = ni2;	// L1809
          bool v1340 = v1339 == 0;	// L1812
          if (v1340) {	// L1813
            float v1341 = v1329[((mi2 * 4) + ai2)][ak2];	// L1814
            local_A2[ai2][ak2] = v1341;	// L1815
          }
        }
      }
      l_load_B_tile_bk2: for (int bk2 = 0; bk2 < 48; bk2++) {	// L1819
        l_bj2: for (int bj2 = 0; bj2 < 4; bj2++) {	// L1820
        #pragma HLS pipeline II=1
        float v1344 = Wv[bk2*48+((ni2 * 4) + bj2)];	// L1821
          // float v1344 = v1330[bk2][((ni2 * 4) + bj2)];	// L1821
          local_B2[bk2][bj2] = v1344;	// L1822
        }
      }
      systolic_tile_V(local_A2, local_B2, local_C2);	// L1825
      l_store_C_tile_sj2: for (int sj2 = 0; sj2 < 4; sj2++) {	// L1826
        l_si2: for (int si2 = 0; si2 < 4; si2++) {	// L1827
        #pragma HLS pipeline II=1
          float v1347 = local_C2[si2][sj2];	// L1828
          v1331[((mi2 * 4) + si2)][((ni2 * 4) + sj2)] = v1347;	// L1829
        }
      }
    }
  }
}

void PE_kernel_QKT_0_0(
  hls::stream< float > &v1348 /* v1348[4] */,
  hls::stream< float > &v1349 /* v1349[4] */,
  hls::stream< float > &v1350 /* v1350[4] */,
  hls::stream< float > &v1351 /* v1351[4] */,
  float v1352[4][4],
  int v1353,
  int v1354
) {	// L1836
  #pragma HLS stream variable=v1348 depth=5
  #pragma HLS stream variable=v1349 depth=5
  #pragma HLS stream variable=v1350 depth=5
  #pragma HLS stream variable=v1351 depth=5
  #pragma HLS array_partition variable=v1352 complete dim=1
  #pragma HLS array_partition variable=v1352 complete dim=2

  float v48;	// L1839
  v48 = 0.000000;	// L1840
  l_S_k_0_k54: for (int k54 = 0; k54 < 4; k54++) {	// L1841
    float v1357 = v1348.read(); // v1348[k54];	// L1842
    float a48;	// L1843
    a48 = v1357;	// L1844
    float v1359 = v1349.read(); // v1349[k54];	// L1845
    float b48;	// L1846
    b48 = v1359;	// L1847
    float v1361 = a48;	// L1848
    float v1362 = b48;	// L1849
    float v1363 = v1361 * v1362;	// L1850
    float v1364 = v48;	// L1851
    float v1365 = v1364 + v1363;	// L1852
    v48 = v1365;	// L1853
    float v1366 = a48;	// L1854
    v1350.write(v1366); // v1350[k54] = v1366;	// L1855
    float v1367 = b48;	// L1856
    v1351.write(v1367); // v1351[k54] = v1367;	// L1857
  }
  float v1368 = v48;	// L1859
  v1352[v1353][v1354] = v1368;	// L1860
}

void PE_kernel_QKT_1_0(
  hls::stream< float > &v1369 /* v1369[4] */,
  hls::stream< float > &v1370 /* v1370[4] */,
  hls::stream< float > &v1371 /* v1371[4] */,
  hls::stream< float > &v1372 /* v1372[4] */,
  float v1373[4][4],
  int v1374,
  int v1375
) {	// L1863
  #pragma HLS stream variable=v1369 depth=5
  #pragma HLS stream variable=v1370 depth=5
  #pragma HLS stream variable=v1371 depth=5
  #pragma HLS stream variable=v1372 depth=5
  #pragma HLS array_partition variable=v1373 complete dim=1
  #pragma HLS array_partition variable=v1373 complete dim=2

  float v49;	// L1866
  v49 = 0.000000;	// L1867
  l_S_k_0_k55: for (int k55 = 0; k55 < 4; k55++) {	// L1868
    float v1378 = v1369.read(); // v1369[k55];	// L1869
    float a49;	// L1870
    a49 = v1378;	// L1871
    float v1380 = v1370.read(); // v1370[k55];	// L1872
    float b49;	// L1873
    b49 = v1380;	// L1874
    float v1382 = a49;	// L1875
    float v1383 = b49;	// L1876
    float v1384 = v1382 * v1383;	// L1877
    float v1385 = v49;	// L1878
    float v1386 = v1385 + v1384;	// L1879
    v49 = v1386;	// L1880
    float v1387 = a49;	// L1881
    v1371.write(v1387); // v1371[k55] = v1387;	// L1882
    float v1388 = b49;	// L1883
    v1372.write(v1388); // v1372[k55] = v1388;	// L1884
  }
  float v1389 = v49;	// L1886
  v1373[v1374][v1375] = v1389;	// L1887
}

void PE_kernel_QKT_2_0(
  hls::stream< float > &v1390 /* v1390[4] */,
  hls::stream< float > &v1391 /* v1391[4] */,
  hls::stream< float > &v1392 /* v1392[4] */,
  hls::stream< float > &v1393 /* v1393[4] */,
  float v1394[4][4],
  int v1395,
  int v1396
) {	// L1890
  #pragma HLS stream variable=v1390 depth=5
  #pragma HLS stream variable=v1391 depth=5
  #pragma HLS stream variable=v1392 depth=5
  #pragma HLS stream variable=v1393 depth=5
  #pragma HLS array_partition variable=v1394 complete dim=1
  #pragma HLS array_partition variable=v1394 complete dim=2

  float v50;	// L1893
  v50 = 0.000000;	// L1894
  l_S_k_0_k56: for (int k56 = 0; k56 < 4; k56++) {	// L1895
    float v1399 = v1390.read(); // v1390[k56];	// L1896
    float a50;	// L1897
    a50 = v1399;	// L1898
    float v1401 = v1391.read(); // v1391[k56];	// L1899
    float b50;	// L1900
    b50 = v1401;	// L1901
    float v1403 = a50;	// L1902
    float v1404 = b50;	// L1903
    float v1405 = v1403 * v1404;	// L1904
    float v1406 = v50;	// L1905
    float v1407 = v1406 + v1405;	// L1906
    v50 = v1407;	// L1907
    float v1408 = a50;	// L1908
    v1392.write(v1408); // v1392[k56] = v1408;	// L1909
    float v1409 = b50;	// L1910
    v1393.write(v1409); // v1393[k56] = v1409;	// L1911
  }
  float v1410 = v50;	// L1913
  v1394[v1395][v1396] = v1410;	// L1914
}

void PE_kernel_QKT_3_0(
  hls::stream< float > &v1411 /* v1411[4] */,
  hls::stream< float > &v1412 /* v1412[4] */,
  hls::stream< float > &v1413 /* v1413[4] */,
  hls::stream< float > &v1414 /* v1414[4] */,
  float v1415[4][4],
  int v1416,
  int v1417
) {	// L1917
  #pragma HLS stream variable=v1411 depth=5
  #pragma HLS stream variable=v1412 depth=5
  #pragma HLS stream variable=v1413 depth=5
  #pragma HLS stream variable=v1414 depth=5
  #pragma HLS array_partition variable=v1415 complete dim=1
  #pragma HLS array_partition variable=v1415 complete dim=2

  float v51;	// L1920
  v51 = 0.000000;	// L1921
  l_S_k_0_k57: for (int k57 = 0; k57 < 4; k57++) {	// L1922
    float v1420 = v1411.read(); // v1411[k57];	// L1923
    float a51;	// L1924
    a51 = v1420;	// L1925
    float v1422 = v1412.read(); // v1412[k57];	// L1926
    float b51;	// L1927
    b51 = v1422;	// L1928
    float v1424 = a51;	// L1929
    float v1425 = b51;	// L1930
    float v1426 = v1424 * v1425;	// L1931
    float v1427 = v51;	// L1932
    float v1428 = v1427 + v1426;	// L1933
    v51 = v1428;	// L1934
    float v1429 = a51;	// L1935
    v1413.write(v1429); // v1413[k57] = v1429;	// L1936
    float v1430 = b51;	// L1937
    v1414.write(v1430); // v1414[k57] = v1430;	// L1938
  }
  float v1431 = v51;	// L1940
  v1415[v1416][v1417] = v1431;	// L1941
}

void PE_kernel_QKT_0_1(
  hls::stream< float > &v1432 /* v1432[4] */,
  hls::stream< float > &v1433 /* v1433[4] */,
  hls::stream< float > &v1434 /* v1434[4] */,
  hls::stream< float > &v1435 /* v1435[4] */,
  float v1436[4][4],
  int v1437,
  int v1438
) {	// L1944
  #pragma HLS stream variable=v1432 depth=5
  #pragma HLS stream variable=v1433 depth=5
  #pragma HLS stream variable=v1434 depth=5
  #pragma HLS stream variable=v1435 depth=5
  #pragma HLS array_partition variable=v1436 complete dim=1
  #pragma HLS array_partition variable=v1436 complete dim=2

  float v52;	// L1947
  v52 = 0.000000;	// L1948
  l_S_k_0_k58: for (int k58 = 0; k58 < 4; k58++) {	// L1949
    float v1441 = v1432.read(); // v1432[k58];	// L1950
    float a52;	// L1951
    a52 = v1441;	// L1952
    float v1443 = v1433.read(); // v1433[k58];	// L1953
    float b52;	// L1954
    b52 = v1443;	// L1955
    float v1445 = a52;	// L1956
    float v1446 = b52;	// L1957
    float v1447 = v1445 * v1446;	// L1958
    float v1448 = v52;	// L1959
    float v1449 = v1448 + v1447;	// L1960
    v52 = v1449;	// L1961
    float v1450 = a52;	// L1962
    v1434.write(v1450); // v1434[k58] = v1450;	// L1963
    float v1451 = b52;	// L1964
    v1435.write(v1451); // v1435[k58] = v1451;	// L1965
  }
  float v1452 = v52;	// L1967
  v1436[v1437][v1438] = v1452;	// L1968
}

void PE_kernel_QKT_1_1(
  hls::stream< float > &v1453 /* v1453[4] */,
  hls::stream< float > &v1454 /* v1454[4] */,
  hls::stream< float > &v1455 /* v1455[4] */,
  hls::stream< float > &v1456 /* v1456[4] */,
  float v1457[4][4],
  int v1458,
  int v1459
) {	// L1971
  #pragma HLS stream variable=v1453 depth=5
  #pragma HLS stream variable=v1454 depth=5
  #pragma HLS stream variable=v1455 depth=5
  #pragma HLS stream variable=v1456 depth=5
  #pragma HLS array_partition variable=v1457 complete dim=1
  #pragma HLS array_partition variable=v1457 complete dim=2

  float v53;	// L1974
  v53 = 0.000000;	// L1975
  l_S_k_0_k59: for (int k59 = 0; k59 < 4; k59++) {	// L1976
    float v1462 = v1453.read(); // v1453[k59];	// L1977
    float a53;	// L1978
    a53 = v1462;	// L1979
    float v1464 = v1454.read(); // v1454[k59];	// L1980
    float b53;	// L1981
    b53 = v1464;	// L1982
    float v1466 = a53;	// L1983
    float v1467 = b53;	// L1984
    float v1468 = v1466 * v1467;	// L1985
    float v1469 = v53;	// L1986
    float v1470 = v1469 + v1468;	// L1987
    v53 = v1470;	// L1988
    float v1471 = a53;	// L1989
    v1455.write(v1471); // v1455[k59] = v1471;	// L1990
    float v1472 = b53;	// L1991
    v1456.write(v1472); // v1456[k59] = v1472;	// L1992
  }
  float v1473 = v53;	// L1994
  v1457[v1458][v1459] = v1473;	// L1995
}

void PE_kernel_QKT_2_1(
  hls::stream< float > &v1474 /* v1474[4] */,
  hls::stream< float > &v1475 /* v1475[4] */,
  hls::stream< float > &v1476 /* v1476[4] */,
  hls::stream< float > &v1477 /* v1477[4] */,
  float v1478[4][4],
  int v1479,
  int v1480
) {	// L1998
  #pragma HLS stream variable=v1474 depth=5
  #pragma HLS stream variable=v1475 depth=5
  #pragma HLS stream variable=v1476 depth=5
  #pragma HLS stream variable=v1477 depth=5
  #pragma HLS array_partition variable=v1478 complete dim=1
  #pragma HLS array_partition variable=v1478 complete dim=2

  float v54;	// L2001
  v54 = 0.000000;	// L2002
  l_S_k_0_k60: for (int k60 = 0; k60 < 4; k60++) {	// L2003
    float v1483 = v1474.read(); // v1474[k60];	// L2004
    float a54;	// L2005
    a54 = v1483;	// L2006
    float v1485 = v1475.read(); // v1475[k60];	// L2007
    float b54;	// L2008
    b54 = v1485;	// L2009
    float v1487 = a54;	// L2010
    float v1488 = b54;	// L2011
    float v1489 = v1487 * v1488;	// L2012
    float v1490 = v54;	// L2013
    float v1491 = v1490 + v1489;	// L2014
    v54 = v1491;	// L2015
    float v1492 = a54;	// L2016
    v1476.write(v1492); // v1476[k60] = v1492;	// L2017
    float v1493 = b54;	// L2018
    v1477.write(v1493); // v1477[k60] = v1493;	// L2019
  }
  float v1494 = v54;	// L2021
  v1478[v1479][v1480] = v1494;	// L2022
}

void PE_kernel_QKT_3_1(
  hls::stream< float > &v1495 /* v1495[4] */,
  hls::stream< float > &v1496 /* v1496[4] */,
  hls::stream< float > &v1497 /* v1497[4] */,
  hls::stream< float > &v1498 /* v1498[4] */,
  float v1499[4][4],
  int v1500,
  int v1501
) {	// L2025
  #pragma HLS stream variable=v1495 depth=5
  #pragma HLS stream variable=v1496 depth=5
  #pragma HLS stream variable=v1497 depth=5
  #pragma HLS stream variable=v1498 depth=5
  #pragma HLS array_partition variable=v1499 complete dim=1
  #pragma HLS array_partition variable=v1499 complete dim=2

  float v55;	// L2028
  v55 = 0.000000;	// L2029
  l_S_k_0_k61: for (int k61 = 0; k61 < 4; k61++) {	// L2030
    float v1504 = v1495.read(); // v1495[k61];	// L2031
    float a55;	// L2032
    a55 = v1504;	// L2033
    float v1506 = v1496.read(); // v1496[k61];	// L2034
    float b55;	// L2035
    b55 = v1506;	// L2036
    float v1508 = a55;	// L2037
    float v1509 = b55;	// L2038
    float v1510 = v1508 * v1509;	// L2039
    float v1511 = v55;	// L2040
    float v1512 = v1511 + v1510;	// L2041
    v55 = v1512;	// L2042
    float v1513 = a55;	// L2043
    v1497.write(v1513); // v1497[k61] = v1513;	// L2044
    float v1514 = b55;	// L2045
    v1498.write(v1514); // v1498[k61] = v1514;	// L2046
  }
  float v1515 = v55;	// L2048
  v1499[v1500][v1501] = v1515;	// L2049
}

void PE_kernel_QKT_0_2(
  hls::stream< float > &v1516 /* v1516[4] */,
  hls::stream< float > &v1517 /* v1517[4] */,
  hls::stream< float > &v1518 /* v1518[4] */,
  hls::stream< float > &v1519 /* v1519[4] */,
  float v1520[4][4],
  int v1521,
  int v1522
) {	// L2052
  #pragma HLS stream variable=v1516 depth=5
  #pragma HLS stream variable=v1517 depth=5
  #pragma HLS stream variable=v1518 depth=5
  #pragma HLS stream variable=v1519 depth=5
  #pragma HLS array_partition variable=v1520 complete dim=1
  #pragma HLS array_partition variable=v1520 complete dim=2

  float v56;	// L2055
  v56 = 0.000000;	// L2056
  l_S_k_0_k62: for (int k62 = 0; k62 < 4; k62++) {	// L2057
    float v1525 = v1516.read(); // v1516[k62];	// L2058
    float a56;	// L2059
    a56 = v1525;	// L2060
    float v1527 = v1517.read(); // v1517[k62];	// L2061
    float b56;	// L2062
    b56 = v1527;	// L2063
    float v1529 = a56;	// L2064
    float v1530 = b56;	// L2065
    float v1531 = v1529 * v1530;	// L2066
    float v1532 = v56;	// L2067
    float v1533 = v1532 + v1531;	// L2068
    v56 = v1533;	// L2069
    float v1534 = a56;	// L2070
    v1518.write(v1534); // v1518[k62] = v1534;	// L2071
    float v1535 = b56;	// L2072
    v1519.write(v1535); // v1519[k62] = v1535;	// L2073
  }
  float v1536 = v56;	// L2075
  v1520[v1521][v1522] = v1536;	// L2076
}

void PE_kernel_QKT_1_2(
  hls::stream< float > &v1537 /* v1537[4] */,
  hls::stream< float > &v1538 /* v1538[4] */,
  hls::stream< float > &v1539 /* v1539[4] */,
  hls::stream< float > &v1540 /* v1540[4] */,
  float v1541[4][4],
  int v1542,
  int v1543
) {	// L2079
  #pragma HLS stream variable=v1537 depth=5
  #pragma HLS stream variable=v1538 depth=5
  #pragma HLS stream variable=v1539 depth=5
  #pragma HLS stream variable=v1540 depth=5
  #pragma HLS array_partition variable=v1541 complete dim=1
  #pragma HLS array_partition variable=v1541 complete dim=2

  float v57;	// L2082
  v57 = 0.000000;	// L2083
  l_S_k_0_k63: for (int k63 = 0; k63 < 4; k63++) {	// L2084
    float v1546 = v1537.read(); // v1537[k63];	// L2085
    float a57;	// L2086
    a57 = v1546;	// L2087
    float v1548 = v1538.read(); // v1538[k63];	// L2088
    float b57;	// L2089
    b57 = v1548;	// L2090
    float v1550 = a57;	// L2091
    float v1551 = b57;	// L2092
    float v1552 = v1550 * v1551;	// L2093
    float v1553 = v57;	// L2094
    float v1554 = v1553 + v1552;	// L2095
    v57 = v1554;	// L2096
    float v1555 = a57;	// L2097
    v1539.write(v1555); // v1539[k63] = v1555;	// L2098
    float v1556 = b57;	// L2099
    v1540.write(v1556); // v1540[k63] = v1556;	// L2100
  }
  float v1557 = v57;	// L2102
  v1541[v1542][v1543] = v1557;	// L2103
}

void PE_kernel_QKT_2_2(
  hls::stream< float > &v1558 /* v1558[4] */,
  hls::stream< float > &v1559 /* v1559[4] */,
  hls::stream< float > &v1560 /* v1560[4] */,
  hls::stream< float > &v1561 /* v1561[4] */,
  float v1562[4][4],
  int v1563,
  int v1564
) {	// L2106
  #pragma HLS stream variable=v1558 depth=5
  #pragma HLS stream variable=v1559 depth=5
  #pragma HLS stream variable=v1560 depth=5
  #pragma HLS stream variable=v1561 depth=5
  #pragma HLS array_partition variable=v1562 complete dim=1
  #pragma HLS array_partition variable=v1562 complete dim=2

  float v58;	// L2109
  v58 = 0.000000;	// L2110
  l_S_k_0_k64: for (int k64 = 0; k64 < 4; k64++) {	// L2111
    float v1567 = v1558.read(); // v1558[k64];	// L2112
    float a58;	// L2113
    a58 = v1567;	// L2114
    float v1569 = v1559.read(); // v1559[k64];	// L2115
    float b58;	// L2116
    b58 = v1569;	// L2117
    float v1571 = a58;	// L2118
    float v1572 = b58;	// L2119
    float v1573 = v1571 * v1572;	// L2120
    float v1574 = v58;	// L2121
    float v1575 = v1574 + v1573;	// L2122
    v58 = v1575;	// L2123
    float v1576 = a58;	// L2124
    v1560.write(v1576); // v1560[k64] = v1576;	// L2125
    float v1577 = b58;	// L2126
    v1561.write(v1577); // v1561[k64] = v1577;	// L2127
  }
  float v1578 = v58;	// L2129
  v1562[v1563][v1564] = v1578;	// L2130
}

void PE_kernel_QKT_3_2(
  hls::stream< float > &v1579 /* v1579[4] */,
  hls::stream< float > &v1580 /* v1580[4] */,
  hls::stream< float > &v1581 /* v1581[4] */,
  hls::stream< float > &v1582 /* v1582[4] */,
  float v1583[4][4],
  int v1584,
  int v1585
) {	// L2133
  #pragma HLS stream variable=v1579 depth=5
  #pragma HLS stream variable=v1580 depth=5
  #pragma HLS stream variable=v1581 depth=5
  #pragma HLS stream variable=v1582 depth=5
  #pragma HLS array_partition variable=v1583 complete dim=1
  #pragma HLS array_partition variable=v1583 complete dim=2

  float v59;	// L2136
  v59 = 0.000000;	// L2137
  l_S_k_0_k65: for (int k65 = 0; k65 < 4; k65++) {	// L2138
    float v1588 = v1579.read(); // v1579[k65];	// L2139
    float a59;	// L2140
    a59 = v1588;	// L2141
    float v1590 = v1580.read(); // v1580[k65];	// L2142
    float b59;	// L2143
    b59 = v1590;	// L2144
    float v1592 = a59;	// L2145
    float v1593 = b59;	// L2146
    float v1594 = v1592 * v1593;	// L2147
    float v1595 = v59;	// L2148
    float v1596 = v1595 + v1594;	// L2149
    v59 = v1596;	// L2150
    float v1597 = a59;	// L2151
    v1581.write(v1597); // v1581[k65] = v1597;	// L2152
    float v1598 = b59;	// L2153
    v1582.write(v1598); // v1582[k65] = v1598;	// L2154
  }
  float v1599 = v59;	// L2156
  v1583[v1584][v1585] = v1599;	// L2157
}

void PE_kernel_QKT_0_3(
  hls::stream< float > &v1600 /* v1600[4] */,
  hls::stream< float > &v1601 /* v1601[4] */,
  hls::stream< float > &v1602 /* v1602[4] */,
  hls::stream< float > &v1603 /* v1603[4] */,
  float v1604[4][4],
  int v1605,
  int v1606
) {	// L2160
  #pragma HLS stream variable=v1600 depth=5
  #pragma HLS stream variable=v1601 depth=5
  #pragma HLS stream variable=v1602 depth=5
  #pragma HLS stream variable=v1603 depth=5
  #pragma HLS array_partition variable=v1604 complete dim=1
  #pragma HLS array_partition variable=v1604 complete dim=2

  float v60;	// L2163
  v60 = 0.000000;	// L2164
  l_S_k_0_k66: for (int k66 = 0; k66 < 4; k66++) {	// L2165
    float v1609 = v1600.read(); // v1600[k66];	// L2166
    float a60;	// L2167
    a60 = v1609;	// L2168
    float v1611 = v1601.read(); // v1601[k66];	// L2169
    float b60;	// L2170
    b60 = v1611;	// L2171
    float v1613 = a60;	// L2172
    float v1614 = b60;	// L2173
    float v1615 = v1613 * v1614;	// L2174
    float v1616 = v60;	// L2175
    float v1617 = v1616 + v1615;	// L2176
    v60 = v1617;	// L2177
    float v1618 = a60;	// L2178
    v1602.write(v1618); // v1602[k66] = v1618;	// L2179
    float v1619 = b60;	// L2180
    v1603.write(v1619); // v1603[k66] = v1619;	// L2181
  }
  float v1620 = v60;	// L2183
  v1604[v1605][v1606] = v1620;	// L2184
}

void PE_kernel_QKT_1_3(
  hls::stream< float > &v1621 /* v1621[4] */,
  hls::stream< float > &v1622 /* v1622[4] */,
  hls::stream< float > &v1623 /* v1623[4] */,
  hls::stream< float > &v1624 /* v1624[4] */,
  float v1625[4][4],
  int v1626,
  int v1627
) {	// L2187
  #pragma HLS stream variable=v1621 depth=5
  #pragma HLS stream variable=v1622 depth=5
  #pragma HLS stream variable=v1623 depth=5
  #pragma HLS stream variable=v1624 depth=5
  #pragma HLS array_partition variable=v1625 complete dim=1
  #pragma HLS array_partition variable=v1625 complete dim=2

  float v61;	// L2190
  v61 = 0.000000;	// L2191
  l_S_k_0_k67: for (int k67 = 0; k67 < 4; k67++) {	// L2192
    float v1630 = v1621.read(); // v1621[k67];	// L2193
    float a61;	// L2194
    a61 = v1630;	// L2195
    float v1632 = v1622.read(); // v1622[k67];	// L2196
    float b61;	// L2197
    b61 = v1632;	// L2198
    float v1634 = a61;	// L2199
    float v1635 = b61;	// L2200
    float v1636 = v1634 * v1635;	// L2201
    float v1637 = v61;	// L2202
    float v1638 = v1637 + v1636;	// L2203
    v61 = v1638;	// L2204
    float v1639 = a61;	// L2205
    v1623.write(v1639); // v1623[k67] = v1639;	// L2206
    float v1640 = b61;	// L2207
    v1624.write(v1640); // v1624[k67] = v1640;	// L2208
  }
  float v1641 = v61;	// L2210
  v1625[v1626][v1627] = v1641;	// L2211
}

void PE_kernel_QKT_2_3(
  hls::stream< float > &v1642 /* v1642[4] */,
  hls::stream< float > &v1643 /* v1643[4] */,
  hls::stream< float > &v1644 /* v1644[4] */,
  hls::stream< float > &v1645 /* v1645[4] */,
  float v1646[4][4],
  int v1647,
  int v1648
) {	// L2214
  #pragma HLS stream variable=v1642 depth=5
  #pragma HLS stream variable=v1643 depth=5
  #pragma HLS stream variable=v1644 depth=5
  #pragma HLS stream variable=v1645 depth=5
  #pragma HLS array_partition variable=v1646 complete dim=1
  #pragma HLS array_partition variable=v1646 complete dim=2

  float v62;	// L2217
  v62 = 0.000000;	// L2218
  l_S_k_0_k68: for (int k68 = 0; k68 < 4; k68++) {	// L2219
    float v1651 = v1642.read(); // v1642[k68];	// L2220
    float a62;	// L2221
    a62 = v1651;	// L2222
    float v1653 = v1643.read(); // v1643[k68];	// L2223
    float b62;	// L2224
    b62 = v1653;	// L2225
    float v1655 = a62;	// L2226
    float v1656 = b62;	// L2227
    float v1657 = v1655 * v1656;	// L2228
    float v1658 = v62;	// L2229
    float v1659 = v1658 + v1657;	// L2230
    v62 = v1659;	// L2231
    float v1660 = a62;	// L2232
    v1644.write(v1660); // v1644[k68] = v1660;	// L2233
    float v1661 = b62;	// L2234
    v1645.write(v1661); // v1645[k68] = v1661;	// L2235
  }
  float v1662 = v62;	// L2237
  v1646[v1647][v1648] = v1662;	// L2238
}

void PE_kernel_QKT_3_3(
  hls::stream< float > &v1663 /* v1663[4] */,
  hls::stream< float > &v1664 /* v1664[4] */,
  hls::stream< float > &v1665 /* v1665[4] */,
  hls::stream< float > &v1666 /* v1666[4] */,
  float v1667[4][4],
  int v1668,
  int v1669
) {	// L2241
  #pragma HLS stream variable=v1663 depth=5
  #pragma HLS stream variable=v1664 depth=5
  #pragma HLS stream variable=v1665 depth=5
  #pragma HLS stream variable=v1666 depth=5
  #pragma HLS array_partition variable=v1667 complete dim=1
  #pragma HLS array_partition variable=v1667 complete dim=2

  float v63;	// L2244
  v63 = 0.000000;	// L2245
  l_S_k_0_k69: for (int k69 = 0; k69 < 4; k69++) {	// L2246
    float v1672 = v1663.read(); // v1663[k69];	// L2247
    float a63;	// L2248
    a63 = v1672;	// L2249
    float v1674 = v1664.read(); // v1664[k69];	// L2250
    float b63;	// L2251
    b63 = v1674;	// L2252
    float v1676 = a63;	// L2253
    float v1677 = b63;	// L2254
    float v1678 = v1676 * v1677;	// L2255
    float v1679 = v63;	// L2256
    float v1680 = v1679 + v1678;	// L2257
    v63 = v1680;	// L2258
    float v1681 = a63;	// L2259
    v1665.write(v1681); // v1665[k69] = v1681;	// L2260
    float v1682 = b63;	// L2261
    v1666.write(v1682); // v1666[k69] = v1682;	// L2262
  }
  float v1683 = v63;	// L2264
  v1667[v1668][v1669] = v1683;	// L2265
}

void systolic_tile_QKT(
  float v1684[4][4],
  float v1685[4][4],
  float v1686[4][4]
) {	// L2268
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v1684 complete dim=1

  #pragma HLS array_partition variable=v1685 complete dim=2

  #pragma HLS array_partition variable=v1686 complete dim=1
  #pragma HLS array_partition variable=v1686 complete dim=2

  hls::stream< float > A_fifo3[4][5] /* A_fifo3[4][5][4] */;	// L2269
  #pragma HLS stream variable=A_fifo3 depth=5
  hls::stream< float > B_fifo3[4][5] /* B_fifo3[4][5][4] */;	// L2270
  #pragma HLS stream variable=B_fifo3 depth=5
  float A_drain3[4];	// L2271
  float B_drain3[4];	// L2272
  l_data_load_k70: for (int k70 = 0; k70 < 4; k70++) {	// L2273
    l_S_m_0_m6: for (int m6 = 0; m6 < 4; m6++) {	// L2274
      float v1693 = v1684[m6][k70];	// L2275
      A_fifo3[m6][0].write(v1693); // A_fifo3[m6][0][k70] = v1693;	// L2276
    }
    l_S_n_1_n6: for (int n6 = 0; n6 < 4; n6++) {	// L2278
      float v1695 = v1685[k70][n6];	// L2279
      B_fifo3[n6][0].write(v1695); // B_fifo3[n6][0][k70] = v1695;	// L2280
    }
  }
  hls::stream< float > &v1696 /* v1696[4] */ = A_fifo3[0][0];	// L2284
  hls::stream< float > &v1697 /* v1697[4] */ = B_fifo3[0][0];	// L2285
  hls::stream< float > &v1698 /* v1698[4] */ = A_fifo3[0][1];	// L2291
  hls::stream< float > &v1699 /* v1699[4] */ = B_fifo3[0][1];	// L2292
  PE_kernel_QKT_0_0(v1696, v1697, v1698, v1699, v1686, 0, 0);	// L2293
  hls::stream< float > &v1700 /* v1700[4] */ = A_fifo3[0][1];	// L2295
  hls::stream< float > &v1701 /* v1701[4] */ = B_fifo3[1][0];	// L2296
  hls::stream< float > &v1702 /* v1702[4] */ = A_fifo3[0][2];	// L2300
  hls::stream< float > &v1703 /* v1703[4] */ = B_fifo3[1][1];	// L2301
  PE_kernel_QKT_1_0(v1700, v1701, v1702, v1703, v1686, 0, 1);	// L2302
  hls::stream< float > &v1704 /* v1704[4] */ = A_fifo3[0][2];	// L2304
  hls::stream< float > &v1705 /* v1705[4] */ = B_fifo3[2][0];	// L2305
  hls::stream< float > &v1706 /* v1706[4] */ = A_fifo3[0][3];	// L2309
  hls::stream< float > &v1707 /* v1707[4] */ = B_fifo3[2][1];	// L2310
  PE_kernel_QKT_2_0(v1704, v1705, v1706, v1707, v1686, 0, 2);	// L2311
  hls::stream< float > &v1708 /* v1708[4] */ = A_fifo3[0][3];	// L2313
  hls::stream< float > &v1709 /* v1709[4] */ = B_fifo3[3][0];	// L2314
  hls::stream< float > &v1710 /* v1710[4] */ = A_fifo3[0][4];	// L2318
  hls::stream< float > &v1711 /* v1711[4] */ = B_fifo3[3][1];	// L2319
  PE_kernel_QKT_3_0(v1708, v1709, v1710, v1711, v1686, 0, 3);	// L2320
  hls::stream< float > &v1712 /* v1712[4] */ = A_fifo3[1][0];	// L2321
  hls::stream< float > &v1713 /* v1713[4] */ = B_fifo3[0][1];	// L2322
  hls::stream< float > &v1714 /* v1714[4] */ = A_fifo3[1][1];	// L2323
  hls::stream< float > &v1715 /* v1715[4] */ = B_fifo3[0][2];	// L2324
  PE_kernel_QKT_0_1(v1712, v1713, v1714, v1715, v1686, 1, 0);	// L2325
  hls::stream< float > &v1716 /* v1716[4] */ = A_fifo3[1][1];	// L2326
  hls::stream< float > &v1717 /* v1717[4] */ = B_fifo3[1][1];	// L2327
  hls::stream< float > &v1718 /* v1718[4] */ = A_fifo3[1][2];	// L2328
  hls::stream< float > &v1719 /* v1719[4] */ = B_fifo3[1][2];	// L2329
  PE_kernel_QKT_1_1(v1716, v1717, v1718, v1719, v1686, 1, 1);	// L2330
  hls::stream< float > &v1720 /* v1720[4] */ = A_fifo3[1][2];	// L2331
  hls::stream< float > &v1721 /* v1721[4] */ = B_fifo3[2][1];	// L2332
  hls::stream< float > &v1722 /* v1722[4] */ = A_fifo3[1][3];	// L2333
  hls::stream< float > &v1723 /* v1723[4] */ = B_fifo3[2][2];	// L2334
  PE_kernel_QKT_2_1(v1720, v1721, v1722, v1723, v1686, 1, 2);	// L2335
  hls::stream< float > &v1724 /* v1724[4] */ = A_fifo3[1][3];	// L2336
  hls::stream< float > &v1725 /* v1725[4] */ = B_fifo3[3][1];	// L2337
  hls::stream< float > &v1726 /* v1726[4] */ = A_fifo3[1][4];	// L2338
  hls::stream< float > &v1727 /* v1727[4] */ = B_fifo3[3][2];	// L2339
  PE_kernel_QKT_3_1(v1724, v1725, v1726, v1727, v1686, 1, 3);	// L2340
  hls::stream< float > &v1728 /* v1728[4] */ = A_fifo3[2][0];	// L2341
  hls::stream< float > &v1729 /* v1729[4] */ = B_fifo3[0][2];	// L2342
  hls::stream< float > &v1730 /* v1730[4] */ = A_fifo3[2][1];	// L2343
  hls::stream< float > &v1731 /* v1731[4] */ = B_fifo3[0][3];	// L2344
  PE_kernel_QKT_0_2(v1728, v1729, v1730, v1731, v1686, 2, 0);	// L2345
  hls::stream< float > &v1732 /* v1732[4] */ = A_fifo3[2][1];	// L2346
  hls::stream< float > &v1733 /* v1733[4] */ = B_fifo3[1][2];	// L2347
  hls::stream< float > &v1734 /* v1734[4] */ = A_fifo3[2][2];	// L2348
  hls::stream< float > &v1735 /* v1735[4] */ = B_fifo3[1][3];	// L2349
  PE_kernel_QKT_1_2(v1732, v1733, v1734, v1735, v1686, 2, 1);	// L2350
  hls::stream< float > &v1736 /* v1736[4] */ = A_fifo3[2][2];	// L2351
  hls::stream< float > &v1737 /* v1737[4] */ = B_fifo3[2][2];	// L2352
  hls::stream< float > &v1738 /* v1738[4] */ = A_fifo3[2][3];	// L2353
  hls::stream< float > &v1739 /* v1739[4] */ = B_fifo3[2][3];	// L2354
  PE_kernel_QKT_2_2(v1736, v1737, v1738, v1739, v1686, 2, 2);	// L2355
  hls::stream< float > &v1740 /* v1740[4] */ = A_fifo3[2][3];	// L2356
  hls::stream< float > &v1741 /* v1741[4] */ = B_fifo3[3][2];	// L2357
  hls::stream< float > &v1742 /* v1742[4] */ = A_fifo3[2][4];	// L2358
  hls::stream< float > &v1743 /* v1743[4] */ = B_fifo3[3][3];	// L2359
  PE_kernel_QKT_3_2(v1740, v1741, v1742, v1743, v1686, 2, 3);	// L2360
  hls::stream< float > &v1744 /* v1744[4] */ = A_fifo3[3][0];	// L2361
  hls::stream< float > &v1745 /* v1745[4] */ = B_fifo3[0][3];	// L2362
  hls::stream< float > &v1746 /* v1746[4] */ = A_fifo3[3][1];	// L2363
  hls::stream< float > &v1747 /* v1747[4] */ = B_fifo3[0][4];	// L2364
  PE_kernel_QKT_0_3(v1744, v1745, v1746, v1747, v1686, 3, 0);	// L2365
  hls::stream< float > &v1748 /* v1748[4] */ = A_fifo3[3][1];	// L2366
  hls::stream< float > &v1749 /* v1749[4] */ = B_fifo3[1][3];	// L2367
  hls::stream< float > &v1750 /* v1750[4] */ = A_fifo3[3][2];	// L2368
  hls::stream< float > &v1751 /* v1751[4] */ = B_fifo3[1][4];	// L2369
  PE_kernel_QKT_1_3(v1748, v1749, v1750, v1751, v1686, 3, 1);	// L2370
  hls::stream< float > &v1752 /* v1752[4] */ = A_fifo3[3][2];	// L2371
  hls::stream< float > &v1753 /* v1753[4] */ = B_fifo3[2][3];	// L2372
  hls::stream< float > &v1754 /* v1754[4] */ = A_fifo3[3][3];	// L2373
  hls::stream< float > &v1755 /* v1755[4] */ = B_fifo3[2][4];	// L2374
  PE_kernel_QKT_2_3(v1752, v1753, v1754, v1755, v1686, 3, 2);	// L2375
  hls::stream< float > &v1756 /* v1756[4] */ = A_fifo3[3][3];	// L2376
  hls::stream< float > &v1757 /* v1757[4] */ = B_fifo3[3][3];	// L2377
  hls::stream< float > &v1758 /* v1758[4] */ = A_fifo3[3][4];	// L2378
  hls::stream< float > &v1759 /* v1759[4] */ = B_fifo3[3][4];	// L2379
  PE_kernel_QKT_3_3(v1756, v1757, v1758, v1759, v1686, 3, 3);	// L2380
  l_data_drain_k71: for (int k71 = 0; k71 < 4; k71++) {	// L2381
    l_S_m_4_m7: for (int m7 = 0; m7 < 4; m7++) {	// L2382
      float v1762 = A_fifo3[m7][4].read(); // A_fifo3[m7][4][k71];	// L2383
      A_drain3[m7] = v1762;	// L2384
    }
    l_S_n_5_n7: for (int n7 = 0; n7 < 4; n7++) {	// L2386
      float v1764 = B_fifo3[n7][4].read(); // B_fifo3[n7][4][k71];	// L2387
      B_drain3[n7] = v1764;	// L2388
    }
  }
}

void systolic_QKT(
  float v1765[32][4],
  float v1766[4][32],
  float v1767[32][32]
) {	// L2393
  float local_A3[4][4];	// L2394
  #pragma HLS array_partition variable=local_A3 complete dim=1

  float local_B3[4][4];	// L2395
  #pragma HLS array_partition variable=local_B3 complete dim=2

  float local_C3[4][4];	// L2396
  #pragma HLS array_partition variable=local_C3 complete dim=1
  #pragma HLS array_partition variable=local_C3 complete dim=2

  l_outer_tile_mi3: for (int mi3 = 0; mi3 < 8; mi3++) {	// L2397
    l_ni3: for (int ni3 = 0; ni3 < 8; ni3++) {	// L2398
    #pragma HLS dataflow
      l_load_A_tile_ak3: for (int ak3 = 0; ak3 < 4; ak3++) {	// L2399
        l_ai3: for (int ai3 = 0; ai3 < 4; ai3++) {	// L2400
        #pragma HLS pipeline II=1
          ap_int<33> v1775 = ni3;	// L2401
          bool v1776 = v1775 == 0;	// L2404
          if (v1776) {	// L2405
            float v1777 = v1765[((mi3 * 4) + ai3)][ak3];	// L2406
            local_A3[ai3][ak3] = v1777;	// L2407
          }
        }
      }
      l_load_B_tile_bk3: for (int bk3 = 0; bk3 < 4; bk3++) {	// L2411
        l_bj3: for (int bj3 = 0; bj3 < 4; bj3++) {	// L2412
        #pragma HLS pipeline II=1
          float v1780 = v1766[bk3][((ni3 * 4) + bj3)];	// L2413
          local_B3[bk3][bj3] = v1780;	// L2414
        }
      }
      systolic_tile_QKT(local_A3, local_B3, local_C3);	// L2417
      l_store_C_tile_sj3: for (int sj3 = 0; sj3 < 4; sj3++) {	// L2418
        l_si3: for (int si3 = 0; si3 < 4; si3++) {	// L2419
        #pragma HLS pipeline II=1
          float v1783 = local_C3[si3][sj3];	// L2420
          v1767[((mi3 * 4) + si3)][((ni3 * 4) + sj3)] = v1783;	// L2421
        }
      }
    }
  }
}

void mask_sft_head_sft_Y(
  float v1784[32][32],
  int32_t v1785[2],
  float v1786[32][32]
) {	// L2428
  float E[32][32];	// L2430
  float S[32];	// L2431
  for (int v1789 = 0; v1789 < 32; v1789++) {	// L2433
    S[v1789] = 0.000000;	// L2433
  }
  float M[32];	// L2436
  for (int v1791 = 0; v1791 < 32; v1791++) {	// L2437
    M[v1791] = -10000000272564224.000000;	// L2437
  }
  l_row_max_i3: for (int i3 = 0; i3 < 32; i3++) {	// L2438
    l_j2: for (int j2 = 0; j2 < 32; j2++) {	// L2439
    #pragma HLS pipeline II=1
      bool v1794 = i3 >= j2;	// L2440
      if (v1794) {	// L2441
        int32_t v1795 = v1785[0];	// L2442
        ap_int<33> v1796 = v1795;	// L2445
        ap_int<33> v1797 = 32 - v1796;	// L2446
        ap_int<33> v1798 = i3;	// L2447
        bool v1799 = v1798 >= v1797;	// L2448
        if (v1799) {	// L2449
          int32_t v1800 = v1785[0];	// L2450
          ap_int<33> v1801 = v1800;	// L2451
          ap_int<33> v1802 = 32 - v1801;	// L2452
          ap_int<33> v1803 = j2;	// L2453
          bool v1804 = v1803 >= v1802;	// L2454
          if (v1804) {	// L2455
            float v1805 = v1784[i3][j2];	// L2456
            float v1806 = M[i3];	// L2457
            bool v1807 = v1805 > v1806;	// L2458
            if (v1807) {	// L2459
              float v1808 = v1784[i3][j2];	// L2460
              M[i3] = v1808;	// L2461
            }
          }
        }
      }
    }
  }
  l_exp_sum_i4: for (int i4 = 0; i4 < 32; i4++) {	// L2468
    l_j3: for (int j3 = 0; j3 < 32; j3++) {	// L2469
    #pragma HLS pipeline II=1
      bool v1811 = i4 >= j3;	// L2470
      if (v1811) {	// L2471
        int32_t v1812 = v1785[0];	// L2472
        ap_int<33> v1813 = v1812;	// L2475
        ap_int<33> v1814 = 32 - v1813;	// L2476
        ap_int<33> v1815 = i4;	// L2477
        bool v1816 = v1815 >= v1814;	// L2478
        if (v1816) {	// L2479
          int32_t v1817 = v1785[0];	// L2480
          ap_int<33> v1818 = v1817;	// L2481
          ap_int<33> v1819 = 32 - v1818;	// L2482
          ap_int<33> v1820 = j3;	// L2483
          bool v1821 = v1820 >= v1819;	// L2484
          if (v1821) {	// L2485
            float v1822 = v1784[i4][j3];	// L2486
            float v1823 = M[i4];	// L2487
            float v1824 = v1822 - v1823;	// L2488
            float v1825 = exp(v1824);	// L2489
            E[i4][j3] = v1825;	// L2490
            float v1826 = E[i4][j3];	// L2491
            float v1827 = S[i4];	// L2492
            float v1828 = v1827 + v1826;	// L2493
            S[i4] = v1828;	// L2494
          }
        }
      }
    }
  }
  l_update_i5: for (int i5 = 0; i5 < 32; i5++) {	// L2500
    l_j4: for (int j4 = 0; j4 < 32; j4++) {	// L2501
    #pragma HLS pipeline II=1
      bool v1831 = i5 >= j4;	// L2502
      if (v1831) {	// L2503
        int32_t v1832 = v1785[0];	// L2504
        ap_int<33> v1833 = v1832;	// L2507
        ap_int<33> v1834 = 32 - v1833;	// L2508
        ap_int<33> v1835 = i5;	// L2509
        bool v1836 = v1835 >= v1834;	// L2510
        if (v1836) {	// L2511
          int32_t v1837 = v1785[0];	// L2512
          ap_int<33> v1838 = v1837;	// L2513
          ap_int<33> v1839 = 32 - v1838;	// L2514
          ap_int<33> v1840 = j4;	// L2515
          bool v1841 = v1840 >= v1839;	// L2516
          if (v1841) {	// L2517
            float v1842 = E[i5][j4];	// L2518
            float v1843 = S[i5];	// L2519
            float v1844 = v1842 / v1843;	// L2520
            v1786[i5][j4] = v1844;	// L2521
          } else {
            v1786[i5][j4] = 0.000000;	// L2525
          }
        } else {
          ap_int<34> v1845 = i5;	// L2528
          ap_int<34> v1846 = v1845 + 1;	// L2531
          int32_t v1847 = v1785[0];	// L2532
          ap_int<35> v1848 = v1846;	// L2533
          ap_int<35> v1849 = v1847;	// L2534
          ap_int<35> v1850 = v1848 + v1849;	// L2535
          float v1851 = v1850;	// L2536
          float v1852 = 1.000000 / v1851;	// L2538
          v1786[i5][j4] = v1852;	// L2539
        }
      } else {
        int32_t v1853 = v1785[0];	// L2542
        ap_int<33> v1854 = v1853;	// L2545
        ap_int<33> v1855 = 32 - v1854;	// L2546
        ap_int<33> v1856 = i5;	// L2547
        bool v1857 = v1856 < v1855;	// L2548
        ap_int<33> v1858 = j4;	// L2549
        bool v1859 = v1858 >= v1855;	// L2550
        bool v1860 = v1857 & v1859;	// L2551
        if (v1860) {	// L2552
          ap_int<34> v1861 = i5;	// L2553
          ap_int<34> v1862 = v1861 + 1;	// L2556
          int32_t v1863 = v1785[0];	// L2557
          ap_int<35> v1864 = v1862;	// L2558
          ap_int<35> v1865 = v1863;	// L2559
          ap_int<35> v1866 = v1864 + v1865;	// L2560
          float v1867 = v1866;	// L2561
          float v1868 = 1.000000 / v1867;	// L2563
          v1786[i5][j4] = v1868;	// L2564
        } else {
          v1786[i5][j4] = 0.000000;	// L2568
        }
      }
    }
  }
}

void PE_kernel_YV_0_0(
  hls::stream< float > &v1869 /* v1869[32] */,
  hls::stream< float > &v1870 /* v1870[32] */,
  hls::stream< float > &v1871 /* v1871[32] */,
  hls::stream< float > &v1872 /* v1872[32] */,
  float v1873[4][4],
  int v1874,
  int v1875
) {	// L2575
  #pragma HLS stream variable=v1869 depth=5
  #pragma HLS stream variable=v1870 depth=5
  #pragma HLS stream variable=v1871 depth=5
  #pragma HLS stream variable=v1872 depth=5
  #pragma HLS array_partition variable=v1873 complete dim=1
  #pragma HLS array_partition variable=v1873 complete dim=2

  float v64;	// L2578
  v64 = 0.000000;	// L2579
  l_S_k_0_k72: for (int k72 = 0; k72 < 32; k72++) {	// L2580
    float v1878 = v1869.read(); // v1869[k72];	// L2581
    float a64;	// L2582
    a64 = v1878;	// L2583
    float v1880 = v1870.read(); // v1870[k72];	// L2584
    float b64;	// L2585
    b64 = v1880;	// L2586
    float v1882 = a64;	// L2587
    float v1883 = b64;	// L2588
    float v1884 = v1882 * v1883;	// L2589
    float v1885 = v64;	// L2590
    float v1886 = v1885 + v1884;	// L2591
    v64 = v1886;	// L2592
    float v1887 = a64;	// L2593
    v1871.write(v1887); // v1871[k72] = v1887;	// L2594
    float v1888 = b64;	// L2595
    v1872.write(v1888); // v1872[k72] = v1888;	// L2596
  }
  float v1889 = v64;	// L2598
  v1873[v1874][v1875] = v1889;	// L2599
}

void PE_kernel_YV_1_0(
  hls::stream< float > &v1890 /* v1890[32] */,
  hls::stream< float > &v1891 /* v1891[32] */,
  hls::stream< float > &v1892 /* v1892[32] */,
  hls::stream< float > &v1893 /* v1893[32] */,
  float v1894[4][4],
  int v1895,
  int v1896
) {	// L2602
  #pragma HLS stream variable=v1890 depth=5
  #pragma HLS stream variable=v1891 depth=5
  #pragma HLS stream variable=v1892 depth=5
  #pragma HLS stream variable=v1893 depth=5
  #pragma HLS array_partition variable=v1894 complete dim=1
  #pragma HLS array_partition variable=v1894 complete dim=2

  float v65;	// L2605
  v65 = 0.000000;	// L2606
  l_S_k_0_k73: for (int k73 = 0; k73 < 32; k73++) {	// L2607
    float v1899 = v1890.read(); // v1890[k73];	// L2608
    float a65;	// L2609
    a65 = v1899;	// L2610
    float v1901 = v1891.read(); // v1891[k73];	// L2611
    float b65;	// L2612
    b65 = v1901;	// L2613
    float v1903 = a65;	// L2614
    float v1904 = b65;	// L2615
    float v1905 = v1903 * v1904;	// L2616
    float v1906 = v65;	// L2617
    float v1907 = v1906 + v1905;	// L2618
    v65 = v1907;	// L2619
    float v1908 = a65;	// L2620
    v1892.write(v1908); // v1892[k73] = v1908;	// L2621
    float v1909 = b65;	// L2622
    v1893.write(v1909); // v1893[k73] = v1909;	// L2623
  }
  float v1910 = v65;	// L2625
  v1894[v1895][v1896] = v1910;	// L2626
}

void PE_kernel_YV_2_0(
  hls::stream< float > &v1911 /* v1911[32] */,
  hls::stream< float > &v1912 /* v1912[32] */,
  hls::stream< float > &v1913 /* v1913[32] */,
  hls::stream< float > &v1914 /* v1914[32] */,
  float v1915[4][4],
  int v1916,
  int v1917
) {	// L2629
  #pragma HLS stream variable=v1911 depth=5
  #pragma HLS stream variable=v1912 depth=5
  #pragma HLS stream variable=v1913 depth=5
  #pragma HLS stream variable=v1914 depth=5
  #pragma HLS array_partition variable=v1915 complete dim=1
  #pragma HLS array_partition variable=v1915 complete dim=2

  float v66;	// L2632
  v66 = 0.000000;	// L2633
  l_S_k_0_k74: for (int k74 = 0; k74 < 32; k74++) {	// L2634
    float v1920 = v1911.read(); // v1911[k74];	// L2635
    float a66;	// L2636
    a66 = v1920;	// L2637
    float v1922 = v1912.read(); // v1912[k74];	// L2638
    float b66;	// L2639
    b66 = v1922;	// L2640
    float v1924 = a66;	// L2641
    float v1925 = b66;	// L2642
    float v1926 = v1924 * v1925;	// L2643
    float v1927 = v66;	// L2644
    float v1928 = v1927 + v1926;	// L2645
    v66 = v1928;	// L2646
    float v1929 = a66;	// L2647
    v1913.write(v1929); // v1913[k74] = v1929;	// L2648
    float v1930 = b66;	// L2649
    v1914.write(v1930); // v1914[k74] = v1930;	// L2650
  }
  float v1931 = v66;	// L2652
  v1915[v1916][v1917] = v1931;	// L2653
}

void PE_kernel_YV_3_0(
  hls::stream< float > &v1932 /* v1932[32] */,
  hls::stream< float > &v1933 /* v1933[32] */,
  hls::stream< float > &v1934 /* v1934[32] */,
  hls::stream< float > &v1935 /* v1935[32] */,
  float v1936[4][4],
  int v1937,
  int v1938
) {	// L2656
  #pragma HLS stream variable=v1932 depth=5
  #pragma HLS stream variable=v1933 depth=5
  #pragma HLS stream variable=v1934 depth=5
  #pragma HLS stream variable=v1935 depth=5
  #pragma HLS array_partition variable=v1936 complete dim=1
  #pragma HLS array_partition variable=v1936 complete dim=2

  float v67;	// L2659
  v67 = 0.000000;	// L2660
  l_S_k_0_k75: for (int k75 = 0; k75 < 32; k75++) {	// L2661
    float v1941 = v1932.read(); // v1932[k75];	// L2662
    float a67;	// L2663
    a67 = v1941;	// L2664
    float v1943 = v1933.read(); // v1933[k75];	// L2665
    float b67;	// L2666
    b67 = v1943;	// L2667
    float v1945 = a67;	// L2668
    float v1946 = b67;	// L2669
    float v1947 = v1945 * v1946;	// L2670
    float v1948 = v67;	// L2671
    float v1949 = v1948 + v1947;	// L2672
    v67 = v1949;	// L2673
    float v1950 = a67;	// L2674
    v1934.write(v1950); // v1934[k75] = v1950;	// L2675
    float v1951 = b67;	// L2676
    v1935.write(v1951); // v1935[k75] = v1951;	// L2677
  }
  float v1952 = v67;	// L2679
  v1936[v1937][v1938] = v1952;	// L2680
}

void PE_kernel_YV_0_1(
  hls::stream< float > &v1953 /* v1953[32] */,
  hls::stream< float > &v1954 /* v1954[32] */,
  hls::stream< float > &v1955 /* v1955[32] */,
  hls::stream< float > &v1956 /* v1956[32] */,
  float v1957[4][4],
  int v1958,
  int v1959
) {	// L2683
  #pragma HLS stream variable=v1953 depth=5
  #pragma HLS stream variable=v1954 depth=5
  #pragma HLS stream variable=v1955 depth=5
  #pragma HLS stream variable=v1956 depth=5
  #pragma HLS array_partition variable=v1957 complete dim=1
  #pragma HLS array_partition variable=v1957 complete dim=2

  float v68;	// L2686
  v68 = 0.000000;	// L2687
  l_S_k_0_k76: for (int k76 = 0; k76 < 32; k76++) {	// L2688
    float v1962 = v1953.read(); // v1953[k76];	// L2689
    float a68;	// L2690
    a68 = v1962;	// L2691
    float v1964 = v1954.read(); // v1954[k76];	// L2692
    float b68;	// L2693
    b68 = v1964;	// L2694
    float v1966 = a68;	// L2695
    float v1967 = b68;	// L2696
    float v1968 = v1966 * v1967;	// L2697
    float v1969 = v68;	// L2698
    float v1970 = v1969 + v1968;	// L2699
    v68 = v1970;	// L2700
    float v1971 = a68;	// L2701
    v1955.write(v1971); // v1955[k76] = v1971;	// L2702
    float v1972 = b68;	// L2703
    v1956.write(v1972); // v1956[k76] = v1972;	// L2704
  }
  float v1973 = v68;	// L2706
  v1957[v1958][v1959] = v1973;	// L2707
}

void PE_kernel_YV_1_1(
  hls::stream< float > &v1974 /* v1974[32] */,
  hls::stream< float > &v1975 /* v1975[32] */,
  hls::stream< float > &v1976 /* v1976[32] */,
  hls::stream< float > &v1977 /* v1977[32] */,
  float v1978[4][4],
  int v1979,
  int v1980
) {	// L2710
  #pragma HLS stream variable=v1974 depth=5
  #pragma HLS stream variable=v1975 depth=5
  #pragma HLS stream variable=v1976 depth=5
  #pragma HLS stream variable=v1977 depth=5
  #pragma HLS array_partition variable=v1978 complete dim=1
  #pragma HLS array_partition variable=v1978 complete dim=2

  float v69;	// L2713
  v69 = 0.000000;	// L2714
  l_S_k_0_k77: for (int k77 = 0; k77 < 32; k77++) {	// L2715
    float v1983 = v1974.read(); // v1974[k77];	// L2716
    float a69;	// L2717
    a69 = v1983;	// L2718
    float v1985 = v1975.read(); // v1975[k77];	// L2719
    float b69;	// L2720
    b69 = v1985;	// L2721
    float v1987 = a69;	// L2722
    float v1988 = b69;	// L2723
    float v1989 = v1987 * v1988;	// L2724
    float v1990 = v69;	// L2725
    float v1991 = v1990 + v1989;	// L2726
    v69 = v1991;	// L2727
    float v1992 = a69;	// L2728
    v1976.write(v1992); // v1976[k77] = v1992;	// L2729
    float v1993 = b69;	// L2730
    v1977.write(v1993); // v1977[k77] = v1993;	// L2731
  }
  float v1994 = v69;	// L2733
  v1978[v1979][v1980] = v1994;	// L2734
}

void PE_kernel_YV_2_1(
  hls::stream< float > &v1995 /* v1995[32] */,
  hls::stream< float > &v1996 /* v1996[32] */,
  hls::stream< float > &v1997 /* v1997[32] */,
  hls::stream< float > &v1998 /* v1998[32] */,
  float v1999[4][4],
  int v2000,
  int v2001
) {	// L2737
  #pragma HLS stream variable=v1995 depth=5
  #pragma HLS stream variable=v1996 depth=5
  #pragma HLS stream variable=v1997 depth=5
  #pragma HLS stream variable=v1998 depth=5
  #pragma HLS array_partition variable=v1999 complete dim=1
  #pragma HLS array_partition variable=v1999 complete dim=2

  float v70;	// L2740
  v70 = 0.000000;	// L2741
  l_S_k_0_k78: for (int k78 = 0; k78 < 32; k78++) {	// L2742
    float v2004 = v1995.read(); // v1995[k78];	// L2743
    float a70;	// L2744
    a70 = v2004;	// L2745
    float v2006 = v1996.read(); // v1996[k78];	// L2746
    float b70;	// L2747
    b70 = v2006;	// L2748
    float v2008 = a70;	// L2749
    float v2009 = b70;	// L2750
    float v2010 = v2008 * v2009;	// L2751
    float v2011 = v70;	// L2752
    float v2012 = v2011 + v2010;	// L2753
    v70 = v2012;	// L2754
    float v2013 = a70;	// L2755
    v1997.write(v2013); // v1997[k78] = v2013;	// L2756
    float v2014 = b70;	// L2757
    v1998.write(v2014); // v1998[k78] = v2014;	// L2758
  }
  float v2015 = v70;	// L2760
  v1999[v2000][v2001] = v2015;	// L2761
}

void PE_kernel_YV_3_1(
  hls::stream< float > &v2016 /* v2016[32] */,
  hls::stream< float > &v2017 /* v2017[32] */,
  hls::stream< float > &v2018 /* v2018[32] */,
  hls::stream< float > &v2019 /* v2019[32] */,
  float v2020[4][4],
  int v2021,
  int v2022
) {	// L2764
  #pragma HLS stream variable=v2016 depth=5
  #pragma HLS stream variable=v2017 depth=5
  #pragma HLS stream variable=v2018 depth=5
  #pragma HLS stream variable=v2019 depth=5
  #pragma HLS array_partition variable=v2020 complete dim=1
  #pragma HLS array_partition variable=v2020 complete dim=2

  float v71;	// L2767
  v71 = 0.000000;	// L2768
  l_S_k_0_k79: for (int k79 = 0; k79 < 32; k79++) {	// L2769
    float v2025 = v2016.read(); // v2016[k79];	// L2770
    float a71;	// L2771
    a71 = v2025;	// L2772
    float v2027 = v2017.read(); // v2017[k79];	// L2773
    float b71;	// L2774
    b71 = v2027;	// L2775
    float v2029 = a71;	// L2776
    float v2030 = b71;	// L2777
    float v2031 = v2029 * v2030;	// L2778
    float v2032 = v71;	// L2779
    float v2033 = v2032 + v2031;	// L2780
    v71 = v2033;	// L2781
    float v2034 = a71;	// L2782
    v2018.write(v2034); // v2018[k79] = v2034;	// L2783
    float v2035 = b71;	// L2784
    v2019.write(v2035); // v2019[k79] = v2035;	// L2785
  }
  float v2036 = v71;	// L2787
  v2020[v2021][v2022] = v2036;	// L2788
}

void PE_kernel_YV_0_2(
  hls::stream< float > &v2037 /* v2037[32] */,
  hls::stream< float > &v2038 /* v2038[32] */,
  hls::stream< float > &v2039 /* v2039[32] */,
  hls::stream< float > &v2040 /* v2040[32] */,
  float v2041[4][4],
  int v2042,
  int v2043
) {	// L2791
  #pragma HLS stream variable=v2037 depth=5
  #pragma HLS stream variable=v2038 depth=5
  #pragma HLS stream variable=v2039 depth=5
  #pragma HLS stream variable=v2040 depth=5
  #pragma HLS array_partition variable=v2041 complete dim=1
  #pragma HLS array_partition variable=v2041 complete dim=2

  float v72;	// L2794
  v72 = 0.000000;	// L2795
  l_S_k_0_k80: for (int k80 = 0; k80 < 32; k80++) {	// L2796
    float v2046 = v2037.read(); // v2037[k80];	// L2797
    float a72;	// L2798
    a72 = v2046;	// L2799
    float v2048 = v2038.read(); // v2038[k80];	// L2800
    float b72;	// L2801
    b72 = v2048;	// L2802
    float v2050 = a72;	// L2803
    float v2051 = b72;	// L2804
    float v2052 = v2050 * v2051;	// L2805
    float v2053 = v72;	// L2806
    float v2054 = v2053 + v2052;	// L2807
    v72 = v2054;	// L2808
    float v2055 = a72;	// L2809
    v2039.write(v2055); // v2039[k80] = v2055;	// L2810
    float v2056 = b72;	// L2811
    v2040.write(v2056); // v2040[k80] = v2056;	// L2812
  }
  float v2057 = v72;	// L2814
  v2041[v2042][v2043] = v2057;	// L2815
}

void PE_kernel_YV_1_2(
  hls::stream< float > &v2058 /* v2058[32] */,
  hls::stream< float > &v2059 /* v2059[32] */,
  hls::stream< float > &v2060 /* v2060[32] */,
  hls::stream< float > &v2061 /* v2061[32] */,
  float v2062[4][4],
  int v2063,
  int v2064
) {	// L2818
  #pragma HLS stream variable=v2058 depth=5
  #pragma HLS stream variable=v2059 depth=5
  #pragma HLS stream variable=v2060 depth=5
  #pragma HLS stream variable=v2061 depth=5
  #pragma HLS array_partition variable=v2062 complete dim=1
  #pragma HLS array_partition variable=v2062 complete dim=2

  float v73;	// L2821
  v73 = 0.000000;	// L2822
  l_S_k_0_k81: for (int k81 = 0; k81 < 32; k81++) {	// L2823
    float v2067 = v2058.read(); // v2058[k81];	// L2824
    float a73;	// L2825
    a73 = v2067;	// L2826
    float v2069 = v2059.read(); // v2059[k81];	// L2827
    float b73;	// L2828
    b73 = v2069;	// L2829
    float v2071 = a73;	// L2830
    float v2072 = b73;	// L2831
    float v2073 = v2071 * v2072;	// L2832
    float v2074 = v73;	// L2833
    float v2075 = v2074 + v2073;	// L2834
    v73 = v2075;	// L2835
    float v2076 = a73;	// L2836
    v2060.write(v2076); // v2060[k81] = v2076;	// L2837
    float v2077 = b73;	// L2838
    v2061.write(v2077); // v2061[k81] = v2077;	// L2839
  }
  float v2078 = v73;	// L2841
  v2062[v2063][v2064] = v2078;	// L2842
}

void PE_kernel_YV_2_2(
  hls::stream< float > &v2079 /* v2079[32] */,
  hls::stream< float > &v2080 /* v2080[32] */,
  hls::stream< float > &v2081 /* v2081[32] */,
  hls::stream< float > &v2082 /* v2082[32] */,
  float v2083[4][4],
  int v2084,
  int v2085
) {	// L2845
  #pragma HLS stream variable=v2079 depth=5
  #pragma HLS stream variable=v2080 depth=5
  #pragma HLS stream variable=v2081 depth=5
  #pragma HLS stream variable=v2082 depth=5
  #pragma HLS array_partition variable=v2083 complete dim=1
  #pragma HLS array_partition variable=v2083 complete dim=2

  float v74;	// L2848
  v74 = 0.000000;	// L2849
  l_S_k_0_k82: for (int k82 = 0; k82 < 32; k82++) {	// L2850
    float v2088 = v2079.read(); // v2079[k82];	// L2851
    float a74;	// L2852
    a74 = v2088;	// L2853
    float v2090 = v2080.read(); // v2080[k82];	// L2854
    float b74;	// L2855
    b74 = v2090;	// L2856
    float v2092 = a74;	// L2857
    float v2093 = b74;	// L2858
    float v2094 = v2092 * v2093;	// L2859
    float v2095 = v74;	// L2860
    float v2096 = v2095 + v2094;	// L2861
    v74 = v2096;	// L2862
    float v2097 = a74;	// L2863
    v2081.write(v2097); // v2081[k82] = v2097;	// L2864
    float v2098 = b74;	// L2865
    v2082.write(v2098); // v2082[k82] = v2098;	// L2866
  }
  float v2099 = v74;	// L2868
  v2083[v2084][v2085] = v2099;	// L2869
}

void PE_kernel_YV_3_2(
  hls::stream< float > &v2100 /* v2100[32] */,
  hls::stream< float > &v2101 /* v2101[32] */,
  hls::stream< float > &v2102 /* v2102[32] */,
  hls::stream< float > &v2103 /* v2103[32] */,
  float v2104[4][4],
  int v2105,
  int v2106
) {	// L2872
  #pragma HLS stream variable=v2100 depth=5
  #pragma HLS stream variable=v2101 depth=5
  #pragma HLS stream variable=v2102 depth=5
  #pragma HLS stream variable=v2103 depth=5
  #pragma HLS array_partition variable=v2104 complete dim=1
  #pragma HLS array_partition variable=v2104 complete dim=2

  float v75;	// L2875
  v75 = 0.000000;	// L2876
  l_S_k_0_k83: for (int k83 = 0; k83 < 32; k83++) {	// L2877
    float v2109 = v2100.read(); // v2100[k83];	// L2878
    float a75;	// L2879
    a75 = v2109;	// L2880
    float v2111 = v2101.read(); // v2101[k83];	// L2881
    float b75;	// L2882
    b75 = v2111;	// L2883
    float v2113 = a75;	// L2884
    float v2114 = b75;	// L2885
    float v2115 = v2113 * v2114;	// L2886
    float v2116 = v75;	// L2887
    float v2117 = v2116 + v2115;	// L2888
    v75 = v2117;	// L2889
    float v2118 = a75;	// L2890
    v2102.write(v2118); // v2102[k83] = v2118;	// L2891
    float v2119 = b75;	// L2892
    v2103.write(v2119); // v2103[k83] = v2119;	// L2893
  }
  float v2120 = v75;	// L2895
  v2104[v2105][v2106] = v2120;	// L2896
}

void PE_kernel_YV_0_3(
  hls::stream< float > &v2121 /* v2121[32] */,
  hls::stream< float > &v2122 /* v2122[32] */,
  hls::stream< float > &v2123 /* v2123[32] */,
  hls::stream< float > &v2124 /* v2124[32] */,
  float v2125[4][4],
  int v2126,
  int v2127
) {	// L2899
  #pragma HLS stream variable=v2121 depth=5
  #pragma HLS stream variable=v2122 depth=5
  #pragma HLS stream variable=v2123 depth=5
  #pragma HLS stream variable=v2124 depth=5
  #pragma HLS array_partition variable=v2125 complete dim=1
  #pragma HLS array_partition variable=v2125 complete dim=2

  float v76;	// L2902
  v76 = 0.000000;	// L2903
  l_S_k_0_k84: for (int k84 = 0; k84 < 32; k84++) {	// L2904
    float v2130 = v2121.read(); // v2121[k84];	// L2905
    float a76;	// L2906
    a76 = v2130;	// L2907
    float v2132 = v2122.read(); // v2122[k84];	// L2908
    float b76;	// L2909
    b76 = v2132;	// L2910
    float v2134 = a76;	// L2911
    float v2135 = b76;	// L2912
    float v2136 = v2134 * v2135;	// L2913
    float v2137 = v76;	// L2914
    float v2138 = v2137 + v2136;	// L2915
    v76 = v2138;	// L2916
    float v2139 = a76;	// L2917
    v2123.write(v2139); // v2123[k84] = v2139;	// L2918
    float v2140 = b76;	// L2919
    v2124.write(v2140); // v2124[k84] = v2140;	// L2920
  }
  float v2141 = v76;	// L2922
  v2125[v2126][v2127] = v2141;	// L2923
}

void PE_kernel_YV_1_3(
  hls::stream< float > &v2142 /* v2142[32] */,
  hls::stream< float > &v2143 /* v2143[32] */,
  hls::stream< float > &v2144 /* v2144[32] */,
  hls::stream< float > &v2145 /* v2145[32] */,
  float v2146[4][4],
  int v2147,
  int v2148
) {	// L2926
  #pragma HLS stream variable=v2142 depth=5
  #pragma HLS stream variable=v2143 depth=5
  #pragma HLS stream variable=v2144 depth=5
  #pragma HLS stream variable=v2145 depth=5
  #pragma HLS array_partition variable=v2146 complete dim=1
  #pragma HLS array_partition variable=v2146 complete dim=2

  float v77;	// L2929
  v77 = 0.000000;	// L2930
  l_S_k_0_k85: for (int k85 = 0; k85 < 32; k85++) {	// L2931
    float v2151 = v2142.read(); // v2142[k85];	// L2932
    float a77;	// L2933
    a77 = v2151;	// L2934
    float v2153 = v2143.read(); // v2143[k85];	// L2935
    float b77;	// L2936
    b77 = v2153;	// L2937
    float v2155 = a77;	// L2938
    float v2156 = b77;	// L2939
    float v2157 = v2155 * v2156;	// L2940
    float v2158 = v77;	// L2941
    float v2159 = v2158 + v2157;	// L2942
    v77 = v2159;	// L2943
    float v2160 = a77;	// L2944
    v2144.write(v2160); // v2144[k85] = v2160;	// L2945
    float v2161 = b77;	// L2946
    v2145.write(v2161); // v2145[k85] = v2161;	// L2947
  }
  float v2162 = v77;	// L2949
  v2146[v2147][v2148] = v2162;	// L2950
}

void PE_kernel_YV_2_3(
  hls::stream< float > &v2163 /* v2163[32] */,
  hls::stream< float > &v2164 /* v2164[32] */,
  hls::stream< float > &v2165 /* v2165[32] */,
  hls::stream< float > &v2166 /* v2166[32] */,
  float v2167[4][4],
  int v2168,
  int v2169
) {	// L2953
  #pragma HLS stream variable=v2163 depth=5
  #pragma HLS stream variable=v2164 depth=5
  #pragma HLS stream variable=v2165 depth=5
  #pragma HLS stream variable=v2166 depth=5
  #pragma HLS array_partition variable=v2167 complete dim=1
  #pragma HLS array_partition variable=v2167 complete dim=2

  float v78;	// L2956
  v78 = 0.000000;	// L2957
  l_S_k_0_k86: for (int k86 = 0; k86 < 32; k86++) {	// L2958
    float v2172 = v2163.read(); // v2163[k86];	// L2959
    float a78;	// L2960
    a78 = v2172;	// L2961
    float v2174 = v2164.read(); // v2164[k86];	// L2962
    float b78;	// L2963
    b78 = v2174;	// L2964
    float v2176 = a78;	// L2965
    float v2177 = b78;	// L2966
    float v2178 = v2176 * v2177;	// L2967
    float v2179 = v78;	// L2968
    float v2180 = v2179 + v2178;	// L2969
    v78 = v2180;	// L2970
    float v2181 = a78;	// L2971
    v2165.write(v2181); // v2165[k86] = v2181;	// L2972
    float v2182 = b78;	// L2973
    v2166.write(v2182); // v2166[k86] = v2182;	// L2974
  }
  float v2183 = v78;	// L2976
  v2167[v2168][v2169] = v2183;	// L2977
}

void PE_kernel_YV_3_3(
  hls::stream< float > &v2184 /* v2184[32] */,
  hls::stream< float > &v2185 /* v2185[32] */,
  hls::stream< float > &v2186 /* v2186[32] */,
  hls::stream< float > &v2187 /* v2187[32] */,
  float v2188[4][4],
  int v2189,
  int v2190
) {	// L2980
  #pragma HLS stream variable=v2184 depth=5
  #pragma HLS stream variable=v2185 depth=5
  #pragma HLS stream variable=v2186 depth=5
  #pragma HLS stream variable=v2187 depth=5
  #pragma HLS array_partition variable=v2188 complete dim=1
  #pragma HLS array_partition variable=v2188 complete dim=2

  float v79;	// L2983
  v79 = 0.000000;	// L2984
  l_S_k_0_k87: for (int k87 = 0; k87 < 32; k87++) {	// L2985
    float v2193 = v2184.read(); // v2184[k87];	// L2986
    float a79;	// L2987
    a79 = v2193;	// L2988
    float v2195 = v2185.read(); // v2185[k87];	// L2989
    float b79;	// L2990
    b79 = v2195;	// L2991
    float v2197 = a79;	// L2992
    float v2198 = b79;	// L2993
    float v2199 = v2197 * v2198;	// L2994
    float v2200 = v79;	// L2995
    float v2201 = v2200 + v2199;	// L2996
    v79 = v2201;	// L2997
    float v2202 = a79;	// L2998
    v2186.write(v2202); // v2186[k87] = v2202;	// L2999
    float v2203 = b79;	// L3000
    v2187.write(v2203); // v2187[k87] = v2203;	// L3001
  }
  float v2204 = v79;	// L3003
  v2188[v2189][v2190] = v2204;	// L3004
}

void systolic_tile_YV(
  float v2205[4][32],
  float v2206[32][4],
  float v2207[4][4]
) {	// L3007
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v2205 complete dim=1

  #pragma HLS array_partition variable=v2206 complete dim=2

  #pragma HLS array_partition variable=v2207 complete dim=1
  #pragma HLS array_partition variable=v2207 complete dim=2

  hls::stream< float > A_fifo4[4][5] /* A_fifo4[4][5][32] */;	// L3008
  #pragma HLS stream variable=A_fifo4 depth=5
  hls::stream< float > B_fifo4[4][5] /* B_fifo4[4][5][32] */;	// L3009
  #pragma HLS stream variable=B_fifo4 depth=5
  float A_drain4[4];	// L3010
  float B_drain4[4];	// L3011
  l_data_load_k88: for (int k88 = 0; k88 < 32; k88++) {	// L3012
    l_S_m_0_m8: for (int m8 = 0; m8 < 4; m8++) {	// L3013
      float v2214 = v2205[m8][k88];	// L3014
      A_fifo4[m8][0].write(v2214); // A_fifo4[m8][0][k88] = v2214;	// L3015
    }
    l_S_n_1_n8: for (int n8 = 0; n8 < 4; n8++) {	// L3017
      float v2216 = v2206[k88][n8];	// L3018
      B_fifo4[n8][0].write(v2216); // B_fifo4[n8][0][k88] = v2216;	// L3019
    }
  }
  hls::stream< float > &v2217 /* v2217[32] */ = A_fifo4[0][0];	// L3023
  hls::stream< float > &v2218 /* v2218[32] */ = B_fifo4[0][0];	// L3024
  hls::stream< float > &v2219 /* v2219[32] */ = A_fifo4[0][1];	// L3030
  hls::stream< float > &v2220 /* v2220[32] */ = B_fifo4[0][1];	// L3031
  PE_kernel_YV_0_0(v2217, v2218, v2219, v2220, v2207, 0, 0);	// L3032
  hls::stream< float > &v2221 /* v2221[32] */ = A_fifo4[0][1];	// L3034
  hls::stream< float > &v2222 /* v2222[32] */ = B_fifo4[1][0];	// L3035
  hls::stream< float > &v2223 /* v2223[32] */ = A_fifo4[0][2];	// L3039
  hls::stream< float > &v2224 /* v2224[32] */ = B_fifo4[1][1];	// L3040
  PE_kernel_YV_1_0(v2221, v2222, v2223, v2224, v2207, 0, 1);	// L3041
  hls::stream< float > &v2225 /* v2225[32] */ = A_fifo4[0][2];	// L3043
  hls::stream< float > &v2226 /* v2226[32] */ = B_fifo4[2][0];	// L3044
  hls::stream< float > &v2227 /* v2227[32] */ = A_fifo4[0][3];	// L3048
  hls::stream< float > &v2228 /* v2228[32] */ = B_fifo4[2][1];	// L3049
  PE_kernel_YV_2_0(v2225, v2226, v2227, v2228, v2207, 0, 2);	// L3050
  hls::stream< float > &v2229 /* v2229[32] */ = A_fifo4[0][3];	// L3052
  hls::stream< float > &v2230 /* v2230[32] */ = B_fifo4[3][0];	// L3053
  hls::stream< float > &v2231 /* v2231[32] */ = A_fifo4[0][4];	// L3057
  hls::stream< float > &v2232 /* v2232[32] */ = B_fifo4[3][1];	// L3058
  PE_kernel_YV_3_0(v2229, v2230, v2231, v2232, v2207, 0, 3);	// L3059
  hls::stream< float > &v2233 /* v2233[32] */ = A_fifo4[1][0];	// L3060
  hls::stream< float > &v2234 /* v2234[32] */ = B_fifo4[0][1];	// L3061
  hls::stream< float > &v2235 /* v2235[32] */ = A_fifo4[1][1];	// L3062
  hls::stream< float > &v2236 /* v2236[32] */ = B_fifo4[0][2];	// L3063
  PE_kernel_YV_0_1(v2233, v2234, v2235, v2236, v2207, 1, 0);	// L3064
  hls::stream< float > &v2237 /* v2237[32] */ = A_fifo4[1][1];	// L3065
  hls::stream< float > &v2238 /* v2238[32] */ = B_fifo4[1][1];	// L3066
  hls::stream< float > &v2239 /* v2239[32] */ = A_fifo4[1][2];	// L3067
  hls::stream< float > &v2240 /* v2240[32] */ = B_fifo4[1][2];	// L3068
  PE_kernel_YV_1_1(v2237, v2238, v2239, v2240, v2207, 1, 1);	// L3069
  hls::stream< float > &v2241 /* v2241[32] */ = A_fifo4[1][2];	// L3070
  hls::stream< float > &v2242 /* v2242[32] */ = B_fifo4[2][1];	// L3071
  hls::stream< float > &v2243 /* v2243[32] */ = A_fifo4[1][3];	// L3072
  hls::stream< float > &v2244 /* v2244[32] */ = B_fifo4[2][2];	// L3073
  PE_kernel_YV_2_1(v2241, v2242, v2243, v2244, v2207, 1, 2);	// L3074
  hls::stream< float > &v2245 /* v2245[32] */ = A_fifo4[1][3];	// L3075
  hls::stream< float > &v2246 /* v2246[32] */ = B_fifo4[3][1];	// L3076
  hls::stream< float > &v2247 /* v2247[32] */ = A_fifo4[1][4];	// L3077
  hls::stream< float > &v2248 /* v2248[32] */ = B_fifo4[3][2];	// L3078
  PE_kernel_YV_3_1(v2245, v2246, v2247, v2248, v2207, 1, 3);	// L3079
  hls::stream< float > &v2249 /* v2249[32] */ = A_fifo4[2][0];	// L3080
  hls::stream< float > &v2250 /* v2250[32] */ = B_fifo4[0][2];	// L3081
  hls::stream< float > &v2251 /* v2251[32] */ = A_fifo4[2][1];	// L3082
  hls::stream< float > &v2252 /* v2252[32] */ = B_fifo4[0][3];	// L3083
  PE_kernel_YV_0_2(v2249, v2250, v2251, v2252, v2207, 2, 0);	// L3084
  hls::stream< float > &v2253 /* v2253[32] */ = A_fifo4[2][1];	// L3085
  hls::stream< float > &v2254 /* v2254[32] */ = B_fifo4[1][2];	// L3086
  hls::stream< float > &v2255 /* v2255[32] */ = A_fifo4[2][2];	// L3087
  hls::stream< float > &v2256 /* v2256[32] */ = B_fifo4[1][3];	// L3088
  PE_kernel_YV_1_2(v2253, v2254, v2255, v2256, v2207, 2, 1);	// L3089
  hls::stream< float > &v2257 /* v2257[32] */ = A_fifo4[2][2];	// L3090
  hls::stream< float > &v2258 /* v2258[32] */ = B_fifo4[2][2];	// L3091
  hls::stream< float > &v2259 /* v2259[32] */ = A_fifo4[2][3];	// L3092
  hls::stream< float > &v2260 /* v2260[32] */ = B_fifo4[2][3];	// L3093
  PE_kernel_YV_2_2(v2257, v2258, v2259, v2260, v2207, 2, 2);	// L3094
  hls::stream< float > &v2261 /* v2261[32] */ = A_fifo4[2][3];	// L3095
  hls::stream< float > &v2262 /* v2262[32] */ = B_fifo4[3][2];	// L3096
  hls::stream< float > &v2263 /* v2263[32] */ = A_fifo4[2][4];	// L3097
  hls::stream< float > &v2264 /* v2264[32] */ = B_fifo4[3][3];	// L3098
  PE_kernel_YV_3_2(v2261, v2262, v2263, v2264, v2207, 2, 3);	// L3099
  hls::stream< float > &v2265 /* v2265[32] */ = A_fifo4[3][0];	// L3100
  hls::stream< float > &v2266 /* v2266[32] */ = B_fifo4[0][3];	// L3101
  hls::stream< float > &v2267 /* v2267[32] */ = A_fifo4[3][1];	// L3102
  hls::stream< float > &v2268 /* v2268[32] */ = B_fifo4[0][4];	// L3103
  PE_kernel_YV_0_3(v2265, v2266, v2267, v2268, v2207, 3, 0);	// L3104
  hls::stream< float > &v2269 /* v2269[32] */ = A_fifo4[3][1];	// L3105
  hls::stream< float > &v2270 /* v2270[32] */ = B_fifo4[1][3];	// L3106
  hls::stream< float > &v2271 /* v2271[32] */ = A_fifo4[3][2];	// L3107
  hls::stream< float > &v2272 /* v2272[32] */ = B_fifo4[1][4];	// L3108
  PE_kernel_YV_1_3(v2269, v2270, v2271, v2272, v2207, 3, 1);	// L3109
  hls::stream< float > &v2273 /* v2273[32] */ = A_fifo4[3][2];	// L3110
  hls::stream< float > &v2274 /* v2274[32] */ = B_fifo4[2][3];	// L3111
  hls::stream< float > &v2275 /* v2275[32] */ = A_fifo4[3][3];	// L3112
  hls::stream< float > &v2276 /* v2276[32] */ = B_fifo4[2][4];	// L3113
  PE_kernel_YV_2_3(v2273, v2274, v2275, v2276, v2207, 3, 2);	// L3114
  hls::stream< float > &v2277 /* v2277[32] */ = A_fifo4[3][3];	// L3115
  hls::stream< float > &v2278 /* v2278[32] */ = B_fifo4[3][3];	// L3116
  hls::stream< float > &v2279 /* v2279[32] */ = A_fifo4[3][4];	// L3117
  hls::stream< float > &v2280 /* v2280[32] */ = B_fifo4[3][4];	// L3118
  PE_kernel_YV_3_3(v2277, v2278, v2279, v2280, v2207, 3, 3);	// L3119
  l_data_drain_k89: for (int k89 = 0; k89 < 32; k89++) {	// L3120
    l_S_m_4_m9: for (int m9 = 0; m9 < 4; m9++) {	// L3121
      float v2283 = A_fifo4[m9][4].read(); // A_fifo4[m9][4][k89];	// L3122
      A_drain4[m9] = v2283;	// L3123
    }
    l_S_n_5_n9: for (int n9 = 0; n9 < 4; n9++) {	// L3125
      float v2285 = B_fifo4[n9][4].read(); // B_fifo4[n9][4][k89];	// L3126
      B_drain4[n9] = v2285;	// L3127
    }
  }
}

void systolic_YV(
  float v2286[32][32],
  float v2287[32][4],
  float v2288[32][4]
) {	// L3132
  float local_A4[4][32];	// L3133
  #pragma HLS array_partition variable=local_A4 complete dim=1

  float local_B4[32][4];	// L3134
  #pragma HLS array_partition variable=local_B4 complete dim=2

  float local_C4[4][4];	// L3135
  #pragma HLS array_partition variable=local_C4 complete dim=1
  #pragma HLS array_partition variable=local_C4 complete dim=2

  l_outer_tile_mi4: for (int mi4 = 0; mi4 < 8; mi4++) {	// L3136
    l_ni4: for (int ni4 = 0; ni4 < 1; ni4++) {	// L3137
    #pragma HLS dataflow
      l_load_A_tile_ak4: for (int ak4 = 0; ak4 < 32; ak4++) {	// L3138
        l_ai4: for (int ai4 = 0; ai4 < 4; ai4++) {	// L3139
        #pragma HLS pipeline II=1
          ap_int<33> v2296 = ni4;	// L3140
          bool v2297 = v2296 == 0;	// L3143
          if (v2297) {	// L3144
            float v2298 = v2286[((mi4 * 4) + ai4)][ak4];	// L3145
            local_A4[ai4][ak4] = v2298;	// L3146
          }
        }
      }
      l_load_B_tile_bk4: for (int bk4 = 0; bk4 < 32; bk4++) {	// L3150
        l_bj4: for (int bj4 = 0; bj4 < 4; bj4++) {	// L3151
        #pragma HLS pipeline II=1
          float v2301 = v2287[bk4][((ni4 * 4) + bj4)];	// L3152
          local_B4[bk4][bj4] = v2301;	// L3153
        }
      }
      systolic_tile_YV(local_A4, local_B4, local_C4);	// L3156
      l_store_C_tile_sj4: for (int sj4 = 0; sj4 < 4; sj4++) {	// L3157
        l_si4: for (int si4 = 0; si4 < 4; si4++) {	// L3158
        #pragma HLS pipeline II=1
          float v2304 = local_C4[si4][sj4];	// L3159
          v2288[((mi4 * 4) + si4)][((ni4 * 4) + sj4)] = v2304;	// L3160
        }
      }
    }
  }
}

void masked_casual_sdp(
  float v2305[32][48],
  float v2306[32][48],
  float v2307[32][48],
  int32_t v2308[2],
  float v2309[32][48]
) {	// L3167
  l_S_h_0_h: for (int h = 0; h < 12; h++) {	// L3169
    float Q_h[32][4];	// L3170
    float K_h[4][32];	// L3171
    float V_h[32][4];	// L3172
    l_mha_split_i6: for (int i6 = 0; i6 < 32; i6++) {	// L3173
      l_j5: for (int j5 = 0; j5 < 4; j5++) {	// L3174
        float v2316 = v2305[i6][((h * 4) + j5)];	// L3175
        Q_h[i6][j5] = v2316;	// L3176
        float v2317 = v2306[i6][((h * 4) + j5)];	// L3177
        K_h[j5][i6] = v2317;	// L3178
        float v2318 = v2307[i6][((h * 4) + j5)];	// L3179
        V_h[i6][j5] = v2318;	// L3180
      }
    }
    float C_h[32][4];	// L3185
    for (int v2320 = 0; v2320 < 32; v2320++) {	// L3186
      for (int v2321 = 0; v2321 < 4; v2321++) {	// L3186
        C_h[v2320][v2321] = 0.000000;	// L3186
      }
    }
    float Y[32][32];	// L3187
    for (int v2323 = 0; v2323 < 32; v2323++) {	// L3188
      for (int v2324 = 0; v2324 < 32; v2324++) {	// L3188
        Y[v2323][v2324] = 0.000000;	// L3188
      }
    }
    systolic_QKT(Q_h, K_h, Y);	// L3189
    float v2325[32][32];
    mask_sft_head_sft_Y(Y, v2308, v2325);	// L3190
    systolic_YV(v2325, V_h, C_h);	// L3191
    l_mha_merge_i7: for (int i7 = 0; i7 < 32; i7++) {	// L3192
      l_j6: for (int j6 = 0; j6 < 4; j6++) {	// L3193
        float v2328 = C_h[i7][j6];	// L3194
        v2309[i7][((h * 4) + j6)] = v2328;	// L3195
      }
    }
  }
}

void PE_kernel_P_0_0(
  hls::stream< float > &v2329 /* v2329[48] */,
  hls::stream< float > &v2330 /* v2330[48] */,
  hls::stream< float > &v2331 /* v2331[48] */,
  hls::stream< float > &v2332 /* v2332[48] */,
  float v2333[4][4],
  int v2334,
  int v2335
) {	// L3201
  #pragma HLS stream variable=v2329 depth=5
  #pragma HLS stream variable=v2330 depth=5
  #pragma HLS stream variable=v2331 depth=5
  #pragma HLS stream variable=v2332 depth=5
  #pragma HLS array_partition variable=v2333 complete dim=1
  #pragma HLS array_partition variable=v2333 complete dim=2

  float v80;	// L3204
  v80 = 0.000000;	// L3205
  l_S_k_0_k90: for (int k90 = 0; k90 < 48; k90++) {	// L3206
    float v2338 = v2329.read(); // v2329[k90];	// L3207
    float a80;	// L3208
    a80 = v2338;	// L3209
    float v2340 = v2330.read(); // v2330[k90];	// L3210
    float b80;	// L3211
    b80 = v2340;	// L3212
    float v2342 = a80;	// L3213
    float v2343 = b80;	// L3214
    float v2344 = v2342 * v2343;	// L3215
    float v2345 = v80;	// L3216
    float v2346 = v2345 + v2344;	// L3217
    v80 = v2346;	// L3218
    float v2347 = a80;	// L3219
    v2331.write(v2347); // v2331[k90] = v2347;	// L3220
    float v2348 = b80;	// L3221
    v2332.write(v2348); // v2332[k90] = v2348;	// L3222
  }
  float v2349 = v80;	// L3224
  v2333[v2334][v2335] = v2349;	// L3225
}

void PE_kernel_P_1_0(
  hls::stream< float > &v2350 /* v2350[48] */,
  hls::stream< float > &v2351 /* v2351[48] */,
  hls::stream< float > &v2352 /* v2352[48] */,
  hls::stream< float > &v2353 /* v2353[48] */,
  float v2354[4][4],
  int v2355,
  int v2356
) {	// L3228
  #pragma HLS stream variable=v2350 depth=5
  #pragma HLS stream variable=v2351 depth=5
  #pragma HLS stream variable=v2352 depth=5
  #pragma HLS stream variable=v2353 depth=5
  #pragma HLS array_partition variable=v2354 complete dim=1
  #pragma HLS array_partition variable=v2354 complete dim=2

  float v81;	// L3231
  v81 = 0.000000;	// L3232
  l_S_k_0_k91: for (int k91 = 0; k91 < 48; k91++) {	// L3233
    float v2359 = v2350.read(); // v2350[k91];	// L3234
    float a81;	// L3235
    a81 = v2359;	// L3236
    float v2361 = v2351.read(); // v2351[k91];	// L3237
    float b81;	// L3238
    b81 = v2361;	// L3239
    float v2363 = a81;	// L3240
    float v2364 = b81;	// L3241
    float v2365 = v2363 * v2364;	// L3242
    float v2366 = v81;	// L3243
    float v2367 = v2366 + v2365;	// L3244
    v81 = v2367;	// L3245
    float v2368 = a81;	// L3246
    v2352.write(v2368); // v2352[k91] = v2368;	// L3247
    float v2369 = b81;	// L3248
    v2353.write(v2369); // v2353[k91] = v2369;	// L3249
  }
  float v2370 = v81;	// L3251
  v2354[v2355][v2356] = v2370;	// L3252
}

void PE_kernel_P_2_0(
  hls::stream< float > &v2371 /* v2371[48] */,
  hls::stream< float > &v2372 /* v2372[48] */,
  hls::stream< float > &v2373 /* v2373[48] */,
  hls::stream< float > &v2374 /* v2374[48] */,
  float v2375[4][4],
  int v2376,
  int v2377
) {	// L3255
  #pragma HLS stream variable=v2371 depth=5
  #pragma HLS stream variable=v2372 depth=5
  #pragma HLS stream variable=v2373 depth=5
  #pragma HLS stream variable=v2374 depth=5
  #pragma HLS array_partition variable=v2375 complete dim=1
  #pragma HLS array_partition variable=v2375 complete dim=2

  float v82;	// L3258
  v82 = 0.000000;	// L3259
  l_S_k_0_k92: for (int k92 = 0; k92 < 48; k92++) {	// L3260
    float v2380 = v2371.read(); // v2371[k92];	// L3261
    float a82;	// L3262
    a82 = v2380;	// L3263
    float v2382 = v2372.read(); // v2372[k92];	// L3264
    float b82;	// L3265
    b82 = v2382;	// L3266
    float v2384 = a82;	// L3267
    float v2385 = b82;	// L3268
    float v2386 = v2384 * v2385;	// L3269
    float v2387 = v82;	// L3270
    float v2388 = v2387 + v2386;	// L3271
    v82 = v2388;	// L3272
    float v2389 = a82;	// L3273
    v2373.write(v2389); // v2373[k92] = v2389;	// L3274
    float v2390 = b82;	// L3275
    v2374.write(v2390); // v2374[k92] = v2390;	// L3276
  }
  float v2391 = v82;	// L3278
  v2375[v2376][v2377] = v2391;	// L3279
}

void PE_kernel_P_3_0(
  hls::stream< float > &v2392 /* v2392[48] */,
  hls::stream< float > &v2393 /* v2393[48] */,
  hls::stream< float > &v2394 /* v2394[48] */,
  hls::stream< float > &v2395 /* v2395[48] */,
  float v2396[4][4],
  int v2397,
  int v2398
) {	// L3282
  #pragma HLS stream variable=v2392 depth=5
  #pragma HLS stream variable=v2393 depth=5
  #pragma HLS stream variable=v2394 depth=5
  #pragma HLS stream variable=v2395 depth=5
  #pragma HLS array_partition variable=v2396 complete dim=1
  #pragma HLS array_partition variable=v2396 complete dim=2

  float v83;	// L3285
  v83 = 0.000000;	// L3286
  l_S_k_0_k93: for (int k93 = 0; k93 < 48; k93++) {	// L3287
    float v2401 = v2392.read(); // v2392[k93];	// L3288
    float a83;	// L3289
    a83 = v2401;	// L3290
    float v2403 = v2393.read(); // v2393[k93];	// L3291
    float b83;	// L3292
    b83 = v2403;	// L3293
    float v2405 = a83;	// L3294
    float v2406 = b83;	// L3295
    float v2407 = v2405 * v2406;	// L3296
    float v2408 = v83;	// L3297
    float v2409 = v2408 + v2407;	// L3298
    v83 = v2409;	// L3299
    float v2410 = a83;	// L3300
    v2394.write(v2410); // v2394[k93] = v2410;	// L3301
    float v2411 = b83;	// L3302
    v2395.write(v2411); // v2395[k93] = v2411;	// L3303
  }
  float v2412 = v83;	// L3305
  v2396[v2397][v2398] = v2412;	// L3306
}

void PE_kernel_P_0_1(
  hls::stream< float > &v2413 /* v2413[48] */,
  hls::stream< float > &v2414 /* v2414[48] */,
  hls::stream< float > &v2415 /* v2415[48] */,
  hls::stream< float > &v2416 /* v2416[48] */,
  float v2417[4][4],
  int v2418,
  int v2419
) {	// L3309
  #pragma HLS stream variable=v2413 depth=5
  #pragma HLS stream variable=v2414 depth=5
  #pragma HLS stream variable=v2415 depth=5
  #pragma HLS stream variable=v2416 depth=5
  #pragma HLS array_partition variable=v2417 complete dim=1
  #pragma HLS array_partition variable=v2417 complete dim=2

  float v84;	// L3312
  v84 = 0.000000;	// L3313
  l_S_k_0_k94: for (int k94 = 0; k94 < 48; k94++) {	// L3314
    float v2422 = v2413.read(); // v2413[k94];	// L3315
    float a84;	// L3316
    a84 = v2422;	// L3317
    float v2424 = v2414.read(); // v2414[k94];	// L3318
    float b84;	// L3319
    b84 = v2424;	// L3320
    float v2426 = a84;	// L3321
    float v2427 = b84;	// L3322
    float v2428 = v2426 * v2427;	// L3323
    float v2429 = v84;	// L3324
    float v2430 = v2429 + v2428;	// L3325
    v84 = v2430;	// L3326
    float v2431 = a84;	// L3327
    v2415.write(v2431); // v2415[k94] = v2431;	// L3328
    float v2432 = b84;	// L3329
    v2416.write(v2432); // v2416[k94] = v2432;	// L3330
  }
  float v2433 = v84;	// L3332
  v2417[v2418][v2419] = v2433;	// L3333
}

void PE_kernel_P_1_1(
  hls::stream< float > &v2434 /* v2434[48] */,
  hls::stream< float > &v2435 /* v2435[48] */,
  hls::stream< float > &v2436 /* v2436[48] */,
  hls::stream< float > &v2437 /* v2437[48] */,
  float v2438[4][4],
  int v2439,
  int v2440
) {	// L3336
  #pragma HLS stream variable=v2434 depth=5
  #pragma HLS stream variable=v2435 depth=5
  #pragma HLS stream variable=v2436 depth=5
  #pragma HLS stream variable=v2437 depth=5
  #pragma HLS array_partition variable=v2438 complete dim=1
  #pragma HLS array_partition variable=v2438 complete dim=2

  float v85;	// L3339
  v85 = 0.000000;	// L3340
  l_S_k_0_k95: for (int k95 = 0; k95 < 48; k95++) {	// L3341
    float v2443 = v2434.read(); // v2434[k95];	// L3342
    float a85;	// L3343
    a85 = v2443;	// L3344
    float v2445 = v2435.read(); // v2435[k95];	// L3345
    float b85;	// L3346
    b85 = v2445;	// L3347
    float v2447 = a85;	// L3348
    float v2448 = b85;	// L3349
    float v2449 = v2447 * v2448;	// L3350
    float v2450 = v85;	// L3351
    float v2451 = v2450 + v2449;	// L3352
    v85 = v2451;	// L3353
    float v2452 = a85;	// L3354
    v2436.write(v2452); // v2436[k95] = v2452;	// L3355
    float v2453 = b85;	// L3356
    v2437.write(v2453); // v2437[k95] = v2453;	// L3357
  }
  float v2454 = v85;	// L3359
  v2438[v2439][v2440] = v2454;	// L3360
}

void PE_kernel_P_2_1(
  hls::stream< float > &v2455 /* v2455[48] */,
  hls::stream< float > &v2456 /* v2456[48] */,
  hls::stream< float > &v2457 /* v2457[48] */,
  hls::stream< float > &v2458 /* v2458[48] */,
  float v2459[4][4],
  int v2460,
  int v2461
) {	// L3363
  #pragma HLS stream variable=v2455 depth=5
  #pragma HLS stream variable=v2456 depth=5
  #pragma HLS stream variable=v2457 depth=5
  #pragma HLS stream variable=v2458 depth=5
  #pragma HLS array_partition variable=v2459 complete dim=1
  #pragma HLS array_partition variable=v2459 complete dim=2

  float v86;	// L3366
  v86 = 0.000000;	// L3367
  l_S_k_0_k96: for (int k96 = 0; k96 < 48; k96++) {	// L3368
    float v2464 = v2455.read(); // v2455[k96];	// L3369
    float a86;	// L3370
    a86 = v2464;	// L3371
    float v2466 = v2456.read(); // v2456[k96];	// L3372
    float b86;	// L3373
    b86 = v2466;	// L3374
    float v2468 = a86;	// L3375
    float v2469 = b86;	// L3376
    float v2470 = v2468 * v2469;	// L3377
    float v2471 = v86;	// L3378
    float v2472 = v2471 + v2470;	// L3379
    v86 = v2472;	// L3380
    float v2473 = a86;	// L3381
    v2457.write(v2473); // v2457[k96] = v2473;	// L3382
    float v2474 = b86;	// L3383
    v2458.write(v2474); // v2458[k96] = v2474;	// L3384
  }
  float v2475 = v86;	// L3386
  v2459[v2460][v2461] = v2475;	// L3387
}

void PE_kernel_P_3_1(
  hls::stream< float > &v2476 /* v2476[48] */,
  hls::stream< float > &v2477 /* v2477[48] */,
  hls::stream< float > &v2478 /* v2478[48] */,
  hls::stream< float > &v2479 /* v2479[48] */,
  float v2480[4][4],
  int v2481,
  int v2482
) {	// L3390
  #pragma HLS stream variable=v2476 depth=5
  #pragma HLS stream variable=v2477 depth=5
  #pragma HLS stream variable=v2478 depth=5
  #pragma HLS stream variable=v2479 depth=5
  #pragma HLS array_partition variable=v2480 complete dim=1
  #pragma HLS array_partition variable=v2480 complete dim=2

  float v87;	// L3393
  v87 = 0.000000;	// L3394
  l_S_k_0_k97: for (int k97 = 0; k97 < 48; k97++) {	// L3395
    float v2485 = v2476.read(); // v2476[k97];	// L3396
    float a87;	// L3397
    a87 = v2485;	// L3398
    float v2487 = v2477.read(); // v2477[k97];	// L3399
    float b87;	// L3400
    b87 = v2487;	// L3401
    float v2489 = a87;	// L3402
    float v2490 = b87;	// L3403
    float v2491 = v2489 * v2490;	// L3404
    float v2492 = v87;	// L3405
    float v2493 = v2492 + v2491;	// L3406
    v87 = v2493;	// L3407
    float v2494 = a87;	// L3408
    v2478.write(v2494); // v2478[k97] = v2494;	// L3409
    float v2495 = b87;	// L3410
    v2479.write(v2495); // v2479[k97] = v2495;	// L3411
  }
  float v2496 = v87;	// L3413
  v2480[v2481][v2482] = v2496;	// L3414
}

void PE_kernel_P_0_2(
  hls::stream< float > &v2497 /* v2497[48] */,
  hls::stream< float > &v2498 /* v2498[48] */,
  hls::stream< float > &v2499 /* v2499[48] */,
  hls::stream< float > &v2500 /* v2500[48] */,
  float v2501[4][4],
  int v2502,
  int v2503
) {	// L3417
  #pragma HLS stream variable=v2497 depth=5
  #pragma HLS stream variable=v2498 depth=5
  #pragma HLS stream variable=v2499 depth=5
  #pragma HLS stream variable=v2500 depth=5
  #pragma HLS array_partition variable=v2501 complete dim=1
  #pragma HLS array_partition variable=v2501 complete dim=2

  float v88;	// L3420
  v88 = 0.000000;	// L3421
  l_S_k_0_k98: for (int k98 = 0; k98 < 48; k98++) {	// L3422
    float v2506 = v2497.read(); // v2497[k98];	// L3423
    float a88;	// L3424
    a88 = v2506;	// L3425
    float v2508 = v2498.read(); // v2498[k98];	// L3426
    float b88;	// L3427
    b88 = v2508;	// L3428
    float v2510 = a88;	// L3429
    float v2511 = b88;	// L3430
    float v2512 = v2510 * v2511;	// L3431
    float v2513 = v88;	// L3432
    float v2514 = v2513 + v2512;	// L3433
    v88 = v2514;	// L3434
    float v2515 = a88;	// L3435
    v2499.write(v2515); // v2499[k98] = v2515;	// L3436
    float v2516 = b88;	// L3437
    v2500.write(v2516); // v2500[k98] = v2516;	// L3438
  }
  float v2517 = v88;	// L3440
  v2501[v2502][v2503] = v2517;	// L3441
}

void PE_kernel_P_1_2(
  hls::stream< float > &v2518 /* v2518[48] */,
  hls::stream< float > &v2519 /* v2519[48] */,
  hls::stream< float > &v2520 /* v2520[48] */,
  hls::stream< float > &v2521 /* v2521[48] */,
  float v2522[4][4],
  int v2523,
  int v2524
) {	// L3444
  #pragma HLS stream variable=v2518 depth=5
  #pragma HLS stream variable=v2519 depth=5
  #pragma HLS stream variable=v2520 depth=5
  #pragma HLS stream variable=v2521 depth=5
  #pragma HLS array_partition variable=v2522 complete dim=1
  #pragma HLS array_partition variable=v2522 complete dim=2

  float v89;	// L3447
  v89 = 0.000000;	// L3448
  l_S_k_0_k99: for (int k99 = 0; k99 < 48; k99++) {	// L3449
    float v2527 = v2518.read(); // v2518[k99];	// L3450
    float a89;	// L3451
    a89 = v2527;	// L3452
    float v2529 = v2519.read(); // v2519[k99];	// L3453
    float b89;	// L3454
    b89 = v2529;	// L3455
    float v2531 = a89;	// L3456
    float v2532 = b89;	// L3457
    float v2533 = v2531 * v2532;	// L3458
    float v2534 = v89;	// L3459
    float v2535 = v2534 + v2533;	// L3460
    v89 = v2535;	// L3461
    float v2536 = a89;	// L3462
    v2520.write(v2536); // v2520[k99] = v2536;	// L3463
    float v2537 = b89;	// L3464
    v2521.write(v2537); // v2521[k99] = v2537;	// L3465
  }
  float v2538 = v89;	// L3467
  v2522[v2523][v2524] = v2538;	// L3468
}

void PE_kernel_P_2_2(
  hls::stream< float > &v2539 /* v2539[48] */,
  hls::stream< float > &v2540 /* v2540[48] */,
  hls::stream< float > &v2541 /* v2541[48] */,
  hls::stream< float > &v2542 /* v2542[48] */,
  float v2543[4][4],
  int v2544,
  int v2545
) {	// L3471
  #pragma HLS stream variable=v2539 depth=5
  #pragma HLS stream variable=v2540 depth=5
  #pragma HLS stream variable=v2541 depth=5
  #pragma HLS stream variable=v2542 depth=5
  #pragma HLS array_partition variable=v2543 complete dim=1
  #pragma HLS array_partition variable=v2543 complete dim=2

  float v90;	// L3474
  v90 = 0.000000;	// L3475
  l_S_k_0_k100: for (int k100 = 0; k100 < 48; k100++) {	// L3476
    float v2548 = v2539.read(); // v2539[k100];	// L3477
    float a90;	// L3478
    a90 = v2548;	// L3479
    float v2550 = v2540.read(); // v2540[k100];	// L3480
    float b90;	// L3481
    b90 = v2550;	// L3482
    float v2552 = a90;	// L3483
    float v2553 = b90;	// L3484
    float v2554 = v2552 * v2553;	// L3485
    float v2555 = v90;	// L3486
    float v2556 = v2555 + v2554;	// L3487
    v90 = v2556;	// L3488
    float v2557 = a90;	// L3489
    v2541.write(v2557); // v2541[k100] = v2557;	// L3490
    float v2558 = b90;	// L3491
    v2542.write(v2558); // v2542[k100] = v2558;	// L3492
  }
  float v2559 = v90;	// L3494
  v2543[v2544][v2545] = v2559;	// L3495
}

void PE_kernel_P_3_2(
  hls::stream< float > &v2560 /* v2560[48] */,
  hls::stream< float > &v2561 /* v2561[48] */,
  hls::stream< float > &v2562 /* v2562[48] */,
  hls::stream< float > &v2563 /* v2563[48] */,
  float v2564[4][4],
  int v2565,
  int v2566
) {	// L3498
  #pragma HLS stream variable=v2560 depth=5
  #pragma HLS stream variable=v2561 depth=5
  #pragma HLS stream variable=v2562 depth=5
  #pragma HLS stream variable=v2563 depth=5
  #pragma HLS array_partition variable=v2564 complete dim=1
  #pragma HLS array_partition variable=v2564 complete dim=2

  float v91;	// L3501
  v91 = 0.000000;	// L3502
  l_S_k_0_k101: for (int k101 = 0; k101 < 48; k101++) {	// L3503
    float v2569 = v2560.read(); // v2560[k101];	// L3504
    float a91;	// L3505
    a91 = v2569;	// L3506
    float v2571 = v2561.read(); // v2561[k101];	// L3507
    float b91;	// L3508
    b91 = v2571;	// L3509
    float v2573 = a91;	// L3510
    float v2574 = b91;	// L3511
    float v2575 = v2573 * v2574;	// L3512
    float v2576 = v91;	// L3513
    float v2577 = v2576 + v2575;	// L3514
    v91 = v2577;	// L3515
    float v2578 = a91;	// L3516
    v2562.write(v2578); // v2562[k101] = v2578;	// L3517
    float v2579 = b91;	// L3518
    v2563.write(v2579); // v2563[k101] = v2579;	// L3519
  }
  float v2580 = v91;	// L3521
  v2564[v2565][v2566] = v2580;	// L3522
}

void PE_kernel_P_0_3(
  hls::stream< float > &v2581 /* v2581[48] */,
  hls::stream< float > &v2582 /* v2582[48] */,
  hls::stream< float > &v2583 /* v2583[48] */,
  hls::stream< float > &v2584 /* v2584[48] */,
  float v2585[4][4],
  int v2586,
  int v2587
) {	// L3525
  #pragma HLS stream variable=v2581 depth=5
  #pragma HLS stream variable=v2582 depth=5
  #pragma HLS stream variable=v2583 depth=5
  #pragma HLS stream variable=v2584 depth=5
  #pragma HLS array_partition variable=v2585 complete dim=1
  #pragma HLS array_partition variable=v2585 complete dim=2

  float v92;	// L3528
  v92 = 0.000000;	// L3529
  l_S_k_0_k102: for (int k102 = 0; k102 < 48; k102++) {	// L3530
    float v2590 = v2581.read(); // v2581[k102];	// L3531
    float a92;	// L3532
    a92 = v2590;	// L3533
    float v2592 = v2582.read(); // v2582[k102];	// L3534
    float b92;	// L3535
    b92 = v2592;	// L3536
    float v2594 = a92;	// L3537
    float v2595 = b92;	// L3538
    float v2596 = v2594 * v2595;	// L3539
    float v2597 = v92;	// L3540
    float v2598 = v2597 + v2596;	// L3541
    v92 = v2598;	// L3542
    float v2599 = a92;	// L3543
    v2583.write(v2599); // v2583[k102] = v2599;	// L3544
    float v2600 = b92;	// L3545
    v2584.write(v2600); // v2584[k102] = v2600;	// L3546
  }
  float v2601 = v92;	// L3548
  v2585[v2586][v2587] = v2601;	// L3549
}

void PE_kernel_P_1_3(
  hls::stream< float > &v2602 /* v2602[48] */,
  hls::stream< float > &v2603 /* v2603[48] */,
  hls::stream< float > &v2604 /* v2604[48] */,
  hls::stream< float > &v2605 /* v2605[48] */,
  float v2606[4][4],
  int v2607,
  int v2608
) {	// L3552
  #pragma HLS stream variable=v2602 depth=5
  #pragma HLS stream variable=v2603 depth=5
  #pragma HLS stream variable=v2604 depth=5
  #pragma HLS stream variable=v2605 depth=5
  #pragma HLS array_partition variable=v2606 complete dim=1
  #pragma HLS array_partition variable=v2606 complete dim=2

  float v93;	// L3555
  v93 = 0.000000;	// L3556
  l_S_k_0_k103: for (int k103 = 0; k103 < 48; k103++) {	// L3557
    float v2611 = v2602.read(); // v2602[k103];	// L3558
    float a93;	// L3559
    a93 = v2611;	// L3560
    float v2613 = v2603.read(); // v2603[k103];	// L3561
    float b93;	// L3562
    b93 = v2613;	// L3563
    float v2615 = a93;	// L3564
    float v2616 = b93;	// L3565
    float v2617 = v2615 * v2616;	// L3566
    float v2618 = v93;	// L3567
    float v2619 = v2618 + v2617;	// L3568
    v93 = v2619;	// L3569
    float v2620 = a93;	// L3570
    v2604.write(v2620); // v2604[k103] = v2620;	// L3571
    float v2621 = b93;	// L3572
    v2605.write(v2621); // v2605[k103] = v2621;	// L3573
  }
  float v2622 = v93;	// L3575
  v2606[v2607][v2608] = v2622;	// L3576
}

void PE_kernel_P_2_3(
  hls::stream< float > &v2623 /* v2623[48] */,
  hls::stream< float > &v2624 /* v2624[48] */,
  hls::stream< float > &v2625 /* v2625[48] */,
  hls::stream< float > &v2626 /* v2626[48] */,
  float v2627[4][4],
  int v2628,
  int v2629
) {	// L3579
  #pragma HLS stream variable=v2623 depth=5
  #pragma HLS stream variable=v2624 depth=5
  #pragma HLS stream variable=v2625 depth=5
  #pragma HLS stream variable=v2626 depth=5
  #pragma HLS array_partition variable=v2627 complete dim=1
  #pragma HLS array_partition variable=v2627 complete dim=2

  float v94;	// L3582
  v94 = 0.000000;	// L3583
  l_S_k_0_k104: for (int k104 = 0; k104 < 48; k104++) {	// L3584
    float v2632 = v2623.read(); // v2623[k104];	// L3585
    float a94;	// L3586
    a94 = v2632;	// L3587
    float v2634 = v2624.read(); // v2624[k104];	// L3588
    float b94;	// L3589
    b94 = v2634;	// L3590
    float v2636 = a94;	// L3591
    float v2637 = b94;	// L3592
    float v2638 = v2636 * v2637;	// L3593
    float v2639 = v94;	// L3594
    float v2640 = v2639 + v2638;	// L3595
    v94 = v2640;	// L3596
    float v2641 = a94;	// L3597
    v2625.write(v2641); // v2625[k104] = v2641;	// L3598
    float v2642 = b94;	// L3599
    v2626.write(v2642); // v2626[k104] = v2642;	// L3600
  }
  float v2643 = v94;	// L3602
  v2627[v2628][v2629] = v2643;	// L3603
}

void PE_kernel_P_3_3(
  hls::stream< float > &v2644 /* v2644[48] */,
  hls::stream< float > &v2645 /* v2645[48] */,
  hls::stream< float > &v2646 /* v2646[48] */,
  hls::stream< float > &v2647 /* v2647[48] */,
  float v2648[4][4],
  int v2649,
  int v2650
) {	// L3606
  #pragma HLS stream variable=v2644 depth=5
  #pragma HLS stream variable=v2645 depth=5
  #pragma HLS stream variable=v2646 depth=5
  #pragma HLS stream variable=v2647 depth=5
  #pragma HLS array_partition variable=v2648 complete dim=1
  #pragma HLS array_partition variable=v2648 complete dim=2

  float v95;	// L3609
  v95 = 0.000000;	// L3610
  l_S_k_0_k105: for (int k105 = 0; k105 < 48; k105++) {	// L3611
    float v2653 = v2644.read(); // v2644[k105];	// L3612
    float a95;	// L3613
    a95 = v2653;	// L3614
    float v2655 = v2645.read(); // v2645[k105];	// L3615
    float b95;	// L3616
    b95 = v2655;	// L3617
    float v2657 = a95;	// L3618
    float v2658 = b95;	// L3619
    float v2659 = v2657 * v2658;	// L3620
    float v2660 = v95;	// L3621
    float v2661 = v2660 + v2659;	// L3622
    v95 = v2661;	// L3623
    float v2662 = a95;	// L3624
    v2646.write(v2662); // v2646[k105] = v2662;	// L3625
    float v2663 = b95;	// L3626
    v2647.write(v2663); // v2647[k105] = v2663;	// L3627
  }
  float v2664 = v95;	// L3629
  v2648[v2649][v2650] = v2664;	// L3630
}

void systolic_tile_P(
  float v2665[4][48],
  float v2666[48][4],
  float v2667[4][4]
) {	// L3633
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v2665 complete dim=1

  #pragma HLS array_partition variable=v2666 complete dim=2

  #pragma HLS array_partition variable=v2667 complete dim=1
  #pragma HLS array_partition variable=v2667 complete dim=2

  hls::stream< float > A_fifo5[4][5] /* A_fifo5[4][5][48] */;	// L3634
  #pragma HLS stream variable=A_fifo5 depth=5
  hls::stream< float > B_fifo5[4][5] /* B_fifo5[4][5][48] */;	// L3635
  #pragma HLS stream variable=B_fifo5 depth=5
  float A_drain5[4];	// L3636
  float B_drain5[4];	// L3637
  l_data_load_k106: for (int k106 = 0; k106 < 48; k106++) {	// L3638
    l_S_m_0_m10: for (int m10 = 0; m10 < 4; m10++) {	// L3639
      float v2674 = v2665[m10][k106];	// L3640
      A_fifo5[m10][0].write(v2674); // A_fifo5[m10][0][k106] = v2674;	// L3641
    }
    l_S_n_1_n10: for (int n10 = 0; n10 < 4; n10++) {	// L3643
      float v2676 = v2666[k106][n10];	// L3644
      B_fifo5[n10][0].write(v2676); // B_fifo5[n10][0][k106] = v2676;	// L3645
    }
  }
  hls::stream< float > &v2677 /* v2677[48] */ = A_fifo5[0][0];	// L3649
  hls::stream< float > &v2678 /* v2678[48] */ = B_fifo5[0][0];	// L3650
  hls::stream< float > &v2679 /* v2679[48] */ = A_fifo5[0][1];	// L3656
  hls::stream< float > &v2680 /* v2680[48] */ = B_fifo5[0][1];	// L3657
  PE_kernel_P_0_0(v2677, v2678, v2679, v2680, v2667, 0, 0);	// L3658
  hls::stream< float > &v2681 /* v2681[48] */ = A_fifo5[0][1];	// L3660
  hls::stream< float > &v2682 /* v2682[48] */ = B_fifo5[1][0];	// L3661
  hls::stream< float > &v2683 /* v2683[48] */ = A_fifo5[0][2];	// L3665
  hls::stream< float > &v2684 /* v2684[48] */ = B_fifo5[1][1];	// L3666
  PE_kernel_P_1_0(v2681, v2682, v2683, v2684, v2667, 0, 1);	// L3667
  hls::stream< float > &v2685 /* v2685[48] */ = A_fifo5[0][2];	// L3669
  hls::stream< float > &v2686 /* v2686[48] */ = B_fifo5[2][0];	// L3670
  hls::stream< float > &v2687 /* v2687[48] */ = A_fifo5[0][3];	// L3674
  hls::stream< float > &v2688 /* v2688[48] */ = B_fifo5[2][1];	// L3675
  PE_kernel_P_2_0(v2685, v2686, v2687, v2688, v2667, 0, 2);	// L3676
  hls::stream< float > &v2689 /* v2689[48] */ = A_fifo5[0][3];	// L3678
  hls::stream< float > &v2690 /* v2690[48] */ = B_fifo5[3][0];	// L3679
  hls::stream< float > &v2691 /* v2691[48] */ = A_fifo5[0][4];	// L3683
  hls::stream< float > &v2692 /* v2692[48] */ = B_fifo5[3][1];	// L3684
  PE_kernel_P_3_0(v2689, v2690, v2691, v2692, v2667, 0, 3);	// L3685
  hls::stream< float > &v2693 /* v2693[48] */ = A_fifo5[1][0];	// L3686
  hls::stream< float > &v2694 /* v2694[48] */ = B_fifo5[0][1];	// L3687
  hls::stream< float > &v2695 /* v2695[48] */ = A_fifo5[1][1];	// L3688
  hls::stream< float > &v2696 /* v2696[48] */ = B_fifo5[0][2];	// L3689
  PE_kernel_P_0_1(v2693, v2694, v2695, v2696, v2667, 1, 0);	// L3690
  hls::stream< float > &v2697 /* v2697[48] */ = A_fifo5[1][1];	// L3691
  hls::stream< float > &v2698 /* v2698[48] */ = B_fifo5[1][1];	// L3692
  hls::stream< float > &v2699 /* v2699[48] */ = A_fifo5[1][2];	// L3693
  hls::stream< float > &v2700 /* v2700[48] */ = B_fifo5[1][2];	// L3694
  PE_kernel_P_1_1(v2697, v2698, v2699, v2700, v2667, 1, 1);	// L3695
  hls::stream< float > &v2701 /* v2701[48] */ = A_fifo5[1][2];	// L3696
  hls::stream< float > &v2702 /* v2702[48] */ = B_fifo5[2][1];	// L3697
  hls::stream< float > &v2703 /* v2703[48] */ = A_fifo5[1][3];	// L3698
  hls::stream< float > &v2704 /* v2704[48] */ = B_fifo5[2][2];	// L3699
  PE_kernel_P_2_1(v2701, v2702, v2703, v2704, v2667, 1, 2);	// L3700
  hls::stream< float > &v2705 /* v2705[48] */ = A_fifo5[1][3];	// L3701
  hls::stream< float > &v2706 /* v2706[48] */ = B_fifo5[3][1];	// L3702
  hls::stream< float > &v2707 /* v2707[48] */ = A_fifo5[1][4];	// L3703
  hls::stream< float > &v2708 /* v2708[48] */ = B_fifo5[3][2];	// L3704
  PE_kernel_P_3_1(v2705, v2706, v2707, v2708, v2667, 1, 3);	// L3705
  hls::stream< float > &v2709 /* v2709[48] */ = A_fifo5[2][0];	// L3706
  hls::stream< float > &v2710 /* v2710[48] */ = B_fifo5[0][2];	// L3707
  hls::stream< float > &v2711 /* v2711[48] */ = A_fifo5[2][1];	// L3708
  hls::stream< float > &v2712 /* v2712[48] */ = B_fifo5[0][3];	// L3709
  PE_kernel_P_0_2(v2709, v2710, v2711, v2712, v2667, 2, 0);	// L3710
  hls::stream< float > &v2713 /* v2713[48] */ = A_fifo5[2][1];	// L3711
  hls::stream< float > &v2714 /* v2714[48] */ = B_fifo5[1][2];	// L3712
  hls::stream< float > &v2715 /* v2715[48] */ = A_fifo5[2][2];	// L3713
  hls::stream< float > &v2716 /* v2716[48] */ = B_fifo5[1][3];	// L3714
  PE_kernel_P_1_2(v2713, v2714, v2715, v2716, v2667, 2, 1);	// L3715
  hls::stream< float > &v2717 /* v2717[48] */ = A_fifo5[2][2];	// L3716
  hls::stream< float > &v2718 /* v2718[48] */ = B_fifo5[2][2];	// L3717
  hls::stream< float > &v2719 /* v2719[48] */ = A_fifo5[2][3];	// L3718
  hls::stream< float > &v2720 /* v2720[48] */ = B_fifo5[2][3];	// L3719
  PE_kernel_P_2_2(v2717, v2718, v2719, v2720, v2667, 2, 2);	// L3720
  hls::stream< float > &v2721 /* v2721[48] */ = A_fifo5[2][3];	// L3721
  hls::stream< float > &v2722 /* v2722[48] */ = B_fifo5[3][2];	// L3722
  hls::stream< float > &v2723 /* v2723[48] */ = A_fifo5[2][4];	// L3723
  hls::stream< float > &v2724 /* v2724[48] */ = B_fifo5[3][3];	// L3724
  PE_kernel_P_3_2(v2721, v2722, v2723, v2724, v2667, 2, 3);	// L3725
  hls::stream< float > &v2725 /* v2725[48] */ = A_fifo5[3][0];	// L3726
  hls::stream< float > &v2726 /* v2726[48] */ = B_fifo5[0][3];	// L3727
  hls::stream< float > &v2727 /* v2727[48] */ = A_fifo5[3][1];	// L3728
  hls::stream< float > &v2728 /* v2728[48] */ = B_fifo5[0][4];	// L3729
  PE_kernel_P_0_3(v2725, v2726, v2727, v2728, v2667, 3, 0);	// L3730
  hls::stream< float > &v2729 /* v2729[48] */ = A_fifo5[3][1];	// L3731
  hls::stream< float > &v2730 /* v2730[48] */ = B_fifo5[1][3];	// L3732
  hls::stream< float > &v2731 /* v2731[48] */ = A_fifo5[3][2];	// L3733
  hls::stream< float > &v2732 /* v2732[48] */ = B_fifo5[1][4];	// L3734
  PE_kernel_P_1_3(v2729, v2730, v2731, v2732, v2667, 3, 1);	// L3735
  hls::stream< float > &v2733 /* v2733[48] */ = A_fifo5[3][2];	// L3736
  hls::stream< float > &v2734 /* v2734[48] */ = B_fifo5[2][3];	// L3737
  hls::stream< float > &v2735 /* v2735[48] */ = A_fifo5[3][3];	// L3738
  hls::stream< float > &v2736 /* v2736[48] */ = B_fifo5[2][4];	// L3739
  PE_kernel_P_2_3(v2733, v2734, v2735, v2736, v2667, 3, 2);	// L3740
  hls::stream< float > &v2737 /* v2737[48] */ = A_fifo5[3][3];	// L3741
  hls::stream< float > &v2738 /* v2738[48] */ = B_fifo5[3][3];	// L3742
  hls::stream< float > &v2739 /* v2739[48] */ = A_fifo5[3][4];	// L3743
  hls::stream< float > &v2740 /* v2740[48] */ = B_fifo5[3][4];	// L3744
  PE_kernel_P_3_3(v2737, v2738, v2739, v2740, v2667, 3, 3);	// L3745
  l_data_drain_k107: for (int k107 = 0; k107 < 48; k107++) {	// L3746
    l_S_m_4_m11: for (int m11 = 0; m11 < 4; m11++) {	// L3747
      float v2743 = A_fifo5[m11][4].read(); // A_fifo5[m11][4][k107];	// L3748
      A_drain5[m11] = v2743;	// L3749
    }
    l_S_n_5_n11: for (int n11 = 0; n11 < 4; n11++) {	// L3751
      float v2745 = B_fifo5[n11][4].read(); // B_fifo5[n11][4][k107];	// L3752
      B_drain5[n11] = v2745;	// L3753
    }
  }
}

void systolic_P(
  float v2746[32][48],
  float *Wp,
  float v2748[32][48]
) {	// L3758
  float local_A5[4][48];	// L3759
  #pragma HLS array_partition variable=local_A5 complete dim=1

  float local_B5[48][4];	// L3760
  #pragma HLS array_partition variable=local_B5 complete dim=2

  float local_C5[4][4];	// L3761
  #pragma HLS array_partition variable=local_C5 complete dim=1
  #pragma HLS array_partition variable=local_C5 complete dim=2

  l_outer_tile_mi5: for (int mi5 = 0; mi5 < 8; mi5++) {	// L3762
    l_ni5: for (int ni5 = 0; ni5 < 12; ni5++) {	// L3763
    #pragma HLS dataflow
      l_load_A_tile_ak5: for (int ak5 = 0; ak5 < 48; ak5++) {	// L3764
        l_ai5: for (int ai5 = 0; ai5 < 4; ai5++) {	// L3765
        #pragma HLS pipeline II=1
          ap_int<33> v2756 = ni5;	// L3766
          bool v2757 = v2756 == 0;	// L3769
          if (v2757) {	// L3770
            float v2758 = v2746[((mi5 * 4) + ai5)][ak5];	// L3771
            local_A5[ai5][ak5] = v2758;	// L3772
          }
        }
      }
      l_load_B_tile_bk5: for (int bk5 = 0; bk5 < 48; bk5++) {	// L3776
        l_bj5: for (int bj5 = 0; bj5 < 4; bj5++) {	// L3777
        #pragma HLS pipeline II=1
          float v2761 = Wp[bk5*48+((ni5 * 4) + bj5)];	// L3778
          // float v2761 = v2747[bk5][((ni5 * 4) + bj5)];	// L3778
          local_B5[bk5][bj5] = v2761;	// L3779
        }
      }
      systolic_tile_P(local_A5, local_B5, local_C5);	// L3782
      l_store_C_tile_sj5: for (int sj5 = 0; sj5 < 4; sj5++) {	// L3783
        l_si5: for (int si5 = 0; si5 < 4; si5++) {	// L3784
        #pragma HLS pipeline II=1
          float v2764 = local_C5[si5][sj5];	// L3785
          v2748[((mi5 * 4) + si5)][((ni5 * 4) + sj5)] = v2764;	// L3786
        }
      }
    }
  }
}

void bias_add(
  float v2765[32][48],
  float v2766[48],
  float v2767[32][48]
) {	// L3793
  l_S_i_j_0_i8: for (int i8 = 0; i8 < 32; i8++) {	// L3795
    l_j7: for (int j7 = 0; j7 < 48; j7++) {	// L3796
      float v2770 = v2765[i8][j7];	// L3797
      float v2771 = v2766[j7];	// L3798
      float v2772 = v2770 + v2771;	// L3799
      v2767[i8][j7] = v2772;	// L3800
    }
  }
}

void residual_add(
  float v2773[32][48],
  float v2774[32][48],
  float v2775[32][48]
) {	// L3805
  l_S_i_j_0_i9: for (int i9 = 0; i9 < 32; i9++) {	// L3807
    l_j8: for (int j8 = 0; j8 < 48; j8++) {	// L3808
      float v2778 = v2773[i9][j8];	// L3809
      float v2779 = v2774[i9][j8];	// L3810
      float v2780 = v2778 + v2779;	// L3811
      v2775[i9][j8] = v2780;	// L3812
    }
  }
}

void PE_kernel_ffn1_0_0(
  hls::stream< float > &v2781 /* v2781[48] */,
  hls::stream< float > &v2782 /* v2782[48] */,
  hls::stream< float > &v2783 /* v2783[48] */,
  hls::stream< float > &v2784 /* v2784[48] */,
  float v2785[4][4],
  int v2786,
  int v2787
) {	// L3817
  #pragma HLS stream variable=v2781 depth=5
  #pragma HLS stream variable=v2782 depth=5
  #pragma HLS stream variable=v2783 depth=5
  #pragma HLS stream variable=v2784 depth=5
  #pragma HLS array_partition variable=v2785 complete dim=1
  #pragma HLS array_partition variable=v2785 complete dim=2

  float v96;	// L3820
  v96 = 0.000000;	// L3821
  l_S_k_0_k108: for (int k108 = 0; k108 < 48; k108++) {	// L3822
    float v2790 = v2781.read(); // v2781[k108];	// L3823
    float a96;	// L3824
    a96 = v2790;	// L3825
    float v2792 = v2782.read(); // v2782[k108];	// L3826
    float b96;	// L3827
    b96 = v2792;	// L3828
    float v2794 = a96;	// L3829
    float v2795 = b96;	// L3830
    float v2796 = v2794 * v2795;	// L3831
    float v2797 = v96;	// L3832
    float v2798 = v2797 + v2796;	// L3833
    v96 = v2798;	// L3834
    float v2799 = a96;	// L3835
    v2783.write(v2799); // v2783[k108] = v2799;	// L3836
    float v2800 = b96;	// L3837
    v2784.write(v2800); // v2784[k108] = v2800;	// L3838
  }
  float v2801 = v96;	// L3840
  v2785[v2786][v2787] = v2801;	// L3841
}

void PE_kernel_ffn1_1_0(
  hls::stream< float > &v2802 /* v2802[48] */,
  hls::stream< float > &v2803 /* v2803[48] */,
  hls::stream< float > &v2804 /* v2804[48] */,
  hls::stream< float > &v2805 /* v2805[48] */,
  float v2806[4][4],
  int v2807,
  int v2808
) {	// L3844
  #pragma HLS stream variable=v2802 depth=5
  #pragma HLS stream variable=v2803 depth=5
  #pragma HLS stream variable=v2804 depth=5
  #pragma HLS stream variable=v2805 depth=5
  #pragma HLS array_partition variable=v2806 complete dim=1
  #pragma HLS array_partition variable=v2806 complete dim=2

  float v97;	// L3847
  v97 = 0.000000;	// L3848
  l_S_k_0_k109: for (int k109 = 0; k109 < 48; k109++) {	// L3849
    float v2811 = v2802.read(); // v2802[k109];	// L3850
    float a97;	// L3851
    a97 = v2811;	// L3852
    float v2813 = v2803.read(); // v2803[k109];	// L3853
    float b97;	// L3854
    b97 = v2813;	// L3855
    float v2815 = a97;	// L3856
    float v2816 = b97;	// L3857
    float v2817 = v2815 * v2816;	// L3858
    float v2818 = v97;	// L3859
    float v2819 = v2818 + v2817;	// L3860
    v97 = v2819;	// L3861
    float v2820 = a97;	// L3862
    v2804.write(v2820); // v2804[k109] = v2820;	// L3863
    float v2821 = b97;	// L3864
    v2805.write(v2821); // v2805[k109] = v2821;	// L3865
  }
  float v2822 = v97;	// L3867
  v2806[v2807][v2808] = v2822;	// L3868
}

void PE_kernel_ffn1_2_0(
  hls::stream< float > &v2823 /* v2823[48] */,
  hls::stream< float > &v2824 /* v2824[48] */,
  hls::stream< float > &v2825 /* v2825[48] */,
  hls::stream< float > &v2826 /* v2826[48] */,
  float v2827[4][4],
  int v2828,
  int v2829
) {	// L3871
  #pragma HLS stream variable=v2823 depth=5
  #pragma HLS stream variable=v2824 depth=5
  #pragma HLS stream variable=v2825 depth=5
  #pragma HLS stream variable=v2826 depth=5
  #pragma HLS array_partition variable=v2827 complete dim=1
  #pragma HLS array_partition variable=v2827 complete dim=2

  float v98;	// L3874
  v98 = 0.000000;	// L3875
  l_S_k_0_k110: for (int k110 = 0; k110 < 48; k110++) {	// L3876
    float v2832 = v2823.read(); // v2823[k110];	// L3877
    float a98;	// L3878
    a98 = v2832;	// L3879
    float v2834 = v2824.read(); // v2824[k110];	// L3880
    float b98;	// L3881
    b98 = v2834;	// L3882
    float v2836 = a98;	// L3883
    float v2837 = b98;	// L3884
    float v2838 = v2836 * v2837;	// L3885
    float v2839 = v98;	// L3886
    float v2840 = v2839 + v2838;	// L3887
    v98 = v2840;	// L3888
    float v2841 = a98;	// L3889
    v2825.write(v2841); // v2825[k110] = v2841;	// L3890
    float v2842 = b98;	// L3891
    v2826.write(v2842); // v2826[k110] = v2842;	// L3892
  }
  float v2843 = v98;	// L3894
  v2827[v2828][v2829] = v2843;	// L3895
}

void PE_kernel_ffn1_3_0(
  hls::stream< float > &v2844 /* v2844[48] */,
  hls::stream< float > &v2845 /* v2845[48] */,
  hls::stream< float > &v2846 /* v2846[48] */,
  hls::stream< float > &v2847 /* v2847[48] */,
  float v2848[4][4],
  int v2849,
  int v2850
) {	// L3898
  #pragma HLS stream variable=v2844 depth=5
  #pragma HLS stream variable=v2845 depth=5
  #pragma HLS stream variable=v2846 depth=5
  #pragma HLS stream variable=v2847 depth=5
  #pragma HLS array_partition variable=v2848 complete dim=1
  #pragma HLS array_partition variable=v2848 complete dim=2

  float v99;	// L3901
  v99 = 0.000000;	// L3902
  l_S_k_0_k111: for (int k111 = 0; k111 < 48; k111++) {	// L3903
    float v2853 = v2844.read(); // v2844[k111];	// L3904
    float a99;	// L3905
    a99 = v2853;	// L3906
    float v2855 = v2845.read(); // v2845[k111];	// L3907
    float b99;	// L3908
    b99 = v2855;	// L3909
    float v2857 = a99;	// L3910
    float v2858 = b99;	// L3911
    float v2859 = v2857 * v2858;	// L3912
    float v2860 = v99;	// L3913
    float v2861 = v2860 + v2859;	// L3914
    v99 = v2861;	// L3915
    float v2862 = a99;	// L3916
    v2846.write(v2862); // v2846[k111] = v2862;	// L3917
    float v2863 = b99;	// L3918
    v2847.write(v2863); // v2847[k111] = v2863;	// L3919
  }
  float v2864 = v99;	// L3921
  v2848[v2849][v2850] = v2864;	// L3922
}

void PE_kernel_ffn1_0_1(
  hls::stream< float > &v2865 /* v2865[48] */,
  hls::stream< float > &v2866 /* v2866[48] */,
  hls::stream< float > &v2867 /* v2867[48] */,
  hls::stream< float > &v2868 /* v2868[48] */,
  float v2869[4][4],
  int v2870,
  int v2871
) {	// L3925
  #pragma HLS stream variable=v2865 depth=5
  #pragma HLS stream variable=v2866 depth=5
  #pragma HLS stream variable=v2867 depth=5
  #pragma HLS stream variable=v2868 depth=5
  #pragma HLS array_partition variable=v2869 complete dim=1
  #pragma HLS array_partition variable=v2869 complete dim=2

  float v100;	// L3928
  v100 = 0.000000;	// L3929
  l_S_k_0_k112: for (int k112 = 0; k112 < 48; k112++) {	// L3930
    float v2874 = v2865.read(); // v2865[k112];	// L3931
    float a100;	// L3932
    a100 = v2874;	// L3933
    float v2876 = v2866.read(); // v2866[k112];	// L3934
    float b100;	// L3935
    b100 = v2876;	// L3936
    float v2878 = a100;	// L3937
    float v2879 = b100;	// L3938
    float v2880 = v2878 * v2879;	// L3939
    float v2881 = v100;	// L3940
    float v2882 = v2881 + v2880;	// L3941
    v100 = v2882;	// L3942
    float v2883 = a100;	// L3943
    v2867.write(v2883); // v2867[k112] = v2883;	// L3944
    float v2884 = b100;	// L3945
    v2868.write(v2884); // v2868[k112] = v2884;	// L3946
  }
  float v2885 = v100;	// L3948
  v2869[v2870][v2871] = v2885;	// L3949
}

void PE_kernel_ffn1_1_1(
  hls::stream< float > &v2886 /* v2886[48] */,
  hls::stream< float > &v2887 /* v2887[48] */,
  hls::stream< float > &v2888 /* v2888[48] */,
  hls::stream< float > &v2889 /* v2889[48] */,
  float v2890[4][4],
  int v2891,
  int v2892
) {	// L3952
  #pragma HLS stream variable=v2886 depth=5
  #pragma HLS stream variable=v2887 depth=5
  #pragma HLS stream variable=v2888 depth=5
  #pragma HLS stream variable=v2889 depth=5
  #pragma HLS array_partition variable=v2890 complete dim=1
  #pragma HLS array_partition variable=v2890 complete dim=2

  float v101;	// L3955
  v101 = 0.000000;	// L3956
  l_S_k_0_k113: for (int k113 = 0; k113 < 48; k113++) {	// L3957
    float v2895 = v2886.read(); // v2886[k113];	// L3958
    float a101;	// L3959
    a101 = v2895;	// L3960
    float v2897 = v2887.read(); // v2887[k113];	// L3961
    float b101;	// L3962
    b101 = v2897;	// L3963
    float v2899 = a101;	// L3964
    float v2900 = b101;	// L3965
    float v2901 = v2899 * v2900;	// L3966
    float v2902 = v101;	// L3967
    float v2903 = v2902 + v2901;	// L3968
    v101 = v2903;	// L3969
    float v2904 = a101;	// L3970
    v2888.write(v2904); // v2888[k113] = v2904;	// L3971
    float v2905 = b101;	// L3972
    v2889.write(v2905); // v2889[k113] = v2905;	// L3973
  }
  float v2906 = v101;	// L3975
  v2890[v2891][v2892] = v2906;	// L3976
}

void PE_kernel_ffn1_2_1(
  hls::stream< float > &v2907 /* v2907[48] */,
  hls::stream< float > &v2908 /* v2908[48] */,
  hls::stream< float > &v2909 /* v2909[48] */,
  hls::stream< float > &v2910 /* v2910[48] */,
  float v2911[4][4],
  int v2912,
  int v2913
) {	// L3979
  #pragma HLS stream variable=v2907 depth=5
  #pragma HLS stream variable=v2908 depth=5
  #pragma HLS stream variable=v2909 depth=5
  #pragma HLS stream variable=v2910 depth=5
  #pragma HLS array_partition variable=v2911 complete dim=1
  #pragma HLS array_partition variable=v2911 complete dim=2

  float v102;	// L3982
  v102 = 0.000000;	// L3983
  l_S_k_0_k114: for (int k114 = 0; k114 < 48; k114++) {	// L3984
    float v2916 = v2907.read(); // v2907[k114];	// L3985
    float a102;	// L3986
    a102 = v2916;	// L3987
    float v2918 = v2908.read(); // v2908[k114];	// L3988
    float b102;	// L3989
    b102 = v2918;	// L3990
    float v2920 = a102;	// L3991
    float v2921 = b102;	// L3992
    float v2922 = v2920 * v2921;	// L3993
    float v2923 = v102;	// L3994
    float v2924 = v2923 + v2922;	// L3995
    v102 = v2924;	// L3996
    float v2925 = a102;	// L3997
    v2909.write(v2925); // v2909[k114] = v2925;	// L3998
    float v2926 = b102;	// L3999
    v2910.write(v2926); // v2910[k114] = v2926;	// L4000
  }
  float v2927 = v102;	// L4002
  v2911[v2912][v2913] = v2927;	// L4003
}

void PE_kernel_ffn1_3_1(
  hls::stream< float > &v2928 /* v2928[48] */,
  hls::stream< float > &v2929 /* v2929[48] */,
  hls::stream< float > &v2930 /* v2930[48] */,
  hls::stream< float > &v2931 /* v2931[48] */,
  float v2932[4][4],
  int v2933,
  int v2934
) {	// L4006
  #pragma HLS stream variable=v2928 depth=5
  #pragma HLS stream variable=v2929 depth=5
  #pragma HLS stream variable=v2930 depth=5
  #pragma HLS stream variable=v2931 depth=5
  #pragma HLS array_partition variable=v2932 complete dim=1
  #pragma HLS array_partition variable=v2932 complete dim=2

  float v103;	// L4009
  v103 = 0.000000;	// L4010
  l_S_k_0_k115: for (int k115 = 0; k115 < 48; k115++) {	// L4011
    float v2937 = v2928.read(); // v2928[k115];	// L4012
    float a103;	// L4013
    a103 = v2937;	// L4014
    float v2939 = v2929.read(); // v2929[k115];	// L4015
    float b103;	// L4016
    b103 = v2939;	// L4017
    float v2941 = a103;	// L4018
    float v2942 = b103;	// L4019
    float v2943 = v2941 * v2942;	// L4020
    float v2944 = v103;	// L4021
    float v2945 = v2944 + v2943;	// L4022
    v103 = v2945;	// L4023
    float v2946 = a103;	// L4024
    v2930.write(v2946); // v2930[k115] = v2946;	// L4025
    float v2947 = b103;	// L4026
    v2931.write(v2947); // v2931[k115] = v2947;	// L4027
  }
  float v2948 = v103;	// L4029
  v2932[v2933][v2934] = v2948;	// L4030
}

void PE_kernel_ffn1_0_2(
  hls::stream< float > &v2949 /* v2949[48] */,
  hls::stream< float > &v2950 /* v2950[48] */,
  hls::stream< float > &v2951 /* v2951[48] */,
  hls::stream< float > &v2952 /* v2952[48] */,
  float v2953[4][4],
  int v2954,
  int v2955
) {	// L4033
  #pragma HLS stream variable=v2949 depth=5
  #pragma HLS stream variable=v2950 depth=5
  #pragma HLS stream variable=v2951 depth=5
  #pragma HLS stream variable=v2952 depth=5
  #pragma HLS array_partition variable=v2953 complete dim=1
  #pragma HLS array_partition variable=v2953 complete dim=2

  float v104;	// L4036
  v104 = 0.000000;	// L4037
  l_S_k_0_k116: for (int k116 = 0; k116 < 48; k116++) {	// L4038
    float v2958 = v2949.read(); // v2949[k116];	// L4039
    float a104;	// L4040
    a104 = v2958;	// L4041
    float v2960 = v2950.read(); // v2950[k116];	// L4042
    float b104;	// L4043
    b104 = v2960;	// L4044
    float v2962 = a104;	// L4045
    float v2963 = b104;	// L4046
    float v2964 = v2962 * v2963;	// L4047
    float v2965 = v104;	// L4048
    float v2966 = v2965 + v2964;	// L4049
    v104 = v2966;	// L4050
    float v2967 = a104;	// L4051
    v2951.write(v2967); // v2951[k116] = v2967;	// L4052
    float v2968 = b104;	// L4053
    v2952.write(v2968); // v2952[k116] = v2968;	// L4054
  }
  float v2969 = v104;	// L4056
  v2953[v2954][v2955] = v2969;	// L4057
}

void PE_kernel_ffn1_1_2(
  hls::stream< float > &v2970 /* v2970[48] */,
  hls::stream< float > &v2971 /* v2971[48] */,
  hls::stream< float > &v2972 /* v2972[48] */,
  hls::stream< float > &v2973 /* v2973[48] */,
  float v2974[4][4],
  int v2975,
  int v2976
) {	// L4060
  #pragma HLS stream variable=v2970 depth=5
  #pragma HLS stream variable=v2971 depth=5
  #pragma HLS stream variable=v2972 depth=5
  #pragma HLS stream variable=v2973 depth=5
  #pragma HLS array_partition variable=v2974 complete dim=1
  #pragma HLS array_partition variable=v2974 complete dim=2

  float v105;	// L4063
  v105 = 0.000000;	// L4064
  l_S_k_0_k117: for (int k117 = 0; k117 < 48; k117++) {	// L4065
    float v2979 = v2970.read(); // v2970[k117];	// L4066
    float a105;	// L4067
    a105 = v2979;	// L4068
    float v2981 = v2971.read(); // v2971[k117];	// L4069
    float b105;	// L4070
    b105 = v2981;	// L4071
    float v2983 = a105;	// L4072
    float v2984 = b105;	// L4073
    float v2985 = v2983 * v2984;	// L4074
    float v2986 = v105;	// L4075
    float v2987 = v2986 + v2985;	// L4076
    v105 = v2987;	// L4077
    float v2988 = a105;	// L4078
    v2972.write(v2988); // v2972[k117] = v2988;	// L4079
    float v2989 = b105;	// L4080
    v2973.write(v2989); // v2973[k117] = v2989;	// L4081
  }
  float v2990 = v105;	// L4083
  v2974[v2975][v2976] = v2990;	// L4084
}

void PE_kernel_ffn1_2_2(
  hls::stream< float > &v2991 /* v2991[48] */,
  hls::stream< float > &v2992 /* v2992[48] */,
  hls::stream< float > &v2993 /* v2993[48] */,
  hls::stream< float > &v2994 /* v2994[48] */,
  float v2995[4][4],
  int v2996,
  int v2997
) {	// L4087
  #pragma HLS stream variable=v2991 depth=5
  #pragma HLS stream variable=v2992 depth=5
  #pragma HLS stream variable=v2993 depth=5
  #pragma HLS stream variable=v2994 depth=5
  #pragma HLS array_partition variable=v2995 complete dim=1
  #pragma HLS array_partition variable=v2995 complete dim=2

  float v106;	// L4090
  v106 = 0.000000;	// L4091
  l_S_k_0_k118: for (int k118 = 0; k118 < 48; k118++) {	// L4092
    float v3000 = v2991.read(); // v2991[k118];	// L4093
    float a106;	// L4094
    a106 = v3000;	// L4095
    float v3002 = v2992.read(); // v2992[k118];	// L4096
    float b106;	// L4097
    b106 = v3002;	// L4098
    float v3004 = a106;	// L4099
    float v3005 = b106;	// L4100
    float v3006 = v3004 * v3005;	// L4101
    float v3007 = v106;	// L4102
    float v3008 = v3007 + v3006;	// L4103
    v106 = v3008;	// L4104
    float v3009 = a106;	// L4105
    v2993.write(v3009); // v2993[k118] = v3009;	// L4106
    float v3010 = b106;	// L4107
    v2994.write(v3010); // v2994[k118] = v3010;	// L4108
  }
  float v3011 = v106;	// L4110
  v2995[v2996][v2997] = v3011;	// L4111
}

void PE_kernel_ffn1_3_2(
  hls::stream< float > &v3012 /* v3012[48] */,
  hls::stream< float > &v3013 /* v3013[48] */,
  hls::stream< float > &v3014 /* v3014[48] */,
  hls::stream< float > &v3015 /* v3015[48] */,
  float v3016[4][4],
  int v3017,
  int v3018
) {	// L4114
  #pragma HLS stream variable=v3012 depth=5
  #pragma HLS stream variable=v3013 depth=5
  #pragma HLS stream variable=v3014 depth=5
  #pragma HLS stream variable=v3015 depth=5
  #pragma HLS array_partition variable=v3016 complete dim=1
  #pragma HLS array_partition variable=v3016 complete dim=2

  float v107;	// L4117
  v107 = 0.000000;	// L4118
  l_S_k_0_k119: for (int k119 = 0; k119 < 48; k119++) {	// L4119
    float v3021 = v3012.read(); // v3012[k119];	// L4120
    float a107;	// L4121
    a107 = v3021;	// L4122
    float v3023 = v3013.read(); // v3013[k119];	// L4123
    float b107;	// L4124
    b107 = v3023;	// L4125
    float v3025 = a107;	// L4126
    float v3026 = b107;	// L4127
    float v3027 = v3025 * v3026;	// L4128
    float v3028 = v107;	// L4129
    float v3029 = v3028 + v3027;	// L4130
    v107 = v3029;	// L4131
    float v3030 = a107;	// L4132
    v3014.write(v3030); // v3014[k119] = v3030;	// L4133
    float v3031 = b107;	// L4134
    v3015.write(v3031); // v3015[k119] = v3031;	// L4135
  }
  float v3032 = v107;	// L4137
  v3016[v3017][v3018] = v3032;	// L4138
}

void PE_kernel_ffn1_0_3(
  hls::stream< float > &v3033 /* v3033[48] */,
  hls::stream< float > &v3034 /* v3034[48] */,
  hls::stream< float > &v3035 /* v3035[48] */,
  hls::stream< float > &v3036 /* v3036[48] */,
  float v3037[4][4],
  int v3038,
  int v3039
) {	// L4141
  #pragma HLS stream variable=v3033 depth=5
  #pragma HLS stream variable=v3034 depth=5
  #pragma HLS stream variable=v3035 depth=5
  #pragma HLS stream variable=v3036 depth=5
  #pragma HLS array_partition variable=v3037 complete dim=1
  #pragma HLS array_partition variable=v3037 complete dim=2

  float v108;	// L4144
  v108 = 0.000000;	// L4145
  l_S_k_0_k120: for (int k120 = 0; k120 < 48; k120++) {	// L4146
    float v3042 = v3033.read(); // v3033[k120];	// L4147
    float a108;	// L4148
    a108 = v3042;	// L4149
    float v3044 = v3034.read(); // v3034[k120];	// L4150
    float b108;	// L4151
    b108 = v3044;	// L4152
    float v3046 = a108;	// L4153
    float v3047 = b108;	// L4154
    float v3048 = v3046 * v3047;	// L4155
    float v3049 = v108;	// L4156
    float v3050 = v3049 + v3048;	// L4157
    v108 = v3050;	// L4158
    float v3051 = a108;	// L4159
    v3035.write(v3051); // v3035[k120] = v3051;	// L4160
    float v3052 = b108;	// L4161
    v3036.write(v3052); // v3036[k120] = v3052;	// L4162
  }
  float v3053 = v108;	// L4164
  v3037[v3038][v3039] = v3053;	// L4165
}

void PE_kernel_ffn1_1_3(
  hls::stream< float > &v3054 /* v3054[48] */,
  hls::stream< float > &v3055 /* v3055[48] */,
  hls::stream< float > &v3056 /* v3056[48] */,
  hls::stream< float > &v3057 /* v3057[48] */,
  float v3058[4][4],
  int v3059,
  int v3060
) {	// L4168
  #pragma HLS stream variable=v3054 depth=5
  #pragma HLS stream variable=v3055 depth=5
  #pragma HLS stream variable=v3056 depth=5
  #pragma HLS stream variable=v3057 depth=5
  #pragma HLS array_partition variable=v3058 complete dim=1
  #pragma HLS array_partition variable=v3058 complete dim=2

  float v109;	// L4171
  v109 = 0.000000;	// L4172
  l_S_k_0_k121: for (int k121 = 0; k121 < 48; k121++) {	// L4173
    float v3063 = v3054.read(); // v3054[k121];	// L4174
    float a109;	// L4175
    a109 = v3063;	// L4176
    float v3065 = v3055.read(); // v3055[k121];	// L4177
    float b109;	// L4178
    b109 = v3065;	// L4179
    float v3067 = a109;	// L4180
    float v3068 = b109;	// L4181
    float v3069 = v3067 * v3068;	// L4182
    float v3070 = v109;	// L4183
    float v3071 = v3070 + v3069;	// L4184
    v109 = v3071;	// L4185
    float v3072 = a109;	// L4186
    v3056.write(v3072); // v3056[k121] = v3072;	// L4187
    float v3073 = b109;	// L4188
    v3057.write(v3073); // v3057[k121] = v3073;	// L4189
  }
  float v3074 = v109;	// L4191
  v3058[v3059][v3060] = v3074;	// L4192
}

void PE_kernel_ffn1_2_3(
  hls::stream< float > &v3075 /* v3075[48] */,
  hls::stream< float > &v3076 /* v3076[48] */,
  hls::stream< float > &v3077 /* v3077[48] */,
  hls::stream< float > &v3078 /* v3078[48] */,
  float v3079[4][4],
  int v3080,
  int v3081
) {	// L4195
  #pragma HLS stream variable=v3075 depth=5
  #pragma HLS stream variable=v3076 depth=5
  #pragma HLS stream variable=v3077 depth=5
  #pragma HLS stream variable=v3078 depth=5
  #pragma HLS array_partition variable=v3079 complete dim=1
  #pragma HLS array_partition variable=v3079 complete dim=2

  float v110;	// L4198
  v110 = 0.000000;	// L4199
  l_S_k_0_k122: for (int k122 = 0; k122 < 48; k122++) {	// L4200
    float v3084 = v3075.read(); // v3075[k122];	// L4201
    float a110;	// L4202
    a110 = v3084;	// L4203
    float v3086 = v3076.read(); // v3076[k122];	// L4204
    float b110;	// L4205
    b110 = v3086;	// L4206
    float v3088 = a110;	// L4207
    float v3089 = b110;	// L4208
    float v3090 = v3088 * v3089;	// L4209
    float v3091 = v110;	// L4210
    float v3092 = v3091 + v3090;	// L4211
    v110 = v3092;	// L4212
    float v3093 = a110;	// L4213
    v3077.write(v3093); // v3077[k122] = v3093;	// L4214
    float v3094 = b110;	// L4215
    v3078.write(v3094); // v3078[k122] = v3094;	// L4216
  }
  float v3095 = v110;	// L4218
  v3079[v3080][v3081] = v3095;	// L4219
}

void PE_kernel_ffn1_3_3(
  hls::stream< float > &v3096 /* v3096[48] */,
  hls::stream< float > &v3097 /* v3097[48] */,
  hls::stream< float > &v3098 /* v3098[48] */,
  hls::stream< float > &v3099 /* v3099[48] */,
  float v3100[4][4],
  int v3101,
  int v3102
) {	// L4222
  #pragma HLS stream variable=v3096 depth=5
  #pragma HLS stream variable=v3097 depth=5
  #pragma HLS stream variable=v3098 depth=5
  #pragma HLS stream variable=v3099 depth=5
  #pragma HLS array_partition variable=v3100 complete dim=1
  #pragma HLS array_partition variable=v3100 complete dim=2

  float v111;	// L4225
  v111 = 0.000000;	// L4226
  l_S_k_0_k123: for (int k123 = 0; k123 < 48; k123++) {	// L4227
    float v3105 = v3096.read(); // v3096[k123];	// L4228
    float a111;	// L4229
    a111 = v3105;	// L4230
    float v3107 = v3097.read(); // v3097[k123];	// L4231
    float b111;	// L4232
    b111 = v3107;	// L4233
    float v3109 = a111;	// L4234
    float v3110 = b111;	// L4235
    float v3111 = v3109 * v3110;	// L4236
    float v3112 = v111;	// L4237
    float v3113 = v3112 + v3111;	// L4238
    v111 = v3113;	// L4239
    float v3114 = a111;	// L4240
    v3098.write(v3114); // v3098[k123] = v3114;	// L4241
    float v3115 = b111;	// L4242
    v3099.write(v3115); // v3099[k123] = v3115;	// L4243
  }
  float v3116 = v111;	// L4245
  v3100[v3101][v3102] = v3116;	// L4246
}

void systolic_tile_ffn1(
  float v3117[4][48],
  float v3118[48][4],
  float v3119[4][4]
) {	// L4249
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v3117 complete dim=1

  #pragma HLS array_partition variable=v3118 complete dim=2

  #pragma HLS array_partition variable=v3119 complete dim=1
  #pragma HLS array_partition variable=v3119 complete dim=2

  hls::stream< float > A_fifo6[4][5] /* A_fifo6[4][5][48] */;	// L4250
  #pragma HLS stream variable=A_fifo6 depth=5
  hls::stream< float > B_fifo6[4][5] /* B_fifo6[4][5][48] */;	// L4251
  #pragma HLS stream variable=B_fifo6 depth=5
  float A_drain6[4];	// L4252
  float B_drain6[4];	// L4253
  l_data_load_k124: for (int k124 = 0; k124 < 48; k124++) {	// L4254
    l_S_m_0_m12: for (int m12 = 0; m12 < 4; m12++) {	// L4255
      float v3126 = v3117[m12][k124];	// L4256
      A_fifo6[m12][0].write(v3126); // A_fifo6[m12][0][k124] = v3126;	// L4257
    }
    l_S_n_1_n12: for (int n12 = 0; n12 < 4; n12++) {	// L4259
      float v3128 = v3118[k124][n12];	// L4260
      B_fifo6[n12][0].write(v3128); // B_fifo6[n12][0][k124] = v3128;	// L4261
    }
  }
  hls::stream< float > &v3129 /* v3129[48] */ = A_fifo6[0][0];	// L4265
  hls::stream< float > &v3130 /* v3130[48] */ = B_fifo6[0][0];	// L4266
  hls::stream< float > &v3131 /* v3131[48] */ = A_fifo6[0][1];	// L4272
  hls::stream< float > &v3132 /* v3132[48] */ = B_fifo6[0][1];	// L4273
  PE_kernel_ffn1_0_0(v3129, v3130, v3131, v3132, v3119, 0, 0);	// L4274
  hls::stream< float > &v3133 /* v3133[48] */ = A_fifo6[0][1];	// L4276
  hls::stream< float > &v3134 /* v3134[48] */ = B_fifo6[1][0];	// L4277
  hls::stream< float > &v3135 /* v3135[48] */ = A_fifo6[0][2];	// L4281
  hls::stream< float > &v3136 /* v3136[48] */ = B_fifo6[1][1];	// L4282
  PE_kernel_ffn1_1_0(v3133, v3134, v3135, v3136, v3119, 0, 1);	// L4283
  hls::stream< float > &v3137 /* v3137[48] */ = A_fifo6[0][2];	// L4285
  hls::stream< float > &v3138 /* v3138[48] */ = B_fifo6[2][0];	// L4286
  hls::stream< float > &v3139 /* v3139[48] */ = A_fifo6[0][3];	// L4290
  hls::stream< float > &v3140 /* v3140[48] */ = B_fifo6[2][1];	// L4291
  PE_kernel_ffn1_2_0(v3137, v3138, v3139, v3140, v3119, 0, 2);	// L4292
  hls::stream< float > &v3141 /* v3141[48] */ = A_fifo6[0][3];	// L4294
  hls::stream< float > &v3142 /* v3142[48] */ = B_fifo6[3][0];	// L4295
  hls::stream< float > &v3143 /* v3143[48] */ = A_fifo6[0][4];	// L4299
  hls::stream< float > &v3144 /* v3144[48] */ = B_fifo6[3][1];	// L4300
  PE_kernel_ffn1_3_0(v3141, v3142, v3143, v3144, v3119, 0, 3);	// L4301
  hls::stream< float > &v3145 /* v3145[48] */ = A_fifo6[1][0];	// L4302
  hls::stream< float > &v3146 /* v3146[48] */ = B_fifo6[0][1];	// L4303
  hls::stream< float > &v3147 /* v3147[48] */ = A_fifo6[1][1];	// L4304
  hls::stream< float > &v3148 /* v3148[48] */ = B_fifo6[0][2];	// L4305
  PE_kernel_ffn1_0_1(v3145, v3146, v3147, v3148, v3119, 1, 0);	// L4306
  hls::stream< float > &v3149 /* v3149[48] */ = A_fifo6[1][1];	// L4307
  hls::stream< float > &v3150 /* v3150[48] */ = B_fifo6[1][1];	// L4308
  hls::stream< float > &v3151 /* v3151[48] */ = A_fifo6[1][2];	// L4309
  hls::stream< float > &v3152 /* v3152[48] */ = B_fifo6[1][2];	// L4310
  PE_kernel_ffn1_1_1(v3149, v3150, v3151, v3152, v3119, 1, 1);	// L4311
  hls::stream< float > &v3153 /* v3153[48] */ = A_fifo6[1][2];	// L4312
  hls::stream< float > &v3154 /* v3154[48] */ = B_fifo6[2][1];	// L4313
  hls::stream< float > &v3155 /* v3155[48] */ = A_fifo6[1][3];	// L4314
  hls::stream< float > &v3156 /* v3156[48] */ = B_fifo6[2][2];	// L4315
  PE_kernel_ffn1_2_1(v3153, v3154, v3155, v3156, v3119, 1, 2);	// L4316
  hls::stream< float > &v3157 /* v3157[48] */ = A_fifo6[1][3];	// L4317
  hls::stream< float > &v3158 /* v3158[48] */ = B_fifo6[3][1];	// L4318
  hls::stream< float > &v3159 /* v3159[48] */ = A_fifo6[1][4];	// L4319
  hls::stream< float > &v3160 /* v3160[48] */ = B_fifo6[3][2];	// L4320
  PE_kernel_ffn1_3_1(v3157, v3158, v3159, v3160, v3119, 1, 3);	// L4321
  hls::stream< float > &v3161 /* v3161[48] */ = A_fifo6[2][0];	// L4322
  hls::stream< float > &v3162 /* v3162[48] */ = B_fifo6[0][2];	// L4323
  hls::stream< float > &v3163 /* v3163[48] */ = A_fifo6[2][1];	// L4324
  hls::stream< float > &v3164 /* v3164[48] */ = B_fifo6[0][3];	// L4325
  PE_kernel_ffn1_0_2(v3161, v3162, v3163, v3164, v3119, 2, 0);	// L4326
  hls::stream< float > &v3165 /* v3165[48] */ = A_fifo6[2][1];	// L4327
  hls::stream< float > &v3166 /* v3166[48] */ = B_fifo6[1][2];	// L4328
  hls::stream< float > &v3167 /* v3167[48] */ = A_fifo6[2][2];	// L4329
  hls::stream< float > &v3168 /* v3168[48] */ = B_fifo6[1][3];	// L4330
  PE_kernel_ffn1_1_2(v3165, v3166, v3167, v3168, v3119, 2, 1);	// L4331
  hls::stream< float > &v3169 /* v3169[48] */ = A_fifo6[2][2];	// L4332
  hls::stream< float > &v3170 /* v3170[48] */ = B_fifo6[2][2];	// L4333
  hls::stream< float > &v3171 /* v3171[48] */ = A_fifo6[2][3];	// L4334
  hls::stream< float > &v3172 /* v3172[48] */ = B_fifo6[2][3];	// L4335
  PE_kernel_ffn1_2_2(v3169, v3170, v3171, v3172, v3119, 2, 2);	// L4336
  hls::stream< float > &v3173 /* v3173[48] */ = A_fifo6[2][3];	// L4337
  hls::stream< float > &v3174 /* v3174[48] */ = B_fifo6[3][2];	// L4338
  hls::stream< float > &v3175 /* v3175[48] */ = A_fifo6[2][4];	// L4339
  hls::stream< float > &v3176 /* v3176[48] */ = B_fifo6[3][3];	// L4340
  PE_kernel_ffn1_3_2(v3173, v3174, v3175, v3176, v3119, 2, 3);	// L4341
  hls::stream< float > &v3177 /* v3177[48] */ = A_fifo6[3][0];	// L4342
  hls::stream< float > &v3178 /* v3178[48] */ = B_fifo6[0][3];	// L4343
  hls::stream< float > &v3179 /* v3179[48] */ = A_fifo6[3][1];	// L4344
  hls::stream< float > &v3180 /* v3180[48] */ = B_fifo6[0][4];	// L4345
  PE_kernel_ffn1_0_3(v3177, v3178, v3179, v3180, v3119, 3, 0);	// L4346
  hls::stream< float > &v3181 /* v3181[48] */ = A_fifo6[3][1];	// L4347
  hls::stream< float > &v3182 /* v3182[48] */ = B_fifo6[1][3];	// L4348
  hls::stream< float > &v3183 /* v3183[48] */ = A_fifo6[3][2];	// L4349
  hls::stream< float > &v3184 /* v3184[48] */ = B_fifo6[1][4];	// L4350
  PE_kernel_ffn1_1_3(v3181, v3182, v3183, v3184, v3119, 3, 1);	// L4351
  hls::stream< float > &v3185 /* v3185[48] */ = A_fifo6[3][2];	// L4352
  hls::stream< float > &v3186 /* v3186[48] */ = B_fifo6[2][3];	// L4353
  hls::stream< float > &v3187 /* v3187[48] */ = A_fifo6[3][3];	// L4354
  hls::stream< float > &v3188 /* v3188[48] */ = B_fifo6[2][4];	// L4355
  PE_kernel_ffn1_2_3(v3185, v3186, v3187, v3188, v3119, 3, 2);	// L4356
  hls::stream< float > &v3189 /* v3189[48] */ = A_fifo6[3][3];	// L4357
  hls::stream< float > &v3190 /* v3190[48] */ = B_fifo6[3][3];	// L4358
  hls::stream< float > &v3191 /* v3191[48] */ = A_fifo6[3][4];	// L4359
  hls::stream< float > &v3192 /* v3192[48] */ = B_fifo6[3][4];	// L4360
  PE_kernel_ffn1_3_3(v3189, v3190, v3191, v3192, v3119, 3, 3);	// L4361
  l_data_drain_k125: for (int k125 = 0; k125 < 48; k125++) {	// L4362
    l_S_m_4_m13: for (int m13 = 0; m13 < 4; m13++) {	// L4363
      float v3195 = A_fifo6[m13][4].read(); // A_fifo6[m13][4][k125];	// L4364
      A_drain6[m13] = v3195;	// L4365
    }
    l_S_n_5_n13: for (int n13 = 0; n13 < 4; n13++) {	// L4367
      float v3197 = B_fifo6[n13][4].read(); // B_fifo6[n13][4][k125];	// L4368
      B_drain6[n13] = v3197;	// L4369
    }
  }
}

void systolic_ffn1(
  float v3198[32][48],
  float *Wmlp1,
  float v3200[32][192]
) {	// L4374
  float local_A6[4][48];	// L4375
  #pragma HLS array_partition variable=local_A6 complete dim=1

  float local_B6[48][4];	// L4376
  #pragma HLS array_partition variable=local_B6 complete dim=2

  float local_C6[4][4];	// L4377
  #pragma HLS array_partition variable=local_C6 complete dim=1
  #pragma HLS array_partition variable=local_C6 complete dim=2

  l_outer_tile_mi6: for (int mi6 = 0; mi6 < 8; mi6++) {	// L4378
    l_ni6: for (int ni6 = 0; ni6 < 48; ni6++) {	// L4379
    #pragma HLS dataflow
      l_load_A_tile_ak6: for (int ak6 = 0; ak6 < 48; ak6++) {	// L4380
        l_ai6: for (int ai6 = 0; ai6 < 4; ai6++) {	// L4381
        #pragma HLS pipeline II=1
          ap_int<33> v3208 = ni6;	// L4382
          bool v3209 = v3208 == 0;	// L4385
          if (v3209) {	// L4386
            float v3210 = v3198[((mi6 * 4) + ai6)][ak6];	// L4387
            local_A6[ai6][ak6] = v3210;	// L4388
          }
        }
      }
      l_load_B_tile_bk6: for (int bk6 = 0; bk6 < 48; bk6++) {	// L4392
        l_bj6: for (int bj6 = 0; bj6 < 4; bj6++) {	// L4393
        #pragma HLS pipeline II=1
          float v3213 = Wmlp1[bk6*192+((ni6 * 4) + bj6)];	// L4394
          // float v3213 = v3199[bk6][((ni6 * 4) + bj6)];	// L4394
          local_B6[bk6][bj6] = v3213;	// L4395
        }
      }
      systolic_tile_ffn1(local_A6, local_B6, local_C6);	// L4398
      l_store_C_tile_sj6: for (int sj6 = 0; sj6 < 4; sj6++) {	// L4399
        l_si6: for (int si6 = 0; si6 < 4; si6++) {	// L4400
        #pragma HLS pipeline II=1
          float v3216 = local_C6[si6][sj6];	// L4401
          v3200[((mi6 * 4) + si6)][((ni6 * 4) + sj6)] = v3216;	// L4402
        }
      }
    }
  }
}

void bias_add_1(
  float v3217[32][192],
  float v3218[192],
  float v3219[32][192]
) {	// L4409
  l_S_i_j_0_i10: for (int i10 = 0; i10 < 32; i10++) {	// L4411
    l_j9: for (int j9 = 0; j9 < 192; j9++) {	// L4412
      float v3222 = v3217[i10][j9];	// L4413
      float v3223 = v3218[j9];	// L4414
      float v3224 = v3222 + v3223;	// L4415
      v3219[i10][j9] = v3224;	// L4416
    }
  }
}

void GeLU(
  float v3225[32][192],
  float v3226[32][192]
) {	// L4421
  l_gelu_i11: for (int i11 = 0; i11 < 32; i11++) {	// L4423
    l_j10: for (int j10 = 0; j10 < 192; j10++) {	// L4424
      float v3229 = v3225[i11][j10];	// L4425
      float v3230 = v3229 * 0.500000;	// L4427
      float v3231 = pow(v3229, 3.000000);	// L4429
      float v3232 = v3231 * 0.044715;	// L4431
      float v3233 = v3229 + v3232;	// L4432
      float v3234 = v3233 * 0.797885;	// L4434
      float v3235 = tanh(v3234);	// L4435
      float v3236 = v3235 + 1.000000;	// L4437
      float v3237 = v3230 * v3236;	// L4438
      v3226[i11][j10] = v3237;	// L4439
    }
  }
}

void PE_kernel_ffn2_0_0(
  hls::stream< float > &v3238 /* v3238[192] */,
  hls::stream< float > &v3239 /* v3239[192] */,
  hls::stream< float > &v3240 /* v3240[192] */,
  hls::stream< float > &v3241 /* v3241[192] */,
  float v3242[4][4],
  int v3243,
  int v3244
) {	// L4444
  #pragma HLS stream variable=v3238 depth=5
  #pragma HLS stream variable=v3239 depth=5
  #pragma HLS stream variable=v3240 depth=5
  #pragma HLS stream variable=v3241 depth=5
  #pragma HLS array_partition variable=v3242 complete dim=1
  #pragma HLS array_partition variable=v3242 complete dim=2

  float v112;	// L4447
  v112 = 0.000000;	// L4448
  l_S_k_0_k126: for (int k126 = 0; k126 < 192; k126++) {	// L4449
    float v3247 = v3238.read(); // v3238[k126];	// L4450
    float a112;	// L4451
    a112 = v3247;	// L4452
    float v3249 = v3239.read(); // v3239[k126];	// L4453
    float b112;	// L4454
    b112 = v3249;	// L4455
    float v3251 = a112;	// L4456
    float v3252 = b112;	// L4457
    float v3253 = v3251 * v3252;	// L4458
    float v3254 = v112;	// L4459
    float v3255 = v3254 + v3253;	// L4460
    v112 = v3255;	// L4461
    float v3256 = a112;	// L4462
    v3240.write(v3256); // v3240[k126] = v3256;	// L4463
    float v3257 = b112;	// L4464
    v3241.write(v3257); // v3241[k126] = v3257;	// L4465
  }
  float v3258 = v112;	// L4467
  v3242[v3243][v3244] = v3258;	// L4468
}

void PE_kernel_ffn2_1_0(
  hls::stream< float > &v3259 /* v3259[192] */,
  hls::stream< float > &v3260 /* v3260[192] */,
  hls::stream< float > &v3261 /* v3261[192] */,
  hls::stream< float > &v3262 /* v3262[192] */,
  float v3263[4][4],
  int v3264,
  int v3265
) {	// L4471
  #pragma HLS stream variable=v3259 depth=5
  #pragma HLS stream variable=v3260 depth=5
  #pragma HLS stream variable=v3261 depth=5
  #pragma HLS stream variable=v3262 depth=5
  #pragma HLS array_partition variable=v3263 complete dim=1
  #pragma HLS array_partition variable=v3263 complete dim=2

  float v113;	// L4474
  v113 = 0.000000;	// L4475
  l_S_k_0_k127: for (int k127 = 0; k127 < 192; k127++) {	// L4476
    float v3268 = v3259.read(); // v3259[k127];	// L4477
    float a113;	// L4478
    a113 = v3268;	// L4479
    float v3270 = v3260.read(); // v3260[k127];	// L4480
    float b113;	// L4481
    b113 = v3270;	// L4482
    float v3272 = a113;	// L4483
    float v3273 = b113;	// L4484
    float v3274 = v3272 * v3273;	// L4485
    float v3275 = v113;	// L4486
    float v3276 = v3275 + v3274;	// L4487
    v113 = v3276;	// L4488
    float v3277 = a113;	// L4489
    v3261.write(v3277); // v3261[k127] = v3277;	// L4490
    float v3278 = b113;	// L4491
    v3262.write(v3278); // v3262[k127] = v3278;	// L4492
  }
  float v3279 = v113;	// L4494
  v3263[v3264][v3265] = v3279;	// L4495
}

void PE_kernel_ffn2_2_0(
  hls::stream< float > &v3280 /* v3280[192] */,
  hls::stream< float > &v3281 /* v3281[192] */,
  hls::stream< float > &v3282 /* v3282[192] */,
  hls::stream< float > &v3283 /* v3283[192] */,
  float v3284[4][4],
  int v3285,
  int v3286
) {	// L4498
  #pragma HLS stream variable=v3280 depth=5
  #pragma HLS stream variable=v3281 depth=5
  #pragma HLS stream variable=v3282 depth=5
  #pragma HLS stream variable=v3283 depth=5
  #pragma HLS array_partition variable=v3284 complete dim=1
  #pragma HLS array_partition variable=v3284 complete dim=2

  float v114;	// L4501
  v114 = 0.000000;	// L4502
  l_S_k_0_k128: for (int k128 = 0; k128 < 192; k128++) {	// L4503
    float v3289 = v3280.read(); // v3280[k128];	// L4504
    float a114;	// L4505
    a114 = v3289;	// L4506
    float v3291 = v3281.read(); // v3281[k128];	// L4507
    float b114;	// L4508
    b114 = v3291;	// L4509
    float v3293 = a114;	// L4510
    float v3294 = b114;	// L4511
    float v3295 = v3293 * v3294;	// L4512
    float v3296 = v114;	// L4513
    float v3297 = v3296 + v3295;	// L4514
    v114 = v3297;	// L4515
    float v3298 = a114;	// L4516
    v3282.write(v3298); // v3282[k128] = v3298;	// L4517
    float v3299 = b114;	// L4518
    v3283.write(v3299); // v3283[k128] = v3299;	// L4519
  }
  float v3300 = v114;	// L4521
  v3284[v3285][v3286] = v3300;	// L4522
}

void PE_kernel_ffn2_3_0(
  hls::stream< float > &v3301 /* v3301[192] */,
  hls::stream< float > &v3302 /* v3302[192] */,
  hls::stream< float > &v3303 /* v3303[192] */,
  hls::stream< float > &v3304 /* v3304[192] */,
  float v3305[4][4],
  int v3306,
  int v3307
) {	// L4525
  #pragma HLS stream variable=v3301 depth=5
  #pragma HLS stream variable=v3302 depth=5
  #pragma HLS stream variable=v3303 depth=5
  #pragma HLS stream variable=v3304 depth=5
  #pragma HLS array_partition variable=v3305 complete dim=1
  #pragma HLS array_partition variable=v3305 complete dim=2

  float v115;	// L4528
  v115 = 0.000000;	// L4529
  l_S_k_0_k129: for (int k129 = 0; k129 < 192; k129++) {	// L4530
    float v3310 = v3301.read(); // v3301[k129];	// L4531
    float a115;	// L4532
    a115 = v3310;	// L4533
    float v3312 = v3302.read(); // v3302[k129];	// L4534
    float b115;	// L4535
    b115 = v3312;	// L4536
    float v3314 = a115;	// L4537
    float v3315 = b115;	// L4538
    float v3316 = v3314 * v3315;	// L4539
    float v3317 = v115;	// L4540
    float v3318 = v3317 + v3316;	// L4541
    v115 = v3318;	// L4542
    float v3319 = a115;	// L4543
    v3303.write(v3319); // v3303[k129] = v3319;	// L4544
    float v3320 = b115;	// L4545
    v3304.write(v3320); // v3304[k129] = v3320;	// L4546
  }
  float v3321 = v115;	// L4548
  v3305[v3306][v3307] = v3321;	// L4549
}

void PE_kernel_ffn2_0_1(
  hls::stream< float > &v3322 /* v3322[192] */,
  hls::stream< float > &v3323 /* v3323[192] */,
  hls::stream< float > &v3324 /* v3324[192] */,
  hls::stream< float > &v3325 /* v3325[192] */,
  float v3326[4][4],
  int v3327,
  int v3328
) {	// L4552
  #pragma HLS stream variable=v3322 depth=5
  #pragma HLS stream variable=v3323 depth=5
  #pragma HLS stream variable=v3324 depth=5
  #pragma HLS stream variable=v3325 depth=5
  #pragma HLS array_partition variable=v3326 complete dim=1
  #pragma HLS array_partition variable=v3326 complete dim=2

  float v116;	// L4555
  v116 = 0.000000;	// L4556
  l_S_k_0_k130: for (int k130 = 0; k130 < 192; k130++) {	// L4557
    float v3331 = v3322.read(); // v3322[k130];	// L4558
    float a116;	// L4559
    a116 = v3331;	// L4560
    float v3333 = v3323.read(); // v3323[k130];	// L4561
    float b116;	// L4562
    b116 = v3333;	// L4563
    float v3335 = a116;	// L4564
    float v3336 = b116;	// L4565
    float v3337 = v3335 * v3336;	// L4566
    float v3338 = v116;	// L4567
    float v3339 = v3338 + v3337;	// L4568
    v116 = v3339;	// L4569
    float v3340 = a116;	// L4570
    v3324.write(v3340); // v3324[k130] = v3340;	// L4571
    float v3341 = b116;	// L4572
    v3325.write(v3341); // v3325[k130] = v3341;	// L4573
  }
  float v3342 = v116;	// L4575
  v3326[v3327][v3328] = v3342;	// L4576
}

void PE_kernel_ffn2_1_1(
  hls::stream< float > &v3343 /* v3343[192] */,
  hls::stream< float > &v3344 /* v3344[192] */,
  hls::stream< float > &v3345 /* v3345[192] */,
  hls::stream< float > &v3346 /* v3346[192] */,
  float v3347[4][4],
  int v3348,
  int v3349
) {	// L4579
  #pragma HLS stream variable=v3343 depth=5
  #pragma HLS stream variable=v3344 depth=5
  #pragma HLS stream variable=v3345 depth=5
  #pragma HLS stream variable=v3346 depth=5
  #pragma HLS array_partition variable=v3347 complete dim=1
  #pragma HLS array_partition variable=v3347 complete dim=2

  float v117;	// L4582
  v117 = 0.000000;	// L4583
  l_S_k_0_k131: for (int k131 = 0; k131 < 192; k131++) {	// L4584
    float v3352 = v3343.read(); // v3343[k131];	// L4585
    float a117;	// L4586
    a117 = v3352;	// L4587
    float v3354 = v3344.read(); // v3344[k131];	// L4588
    float b117;	// L4589
    b117 = v3354;	// L4590
    float v3356 = a117;	// L4591
    float v3357 = b117;	// L4592
    float v3358 = v3356 * v3357;	// L4593
    float v3359 = v117;	// L4594
    float v3360 = v3359 + v3358;	// L4595
    v117 = v3360;	// L4596
    float v3361 = a117;	// L4597
    v3345.write(v3361); // v3345[k131] = v3361;	// L4598
    float v3362 = b117;	// L4599
    v3346.write(v3362); // v3346[k131] = v3362;	// L4600
  }
  float v3363 = v117;	// L4602
  v3347[v3348][v3349] = v3363;	// L4603
}

void PE_kernel_ffn2_2_1(
  hls::stream< float > &v3364 /* v3364[192] */,
  hls::stream< float > &v3365 /* v3365[192] */,
  hls::stream< float > &v3366 /* v3366[192] */,
  hls::stream< float > &v3367 /* v3367[192] */,
  float v3368[4][4],
  int v3369,
  int v3370
) {	// L4606
  #pragma HLS stream variable=v3364 depth=5
  #pragma HLS stream variable=v3365 depth=5
  #pragma HLS stream variable=v3366 depth=5
  #pragma HLS stream variable=v3367 depth=5
  #pragma HLS array_partition variable=v3368 complete dim=1
  #pragma HLS array_partition variable=v3368 complete dim=2

  float v118;	// L4609
  v118 = 0.000000;	// L4610
  l_S_k_0_k132: for (int k132 = 0; k132 < 192; k132++) {	// L4611
    float v3373 = v3364.read(); // v3364[k132];	// L4612
    float a118;	// L4613
    a118 = v3373;	// L4614
    float v3375 = v3365.read(); // v3365[k132];	// L4615
    float b118;	// L4616
    b118 = v3375;	// L4617
    float v3377 = a118;	// L4618
    float v3378 = b118;	// L4619
    float v3379 = v3377 * v3378;	// L4620
    float v3380 = v118;	// L4621
    float v3381 = v3380 + v3379;	// L4622
    v118 = v3381;	// L4623
    float v3382 = a118;	// L4624
    v3366.write(v3382); // v3366[k132] = v3382;	// L4625
    float v3383 = b118;	// L4626
    v3367.write(v3383); // v3367[k132] = v3383;	// L4627
  }
  float v3384 = v118;	// L4629
  v3368[v3369][v3370] = v3384;	// L4630
}

void PE_kernel_ffn2_3_1(
  hls::stream< float > &v3385 /* v3385[192] */,
  hls::stream< float > &v3386 /* v3386[192] */,
  hls::stream< float > &v3387 /* v3387[192] */,
  hls::stream< float > &v3388 /* v3388[192] */,
  float v3389[4][4],
  int v3390,
  int v3391
) {	// L4633
  #pragma HLS stream variable=v3385 depth=5
  #pragma HLS stream variable=v3386 depth=5
  #pragma HLS stream variable=v3387 depth=5
  #pragma HLS stream variable=v3388 depth=5
  #pragma HLS array_partition variable=v3389 complete dim=1
  #pragma HLS array_partition variable=v3389 complete dim=2

  float v119;	// L4636
  v119 = 0.000000;	// L4637
  l_S_k_0_k133: for (int k133 = 0; k133 < 192; k133++) {	// L4638
    float v3394 = v3385.read(); // v3385[k133];	// L4639
    float a119;	// L4640
    a119 = v3394;	// L4641
    float v3396 = v3386.read(); // v3386[k133];	// L4642
    float b119;	// L4643
    b119 = v3396;	// L4644
    float v3398 = a119;	// L4645
    float v3399 = b119;	// L4646
    float v3400 = v3398 * v3399;	// L4647
    float v3401 = v119;	// L4648
    float v3402 = v3401 + v3400;	// L4649
    v119 = v3402;	// L4650
    float v3403 = a119;	// L4651
    v3387.write(v3403); // v3387[k133] = v3403;	// L4652
    float v3404 = b119;	// L4653
    v3388.write(v3404); // v3388[k133] = v3404;	// L4654
  }
  float v3405 = v119;	// L4656
  v3389[v3390][v3391] = v3405;	// L4657
}

void PE_kernel_ffn2_0_2(
  hls::stream< float > &v3406 /* v3406[192] */,
  hls::stream< float > &v3407 /* v3407[192] */,
  hls::stream< float > &v3408 /* v3408[192] */,
  hls::stream< float > &v3409 /* v3409[192] */,
  float v3410[4][4],
  int v3411,
  int v3412
) {	// L4660
  #pragma HLS stream variable=v3406 depth=5
  #pragma HLS stream variable=v3407 depth=5
  #pragma HLS stream variable=v3408 depth=5
  #pragma HLS stream variable=v3409 depth=5
  #pragma HLS array_partition variable=v3410 complete dim=1
  #pragma HLS array_partition variable=v3410 complete dim=2

  float v120;	// L4663
  v120 = 0.000000;	// L4664
  l_S_k_0_k134: for (int k134 = 0; k134 < 192; k134++) {	// L4665
    float v3415 = v3406.read(); // v3406[k134];	// L4666
    float a120;	// L4667
    a120 = v3415;	// L4668
    float v3417 = v3407.read(); // v3407[k134];	// L4669
    float b120;	// L4670
    b120 = v3417;	// L4671
    float v3419 = a120;	// L4672
    float v3420 = b120;	// L4673
    float v3421 = v3419 * v3420;	// L4674
    float v3422 = v120;	// L4675
    float v3423 = v3422 + v3421;	// L4676
    v120 = v3423;	// L4677
    float v3424 = a120;	// L4678
    v3408.write(v3424); // v3408[k134] = v3424;	// L4679
    float v3425 = b120;	// L4680
    v3409.write(v3425); // v3409[k134] = v3425;	// L4681
  }
  float v3426 = v120;	// L4683
  v3410[v3411][v3412] = v3426;	// L4684
}

void PE_kernel_ffn2_1_2(
  hls::stream< float > &v3427 /* v3427[192] */,
  hls::stream< float > &v3428 /* v3428[192] */,
  hls::stream< float > &v3429 /* v3429[192] */,
  hls::stream< float > &v3430 /* v3430[192] */,
  float v3431[4][4],
  int v3432,
  int v3433
) {	// L4687
  #pragma HLS stream variable=v3427 depth=5
  #pragma HLS stream variable=v3428 depth=5
  #pragma HLS stream variable=v3429 depth=5
  #pragma HLS stream variable=v3430 depth=5
  #pragma HLS array_partition variable=v3431 complete dim=1
  #pragma HLS array_partition variable=v3431 complete dim=2

  float v121;	// L4690
  v121 = 0.000000;	// L4691
  l_S_k_0_k135: for (int k135 = 0; k135 < 192; k135++) {	// L4692
    float v3436 = v3427.read(); // v3427[k135];	// L4693
    float a121;	// L4694
    a121 = v3436;	// L4695
    float v3438 = v3428.read(); // v3428[k135];	// L4696
    float b121;	// L4697
    b121 = v3438;	// L4698
    float v3440 = a121;	// L4699
    float v3441 = b121;	// L4700
    float v3442 = v3440 * v3441;	// L4701
    float v3443 = v121;	// L4702
    float v3444 = v3443 + v3442;	// L4703
    v121 = v3444;	// L4704
    float v3445 = a121;	// L4705
    v3429.write(v3445); // v3429[k135] = v3445;	// L4706
    float v3446 = b121;	// L4707
    v3430.write(v3446); // v3430[k135] = v3446;	// L4708
  }
  float v3447 = v121;	// L4710
  v3431[v3432][v3433] = v3447;	// L4711
}

void PE_kernel_ffn2_2_2(
  hls::stream< float > &v3448 /* v3448[192] */,
  hls::stream< float > &v3449 /* v3449[192] */,
  hls::stream< float > &v3450 /* v3450[192] */,
  hls::stream< float > &v3451 /* v3451[192] */,
  float v3452[4][4],
  int v3453,
  int v3454
) {	// L4714
  #pragma HLS stream variable=v3448 depth=5
  #pragma HLS stream variable=v3449 depth=5
  #pragma HLS stream variable=v3450 depth=5
  #pragma HLS stream variable=v3451 depth=5
  #pragma HLS array_partition variable=v3452 complete dim=1
  #pragma HLS array_partition variable=v3452 complete dim=2

  float v122;	// L4717
  v122 = 0.000000;	// L4718
  l_S_k_0_k136: for (int k136 = 0; k136 < 192; k136++) {	// L4719
    float v3457 = v3448.read(); // v3448[k136];	// L4720
    float a122;	// L4721
    a122 = v3457;	// L4722
    float v3459 = v3449.read(); // v3449[k136];	// L4723
    float b122;	// L4724
    b122 = v3459;	// L4725
    float v3461 = a122;	// L4726
    float v3462 = b122;	// L4727
    float v3463 = v3461 * v3462;	// L4728
    float v3464 = v122;	// L4729
    float v3465 = v3464 + v3463;	// L4730
    v122 = v3465;	// L4731
    float v3466 = a122;	// L4732
    v3450.write(v3466); // v3450[k136] = v3466;	// L4733
    float v3467 = b122;	// L4734
    v3451.write(v3467); // v3451[k136] = v3467;	// L4735
  }
  float v3468 = v122;	// L4737
  v3452[v3453][v3454] = v3468;	// L4738
}

void PE_kernel_ffn2_3_2(
  hls::stream< float > &v3469 /* v3469[192] */,
  hls::stream< float > &v3470 /* v3470[192] */,
  hls::stream< float > &v3471 /* v3471[192] */,
  hls::stream< float > &v3472 /* v3472[192] */,
  float v3473[4][4],
  int v3474,
  int v3475
) {	// L4741
  #pragma HLS stream variable=v3469 depth=5
  #pragma HLS stream variable=v3470 depth=5
  #pragma HLS stream variable=v3471 depth=5
  #pragma HLS stream variable=v3472 depth=5
  #pragma HLS array_partition variable=v3473 complete dim=1
  #pragma HLS array_partition variable=v3473 complete dim=2

  float v123;	// L4744
  v123 = 0.000000;	// L4745
  l_S_k_0_k137: for (int k137 = 0; k137 < 192; k137++) {	// L4746
    float v3478 = v3469.read(); // v3469[k137];	// L4747
    float a123;	// L4748
    a123 = v3478;	// L4749
    float v3480 = v3470.read(); // v3470[k137];	// L4750
    float b123;	// L4751
    b123 = v3480;	// L4752
    float v3482 = a123;	// L4753
    float v3483 = b123;	// L4754
    float v3484 = v3482 * v3483;	// L4755
    float v3485 = v123;	// L4756
    float v3486 = v3485 + v3484;	// L4757
    v123 = v3486;	// L4758
    float v3487 = a123;	// L4759
    v3471.write(v3487); // v3471[k137] = v3487;	// L4760
    float v3488 = b123;	// L4761
    v3472.write(v3488); // v3472[k137] = v3488;	// L4762
  }
  float v3489 = v123;	// L4764
  v3473[v3474][v3475] = v3489;	// L4765
}

void PE_kernel_ffn2_0_3(
  hls::stream< float > &v3490 /* v3490[192] */,
  hls::stream< float > &v3491 /* v3491[192] */,
  hls::stream< float > &v3492 /* v3492[192] */,
  hls::stream< float > &v3493 /* v3493[192] */,
  float v3494[4][4],
  int v3495,
  int v3496
) {	// L4768
  #pragma HLS stream variable=v3490 depth=5
  #pragma HLS stream variable=v3491 depth=5
  #pragma HLS stream variable=v3492 depth=5
  #pragma HLS stream variable=v3493 depth=5
  #pragma HLS array_partition variable=v3494 complete dim=1
  #pragma HLS array_partition variable=v3494 complete dim=2

  float v124;	// L4771
  v124 = 0.000000;	// L4772
  l_S_k_0_k138: for (int k138 = 0; k138 < 192; k138++) {	// L4773
    float v3499 = v3490.read(); // v3490[k138];	// L4774
    float a124;	// L4775
    a124 = v3499;	// L4776
    float v3501 = v3491.read(); // v3491[k138];	// L4777
    float b124;	// L4778
    b124 = v3501;	// L4779
    float v3503 = a124;	// L4780
    float v3504 = b124;	// L4781
    float v3505 = v3503 * v3504;	// L4782
    float v3506 = v124;	// L4783
    float v3507 = v3506 + v3505;	// L4784
    v124 = v3507;	// L4785
    float v3508 = a124;	// L4786
    v3492.write(v3508); // v3492[k138] = v3508;	// L4787
    float v3509 = b124;	// L4788
    v3493.write(v3509); // v3493[k138] = v3509;	// L4789
  }
  float v3510 = v124;	// L4791
  v3494[v3495][v3496] = v3510;	// L4792
}

void PE_kernel_ffn2_1_3(
  hls::stream< float > &v3511 /* v3511[192] */,
  hls::stream< float > &v3512 /* v3512[192] */,
  hls::stream< float > &v3513 /* v3513[192] */,
  hls::stream< float > &v3514 /* v3514[192] */,
  float v3515[4][4],
  int v3516,
  int v3517
) {	// L4795
  #pragma HLS stream variable=v3511 depth=5
  #pragma HLS stream variable=v3512 depth=5
  #pragma HLS stream variable=v3513 depth=5
  #pragma HLS stream variable=v3514 depth=5
  #pragma HLS array_partition variable=v3515 complete dim=1
  #pragma HLS array_partition variable=v3515 complete dim=2

  float v125;	// L4798
  v125 = 0.000000;	// L4799
  l_S_k_0_k139: for (int k139 = 0; k139 < 192; k139++) {	// L4800
    float v3520 = v3511.read(); // v3511[k139];	// L4801
    float a125;	// L4802
    a125 = v3520;	// L4803
    float v3522 = v3512.read(); // v3512[k139];	// L4804
    float b125;	// L4805
    b125 = v3522;	// L4806
    float v3524 = a125;	// L4807
    float v3525 = b125;	// L4808
    float v3526 = v3524 * v3525;	// L4809
    float v3527 = v125;	// L4810
    float v3528 = v3527 + v3526;	// L4811
    v125 = v3528;	// L4812
    float v3529 = a125;	// L4813
    v3513.write(v3529); // v3513[k139] = v3529;	// L4814
    float v3530 = b125;	// L4815
    v3514.write(v3530); // v3514[k139] = v3530;	// L4816
  }
  float v3531 = v125;	// L4818
  v3515[v3516][v3517] = v3531;	// L4819
}

void PE_kernel_ffn2_2_3(
  hls::stream< float > &v3532 /* v3532[192] */,
  hls::stream< float > &v3533 /* v3533[192] */,
  hls::stream< float > &v3534 /* v3534[192] */,
  hls::stream< float > &v3535 /* v3535[192] */,
  float v3536[4][4],
  int v3537,
  int v3538
) {	// L4822
  #pragma HLS stream variable=v3532 depth=5
  #pragma HLS stream variable=v3533 depth=5
  #pragma HLS stream variable=v3534 depth=5
  #pragma HLS stream variable=v3535 depth=5
  #pragma HLS array_partition variable=v3536 complete dim=1
  #pragma HLS array_partition variable=v3536 complete dim=2

  float v126;	// L4825
  v126 = 0.000000;	// L4826
  l_S_k_0_k140: for (int k140 = 0; k140 < 192; k140++) {	// L4827
    float v3541 = v3532.read(); // v3532[k140];	// L4828
    float a126;	// L4829
    a126 = v3541;	// L4830
    float v3543 = v3533.read(); // v3533[k140];	// L4831
    float b126;	// L4832
    b126 = v3543;	// L4833
    float v3545 = a126;	// L4834
    float v3546 = b126;	// L4835
    float v3547 = v3545 * v3546;	// L4836
    float v3548 = v126;	// L4837
    float v3549 = v3548 + v3547;	// L4838
    v126 = v3549;	// L4839
    float v3550 = a126;	// L4840
    v3534.write(v3550); // v3534[k140] = v3550;	// L4841
    float v3551 = b126;	// L4842
    v3535.write(v3551); // v3535[k140] = v3551;	// L4843
  }
  float v3552 = v126;	// L4845
  v3536[v3537][v3538] = v3552;	// L4846
}

void PE_kernel_ffn2_3_3(
  hls::stream< float > &v3553 /* v3553[192] */,
  hls::stream< float > &v3554 /* v3554[192] */,
  hls::stream< float > &v3555 /* v3555[192] */,
  hls::stream< float > &v3556 /* v3556[192] */,
  float v3557[4][4],
  int v3558,
  int v3559
) {	// L4849
  #pragma HLS stream variable=v3553 depth=5
  #pragma HLS stream variable=v3554 depth=5
  #pragma HLS stream variable=v3555 depth=5
  #pragma HLS stream variable=v3556 depth=5
  #pragma HLS array_partition variable=v3557 complete dim=1
  #pragma HLS array_partition variable=v3557 complete dim=2

  float v127;	// L4852
  v127 = 0.000000;	// L4853
  l_S_k_0_k141: for (int k141 = 0; k141 < 192; k141++) {	// L4854
    float v3562 = v3553.read(); // v3553[k141];	// L4855
    float a127;	// L4856
    a127 = v3562;	// L4857
    float v3564 = v3554.read(); // v3554[k141];	// L4858
    float b127;	// L4859
    b127 = v3564;	// L4860
    float v3566 = a127;	// L4861
    float v3567 = b127;	// L4862
    float v3568 = v3566 * v3567;	// L4863
    float v3569 = v127;	// L4864
    float v3570 = v3569 + v3568;	// L4865
    v127 = v3570;	// L4866
    float v3571 = a127;	// L4867
    v3555.write(v3571); // v3555[k141] = v3571;	// L4868
    float v3572 = b127;	// L4869
    v3556.write(v3572); // v3556[k141] = v3572;	// L4870
  }
  float v3573 = v127;	// L4872
  v3557[v3558][v3559] = v3573;	// L4873
}

void systolic_tile_ffn2(
  float v3574[4][192],
  float v3575[192][4],
  float v3576[4][4]
) {	// L4876
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v3574 complete dim=1

  #pragma HLS array_partition variable=v3575 complete dim=2

  #pragma HLS array_partition variable=v3576 complete dim=1
  #pragma HLS array_partition variable=v3576 complete dim=2

  hls::stream< float > A_fifo7[4][5] /* A_fifo7[4][5][192] */;	// L4877
  #pragma HLS stream variable=A_fifo7 depth=5
  hls::stream< float > B_fifo7[4][5] /* B_fifo7[4][5][192] */;	// L4878
  #pragma HLS stream variable=B_fifo7 depth=5
  float A_drain7[4];	// L4879
  float B_drain7[4];	// L4880
  l_data_load_k142: for (int k142 = 0; k142 < 192; k142++) {	// L4881
    l_S_m_0_m14: for (int m14 = 0; m14 < 4; m14++) {	// L4882
      float v3583 = v3574[m14][k142];	// L4883
      A_fifo7[m14][0].write(v3583); // A_fifo7[m14][0][k142] = v3583;	// L4884
    }
    l_S_n_1_n14: for (int n14 = 0; n14 < 4; n14++) {	// L4886
      float v3585 = v3575[k142][n14];	// L4887
      B_fifo7[n14][0].write(v3585); // B_fifo7[n14][0][k142] = v3585;	// L4888
    }
  }
  hls::stream< float > &v3586 /* v3586[192] */ = A_fifo7[0][0];	// L4892
  hls::stream< float > &v3587 /* v3587[192] */ = B_fifo7[0][0];	// L4893
  hls::stream< float > &v3588 /* v3588[192] */ = A_fifo7[0][1];	// L4899
  hls::stream< float > &v3589 /* v3589[192] */ = B_fifo7[0][1];	// L4900
  PE_kernel_ffn2_0_0(v3586, v3587, v3588, v3589, v3576, 0, 0);	// L4901
  hls::stream< float > &v3590 /* v3590[192] */ = A_fifo7[0][1];	// L4903
  hls::stream< float > &v3591 /* v3591[192] */ = B_fifo7[1][0];	// L4904
  hls::stream< float > &v3592 /* v3592[192] */ = A_fifo7[0][2];	// L4908
  hls::stream< float > &v3593 /* v3593[192] */ = B_fifo7[1][1];	// L4909
  PE_kernel_ffn2_1_0(v3590, v3591, v3592, v3593, v3576, 0, 1);	// L4910
  hls::stream< float > &v3594 /* v3594[192] */ = A_fifo7[0][2];	// L4912
  hls::stream< float > &v3595 /* v3595[192] */ = B_fifo7[2][0];	// L4913
  hls::stream< float > &v3596 /* v3596[192] */ = A_fifo7[0][3];	// L4917
  hls::stream< float > &v3597 /* v3597[192] */ = B_fifo7[2][1];	// L4918
  PE_kernel_ffn2_2_0(v3594, v3595, v3596, v3597, v3576, 0, 2);	// L4919
  hls::stream< float > &v3598 /* v3598[192] */ = A_fifo7[0][3];	// L4921
  hls::stream< float > &v3599 /* v3599[192] */ = B_fifo7[3][0];	// L4922
  hls::stream< float > &v3600 /* v3600[192] */ = A_fifo7[0][4];	// L4926
  hls::stream< float > &v3601 /* v3601[192] */ = B_fifo7[3][1];	// L4927
  PE_kernel_ffn2_3_0(v3598, v3599, v3600, v3601, v3576, 0, 3);	// L4928
  hls::stream< float > &v3602 /* v3602[192] */ = A_fifo7[1][0];	// L4929
  hls::stream< float > &v3603 /* v3603[192] */ = B_fifo7[0][1];	// L4930
  hls::stream< float > &v3604 /* v3604[192] */ = A_fifo7[1][1];	// L4931
  hls::stream< float > &v3605 /* v3605[192] */ = B_fifo7[0][2];	// L4932
  PE_kernel_ffn2_0_1(v3602, v3603, v3604, v3605, v3576, 1, 0);	// L4933
  hls::stream< float > &v3606 /* v3606[192] */ = A_fifo7[1][1];	// L4934
  hls::stream< float > &v3607 /* v3607[192] */ = B_fifo7[1][1];	// L4935
  hls::stream< float > &v3608 /* v3608[192] */ = A_fifo7[1][2];	// L4936
  hls::stream< float > &v3609 /* v3609[192] */ = B_fifo7[1][2];	// L4937
  PE_kernel_ffn2_1_1(v3606, v3607, v3608, v3609, v3576, 1, 1);	// L4938
  hls::stream< float > &v3610 /* v3610[192] */ = A_fifo7[1][2];	// L4939
  hls::stream< float > &v3611 /* v3611[192] */ = B_fifo7[2][1];	// L4940
  hls::stream< float > &v3612 /* v3612[192] */ = A_fifo7[1][3];	// L4941
  hls::stream< float > &v3613 /* v3613[192] */ = B_fifo7[2][2];	// L4942
  PE_kernel_ffn2_2_1(v3610, v3611, v3612, v3613, v3576, 1, 2);	// L4943
  hls::stream< float > &v3614 /* v3614[192] */ = A_fifo7[1][3];	// L4944
  hls::stream< float > &v3615 /* v3615[192] */ = B_fifo7[3][1];	// L4945
  hls::stream< float > &v3616 /* v3616[192] */ = A_fifo7[1][4];	// L4946
  hls::stream< float > &v3617 /* v3617[192] */ = B_fifo7[3][2];	// L4947
  PE_kernel_ffn2_3_1(v3614, v3615, v3616, v3617, v3576, 1, 3);	// L4948
  hls::stream< float > &v3618 /* v3618[192] */ = A_fifo7[2][0];	// L4949
  hls::stream< float > &v3619 /* v3619[192] */ = B_fifo7[0][2];	// L4950
  hls::stream< float > &v3620 /* v3620[192] */ = A_fifo7[2][1];	// L4951
  hls::stream< float > &v3621 /* v3621[192] */ = B_fifo7[0][3];	// L4952
  PE_kernel_ffn2_0_2(v3618, v3619, v3620, v3621, v3576, 2, 0);	// L4953
  hls::stream< float > &v3622 /* v3622[192] */ = A_fifo7[2][1];	// L4954
  hls::stream< float > &v3623 /* v3623[192] */ = B_fifo7[1][2];	// L4955
  hls::stream< float > &v3624 /* v3624[192] */ = A_fifo7[2][2];	// L4956
  hls::stream< float > &v3625 /* v3625[192] */ = B_fifo7[1][3];	// L4957
  PE_kernel_ffn2_1_2(v3622, v3623, v3624, v3625, v3576, 2, 1);	// L4958
  hls::stream< float > &v3626 /* v3626[192] */ = A_fifo7[2][2];	// L4959
  hls::stream< float > &v3627 /* v3627[192] */ = B_fifo7[2][2];	// L4960
  hls::stream< float > &v3628 /* v3628[192] */ = A_fifo7[2][3];	// L4961
  hls::stream< float > &v3629 /* v3629[192] */ = B_fifo7[2][3];	// L4962
  PE_kernel_ffn2_2_2(v3626, v3627, v3628, v3629, v3576, 2, 2);	// L4963
  hls::stream< float > &v3630 /* v3630[192] */ = A_fifo7[2][3];	// L4964
  hls::stream< float > &v3631 /* v3631[192] */ = B_fifo7[3][2];	// L4965
  hls::stream< float > &v3632 /* v3632[192] */ = A_fifo7[2][4];	// L4966
  hls::stream< float > &v3633 /* v3633[192] */ = B_fifo7[3][3];	// L4967
  PE_kernel_ffn2_3_2(v3630, v3631, v3632, v3633, v3576, 2, 3);	// L4968
  hls::stream< float > &v3634 /* v3634[192] */ = A_fifo7[3][0];	// L4969
  hls::stream< float > &v3635 /* v3635[192] */ = B_fifo7[0][3];	// L4970
  hls::stream< float > &v3636 /* v3636[192] */ = A_fifo7[3][1];	// L4971
  hls::stream< float > &v3637 /* v3637[192] */ = B_fifo7[0][4];	// L4972
  PE_kernel_ffn2_0_3(v3634, v3635, v3636, v3637, v3576, 3, 0);	// L4973
  hls::stream< float > &v3638 /* v3638[192] */ = A_fifo7[3][1];	// L4974
  hls::stream< float > &v3639 /* v3639[192] */ = B_fifo7[1][3];	// L4975
  hls::stream< float > &v3640 /* v3640[192] */ = A_fifo7[3][2];	// L4976
  hls::stream< float > &v3641 /* v3641[192] */ = B_fifo7[1][4];	// L4977
  PE_kernel_ffn2_1_3(v3638, v3639, v3640, v3641, v3576, 3, 1);	// L4978
  hls::stream< float > &v3642 /* v3642[192] */ = A_fifo7[3][2];	// L4979
  hls::stream< float > &v3643 /* v3643[192] */ = B_fifo7[2][3];	// L4980
  hls::stream< float > &v3644 /* v3644[192] */ = A_fifo7[3][3];	// L4981
  hls::stream< float > &v3645 /* v3645[192] */ = B_fifo7[2][4];	// L4982
  PE_kernel_ffn2_2_3(v3642, v3643, v3644, v3645, v3576, 3, 2);	// L4983
  hls::stream< float > &v3646 /* v3646[192] */ = A_fifo7[3][3];	// L4984
  hls::stream< float > &v3647 /* v3647[192] */ = B_fifo7[3][3];	// L4985
  hls::stream< float > &v3648 /* v3648[192] */ = A_fifo7[3][4];	// L4986
  hls::stream< float > &v3649 /* v3649[192] */ = B_fifo7[3][4];	// L4987
  PE_kernel_ffn2_3_3(v3646, v3647, v3648, v3649, v3576, 3, 3);	// L4988
  l_data_drain_k143: for (int k143 = 0; k143 < 192; k143++) {	// L4989
    l_S_m_4_m15: for (int m15 = 0; m15 < 4; m15++) {	// L4990
      float v3652 = A_fifo7[m15][4].read(); // A_fifo7[m15][4][k143];	// L4991
      A_drain7[m15] = v3652;	// L4992
    }
    l_S_n_5_n15: for (int n15 = 0; n15 < 4; n15++) {	// L4994
      float v3654 = B_fifo7[n15][4].read(); // B_fifo7[n15][4][k143];	// L4995
      B_drain7[n15] = v3654;	// L4996
    }
  }
}

void systolic_ffn2(
  float v3655[32][192],
  float *Wmlp2,
  float v3657[32][48]
) {	// L5001
  float local_A7[4][192];	// L5002
  #pragma HLS array_partition variable=local_A7 complete dim=1

  float local_B7[192][4];	// L5003
  #pragma HLS array_partition variable=local_B7 complete dim=2

  float local_C7[4][4];	// L5004
  #pragma HLS array_partition variable=local_C7 complete dim=1
  #pragma HLS array_partition variable=local_C7 complete dim=2

  l_outer_tile_mi7: for (int mi7 = 0; mi7 < 8; mi7++) {	// L5005
    l_ni7: for (int ni7 = 0; ni7 < 12; ni7++) {	// L5006
    #pragma HLS dataflow
      l_load_A_tile_ak7: for (int ak7 = 0; ak7 < 192; ak7++) {	// L5007
        l_ai7: for (int ai7 = 0; ai7 < 4; ai7++) {	// L5008
        #pragma HLS pipeline II=1
          ap_int<33> v3665 = ni7;	// L5009
          bool v3666 = v3665 == 0;	// L5012
          if (v3666) {	// L5013
            float v3667 = v3655[((mi7 * 4) + ai7)][ak7];	// L5014
            local_A7[ai7][ak7] = v3667;	// L5015
          }
        }
      }
      l_load_B_tile_bk7: for (int bk7 = 0; bk7 < 192; bk7++) {	// L5019
        l_bj7: for (int bj7 = 0; bj7 < 4; bj7++) {	// L5020
        #pragma HLS pipeline II=1
          float v3670 = Wmlp2[bk7*48+((ni7 * 4) + bj7)];	// L5021
          // float v3670 = v3656[bk7][((ni7 * 4) + bj7)];	// L5021
          local_B7[bk7][bj7] = v3670;	// L5022
        }
      }
      systolic_tile_ffn2(local_A7, local_B7, local_C7);	// L5025
      l_store_C_tile_sj7: for (int sj7 = 0; sj7 < 4; sj7++) {	// L5026
        l_si7: for (int si7 = 0; si7 < 4; si7++) {	// L5027
        #pragma HLS pipeline II=1
          float v3673 = local_C7[si7][sj7];	// L5028
          v3657[((mi7 * 4) + si7)][((ni7 * 4) + sj7)] = v3673;	// L5029
        }
      }
    }
  }
}

void GPTNEOLayer(
  float *v3674,
  float *v3675,
  float *v3676,
  float *v3677,
  float *v3678,
  float *v3679,
  float *v3680,
  float *v3681,
  float *v3682,
  float *v3683,
  float *v3684,
  float *v3685,
  float *v3686,
  float *v3687,
  int32_t *v3688,
  float *v3689
) {	// L5036
  #pragma HLS interface m_axi port=v3674 offset=slave bundle=gmem0
  #pragma HLS interface m_axi port=v3675 offset=slave bundle=gmem1
  #pragma HLS interface m_axi port=v3676 offset=slave bundle=gmem2
  #pragma HLS interface m_axi port=v3677 offset=slave bundle=gmem3
  #pragma HLS interface m_axi port=v3678 offset=slave bundle=gmem4
  #pragma HLS interface m_axi port=v3679 offset=slave bundle=gmem5
  #pragma HLS interface m_axi port=v3680 offset=slave bundle=gmem6
  #pragma HLS interface m_axi port=v3681 offset=slave bundle=gmem7
  #pragma HLS interface m_axi port=v3682 offset=slave bundle=gmem8
  #pragma HLS interface m_axi port=v3683 offset=slave bundle=gmem9
  #pragma HLS interface m_axi port=v3684 offset=slave bundle=gmem10
  #pragma HLS interface m_axi port=v3685 offset=slave bundle=gmem11
  #pragma HLS interface m_axi port=v3686 offset=slave bundle=gmem12
  #pragma HLS interface m_axi port=v3687 offset=slave bundle=gmem13
  #pragma HLS interface m_axi port=v3688 offset=slave bundle=gmem14
  #pragma HLS interface m_axi port=v3689 offset=slave bundle=gmem15
  float buf0[32][48];	//
  l_S_buf0_buf0_l_0: for (int buf0_l_0 = 0; buf0_l_0 < 32; buf0_l_0++) {	//
    l_buf0_l_1: for (int buf0_l_1 = 0; buf0_l_1 < 48; buf0_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v3693 = v3674[((buf0_l_0 * 48) + buf0_l_1)];	//
      buf0[buf0_l_0][buf0_l_1] = v3693;	//
    }
  }
  float buf1[48];	//
  l_S_buf1_buf1_l_0: for (int buf1_l_0 = 0; buf1_l_0 < 48; buf1_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v3696 = v3675[buf1_l_0];	//
    buf1[buf1_l_0] = v3696;	//
  }
  float buf2[48];	//
  l_S_buf2_buf2_l_0: for (int buf2_l_0 = 0; buf2_l_0 < 48; buf2_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v3699 = v3676[buf2_l_0];	//
    buf2[buf2_l_0] = v3699;	//
  }
  // float buf3[48][48];	//
  // l_S_buf3_buf3_l_0: for (int buf3_l_0 = 0; buf3_l_0 < 48; buf3_l_0++) {	//
  //   l_buf3_l_1: for (int buf3_l_1 = 0; buf3_l_1 < 48; buf3_l_1++) {	//
  //   #pragma HLS pipeline II=1 rewind
  //     float v3703 = v3677[((buf3_l_0 * 48) + buf3_l_1)];	//
  //     buf3[buf3_l_0][buf3_l_1] = v3703;	//
  //   }
  // }
  // float buf4[48][48];	//
  // l_S_buf4_buf4_l_0: for (int buf4_l_0 = 0; buf4_l_0 < 48; buf4_l_0++) {	//
  //   l_buf4_l_1: for (int buf4_l_1 = 0; buf4_l_1 < 48; buf4_l_1++) {	//
  //   #pragma HLS pipeline II=1 rewind
  //     float v3707 = v3678[((buf4_l_0 * 48) + buf4_l_1)];	//
  //     buf4[buf4_l_0][buf4_l_1] = v3707;	//
  //   }
  // }
  // float buf5[48][48];	//
  // l_S_buf5_buf5_l_0: for (int buf5_l_0 = 0; buf5_l_0 < 48; buf5_l_0++) {	//
  //   l_buf5_l_1: for (int buf5_l_1 = 0; buf5_l_1 < 48; buf5_l_1++) {	//
  //   #pragma HLS pipeline II=1 rewind
  //     float v3711 = v3679[((buf5_l_0 * 48) + buf5_l_1)];	//
  //     buf5[buf5_l_0][buf5_l_1] = v3711;	//
  //   }
  // }
  // float buf6[48][48];	//
  // l_S_buf6_buf6_l_0: for (int buf6_l_0 = 0; buf6_l_0 < 48; buf6_l_0++) {	//
  //   l_buf6_l_1: for (int buf6_l_1 = 0; buf6_l_1 < 48; buf6_l_1++) {	//
  //   #pragma HLS pipeline II=1 rewind
  //     float v3715 = v3680[((buf6_l_0 * 48) + buf6_l_1)];	//
  //     buf6[buf6_l_0][buf6_l_1] = v3715;	//
  //   }
  // }
  float buf7[48];	//
  l_S_buf7_buf7_l_0: for (int buf7_l_0 = 0; buf7_l_0 < 48; buf7_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v3718 = v3681[buf7_l_0];	//
    buf7[buf7_l_0] = v3718;	//
  }
  float buf8[48];	//
  l_S_buf8_buf8_l_0: for (int buf8_l_0 = 0; buf8_l_0 < 48; buf8_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v3721 = v3682[buf8_l_0];	//
    buf8[buf8_l_0] = v3721;	//
  }
  float buf9[48];	//
  l_S_buf9_buf9_l_0: for (int buf9_l_0 = 0; buf9_l_0 < 48; buf9_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v3724 = v3683[buf9_l_0];	//
    buf9[buf9_l_0] = v3724;	//
  }
  // float buf10[48][192];	//
  // l_S_buf10_buf10_l_0: for (int buf10_l_0 = 0; buf10_l_0 < 48; buf10_l_0++) {	//
  //   l_buf10_l_1: for (int buf10_l_1 = 0; buf10_l_1 < 192; buf10_l_1++) {	//
  //   #pragma HLS pipeline II=1 rewind
  //     float v3728 = v3684[((buf10_l_0 * 192) + buf10_l_1)];	//
  //     buf10[buf10_l_0][buf10_l_1] = v3728;	//
  //   }
  // }
  float buf11[192];	//
  l_S_buf11_buf11_l_0: for (int buf11_l_0 = 0; buf11_l_0 < 192; buf11_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v3731 = v3685[buf11_l_0];	//
    buf11[buf11_l_0] = v3731;	//
  }
  // float buf12[192][48];	//
  // l_S_buf12_buf12_l_0: for (int buf12_l_0 = 0; buf12_l_0 < 192; buf12_l_0++) {	//
  //   l_buf12_l_1: for (int buf12_l_1 = 0; buf12_l_1 < 48; buf12_l_1++) {	//
  //   #pragma HLS pipeline II=1 rewind
  //     float v3735 = v3686[((buf12_l_0 * 48) + buf12_l_1)];	//
  //     buf12[buf12_l_0][buf12_l_1] = v3735;	//
  //   }
  // }
  float buf13[48];	//
  l_S_buf13_buf13_l_0: for (int buf13_l_0 = 0; buf13_l_0 < 48; buf13_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v3738 = v3687[buf13_l_0];	//
    buf13[buf13_l_0] = v3738;	//
  }
  int32_t buf14[2];	//
  l_S_buf14_buf14_l_0: for (int buf14_l_0 = 0; buf14_l_0 < 2; buf14_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    int32_t v3741 = v3688[buf14_l_0];	//
    buf14[buf14_l_0] = v3741;	//
  }
  float v3742[32][48];
  layer_norm(buf0, buf1, buf2, v3742);	// L5037
  float Q[32][48];	// L5040
  for (int v3744 = 0; v3744 < 32; v3744++) {	// L5041
    for (int v3745 = 0; v3745 < 48; v3745++) {	// L5041
      Q[v3744][v3745] = 0.000000;	// L5041
    }
  }
  float K[32][48];	// L5042
  for (int v3747 = 0; v3747 < 32; v3747++) {	// L5043
    for (int v3748 = 0; v3748 < 48; v3748++) {	// L5043
      K[v3747][v3748] = 0.000000;	// L5043
    }
  }
  float V[32][48];	// L5044
  for (int v3750 = 0; v3750 < 32; v3750++) {	// L5045
    for (int v3751 = 0; v3751 < 48; v3751++) {	// L5045
      V[v3750][v3751] = 0.000000;	// L5045
    }
  }
  systolic_Q(v3742, v3677, Q);	// L5046
  systolic_K(v3742, v3678, K);	// L5047
  systolic_V(v3742, v3679, V);	// L5048
  float v3752[32][48];
  masked_casual_sdp(Q, K, V, buf14, v3752);	// L5049
  float O_proj[32][48];	// L5050
  for (int v3754 = 0; v3754 < 32; v3754++) {	// L5051
    for (int v3755 = 0; v3755 < 48; v3755++) {	// L5051
      O_proj[v3754][v3755] = 0.000000;	// L5051
    }
  }
  systolic_P(v3752, v3680, O_proj);	// L5052
  float v3756[32][48];
  bias_add(O_proj, buf7, v3756);	// L5053
  float v3757[32][48];
  residual_add(buf0, v3756, v3757);	// L5054
  float v3758[32][48];
  layer_norm(v3757, buf8, buf9, v3758);	// L5055
  float mlp1[32][192];	// L5056
  for (int v3760 = 0; v3760 < 32; v3760++) {	// L5057
    for (int v3761 = 0; v3761 < 192; v3761++) {	// L5057
      mlp1[v3760][v3761] = 0.000000;	// L5057
    }
  }
  systolic_ffn1(v3758, v3684, mlp1);	// L5058
  float v3762[32][192];
  bias_add_1(mlp1, buf11, v3762);	// L5059
  float v3763[32][192];
  GeLU(v3762, v3763);	// L5060
  float mlp2[32][48];	// L5061
  for (int v3765 = 0; v3765 < 32; v3765++) {	// L5062
    for (int v3766 = 0; v3766 < 48; v3766++) {	// L5062
      mlp2[v3765][v3766] = 0.000000;	// L5062
    }
  }
  systolic_ffn2(v3763, v3686, mlp2);	// L5063
  float v3767[32][48];
  bias_add(mlp2, buf13, v3767);	// L5064
  float v3768[32][48];
  residual_add(v3757, v3767, v3768);	// L5065
  l_S_result15_result15_l_0: for (int result15_l_0 = 0; result15_l_0 < 32; result15_l_0++) {	//
    l_result15_l_1: for (int result15_l_1 = 0; result15_l_1 < 48; result15_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v3771 = v3768[result15_l_0][result15_l_1];	//
      v3689[((result15_l_0 * 48) + result15_l_1)] = v3771;	//
    }
  }
}


} // extern "C"
