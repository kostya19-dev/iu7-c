#include <stdio.h> // Подключение стандартной библиотеки ввода/вывода
#include <math.h> // Подключение математической библиотеки


#define MAXITER 1000 // максимальное количество итераций в функции

double func(double x, double eps)
{
    double s = x; // Начальное значение s равно x
    double current = x; // Текущее значение равно x
    int i = 2; // Начальное значение счетчика итераций

    while (current >= eps && i < MAXITER)
    {
        i += 2; // Увеличиваем счетчик на 2
        current *= x * x * (i - 3) * (i - 3) / ((i - 2) * (i - 1)); // Вычисление нового текущего значения
        s += current; // Прибавляем текущее значение к общей сумме
    }

    return s; // Возвращаем результат вычислений
}

int main(void)
{
    double x; // Переменная для ввода x
    double eps; // Переменная для ввода точности eps

    printf("Input x: \n");
    if (scanf("%lf", &x) != 1 || fabs(x) > 1)
    {
        printf("Error: Wrong input");
        return 1; // В случае ошибки возвращаем 0 и завершаем программу с ошибкой
    }

    printf("Input eps: \n");
    if (scanf("%lf", &eps) != 1 || eps <= 0 || eps > 1)
    {
        printf("Error: Wrong input");
        return 1; // В случае ошибки возвращаем 0 и завершаем программу с ошибкой
    }

    double f = asin(x); // Вычисление арксинуса встроенной функцией asin для проверки
    double s = func(x, eps); // Вычисление функции через метод, описанный в функции func
    double abs_mistake = fabs(f - s); // Абсолютная ошибка вычислений
    double compare_mistake = abs_mistake / fabs(f); // Относительная ошибка вычислений

    printf("f is %.6lf\n", f); // Вывод значения арксинуса
    printf("s is %.6lf\n", s); // Вывод вычисленного значения с использованием метода
    printf("Absolute mistake is %.6lf\n", abs_mistake); // Вывод абсолютной ошибки
    printf("Comparetive mistake is %.6lf\n", compare_mistake); // Вывод относительной ошибки

    return 0;
}

