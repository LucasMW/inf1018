#include <stdio.h>
#include "gera_func.h"
#define ON 1;
#define OFF 0;
float amultbdivc (int a, int b,int c)
{
 return a*1.0*b/c;
}

typedef int (*ifooi) (int x);
typedef int (*ifooii)(int x, int y);
typedef int (*ifooiii) (int x, int y, int z);
int main (void) {
  Parametro params[3];
  ifooi doistercos=NULL;
	ifooii amultbdiv2=NULL;
	ifooiii cab=NULL;
  char messages=ON;
  int a,b,c;
  params[0].tipo = INT_PAR;
  params[0].amarrado = 0;
  params[0].posicao = 1;
  params[1].tipo = INT_PAR;
  params[1].amarrado = 1;
  params[1].valor.v_int = 2;
  params[2].tipo = INT_PAR;
  params[2].amarrado = 1;
  params[2].valor.v_int = 3;	
  
  a=10; b=120; c=3;

  doistercos= (ifooi) gera_func (amultbdivc, 3, params);
  printf("A*2/3: %f VS doistercos %f\n",amultbdivc(a,2,3) ,doistercos(a));
if(messages)
	for(a=0;a<45;a++)  
	{	
	if(1.0*a*params[1].valor.v_int/params[2].valor.v_int==doistercos(a))
	printf("SUCESS\n");
	else
	printf("AARGH\n");
 	} 
	/*params[0].tipo = INT_PAR;
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
	
*/
  return 0;
}
