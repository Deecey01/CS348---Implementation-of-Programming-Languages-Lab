section .data
    msg1 db 'Enter a string: ',0
    format_str db '%s',0
    format_char db '%c',0
    format_int db '%d',0
    newline db 10,0
    output db '%d',10,0
    ; true db 'True',10,0
    ; false db 'False',10,0

section .bss
    str1 resb 100
    str2 resb 100
    sz1 resd 1
    sz2 resd 1

section .text
    global main
    extern printf , scanf, strlen

main:
    push ebp
    mov ebp, esp

    push msg1
    call printf
    add esp,4

    push str1
    push format_str
    call scanf
    add esp,8

    push msg1
    call printf
    add esp,4

    push str2
    push format_str
    call scanf
    add esp,8

    push str1
    call strlen
    add esp,4
    mov [sz1],eax

    push str2
    call strlen
    add esp,4
    mov [sz2],eax

    xor ecx,ecx
    xor esi,esi

check:
    cmp esi,[sz2]
    jge true
    cmp ecx,[sz1]
    jge false

    mov al,[str1+ecx]
    mov bl,[str2+esi]

    cmp al,bl
    jne restart

    inc ecx
    inc esi
    jmp check

restart:
    xor esi,esi
    inc ecx
    jmp check

false:
    mov ecx ,-1
    push ecx
    push output
    call printf
    add esp,8

    mov esp,ebp
    pop ebp
    ret

true:
    sub ecx, [sz2]
    ; push dword [sz2]
    ; push output
    ; call printf
    ; add esp,8

    push ecx
    push output
    call printf
    add esp,8

    mov esp,ebp
    pop ebp
    ret



    


