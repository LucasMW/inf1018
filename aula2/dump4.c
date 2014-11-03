#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}
 int main (void) {
      char i[] = {'U','u','m','a',' ','s','t','r','i','n','g','\0','\n','s','$',00};
	printf("string:\t%s\n",i);
      dump(i, sizeof(i));

      return 0;
    }


