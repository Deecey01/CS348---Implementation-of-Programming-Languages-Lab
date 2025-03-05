section .data
    enterSizeMsg db 'Enter the number of elements: ',0
    mergedArrayMsg db 'The final sorted array is - ',0
    firstArrrayInpMsg db 'Enter the elements of first array one after one',0
    secondArrrayInpMsg db 'Enter the elements of second array one after one',0
    newline db 10
    spacebar db ' ',0

section .bss
    n resd 1
    outputStringBuffer resb 100 ; buffer for output string printing
    sizeBuffer resb 100 ; buffer for reading n as a string
    array1 resd 200
    array2 resd 200
    array3 resd 500 ; sorted array

section .text
    global _start:

_start:
    mov eax, enterSizeMsg                         ; Load address of the prompt string
    call print_string

    call read_number
    mov [n], eax

    mov eax, firstArrrayInpMsg
    call print_string
    mov eax, newline
    call print_string

    mov ecx, 0


; reading elements of first array one by one
firstArrayInp:
    cmp ecx, [n]
    jge secondArrayInpStart
    push ecx
    call read_number
    pop ecx
    mov [array1 + ecx*4],eax
    inc ecx
    jmp firstArrayInp


; reading second array elements one by one
secondArrayInpStart:
    mov eax, secondArrrayInpMsg
    call print_string
    mov eax, newline
    call print_string

    mov ecx, 0

secondArrayInp:
    cmp ecx, [n]
    jge mergeArrays
    push ecx
    call read_number
    pop ecx
    mov [array2 + ecx*4],eax
    inc ecx
    jmp secondArrayInp

; -------------------------------------------------------------------
; Now, merging the sorted arrays into one final array called array3
; -------------------------------------------------------------------
mergeArrays:
    mov esi, 0 ; index of array1
    mov edi, 0 ; index of array2
    mov ecx, 0 ; index of array3   

; merge function
merge:
    cmp esi, [n]
    jge remainingArray2
    cmp edi, [n]
    jge remainingArray1
    
    mov eax, [array1 + esi*4]
    mov ebx, [array2 + edi*4]
    cmp eax, ebx
    jle pickFromArray1
    ; element to be picked from array 2
    mov [array3 + ecx*4], ebx
    inc edi
    inc ecx
    jmp merge

; element to be picked from array 1
pickFromArray1:
    mov [array3 + ecx*4], eax
    inc esi 
    inc ecx
    jmp merge   


; copying the remaining elements of array 1
remainingArray1:
    cmp esi, [n]
    jge printAnswer
    mov eax, [array1 + esi*4]
    mov [array3 + ecx*4], eax
    inc esi
    inc ecx
    jmp remainingArray1

; copying the remaining elements of array 1
remainingArray2:
    cmp edi, [n]
    jge printAnswer
    mov eax, [array2 + edi*4]
    mov [array3 + ecx*4], eax
    inc edi
    inc ecx
    jmp remainingArray2


; ---------------------------------
; printing final sorted array 3
; ---------------------------------
printAnswer:
    mov eax, mergedArrayMsg
    call print_string
    mov ecx, 0

; looping over the final array 3
printLoop:
    mov eax, [n]
    add eax, eax
    cmp ecx, eax
    jge exit

    mov eax, [array3 + ecx*4]
    push ecx
    call print_number
    mov eax, spacebar
    call print_string
    pop ecx
    
    inc ecx
    jmp printLoop


; -------------------------
; finishing the program
; -------------------------
exit:
    mov eax, newline
    call print_string
    mov eax, 1
    mov ebx, 0
    int 0x80

; ---------------------------
; reading n as input
; ---------------------------
read_number:
    mov eax, 3
    mov ebx, 0
    mov ecx, sizeBuffer
    mov edx, 100
    int 0x80

    mov eax, 0
    mov ebx, 0
    mov ecx, sizeBuffer

; converting n(string) to n(number)
parsing:
    mov bl, [ecx]
    cmp bl, 0x0a
    je parsingDone
    cmp bl, 32
    je parsingDone
    sub bl, '0'
    imul eax, 10
    add eax, ebx
    inc ecx
    jmp parsing

parsingDone:
    ret


; ---------------------------------
; function for printing string
; ---------------------------------
print_string:
    pusha                                   ; Save registers
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
    popa                                    ; Restore registers
    ret


; -----------------------------
; print number as string
; -----------------------------
print_number:
    mov ecx, outputStringBuffer
    add ecx, 99
    mov byte [ecx], 0 ; null terminating the string
    mov ebx, 10
    mov edi, ecx

convertToStr:
    dec ecx
    mov edx, 0
    div ebx
    add dl, '0'
    mov [ecx], dl
    test eax, eax
    jnz convertToStr

    mov edx, edi
    sub edx, ecx
    mov eax, 4
    mov ebx, 1
    int 0x80
    ret