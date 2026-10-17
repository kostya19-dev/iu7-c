#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

#define ARR_LEN(a) (sizeof(a) / sizeof(*a))

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
        "internal logic error"
    };

    if (code >= (int)ARR_LEN(messages))
    {
        return;
    }

    fprintf(stderr, "%s\n", messages[code]);
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

int input_array(int*arr, int*p_len)
{
    int ret = 0;

    int len = 0;
    ret = scanf("%d", &len);
    if (ret != 1)
    {
        return 1;
    }

    if (len <= 0 || len > 10)
    {
        return 1;
    }
    
    if (p_len == NULL)
    {
        return 2;
    }
    *p_len = len;

    int*end = arr + len;

    for (int*pa = arr; pa < end; ++pa)
    {
        ret = scanf("%d", pa);
        if (ret != 1)
        {
            return 1;
        }
    }

    return 0;
}

int output_array(int*arr, int*end)
{
    for (int*pa = arr; pa < end; ++pa)
    {
        printf("%s%d", (pa == arr ? "" : " "), *pa);
    }
    printf("\n");
    return 0;
}

int*find_negative(int*arr, int*end)
{
    for (int*pa = arr; pa < end; ++pa)
    {
        if (*pa < 0)
        {
            return pa;
        }
    }
    return end - 1;
}

// calculate sum[i]_0^m(prod[j]_0^i(arr[j]))
int solve(int*arr, int*end, int*p_result)
{
    int result = 0;
    int*pa_m = find_negative(arr, end);
    for (int*p_i = arr; p_i <= pa_m; ++p_i)
    {
        int term = 1;
        for (int*p_j = arr; p_j <= p_i; ++p_j)
        {
            term *= *p_j;
        }
        result += term;
    }
    *p_result = result;
    return 0;
}

int main(void)
{
    int subject[CAPACITY] = { 0 };
    int length = 0;

    require(input_array(subject, &length));
    int*end = subject + length;

    int result = 0;
    require(solve(subject, end, &result));

    printf("%d\n", result);

    return 0;
}
