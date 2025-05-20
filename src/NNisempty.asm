section .text
    global isEmpty_func

isEmpty_func:
    test    rdi, rdi      ; check if rdi (pointer) is NULL
    je      .empty        ; jump if zero (NULL)
    mov     al, byte [rdi] ; load the byte at pointer rdi into al
    test    al, al        ; test if that byte is zero
    je      .empty        ; if zero, jump to empty
    mov     eax, 0        ; return 0 (not empty)
    ret

.empty:
    mov     eax, 1        ; return 1 (empty)
    ret

