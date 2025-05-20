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

