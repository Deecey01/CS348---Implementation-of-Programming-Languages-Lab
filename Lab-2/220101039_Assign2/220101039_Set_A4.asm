;-------------------------------------
; NAME: DIVYANSH CHANDAK (220101039)
; Design a calculator to perform various operations of floating point numbers.
; Your design should follow the following convention:
; 1. Addition
; 2. Subtraction
; 3. Multiplication
; 4. Division
;-------------------------------------

; How to run? 
; Run the following commands:
; nasm -f elf32 220101039_Set_A4.asm -o 220101039_Set_A4.o
; gcc -no-pie -m32 220101039_Set_A4.o -o 220101039_Set_A4
; ./220101039_Set_A4 

extern printf
extern scanf

section .data
    float_fmt db "%f",0
    int_fmt db "%d",0
    output_fmt db "%f", 10, 0
    output_msg db "The result after operation is : ", 0
    prompt1 db "Enter first float number : ", 0
    prompt2 db "Enter second float number : ", 0
    prompt3 db "Enter 1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division : ", 0
    num1 dd 0.0
    num2 dd 0.0
    choice dd 0
    division_by_zero db "Exception(Division by zero error)", 10, 0
    open_error db "Error: Cannot open file.", 0xA, 0

section .bss
    buffer resb 1024      ; buffer for reading elements
section .text
    global main

main:
;print msg for 1st input
    push prompt1
    call printf
    add esp, 4 ;adjusting stack pointer
;read 1st float no.
    push num1
    push float_fmt
    call scanf
    add esp, 8 ;adjusting stack pointer
;print msg for 2nd input
    push prompt2
    call printf
    add esp, 4 ;adjusting stack pointer
;read 2nd float no.
    push num2
    push float_fmt
    call scanf
    add esp, 8 ;adjusting stack pointer

;print the choices for an operation
    push prompt3
    call printf
    add esp, 4 ;adjusting stack pointer
;read the choice entered(integer)
    push choice
    push int_fmt
    call scanf
    add esp, 8 ;adjusting stack pointer
;print the result message
    push output_msg
    call printf
    add esp, 4 ;adjusting stack pointer

    fld dword [num1]
    fld dword [num2]
;compare the choice entered with the 4 options available
    mov ecx, [choice]
    cmp ecx, 1
    je addition
    cmp ecx, 2
    je subtraction
    cmp ecx, 3
    je multiplication
    cmp ecx, 4
    je division
    jmp exit_program

multiplication:
    fmulp st1, st0      
    sub esp, 8          
    fstp qword [esp]    
    push output_fmt
    call printf
    add esp, 12
    jmp exit_program

subtraction:
    fsubp st1, st0      
    sub esp, 8    
    fstp qword [esp]    
    push output_fmt
    call printf
    add esp, 12
    jmp exit_program

division:
    fldz                
    fcomip st0, st1     
    je condition_for_zero_division           
    fdivp st1, st0      
    sub esp, 8          
    fstp qword [esp]    
    push output_fmt
    call printf
    add esp, 12
    jmp exit_program

addition:
    ; movss xmm0, dword [num1]
    ; movss xmm1, dword [num2]
    ; addss xmm1, xmm0
    ; push xmm1
    faddp st1, st0
    sub esp, 8
    fstp qword [esp]
    push output_fmt
    call printf
    add esp, 12
    jmp exit_program

condition_for_zero_division:
    fstp st0            
    fstp st0
    push division_by_zero
    call printf
    add esp, 4

exit_program:
    mov eax, 1
    ; xor ebx, ebx
    int 0x80