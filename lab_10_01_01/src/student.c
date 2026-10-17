#include <stdio.h>
#include <stdlib.h>
#include "../inc/list.h"
#include "student.h"
#include "node.h"
#include "errors.h"

// Функция сравнения для сортировки по ID студента
int compare_students_by_rate(const void *a, const void *b)
{
    const student_t *student_a = (const student_t *)a;
    const student_t *student_b = (const student_t *)b;

    if (student_a->rate - student_b->rate > 0.0)
    {
        return -1;
    }
    if (student_a->rate - student_b->rate < 0.0)
    {
        return 1;
    }

    return 0;
}

// Функция для вывода данных студента
void print_student(const void *data, FILE * output)
{
    const student_t *student = (const student_t *)data;
    fprintf(output, "{%d, %.2lf}", student->id, student->rate);
}

node_t *read_students_from_file(const char *filename, student_t **pool, size_t *count)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file"); 
        exit(ERROR_FILE_OPEN);
    }

    size_t capacity = 10;
    *pool = malloc(capacity * sizeof(student_t));
    if (*pool == NULL)
    {
        fclose(file);
        perror("Error allocating memory");
        exit(ERROR_MEMORY_ALLOCATE);
    }

    node_t *head = NULL;
    *count = 0;

    unsigned int id;
    double rate;
    while (fscanf(file, "%u %lf\n", &id, &rate) == 2)
    {
        printf("Read student: ID = %u, Rate = %.2lf\n", id, rate); 

        if (*count >= capacity)
        {
            capacity *= 2;
            student_t *temp_pool = realloc(*pool, capacity * sizeof(student_t));
            if (temp_pool == NULL)
            {
                free(*pool);
                fclose(file);
                free_list(&head);
                perror("Error reallocating memory"); 
                exit(ERROR_MEMORY_ALLOCATE);
            }
            *pool = temp_pool; 
        }

        (*pool)[*count].id = id;
        (*pool)[*count].rate = rate;

        if (push_back(&head, &((*pool)[*count])) != EXIT_SUCCESS)
        {
            free(*pool);
            fclose(file);
            free_list(&head);
            perror("Error pushing back to list"); 
            exit(ERROR_MEMORY_ALLOCATE);
        }

        (*count)++;
    }

    if (ferror(file))
    {
        perror("Error reading from file"); 
    }

    fclose(file);
    return head;
}