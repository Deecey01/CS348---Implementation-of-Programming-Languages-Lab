output.txt: a.out code.nc
	./a.out < code.nc > output.txt

a.out:	lex.yy.c
		cc lex.yy.c -lfl

lex.yy.c: code.l 
		flex code.l code.c



clean:
		rm a.out lex.yy.c output.txt