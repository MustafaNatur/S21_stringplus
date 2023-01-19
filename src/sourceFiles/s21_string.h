#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long s21_size_t;
#define s21_NULL ((void *)0)

// http://microsin.net/programming/arm/void-type-in-c-language.html гайд про
// void * https://pvs-studio.com/ru/blog/terms/0088/ про терминирующий 0
// http://natalia.appmat.ru/c&c++/lezione5.php обо всем по чуть-чуть

void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strerror(int errnum);
