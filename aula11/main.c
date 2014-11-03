#include<stdio.h>
float foo (double a, float b);

int main (void)
{
float x=3.5;
float y=2.5;
float r;

r=foo(x,y);
printf("resultado: %f\n",r);
return 0;

}
