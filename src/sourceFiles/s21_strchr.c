#include "string.h"

char *s21_strchr(const char *str, int symbol) {
  for (; *str != '\0'; ++str)
    if (*str == symbol) return (char *)str;
  return s21_NULL;
}