/*int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}*/
.text

.global	fat
fat:	push	%ebp  /* Início da Função */
	mov	%esp, %ebp
	push  	%ebx 

	mov	8(%ebp), %edx /* %edx=n */
	cmpl	$0, %edx /* n==0? */
	jne	L1	/*n!=0 else */
	mov	$1, %eax /* preparing to return 1 */
	jmp 	Fim
L1:	add     %edx, %ecx /* ecx=n */
	sub 	%1, %ecx /* n-1; */
	push	%ecx     /* atributo n-1 */
	addl	$4, %esp
	imull 	%edx,%eax /* %eax=n*%eax */	   	
	
	/*retorne */

Fim:	pop 	%ebx       /* Preserve %ebx */
	mov	%ebp, %esp  /* fim de função */
	pop	%ebp
	ret
