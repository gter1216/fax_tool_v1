	.file	"test2.c"
	.section	.rodata
.LC0:
	.string	"%02d:%02d:%02d.%03d ---> "
	.text
	.globl	get_ts_tag
	.type	get_ts_tag, @function
get_ts_tag:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$144, %rsp
	movq	%rdi, -136(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-112(%rbp), %rax
	movq	%rax, -120(%rbp)
	movq	-136(%rbp), %rax
	movl	12(%rax), %edi
	movq	-136(%rbp), %rax
	movl	8(%rax), %esi
	movq	-136(%rbp), %rax
	movl	4(%rax), %ecx
	movq	-136(%rbp), %rax
	movl	(%rax), %edx
	movq	-120(%rbp), %rax
	movl	%edi, %r9d
	movl	%esi, %r8d
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf
	movq	-120(%rbp), %rax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	get_ts_tag, .-get_ts_tag
	.section	.rodata
.LC1:
	.string	"Hello World!"
.LC2:
	.string	"Test1: %s\n"
.LC3:
	.string	"Test2: %s\n"
.LC4:
	.string	"Test3: %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC1, %edi
	call	puts
	movl	$16, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$12, (%rax)
	movq	-16(%rbp), %rax
	movl	$21, 4(%rax)
	movq	-16(%rbp), %rax
	movl	$32, 8(%rax)
	movq	-16(%rbp), %rax
	movl	$341, 12(%rax)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	get_ts_tag
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
