import numpy as np
import ctypes

# load the shared library
lib = ctypes.CDLL('./libmatrix_mult.so')

# define the function's parameters and return type
lib.matrix_multiply.argtypes = [
    np.ctypeslib.ndpointer(dtype=np.float32, ndim=1, flags='C_CONTIGUOUS'),  # A
    np.ctypeslib.ndpointer(dtype=np.float32, ndim=1, flags='C_CONTIGUOUS'),  # B
    np.ctypeslib.ndpointer(dtype=np.float32, ndim=1, flags='C_CONTIGUOUS'),  # C
    ctypes.c_int  # N
]
lib.matrix_multiply.restype = None

# define the matrix size
N = 3

# define the input matrices
A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]], dtype=np.float32).flatten()
B = np.array([[9, 8, 7], [6, 5, 4], [3, 2, 1]], dtype=np.float32).flatten()
C = np.zeros((N, N), dtype=np.float32).flatten()

# call the function
lib.matrix_multiply(A, B, C, N)

# reshape the output matrix
C = C.reshape((N, N))
print("Matrix A:")
print(A.reshape((N, N)))
print("Matrix B:")
print(B.reshape((N, N)))
print("Matrix C (Result):")
print(C)
breakpoint()
