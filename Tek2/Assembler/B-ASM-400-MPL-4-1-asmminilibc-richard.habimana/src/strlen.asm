BITS    64
GLOBAL  strlen

SECTION .text

strlen:
    mov rcx, 0
    cmp rdi, 0
    je strlen_end

strlen_loop:
    cmp [rdi], byte 0
    je strlen_end
    inc rcx
    inc rdi
    jmp strlen_loop

strlen_end:
    mov rax, rcx
    ret