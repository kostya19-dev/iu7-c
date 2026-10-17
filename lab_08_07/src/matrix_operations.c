#include "matrix.h"
#include "matrix_alloc.h"
#include <stdlib.h>
#include <math.h>
#include "errors.h"

int64_t geometric_mean(int64_t **matrix, int64_t rows, int64_t j)
{
    double product = 1.0;
    for (int64_t i = 0; i < rows; i++)
    {
        product *= matrix[i][j];
    }
    if (product < 0)
    {
        return -1;  // Ошибка, если произведение отрицательное
    }
    double mean = pow(product, 1.0 / rows);
    return (int64_t)mean;
}

int64_t max_in_row(int64_t *row, int64_t cols)
{
    int64_t max_value = row[0];
    for (int64_t i = 1; i < cols; i++)
    {
        if (row[i] > max_value)
        {
            max_value = row[i];
        }
    }
    return max_value;
}

int expand_matrix(int64_t ***matrix, int64_t *rows, int64_t *cols, int64_t new_size)
{
    int64_t i, j;

    int64_t **new_matrix = allocate_matrix(new_size, new_size);
    if (new_matrix == NULL)
    {
        return ARG_ERROR;
    }

    for (i = 0; i < *rows; i++)
    {
        for (j = 0; j < *cols; j++)
        {
            new_matrix[i][j] = (*matrix)[i][j];
        }
    }

    for (i = *rows; i < new_size; i++)
    {
        for (j = 0; j < *cols; j++)
        {
            int64_t gm = geometric_mean(new_matrix, *rows, j);
            if (gm == -1)
            {
                free_matrix(new_matrix, new_size);
                return ARG_ERROR;
            }
            new_matrix[i][j] = gm;
        }
    }

    for (i = 0; i < new_size; i++)
    {
        for (j = *cols; j < new_size; j++)
        {
            int64_t max_value = max_in_row(new_matrix[i], *cols);
            new_matrix[i][j] = max_value;
        }
    }

    free_matrix(*matrix, *rows);
    *matrix = new_matrix;
    *rows = *cols = new_size;

    return OK;
}


int64_t **matrix_power(int64_t **matrix, int64_t size, int64_t exp)
{
    int64_t i, j, k, p;
    int64_t **result = allocate_matrix(size, size);
    if (result == NULL)
    {
        return NULL;
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            result[i][j] = ((i == j) ? 1 : 0);  // Инициализируем результат как единичную матрицу
        }
    }

    for (p = 0; p < exp; p++)
    {
        int64_t **temp = allocate_matrix(size, size);
        if (temp == NULL)
        {
            free_matrix(result, size);
            return NULL;
        }

        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                temp[i][j] = 0;
                for (k = 0; k < size; k++)
                {
                    temp[i][j] += matrix[i][k] * result[k][j];
                }
            }
        }

        free_matrix(result, size);
        result = temp;
    }

    return result;
}
