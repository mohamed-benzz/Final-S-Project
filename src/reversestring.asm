%include "lib.enc"
section .data
	msg1 db "Enter your string:"
	msg1_len equ $-msg1
	msg2 db "Your string in reverse is :"
	msg2_len equ $-msg2
section .bss
	input resb 25
section .text
	global _start
_start:
	print_str msg1,msg1_len
	user_input input,25
	stringlength10 input
	mov r15,rcx
	call rev
	print_str msg2,msg2_len
	print_str input,r15
	exit 0


rev:
	mov rsi,input
loop1:
	dec rcx
	movzx rax,byte [rsi]
	push rax
	inc rsi
	cmp rcx,0
	jne loop1
	mov rsi,input
loop2:
	inc rcx
	pop rax
	mov byte [rsi],al
	inc rsi
	cmp rcx,r15
	jne loop2
ret

