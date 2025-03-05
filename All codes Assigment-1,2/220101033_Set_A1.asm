section .data
    filename db 'document1.txt', 0
    prompt_char db "Enter character to search: ", 0
    prompt_char_len equ $ - prompt_char
    found_msg db "1", 10
    not_found_msg db "0", 10
    iter_msg db "Number of iterations: ", 0
    iter_msg_len equ $ - iter_msg
    newline db 10
    error_msg db "Error opening file", 0xa
    error_len equ $ - error_msg

section .bss
    document resb 1000         ; Buffer for document text
    doc_len resb 4            ; Store document length
    search_char resb 2        ; Buffer for search character
    iter_str resb 8           ; Buffer for iteration number string
    file_handle resd 1        ; File handle

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

    ; Read from file
    mov eax, 3          ; sys_read
    mov ebx, [file_handle]
    mov ecx, document
    mov edx, 1000       ; Maximum document size
    int 0x80
    
    mov [doc_len], eax  ; Store document length

    ; Close file
    mov eax, 6          ; sys_close
    mov ebx, [file_handle]
    int 0x80

    ; Print prompt for search character
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_char
    mov edx, prompt_char_len
    int 0x80

    ; Read search character
    mov eax, 3
    mov ebx, 0
    mov ecx, search_char
    mov edx, 2              ; Read character + newline
    int 0x80

    ; Initialize counter and pointer
    xor ecx, ecx           ; Clear counter
    mov esi, document      ; Point to start of document

search_loop:
    cmp ecx, [doc_len]     ; Check if we've reached end of document
    jge not_found          ; If at end, character not found
    
    mov al, byte [esi]     ; Load current character
    inc ecx                ; Increment iteration counter
    cmp al, byte [search_char] ; Compare with search character
    je found               ; If match found, jump to found
    
    inc esi                ; Move to next character
    jmp search_loop        ; Continue searching

found:
    push ecx               ; Save iteration count
    mov eax, 4
    mov ebx, 1
    mov ecx, found_msg
    mov edx, 2
    int 0x80
    pop ecx
    jmp print_iterations

not_found:
    push ecx               ; Save iteration count
    mov eax, 4
    mov ebx, 1
    mov ecx, not_found_msg
    mov edx, 2
    int 0x80
    pop ecx

print_iterations:
    ; Print iteration message
    push ecx
    mov eax, 4
    mov ebx, 1
    mov ecx, iter_msg
    mov edx, iter_msg_len
    int 0x80
    pop ecx

    ; Convert iteration count to string
    mov eax, ecx
    mov edi, iter_str
    add edi, 7
    mov byte [edi], 0
    mov ebx, 10

convert_loop:
    dec edi
    xor edx, edx
    div ebx
    add dl, '0'
    mov [edi], dl
    test eax, eax
    jnz convert_loop

    ; Print iteration count
    mov eax, 4
    mov ebx, 1
    mov ecx, edi
    mov edx, iter_str
    add edx, 8
    sub edx, edi
    int 0x80

    ; Print newline
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80

error_handler:
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    mov ecx, error_msg
    mov edx, error_len
    int 0x80
    
    mov eax, 1          ; sys_exit
    mov ebx, 1          ; error code 1
    int 0x80