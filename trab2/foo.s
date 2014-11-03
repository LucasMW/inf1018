
.global foo, boo

foo:	push %ebp
	mov %esp, %ebp

	push 12(%ebp)
	push 8(%ebp)
	call boo
	add $8, %esp

	mov %ebp, %esp
	pop %ebp
