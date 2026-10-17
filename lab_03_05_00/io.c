#include "io.h"

int is_correct_dim(int len)
{
    return len >= 0 && len < CAPACITY;
}

void print_error_message(int code)
{
    if (code <= 0)
    {
        return;
    }

    char const*messages[] = {
        "placeholder for no error",
        "user input error",
        "pointer error",
        "internal logic error",
        "capacity error"
    };

    if (code >= (int)ARR_LEN(messages))
    {
        return;
    }

    fprintf(stderr, "%s\n", messages[code]);
}

int output_matrix(int arr[][CAPACITY], int h, int w)
{
    printf("Вывод измененной матрицы:\n");

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            printf("%s%d", (j == 0 ? "" : " "), arr[i][j]);
        }
        printf("\n");
    }
    return OK;
}

int input_matrix(int arr[][CAPACITY], int*p_h, int*p_w)
{
    int ret = 0;

    int h = 0, w = 0;
    ret = scanf("%d%d", &h, &w);
    if (ret != 2 || !is_correct_dim(h) || !is_correct_dim(w))
    {
        return INPUT_ERROR;
    }

    if (p_h == NULL || p_w == NULL)
    {
        return POINTER_ERROR;
    }
    *p_h = h;
    *p_w = w;

    printf("Введите числа исходной матрицы:\n");

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            ret = scanf("%d", &arr[i][j]);
            if (ret != 1)
            {
                return INPUT_ERROR;
            }
        }
    }

    return OK;
}

void require(int code)
{
    if (code == 0)
    {
        return;
    }

    print_error_message(code);
    exit(code);
}
