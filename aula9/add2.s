/*int add2 (struct X *x) {
  if (x == 0) 
	return 0;
  else 
	return x->c + add2(x->next);
}*/

.global add2
add2:     /* inicio */
	push 	%ebp /* Preserve %ebp antigo */
	mov	%esp, %ebp /* %esp é o novo %ebp */
	mov	8(%ebp), %ecx
	cmpl	$0, %ecx /* x==0 ?*/
	jne	L2
	movl 	$0, %eax /* prepare-se para retornar 0 */
	jmp 	Fim
L2:  		
	movl    4(%ecx), %ecx /* ecx =ecx->next */
	push   %ecx
	call   add2
	addl   $4, %esp /* Desaloque o espaço da pilha */
	mov    8(%ebp), %ecx /* pegue o &x de novo */ 
	addl   (%ecx), %eax /* primieros bytes são o int */
	

Fim: 	mov	%esp, %ebp
	pop	%ebp
	ret
