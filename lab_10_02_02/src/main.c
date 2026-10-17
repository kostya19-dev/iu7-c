#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/polynomial_operations.h"
#include "../inc/list.h"

int main()
{
    char command[4];
    node_t *polynomial = NULL;

    if (scanf("%3s", command) != 1)
    {
        return EXIT_FAILURE;
    }

    if (strcmp(command, "val") == 0)
    {
        if (read_polynomial(&polynomial) == -1)
        {
            free_list(polynomial);
            return EXIT_FAILURE;
        }
        int a;
        if (scanf("%d", &a) != 1)
        {
            free_list(polynomial);
            return EXIT_FAILURE;
        }
        double result = evaluate_polynomial(polynomial, a);
        printf("%.0f\n", result);
    }
    else if (strcmp(command, "ddx") == 0)
    {
        if (read_polynomial(&polynomial) == -1)
        {
            free_list(polynomial);
            return EXIT_FAILURE;
        }
        node_t *derivative_poly = derivative(polynomial);
        if (derivative_poly == NULL)
        {
            free_list(polynomial);
            return EXIT_FAILURE;
        }
        node_t *current = derivative_poly;
        while (current != NULL)
        {
            printf("%d ", current->coefficient);
            current = current->next;
        }
        printf("L\n");
        free_list(derivative_poly);
    }
    else if (strcmp(command, "sum") == 0)
    {
        node_t *poly1 = NULL;
        node_t *poly2 = NULL;
        if (read_polynomial(&poly1) == -1 || read_polynomial(&poly2) == -1)
        {
            free_list(poly1);
            free_list(poly2);
            return EXIT_FAILURE;
        }
        node_t *sum_poly = add_polynomials(poly1, poly2);
        if (sum_poly == NULL)
        {
            free_list(poly1);
            free_list(poly2);
            return EXIT_FAILURE;
        }
        node_t *current = sum_poly;
        while (current != NULL)
        {
            printf("%d ", current->coefficient);
            current = current->next;
        }
        printf("L\n");
        free_list(poly1);
        free_list(poly2);
        free_list(sum_poly);
    }
    else if (strcmp(command, "dvd") == 0)
    {
        if (read_polynomial(&polynomial) == -1)
        {
            free_list(polynomial);
            return EXIT_FAILURE;
        }
        node_t *even_poly = NULL;
        node_t *odd_poly = NULL;
        if (divide_polynomial(polynomial, &even_poly, &odd_poly) == -1)
        {
            free_list(polynomial);
            return EXIT_FAILURE;
        }
        node_t *current = even_poly;
        while (current != NULL)
        {
            printf("%d ", current->coefficient);
            current = current->next;
        }
        printf("L\n");
        current = odd_poly;
        while (current != NULL)
        {
            printf("%d ", current->coefficient);
            current = current->next;
        }
        printf("L\n");
        free_list(even_poly);
        free_list(odd_poly);
    }
    else
    {
        free_list(polynomial);
        return EXIT_FAILURE;
    }

    free_list(polynomial);
    return EXIT_SUCCESS;
}
