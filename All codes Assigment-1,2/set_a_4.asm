extern printf
extern scanf

section .data
    num1 dd 0.0
    num2 dd 0.0
    num3 dd 0
    inf1 db "Enter first float: ", 0
    inf2 db "Enter second float: ", 0
    inf3 db "Enter op (1:Add, 2:Sub, 3:Mul, 4:Div): ", 0
    fmt_in_float db "%f", 0    
    fmt_in_int db "%d", 0      
    outptstring db "Output: ", 0
    printfmt db "%f", 10, 0    
    zero db "Error: Division by zero", 10, 0

section .text
global main

main:
    ; Print first prompt
    push inf1
    call printf
    add esp, 4
    
    ; First float input
    push num1
    push fmt_in_float
    call scanf
    add esp, 8
    
    ; Print second prompt
    push inf2
    call printf
    add esp, 4
    
    ; Second float input
    push num2
    push fmt_in_float
    call scanf
    add esp, 8
    
    ; Print operation prompt
    push inf3
    call printf
    add esp, 4
    
    ; Operation input
    push num3
    push fmt_in_int
    call scanf
    add esp, 8
    
    ; Print output string
    push outptstring
    call printf
    add esp, 4

    
    fld dword [num1]    
    fld dword [num2]    
    
    ; Check operation
    mov ecx, [num3]
    mov edi,2
    cmp ecx, 1
    je addval
    cmp ecx, 2
    je subval
    cmp ecx, 3
    je mulval
    cmp ecx, 4
    je divval
    jmp end
;//////////////////////////////////////////////
addval:
    faddp st1, st0 
    mov edi,3     
    sub esp, 8          
    fstp qword [esp]   
    push printfmt
    call printf
    add esp, 12
    jmp end
;///////////////////////////////////////////////
subval:
    fsubp st1, st0  
    mov edi,2    
    sub esp, 8     

    fstp qword [esp]    
    push printfmt
    call printf
    add esp, 12
    jmp end
;////////////////////////////////////////////////
mulval:
    fmulp st1, st0      
    sub esp, 8    
    mov edi,2      
    fstp qword [esp]    
    push printfmt
    call printf
    add esp, 12
    jmp end
;///////////////////////////////////////////////
divval:
    
    fldz                
    fcomip st0, st1     
    je ifzero           
    mov edi,3
    fdivp st1, st0      
    sub esp, 8          
    fstp qword [esp]    
    push printfmt
    call printf
    add esp, 12
    jmp end
;/////////////////////////////////////////////////
ifzero:
    fstp st0            
    fstp st0
    push zero
    call printf
    add esp, 4

end:
    mov eax, 1
    int 0x80