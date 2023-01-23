#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  // va_list va;
  // va_start(va, str);
  flag flags = {0};
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&flags, 0, sizeof(flag));
      get_opt(format, &flags);
    }
  }
}

void *get_opt(const char *format, flag *flags) {
  format = get_flags(format, flags);
  format = get_width(format, flags);
  format = get_prec(format, flags);
  // format = get_length(format, flags);
}

char *get_flags(const char *format, flag *flags) {
  char *ptr = (char *)format;
  while (*ptr == '+' || *ptr == '-') {
    ptr++;
    switch (*ptr) {
      case '+':
        flags->plus = 1;
        break;
      case '-':
        flags->minus = 1;
        break;
    }
  }
}

char *get_width(const char *format, flag *flags) {
  char *ptr = (char *)format;
  if (*ptr >= '0' && *ptr <= '9') flags->width = s21_atoi(ptr);
  return ptr;
}

char *get_prec(const char *format, flag *flags) {
  char *ptr = (char *)format;
  if (*ptr == '.') {
    ptr++;
    flags->prec = s21_atoi(ptr);
  }
  return ptr;
}

int s21_atoi(char *str) {
  int res = 0;
  if (*str) {
    res = *str++ - '0';
    while (*str >= '0' && *str <= '9') {
      res = res * 10 + *str++ - '0';
    }
  }
  return res;
}