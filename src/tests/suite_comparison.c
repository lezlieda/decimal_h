#include "../s21_decimal.h"
#include "../suitecases.h"

START_TEST(test_s21_is_equal_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_3) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_4) {
  s21_decimal value_1 = {{1, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0x89E80000, 0x8AC72304, 0, 0x80130000}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_5) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_6) {
  s21_decimal value_1 = {{111, 0, 0, 0}};
  s21_decimal value_2 = {{111, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_3) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_4) {
  s21_decimal value_1 = {{1, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0x89E80000, 0x8AC72304, 0, 0x80130000}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_5) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_6) {
  s21_decimal value_1 = {{111, 0, 0, 0}};
  s21_decimal value_2 = {{111, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_1) {
  s21_decimal value_1 = {{0, 651, 2, 0}};
  s21_decimal value_2 = {{0, 651, 2, 0x80000000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_3) {
  s21_decimal value_1 = {{123, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{124, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_4) {
  s21_decimal value_1 = {{124, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0x49504F80, 0, 0, 0x80070000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_5) {
  s21_decimal value_1 = {{124, 0, 0, 0}};
  s21_decimal value_2 = {{0x49504F80, 0, 0, 0x70000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_6) {
  s21_decimal value_1 = {{0x27780058, 0xC249FDD3, 0, 0x120000}};
  s21_decimal value_2 = {{14, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_7) {
  s21_decimal value_1 = {{0x27780058, 0xC249FDD3, 0, 0x120000}};
  s21_decimal value_2 = {{15, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_1) {
  s21_decimal value_1 = {{0x27780058, 0xC249FDD3, 0, 0x110000}};
  s21_decimal value_2 = {{0x27780058, 0xC249FDD3, 0, 0x110000}};
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_2) {
  s21_decimal value_1 = {{0x27780058, 0xC249FDD3, 0, 0x110000}};
  s21_decimal value_2 = {{0x27780058, 0xC249FDD3, 0, 0x100000}};
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_1) {
  s21_decimal value_1 = {{0, 651, 2, 0}};
  s21_decimal value_2 = {{0, 651, 2, 0x80000000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_3) {
  s21_decimal value_1 = {{123, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{124, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_4) {
  s21_decimal value_1 = {{124, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0x49504F80, 0, 0, 0x80070000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_5) {
  s21_decimal value_1 = {{124, 0, 0, 0}};
  s21_decimal value_2 = {{0x49504F80, 0, 0, 0x70000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_6) {
  s21_decimal value_1 = {{0x27780058, 0xC249FDD3, 0, 0x120000}};
  s21_decimal value_2 = {{14, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_7) {
  s21_decimal value_1 = {{0x27780058, 0xC249FDD3, 0, 0x120000}};
  s21_decimal value_2 = {{15, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_1) {
  s21_decimal value_1 = {{0x27780058, 0xC249FDD3, 0, 0x110000}};
  s21_decimal value_2 = {{0x27780058, 0xC249FDD3, 0, 0x110000}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_2) {
  s21_decimal value_1 = {{0x27780058, 0xC249FDD3, 0, 0x110000}};
  s21_decimal value_2 = {{0x27780058, 0xC249FDD3, 0, 0x100000}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 0);
}
END_TEST

Suite *suite_s21_comparison() {
  Suite *suite = suite_create("s21_comparison");
  TCase *tcase = tcase_create("s21_comparison");

  tcase_add_test(tcase, test_s21_is_equal_1);
  tcase_add_test(tcase, test_s21_is_equal_2);
  tcase_add_test(tcase, test_s21_is_equal_3);
  tcase_add_test(tcase, test_s21_is_equal_4);
  tcase_add_test(tcase, test_s21_is_equal_5);
  tcase_add_test(tcase, test_s21_is_equal_6);

  tcase_add_test(tcase, test_s21_is_not_equal_1);
  tcase_add_test(tcase, test_s21_is_not_equal_2);
  tcase_add_test(tcase, test_s21_is_not_equal_3);
  tcase_add_test(tcase, test_s21_is_not_equal_4);
  tcase_add_test(tcase, test_s21_is_not_equal_5);
  tcase_add_test(tcase, test_s21_is_not_equal_6);

  tcase_add_test(tcase, test_s21_is_less_1);
  tcase_add_test(tcase, test_s21_is_less_2);
  tcase_add_test(tcase, test_s21_is_less_3);
  tcase_add_test(tcase, test_s21_is_less_4);
  tcase_add_test(tcase, test_s21_is_less_5);
  tcase_add_test(tcase, test_s21_is_less_6);
  tcase_add_test(tcase, test_s21_is_less_7);

  tcase_add_test(tcase, test_s21_is_less_or_equal_1);
  tcase_add_test(tcase, test_s21_is_less_or_equal_2);

  tcase_add_test(tcase, test_s21_is_greater_1);
  tcase_add_test(tcase, test_s21_is_greater_2);
  tcase_add_test(tcase, test_s21_is_greater_3);
  tcase_add_test(tcase, test_s21_is_greater_4);
  tcase_add_test(tcase, test_s21_is_greater_5);
  tcase_add_test(tcase, test_s21_is_greater_6);
  tcase_add_test(tcase, test_s21_is_greater_7);

  tcase_add_test(tcase, test_s21_is_greater_or_equal_1);
  tcase_add_test(tcase, test_s21_is_greater_or_equal_2);

  suite_add_tcase(suite, tcase);
  return suite;
}