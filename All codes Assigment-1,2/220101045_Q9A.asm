section .data
    originalString db "string", 0        ; Input string (null-terminated)
    k         db 2                   ; Value of k
    buffer         db 20 dup(0)           ; Buffer for modified string
    trueMsg        db "TRUE", 10, 0       ; "TRUE" followed by newline and null terminator
    falseMsg       db "FALSE", 10, 0      ; "FALSE" followed by newline and null terminator
    newline        db 10, 0                ; Newline character with null terminator

section .bss
    strLen resd 1                         ; To store string length

section .text
    global _start

_start:
    ; Initialize pointers
    lea esi, [originalString]              ; ESI points to originalString
    lea edi, [buffer]                      ; EDI points to buffer

    ; Copy the original string to buffer
    mov ecx, 0                             ; Counter = 0

copy_loop:
    mov al, [esi + ecx]
    mov [edi + ecx], al
    cmp al, 0                              ; Check for null terminator
    je copy_done
    inc ecx
    jmp copy_loop

copy_done:
    mov [strLen], ecx                     ; Store string length

    ; Reverse the first k characters in buffer
    mov al, [k]                      ; Load k
    movzx ebx, al                          ; Zero-extend al to ebx
    cmp ebx, 0
    je skip_reverse                        ; If k=0, skip reversing
    cmp ebx, ecx
    jg adjust_k                            ; If k > string length, adjust k to string length

    jmp set_reverse_indices

adjust_k:
    mov ebx, ecx                           ; Set k to string length

set_reverse_indices:
    mov esi, 0                             ; Start index
    mov edi, ebx                           ; End index = k

    dec edi                                ; Convert to 0-based index

reverse_loop:
    cmp esi, edi
    jge reverse_done

    ; Swap buffer[esi] and buffer[edi]
    mov al, [buffer + esi]
    mov dl, [buffer + edi]
    mov [buffer + esi], dl
    mov [buffer + edi], al

    inc esi
    dec edi
    jmp reverse_loop

reverse_done:

skip_reverse:
    ; Check if all characters are alphabets
    lea esi, [buffer]                      ; ESI points to buffer
    mov ecx, 0                             ; Index = 0
    mov ebx, 1                             ; Assume TRUE

check_loop:
    mov al, [esi + ecx]
    cmp al, 0                              ; Check for null terminator
    je check_end

    ; Check if AL is between 'A' and 'Z' or 'a' and 'z'
    cmp al, 'A'
    jl not_alpha
    cmp al, 'Z'
    jle continue_check
    cmp al, 'a'
    jl not_alpha
    cmp al, 'z'
    jle continue_check
    jmp not_alpha

continue_check:
    inc ecx
    jmp check_loop

not_alpha:
    mov ebx, 0                             ; Set to FALSE
    jmp check_end

check_end:
    ; Print the modified string
    lea eax, [buffer]
    call print_string

    ; Print newline
    lea eax, [newline]
    call print_string

    ; Print TRUE or FALSE based on EBX
    cmp ebx, 1
    je print_true
    lea eax, [falseMsg]
    call print_string
    jmp program_exit

print_true:
    lea eax, [trueMsg]
    call print_string

program_exit:
    ; Exit the program
    mov eax, 1             ; sys_exit
    xor ebx, ebx           ; Exit code 0
    int 0x80

; --------------------------------------------
; Subroutine: print_string
; Input: EAX points to the null-terminated string
; Output: Writes the string to stdout
; Clobbers: ECX, EDX, ESI
; --------------------------------------------
print_string:
    push ecx               ; Save ECX
    push edx               ; Save EDX
    push esi               ; Save ESI
    push ebx               ; Save EBX

    mov esi, eax           ; ESI points to the string
    mov ecx, 0             ; Counter = 0

strlen_loop:
    cmp byte [esi + ecx], 0
    je strlen_done
    inc ecx
    jmp strlen_loop

strlen_done:
    ; sys_write(int fd, const void *buf, size_t count)
    mov edx, ecx           ; count
    mov ecx, eax           ; buf
    mov ebx, 1             ; stdout
    mov eax, 4             ; sys_write
    int 0x80

    pop ebx                ; Restore EBX
    pop esi                ; Restore ESI
    pop edx                ; Restore EDX
    pop ecx                ; Restore ECX
    ret
