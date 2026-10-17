#include "process.h"
#define TRUE 1
#define FALSE 0

int is_prime(int num)
{
    if (num <= 1)
    {
        return FALSE;
    }
    for (int divisor = 2; divisor * divisor <= num; ++divisor)
    {
        if (num % divisor == 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}


void swap(int*a, int*b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int rotate(int line[], int w)
{
    for (int i = 0; i < w / 2; ++i)
    {
        swap(&line[i], &line[w - i - 1]);
    }
    return OK;
}

int solve(int arr[][CAPACITY], int h, int w)
{
    int primes[CAPACITY *CAPACITY], len_primes = 0;
    int locations[CAPACITY *CAPACITY][2];
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (is_prime(arr[i][j]))
            {
                primes[len_primes] = arr[i][j];
                locations[len_primes][0] = i;
                locations[len_primes][1] = j;
                len_primes += 1;
            }
        }
    }
    if (len_primes == 0)
    {
        return INTERNAL_LOGIC_ERROR;
    }
    rotate(primes, len_primes);
    for (int k = 0; k < len_primes; ++k)
    {
        int i = locations[k][0];
        int j = locations[k][1];
        arr[i][j] = primes[k];
    }
    return OK;
}
