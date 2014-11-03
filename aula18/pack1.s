/*struct X1 {
  int vi;
  float vf;
};

double pack1 (struct X1 *px, int n) {
  double acc = 0;
  int i;
  for (i=0;i<n;i++)
    acc += foo(px[i].vf, px[i].vi);
  return acc;
}*/

.global foo, pack1

pack1:

		push %ebp
		mov %esp, %ebp /* início */
		push %ebx 
		
		sub $8, %esp /* aloque espaço para uma double */
		fldz  /* pilha recebe 0 */
		fstpl -12(%ebp) /* jogue 0 na double */

		mov 8(%ebp), %ecx   /* ecx=&px[0] */
		mov 12(%ebp), %eax /* int n */
		mov $0, %ebx /* %ebx=i */

L1:		cmp %eax, %ebx /* i<n */
		jge  L2 /* i>=n, caia fora*/
		push %ecx /* protects from call */
		push %eax
		push %edx

		/* Call foo */
		mov %ebx, %edx /* edx = i;*/
		shll $3, %edx /* edx*8 */
		add %ecx, %edx
		push (%edx) /*push vi*/
		sub $8, %esp
		flds 4(%edx)
		fstpl (%esp)
		call foo
		add $12, %esp
		pop %edx /* Restaure  */
		pop %eax
		pop %ecx
		fldl -12(%ebp) /* Ponha a double no st(0) */ 
		
		faddp  /* st(0) +st(1) */
		fstpl -12(%ebp) /* Jogue o st(0) na double */ 
		
		
		add $1,%ebx /* i++ */
		jmp L1 /* volte pro loop */

L2:		fldl -12(%ebp) /* jogue a double para st(0) */
		/*add $8, %esp /*desaloque essa double */
		add $8, %esp
		pop %ebx
		
		mov %ebp, %esp
		pop %ebp
		ret






