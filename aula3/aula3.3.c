#include<stdio.h>
unsigned int incrSeq(unsigned int pacote)
{
if(getSeq(pacote)==15)
return pacote&0x87ffffff; // Zere a sequência
else
 return (pacote+(1<<26)); //pacote + incremente

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


unsigned int setParity(unsigned int pacote)
{       int pkge;
	unsigned int i,c;
	pkge=pacote; 
for(i=1;i<(1<<31);i=i<<1)
if(pacote&i)
c++;
if(c&0) //c é par
return pacote&0x7fffffff; //paridade 0
else
return pacote&0x7fffffff+ (1<<31); //paridade 1



	   
	
}



int main() {

   unsigned int pacote1 = 0x7801E3A2;
   unsigned int pacote2 = 0x0801FBA2;
   unsigned int pacote3=1004096;
   

   printf("prio pac1 = %s\n", isPrio(pacote1) ? "S" : "N");
   printf("prio pac2 = %s\n", isPrio(pacote2) ? "S" : "N");
   printf("seq pac1 = %d\n",getSeq(pacote1));
   printf("seq pac2 = %d\n",getSeq(pacote2));	
   printf("seq pac1 = %d\n",getSeq(incrSeq(pacote1)));
    printf("incrseq pac2 = %d\n",getSeq(incrSeq(pacote2)));	

   printf("prio pac3 = %s\n", isPrio(pacote3) ? "S" : "N");

   return 0;
}
