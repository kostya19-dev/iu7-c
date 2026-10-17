import unittest
from gui.lib_wrapper import (
    is_perfect_square,
    cyclic_shift_left,
    estimate_perfect_square_count,
    extract_perfect_squares,
)


class TestMathUtils(unittest.TestCase):

    def test_is_perfect_square(self):
        print("Testing is_perfect_square...")
        self.assertTrue(is_perfect_square(4))
        self.assertTrue(is_perfect_square(9))
        self.assertFalse(is_perfect_square(8))
        self.assertFalse(is_perfect_square(10))

    def test_cyclic_shift_left(self):
        print("Testing cyclic_shift_left...")
        arr = [1, 2, 3, 4, 5]
        shifted = cyclic_shift_left(arr, 2)
        print(f"Original: {arr}, Shifted by 2: {shifted}")
        self.assertEqual(shifted, [3, 4, 5, 1, 2])

        shifted = cyclic_shift_left(arr, 0)
        print(f"Shifted by 0: {shifted}")
        self.assertEqual(shifted, [1, 2, 3, 4, 5])

        shifted = cyclic_shift_left(arr, 5)
        print(f"Shifted by 5 (array length): {shifted}")
        self.assertEqual(shifted, [1, 2, 3, 4, 5])

    def test_estimate_perfect_square_count(self):
        print("Testing estimate_perfect_square_count...")
        arr = [1, 2, 3, 4, 16, 5, 6, 25]
        count = estimate_perfect_square_count(arr)
        print(f"Array: {arr}, Count: {count}")
        self.assertEqual(count, 4)

        arr = [2, 3, 5, 7, 11]
        count = estimate_perfect_square_count(arr)
        print(f"Array: {arr}, Count: {count}")
        self.assertEqual(count, 0)

    def test_extract_perfect_squares(self):
        print("Testing extract_perfect_squares...")
        src = [1, 2, 3, 4, 16, 5, 6, 25]
        dest = extract_perfect_squares(src)
        print(f"Source: {src}, Extracted: {dest}")
        self.assertEqual(dest, [1, 4, 16, 25])

        src = [2, 3, 5, 7, 11]
        dest = extract_perfect_squares(src)
        print(f"Source: {src}, Extracted: {dest}")
        self.assertEqual(dest, [])


if __name__ == "__main__":
    unittest.main()
