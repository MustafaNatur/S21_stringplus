#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_memchr_usual) {
  int size = 5;
  char str[5] = "abcd";
  for (int i = 0; i < size; i++) {
    ck_assert_pstr_eq(memchr(str, str[i], 5), s21_memchr(str, str[i], 5));
  }
}
END_TEST

START_TEST(test_s21_string_memchr_unusual){ck_assert_ptr_null(s21_memchr("abcd", 'c', 2));} END_TEST

    Suite *s21_math_pow_suite() {
  Suite *s;
  TCase *tc_memchr_usual, *tc_memchr_unusual;

  s = suite_create("memchr");

  tc_memchr_usual = tcase_create("memchr_usual");
  tcase_add_test(tc_memchr_usual, test_s21_string_memchr_usual);
  suite_add_tcase(s, tc_memchr_usual);

  tc_memchr_unusual = tcase_create("memchr_unusual");
  tcase_add_test(tc_memchr_unusual, test_s21_string_memchr_unusual);
  suite_add_tcase(s, tc_memchr_unusual);

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
