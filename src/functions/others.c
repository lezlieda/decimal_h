#include "../s21_decimal.h"

/*
 * Возвращаемое значение - код ошибки:
 *    0 - OK
 *    1 - ошибка вычисления
 */

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  int sign = get_dec_sign(value);
  if (!sign) {
    s21_truncate(value, result);
  } else {
    s21_decimal one = {{1, 0, 0, 0}};
    s21_truncate(value, result);
    if (s21_is_equal(value, *result) == FALSE)
      error = s21_sub(*result, one, result);
  }
  if (error) error = CALCULATION_ERROR;
  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  int sign = get_dec_sign(value);
  value.bits[3] &= 0x7FFFFFFF;
  s21_truncate(value, result);
  s21_decimal temp = {0};
  s21_decimal half = {{5, 0, 0, 0x10000}};
  s21_sub(value, *result, &temp);
  if (s21_is_greater_or_equal(temp, half) == TRUE) {
    s21_decimal one = {{1, 0, 0, 0}};
    error = s21_add(*result, one, result);
  }
  if (sign) s21_negate(*result, result);
  if (error) error = CALCULATION_ERROR;
  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  int sign = get_dec_sign(value);
  int scale = get_dec_scale(value);
  s21_bigdecimal val = {0};
  decimal_to_bigdec(value, &val);
  val.bits[7] &= 0x7FFFFFFF;
  while (scale > 0) {
    bigdec_div_by_10(&val);
    scale--;
  }
  set_bigdec_sign(&val, sign);
  error = bigdec_to_decimal(val, result);
  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = OK;
  *result = (s21_decimal){0};
  *result = value;
  result->bits[3] ^= 0x80000000;
  return error;
}
