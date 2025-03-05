;-------------------------------------
; NAME: DIVYANSH CHANDAK (220101039)
; SET-B-Q6
; Write a program to find the transpose of a (N*N) matrix and print the resultant
; matrix. All inputs must be taken from user.
;-------------------------------------

; section .data
;     msg1 db "Enter the size of the matrix (N): ", 0
;     msg2 db "Enter matrix elements row by row: ", 0
;     msg3 db "The transposed matrix is: ", 0
;     newline db 0xA, 0
;     buffer db 0

; section .bss
;     n resb 4                  ; Matrix size (N)
;     matrix resb 400           ; Matrix buffer (max 10x10, 4 bytes per element)
;     transpose resb 400        ; Transposed matrix buffer

; section .text
;     global _start

; _start:
;     ; Prompt for matrix size (N)
;     mov eax, 4
;     mov ebx, 1
;     mov ecx, msg1
;     mov edx, 31
;     int 0x80

;     ; Read N
;     mov eax, 3
;     mov ebx, 0
;     mov ecx, n
;     mov edx, 4
;     int 0x80

;     ; Convert N from ASCII to integer
;     mov ecx, n
;     call atoi
;     mov [n], eax

;     ; Prompt for matrix elements
;     mov eax, 4
;     mov ebx, 1
;     mov ecx, msg2
;     mov edx, 34
;     int 0x80

;     ; Input matrix elements
;     mov esi, matrix           ; Pointer to matrix buffer
;     mov ecx, [n]              ; Rows
;     mov edx, [n]              ; Columns

; input_matrix:
;     cmp ecx, 0                ; Check if all rows are processed
;     je transpose_matrix
;     mov edi, edx              ; Reset column counter
; input_row:
;     cmp edi, 0
;     je next_row

;     ; Read element
;     mov eax, 3
;     mov ebx, 0
;     mov ecx, buffer
;     mov edx, 4
;     int 0x80

;     ; Convert element to integer
;     mov ecx, buffer
;     call atoi

;     ; Store in matrix
;     mov [esi], eax
;     add esi, 4                ; Move to next matrix element
;     dec edi
;     jmp input_row

; next_row:
;     dec ecx                   ; Move to next row
;     jmp input_matrix

; transpose_matrix:
;     ; Transpose the matrix
;     mov esi, matrix           ; Pointer to original matrix
;     mov ecx, [n]              ; Rows (outer loop)

; transpose_outer:
;     cmp ecx, 0
;     je print_transpose
;     push ecx                  ; Save outer loop counter
;     mov edi, transpose        ; Reset pointer to transposed matrix
;     mov edx, [n]              ; Columns (inner loop)

; transpose_inner:
;     cmp edx, 0
;     je next_transpose_row

;     ; Calculate transpose position
;     mov eax, [esi]            ; Get element from original matrix
;     mov [edi], eax            ; Store in transposed matrix

;     add esi, 4                ; Move to next column in original matrix
;     add edi, [n]              ; Move to next row in transposed matrix
;     dec edx
;     jmp transpose_inner

; next_transpose_row:
;     pop ecx                   ; Restore outer loop counter
;     add esi, [n]              ; Move to next row in original matrix
;     sub esi, 4                ; Adjust for added column offset
;     dec ecx
;     jmp transpose_outer

; print_transpose:
;     ; Print the transposed matrix
;     mov eax, 4
;     mov ebx, 1
;     mov ecx, msg3
;     mov edx, 26
;     int 0x80

;     mov esi, transpose        ; Pointer to transposed matrix
;     mov ecx, [n]              ; Rows

; print_outer:
;     cmp ecx, 0
;     je done
;     push ecx
;     mov edx, [n]              ; Columns

; print_inner:
;     cmp edx, 0
;     je next_print_row

;     ; Print element
;     mov eax, [esi]
;     call print_number

;     ; Print space
;     mov eax, 4
;     mov ebx, 1
;     mov ecx, newline
;     mov edx, 1
;     int 0x80

;     add esi, 4                ; Move to next element
;     dec edx
;     jmp print_inner

; next_print_row:
;     ; Print newline
;     mov eax, 4
;     mov ebx, 1
;     mov ecx, newline
;     mov edx, 1
;     int 0x80

;     pop ecx                   ; Restore outer loop counter
;     dec ecx
;     jmp print_outer

; done:
;     ; Exit
;     mov eax, 1
;     xor ebx, ebx
;     int 0x80

; ; Helper: atoi
; ; Convert ASCII string to integer
; ; Input: ecx = address of string
; ; Output: eax = integer value
; atoi:
;     xor eax, eax
;     xor ebx, ebx
; atoi_loop:
;     mov bl, byte [ecx]
;     cmp bl, 0xA               ; Newline
;     je atoi_end
;     sub bl, '0'
;     imul eax, eax, 10
;     add eax, ebx
;     inc ecx
;     jmp atoi_loop
; atoi_end:
;     ret

; ; Helper: print_number
; ; Print integer in eax
; print_number:
;     push ebx
;     push ecx
;     push edx

