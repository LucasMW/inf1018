#include <stdio.h>

unsigned long varint(unsigned int n, int* nb){   // msb == most significant bit
	unsigned long var;				
	var=0;
	*nb = bytesForVarint2(n);
	while(n!=0){
		var = var<<8;			//cria espaço para um novo byte em var
		var = var|((n & 0x0000007f)|0x80); //copia os 7 bits seguinte para var
		n = n>>7;				//busca os próximos 7 bits
	}
	var = var&0xffffff7f;		//seta o msb do byte menos significativo para zero	
								// usar um fwrite((&var+8)-nb+1, 1, nb, arq);
	return var;
}



int bytesforvarint (unsigned int x) // número tem que ter vindo zigzageado
 {
	 if(x>=(268435456)) // 0111 1111 = 0x7F
		 return 5;
	 else 
			if(x>=(2097152))
			return 4;
			else 
					if(x>=(16384))
					return 3;
					else 
						if(x>=(128))
						return 2;
	return 1; 
 }

int bytesForVarint2 (unsigned int c)
{
	if(c <= 0x7F) return 1;
	if(c <= 0x3FFF) return 2; // 0011 1111 1111 1111 = 0x3FFF
	if(c <= 0x1FFFFF) return 3; // 0001 1111 1111 1111 1111 1111
	if(c <= 0xFFFFFFF) return 4;
	return 5;
}

unsigned int zigzag(int n){
	n = (n<<1)^(n>>31);
	return n;
}

void tests ()
{
 int nb;
 /* Testando Zigzag */
 printf("\n\tTestando Zigzag\n\n");
  printf("%d encoded as %u\n",0,zigzag(0));
  printf("%d encoded as %u\n",-1,zigzag(-1));
  printf("%d encoded as %u\n",1,zigzag(1));
  printf("%d encoded as %u\n",-2,zigzag(-2));
  printf("%d encoded as %u\n",2147483647,zigzag(2147483647));
  printf("%d encoded as %u\n",-2147483648,zigzag(-2147483648));
  printf("\n\tTeste bem sucedido\n");
/* Testando BytesFor varint */
 printf("\n\tTestando BytesForVarint\n\n");
printf("numero %d bfv %d bf2 %d\n",1,bytesforvarint(1),bytesForVarint2(1));
printf("numero %d bfv %d bf2 %d\n",300,bytesforvarint(300),bytesForVarint2(300));
printf("numero %d bfv %d bf2 %d\n",150,bytesforvarint(150),bytesForVarint2(150));
printf("numero %d bfv %d bf2 %d\n",128,bytesforvarint(128),bytesForVarint2(128));
printf("numero %d bfv %d bf2 %d\n",127,bytesforvarint(127),bytesForVarint2(127));
printf("numero %d bfv %d bf2 %d\n",126,bytesforvarint(126),bytesForVarint2(126));



/* Testando Varint */
 printf("\n\tTestando Varint\n\n");
nb=0;
printf("%d tranformado em varint %x \n ",1,varint(1,&nb)); 
printf("Ocupa nb: %d\n",nb);
printf("%d tranformado em varint %x\n",128,varint(128,&nb)); 
printf("Ocupa nb: %d\n",nb);
printf("%d tranformado em varint %x\n",300,varint(300,&nb)); 
printf("Ocupa nb: %d\n",nb);
printf("%d tranformado em varint %x\n",zigzag(65632),varint(zigzag(65632),&nb)); 
printf("Ocupa nb: %d\n",nb);



}
int main(void){
	int num = 150;

	unsigned int us;
	int qbytes; // número de 1 a 5
	char *c;
	long long int bla;
	FILE* output;
	output=fopen("test1","wb");
	if(!output)
	return 171;
	tests();
	num = zigzag(num);
	printf("%u - %x\n", num, num);
	num = varint(num,&qbytes);
	fwrite(&bla,1,qbytes,output);
	printf("%d - %x\n", num, num);

	//num = varint(zigzag(-1),&qbytes);
	//fwrite(&bla,1,qbytes,output);
	//num = varint(zigzag(-1),&qbytes);
	//fwrite(&num,1,8,output);
	
	printf("\nsizeofint: %d size of long long int %d\n",sizeof(unsigned int),sizeof(unsigned long long int));
	
	return 0;
}

