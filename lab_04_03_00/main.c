#include "io.h"
#include "process.h"
#include "errors.h"


int main(void)
{
	char in_string[LEN + 1];
	char out_string[LEN + 1];
	char words_arr[NMAX][NMAX + 1];
	size_t in_str_len;
	size_t words_count;
	size_t out_string_len = 0;
	
	in_str_len = read_string(in_string, LEN + 1);
	if (!in_str_len)
		return STRING_ERROR;
	
	words_count = split_string(words_arr, in_string, in_str_len);
	if (!words_count)
		return SPLIT_ERROR;
	
	for (size_t k = words_count - 1; k > 0; k--)
	{
		size_t i = k - 1;
		if (strcmp(words_arr[i], words_arr[words_count - 1]))
		{
			delete_first_repeats(words_arr[i]);
			out_string_len = insert_word(out_string, out_string_len, words_arr[i]);
		}
	}
	
	if (out_string_len)
		printf("Result: %s\n", out_string);
	else
		return RESULT_STRING_ERROR;
	
	return EXIT_SUCCESS;
}
