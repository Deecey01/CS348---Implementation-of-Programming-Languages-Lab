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
- `README.md`

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
1. Each grammar reduction as it happens in a separate file named `output.txt`
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

## Note

Instead of using the "opt" term in case of optional expression in my grammar, the syntax is defined in 2 ways such that whenever the optional expression's condition is met, then only the optional term would be shown in the reduction otherwise it wont't be shown.
```
    example:
    direct_declarator:
    IDENTIFIER                                  
    | IDENTIFIER '[' INTEGER_CONSTANT ']'       
    | IDENTIFIER '(' parameter_list ')'         
    | IDENTIFIER '(' ')'                        
    ;
```
Here, "parameter-list" is an optional term but is defined in 2 ways.

The necessary changes given in the mail are also incorporated in the grammar.
```
    function_declarator:
    IDENTIFIER '(' parameter_list ')'         
    | IDENTIFIER '(' ')'                        
    ;

    function_definition:
    type_specifier function_declarator compound_statement                    
    | type_specifier function_declarator declaration_list compound_statement 
    ;

```