# Makefile for Micro C Lexer
# Replace ROLL with your roll number

CC = gcc
FLEX = flex
CFLAGS = -lfl
ROLL = 220101039

# Iterative Lexer
it_lexer: a6it_$(ROLL).l
	$(FLEX) a6it_$(ROLL).l
	$(CC) $(CFLAGS) lex.yy.c -o a6it_$(ROLL)

# Non-Iterative Lexer
nit_lexer: a6nit_$(ROLL).l
	$(FLEX) a6nit_$(ROLL).l
	$(CC) $(CFLAGS) lex.yy.c -o a6nit_$(ROLL)

# All targets
all: it_lexer nit_lexer

# Clean up
clean:
	rm -f lex.yy.c a6it_$(ROLL) a6nit_$(ROLL) a6it_tokens.txt a6it_symbol_table.txt a6nit_tokens.txt a6nit_symbol_table.txt

.PHONY: all clean