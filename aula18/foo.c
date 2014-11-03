/*double foo (double a, int b) {
  return a * (-b);
}*/

.global foo

.text
		push %ebp
		mov %esp,%ebp

		fildl 16(%ebp) /*b */
		fildl 16(%ebp) /*b */
		fildl 16(%ebp) /*b */ /* same as fchs */
		fsubp   	/* b-b */
		fsubp      /*0-b */
		fldl  8(%ebp) /*double a */
		fmulp  /*a * -b */

		mov %ebp, %esp
		pop %ebp
		ret
