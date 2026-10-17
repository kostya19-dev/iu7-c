#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define LEN 256
#define NMAX 16

size_t split_string(char words[NMAX][NMAX + 1], const char *string, const size_t n);
void delete_first_repeats(char *string);
size_t insert_word(char *string, size_t length, const char *word);

#endif // PROCESS_H
