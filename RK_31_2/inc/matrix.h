#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

int load_matrix(const char *filename, int **matrix, size_t *rows, size_t *cols);
void save_matrix(const char *filename, int *matrix, size_t rows, size_t cols);

#endif 
