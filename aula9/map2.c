/*int f (int x) { return x+2; }

void map2 (int* um, int * outro, int n) {
  int i;
  for (i=0; i<n; i++)
    *(outro+i) = f(*(um+i));
}*/

.global f, map2

f:	push 	%ebp
	movl 	%esp, %ebp
	movl	8(%ebp), %eax /* pegue parametro */
	addl 	$2, %eax /* some 2 */
	
	movl	%ebp, %esp
	pop	%ebp
	ret
map2: 
	push 	%ebp
	movl 	%esp, %ebp
	push 	%ebx

	movl   12(%ebp)	%ecx	/* %ecx = outro */
	mov	$0, %ebx 	
	cmpl	8(%ebp), %ebx /* i<n */
	jge	 Fim
	mov	%ebx, %edx /* edx=i */	
	shfl	%2,   %edx /* i*4 , inteiro ocupa 4 bytes */
	addl    16(%ebp), %edx  /* edx = um +i */
	push 	(%edx)
	call    f   
	mov	%ebx, %edx /* edx=i */	
	shfl	%2,   %edx /* i*4 , inteiro ocupa 4 bytes */
	addl    %ecx, %edx  /* edx = um +i */
	mov 	%eax, (%edx)

	

	
	 


Fim:    pop 	%ebx
	movl	%ebp, %esp
	pop	%ebp
	ret
