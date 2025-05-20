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
    push   rbp
    mov    rbp, rsp

    print_str msg1, msg1_len

    mov    rcx, count
    mov    r12, array

.loop:
    dec    rcx
    mov    eax, [r12]
    mov    rdi, tmpbuf
    num_to_str tmpbuf
    stringlength0 tmpbuf
    print_str tmpbuf, rcx

    print_str space, 1
    add    r12, 4
    cmp    rcx, 0
    jne    .loop

    pop    rbp
    ret

