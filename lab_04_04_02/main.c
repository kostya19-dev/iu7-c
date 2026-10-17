#include "io.h"
#include "process.h"
#include "errors.h"


int main(void)
{
	char string[LEN + 1];
	char words[NMAX][NMAX + 1];
	size_t string_len;
	size_t words_count;
	
	string_len = read_string(string, LEN + 1);
	if (string_len == LEN + 1)
		return STRING_ERROR;
	
	if (!string_len)
	{
		printf("NO\n");
		return EXIT_SUCCESS;
	}
	
	words_count = split_string(words, string, string_len);
	if (words_count != 3)
	{
		printf("NO\n");
		return EXIT_SUCCESS; 
	}
	
	if (check_date(words))
		printf("YES\n");
	else
		printf("NO\n");
	
	return EXIT_SUCCESS;
}
