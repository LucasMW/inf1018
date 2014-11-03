/*int foo (int x) {
  return x+1;
}*/
.global foo

	push %ebp
	mov  %esp, %ebp

	mov 8(%ebp), %eax
	add $1, %eax
	
	mov  %ebp, %esp
	pop  %ebp
	ret

