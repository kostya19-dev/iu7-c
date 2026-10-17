#include <check.h>
#include "utils.h"
#include <stdlib.h>
#include "errors.h"

START_TEST(test_str_to_double_valid)
{
    double value;
    int result = str_to_double("123.45", &value);
    ck_assert_int_eq(result, OK);
    ck_assert_double_eq_tol(value, 123.45, 0.001);
}
END_TEST

START_TEST(test_str_to_double_invalid)
{
    double value;
    int result = str_to_double("abc", &value);
    ck_assert_int_eq(result, ARG_ERROR);
}
END_TEST

Suite* utils_suite()
{
    Suite* s;
    TCase* tc_core;

    s = suite_create("Utils");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_str_to_double_valid);
    tcase_add_test(tc_core, test_str_to_double_invalid);
    suite_add_tcase(s, tc_core);

    return s;
}
