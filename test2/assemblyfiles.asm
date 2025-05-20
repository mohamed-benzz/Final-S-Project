section .text
    global gcd_asm

gcd_asm:
    cmp rdi, rsi
    jge .continue
    xchg rdi, rsi

.continue:
    cmp rsi, 0
    je .done

    xor rdx, rdx
    mov rax, rdi
    div rsi

    mov rdi, rsi
    mov rsi, rdx
    call gcd_asm
    ret

.done:
    mov rax, rdi
    ret

_____________________________________________________
section .text
global max_asm

max_asm:
test rsi, rsi
    jle .done
    mov rdx, rdi
    mov rcx, rsi
    mov eax, [rdx]
    xor r8, r8
.loop:
    inc r8
    cmp r8, rcx
    jge .done
    mov ebx, [rdx + r8*4]
    cmp ebx, eax
    jle .loop
    mov eax, ebx
    jmp .loop
.done:
    ret











_______________________________________

section .data
pal db "THIS IS PALINDROME!", 10
pal_len equ $ - pal

nopal db "THIS IS NOT PALINDROME!", 10
nopal_len equ $ - nopal

section .text
global ispalindrome_asm

ispalindrome_asm:
    xor rcx, rcx
.loop:
    cmp rcx, rdx
    jge .is_palindrome_ok

    mov al, [rdi + rcx]
    mov bl, [rdi + rsi]
    cmp al, bl
    jne .not_palindrome

    inc rcx
    dec rsi
    jmp .loop

.is_palindrome_ok:
    mov rax, 1
    mov rdi, 1
    mov rsi, pal
    mov rdx, pal_len
    syscall
    ret

.not_palindrome:
    mov rax, 1
    mov rdi, 1
    mov rsi, nopal
    mov rdx, nopal_len
    syscall
    ret



