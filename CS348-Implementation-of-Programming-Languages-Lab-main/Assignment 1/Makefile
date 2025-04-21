MAKEFLAGS += -s
TARGET = A1B_200101038
.PHONY: default


default: run clean

debug: $(TARGET)
	gdb $(TARGET)

run: $(TARGET)
	./$(TARGET)
	

$(TARGET): $(TARGET).o
	gcc -no-pie -g -o  $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).asm
	nasm $(TARGET).asm -f elf64 -o $(TARGET).o

clean: 
	rm $(TARGET) $(TARGET).o