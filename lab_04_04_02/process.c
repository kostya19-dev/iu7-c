#include "process.h"

// Функция, которая разбивает строку на массив строк. Строки представляют собой слова.
size_t split_string(char words[NMAX][NMAX + 1], const char *string, const size_t n)
{
	size_t j = 0, k = 0;
	int delim_flag = 1;
	// Пока не встречается символ разделителя, в массив добавляются символы
	for (size_t i = 0; i <= n; i++)
	{
		if (!strchr("\n\t\v\r\f ", string[i])) 
		{
			delim_flag = 0;
			if (k < NMAX)
				words[j][k++] = string[i];
			else
				return 0;
		}
		else
		{
			if (!delim_flag)
			{
				delim_flag = 1;
				words[j++][k] = '\0';
				k = 0;
				if (j >= NMAX)
					return 0;
			}
		}
	}
	//Возвращаем номер последнего символа, не являющегося разделителем
	if (!delim_flag)
		return j + 1;
	return j;
}

// Удаление символа с индексом i из строки string
void delete_symbol(char *string, size_t i)
{
	while (string[i + 1] != '\0')
	{
		char temp = string[i];
		string[i] = string[i + 1];
		string[i + 1] = temp;
		i++;
	}
	//Последний символ меняется на символ конца строки
	string[i] = '\0';
}


// Проверка года на валидность строки и возврат года в случае валидности и Удаление лишних незначащих нулей в цикле for
int check_year(char *string)
{   
	for (size_t i = 0; string[i] == '0' && strlen(string) > 4; i++)
	{
		delete_symbol(string, i);
		i--;
	}

	// Если количество символов меньше 5
	if (strlen(string) != 4)
		return 0;

	// Проверка, что в формате даты не присутствуют символы, не являющиеся цифрами
	for (size_t i = 0; string[i] != '\0'; i++)
		if (!strchr("0123456789", string[i]))
			return 0;
	
	// Превращение строки в число
	return atoi(string);
}

// Проверка месяца на валидность и номера месяца в случае валидности
int check_month(char *string)
{  
	char months[MONTHS][NMAX + 1] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	
	// символы в строке превращают в строчные
	for (size_t i = 0; string[i] != '\0'; i++)
		string[i] = tolower(string[i]);
	
	// поиск совпадения с названием месяца
	for (size_t i = 0; i < MONTHS; i++)
		if (!strcmp(string, months[i]))
			// Возвращается номер месяца
			return i + 1;	
	// В случае ненахождения возвращаетс 0
	return 0;
}


int check_day(char *string, size_t month, int year)
{
	// Удаление незначащих нулей
	for (size_t i = 0; string[i] == '0' && strlen(string) > 2; i++)
	{
		delete_symbol(string, i);
		i--;
	}

	// Проверка, что номер дня состоит из одного или двух символов
	if (strlen(string) != 1 && strlen(string) != 2)
		return 0;
	
	// Проверка, что символы номера дня - это цифры
	for (size_t i = 0; string[i] != '\0'; i++)
		if (!strchr("0123456789", string[i]))
			return 0;
	
	// Превращение символов в число
	int day = atoi(string);
	
	// Проверка на валидность в зависимости от месяца
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if (day > 31)
			return 0;
	
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30)
			return 0;
	
	// Проверка в случаая февраля на високосность
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day > 29)
				return 0;
		}
		else if (day > 28)
			return 0;
	}

	return 1;
}

// Проверка всей даты
int check_date(char string[NMAX][NMAX + 1])
{   
	int year = check_year(string[2]);
	int month = check_month(string[1]);
	int day = check_day(string[0], month, year);
	
	// Проверка, что части даты валидны
	if (day && month && year)
		return 1;
	
	return 0;
}
