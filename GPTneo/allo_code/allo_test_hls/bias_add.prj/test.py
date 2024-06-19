import allo
import numpy as np
def test_pybind11():
    mod = allo.IPModule(
        top="bias_add",
        headers=["kernel.h"],
        impls=["kernel.cpp"],
        signature=["float32[49152]", "float32[768]", "float32[49152]"],
        link_hls="/work/zhang-capra/users/ky427/allo/GPTneo/allo_code/allo_test_hls/bias_add.prj",
    )
    a = np.random.random(49152).astype(np.float32)
    b = np.random.random(768).astype(np.float32)
    c = np.zeros(49152).astype(np.float32)
    breakpoint()
    mod(a, b, c)
    breakpoint()
    a=a.view('float32').reshape(64, 768)
    c=c.view('float32').reshape(64, 768)
    breakpoint()
    np.testing.assert_allclose(a+b, c, atol=1e-6)
    print("Passed!")


test_pybind11()