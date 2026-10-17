#include <stdio.h> // Подключение стандартной библиотеки ввода/вывода
#include <math.h> // Подключение математической библиотеки для использования функций sqrt


const double eps = 1e-8; // Определение константы eps

// Функция для вычисления площади треугольника по формуле Герона
double square(double a, double b, double c)
{
    double p = (a + b + c) / 2; // Вычисление полупериметра треугольника
    return sqrt(p * (p - a) * (p - b) * (p - c)); // Возвращение значения площади треугольника
}

int main(void)
{
    double ax, ay; // Координаты точки A
    double bx, by; // Координаты точки B
    double cx, cy; // Координаты точки C
    double a, b, c; // Длины сторон треугольника
    double mx, my; //координаты точки M

    printf("Input ax and ay: \n"); // Запрос ввода координат точки A
    if (scanf("%lf%lf", &ax, &ay) != 2)
    {
        printf("Error: Wrong input");
        return 1;
    }

    printf("Input bx and by: \n"); // Запрос ввода координат точки B
    if (scanf("%lf%lf", &bx, &by) != 2 || ((fabs(ax - bx) < eps) && // Проверка успешного ввода и считывание значений, а также проверка совпадения с точкой A
        (fabs(ay - by) < eps)))
    {
        printf("Error: Wrong input");
        return 1;
    }

    printf("Input cx and cy: \n"); // Запрос ввода координат точки С
    if (scanf("%lf%lf", &cx, &cy) != 2 || ((fabs(ax - cx) < eps) && // Проверка успешного ввода и считывание значений, а также проверка совпадения с точками A и B  
        (fabs(ay - cy) < eps)) || ((fabs(bx - cx) < eps) &&
        (fabs(by - cy) < eps)))
    {
        printf("Error: Wrong input");
        return 1;
    }
    
    // Вычисление длин сторон треугольника
    a = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
    b = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
    c = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
    
    // Проверка существования треугольника
    if (fabs(a + b - c) <= eps || fabs(a + c - b) <= eps ||
        fabs(b + c - a) <= eps)
    {
        printf("Error: Triangle does not exist.\n");
        return 1;
    }
    // Запрос ввода координат точки М
    printf("Input coordinats of point: \n");
    // Проверка успешного ввода и считывание значений
    if (scanf("%lf%lf", &mx, &my) != 2)
    {
        printf("Wrong input");
        return 1;
    }
    
    // Вычисление расстояний от точки M до вершин треугольника
    double ma = sqrt((mx - ax) * (mx - ax) + (my - ay) * (my - ay));
    double mb = sqrt((mx - bx) * (mx - bx) + (my - by) * (my - by));
    double mc = sqrt((mx - cx) * (mx - cx) + (my - cy) * (my - cy));
    // Проверка расположения точки M относительно треугольника и вывод результата
    if (fabs(square(c, ma, mb)) <= 0 || fabs(square(b, ma, mc)) <= 0 || fabs(square(a, mb, mc)) <= 0)
        printf("1");
    else if (fabs(square(c, ma, mb) + square(b, ma, mc) + square(a, mb, mc) - square(a, b, c)) < eps)
        printf("0");
    else
        printf("2");

    return 0; // Возврат успешного завершения программы
}
