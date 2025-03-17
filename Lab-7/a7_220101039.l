%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern void yyerror(const char *);
extern int line_no;

/* Symbol table implementation */
struct symbol {
    char *name;
    int type;
    struct symbol *next;
};

struct symbol *symbol_table = NULL;

void add_to_symbol_table(char *name, int type) {
    struct symbol *s = symbol_table;
    while (s != NULL) {
        if (strcmp(s->name, name) == 0) {
            /* Symbol already exists */
            return;
        }
        s = s->next;
    }
    
    /* Create new symbol */
    s = (struct symbol *) malloc(sizeof(struct symbol));
    s->name = strdup(name);
    s->type = type;
    s->next = symbol_table;
    symbol_table = s;
}

void print_symbol_table() {
    struct symbol *s = symbol_table;
    printf("\n---- Symbol Table ----\n");
    printf("%-20s %-10s\n", "Name", "Token Type");
    printf("------------------------------\n");
    while (s != NULL) {
        printf("%-20s %-10d\n", s->name, s->type);
        s = s->next;
    }
    printf("------------------------------\n");
}

%}

/* Regular expressions for tokens */
digit       [0-9]
nonzero     [1-9]
letter      [a-zA-Z_]
identifier  {letter}({letter}|{digit})*
integer     {nonzero}{digit}*|0
    // float       {digit}*\.{digit}+([eE][+-]?{digit}+)?|{digit}+[eE][+-]?{digit}+
float       {digit}+\.{digit}*([eE][+-]?{digit}+)?|{digit}*\.{digit}+([eE][+-]?{digit}+)?|{digit}+[eE][+-]?{digit}+
string      \"([^\"\\\n]|\\['"?\\abfnrtv])*\"
char_const  \'([^'\\\n]|\\['"?\\abfnrtv])\'
comment     \/\/.*|\/\*([^*]|\*[^\/])*\*\/
whitespace  [ \t\n\r\f\v]+

%%

"return"    { return RETURN; }
"void"      { return VOID; }
"float"     { return FLOAT; }
"integer"   { return INTEGER; }
"char"      { return CHAR; }
"for"       { return FOR; }
"const"     { return CONST; }
"while"     { return WHILE; }
"bool"      { return BOOL; }
"if"        { return IF; }
"do"        { return DO; }
"else"      { return ELSE; }
"begin"     { return BEGIN_BLOCK; }
"end"       { return END_BLOCK; }

{identifier}    { 
    add_to_symbol_table(yytext, IDENTIFIER);
    yylval.sval = strdup(yytext); 
    return IDENTIFIER; 
}

{integer}       { 
    yylval.ival = atoi(yytext); 
    return INTEGER_CONSTANT; 
}

{float}         { 
    yylval.fval = atof(yytext); 
    return FLOATING_CONSTANT; 
}

{char_const}    { 
    /* Handle character constants */
    if (strlen(yytext) == 3) {
        yylval.cval = yytext[1];
    } else if (strlen(yytext) == 4 && yytext[1] == '\\') {
        /* Handle escape sequences */
        switch (yytext[2]) {
            case 'n': yylval.cval = '\n'; break;
            case 't': yylval.cval = '\t'; break;
            case 'r': yylval.cval = '\r'; break;
            case '\\': yylval.cval = '\\'; break;
            case '\'': yylval.cval = '\''; break;
            case '\"': yylval.cval = '\"'; break;
            case 'b': yylval.cval = '\b'; break;
            case 'f': yylval.cval = '\f'; break;
            case 'v': yylval.cval = '\v'; break;
            case 'a': yylval.cval = '\a'; break;
            default: yylval.cval = yytext[2];
        }
    }
    return CHARACTER_CONSTANT; 
}

{string}        { 
    /* Remove the quotes */
    yylval.sval = strdup(yytext + 1);
    if (yylval.sval[strlen(yylval.sval) - 1] == '"')
        yylval.sval[strlen(yylval.sval) - 1] = '\0';
    return STRING_LITERAL; 
}

"["     { return '['; }
"]"     { return ']'; }
"("     { return '('; }
")"     { return ')'; }
"->"    { return ARROW; }
"++"    { return INC; }
"--"    { return DEC; }
"&"     { return '&'; }
"*"     { return '*'; }
"+"     { return '+'; }
"-"     { return '-'; }
"!"     { return '!'; }
"/"     { return '/'; }
"%"     { return '%'; }
"<<"    { return LEFT_SHIFT; }
">>"    { return RIGHT_SHIFT; }
"<"     { return '<'; }
">"     { return '>'; }
"<="    { return LE_OP; }
">="    { return GE_OP; }
"=="    { return EQ_OP; }
"!="    { return NE_OP; }
"^"     { return '^'; }
"|"     { return '|'; }
"&&"    { return AND_OP; }
"||"    { return OR_OP; }
"?"     { return '?'; }
":"     { return ':'; }
";"     { return ';'; }
"="     { return '='; }
","     { return ','; }

{comment}       { /* Ignore comments */ }
{whitespace}    { /* Ignore whitespace */ 
    /* Count line numbers */
    for (int i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') line_no++;
    }
}

.               { 
    /* Unrecognized character */
    char msg[100];
    sprintf(msg, "Unrecognized character: %s", yytext);
    yyerror(msg);
}

%%

int yywrap() {
    return 1;
}