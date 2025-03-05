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
%}

RESERVED     "char"|"else"|"for"|"if"|"int"|"return"|"void"
D            [0-9]
L            [a-zA-Z]
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

WHITESPACE   [ \t\n]+

%%

{RESERVED}    { printf("<KEYWORD, %s>\n", yytext); }
{NAME}        { printf("<IDENTIFIER, %s>\n", yytext); }
{NUMCONST}    { if(validate_num(yytext)) 
                printf("<INTEGER_CONSTANT, %s>\n", yytext); 
              else 
                printf("<INVALID_NUMBER, %s>\n", yytext); }
{CHAR_LIT}    { printf("<CHARACTER_CONSTANT, %s>\n", yytext); }
{STR_LIT}     { printf("<STRING_LITERAL, %s>\n", yytext); }
{SYMBOL}      { printf("<PUNCTUATOR, %s>\n", yytext); }
{CMT_SINGLE}  { printf("<SINGLE_LINE_COMMENT>\n"); }
{CMT_MULTI}   { printf("<MULTILINE_COMMENT>\n"); }
{WHITESPACE}  { ; }
    /*.             { printf("<UNRECOGNIZED, %s>\n", yytext); }*/

%%

int validate_num(const char* txt) {
    if(*txt == '-' || *txt == '+') txt++;
    return !(*txt == '0' && *(txt+1) != '\0');
}

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}