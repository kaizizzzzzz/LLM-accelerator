1. <host_gemm_512_768_m8.cpp> and <host_single_packed_8_512x768_tile_8x8.cpp> passed
2. The script in <single_packed_16_512x768_tile_16x16> seems still has some bugs!
3. Not sure why pack 16 seems can't pass even using the host.cpp in pack8. Code bug or wrong 16 pack?