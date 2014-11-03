/*int foo (int x) {
  return add(x);
}*/

.global foo1

	push %ebp
	mov %esp, %ebp

	push 8(%ebp)
	call  add
	add $4, %esp 
	
	mov %ebp, %esp
	pop %ebp
	ret 
