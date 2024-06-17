#ifndef KERNEL_H
#define KERNEL_H

extern "C" {
void mask_softmax_per_head(
  float *v0,
  int32_t *v1,
  float *v2
);
} // extern "C"

#endif // KERNEL_H
