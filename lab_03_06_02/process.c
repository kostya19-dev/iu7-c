#include "process.h"

int next_position(int h, int w, int*p_i, int*p_j)
{
    int i = *p_i, j = *p_j;
    if ((w - j) % 2 == 1)
    {
        if (i == 0)
        {
            j -= 1;
        }
        else
        {
            i -= 1;
        }
    }
    else
    {
        if (i == h - 1)
        {
            j -= 1;
        }
        else
        {
            i += 1;
        }
    }
    if (i < 0 || i >= h || j < 0 || j >= w)
    {
        return OK;
    }
    *p_i = i;
    *p_j = j;
    return INPUT_ERROR;
}

int solve(int arr[][CAPACITY], int h, int w)
{
    int current = 1;
    int i = h - 1, j = w - 1; 
    do
    {
        arr[i][j] = current;
        current += 1;
    } while (next_position(h, w, &i, &j));
    return OK;
}
