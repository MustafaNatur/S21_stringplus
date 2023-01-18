#include "s21_string.h"

int strncmp(const char *str1, const char *str2, s21_size_t n) {
  int ret = 1, i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      ret = 0;
      break;
    }
    i++;
  }
  if (str1[i] != '\0' || str2[i] != '\0') {
    ret = 0;
  }
  return ret;
}

int s21_strcmp(const char *left, const char *right) {
  int ret = 1, i = 0;
  while (left[i] != '\0' && right[i] != '\0') {
    if (left[i] != right[i]) {
      ret = 0;
      break;
    }
    i++;
  }
  if (left[i] != '\0' || right[i] != '\0') {
    ret = 0;
  }
  return ret;
}