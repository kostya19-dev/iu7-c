#include "check_func_max.h"
#include "associative_array.h"

// Define your test functions here
START_TEST(test_assoc_array_max)
{
    // Test logic for max function
}
END_TEST

Suite *get_max_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Max");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_assoc_array_max);
    suite_add_tcase(s, tc_core);

    return s;
}