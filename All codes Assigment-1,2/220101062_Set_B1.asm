section .data
graph: dd 0,1,0,1
      dd 1,0,1,0
      dd 0,1,0,0
      dd 1,0,0,0
size: dd 4

msg_connected: db "Graph is connected", 10, 0
len_connected: equ $ - msg_connected
msg_not_connected: db "Graph is not connected", 10, 0
len_not_connected: equ $ - msg_not_connected

section .bss
visited: resb 100
stack: resd 100
stack_top: resd 1

section .text
global _start

_start:
mov ecx, [size]
mov edi, visited
xor eax, eax
rep stosb

mov dword [stack_top], 0

mov byte [visited], 1
push 0
inc dword [stack_top]

dfs_loop:
cmp dword [stack_top], 0
je check_connectivity

dec dword [stack_top]
mov edx, [stack_top]
mov ebx, [stack + 4*edx]

xor ecx, ecx

check_adjacent:
cmp ecx, [size]
je dfs_loop

mov eax, ebx
mov edx, [size]
mul edx
add eax, ecx
mov edx, eax
shl edx, 2

cmp dword [graph + edx], 0
je next_adjacent

cmp byte [visited + ecx], 0
jne next_adjacent

mov byte [visited + ecx], 1
mov eax, [stack_top]
mov [stack + 4*eax], ecx
inc dword [stack_top]

next_adjacent:
inc ecx
jmp check_adjacent

check_connectivity:
xor ecx, ecx
mov esi, visited

check_visited:
cmp ecx, [size]
je is_connected

cmp byte [esi + ecx], 0
je not_connected

inc ecx
jmp check_visited

is_connected:
mov eax, 4
mov ebx, 1
mov ecx, msg_connected
mov edx, len_connected
int 0x80
jmp exit

not_connected:
mov eax, 4
mov ebx, 1
mov ecx, msg_not_connected
mov edx, len_not_connected
int 0x80

exit:
mov eax, 1
xor ebx, ebx
int 0x80
