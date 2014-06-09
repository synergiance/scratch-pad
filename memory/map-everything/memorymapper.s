	.file	"memorymapper.cpp"
	.globl	address
	.bss
	.align 8
address:
	.space 8
	.section .rdata,"dr"
.LC0:
	.ascii "%p\12\0"
	.text
	.globl	_Z10sigHandleri
	.def	_Z10sigHandleri;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10sigHandleri
_Z10sigHandleri:
.LFB7:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$11, 16(%rbp)
	jne	.L2
	movq	address(%rip), %rax
	addq	$1, %rax
	movq	%rax, address(%rip)
	movq	address(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
.L2:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	leaq	_Z10sigHandleri(%rip), %rdx
	movl	$11, %ecx
	call	signal
.L5:
	movq	address(%rip), %rax
	addq	$1, %rax
	movq	%rax, address(%rip)
	movq	address(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
	movq	address(%rip), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	jmp	.L5
	.seh_endproc
	.ident	"GCC: (GNU) 4.8.2"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	signal;	.scl	2;	.type	32;	.endef
