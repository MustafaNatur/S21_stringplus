#include <string.h>

#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *cur_char = "";
  if (*str != '\0' && c != '\0') {
    while (*str != '\0') {
      if (*str == c) {
        cur_char = (char *)str;
      }
      str++;
    }
  }
  return (char *)cur_char;
}