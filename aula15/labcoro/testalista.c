#include <stdio.h>
#include <values.h>
#include "listainteiros.h"
int somalista(ListaInteiros* l)
{
void * p;
  int x;
  int soma=0;
p=criaIterador(l);
 while(1)
  {
	x=ativaIterador(p);
	if(x!=MININT)
		soma+=x;
	else
	break;
  }
return soma;
}

int main(void) {

  ListaInteiros *l1 = listaCria();
  ListaInteiros *l2 = listaCria();
 

  l1 = listaInsere(l1, 1);
  l1 = listaInsere(l1, 2);
  l1 = listaInsere(l1, 3);
  l1 = listaInsere(l1, 4);
  l1 = listaInsere(l1, 5);

  l2 = listaInsere(l2, 2);
  l2 = listaInsere(l2, 5);
  l2 = listaInsere(l2, 1);

 printf("soma: %d\n",somalista(l1));
 printf("soma: %d\n",somalista(l2));

  listaLibera(l1);
  listaLibera(l2);

  return 0;
}



