#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "palindromes.h"
#include "errors.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return FILE_READ_ERROR;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    size_t rows, cols;
    int *matrix = NULL;

    int status = load_matrix(input_filename, &matrix, &rows, &cols);
    if (status != SUCCESS) {
        fprintf(stderr, "ошибка: %d\n", status);
        return status;
    }

    int *palindromes = NULL;
    size_t pal_count = extract_palindromes(matrix, rows, cols, &palindromes);

    printf("одномерный массив из чисел-палиндромов:\n");
    for (size_t i = 0; i < pal_count; i++) {
        printf("%d ", palindromes[i]);
    }
    printf("\n");

    if (pal_count == 0) {
        printf("Нету палиндромов в матрице.\n");
        save_matrix(output_filename, matrix, rows, cols);
    } else {
        sort_array(palindromes, pal_count);
        int *new_matrix = fill_matrix_with_sorted_palindromes(matrix, rows, cols, palindromes, pal_count);
        if (new_matrix) {
            save_matrix(output_filename, new_matrix, rows, cols);
            free(new_matrix);
        }
        free(palindromes);
    }

    free(matrix);
    return SUCCESS;
}
