section .text
    global  _ft_strcmp
_ft_strcmp:
loop:
    cmp byte [rdi],0
    je endloop
    cmp byte [rsi],0
    je endloop
    movzx rcx,byte[rsi]
    movzx rdx,byte[rdi]
    cmp rcx,rdx
    jne endloop
    inc rdi
    inc rsi
    jmp loop
endloop:
    push rcx
    movzx rcx,byte[rdi]
    movzx rdx,byte[rsi]
    sub rcx,rdx
    mov rax,rcx
    pop rcx
    ret

