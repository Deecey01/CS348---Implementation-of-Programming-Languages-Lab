section .data
    prompt_elements db "Please enter the total number of elements: ", 0
    prompt_k_value db "Please enter the value of k (k must not exceed the number of elements): ", 0
    prompt_input_num db "Input value for element %d: ", 0
    result_message db "The %d-th largest value is: %f", 10, 0
    fmt_int_input db "%d", 0
    fmt_float_input db "%lf", 0
    error_message db "Error: k is greater than n. Please retry.", 10, 0
    new_line db 10, 0

section .bss
    total_elements resd 1      ; Stores total number of elements
    kth_value resd 1           ; Stores k for the k-th largest value
    data_array resq 100        ; Array to store floating point numbers (8 bytes each)
    temp_var resq 1            ; Temporary variable for input storage

section .text
    global main
    extern printf
    extern scanf
    extern exit

main:
    push ebp
    mov ebp, esp
    and esp, 0xFFFFFFF0         ; Stack alignment for better performance

    ; Prompt for number of elements
    push prompt_elements
    call printf
    add esp, 4

    push total_elements
    push fmt_int_input
    call scanf
    add esp, 8

    ; Prompt for value of k
    push prompt_k_value
    call printf
    add esp, 4

    push kth_value
    push fmt_int_input
    call scanf
    add esp, 8

    ; Check if k is less than or equal to the number of elements
    mov eax, [kth_value]
    cmp eax, [total_elements]
    jg error_case

    ; Read input numbers into the array
    xor esi, esi      ; Initialize counter to 0
input_loop:
    cmp esi, [total_elements]
    jge sort_values    ; Exit loop when all elements are read

    ; Display prompt for the current element
    push esi          ; Save counter
    push esi          ; Argument for printf
    push prompt_input_num
    call printf
    add esp, 8
    pop esi           ; Restore counter

    ; Read floating-point number
    push temp_var
    push fmt_float_input
    call scanf
    add esp, 8

    ; Store the number into the array
    mov eax, [temp_var]
    mov ebx, [temp_var + 4]
    mov [data_array + esi*8], eax
    mov [data_array + esi*8 + 4], ebx

    inc esi
    jmp input_loop

sort_values:
    ; Sort the array using insertion sort
    mov ecx, 1              ; Start from the second element
outer_loop:
    cmp ecx, [total_elements]
    jge display_result      ; If all elements are sorted, proceed to display result

    mov edx, ecx           ; Inner loop starts from current element
inner_loop:
    test edx, edx           ; Check if j == 0
    jz outer_continue

    ; Compare current element with previous one
    fld qword [data_array + edx * 8]       ; Load current element
    fld qword [data_array + edx * 8 - 8]   ; Load previous element
    fcomip st0, st1                       ; Compare elements and pop st0
    fstp st0                              ; Pop st1 (clear FPU stack)
    jbe outer_continue                    ; If current element is <= previous, continue with next iteration

    ; Swap elements
    push edx
    mov eax, [data_array + edx * 8]
    mov ebx, [data_array + edx * 8 + 4]
    mov esi, [data_array + edx * 8 - 8]
    mov edi, [data_array + edx * 8 - 4]
    mov [data_array + edx * 8 - 8], eax
    mov [data_array + edx * 8 - 4], ebx
    mov [data_array + edx * 8], esi
    mov [data_array + edx * 8 + 4], edi
    pop edx

    dec edx
    jmp inner_loop

outer_continue:
    inc ecx
    jmp outer_loop

display_result:
    ; Calculate the position of k-th largest (n - k)
    mov eax, [total_elements]
    sub eax, [kth_value]
    fld qword [data_array + eax * 8]   ; Load k-th largest number
    sub esp, 8
    fstp qword [esp]                    ; Store the number on the stack for printf
    push dword [kth_value]              ; Push k for formatting
    push result_message
    call printf
    add esp, 16

    mov esp, ebp
    pop ebp
    xor eax, eax
    ret

error_case:
    ; Display error message for invalid k
    push error_message
    call printf
    add esp, 4
    push 1
    call exit
