%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "quad_array.h"
#include "type_check.h"
#include "parser.h"

extern int line_no;
extern void yyerror(const char *);
extern SymbolTable *current_table;
extern SymbolTable *global_table;
int line_no = 1;
// Function to create a constant symbol
Symbol* make_constant(TypeName type, void *value) {
    char temp_name[30];
    static int const_count = 0;
    
    // Generate a unique name for the constant
    sprintf(temp_name, "const_%d", const_count++);
    
    // Insert into current symbol table
    Symbol *sym = insert_symbol(current_table, temp_name, type, get_type_size(type));
    
    // Set value based on type
    switch (type) {
        case INT_TYPE:
            sym->type_info.int_val = *((int*)value);
            break;
        case FLOAT_TYPE:
            sym->type_info.float_val = *((float*)value);
            break;
        case CHAR_TYPE:
            sym->type_info.char_val = *((char*)value);
            break;
        case BOOL_TYPE:
            sym->type_info.bool_val = *((int*)value);
            break;
        default:
            // Should not reach here
            break;
    }
    
    return sym;
}

%}

/* Regular expressions for tokens */
digit       [0-9]
nonzero     [1-9]
letter      [a-zA-Z_]
identifier  {letter}({letter}|{digit})*
integer     {nonzero}{digit}*|0
float       {digit}+\.{digit}*([eE][+-]?{digit}+)?|{digit}*\.{digit}+([eE][+-]?{digit}+)?|{digit}+[eE][+-]?{digit}+
string      \"([^\"\\\n]|\\['"?\\abfnrtv])*\"
char_const  \'([^'\\\n]|\\['"?\\abfnrtv])\'

SINGLE_LINE_COMMENT_START \/\/
SINGLE_LINE_COMMENT {SINGLE_LINE_COMMENT_START}.*

MULTI_LINE_COMMENT_START \/\*
MULTI_LINE_COMMENT_END \*\/
MULTI_LINE_COMMENT {MULTI_LINE_COMMENT_START}([^*]|\*+[^*/])*\*+\/

%%

"void"      { return VOID; }
"char"      { return CHAR; }
"integer"       { return INT; }
"float"     { return FLOAT; }
"return"    { return RETURN; }
"if"        { return IF; }
"else"      { return ELSE; }
"for"       { return FOR; }
"while"     { return WHILE; }
"do"        { return DO; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }
"begin"     { return '{'; }  /* Map begin to { */
"end"       { return '}'; }  /* Map end to } */

{identifier} { 
    yylval.sym = lookup_symbol(current_table, yytext);
    if (!yylval.sym) {
        // Not found, create a new default entry
        yylval.sym = insert_symbol(current_table, yytext, INT_TYPE, get_type_size(INT_TYPE));
    }
    // No need for the is_pointer field - the type field already indicates this
    return IDENTIFIER; 
}

{integer}       { 
    int value = atoi(yytext);
    yylval.sym = make_constant(INT_TYPE, &value);
    return INTEGER_CONSTANT; 
}

{float}         { 
    float value = atof(yytext);
    yylval.sym = make_constant(FLOAT_TYPE, &value);
    return FLOATING_CONSTANT; 
}

{char_const}    { 
    char value;
    if (strlen(yytext) == 3) {
        value = yytext[1];
    } else if (strlen(yytext) == 4 && yytext[1] == '\\') {
        switch (yytext[2]) {
            case 'n': value = '\n'; break;
            case 't': value = '\t'; break;
            case 'r': value = '\r'; break;
            case '\\': value = '\\'; break;
            case '\'': value = '\''; break;
            case '\"': value = '\"'; break;
            case 'b': value = '\b'; break;
            case 'f': value = '\f'; break;
            case 'v': value = '\v'; break;
            case 'a': value = '\a'; break;
            default: value = yytext[2];
        }
    }
    yylval.sym = make_constant(CHAR_TYPE, &value);
    return CHARACTER_CONSTANT; 
}

{string}        { 
    /* Remove the quotes */
    yytext[strlen(yytext) - 1] = '\0';
    yylval.sval = strdup(yytext + 1);
    return STRING_LITERAL; 
}

"["     { return '['; }
"]"     { return ']'; }
"("     { return '('; }
")"     { return ')'; }
"{"     { return '{'; }
"}"     { return '}'; }
"."     { return '.'; }
"->"    { return ARROW; }
"++"    { return INC; }
"--"    { return DEC; }
"&"     { return '&'; }
"*"     { return '*'; }
"+"     { return '+'; }
"-"     { return '-'; }
"~"     { return '~'; }
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
{MULTI_LINE_COMMENT}        { 
    /* Count line numbers in multi-line comments */
    for (int i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') line_no++;
    }
}

\n                          { line_no++; }

[ \t\r]+                    { /* Ignore whitespace */ }

.                           { 
    /* Unrecognized character */
    char msg[100];
    sprintf(msg, "Unrecognized character: %s", yytext);
    yyerror(msg);
}

%%

int yywrap() {
    return 1;
}
