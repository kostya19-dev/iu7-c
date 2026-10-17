#include <check.h>
#include "list.h"
#include "student.h"
#include <stdlib.h>

START_TEST(test_create_node)
{
    student_t *student = (student_t*) malloc(sizeof(student_t));
    student->id = 1;
    student->rate = 90.5;

    node_t *node = create_node(student);
    ck_assert_ptr_nonnull(node);
    ck_assert_ptr_eq(node->data, student);
    ck_assert_ptr_null(node->next);

    free(node);
    free(student);
}
END_TEST

START_TEST(test_push_back)
{
    node_t *head = NULL;
    student_t *student1 = (student_t*) malloc(sizeof(student_t));
    student1->id = 1;
    student1->rate = 90.5;

    student_t *student2 = (student_t*) malloc(sizeof(student_t));
    student2->id = 2;
    student2->rate = 85.0;

    push_back(&head, student1);
    push_back(&head, student2);

    ck_assert_ptr_nonnull(head);
    ck_assert_ptr_eq(head->data, student1);
    ck_assert_ptr_nonnull(head->next);
    ck_assert_ptr_eq(head->next->data, student2);
    ck_assert_ptr_null(head->next->next);

    free(head->next);
    free(head);
    free(student1);
    free(student2);
}
END_TEST

START_TEST(test_pop_front)
{
    node_t *head = NULL;
    student_t *student1 = (student_t*) malloc(sizeof(student_t));
    student1->id = 1;
    student1->rate = 90.5;

    student_t *student2 = (student_t*) malloc(sizeof(student_t));
    student2->id = 2;
    student2->rate = 85.0;

    push_back(&head, student1);
    push_back(&head, student2);

    student_t *popped = (student_t*) pop_front(&head);
    ck_assert_ptr_eq(popped, student1);
    ck_assert_ptr_eq(head->data, student2);
    ck_assert_ptr_null(head->next);

    free(head);
    free(student1);
    free(student2);
}
END_TEST

START_TEST(test_pop_back)
{
    node_t *head = NULL;
    student_t *student1 = (student_t*) malloc(sizeof(student_t));
    student1->id = 1;
    student1->rate = 90.5;

    student_t *student2 = (student_t*) malloc(sizeof(student_t));
    student2->id = 2;
    student2->rate = 85.0;

    push_back(&head, student1);
    push_back(&head, student2);

    student_t *popped = (student_t*) pop_back(&head);
    ck_assert_ptr_eq(popped, student2);
    ck_assert_ptr_eq(head->data, student1);
    ck_assert_ptr_null(head->next);

    free(head);
    free(student1);
    free(student2);
}
END_TEST

START_TEST(test_free_list)
{
    node_t *head = NULL;
    student_t *student1 = (student_t*) malloc(sizeof(student_t));
    student1->id = 1;
    student1->rate = 90.5;

    student_t *student2 = (student_t*) malloc(sizeof(student_t));
    student2->id = 2;
    student2->rate = 85.0;

    push_back(&head, student1);
    push_back(&head, student2);

    free_list(&head);
    ck_assert_ptr_null(head);

    free(student1);
    free(student2);
}
END_TEST

START_TEST(test_copy_list)
{
    node_t *head = NULL;
    student_t *student1 = (student_t*) malloc(sizeof(student_t));
    student1->id = 1;
    student1->rate = 90.5;

    student_t *student2 = (student_t*) malloc(sizeof(student_t));
    student2->id = 2;
    student2->rate = 85.0;

    push_back(&head, student1);
    push_back(&head, student2);

    node_t *copied_head = NULL;
    int result = copy(head, &copied_head);
    ck_assert_int_eq(result, OK);

    ck_assert_ptr_nonnull(copied_head);
    ck_assert_ptr_eq(copied_head->data, student1);
    ck_assert_ptr_nonnull(copied_head->next);
    ck_assert_ptr_eq(copied_head->next->data, student2);
    ck_assert_ptr_null(copied_head->next->next);

    free_list(&head);
    free_list(&copied_head);
    free(student1);
    free(student2);
}
END_TEST

START_TEST(test_sort_list)
{
    node_t *head = NULL;
    student_t *student1 = (student_t*) malloc(sizeof(student_t));
    student1->id = 1;
    student1->rate = 85.0;

    student_t *student2 = (student_t*) malloc(sizeof(student_t));
    student2->id = 2;
    student2->rate = 90.5;

    push_back(&head, student1);
    push_back(&head, student2);

    node_t *sorted_head = sort(head, compare_students_by_rate);

    ck_assert_ptr_nonnull(sorted_head);
    ck_assert_int_eq(((student_t*)sorted_head->data)->id, student2->id);
    ck_assert_double_eq_tol(((student_t*)sorted_head->data)->rate, student2->rate, 0.01);
    ck_assert_ptr_nonnull(sorted_head->next);
    ck_assert_int_eq(((student_t*)sorted_head->next->data)->id, student1->id);
    ck_assert_double_eq_tol(((student_t*)sorted_head->next->data)->rate, student1->rate, 0.01);
    ck_assert_ptr_null(sorted_head->next->next);

    free_list(&sorted_head);
    free(student1);
    free(student2);
}
END_TEST

Suite* list_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("List");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_node);
    tcase_add_test(tc_core, test_push_back);
    tcase_add_test(tc_core, test_pop_front);
    tcase_add_test(tc_core, test_pop_back);
    tcase_add_test(tc_core, test_free_list);
    tcase_add_test(tc_core, test_copy_list);
    tcase_add_test(tc_core, test_sort_list);
    suite_add_tcase(s, tc_core);

    return s;
}
