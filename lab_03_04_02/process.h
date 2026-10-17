#ifndef PROCESS
#define PROCESS

#include "const.h"
#include "errors.h"
#include <stddef.h>

#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int does_end5(int num);
int solve(int arr[][CAPACITY], int h, int w, int*p_result);

#endif // #ifndef IO_H__
