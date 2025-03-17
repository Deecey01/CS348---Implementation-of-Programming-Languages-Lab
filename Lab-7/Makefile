# Makefile for microC compiler

# Variables
CC = gcc
YACC = yacc
LEX = lex
CFLAGS = -lfl

ROLL = 220101039

# Object files
OBJS = y.tab.o lex.yy.o

# Default target
all: microc

# Generate parser
y.tab.c y.tab.h: a7_$(ROLL).y
	$(YACC) -d a7_$(ROLL).y

# Generate lexer
lex.yy.c: a7_$(ROLL).l y.tab.h
	$(LEX) a7_$(ROLL).l

# Compile parser
y.tab.o: y.tab.c
	$(CC) $(CFLAGS) -c y.tab.c

# Compile lexer
lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

# Build final executable
microc: $(OBJS)
	$(CC) $(CFLAGS) -o microc $(OBJS)

# Run test
test: microc
	./microc a7_$(ROLL)_test.mc

# Clean up
clean:
	rm -f microc $(OBJS) lex.yy.c y.tab.c y.tab.h output.txt

# Create zip file for submission
zip: a7_$(ROLL).l a7_$(ROLL).y a7_$(ROLL)_test.mc Makefile README.md
	zip a7_$(ROLL).zip a7_$(ROLL).l a7_$(ROLL).y a7_$(ROLL)_test.mc Makefile README.md

.PHONY: all clean test zip