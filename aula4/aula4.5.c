#include<stdio.h>

int main (void)
{
signed char sc = -1;
unsigned int ui = sc;

printf("sc=%i ui=%u %p\n",ui,ui,ui);
return 0;
}
