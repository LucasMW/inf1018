/* tipo do parÃ¢metro para uma corotina */
typedef int CoroParam;

/* corpo de uma corotina */
typedef CoroParam (*CoroBody)(CoroParam param);

/* referencia para uma corotina */
typedef struct coroDescr *CoroP; 

/* 
 * coro_create: cria uma nova corotina
 *
 * ParÃ¢metro: funÃ§Ã£o que implementa o "corpo" da corotina
 * Retorna: referencia para a corotina criada
 */
CoroP coro_create(char *name, CoroBody func);

/*
 * coro_resume: (re)ativa a execuÃ§Ã£o de uma corotina
 *
 * ParÃ¢metros:
 *   - referencia para a corotina a (re)ativar
 *   - parametro para a corotina (parametro inicial ou retorno de coro_yield)
 *
 * Retorna:
 *   o parÃ¢metro passado a coro_yield quando a corotina suspender,
 *   ou o retorno do "corpo" da corotina, quando ela terminar
 */
CoroParam coro_resume(CoroP coro, CoroParam param);

/*
 * coro_yield: suspende a execuÃ§Ã£o de uma corotina, retomando a execuÃ§Ã£o 
 *             do chamador 
 * ParÃ¢metros:
 *   - valor de retorno para o chamador (retorno de coro_resume)
 *
 * Retorna:
 *   o parÃ¢metro passado a coro_resume quando a corotina for reativada
 */
CoroParam coro_yield(CoroParam param);

/*
 * coro_free: libera Ã¡rea usada por corotina
 *
 * ParÃ¢metro: referencia para a corotina
 */
void coro_free(CoroP coro);

