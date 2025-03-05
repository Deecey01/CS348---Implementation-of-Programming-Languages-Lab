section .data
    msg1 db "Enter the size of matrix: ", 0
    msg2 db "Enter element [%d][%d]: ", 0
    format_int db "%d", 0
    format_space db " ", 0
    newline db 10, 0
    msg3 db "Given Matrix:", 10, 0
    msg4 db "Result:", 10, 0

section .bss
    n resd 1              
    matrix resd 100       

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

    
    xor esi, esi        
row_input:
    xor edi, edi        
column_input:
    push edi            ; c
    push esi            ;  r
    push msg2
    call printf
    add esp, 12

    mov eax, esi        
    mul dword [n]       
    add eax, edi        
    lea eax, [matrix + eax*4]  

    push eax         
    push format_int
    call scanf
    add esp, 8

    inc edi             
    cmp edi, [n]
    jl column_input

    inc esi             
    cmp esi, [n]
    jl row_input

    
    push msg3
    call printf
    add esp, 4

    call print_matrix   

    push msg4
    call printf
    add esp, 4

    xor esi, esi       
print_transpose_row:
    xor edi, edi       
print_transpose_col:
    mov eax, edi        
    mul dword [n]
    add eax, esi        

    push dword [matrix + eax*4]
    push format_int
    call printf
    add esp, 8

    push format_space
    call printf
    add esp, 4

    inc edi
    cmp edi, [n]
    jl print_transpose_col

    push newline
    call printf
    add esp, 4

    inc esi
    cmp esi, [n]
    jl print_transpose_row

    mov esp, ebp        
    pop ebp
    xor eax, eax        
    ret
print_matrix:
    push ebp
    mov ebp, esp

    xor esi, esi      
print_row:
    xor edi, edi       
print_col:
    mov eax, esi        
    mul dword [n]       
    add eax, edi        
    
    push dword [matrix + eax*4]
    push format_int
    call printf
    add esp, 8

    push format_space
    call printf
    add esp, 4

    inc edi
    cmp edi, [n]
    jl print_col

    push newline
    call printf
    add esp, 4

    inc esi
    cmp esi, [n]
    jl print_row

    mov esp, ebp
    pop ebp
    ret