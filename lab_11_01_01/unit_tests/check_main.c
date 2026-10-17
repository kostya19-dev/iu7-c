#include <check.h>
#include <stdio.h>
#include <string.h>
#include "../inc/check_snprintf.h"

int main(void)
{
    int number_failed;
    Suite *s = snprintf_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
