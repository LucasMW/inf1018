#include<stdio.h>
#include<string.h>
int add (int x);
typedef int (*funcp) (int x); // declaro um ponteiro pra função que reotna int e recebe um int

unsigned char codigo[]={0x55,0x89,0xe5,0xff,0x75,0x08,0xe8,0xfc,0xff,0xff,0xff,0x83,0xc4,0x04,0x89,0xec,0x5d,0xc3}; //Codigo da função foo.s
int main (void)
{
	int i;
	unsigned int diff=(unsigned int) add- (unsigned int)&codigo[11]; // Diferença do add para a posição do 0xe8
	
	//memcpy(&codigo[7],&diff,4);
	for(i=0; i<4; i++)
		codigo[7+i]= (unsigned char) (diff>>(i*8)); //same effect as memcpy code above in little endian machines. This code is more generic

	

	funcp f = (funcp)codigo;
	i = (*f)(10); //chamo a função com o argumento 10
	printf("\t%d\n",i);
	return i;
}
