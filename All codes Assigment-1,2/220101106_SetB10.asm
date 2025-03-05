section .data
    prompt_n: db "Enter number of elements (max 10): ", 0
    prompt_k: db "Enter k (1 to n): ", 0  
    scan_n: db "%d", 0
    input_prompt: db "Enter number %d: ", 0
    scan_float: db "%lf", 0           
    print_array: db "Sorted array: ", 0
    print_element: db "%.2lf ", 0     
    print_k: db "The %dth largest element is: %.2lf", 10, 0  
    newline: db 10, 0

section .bss
    n: resd 1
    k: resd 1        
    array: resq 10   

section .text
    extern printf
    extern scanf
    global main

main:
    push ebp
    mov ebp, esp
    sub esp, 8      

    ; Get number of elements
    push prompt_n
    call printf
    add esp, 4

    push n
    push scan_n
    call scanf
    add esp, 8

    ; Input validation for n
    mov eax, [n]
    cmp eax, 10
    jg .done        
    cmp eax, 0
    jle .done       

    ; Get k
    push prompt_k
    call printf
    add esp, 4

    push k
    push scan_n
    call scanf
    add esp, 8

    ; Validate k
    mov eax, [k]
    cmp eax, 0
    jle .done           ; k should be > 0
    cmp eax, [n]
    jg .done           ; k should be <= n

    ; Input loop
    xor esi, esi      
.input_loop:
    cmp esi, [n]      
    jge .sort_prep     

    push esi
    push input_prompt
    call printf
    add esp, 8

    lea eax, [array + esi*8]  
    push eax
    push scan_float
    call scanf
    add esp, 8

    inc esi
    jmp .input_loop

.sort_prep:
    mov ecx, [n]                   
    dec ecx                        

.outer_loop:
    test ecx, ecx
    jz .print_prep                 
    
    xor esi, esi                   

.inner_loop:
    mov eax, [n]
    dec eax
    cmp esi, eax
    jge .outer_loop_continue

    fld qword [array + esi*8]        
    fld qword [array + esi*8 + 8]    
    fcomip st0, st1                  
    fstp st0                         
    jbe .no_swap                    

    fld qword [array + esi*8]
    fld qword [array + esi*8 + 8]
    fstp qword [array + esi*8]
    fstp qword [array + esi*8 + 8]

.no_swap:
    inc esi
    jmp .inner_loop

.outer_loop_continue:
    dec ecx
    jmp .outer_loop

.print_prep:
    push print_array
    call printf
    add esp, 4

    xor esi, esi                   

.print_loop:
    cmp esi, [n]
    jge .print_k_element

    fld qword [array + esi*8]
    sub esp, 8
    fstp qword [esp]               
    push print_element
    call printf
    add esp, 12

    inc esi
    jmp .print_loop

.print_k_element:
    push newline
    call printf
    add esp, 4

    ; Print kth largest element
    mov eax, [k]
    dec eax             ; Decrement k by 1 for 0-based indexing
    fld qword [array + eax*8]  ; Load kth element
    sub esp, 8
    fstp qword [esp]    ; Push value for printf
    push dword [k]      ; Push k
    push print_k
    call printf
    add esp, 16

.done:
    mov esp, ebp
    pop ebp
    ret