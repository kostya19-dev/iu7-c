#ifndef NODE_H
#define NODE_H

typedef struct node node_t;
struct node
{
    void *data;
    node_t *next;
};

#endif 
