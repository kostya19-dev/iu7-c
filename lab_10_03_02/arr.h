#ifndef ARR_H
#define ARR_H

#include <stdlib.h>
#include <string.h>

struct entry
{
    char *key;
    int value;
};

struct assoc_array_type
{
    struct entry *entries;
    size_t size;
    size_t capacity;
};

#endif // ARR_H