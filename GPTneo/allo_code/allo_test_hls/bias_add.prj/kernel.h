#ifndef KERNEL_H
#define KERNEL_H

extern "C" {
void bias_add(
  float *v0,
  float *v1,
  float *v2
);
} // extern "C"

#endif // KERNEL_H
