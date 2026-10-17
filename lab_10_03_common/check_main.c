#include <check.h>
#include "check_func_each.h"
#include "check_func_insert.h"
#include "check_func_remove.h"
#include "check_func_clear.h"
#include "check_func_find.h"
#include "check_func_max.h"
#include "check_func_min.h"
#include "check_func_create_destroy.h"

int main(void)
{
    Suite *each_suite = get_each_suite();
    Suite *insert_suite = get_insert_suite();
    Suite *remove_suite = get_remove_suite();
    Suite *clear_suite = get_clear_suite();
    Suite *find_suite = get_find_suite();
    Suite *max_suite = get_max_suite();
    Suite *min_suite = get_min_suite();
    Suite *create_destroy_suite = get_create_destroy_suite();

    SRunner *srunner = srunner_create(create_destroy_suite);
    srunner_add_suite(srunner, insert_suite);
    srunner_add_suite(srunner, remove_suite);
    srunner_add_suite(srunner, clear_suite);
    srunner_add_suite(srunner, find_suite);
    srunner_add_suite(srunner, max_suite);
    srunner_add_suite(srunner, min_suite);
    srunner_add_suite(srunner, each_suite);

    srunner_set_fork_status(srunner, CK_NOFORK);
    srunner_run_all(srunner, CK_VERBOSE);

    int fails = srunner_ntests_failed(srunner);

    srunner_free(srunner);

    return (fails) ? 1 : 0;
}