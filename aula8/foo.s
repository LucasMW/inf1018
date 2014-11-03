.text

.global	foo
foo:	push	%ebp  /* Início da Função */
	mov	%esp, %ebp
	push  	%ebx 

	mov	8(%ebp), %ecx /* %ecx=a */
	mov	12(%ebp), %edx /* %edx=n */ 
	mov 	$0, %eax  /* s=0 */
	mov     $0, %ebx  /* i=0 */
L1:	cmpl    12(%ebp),%ebx /* i<n ? */
	jge     Fim  /* i>=n  caia fora */
	mov	%ebx, %edx /* Sessão a[i] */
	imull   $4, %edx  /* edx= i*4 */
	add 	%ecx, %edx   /* edx= i*4 +&a[0] */ 
	add     (%edx), %eax /* s=+a[i] */ 
	cmpl    $0,(%edx)   /* a[i]==0? */
	jne 	L2 	/* a[i]!=0 vá para else */
	mov     %eax, (%edx)  /* a[i]=s */
	mov	$0, %eax /* s=0 */
	
L2:	addl 	$1, %ebx /* i++ */
	jmp 	L1
	

Fim:	pop 	%ebx       /* Preserve %ebx */
	mov	%ebp, %esp  /* fim de função */
	pop	%ebp
	ret
