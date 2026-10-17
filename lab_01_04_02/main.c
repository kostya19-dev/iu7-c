#include <stdio.h> // Подключение стандартной библиотеки ввода/вывода


#define SEC_IN_HOURS 3600 // количество секунд в часе
#define SEC_IN_MINS 60 // количество секунд в минуте

int main(void)
{
    int time; // Объявление переменных для хранения времени в секундах, часов, минут, секунд
    int hours, minutes, seconds;

    printf("Input number of seconds: \n"); // Вывод приглашения для ввода времени в секундах
    scanf("%d", &time); // Считывание времени

    if (time < 0)
    {
        printf("Wrong input\n"); // Вывод сообщения об ошибке
        return 1; // Возврат кода ошибки
    }

    hours = time / SEC_IN_HOURS; // Вычисление количества часов
    time %= SEC_IN_HOURS; // Обновление значения времени без учета часов
    minutes = time / SEC_IN_MINS; // Вычисление количества минут
    seconds = time % SEC_IN_MINS; // Вычисление количества секунд

    printf("Hour(s) is %d , minute(s) is %d , second(s) is %d", hours, minutes, seconds); // Вывод результата

    return 0; // Возврат успешного завершения программы
}

