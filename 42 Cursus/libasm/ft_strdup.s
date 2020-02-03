section .text
extern _malloc
extern _ft_strlen
extern _ft_strcpy
global  _ft_strdup
_ft_strdup:
    push rdi
    call _ft_strlen
    inc rax
    mov rdi,rax
    call _malloc
    pop rsi
    mov rdi,rax
    call _ft_strcpy
    ret