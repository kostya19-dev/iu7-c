#include "process.h"
// Поиск первого вхождения символа symbol в строке string. Функция возвращает указатеь на первый найденный символ
char *my_strchr(const char *string, int symbol)
{ 
	size_t length = 0;

	// Цикл запускается, пока перебор не дойдёт до символа конца строки или пока не будет найден символ
	for (size_t i = 0; string[i] != '\0'; i++)
	{
		length += 1;
		if ((int)string[i] == symbol)
			return (char *)(string + i);
	}

	// Если symbol является символом конца строки, возвращается указатель символ конца строки, расположенный после последнего символа строки
	if (symbol == 0)
		return (char *)(string + length);
	
	return NULL;
}

// Функция, которая разбивает строку на массив строк. Строки представляют собой слова.
size_t split_string(char words[NMAX][NMAX + 1], const char *string, const size_t n)
{ 
	size_t j = 0, k = 0;
	int delim_flag = 1;

	// Пока не встречается символ разделителя, в массив добавляются символы
	for (size_t i = 0; i <= n; i++)
	{	
		if (!my_strchr(",;:-.!? \0", string[i])) 
		{
			delim_flag = 0;
			// Если встречается символ разделителя, происходит переход к следующему элементу массива
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

//Проверка, является ли слово не уникальным 
int repeat(char string[][NMAX + 1], const size_t index)
{ 
	for (size_t i = 0; i < index; i++) 
		if (strcmp(string[index], string[i]) == 0)
			return 1;
	
	return 0;
}

// Проверка, есть ли слово char  в массиве
int in_string(const char *word, char string_words[][NMAX + 1], const size_t n)
{ 	
	for (size_t i = 0; i < n; i++)
		if (strcmp(word, string_words[i]) == 0)
			return 1;
	// Если слово не найдено, возвращается 0
	return 0;
}
