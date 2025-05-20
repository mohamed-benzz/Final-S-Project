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

