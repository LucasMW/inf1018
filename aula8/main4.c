#include <stdio.h>

void foo (int a[], int n);


int main (void) {
	int i;
   int a[]={10,1,2,3,4,5,0,1,2,3,4,5};
	foo(a,12);
	for(i=0;i<12;i++)
	printf("%d\n",a[i]);
   return 0;
}
