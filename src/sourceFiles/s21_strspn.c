#include <string.h>

#include "s21_string.h"

// failed testcase
// char *str1 = "abobus";
// char *str2 = "basuo";

s21_size_t s21_strspn(const char* str1, const char* str2) {
  s21_size_t count = 0;
  while (*str1 != '\0') {
    while (*str2 != '\0') {
      if (*str1 == *str2) {
        printf("abob ");
        count++;
        break;
      }
      str2++;
    }
    str1++;
  }
  return count;
}
