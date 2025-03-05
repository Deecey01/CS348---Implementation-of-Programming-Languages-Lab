;-------------------------------------
; NAME: DIVYANSH CHANDAK (220101039)
; SET-A-Q12
; Write a program which takes two numbers as inputs and shows all the prime numbers
; in between those numbers and also finds the multiplication between the sum of
; primes in even position and primes in odd position.
;-------------------------------------

section .data
    ; Strings for user prompts and output
    msg1 db 'Enter first number: ', 0            ; Message asking for the first number
    msg1_len equ $ - msg1                        ; Length of msg1
    msg2 db 'Enter second number: ', 0           ; Message asking for the second number
    msg2_len equ $ - msg2                        ; Length of msg2
    comma db ', '                               ; Comma separator to print between prime numbers
    newline db 10                                ; Newline character
    mult_msg db 'Multiplication = '              ; Message to print before result
    mult_msg_len equ $ - mult_msg                ; Length of multiplication message

section .bss
    ; Reserve memory for variables
    num1 resd 1                                   ; Reserved space for the first number
    num2 resd 1                                   ; Reserved space for the second number
    even_sum resd 1                               ; Reserved space for sum of primes in even positions
    odd_sum resd 1                                ; Reserved space for sum of primes in odd positions
    count resd 1                                  ; Reserved space for tracking the position (odd/even)
    buffer resb 32                                ; Reserved space for input buffer (to read numbers)

section .text
    global _start

_start:
    ; Display the message "Enter first number"
    mov eax, 4                                   ; Syscall number for sys_write
    mov ebx, 1                                   ; File descriptor 1 (stdout)
    mov ecx, msg1                                ; Pointer to the message
    mov edx, msg1_len                            ; Length of the message
    int 0x80                                      ; Interrupt to make the syscall

    ; Call read_num to get the first number from user
    call read_num
    mov [num1], eax                              ; Store the first number in num1

    ; Display the message "Enter second number"
    mov eax, 4                                   ; Syscall number for sys_write
    mov ebx, 1                                   ; File descriptor 1 (stdout)
    mov ecx, msg2                                ; Pointer to the message
    mov edx, msg2_len                            ; Length of the message
    int 0x80                                      ; Interrupt to make the syscall

    ; Call read_num to get the second number from user
    call read_num
    mov [num2], eax                              ; Store the second number in num2

    ; Initialize variables for counting primes and sums
    mov dword [count], 0                         ; Initialize count to 0 (position counter)
    mov dword [even_sum], 0                      ; Initialize even_sum to 0
    mov dword [odd_sum], 0                       ; Initialize odd_sum to 0

    ; Start from the first number (num1)
    mov esi, [num1]

number_loop:
    ; Compare current number with second number (num2)
    cmp esi, [num2]
    jg display                                   ; If we have reached the end, display the result

    ; Check if the current number is prime
    mov ecx, esi
    call is_prime                                ; Check if the number is prime
    test al, al                                  ; Test if the result is 1 (prime)
    jz not_prime                                 ; If not prime, jump to not_prime

    ; If the number is prime, print it
    push esi                                     ; Save current number to the stack
    mov eax, esi
    call print_num                               ; Print the prime number

    ; Print comma separator
    mov eax, 4                                   ; Syscall number for sys_write
    mov ebx, 1                                   ; File descriptor 1 (stdout)
    mov ecx, comma                               ; Pointer to the comma string
    mov edx, 2                                    ; Length of the comma string
    int 0x80                                      ; Interrupt to make the syscall

    ; Add the prime to the appropriate sum (odd/even)
    mov eax, [count]                             ; Get current count (position)
    and eax, 1                                   ; Check if the count is odd (0 = even, 1 = odd)
    pop esi                                      ; Restore current number from stack
    jnz sum_of_numbers_at_odd_places             ; If odd, jump to add to odd sum

    ; Add to even sum if position is even
    mov eax, [even_sum]
    add eax, esi
    mov [even_sum], eax
    jmp continue_count

sum_of_numbers_at_odd_places:
    ; Add to odd sum if position is odd
    mov eax, [odd_sum]
    add eax, esi
    mov [odd_sum], eax

continue_count:
    ; Increment the count (to keep track of position)
    inc dword [count]

not_prime:
    ; Increment the number and continue checking the next number
    inc esi
    jmp number_loop

