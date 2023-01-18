#include "s21_string.h"
size_t s21_strlen(const char *str) {
  size_t i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}

int s21_strcmp(const char *left, const char *right) {
  int ret = 1, i = 0;
  while (left[i] != '\0' && right[i] != '\0') {
    if (left[i] != right[i]) {
      ret = 0;
      break;
    }
    i++;
  }
  if (left[i] != '\0' || right[i] != '\0') {
    ret = 0;
  }
  return ret;
}

char *s21_strcpy(char *copy, const char *orig) {
  int i = 0;
  while (orig[i] != '\0') {
    copy[i] = orig[i];
    i++;
  }
  copy[i] = '\0';
  return copy;
}

char *s21_strcat(char *dest, char *source) {
  int i = 0, j = 0;
  while (dest[i] != '\0')
    i++;
  while (source[j] != '\0') {
    dest[i] = source[j];
    j++;
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strchr(char *str, int character) {
  int i = 0;
  char *pointer = NULL;
  while (str[i] != '\0') {
    if ((int)(str[i]) == character) {
      pointer = &str[i];
      break;
    }
    i++;
  }
  if (character == 0 && pointer == NULL) {
    pointer = &str[i];
  }
  return pointer;
}

char *s21_strstr(char *toSearch, const char *toFind) {
  int i = 0;
  char *pointer = NULL;
  while (toSearch[i] != '\0' && pointer == NULL) {
    if (toSearch[i] == toFind[0]) {
      pointer = &toSearch[i];
      int j = 0, k = i;
      while (toFind[j] != '\0' && toSearch[k] != '\0') {
        if (toSearch[k] != toFind[j]) {
          pointer = NULL;
          break;
        }
        k++;
        j++;
      }
      if (toFind[j] != '\0')
        pointer = NULL;
    }
    i++;
  }
  return pointer;
}

char *s21_strtok(char *toSplit, const char *delim) {
  int i = 0, flagWasNull = 0;
  static char *last;
  char *pointer = NULL;
  if (toSplit == NULL)
    flagWasNull = 1;
  if (toSplit != NULL && last != NULL)
    last = NULL;
  if (!(toSplit == NULL && last == NULL)) {
    if (toSplit == NULL && last != NULL) {
      toSplit = last;
    }
    int skipsDone = 0;
    while (!skipsDone && toSplit[i] != '\0') {
      int j = 0, skipFlag = 0;
      while (delim[j] != '\0') {
        if (toSplit[i] == delim[j]) {
          skipFlag = 1;
          break;
        }
        j++;
      }
      if (skipFlag) {
        i++;
      } else {
        skipsDone = 1;
      }
    }
    if (toSplit[i] != '\0')
      pointer = &toSplit[i];
    while (toSplit[i] != '\0') {
      int j = 0, stopFlag = 0;
      while (delim[j] != '\0') {
        if (toSplit[i] == delim[j]) {
          toSplit[i] = '\0';
          last = &toSplit[i + 1];
          stopFlag = 1;
          break;
        }
        j++;
      }
      if (stopFlag)
        break;
      i++;
      if (!stopFlag && toSplit[i] == '\0') {
        last = NULL;
      }
    }
  }
  if (last != NULL && !flagWasNull) {
    if (*last == '\0')
      last = NULL;
  }
  if (pointer == NULL)
    last = NULL;
  return pointer;
}
