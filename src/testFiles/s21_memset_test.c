#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_memset_normal) {
  int size = 5;
  char str[5] = "Hello world! Hello School 21!";
  int ch = '$';
  for (int i = 0; i < size; i++) {
    ck_assert_pstr_eq(memset(str, ch, 5), s21_memset(str, ch, 5));
  }
}
END_TEST

START_TEST(test_s21_string_memset_broke) {
  ck_assert_ptr_null(s21_memset("abcd", '$', 2));
}
END_TEST

Suite *s21_string_memset_suite() {
  Suite *s;
  TCase *tc_memset_normal, *tc_memset_broke;

  s = suite_create("memset");

  tc_memset_normal = tcase_create("memset_normal");
  tcase_add_test(tc_memset_normal, test_s21_string_memset_normal);
  suite_add_tcase(s, tc_memset_normal);

  tc_memset_broke = tcase_create("memset_broke");
  tcase_add_test(tc_memset_broke, test_s21_string_memset_broke);
  suite_add_tcase(s, tc_memset_broke);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_pow_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
