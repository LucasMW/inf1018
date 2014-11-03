.global foo2s
.text
foo2s:	push 	%ebp
	mov	%esp, %ebp
	

	flds	8(%ebp) /*float a*/
	
	sub	$8,%esp /* push double: aloque espaço */
	fstpl	(%esp) /* store double */
	
	call	sin
	addl     $8 ,%esp /* desaloque essa chapa */
	
	flds	12(%ebp) /*float b*/
	
	sub	$8,%esp /* push double: aloque espaço */
	fstpl	(%esp) /* store double */

	call	cos
	addl     $8 ,%esp /* desaloque essa chapa */
	
	faddp  /* b+a */
	
	
	
	movl 	%ebp, %esp
	pop  	%ebp
	ret
