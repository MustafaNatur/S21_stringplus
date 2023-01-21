/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "srtspn.check" instead.
 */

#include <check.h>

// checkmk clean_mode=1 srtspn.check > s21_strspn_test.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"

START_TEST(s21_test_strspn_usual1)
{
char *str = "abobus";
char *sym = "boooooooooooooooooob";
ck_assert_int_eq(s21_strspn(str, sym), strspn(str, sym));

}
END_TEST

START_TEST(s21_test_strspn_usual2)
{
char *str = "privet";
char *sym = "privet";
ck_assert_int_eq(s21_strspn(str, sym), strspn(str, sym));

}
END_TEST

START_TEST(s21_test_strspn_usual3)
{
char *str = "abooooooooooooooooooooobus";
char *sym = "o";
ck_assert_int_eq(s21_strspn(str, sym), strspn(str, sym));

}
END_TEST

START_TEST(s21_test_strspn_usual4)
{
char *str = "abobus";
char *sym = "basuo";
ck_assert_int_eq(s21_strspn(str, sym), strspn(str, sym));

}
END_TEST

START_TEST(s21_test_strspn_unusual1)
{
char *str = "\0";
char *sym = "\0";
ck_assert_int_eq(s21_strspn(str, sym), strspn(str, sym));

}
END_TEST

START_TEST(s21_test_strspn_unusual2)
{
char str[6];
str[0] = 65;
str[1] = 66;
str[2] = 79;
str[3] = 66;
str[4] = 85;
str[5] = 83;

char *sym = "abobus";
ck_assert_int_eq(s21_strspn(str, sym), strspn(str, sym));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_test_strspn_usual1);
    tcase_add_test(tc1_1, s21_test_strspn_usual2);
    tcase_add_test(tc1_1, s21_test_strspn_usual3);
    tcase_add_test(tc1_1, s21_test_strspn_usual4);
    tcase_add_test(tc1_1, s21_test_strspn_unusual1);
    tcase_add_test(tc1_1, s21_test_strspn_unusual2);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
