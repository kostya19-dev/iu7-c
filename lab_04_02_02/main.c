#include "io.h"
#include "process.h"
#include "errors.h"


int main(void)
{
	char string1[LEN + 1];
	char string2[LEN + 1];
	char string1_words[NMAX][NMAX + 1];
	char string2_words[NMAX][NMAX + 1];
	size_t string1_len, string1_words_count;
	size_t string2_len, string2_words_count;
	
	string1_len = read_string(string1, LEN + 1);
	
	if (!string1_len)
		return STRING_ERROR;
	
	string2_len = read_string(string2, LEN + 1);
	
	if (!string2_len)
		return STRING_ERROR;
	
	string1_words_count = split_string(string1_words, string1, string1_len);
	
	if (!string1_words_count)
		return SPLIT_ERROR;
	
	string2_words_count = split_string(string2_words, string2, string2_len);
	
	if (!string2_words_count)
		return SPLIT_ERROR;
	
	printf("Result: \n");
	for (size_t i = 0; i < string1_words_count; i++)
	{
		if (!repeat(string1_words, i))
		{
			if (in_string(string1_words[i], string2_words, string2_words_count))
			{
				fputs(string1_words[i], stdout);
				printf(" yes\n");
			}
			else
			{
				fputs(string1_words[i], stdout);
				printf(" no\n");
			}
		}
	}
	
	return EXIT_SUCCESS;
}

