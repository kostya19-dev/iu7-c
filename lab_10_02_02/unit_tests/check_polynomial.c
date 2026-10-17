#include <check.h>
#include <stdlib.h>
#include "list.h"
#include "polynomial_operations.h"


START_TEST(test_evaluate_polynomial)
{
    node_t *poly = NULL;
    insert_node(&poly, 3, 2);
    insert_node(&poly, 4, 1);
    insert_node(&poly, 5, 0);

    double result = evaluate_polynomial(poly, 2);
    ck_assert_double_eq(result, 25.0);

    free_list(poly);
}
END_TEST

START_TEST(test_evaluate_empty_polynomial)
{
    node_t *poly = NULL;
    double result = evaluate_polynomial(poly, 2);
    ck_assert_double_eq(result, 0.0);
}
END_TEST

START_TEST(test_derivative)
{
    node_t *poly = NULL;
    insert_node(&poly, 3, 2);
    insert_node(&poly, 4, 1);
    insert_node(&poly, 5, 0);

    node_t *derivative_poly = derivative(poly);
    ck_assert_ptr_nonnull(derivative_poly);
    ck_assert_int_eq(derivative_poly->coefficient, 6);
    ck_assert_int_eq(derivative_poly->degree, 1);
    ck_assert_int_eq(derivative_poly->next->coefficient, 4);
    ck_assert_int_eq(derivative_poly->next->degree, 0);
    ck_assert_ptr_null(derivative_poly->next->next);

    free_list(poly);
    free_list(derivative_poly);
}
END_TEST

START_TEST(test_derivative_empty_polynomial)
{
    node_t *poly = NULL;
    node_t *derivative_poly = derivative(poly);
    ck_assert_ptr_null(derivative_poly);
}
END_TEST

START_TEST(test_add_polynomials)
{
    node_t *poly1 = NULL;
    insert_node(&poly1, 3, 2);
    insert_node(&poly1, 4, 1);

    node_t *poly2 = NULL;
    insert_node(&poly2, 5, 1);
    insert_node(&poly2, 6, 0);

    node_t *sum_poly = add_polynomials(poly1, poly2);
    ck_assert_ptr_nonnull(sum_poly);
    ck_assert_int_eq(sum_poly->coefficient, 3);
    ck_assert_int_eq(sum_poly->degree, 2);
    ck_assert_int_eq(sum_poly->next->coefficient, 9);
    ck_assert_int_eq(sum_poly->next->degree, 1);
    ck_assert_int_eq(sum_poly->next->next->coefficient, 6);
    ck_assert_int_eq(sum_poly->next->next->degree, 0);
    ck_assert_ptr_null(sum_poly->next->next->next);

    free_list(poly1);
    free_list(poly2);
    free_list(sum_poly);
}
END_TEST

START_TEST(test_add_empty_polynomials)
{
    node_t *poly1 = NULL;
    node_t *poly2 = NULL;

    node_t *sum_poly = add_polynomials(poly1, poly2);
    ck_assert_ptr_null(sum_poly);
}
END_TEST

START_TEST(test_divide_polynomial)
{
    node_t *poly = NULL;
    insert_node(&poly, 3, 2);
    insert_node(&poly, 4, 1);
    insert_node(&poly, 5, 0);

    node_t *even_poly = NULL;
    node_t *odd_poly = NULL;
    divide_polynomial(poly, &even_poly, &odd_poly);

    ck_assert_ptr_nonnull(even_poly);
    ck_assert_int_eq(even_poly->coefficient, 3);
    ck_assert_int_eq(even_poly->degree, 2);
    ck_assert_int_eq(even_poly->next->coefficient, 5);
    ck_assert_int_eq(even_poly->next->degree, 0);
    ck_assert_ptr_null(even_poly->next->next);

    ck_assert_ptr_nonnull(odd_poly);
    ck_assert_int_eq(odd_poly->coefficient, 4);
    ck_assert_int_eq(odd_poly->degree, 1);
    ck_assert_ptr_null(odd_poly->next);

    free_list(poly);
    free_list(even_poly);
    free_list(odd_poly);
}
END_TEST

START_TEST(test_divide_empty_polynomial)
{
    node_t *poly = NULL;
    node_t *even_poly = NULL;
    node_t *odd_poly = NULL;

    divide_polynomial(poly, &even_poly, &odd_poly);

    ck_assert_ptr_null(even_poly);
    ck_assert_ptr_null(odd_poly);
}
END_TEST

Suite *polynomial_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("Polynomial Operations");
    pos = tcase_create("Positive Tests");
    neg = tcase_create("Negative Tests");

    tcase_add_test(pos, test_evaluate_polynomial);
    tcase_add_test(pos, test_derivative);
    tcase_add_test(pos, test_add_polynomials);
    tcase_add_test(pos, test_divide_polynomial);

    tcase_add_test(neg, test_evaluate_empty_polynomial);
    tcase_add_test(neg, test_derivative_empty_polynomial);
    tcase_add_test(neg, test_add_empty_polynomials);
    tcase_add_test(neg, test_divide_empty_polynomial);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}
