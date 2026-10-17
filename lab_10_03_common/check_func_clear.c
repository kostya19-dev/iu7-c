#include "check_func_clear.h"
#include "associative_array.h"

START_TEST(test_assoc_array_clear)
{
    assoc_array_t array = assoc_array_create();
    assoc_array_insert(array, "key1", 10);
    assoc_array_insert(array, "key2", 20);
    ck_assert_int_eq(assoc_array_clear(array), ASSOC_ARRAY_OK);
    int *value;
    ck_assert_int_eq(assoc_array_find(array, "key1", &value), ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&array);
}
END_TEST

Suite *get_clear_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Clear");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_assoc_array_clear);
    suite_add_tcase(s, tc_core);

    return s;
}