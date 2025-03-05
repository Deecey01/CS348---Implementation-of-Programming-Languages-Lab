;-------------------------------------
; NAME: DIVYANSH CHANDAK (220101039)
;-------------------------------------

; How to run? 
; Run the following commands:
; nasm -f elf32 220101039.asm -o 220101039.o && gcc -no-pie -m32 220101039.o -o 220101039
; ./220101039

section .data
    prompt_msg db "Enter 0 to quit, 1 for read, 2 for write: ", 0
    read_addr_msg db "Enter address to read: ", 0
    write_addr_msg db "Enter address to write: ", 0
    write_val_msg db "Enter value to write: ", 0
    hit_msg db "Cache Hit!", 10, 0
    miss_msg db "Cache Miss!", 10, 0
    cache_header db "Current Cache Contents:", 10, "Set Block Valid Tag Value", 10, 0
    cache_fmt db "%-3d %-5d %-5d %-3d %-5d", 10, 0
    fmt_in db "%d", 0
    fmt_out db "%d", 10, 0
    fmt_str db "%s", 0

section .bss
    choice resd 1
    address resd 1
    value resd 1
    cache_tags resd 8     ; 4 sets * 2 blocks * 4 bytes
    cache_values resd 8   ; 4 sets * 2 blocks * 4 bytes
    cache_valid resb 8    ; 4 sets * 2 blocks * 1 byte
    fifo_bits resb 4      ; 4 sets * 1 byte

section .text
    global main
    extern printf
    extern scanf

main:
    push ebp
    mov ebp, esp

main_loop:
    ; Print prompt
    push prompt_msg
    push fmt_str
    call printf
    add esp, 8

    ; Read choice
    push choice
    push fmt_in
    call scanf
    add esp, 8

    ; Check if exit
    mov eax, [choice]
    cmp eax, 0
    je exit

    ; Check if read or write
    cmp eax, 1
    je read_op
    cmp eax, 2
    je write_op
    jmp main_loop

read_op:
    ; Get address to read
    push read_addr_msg
    push fmt_str
    call printf
    add esp, 8

    push address
    push fmt_in
    call scanf
    add esp, 8

    ; Calculate set index (address % 4)
    mov eax, [address]
    xor edx, edx
    mov ecx, 4
    div ecx
    mov ebx, edx        ; ebx = set index

    ; Check both blocks in the set
    mov esi, ebx
    shl esi, 1         ; esi = set_index * 2 (first block in set)
    
    ; Check first block
    mov eax, [cache_tags + esi*4]
    cmp byte [cache_valid + esi], 1
    jne check_second_block
    cmp eax, [address]
    je cache_hit

check_second_block:
    inc esi            ; Second block in set
    mov eax, [cache_tags + esi*4]
    cmp byte [cache_valid + esi], 1
    jne cache_miss
    cmp eax, [address]
    je cache_hit

cache_miss:
    ; Print miss message
    push miss_msg
    push fmt_str
    call printf
    add esp, 8
    call display_cache
    jmp main_loop

cache_hit:
    ; Print hit message and value
    push hit_msg
    push fmt_str
    call printf
    add esp, 8

    mov eax, [cache_values + esi*4]
    push eax
    push fmt_out
    call printf
    add esp, 8
    call display_cache
    jmp main_loop

write_op:
    ; Get address to write
    push write_addr_msg
    push fmt_str
    call printf
    add esp, 8

    push address
    push fmt_in
    call scanf
    add esp, 8

    ; Get value to write
    push write_val_msg
    push fmt_str
    call printf
    add esp, 8

    push value
    push fmt_in
    call scanf
    add esp, 8

    ; Calculate set index
    mov eax, [address]
    xor edx, edx
    mov ecx, 4
    div ecx
    mov ebx, edx        ; ebx = set index

    ; Check both blocks in set
    mov esi, ebx
    shl esi, 1         ; esi = set_index * 2

    ; Check first block
    mov eax, [cache_tags + esi*4]
    cmp byte [cache_valid + esi], 1
    jne write_to_cache
    cmp eax, [address]
    je update_cache

    ; Check second block
    inc esi
    mov eax, [cache_tags + esi*4]
    cmp byte [cache_valid + esi], 1
    jne write_to_cache
    cmp eax, [address]
    je update_cache

    ; Miss - need to evict
    mov esi, ebx
    shl esi, 1         ; Back to first block of set
    movzx eax, byte [fifo_bits + ebx]
    add esi, eax
    xor byte [fifo_bits + ebx], 1    ; Toggle FIFO bit

write_to_cache:
    mov eax, [address]
    mov [cache_tags + esi*4], eax
    mov eax, [value]
    mov [cache_values + esi*4], eax
    mov byte [cache_valid + esi], 1
    push miss_msg
    push fmt_str
    call printf
    add esp, 8
    call display_cache
    jmp main_loop

update_cache:
    mov eax, [value]
    mov [cache_values + esi*4], eax
    push hit_msg
    push fmt_str
    call printf
    add esp, 8
    call display_cache
    jmp main_loop

; Function to display cache contents
display_cache:
    push ebp
    mov ebp, esp
    push esi
    push ebx

    ; Print header
    push cache_header
    push fmt_str
    call printf
    add esp, 8

    ; Loop through all cache entries
    xor ebx, ebx        ; set counter
    xor esi, esi        ; block counter

display_loop:
    cmp esi, 8          ; Check if we've displayed all blocks
    je display_done

    ; Calculate set number (esi / 2)
    mov eax, esi
    xor edx, edx
    mov ecx, 2
    div ecx             ; eax = set number, edx = block within set

    ; Push parameters for printf (in reverse order)
    mov ecx, [cache_values + esi*4]
    push ecx                        ; value
    mov ecx, [cache_tags + esi*4]
    push ecx                        ; tag
    movzx ecx, byte [cache_valid + esi]
    push ecx                        ; valid bit
    mov ecx, edx
    push ecx                        ; block number
    push eax                        ; set number
    push cache_fmt
    call printf
    add esp, 24

    inc esi
    jmp display_loop

display_done:
    pop ebx
    pop esi
    mov esp, ebp
    pop ebp
    ret

exit:
    mov esp, ebp
    pop ebp
    ret