# Assignment 3
## CS348 (Implementation of Programming Languages Laboratory, IIT Guwahati)
Submitted by Gunjan Dhanuka (200101038) and Pranjal Singh (200101084)

Instructions to run the code

1. To generate the output file from the C-code, type `make`
2. To run the lexical analysis and print the output, type `make run`
3. To clean up the generated files, type `make clean`

In the `Makefile`, you can also edit the following parameters according to the target system:
```
CC = gcc
LEX = lex
RM = rm -f

TARGET_LEX = A3_46.l
LEX_C = lex.yy.c
MAIN = A3_46.c

EXEC = a.out
TEST = A3_46.nc
OUTPUT = output.txt
```