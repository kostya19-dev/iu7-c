#include "process.h"

int does_end5(int num)
{
    if (num < 0)
    {
        num = -num;
    }
    return num % 10 == 5;
}

int solve(int arr[][CAPACITY], int h, int w, int*p_result)
{
    if (h != w)
    {
        return INPUT_ERROR;
    }
    int result, found_result = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = MAX(0, w - i); j < w; ++j)
        {
            if (does_end5(arr[i][j]))
            {
                if (!found_result)
                {
                    result = arr[i][j];
                    found_result = 1;
                }
                result = MAX(result, arr[i][j]);
            }
        }
    }
    if (!found_result)
    {
        return INTERNAL_LOGIC_ERROR;
    }
    *p_result = result;
    return OK;
}


