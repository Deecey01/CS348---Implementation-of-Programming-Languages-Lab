section .data
    prompt1 db "Enter the main string: ", 0
    prompt1_len equ $ - prompt1
    prompt2 db "Enter the substring to find: ", 0
    prompt2_len equ $ - prompt2
    result_msg db "Found at index: ", 0
    result_msg_len equ $ - result_msg
    not_found_msg db "Substring not found", 0
    not_found_msg_len equ $ - not_found_msg
    newline db 10

section .bss
    main_string resb 100
    sub_string resb 100
    result resb 12

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt1
    mov edx, prompt1_len
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, main_string
    mov edx, 100
    int 0x80

    dec eax
    mov byte [main_string + eax], 0

    mov eax, 4
    mov ebx, 1
    mov ecx, prompt2
    mov edx, prompt2_len
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, sub_string
    mov edx, 100
    int 0x80

    dec eax
    mov byte [sub_string + eax], 0

    push sub_string
    push main_string
    call find_substring
    add esp, 8

    cmp eax, -1
    je print_not_found

    push eax
    call int_to_string
    add esp, 4

    mov eax, 4
    mov ebx, 1
    mov ecx, result_msg
    mov edx, result_msg_len
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 12
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    jmp exit

print_not_found:
    mov eax, 4
    mov ebx, 1
    mov ecx, not_found_msg
    mov edx, not_found_msg_len
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80

find_substring:
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi

    mov esi, [ebp + 8]
    mov edi, [ebp + 12]

    mov ecx, esi
    xor eax, eax
str1_len:
    cmp byte [ecx], 0
    je str2_len
    inc eax
    inc ecx
    jmp str1_len

str2_len:
    mov ecx, edi
    xor edx, edx
substr_len:
    cmp byte [ecx], 0
    je start_search
    inc edx
    inc ecx
    jmp substr_len

start_search:
    cmp edx, eax
    jg not_found_sub

    xor ebx, ebx
main_loop:
    mov esi, [ebp + 8]
    add esi, ebx
    mov edi, [ebp + 12]
    push eax
    mov ecx, edx

    push esi
    push edi
    repe cmpsb
    pop edi
    pop esi
    je found_sub

    pop eax
    inc ebx
    mov esi, [ebp + 8]
    add esi, ebx
    cmp byte [esi], 0
    je not_found_sub
    jmp main_loop

found_sub:
    pop eax
    mov eax, ebx
    jmp find_exit

not_found_sub:
    mov eax, -1

find_exit:
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret

int_to_string:
    push ebp
    mov ebp, esp

    mov eax, [ebp + 8]
    mov edi, result
    add edi, 11
    mov byte [edi], 0

    mov ebx, 10

    test eax, eax
    jns convert_loop

    neg eax
    push eax
    mov byte [result], '-'
    pop eax

convert_loop:
    dec edi
    xor edx, edx
    div ebx
    add dl, '0'
    mov [edi], dl
    test eax, eax
    jnz convert_loop

    mov esp, ebp
    pop ebp
    ret
