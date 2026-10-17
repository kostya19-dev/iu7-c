#include "file_handler.h"
#include <stdio.h>
#include <string.h>

int read_file(const char *filename, char *buffer, int buffer_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    if (fgets(buffer, buffer_size, file) == NULL) {
        fclose(file);
        return -2;
    }

    fclose(file);
    return 0;
}