;     xor ecx, ecx
;     mov ebx, 10

; print_digit:
;     xor edx, edx
;     div ebx
;     add dl, '0'
;     push dx
;     inc ecx
;     test eax, eax
;     jnz print_digit

; print_digit_loop:
;     pop dx
;     mov al, dl
;     mov [buffer], al
;     mov eax, 4
;     mov ebx, 1
;     mov ecx, buffer
;     mov edx, 1
;     int 0x80
;     loop print_digit_loop

;     pop edx
;     pop ecx
;     pop ebx
;     ret

section .data
    input_msg_n db "Enter the size of matrix (N): ", 0           ; Prompt message for inputting matrix size
    input_msg_n_len equ $ - input_msg_n                          ; Length of the above message
    
    input_msg_element db "Enter element [", 0                   ; Prompt message prefix for matrix element
    input_msg_element_len equ $ - input_msg_element             ; Length of the above message
    
    input_msg_row db "][", 0                                    ; Middle part of the prompt for element (row)
    input_msg_row_len equ $ - input_msg_row                     ; Length of the above message
    
    input_msg_col db "]: ", 0                                   ; End part of the prompt for element (column)
    input_msg_col_len equ $ - input_msg_col                     ; Length of the above message
    
    newline db 10, 0                                            ; Newline character
    space db " ", 0                                             ; Space character
    
    display_msg_original db "Original Matrix:", 10, 0           ; Message to display before the original matrix
    display_msg_original_len equ $ - display_msg_original       ; Length of the above message
    
    display_msg_transpose db 10, "Transpose Matrix:", 10, 0     ; Message to display before the transpose matrix
    display_msg_transpose_len equ $ - display_msg_transpose     ; Length of the above message

section .bss
    n resd 1                ; Reserve space for the matrix size (N)
    matrix resd 100         ; Reserve space for a 10x10 matrix (maximum size)
    buffer resb 32          ; Reserve a buffer for number-to-string conversion
    num_buffer resb 32      ; Reserve a buffer for reading numbers

section .text
    global _start

_start:
    ; Print prompt for N
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1                   ; file descriptor: stdout
    mov ecx, input_msg_n         ; message to print
    mov edx, input_msg_n_len     ; message length
    int 80h                      ; invoke syscall
    
    ; Read N
    call input_num               ; Call function to read the number (size of the matrix)
    mov [n], eax                 ; Store the inputted size in variable `n`
    
    ; Read matrix elements
    xor esi, esi                 ; Initialize row counter (esi) to 0
input_row:
    xor edi, edi                 ; Initialize column counter (edi) to 0
input_col:
    ; Print prompt for element
    push esi                     ; Save current row index on stack
    push edi                     ; Save current column index on stack
    
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1                   ; file descriptor: stdout
    mov ecx, input_msg_element   ; Print "Enter element ["
    mov edx, input_msg_element_len
    int 80h                      ; invoke syscall
    
    ; Print row number
    mov eax, esi                 ; Move row number to eax
    call print_num               ; Call function to print the number
    
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1
    mov ecx, input_msg_row       ; Print "]["
    mov edx, input_msg_row_len
    int 80h                      ; invoke syscall
    
    ; Print column number
    mov eax, edi                 ; Move column number to eax
    call print_num               ; Call function to print the number
    
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1
    mov ecx, input_msg_col       ; Print "]: "
    mov edx, input_msg_col_len
    int 80h                      ; invoke syscall
    
    ; Read element
    call input_num               ; Call function to read the input number
    
    pop edi                      ; Restore column index
    pop esi                      ; Restore row index
    
    ; Calculate position in matrix and store element
    push eax                     ; Save inputted number on stack
    mov eax, esi                 ; Load row index into eax
    mul dword [n]                ; Multiply row index by the size of the matrix (N)
    add eax, edi                 ; Add column index to get the flat index
    mov ebx, 4                   ; Element size is 4 bytes
    mul ebx                      ; Calculate byte offset for the element
    mov ebx, eax                 ; Store offset in ebx
    pop eax                      ; Retrieve the inputted number
    mov [matrix + ebx], eax      ; Store the number in the calculated position
    
    inc edi                      ; Increment column counter
    cmp edi, [n]                 ; Check if all columns are filled
    jl input_col                 ; If not, continue to next column
    
    inc esi                      ; Increment row counter
    cmp esi, [n]                 ; Check if all rows are filled
    jl input_row                 ; If not, continue to next row
    
    ; Print original matrix
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1
    mov ecx, display_msg_original ; Print "Original Matrix:"
    mov edx, display_msg_original_len
    int 80h                      ; invoke syscall
    
    call print_matrix            ; Call function to print the original matrix
    
    ; Print transpose matrix message
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1
    mov ecx, display_msg_transpose ; Print "Transpose Matrix:"
    mov edx, display_msg_transpose_len
    int 80h                      ; invoke syscall
    
    ; Print transpose
    xor esi, esi                 ; Initialize transpose column counter (row in transpose)
