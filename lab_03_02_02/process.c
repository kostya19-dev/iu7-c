#include "process.h"

int sum_digits(int num)
{
    if (num < 0)
    {
        num = -num;
    }
    int result = 0;
    while (num != 0)
    {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int count_odd_sum(int arr[][CAPACITY], int i, int w)
{
    int result = 0;
    for (int j = 0; j < w; ++j)
    {
        if (sum_digits(arr[i][j]) % 2 == 1)
        {
            result += 1;
        }
    }
    return result;
}

int move_line_down(int arr[][CAPACITY], int i, int w)
{
    //printf("moveLineDown1");
    for (int j = 0; j < w; ++j)
    {
        arr[i + 1][j] = arr[i][j];
    }
    //printf("moveLineDown2");
    return OK;
}

int insert_neg_ones(int arr[][CAPACITY], int i, int h, int w)
{
    for (int index = h - 1; index >= i; --index)
    {
        move_line_down(arr, index, w);
    }
    for (int j = 0; j < w; ++j)
    {
        arr[i][j] = -1;
    }
    return OK;
}

int solve(int arr[][CAPACITY], int*p_h, int w)
{
    if (p_h == NULL)
    {
        return POINTER_ERROR;
    }
    int h = *p_h;
    if (h == 1 && w == 1)
    {
        return INTERNAL_LOGIC_ERROR;
    }
    for (int i = 0; i < h; ++i)
    {
        if (count_odd_sum(arr, i, w) >= 2)
        {
            insert_neg_ones(arr, i, h, w);
            h += 1;
            i += 1;
        }
    }
    *p_h = h;
    return OK;
}
