#include <check.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "errors.h"

// START_TEST(test_read_product_from_file_valid) {
//     int count;
//     Product* products;
//     int result = read_product_from_file("test_input.txt", 20, &count, &products);
//     ck_assert_int_eq(result, OK);
//     ck_assert_int_eq(count, 2);
//     ck_assert_str_eq(products[0].name, "Product1");
//     ck_assert_int_eq(products[0].price, 10);
//     ck_assert_str_eq(products[1].name, "Product2");
//     ck_assert_int_eq(products[1].price, 20);
//     free_products(products, count);
// }
// END_TEST

// START_TEST(test_read_product_from_file_invalid) {
//     int count;
//     Product* products;
//     int result = read_product_from_file("invalid_file.txt", 20, &count, &products);
//     ck_assert_int_eq(result, FILE_READ_ERROR);
// }
// END_TEST

START_TEST(test_show_products_valid)
{
    product products[2] = {{"Product1", 10}, {"Product2", 20}};
    int result = show_products(products, 2, 15);
    ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(test_show_products_invalid)
{
    product products[2] = {{"", 10}, {"Product2", -20}};
    int result = show_products(products, 2, 15);
    ck_assert_int_eq(result, ARG_ERROR);
}
END_TEST

// START_TEST(test_free_products) {
//     Product* products = malloc(sizeof(Product) * 2);
//     for (int i = 0; i < 2; i++) {
//         products[i].name = malloc(sizeof(char) * 20); // Выделение памяти под строки name
//     }
//     strcpy(products[0].name, "Product1");
//     strcpy(products[1].name, "Product2");
//     free_products(products, 2);
//     ck_assert_ptr_eq(products, NULL);
// }
// END_TEST

START_TEST(test_print_product)
{
    product product = {"Product1", 10};
    print_product(&product);
}
END_TEST

Suite* product_suite()
{
    Suite* s;
    TCase* tc_core;

    s = suite_create("Product");

    tc_core = tcase_create("Core");
    // tcase_add_test(tc_core, test_read_product_from_file_valid);
    // tcase_add_test(tc_core, test_read_product_from_file_invalid);
    tcase_add_test(tc_core, test_show_products_valid);
    tcase_add_test(tc_core, test_show_products_invalid);
    // tcase_add_test(tc_core, test_free_products);
    tcase_add_test(tc_core, test_print_product);
    suite_add_tcase(s, tc_core);

    return s;
}
