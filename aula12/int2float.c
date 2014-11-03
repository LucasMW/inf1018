
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

  float int2float(int i)
{	unsigned int t;
	unsigned int exp=0;
	unsigned int mantissa;
	unsigned char signal;
	intfloat x;
	signal=i>>31;
	if(i<0)
	i=-1*i;
	if(i>0)
	{
		
		t=i;
		while(t!=1) 
		{
			t=t>>1;
			exp++;
		} 
		printf("DEBUG exp=%u\n",exp);
		if(exp<=23)
		mantissa=i<<(23-exp);
		else
		mantissa=i>>(exp-23);
		printf("DEBUG mantissa=%x\n",mantissa);
	
	}
	
	
	
	
	if(i)
		x.i=makefloat(signal,exp+127,mantissa);
	else
		x.i=makefloat(0,0,0);
	return x.f;
	
}
int main (void)
{ 
printf("int %d float %f\n",0,int2float(0));
printf("int %d float %f\n",1,int2float(1));
printf("int %d float %f\n",2,int2float(2));
printf("int %d float %f\n",3,int2float(3));
printf("int %d float %f\n",128,int2float(128));
printf("int %d float %f\n",256,int2float(256));
printf("int %d float %f\n",16777216,int2float(16777216));
printf("int %d float %f\n",-2,int2float(-2));
printf("int %d float %f\n",-3,int2float(-3));
printf("int %d float %f\n",-128,int2float(-128));
printf("int %d float %f\n",-256,int2float(-256));
printf("int %d float %f\n",-16777216,int2float(-16777216));




return 0;
}
