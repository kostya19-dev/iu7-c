#ifndef LIST_H
#define LIST_H

typedef struct node_t
{
    int coefficient;     
    int degree;          
    struct node_t *next;  
} node_t;

node_t *create_node(int coefficient, int degree);
void insert_node(node_t **head, int coefficient, int degree);
void free_list(node_t *head); 

#endif 