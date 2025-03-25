CC = gcc
YACC = yacc
LEX = flex

all: 220101039

220101039: 220101039.tab.c lex.yy.c
	$(CC) -o 220101039 y.tab.c lex.yy.c -lfl -lm

220101039.tab.c 220101039.tab.h: 220101039.y
	$(YACC) -d 220101039.y

lex.yy.c: 220101039.l y.tab.h
	$(LEX) 220101039.l

test: 220101039
	./220101039

clean:
	rm -f 220101039 y.tab.c y.tab.h lex.yy.c
