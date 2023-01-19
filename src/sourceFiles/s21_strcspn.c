#include <string.h>

#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < strlen(str1); i++) {
    for (s21_size_t j = 0; j < strlen(str2); j++) {
      if (str1[i] != str2[j] && flag == 0) {
        counter++;
        break;
      } else {
        flag = 1;
      }
    }
  }
  return counter;
}