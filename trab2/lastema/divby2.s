.global divby2, intdiv

 divby2:
	push %ebp
	mov %esp, %ebp
	
	pushl $0xc1c2c3c4 /* amarrado */
	push 8(%ebp)
	call intdiv
	add $8 , %esp
	leave
	ret
	
	

