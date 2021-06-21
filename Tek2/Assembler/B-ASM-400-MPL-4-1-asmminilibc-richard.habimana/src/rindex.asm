BITS 64

section .text
global rindex

rindex:
    xor rcx, rcx
    cmp rdi, 0
    je rindex_ending
    jmp set

increment:
    inc rcx

set:
    mov dl, BYTE [rdi+rcx]
    cmp dl, 0
    jne increment
    jmp loop

decrement:
    cmp rcx, 0
    je rindex_ending
    dec rcx

loop:
    movsx edx, BYTE [rdi+rcx]
    cmp edx, esi
    jne decrement
    mov rax, rdi
    add rax, rcx
    jmp rindex_end

rindex_ending:
    xor rax, rax

rindex_end:
    ret