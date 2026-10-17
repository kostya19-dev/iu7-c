#include "check_func_each.h"
#include "associative_array.h"

// Define your test functions here
START_TEST(test_assoc_array_each)
{
    // Test logic for each function
}
END_TEST

Suite *get_each_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Each");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_assoc_array_each);
    suite_add_tcase(s, tc_core);

    return s;
}