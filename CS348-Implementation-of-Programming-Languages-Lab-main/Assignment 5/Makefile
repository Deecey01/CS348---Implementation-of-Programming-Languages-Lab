MAKEFLAGS += -s
# Makefile variables
RM = rm -f
MAIN = A5_46
CC = g++
TESTS = 1
.PHONY: run

run: a.out 
	$(foreach test,$(TESTS), \
	./a.out < $(MAIN)_test$(test).mc > $(MAIN)_quads$(test).out; \
	echo Test case $(test) completed; \
	echo The Quad Array and Symbol Table are present in $(MAIN)_quads$(test).out; \
	)

a.out: lex.yy.o $(MAIN).tab.o $(MAIN)_translator.o
	echo Creating a.out from lex.yy.o $(MAIN).tab.o $(MAIN)_translator.o
	$(CC) lex.yy.o $(MAIN).tab.o $(MAIN)_translator.o

$(MAIN).tab.c: $(MAIN).y
	bison -dty $(MAIN).y 

lex.yy.c: $(MAIN).l $(MAIN).tab.h 
	flex $(MAIN).l

$(MAIN).tab.h: $(MAIN).y
	bison -d $(MAIN).y 

$(MAIN)_translator.o:
	echo Creating $(MAIN)_translator.o
	$(CC) -c $(MAIN)_translator.cpp

lex.yy.o: lex.yy.c
	echo Creating lex.yy.o
	$(CC) -c lex.yy.c

$(MAIN).tab.o: $(MAIN).tab.c
	echo Creating $(MAIN).tab.o
	$(CC) -c $(MAIN).tab.c

clean:
	$(RM) a.out lex.yy.* *.o *.tab.* *.out *.output
