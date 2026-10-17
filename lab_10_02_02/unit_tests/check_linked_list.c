#include <check.h>
#include <stdlib.h>
#include "list.h"

START_TEST(test_create_node)
{
    node_t *node = create_node(3, 2);
    ck_assert_ptr_nonnull(node);
    ck_assert_int_eq(node->coefficient, 3);
    ck_assert_int_eq(node->degree, 2);
    ck_assert_ptr_null(node->next);
    free(node);
}
END_TEST

START_TEST(test_insert_node)
{
    node_t *head = NULL;
    insert_node(&head, 3, 2);
    insert_node(&head, 4, 1);
    insert_node(&head, 5, 0);

    ck_assert_ptr_nonnull(head);
    ck_assert_int_eq(head->coefficient, 3);
    ck_assert_int_eq(head->degree, 2);
    ck_assert_int_eq(head->next->coefficient, 4);
    ck_assert_int_eq(head->next->degree, 1);
    ck_assert_int_eq(head->next->next->coefficient, 5);
    ck_assert_int_eq(head->next->next->degree, 0);
    ck_assert_ptr_null(head->next->next->next);

    free_list(head);
}
END_TEST

Suite *list_suite(void)
{
    Suite *s;
    TCase *pos;

    s = suite_create("List Operations");
    pos = tcase_create("Positive Tests");

    tcase_add_test(pos, test_create_node);
    tcase_add_test(pos, test_insert_node);

    suite_add_tcase(s, pos);

    return s;
}
