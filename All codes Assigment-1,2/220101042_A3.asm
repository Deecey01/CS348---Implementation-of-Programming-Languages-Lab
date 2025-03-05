section .data
    prompt_n db "Enter the size of array: "
    prompt_n_len equ $ - prompt_n
    prompt_num db "Enter number: "
    prompt_num_len equ $ - prompt_num
    msg_min db "Smallest = "
    msg_min_len equ $ - msg_min
    msg_min_loc db "Location of smallest = "
    msg_min_loc_len equ $ - msg_min_loc
    msg_max db "Largest = "
    msg_max_len equ $ - msg_max
    msg_max_loc db "Location of largest = "
    msg_max_loc_len equ $ - msg_max_loc
    newline db 0xA
    space db " "

section .bss
    array resd 100    
    n resd 1          
    min resd 1        
    max resd 1        
    min_loc resd 1    
    max_loc resd 1    
    input_buffer resb 32
    output_buffer resb 32

section .text
    global _start

_start:
    ; Print prompt for array size
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    mov ecx, prompt_n
    mov edx, prompt_n_len
    int 0x80

    ; Read array size
    call read_num
    mov [n], eax

    ; Initialize loop counter for input
    xor ecx, ecx        ; ecx = 0
input_loop:
    cmp ecx, [n]
    jge input_done

    ; Print prompt for number
    push ecx            ; Save counter
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_num
    mov edx, prompt_num_len
    int 0x80

    ; Read number
    call read_num
    pop ecx             ; Restore counter
    mov [array + ecx*4], eax
    inc ecx
    jmp input_loop

input_done:
    ; Initialize min and max with first element
    mov eax, [array]
    mov [min], eax
    mov [max], eax
    mov dword [min_loc], 0
    mov dword [max_loc], 0

    ; Initialize loop counter for finding min/max
    mov ecx, 1
find_loop:
    cmp ecx, [n]
    jge find_done

    ; Compare current element with min
    mov eax, [array + ecx*4]
    cmp eax, [min]
    jge not_min
    mov [min], eax
    mov [min_loc], ecx
not_min:
    ; Compare current element with max
    cmp eax, [max]
    jle not_max
    mov [max], eax
    mov [max_loc], ecx
not_max:
    inc ecx
    jmp find_loop

find_done:
    ; Print smallest number
    mov eax, 4
    mov ebx, 1
    mov ecx, msg_min
    mov edx, msg_min_len
    int 0x80

    mov eax, [min]
    call print_num

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Print location of smallest
    mov eax, 4
    mov ebx, 1
    mov ecx, msg_min_loc
    mov edx, msg_min_loc_len
    int 0x80

    mov eax, [min_loc]
    inc eax
    call print_num

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Print largest number
    mov eax, 4
    mov ebx, 1
    mov ecx, msg_max
    mov edx, msg_max_len
    int 0x80

    mov eax, [max]
    call print_num

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Print location of largest
    mov eax, 4
    mov ebx, 1
    mov ecx, msg_max_loc
    mov edx, msg_max_loc_len
    int 0x80

    mov eax, [max_loc]
    inc eax
    call print_num

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Exit program
    mov eax, 1          ; sys_exit
    xor ebx, ebx        ; return 0
    int 0x80

; Function to read a number from stdin
read_num:
    push ebx
    push ecx
    push edx

    ; Read input
    mov eax, 3         
    mov ebx, 0          
    mov ecx, input_buffer
    mov edx, 32
    int 0x80

    ; Convert string to number
    xor eax, eax       
    mov ecx, input_buffer
convert_loop:
    movzx edx, byte [ecx]   ; Get current character
    cmp dl, 0xA             ; Check for newline
    je convert_done
    cmp dl, '0'             ; Check if it's a digit
    jb convert_done
    cmp dl, '9'
    ja convert_done
    sub dl, '0'             
    imul eax, 10            
    add eax, edx            
    inc ecx
    jmp convert_loop

convert_done:
    pop edx
    pop ecx
    pop ebx
    ret

; Function to print a number
print_num:
    push ebx
    push ecx
    push edx

    mov ecx, output_buffer
    add ecx, 31             ; Start from end of buffer
    mov byte [ecx], 0       ; Null terminate string
    mov ebx, 10             ; Divisor

convert_to_string:
    dec ecx
    xor edx, edx           
    div ebx                 
    add dl, '0'            
    mov [ecx], dl           
    test eax, eax          
    jnz convert_to_string

    ; Print the number
    mov eax, 4             
    mov ebx, 1             
    push ecx               
    mov edx, output_buffer
    add edx, 31             
    sub edx, ecx            
    int 0x80

    pop ecx
    pop edx
    pop ecx
    pop ebx
    ret


