section .text
    global _ft_strlen
_ft_strlen:
    mov rcx, 0
loop:
    cmp byte [rdi], 0
    je endLoop
    inc rdi
    inc rcx
    jmp loop
endLoop:
    mov rax,rcx
    ret