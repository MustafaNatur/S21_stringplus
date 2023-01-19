typedef unsigned long long s21_size_t;
#define s21_NULL ((void *)0)

// http://microsin.net/programming/arm/void-type-in-c-language.html гайд про
// void * https://pvs-studio.com/ru/blog/terms/0088/ про терминирующий 0
// http://natalia.appmat.ru/c&c++/lezione5.php обо всем по чуть-чуть

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
