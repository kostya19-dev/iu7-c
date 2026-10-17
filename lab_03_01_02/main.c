#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "errors.h"
#include "process.h"

int main(void)
{
    int subject[CAPACITY][CAPACITY];
    int h = 0, w = 0;
    require(input_matrix(subject, &h, &w));
    int result[CAPACITY];
    require(solve(subject, h, w, result));
    require(output_array(result, w));
    return OK;
}
