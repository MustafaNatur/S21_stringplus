#include <stdio.h>
#include <string.h>
#include "../sourceFiles/s21_string.h"

int main() {
  char *str = "\0";
  int c = '\0';
  printf("%s", s21_strrchr(str, c));
  printf("%s", "\0");
  return 0;
}