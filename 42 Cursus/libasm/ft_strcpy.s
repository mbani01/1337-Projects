section .text
    global _ft_strcpy
_ft_strcpy:
mov rcx,0
loop:
    cmp byte [rsi + rcx],0
    je endloop
    mov dl,byte [rsi + rcx]
    mov [rdi + rcx],dl
    inc rcx
    jmp loop
endloop:
    mov dl,0
    mov [rdi + rcx],dl
    mov rax,rdi
    ret