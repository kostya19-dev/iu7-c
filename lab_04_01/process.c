#include "process.h"

// Функция возвращает указатель на первый символ в str1, который есть в строке str2
char *my_strpbrk(const char *str1, const char *str2)
{
	for (size_t i = 0; str1[i] != '\0'; i++) 
		for (size_t j = 0; str2[j] != '\0'; j++)
			if (str1[i] == str2[j])
				return (char *)(str1 + i);
	// поиск одинаковых символов в str1 и str2
	return NULL;
}

// Функция возвращает длину первой подстроки в строке str1, содержащую только символы из str2
size_t my_strspn(const char *str1, const char *str2)
{
	int flag = 1;
	size_t result = 0;
	
	// Проверяем все символы в str[1], пока не будет конца строки или пока не встретится символ, которого нет в str2
	for (size_t i = 0; flag && str1[i] != '\0'; i++)
	{
		flag = 0;
		for (size_t j = 0; !flag && str2[j] != '\0'; j++)
			if (str1[i] == str2[j])
			{
				flag = 1;
				result++;
			}
	}
	
	return result;
}

// Функция возвращает длину первой подстроки в строке str1, не содержащую символы из str2
size_t my_strcspn(const char *str1, const char *str2)
{
	size_t result = 0;
	
	// Проверяем все символы в str[1], пока не будет конца строки или пока не встретится символ, который есть в str2
	for (size_t i = 0; str1[i] != '\0'; i++)
	{
		result++;
		for (size_t j = 0; str2[j] != '\0'; j++)
			if (str1[i] == str2[j])
				return i;
	}
	
	return result;
}

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

// Поиск последнего вхождения символа symbol в строке string. Функция возвращает указатеь на последний найденный символ
char *my_strrchr(const char *string, int symbol)
{ 
	size_t length = 0;
	char *result = NULL;
	
	// Цикл запускается, пока перебор не дойдёт до символа конца строки. Если находится символ, равный symbol, result меняется
	for (size_t i = 0; string[i] != '\0'; i++)
	{
		length++;
		if ((int)string[i] == symbol)
			result = (char *)(string + i);
	}
	
	// Если symbol равен символу конца строки, возвращается указатель на первый символ конца строки в строке
	if (symbol == 0)
		return (char *)(string + length);
	
	return result;
}