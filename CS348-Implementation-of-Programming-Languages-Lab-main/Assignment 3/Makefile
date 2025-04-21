CC = gcc
LEX = lex
RM = rm -f

TARGET_LEX = A3_46.l
LEX_C = lex.yy.c
MAIN = A3_46.c

EXEC = a.out
TEST = A3_46.nc
OUTPUT = output.txt

$(EXEC): $(LEX_C)
	$(CC) $(LEX_C) $(MAIN)

$(LEX_C): $(TARGET_LEX)
	$(LEX) $(TARGET_LEX)

clean:
	$(RM) $(LEX_C) $(EXEC) $(OUTPUT)

run: $(EXEC)
	./$(EXEC) $(TEST) && ./$(EXEC) $(TEST) > $(OUTPUT)