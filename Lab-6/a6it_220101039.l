%{
#include <stdio.h>
#include <string.h>

// Token type definitions
#define KEYWORD 1
#define IDENTIFIER 2
#define INTEGER_CONSTANT 3
#define FLOAT_CONSTANT 4
#define CHARACTER_CONSTANT 5
#define STRING_LITERAL 6
#define PUNCTUATOR 7
#define COMMENT 8

// Symbol table structure
struct SymbolTableEntry {
    char name[50];
    int type;
    int line_number;
};

struct SymbolTableEntry symbol_table[1000];
int symbol_table_size = 0;

FILE *token_output_file;
FILE *symbol_table_file;

// Function to add entry to symbol table
void add_to_symbol_table(char* name, int type, int line_number) {
    // Check if already exists
    for (int i = 0; i < symbol_table_size; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return;
        }
    }
    
    // Add new entry
    strcpy(symbol_table[symbol_table_size].name, name);
    symbol_table[symbol_table_size].type = type;
    symbol_table[symbol_table_size].line_number = line_number;
    symbol_table_size++;
}

// Function to print symbol table
void print_symbol_table() {
    fprintf(symbol_table_file, "--- Symbol Table ---\n");
    fprintf(symbol_table_file, "%-20s%-20s%-20s\n", "Name", "Type", "Line Number");
    for (int i = 0; i < symbol_table_size; i++) {
        fprintf(symbol_table_file, "%-20s%-20d%-20d\n", 
               symbol_table[i].name, 
               symbol_table[i].type, 
               symbol_table[i].line_number);
    }
}

int line_number = 1;
%}

%option noyywrap

/* Keywords */
KEYWORD (return|void|float|integer|char|for|const|while|bool|if|do|else|begin|end)

/* Identifiers */
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

/* Integer Constants */
INTEGER_CONSTANT [1-9][0-9]*|0

/* Floating Constants */
FLOAT_CONSTANT ([0-9]*\.[0-9]+([eE][+-]?[0-9]+)?)|([0-9]+\.[0-9]*([eE][+-]?[0-9]+)?)|([0-9]+([eE][+-]?[0-9]+))

/* Character Constants */
CHARACTER_CONSTANT \'(\\.|[^\\'])+\'

/* String Literals */
STRING_LITERAL \"(\\.|[^\\"])*\"

/* Punctuators */
PUNCTUATOR (\[|\]|\(|\)|\->|\+\+|--|&|\*|\+|-|!|\/|%|<<|>>|<|>|<=|>=|==|!=|\^|\||&&|\|\||[?:;=,])

/* Comments */
SINGLE_LINE_COMMENT \/\/.*
MULTI_LINE_COMMENT \/\*([^*]|\*+[^*/])*\*+\/

%%

{KEYWORD} {
    fprintf(token_output_file, "<KEYWORD, %s, line %d>\n", yytext, line_number);
    add_to_symbol_table(yytext, KEYWORD, line_number);
    return KEYWORD;
}

{IDENTIFIER} {
    fprintf(token_output_file, "<IDENTIFIER, %s, line %d>\n", yytext, line_number);
    add_to_symbol_table(yytext, IDENTIFIER, line_number);
    return IDENTIFIER;
}

{INTEGER_CONSTANT} {
    fprintf(token_output_file, "<INTEGER_CONSTANT, %s, line %d>\n", yytext, line_number);
    add_to_symbol_table(yytext, INTEGER_CONSTANT, line_number);
    return INTEGER_CONSTANT;
}

{FLOAT_CONSTANT} {
    fprintf(token_output_file, "<FLOAT_CONSTANT, %s, line %d>\n", yytext, line_number);
    add_to_symbol_table(yytext, FLOAT_CONSTANT, line_number);
    return FLOAT_CONSTANT;
}

{CHARACTER_CONSTANT} {
    fprintf(token_output_file, "<CHARACTER_CONSTANT, %s, line %d>\n", yytext, line_number);
    add_to_symbol_table(yytext, CHARACTER_CONSTANT, line_number);
    return CHARACTER_CONSTANT;
}

{STRING_LITERAL} {
    fprintf(token_output_file, "<STRING_LITERAL, %s, line %d>\n", yytext, line_number);
    add_to_symbol_table(yytext, STRING_LITERAL, line_number);
    return STRING_LITERAL;
}

{PUNCTUATOR} {
    fprintf(token_output_file, "<PUNCTUATOR, %s, line %d>\n", yytext, line_number);
    return PUNCTUATOR;
}

{SINGLE_LINE_COMMENT} { /* Ignore single-line comments */ }
{MULTI_LINE_COMMENT} { /* Ignore multi-line comments */ }

\n { line_number++; }
[ \t\r] { /* Ignore whitespace */ }

. { fprintf(token_output_file, "<UNRECOGNIZED_TOKEN, %s, line %d>\n", yytext, line_number); }

%%

int main() {
    // Open output files
    token_output_file = fopen("a6it_tokens.txt", "w");
    symbol_table_file = fopen("a6it_symbol_table.txt", "w");
    
    if (!token_output_file || !symbol_table_file) {
        perror("Error opening output files");
        return 1;
    }
    
    int token;
    while (token = yylex()) {
        // Process tokens if needed
    }
    
    print_symbol_table();
    
    // Close files
    fclose(token_output_file);
    fclose(symbol_table_file);
    
    return 0;
}