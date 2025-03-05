section .data
    prompt_m db "Enter number of rows for Matrix A : ", 0
    prompt_n db "Enter number of columns for Matrix A: ", 0
    prompt_p db "Enter number of columns for Matrix B : ", 0
    prompt_elem db "Enter element: ", 0
    newline db 10, 0
    space db " ", 0
    matrix_a_msg db "Enter elements for Matrix A:", 10, 0
    matrix_b_msg db "Enter elements for Matrix B:", 10, 0
    result_msg db "Resultant Matrix C:", 10, 0

section .bss
    m resd 1
    n resd 1
    p resd 1
    input_buffer resb 1024
    matrix_a resd 100
    matrix_b resd 100
    matrix_c resd 100
    temp resd 1

section .text
    global _start

_start:
    call get_dimensions
    mov ecx, matrix_a_msg
    call print_string
    mov ebx, matrix_a
    mov eax, [m]
    mov edx, [n]
    call input_matrix
    mov ecx, matrix_b_msg
    call print_string
    mov ebx, matrix_b
    mov eax, [n]
    mov edx, [p]
    call input_matrix
    call multiply_matrices
    mov ecx, result_msg
    call print_string
    call print_matrix
    mov eax, 1
    xor ebx, ebx
    int 0x80

get_dimensions:
    mov ecx, prompt_m
    call print_string
    call read_number
    mov [m], eax
    mov ecx, prompt_n
    call print_string
    call read_number
    mov [n], eax
    mov ecx, prompt_p
    call print_string
    call read_number
    mov [p], eax
    ret

input_matrix:
    push ebp
    mov ebp, esp
    push esi
    push edi
    push eax
    mul edx
    mov esi, eax
    pop eax
    mov edi, 0
input_matrix_loop:
    cmp edi, esi
    jge input_matrix_done
    mov ecx, prompt_elem
    call print_string
    call read_number
    mov [ebx + edi*4], eax
    inc edi
    jmp input_matrix_loop
input_matrix_done:
    pop edi
    pop esi
    mov esp, ebp
    pop ebp
    ret

multiply_matrices:
    xor ecx, ecx
outer_loop:
    cmp ecx, [m]
    jge multiply_done
    xor edx, edx
middle_loop:
    cmp edx, [p]
    jge next_row
    xor esi, esi
    mov dword [temp], 0
inner_loop:
    cmp esi, [n]
    jge store_result
    mov eax, ecx
    imul eax, [n]
    add eax, esi
    mov ebx, [matrix_a + eax*4]
    mov eax, esi
    imul eax, [p]
    add eax, edx
    mov eax, [matrix_b + eax*4]
    imul eax, ebx
    add dword [temp], eax
    inc esi
    jmp inner_loop
store_result:
    mov eax, ecx
    imul eax, [p]
    add eax, edx
    mov ebx, [temp]
    mov [matrix_c + eax*4], ebx
    inc edx
    jmp middle_loop
next_row:
    inc ecx
    jmp outer_loop
multiply_done:
    ret

print_matrix:
    xor ecx, ecx
print_matrix_outer:
    cmp ecx, [m]
    jge print_matrix_done
    xor edx, edx
print_matrix_inner:
    cmp edx, [p]
    jge print_newline
    mov eax, ecx
    imul eax, [p]
    add eax, edx
    mov eax, [matrix_c + eax*4]
    push ecx
    push edx
    call print_number
    mov ecx, space
    call print_string
    pop edx
    pop ecx
    inc edx
    jmp print_matrix_inner
print_newline:
    push ecx
    push edx
    mov ecx, newline
    call print_string
    pop edx
    pop ecx
    inc ecx
    jmp print_matrix_outer
print_matrix_done:
    ret

print_string:
    push ebx
    push eax
    mov ebx, ecx
    xor eax, eax
count_string_length:
    cmp byte [ebx + eax], 0
    je string_length_done
    inc eax
    jmp count_string_length
string_length_done:
    mov edx, eax
    mov ecx, ebx
    mov eax, 4
    mov ebx, 1
    int 0x80
    pop eax
    pop ebx
    ret

read_number:
    push ebx
    push ecx
    push edx
    mov ecx, input_buffer
    mov edx, 32
    mov eax, 3
    mov ebx, 0
    int 0x80
    mov ebx, input_buffer
    xor eax, eax
convert_loop:
    movzx edx, byte [ebx]
    cmp dl, 10
    je convert_done
    cmp dl, '0'
    jb convert_done
    cmp dl, '9'
    ja convert_done
    sub dl, '0'
    imul eax, 10
    add eax, edx
    inc ebx
    jmp convert_loop
convert_done:
    pop edx
    pop ecx
    pop ebx
    ret

print_number:
    push ebx
    push ecx
    push edx
    mov ecx, input_buffer
    add ecx, 31
    mov byte [ecx], 0
    mov ebx, 10
convert_number:
    dec ecx
    xor edx, edx
    div ebx
    add dl, '0'
    mov [ecx], dl
    test eax, eax
    jnz convert_number
    mov edx, input_buffer + 31
    sub edx, ecx
    mov eax, 4
    mov ebx, 1
    int 0x80
    pop edx
    pop ecx
    pop ebx
    ret

Matrix_loop:
    mov eax, 1
    mov ebx, 2
    mov ecx, 3
    mov edx, 4
    
    mov edi, eax
    mov eax, ebx
    mov ebx, ecx
    mov ecx, edx
    mov edx, edi
    
    ; Move them back
    mov edi, edx
    mov edx, ecx
    mov ecx, ebx
    mov ebx, eax
    mov eax, edi
    ret

allocate_and_forget:
    push ebp
    mov ebp, esp
    sub esp, 4          ; Allocate 4 bytes
    mov dword [esp], 42 ; Store 42
    mov eax, [esp]      ; Read it
    add esp, 4          ; Deallocate
    pop ebp
    ret

math_undo:
    push eax
    mov eax, 42
    add eax, 10
    sub eax, 10
    mul dword 2
    div dword 2
    pop eax
    ret

Template_useful:
    push ebp
    mov ebp, esp
    push eax
    push ebx
    
    mov eax, [ebp + 8]
    mov ebx, [ebp + 12]
    xchg eax, ebx      ; Swap
    xchg eax, ebx      ; Swap back
    
    pop ebx
    pop eax
    pop ebp
    ret