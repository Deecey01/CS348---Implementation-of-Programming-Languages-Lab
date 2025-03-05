section .data
    prompt_msg db "Enter text (end with Enter): ", 0
    prompt_len equ $ - prompt_msg
    
    word_msg db "Number of words: ", 0
    word_len equ $ - word_msg
    
    vowel_msg db "Number of vowels: ", 0
    vowel_len equ $ - vowel_msg
    
    consonant_msg db "Number of consonants: ", 0
    consonant_len equ $ - consonant_msg
    
    newline db 10, 0
    
    ; Define vowels for comparison
    vowels db 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u', 0

section .bss
    buffer resb 1024      ; Input buffer
    num_buffer resb 12    ; Buffer for number conversion
    word_count resd 1     
    vowel_count resd 1    
    consonant_count resd 1 
    in_word resd 1        ; Flag for word boundary detection
    current_char resd 1   ; Current character being processed

section .text
    global _start

_start:
    ; Initialize counters
    mov dword [word_count], 0
    mov dword [vowel_count], 0
    mov dword [consonant_count], 0
    mov dword [in_word], 0

    ; Print prompt
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_msg
    mov edx, prompt_len
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline 
    mov edx, 1
    int 0x80

    ; Read input
    mov eax, 3
    mov ebx, 0
    mov ecx, buffer
    mov edx, 1024
    int 0x80
    
    ; Save input length
    push eax

    ; Process text
    mov esi, buffer       
    pop ecx              
    dec ecx               

process_loop:
    
    movzx eax, byte [esi]
    mov [current_char], eax
    
    ; Check for end of input
    cmp eax, 10           ; Newline
    je print_results
    cmp eax, 0            ; Null terminator
    je print_results
    
    ; Check if it's a letter
    call is_letter
    test eax, eax
    jz not_letter

    ; Check if it's a vowel
    mov eax, [current_char]
    call is_vowel
    test eax, eax
    jz handle_consonant

    ; Vowel found
    inc dword [vowel_count]
    jmp check_word_boundary

handle_consonant:
    inc dword [consonant_count]
    
check_word_boundary:
    ; Check if we're starting a new word
    cmp dword [in_word], 0
    jne next_char
    mov dword [in_word], 1
    inc dword [word_count]
    jmp next_char

not_letter:
    ; Reset word boundary flag if we hit a non-letter
    mov dword [in_word], 0

next_char:
    inc esi
    loop process_loop

print_results:
    ; Print word count
    mov eax, 4
    mov ebx, 1
    mov ecx, word_msg
    mov edx, word_len
    int 0x80

    mov eax, [word_count]
    call print_number
    
    mov eax, 4
    mov ebx, 1
    mov ecx, newline 
    mov edx, 1
    int 0x80

    ; Print vowel count
    mov eax, 4
    mov ebx, 1
    mov ecx, vowel_msg
    mov edx, vowel_len
    int 0x80

    mov eax, [vowel_count]
    call print_number

    mov eax, 4
    mov ebx, 1
    mov ecx, newline 
    mov edx, 1
    int 0x80
    
    ; Print consonant count
    mov eax, 4
    mov ebx, 1
    mov ecx, consonant_msg
    mov edx, consonant_len
    int 0x80

    mov eax, [consonant_count]
    call print_number

    mov eax, 4
    mov ebx, 1
    mov ecx, newline 
    mov edx, 1
    int 0x80
    
    ; Exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80

; Function to check if character in EAX is a letter
is_letter:
    cmp eax, 'A'
    jl not_a_letter
    cmp eax, 'Z'
    jle is_a_letter
    cmp eax, 'a'
    jl not_a_letter
    cmp eax, 'z'
    jle is_a_letter
not_a_letter:
    xor eax, eax        ; Return 0 (not a letter)
    ret
is_a_letter:
    mov eax, 1          ; Return 1 (is a letter)
    ret

; Function to check if character in EAX is a vowel
is_vowel:
    push esi            ; Save original esi
    push eax            ; Save character to check
    
    mov esi, vowels     ; Point to vowels array

check_vowel_loop:
    movzx eax, byte [esi]  ; Get current vowel
    test eax, eax          ; Check for end of vowels
    jz vowel_not_found
    
    cmp eax, [esp]         ; Compare with our character
    je vowel_found
    
    inc esi
    jmp check_vowel_loop

vowel_found:
    pop eax             ; Clean up stack
    pop esi             ; Restore esi
    mov eax, 1          ; Return 1 (is vowel)
    ret

vowel_not_found:
    pop eax             ; Clean up stack
    pop esi             ; Restore esi
    xor eax, eax        ; Return 0 (not vowel)
    ret

; Function to convert number to string and print it
print_number:
    push eax
    push ebx
    push ecx
    push edx
    
    mov ecx, num_buffer
    add ecx, 11          ; Start from end of buffer
    mov byte [ecx], 10   ; Add newline
    mov ebx, 10

convert_loop:
    dec ecx
    xor edx, edx
    div ebx
    add edx, '0'
    mov [ecx], dl
    test eax, eax
    jnz convert_loop

    ; Calculate length and print
    mov edx, num_buffer
    add edx, 11
    sub edx, ecx
    mov eax, 4
    mov ebx, 1
    int 0x80

    pop edx
    pop ecx
    pop ebx
    pop eax
    ret

    