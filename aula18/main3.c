#include<stdio.h>
#include<stdlib.h>
struct X1 {
 int vi;
  float vf;
};
typedef struct X1 El;

double foo (double a, int b);
double pack1 (struct X1 *px, int n);

int main (void)
{
int i;
El * v;
v=(El*)malloc(sizeof(El)*10);
for(i=0;i<10;i++)
{
v[i].vi=-i;
v[i].vf=i/1.5;
}
printf("pack=%lf\n",pack1(&v[0],10));
return 0;
}
