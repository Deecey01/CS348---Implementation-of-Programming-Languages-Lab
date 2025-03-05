section .data
    prompt_m db "Enter number of rows for Matrix A (M): ", 0
    prompt_n db "Enter number of columns for Matrix A / rows for Matrix B (N): ", 0
    prompt_p db "Enter number of columns for Matrix B (P): ", 0
    prompt_elem db "Enter element: ", 0
    newline db 10, 0
    space db " ", 0
    matrix_a_msg db "Enter elements for Matrix A:", 10, 0
    matrix_b_msg db "Enter elements for Matrix B:", 10, 0
    result_msg db "Resultant Matrix C:", 10, 0

section .bss
    m resd 1              ; Rows of Matrix A
    n resd 1              ; Columns of Matrix A / Rows of Matrix B
    p resd 1              ; Columns of Matrix B
    input_buffer resb 1024    ; Input buffer for reading elements
    matrix_a resd 100     ; Storage for Matrix A (max 10x10)
    matrix_b resd 100     ; Storage for Matrix B (max 10x10)
    matrix_c resd 100     ; Storage for result Matrix C (max 10x10)
    temp resd 1           ; Temporary variable for sum in multiplication

section .text
    global _start

_start:
    ; Step 1: Get dimensions of matrices
    call get_dimensions

    ; Step 2: Input Matrix A
    mov ecx, matrix_a_msg
    call print_string
    mov ebx, matrix_a
    mov eax, [m]    ; Rows of A
    mov edx, [n]    ; Columns of A
    call input_matrix

    ; Step 3: Input Matrix B
    mov ecx, matrix_b_msg
    call print_string
    mov ebx, matrix_b
    mov eax, [n]    ; Rows of B (same as columns of A)
    mov edx, [p]    ; Columns of B
    call input_matrix

    ; Step 4: Perform matrix multiplication
    call multiply_matrices

    ; Step 5: Print the resultant matrix
    mov ecx, result_msg
    call print_string
    call print_matrix

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80

; -----------------------------
; Subroutine: get_dimensions
; -----------------------------
get_dimensions:
    ; Get M
    mov ecx, prompt_m
    call print_string
    call read_number
    mov [m], eax

    ; Get N
    mov ecx, prompt_n
    call print_string
    call read_number
    mov [n], eax

    ; Get P
    mov ecx, prompt_p
    call print_string
    call read_number
    mov [p], eax
    ret

; -----------------------------
; Subroutine: input_matrix
; -----------------------------
input_matrix:
    push ebp
    mov ebp, esp
    push esi
    push edi

    push eax            ; Save rows
    mul edx             ; Total elements = rows * cols
    mov esi, eax        ; Store total elements
    pop eax             ; Restore rows

    mov edi, 0          ; Element counter
input_matrix_loop:
    cmp edi, esi
    jge input_matrix_done

    mov ecx, prompt_elem
    call print_string
    call read_number

    mov [ebx + edi*4], eax    ; Store element in matrix
    inc edi
    jmp input_matrix_loop

input_matrix_done:
    pop edi
    pop esi
    mov esp, ebp
    pop ebp
    ret

; -----------------------------
; Subroutine: multiply_matrices
; -----------------------------
multiply_matrices:
    xor ecx, ecx        ; i = 0 (row index for A and C)
outer_loop:
    cmp ecx, [m]
    jge multiply_done

    xor edx, edx        ; j = 0 (column index for B and C)
middle_loop:
    cmp edx, [p]
    jge next_row

    xor esi, esi        ; k = 0 (index for multiplication)
    mov dword [temp], 0 ; Initialize sum

inner_loop:
    cmp esi, [n]
    jge store_result

    ; A[i][k] = matrix_a[i * n + k]
    mov eax, ecx
    imul eax, [n]       ; i * n
    add eax, esi        ; i * n + k
    mov ebx, [matrix_a + eax*4]

    ; B[k][j] = matrix_b[k * p + j]
    mov eax, esi
    imul eax, [p]       ; k * p
    add eax, edx        ; k * p + j
    mov eax, [matrix_b + eax*4]

    imul eax, ebx       ; A[i][k] * B[k][j]
    add dword [temp], eax    ; Accumulate the sum

    inc esi
    jmp inner_loop

store_result:
    ; Store sum in C[i][j] = matrix_c[i * p + j]
    mov eax, ecx
    imul eax, [p]       ; i * p
    add eax, edx        ; i * p + j
    mov ebx, [temp]

    
    mov [matrix_c + eax*4], ebx

    inc edx
    jmp middle_loop

next_row:
    inc ecx
    jmp outer_loop

multiply_done:
    ret

; -----------------------------
; Subroutine: print_matrix
; -----------------------------
print_matrix:
    xor ecx, ecx        ; i = 0 (row index for C)
print_matrix_outer:
    cmp ecx, [m]
    jge print_matrix_done

    xor edx, edx        ; j = 0 (column index for C)
print_matrix_inner:
    cmp edx, [p]
    jge print_newline

    ; C[i][j] = matrix_c[i * p + j]
    mov eax, ecx
    imul eax, [p]       ; i * p
    add eax, edx        ; i * p + j
    mov eax, [matrix_c + eax*4]
    call print_number

    ; Print space

    
    push edx
    push ecx 

    mov ecx, space
    call print_string

    pop ecx
    pop edx

    inc edx
    jmp print_matrix_inner

print_newline:
    push ecx
    mov ecx, newline
    call print_string
    pop ecx
    inc ecx
    jmp print_matrix_outer

print_matrix_done:
    ret

; -----------------------------
; Subroutine: print_string
; -----------------------------
print_string:
    push ebx
    push eax
    mov ebx, ecx        ; String pointer
    xor eax, eax
count_string_length:
    cmp byte [ebx + eax], 0
    je string_length_done
    inc eax
    jmp count_string_length
string_length_done:
    mov edx, eax        ; Length
    mov ecx, ebx        ; String pointer
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    int 0x80
    pop eax
    pop ebx
    ret

; -----------------------------
; Subroutine: read_number
; -----------------------------
read_number:
    push ebx
    push ecx
    push edx

    mov ecx, input_buffer
    mov edx, 32
    mov eax, 3          ; sys_read
    mov ebx, 0          ; stdin
    int 0x80

    mov ebx, input_buffer
    xor eax, eax
convert_loop:
    movzx edx, byte [ebx]
    cmp dl, 10          ; Newline
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

; -----------------------------
; Subroutine: print_number
; -----------------------------
print_number:
    push ebx
    push ecx
    push edx

    mov ecx, input_buffer
    add ecx, 31
    mov byte [ecx], 0   ; Null-terminate the buffer
    mov ebx, 10

convert_number:
    dec ecx
    xor edx, edx
    div ebx             ; EAX = EAX / 10, EDX = EAX % 10
    add dl, '0'
    mov [ecx], dl
    test eax, eax
    jnz convert_number

    mov edx, input_buffer + 31
    sub edx, ecx        ; Length
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    int 0x80

    pop edx
    pop ecx
    pop ebx
    ret
