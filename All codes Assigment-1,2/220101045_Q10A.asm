section .data
    prompt1 db "Enter first string: ", 0
    prompt2 db "Enter second string (substring to find): ", 0
    format_str db "%s", 0
    format_out db "Index: %d", 10, 0
    
section .bss
    str1 resb 100       ; Buffer for first string
    str2 resb 100       ; Buffer for second string
    str1_len resd 1     ; Length of first string
    str2_len resd 1     ; Length of second string

section .text
    extern printf
    extern scanf
    extern strlen
    global main

main:
    push ebp
    mov ebp, esp
    
    ; Print prompt for first string
    push prompt1
    call printf
    add esp, 4
    
    ; Read first string
    push str1
    push format_str
    call scanf
    add esp, 8
    
    ; Get length of first string
    push str1
    call strlen
    add esp, 4
    mov [str1_len], eax
    
    ; Print prompt for second string
    push prompt2
    call printf
    add esp, 4
    
    ; Read second string
    push str2
    push format_str
    call scanf
    add esp, 8
    
    ; Get length of second string
    push str2
    call strlen
    add esp, 4
    mov [str2_len], eax
    
    ; Find substring
    call find_substring
    
    ; Print result
    push eax            ; Index found (or -1)
    push format_out
    call printf
    add esp, 8
    
    mov esp, ebp
    pop ebp
    xor eax, eax
    ret

find_substring:
    mov esi, 0          ; Index in str1
    
search_loop:
    ; Check if we've reached the end of str1
    mov eax, [str1_len]
    sub eax, [str2_len]
    inc eax             ; Maximum valid starting position
    cmp esi, eax
    jge not_found
    
    ; Compare substring at current position
    mov ecx, [str2_len] ; Length to compare
    mov edi, 0          ; Index in str2
    
compare_loop:
    mov al, [str1 + esi + edi]  ; Character from str1
    mov bl, [str2 + edi]        ; Character from str2
    cmp al, bl
    jne next_position
    
    inc edi
    dec ecx
    jnz compare_loop
    
    ; If we get here, we found a match
    mov eax, esi
    ret
    
next_position:
    inc esi
    jmp search_loop
    
not_found:
    mov eax, -1
    ret



