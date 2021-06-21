BITS    64
GLOBAL  strstr

SECTION .text

strstr:
    xor eax, eax
    mov rcx, 0
    cmp rdi, 0
    je strstr_equal
    cmp rsi, 0
    je strstr_equal
    jmp strstr_loop

strstr_increment:
    cmp al, 0
    je strstr_equal
    inc rdi

strstr_loop:
    mov al, byte [rdi + rcx]
    mov r8b, byte [rsi + rcx]
    cmp r8b, 0
    je strstr_finish
    cmp al, r8b
    jne strstr_increment
    inc rcx
    jmp strstr_loop

strstr_finish:
    mov rax, rdi
    jmp strstr_end

strstr_equal:
    mov rax, 0

strstr_end:
    ret