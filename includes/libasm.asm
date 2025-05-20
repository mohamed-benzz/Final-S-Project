
section .text
    global lcm_asm

lcm_asm:
    ; rdi = a, rsi = b
    mov     r8, rdi            ; r8 = a
    mov     r9, rsi            ; r9 = b
    cmp     r8, r9
    jle     .call
    mov     r11, r8
    mov     r8, r9
    mov     r9, r11

.call:
    mov     r11, r9
    call    lcm_calc
    sub     r9, r11
    mov     rax, r9
    ret

lcm_calc:
    xor     rdx, rdx
    mov     rax, r9
    div     r8
    add     r9, r11
    cmp     rdx, 0
    jne     lcm_calc
    ret


section .text
    global revnum_asm

; void revnum_asm(char *buf, int len)
revnum_asm:
    push   rbp
    mov    rbp, rsp

    mov    r8, rdi        ; r8 = buf
    mov    rcx, rsi       ; rcx = len
    lea    r10, [r8 + rcx]
    dec    r10            ; point to last character

.rev_loop:
    cmp    r8, r10
    jge    .done
    movzx  r9, byte [r8]
    movzx  r11, byte [r10]
    mov    byte [r10], r9b
    mov    byte [r8], r11b
    inc    r8
    dec    r10
    jmp    .rev_loop

.done:
    pop    rbp
    ret



section .text
    global rev_asm           


rev_asm:
    push   rbp               
    mov    rbp, rsp         

    
    mov    r15, rdi          
    mov    rcx, rsi          

    test   rcx, rcx          
    jle    .done            

    xor    rdx, rdx          
    dec    rcx               

.loop:
    cmp    rdx, rcx          
    jge    .done             
    mov    al, [r15 + rdx]
    mov    bl, [r15 + rcx]
    mov    [r15 + rdx], bl
    mov    [r15 + rcx], al

    inc    rdx               ; i++
    dec    rcx               ; j--
    jmp    .loop

.done:
    pop    rbp               ; standard epilogue, restores both RSP and RBP
    ret



%include "lib.enc"

section .data
    msg1      db "The output array (specified in the program) is:",10
    msg1_len  equ $ - msg1
    array      dd 11,1,8,2,4,0,5,1,20,5
    count      equ ($ - array) / 4
    space     db " ",0

section .bss
    tmpbuf    resb 12

section .text
    global printarray_asm

printarray_asm:

    print_str msg1, msg1_len

    mov    r15, count
    mov    r12, array

.loop:
    dec    r15
    mov    eax, [r12]
    mov    rdi, tmpbuf
    num_to_str tmpbuf
    stringlength0 tmpbuf
    print_str tmpbuf, rcx

    print_str space, 1
    add    r12, 4
    cmp    r15, 0
    jne    .loop

    ret


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






