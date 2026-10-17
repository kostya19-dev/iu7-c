#include "matrix.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

int load_matrix(const char *filename, int **matrix, size_t *rows, size_t *cols)
{
    FILE *file = fopen(filename, "r");
    if (!file) return FILE_READ_ERROR;

    if (fscanf(file, "%zu %zu", rows, cols) != 2)
    {
        fclose(file);
        return PARSE_ERROR;
    }

    size_t size = (*rows) * (*cols);
    *matrix = malloc(size * sizeof(int));
    if (!*matrix)
    {
        fclose(file);
        return MEMORY_ALLOCATION_ERROR;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (fscanf(file, "%d", &(*matrix)[i]) != 1)
        {
            free(*matrix);
            fclose(file);
            return PARSE_ERROR;
        }
    }

    fclose(file);
    return SUCCESS;
}

void save_matrix(const char *filename, int *matrix, size_t rows, size_t cols)
{
    FILE *file = fopen(filename, "w");
    if (!file) return;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            fprintf(file, "%d ", matrix[i * cols + j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}