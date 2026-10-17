#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <stdio.h>
#include "node.h"

typedef struct
{
    unsigned int id;
    unsigned int available_slots;
} supervisor_t;

void assign_students_to_supervisors(node_t *students, node_t *supervisors, FILE *output);
node_t *read_supervisor_from_file(const char *filename, supervisor_t **pool, size_t *count);
void print_supervisor(const void *data, FILE *output);
int compare_supervisors_by_slots(const void *a, const void *b);
void print_student(const void *data, FILE *output);

#endif 
