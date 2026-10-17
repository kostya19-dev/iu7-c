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

int input_array(int arr[], int*p_len)
{
    int ret = 0;

    int len = 0;
    ret = scanf("%d", &len);
    if (ret != 1 || len > 10)
    {
        return 1;
    }

    if (len < 0)
    {
        return 1;
    }
    
    if (p_len == NULL)
    {
        return 2;
    }
    *p_len = len;

    for (int i = 0; i < len; ++i)
    {
        ret = scanf("%d", &arr[i]);
        if (ret != 1)
        {
            return 1;
        }
    }

    return 0;
}

int output_array(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%s%d", (i == 0 ? "" : " "), arr[i]);
    }
    printf("\n");
    return 0;
}

#include <math.h>

int is_perfect_square(int num)
{
    if (num < 0)
    {
        return 0;
    }

    double root = sqrt(num);
    int i_root = (int)root;

    return i_root * i_root == num;
}

int remove_element(int arr[], int*p_len, int index)
{
    int len = *p_len;
    if (index >= len)
    {
        return 3;
    }

    for (int i = index + 1; i < len; ++i)
    {
        arr[i - 1] = arr[i];
    }

    *p_len = len - 1;
    return 0;
}

// remove elements that are perfect squares
int solve(int arr[], int*p_len)
{
    if (p_len == NULL)
    {
        return 2;
    }

    int len = *p_len;
    for (int i = 0; i < len; ++i)
    {
        if (is_perfect_square(arr[i]))
        {
            require(remove_element(arr, &len, i));
            i -= 1; // counteracting following `++i`
        }
    }

    if (len == 0)
    {
        return 1;
    }

    *p_len = len;

    return 0;
}

int main(void)
{
    int subject[CAPACITY] = { 0 };
    int length = 0;

    require(input_array(subject, &length));

    require(solve(subject, &length));

    require(output_array(subject, length));

    return 0;
}
