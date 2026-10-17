#include <stdio.h>
#include <math.h>


// Функция проверяет является ли сумма цифр числа нечетной
int is_digits_sum_odd(int num)
{
    int s = 0;
    for (; num != 0; num /= 10)
    {
        s += num % 10;
    }

    return s % 2;
}

//Функция находит максимальную цифру в числе
int find_max_digit(int num)
{
    int max = num % 10;
    int tmp;
    for (; num != 0; num /= 10)
    {
        tmp = num % 10;
        if (tmp > max)
        {
            max = tmp;
        }
    }
    return max;
}

// Функция находит минимальную цифру в числе
int find_min_digit(int num)
{
    int min = num % 10;
    int tmp;
    for (; num != 0; num /= 10)
    {
        tmp = num % 10;

        if (tmp < min)
        {
            min = tmp;
        }
    }
    return min;
}

int main()
{
    int number;
    if (scanf("%d", &number) != 1 || number <= 0)
    {
        printf("Введено некорректное число!\n");
        return 1;
    }

    int min = find_min_digit(number);
    int max = find_max_digit(number);
    printf("min = %d, max = %d\n", min, max);

    if (is_digits_sum_odd(number))
    {
        printf("Среднее геометрическое минимальной (%d) и максимальной (%d) цифры: %lf\n", min, max, sqrt(min * max));
    }
    else
    {
        printf("Среднее арифметическое минимальной (%d) и максимальной (%d) цифры: %lf\n", min, max, (double)(min + max) / 2);
    }

    return 0;
}
