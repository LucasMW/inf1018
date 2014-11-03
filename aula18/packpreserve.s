/*#include<stdlib.h>
double foo (double a, int b);
struct X {
  int vi;
  double vd;
  struct X *next;
};
double pack (struct X *px) {
  double acc = 0;
  while (px != NULL) {
    acc += foo(px->vd, px->vi);
    px = px->next;
  }
  return acc;
}*/

.global foo, pack

pack: 
		push %ebp
		mov %esp, %ebp /* início */
		push %ebx 
		
		sub $8, %esp /* aloque espaço para uma double */
		fldz  /* pilha recebe 0 */
		fstpl -8(%ebp) /* jogue 0 na double */

		mov 8(%ebp), %ecx   /* ecx=px */

L1:		cmp $0, %ecx /* px!=0 */
		je  L2 /* px==0, caia fora*/
		push %ecx /* protects %ecx from call */
		
		/* Call foo */
		push (%ecx) /* empilhe vi */		
		fldl 4(%ecx)  /* joga a vd pra st(0) */
		sub $8, %esp /* "Push Double" Aloque um double na pilha" */
		fstpl (%esp) /* Jogue o vd na pilha */
		call foo /* retorne no st(0) */
		add $12, %esp /* int  + double */

		pop %ecx /* Restaure %ecx */
		fldl -8(%ebp) /* Ponha a double no st(0) */ 
		
		faddp  /* st(0) +st(1) */
		fstpl -8(%ebp) /* Jogue o st(0) na double */ 
		
		mov 12(%ecx), %ecx /* px= px->next */
		jmp L1 /* volte pro loop */

L2:		fldl -8(%ebp) /* jogue a double para st(0) */
		/*add $8, %esp /*desaloque essa double */
		pop %ebx
		mov %ebp, %esp
		pop %ebp
		ret
