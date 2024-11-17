#include "s21_decimal.h"
#include "suitecases.h"

void run_testcase(Suite *testcase) {
  SRunner *runner = srunner_create(testcase);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}

void run_all_testcases() {
  Suite *list_cases[] = {suite_s21_converters(), suite_s21_comparison(),
                         suite_s21_others(), suite_s21_arithmetics(),
                         //  test_from_float_to_decimal(),
                         s21_decimal_suite(), NULL};
  for (int i = 0; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main() {
  run_all_testcases();
  /*

  s21_decimal src1, src2, result, origin;
  // 30064771176
  // 3
  // 10021590392
  src1.bits[0] = 0x0006BFD0;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000028;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  float f1, f2, fres, fori;
    s21_from_decimal_to_float(src1, &f1);
    s21_from_decimal_to_float(src2, &f2);
    s21_from_decimal_to_float(result, &fres);
    s21_from_decimal_to_float(origin, &fori);

    printf("f1 = %f; src1.bits:\n", f1);
    print_decimal_bits(src1);
    printf("f2 = %f; src2.bits:\n", f2);
    print_decimal_bits(src2);
    printf("fres = %f; result.bits:\n", fres);
    print_decimal_bits(result);
    printf("fori = %f; origin.bits:\n", fori);
    print_decimal_bits(origin);
    printf("check = %d\n", check);
  */
  return 0;
}

// 2.54395200000