#ifndef PROCESS
#define PROCESS

#include "const.h"
#include "errors.h"
#include <stddef.h>


int is_prime(int num);
void swap(int*a, int*b);
int rotate(int line[], int w);
int solve(int arr[][CAPACITY], int h, int w);

#endif // #ifndef IO_H__
