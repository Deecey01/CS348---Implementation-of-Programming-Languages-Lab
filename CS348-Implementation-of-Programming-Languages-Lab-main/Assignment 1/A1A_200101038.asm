; int leap = r12
; int currYear = r12
; int endyear = r13
; dec r12

%macro modulo 2 ; macro to calculate the modulo of %1 divided by %2
    mov rax, %1
    mov rdx, 0
    push rbx
    mov rbx, %2
    idiv rbx
    pop rbx
%endmacro

global main
extern printf
extern scanf

section .text
main:
    ; push the preserved register and the rbp to the stack (to align the stack as well)
    push rbp
    push r12
    push r13

    ; print the prompt to enter the start year
    mov rdi, message1
    mov rax, 0
    call printf
    
    ; accept the input from the user for the start year
    mov rdi, formatin
    mov rsi, integer1
    call scanf 

    ; print prompt to enter the end year
    mov rdi, message2
    mov rax, 0
    call printf

    ; accept the input from the user for the end year
    mov rdi, formatin
    mov rsi, integer2
    call scanf

    ; copy over the inputs to the registers
    movsx r12, dword[integer1]
    movsx r13, dword[integer2]

    ; decrement the value of the start year, to align with the loop iteration
    dec r12

outer:
    inc r12
    cmp r12, r13
    jg exit ; check if curryear is <= endyear else break
    
    modulo r12, 400 ; modulo stores the result in rdx
    cmp rdx, 0
    je outer ; if curryear % 400 == 0 then leap year
    
    modulo r12, 4
    cmp rdx, 0
    je condition ; if curryear % 4 == 0 then go and check for 100
    
    mov rdi, formatout
    mov rsi, r12
    call printf ; if curryear % 4 != 0 then no leap year
    
    jmp outer


condition:
    modulo r12, 100
    cmp rdx, 0
    jne outer ; if curryear % 100 == 0 also then its not leap year
    
    mov rdi, formatout
    mov rsi, r12
    call printf

    jmp outer ; else leap year

exit:
    ; pop the value from the stack back into the registers
    pop r12
    pop r13
    pop rbp
    mov rax, 0
    ret


section .data
message1: 
    db "Enter the start year: ", 0
message2: 
    db "Enter the end year: ", 0
formatin: 
    db "%d", 0
formatout: 
    db "%d ", 0
integer1: 
    dd 0
integer2: 
    dd 0