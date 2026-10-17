#include "check_func_remove.h"
#include "associative_array.h"

// Define your test functions here
START_TEST(test_assoc_array_remove)
{
    // Test logic for remove function
}
END_TEST

Suite *get_remove_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Remove");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_assoc_array_remove);
    suite_add_tcase(s, tc_core);

    return s;
}