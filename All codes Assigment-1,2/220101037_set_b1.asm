section .data
    matrix db 1, 1, 0, 0
            db 1, 1, 1, 0
            db 0, 1, 1, 1
            db 0, 0, 1, 1
    visited db 0, 0, 0, 0
    n equ 4  ; number of vertices

    msg_connected db 'Graph is connected', 0xA
    msg_not_connected db 'Graph is not connected', 0xA
    len_connected equ $-msg_connected
    len_not_connected equ $-msg_not_connected

section .text
    global _start

_start:
    mov ecx, 0              ; Start DFS from vertex 0
    call dfs

    ; Check if all vertices are visited
    mov ecx, 0
check_visited:
    cmp byte [visited + ecx], 0  ; If any vertex is not visited
    je not_connected
    inc ecx
    cmp ecx, n
    jne check_visited

    ; If all vertices are visited, the graph is connected
connected:
    mov eax, 4              ; sys_write
    mov ebx, 1              ; file descriptor 1 (stdout)
    mov ecx, msg_connected
    mov edx, len_connected
    int 0x80
    jmp exit

not_connected:
    mov eax, 4              ; sys_write
    mov ebx, 1              ; file descriptor 1 (stdout)
    mov ecx, msg_not_connected
    mov edx, len_not_connected
    int 0x80

exit:
    mov eax, 1              ; sys_exit
    xor ebx, ebx
    int 0x80

dfs:
    push ebp
    mov ebp, esp
    push ecx                ; Save registers that will be used
    push ebx

    mov eax, [ebp+8]        ; Load the current vertex
    mov byte [visited + eax], 1

    mov ecx, 0
dfs_loop:
    cmp ecx, n
    je dfs_end

    ; Check if there is an edge and the vertex is not visited
    mov eax, [ebp+8]
    mov ebx, [matrix + eax*n + ecx]
    cmp ebx, 1
    jne dfs_next
    cmp byte [visited + ecx], 1
    je dfs_next

    ; Visit the next vertex
    push ecx
    call dfs
    add esp, 4

dfs_next:
    inc ecx
    jmp dfs_loop

dfs_end:
    pop ebx                 ; Restore registers
    pop ecx
    pop ebp
    ret
