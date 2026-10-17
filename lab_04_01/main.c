#include <string.h>
#include "process.h"

#define STR_LEN 20
#define N 5


int main(void)
{	
	const char data[N][STR_LEN] = { "", "5", "1234567890", "sdkrnf214", "smkjgnsfe" };
	const char strpbrk_data[N][STR_LEN] = { "5sg", "01234", "nrf534", "2ns", "amskj" };
	const char strcsp_data[N][STR_LEN] = { "s", "45", "1234", "sefsef2342", "098987" };
	int symbols[N] = { '4', 's', 'g', '5', '\0' };

	int fails = 0;
	
	for (size_t j = 0; j < N; j++)
		for (size_t i = 0; i < N; i++)
			if (my_strpbrk(data[j], strpbrk_data[i]) != strpbrk(data[j], strpbrk_data[i]))
				fails++;
	
	for (size_t j = 0; j < N; j++)
		for (size_t i = 0; i < N; i++)
			if (my_strspn(data[j], strcsp_data[i]) != strspn(data[j], strcsp_data[i]))
				fails++;
	
	for (size_t j = 0; j < N; j++)
		for (size_t i = 0; i < N; i++)
			if (my_strcspn(data[j], strcsp_data[i]) != strcspn(data[j], strcsp_data[i]))
				fails++;
	
	for (size_t j = 0; j < N; j++)
		for (size_t i = 0; i < N; i++)
			if (my_strchr(data[j], symbols[i]) != strchr(data[j], symbols[i]))
				fails++;
	
	for (size_t j = 0; j < N; j++)
		for (size_t i = 0; i < N; i++)
			if (my_strrchr(data[j], symbols[i]) != strrchr(data[j], symbols[i]))
				fails++;
	
	printf("Fails: %d\n", fails);
	
	return EXIT_SUCCESS;
}
