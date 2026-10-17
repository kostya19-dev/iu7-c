#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"
#include "student.h"
#include "errors.h"
#include "supervisor.h"

/*
Задача
В университете студенты должны выбрать себе научного руководителя для дипломного проекта.
Каждый студент имеет рейтинг, и каждый научный руководитель имеет ограниченное количество мест для студентов.
Студенты хотят выбрать научного руководителя с наибольшим количеством мест, а если мест не хватает, то они выбирают следующего по количеству мест.
Необходимо:
1. Прочитать данные о студентах и научных руководителях из файла.
2. Отсортировать студентов по рейтингу.
3. Отсортировать научных руководителей по количеству мест.
4. Распределить студентов по научным руководителям, начиная с тех, у кого больше мест.
5. Сохранить результаты распределения в выходной файл.
*/


int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <students_file> <supervisors_file> <output_file>\n", argv[0]);
        return ERROR_INVALID_ARGUMENT;
    }

    const char *students_file = argv[1];
    const char *supervisors_file = argv[2];
    const char *output_file = argv[3];

    student_t *student_pool = NULL;
    size_t student_count = 0;

    supervisor_t *supervisor_pool = NULL;
    size_t supervisor_count = 0;

    node_t *students = read_students_from_file(students_file, &student_pool, &student_count);
    node_t *supervisors = read_supervisor_from_file(supervisors_file, &supervisor_pool, &supervisor_count);

    FILE *output = fopen(output_file, "w");
    if (output == NULL)
    {
        return ERROR_FILE_OPEN;
    }

    node_t *sorted_students = sort(students, compare_students_by_rate);
    node_t *sorted_supervisors = sort(supervisors, compare_supervisors_by_slots);

    assign_students_to_supervisors(sorted_students, sorted_supervisors, output);

    fclose(output);

    free_list(&students);
    free_list(&supervisors);
    free(sorted_students);
    free(sorted_supervisors);

    free(student_pool);
    free(supervisor_pool);

    return 0;
}
