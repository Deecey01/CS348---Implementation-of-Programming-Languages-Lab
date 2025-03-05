Name     :- Divyansh Chandak
Roll No. :- 220101039

1) Set A: Q4
 Design a calculator to perform various operations of floating point numbers.
 Your design should follow the following convention:
 1. Addition
 2. Subtraction
 3. Multiplication
 4. Division
-------------------------------------

 How to run? 
 Run the following commands:
 nasm -f elf32 220101039_Set_A4.asm -o 220101039_Set_A4.o
 gcc -no-pie -m32 220101039_Set_A4.o -o 220101039_Set_A4
 ./220101039_Set_A4 

2) Set B: Q5
 Write a program to multiply the given two matrices (N*M, M*N) and print the resultant matrix.
 All inputs must be taken from the user.(The value of input N and M should be less than 10)
-------------------------------------

 How to run? 
 Run the following commands:
 nasm -f elf32 220101039_Set_B5.asm -o 220101039_Set_B5.o
 ld -m elf_i386 220101039_Set_B5.o -o 220101039_Set_B5
 ./220101039_Set_B5