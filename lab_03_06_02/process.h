#ifndef PROCESS
#define PROCESS

#include "const.h"
#include "errors.h"
#include <stddef.h>


int next_position(int h, int w, int*p_i, int*p_j);
int solve(int arr[][CAPACITY], int h, int w);


#endif // #ifndef IO_H__
