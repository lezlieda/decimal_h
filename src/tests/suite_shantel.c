#include "../s21_decimal.h"
#include "../suitecases.h"

START_TEST(test_s21_add_1) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(1899999, &test_value_1);
  s21_from_int_to_decimal(100001, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 2000000);
}
END_TEST

START_TEST(test_s21_add_2) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(199421, &test_value_1);
  s21_from_int_to_decimal(-4433, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 199421 + (-4433));
}
END_TEST

START_TEST(test_s21_add_3) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(-199421, &test_value_1);
  s21_from_int_to_decimal(4433, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -199421 + 4433);
}
END_TEST

START_TEST(test_s21_add_4) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(-199421, &test_value_1);
  s21_from_int_to_decimal(-4433, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -199421 + (-4433));
}
END_TEST

START_TEST(test_s21_add_5) {
  s21_decimal test_value_1 = {{10000, 3, 10, 0}};
  s21_decimal test_value_2 = {{5000, 2, 500, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_value_1, test_value_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 10000 + 5000);
  ck_assert_uint_eq(result_dec.bits[1], 3 + 2);
  ck_assert_uint_eq(result_dec.bits[2], 10 + 500);
}
END_TEST

START_TEST(test_s21_add_6) {
  s21_decimal test_value_1 = {{4294967295, 10, 10, 0}};
  s21_decimal test_value_2 = {{1, 2, 20, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_value_1, test_value_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 0);
  ck_assert_uint_eq(result_dec.bits[1], 13);
  ck_assert_uint_eq(result_dec.bits[2], 30);
}
END_TEST

START_TEST(test_s21_add_7) {
  s21_decimal test_value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal test_value_2 = {{1, 1, 1, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = s21_add(test_value_1, test_value_2, &result_dec);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_add_9) {
  s21_decimal test_value_1 = {{123, 0, 0, 262144}};
  s21_decimal test_value_2 = {{37, 0, 0, 196608}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_value_1, test_value_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 493);
  ck_assert_uint_eq(result_dec.bits[3], 262144);
}
END_TEST

START_TEST(test_s21_add_11) {
  s21_decimal src1, src2, result;
  int a = -1234;
  float b = 1.234;
  float res_origin = -1232.766;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_12) {
  s21_decimal src1, src2, result;
  int a = -1234;
  float b = -1.234;
  float res_origin = -1235.234;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_13) {
  s21_decimal src1, src2, result;
  float a = -1234;
  float b = -221.234;
  float res_origin = -1455.234;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_14) {
  s21_decimal src1, src2, result;
  float a = -9403;
  float b = 0.00234;
  float res_origin = -9402.99766;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_15) {
  s21_decimal src1, src2, result;
  float a = -940.3;
  float b = 0.000234;
  float res_origin = -940.299766;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_16) {
  s21_decimal src1, src2, result;
  float a = -0.9403;
  float b = 0.000234;
  float res_origin = -0.940066;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_17) {
  s21_decimal src1, src2, result;
  float a = -0.9403;
  float b = 2.0234;
  float res_origin = 1.0831;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_18) {
  s21_decimal src1, src2, result;
  float a = -0.9403;
  float b = -112.0234;
  float res_origin = -112.9637;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_19) {
  s21_decimal src1, src2, result;
  float a = -0.94e03;
  float b = -112.0234;
  float res_origin = -1052.0234;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_20) {
  s21_decimal src1, src2, result;
  float a = -0.94e03;
  float b = -112.0e2;
  float res_origin = -12140;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_21) {
  s21_decimal src1, src2, result;
  src1.bits[3] = 0x30000;
  src1.bits[2] = 0;
  src1.bits[1] = 0xF;
  src1.bits[0] = 0x67E4FEEF;
  src2.bits[3] = 0x30000;
  src2.bits[2] = 0;
  src2.bits[1] = 0xFF;
  src2.bits[0] = 0x67E4FFFF;
  s21_decimal result_origin;
  result_origin.bits[3] = 0x30000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0x10E;
  result_origin.bits[0] = 0xCFC9FEEE;
  s21_add(src1, src2, &result);
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_add_22) {
  s21_decimal src1, src2, result;
  src1.bits[3] = 0x30000;
  src1.bits[2] = 0;
  src1.bits[1] = 0xFF;
  src1.bits[0] = 0x67E4F;
  src2.bits[3] = 0x60000;
  src2.bits[2] = 0;
  src2.bits[1] = 0xEA;
  src2.bits[0] = 0x67E4F;
  s21_decimal result_origin;
  result_origin.bits[3] = 0x60000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0x3E502;
  result_origin.bits[0] = 0x1963E2E7;
  s21_add(src1, src2, &result);
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_sub_1) {
  s21_decimal src1, src2, result;
  int a = 9403;
  int b = 202;
  int res_origin = 9201;
  int res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our);
  ck_assert_int_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_2) {
  s21_decimal src1, src2, result;
  int a = 9403;
  float b = 202.098;
  float res_origin = 9200.902;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_3) {
  s21_decimal src1, src2, result;
  float a = -9403;
  float b = 202.098;
  float res_origin = a - b;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_6) {
  s21_decimal src1, src2, result;
  float a = -9403.0e2;
  int b = -202;
  float res_origin = a - b;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_7) {
  s21_decimal src1, src2, result;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src1.bits[2] = 0;
  src1.bits[1] = 0;
  src1.bits[0] = 0b00000000000000000110011011110000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[2] = 0;
  src2.bits[1] = 0;
  src2.bits[0] = 0b00000000000001000101000111010110;
  s21_decimal result_origin;
  result_origin.bits[3] = 0b00000000000000110000000000000000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[0] = 0b00000000001000111110001111101010;
  s21_sub(src1, src2, &result);
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_mul_1) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = 9403.0e2;
  int b = 202;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  float res_origin = 189940600;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(test_s21_mul_2) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = 9403.0e2;
  float b = 9403.0e2;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = 884164090000;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(test_s21_mul_3) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = 9403;
  float b = 202;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = 1899406;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(test_s21_mul_4) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = -32768;
  float b = 2;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = -65536;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(test_s21_mul_5) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = -32768;
  float b = 32768;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = -1073741824;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(test_s21_mul_6) {
  s21_decimal src1 = {{0, 1, 0, 0}};
  s21_decimal src2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float res_our_dec = 0.0;
  float res_origin = 4294967296;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(test_s21_mul_7) {
  s21_decimal src1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal src2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_mul(src1, src2, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_mul_8) {
  s21_decimal src1 = {{4294967295, 4294967295, 4294967295, 2147483648}};
  s21_decimal src2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_mul(src1, src2, &result);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(test_s21_mul_10) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  float n1 = -5.6e-15;
  float n2 = 1.5e-15;
  s21_from_float_to_decimal(n1, &val1);
  s21_from_float_to_decimal(n2, &val2);
  // int r = s21_mul(val1, val2, &res);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
}
END_TEST

START_TEST(test_s21_div_2) {
  s21_decimal src1 = {{25, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_div(src1, src2, &result);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(test_s21_mod_1) {
  s21_decimal src1 = {{1, 0, 0, 0}};
  s21_decimal src2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_mod(src1, src2, &result);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
}
END_TEST

START_TEST(test_s21_mod_2) {
  s21_decimal src1 = {{1, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_mod(src1, src2, &result);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(test_s21_is_less_1) {
  s21_decimal test_value_1 = {{10, 0, 0, 0}};
  s21_decimal test_value_2 = {{15, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2),
                   1);  // 10 < 15 = True
}
END_TEST

START_TEST(test_s21_is_less_2) {
  s21_decimal test_value_1 = {{6739, 0, 0, 0}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2),
                   1);  // 6739 < 19993 = True
}
END_TEST

START_TEST(test_s21_is_less_3) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{6739, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2),
                   0);  // 19993 < 6739 = False
}
END_TEST

START_TEST(test_s21_is_less_4) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{6739, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2),
                   0);  // 19993 < -6739 = False
}
END_TEST

START_TEST(test_s21_is_less_5) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2),
                   0);  // 19993 < 19993 = False
}
END_TEST

START_TEST(test_s21_is_less_6) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{19993, 0, 0, 131072}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2),
                   0);  // 19993 < 199,93 = False
}
END_TEST

