#include "../s21_decimal.h"
#include "../suitecases.h"

START_TEST(s21_from_int_to_decimal_1) {
  s21_decimal dec = {{32165, 651651, 351651, 651651}};
  int input = -2147483648;
  int error = s21_from_int_to_decimal(input, &dec);
  s21_decimal expected = {{2147483648, 0, 0, 0x80000000}};
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], expected.bits[i]);
  }
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
  s21_decimal dec = {{32165, 651651, 351651, 651651}};
  int input = -1469;
  int error = s21_from_int_to_decimal(input, &dec);
  s21_decimal expected = {{1469, 0, 0, 0x80000000}};
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], expected.bits[i]);
  }
}
END_TEST

START_TEST(s21_from_int_to_decimal_3) {
  s21_decimal dec = {{32165, 651651, 351651, 651651}};
  int input = 0;
  int error = s21_from_int_to_decimal(input, &dec);
  s21_decimal expected = {{0, 0, 0, 0}};
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], expected.bits[i]);
  }
}
END_TEST

START_TEST(s21_from_int_to_decimal_4) {
  s21_decimal dec = {{32165, 651651, 351651, 651651}};
  int input = 1469;
  int error = s21_from_int_to_decimal(input, &dec);
  s21_decimal expected = {{1469, 0, 0, 0}};
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], expected.bits[i]);
  }
}
END_TEST

START_TEST(s21_from_int_to_decimal_5) {
  s21_decimal *dec = NULL;
  int input = 2147483647;
  int error = s21_from_int_to_decimal(input, dec);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal dec = {{2147483648, 0, 0, 0x80000000}};
  float output = 13241.16451;
  int error = s21_from_decimal_to_float(dec, &output);
  ck_assert_int_eq(error, 0);
  ck_assert_float_eq(output, -2147483648);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal dec = {{1469, 0, 0, 0x80000000}};
  float output = 13241.16451;
  int error = s21_from_decimal_to_float(dec, &output);
  ck_assert_int_eq(error, 0);
  ck_assert_float_eq(output, -1469);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal dec = {{0xC08C4AEF, 0x3131496B, 0x8C88291, 0x1B0000}};
  float output = 13241.16451;
  int error = s21_from_decimal_to_float(dec, &output);
  ck_assert_int_eq(error, 0);
  ck_assert_float_eq(output, 2.718281828459045235360287471);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  s21_decimal dec = {{0x26000000, 0xBB463BB0, 0x6582A3D3, 0x801C0000}};
  float output = 13241.16451;
  int error = s21_from_decimal_to_float(dec, &output);
  ck_assert_int_eq(error, 0);
  ck_assert_float_eq(output, -3.141592);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal dec = {{0, 0, 0, 0x80000000}};
  float output = 13241.16451;
  int error = s21_from_decimal_to_float(dec, &output);
  ck_assert_int_eq(error, 0);
  ck_assert_float_eq(output, -0.);
}
END_TEST

