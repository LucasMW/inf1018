#include <stdio.h>

int add1 (int *a, int n);

int main (void) {
	int i;
   int a[10];
	for(i=0;i<10;i++)
	a[i]=i+1;
   printf("%d\n", add1(a,10));
   return 0;
}
