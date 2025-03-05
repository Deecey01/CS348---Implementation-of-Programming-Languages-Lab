section .data
    format_input db "%d", 0       
    format_output db "GCD is: %d", 10, 0
    msg1 db "Enter first number: ", 0
    msg2 db "Enter second number: ", 0

section .bss
    num1 resd 1
    num2 resd 1         

section .text
    global main
    extern printf, scanf  

main:
    
    push msg1          
    call printf          
    add esp, 4          

    
    push num1            
    push format_input   
    call scanf
    add esp, 8          

    
    push msg2          
    call printf          
    add esp, 4           

    
    push num2            
    push format_input   
    call scanf
    add esp, 8           

    ; Calculate GCD
    mov eax, [num1]      
    mov ebx, [num2]      
    call gcd             

    ; Print the result
    push eax             
    push format_output   
    call printf           
    add esp, 8           

    ; Exit the program
    mov eax, 0           ; Return 0 (success)
    ret

gcd:
    test ebx, ebx        
    jz .done             ; If b == 0, return a

    xor edx, edx         ; Clear edx for division
    div ebx             
    mov eax, ebx         
    mov ebx, edx         ; Move remainder to ebx
    call gcd             

.done:
    ret
