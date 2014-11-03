#include<stdio.h>
unsigned int mul (unsigned int a, unsigned int b) {
  unsigned int p = 0;
  while (b) {
    if (b&1) //bit 1 na última posição
      p += a;
    a=a << 1; // a*=2;
    b =b>>1; //  b/=2;
  }
  return p;
}
int main (void)
{
int a=105;
int b=40;
	printf("%d\n",mul(a,b));
return 0;
}
