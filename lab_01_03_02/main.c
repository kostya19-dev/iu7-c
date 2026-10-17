#include <stdio.h>

int main(void)
{
    double r1, r2, r3; // Объявление переменных для хранения значений сопротивлений
    double total_r;
    
    // Вывод приглашения для ввода значений сопротивлений
    printf("Input r_first, r_second and r_third: \n");
    // Считывание значений
    scanf("%lf%lf%lf", &r1, &r2, &r3);

    total_r = 1.0 / (1.0 / r1 + 1.0 / r2 + 1.0 / r3); // Вычисление общего сопротивления
    printf("R is %.6lf", total_r);

    return 0;
}
