# micro C Compiler Implementation

This is an implementation of a parser for the micro C language as specified in the assignment. The implementation consists of:

1. A lexical analyzer (`a7_220101039.l`) written using Lex
2. A parser (`a7_220101039.y`) written using Yacc
3. A test file (`a7_220101039_test.mc`) that tests all the lexical rules
4. A Makefile for compilation

## Files in the Project

- `a7_220101039.l`: The Lex specification for the lexical analyzer
- `a7_220101039.y`: The Yacc specification for the parser
- `a7_220101039_test.mc`: A test file containing micro C code
- `Makefile`: File to automate the build process

## Building the Project

To build the project, simply run:

```
make
```

This will:
1. Generate the parser files using Yacc
2. Generate the lexer files using Lex
3. Compile all files and create the executable `microc`

## Running the Parser

To run the parser on the test file:

```
make test
```

Or manually:

```
./microc a7_220101039_test.mc
```

## Output

The parser will output:
1. Each grammar reduction as it happens
2. A symbol table at the end of parsing
3. Success or failure message

## Cleaning Up

To clean all generated files:

```
make clean
```


## Note on Symbol Table

The symbol table implementation is simple, storing identifiers and their token types. A more advanced implementation could include scoping information, data types, etc.

## Features

The parser implements all the features required in the assignment:
- All lexical rules for micro C
- Grammar rules as specified
- Symbol table generation
- Printing of grammar reductions