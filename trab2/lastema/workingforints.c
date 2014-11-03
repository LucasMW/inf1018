#include <stdio.h>
#include <stdlib.h>
#include"gera_func.h"
void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

typedef struct {
    int index;        /* ordem que o parâmetro é passado para a nova função */
    char* inst;        /* endereço da instrução onde deve ser colocado o deslocamento. */   
    char tamanho;    /* tamanho do tipo do parâmetro */
} paramIndex;

void* gera_func (void* f, int n, Parametro params[]){
    int nAmarrados, tamBytes, i, j; //ñAmarrados, qtd de parâmetros não amarrados. tamBytes, tamanho da nova função.
    paramIndex tabela[n];
    char *func, *temp;                //Ponteiro função onde será criada a nova função, ponteiro auxiliar temp.
    unsigned int diff;                //Diff para determinar a função chamada.
   
    tamBytes = (n*10)+12;
   
    func = (char*)malloc(tamBytes);    
    if(!func)
        exit(1);
    /* INICIALIZA A FUNÇÃO */   
    func[0] = 0x55;
    func[1] = 0x89;
    func[2] = 0xe5;
    temp = &func[3];
    nAmarrados = 0;
    for(i = n-1; i >= 0; i--){
        if(params[i].amarrado){
            if(params[i].tipo == DOUBLE_PAR){
                /*int* d = &params[i].valor.v_int;
                temp[0] = 0x68;
                *((int*) &temp[1]) = *d;
                d += 5;
                temp[5] = 0x68;
                *((int*) &temp[6]) = *d;*/
                int *d = &params[i].valor.v_int;
                temp[0] = 0x68;
                temp[1] = d[0];
                temp[2] = d[1];
                temp[3] = d[2];
                temp[4] = d[3];
                temp[5] = 0x68;
                temp[6] = d[4];
                temp[7] = d[5];
                temp[8] = d[6];
                temp[9] = d[7];
                
                dump((temp), 10);
                temp += 10;
            }else if(params[i].tipo == INT_PAR){
                char *d = (char*)&params[i].valor.v_int;
                temp[0] = 0x68;
                temp[1] = d[0];
                temp[2] = d[1];
                temp[3] = d[2];
                temp[4] = d[3];
                temp += 5;
				
            }else if(params[i].tipo == CHAR_PAR){
                temp[0] = 0x6a;
                temp[1] = params[i].valor.v_char;
                temp += 2;
            }
        }else{
            nAmarrados++;
            printf("Parametro nao amarrado - ordem: %d\n", nAmarrados);
            temp[0] = 0xff;
            temp[1] = 0x75;
            temp[2] = 0x00;
            
            int d = params[i].posicao;
            tabela[d-1].index = d;				// Ordem que o parâmetro é passado para a nova função
            tabela[d-1].inst = &temp[2];		// Endereço onde deve ser colocado o deslocamento na pilha, posteriormente.
            if(params[i].tipo == DOUBLE_PAR)	// Tamanho dos tipos, para calcular o deslocamento da pilha dos parâmetros subsequentes
                tabela[d-1].tamanho = 0x08;
            else if(params[i].tipo == CHAR_PAR)
                tabela[d-1].tamanho = 0x01;
            else
                tabela[d-1].tamanho = 0x04;
            temp += 3;
        }   
    }
   
    /* CALL */
    temp[0] = 0xe8;
    diff = (unsigned int)f - (unsigned int)&(temp[5]);
    temp[1] = diff&0xff;
    temp[2] = (diff>>8)&0xff;
    temp[3] = (diff>>16)&0xff;
    temp[4] = (diff>>24)&0xff;
   
    /* FINALIZAÇÃO */
    temp[5] = 0xc9; //leave
    temp[6] = 0xc3; //ret
   
    for(i=0; i<nAmarrados; i++){
        int g = 8;
        char *t = tabela[i].inst;   
        printf("Parametro %d - tamanho %d\n", tabela[i].index, tabela[i].tamanho);
        for(j=0; j<nAmarrados; j++){
            if(tabela[j].index < tabela[i].index){
                printf("Vem depois de %d bytes\n", tabela[j].tamanho+g);
                g += tabela[j].tamanho;
            }
        }
	
        *t = g;
        printf("%d\n", *t);
    }
   
    dump(func, tamBytes);
	
    return (void*)func;
}

void libera_func (void* func){
	free(func);
}
