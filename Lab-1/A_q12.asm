;-------------------------------------
; NAME: DIVYANSH CHANDAK (220101039)
; SET-A-Q12
; Write a program which takes two numbers as inputs and shows all the prime numbers
; in between those numbers and also finds the multiplication between the sum of
; primes in even position and primes in odd position.
;-------------------------------------


section .data
    msg1 db "Enter first number (n1): ", 0
    msg2 db "Enter second number (n2): ", 0
    primes db "Primes: ", 0
    result db "Multiplication = ", 0
    newline db 0xA, 0xD, 0
    buffer db 0

section .bss
    n1 resb 4
    n2 resb 4
    odd_sum resd 1
    even_sum resd 1
    multiplication resd 1

section .text
    global _start

_start:
    ; Print "Enter first number"
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, 22
    int 0x80

    ; Read n1
    mov eax, 3
    mov ebx, 0
    mov ecx, n1
    mov edx, 4
    int 0x80

    ; Convert n1 from ASCII to integer
    mov ecx, n1
    call atoi
    mov [n1], eax

    ; Print "Enter second number"
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, 22
    int 0x80

    ; Read n2
    mov eax, 3
    mov ebx, 0
    mov ecx, n2
    mov edx, 4
    int 0x80

    ; Convert n2 from ASCII to integer
    mov ecx, n2
    call atoi
    mov [n2], eax

    ; Initialize sums
    mov dword [odd_sum], 0
    mov dword [even_sum], 0

    ; Print "Primes: "
    mov eax, 4
    mov ebx, 1
    mov ecx, primes
    mov edx, 8
    int 0x80

    ; Calculate primes and sums
    mov esi, [n1]
    mov edi, [n2]
    mov ecx, 1  ; Position counter (1-based)

find_primes:
    cmp esi, edi
    jg end_primes

    ; Check if `esi` is prime
    push esi
    call is_prime
    pop esi

    cmp eax, 1
    jne not_prime

    ; Print prime
    mov eax, esi
    call print_number

    ; Add to sums based on position
    mov eax, esi
    mov edx, ecx
    and edx, 1  ; Check if position is odd or even
    jz even_position
    ; Odd position
    add dword [odd_sum], eax
    jmp increment_position

even_position:
    ; Even position
    add dword [even_sum], eax

increment_position:
    inc ecx

not_prime:
    inc esi
    jmp find_primes

end_primes:
    ; Print newline
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80

    ; Multiply odd_sum and even_sum
    mov eax, dword [odd_sum]
    imul eax, dword [even_sum]
    mov [multiplication], eax

    ; Print "Multiplication = "
    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 17
    int 0x80

    ; Print multiplication result
    mov eax, dword [multiplication]
    call print_number

    ; Exit
    mov eax, 1
    xor ebx, ebx
    int 0x80

; Helper: is_prime
; Input: eax = number to check
; Output: eax = 1 (prime), eax = 0 (not prime)
is_prime:
    push ebx
    push ecx
    push edx

    cmp eax, 2
    jl not_prime_number
    je is_prime_number

    mov ecx, 2
check_division:
    mov edx, 0
    div ecx
    cmp edx, 0
    je not_prime_number

    inc ecx
    mov ebx, ecx
    imul ebx, ebx
    cmp ebx, eax
    jl check_division

is_prime_number:
    mov eax, 1
    jmp end_is_prime

not_prime_number:
    xor eax, eax

end_is_prime:
    pop edx
    pop ecx
    pop ebx
    ret

; Helper: atoi
; Convert ASCII string to integer
; Input: ecx = address of string
; Output: eax = integer value
atoi:
    xor eax, eax
    xor ebx, ebx
atoi_loop:
    mov bl, byte [ecx]
    cmp bl, 0xA  ; Newline
    je atoi_end
    sub bl, '0'
    imul eax, eax, 10
    add eax, ebx
    inc ecx
    jmp atoi_loop
atoi_end:
    ret

; Helper: print_number
; Print integer in eax
print_number:
    push ebx
    push ecx
    push edx

    xor ecx, ecx
    mov ebx, 10

print_digit:
    xor edx, edx
    div ebx
    add dl, '0'
    push dx
    inc ecx
    test eax, eax
    jnz print_digit

print_digit_loop:
    pop dx
    mov al, dl
    mov [buffer], al
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, 1
    int 0x80
    loop print_digit_loop

    ; Print space
    mov al, ' '
    mov [buffer], al
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, 1
    int 0x80

    pop edx
    pop ecx
    pop ebx
    ret
