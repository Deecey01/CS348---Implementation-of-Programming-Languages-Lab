
extern printf
extern scanf

section .data
    num1 dd 0
    num2 dd 0
    inf1 db "Enter first year: ", 0
    inf2 db "Enter second year: ", 0
    fmt db "%d", 0
    outptstring db "Non-leap years are:", 10, 0
    printfmt db "%d ", 0
    newline db 10, 0

section .text
global main

main:
    push ebp
    mov ebp, esp

    push inf1
    call printf
    add esp, 4
    
    push num1
    push fmt
    call scanf
    add esp, 8

    push inf2
    call printf
    add esp, 4
    
    push num2
    push fmt
    call scanf
    add esp, 8
    
    push outptstring
    call printf
    add esp, 4

    mov ecx, [num1]
;/////////////////////////////////////////////
loop_years:
    mov eax, ecx
    cmp ecx, [num2]
    jg print_final_newline

    xor edx, edx
    mov ebx, 4
    div ebx
    cmp edx, 0
    je check_100
    jmp print_year
;///////////////////////////////////////////////
check_100:
    mov eax, ecx
    xor edx, edx
    mov ebx, 100
    div ebx
    cmp edx, 0
    je check_400
    jmp next_year
;/////////////////////////////////////////////
check_400:
    mov eax, ecx
    xor edx, edx
    mov ebx, 400
    div ebx
    cmp edx, 0
    je next_year
    jmp print_year
;///////////////////////////////////////////
print_year:
    push ecx
    push ecx
    push printfmt
    call printf
    add esp, 8
    pop ecx
;////////////////////////////////////////
next_year:
    inc ecx
    jmp loop_years
;////////////////////////////////////
print_final_newline:
    push newline
    call printf
    add esp, 4

    mov esp, ebp
    pop ebp
    
    mov eax, 1
    xor ebx, ebx
    int 0x80

