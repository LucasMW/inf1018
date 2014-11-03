#include<stdio.h>
    struct X1 {
      char c1;
      int i;
      char c2;
    };

    struct X2 {
      int i;
      char c;
    };

    struct X3 {
      int i;
      char c1;
      char c2;
    };

    struct X4 {
      struct X2 x;
      char c;
    };

    struct X5 {
      char c1;
      char c2;
      char c3;
    };

    struct X6 {
      short s1;
      int i;
      char c[3];
      short s2;
    };

    union U1 {
      int i;
      char c[5];
    };

    union U2 {
      short s;
      char c[5];
    };

void dump (void *p, int n)
 {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void)
{
struct X1 x1;
x1.c=0xc1;
x1.i=0xa1a2a3a4;
x1.c2=0xc2;
dump(&x,sizeof(x));
printf("%i\n",sizeof(X));
}




