#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int base) {
  int a = 0;
  for (; *s; s++) //percorra a string
	if(*s>=48&&*s<=57) //é numero
    a = a*base + (*s - '0'); // o inteiro a retornar é o inteiro anterior*base + o próximo algarismo
else 
if(*s>=65&&*s<=90) // letra maiuscula
a = a*base + (*s - 'A'+10);
else
if(*s>=97&&*s<=122) //letra minuscula
a = a*base + (*s - 'a'+10);
  return a;
}

int main (void) {
   printf("%d\n", string2num("777", 8));
  printf("%d\n", string2num("777", 10));
 printf("%d\n", string2num("1a", 16));
  printf("%d\n", string2num("a09b", 16));
  printf("%d\n", string2num("z09b", 36)); //base limite
  return 0;
}
