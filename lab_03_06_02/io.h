#ifndef IO_H__
#define IO_H__

#include <stdlib.h>
#include <stdio.h>
#include "const.h"
#include "errors.h"

#define ARR_LEN(a) (sizeof(a) / sizeof(*a))

int is_correct_dim(int len);
void print_error_message(int code);
int output_matrix(int arr[][CAPACITY], int h, int w);
int input_dimensions(int*p_h, int*p_w);
void require(int code);

#endif // #ifndef IO_H__
