section .data
    input_msg db "Enter text (end with Enter): ", 0
    input_len equ $ - input_msg
    longest_msg db "Longest word: ", 0
    longest_len equ $ - longest_msg
    shortest_msg db "Shortest word: ", 0
    shortest_len equ $ - shortest_msg
    length_msg db " (length: ", 0
    length_len equ $ - length_msg
    close_msg db ")", 10, 0
    close_len equ $ - close_msg
    newline db 0xA

section .bss
    buffer resb 1024        ; Input buffer
    word_buffer resb 50     ; Current word buffer
    longest_word resb 50    ; Buffer for longest word
    shortest_word resb 50   ; Buffer for shortest word
    longest_len_val resd 1  ; Length of longest word
    shortest_len_val resd 1 ; Length of shortest word
    curr_len resd 1        ; Length of current word
    num_buffer resb 10     ; Buffer for number conversion

section .text
    global _start

_start:
    ; Print input message
    mov eax, 4
    mov ebx, 1
    mov ecx, input_msg
    mov edx, input_len
    int 0x80

    ; Read input
    mov eax, 3
    mov ebx, 0
    mov ecx, buffer
    mov edx, 1024
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80


    ; Save input length
    push eax

    ; Initialize variables
    mov dword [longest_len_val], 0
    mov dword [shortest_len_val], 0x0FFFFFFF
    mov esi, buffer        ; Source index
    mov edi, word_buffer   ; Destination index
    mov dword [curr_len], 0

process_loop:
    movzx eax, byte [esi]  ; Load current character with zero extension
    
    cmp eax, 10            ; Check for newline
    je process_last_word
    cmp eax, 32            ; Check for space
    je word_boundary
    cmp eax, 0             ; Check for null terminator
    je process_last_word

    ; Add character to current word
    mov [edi], eax         ; Store full 32-bit value
    inc edi
    inc dword [curr_len]
    inc esi
    jmp process_loop

word_boundary:
    ; Process word if it's not empty
    cmp dword [curr_len], 0
    je skip_word

    ; Check if current word is longest
    mov eax, [curr_len]
    cmp eax, [longest_len_val]
    jle check_shortest
    
    ; Update longest word
    mov dword [longest_len_val], eax
    push esi
    push edi
    mov ecx, eax         ; Length of word
    mov esi, word_buffer
    mov edi, longest_word
    rep movsb            ; Copy word
    mov byte [edi], 0    ; Null terminate
    pop edi
    pop esi

check_shortest:
    mov eax, [curr_len]
    cmp eax, [shortest_len_val]
    jge reset_word
    
    ; Update shortest word
    mov dword [shortest_len_val], eax
    push esi
    push edi
    mov ecx, eax         ; Length of word
    mov esi, word_buffer
    mov edi, shortest_word
    rep movsb            ; Copy word
    mov byte [edi], 0    ; Null terminate
    pop edi
    pop esi

reset_word:
    mov edi, word_buffer ; Reset word buffer pointer
    mov dword [curr_len], 0

skip_word:
    inc esi
    jmp process_loop

process_last_word:
    cmp dword [curr_len], 0
    je print_results
    
    ; Process the last word
    mov eax, [curr_len]
    
    ; Check if it's longest
    cmp eax, [longest_len_val]
    jle check_last_shortest
    
    ; Update longest word
    mov dword [longest_len_val], eax
    push esi
    push edi
    mov ecx, eax
    mov esi, word_buffer
    mov edi, longest_word
    rep movsb
    mov byte [edi], 0
    pop edi
    pop esi

check_last_shortest:
    mov eax, [curr_len]
    cmp eax, [shortest_len_val]
    jge print_results
    
    ; Update shortest word
    mov dword [shortest_len_val], eax
    push esi
    push edi
    mov ecx, eax
    mov esi, word_buffer
    mov edi, shortest_word
    rep movsb
    mov byte [edi], 0
    pop edi
    pop esi

print_results:
    ; Print longest word results
    mov eax, 4
    mov ebx, 1
    mov ecx, longest_msg
    mov edx, longest_len
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, longest_word
    mov edx, [longest_len_val]
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, length_msg
    mov edx, length_len
    int 0x80

    mov eax, [longest_len_val]
    call number_to_string

    mov eax, 4
    mov ebx, 1
    mov ecx, close_msg
    mov edx, close_len
    int 0x80

    ; Print shortest word results
    mov eax, 4
    mov ebx, 1
    mov ecx, shortest_msg
    mov edx, shortest_len
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, shortest_word
    mov edx, [shortest_len_val]
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, length_msg
    mov edx, length_len
    int 0x80

    mov eax, [shortest_len_val]
    call number_to_string

    mov eax, 4
    mov ebx, 1
    mov ecx, close_msg
    mov edx, close_len
    int 0x80

    ; Exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80

number_to_string:
    push esi
    push edi
    mov edi, num_buffer
    add edi, 9
    mov byte [edi], 0
    mov ebx, 10

convert_loop:
    dec edi
    xor edx, edx
    div ebx
    add edx, '0'
    mov [edi], dl
    test eax, eax
    jnz convert_loop

    mov eax, 4
    mov ebx, 1
    mov ecx, edi
    mov edx, 10
    int 0x80

    pop edi
    pop esi
    ret
