#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "corotinas.h"

#define STACK_SIZE 4096

typedef unsigned int *CoroStack; /* pilha */
typedef unsigned int CoroReg;    /* registrador */


typedef enum {ALIVE, DEAD} CoroStatus;

/* Descritor de uma corotina */
struct coroDescr {

  /* Ã¡rea para a pilha da corotina */
  CoroReg  esp;
  CoroStack stack;

  /* descritor da corotina "chamadora" */
  struct coroDescr *caller;

  /* status e nome da corotina */
  int	status;
  char  *name;
};

/* descritor dummy para programa principal */
static struct coroDescr mainCoroDescr;
static CoroP mainCoro = &mainCoroDescr;

/* guarda o descritor da corotina corrente */
static CoroP currentCoro = &mainCoroDescr;

/* FunÃ§Ãµes em assembly */
void icoro_begin();
CoroParam icoro_transfer(CoroP from, CoroP to, CoroParam param);

/*
 * Termina o programa com erro
 */
static void error(const char* msg, const char *name) {
  fprintf(stderr, "\nERRO: %s (%s)\n",msg, name);
  exit(EXIT_FAILURE);
}

/* 
 * coro_create: cria uma nova corotina
 *
 * ParÃ¢metro: funÃ§Ã£o que implementa o "corpo" da corotina
 * Retorna: ponteiro para o descritor da corotina criada
 */

CoroP coro_create(char *name, CoroBody func) {

   /* aloca o descritor da corotina */
   CoroP coro = (CoroP) malloc(sizeof(struct coroDescr));

   /* aloca a pilha */
   coro->stack = (CoroStack) malloc(STACK_SIZE*4);
/*
#ifdef NOMAP
   coro->stack = (CoroStack) malloc(STACK_SIZE*4);
#else
   coro->stack = (CoroStack) mmap(NULL, STACK_SIZE*4, (PROT_READ | PROT_WRITE | PROT_EXEC),
                    (MAP_32BIT | MAP_ANONYMOUS | MAP_PRIVATE | MAP_STACK),
		    -1, 0);
#endif
*/

   /* coloca no fundo da pilha o endereÃ§o do corpo da corotina 
        e o endereÃ§o da funÃ§Ã£o de inicializaÃ§Ã£o da corotina */
   coro->stack[STACK_SIZE-1] = (unsigned int)func;
   coro->stack[STACK_SIZE-2] = (unsigned int)icoro_begin;
   coro->esp = (CoroReg) &(coro->stack[STACK_SIZE-2]);

   coro->name = name;
   coro->status = ALIVE;
   return coro;
}

/*
 * coro_resume: (re)ativa a execuÃ§Ã£o de uma corotina
 *
 * ParÃ¢metros:
 *   - ponteiro para o descritor da corotina a (re)ativar
 *   - parametro para a corotina (parametro inicial ou retorno de coro_yield)
 *
 * Retorna:
 *   o parÃ¢metro passado a coro_yield quando a corotina suspender,
 *   ou o retorno do "corpo" da corotina, quando ela terminar
 */
CoroParam coro_resume(CoroP coro, CoroParam param) {

  /* somente pode reativar corotina que nÃ£o terminou */
  if (coro->status == DEAD)
    error("Tentativa de reativar corotina terminada", coro->name);

  /* guarda o chamador e transfere controle */
  coro->caller = currentCoro;
  currentCoro = coro;

  return icoro_transfer(coro->caller, coro, param);
}

/*
 * coro_yield: suspende a execuÃ§Ã£o de uma corotina, retomando a execuÃ§Ã£o 
 *             do chamador 
 * ParÃ¢metros:
 *   - valor de retorno para o chamador (retorno de coro_resume)
 *
 * Retorna:
 *   o parÃ¢metro passado a coro_resume quando a corotina for reativada
 */
CoroParam coro_yield(CoroParam param){

  CoroP curr;

  /* programa principal (main) nÃ£o pode chamar yield */
  if (currentCoro == mainCoro)
    error("Programa principal nÃ£o pode suspender", NULL);

  /* transfere o controle para o chamador */
  curr = currentCoro;
  currentCoro = curr->caller;

  return icoro_transfer(curr, currentCoro, param);
}

/*
 * coro_end: termina uma corotina, colocando-a no estado "morto" e devolvendo
 *           controle a seu chamador
 *
 * ParÃ¢metros:
 *   - valor de retorno para o chamador
 */
void coro_end(CoroParam param) {
  CoroP curr;
  curr = currentCoro;
  currentCoro = curr->caller;
  curr->status = DEAD;

  icoro_transfer(curr, currentCoro, param);
  
  error("Corotina terminada nÃ£o pode retomar controle!", curr->name);
}

/*
 * coro_free: libera Ã¡rea usada por corotina
 *
 * ParÃ¢metro: ponteiro para o descritor da corotina
 */
void coro_free(CoroP coro) {

  /* libera a Ã¡rea de pilha */
#ifdef NOMAP
  free(coro->stack);
#else
  munmap(coro->stack, STACK_SIZE*4);
#endif

  /* libera o descritor */
  free(coro);
}

