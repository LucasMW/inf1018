.data
nums:	.byte	65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0
Sf:	.string "Tamanho da string %d"		# string de formato para printf
Sn:     .string "\n"            #string segunda

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
	pushl	%ebx		/* salva ebx */
/*******/
	movl 	$nums, %ecx /* char* pc = s2; */
	movl    $0   , %ebx /* i=0; */
L1:     cmpb    $0, (%ecx)  /* teste *pc */
	je 	L2          /* se é nulo saia do loop */
	add	$1, %ecx /* p++ */
	add 	$1, %ebx /* i++ */
	jmp 	L1 /* Pule para L1*/    

L2:     movl	%ebx, %eax	 /* Imprimirá o valor de i */
/****** nao mexa - imprime o valor de %eax !!!! */
/* pode estragar o valor de %eax           ******/
        pushl   %ecx
        pushl   %edx
        pushl   %eax
        pushl   $Sf
 	call	printf	
        addl    $8, %esp
        popl   %edx
        popl   %ecx
/*******/
/****** nao mexa - imprime o valor de %eax !!!! */
/* pode estragar o valor de %eax           ******/
    pushl   %ecx
        pushl   %edx
        pushl   %eax
        pushl   $Sn
 	call	printf	
        addl    $8, %esp
        popl   %edx
        popl   %ecx
/*******/
/****** nao mexa - finalizacao!!!! */
	popl	%ebx		
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/