START_TEST(s21_from_decimal_to_float_6) {
  s21_decimal dec = {{0x26000000, 0xBB463BB0, 0x6582A3D3, 0x801C0000}};
  float *output = NULL;
  int error = s21_from_decimal_to_float(dec, output);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_1) {
  float input = -30914.76;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0x002F2C14, 0, 0, 0x80020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  float input = 1.965111E-26;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0x000000C5, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  float input = -750.9904;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0x00729790, 0, 0, 0x80040000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  float input = 72932.2;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0x006F4924, 0, 0, 0x00020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
  float input = 7.526432E-06;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0x0072D820, 0, 0, 0x000C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
  float input = -1.391184E+17;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0x9DB88000, 0x01EE3F72, 0, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_7) {
  float input = 1. / 0.;
  s21_decimal output;
  int error = s21_from_float_to_decimal(input, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], 0);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_8) {
  float input = 2;
  s21_decimal *output = NULL;
  int error = s21_from_float_to_decimal(input, output);
  ck_assert_ptr_eq(output, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_9) {
  float input = NAN;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_10) {
  float input = -INFINITY;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_11) {
  float input = INFINITY;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_12) {
  float input = -0.;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0, 0, 0, 0x80060000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_13) {
  float input = 1.23e-33;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_14) {
  float input = 1.23e34;
  s21_decimal output = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(input, &output);
  s21_decimal res = {{0, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_1) {
  s21_decimal input = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int output = 123;
  int error = s21_from_decimal_to_int(input, &output);
  ck_assert_int_eq(output, -7);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  s21_decimal input = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int *output = NULL;
  int error = s21_from_decimal_to_int(input, output);
  ck_assert_ptr_eq(output, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  s21_decimal input = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001A0000}};
  int output = 123;
  int error = s21_from_decimal_to_int(input, &output);
  ck_assert_int_eq(output, 792);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  s21_decimal input = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00080000}};
  int output = 123;
  int error = s21_from_decimal_to_int(input, &output);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_5) {
  s21_decimal input = {{0xFFFFFFFF, 0, 0, 0}};
  int output = 123;
  int error = s21_from_decimal_to_int(input, &output);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_6) {
  s21_decimal input = {{0xFFFF0000, 0xEB0B0, 0, 0x800A0000}};
  int output = 123;
  int error = s21_from_decimal_to_int(input, &output);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(output, -413492);
}
END_TEST

START_TEST(s21_from_decimal_to_int_7) {
  s21_decimal input = {{0xFFFF0000, 0xAB0BA, 0xEB0B0, 0x800A0000}};
  int output = 123;
  int error = s21_from_decimal_to_int(input, &output);
  ck_assert_int_eq(error, 1);
}
END_TEST

Suite *suite_s21_converters() {
  Suite *suite = suite_create("s21_converters");
  TCase *tcase = tcase_create("s21_converters");

  tcase_add_test(tcase, s21_from_int_to_decimal_1);
  tcase_add_test(tcase, s21_from_int_to_decimal_2);
  tcase_add_test(tcase, s21_from_int_to_decimal_3);
  tcase_add_test(tcase, s21_from_int_to_decimal_4);
  tcase_add_test(tcase, s21_from_int_to_decimal_5);

  tcase_add_test(tcase, s21_from_decimal_to_float_1);
  tcase_add_test(tcase, s21_from_decimal_to_float_2);
  tcase_add_test(tcase, s21_from_decimal_to_float_3);
  tcase_add_test(tcase, s21_from_decimal_to_float_4);
  tcase_add_test(tcase, s21_from_decimal_to_float_5);
  tcase_add_test(tcase, s21_from_decimal_to_float_6);

  tcase_add_test(tcase, s21_from_float_to_decimal_1);
  tcase_add_test(tcase, s21_from_float_to_decimal_2);
  tcase_add_test(tcase, s21_from_float_to_decimal_3);
  tcase_add_test(tcase, s21_from_float_to_decimal_4);
  tcase_add_test(tcase, s21_from_float_to_decimal_5);
  tcase_add_test(tcase, s21_from_float_to_decimal_6);
  tcase_add_test(tcase, s21_from_float_to_decimal_7);
  tcase_add_test(tcase, s21_from_float_to_decimal_8);
  tcase_add_test(tcase, s21_from_float_to_decimal_9);
  tcase_add_test(tcase, s21_from_float_to_decimal_10);
  tcase_add_test(tcase, s21_from_float_to_decimal_11);
  tcase_add_test(tcase, s21_from_float_to_decimal_12);
  tcase_add_test(tcase, s21_from_float_to_decimal_13);
  tcase_add_test(tcase, s21_from_float_to_decimal_14);

  tcase_add_test(tcase, s21_from_decimal_to_int_1);
  tcase_add_test(tcase, s21_from_decimal_to_int_2);
  tcase_add_test(tcase, s21_from_decimal_to_int_3);
  tcase_add_test(tcase, s21_from_decimal_to_int_4);
  tcase_add_test(tcase, s21_from_decimal_to_int_5);
  tcase_add_test(tcase, s21_from_decimal_to_int_6);
  tcase_add_test(tcase, s21_from_decimal_to_int_7);

  suite_add_tcase(suite, tcase);
  return suite;
}
