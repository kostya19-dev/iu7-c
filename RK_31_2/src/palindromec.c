#include "palindromes.h"
#include <stdlib.h>

int is_palindrome(int number) {

    int reversed = 0, original = number;
    while (number > 0) {
        reversed = reversed * 10 + (number % 10);
        number /= 10;
    }
    return original == reversed;
}

size_t extract_palindromes(int *matrix, size_t rows, size_t cols, int **palindromes) {
    size_t count = 0;
    *palindromes = malloc(rows * cols * sizeof(int));

    if (!*palindromes) return 0;

    for (size_t j = 0; j < cols; j++) {
        for (size_t i = 0; i < rows; i++) {
            int value = matrix[i * cols + j];
            if (is_palindrome(value)) {
                (*palindromes)[count++] = value;
            }
        }
    }

    return count;
}

void sort_array(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int* fill_matrix_with_sorted_palindromes(int *matrix, size_t rows, size_t cols, int *palindromes, size_t pal_count)
{
    int *new_matrix = malloc(rows * cols * sizeof(int));
    if (!new_matrix) return NULL;

    size_t index = 0;

    for (size_t j = 0; j < cols; j++)
    {
        for (size_t i = 0; i < rows; i++)
        {
            int value = matrix[i * cols + j];
            if (is_palindrome(value) && index < pal_count)
            {
                new_matrix[i * cols + j] = palindromes[index++];
            }
            else
            {
                new_matrix[i * cols + j] = value;
            }
        }
    }

    return new_matrix;
}
