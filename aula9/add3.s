/* int add3 (struct X *x) {
  if (x == 0) 
	return 0;
  else 
	return x->c + add2(x->next);
}*/

.global add3
add3: 	
	push	%ebp /* preserve %ebp */
	mov 	%esp,%ebp /* guarde %esp */
	movl	8(%ebp), %ecx /* pegue parametro &x */
	cmpl 	$0, %ecx	/* &x==0 ? */
	jne	L2	/* se não for , pule essas intruções */
	mov 	$0, %eax /* prepare-se para retornar 0 */
	jmp 	Fim
L2:	
	mov	4(%ecx), %ecx /* pule char c  e dois bytes de padding e pegue o atributo next */  
	push   	%ecx
	call 	add3	
	add 	$4, %esp /* desaloque o espaço do endereço */
	movl	8(%ebp), %ecx /* pegue  &x de novo de novo */
	movsbl	(%ecx), %edx	/* pegue char c e converta - o num int e jogue no %eax */
	add	%edx, %eax

Fim:	mov 	%ebp, %esp /* Ponha %esp no lugar */
	pop	%ebp /* restaure %ebp */
	ret
