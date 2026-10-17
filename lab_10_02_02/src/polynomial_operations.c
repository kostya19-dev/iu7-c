#include "polynomial_operations.h"
#include <stdio.h>

int read_polynomial(node_t **head)
{
    int degree;
    if (scanf("%d", &degree) != 1 || degree < 0)
    {
        return -1;
    }
    for (int i = degree - 1; i >= 0; i--)
    {
        int coefficient;
        if (scanf("%d", &coefficient) != 1)
        {
            return -1;
        }
        insert_node(head, coefficient, i);
    }
    return 0;
}

double evaluate_polynomial(node_t *head, int a)
{
    double result = 0;
    node_t *current = head;
    while (current != NULL)
    {
        result = result * a + current->coefficient;
        current = current->next;
    }
    return result;
}

node_t *derivative(node_t *head)
{
    node_t *derivative_head = NULL;
    node_t *current = head;

    while (current != NULL)
    {
        if (current->degree > 0)
        {
            int new_coefficient = current->coefficient * current->degree;
            int new_degree = current->degree - 1;

            insert_node(&derivative_head, new_coefficient, new_degree);
        }
        current = current->next;
    }

    return derivative_head;
}

node_t *add_polynomials(node_t *poly1, node_t *poly2)
{
    node_t *result = NULL;
    node_t *p1 = poly1;
    node_t *p2 = poly2;

    while (p1 != NULL || p2 != NULL)
    {
        int degree, coefficient;
        if (p1 != NULL && (p2 == NULL || p1->degree > p2->degree))
        {
            degree = p1->degree;
            coefficient = p1->coefficient;
            p1 = p1->next;
        }
        else if (p2 != NULL && (p1 == NULL || p2->degree > p1->degree))
        {
            degree = p2->degree;
            coefficient = p2->coefficient;
            p2 = p2->next;
        }
        else
        {
            degree = p1->degree;
            coefficient = p1->coefficient + p2->coefficient;
            p1 = p1->next;
            p2 = p2->next;
        }
        insert_node(&result, coefficient, degree);
    }
    return result;
}

int divide_polynomial(node_t *head, node_t **even, node_t **odd)
{
    if (head == NULL)
    {
        return -1;
    }

    node_t *current = head;
    while (current != NULL)
    {
        if (current->degree < 0)
        {
            return -1;
        }
        if (current->degree % 2 == 0)
        {
            insert_node(even, current->coefficient, current->degree);
        }
        else
        {
            insert_node(odd, current->coefficient, current->degree);
        }
        current = current->next;
    }
    return 0;
}
