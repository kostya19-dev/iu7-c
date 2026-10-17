#include <stdio.h>
#include "file_handler.h"
#include "string_handler.h"

int main() {
    const char *filename = "input.txt";
    char text[101];  // добавляем +1 для нулевого завершителя

    // Чтение текста из файла
    if (read_file(filename, text, sizeof(text)) != 0) {
        fprintf(stderr, "Ошибка чтения файла '%s'\n", filename);
        return 1;
    }

    // Вывод текста для отладки
    printf("Содержимое файла:\n%s\n\n", text);

    // Разбор и обработка текста
    find_words(text);

    return 0;
}