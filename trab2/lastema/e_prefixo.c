#include<string.h>

char a[] = "quero saber se a outra string é um prefixo dessa aqu";
int e_prefixo (void* candidata, size_t n)
{
 return memcmp(candidata,a,n);
}

