#include<stdio.h>
float foo2 (float a, float b);
float foo2s (float a, float b);
int main (void)
{
printf("foo.c %f foo.s %f\n",foo2(3,4),foo2s(3,4));
printf("foo.c %f foo.s %f\n",foo2(300,-440),foo2s(300,-440));
printf("foo.c %f foo.s %f\n",foo2(-890,4),foo2s(-890,4));


return 0;
}
