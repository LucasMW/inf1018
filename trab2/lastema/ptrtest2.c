#include <stdio.h>
#include "gera_func.h"
#define ON 1;
#define OFF 0;
void atribut (int* a, int* b)
{
  *a=-21;
	*b=32;
}

typedef int (*ifooptr) (int x);
typedef int (*ifooptrptr)(int x, int y);
int main (void) {
  Parametro params[2];
  ifooi DivBy2=NULL;
	ifooii InvDiv=NULL;
	ifooii NormalDiv=NULL;
  char messages=ON;
  int a,b;
  params[0].tipo = PTR_PAR;
  params[0].amarrado = 0;
  params[0].posicao = 1;
  params[1].tipo = PTR_PAR;
  params[1].amarrado = 1;
  params[1].valor.v_int = 2;
  
  a=10; b=120;

  DivBy2 = (ifooi) gera_func (intdiv, 2, params);
  printf("A/2: %d VS DivBy2 %d\n",a/params[1].valor.v_int ,DivBy2(a));
if(messages)
	for(a=0;a<45;a++)  
	{	
	if(a/params[1].valor.v_int==DivBy2(a))
	printf("SUCESS\n");
	else
	printf("AARGH\n");
 	} 
	params[0].tipo = INT_PAR;
  params[0].amarrado = 0;
  params[0].posicao = 2;
  params[1].tipo = INT_PAR;
  params[1].amarrado = 0;
  params[1].posicao = 1;

   InvDiv = (ifooii) gera_func (intdiv, 2, params);
 	 printf("b/a: %d VS InvDiv %d\n",b/a,InvDiv(a,b));
 if(messages)
	for(b=0,a=1;b<100;b=b+3,a=a+1)
	{
	if(b/a==InvDiv(a,b))
	printf("SUCESS\n");
	else
	printf("AARGH\n");
	}
	params[0].tipo = INT_PAR;
  params[0].amarrado = 0;
  params[0].posicao = 1;
  params[1].tipo = INT_PAR;
  params[1].amarrado = 0;
  params[1].posicao = 2;
	
    NormalDiv = (ifooii) gera_func (intdiv, 2, params);
  a=1345; b=234;
	printf("a/b: %d VS NormalDiv: %d\n",a/b,NormalDiv(a,b));
  	if(messages)
  for(b=10,a=1;b<1000;b=b+10,a=a+1)
	{
	if(a/b==NormalDiv(a,b))
	printf("SUCESS\n");
	else
	printf("AARGH\n");
	}
	

  return 0;
}
