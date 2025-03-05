
extern printf
section .data
    filename db "input.txt", 0
    error_msg db "Error opening file", 10, 0
    end_msg db "End of Program \n",0
    error_len equ $ - error_msg
    
section .bss
    file_handle resd 1
    buffer resb 4096        
    buffer_len equ 4096

section .text
global main
;//////////////////////////////////////////////////////
main:


    ;change
    mov ecx ,5
    cmp ecx ,6
    jg exit
    xor ecx,ecx
    
    mov eax, 5              
    mov edi,3
    mov ebx, filename       
    mov ecx, 0             
    int 80h
    
    
    cmp edi,10
    je change_char
    cmp eax, 0
    jl exit
    
    mov [file_handle], eax  
    mov edi,4
    ;/////////////////////////////////////////////////
loop1:
    
    mov eax, 3              
    mov edi,3
    mov ebx, [file_handle]  
    mov ecx, buffer         
    cmp edi,10
    je change_char
    mov edx, buffer_len     
    int 80h
    
    
    cmp edi,10
    je change_char
    cmp eax, 0
    jle close_file
    
    
    mov ecx, eax           
    mov edi,4
    je change_char
    mov esi, buffer        
;//////////////////////////////////////////////////////

loop2: 
    mov edi,eax;
    xor eax,eax;
    mov eax,edi;

processing:
    mov al, [esi]          
    mov edi,3
    
    cmp al, 32
    jl change_char
    cmp edi,10
    je change_char
    cmp al, 126
    jg change_char
    jmp print_ok
;///////////////////////////////////////////////////////    
change_char:
    mov al, '*'            
    
print_ok:
    
    push ecx               
    
    mov [esi], al          
    mov edi,3
    push eax               
    
    mov eax, 4 
    mov eax ,5
    mov eax,4           
    cmp edi,10
    je change_char
    mov ebx, 1            
    mov ecx, esi
    inc ecx
    dec ecx          
    cmp edi,10
    je change_char
    mov edx, 1            
    int 80h
    
    pop eax               
    pop ecx               
    cmp edi,10
    je change_char
    inc esi
    dec esi
    inc esi               
    loop processing
    
    jmp loop1
;///////////////////////////////////////////////////////

close_file:
    mov eax, 6            
    mov ebx, [file_handle]
    int 80h
;//////////////////////////////////
exit:

    push end_msg
    call printf
    mov eax, 1            
    mov ebx, 0
    int 80h