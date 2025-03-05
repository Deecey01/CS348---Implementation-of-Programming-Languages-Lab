section .data
    prompt_n db "Enter the number of elements (n): "
    prompt_n_len equ $ - prompt_n
    prompt_k db "Enter the value of k: "
    prompt_k_len equ $ - prompt_k
    prompt_num db "Enter number: "
    prompt_num_len equ $ - prompt_num
    result_msg db "The kth largest number is: "
    result_msg_len equ $ - result_msg
    newline db 10
    dot db "."
    zero db "0"
    error_msg db "Error: k should be less than or equal to n", 10
    error_msg_len equ $ - error_msg
    ten dd 10
    hundred dd 100
    thousand dd 1000

section .bss
    array resq 100
    n resd 1
    k resd 1
    input_buffer resb 32
    number_buffer resd 1
    decimal_buffer resd 1
    temp resq 1

section .text
    global _start

_start:
    finit

    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_n
    mov edx, prompt_n_len
    int 0x80

    call read_int
    mov [n], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_k
    mov edx, prompt_k_len
    int 0x80

    call read_int
    mov [k], eax

    mov eax, [k]
    cmp eax, [n]
    jg error_exit

    xor esi, esi
input_loop:
    cmp esi, [n]
    jge input_done

    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_num
    mov edx, prompt_num_len
    int 0x80

    call read_float
    fstp qword [array + esi * 8]

    inc esi
    jmp input_loop

input_done:
    xor esi, esi
outer_loop:
    cmp esi, [n]
    jge sort_done

    mov ebx, esi
    mov edi, esi
    inc edi

inner_loop:
    cmp edi, [n]
    jge swap_max

    fld qword [array + edi * 8]
    fld qword [array + ebx * 8]
    fcomip st1
    fstp st0
    jae next_iter

    mov ebx, edi

next_iter:
    inc edi
    jmp inner_loop

swap_max:
    cmp esi, ebx
    je no_swap

    fld qword [array + esi * 8]
    fld qword [array + ebx * 8]
    fstp qword [array + esi * 8]
    fstp qword [array + ebx * 8]

no_swap:
    inc esi
    jmp outer_loop

sort_done:
    mov eax, 4
    mov ebx, 1
    mov ecx, result_msg
    mov edx, result_msg_len
    int 0x80

    mov eax, [k]
    dec eax
    fld qword [array + eax * 8]
    
    call print_float_precise

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80

error_exit:
    mov eax, 4
    mov ebx, 1
    mov ecx, error_msg
    mov edx, error_msg_len
    int 0x80
    mov eax, 1
    mov ebx, 1
    int 0x80

read_int:
    push ebx
    push ecx
    push edx
    
    mov eax, 3
    mov ebx, 0
    mov ecx, input_buffer
    mov edx, 32
    int 0x80
    
    xor eax, eax
    mov ecx, input_buffer
.convert:
    movzx edx, byte [ecx]
    cmp dl, 10
    je .done
    sub dl, '0'
    imul eax, 10
    add eax, edx
    inc ecx
    jmp .convert
.done:
    pop edx
    pop ecx
    pop ebx
    ret

read_float:
    push ebx
    push ecx
    
    mov eax, 3
    mov ebx, 0
    mov ecx, input_buffer
    mov edx, 32
    int 0x80
    
    fldz
    mov ecx, input_buffer
    
.int_part:
    movzx edx, byte [ecx]
    cmp dl, '.'
    je .dec_part
    cmp dl, 10
    je .done
    
    sub dl, '0'
    mov [number_buffer], edx
    fimul dword [ten]
    fiadd dword [number_buffer]
    inc ecx
    jmp .int_part
    
.dec_part:
    inc ecx
    fld1
    fidiv dword [ten]
    fstp qword [temp]
    
.dec_loop:
    movzx edx, byte [ecx]
    cmp dl, 10
    je .done
    
    sub dl, '0'
    mov [number_buffer], edx
    fld qword [temp]
    fild dword [number_buffer]
    fmul
    fadd
    inc ecx
    fld1
    fidiv dword [ten]
    fstp qword [temp]
    jmp .dec_loop
    
.done:
    pop ecx
    pop ebx
    ret

print_float_precise:
    fst qword [temp]
    
    fld qword [temp]
    fisttp dword [number_buffer]
    
    fld qword [temp]
    fild dword [number_buffer]
    fsub
    
    fild dword [thousand]
    fmul
    fisttp dword [decimal_buffer]
    
    mov eax, [number_buffer]
    call print_integer
    
    mov eax, 4
    mov ebx, 1
    mov ecx, dot
    mov edx, 1
    int 0x80
    
    mov eax, [decimal_buffer]
    
    test eax, eax
    jns .positive
    neg eax
.positive:
    
    cmp eax, 100
    jge .print_decimal
    push eax
    mov eax, 4
    mov ebx, 1
    mov ecx, zero
    mov edx, 1
    int 0x80
    pop eax
    
    cmp eax, 10
    jge .print_decimal
    push eax
    mov eax, 4
    mov ebx, 1
    mov ecx, zero
    mov edx, 1
    int 0x80
    pop eax
    
.print_decimal:
    call print_integer
    ret

print_integer:
    push ebx
    push ecx
    push edx
    
    mov ecx, input_buffer
    add ecx, 31
    mov byte [ecx], 0
    dec ecx
    
    test eax, eax
    jnz .convert
    mov byte [ecx], '0'
    dec ecx
    jmp .print
    
.convert:
    test eax, eax
    jz .print
    mov ebx, 10
    xor edx, edx
    div ebx
    add dl, '0'
    mov [ecx], dl
    dec ecx
    jmp .convert
    
.print:
    inc ecx
    push ecx
    
    mov edx, input_buffer
    add edx, 31
    sub edx, ecx
    
    mov eax, 4
    mov ebx, 1
    int 0x80
    
    pop ecx
    pop edx
    pop ecx
    pop ebx
    ret