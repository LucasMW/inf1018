/*int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}*/
.text

.global	fat
fat:	push	%ebp  /* Início da Função */
	mov	%esp, %ebp
	

	mov	8(%ebp), %edx /* %edx=n */
	cmpl	$0, %edx /* n==0? */
	jne	L1	/*n!=0 else */
	mov	$1, %eax /* preparing to return 1 */
	jmp 	Fim
L1:	sub 	$1, %edx /* n-1; */
	push	%edx     /* atributo n-1 */
	call	fat
	addl	$4, %esp
	imull 	8(%ebp),%eax /* %eax=n*%eax */	   	
	
	/*retorne */

Fim:	
	mov	%ebp, %esp  /* fim de função */
	pop	%ebp
	ret
