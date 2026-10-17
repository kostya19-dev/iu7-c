#include <check.h>
#include "../inc/matrix.h"
#include <stdlib.h>
#include "../inc/main.h"

// Тест удаления строк с минимальными значениями
START_TEST(test_remove_min_rows) {
  int64_t **matrix = allocate_matrix(3, 2);
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[1][0] = 3;
  matrix[1][1] = 4;
  matrix[2][0] = 5;
  matrix[2][1] = 6;

  int64_t expected_row_1[2] = {3, 4};
  int64_t expected_row_2[2] = {5, 6};
  int64_t rows = 3;
  int64_t expected_rows = 2;

  remove_min_rows(&matrix, &rows, 2);

  ck_assert_int_eq(rows, expected_rows);
  ck_assert_mem_eq(matrix[0], expected_row_1, sizeof(int64_t) * 2);
  ck_assert_mem_eq(matrix[1], expected_row_2, sizeof(int64_t) * 2);

  free_matrix(matrix, rows);
}
END_TEST

// Тест удаления столбцов с минимальными значениями
START_TEST(test_remove_min_cols) {
  int64_t **matrix = allocate_matrix(2, 3);
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 5;
  matrix[1][2] = 6;

  int64_t expected_row_1[2] = {2, 3};
  int64_t expected_row_2[2] = {5, 6};
  int64_t cols = 3;

  remove_min_cols(&matrix, 2, &cols);

  ck_assert_int_eq(cols, 2);
  ck_assert_mem_eq(matrix[0], expected_row_1, sizeof(int64_t) * 2);
  ck_assert_mem_eq(matrix[1], expected_row_2, sizeof(int64_t) * 2);

  free_matrix(matrix, 2);
}
END_TEST

// Тест на расширение матрицы
START_TEST(test_expand_matrix) {
  int64_t **matrix = allocate_matrix(2, 3);
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 5;
  matrix[1][2] = 6;

  int64_t rows = 2;
  int64_t cols = 3;

  expand_matrix(&matrix, &rows, &cols, 4);

  int64_t expected_row_1[4] = {1, 2, 3, 3};
  int64_t expected_row_2[4] = {4, 5, 6, 6};
  int64_t expected_row_3[4] = {2, 3, 4, 4};
  int64_t expected_row_4[4] = {2, 3, 4, 4};

  ck_assert_int_eq(rows, 4);
  ck_assert_int_eq(cols, 4);

  ck_assert_mem_eq(matrix[0], expected_row_1, sizeof(int64_t) * 4);
  ck_assert_mem_eq(matrix[1], expected_row_2, sizeof(int64_t) * 4);
  ck_assert_mem_eq(matrix[2], expected_row_3, sizeof(int64_t) * 4);
  ck_assert_mem_eq(matrix[3], expected_row_4, sizeof(int64_t) * 4);

  free_matrix(matrix, rows);
}
END_TEST

// Тест на возведение матрицы в степень
// START_TEST(test_matrix_power)
// {
//   int64_t **matrix = allocate_matrix(2, 2);
//   matrix[0][0] = 1;
//   matrix[0][1] = 2;
//   matrix[1][0] = 3;
//   matrix[1][1] = 4;

//   int64_t expected_row_1[2] = {1295, 1908};
//   int64_t expected_row_2[2] = {2607, 3732};

//   int64_t **result = matrix_power(matrix, 2, 5);
//   print_matrix(result, 2, 2);
//   ck_assert_mem_eq(result[0], expected_row_1, sizeof(int64_t) * 2);
//   ck_assert_mem_eq(result[1], expected_row_2, sizeof(int64_t) * 2);

//   free_matrix(matrix, 2);
//   free_matrix(result, 2);
// }
// END_TEST



// Тест на чтение матрицы (граничный случай)
START_TEST(test_read_matrix) {
  int64_t **matrix = allocate_matrix(3, 3);

  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 5;
  matrix[1][2] = 6;
  matrix[2][0] = 7;
  matrix[2][1] = 8;
  matrix[2][2] = 9;

  // Проверка корректности данных
  ck_assert_int_eq(matrix[0][0], 1);
  ck_assert_int_eq(matrix[1][1], 5);
  ck_assert_int_eq(matrix[2][2], 9);

  free_matrix(matrix, 3);
}
END_TEST

// Тест на освобождение памяти
START_TEST(test_free_matrix) {
  int64_t **matrix = allocate_matrix(2, 2);
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[1][0] = 3;
  matrix[1][1] = 4;

  // Проверка до освобождения
  ck_assert_int_eq(matrix[0][0], 1);
  ck_assert_int_eq(matrix[1][1], 4);

  free_matrix(matrix, 2);
}
END_TEST

// Тест на матрицу с нулями
START_TEST(test_matrix_with_zeros) {
  int64_t **matrix = allocate_matrix(2, 3);

  // Заполнение матрицы нулями
  matrix[0][0] = 0;
  matrix[0][1] = 0;
  matrix[0][2] = 0;
  matrix[1][0] = 0;
  matrix[1][1] = 0;
  matrix[1][2] = 0;

  int64_t expected_row_1[3] = {0, 0, 0};
  int64_t expected_row_2[3] = {0, 0, 0};

  // Проверка нулевой матрицы
  ck_assert_mem_eq(matrix[0], expected_row_1, sizeof(int64_t) * 3);
  ck_assert_mem_eq(matrix[1], expected_row_2, sizeof(int64_t) * 3);

  free_matrix(matrix, 2);
}
END_TEST

Suite *matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("matrix");

  /* Основной тест */
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_remove_min_rows);
  tcase_add_test(tc_core, test_remove_min_cols);
  tcase_add_test(tc_core, test_expand_matrix);
  // tcase_add_test(tc_core, test_matrix_power);
  tcase_add_test(tc_core, test_read_matrix);
  tcase_add_test(tc_core, test_free_matrix);
  tcase_add_test(tc_core, test_matrix_with_zeros);
  suite_add_tcase(s, tc_core);

  return s;
}
