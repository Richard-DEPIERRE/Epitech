BITS    64
GLOBAL  strncmp

SECTION .text

strncmp:
    xor eax, eax
    mov rcx, 0
    cmp rdx, 0
    je strncmp_equal
    cmp rdi, 0
    je strncmp_end
    cmp rsi, 0
    je strncmp_end

strncmp_loop:
    mov al, [rdi + rcx]
    mov r8b, [rsi + rcx]
    cmp al, 0
    je strncmp_finish
    cmp r8b, 0
    je strncmp_finish
    cmp al, r8b
    jne strncmp_finish
    inc rcx
    cmp rdx, rcx
    je strncmp_finish
    jmp strncmp_loop

strncmp_finish:
    sub al, r8b
    movsx rax, al
    jmp strncmp_end

strncmp_equal:
    mov rax, 0

strncmp_end:
    ret