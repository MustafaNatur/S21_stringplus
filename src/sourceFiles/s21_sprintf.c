#include "s21_sprintf.h"

#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n);
s21_size_t s21_strlen(const char *str);

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
      get_opt(format, &flags);
    }
  }
}

void *get_opt(const char *format, flag *flags) {
  s21_memset(&flags, 0, sizeof(flag));
  format = get_flags(format, flags);
  format = get_width(format, flags);
  format = get_prec(format, flags);
  // format = get_length(format, flags);
}

char *get_flags(const char *format, flag *flags) {
  char *ptr = (char *)format;
  while (*ptr == '+' || *ptr == '-') {
    switch (*ptr) {
      case '+':
        flags->plus = 1;
        break;
      case '-':
        flags->minus = 1;
        break;
      case 'd':
        flags->d = 1;
        break;
    }
    ptr++;
  }
  return ptr;
}
char *str_processing(const char *format, flag *flags) {}
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

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str && s21_strlen(str) >= n) {
    char *buf = (char *)str;
    while (n--) *buf++ = c;  // Пока n > 0 и при этом n уменьшается
  }
  return str;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t strlen = 0;
  while (*str++) strlen++;
  return strlen;
}

int main() {
  char str[100];
  int a = 5;
  int b = 4;
  s21_sprintf(str, "%d abobus %d", a, b);
  //  printf("%s", str);
  return 0;
}