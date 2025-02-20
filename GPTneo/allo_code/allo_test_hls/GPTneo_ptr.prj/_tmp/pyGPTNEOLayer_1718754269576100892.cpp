// Auto-generated by Allo

#include <iostream>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include "kernel.h"

namespace py = pybind11;

void pyGPTNEOLayer_1718754269576100892(
  py::array_t<float> &arg0,
  py::array_t<float> &arg1,
  py::array_t<float> &arg2,
  py::array_t<float> &arg3,
  py::array_t<float> &arg4,
  py::array_t<float> &arg5,
  py::array_t<float> &arg6,
  py::array_t<float> &arg7,
  py::array_t<float> &arg8,
  py::array_t<float> &arg9,
  py::array_t<float> &arg10,
  py::array_t<float> &arg11,
  py::array_t<float> &arg12,
  py::array_t<float> &arg13,
  py::array_t<int> &arg14) {

  py::buffer_info buf0 = arg0.request();
  py::buffer_info buf1 = arg1.request();
  py::buffer_info buf2 = arg2.request();
  py::buffer_info buf3 = arg3.request();
  py::buffer_info buf4 = arg4.request();
  py::buffer_info buf5 = arg5.request();
  py::buffer_info buf6 = arg6.request();
  py::buffer_info buf7 = arg7.request();
  py::buffer_info buf8 = arg8.request();
  py::buffer_info buf9 = arg9.request();
  py::buffer_info buf10 = arg10.request();
  py::buffer_info buf11 = arg11.request();
  py::buffer_info buf12 = arg12.request();
  py::buffer_info buf13 = arg13.request();
  py::buffer_info buf14 = arg14.request();

  float *p_arg0 = (float *)buf0.ptr;
  float *p_arg1 = (float *)buf1.ptr;
  float *p_arg2 = (float *)buf2.ptr;
  float *p_arg3 = (float *)buf3.ptr;
  float *p_arg4 = (float *)buf4.ptr;
  float *p_arg5 = (float *)buf5.ptr;
  float *p_arg6 = (float *)buf6.ptr;
  float *p_arg7 = (float *)buf7.ptr;
  float *p_arg8 = (float *)buf8.ptr;
  float *p_arg9 = (float *)buf9.ptr;
  float *p_arg10 = (float *)buf10.ptr;
  float *p_arg11 = (float *)buf11.ptr;
  float *p_arg12 = (float *)buf12.ptr;
  float *p_arg13 = (float *)buf13.ptr;
  int *p_arg14 = (int *)buf14.ptr;

  GPTNEOLayer(p_arg0, p_arg1, p_arg2, p_arg3, p_arg4, p_arg5, p_arg6, p_arg7, p_arg8, p_arg9, p_arg10, p_arg11, p_arg12, p_arg13, p_arg14);
}


PYBIND11_MODULE(pyGPTNEOLayer_1718754269576100892, m) {
  m.def("GPTNEOLayer", &pyGPTNEOLayer_1718754269576100892, "GPTNEOLayer wrapper");
}
