#include "io.h"

int open_file(const char *file_name, FILE **file)
{
    *file = NULL;
    *file = fopen(file_name, "r");
    if (*file == NULL)
    {
        return FILE_OPEN_ERROR;
    }
    return OK;
}

int open_file_w(const char *file_name, FILE **file)
{
    *file = NULL;
    *file = fopen(file_name, "w");
    if (*file == NULL)
    {
        return FILE_OPEN_ERROR;
    }
    return OK;
}

int count_elements(FILE *file, int *count)
{
    if (file == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    int num;
    *count = 0;
    int result = 0;
    while ((result = fscanf(file, "%d", &num)) == 1)
    {
        (*count)++;
    }
    if (result != EOF)
    {
        return FILE_READ_ERROR;
    }

    if (*count == 0)
    {   
        return EMPTY_ERROR;
    }

    return OK;
}

int check_arguments(int argc, char *argv[], int *is_filter)
{
    if (argc < 3)
    {
        return ARG_ERROR;
    }

    *is_filter = 0;
    if (argc == 4)
    {
        if (strcmp(argv[3], "f") == 0)
        {
            *is_filter = 1;
        }
        else
        {
            return ARG_ERROR;
        }
    }

    return OK;
}

int allocate_memory(int **pb, int **pe, int count_of_numbers)
{
    *pb = NULL;



    *pb = (int*) malloc(count_of_numbers * sizeof(int));
    if (*pb == NULL)
    {
        return ALLOC_ERROR;
    }

    *pe = *pb + count_of_numbers;

    return OK;
}

int read_array(FILE *file, int *pb, int *pe)
{
    if (file == NULL)
    {
        return FILE_READ_ERROR;
    }

    int *p_this = pb;

    while (p_this < pe)
    {
        if (fscanf(file, "%d", p_this) != 1)
        {
            return FILE_READ_ERROR;
        }
        p_this++;
    }

    return OK;
}

int write_array_to_file(FILE *file, int *pb, int *pe)
{
    int *p_this;
    if (file == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    p_this = pb;
    while (p_this < pe)
    {
        if (fprintf(file, "%d ", *p_this) < 0)
        {
            return FILE_WRITE_ERROR;
        }
        p_this++;
    }

    return OK;
}
