; Set A - Q- 7

; Write a program to check whether a given number is pal in binary or not.

;To Run:
; nasm -f elf32 220101035_Set_A7.asm -o 220101035_Set_A7.o && gcc -m32 220101035_Set_A7.o -o 220101035_Set_A7 && ./220101035_Set_A7


section .bss
    user_input resb 5 
    bin resb 33 
    revBin resb 33 
    dec resd 1 

section .data
    ms db "Enter a decimal number: ", 0
    nl db 10, 0 ; newline character
    i db "%s", 0
    o db "%s", 10, 0
    true db "TRUE", 10, 0
    false db "FALSE", 10, 0

section .text
    extern printf, scanf
    global main

main:
    push ms
    call printf
    add esp, 4

    ; Read user input
    push user_input
    push i
    call scanf
    add esp, 8

    ; Convert string to integer
    mov esi, user_input ; source string
    xor eax, eax 
    xor ebx, ebx 

loop1:
    movzx ebx, byte [esi] ; get current character
    cmp bl, 10 ; 
    je done1 ; if newline, conversion is done
    cmp bl, 0 ;
    je done1 ; if null, conversion is done
    
    sub bl, '0' ; convert ASCII to number
    imul eax, 10 ; multiply accumulated value by 10
    add eax, ebx ; add new digit
    
    inc esi ; move to next character
    jmp loop1

done1:
    mov [dec], eax ; store final number

    ; Convert to binary
    mov ebx, [dec] 
    mov edi, bin ; destination for binary string
    xor ecx, ecx 

binn:
    mov eax, ebx 
    and eax, 1 ; get least significant bit
    add al, '0' 
    push eax ; save the digit
    inc ecx ; increment digit counter
    shr ebx, 1 ; shift right by 1 
    test ebx, ebx 
    jnz binn 

    ; Store binary string
    mov edi, bin
loop2:
    pop eax 
    mov [edi], al ; get digit
    inc edi 
    loop loop2 ; continue until all digits stored
    
    mov byte [edi], 0 ; terminate the string

    ; Print binary representation
    push bin
    push o
    call printf
    add esp, 8

    ; Create reversed string
    mov esi, bin ; source string
    mov ecx, edi 
    sub ecx, bin 
    mov edi, revBin ; destination for reversed string
    add edi, ecx 
    dec edi 
    mov edx, ecx 

;swap characters one by one
revv:
    mov al, [esi] 
    mov [edi], al 
    inc esi
    dec edi
    loop revv

    ; Compare strings
    mov esi, bin
    mov edi, revBin
    mov ecx, edx ; restore length

;check if the reversed string is same as the original string
loop3:
    mov al, [esi]
    mov bl, [edi]
    cmp al, bl
    jne nott
    inc esi
    inc edi
    loop loop3
    jmp pal

nott:
    push false
    call printf
    add esp, 4
    jmp exit

pal:
    push true
    call printf
    add esp, 4

exit:
    ret
