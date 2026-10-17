#include "matrix.h"
#include <check.h>
#include <stdlib.h>


Suite *matrix_suite(void);

int main(void) {
    int number_failed;
    SRunner *sr;

    // Добавляем все сьюты в один раннер
    sr = srunner_create(matrix_suite());

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
