#include "main.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int64_t **matrix, int64_t rows, int64_t cols)
{
    int64_t i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%ld ", matrix[i][j]);
        }
        printf("\n");
    }
}

void remove_min_rows(int64_t ***matrix, int64_t *rows, int64_t cols)
{
    int64_t min_value = (*matrix)[0][0];
    int64_t min_row = 0;
    int64_t i, j;

    for (i = 0; i < *rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if ((*matrix)[i][j] < min_value)
            {
                min_value = (*matrix)[i][j];
                min_row = i;
            }
        }
    }

    free((*matrix)[min_row]);
    for (i = min_row; i < *rows - 1; i++)
    {
        (*matrix)[i] = (*matrix)[i + 1];
    }

    (*rows)--;
}

void remove_min_cols(int64_t ***matrix, int64_t rows, int64_t *cols)
{
    int64_t min_value = (*matrix)[0][0];
    int64_t min_col = 0;
    int64_t i, j;

    for (j = 0; j < *cols; j++)
    {
        for (i = 0; i < rows; i++)
        {
            if ((*matrix)[i][j] < min_value)
            {
                min_value = (*matrix)[i][j];
                min_col = j;
            }
        }
    }

    for (j = min_col; j < *cols - 1; j++)
    {
        for (i = 0; i < rows; i++)
        {
            (*matrix)[i][j] = (*matrix)[i][j + 1];
        }
    }

    (*cols)--;
}
