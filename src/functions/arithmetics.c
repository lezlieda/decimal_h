#include "../s21_decimal.h"
/*
 *  Функции возвращают код ошибки:
 *  0 - OK
 *  1 - число слишком велико или равно бесконечности
 *  2 - число слишком мало или равно отрицательной бесконечности
 *  3 - деление на 0
 */

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  s21_bigdecimal val_1 = (s21_bigdecimal){0};
  s21_bigdecimal val_2 = (s21_bigdecimal){0};
  s21_bigdecimal val_r = (s21_bigdecimal){0};
  int sign_1 = get_dec_bit(value_1, 127);
  int sign_2 = get_dec_bit(value_2, 127);
  decimal_to_bigdec(value_1, &val_1);
  decimal_to_bigdec(value_2, &val_2);
  scale_equilizer_bigdec(&val_1, &val_2);
  int scale = get_bigdec_scale(val_1);
  set_bigdec_sign(&val_1, 0);
  set_bigdec_sign(&val_2, 0);
  int bigger = is_greater_or_equal_bigdec(val_1, val_2);
  if (sign_1 ^ sign_2) {
    if (bigger) {
      sub_bigdec_noscale(val_1, val_2, &val_r);
      set_bigdec_sign(&val_r, sign_1);
    } else {
      sub_bigdec_noscale(val_2, val_1, &val_r);
      set_bigdec_sign(&val_r, sign_2);
    }
  } else {
    add_bigdec_noscale(val_1, val_2, &val_r);
    set_bigdec_sign(&val_r, sign_1);
  }
  set_bigdec_scale(&val_r, scale);
  scale_checker(&val_r);
  bigdec_mantissa_round(&val_r);
  error = bigdec_to_decimal(val_r, result);
  if (error == TOO_BIG && get_bigdec_sign(val_r)) error = TOO_SMALL;
  if (error) *result = (s21_decimal){0};
  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  s21_decimal tmp_2 = value_2;
  tmp_2.bits[3] ^= 0x80000000;
  error = s21_add(value_1, tmp_2, result);
  return error;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  int sign = get_dec_sign(value_1) ^ get_dec_sign(value_2);
  int scale = get_dec_scale(value_1) + get_dec_scale(value_2);
  value_1.bits[3] = 0;
  value_2.bits[3] = 0;
  s21_bigdecimal val_1 = {0};
  s21_bigdecimal val_2 = {0};
  s21_bigdecimal val_r = {0};
  decimal_to_bigdec(value_1, &val_1);
  decimal_to_bigdec(value_2, &val_2);
  bigdec_mul_noscale(val_1, val_2, &val_r);
  set_bigdec_scale(&val_r, scale);
  s21_bigdecimal min = {{1, 0, 0, 0, 0, 0, 0, 0x1C0000}};
  if (is_less_bigdec(val_r, min)) error = TOO_SMALL;
  if (!error) {
    bigdec_mantissa_round(&val_r);
    scale_checker(&val_r);
    set_bigdec_sign(&val_r, sign);
    error = bigdec_to_decimal(val_r, result);
    if (error == TOO_BIG && get_bigdec_sign(val_r)) error = TOO_SMALL;
  }
  if (error) *result = (s21_decimal){0};
  return error;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  if (is_dec_zero(value_2)) return DIV_BY_ZERO;
  s21_bigdecimal val_1 = {0};
  s21_bigdecimal val_2 = {0};
  s21_bigdecimal val_r = {0};
  int sign = get_dec_sign(value_1);
  decimal_to_bigdec(value_1, &val_1);
  decimal_to_bigdec(value_2, &val_2);
  set_bigdec_sign(&val_1, 0);
  set_bigdec_sign(&val_2, 0);
  if (is_less_bigdec(val_1, val_2)) {
    *result = value_1;
  } else if (is_not_equal_bigdec(val_1, val_2)) {
    scale_equilizer_bigdec(&val_1, &val_2);
    int scale = get_bigdec_scale(val_1);
    set_bigdec_scale(&val_1, 0);
    set_bigdec_scale(&val_2, 0);
    bigdec_div_int(val_1, val_2, &val_r);
    bigdec_mul_noscale(val_r, val_2, &val_r);
    sub_bigdec_noscale(val_1, val_r, &val_r);
    set_bigdec_scale(&val_r, scale);
    bigdec_mantissa_round(&val_r);
    scale_checker(&val_r);
    error = bigdec_to_decimal(val_r, result);
  }
  set_dec_sign(result, sign);
  return error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  if (is_dec_zero(value_2)) return DIV_BY_ZERO;
  s21_bigdecimal val_1 = {0};
  s21_bigdecimal val_2 = {0};
  s21_bigdecimal val_r = {0};
  int sign = get_dec_sign(value_1) ^ get_dec_sign(value_2);
  decimal_to_bigdec(value_1, &val_1);
  decimal_to_bigdec(value_2, &val_2);
  set_bigdec_sign(&val_1, 0);
  set_bigdec_sign(&val_2, 0);
  scale_equilizer_bigdec(&val_1, &val_2);
  for (int i = 0; i < 28; i++) {
    bigdec_mul_by_10(&val_1);
  }
  set_bigdec_scale(&val_1, 0);
  set_bigdec_scale(&val_2, 0);
  bigdec_div_int(val_1, val_2, &val_r);
  set_bigdec_scale(&val_r, 28);
  bigdec_mantissa_round(&val_r);
  scale_checker(&val_r);
  error = bigdec_to_decimal(val_r, result);
  if (error == TOO_BIG && sign) error = TOO_SMALL;
  set_dec_sign(result, sign);
  if (error) *result = (s21_decimal){0};
  return error;
}
