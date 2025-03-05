section .data
    enterNmsg db "Enter number of rows(n) of matrix A : ",0
    enterMmsg db "Enter number of columns(m) of matrix A (number of rows for matrix B) : ",0
    enterOmsg db "Enter number of columns of matrix B : ",0
    enterAelements db "Enter elements for A (row-wise) - ",0
    enterBelements db "Enter elements for B (row-wise) - ",0
    newline db 0x0a
    spacebar db ' ',0
    finalMatrixMsg db "Matrix C (AxB) is - ",0

section .bss
    n resd 1
    m resd 1
    o resd 1
    sum resd 1
    buffer resb 1000 ; buffer for input and string printing
    matrixA resd 200
    matrixB resd 200
    matrixC resd 200 ; sorted array

section .text
    global _start

_start:
    mov eax, enterNmsg
    call print_string
    call read_number ; reading number of rows of matrix A
    mov [n], eax

    mov eax, enterMmsg
    call print_string
    call read_number ; reading number of columns of matrix A
    mov [m], eax

    mov eax, enterOmsg
    call print_string
    call read_number ; reading number of rows of columns of B
    mov [o], eax

    ; reading Input matrix A
    mov eax, enterAelements
    call print_string
    mov eax, newline
    call print_string
    mov ebx, matrixA
    mov eax, [n]
    mov edx, [m]
    call inputMatrix

    ; reading Input matrix B
    mov eax, enterBelements
    call print_string
    mov eax, newline
    call print_string
    mov ebx, matrixB
    mov eax, [m]
    mov edx, [o]
    call inputMatrix

    ; multiplication function
    call multiplyMatrix

    ; printing final matrix message
    mov eax, finalMatrixMsg
    call print_string
    mov eax, newline
    call print_string
    ; printing matrix
    call printMatrix

    ; finishing the program
    jmp exit


; ------------------------------------
; function for matrix multiplication
; ------------------------------------
multiplyMatrix:
    mov ecx, 0 ; i=0 (row number of A)

outerLoop:
    cmp ecx, [n]
    jge multiplyMatrixDone
    mov edx, 0 ; j=0 (column number of A and row number for B)

middleLoop:
    cmp edx, [o]
    jge nextRow
    mov esi, 0 ; k=0 (index for multiplication)
    mov dword [sum], 0 ; intializing sum=0

innerLoop:
    cmp esi, [m]
    jge storeSum

    ; A[i][k] = matrixA [i*m + k] element a row i and column k
    ; ecx = i , edx = j , esi = k
    mov eax, ecx ; eax = i
    imul eax, [m] ; eax = i*m
    add eax, esi ; eax = i*m + k
    mov ebx, [matrixA + eax*4]

    ; A[k][j] = matrixA [k*o + j] element a row k and column j
    ; ecx = i , edx = j , esi = k
    mov eax, esi ; eax = k
    imul eax, [o] ; eax = k*o
    add eax, edx ; eax = k*o + j
    mov eax, [matrixB + eax*4]

    imul eax, ebx ; multiplying A[i][k]+B[k][j]
    add dword [sum], eax ; sum += eax

    inc esi ; k++
    jmp innerLoop

storeSum:
    ; C[i][j] = matrixC [i*o + j]
    mov eax, ecx ; eax = i
    imul eax, [o] ; eax = i*o
    add eax, edx ; eax = i*o + j
    mov ebx, [sum] ; ebx = sum
    
    mov [matrixC + eax*4], ebx ; C[i][j] = sum
    inc edx ; j++
    jmp middleLoop

nextRow:
    inc ecx ; i++
    jmp outerLoop

multiplyMatrixDone:
    ret


; ------------------------------------
; function for printing Matrix
; ------------------------------------
printMatrix:
    mov ecx, 0 ; i=0 (row number of C)

printMatrixOuterLoop:
    cmp ecx, [n]
    jge printMatrixDone
    mov edx, 0 ; j=0 (column number of C)

printMatrixInnerLoop:
    cmp edx, [o]
    jge printNewline
    ; C[i][j] = matrixC [i*o+j]
    mov eax, ecx ; eax = i
    imul eax, [o] ; eax = i*o
    add eax, edx ; eax = i*o + j
    mov eax, [matrixC + eax*4]

    
    call print_number
    mov eax, spacebar
    call print_string

    inc edx ; j++
    jmp printMatrixInnerLoop 

printNewline:
    mov eax, newline
    call print_string
    inc ecx ; i++
    jmp printMatrixOuterLoop

printMatrixDone:
    ret

; ------------------------------------
; function for reading the 2D arrays
; ------------------------------------
inputMatrix:
    push ebp
    push esi
    push edi
    push eax ; saving number of rows
    mov ebp, esp

    mul edx ; total elements = rows * cols
    mov esi, eax ; storing total elements
    pop eax ; restoring rows

    mov edi, 0 ; element counter

inputMatrixLoop:
    cmp edi, esi
    jge inputMatrixDone
    call read_number
    mov [ebx + edi*4], eax
    inc edi
    jmp inputMatrixLoop

inputMatrixDone:
    pop edi
    pop esi
    pop ebp
    ret


; ------------------------------------
; function for reading a number
; ------------------------------------
read_number:
    push ebx
    push ecx
    push edx

    mov eax, 3
    mov ebx, 0
    mov ecx, buffer
    mov edx, 1000
    int 0x80

    mov eax, 0
    mov edx, 0
    mov ecx, buffer

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
    pop edx
    pop ecx
    pop ebx
    ret


; ------------------------------------
; function for printing a string
; ------------------------------------
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


; print number as string
print_number:
    push ebx
    push ecx
    push edx

    mov ecx, buffer
    add ecx, 1000
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

    pop edx
    pop ecx
    pop ebx
    ret

; ------------
; exit label
; ------------
exit:
    mov eax, 1
    mov ebx, 0
    int 0x80