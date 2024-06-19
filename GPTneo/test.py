import allo
import numpy as np
def test_pybind11():
    mod = allo.IPModule(
        top="bias_add",
        headers=["kernel.h"],
        impls=["kernel.cpp"],
        signature=["float32[64, 768]", "float32[768]", "float32[64, 768]"],
        link_hls="/work/zhang-capra/users/ky427/allo/GPTneo/allo_code/allo_test_hls/bias_add.prj",
    )
    a = np.random.random((64, 768)).astype(np.float32)
    b = np.random.random((768)).astype(np.float32)
    c = np.zeros((64, 768)).astype(np.float32)
    breakpoint()
    mod(a, b, c)
    np.testing.assert_allclose(np.matmul(a, b), c, atol=1e-6)
    print("Passed!")


test_pybind11()