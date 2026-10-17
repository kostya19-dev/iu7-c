#include <check.h>
#include <stdio.h>
#include <string.h>
#include "../inc/my_snprintf.h"

// START_TEST(test_simple_strings)
// {
//   char buffer1[100], buffer2[100];
//   int len1 = snprintf(buffer1, sizeof(buffer1), "123");
//   int len2 = my_snprintf(buffer2, sizeof(buffer2), "123");
//   ck_assert_int_eq(len1, len2);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(test_integer)
{
  char buffer1[100], buffer2[100];
  int len1 = snprintf(buffer1, sizeof(buffer1), "Number: %d", 52);
  int len2 = my_snprintf(buffer2, sizeof(buffer2), "Number: %d", 52);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_hexadecimal)
{
  char buffer1[100], buffer2[100];
  int len1 = snprintf(buffer1, sizeof(buffer1), "Hex: %x", 52);
  int len2 = my_snprintf(buffer2, sizeof(buffer2), "Hex: %x", 52);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_octal)
{
  char buffer1[100], buffer2[100];
  int len1 = snprintf(buffer1, sizeof(buffer1), "Octal: %o", 52);
  int len2 = my_snprintf(buffer2, sizeof(buffer2), "Octal: %o", 52);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_char)
{
  char buffer1[100], buffer2[100];
  int len1 = snprintf(buffer1, sizeof(buffer1), "Char: %c", 'A');
  int len2 = my_snprintf(buffer2, sizeof(buffer2), "Char: %c", 'A');
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_string)
{
  char buffer1[100], buffer2[100];
  int len1 = snprintf(buffer1, sizeof(buffer1), "String: %s", "sankt-peterburg");
  int len2 = my_snprintf(buffer2, sizeof(buffer2), "String: %s", "sankt-peterburg");
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_combined)
{
  char buffer1[100], buffer2[100];
  int len1 = snprintf(buffer1, sizeof(buffer1), "Int: %d, Hex: %x, Oct: %o, Char: %c, Str: %s", 52, 5252, 511, 'A', "xx");
  int len2 = my_snprintf(buffer2, sizeof(buffer2), "Int: %d, Hex: %x, Oct: %o, Char: %c, Str: %s", 52, 5252, 511, 'A', "xx");
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_long_and_short)
{
  char buffer1[100], buffer2[100];
  int len1 = snprintf(buffer1, sizeof(buffer1), "Long: %ld, Short: %hd", 123456789L, (short)12345);
  int len2 = my_snprintf(buffer2, sizeof(buffer2), "Long: %ld, Short: %hd", 123456789L, (short)12345);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST


Suite *snprintf_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("my_snprintf");

  tc_core = tcase_create("Core");

  // tcase_add_test(tc_core, test_simple_strings);
  tcase_add_test(tc_core, test_integer);
  tcase_add_test(tc_core, test_hexadecimal);
  tcase_add_test(tc_core, test_octal);
  tcase_add_test(tc_core, test_char);
  tcase_add_test(tc_core, test_string);
  tcase_add_test(tc_core, test_combined);
  tcase_add_test(tc_core, test_long_and_short);

  suite_add_tcase(s, tc_core);

  return s;
}
