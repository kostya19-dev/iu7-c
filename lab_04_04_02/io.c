#include "io.h"

// Функция для ввода одной строки из командной строки. Функция возвращает длину введённой строки. Если длина превышает n, возвращается максимально допустимая длина
size_t read_string(char *string, const size_t n)
{ 
	int symbol;
	size_t i = 0;
	// Ввод данных до тех пор, пока не встретится символ перехода на новую строку
	while ((symbol = getchar()) != '\n' && symbol != EOF)
		if (i < n - 1)
			string[i++] = symbol;
		else
			return LEN + 1;

	// Добавление в конец символа конца строки
	string[i] = '\0';
	return i;
}
