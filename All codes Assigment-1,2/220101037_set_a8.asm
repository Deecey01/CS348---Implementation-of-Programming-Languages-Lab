section .data
    prompt db 'Enter the start and end year (separated by space): ', 0
    leap_msg db 'Leap Year: ', 0
    newline db 0xA, 0

section .bss
    start resd 1
    end resd 1
    year resd 1
    is_leap resb 1

section .text
    global _start

_start:
    ; Print the prompt
    mov edx, len prompt
    mov ecx, prompt
    mov ebx, 1
    mov eax, 4
    int 0x80

    ; Read input
    mov eax, 3
    mov ebx, 0
    lea ecx, [year]
    mov edx, 20
    int 0x80

    ; Parse the input (start and end year)
    lea ecx, [year]
    call atoi
    mov [start], eax
    add ecx, 4
    call atoi
    mov [end], eax

    ; Loop through the range
    mov eax, [start]
check_leap:
    mov [year], eax
    call is_leap_year
    cmp byte [is_leap], 0
    je print_year
    ; Increment year
    inc eax
    cmp eax, [end]
    jle check_leap

    ; Exit
    mov eax, 1
    xor ebx, ebx
    int 0x80

print_year:
    push eax
    call print_int
    add esp, 4
    ; Print newline
    mov edx, 1
    mov ecx, newline
    mov ebx, 1
    mov eax, 4
    int 0x80
    ; Increment year
    inc eax
    cmp eax, [end]
    jle check_leap

    ; Exit
    mov eax, 1
    xor ebx, ebx
    int 0x80

is_leap_year:
    ; Check if year is divisible by 4 and not 100 or divisible by 400
    mov eax, [year]
    mov ecx, 4
    xor edx, edx
    div ecx
    cmp edx, 0
    jne not_leap
    ; Year divisible by 4
    mov eax, [year]
    mov ecx, 100
    xor edx, edx
    div ecx
    cmp edx, 0
    je check_400
    ; Year is leap year
    mov byte [is_leap], 1
    ret

check_400:
    mov eax, [year]
    mov ecx, 400
    xor edx, edx
    div ecx
    cmp edx, 0
    je leap
    ; Year is not leap year
    mov byte [is_leap], 0
    ret

not_leap:
    mov byte [is_leap], 0
    ret

leap:
    mov byte [is_leap], 1
    ret

atoi:
    ; Convert string to integer
    xor eax, eax
    xor ebx, ebx
atoi_loop:
    mov bl, byte [ecx]
    cmp bl, '0'
    jb atoi_end
    cmp bl, '9'
    ja atoi_end
    sub bl, '0'
    mul byte 10
    add eax, ebx
    inc ecx
    jmp atoi_loop
atoi_end:
    ret

print_int:
    ; Print integer
    mov edx, 0
    mov ecx, 10
    mov ebx, esp
    dec ebx
print_int_loop:
    xor edx, edx
    div ecx
    add dl, '0'
    mov [ebx], dl
    dec ebx
    cmp eax, 0
    jne print_int_loop
    inc ebx
    mov edx, esp
    sub edx, ebx
    mov ecx, ebx
    mov ebx, 1
    mov eax, 4
    int 0x80
    ret

len:
    .equ $ - prompt
