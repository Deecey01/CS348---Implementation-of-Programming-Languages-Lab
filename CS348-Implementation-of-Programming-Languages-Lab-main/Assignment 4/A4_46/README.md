# Assignment 4: Bison specification for the nanoC
## CS348: Implementation of Programming Languages Lab

```
Group Number : 46
Group Members: 
    Gunjan Dhanuka: 200101038
    Pranjal Singh: 200101084
```

## Files
- `A4_46.y` contains the bison specifications of nanoC.
- `A4_46.l` contains the flex specifications required to run the bison file.
- `A4_46.c` contains the main function which uses the bison/lex library.
- `A4_46.nc` contains the test file written in nanoC.
- `Makefile` contains the commands to generate the required tab files and the executable file and to run them.
The rules used to reduce the `A4_46.nc` file in order are printed in the `output.txt` file.

We have considered the following two changes from the assignment:
 - Removed '(' declaration_list_opt ')' from function function_definition
 - To allow multiple translation units, new grammar rules have been added.

## Steps to run
1. Open the folder containing the files in terminal. 
2. Enter the command `make` in the terminal.
3. The output will be saved in `output.txt` file.
4. To clean up the generated files, run `make clean` in the terminal.