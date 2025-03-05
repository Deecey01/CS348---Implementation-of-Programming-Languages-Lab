section .data
    prompt_str db "Enter the string: ", 0
    prompt_k db "Enter the value of k: ", 0
    result_fmt db "Reversed string: %s", 10, 0
    fmt_str db "%s", 0
    fmt_int db "%d", 0
    true_msg db "TRUE", 10, 0
    false_msg db "FALSE", 10, 0

section .bss
    input_string resb 100
    input_k resd 1
    length resd 1
    buffer resb 100

section .text
    extern printf
    extern scanf
    global main

main:
    push ebp
    mov ebp, esp

    ; Print prompt for string
    push prompt_str
    push fmt_str
    call printf
    add esp, 8

    ; Get string input
    push input_string
    push fmt_str
    call scanf
    add esp, 8

    ; Calculate string length
    mov esi, input_string
    mov ecx, 0
find_length:
    cmp byte [esi], 0
    je found_length
    inc esi
    inc ecx
    jmp find_length
found_length:
    mov [length], ecx

    ; Print prompt for k
    push prompt_k
    push fmt_str
    call printf
    add esp, 8

    ; Get k value
    push input_k
    push fmt_int
    call scanf
    add esp, 8

    ; Copy string to buffer
    mov esi, input_string
    mov edi, buffer
    mov ecx, [length]
    rep movsb
    mov byte [edi], 0

    ; Initialize for reversal
    mov ecx, [input_k]  ; k value
    mov esi, 0          ; start index
    dec ecx             ; end index = k-1
    
reverse_loop:
    cmp esi, ecx        ; check if indices have crossed
    jge done_reversing

    ; Swap characters at esi and ecx
    mov al, [buffer + esi]
    mov bl, [buffer + ecx]
    mov [buffer + esi], bl
    mov [buffer + ecx], al

    inc esi             ; move start index forward
    dec ecx             ; move end index backward
    jmp reverse_loop

done_reversing:
    ; Print reversed string
    push buffer
    push result_fmt
    call printf
    add esp, 8

    ; Check if all characters are alphabets
    mov ecx, [length]
    mov esi, buffer
    mov ebx, 1    ; TRUE flag

check_alphabet:
    lodsb
    cmp al, 'A'
    jl not_alphabet
    cmp al, 'Z'
    jle next_char
    cmp al, 'a'
    jl not_alphabet
    cmp al, 'z'
    jg not_alphabet

next_char:
    loop check_alphabet
    jmp print_true

not_alphabet:
    mov ebx, 0

print_true:
    cmp ebx, 1
    je print_true_msg

print_false_msg:
    push false_msg
    push fmt_str
    call printf
    add esp, 8
    jmp exit_program

print_true_msg:
    push true_msg
    push fmt_str
    call printf
    add esp, 8

exit_program:
    mov esp, ebp
    pop ebp
    xor eax, eax
    ret