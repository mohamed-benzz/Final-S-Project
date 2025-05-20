sumArray_func:
    xor     rax, rax        ; sum = 0
    xor     rcx, rcx        ; i = 0

.loop:
    cmp     rcx, rsi        ; compare i with length
    jge     .done           ; if i >= length, exit loop

    mov     rdx, [rdi + rcx*8] ; load arr[i] (each element is 8 bytes)
    add     rax, rdx        ; sum += arr[i]
    inc     rcx             ; i++
    jmp     .loop

.done:
    ret                     ; return sum in rax

