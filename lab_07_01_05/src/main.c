#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "process.h"
#include "io.h"

int main(int argc, char *argv[])
{
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    int *pb = NULL;
    int *pe = NULL;
    int *pb_filtered = NULL;
    int *pe_filtered = NULL;
    int count = 0;
    int is_filter = 0;

    handle_error(check_arguments(argc, argv, &is_filter), NULL);
    handle_error(open_file(argv[1], &input_file), NULL);
    handle_error(count_elements(input_file, &count), input_file);
    handle_error(allocate_memory(&pb, &pe, count), input_file);

    rewind(input_file);
    handle_error(read_array(input_file, pb, pe), input_file);

    fclose(input_file);

    if (is_filter)
    {
        handle_error(key(pb, pe, &pb_filtered, &pe_filtered), NULL);
        free(pb);
        pb = pb_filtered;
        pe = pe_filtered;
    }

    mysort(pb, (pe - pb), sizeof(int), compare_numbers);

    handle_error(open_file_w(argv[2], &output_file), NULL);
    handle_error(write_array_to_file(output_file, pb, pe), output_file);

    fclose(output_file);
    free(pb);

    return OK;
}
