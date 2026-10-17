#ifndef PROCESS
#define PROCESS

#include "errors.h"
#include "const.h"

int are_opposite_signs(int a, int b);
int solve(int arr[][CAPACITY], int h, int w, int result[]);
int do_oscillate(int arr[][CAPACITY], int h, int j);

#endif // #ifndef IO_H__
