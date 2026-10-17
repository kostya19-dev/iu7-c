#include "string_handler.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Функция для проверки условия чередования букв
int is_alternating_vowel_consonant(const char *word) {
    const char *vowels = "aeiouy";
    
    int length = strlen(word);
    for (int i = 0; i < length - 1; ++i) {
        int is_current_vowel = !!strchr(vowels, tolower(word[i]));
        int is_next_vowel = !!strchr(vowels, tolower(word[i + 1]));

        if (is_current_vowel == is_next_vowel) {
            return 0;
        }
    }
    return 1;
}

void find_words(const char *text) {
    const char *delimiters = " \t\n";
    char temp[101];
    strcpy(temp, text);

    char *word = strtok(temp, delimiters);

    printf("Найденные слова:\n");

    int found_word = 0;
    while (word != NULL) {
        if (is_alternating_vowel_consonant(word)) {
            printf("%s\n", word);
            found_word = 1;
        }
        word = strtok(NULL, delimiters);
    }

    if (!found_word) {
        printf("Нет слов с чередующимися гласными и согласными\n");
    }
}