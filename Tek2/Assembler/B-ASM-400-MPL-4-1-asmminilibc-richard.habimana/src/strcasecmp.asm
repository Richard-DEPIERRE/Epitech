BITS    64
GLOBAL  strcasecmp

SECTION .text

strcasecmp:
    xor eax, eax
    mov rcx, 0
    cmp rdi, 0
    je strcasecmp_end
    cmp rsi, 0
    je strcasecmp_end
    jmp strcasecmp_loop

check_classic:
    cmp bl, dl
    jne strcasecmp_end

increment:
    inc rdi
    inc rsi

strcasecmp_loop:
    mov bl, byte [rdi]
    mov dl, byte [rsi]
    cmp bl, 0
    je strcasecmp_end_bl
    cmp dl, 0
    je strcasecmp_end_dl
    cmp bl, 'Z'
    jbe bl_is_capital

bl_is_not_capital:
    cmp bl, 'a'
    jb check_classic
    cmp bl, 'z'
    ja check_classic
    cmp dl, 'Z'
    jg check_classic
    add dl, 32
    jmp check_classic

bl_is_capital:
    cmp bl, 'A'
    jb check_classic
    cmp dl, 'Z'
    jbe check_classic
    add bl, 32
    jmp check_classic

strcasecmp_end_bl:
    cmp dl, 'Z'
    jg strcasecmp_end
    cmp dl, 'A'
    jb strcasecmp_end
    add dl, 32
    jmp strcasecmp_end

strcasecmp_end_dl:
    cmp bl, 'Z'
    jg strcasecmp_end
    cmp bl, 'A'
    jb strcasecmp_end
    add bl, 32
    jmp strcasecmp_end

strcasecmp_end:
    sub bl, dl
    movsx rax, bl
    ret