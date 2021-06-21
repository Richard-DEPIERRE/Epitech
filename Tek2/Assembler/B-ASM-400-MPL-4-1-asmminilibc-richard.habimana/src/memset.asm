BITS    64
GLOBAL  memset

SECTION .text

memset:
    mov rcx, 0
    cmp rdi, 0
    je memset_end
    cmp rdx, 0
    jg memset_loop
    jmp memset_end

memset_loop:
    cmp	rdx, 0
    je memset_end
    mov byte [rdi + rcx], sil
    inc rcx
    dec rdx
    jmp memset_loop

memset_end:
    mov rax, rdi
    ret