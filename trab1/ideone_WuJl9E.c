#include <stdio.h>
#include <stdlib.h>

char* getString(void *strc, int* tam){
	char *result;
	char* p = strc;
	while(*p!=0){
		*tam++;
		p++;
	}
	result = (char*)malloc(*tam*sizeof(char));
	p = strc;
	while(*p!=0){
		*result = *p;
		result++;
		p++;
	}
	return result;
}
struct teste{
	char nome[10];
};
int main(void) {
	// your code goes here
	int t;
	struct teste Str;
	char *res;
	Str.nome = "Albert";
	res = getString(&Str, &t);
	printf("%s", res);
	return 0;
}