START_TEST(test_s21_is_less_7) {
  s21_decimal test_value_1 = {{0, 1, 0, 0}};
  s21_decimal test_value_2 = {{
      19993,
      0,
      0,
  }};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2),
                   0);  // 4294967295 < 19993 = False
}
END_TEST

START_TEST(test_s21_is_less_8) {
  s21_decimal test_value_1 = {{19993, 1, 0, 2147483648}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2),
                   1);  // -19993 < 19993 = True
}
END_TEST

START_TEST(test_s21_is_less_or_equal_1) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2),
                   1);  // 0 <= 0 = True
}
END_TEST

START_TEST(test_s21_is_less_or_equal_2) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2),
                   1);  // 5000 <= 5001 = True
}
END_TEST

START_TEST(test_s21_is_less_or_equal_3) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2),
                   0);  // 5000 <= -5000 = False
}
END_TEST

START_TEST(test_s21_is_less_or_equal_4) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 131072}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2),
                   0);  // 5000 <= 50 = False
}
END_TEST

START_TEST(test_s21_is_less_or_equal_5) {
  s21_decimal test_value_1 = {{0, 1, 0, 0}};
  s21_decimal test_value_2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2),
                   1);  // 4294967295 <= 4294967295 = True
}
END_TEST

START_TEST(test_s21_is_greater_1) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 1);  // 1.2345 > 1.2 = True
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 0);  // 1.2 > 1.2345 = False
}
END_TEST

