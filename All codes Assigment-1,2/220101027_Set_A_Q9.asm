section .bss
    p resb 100
    ans resb 100
    k resb 1
    sz resd 1
section .data
    msg1 db 'Enter a string: ',0
    msg2 db 'Enter k: ',0
    msg3 db 'Result: ',0
    format_str db '%s',0
    format_char db '%c',0
    format_int db '%d',0
    newline db 10,0
    output db '%d',10,0
    true db 'True',10,0
    false db 'False',10,0


section .text
    global main
    extern printf,scanf,strlen

main:
    push ebp
    mov ebp, esp

    push msg1
    call printf
    add esp,4

    push p
    push format_str
    call scanf
    add esp,8

    push msg2
    call printf
    add esp,4

    push k
    push format_int
    call scanf
    add esp,8

    xor ecx,ecx
    mov esi, [k]
    dec esi


reverse:
    cmp ecx ,esi
    jge check

    mov al , [p+ecx]
    mov bl , [p+esi]

    mov [p+ecx],bl
    mov [p+esi],al

    inc ecx
    dec esi
    jmp reverse

check:
    xor ecx,ecx
    push p
    call strlen
    add esp,4
    mov [sz], eax

    mov esi, [sz]

check_loop:
    cmp ecx,esi
    jge print_true

    mov al,[p+ecx]

    cmp al, 'A'
    jl false_char
    cmp al,'Z'
    jle true_char
    cmp al,'a'
    jl false_char
    cmp al,'z'
    jle true_char
    jmp false_char

true_char: 
    inc ecx
    jmp check_loop
false_char:
    push msg3
    call printf
    add esp,4

    push p
    call printf
    add esp,4

    push newline
    call printf
    add esp,4

    push false
    call printf
    add esp,4

     mov esp,ebp
    pop ebp
    ret

print_true:

    push msg3
    call printf
    add esp,4

    push p
    call printf
    add esp,4

    push newline
    call printf
    add esp,4

    push true
    call printf
    add esp,4

    mov esp,ebp
    pop ebp
    ret


