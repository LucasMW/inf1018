#include<stdio.h>
#include "corotinas.h"
int ping(int x)
{   int c = 0;
    while(c!=10)
	{	
		printf("ping %d\n",x);
		x = coro_yield(c);
		c++;
	}
	return x*-9;
}



int pong(int x)
{	int c=0;
 	while(c!=10)
	{	
		printf("pong %d\n",x);
		x=coro_yield(c);
		c++;
	}
	return x*-9;
}


int main (void)
{   int x;
	int t=1;
	CoroP C1=coro_create("cr1",ping);
	CoroP C2=coro_create("cr2",pong);
	while(t!=10)
	{	
		if(t&1)
		x=coro_resume(C1,t);
		else
		x=coro_resume(C2,t);
	printf("Main %d\n",x);
	t++;

	}

}













