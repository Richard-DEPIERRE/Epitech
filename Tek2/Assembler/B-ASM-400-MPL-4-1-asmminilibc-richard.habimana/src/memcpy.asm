BITS    64
GLOBAL  memcpy

SECTION .text

memcpy:
    mov rcx, 0
    mov r8, rdi
    cmp rdi, 0
    je memcpy_end
    cmp rsi, 0
    je memcpy_end
    cmp rdx, 0
    jg memcpy_loop
    jmp memcpy_end

memcpy_loop:
    cmp dl, 0
    jz memcpy_end
    cmp	byte [rsi], 0
    je memcpy_end
    cmp	byte [rdi], 0
    je memcpy_end
    dec dl
    mov dh, byte [rsi]
    mov byte [rdi], dh
    inc rsi
    inc rdi
    jmp memcpy_loop

memcpy_end:
    mov rax, r8
    ret