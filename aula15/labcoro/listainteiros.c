#include <stdlib.h>
#include <values.h>
#include "corotinas.h"
#include "listainteiros.h"

struct noLista {
  int info;
  struct noLista *prox;
};

ListaInteiros *listaCria(void) {
  return NULL;
}

ListaInteiros *listaInsere(ListaInteiros *l, int v) {
  ListaInteiros *n = (ListaInteiros *) malloc(sizeof(ListaInteiros));
  if (n != NULL) {
    n->info = v;
    n->prox = l;
  }
  return n;
}

void listaLibera(ListaInteiros *l) {
  ListaInteiros *prox, *n = l;
  while (n != NULL) {
    prox = n->prox;
    free(n);
    n = prox;
  }
}

/*
 * Corpo da corotina que implementa o iterador 
 */
static CoroParam iteraLista (CoroParam lista) {

  /* Guarda a lista que deve ser "iterada" */
  ListaInteiros *l = (ListaInteiros *) lista;

  /* Retorna o controle para quem a iniciou */
  coro_yield((CoroParam) 0); //Essa primeira chamada é só pra receber a lista. Dane-se o retorno. é inútil	
 while(l)
 {
	coro_yield(l->info); //me dê o elemento
	l=l->prox;  //percorra a lista
 }
  /* preencha o resto do cÃ³digo! */
  return MININT;
}

/*
 * Cria uma corotina com corpo iteraLista
 *  para percorrer a lista
 */
void *criaIterador (ListaInteiros *l) {
  CoroP IT=coro_create("iterador",iteraLista);
   coro_resume(IT,(CoroParam)l); //chama pela primeira vez para passar a lista. O retorno não interessa
  return (void *)IT ; 
}

int ativaIterador (void *iterador) {
  return (int)coro_resume((CoroP)iterador,(CoroParam)NULL); //Continue o iterador. Dane-se o parâmetro passado, ele já recebeu a lista
  //return MININT;
}

void destroiIterador (void *iterador) {
 coro_free((CoroP)iterador);
}

