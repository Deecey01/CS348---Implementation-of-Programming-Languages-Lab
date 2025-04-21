%{
        #include <stdio.h>
    #include <stdlib.h>
   #include "A4_46.tab.h"
   extern void yyerror(char*);
%}


%x MULTI_LINE_FLAG
%x SINGLE_LINE_FLAG

IDENTIFIER              [A-Za-z_][A-Za-z0-9_]*
ESCAPE_SEQUENCE         "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"  

DIGIT                   [0-9]
DIGIT_SEQUENCE          [0-9]+
NON_ZERO_DIGIT          [1-9]
INTEGER_CONSTANT        {NON_ZERO_DIGIT}{DIGIT}*|"0"


C_CHAR                  [^\'\n\\']|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE         {C_CHAR}+
CHARACTER_CONSTANT      \'{C_CHAR_SEQUENCE}\'

S_CHAR                  [^\"\n\\]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE         {S_CHAR}+
STRING_LITERAL          \"({S_CHAR_SEQUENCE}?)\"
WHITESPACE              [ \t\r]

%%
"char"                      {return CHAR;}
"else"                      {return ELSE;}
"for"                       {return FOR;}
"if"                        {return IF;}
"int"                       {return INT;}
"return"                    {return RETURN;}
"void"                      {return VOID;}
{IDENTIFIER}                {return IDENTIFIER;}
{INTEGER_CONSTANT}          {return INTEGER_CONSTANT;}
{CHARACTER_CONSTANT}        {return CHARACTER_CONSTANT;}
{STRING_LITERAL}            {return STRING_LITERAL;}

"="                         {return EQ;}
":"                         {return COLON;}
";"                         {return SEMI_COLON;}
"?"                         {return QUESTION_MARK;}
"->"                        {return PTR;}
"<"                         {return LESS_THAN;}
">"                         {return GREATER_THAN;}
"<="                        {return LTE_OP;}
">="                        {return GTE_OP;}
"=="                        {return EQ_OP;}
"&&"                        {return AND_OP;}
"||"                        {return OR_OP;}
"!="                        {return NE_OP;}
"("                         {return ROUND_BRACE_OPEN;}
")"                         {return ROUND_BRACE_CLOSE;}
"{"                         {return CURLY_BRACE_OPEN;}
"}"                         {return CURLY_BRACE_CLOSE;}
"["                         {return SQ_BRACE_OPEN;}
"]"                         {return SQ_BRACE_CLOSE;}
"&"                         {return BITWISEAND;}
"*"                         {return STAR;}
"+"                         {return PLUS;}
"-"                         {return MINUS;}
"!"                         {return EXCLAMATION;}
"/"                         {return DIVIDE;}
"%"                         {return PERCENTAGE;}
","                         {return COMMA;}

"/*"                        {BEGIN(MULTI_LINE_FLAG);}
<MULTI_LINE_FLAG>"*/"       {BEGIN(INITIAL);}
<MULTI_LINE_FLAG>.          { }
<MULTI_LINE_FLAG>"\n"       { yylineno++; printf("\n-------- Parsing Line No. %d --------\n", yylineno); }

"//"                        {BEGIN(SINGLE_LINE_FLAG);}
<SINGLE_LINE_FLAG>"\n"      {BEGIN(INITIAL); yylineno++;printf("\n-------- Parsing Line No. %d --------\n", yylineno); }
<SINGLE_LINE_FLAG>.         { }
\n                          { yylineno++; printf("\n-------- Parsing Line No. %d --------\n", yylineno); }
{WHITESPACE}                { }
.                           { printf("ERROR [Line %d] : Invalid Token %s\n",yylineno,yytext); return INVALID_TOKEN;}

%%

int yywrap() {
    return 1;
}
