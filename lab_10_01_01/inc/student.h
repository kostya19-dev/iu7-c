#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include "../inc/node.h"
// Структура для хранения данных студента
typedef struct
{
    unsigned int id;
    double rate;
} student_t;

// Функции для работы с данными студента
int compare_students_by_rate(const void *a, const void *b);
void print_student(const void *data, FILE * output);
node_t *read_students_from_file(const char *filename, student_t **student_pool, size_t *count);

#endif 
