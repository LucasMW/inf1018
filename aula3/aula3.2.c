#include<stdio.h>
unsigned int incrSeq(unsigned int pacote);
{
if(getSeq(pacote2)==15)
pacote&0x87ffffff; // Zere a sequência
else
 return pacote+1<<27; //pacote + 2²7 incremente

}
int getSeq(unsigned int pacote)
{
pacote=pacote<<1; //some com bit 31
pacote=pacote>>28; // some com o resto
return pacote;
}
int isPrio(unsigned int pacote)
{
return pacote&4096; //tem o bit 1 na exata posição 12 contando de 0? aka 2¹²=4096
}



int main() {

   unsigned int pacote1 = 0x7801E3A2;
   unsigned int pacote2 = 0x0801FBA2;
   unsigned int pacote3=1004096;
   unsigned int novopacote;

   printf("prio pac1 = %s\n", isPrio(pacote1) ? "S" : "N");
   printf("prio pac2 = %s\n", isPrio(pacote2) ? "S" : "N");
   printf("seq pac1 = %d\n",getSeq(pacote1));
   printf("seq pac2 = %d\n",getSeq(pacote2));	

   printf("prio pac3 = %s\n", isPrio(pacote3) ? "S" : "N");

   return 0;
}
