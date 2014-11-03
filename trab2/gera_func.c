#include "gera_func.h" 
#include <stdlib.h>
#include <stdio.h>  



void* gera_func (void* f, int n, Parametro params[])
{
unsigned char codigo[]={0x55,0x89,0xe5,0x8b,0x45,0x08,0x83,0xc0,0x01,0x89,0xec,0x5d,0xc3,0x00};
 char * p;
 int i;
printf("my program\n");
 for(i=0;codigo[i];i++);
 p=(char*)malloc(i);
 for(i=0;codigo[i];i++);
 *(p+i)=codigo[i];
printf("End of my program\n");
return (void*)p;
	



}
void libera_func (void* func)
{ char* p;
  p=func; 
  *p=0;		// garantees it won't acessed and executed again
 free(func);
}

