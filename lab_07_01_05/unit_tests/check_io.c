#include <check.h>
#include "io.h"

START_TEST(test_open_file_success)
{
    FILE *file = NULL;
    int result = open_file("test_input.txt", &file);
    ck_assert_int_eq(result, OK);
    fclose(file);
}
END_TEST

START_TEST(test_open_file_failure)
{
    FILE *file = NULL;
    int result = open_file("non_existing_file.txt", &file);
    ck_assert_int_eq(result, FILE_OPEN_ERROR);
    ck_assert_ptr_eq(file, NULL);
}
END_TEST

START_TEST(test_count_elements_success)
{
    FILE *file = fopen("test_input.txt", "r");
    int count = 0;
    int result = count_elements(file, &count);
    ck_assert_int_eq(result, OK);
    ck_assert_int_eq(count, 5); // Предположим, что в файле 5 чисел
    fclose(file);
}
END_TEST

// START_TEST(test_count_elements_empty_file)
// {
//     FILE *file = fopen("empty_file.txt", "r");
//     int count = 0;
//     int result = count_elements(file, &count);
//     ck_assert_int_eq(result, EMPTY_ERROR);
//     fclose(file);
// }
// END_TEST

START_TEST(test_read_array_success)
{
    FILE *file = fopen("test_input.txt", "r");
    int count = 5;
    int *pb = NULL, *pe = NULL;

    allocate_memory(&pb, &pe, count);
    int result = read_array(file, pb, pe);
    ck_assert_int_eq(result, OK);
    ck_assert_int_eq(pb[0], 1); // Предположим, что в файле первый элемент — 1
    ck_assert_int_eq(pb[4], 5); // Предположим, что в файле последний элемент — 5
    fclose(file);
    free(pb);
}
END_TEST

START_TEST(test_write_array_success)
{
    int array[] = {1, 2, 3, 4, 5};
    FILE *file = fopen("test_output.txt", "w");
    int result = write_array_to_file(file, array, array + 5);
    ck_assert_int_eq(result, OK);
    fclose(file);
}
END_TEST

Suite *io_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("IO");

    /* Основной тест */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_open_file_success);
    tcase_add_test(tc_core, test_open_file_failure);
    tcase_add_test(tc_core, test_count_elements_success);
    // tcase_add_test(tc_core, test_count_elements_empty_file);
    tcase_add_test(tc_core, test_read_array_success);
    tcase_add_test(tc_core, test_write_array_success);
    suite_add_tcase(s, tc_core);

    return s;
}
