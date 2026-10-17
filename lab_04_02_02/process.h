#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define LEN 256
#define NMAX 16

char *my_strchr(const char *string, int symbol);
size_t split_string(char words[NMAX][NMAX + 1], const char *string, const size_t n);
int repeat(char string[][NMAX + 1], const size_t index);
int in_string(const char *word, char string_words[][NMAX + 1], const size_t n);

#endif // PROCESS_H
