#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "process.h"

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
int filter_element(const int *pb, const int *pe);
int key(const int *start_ptr, const int *end_ptr, int **pb_dst, int **pe_dst);
int compare_numbers(const void *a, const void *b);


#endif // PROCESS_H
