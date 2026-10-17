#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h> // Для динамической загрузки

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
    int filtered_count = 0;

    void *lib_handle = NULL;
    int (*mysort_ptr)(void *, size_t, size_t, int (*)(const void *, const void *)) = NULL;
    int (*key_ptr)(const int *, const int *, int *, int **) = NULL;
    int (*compare_numbers_ptr)(const void *, const void *) = NULL;
    int (*filter_element_ptr)(const int *, const int *) = NULL;

    lib_handle = dlopen("./lib/libmylib.so", RTLD_LAZY);
    if (!lib_handle)
    {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        return LIB_LOAD_ERROR;
        
    }

    mysort_ptr = dlsym(lib_handle, "mysort");
    key_ptr = dlsym(lib_handle, "key");
    compare_numbers_ptr = dlsym(lib_handle, "compare_numbers");
    filter_element_ptr = dlsym(lib_handle, "filter_element");

    const char *error = dlerror();
    if (error != NULL)
    {
        fprintf(stderr, "Error loading symbol: %s\n", error);
        dlclose(lib_handle);
        return FILE_OPEN_ERROR;
    }

    handle_error(check_arguments(argc, argv, &is_filter), NULL);
    handle_error(open_file(argv[1], &input_file), NULL);
    handle_error(count_elements(input_file, &count), input_file);
    handle_error(allocate_memory(&pb, &pe, count), input_file);
    rewind(input_file);
    handle_error(read_array(input_file, pb, pe), input_file);

    fclose(input_file);

    if (is_filter)
    {
        const int *p_this = pb;
        while (p_this + 1 < pe)
        {
            if (filter_element_ptr(p_this, pe))
            {
                filtered_count++;
            }
            p_this++;
        }

        if (filtered_count == 0)
        {
            free(pb);
            handle_error(EMPTY_ERROR, NULL);
        }

        pb_filtered = (int *)malloc(filtered_count * sizeof(int));
        if (pb_filtered == NULL)
        {
            free(pb);
            handle_error(ALLOC_ERROR, NULL);
        }

        handle_error(key_ptr(pb, pe, pb_filtered, &pe_filtered), NULL);

        free(pb);

        pb = pb_filtered;
        pe = pe_filtered;
    }

    // Сортировка массива
    mysort_ptr(pb, (pe - pb), sizeof(int), compare_numbers_ptr);

    handle_error(open_file_w(argv[2], &output_file), NULL);

    handle_error(write_array_to_file(output_file, pb, pe), output_file);

    fclose(output_file);
    free(pb);
    dlclose(lib_handle);

    return OK;
}