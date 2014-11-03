/*float foo1 (float a, float b) {
  return sin(a) + b;
}*/
.global foo1s
.text
foo1s:	push 	%ebp
	mov	%esp, %ebp
	

	flds	12(%ebp) /*float b*/
	flds	8(%ebp) /*float a*/
	
	sub	$8,%esp /* push double: aloque espaço */
	fstpl	(%esp) /* store double */
	
	call	sin
	addl     $8 ,%esp /* desaloque essa chapa */
	
	flds	12(%ebp) /*float b*/
	faddp  /* b+a */
	
	
	
	movl 	%ebp, %esp
	pop  	%ebp
	ret
	
	
