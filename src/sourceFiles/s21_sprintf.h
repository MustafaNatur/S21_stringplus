typedef struct flags {
  char plus;
  char minus;
  // ШИРИНА
  int width;
  // ТОЧНОСТЬ
  int prec;
  // ДЛИНА
  char h; /* Аргумент интерпретируется как короткое int или короткое int без
            знака (применяется только к целочисленным спецификаторам: i, d, o,
            u, x и X). */
  char l; /* Аргумент интерпретируется как длинное int или длинное int без знака
           для целочисленных спецификаторов (i, d, o, u, x и X) и как широкий
           символ или строка широких символов для спецификаторов c и s. */
          // СПЕЦИФИКАТОРЫ
  char c;  // Символ
  char d;  // Знаковое десятичное целое число
  char i;  // Знаковое десятичное целое число
  char f;  // Десятичное число с плавающей точкой
  char s;  // Строка символов
  char u;  // Беззнаковое десятичное целое число
} flag;

char *get_opt(char *format, flag *flags);
char *get_flags(char *format, flag *flags);
char *get_width(char *format, flag *flags);
int s21_atoi(char *str);