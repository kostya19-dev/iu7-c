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
    
    if (len <= 0 || len > 10)
    {
        return 1;
    }
    
    if (ret != 1)
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

int same_digits(int num)
{
    int last = num % 10;

    int first = last;
    while (num != 0)
    {
        first = num % 10;
        num /= 10;
    }

    return first == last;
}

// copy elements with same first and last digit
int solve(int arr[], int len, int result[], int*p_l_result)
{
    int l_result = 0;
    for (int i = 0; i < len; ++i)
    {
        if (same_digits(arr[i]))
        {
            result[l_result] = arr[i];
            l_result += 1;
        }
    }

    if (l_result == 0)
    {
        return 1;
    }

    if (p_l_result == NULL)
    {
        return 2;
    }

    *p_l_result = l_result;

    return 0;
}

int main(void)
{
    int subject[CAPACITY] = { 0 };
    int length = 0;

    require(input_array(subject, &length));

    int answer[CAPACITY] = { 0 };
    int l_answer = 0;

    require(solve(subject, length, answer, &l_answer));

    require(output_array(answer, l_answer));

    return 0;
}
