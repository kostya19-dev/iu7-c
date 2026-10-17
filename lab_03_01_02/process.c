#include "process.h"

int are_opposite_signs(int a, int b)
{
    return (a < 0 && b > 0) || (a > 0 && b < 0);
}

int solve(int arr[][CAPACITY], int h, int w, int result[])
{
    for (int j = 0; j < w; ++j)
    {
        if (do_oscillate(arr, h, j))
        {
            result[j] = 1;
        }
        else
        {
            result[j] = 0;
        }
    }
    return OK;
}

int do_oscillate(int arr[][CAPACITY], int h, int j)
{
    if (h == 1)
    {
        return OK;
    }
    
    for (int i = 1; i < h; ++i)
    {
        if (!are_opposite_signs(arr[i - 1][j], arr[i][j]))
        {
            return OK;
        }
    }
    
    return INPUT_ERROR;
}
