#ifndef PROCESS
#define PROCESS

#include "const.h"
#include "errors.h"
#include <stddef.h>


int solve(int arr[][CAPACITY], int h, int w);
int multiply(int arr[][CAPACITY], int h, int w, int i);
int compare(int arr[][CAPACITY], int h, int w, int i, int j);
int swap(int arr[][CAPACITY], int h, int w, int i, int j);
void sort(int arr[][CAPACITY], int h, int w);

#endif // #ifndef IO_H__
