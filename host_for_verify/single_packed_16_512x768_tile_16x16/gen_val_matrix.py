import numpy as np

def gen():
    # Matrix dimensions
    MATRIX_M = 512
    MATRIX_K = 768
    MATRIX_N = 3072

    # Generate random matrices
    A = np.random.randint(0, 127, size=(MATRIX_M, MATRIX_K), dtype=np.int8)
    B = np.random.randint(0, 127, size=(MATRIX_K, MATRIX_N), dtype=np.int8)

    # Save matrices to files
    np.savetxt("matrixA.txt", A, fmt='%d')
    np.savetxt("matrixB.txt", B, fmt='%d')


# read
def read_matrix_from_file(filename, rows, cols):
    matrix = np.zeros((rows, cols), dtype=np.int8)
    with open(filename, 'r') as f:
        for i, line in enumerate(f):
            matrix[i, :] = np.array(list(map(int, line.strip().split())))
    return matrix

def read_packed_matrix_from_file(filename, num_elements,np_type):
    packed_data = np.zeros(num_elements, np_type)
    with open(filename, "rb") as f:
        f.readinto(packed_data)
    return packed_data

def unpack_data(packed_data):
    unpacked_data = np.zeros((packed_data.size * 16,), dtype=np.int8)
    for i in range(packed_data.size):
        unpacked_data[i * 16:(i + 1) * 16] = packed_data[i]["data"]
    return unpacked_data

def get_np_struct_type_fake(bit_width):
    if bit_width == 128:
        return np.dtype([("data", np.int8, 16)])
    raise ValueError(f"Unsupported bit width: {bit_width}")

def verify():
    from allo.utils import get_np_struct_type
    L, D = 512, 768
    M = 3072
    np_type = get_np_struct_type(128)
    np_type_fake = get_np_struct_type_fake(128)
    source_in0_packed = read_packed_matrix_from_file("source_in0_packed.txt", 24576, np_type_fake)
    source_in1_packed = read_packed_matrix_from_file("source_in1_packed.txt", 147456, np_type_fake)
    source_in0 = unpack_data(source_in0_packed).reshape(L, D)
    source_in1 = unpack_data(source_in1_packed).reshape(D, M)
    packed2unpacked_result_numpy = np.dot(source_in0, source_in1)
    # read A and B
    A = read_matrix_from_file("matrixA.txt", 512, 768)
    B = read_matrix_from_file("matrixB.txt", 768, 3072)

    # read fpga and cpu result
    result_fpga = read_matrix_from_file("result_fpga.txt", 512, 3072)
    result_fpga_pack = read_packed_matrix_from_file("result_fpga_packed.txt", 32*3072,np_type)
    result_cpu = read_matrix_from_file("result_cpu.txt", 512, 3072)
    # numpy result
    result_numpy = np.dot(A, B)
    packed_numpy = np.ascontiguousarray(
        np.ascontiguousarray(result_numpy.transpose()).view(np_type).transpose()
    )
    breakpoint()
    # compare
    packed2unpacked_match = np.array_equal(packed2unpacked_result_numpy, result_numpy)
    fpga_match = np.array_equal(result_fpga, result_numpy)
    cpu_match = np.array_equal(result_cpu, result_numpy)
    fpga_packed_match = np.array_equal(result_fpga_pack, packed_numpy)
    print("Packed to Unpacked Result Match:", packed2unpacked_match)
    print("FPGA Result Match:", fpga_match)
    print("CPU Result Match:", cpu_match)
    print("FPGA packed Result Match:", fpga_packed_match)
    if fpga_match and cpu_match:
        print("All results match the NumPy result.")
    else:
        print("There is a discrepancy in the results.")

def get_args():
    import argparse
    parser = argparse.ArgumentParser(description='Generate and verify matrices for matrix multiplication.')
    parser.add_argument('mode', choices=['gen', 'verify'], help='Mode to run the script in.')
    return parser.parse_args()


if __name__ == "__main__":
    args = get_args()
    if args.mode == 'gen':
        gen()
    elif args.mode == 'verify':
        verify()
    else:
        print("Invalid mode. Please choose either 'gen' or 'verify'.")
