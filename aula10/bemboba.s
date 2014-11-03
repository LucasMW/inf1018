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
.globl	bemboba
bemboba:
	push	%ebp  /* Início da Função */
	mov	%esp, %ebp
	subl	$20,   %esp  # 3*4 +2*4 aloque espaço para os ints
	push	%ebx /* preserve %ebx */

	movl 	$0, %ebx /* i=0 */
	movl 	%ebp, %ecx  /* ecx consiga ebp */
	sub	$12,  %ecx  /* a= local[0] */
L1:	cmpl	$3,  %ebx   /* i<3 ? */
	jge 	L2	/* i>=3 caia fora */
	mov	8(%ebp), %edx /* edx = num */
	mov 	%edx, (%ecx) /* *a= num */
	addl	$4, %ecx /* incrementa  a */
	addl	$1, %ebx /* incrementa i */
	jmp 	L1
 L2:	pushl   $3     	/*argumento */
	movl 	%ebp, %ecx  /* ecx consiga ebp */
	sub	$12,  %ecx  /* a= &local[0] */
	push    %ecx    /* push &local[0] */

 	call 	addl     

	



Fim:	pop	%ebx
	mov	%ebp, %esp  /* fim de função */
	pop	%ebp
	ret



