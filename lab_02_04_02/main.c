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
        "internal logic error",
        "capacity error"
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

    if (p_len == NULL)
    {
        return 2;
    }
    *p_len = 0;

    for (int i = 0; i < CAPACITY; ++i)
    {
        ret = scanf("%d", &arr[i]);
        if (ret != 1)
        {
            return 1;
        }
        *p_len += 1;
    }
    if (*p_len == 10)
    {
        int trash;
        if (scanf("%d", &trash) != 1)
        {
            return 1;
        }
    }

    return 4;
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

void swap(int*p_a, int*p_b)
{
    int tmp = *p_a;
    *p_a = *p_b;
    *p_b = tmp;
}

void selection_sort(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        int j_min = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[j] < arr[j_min])
            {
                j_min = j;
            }
        }
        swap(&arr[i], &arr[j_min]);
    }
}

// sort using selection sort
int solve(int arr[], int len)
{
    selection_sort(arr, len);
    return 0;
}

int main(void)
{
    int ret = 0;

    int subject[CAPACITY] = { 0 };
    int length = 0;

    ret = input_array(subject, &length);
    if (length == 0)
    {
        require(1);
    }

    require(solve(subject, length));

    require(output_array(subject, length));

    if (ret == 4)
    {
        return 100;
    }
    return 0;
}
