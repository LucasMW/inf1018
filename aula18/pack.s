	.file	"pack.c"
	.text
	.globl	pack
	.type	pack, @function
pack:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	fldz
	fstpl	-16(%ebp)
	jmp	.L2
.L3:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	fldl	4(%edx)
	movl	%eax, 8(%esp)
	fstpl	(%esp)
	call	foo
	fldl	-16(%ebp)
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 8(%ebp)
.L2:
	cmpl	$0, 8(%ebp)
	jne	.L3
	fldl	-16(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	pack, .-pack
	.ident	"GCC: (GNU) 4.8.2 20131212 (Red Hat 4.8.2-7)"
	.section	.note.GNU-stack,"",@progbits
