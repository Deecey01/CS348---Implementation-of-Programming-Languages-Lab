# Micro C Lexer Assignment

## Files
- `a6it_220101039.l`: Iterative lexer specification
- `a6nit_220101039.l`: Non-iterative lexer specification
- `Makefile`: Compilation instructions
- `a6_220101039_test.mc`: Test input file

## Building the Lexer
1. Run `make all` to build both iterative and non-iterative lexers

## Running the Lexer
- Iterative lexer: `./a6it_220101039 < a6_220101039_test.mc`
- Non-iterative lexer: `./a6nit_220101039 < a6_220101039_test.mc`

## Notes
- The lexer follows the micro C lexical specification
- Handles keywords, identifiers, constants, string literals, punctuators
- Supports multi-line and single-line comments
- Generates a symbol table with token details