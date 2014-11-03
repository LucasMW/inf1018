#include <ctype.h>
#include <stdio.h>

int string2num (char *s) {
  int a = 0;
  for (; *s; s++) //percorra a string
    a = a*10 + (*s - '0'); // o inteiro a retornar é o inteiro anterior*10 + o próximo algarismo
  return a;
}

int main (void) {
  printf("==> %d\n", string2num("01234"));
  printf("==> %d\n", string2num("01234") + 1);
  printf("==> %d\n", string2num("01234") + string2num("1"));
  return 0;
}
