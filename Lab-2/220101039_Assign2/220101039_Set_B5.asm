;-------------------------------------
; NAME: DIVYANSH CHANDAK (220101039)
; Write a program to multiply the given two matrices (N*M, M*N) and print the resultant matrix.
; All inputs must be taken from the user.
;-------------------------------------

; How to run? 
; Run the following commands:
; nasm -f elf32 220101039_Set_B5.asm -o 220101039_Set_B5.o
; ld -m elf_i386 220101039_Set_B5.o -o 220101039_Set_B5
; ./220101039_Set_B5

extern printf
extern scanf
section .data
    input_n db "Enter number of rows for first matrix (N, to be <=10): ", 0
    input_m db "Enter number of columns for first matrix / rows for second matrix (M, to be <=10): ", 0
    input_p db "Enter number of columns for second matrix (P, to be <=10): ", 0
    AMAT_msg db "Enter elements for first matrix:", 10, 0
    BMAT_msg db "Enter elements for second matrix:", 10, 0
    resultant_matrix_msg db "Resultant Matrix :", 10, 0
    open_error db "Error: Cannot open file.", 0xA, 0
    input_element_msg db "Enter element: ", 0
    newline db 10, 0
    space db " ", 0

section .bss
    m resd 1              ; Rows of first matrix
    n resd 1              ; Columns of first matrix / Rows of second matrix
    p resd 1              ; Columns of second matrix
    buffer resb 1024      ; buffer for reading elements
    AMAT resd 100     
    BMAT resd 100     
    CMAT resd 100     
    temp resd 1           ; Temporary variable for sum in multiplication

section .text
    global _start

_start:
    ; Get N
    mov ecx, input_n
    call print_msg
    ; push input_n
    ; call printf
    add esp, 4

    call read_number
    mov [m], eax

    ; Get M
    mov ecx, input_m
    call print_msg
    call read_number
    mov [n], eax

    ; Get P
    mov ecx, input_p
    call print_msg
    call read_number
    mov [p], eax
    

    ; Input first matrix
    mov ecx, AMAT_msg
    call print_msg
    mov ebx, AMAT
    mov eax, [m]    
    mov edx, [n]    
    call input_matrix

    ; Input second matrix
    mov ecx, BMAT_msg
    call print_msg
    mov ebx, BMAT
    mov eax, [n]    
    mov edx, [p]    
    call input_matrix

    ; Perform matrix multiplication
    call multiplication

    ; Print the resultant matrix
    mov ecx, resultant_matrix_msg
    call print_msg
    call print_matrix

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80 

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

    mov ecx, input_element_msg
    call print_msg
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

multiplication:
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

    ; A[i][k] = AMAT[i * n + k]
    mov eax, ecx
    imul eax, [n]       ; i * n
    add eax, esi        ; i * n + k
    mov ebx, [AMAT + eax*4]

    ; B[k][j] = BMAT[k * p + j]
    mov eax, esi
    imul eax, [p]       ; k * p
    add eax, edx        ; k * p + j
    mov eax, [BMAT + eax*4]

    imul eax, ebx       ; A[i][k] * B[k][j]
    add dword [temp], eax    ; Accumulate the sum

    inc esi
    jmp inner_loop

store_result:
    ; Store sum in C[i][j] = CMAT[i * p + j]
    mov eax, ecx
    imul eax, [p]       ; i * p
    add eax, edx        ; i * p + j
    mov ebx, [temp]

    
    mov [CMAT + eax*4], ebx

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

    ; C[i][j] = CMAT[i * p + j]
    mov eax, ecx
    imul eax, [p]       ; i * p
    add eax, edx        ; i * p + j
    mov eax, [CMAT + eax*4]
    call print_number

    ; Print space
    push edx
    push ecx 

    mov ecx, space
    call print_msg

    pop ecx
    pop edx

    inc edx
    jmp print_matrix_inner

print_newline:
    push ecx
    mov ecx, newline
    call print_msg
    pop ecx
    inc ecx
    jmp print_matrix_outer

print_matrix_done:
    ret

check_matrix_val4:
    push ebp
    push eax
    mov ebp, esp
    mov eax, 0       
    inc eax          
    mov esp, ebp
    pop eax
    pop ebp

check_row_val4:
    push ebp
    push ecx
    mov ebp, esp
    mov ecx, 10      
    pop ecx
    pop ebp

print_msg:
    push ebx
    push eax
    mov ebx, ecx        ; String pointer
    xor eax, eax
find_msg_len:
    cmp byte [ebx + eax], 0
    je sl_done
    inc eax
    jmp find_msg_len
sl_done:
    mov edx, eax        
    mov ecx, ebx        ; String pointer
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    int 0x80
    pop eax
    pop ebx
    ret

read_number:
    push ebx
    push ecx
    push edx

    mov ecx, buffer
    mov edx, 32
    mov eax, 3          ; sys_read
    mov ebx, 0          ; stdin
    int 0x80

    mov ebx, buffer
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

print_number:
    push ebx
    push ecx
    push edx

    mov ecx, buffer
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

    mov edx, buffer + 31
    sub edx, ecx        ; Length
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    int 0x80

    pop edx
    pop ecx
    pop ebx
    ret