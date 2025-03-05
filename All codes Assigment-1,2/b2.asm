section .data
prompt_n db "Enter number of vertices (N): ", 0
prompt_edge db "Enter edge (0/1) for vertex %d to %d: ", 0
format_in db "%d", 0
cycle_msg db "Cycle found in the graph", 10, 0
no_cycle_msg db "No cycle found in the graph", 10, 0

section .bss
n resd 1 ; Number of vertices
matrix resd 400 ; Adjacency matrix (max 20x20)
visited resd 20 ; Visited array for DFS
parent resd 20 ; Parent array for tracking path
has_cycle resd 1 ; Flag for cycle detection
from resd 1 ; Current from vertex
to1 resd 1 ; Current to vertex
temp resd 1 ; Temporary storage

section .text
extern printf
extern scanf
global main

; DFS function for cycle detection
dfs:
push ebp
mov ebp, esp
push ebx
push esi
mov ebx, [ebp + 8] ; Current vertex
mov dword [visited + ebx*4], 1 ; Mark as visited
xor ecx, ecx ; Initialize vertex counter
check_adjacent:
cmp ecx, [n]
jge dfs_done
; Check if edge exists
mov eax, ebx
imul eax, [n]
add eax, ecx
mov eax, [matrix + eax*4]
cmp eax, 0
je next_adjacent
; Skip if vertex is parent
mov edx, [parent + ebx*4]
cmp ecx, edx
je next_adjacent
; Check if adjacent vertex is visited
mov eax, [visited + ecx*4]
cmp eax, 1
jne unvisited_vertex
; Found a back edge - cycle detected
mov dword [has_cycle], 1
jmp dfs_done

unvisited_vertex:
cmp eax, 0
jne next_adjacent
; Set parent and recurse
mov [parent + ecx*4], ebx
push ecx
call dfs
pop ecx
; Check if cycle was found in recursive call
cmp dword [has_cycle], 1
je dfs_done

next_adjacent:
inc ecx
jmp check_adjacent

dfs_done:
pop esi
pop ebx
mov esp, ebp
pop ebp
ret

main:
push ebp
mov ebp, esp

; Get number of vertices
push prompt_n
call printf
add esp, 4

push n
push format_in
call scanf
add esp, 8

; Initialize variables
mov dword [from], 0
mov dword [has_cycle], 0

input_outer:
mov eax, [from]
cmp eax, [n]
jge input_done

; Start with from+1 for upper triangle
mov eax, [from]
inc eax
mov [to1], eax

input_inner:
mov eax, [to1]
cmp eax, [n]
jge next_from

; Print edge prompt
push dword [to1]
push dword [from]
push prompt_edge
call printf
add esp, 12

; Read edge value
push temp
push format_in
call scanf
add esp, 8

; Store edge in matrix (both directions)
mov ebx, [from]
imul ebx, [n]
add ebx, [to1]
mov eax, [temp]
mov [matrix + ebx*4], eax ; Store A to B

mov ebx, [to1]
imul ebx, [n]
add ebx, [from]
mov [matrix + ebx*4], eax ; Store B to A

inc dword [to1]
jmp input_inner

next_from:
inc dword [from]
jmp input_outer

input_done:
; Initialize arrays for DFS
mov ecx, 0
init_arrays:
cmp ecx, [n]
jge start_cycle_check
mov dword [visited + ecx*4], 0
mov dword [parent + ecx*4], -1
inc ecx
jmp init_arrays

start_cycle_check:
; Start DFS from each unvisited vertex
mov ecx, 0
check_vertex:
cmp ecx, [n]
jge check_result
cmp dword [visited + ecx*4], 0
jne next_vertex
mov dword [parent + ecx*4], -1
push ecx
call dfs
pop ecx
cmp dword [has_cycle], 1
je found_cycle

next_vertex:
inc ecx
jmp check_vertex

check_result:
cmp dword [has_cycle], 1
je found_cycle
push no_cycle_msg
call printf
add esp, 4
jmp exit_program

found_cycle:
push cycle_msg
call printf
add esp, 4

exit_program:
mov eax, 0
mov esp, ebp
pop ebp
ret