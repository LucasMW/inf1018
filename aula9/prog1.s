/*void printstring(char * p)
{			//mov8(%ebp),%ecx
			cmpl $0,
for(p;*p;p++)
putchar(*p);
putchar('\n');

}
*/


      
.text

.globl	printstring
printstring:	
	push	%ebp  /* Início da Função */
	mov	%esp, %ebp
	push    %ebx /* Preserve %ebx */
	

	movl	8(%ebp), %ecx /* %ecx=p */
L1:	cmpb	$0, (%ecx) /* *p==0? */
	jz	L2	/* *p=0 cai fora */
	push    %ecx
	push    (%ecx)  /* putchar(*p) */
	call	putchar
        addl    $4, %esp /*Desempilhe (%ecx) */
	pop 	%ecx
	add   	$1, %ecx /* p++ */
	jmp     L1        /* volte ao loop */
L2:	push 	$10     /* '\n' */
 	call 	putchar  	
	
	/*retorne */

Fim:	pop 	%ebx /*restaure ebx */
	mov	%ebp, %esp  /* fim de função */
	pop	%ebp
	ret
