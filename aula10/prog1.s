/*
int bemboba (int num) {
  int local[3];
  int *a;
  int i;

  for (i=0,a=local;i<3;i++) {
    *a = num;
    a++;
  }
  return addl (local, 3);
}
*/

.data

Sf:	.string "%d"
Sd: 	.string "numero: "	# string de formato para printf

.text
.globl	novonum
novonum:
	push	%ebp  /* Início da Função */
	mov	%esp, %ebp
	subl	$4,   %esp  #aloque espaço para o int
	
	movl 	$90, -4(%ebp) /* atribua 90 a minhalocal */
 	pushl   $Sd     	/* printf("numero: ") */
 	call 	printf       
	mov 	%ebp, %ecx      /* ecx recebe frame */     
	sub 	$4, %ecx        /* aponte para minha local */
	push	%ecx
	push 	$Sf             
	call 	scanf 
	mov 	-4(%ebp), %eax
	



Fim:	
	mov	%ebp, %esp  /* fim de função */
	pop	%ebp
	ret



