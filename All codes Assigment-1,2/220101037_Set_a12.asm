section .data
    prompt1 db 'Please enter the first number: ', 0
    prompt1_len equ $ - prompt1
    prompt2 db 'Please enter the second number: ', 0
    prompt2_len equ $ - prompt2
    comma db ', '
    newline db 10
    result_msg db 'Multiplication result: ', 0
    result_msg_len equ $ - result_msg

section .bss
    start_num resd 1
    end_num resd 1
    even_prime_sum resd 1
    odd_prime_sum resd 1
    prime_position resd 1
    user_input_buffer resb 32

section .text
    global _start

_start:
    ; Display the prompt for the first number
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt1
    mov edx, prompt1_len
    int 0x80

    ; Read the first number
    call read_user_input
    mov [start_num], eax

    ; Display the prompt for the second number
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt2
    mov edx, prompt2_len
    int 0x80

    ; Read the second number
    call read_user_input
    mov [end_num], eax

    ; Initialize variables for counting prime positions and storing sums
    mov dword [prime_position], 0
    mov dword [even_prime_sum], 0
    mov dword [odd_prime_sum], 0

    ; Start checking numbers from the first number onwards
    mov esi, [start_num]

check_loop:
    ; Compare if the current number exceeds the second number
    cmp esi, [end_num]
    jg display_results

    ; Check if the current number is prime
    mov ecx, esi
    call check_prime
    test al, al
    jz not_prime_number

    ; If prime, print the number
    push esi
    mov eax, esi
    call display_number
    ; Print comma after number
    mov eax, 4
    mov ebx, 1
    mov ecx, comma
    mov edx, 2
    int 0x80

    ; Add prime number to the appropriate sum
    mov eax, [prime_position]
    and eax, 1  ; Check whether the current position is odd or even
    pop esi
    jnz add_to_odd_prime_sum

    ; Add to the sum of even-positioned primes
    mov eax, [even_prime_sum]
    add eax, esi
    mov [even_prime_sum], eax
    jmp increment_position

add_to_odd_prime_sum:
    ; Add to the sum of odd-positioned primes
    mov eax, [odd_prime_sum]
    add eax, esi
    mov [odd_prime_sum], eax

increment_position:
    inc dword [prime_position]

not_prime_number:
    inc esi
    jmp check_loop

display_results:
    ; Print newline after the prime numbers
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Print the multiplication result message
    mov eax, 4
    mov ebx, 1
    mov ecx, result_msg
    mov edx, result_msg_len
    int 0x80

    ; Multiply the sums of even and odd positioned primes
    mov eax, [even_prime_sum]
    mov ebx, [odd_prime_sum]
    mul ebx
    call display_number

    ; Print newline after the result
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80

; Function to check if a number is prime
; Input: ECX = number to check
; Output: AL = 1 if prime, 0 if not prime
check_prime:
    push ebx
    push edx
    push esi

    ; Return 0 for numbers less than 2
    cmp ecx, 2
    jl not_prime_return

    ; Return 1 if number is 2
    je prime_return

    ; Return 0 if the number is even and greater than 2
    test ecx, 1
    jz not_prime_return

    ; Check divisibility from 3 upwards
    mov esi, 3

check_divisor:
    mov eax, esi
    mul eax
    cmp eax, ecx    ; If divisor squared is greater than number, it's prime
    ja prime_return

    mov eax, ecx
    xor edx, edx
    div esi           ; Divide number by divisor
    test edx, edx     ; If remainder is zero, number is not prime
    jz not_prime_return

    add esi, 2        ; Move to next odd number
    jmp check_divisor

prime_return:
    mov al, 1
    jmp check_prime_end

not_prime_return:
    xor al, al

check_prime_end:
    pop esi
    pop edx
    pop ebx
    ret

; Function to read number input
read_user_input:
    push ebx
    push ecx
    push edx

    mov eax, 3
    xor ebx, ebx
    mov ecx, user_input_buffer
    mov edx, 31
    int 0x80

    xor eax, eax
    mov ecx, user_input_buffer
convert_input_loop:
    movzx edx, byte [ecx]
    cmp dl, 0xA
    je end_conversion
    cmp dl, '0'
    jb end_conversion
    cmp dl, '9'
    ja end_conversion

    sub dl, '0'
    imul eax, 10
    add eax, edx
    inc ecx
    jmp convert_input_loop

end_conversion:
    pop edx
    pop ecx
    pop ebx
    ret

; Function to display a number
display_number:
    push ebx
    push ecx
    push edx
    push esi
    push edi

    mov ecx, user_input_buffer
    add ecx, 31
    mov byte [ecx], 0  ; Null terminate

    mov ebx, 10
convert_digits:
    dec ecx
    xor edx, edx
    div ebx
    add dl, '0'
    mov [ecx], dl
    test eax, eax
    jnz convert_digits

    ; Output the number
    mov edx, user_input_buffer
    add edx, 31
    sub edx, ecx
    mov eax, 4
    mov ebx, 1
    int 0x80

    pop edi
    pop esi
    pop edx
    pop ecx
    pop ebx
    ret
