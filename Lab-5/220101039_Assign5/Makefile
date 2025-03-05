output2.txt: a.out 220101039.nc
	./a.out < 220101039.nc > output2.txt

a.out:	lex.yy.c
		cc lex.yy.c -lfl

lex.yy.c: 220101039.l 
		flex 220101039.l

clean:
		rm a.out lex.yy.c output2.txt