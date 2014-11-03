
.global myopen, myread, mywrite, myclose

.text

myopen:	push %ebp
		mov  %esp, %ebp
		push %ebx
		mov 8(%ebp),%ebx
		mov 12(%ebp),%ecx
		mov 16(%ebp), %edx
		mov %edx, tamBufferAberto
		mov $5, %eax
		int $0x80
		pop %ebx
		mov %esp, %ebp
		pop %ebp
		ret
myread: push %ebp
		 mov  %esp, %ebp
		 push %ebx	
		 mov 8(%ebp),%ebx
		 mov 12(%ebp),%ecx
		 mov tamBufferAberto, %edx		 
 		 mov $3, %eax
		 int $0x80
		 pop %ebx	
		 mov %esp, %ebp
		 pop %ebp
		 ret

mywrite:

		push %ebp
		 mov  %esp, %ebp
			push %ebx
		 mov 8(%ebp),%ebx
		 mov 12(%ebp),%ecx
		 mov 16(%ebp), %edx		 
 		 mov $4, %eax
		 int $0x80
		 pop %ebx
		 mov %esp, %ebp
		 pop %ebp
		 ret
myclose:

		push %ebp
		 mov  %esp, %ebp
			push %ebx
		 mov 8(%ebp),%ebx
		 mov $6, %eax
		 int $0x80
		pop %ebx
		 mov %esp, %ebp
		 pop %ebp
		 ret

