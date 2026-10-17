#include <check.h>
#include <stdlib.h>
#include "process.h"

START_TEST(test_sort)
{
    int arr[] = {3, 2, 1};
    int expected[] = {1, 2, 3};
    mysort(arr, 3, sizeof(int), compare_numbers);
    ck_assert_mem_eq(arr, expected, sizeof(expected));
}
END_TEST

START_TEST(test_sort_one)
{
    int arr[] = {1};
    int expected[] = {1};
    mysort(arr, 1, sizeof(int), compare_numbers);
    ck_assert_mem_eq(arr, expected, sizeof(expected));
}
END_TEST

START_TEST(test_sort_big_array)
{
    int arr[] = {4, 2, -4, 1, 2, 5, 7, 3};
    int expected[] = {-4, 1, 2, 2, 3, 4, 5, 7};
    mysort(arr, 8, sizeof(int), compare_numbers);
    ck_assert_mem_eq(arr, expected, sizeof(expected));
}
END_TEST

START_TEST(test_key)
{
    int arr[] = {15, 6, -4, -10, 2, -5, 7, 3};
    int expected[] = {15, 6, 7};
    int *begin = NULL;
    int *end = NULL;
    int filtered_count = 0;

    const int *p_this = arr;
    while (p_this + 1 < arr + 8)
    {
        if (filter_element(p_this, arr + 8))
        {
            filtered_count++;
        }
        p_this++;
    }

    begin = (int *)malloc(filtered_count * sizeof(int));
    if (begin == NULL)
    {
        ck_abort_msg("Memory allocation failed");
    }

    int result = key(arr, arr + 8, begin, &end);
    ck_assert_int_eq(result, OK);
    ck_assert_mem_eq(begin, expected, filtered_count * sizeof(int));

    free(begin);
}
END_TEST

START_TEST(test_whole_arr_key)
{
    int arr[] = {100, 50, 25, 12, 6, 0};
    int expected[] = {100, 50, 25, 12, 6};
    int *begin = NULL;
    int *end = NULL;
    int filtered_count = 0;

    const int *p_this = arr;
    while (p_this + 1 < arr + 6)
    {
        if (filter_element(p_this, arr + 6))
        {
            filtered_count++;
        }
        p_this++;
    }

    begin = (int *)malloc(filtered_count * sizeof(int));
    if (begin == NULL)
    {
        ck_abort_msg("Memory allocation failed");
    }

    int result = key(arr, arr + 6, begin, &end);
    ck_assert_int_eq(result, OK);

    ck_assert_mem_eq(begin, expected, filtered_count * sizeof(int));

    free(begin);
}
END_TEST

START_TEST(test_one_elem_key)
{
    int arr[] = {5000, 2, 3, 4, 5, 1000};
    int expected[] = {5000};
    int *begin = NULL;
    int *end = NULL;
    int filtered_count = 0;

    const int *p_this = arr;
    while (p_this + 1 < arr + 6)
    {
        if (filter_element(p_this, arr + 6))
        {
            filtered_count++;
        }
        p_this++;
    }

    begin = (int *)malloc(filtered_count * sizeof(int));
    if (begin == NULL)
    {
        ck_abort_msg("Memory allocation failed");
    }

    int result = key(arr, arr + 6, begin, &end);
    ck_assert_int_eq(result, OK);

    ck_assert_mem_eq(begin, expected, filtered_count * sizeof(int));

    free(begin);
}
END_TEST

START_TEST(test_empty_key)
{
    int arr[] = {1, 2, 3, 4, 5};
    int *begin = NULL;
    int *end = NULL;

    int result = key(arr, arr + 5, begin, &end);
    ck_assert_int_eq(result, EMPTY_ERROR);
}
END_TEST

Suite *process_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Process");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_sort);
    tcase_add_test(tc_core, test_sort_one);
    tcase_add_test(tc_core, test_sort_big_array);
    tcase_add_test(tc_core, test_key);
    tcase_add_test(tc_core, test_whole_arr_key);
    tcase_add_test(tc_core, test_one_elem_key);
    tcase_add_test(tc_core, test_empty_key);
    suite_add_tcase(s, tc_core);

    return s;
}