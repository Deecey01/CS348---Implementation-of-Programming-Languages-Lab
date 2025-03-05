; File: star_pattern.asm
; Assemble with:
;   nasm -f elf32 -o 220101033_Set_A6.o 220101033_Set_A6.asm
; Link with:
;   ld -m elf_i386 -o 220101033_Set_A6 220101033_Set_A6.o
; Run with:
;   ./220101033_Set_A6

section .data
    prompt      db 'Enter number of rows: ', 0
    prompt_len  equ $ - prompt
    newline     db 10           ; ASCII for newline
    space       db ' '
    star        db '*'

section .bss
    input       resb 2          
    num         resb 1          

section .text
    global _start

_start:
    
    mov eax, 4                   
    mov ebx, 1                   
    mov ecx, prompt              
    mov edx, prompt_len          
    int 0x80                    
    
    mov eax, 3                 
    mov ebx, 0                 
    mov ecx, input             
    mov edx, 2                  
    int 0x80              

    ; ---------------------------
    ; Step 3: Convert ASCII to Integer
    ; ---------------------------
    mov al, [input]              ; Load the first byte of input (the digit)
    sub al, '0'                  ; Convert ASCII to numerical value
    mov byte [num], al            ; Store the numerical value in 'num'

    ; ---------------------------
    ; Step 4: Initialize Row Counter
    ; ---------------------------
    movzx esi, byte [num]         ; Zero-extend the byte in [num] to 32-bit ESI (row counter)

print_rows:
    cmp esi, 0                    ; Check if all rows have been printed
    je exit_program              ; If ESI == 0, exit the program

    ; ---------------------------
    ; Step 5: Calculate Number of Leading Spaces (spaces = n - esi)
    ; ---------------------------
    movzx eax, byte [num]          ; EAX = n
    sub eax, esi                   ; EAX = n - esi
    mov edi, eax                   ; EDI = number of spaces

print_spaces:
    cmp edi, 0                     ; Check if all spaces are printed
    je print_stars                 ; If EDI == 0, proceed to print stars

    ; Print space
    mov eax, 4                     ; sys_write
    mov ebx, 1                     ; File descriptor (stdout)
    mov ecx, space                 ; Address of space character
    mov edx, 1                     ; Number of bytes to write
    int 0x80                       ; Make kernel call

    dec edi                        ; Decrement space counter
    jmp print_spaces               ; Repeat until all spaces are printed

    ; ---------------------------
    ; Step 6: Calculate Number of Stars (stars = 2*esi - 1)
    ; ---------------------------
print_stars:
    mov eax, esi                   ; EAX = current row number (esi)
    shl eax, 1                     ; EAX = EAX * 2
    sub eax, 1                     ; EAX = 2*esi - 1
    mov ebp, eax                   ; EBP = number of stars

print_star_loop:
    cmp ebp, 0                     ; Check if all stars are printed
    je print_newline               ; If EBP == 0, proceed to print newline

    ; Print star
    mov eax, 4                     ; sys_write
    mov ebx, 1                     ; File descriptor (stdout)
    mov ecx, star                  ; Address of star character
    mov edx, 1                     ; Number of bytes to write
    int 0x80                       ; Make kernel call

    dec ebp                        ; Decrement star counter
    jmp print_star_loop            ; Repeat until all stars are printed

    ; ---------------------------
    ; Step 7: Print Newline and Prepare for Next Row
    ; ---------------------------
print_newline:
    mov eax, 4                     ; sys_write
    mov ebx, 1                     ; File descriptor (stdout)
    mov ecx, newline               ; Address of newline character
    mov edx, 1                     ; Number of bytes to write
    int 0x80                       ; Make kernel call

    dec esi                        ; Decrement row counter (esi = esi - 1)
    jmp print_rows                 ; Repeat for the next row

    ; ---------------------------
    ; Step 8: Exit the Program
    ; ---------------------------
exit_program:
    mov eax, 1                     ; sys_exit
    mov ebx, 0                     ; Exit status 0
    int 0x80                       ; Make kernel call
