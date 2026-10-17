#include "check_func_insert.h"
#include "associative_array.h"

// Define your test functions here
START_TEST(test_assoc_array_insert)
{
    // Test logic for insert function
}
END_TEST

Suite *get_insert_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Insert");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_assoc_array_insert);
    suite_add_tcase(s, tc_core);

    return s;
}