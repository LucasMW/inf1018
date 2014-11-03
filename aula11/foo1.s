/*float foo (double a, float b) {
  return (a+b)*(a-b);
}*/
.global foo
foo:	push 	%ebp
	mov	%esp, %ebp
	

	flds	 16(%ebp) /*float b*/
	fldl	 8(%ebp) /*double a*/
	fsubp           /* a-b */
	fldl	8(%ebp) /*double a*/
	flds	16(%ebp) /*float b*/
	faddp  /* b+a */
	fmulp  
	
	
	movl 	%ebp, %esp
	pop  	%ebp
	ret
	
	
