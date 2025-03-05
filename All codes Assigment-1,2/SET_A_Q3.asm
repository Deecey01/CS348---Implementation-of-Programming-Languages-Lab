 section .data 
    prompt_n db "Enter the size of array: "
    prompt_n_len equ $ - prompt_n
    prompt_num db "Enter number: "
    prompt_num_len equ $ - prompt_num
    min_msg db "smallest="
    min_msg_len equ $ - min_msg
    min_loc_msg db 10, "loc small="    ; 10 is newline
    min_loc_msg_len equ $ - min_loc_msg
    max_msg db 10, "largest="
    max_msg_len equ $ - max_msg
    max_loc_msg db 10, "loc lar="
    max_loc_msg_len equ $ - max_loc_msg
    newline db 10

section .bss
    array resd 100    ; Can store up to 100 integers
    n resd 1         ; Size of array
    min resd 1       ; Minimum value
    max resd 1       ; Maximum value
    min_loc resd 1   ; Location of minimum
    max_loc resd 1   ; Location of maximum
    buffer resb 32   ; Buffer for number input
    num resd 1       ; Converted number storage

section .text 
    global _start

atoi:
    push ebx
    push ecx
    push edx
    mov ecx, eax    
    xor eax, eax    ;
    xor ebx, ebx  
.next:
    movzx edx, byte [ecx + ebx]    
    cmp dl, 0       ;
    je .done
    cmp dl, '0'  
    jb .done
    cmp dl, '9'     ; 
    ja .done
    sub dl, '0'     
    imul eax, 10    ;
    add eax, edx   
    inc ebx      
    jmp .next
.done:
    pop edx
    pop ecx
    pop ebx
    ret

itoa:
    push ecx
    push edx
    push esi
    push edi
    
    mov esi, ebx      
    mov edi, 10        
    xor ecx, ecx       
    
.divide_loop:
    xor edx, edx    
    div edi           
    add dl, '0'       
    push edx          
    inc ecx            
    test eax, eax       
    jnz .divide_loop
    
    mov eax, ecx    
    
.store_loop:
    pop edx             
    mov [esi], dl       
    inc esi          
    loop .store_loop  
    
    pop edi
    pop esi
    pop edx
    pop ecx
    ret

_start:
    ; Print prompt for array size
    mov eax, 4        
    mov ebx, 1       
    mov ecx, prompt_n
    mov edx, prompt_n_len
    int 0x80

    ; Read array size
    mov eax, 3          ; sys_read
    mov ebx, 0          ; stdin
    mov ecx, buffer
    mov edx, 32
    int 0x80
    
    ; Convert string to number
    mov byte [buffer + eax - 1], 0 
    mov eax, buffer
    call atoi
    mov [n], eax

    ; Initialize loop counter
    xor esi, esi     

input_loop:
    mov ecx, dword [n] 
    cmp esi, ecx
    jge input_done

    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_num
    mov edx, prompt_num_len
    int 0x80

    ; Read number
    mov eax, 3
    mov ebx, 0
    mov ecx, buffer
    mov edx, 32
    int 0x80

    mov byte [buffer + eax - 1], 0
    mov eax, buffer
    call atoi
    mov [num], eax

    mov eax, dword [num]
    mov dword [array + esi*4], eax

    cmp esi, 0
    jne not_first
    mov dword [min], eax
    mov dword [max], eax
    mov dword [min_loc], 0
    mov dword [max_loc], 0
    jmp continue_input

not_first:
    mov ecx, dword [min]
    cmp eax, ecx
    jge check_max
    mov dword [min], eax
    mov dword [min_loc], esi

check_max:
    mov ecx, dword [max]
    cmp eax, ecx
    jle continue_input
    mov dword [max], eax
    mov dword [max_loc], esi

continue_input:
    inc esi
    jmp input_loop

input_done:
;    Print minimum value
    mov eax, 4
    mov ebx, 1
    mov ecx, min_msg
    mov edx, min_msg_len
    int 0x80

    mov eax, [min]
    mov ebx, buffer
    call itoa
    mov edx, eax            
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    int 0x80

    ; Print minimum location
    mov eax, 4
    mov ebx, 1
    mov ecx, min_loc_msg
    mov edx, min_loc_msg_len
    int 0x80

    mov eax, [min_loc]
    mov ebx, buffer
    call itoa
    mov edx, eax       
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    int 0x80

    ; Print maximum value
    mov eax, 4
    mov ebx, 1
    mov ecx, max_msg
    mov edx, max_msg_len
    int 0x80

    mov eax, [max]
    mov ebx, buffer
    call itoa
    mov edx, eax       
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    int 0x80

    ; Print maximum location
    mov eax, 4
    mov ebx, 1
    mov ecx, max_loc_msg
    mov edx, max_loc_msg_len
    int 0x80

    mov eax, [max_loc]
    mov ebx, buffer
    call itoa
    mov edx, eax    
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    mov eax, 1          
    xor ebx, ebx   
    int 0x80