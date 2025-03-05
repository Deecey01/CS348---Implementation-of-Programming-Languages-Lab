section .data 
    prompt_n db "Enter the size of array: "
    prompt_n_len equ $ - prompt_n
    prompt_k db "Enter k: "
    prompt_k_len equ $ - prompt_k
    prompt_num db "Enter number: "
    prompt_num_len equ $ - prompt_num
    max_msg db "Kth Largest: "
    max_msg_len equ $ - max_msg
    max_idx db "Index: "
    max_idx_len equ $ - max_idx
    newline db 10

section .bss
    array resd 100    ; Can store up to 100 integers
    original_array resd 100    
    ans resd 1
    n resd 1        
    k resd 1       
    max resd 1       
    max_loc resd 1   
    buffer resb 32   ; Buffer for number input
    num resd 1       ; Converted number storage

section .text 
    global _start

; Convert ASCII string to integer
; Input: buffer address in eax
; Output: integer in eax

atoi:
    push ebx
    push ecx
    push edx
    mov ecx, eax    ; Save buffer address
    xor eax, eax    ; Initialize result
    xor ebx, ebx    ; Initialize index
.next:
    movzx edx, byte [ecx + ebx]    ; Get current char
    cmp dl, 0       ; Check for null terminator
    je .done
    cmp dl, '0'     ; Check if below '0'
    jb .done
    cmp dl, '9'     ; Check if above '9'
    ja .done
    sub dl, '0'     
    imul eax, 10   
    add eax, edx    
    inc ebx         
    jmp .next
.done:
    pop edx
    pop ecx
    pop ebx
    ret

; Convert integer to ASCII string
; Input: integer in eax, buffer address in ebx
; Output: length in eax

itoa:
    push ecx
    push edx
    push esi
    push edi
    mov esi, ebx        ; Save buffer address
    mov edi, 10         ; Divisor
    xor ecx, ecx        ; Character count
    
.divide_loop:
    xor edx, edx        ; Clear high bits before div
    div edi            
    add dl, '0'        
    push edx           
    inc ecx             
    test eax, eax      
    jnz .divide_loop
    
    mov eax, ecx        ; Save length for return
    
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
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
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
    mov byte [buffer + eax - 1], 0  ; Replace newline with null, eax automatically has the length of buffer 
    mov eax, buffer
    call atoi
    mov [n], eax

    ; Print prompt for k
    mov eax, 4          ; sys_write
    mov ebx, 1          ; stdout
    mov ecx, prompt_k
    mov edx, prompt_k_len
    int 0x80

    call clear_buffer
    ; Read k
    mov eax, 3          ; sys_read
    mov ebx, 0          ; stdin
    mov ecx, buffer
    mov edx, 32
    int 0x80
    
    ; Convert string to number
    mov byte [buffer + eax - 1], 0  ; Replace newline with null, eax automatically has the length of buffer 
    mov eax, buffer
    call atoi
    mov [k], eax

    ; Initialize loop counter
    xor esi, esi        ; esi = array index

input_loop:
    ; Check if we've reached n
    mov ecx, dword [n] 
    cmp esi, ecx
    jge input_done

    ; Print prompt for number
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_num
    mov edx, prompt_num_len
    int 0x80

    call clear_buffer
    ; Read number
    mov eax, 3
    mov ebx, 0
    mov ecx, buffer
    mov edx, 32
    int 0x80

    ; Convert input to number
    mov byte [buffer + eax - 1], 0
    mov eax, buffer
    call atoi
    mov [num], eax

    ; Store number in array
    mov eax, dword [num]
    mov dword [array + esi*4], eax
    mov dword [original_array + esi*4], eax

continue_input:
    inc esi
    jmp input_loop

input_done:
    ; No need to sort the array
    ; call sort
sort:
    push ecx
    push edi
    push esi
    push eax
    push ebx
    
    mov ecx, dword [n]      ; Load array size
    dec ecx                 ; ecx = n - 1
    mov edi, ecx            ; edi = n - 1 (outer loop counter)

    outer_loop:
        xor esi, esi            ; esi = 0 (inner loop counter)

    inner_loop:
        mov eax, dword [array + esi*4]    ; Load array[esi]
        mov ebx, dword [array + esi*4+4] ; Load array[esi + 1]
        cmp eax, ebx            ; Compare array[esi] and array[esi + 1]
        jle no_swap             ; If array[esi] <= array[esi + 1], no swap

        ; Swap array[esi] and array[esi + 1]
        mov dword [array + esi*4], ebx
        mov dword [array + esi*4 + 4], eax

    no_swap:
        inc esi                 ; esi++
        cmp esi, edi            ; Compare esi with outer loop counter
        jl inner_loop           ; If esi < edi, continue inner loop

        dec edi                 ; edi--
        jnz outer_loop          ; If edi != 0, continue outer loop

    pop ebx
    pop eax
    pop esi
    pop edi
    pop ecx

print_kth:
    mov ecx, dword [k]      ; Load k
    dec ecx                 ; Convert to zero-based index

    push ecx

    ; Print max message
    mov eax, 4              
    mov ebx, 1              
    mov ecx, max_msg
    mov edx, max_msg_len   
    int 0x80

    pop ecx

    ; Convert number to string
    call clear_buffer
    mov ebx, buffer         ; Buffer for itoa
    mov eax, dword [array + ecx*4] ; Load kth element
    mov [ans], eax
    call itoa
    
    ; Print number
    mov edx, eax           
    mov eax, 4             
    mov ebx, 1              
    mov ecx, buffer
    int 0x80

    ; Print newline
    mov eax, 4              
    mov ebx, 1             
    mov ecx, newline
    mov edx, 1              
    int 0x80

    ; print index

    ; Find index of 'ans' in original_array
    mov eax, [ans]       
    xor esi, esi        

find_index:
    mov ebx, dword [original_array + esi*4] 
    cmp eax, ebx       
    je print_index      
    inc esi            
    jmp find_index     

print_index:
    ; Convert index to string
    call clear_buffer
    mov ebx, buffer     
    inc esi
    mov eax, esi        
    call itoa

    mov eax, 4
    mov ebx, 1
    mov ecx, max_idx
    mov edx, max_idx_len
    int 0x80

    ; Print index
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

    ; Exit program
    mov eax, 1             
    xor ebx, ebx            
    int 0x80

clear_buffer:
    push ecx 
    push edi
    push eax
    mov ecx, 32         
    mov edi, buffer      
    xor eax, eax         
    rep stosb            
    pop eax
    pop edi
    pop ecx
    ret




