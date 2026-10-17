#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "process.h"


int open_file(const char *file_name, FILE **file);
int open_file_w(const char *file_name, FILE **file);
int count_elements(FILE *file, int *count);
int check_arguments(int argc, char *argv[], int *filter);
int allocate_memory(int **pb, int **pe, int count_of_numbers);
int read_array(FILE *file, int *pb, int *pe);
int filter_element(const int *pb, const int *pe);
int key(const int *start_ptr, const int *end_ptr, int **pb_dst, int **pe_dst);
int compare_numbers(const void *a, const void *b);
int write_array_to_file(FILE *file, int *pb, int *pe);
void handle_error(int error_code, FILE *file);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif // IO_H
