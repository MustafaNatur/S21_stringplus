#include <string.h>

#include "s21_string.h"

// failed testcase
// char *str1 = "abobus";
// char *str2 = "basuo";

s21_size_t s21_strspn(const char* str1, const char* str2) {
  s21_size_t count = 0;
  s21_size_t i = 0;
  s21_size_t j = 0;
  while (str1[i] != '\0') {
    j = 0;
    while (str2[j] != '\0') {
      if (str1[i] == str2[j]) {
        // printf("abob ");
        count++;
        break;
      }
      j++;
    }
    if (str2[j] == '\0') break;
    i++;
  }
  return count;
}
