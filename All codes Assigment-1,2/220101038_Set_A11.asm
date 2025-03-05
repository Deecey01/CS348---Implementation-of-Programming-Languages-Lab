section .data
    prompt db "Enter a string : ", 0         ; Prompt message to ask user for input
    quotes db 34
    spacebar db 32
    newline db 0x0a                        ; Newline character for output formatting
    result_msg db "Character counts : ", 10
    result_len equ $ - result_msg
    tempBuffer times 10 db 0

section .bss
    count resd 256
    buffer resb 1000

section .text
    global _start

_start:
    ; Step 1: Print the prompt message
    mov eax, prompt
    call print_string

    ; Step 2: Read input string from user
    mov eax, 3
    mov ebx, 0
    mov ecx, buffer
    mov edx, 1000
    int 0x80

    ; Store length of input in esi
    mov esi, eax

    mov ecx, 256 ; loop counter
    mov edi, count
    mov al, 0
    rep stosd     ; Repeat stosb ecx times

    ; Count characters
    mov ecx, esi                  ; Length of input
    mov esi, buffer               ; Source string

countLoop:
    mov al, byte [esi]           ; current character
    inc dword [count + 4*eax]      ; Increment count for this character
    inc esi                      ; next character
    loop countLoop              ; Decrease ecx and continue if not zero

    mov eax, result_msg
    call print_string

    mov ebx, 0 ; ascii 0

printLoop:
    mov eax, dword [count + 4*ebx]
    test al, al
    jz next

    push ebx
    mov [buffer], bl

    mov eax, 4                   ; sys_write
    mov ebx, 1                   ; stdout
    mov ecx, quotes
    mov edx, 1
    int 0x80

    mov eax, 4                   ; sys_write
    mov ebx, 1                   ; stdout
    mov ecx, buffer
    mov edx, 1
    int 0x80


    mov eax, 4                   ; sys_write
    mov ebx, 1                   ; stdout
    mov ecx, quotes
    mov edx, 1
    int 0x80

    mov byte [buffer], ':'
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, 1
    int 0x80

    mov byte [buffer], ' '
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer
    mov edx, 1
    int 0x80
    pop ebx

    mov eax, dword [count + 4*ebx]
    mov edi, tempBuffer + 9
    mov byte [edi], 0           ; Null terminator
    dec edi
    mov byte [edi], 10          ; Newline
    dec edi
    mov ecx, 10                 ; Divisor

    push ebx

numToStr:
    mov edx, 0
    div ecx
    add dl, '0'
    mov [edi], dl
    dec edi
    test eax, eax
    jnz numToStr

    ; Print number
    inc edi
    mov ecx, edi
    mov edx, tempBuffer + 10
    sub edx, edi
    mov eax, 4
    mov ebx, 1
    int 0x80

    pop ebx

next:
    inc ebx                    ;  next character
    cmp ebx, 256              ; Check if we've done all characters
    je exit
    jmp printLoop 


; -------------------------
; exit program
; -------------------------
exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80

; ---------------------------------
; function for printing string
; ---------------------------------
print_string:                                   ; Save registers
    mov edx, 0                              ; Reset string length
    mov ecx, eax                            ; Address of string

count_len:
    cmp byte [ecx + edx], 0                 ; Check for null terminator
    je write_string                         ; If null terminator, calculate length
    inc edx                                 ; Increment length
    jmp count_len

write_string:
    mov eax, 4                              ; syscall: sys_write
    mov ebx, 1                              ; file descriptor: stdout
    int 0x80                                ; Trigger system call
    ret