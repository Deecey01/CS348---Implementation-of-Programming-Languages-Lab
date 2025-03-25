%{
#include <string.h>
#include "y.tab.h"

int context_provider=0;
#define CONTEXT_EXPR 1
#define CONTEXT_BINTODEC 2
#define CONTEXT_BINTOHEX 3
#define CONTEXT_HEXTOBIN 4
#define CONTEXT_HEXTODEC 5
%}

%option noyywrap

%%
"expr"         { context_provider=CONTEXT_EXPR; return EXPR; }
"bintodec"     { context_provider=CONTEXT_BINTODEC; return BINTODEC; }
"bintohex"     { context_provider=CONTEXT_BINTOHEX; return BINTOHEX; }
"hextobin"     { context_provider=CONTEXT_HEXTOBIN; return HEXTOBIN; }
"hextodec"     { context_provider= CONTEXT_HEXTODEC; return HEXTODEC; }

[01]+          { 
    if(context_provider==CONTEXT_BINTODEC || context_provider==CONTEXT_BINTOHEX){
        strcpy(yylval.sval, yytext); 
        return BINARY; 
    }
    else if(context_provider==CONTEXT_HEXTOBIN || context_provider==CONTEXT_HEXTODEC){
        strcpy(yylval.sval, yytext); 
        return HEXNUM; 
    }
    else{
        yylval.ival = atoi(yytext); 
        return NUMBER;
    }
}
[0-9]+         { yylval.ival = atoi(yytext); return NUMBER; }
[0-9A-Fa-f]+   { 
    if(context_provider==CONTEXT_HEXTOBIN || context_provider==CONTEXT_HEXTODEC){
        strcpy(yylval.sval, yytext); 
        return HEXNUM; 
    }
    else{
        yylval.ival = atoi(yytext); 
        return NUMBER;
    }
}
"+"            { return PLUS; }
"-"            { return MINUS; }
"*"            { return MULTIPLY; }
"/"            { return DIVIDE; }
"**"           { return POWER; }
"("            { return LPAREN; }
")"            { return RPAREN; }
[\t\n ]        ; /* Ignore whitespace */
.              { printf("Unexpected character: %s\n", yytext); }
%%
