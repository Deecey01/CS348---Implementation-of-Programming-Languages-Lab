;-------------------------------------
; NAME: DIVYANSH CHANDAK (220101039)
; SET-A-Q15
; Write a program to find the most repeated integer in an array of size n. Take n and
; the elements of the array as user input.
;-------------------------------------


section .data
    input_msg db "Enter the size of array: ", 0 ; Prompt message for array size input
    input_msg_size equ $ - input_msg          ; Length of the size prompt

    input_prompt db "Enter array elements (one per line): ", 10, 0 ; Prompt for array elements
    input_prompt_size equ $ - input_prompt                      ; Length of elements prompt

    result_msg db "Most frequent element is: ", 0 ; Message to display the result
    result_msg_size equ $ - result_msg             ; Length of the result message

    newline db 10  ; Newline character

section .bss
    array resb 100       ; Reserve space for the array (maximum 100 elements)
    freq resb 100        ; Reserve space for the frequency array (max 100 entries)
    size resb 1          ; Reserve 1 byte for storing the size of the array
    input resb 10        ; Buffer for reading input (max 10 characters)
    num resb 4           ; Temporary storage for number conversion
    most_frequent resb 4 ; Reserve 4 bytes for storing the most frequent number

section .text
    global _start

_start:
    ; Print size prompt
    mov eax, 4                  ; Syscall for write
    mov ebx, 1                  ; File descriptor (stdout)
    mov ecx, input_msg        ; Address of the size prompt
    mov edx, input_msg_size    ; Length of the size prompt
    int 80h                     ; Make the syscall

    ; Read size
    call read_number            ; Call function to read a number
    mov byte [size], al         ; Store the array size in `size`

    ; Print elements prompt
    mov eax, 4                  ; Syscall for write
    mov ebx, 1                  ; File descriptor (stdout)
    mov ecx, input_prompt    ; Address of elements prompt
    mov edx, input_prompt_size; Length of elements prompt
    int 80h                     ; Make the syscall

    ; Read array elements
    mov ecx, 0                  ; Counter for the array index
read_elements:
    cmp cl, [size]              ; Compare counter with the array size
    jge find_frequency          ; If all elements are read, proceed to calculate frequencies

    push ecx                    ; Save current counter
    call read_number            ; Call function to read a number
    pop ecx                     ; Restore counter

    mov [array + ecx], al       ; Store the read number in the array
    inc ecx                     ; Increment the counter
    jmp read_elements           ; Loop to read the next element

find_frequency:
    ; Initialize frequency array to 0
    mov ecx, 0                  ; Counter for frequency array
    mov al, 0                   ; Initialize frequency to 0
init_freq:
    cmp ecx, 100                ; Check if we initialized all 100 entries
    jge calc_frequency          ; If done, proceed to calculate frequencies
    mov [freq + ecx], al        ; Set frequency of the current index to 0
    inc ecx                     ; Move to the next index
    jmp init_freq               ; Repeat initialization

calc_frequency:
    mov ecx, 0                  ; Outer loop counter for traversing the array
outer_loop:
    cmp cl, [size]              ; Compare counter with array size
    jge find_max                ; If all elements processed, find the maximum frequency

    movzx eax, byte [array + ecx] ; Get the current element of the array
    movzx edx, byte [freq + eax]  ; Get its current frequency
    inc edx                       ; Increment the frequency
    mov [freq + eax], dl          ; Update the frequency array

    inc ecx                     ; Increment the counter
    jmp outer_loop              ; Loop to process the next element

find_max:
    mov ecx, 0                  ; Counter for frequency array
    mov dl, 0                   ; Initialize max frequency to 0
    mov bl, 0                   ; Initialize most frequent number to 0
check_freq:
    cmp ecx, 100                ; Check if all frequencies are processed
    jge print_result            ; If done, proceed to print the result

    mov al, [freq + ecx]        ; Get the frequency of the current number
    cmp al, dl                  ; Compare with max frequency so far
    jle continue                ; If less, continue to the next number

    mov dl, al                  ; Update max frequency
    mov bl, cl                  ; Update most frequent number

continue:
    inc ecx                     ; Increment the counter
    jmp check_freq              ; Loop to process the next frequency

print_result:
    ; Store result
    mov [most_frequent], bl     ; Store the most frequent number

    ; Print result message
    mov eax, 4                  ; Syscall for write
    mov ebx, 1                  ; File descriptor (stdout)
    mov ecx, result_msg         ; Address of result message
    mov edx, result_msg_size     ; Length of result message
    int 80h                     ; Make the syscall

    ; Print most frequent number
    movzx eax, byte [most_frequent] ; Load the most frequent number
    call print_number           ; Call function to print the number

    ; Print newline
    mov eax, 4                  ; Syscall for write
    mov ebx, 1                  ; File descriptor (stdout)
    mov ecx, newline            ; Address of newline character
    mov edx, 1                  ; Length of newline character
    int 80h                     ; Make the syscall

    ; Exit program
    mov eax, 1                  ; Syscall for exit
    xor ebx, ebx                ; Exit code 0
    int 80h                     ; Make the syscall

; Function to read a number from input
read_number:
    ; Read input
    mov eax, 3                  ; Syscall for read
    mov ebx, 0                  ; File descriptor (stdin)
    mov ecx, input              ; Address of input buffer
    mov edx, 10                 ; Max bytes to read
    int 80h                     ; Make the syscall

    ; Convert string to number
    mov esi, input              ; Pointer to input buffer
    xor eax, eax                ; Clear number accumulator
convert_loop:
    movzx ecx, byte [esi]       ; Get the next character
    cmp cl, 10                  ; Check for newline
    je done_convert             ; If newline, conversion is done
    cmp cl, ' '                 ; Check for space
    je done_convert             ; If space, conversion is done

    sub cl, '0'                 ; Convert ASCII to digit
    imul eax, 10                ; Multiply accumulator by 10
    add eax, ecx                ; Add digit to accumulator
    inc esi                     ; Move to the next character
    jmp convert_loop            ; Repeat conversion

done_convert:
    ret                         ; Return the converted number in EAX

; Function to print a number
print_number:
    mov ecx, 0                  ; Digit counter
    mov ebx, 10                 ; Divisor for modulo operation

    ; Convert number to string (reversed order)
convert_to_string:
    mov edx, 0
    div ebx                     ; Divide by 10
    add dl, '0'                 ; Convert remainder to ASCII
    push dx                     ; Save digit on the stack
    inc ecx                     ; Increment digit counter
    test eax, eax               ; Check if quotient is 0
    jnz convert_to_string       ; If not, continue conversion

    ; Print digits in correct order
print_digits:
    pop dx                      ; Get digit from the stack
    mov [num], dl               ; Store digit in buffer
    push ecx                    ; Save digit counter

    mov eax, 4                  ; Syscall for write
    mov ebx, 1                  ; File descriptor (stdout)
    mov ecx, num                ; Address of digit
    mov edx, 1                  ; Length of digit
    int 80h                     ; Make the syscall

    pop ecx                     ; Restore digit counter
    loop print_digits           ; Loop until all digits are printed

    ret                         ; Return from function

