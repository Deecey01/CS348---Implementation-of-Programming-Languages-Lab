MAKEFLAGS += -s
MAIN := A6_46
INPUT_DIR:= input
OUTPUT_DIR:= output
QUAD_DIR := quads
ASSEMBLY_DIR := assembly
EXEC_DIR := exec
TESTS = 1 2 3 4 5 6 7 8 9 10 11 12

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black:='\033[0;30m'        # Black
Red:='\033[0;31m'          # Red
Green:='\033[0;32m'        # Green
Yellow:='\033[0;33m'       # Yellow
Blue:='\033[0;34m'         # Blue
Purple:='\033[0;35m'       # Purple
Cyan:='\033[0;36m'         # Cyan
White:='\033[0;37m'        # White

.PHONY: test
# TEST_CASES := $(wildcard $(INPUT_DIR)/*.nc)

nanoC: y.tab.o lex.yy.o $(MAIN)_translator.o $(MAIN)_converter.o 
	@g++ -no-pie -g $(MAIN)_translator.o $(MAIN)_converter.o lex.yy.o y.tab.o -lfl -o nanoC

lex.yy.c: $(MAIN).l
	@flex $(MAIN).l

y.tab.c: $(MAIN).y
	@yacc -dtv $(MAIN).y

$(MAIN)_converter.o: $(MAIN)_converter.cpp
	@g++ -no-pie -g -c $(MAIN)_converter.cpp

$(MAIN)_translator.o: $(MAIN)_translator.cpp
	@g++ -no-pie -g -c $(MAIN)_translator.cpp

lex.yy.o: lex.yy.c
	@g++ -no-pie -g -c lex.yy.c

y.tab.o:    y.tab.c
	@g++ -no-pie -g -DYYDEBUG -c y.tab.c

libmyl.a: myl.o
	cc    -c -o myl.o myl.c
	@ar -rcs libmyl.a myl.o


clean:
	@rm -f *.s  lex.yy.c y.tab.h y.output y.tab.c  *.o libmyl.a  *.out nanoC
	rm -rf $(QUAD_DIR) $(OUTPUT_DIR) $(ASSEMBLY_DIR) $(EXEC_DIR)

# $(foreach test_case,$(TESTS),\
# 		echo ${Blue}::Starting Test Case $(MAIN)_test$(test_case).nc::; \
#         ./nanoC < $(test_case) > $(QUAD_DIR)/($(MAIN)_quad$(test_case)).out; \
# 		echo ${Yellow}::Quad file ${White}$(QUAD_DIR)/($(MAIN)_quad$(test_case)).out ${Yellow}made::; \
#         mv output.s ./$(ASSEMBLY_DIR)/($(MAIN)_test$(test_case)).s; \
# 		echo ${Yellow}::Assembly file ${White}$(ASSEMBLY_DIR)/($(MAIN)_test$(test_case)).s ${Yellow}made::; \
# 		echo ${Yellow}::Compiling .o file ${White}($(MAIN)_test$(test_case).o)${Yellow}::; \
# 		gcc -no-pie -g -Wall -c ./$(ASSEMBLY_DIR)/($(MAIN)_test$(test_case)).s -o ./$(OUTPUT_DIR)/($(MAIN)_test$(test_case).o); \
# 		gcc -no-pie -g  ./$(OUTPUT_DIR)/($(MAIN)_test$(test_case).o) -o $$($(MAIN)_test$(test_case) .nc) -L. -lmyl; \
# 		echo ${Yellow}::Executable file for ${White}$(MAIN)_test$(test_case)${Yellow}made at ${White}./$(MAIN)_test$(test_case)${Yellow}::; \
# 		echo ${Color_Off}; \
#     )
run:  nanoC libmyl.a
	echo -e ${Green} ::Running Test Cases:: ${Color_Off}
	echo
	echo
	mkdir -p $(QUAD_DIR)
	mkdir -p $(ASSEMBLY_DIR)
	mkdir -p $(OUTPUT_DIR)
	mkdir -p $(EXEC_DIR)

	$(foreach test_case,$(TESTS),\
		echo ${Blue}::Starting Test Case $(test_case)::; \
        ./nanoC < $(INPUT_DIR)/$(MAIN)_test$(test_case).nc > $(QUAD_DIR)/$(MAIN)_quads$(test_case).out; \
        mv output.s ./$(ASSEMBLY_DIR)/$(MAIN)_quads$(test_case).s; \
		echo ${Yellow}Assembly File ./$(ASSEMBLY_DIR)/$(MAIN)_quads$(test_case).s made; \
		echo ${Yellow}Compiling .o File $$(basename $(test_case) .nc).o; \
		gcc -no-pie -g -Wall -c ./$(ASSEMBLY_DIR)/$(MAIN)_quads$(test_case).s -o ./$(OUTPUT_DIR)/$(MAIN)_quads$(test_case).o; \
		gcc -no-pie -g  ./$(OUTPUT_DIR)/$(MAIN)_quads$(test_case).o -o ./$(EXEC_DIR)/$(MAIN)_exec$(test_case) -L. -lmyl; \
		echo ${Yellow}Executable File for Test case $(test_case) made. To run, use command ./$(EXEC_DIR)/$(MAIN)_exec$(test_case); \
		echo ${Color_Off}; \
    )
	
