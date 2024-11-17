#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = OK;
  if (dst == NULL) {
    error = CONVERT_ERROR;
  } else {
    *dst = (s21_decimal){0};
    dst->bits[0] = src;
    if (src < 0) {
      dst->bits[3] |= 1 << 31;
      dst->bits[0] = ~dst->bits[0] + 1;
    }
  }
  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = OK;
  if (dst == NULL) {
    error = CONVERT_ERROR;
  } else {
    *dst = 0;
    int scale = get_dec_scale(src);
    long double data = 0;
    unsigned int tmp = 0;
    for (int i = 0; i < 3; i++) {
      tmp = 0xFFFFFFFF & src.bits[i];
      data += tmp * pow(2, 32 * i);
    }
    data /= pow(10, scale);
    if (get_dec_sign(src)) {
      data = -data;
      if (data == 0) data = -0.;
    }
    *dst = (float)data;
  }
  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = OK;
  if (dst == NULL) {
    error = CONVERT_ERROR;
  } else {
    *dst = 0;
    int sign = get_dec_sign(src);
    s21_decimal trun = {0};
    s21_truncate(src, &trun);
    if (trun.bits[2] || trun.bits[1] || get_dec_bit(trun, 31)) {
      error = CONVERT_ERROR;
    } else {
      *dst = trun.bits[0];
      if (sign) *dst = -*dst;
    }
  }
  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = OK;
  if (dst == NULL) return CONVERT_ERROR;
  *dst = (s21_decimal){0};
  if ((fabsf(src) < MIN_DECIMAL && src != 0) || fabsf(src) > MAX_DECIMAL ||
      src != src)
    return CONVERT_ERROR;
  s21_bigdecimal tmp = {0};
  int sign = 1 / src < 0;
  float abs_src = fabs(src);
  char buf[64];
  sprintf(buf, "%.28f", abs_src);
  long double data = 0;
  sscanf(buf, "%Lf", &data);
  sprintf(buf, "%Le", data);
  char num[16];
  char exp[4];
  num[0] = buf[0];
  for (int i = 1; i < 7; i++) {
    num[i] = buf[i + 1];
  }
  num[7] = '\0';
  for (int i = 0; i < 3; i++) {
    exp[i] = buf[i + 9];
  }
  exp[3] = '\0';
  int exponent = atoi(exp) - 6;
  tmp.bits[0] = atoi(num);
  if (exponent > 0) {
    while (exponent--) {
      bigdec_mul_by_10(&tmp);
      tmp.bits[7] -= 0x10000;
    }
  } else {
    set_bigdec_scale(&tmp, -exponent);
  }
  scale_checker(&tmp);
  set_bigdec_sign(&tmp, sign);
  bigdec_to_decimal(tmp, dst);
  return error;
}