START_TEST(test_s21_is_greater_2) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(-1.2345, &dst1);
  s21_from_float_to_decimal(-1.2, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 0);  // -1.2345 > -1.2 = False
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 1);  // -1.2 > -1.2345 = True
}
END_TEST

START_TEST(test_s21_is_greater_3) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(-1.2, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 1);  // 1.2345 > -1.2 = True
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 0);  // -1.2 > 1.2345 = False
}
END_TEST

START_TEST(test_s21_is_greater_4) {
  s21_decimal dst1, dst2;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 0);  // 0.0 > 0.0 = False
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_1) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2),
                   1);  // 0 >= 0 = True
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_3) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 131072}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2),
                   1);  // 5000 >= 50 = True
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_4) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2),
                   1);  // 5000 >= -5000 = True
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_5) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2),
                   1);  // 5000 >= 5000 = True
}
END_TEST

START_TEST(test_s21_is_equal_1) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2),
                   1);  // 0 == 0 = True
}
END_TEST

START_TEST(test_s21_is_equal_3) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2),
                   0);  // 5000 == -5000 = False
}
END_TEST

START_TEST(test_s21_is_equal_4) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 131072}};
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2),
                   0);  // 5000 == 50 = False
}
END_TEST

START_TEST(test_s21_is_equal_5) {
  s21_decimal test_value_1 = {{5000, 1, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 2, 0}};
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2),
                   0);  // number1 == number2 = False
}
END_TEST

START_TEST(test_s21_is_not_equal_1) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2),
                   0);  // 0 != 0 = False
}
END_TEST

START_TEST(test_s21_is_not_equal_3) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2),
                   1);  // 5000 != -5000 = True
}
END_TEST

START_TEST(test_s21_is_not_equal_4) {
  s21_decimal test_value_1 = {{5000, 0, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 0, 131072}};
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2),
                   1);  // 5000 != 50 = True
}
END_TEST

START_TEST(test_s21_is_not_equal_5) {
  s21_decimal test_value_1 = {{5000, 1, 0, 0}};
  s21_decimal test_value_2 = {{5000, 0, 2, 0}};
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2),
                   1);  // number1 != number2 = True
}
END_TEST

START_TEST(test_s21_form_int_to_decimal_1) {
  s21_decimal result;
  s21_from_int_to_decimal(0, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_form_int_to_decimal_3) {
  s21_decimal result;
  s21_from_int_to_decimal(5000, &result);
  ck_assert_int_eq(result.bits[0], 5000);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_form_int_to_decimal_5) {
  s21_decimal result;
  s21_from_int_to_decimal(2147483647, &result);
  ck_assert_int_eq(result.bits[0], 2147483647);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_form_float_to_decimal_2) {
  s21_decimal result;
  s21_from_float_to_decimal(127.1234, &result);
  ck_assert_int_eq(result.bits[0], 1271234);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 262144);
}
END_TEST

START_TEST(test_s21_form_float_to_decimal_4) {
  s21_decimal result;
  s21_from_float_to_decimal(22.14836E+03, &result);
  ck_assert_int_eq(result.bits[0], 2214836);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 131072);
}
END_TEST

