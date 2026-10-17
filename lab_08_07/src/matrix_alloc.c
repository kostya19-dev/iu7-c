#include "matrix_alloc.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

int64_t **allocate_matrix(int64_t n, int64_t m)
{
    int64_t **data = (int64_t **)malloc(n * sizeof(int64_t *));

    if (!data)
    {
        return NULL;
    }
    for (int64_t i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(int64_t));
    }

    return data;
}

void free_matrix(int64_t **matrix, int64_t rows)
{
    for (int64_t i = 0; i < rows; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int read_matrix(int64_t ***matrix, int64_t *rows, int64_t *cols)
{
    int64_t i, j;

    if (scanf("%ld%ld", rows, cols) != 2 || *rows <= 0 || *cols <= 0)
    {
        return ARG_ERROR;
    }

    *matrix = allocate_matrix(*rows, *cols);
    if (*matrix == NULL)
    {
        return ALLOC_ERROR;
    }

    for (i = 0; i < *rows; i++)
    {
        for (j = 0; j < *cols; j++)
        {
            if (scanf("%ld", &((*matrix)[i][j])) != 1)
            {
                free_matrix(*matrix, *rows);
                return ARG_ERROR;
            }
        }
    }

    return OK;
}
