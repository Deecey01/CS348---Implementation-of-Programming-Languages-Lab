# Lexical Analyzer using Flex

This project implements a lexical analyzer using `flex` to tokenize a subset of a C-like language. The analyzer identifies keywords, identifiers, numeric constants, character literals, string literals, symbols, comments, and whitespace.

## Prerequisites
- `flex`
- `gcc`
- A Unix-like terminal (Linux/MacOS)

## Files
- `220101039.l` - The flex lexical analyzer definition.
- `Makefile` - Automates the build and execution process.
- `220101039.nc` - Input source code file to be tokenized.
- `output2.txt` - One which contains all the tokens generated from nanoC file
- `symbol_table.txt` - Contains the Symbol/Literal table

## Commands to Run

1. Compile and build the lexer:
   ```sh
   make
   ```

   This will process `220101039.nc` and generate `output2.txt`, `symbol_table.txt`.

2. Clean up generated files:
   ```sh
   make clean
   ```

## Output Format
The program prints recognized tokens in the format:
```
<IDENTIFIER, varName>
<KEYWORD, int>
<INTEGER_CONSTANT, 42>
<PUNCTUATOR, ;>
```

And the symbol table in the format:
```
Line		Token Type			Name
----------------------------------------
1       SINGLE_LINE_COMMENT // Find fibonacci by co-recursion
2       KEYWORD             int
2       IDENTIFIER          f_odd
2       PUNCTUATOR          (
2       KEYWORD             int
2       PUNCTUATOR          )
2       PUNCTUATOR          ;
3       KEYWORD             int
```

## Explanation
- The `validate_num` function ensures numeric constants are valid.
- Tokens are printed according to their classification.
- Comments and whitespace are handled but not tokenized.
- The `write_to_symtab` function is writing token information to a symbol table file with three columns:

```c
void write_to_symtab(int line_no, const char* token_type, const char* name) {
    fprintf(symtab_file, "%-8d%-20s%s\n", line_no, token_type, name);
}
```

This lexical analyzer can be extended for more complex C-like parsing tasks.