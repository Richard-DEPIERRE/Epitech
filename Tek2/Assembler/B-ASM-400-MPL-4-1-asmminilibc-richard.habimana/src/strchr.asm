BITS    64
GLOBAL  strchr

SECTION .text

strchr:
    mov rcx, 0
    cmp rdi, 0
    je strchr_null

strchr_loop:
    movsx edx, BYTE [rdi]
    cmp edx, 0
    je strchr_null
    cmp edx, esi
    je strchr_finish
    inc rcx
    inc rdi
    jmp strchr_loop

strchr_finish:
    mov rax, rdi
    jmp strchr_end

strchr_null:
    xor rax, rax

strchr_end:
    ret