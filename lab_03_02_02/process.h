#ifndef PROCESS
#define PROCESS

#include "const.h"
#include "errors.h"
#include <stddef.h>

int sum_digits(int num);
int count_odd_sum(int arr[][CAPACITY], int i, int w);
int move_line_down(int arr[][CAPACITY], int i, int w);
int insert_neg_ones(int arr[][CAPACITY], int i, int h, int w);
int solve(int arr[][CAPACITY], int*p_h, int w);

#endif // #ifndef IO_H__
