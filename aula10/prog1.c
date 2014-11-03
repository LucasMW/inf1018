int novonum(void) {  
  int minhalocal;   //mov -4(%ebp), %ecx
  printf("numero: ");   // push "numero"
			//call printf
			//mov %ebp, %ecx
			//sub $4, %ecx
			// push "%d"
			//mov -4(%ebp), %eax
			//ret
  scanf("%d",&minhalocal);
  return minhalocal;
}

