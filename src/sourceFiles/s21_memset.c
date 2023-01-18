#include <../s21_string.h>

void *s21_memset(void *str, int c, s21_size_t n) {
  if (strlen(str) >= n) {
    for (s21_size_t i = 0; i < n; i++) {
      *str[i] = c;
    }
  }
}