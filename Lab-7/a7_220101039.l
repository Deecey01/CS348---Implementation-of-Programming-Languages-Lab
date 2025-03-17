%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern void yyerror(const char *);
extern int line_no;

struct symbol *symbol_table = NULL;

/* Symbol table implementation */
struct symbol {
    char *name;
    char *type;     // char* to store type name
    int *line_nos;  // Array of line numbers
    int num_lines;  // Number of occurrences
    int capacity;   // Capacity of line_nos array
    struct symbol *next;
};

void add_to_symbol_table(char *name, char *token_type) {
    struct symbol *s = symbol_table;
    while (s != NULL) {
        if (strcmp(s->name, name) == 0) {
            // Symbol exists, add new line number
            if (s->num_lines >= s->capacity) {
                s->capacity *= 2;
                s->line_nos = realloc(s->line_nos, s->capacity * sizeof(int));
            }
            // Check if line number already exists
            for (int i = 0; i < s->num_lines; i++) {
                if (s->line_nos[i] == line_no) return;
            }
            s->line_nos[s->num_lines++] = line_no;
            return;
        }
        s = s->next;
    }
    
    // Create new symbol
    s = (struct symbol *) malloc(sizeof(struct symbol));
    s->name = strdup(name);
    s->type = strdup(token_type);  // Now directly using the passed token_type string
    s->capacity = 10;
    s->num_lines = 1;
    s->line_nos = malloc(s->capacity * sizeof(int));
    s->line_nos[0] = line_no;
    s->next = symbol_table;
    symbol_table = s;
}

void print_symbol_table() {
    struct symbol *s = symbol_table;
    printf("\n---- Symbol Table ----\n");
    printf("%-20s %-15s %-10s\n", "Name", "Token Type", "Line Numbers");
    printf("----------------------------------------\n");
    while (s != NULL) {
        printf("%-20s %-15s ", s->name, s->type);
        for (int i = 0; i < s->num_lines; i++) {
            printf("%d", s->line_nos[i]);
            if (i < s->num_lines - 1) printf(", ");
        }
        printf("\n");
        s = s->next;
    }
    printf("----------------------------------------\n");
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
    // comment     \/\/.*|\/\*([^*]|\*[^\/])*\*\/
SINGLE_LINE_COMMENT_START \/\/
SINGLE_LINE_COMMENT {SINGLE_LINE_COMMENT_START}.*

MULTI_LINE_COMMENT_START \/\*
MULTI_LINE_COMMENT_END \*\/
MULTI_LINE_COMMENT {MULTI_LINE_COMMENT_START}([^*]|\*+[^*/])*\*+\/
    // whitespace  [ \t\n\r\f\v]+

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
    add_to_symbol_table(yytext, "IDENTIFIER");
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

{SINGLE_LINE_COMMENT}       { /* Ignore comments */ }
{MULTI_LINE_COMMENT}    { /* Ignore whitespace */ 
    /* Count line numbers */
    for (int i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') line_no++;
    }
}

\n                          { line_no++; }

[ \t\r]+                      { /* Ignore whitespace */ }

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