# Assignment 6 - IPLL Lab

## Group 46
- Gunjan Dhanuka: 200101038
- Pranjal Singh: 200101084

In this assignment, we have implemented a target code translator from the TAC quad array (with the supporting symbol table, and other auxiliary data structures) to the assembly language of x86 / IA-32 / x86-64. The translation is now machine-specific and your generated assembly code would be translated with the gcc assembler to produce the final executable codes for the nanoC program.

The following things have been handled:-

- Activation Records
- Static memory and binding
- Handling of Prologue
- Handling of Epilogue
- Handling of Function Body
- Integration of Translated Codes into an Assembly file
- 12 test cases covering various scenarios have been provided

## Files
1. `A6_46.l` -- Flex Specification
2. `A6_46.y` -- Bison Specification
3. `A6_46_translator.h` -- Data Structures Definitions & Global Function Prototypes 
4. `A6_46_translator.c` -- Data Structures, Function Implementations & Translator main()
5. `inputs/` -- contains the test files
6. `quads/` -- contains the generated quad files (after `make run`)
7. `outputs/` -- contains the generated object files (after `make run`)
8. `exec/` -- contains the generated executables for the test cases.
9. `assembly/` -- contains the generated assembly files

## Setup instructions
1. In the current directory, enter `make` in the terminal.
2. To run the testcases, enter `make run` in the termninal.
3. You can then execute the test cases by entering appropriate executable's name in the terminal. Eg: `./exec/A6_46_test1`.
4. To clean up the generated files, enter `make clean`.