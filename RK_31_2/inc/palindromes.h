#ifndef PALINDROMES_H
#define PALINDROMES_H

#include <stddef.h>

size_t extract_palindromes(int *matrix, size_t rows, size_t cols, int **palindromes);
void sort_array(int *array, size_t size);
int* fill_matrix_with_sorted_palindromes(int *matrix, size_t rows, size_t cols, int *palindromes, size_t pal_count);


#endif 
