#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

void remove_min_rows(int64_t ***matrix, int64_t *rows, int64_t cols);
void remove_min_cols(int64_t ***matrix, int64_t rows, int64_t *cols);
int expand_matrix(int64_t ***matrix, int64_t *rows, int64_t *cols, int64_t new_size);
int64_t **matrix_power(int64_t **matrix, int64_t size, int64_t exp);
void free_matrix(int64_t **matrix, int64_t rows);
int64_t **allocate_matrix(int64_t n, int64_t m);

#endif