print_transpose_row:
    xor edi, edi                 ; Initialize transpose row counter (column in transpose)
print_transpose_col:
    ; Calculate position in original matrix
    push esi                     ; Save transpose row index
    push edi                     ; Save transpose column index
    
    mov eax, edi                 ; Original row index
    mul dword [n]                ; Multiply by N
    add eax, esi                 ; Add original column index
    mov ebx, 4                   ; Element size is 4 bytes
    mul ebx                      ; Calculate byte offset
    
    ; Print element
    mov eax, [matrix + eax]      ; Load element from calculated offset
    call print_num               ; Call function to print the element
    
    ; Print space
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1
    mov ecx, space               ; Print a space
    mov edx, 1
    int 80h                      ; invoke syscall
    
    pop edi                      ; Restore transpose column index
    pop esi                      ; Restore transpose row index
    
    inc edi                      ; Increment column counter (original row)
    cmp edi, [n]                 ; Check if all columns are printed
    jl print_transpose_col       ; If not, continue
    
    ; Print newline
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1
    mov ecx, newline             ; Print newline
    mov edx, 1
    int 80h                      ; invoke syscall
    
    inc esi                      ; Increment row counter (original column)
    cmp esi, [n]                 ; Check if all rows are printed
    jl print_transpose_row       ; If not, continue
    
    ; Exit program
    mov eax, 1                   ; syscall: sys_exit
    xor ebx, ebx                 ; Exit code 0
    int 80h                      ; invoke syscall

; Function to print matrix
print_matrix:
    xor esi, esi                 ; Initialize row counter
print_row:
    xor edi, edi                 ; Initialize column counter
print_col:
    ; Calculate position in matrix
    push esi                     ; Save row index
    push edi                     ; Save column index
    
    mov eax, esi                 ; Load row index into eax
    mul dword [n]                ; Multiply by N
    add eax, edi                 ; Add column index
    mov ebx, 4                   ; Element size is 4 bytes
    mul ebx                      ; Calculate byte offset
    
    ; Print element
    mov eax, [matrix + eax]      ; Load element from matrix
    call print_num               ; Call function to print the element
    
    ; Print space
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1
    mov ecx, space               ; Print a space
    mov edx, 1
    int 80h                      ; invoke syscall
    
    pop edi                      ; Restore column index
    pop esi                      ; Restore row index
    
    inc edi                      ; Increment column counter
    cmp edi, [n]                 ; Check if all columns are printed
    jl print_col                 ; If not, continue
    
    ; Print newline
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1
    mov ecx, newline             ; Print newline
    mov edx, 1
    int 80h                      ; invoke syscall
    
    inc esi                      ; Increment row counter
    cmp esi, [n]                 ; Check if all rows are printed
    jl print_row                 ; If not, continue
    ret                          ; Return from function

; Function to read number from input
input_num:
    mov ecx, num_buffer          ; Buffer to store input string
    mov edx, 32                  ; Maximum buffer length
    mov eax, 3                   ; syscall: sys_read
    mov ebx, 0                   ; file descriptor: stdin
    int 80h                      ; invoke syscall
    
    ; Convert string to number
    mov esi, num_buffer          ; Load buffer pointer into esi
    xor eax, eax                 ; Clear eax (result accumulator)
    xor ebx, ebx                 ; Clear ebx (unused)
input_loop:
    movzx edx, byte [esi]        ; Load a character from the buffer
    cmp dl, 10                   ; Check for newline character
    je read_done                 ; If newline, finish reading
    cmp dl, '0'                  ; Check if character is less than '0'
    jl read_done                 ; If so, stop (invalid input)
    cmp dl, '9'                  ; Check if character is greater than '9'
    jg read_done                 ; If so, stop (invalid input)
    
    sub dl, '0'                  ; Convert ASCII digit to numeric value
    imul eax, 10                 ; Multiply result by 10
    add eax, edx                 ; Add current digit to result
    inc esi                      ; Move to next character
    jmp input_loop               ; Repeat for next character
read_done:
    ret                          ; Return result in eax

; Function to print number
print_num:
    push eax                     ; Save eax on stack
    mov ecx, buffer + 31         ; Point to the end of the buffer
    mov byte [ecx], 0            ; Null-terminate the buffer
    mov ebx, 10                  ; Base 10 (decimal)
convert_loop:
    dec ecx                      ; Move pointer back
    xor edx, edx                 ; Clear edx (remainder)
    div ebx                      ; Divide eax by 10
    add dl, '0'                  ; Convert remainder to ASCII
    mov [ecx], dl                ; Store ASCII digit in buffer
    test eax, eax                ; Check if quotient is 0
    jnz convert_loop             ; If not, continue conversion
    
    ; Calculate length
    mov edx, buffer + 31         ; End of buffer
    sub edx, ecx                 ; Calculate length of the number string
    
    ; Print number
    mov eax, 4                   ; syscall: sys_write
    mov ebx, 1                   ; file descriptor: stdout
    int 80h                      ; invoke syscall
    
    pop eax                      ; Restore eax
    ret                          ; Return

