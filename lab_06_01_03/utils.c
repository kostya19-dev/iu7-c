#include <stdlib.h>
#include "utils.h"
#include <stdio.h>

double str_to_double(const char *str)
{   
    double result;
    if (sscanf(str, "%lf", &result) != 1)
    {
        return -1;
    }
    return result;
}
