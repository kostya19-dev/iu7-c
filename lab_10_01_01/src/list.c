#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "errors.h"

// Функция для создания нового узла
node_t *create_node(void *data)
{
    node_t *new_node = (node_t*)malloc(sizeof(node_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(ERROR_MEMORY_ALLOCATE);
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Функция проверки списка на пустоту
bool is_empty(node_t **head)
{
    return (head == NULL || *head == NULL);
}

// Функция для добавления узла в конец списка
int push_back(node_t **head, void *data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node)
    {
        return ERROR_MEMORY_ALLOCATE; 
    }

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node_t *current = *head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    return EXIT_SUCCESS;
}

// Функция pop_front
void *pop_front(node_t **head)
{
    if (is_empty(head)) 
        return NULL;

    node_t *front = *head;
    void *data = front->data;

    *head = front->next;
    free(front);

    return data;
}

// Функция pop_back
void *pop_back(node_t **head)
{
    if (is_empty(head)) 
        return NULL;

    if ((*head)->next == NULL) 
    {
        void *data = (*head)->data;
        free(*head);
        *head = NULL;
        return data;
    }

    node_t *current = *head;
    while (current->next->next != NULL) 
        current = current->next;

    void *data = current->next->data;
    free(current->next);
    current->next = NULL;

    return data;
}

int copy(node_t *head, node_t **new_head)
{
    if (!head || !new_head)
    {
        return ERROR_INVALID_ARGUMENT; 
    }

    *new_head = NULL; 
    node_t *current = head;
    node_t *prev_new_node = NULL; 

    while (current)
    {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        if (!new_node)
        {
            free_list(new_head);
            return ERROR_MEMORY_ALLOCATE; 
        }
        new_node->data = current->data; 
        new_node->next = NULL;

        if (!prev_new_node)
        {
            *new_head = new_node; 
        }
        else
        {
            prev_new_node->next = new_node; 
        }

        prev_new_node = new_node; 
        current = current->next; 
    }

    return EXIT_SUCCESS; 
}


void free_list(node_t **head)
{
    if (!head || !*head) 
    {
        return;
    }

    node_t *current = *head;
    while (current)
    {
        node_t *next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}



// Тип обобщенного компаратора
typedef int(*comparator_t)(const void*, const void*);

// Функция sorted_insert - сохраняет инварианты
void sorted_insert(node_t **head, node_t *element, comparator_t comp)
{
    if (*head == NULL || (comp((*head)->data, element->data) >= 0)) 
    {
        element->next = *head;
        *head = element;
        return;
    }

    node_t *current = *head;
    while (current->next != NULL && (comp(current->next->data, element->data) < 0))
    {
        current = current->next;
    }

    element->next = current->next;
    current->next = element;
}

// Функция sort: сортирует список по возрастанию и возвращает новую голову
node_t *sort(node_t *head, comparator_t comp)
{
    if (head == NULL || head->next == NULL) 
        return head;

    node_t *sorted_list = NULL;
    node_t *current = head;

    while (current != NULL)
    {
        node_t *next = current->next;
        sorted_insert(&sorted_list, current, comp);
        current = next;
    }

    return sorted_list;
}

// Функция для печати списка
typedef void(*printer_t)(const void*, FILE * output);

void print_list(node_t *head, printer_t print_data, FILE *output)
{
    node_t *current = head;
    while (current != NULL)
    {
        print_data(current->data, output);
        fprintf(output, " -> ");
        current = current->next;
    }
    fprintf(output, "NULL\n");
}
