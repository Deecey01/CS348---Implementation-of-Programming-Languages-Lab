section .data 
    prompt_n db "Enter the size of array: "
    prompt_n_len equ $ - prompt_n
    prompt_k db "Enter k: "
    prompt_k_len equ $ - prompt_k
    prompt_num db "Enter number: "
    prompt_num_len equ $ - prompt_num
    max_msg db "Kth Largest: "
    max_msg_len equ $ - max_msg
    newline db 10

section .bss
    array resd 100   ; Can store up to 100 integers
    n resd 1         ; Size of array
    k resd 1         ; kth largest
    max resd 1       ; Maximum value
    max_loc resd 1   ; Location of maximum
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
    sub dl, '0'     ; Convert to number
    imul eax, 10    ; Multiply current result by 10
    add eax, edx    ; Add new digit
    inc ebx         ; Move to next char
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
    div edi             ; Divide by 10
    add dl, '0'         ; Convert remainder to ASCII
    push edx            ; Save digit on stack
    inc ecx             ; Increment count
    test eax, eax       ; Check if quotient is zero
    jnz .divide_loop
    
    mov eax, ecx        ; Save length for return
    
.store_loop:
    pop edx             ; Get digit from stack
    mov [esi], dl       ; Store in buffer
    inc esi             ; Move to next position
    loop .store_loop    ; Repeat for all digits
    
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
    push edx

    mov ecx, dword [n]      ; Load array size
    xor edi, edi           ; i = 0

    outer_loop_selection:
        cmp edi, ecx           ; Compare i with n
        jge selection_done     ; If i >= n, done
        
        mov edx, edi           ; min_idx = i
        mov esi, edi           ; j = i
        inc esi                ; j = i + 1

    find_minimum:
        cmp esi, ecx           ; Compare j with n
        jge swap_minimum       ; If j >= n, swap minimum
        
        mov eax, dword [array + esi*4]    ; Load array[j]
        mov ebx, dword [array + edx*4]    ; Load array[min_idx]
        cmp eax, ebx                      ; Compare array[j] with array[min_idx]
        jge next_element                  ; If array[j] >= array[min_idx], skip
        mov edx, esi                      ; Update min_idx = j

    next_element:
        inc esi                ; j++
        jmp find_minimum       ; Continue inner loop

    swap_minimum:
        cmp edx, edi          ; Check if min_idx != i
        je next_iteration     
        
        mov eax, dword [array + edi*4]    ; temp = array[i]
        mov ebx, dword [array + edx*4]    ; Load array[min_idx]
        mov dword [array + edi*4], ebx    ; array[i] = array[min_idx]
        mov dword [array + edx*4], eax    ; array[min_idx] = temp

    next_iteration:
        inc edi               ; i++
        jmp outer_loop_selection

    selection_done:
        pop edx
        pop ebx
        pop eax
        pop esi
        pop edi
        pop ecx
; print_array:
;     mov ecx , dword [n]     ; Load n
;     dec ecx                 ; Zero based Indexing

;     call clear_buffer
;     mov ebx, buffer         ; Buffer for itoa
;     mov eax, dword [array + ecx*4] ; Load kth element
;     call itoa

print_kth:
    mov ecx, dword [k]      ; Load k
    dec ecx                 ; Convert to zero-based index

    push ecx

    ; Print max message
    mov eax, 4              ; sys_write
    mov ebx, 1              ; stdout
    mov ecx, max_msg
    mov edx, max_msg_len    ; Length of max_msg
    int 0x80

    pop ecx

    ; Convert number to string
    call clear_buffer
    mov ebx, buffer         ; Buffer for itoa
    mov eax, dword [array + ecx*4] ; Load kth element
    call itoa
    
    ; Print number
    mov edx, eax            ; Length of number string
    mov eax, 4              ; sys_write
    mov ebx, 1              ; stdout
    mov ecx, buffer
    int 0x80

    ; Print newline
    mov eax, 4              ; sys_write
    mov ebx, 1              ; stdout
    mov ecx, newline
    mov edx, 1              ; Length of newline
    int 0x80

    ; Exit program
    mov eax, 1              ; sys_exit
    xor ebx, ebx            ; status = 0
    int 0x80

clear_buffer:
    push ecx 
    push edi
    push eax
    mov ecx, 32          ; Number of bytes to clear
    mov edi, buffer      ; Address of buffer
    xor eax, eax         ; Value to set (0)
    rep stosb            ; Clear buffer
    pop eax
    pop edi
    pop ecx
    ret