#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdbool.h>
#include "node.h"
#include "errors.h"

// Функции для работы со списком
node_t *create_node(void *data);
bool is_empty(node_t **head);
int push_back(node_t **head, void *data);
void *pop_front(node_t **head);
void *pop_back(node_t **head);
void free_list(node_t **head);
int copy(node_t *head, node_t **new_head);
node_t *sort(node_t *head, int(*comp)(const void*, const void*));
void print_list(node_t *head, void(*print_data)(const void*, FILE *), FILE *output);

#endif 
