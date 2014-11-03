.data
nums:	.char	65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0
Sf:	.string "%c"		# string de formato para printf
Sn:     .string "\n"            #string segunda

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
	pushl	%ebx		/* salva ebx */
/*******/
	movl $nums,%ecx


/****** nao mexa - finalizacao!!!! */
	popl	%ebx		
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/
