
; int n = r12
; int ctr = r13
; int var = r14
; int flag = r15
; int i = rbx

%macro printval 1 ; macro for printing values of registers for debugging purposes
    mov rdi, formatout
    mov rsi, %1
    call printf
%endmacro

global main
global isPrime
extern printf
extern scanf

section .text
main:
    ; pushing all the preserved registers to the stack before using them.
    push rbx
    push r12
    push r13
    push r14
    push r15

    ; printing the prompt for user to input the size of the array
    mov rdi, message1
    mov rax, 0
    call printf
    
    ; accept the size of the array as input from the user using scanf call
    mov rdi, formatin
    mov rsi, integer1
    call scanf

    movsx r12, dword[integer1] ; store the value of size of array in the r12 register

    ; initialize the registers r13 and r15 to zero.
    xor r13, r13
    xor r15, r15
outer:

    xor rbx, rbx ; set the value of rbx to zero
    cmp r13, r12 ; check if the size of array is equal to the user-given size.
    je print ; if equal, then proceed to printing the values of the array
    
    ; print the prompt for the user to enter the next value
    mov rdi, message2 
    mov rax, 0
    call printf

    ; accept the input from the user using scanf call
    mov rdi, formatin
    mov rsi, integer2
    call scanf

    movsx r14, dword[integer2] ; store the input from the user in the r14 register

    mov r15, 1 ; set the value of the flag to 1
    mov rax, r14 ; copy the value of the user input to the rax register. The rax register would be used in the isPrime function.

    call isPrime ; call the isPrime function which will make the value of al = 0 if the value in rax was not prime, and the value of al = 1 if the value of rax was prime.

    xor rbx, rbx ; reset the value of the rbx register
    cmp al, 0 ; if the value of al is zero, then the value in rax was not prime.
    je print_not_prime ; print "Not prime"

inner: ; this loop is used to check if a duplicate value is already present in the array
    cmp rbx, r13 ; check if the index is equal to the current size of the array
    je dabba ; if equal, then break out of this loop
    cmp r14d, [arr + 4*rbx] ; compare the element at the rbx index with the current element.
    je dabba2 ; if equal, then we don't add this element to the array. break out.
    inc rbx ; increase the value of the index
    jmp inner ; reiterate

dabba: ; this is run at the end of every iteration of the loop
    cmp r15, 1  ; checking if the flag is one
    jne outer ; if not equal, then break out and continue to next iteration of the loop
    mov [arr + 4*rbx], r14d ; else copy the value from r14 register to the array at the current index
    inc r13 ; increment the current size of the array
    jmp outer ; reiterate on the loop

dabba2: ; this is run incase a duplicate is found
    mov r15, 0 ; set the flag to zero
    jmp dabba ; break out of the loop

print: ; used to print the list of elements of the array
    cmp rbx, r12 ; check if the index is equal to the size of array
    je exit ; if equal, then exit

    ; print each value of the array one by one
    mov rdi, formatout 
    mov rsi, [arr+4*rbx]
    call printf

    inc rbx ; increment the iterator
    jmp print ; next iteration of the print loops

print_not_prime: ; to print the message if the number is "Not Prime"
    mov rdi, notprimemessage
    mov rax, 0
    call printf
    jmp outer

exit: 
    ; popping all the registers that were previously pushed to the stack
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    mov rax, 0 ; system call value to exit
    ret ; return

isPrime: ; function to check if a given number is prime or not
    ; input in the rax register
    ; output in the al portion of the rax register. 0 -- not prime, 1 -- prime
    cmp rax, 2
    jl not_prime ; if rax < 2, then it is not prime
    mov rcx, rax ; copy the value of rax to rcx 
    mov r10, rax ; store the value of rax to r10 since the value of rax gets modified.
    dec rcx ; now rcx = rax - 1
    check: ; this loop runs from rax - 1 to 2, and checks if there exists a factor. If there is a factor, then its not prime.
        mov rax, r10 ; copy the value back to rax
        cmp rcx, 1 ; if rcx is less than 2, then there was no factor found.
        jle prime ; so execute the prime label
        mov rdx, qword 0 ; reset the value in rdx
        idiv rcx ; using idiv to perform rax/rcx after which the quotient is stored in rax, and the remainder in rdx
        cmp rdx, 0 ; if the remainder is zero, means it was a factor
        je not_prime ; so not prime
        dec rcx ; else decrease the value of the factor
        jmp check ; reiterate through the loop
    prime: 
        mov al, 1 ; set al to 1 incase prime
        jmp end_isprime
    not_prime:
        mov al, 0 ; set al to 0 incase not prime
    end_isprime:
        ret

section .data
; data section to define the strings and the numbers
message1: db "Enter the number of values in array: ", 0
message2: db "Enter the next value: ", 0
formatin: db "%d", 0
formatout: db "%d ", 0
integer1: dd 0
integer2: dd 0
duplicate: db "This is a duplicate value.",10,0
notprimemessage: db "The number is not prime.",10, 0
debug: dd "Code ran till here.", 0

section .bss
; reserve the space of 400 bytes for the array
arr: resd 100