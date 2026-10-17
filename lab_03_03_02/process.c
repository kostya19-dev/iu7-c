#include "process.h"

int multiply(int arr[][CAPACITY], int h, int w, int i)
{
    if (i < 0 || i >= h)
    {
        return INTERNAL_LOGIC_ERROR;
    }
    int result = 1;
    for (int j = 0; j < w; ++j)
    {
        result *= arr[i][j];
    }
    return result;
}


int compare(int arr[][CAPACITY], int h, int w, int i, int j)
{
    if (i < 0 || i >= h)
    {
        return INTERNAL_LOGIC_ERROR;
    }
    if (j < 0 || j >= w)
    {
        return INTERNAL_LOGIC_ERROR;
    }
    int a = multiply(arr, h, w, i);
    int b = multiply(arr, h, w, j);
    return a - b;
}


int swap(int arr[][CAPACITY], int h, int w, int i, int j)
{
    if (i < 0 || i >= h)
    {
        return INTERNAL_LOGIC_ERROR;
    }
    int tmp[CAPACITY];
    for (int k = 0; k < w; ++k)
    {
        tmp[k] = arr[i][k];
    }
    for (int k = 0; k < w; ++k)
    {
        arr[i][k] = arr[j][k];
    }
    for (int k = 0; k < w; ++k)
    {
        arr[j][k] = tmp[k];
    }
    return OK;
}


void sort(int arr[][CAPACITY], int h, int w)
{
    for (int i = 0; i < h; ++i)
    {
        for (int j = 1; j < h; ++j)
        {
            if (compare(arr, h, w, j - 1, j) > 0)
            {
                swap(arr, h, w, j - 1, j);
            }
        }
    }
}


int solve(int arr[][CAPACITY], int h, int w)
{
    sort(arr, h, w);
    return OK;
}

