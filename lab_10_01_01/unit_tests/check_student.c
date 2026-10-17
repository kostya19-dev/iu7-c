#include <check.h>
#include "student.h"
#include <stdlib.h>
START_TEST(test_compare_students_by_rate)
{
    student_t student1 = {1, 90.5};
    student_t student2 = {2, 85.0};

    ck_assert_int_eq(compare_students_by_rate(&student1, &student2), -1);
    ck_assert_int_eq(compare_students_by_rate(&student2, &student1), 1);
    ck_assert_int_eq(compare_students_by_rate(&student1, &student1), 0);
}
END_TEST

START_TEST(test_print_student)
{
    student_t student = {1, 90.5};
    FILE *output = fopen("test_output.txt", "w");
    print_student(&student, output);
    fclose(output);

    output = fopen("test_output.txt", "r");
    char buffer[50];
    fgets(buffer, 50, output);
    fclose(output);

    ck_assert_str_eq(buffer, "{1, 90.50}");
}
END_TEST

Suite* student_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Student");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_compare_students_by_rate);
    tcase_add_test(tc_core, test_print_student);
    suite_add_tcase(s, tc_core);

    return s;
}
