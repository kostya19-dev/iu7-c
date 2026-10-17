#include <stdlib.h> 
#include "utils.h"
#include <stdio.h>  
#include "errors.h"
// Функция, преобразующая строку в число типа double
int str_to_double(const char *str, double *result)
{
    if (sscanf(str, "%lf", result) != 1) 
    {
        return ARG_ERROR; 
    }
    return OK; 
}
