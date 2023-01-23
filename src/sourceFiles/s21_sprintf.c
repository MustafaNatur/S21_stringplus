#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  flag flags = {0};
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      // format++;
      s21_memset(&flags, 0, sizeof(flag));
      get_opt(format, &flags);
    }
  }
}

char *get_opt(char *format, flag *flags) {
  format = get_flags(format, &flags);
  format = get_width(format, &flags);
  format = get_prec(format, &flags);
  format = get_length(format, &flags);
  return format;
}

char *get_flags(char *format, flag *flags) {
  while (*format == '+' || *format == '-') {
    format++;
    switch (*format) {
      case '+':
        flags->plus = 1;
        break;
      case '-':
        flags->minus = 1;
        break;
    }
  }
}

char *get_width(char *format, flag *flags) {
  while ((int)*format == *format) {
    switch (*format) {
      case '+':
        flags->plus = 1;
        break;
      case '-':
        flags->minus = 1;
        break;
    }
  }
}

int s21_atoi(char *str) {
  int length = s21_strlen(str);
  int res = 0;
  for (; length > 0; length--, str++) {
    res += *str * pow(10, length - 1);
  }
  return res;
}