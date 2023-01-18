#include <string.h>

#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str && strlen(str) >= n) {
    char *buf = (char *)str;
    while (n--) *buf++ = c;
  }
  return str;
}
