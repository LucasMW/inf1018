/*struct X {
  int c;
  struct X *next;
};

int add (struct X *x) {
  int a = 0;
  for (; x != 0; x = x->next)
    a += x->c;
  return a;
}*/

.global add
add:     /* inicio */
	push 	%ebp /* Preserve %ebp antigo */
	mov	%esp,%ebp /* %esp é o novo %ebp */

	mov	$0,%eax	/* a=0 */
	mov	8(%ebp), %ecx /* %ecx=&x */
L1:	cmp	$0, %ecx /*x!=0? */
	je	Fim	/* igual caia fora */
	addl	(%ecx),%eax /* Os primeiros 4 bytes são o int c */
	mov	4(%ecx),%ecx /* O segundo valor é um ponteiro 4 bytes também */
	jmp 	L1
		
	
Fim:	mov 	%ebp,%esp /* Volte o %esp pro lugar */
	pop	%ebp	 /* restaure %ebp */
	ret
