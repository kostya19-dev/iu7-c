#include "process.h"

// Функция, которая разбивает строку на массив строк. Строки представляют собой слова.
size_t split_string(char words[NMAX][NMAX + 1], const char *string, const size_t n)
{
	size_t j = 0, k = 0;
	int delim_flag = 1;
	// Пока не встречается символ разделителя, в массив добавляются символы
	for (size_t i = 0; i <= n; i++)
	{
		if (!strchr(",;:-.!? \0", string[i])) 
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

// Удаляются символы из строки, равные первому символу
void delete_first_repeats(char *string)
{ 
	for (size_t i = 1; string[i] != '\0'; i++)
		if (string[i] == string[0])
		{
			delete_symbol(string, i);
			i--;
		}
}

// Добавляется слово в конец строки
size_t insert_word(char *string, size_t length, const char *word)
{ 
	if (length)
		string[length - 1] = ' ';

	// Посимвольно добавляется слово в конец
	for (size_t j = 0; word[j] != '\0'; j++)
		string[length++] = word[j];
	// В конец добавлем символ конца строки
	string[length++] = '\0';
	// Возвращаем длину полученной строки
	return length;
}
