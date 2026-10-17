#ifndef MATRIX_ALLOC_H
#define MATRIX_ALLOC_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t **allocate_matrix(int64_t n, int64_t m);
void free_matrix(int64_t **matrix, int64_t rows);
int read_matrix(int64_t ***matrix, int64_t *rows, int64_t *cols);

#endif
