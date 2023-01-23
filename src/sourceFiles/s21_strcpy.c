#include "s21_string.h"
char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

// The behavior is undefined if the dest array is not large enough. The behavior
// is undefined if the strings overlap. The behavior is undefined if either dest
// is not a pointer to a character array or src is not a pointer to a
// null-terminated byte string.