START_TEST(test_s21_form_float_to_decimal_7) {
  s21_decimal result;
  int res = s21_from_float_to_decimal(1.0 / 0.0, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_form_float_to_decimal_8) {
  s21_decimal result;
  int res = s21_from_float_to_decimal(-1.0 / 0.0, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_form_float_to_decimal_9) {
  s21_decimal result;
  int res = s21_from_float_to_decimal(0.0 / 0.0, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_decimal_to_int_1) {
  int number = 0;
  s21_decimal src = {{2147483647, 0, 0, 0}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 2147483647);
}
END_TEST

START_TEST(test_s21_decimal_to_int_2) {
  int number = 0;
  s21_decimal src = {{0, 0, 0, 0}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
}
END_TEST

START_TEST(test_s21_decimal_to_int_3) {
  int number = 0;
  s21_decimal src = {{5000, 0, 0, 2147483648}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -5000);
}
END_TEST

START_TEST(test_s21_decimal_to_float_1) {
  float number = 0.0;
  s21_decimal src = {{18122, 0, 0, 2147680256}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
}
END_TEST

START_TEST(test_s21_decimal_to_float_2) {
  float number = 0.0;
  s21_decimal src = {{1812, 0, 0, 2147483648}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
}
END_TEST

START_TEST(test_s21_decimal_to_float_3) {
  float number = 0.0;
  s21_decimal src = {{23450987, 0, 0, 2147745792}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -2345.0987);
}
END_TEST

START_TEST(test_s21_decimal_to_float_4) {
  float number = 0.0;
  s21_decimal src = {{4294967295, 4294967295, 0, 0}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
}
END_TEST

START_TEST(test_s21_floor_1) {
  s21_decimal value_1 = {{673988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(value_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_2) {
  s21_decimal value_1 = {{679988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(value_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_5) {
  s21_decimal value_1 = {{5, 1, 0, 131072}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(value_1, &result);
  ck_assert_float_eq(result.bits[0], 42949673);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_negate_2) {
  s21_decimal value_1 = {{155, 1, 1, 2147483648}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(value_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_truncate_1) {
  s21_decimal value_1 = {{673988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(value_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

Suite *s21_decimal_suite() {
  Suite *suite = suite_create("shantell_tests");
  TCase *tcase = tcase_create("shantell_tests");

  // tests_add
  tcase_add_test(tcase, test_s21_add_1);
  tcase_add_test(tcase, test_s21_add_2);
  tcase_add_test(tcase, test_s21_add_3);
  tcase_add_test(tcase, test_s21_add_4);
  tcase_add_test(tcase, test_s21_add_5);
  tcase_add_test(tcase, test_s21_add_6);
  tcase_add_test(tcase, test_s21_add_7);
  tcase_add_test(tcase, test_s21_add_9);
  tcase_add_test(tcase, test_s21_add_11);
  tcase_add_test(tcase, test_s21_add_12);
  tcase_add_test(tcase, test_s21_add_13);
  tcase_add_test(tcase, test_s21_add_14);
  tcase_add_test(tcase, test_s21_add_15);
  tcase_add_test(tcase, test_s21_add_16);
  tcase_add_test(tcase, test_s21_add_17);
  tcase_add_test(tcase, test_s21_add_18);
  tcase_add_test(tcase, test_s21_add_19);
  tcase_add_test(tcase, test_s21_add_20);
  tcase_add_test(tcase, test_s21_add_21);
  tcase_add_test(tcase, test_s21_add_22);

  // tests_sub
  tcase_add_test(tcase, test_s21_sub_1);
  tcase_add_test(tcase, test_s21_sub_2);
  tcase_add_test(tcase, test_s21_sub_3);
  tcase_add_test(tcase, test_s21_sub_6);
  tcase_add_test(tcase, test_s21_sub_7);

  // tests_mul
  tcase_add_test(tcase, test_s21_mul_1);
  tcase_add_test(tcase, test_s21_mul_2);
  tcase_add_test(tcase, test_s21_mul_3);
  tcase_add_test(tcase, test_s21_mul_4);
  tcase_add_test(tcase, test_s21_mul_5);
  tcase_add_test(tcase, test_s21_mul_6);
  tcase_add_test(tcase, test_s21_mul_7);
  tcase_add_test(tcase, test_s21_mul_8);
  tcase_add_test(tcase, test_s21_mul_10);

  // tests_mul
  tcase_add_test(tcase, test_s21_div_2);

  // tests_mod
  tcase_add_test(tcase, test_s21_mod_1);
  tcase_add_test(tcase, test_s21_mod_2);

  // tests_is_less
  tcase_add_test(tcase, test_s21_is_less_1);
  tcase_add_test(tcase, test_s21_is_less_2);
  tcase_add_test(tcase, test_s21_is_less_3);
  tcase_add_test(tcase, test_s21_is_less_4);
  tcase_add_test(tcase, test_s21_is_less_5);
  tcase_add_test(tcase, test_s21_is_less_6);
  tcase_add_test(tcase, test_s21_is_less_7);
  tcase_add_test(tcase, test_s21_is_less_8);

  // tests_is_less_or_equal
  tcase_add_test(tcase, test_s21_is_less_or_equal_1);
  tcase_add_test(tcase, test_s21_is_less_or_equal_2);
  tcase_add_test(tcase, test_s21_is_less_or_equal_3);
  tcase_add_test(tcase, test_s21_is_less_or_equal_4);
  tcase_add_test(tcase, test_s21_is_less_or_equal_5);

  // tests_is_greater
  tcase_add_test(tcase, test_s21_is_greater_1);
  tcase_add_test(tcase, test_s21_is_greater_2);
  tcase_add_test(tcase, test_s21_is_greater_3);
  tcase_add_test(tcase, test_s21_is_greater_4);

  // tests_is_greater_or_equal
  tcase_add_test(tcase, test_s21_is_greater_or_equal_1);
  tcase_add_test(tcase, test_s21_is_greater_or_equal_3);
  tcase_add_test(tcase, test_s21_is_greater_or_equal_4);
  tcase_add_test(tcase, test_s21_is_greater_or_equal_5);

  // tests_is_equal
  tcase_add_test(tcase, test_s21_is_equal_1);
  tcase_add_test(tcase, test_s21_is_equal_3);
  tcase_add_test(tcase, test_s21_is_equal_4);
  tcase_add_test(tcase, test_s21_is_equal_5);

  // tests_is_not_equal
  tcase_add_test(tcase, test_s21_is_not_equal_1);
  tcase_add_test(tcase, test_s21_is_not_equal_3);
  tcase_add_test(tcase, test_s21_is_not_equal_4);
  tcase_add_test(tcase, test_s21_is_not_equal_5);

  // tests_from_int_to_decimal
  tcase_add_test(tcase, test_s21_form_int_to_decimal_1);
  tcase_add_test(tcase, test_s21_form_int_to_decimal_3);
  tcase_add_test(tcase, test_s21_form_int_to_decimal_5);

  // tests_from_float_to_decimal
  tcase_add_test(tcase, test_s21_form_float_to_decimal_2);
  tcase_add_test(tcase, test_s21_form_float_to_decimal_4);
  tcase_add_test(tcase, test_s21_form_float_to_decimal_7);
  tcase_add_test(tcase, test_s21_form_float_to_decimal_8);
  tcase_add_test(tcase, test_s21_form_float_to_decimal_9);

  // tests_from_decimal_to_int
  tcase_add_test(tcase, test_s21_decimal_to_int_1);
  tcase_add_test(tcase, test_s21_decimal_to_int_2);
  tcase_add_test(tcase, test_s21_decimal_to_int_3);

  // tests_from_decimal_to_float
  tcase_add_test(tcase, test_s21_decimal_to_float_1);
  tcase_add_test(tcase, test_s21_decimal_to_float_2);
  tcase_add_test(tcase, test_s21_decimal_to_float_3);
  tcase_add_test(tcase, test_s21_decimal_to_float_4);

  //  test_floor
  tcase_add_test(tcase, test_s21_floor_1);
  tcase_add_test(tcase, test_s21_floor_2);
  tcase_add_test(tcase, test_s21_floor_5);

  // tests_negate
  tcase_add_test(tcase, test_s21_negate_2);

  // tests_truncate
  tcase_add_test(tcase, test_s21_truncate_1);

  suite_add_tcase(suite, tcase);

  return suite;
}
