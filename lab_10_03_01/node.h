#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node
{
    char *key;
    int value;
    struct node *next;
};

struct assoc_array_type
{
    struct node *head;
};

#endif // NODE_H