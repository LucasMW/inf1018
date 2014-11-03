#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}
 int main (void) {
	int b;      
	short int i = 4;
	char controlchar='a';
	while(controlchar!='s')
	{
	printf("enter a number\n");	
	scanf("%i",&b);
	i=b;
        dump(&i, sizeof(i));
	printf("press any key to continue\npress s to exit\n ");
	scanf("%c",&controlchar);
	}
      return 0;
    }


