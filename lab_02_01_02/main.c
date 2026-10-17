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
        "pointer error"
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

// find average of negative elements
int solve(int const arr[], int len, double*p_result)
{
    int sum = 0, count = 0;
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] < 0)
        {
            sum += arr[i];
            count += 1;
        }
    }

    if (count == 0)
    {
        return 1;
    }

    if (p_result == NULL)
    {
        return 2;
    }

    *p_result = (double)sum / count;

    return 0;
}

int main(void)
{
    int subject[CAPACITY] = { 0 };
    int length = 0;

    require(input_array(subject, &length));

    double answer = 0;

    require(solve(subject, length, &answer));

    printf("%f\n", answer);

    return 0;
}
