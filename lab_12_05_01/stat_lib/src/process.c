#include "io.h"

// Функция для проверки, является ли первый элемент массива больше суммы всех остальных элементов
int filter_element(const int *pb, const int *pe)
{
    long long int sum = 0;
    const int *p_this;

    // Начинаем с элемента, следующего за первым
    p_this = pb + 1;
    while (p_this < pe)
    {
        sum += *p_this;
        p_this++;
    }

    // Возвращаем 1, если первый элемент больше суммы остальных, иначе 0
    return (*pb > sum);
}

// Функция для фильтрации элементов массива и копирования отфильтрованных элементов в новый массив
int key(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst)
{
    const int *p_this;
    int count = 0;

    // Подсчитываем количество элементов, удовлетворяющих условию фильтрации
    p_this = pb_src;
    while (p_this + 1 < pe_src)
    {
        if (filter_element(p_this, pe_src))
        {
            count++;
        }
        p_this++;
    }

    // Если нет элементов, удовлетворяющих условию фильтрации, возвращаем ошибку
    if (count == 0)
    {
        return EMPTY_ERROR;
    }

    // Устанавливаем конец нового массива
    *pe_dst = pb_dst + count;
    int *filtered_ptr = pb_dst;

    // Копируем отфильтрованные элементы в новый массив
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

// Функция для сравнения двух чисел
int compare_numbers(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

// Функция для сортировки массива с использованием алгоритма сортировки пузырьком
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

// Массив строк, содержащий сообщения об ошибках
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

// Функция для обработки ошибок
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
