

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

