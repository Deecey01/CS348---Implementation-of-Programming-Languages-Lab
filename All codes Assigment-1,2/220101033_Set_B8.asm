section .data
    filename db 'document2.txt', 0
    error_msg db 'Error opening file', 0xa
    error_len equ $ - error_msg
    longest_msg db 'Longest word: '
    longest_len equ $ - longest_msg
    shortest_msg db 'Shortest word: '
    shortest_len equ $ - shortest_msg
    len_msg db ' (length: '
    len_msg_len equ $ - len_msg
    close_paren db ')', 0xa
    close_len equ $ - close_paren
    
section .bss
    file_handle resd 1
    buffer resb 4096
    buffer_len equ 4096
    current_word resb 100
    longest_word resb 100
    shortest_word resb 100
    current_len resd 1
    max_len resd 1
    min_len resd 1
    num_string resb 10
    
section .text
    global _start

_start:
    ; Open file
    mov eax, 5          ; sys_open
    mov ebx, filename
    mov ecx, 0          ; O_RDONLY
    int 0x80
    
    test eax, eax       ; Check if file opened successfully
    js error_handler
    
    mov [file_handle], eax
    
    ; Initialize lengths
    mov dword [max_len], 0
    mov dword [min_len], 100    ; Initialize to a large number
    
read_loop:
    ; Read from file
    mov eax, 3          ; sys_read
    mov ebx, [file_handle]
    mov ecx, buffer
    mov edx, buffer_len
    int 0x80
    
    test eax, eax       ; Check if EOF or error
    jle close_file
    
    mov esi, buffer     ; Source index for processing
    mov edi, current_word ; Destination index for current word
    xor ecx, ecx        ; Current word length
    
process_char:
    cmp byte [esi], 0   ; Check for end of buffer
    je check_last_word
    
    cmp byte [esi], ' ' ; Check for space
    je word_boundary
    
    cmp byte [esi], 0xa ; Check for newline
    je word_boundary
    
    ; Add character to current word
    mov al, [esi]
    mov [edi], al
    inc edi
    inc ecx
    inc esi
    jmp process_char
    
word_boundary:
    ; Only process if we have a word
    test ecx, ecx
    jz skip_word
    
    ; Terminate current word
    mov byte [edi], 0
    mov [current_len], ecx
    
    ; Compare lengths
    cmp ecx, [max_len]
    jle check_min
    mov [max_len], ecx
    push esi
    mov esi, current_word
    mov edi, longest_word
    rep movsb
    mov byte [edi], 0   ; Ensure null termination
    pop esi
    jmp reset_word
    
check_min:
    cmp ecx, [min_len]
    jge reset_word
    mov [min_len], ecx
    push esi
    mov esi, current_word
    mov edi, shortest_word
    rep movsb
    mov byte [edi], 0   ; Ensure null termination
    pop esi
    
reset_word:
    mov edi, current_word
    xor ecx, ecx
    
skip_word:
    inc esi
    jmp process_char
    
check_last_word:
    ; Process the last word if there is one
    test ecx, ecx
    jz read_loop
    jmp word_boundary
    
close_file:
    mov eax, 6          ; sys_close
    mov ebx, [file_handle]
    int 0x80
    
    ; Print longest word info
    mov eax, 4
    mov ebx, 1
    mov ecx, longest_msg
    mov edx, longest_len
    int 0x80
    
    mov eax, 4
    mov ebx, 1
    mov ecx, longest_word
    push ecx
    mov edx, [max_len]
    int 0x80
    
    mov eax, 4
    mov ebx, 1
    mov ecx, len_msg
    mov edx, len_msg_len
    int 0x80
    
    ; Convert max_len to string and print
    mov eax, [max_len]
    call int_to_string
    mov eax, 4
    mov ebx, 1
    mov ecx, num_string
    mov edx, 10
    int 0x80
    
    mov eax, 4
    mov ebx, 1
    mov ecx, close_paren
    mov edx, close_len
    int 0x80
    
    ; Print shortest word info
    mov eax, 4
    mov ebx, 1
    mov ecx, shortest_msg
    mov edx, shortest_len
    int 0x80
    
    mov eax, 4
    mov ebx, 1
    mov ecx, shortest_word
    mov edx, [min_len]
    int 0x80
    
    mov eax, 4
    mov ebx, 1
    mov ecx, len_msg
    mov edx, len_msg_len
    int 0x80
    
    ; Convert min_len to string and print
    mov eax, [min_len]
    call int_to_string
    mov eax, 4
    mov ebx, 1
    mov ecx, num_string
    mov edx, 10
    int 0x80
    
    mov eax, 4
    mov ebx, 1
    mov ecx, close_paren
    mov edx, close_len
    int 0x80
    
    ; Exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80
    
error_handler:
    mov eax, 4
    mov ebx, 1
    mov ecx, error_msg
    mov edx, error_len
    int 0x80
    
    mov eax, 1
    mov ebx, 1
    int 0x80

; Function to convert integer to string
int_to_string:
    push ebx
    push ecx
    push edx
    push edi
    
    mov ecx, 10
    mov edi, num_string
    add edi, 9          ; Start from end of buffer
    mov byte [edi], 0   ; Null terminate
    
    .loop:
        xor edx, edx
        div ecx         ; Divide by 10
        add dl, '0'     ; Convert remainder to ASCII
        dec edi
        mov [edi], dl
        test eax, eax
        jnz .loop
    
    mov eax, edi        ; Return pointer to start of string
    
    pop edi
    pop edx
    pop ecx
    pop ebx
    ret