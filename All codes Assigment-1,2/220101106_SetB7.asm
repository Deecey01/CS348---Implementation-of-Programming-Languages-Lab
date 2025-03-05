section .data
    prompt_n: db "Enter matrix size (N): ", 0
    scan_n: db "%d", 0
    input_prompt: db "Enter element [%d][%d]: ", 0
    scan_float: db "%lf", 0
    print_inverse: db 10, "Inverse Matrix is:", 10, 0
    print_element: db "%.2f ", 0
    newline: db 10, 0
    error_msg: db "Matrix is singular, inverse doesn't exist", 10, 0
    epsilon: dq 1.0e-10

section .bss
    n: resd 1
    matrix: resq 100
    augmented: resq 200

section .text
    global main
    extern printf
    extern scanf
    extern exit

main:
    push ebp
    mov ebp, esp
    sub esp, 8  ; Allocate stack space

    ; Print prompt for matrix size
    push prompt_n
    call printf
    add esp, 4

    ; Read matrix size
    push n
    push scan_n
    call scanf
    add esp, 8

    ; Validate matrix size
    mov eax, [n]
    cmp eax, 1
    jl exit_program
    cmp eax, 10
    jg exit_program

    ; Input matrix elements
    xor esi, esi        ; row counter
input_loop_row:
    cmp esi, [n]
    jge init_augmented
    xor edi, edi        ; column counter
input_loop_col:
    cmp edi, [n]
    jge input_next_row

    ; Print prompt
    push edi
    push esi
    push input_prompt
    call printf
    add esp, 12

    ; Calculate element offset
    mov eax, esi
    mul dword [n]
    add eax, edi
    shl eax, 3          ; multiply by 8 (size of double)
    add eax, matrix     

    ; Read element
    push eax
    push scan_float
    call scanf
    add esp, 8

    inc edi
    jmp input_loop_col
input_next_row:
    inc esi
    jmp input_loop_row

init_augmented:
    ; Initialize augmented matrix [A|I]
    xor esi, esi        ; row counter
aug_loop_row:
    cmp esi, [n]
    jge gauss_elim
    xor edi, edi        ; column counter
aug_loop_col:
    mov eax, [n]
    add eax, eax        ; 2*N columns
    cmp edi, eax
    jge aug_next_row

    mov eax, [n]
    cmp edi, eax        
    jge identity_part

    mov eax, esi
    mul dword [n]
    add eax, edi
    mov ecx, eax
    shl eax, 3
    fld qword [matrix + eax]

    mov eax, esi
    mul dword [n]
    add eax, eax
    add eax, edi
    shl eax, 3
    fstp qword [augmented + eax]
    jmp aug_continue

identity_part:
    mov eax, edi
    sub eax, [n]
    cmp eax, esi
    jne zero_element

    ; Set 1.0 on diagonal
    mov eax, esi
    mul dword [n]
    add eax, eax
    add eax, edi
    shl eax, 3
    fld1
    fstp qword [augmented + eax]
    jmp aug_continue

zero_element:
    mov eax, esi
    mul dword [n]
    add eax, eax
    add eax, edi
    shl eax, 3
    fldz
    fstp qword [augmented + eax]

aug_continue:
    inc edi
    jmp aug_loop_col
aug_next_row:
    inc esi
    jmp aug_loop_row

gauss_elim:
    ; Perform Gaussian elimination
    xor esi, esi        
pivot_loop:
    cmp esi, [n]
    jge print_inverse_matrix

    ; Normalize pivot row
    mov eax, esi
    mul dword [n]
    add eax, eax
    add eax, esi
    shl eax, 3
    fld qword [augmented + eax]  ; Load pivot element
    fld1
    fdivr                        ; 1/pivot
    fstp qword [ebp-8]          ; Store for reuse

    ; Multiply pivot row by 1/pivot
    xor edi, edi
normalize_loop:
    mov eax, [n]
    add eax, eax
    cmp edi, eax
    jge eliminate_others

    mov eax, esi
    mul dword [n]
    add eax, eax
    add eax, edi
    shl eax, 3
    fld qword [augmented + eax]
    fld qword [ebp-8]
    fmulp
    fstp qword [augmented + eax]

    inc edi
    jmp normalize_loop

eliminate_others:
    xor ecx, ecx        ; row counter
elim_loop_row:
    cmp ecx, [n]
    jge next_pivot
    cmp ecx, esi
    je elim_next_row

    ; Get multiplier
    mov eax, ecx
    mul dword [n]
    add eax, eax
    add eax, esi
    shl eax, 3
    fld qword [augmented + eax]
    fchs

    ; Eliminate row
    xor edi, edi
elim_loop_col:
    mov eax, [n]
    add eax, eax
    cmp edi, eax
    jge elim_next_row

    mov eax, esi
    mul dword [n]
    add eax, eax
    add eax, edi
    shl eax, 3
    fld qword [augmented + eax]
    fmul st0, st1

    mov eax, ecx
    mul dword [n]
    add eax, eax
    add eax, edi
    shl eax, 3
    fld qword [augmented + eax]
    faddp
    fstp qword [augmented + eax]

    inc edi
    jmp elim_loop_col

elim_next_row:
    fstp st0           
    inc ecx
    jmp elim_loop_row

next_pivot:
    inc esi
    jmp pivot_loop

print_inverse_matrix:
    ; Print "Inverse Matrix is:"
    push print_inverse
    call printf
    add esp, 4

    ; Print the inverse matrix
    xor esi, esi
print_loop_row:
    cmp esi, [n]
    jge exit_program
    xor edi, edi
print_loop_col:
    cmp edi, [n]
    jge print_newline

    ; Print element
    mov eax, esi
    mul dword [n]
    add eax, eax
    add eax, edi
    add eax, [n]        ; Offset to right half
    shl eax, 3
    
    fld qword [augmented + eax]
    sub esp, 8
    fstp qword [esp]
    push print_element
    call printf
    add esp, 12

    inc edi
    jmp print_loop_col

print_newline:
    push newline
    call printf
    add esp, 4
    inc esi
    jmp print_loop_row

exit_program:
    mov esp, ebp
    pop ebp
    push 0
    call exit