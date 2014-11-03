typedef struct noLista ListaInteiros;

ListaInteiros *listaCria(void);
ListaInteiros *listaInsere(ListaInteiros *l, int v);
void listaLibera(ListaInteiros *l);

void *criaIterador (ListaInteiros *l);
int ativaIterador (void *iterador);
void destroiIterador (void *iterador);


