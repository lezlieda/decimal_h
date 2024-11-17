#ifndef SUITECASES_H
#define SUITECASES_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

Suite *suite_s21_converters();
Suite *suite_s21_comparison();
Suite *suite_s21_others();
Suite *suite_s21_arithmetics();
Suite *test_from_float_to_decimal(void);
Suite *s21_decimal_suite(void);

#endif  // SUITECASES_H
