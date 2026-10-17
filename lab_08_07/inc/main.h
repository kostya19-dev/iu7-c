#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

int read_matrix(int64_t ***matrix, int64_t *rows, int64_t *cols);
void print_matrix(int64_t **matrix, int64_t rows, int64_t cols);
void free_matrix(int64_t **matrix, int64_t rows);

#endif
