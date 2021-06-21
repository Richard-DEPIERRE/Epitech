BITS    64
GLOBAL  strcmp

SECTION .text

strcmp:
    xor eax, eax
    mov rcx, 0
    cmp rdi, 0
    je strcmp_equal
    cmp rsi, 0
    je strcmp_equal

strcmp_loop:
    mov bl, byte [rdi]
    mov dl, byte [rsi]
    cmp bl, 0
    je check_other
    cmp dl, 0
    je check_other_two
    cmp bl, dl
    jne strcmp_finish
    inc rcx
    inc rdi
    inc rsi
    jmp strcmp_loop

check_other:
    cmp dl, 0
    je strcmp_equal
    jmp strcmp_finish
check_other_two:
    cmp bl, 0
    je strcmp_equal

strcmp_finish:
    sub bl, dl
    movsx rax, bl
    cmp bl, 0
    jg positive
    cmp bl, 0
    je strcmp_equal
    jmp negative

positive:
    mov rax, 1
    jmp strcmp_end

negative:
    mov rax, -1
    jmp strcmp_end

strcmp_equal:
    xor eax, eax

strcmp_end:
    ret