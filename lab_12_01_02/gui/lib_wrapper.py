import ctypes
from ctypes import POINTER, c_int, c_bool

lib = ctypes.CDLL(
    "./out/libarray.so"
) 

lib.isPerfectSquare.argtypes = [c_int]
lib.isPerfectSquare.restype = c_bool

lib.cyclicShiftLeft.argtypes = [POINTER(c_int), c_int, c_int]
lib.cyclicShiftLeft.restype = None

lib.estimatePerfectSquareCount.argtypes = [POINTER(c_int), c_int]
lib.estimatePerfectSquareCount.restype = c_int

lib.extractPerfectSquares.argtypes = [POINTER(c_int), POINTER(c_int), c_int]
lib.extractPerfectSquares.restype = c_int


def is_perfect_square(num):
    return lib.isPerfectSquare(num)


def cyclic_shift_left(arr, k):

    n = len(arr)
    array_type = ctypes.c_int * n
    c_arr = array_type(*arr)

    lib.cyclicShiftLeft(c_arr, n, k)
    return list(c_arr)


def estimate_perfect_square_count(arr):
    n = len(arr)
    array_type = c_int * n
    c_arr = array_type(*arr)
    return lib.estimatePerfectSquareCount(c_arr, n)


def extract_perfect_squares(src):
    n = len(src)
    src_type = c_int * n
    dest_type = c_int * n
    c_src = src_type(*src)
    c_dest = dest_type()
    count = lib.extractPerfectSquares(c_src, c_dest, n)
    return list(c_dest[:count])
