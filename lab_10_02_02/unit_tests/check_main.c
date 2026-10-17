#include <check.h>
#include <stdlib.h>
#include "../inc/check_linked_list.h"
#include "../inc/check_polynomial.h"

int main(void) {
    int number_failed;
    Suite* listSuite;
    Suite* polynomialSuite;
    SRunner* sr;

    sr = srunner_create(suite_create("All Tests"));

    listSuite = list_suite();
    srunner_add_suite(sr, listSuite); 

    polynomialSuite = polynomial_suite();
    srunner_add_suite(sr, polynomialSuite); 

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}