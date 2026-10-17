#include "../inc/list.h"
#include <stdio.h>
#include <stdlib.h>

node_t *create_node(int coefficient, int degree)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->coefficient = coefficient;
    new_node->degree = degree;
    new_node->next = NULL;
    return new_node;
}

void free_list(node_t *head)
{
    node_t *current = head;
    node_t *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

void insert_node(node_t **head, int coefficient, int degree)
{
    node_t *new_node = create_node(coefficient, degree);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node_t *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
