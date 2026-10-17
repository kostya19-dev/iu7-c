#include <stdlib.h>
#include "../inc/list.h"
#include "../inc/supervisor.h"
#include "../inc/student.h"
#include "../inc/errors.h"


int compare_supervisors_by_slots(const void *a, const void *b)
{
    const supervisor_t *supervisor_a = (const supervisor_t *)a;
    const supervisor_t *supervisor_b = (const supervisor_t *)b;
    return supervisor_b->available_slots - supervisor_a->available_slots;
}

void print_supervisor(const void *data, FILE *output)
{
    const supervisor_t *supervisor = (const supervisor_t *)data;
    fprintf(output, "{%u, %u}", supervisor->id, supervisor->available_slots);
}

node_t *read_supervisor_from_file(const char *filename, supervisor_t **pool, size_t *count)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file"); 
        exit(ERROR_FILE_OPEN);
    }

    size_t capacity = 10;
    *pool = malloc(capacity * sizeof(supervisor_t));
    if (*pool == NULL)
    {
        fclose(file);
        perror("Error allocating memory"); 
        exit(ERROR_MEMORY_ALLOCATE);
    }

    node_t *head = NULL;
    *count = 0;

    unsigned int id;
    unsigned int time;
    while (fscanf(file, "%u %u\n", &id, &time) == 2)
    {
        printf("Read supervisor: ID = %u, Rate = %u\n", id, time); 

        if (*count >= capacity)
        {
            capacity *= 2;
            supervisor_t *temp_pool = realloc(*pool, capacity * sizeof(supervisor_t));
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
        (*pool)[*count].available_slots = time;

        if (push_back(&head, &((*pool)[*count])) != EXIT_SUCCESS)
        {
            free(*pool);
            fclose(file);
            free_list(&head);
            perror("Error pushing back to list|"); 
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

void assign_students_to_supervisors(node_t *students, node_t *supervisors, FILE *output)
{
    node_t *current_student = students;
    node_t *current_supervisor = supervisors;

    while (current_student != NULL)
    {
        student_t *student = (student_t *)current_student->data;
        supervisor_t *supervisor = (supervisor_t *)current_supervisor->data;

        if (supervisor->available_slots > 0)
        {
            fprintf(output, "Студент {%u, %.2lf} назначен на научного руководителя {%u, %u}\n",
            student->id, student->rate, supervisor->id, supervisor->available_slots);
            supervisor->available_slots--;
        }
        else
        {
            current_supervisor = current_supervisor->next;
            if (current_supervisor == NULL)
            {
                fprintf(output, "Студент {%u, %.2lf} не может быть назначен на научного руководителя\n",
                student->id, student->rate);
                break;
            }
            supervisor = (supervisor_t *)current_supervisor->data;
            fprintf(output, "Студент {%u, %.2lf} назначен на научного руководителя {%u, %u}\n",
            student->id, student->rate, supervisor->id, supervisor->available_slots);
            supervisor->available_slots--;
        }

        current_student = current_student->next;
    }
}