#include<stdio.h>
float foo1 (float a, float b);
float foo1s (float a, float b);
int main (void)
{
printf("foo.c %f foo.s %f\n",foo1(3,4),foo1s(3,4));
printf("foo.c %f foo.s %f\n",foo1(300,-440),foo1s(300,-440));
printf("foo.c %f foo.s %f\n",foo1(-890,4),foo1s(-890,4));


return 0;
}
