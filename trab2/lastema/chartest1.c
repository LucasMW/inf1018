#include <stdio.h>
#include "gera_func.h"
#define ON 1;
#define OFF 0;
char chardiv (char a, char b)
{
 return a/b;
}

typedef char (*cfooc) (char x);
typedef char (*cfoocc)(char x, char y);
int main (void) {
  Parametro params[2];
  cfooc DivBy2=NULL;
	cfoocc InvDiv=NULL;
	cfoocc NormalDiv=NULL;
  char messages=ON;
  char a,b;
  params[0].tipo = CHAR_PAR;
  params[0].amarrado = 0;
  params[0].posicao = 1;
  params[1].tipo = CHAR_PAR;
  params[1].amarrado = 1;
  params[1].valor.v_char = 2;
  
  a=10; b=120;

  DivBy2 = (cfooc) gera_func (chardiv, 2, params);
  printf("A/2: %d VS DivBy2 %d\n",a/params[1].valor.v_char ,DivBy2(a));
if(messages)
	for(a=0;a<45;a++)  
	{	
	if(a/params[1].valor.v_char==DivBy2(a))
	printf("SUCESS\n");
	else
	printf("AARGH\n");
 	} 
	params[0].tipo = CHAR_PAR;
  params[0].amarrado = 0;
  params[0].posicao = 2;
  params[1].tipo = CHAR_PAR;
  params[1].amarrado = 0;
  params[1].posicao = 1;

   InvDiv = (cfoocc) gera_func (chardiv, 2, params);
 	 printf("b/a: %d VS InvDiv %d\n",b/a,InvDiv(a,b));
 if(messages)
	for(b=0,a=1;b<100;b=b+3,a=a+1)
	{
	if(b/a==InvDiv(a,b))
	printf("SUCESS\n");
	else
	printf("AARGH\n");
	}
	params[0].tipo = CHAR_PAR;
  params[0].amarrado = 0;
  params[0].posicao = 1;
  params[1].tipo = CHAR_PAR;
  params[1].amarrado = 0;
  params[1].posicao = 2;
	
    NormalDiv = (cfoocc) gera_func (chardiv, 2, params);
  a=45; b=34;
	printf("a/b: %d VS NormalDiv: %d\n",a/b,NormalDiv(a,b));
  	if(messages)
  for(b=10,a=1;b<200;b=b+10,a=a+1)
	{
	if(a/b==NormalDiv(a,b))
	printf("SUCESS\n");
	else
	printf("AARGH\n");
	}
	

  return 0;
}
