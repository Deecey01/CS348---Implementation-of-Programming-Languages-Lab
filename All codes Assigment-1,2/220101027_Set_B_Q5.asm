section .data
    msg1 db "Enter number of rows for first matrix: ", 0
    msg2 db "Enter number of columns for first matrix: ", 0
    msg3 db "Enter element A[%d][%d]: ", 0
    msg4 db "Enter element B[%d][%d]: ", 0
    msg5 db "First Matrix:", 10, 0
    msg6 db "Second Matrix:", 10, 0
    msg7 db "Matrix Multiplication:", 10, 0
    format_int db "%d", 0
    format_space db " ", 0
    format_newline db 10, 0

section .bss
    matrix1 resd 100      
    matrix2 resd 100      
    result resd 100       
    n resd 1              
    m resd 1              

section .text
    global main
    extern printf, scanf

main:
    push ebp              
    mov ebp, esp

    push msg1          
    call printf
    add esp, 4

    push n               
    push format_int
    call scanf
    add esp, 8

    push msg2           
    call printf
    add esp, 4

    push m               
    push format_int
    call scanf
    add esp, 8

    ; matrix 1
    call input_matrix1

    ; matrix 2
    call input_matrix2

    ; Print matrices
    push msg5
    call printf
    add esp, 4
    call print_matrix1

    push msg6
    call printf
    add esp, 4
    call print_matrix2

    ; Multiply matrices
    call multiply_matrices

    ; Print result
    push msg7
    call printf
    add esp, 4
    call print_result

    mov esp, ebp       
    pop ebp
    xor eax, eax       
    ret

; input matrix
input_matrix1:
    push ebp
    mov ebp, esp
    
    xor esi, esi        
input1_row:
    xor edi, edi        
input1_col:
    push edi            ; Column 
    push esi            ; Row 
    push msg3
    call printf
    add esp, 12

    mov eax, esi
    mul dword [m]       
    add eax, edi
    lea eax, [matrix1 + eax*4]

    push eax
    push format_int
    call scanf
    add esp, 8

    inc edi
    cmp edi, [m]
    jl input1_col

    inc esi
    cmp esi, [n]
    jl input1_row

    pop ebp
    ret

input_matrix2:
    push ebp
    mov ebp, esp
    
    xor esi, esi        
input2_row:
    xor edi, edi        
input2_col:
    ; Print prompt
    push edi            ; Column 
    push esi            ; Row 
    push msg4
    call printf
    add esp, 12

    mov eax, esi
    mul dword [n]       
    add eax, edi
    lea eax, [matrix2 + eax*4]

    ; Read element
    push eax
    push format_int
    call scanf
    add esp, 8

    inc edi
    cmp edi, [n]
    jl input2_col

    inc esi
    cmp esi, [m]
    jl input2_row

    pop ebp
    ret

multiply_matrices:
    push ebp
    mov ebp, esp
    
    xor esi, esi       
mult_row:
    xor edi, edi       
mult_col:
    mov eax, esi
    mul dword [n]       
    add eax, edi        
    mov dword [result + eax*4], 0  
    
    xor ecx, ecx        
mult_elem:
    mov eax, esi        
    mul dword [m]       
    add eax, ecx        
    mov ebx, [matrix1 + eax*4]  

    mov eax, ecx        
    mul dword [n]       
    add eax, edi        
    mov edx, [matrix2 + eax*4]  

    imul ebx, edx
    
    mov eax, esi
    mul dword [n]
    add eax, edi
    add [result + eax*4], ebx

    inc ecx
    cmp ecx, [m]
    jl mult_elem

    inc edi
    cmp edi, [n]
    jl mult_col

    inc esi
    cmp esi, [n]
    jl mult_row

    pop ebp
    ret

print_matrix1:
    push ebp
    mov ebp, esp
    
    xor esi, esi        
print1_row:
    xor edi, edi       
print1_col:
    mov eax, esi
    mul dword [m]
    add eax, edi
    push dword [matrix1 + eax*4]
    push format_int
    call printf
    add esp, 8

    push format_space
    call printf
    add esp, 4

    inc edi
    cmp edi, [m]
    jl print1_col

    push format_newline
    call printf
    add esp, 4

    inc esi
    cmp esi, [n]
    jl print1_row

    pop ebp
    ret

print_matrix2:
    push ebp
    mov ebp, esp
    
    xor esi, esi        ; Row 
print2_row:
    xor edi, edi        ; Column 
print2_col:
    mov eax, esi
    mul dword [n]
    add eax, edi
    push dword [matrix2 + eax*4]
    push format_int
    call printf
    add esp, 8

    push format_space
    call printf
    add esp, 4

    inc edi
    cmp edi, [n]
    jl print2_col

    push format_newline
    call printf
    add esp, 4

    inc esi
    cmp esi, [m]
    jl print2_row

    pop ebp
    ret

print_result:
    push ebp
    mov ebp, esp
    
    xor esi, esi        ; Row 
print_res_row:
    xor edi, edi        ; Column 
print_res_col:
    mov eax, esi
    mul dword [n]
    add eax, edi
    push dword [result + eax*4]
    push format_int
    call printf
    add esp, 8

    push format_space
    call printf
    add esp, 4

    inc edi
    cmp edi, [n]
    jl print_res_col

    push format_newline
    call printf
    add esp, 4

    inc esi
    cmp esi, [n]
    jl print_res_row

    pop ebp
    ret