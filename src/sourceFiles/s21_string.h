#ifndef SRC_SOURCEFILES_S21_STRING_H_
#define SRC_SOURCEFILES_S21_STRING_H_
typedef unsigned int s21_size_t;
#define s21_NULL ((void *)0)

#include <stdio.h>

char *s21_strrchr(const char *str, int c);

void *s21_memcpy(void *dest, const void *src,
                 s21_size_t n);  // Копирует n символов из src в dest.
void *s21_memmove(void *dest, const void *src,
                  s21_size_t n);  // Копирует n сиволов из src в dest с защитой
                                  // от потери данных.
int s21_memcmp(const void *str1, const void *str2,
               s21_size_t n);  // Сравнивает первые n байтов str1 и str2.
char *s21_strpbrk(
    const char *str1,
    const char *str2);  // Находит первый символ в строке str1, который
                        // соответствует любому символу, указанному в str2.

s21_size_t s21_strspn(
    const char *str1,
    const char *str2);  //Вычисляет длину начального сегмента str1,
                        //который полностью состоит из символов str2.

#endif  // SRC_SOURCEFILES_S21_STRING_H_
