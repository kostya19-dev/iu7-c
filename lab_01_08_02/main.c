#include <stdio.h> // Подключение стандартной библиотеки ввода/вывода
#include <inttypes.h> 


#define CHAR_BIT 8
#define DIGITS (CHAR_BIT * sizeof(unsigned int)) // определение количества битов в типе uint32_t

// Функция bin_shift выполняет циклический сдвиг числа a на n битов влево
uint32_t bin_shift(unsigned int a, int n)
{
    return (a << n) | (a >> (DIGITS - n)); // Возвращает результат сдвига влево или вправо
}

// Функция print_bin выводит двоичное представление числа a
void print_bin(unsigned int a)
{
    unsigned int mask = 0x80000000; // Начальное значение маски для определения битов
    printf("Result: "); // Выводим сообщение

    while (mask > 0)
    {
        printf("%d", (a & mask) != 0); // Выводим значение бита: 1 или 0
        mask >>= 1; // Сдвигаем маску вправо для проверки следующего бита
    }

    printf("\n"); // Переход на новую строку
}

int main(void)
{
    unsigned int a; // Переменная для ввода числа a
    int n; // Переменная для ввода числа n

    printf("Input a: \n");
    if (scanf("%" SCNu32 "", &a) != 1)
    {
        printf("Error: wrong input."); // Выводим сообщение об ошибке
        return 1; // Завершаем программу с ошибкой
    }

    printf("Input n: \n");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Error: wrong input."); // Выводим сообщение об ошибке
        return 1; // Завершаем программу с ошибкой
    }

    n %= DIGITS; // Приведение значения n к допустимому диапазону для сдвига
    a = bin_shift(a, n); // Выполняем сдвиг числа a на n битов

    print_bin(a); // Выводим двоичное представление результата

    return 0; // Возврат успешного завершения программы
}
  
