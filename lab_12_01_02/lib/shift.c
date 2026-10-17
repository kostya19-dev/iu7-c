#include <math.h>  
#include <stdbool.h>  
#include <stdlib.h>  
// Функция для проверки, является ли число точным квадратом
bool isPerfectSquare(int num)
{
    int root = (int)sqrt(num);  // Вычисляем целую часть квадратного корня числа
    return root * root == num;  // Проверяем, является ли число точным квадратом
}

// Функция для циклического сдвига массива влево на k позиций
void cyclicShiftLeft(int *arr, int n, int k)
{
    k = k % n;  // Нормализуем k, чтобы избежать лишних сдвигов
    int *temp = (int *)malloc(k * sizeof(int));  // Выделяем память для временного массива

    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];  // Сохраняем первые k элементов массива
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];  // Сдвигаем оставшиеся элементы массива влево
    }
    for (int i = 0; i < k; i++)
    {
        arr[n - k + i] = temp[i];  // Вставляем сохраненные элементы в конец массива
    }

    free(temp);  // Освобождаем память, выделенную для временного массива
}

// Функция для подсчета количества точных квадратов в массиве
int estimatePerfectSquareCount(int *src, int n)
{
    int count = 0;  // Счетчик точных квадратов
    for (int i = 0; i < n; i++)
    {
        if (isPerfectSquare(src[i]))  // Проверяем, является ли элемент точным квадратом
        {
            count++;  // Увеличиваем счетчик, если элемент является точным квадратом
        }
    }
    return count;  // Возвращаем количество точных квадратов
}

// Функция для извлечения точных квадратов из массива
int extractPerfectSquares(int *src, int *dest, int n)
{
    int count = 0;  // Счетчик точных квадратов
    for (int i = 0; i < n; i++)
    {
        if (isPerfectSquare(src[i]))  // Проверяем, является ли элемент точным квадратом
        {
            dest[count++] = src[i];  // Копируем точный квадрат в массив dest
        }
    }
    return count;  // Возвращаем количество извлеченных точных квадратов
}
