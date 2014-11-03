.data

Sf:	.string "%d\n"		# string de formato para printf

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
	pushl	%ebx		/* salva ebx */
/*******/
	movl 	$1, %ebx /* i=1; */
L1:     cmpl    $10, %ebx /* teste i com 10 */
	jg 	L2 		/* i>10 Saia do loop */
        movl	%ebx, %eax	 /* s=i; */
	imull	%eax, %eax	/* s=s*s; segundo o cara */
	
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
	add	$1, %ebx /* i++ */
	jmp 	L1 /* Pule para L1*/    


/****** nao mexa - finalizacao!!!! */
L2:  	popl	%ebx		
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/
