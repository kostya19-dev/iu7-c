#include <check.h>
#include "check_list.h"
#include "check_student.h"
#include <stdlib.h>

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = list_suite();
    sr = srunner_create(s);

    srunner_add_suite(sr, student_suite());

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}
