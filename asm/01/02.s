 .global _start #linker needs this (gcc)
_start:  #entry point
	mov $len, %rdx #put message length into edx
	mov $len, %rcx #put message into ecx (probably the pointer)
	mov $1,   %rbx #file descriptor goes in ebx (stdout is 1)
	mov $4,   %rax #put system call number into eax (sys_write is 4)
	int $0x80      #call kernel

	mov $9,   %rdx #message length
	mov $s2,  %rcx #message to write
	mov $1,   %rbx #file descriptor (wonder if it can be carried over)
	mov $4,   %rax #system call number            ||
	int $0x80      #call kernel
	mov $1,   %rax #sys_exit is 1
	int $0x80      #call kernel

 .data
msg:
    .ascii "Displaying 9 stars"
    len = . - msg #apparently calculates the length of the message 'msg'
s2:
    .ascii "*********"
