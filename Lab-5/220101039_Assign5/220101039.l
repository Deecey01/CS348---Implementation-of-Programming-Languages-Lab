%{
#include <stdio.h>
#define RESERVED 1
#define NAME 2
#define NUM 3
#define CHAR_LIT 4
#define STR_LIT 5
#define SYMBOL 6
#define COMMENT1 7
#define COMMENT2 8
#define SPACE 9

int validate_num(const char* txt);
void write_to_symtab(int line_no, const char* token_type, const char* name);
int line_number = 1;
FILE* symtab_file;
%}

RESERVED     "char"|"else"|"for"|"if"|"int"|"return"|"void"
D            [0-9]
L            [a-zA-Z_]
NAME         {L}({L}|{D})*
NZ           [1-9]
NUMCONST     {NZ}{D}*|0+|[-+]?({NZ}{D}*|0+)

ESCSEQ       \\['"?\\abfnrtv]
CHAR_CONTENT {ESCSEQ}|[^'\\\n]
CHAR_LIT     '{CHAR_CONTENT}'

STR_CONTENT  {ESCSEQ}|[^"\\\n]
STR_LIT      \"{STR_CONTENT}*\"

SYMBOL       [][(){}]|->|&&|\|\||[!%&*+,./:;<=>?~-]|==|!=|<=|>=

CMT_SINGLE   \/\/[^\n]*
CMT_MULTI    \/\*([^*]|\*+[^*/])*\*+\/

WHITESPACE   [ \t\n]

%%

{RESERVED}    { printf("<KEYWORD, %s>\n", yytext); 
                write_to_symtab(line_number, "KEYWORD", yytext); }

{NAME}        { printf("<IDENTIFIER, %s>\n", yytext);
                write_to_symtab(line_number, "IDENTIFIER", yytext); }

{NUMCONST}    { if(validate_num(yytext)) {
                    printf("<INTEGER_CONSTANT, %s>\n", yytext);
                    write_to_symtab(line_number, "INTEGER_CONSTANT", yytext);
                } else {
                    printf("<INVALID_NUMBER, %s>\n", yytext);
                    write_to_symtab(line_number, "INVALID_NUMBER", yytext);
                }
              }

{CHAR_LIT}    { printf("<CHARACTER_CONSTANT, %s>\n", yytext);
                write_to_symtab(line_number, "CHARACTER_CONSTANT", yytext); }

{STR_LIT}     { printf("<STRING_LITERAL, %s>\n", yytext);
                write_to_symtab(line_number, "STRING_LITERAL", yytext); }

{SYMBOL}      { printf("<PUNCTUATOR, %s>\n", yytext);
                write_to_symtab(line_number, "PUNCTUATOR", yytext); }

{CMT_SINGLE}  { printf("<SINGLE_LINE_COMMENT> %s\n", yytext);
                write_to_symtab(line_number, "SINGLE_LINE_COMMENT", yytext); }

{CMT_MULTI}   { printf("<MULTILINE_COMMENT, %s>\n", yytext);
                write_to_symtab(line_number, "MULTILINE_COMMENT", yytext); }

\n            { line_number++; }
{WHITESPACE}         { ; }

%%

void write_to_symtab(int line_no, const char* token_type, const char* name) {
    fprintf(symtab_file, "%-8d%-20s%s\n", line_no, token_type, name);
}

int validate_num(const char* txt) {
    if(*txt == '-' || *txt == '+') txt++;
    return !(*txt == '0' && *(txt+1) != '\0');
}

int main() {
    symtab_file = fopen("symbol_table.txt", "w");
    if (!symtab_file) {
        printf("Error: Could not create symbol table file\n");
        return 1;
    }
    
    // Write header to symbol table file
    fprintf(symtab_file, "Line\t\tToken Type\t\t\tName\n");
    fprintf(symtab_file, "----------------------------------------\n");
    
    yylex();
    
    fclose(symtab_file);
    return 0;
}

int yywrap() {
    return 1;
}