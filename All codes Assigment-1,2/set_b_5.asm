
section .data
    prompt_n db "Enter N (number of rows for first matrix): ", 0
    prompt_m db "Enter M (number of columns for first matrix): ", 0
    prompt_elem db "Enter element [%d][%d]: ", 0
    print_elem db "%d ", 0
    newline db 10, 0
    fmt_int db "%d", 0
    matrix1_msg db "Enter elements for Matrix 1:", 10, 0
    matrix2_msg db "Enter elements for Matrix 2:", 10, 0
    result_msg db "Resultant Matrix:", 10, 0
    temp dd 0          ; Temporary storage for scanf

section .bss
    n: resd 1
    m: resd 1
    matrix1: resd 100  ; Max size 10x10
    matrix2: resd 100
    result: resd 100

section .text
    extern printf
    extern scanf
    global main

main:
    push ebp
    mov ebp, esp
    
    ; Get N
    push prompt_n
    call printf
    add esp, 4

    push n
    push fmt_int
    call scanf
    add esp, 8

    ; Get M
    push prompt_m
    call printf
    add esp, 4

    push m
    push fmt_int
    call scanf
    add esp, 8

    
    push matrix1_msg
    call printf
    add esp, 4

    mov esi, 0       
    ;/////////////////////////////////////////////////   
input1_row:
    mov edi, 0          
input1_col:
    
    push edi
    push esi
    push prompt_elem
    call printf
    add esp, 12

    
    mov eax, esi
    mul dword [m]
    add eax, edi
    mov ebx, eax        

    
    push temp
    push fmt_int
    call scanf
    add esp, 8

    
    mov eax, [temp]
    mov [matrix1 + ebx*4], eax

    inc edi
    mov eax, [m]
    cmp edi, eax
    jl input1_col

    inc esi
    inc esi
    sub esi,1
    mov eax, [n]
    cmp esi, eax
    jl input1_row

   
    push matrix2_msg
    call printf
    add esp, 4

    mov esi, 0     
    ;////////////////////////////////////////////////////     
input2_row:
    mov edi, 0          
input2_col:
    
    push edi
    push esi
    push prompt_elem
    call printf
    add esp, 8
    add esp,4

    
    mov eax, esi
    mul dword [n]
    add eax, edi
    mov ebx, eax        

    
    push temp
    push fmt_int
    call scanf
    add esp, 4
    add esp, 4

    
    mov eax, [temp]
    mov [matrix2 + ebx*4], eax

    inc edi
    mov eax, [n]
    cmp edi, eax
    jl input2_col

    inc esi
    mov eax, [m]
    cmp esi, eax
    jl input2_row

    
    mov esi, 0          
    ;//////////////////////////////////////
mult_i:
    mov edi, 0          
mult_j:
    
    mov eax, esi
    mul dword [n]
    add eax, edi
    mov dword [result + eax*4], 0

    mov ecx, 0          
mult_k:
   
    mov eax, esi
    mul dword [m]
    add eax, ecx
    mov ebx, [matrix1 + eax*4]

    
    push eax            
    push eax           
    pop eax           
    mov eax, ecx
    mul dword [n]
    add eax, edi
    mov edx, [matrix2 + eax*4]
    pop eax             
    push eax
    pop eax   
    imul ebx, edx

    
    push eax            
    mov eax, esi
    mul dword [n]
    add eax, edi
    add [result + eax*4], ebx
    pop eax            
    push eax
    pop eax          
    inc ecx
    mov eax, [m]
    cmp ecx, eax
    jl mult_k

    inc edi
    mov eax, [n]
    cmp edi, eax
    jl mult_j

    inc esi
    mov eax, [n]
    push eax
    pop eax
    cmp esi, eax
    jl mult_i

    ; Print result
    push result_msg
    push eax
    pop eax   
    
    call printf
    add esp, 4
    push eax
    pop eax         
    mov esi, 0          
print_row:
    mov edi, 0          
print_col:
    mov eax, esi
    mul dword [n]
    push eax
    pop eax
    add eax, edi

    push dword [result + eax*4]
    push print_elem
    call printf
    add esp, 8

    inc edi
    mov eax, [n]
    push eax
    pop eax  ;
    cmp edi, eax
    jl print_col

    push newline
    push eax  ;
    pop eax
    call printf
    add esp, 4

    inc esi
    mov eax, [n]
    push eax
    pop eax  ;
    cmp esi, eax
    jl print_row
    push eax
    pop eax
;/////////////////////////////////////////////////////
    mov esp, ebp
    pop ebp
    push eax ;
    pop eax
    xor eax, eax
    ret