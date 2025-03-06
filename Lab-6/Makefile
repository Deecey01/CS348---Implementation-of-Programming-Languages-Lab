# Makefile for Micro C Lexer
# Replace ROLL with your roll number

CC = gcc
FLEX = flex
CFLAGS = -Wall

# Iterative Lexer
it_lexer: a6it$(ROLL).l
	$(FLEX) a6it$(ROLL).l
	$(CC) $(CFLAGS) lex.yy.c -o a6it$(ROLL)

# Non-Iterative Lexer
nit_lexer: a6nit$(ROLL).l
	$(FLEX) a6nit$(ROLL).l
	$(CC) $(CFLAGS) lex.yy.c -o a6nit$(ROLL)

# All targets
all: it_lexer nit_lexer

# Clean up
clean:
	rm -f lex.yy.c a6it$(ROLL) a6nit$(ROLL) a6it_tokens.txt a6it_symbol_table.txt a6nit_tokens.txt a6nit_symbol_table.txt

.PHONY: all clean