display:
    ; Print a newline
    mov eax, 4                                   ; Syscall number for sys_write
    mov ebx, 1                                   ; File descriptor 1 (stdout)
    mov ecx, newline                             ; Pointer to the newline character
    mov edx, 1                                   ; Length of the newline character
    int 0x80                                      ; Interrupt to make the syscall

    ; Print multiplication message
    mov eax, 4                                   ; Syscall number for sys_write
    mov ebx, 1                                   ; File descriptor 1 (stdout)
    mov ecx, mult_msg                            ; Pointer to multiplication message
    mov edx, mult_msg_len                        ; Length of multiplication message
    int 0x80                                      ; Interrupt to make the syscall

    ; Multiply even_sum and odd_sum and print the result
    mov eax, [even_sum]                          ; Load even sum into eax
    mul dword [odd_sum]                          ; Multiply eax by odd sum
    call print_num                               ; Print the result

    ; Print final newline
    mov eax, 4                                   ; Syscall number for sys_write
    mov ebx, 1                                   ; File descriptor 1 (stdout)
    mov ecx, newline                             ; Pointer to the newline character
    mov edx, 1                                   ; Length of the newline character
    int 0x80                                      ; Interrupt to make the syscall

    ; Exit the program
    mov eax, 1                                   ; Syscall number for sys_exit
    xor ebx, ebx                                 ; Exit code 0
    int 0x80                                      ; Interrupt to make the syscall

; Function to check if a number is prime
; Input: ECX = number to check
; Output: AL = 1 if prime, 0 if not prime
is_prime:
    push ebx                                      ; Save ebx register
    push edx                                      ; Save edx register
    push esi                                      ; Save esi register

    ; Check if number is less than 2
    cmp ecx, 2
    jl not_prime_ret                             ; If less than 2, it's not prime
    
    ; If the number is 2, it's prime
    je prime_ret

    ; If the number is even (not 2), it's not prime
    test ecx, 1
    jz not_prime_ret                             ; If divisible by 2, not prime

    ; Check divisibility from 3 to sqrt(number)
    mov esi, 3

check_divisor:
    mov eax, esi
    mul eax                                      ; Square of current divisor
    cmp eax, ecx                                  ; Compare divisor squared with the number
    ja prime_ret                                  ; If squared divisor > number, it's prime
    
    mov eax, ecx
    xor edx, edx                                  ; Clear edx for division
    div esi                                       ; Divide the number by the current divisor
    test edx, edx                                 ; Check if there's a remainder
    jz not_prime_ret                             ; If divisible, not prime
    
    add esi, 2                                    ; Try next odd divisor
    jmp check_divisor

prime_ret:
    mov al, 1                                     ; Mark as prime
    jmp is_prime_end

not_prime_ret:
    xor al, al                                    ; Mark as not prime

is_prime_end:
    pop esi                                       ; Restore esi
    pop edx                                       ; Restore edx
    pop ebx                                       ; Restore ebx
    ret                                           ; Return

; Function to read a number from input
read_num:
    push ebx                                      ; Save ebx register
    push ecx                                      ; Save ecx register
    push edx                                      ; Save edx register

    mov eax, 3                                    ; Syscall number for sys_read
    xor ebx, ebx                                  ; File descriptor 0 (stdin)
    mov ecx, buffer                               ; Pointer to buffer
    mov edx, 31                                    ; Max length of input
    int 0x80                                       ; Interrupt to make the syscall

    xor eax, eax                                   ; Clear eax register
    mov ecx, buffer                               ; Point to buffer
convert_loop:
    movzx edx, byte [ecx]                         ; Load the byte from buffer
    cmp dl, 0xA                                    ; Check if it's newline
    je done_convert
    cmp dl, '0'
    jb done_convert
    cmp dl, '9'
    ja done_convert

    sub dl, '0'                                    ; Convert ASCII to integer
    imul eax, 10                                  ; Multiply eax by 10 (shift left)
    add eax, edx                                   ; Add current digit to eax
    inc ecx                                        ; Move to the next character
    jmp convert_loop

done_convert:
    pop edx                                       ; Restore edx
    pop ecx                                       ; Restore ecx
    pop ebx                                       ; Restore ebx
    ret                                           ; Return

; Function to print number
print_num:
    push ebx                                      ; Save ebx register
    push ecx                                      ; Save ecx register
    push edx                                      ; Save edx register
    push esi                                      ; Save esi register
    push edi                                      ; Save edi register

    mov ecx, buffer                               ; Point to the buffer
    add ecx, 31                                    ; Move to the end of the buffer
    mov byte [ecx], 0                             ; Null terminate the string

    mov ebx, 10                                    ; Divisor for decimal conversion
convert_digits:
    dec ecx
    xor edx, edx
    div ebx
    add dl, '0'         ; Convert remainder to ASCII
    mov [ecx], dl
    test eax, eax
    jnz convert_digits

    ; Print the number
    mov edx, buffer
    add edx, 31
    sub edx, ecx        ; Calculate length
    mov eax, 4
    mov ebx, 1
    int 0x80

    pop edi
    pop esi
    pop edx
    pop ecx
    pop ebx
    ret                                        ; Return
