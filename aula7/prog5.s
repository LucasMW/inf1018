.data
nums:	.int	65, -105, 111, 34
Sf:	.string "Soma=%d\n"		# string de formato para printf

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
	pushl	%ebx		/* salva ebx */
/*******/
	movl 	$0, %ebx /* i=0; */
	movl 	$0, %edx /* s=0; */
L1:     cmpl    $4, %ebx /* teste i com 4 */
	jg 	L2 		/* i>4 Saia do loop */
	movl 	%ebx, %ecx      /*temp =i; */
	shll 	$2, %ecx        /* temp*=4 */   
        addl	$nums, %ecx	 /* temp=+=&nums[0]; */
	movl 	(%ecx), %edx	/* s=*temp */
	addl 	$1, %ebx        /* i++ */
	jmp     L1
L2:	movl    %edx, %eax     /* Imprima */ 
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
	  


/****** nao mexa - finalizacao!!!! */
  	popl	%ebx		
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/
