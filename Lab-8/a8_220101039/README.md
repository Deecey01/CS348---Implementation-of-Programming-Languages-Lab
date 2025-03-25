#  Calculator Implementation

The implementation consists of:

1. A lexical analyzer (`220101039.l`) written using Lex
2. A parser (`220101039.y`) written using Yacc
4. A Makefile for compilation

## Files in the Project

- `220101039.l`: The Lex specification for the lexical analyzer
- `220101039.y`: The Yacc specification for the parser
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

## Running the Parser

To run the parser on the test file:

```
make test
```

Or manually:

```
./220101039
```

## Output

The parser will output will look like this:

```
Calculator Ready. Enter expressions:
expr(3+5*2-4**2/2)
5
bintodec(1101)
13
bintodec(00001111)
15
bintohex(10101001)
A9
bintohex(11110000)
F0
hextobin(1F)
11111
hextobin(A3)
10100011
hextodec(FF)
255
hextodec(2A3)
675
```

## Cleaning Up

To clean all generated files:

```
make clean
```

