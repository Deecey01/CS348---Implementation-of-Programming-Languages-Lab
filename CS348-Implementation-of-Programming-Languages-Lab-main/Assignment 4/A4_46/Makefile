# Makefile variables
RM = rm -f
MAIN = A4_46
CC = gcc

$(MAIN)_output.txt: a.out $(MAIN).nc
	./a.out < $(MAIN).nc > output.txt

a.out: lex.yy.o $(MAIN).tab.o $(MAIN).o
	$(CC) lex.yy.o $(MAIN).tab.o $(MAIN).o

$(MAIN).tab.c: $(MAIN).y
	bison -dty $(MAIN).y 

lex.yy.c: $(MAIN).l $(MAIN).tab.h 
	flex $(MAIN).l

$(MAIN).tab.h: $(MAIN).y
	bison -d $(MAIN).y 

$(MAIN).o:
	$(CC) -c $(MAIN).c

lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c

$(MAIN).tab.o: $(MAIN).tab.c
	$(CC) -c $(MAIN).tab.c

clean:
	$(RM) a.out lex.yy.* *.o *.tab.* *.output