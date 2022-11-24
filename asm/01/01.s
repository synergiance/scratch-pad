section .text
	global _start ;linker needs this (gcc)
_start:  ;entry point
	mov edx,len ;put message length into edx
	mov ecx,msg ;put message into ecx (probably the pointer)
	mov ebx,1   ;file descriptor goes in ebx (stdout is 1)
	mov eax,4   ;put system call number into eax (sys_write is 4)
	int 0x80    ;call kernel

	mov edx,9   ;message length
	mov ecx,s2  ;message to write
	mov ebx,1   ;file descriptor (wonder if it can be carried over)
	mov eax,4   ;system call number            ||
	int 0x80    ;call kernel
	mov eax,1   ;sys_exit is 1
	int 0x80    ;call kernel

section .data
msg db 'Displaying 9 stars',0xa ;a message (do not understand this format)
len equ $ - msg ;apparently calculates the length of the message 'msg'
s2 times 9 db '*' ;I guess db = array?
