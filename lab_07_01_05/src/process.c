#include "io.h"

int filter_element(const int *pb, const int *pe)
{
    long long int sum = 0;
    const int *p_this;

    p_this = pb + 1;
    while (p_this < pe)
    {
        sum += *p_this;
        p_this++;
    }

    return (*pb > sum);
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    const int *p_this;
    int count = 0;

    p_this = pb_src;
    while (p_this + 1 < pe_src)
    {
        if (filter_element(p_this, pe_src))
        {
            count++;
        }
        p_this++;
    }

    if (count == 0)
    {
        return EMPTY_ERROR;
    }

    *pb_dst = (int*)malloc(count * sizeof(int));
    if (*pb_dst == NULL)
    {
        return ALLOC_ERROR;
    }

    *pe_dst = *pb_dst + count;
    int *filtered_ptr = *pb_dst;

    p_this = pb_src;
    while (p_this + 1 < pe_src)
    {
        if (filter_element(p_this, pe_src))
        {
            *filtered_ptr = *p_this;
            filtered_ptr++;
        }
        p_this++;
    }

    return OK;
}

int compare_numbers(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    char *swap_elem = (char *)malloc(size),
    *elem,
    *next_elem;

    for (size_t i = 0; i + 1 < num; i++)
    {
        elem = (char *)base;
        next_elem = (char *)base + size;

        for (size_t j = 0; j + i + 1 < num; j++)
        {
            if (compare(elem, next_elem) > 0)
            {
                memcpy(swap_elem, elem, size);
                memcpy(elem, next_elem, size);
                memcpy(next_elem, swap_elem, size);
            }
            elem += size;
            next_elem += size;
        }
    }

    free(swap_elem);
}

const char *const error_messages[7] =
{
    "Успешное завершение",
    "Ошибка открытия файла",
    "Ошибка записи в файл",
    "Ошибка выделения памяти",
    "Ошибка чтения файла",
    "Ошибка чтения аргументов из коммандной строки",
    "Ошибка Файл пуст"
};

void handle_error(int error_code, FILE *file)
{
    if (error_code != 0)
    {
        if (file != NULL)
        {
            fclose(file);
        }
        printf("%s\n", error_messages[error_code]);
        exit(error_code);
    }
}
