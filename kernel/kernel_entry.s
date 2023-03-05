.code32
.text

.globl _start

_start:
	xor %ebp, %ebp
	mov (%esp), %edi
	lea 4(%esp), %esi
	lea 8(%esp, %edi, 4), %edx
	xor %eax, %eax
	call main

	mov %eax, %edi
	xor %eax, %eax
	# call _exit
