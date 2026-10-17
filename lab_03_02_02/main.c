#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "process.h"
#include "errors.h"

int main(void)
{
    int subject[CAPACITY][CAPACITY];
    int h = 0, w = 0;
    require(input_matrix(subject, &h, &w));
    require(solve(subject, &h, w));
    require(output_matrix(subject, h, w));
    return OK;
}
