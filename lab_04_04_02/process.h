#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#define LEN 256
#define NMAX 16
#define MONTHS 12

size_t split_string(char words[NMAX][NMAX + 1], const char *string, const size_t n);
int check_date(char string[NMAX][NMAX + 1]);

#endif // PROCESS_H
