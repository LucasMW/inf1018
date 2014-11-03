#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int zigzag(int n){
	int i;
	i = (n<<1)^(n>>32);
	return i;
}

int swap(int n){
	int sw;
	sw = ((n>>24)&0xff);
	sw = sw|((n<<8)&0xff0000);
	sw = sw|((n>>8)&0xff00);
	sw = sw|((n<<24)&0xff000000);

	return sw;
}

unsigned int varint(unsigned int n){
	unsigned int var;
	var = (n & 0x0000007f)|0x80;
	n = n>>7;
	while(n!=0){
		var = var<<8;
		var = var|(n & 0x0000007f);
		n = n>>7;
	}
	return var;
}

int main(void){
	int i = 0xa1a2a3a4;
//	i = zigzag(i);
	i = varint(i);
	dump(&i, sizeof(int));
//	i = swap(i);
//	dump(&i, sizeof(int));
	return 0;
}
