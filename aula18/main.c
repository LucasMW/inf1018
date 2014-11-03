
#include <stdio.h>
double foo (double a, int b);

int main (void)
{
printf ("foo(%lf,%d)=%lf\n",0.5,7,foo(0.5,7));
printf ("foo(%lf,%d)=%lf\n",0.5,-7,foo(0.5,-7));
printf ("foo(%lf,%d)=%lf\n",-0.5,7,foo(-0.5,7));
printf ("foo(%lf,%d)=%lf\n",-0.5,-7,foo(-0.5,-7));
printf ("foo(%lf,%d)=%lf\n",10.0,7,foo(10.0,7));
printf ("foo(%lf,%d)=%lf\n",0.0,7,foo(0.0,7));
printf ("foo(%lf,%d)=%lf\n",0.5,0,foo(0.5,0));
printf ("foo(%lf,%d)=%lf\n",0.0,0,foo(0.0,0));
return 0;
}
