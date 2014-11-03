#include<stdio.h>
#define makefloat(s,e,m) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((m) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getmant(x) ((x) & 0x7fffff)
union intfloat
{
	float f;
	unsigned int i;
}; 
typedef union intfloat intfloat;

  float float2(float f)
{
	intfloat x;
	x.f=f;
	if(getexp(x.i)>=254) // if OverFlow 255 já é infinito
	x.i=makefloat(0,255,0);
	else
	x.i=makefloat(getsig(x.i),getexp(x.i)+1,getmant(x.i));
	
	
	return x.f;
}
int main (void)
{ 
intfloat a,b,c;
a.i=makefloat(0,254,2); // número gigante
b.i=makefloat(0,255,2); // Já é not a number
c.i=makefloat(0,256,2); // a makefloat resulta 0
printf("expected %f -- float2 %f\n",0.1*2,float2(0.1));
printf("expected %f -- float2 %f\n",0.2*2,float2(0.2));
printf("expected %f -- float2 %f\n",0.121*2,float2(0.121));
printf("expected %f -- float2 %f\n",-0.121*2,float2(-0.121));

printf("expected %f -- float2 %f\n",a.f*2,float2(a.f));
printf("expected %f -- float2 %f\n",b.f*2,float2(b.f));
printf("expected %f -- float2 %f\n",c.f*2,float2(c.f));
return 0;
}
