section .data
    prompt db "Enter text (max 1000 chars): ", 0
    prompt_len equ $ - prompt
    newline db 10
    quote db 34
    result_msg db "Character counts:", 10
    result_len equ $ - result_msg
    
    ; Buffer for number conversion
    num_buffer times 10 db 0
    
section .bss
    buffer resb 1000           
    counts resd 256              

section .text
    global _start

_start:
    mov eax, 4                    ; sys_write
    mov ebx, 1                    ; stdout
    mov ecx, prompt
    mov edx, prompt_len
    int 0x80

    ; Read input
    mov eax, 3                    ; sys_read
    mov ebx, 0                    ; stdin
    mov ecx, buffer
    mov edx, 1000
    int 0x80
    
    mov esi, eax

    mov ecx, 256           
    mov edi, counts   
    xor al, al              
    rep stosd                

    mov ecx, esi           
    mov esi, buffer             
count_loop:
    mov al, byte [esi]         
    inc dword [counts + 4*eax] 
    inc esi                    
    loop count_loop             

    ; Print results header
    mov eax, 4
    mov ebx, 1
    mov ecx, result_msg
    mov edx, result_len
    int 0x80

    xor ebx, ebx          
print_loop:
    mov eax, dword [counts + 4*ebx]
    test al, al         
    jz next_char           

    push ebx                  
    mov [buffer], bl          

    mov eax, 4              
    mov ebx, 1                  
    mov ecx, quote
    mov edx, 1
    int 0x80

    mov eax, 4             
    mov ebx, 1               
    mov ecx, buffer
    mov edx, 1
    int 0x80

     mov eax, 4        
    mov ebx, 1              
    mov ecx, quote
    mov edx, 1
    int 0x80

    ; Print separator
    mov byte [buffer], ':'       
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, 1
    int 0x80

    mov byte [buffer], ' '       ; Store space
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, 1
    int 0x80


    pop ebx                    

    mov eax, dword [counts + 4*ebx]  

    mov edi, num_buffer + 9      
    mov byte [edi], 0           ; Null terminator
    dec edi
    mov byte [edi], 10   
    dec edi
    mov ecx, 10                 ; Divisor

    push ebx

convert_loop:
    xor edx, edx              
    div ecx             
    add dl, '0'           
    mov [edi], dl          
    dec edi               
    test eax, eax          
    jnz convert_loop

    inc edi                  
    mov eax, 4
    mov ebx, 1
    mov ecx, edi
    mov edx, num_buffer + 10
    sub edx, edi
    int 0x80

    pop ebx

next_char:
    inc ebx                 
    cmp ebx, 256           
    jne print_loop         

    ; Exit program
    mov eax, 1                ; sys_exit
    xor ebx, ebx              ; Return 0
    int 0x80
