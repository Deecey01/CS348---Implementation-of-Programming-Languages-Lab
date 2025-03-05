section .data
    prompt_size db "Enter number of vertices (n): ", 0
    prompt_size_len equ $ - prompt_size
    prompt_elem db "Is there an edge from vertex ", 0
    prompt_elem_len equ $ - prompt_elem
    to_msg db " to vertex ", 0
    to_msg_len equ $ - to_msg
    question_mark db "? (1/0): ", 0
    question_len equ $ - question_mark
    connected_msg db "Graph is connected", 10, 0
    connected_len equ $ - connected_msg
    not_connected_msg db "Graph is not connected", 10, 0
    not_connected_len equ $ - not_connected_msg

section .bss
    n resd 1                  ; Number of vertices
    matrix resb 100          ; Max 10x10 matrix (100 bytes)
    visited resb 10          ; Visited array for DFS
    buffer resb 256         ; Input buffer
    num_str resb 8          ; Buffer for number conversion

section .text
    global _start

_start:
    ; Print prompt for size
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_size
    mov edx, prompt_size_len
    int 0x80

    ; Read n
    call read_num
    mov [n], eax

    ; Read matrix elements
    xor esi, esi        ; row counter
read_matrix_rows:
    xor edi, edi        ; column counter
read_matrix_cols:
    ; Print "Is there an edge from vertex "
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_elem
    mov edx, prompt_elem_len
    int 0x80

    ; Print row number (esi)
    mov eax, esi
    inc eax             ; Add 1 for 1-based indexing
    call print_num

    ; Print " to vertex "
    mov eax, 4
    mov ebx, 1
    mov ecx, to_msg
    mov edx, to_msg_len
    int 0x80

    ; Print column number (edi)
    mov eax, edi
    inc eax             ; Add 1 for 1-based indexing
    call print_num

    ; Print "? (1/0): "
    mov eax, 4
    mov ebx, 1
    mov ecx, question_mark
    mov edx, question_len
    int 0x80

    ; Read element
    call read_num
    
    ; Calculate position in matrix and store
    push eax            ; Save the input value
    mov eax, esi
    mul dword [n]       ; multiply by n
    add eax, edi        ; add column number
    mov ebx, eax        ; Position in matrix
    pop eax             ; Restore input value
    mov byte [matrix + ebx], al

    ; Move to next column
    inc edi
    mov eax, [n]
    cmp edi, eax
    jl read_matrix_cols

    ; Move to next row
    inc esi
    mov eax, [n]
    cmp esi, eax
    jl read_matrix_rows

    ; Initialize visited array to 0
    mov ecx, 0
    mov al, 0
init_visited:
    mov [visited + ecx], al
    inc ecx
    cmp ecx, [n]
    jl init_visited

    ; Start DFS from vertex 0
    mov byte [visited], 1    ; Mark first vertex as visited
    mov ebx, 0              ; Start vertex
    call dfs

    ; Check if all vertices are visited
    mov ecx, 0
check_connected:
    mov al, byte [visited + ecx]
    test al, al
    jz not_connected
    inc ecx
    cmp ecx, [n]
    jl check_connected

    ; Print connected message
    mov eax, 4
    mov ebx, 1
    mov ecx, connected_msg
    mov edx, connected_len
    int 0x80
    jmp exit

not_connected:
    ; Print not connected message
    mov eax, 4
    mov ebx, 1
    mov ecx, not_connected_msg
    mov edx, not_connected_len
    int 0x80

exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80

; DFS implementation
dfs:
    push ebx
    push ecx

    mov ecx, 0              ; Loop through all vertices
dfs_loop:
    cmp ecx, [n]
    jge dfs_done

    ; Check if there's an edge and vertex is not visited
    push ecx
    call get_matrix_element
    pop ecx
    test al, al
    jz next_vertex

    mov al, byte [visited + ecx]
    test al, al
    jnz next_vertex

    ; Mark vertex as visited and recurse
    mov byte [visited + ecx], 1
    push ebx
    push ecx
    mov ebx, ecx
    call dfs
    pop ecx
    pop ebx

next_vertex:
    inc ecx
    jmp dfs_loop

dfs_done:
    pop ecx
    pop ebx
    ret

; Get matrix element at [ebx][ecx]
get_matrix_element:
    push ebx
    mov eax, ebx
    mul dword [n]    ; eax = row * n
    add eax, ecx     ; eax = row * n + col
    movzx eax, byte [matrix + eax]
    pop ebx
    ret

; Read single number
read_num:
    push ebx
    push ecx
    push edx

    mov ecx, buffer
    mov edx, 256
    mov eax, 3       ; sys_read
    mov ebx, 0       ; stdin
    int 0x80

    mov ecx, buffer
    xor eax, eax
read_num_loop:
    movzx ebx, byte [ecx]
    cmp bl, 10       ; newline
    je read_num_done
    sub bl, '0'
    imul eax, 10
    add eax, ebx
    inc ecx
    jmp read_num_loop

read_num_done:
    pop edx
    pop ecx
    pop ebx
    ret

; Print number in eax
print_num:
    push ebx
    push ecx
    push edx
    push edi

    mov ecx, num_str
    add ecx, 7           ; Start from end of buffer
    mov byte [ecx], 0    ; Null terminate
    mov ebx, 10

convert_loop:
    dec ecx
    xor edx, edx
    div ebx
    add dl, '0'
    mov [ecx], dl
    test eax, eax
    jnz convert_loop

    ; Print the number
    mov eax, 4
    mov ebx, 1
    push ecx            ; Save start position
    mov edx, num_str
    add edx, 8
    sub edx, ecx        ; Calculate length
    int 0x80
    
    pop ecx
    pop edi
    pop edx
    pop ecx
    pop ebx
    ret