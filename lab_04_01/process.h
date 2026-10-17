#ifndef PROCESS_H
#define PROCESS_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char *my_strpbrk(const char *str1, const char *str2);
size_t my_strspn(const char *str1, const char *str2);
size_t my_strcspn(const char *str1, const char *str2);
char *my_strchr(const char *string, int symbol);
char *my_strrchr(const char *string, int symbol);

#endif // PROCESS_H
