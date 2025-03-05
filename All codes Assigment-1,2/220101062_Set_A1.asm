section .data
    msg1 db "Enter the document text: ", 0
    msg1_len equ $ - msg1
    msg2 db "Enter the character to search: ", 0
    msg2_len equ $ - msg2
    found_msg db "1", 10
    not_found_msg db "0", 10
    iter_msg db "Number of iterations: ", 0
    iter_msg_len equ $ - iter_msg
    newline db 10

section .bss
    filename resb 100
    document resb 1000
    search_char resb 1
    iterations resb 8
    doc_len resb 4
    fd resb 4

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, msg1_len
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, filename
    mov edx, 100
    int 0x80

    dec eax
    mov byte [filename + eax], 0

    mov eax, 5
    mov ebx, filename
    mov ecx, 0
    int 0x80

    mov [fd], eax

    mov eax, 3
    mov ebx, [fd]
    mov ecx, document
    mov edx, 1000
    int 0x80

    mov [doc_len], eax

    mov eax, 6
    mov ebx, [fd]
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, msg2_len
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, search_char
    mov edx, 1
    int 0x80

    xor ecx, ecx
    mov esi, document

search_loop:
    cmp ecx, [doc_len]
    jge not_found

    mov al, [esi]
    cmp al, [search_char]
    je found

    inc ecx
    inc esi
    jmp search_loop

found:
    mov eax, 4
    mov ebx, 1
    mov ecx, found_msg
    mov edx, 2
    int 0x80
    jmp print_iterations

not_found:
    mov eax, 4
    mov ebx, 1
    mov ecx, not_found_msg
    mov edx, 2
    int 0x80

print_iterations:
    mov eax, 4
    mov ebx, 1
    mov ecx, iter_msg
    mov edx, iter_msg_len
    int 0x80

    mov eax, ecx
    mov edi, iterations
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

    mov eax, 4
    mov ebx, 1
    mov ecx, edi
    mov edx, iterations
    add edx, 8
    sub edx, edi
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80
