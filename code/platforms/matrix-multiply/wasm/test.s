	.file	"test.cpp"
	.text
	.globl	run
	.type	run, @function
run:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$1616, %edx
	movl	$2, %r10d
	movl	$1, %r8d
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	subq	%rdx, %rsp
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	subq	%rdx, %rsp
	movq	%rsp, %rbx
	subq	%rdx, %rsp
	movq	%rax, %rdi
	leaq	3(%rsp), %rsi
	movq	%rbx, %r9
	movq	%rax, %r11
	shrq	$2, %rsi
	leaq	0(,%rsi,4), %rdx
.L3:
	xorl	%ecx, %ecx
.L2:
	movl	%r8d, (%r11,%rcx)
	movl	%r10d, (%r9,%rcx)
	addq	$4, %rcx
	cmpq	$80, %rcx
	jne	.L2
	incl	%r8d
	addq	$80, %r11
	incl	%r10d
	addq	$80, %r9
	cmpl	$21, %r8d
	jne	.L3
	addq	$1600, %rax
.L6:
	movq	%rbx, %r9
	xorl	%r8d, %r8d
.L5:
	xorl	%ecx, %ecx
	xorl	%r10d, %r10d
.L4:
	imulq	$80, %rcx, %r11
	movl	(%r9,%r11), %r11d
	imull	(%rdi,%rcx,4), %r11d
	incq	%rcx
	addl	%r11d, %r10d
	cmpq	$20, %rcx
	jne	.L4
	movl	%r10d, (%rdx,%r8)
	addq	$4, %r8
	addq	$4, %r9
	cmpq	$80, %r8
	jne	.L5
	addq	$80, %rdi
	addq	$80, %rdx
	cmpq	%rax, %rdi
	jne	.L6
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	movl	0(,%rsi,4), %eax
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	run, .-run
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	jmp	run
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
