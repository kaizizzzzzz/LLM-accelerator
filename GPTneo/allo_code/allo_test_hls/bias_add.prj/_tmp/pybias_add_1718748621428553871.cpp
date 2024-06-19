// Auto-generated by Allo

#include <iostream>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include "kernel.h"

namespace py = pybind11;

void pybias_add_1718748621428553871(
  py::array_t<float> &arg0,
  py::array_t<float> &arg1,
  py::array_t<float> &arg2) {

  py::buffer_info buf0 = arg0.request();
  py::buffer_info buf1 = arg1.request();
  py::buffer_info buf2 = arg2.request();

  float *p_arg0 = (float *)buf0.ptr;
  float *p_arg1 = (float *)buf1.ptr;
  float *p_arg2 = (float *)buf2.ptr;

  bias_add(p_arg0, p_arg1, p_arg2);
}


PYBIND11_MODULE(pybias_add_1718748621428553871, m) {
  m.def("bias_add", &pybias_add_1718748621428553871, "bias_add wrapper");
}
