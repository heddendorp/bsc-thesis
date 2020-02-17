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
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movl	%edi, -116(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1024, -116(%rbp)
	movl	$1, -96(%rbp)
	movl	$2, -92(%rbp)
	movl	$3, -88(%rbp)
	movl	$4, -84(%rbp)
	movl	$5, -80(%rbp)
	movl	$6, -76(%rbp)
	movl	$7, -72(%rbp)
	movl	$8, -68(%rbp)
	movl	$9, -64(%rbp)
	movl	$10, -60(%rbp)
	movl	$11, -56(%rbp)
	movl	$12, -52(%rbp)
	movl	$13, -48(%rbp)
	movl	$14, -44(%rbp)
	movl	$15, -40(%rbp)
	movl	$16, -36(%rbp)
	movl	$17, -32(%rbp)
	movl	$18, -28(%rbp)
	movl	$19, -24(%rbp)
	movl	$20, -20(%rbp)
	movl	$200, -108(%rbp)
	movl	$0, -104(%rbp)
.L26:
	movl	-104(%rbp), %eax
	cmpl	%eax, -116(%rbp)
	jbe	.L2
	movl	-104(%rbp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, -100(%rbp)
	cmpl	$19, -100(%rbp)
	ja	.L3
	movl	-100(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L5(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L5(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L5:
	.long	.L4-.L5
	.long	.L6-.L5
	.long	.L7-.L5
	.long	.L8-.L5
	.long	.L9-.L5
	.long	.L10-.L5
	.long	.L11-.L5
	.long	.L12-.L5
	.long	.L13-.L5
	.long	.L14-.L5
	.long	.L15-.L5
	.long	.L16-.L5
	.long	.L17-.L5
	.long	.L18-.L5
	.long	.L19-.L5
	.long	.L20-.L5
	.long	.L21-.L5
	.long	.L22-.L5
	.long	.L23-.L5
	.long	.L24-.L5
	.text
.L4:
	movl	-96(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L6:
	movl	-92(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L7:
	movl	-88(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L8:
	movl	-84(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L9:
	movl	-80(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L10:
	movl	-76(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L11:
	movl	-72(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L12:
	movl	-68(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L13:
	movl	-64(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L14:
	movl	-60(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L15:
	movl	-56(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L16:
	movl	-52(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L17:
	movl	-48(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L18:
	movl	-44(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L19:
	movl	-40(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L20:
	movl	-36(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L21:
	movl	-32(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L22:
	movl	-28(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L23:
	movl	-24(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L24:
	movl	-20(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.L25
.L3:
	movl	$100, -108(%rbp)
	nop
.L25:
	addl	$1, -104(%rbp)
	jmp	.L26
.L2:
	movl	-108(%rbp), %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L28
	call	__stack_chk_fail@PLT
.L28:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	run, .-run
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
