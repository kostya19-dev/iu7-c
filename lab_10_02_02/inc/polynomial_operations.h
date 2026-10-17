#ifndef POLYNOMIAL_OPERATIONS_H
#define POLYNOMIAL_OPERATIONS_H
#include "list.h"


void insert_node(node_t **head, int coefficient, int degree);
double evaluate_polynomial(node_t *head, int a);
node_t *derivative(node_t *head);
node_t *add_polynomials(node_t *poly1, node_t *poly2);
int divide_polynomial(node_t *head, node_t **even, node_t **odd);
int read_polynomial(node_t **head);

#endif 
