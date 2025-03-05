;-------------------------------------
; NAME: DIVYANSH CHANDAK (220101039)
; SET-B-Q3
; Write a program that finds non-printable characters from text file and replace those
; characters with ’*’ symbol. Also, print resultant file on the output console.
;-------------------------------------

section .data
    file_name db "input.txt", 0     ; Input file name
    buffer_size equ 1024            ; Size of the buffer
    buffer db buffer_size dup(0)    ; Buffer to store file content
    open_error db "Error: Cannot open file.", 0xA, 0
    newline db 0xA, 0
    asterisk db '*', 0

section .bss
    fd resd 1  ; File descriptor

section .text
    global _start

_start:
    ; Open the file for reading
    mov eax, 5          ; sys_open
    mov ebx, file_name  ; File name
    mov ecx, 0          ; Read-only mode
    int 0x80
    cmp eax, 0
    jl open_failed
    mov [fd], eax       ; Save file descriptor

    ; Read the file contents into buffer
    mov eax, 3          ; sys_read
    mov ebx, [fd]       ; File descriptor
    mov ecx, buffer     ; Buffer to store data
    mov edx, buffer_size
    int 0x80
    cmp eax, 0
    jle done            ; End of file or error
    mov esi, buffer     ; Pointer to buffer
    mov ecx, eax        ; Number of bytes read

replace_loop:
    cmp ecx, 0          ; Check if end of buffer
    je print_result

    mov al, byte [esi]  ; Load current character
    cmp al, 32          ; Check if printable (ASCII 32-126)
    jl replace_char
    cmp al, 126
    jg replace_char
    jmp next_char

replace_char:
    mov byte [esi], '*' ; Replace non-printable character with '*'

next_char:
    inc esi             ; Move to next character
    dec ecx
    jmp replace_loop

print_result:
    ; Print modified buffer to console
    mov eax, 4          ; sys_write
    mov ebx, 1          ; File descriptor (stdout)
    mov ecx, buffer     ; Buffer to print
    mov edx, buffer_size
    int 0x80

done:
    ; Close the file
    mov eax, 6          ; sys_close
    mov ebx, [fd]
    int 0x80

    ; Exit program
    mov eax, 1          ; sys_exit
    xor ebx, ebx
    int 0x80

open_failed:
    ; Print error message
    mov eax, 4          ; sys_write
    mov ebx, 1          ; File descriptor (stdout)
    mov ecx, open_error ; Error message
    mov edx, 25
    int 0x80
    jmp done
