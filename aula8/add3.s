.text

.global	add1
add1:	push	%ebp  /* Início da Função */
	mov	%esp, %ebp
	push  	%ebx 

	mov	8(%ebp), %ecx /* %ecx=a */
	mov	12(%ebp), %edx /* %edx=n */ 
	mov 	$0, %eax  /* s=0 */
	mov     $0, %ebx  /* i=0 */
L1:	cmpl    %edx,%ebx /* i<n ? */
	jge     Fim
	addl	(%ecx),%eax /* s+= *a */
	addl	$4, %ecx /* a++ */
	addl 	$1, %ebx /* i++ */
	jmp 	L1
	

Fim:	pop 	%ebx       /* Preserve %ebx */
	mov	%ebp, %esp  /* fim de função */
	pop	%ebp
	ret
