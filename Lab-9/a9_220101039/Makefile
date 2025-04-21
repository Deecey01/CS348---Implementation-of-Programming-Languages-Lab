# Variables
CC = gcc
CFLAGS = -Wall -g
FLEX = flex
BISON = bison
BISON_FLAGS = -d -v

# Target executable
TARGET = microc_translator

# Object files
OBJS = translator.o lexer.o parser.o quad_array.o symbol_table.o type_check.o

# Default target
all: $(TARGET)

# Rules for building the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule for building the lexer
lexer.c: a9_220101039.l parser.h
	$(FLEX) -o lexer.c a9_220101039.l

# Rule for building the parser
parser.c parser.h: a9_220101039.y
	$(BISON) $(BISON_FLAGS) -o parser.c a9_220101039.y

# Rules for building object files
translator.o: translator.c symbol_table.h quad_array.h type_check.h
	$(CC) $(CFLAGS) -c translator.c

lexer.o: lexer.c parser.h
	$(CC) $(CFLAGS) -c lexer.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

quad_array.o: quad_array.c quad_array.h
	$(CC) $(CFLAGS) -c quad_array.c

symbol_table.o: symbol_table.c symbol_table.h
	$(CC) $(CFLAGS) -c symbol_table.c

type_check.o: type_check.c type_check.h
	$(CC) $(CFLAGS) -c type_check.c

# Test target
test: $(TARGET)
	./$(TARGET) 220101039_test.mc 220101039_quads.out

# Clean target
clean:
	rm -f $(OBJS) $(TARGET) lexer.c parser.c parser.h parser.output 220101039_quads.out *.o