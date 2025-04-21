%{
	#include <stdio.h>
    #include <stdlib.h>
	#include <string.h>
	#include "A5_46_translator.h"
	#include "A5_46.tab.h"
	extern "C" int yylex();
    extern YYSTYPE yylval;
    extern int line;
    int line = 1;   
%}

%option noyywrap

/* Regular Expressions*/
DIGIT           [0-9]
NON_ZERO        [1-9]
LETTER          [a-zA-Z]


DIGIT_SEQ       {DIGIT}{DIGIT}*

ESCAPE_SEQ      "\\b"|"\\v"|"\\\'"|"\\\""|"\\\?"|"\\\\"|"\\a"|"\\f"|"\\n"|"\\r"|"\\t"
C_CHAR          [^\'\\\n]|{ESCAPE_SEQ}
S_CHAR          [^\"\\\n]|{ESCAPE_SEQ}

CHAR_SEQ        {C_CHAR}{C_CHAR}*
STRING_SEQ      {S_CHAR}{S_CHAR}*

IDENTIFIER      ({LETTER}|"_")({LETTER}|{DIGIT}|"_")*

INT_CONST       {NON_ZERO}{DIGIT}*|"0"+
CHAR_CONST      \'{CHAR_SEQ}\'

STRING          \"{STRING_SEQ}\"|\"\"
COMMENT_LINE    "//".*
COMMENT_MULTI   "/*"([^*]|\*+[^/*])*\**(\*"/")? 

WS              [ \t]
NEWLINE         [\n]

%%

{COMMENT_LINE}          { /*printf("single line comment(ignored)\n");*/ }
{COMMENT_MULTI}         { /*printf("multi line comment(ignored)\n");*/  }

"integer"                   { return INT;      }
"char"                  { return CHAR;     }
"void"                  { return VOID;     }

"if"                    { return IF;       }
"else"                  { return ELSE;     }
"for"                   { return FOR;      }

"return"                { return RETURN;   }

"<="                    { return LTE;                  }
">="                    { return GTE;                  }
"=="                    { return EQ;                   }
"!="                    { return NEQ;                  }
"&&"                    { return AND;                  }
"||"                    { return OR;                   }

";"                     { return SEMICOLON;  }

"["                     { return SQUARE_BRACKET_OPEN;  }
"]"                     { return SQUARE_BRACKET_CLOSE; }
"("                     { return ROUND_BRACKET_OPEN;   }
")"                     { return ROUND_BRACKET_CLOSE;  }
"begin"                     { return CURLY_BRACKET_OPEN;   }
"end"                     { return CURLY_BRACKET_CLOSE;  }

"*"                     { return MUL;        }
"+"                     { return ADD;        }
"-"                     { return SUB;        }
"/"                     { return DIV;        }
"%"                     { return MOD;        }

"&"                     { return BITWISE_AND;}
"!"                     { return EXCLAIM;    }
"<"                     { return BIT_SL;     }
">"                     { return BIT_SR;     }
","                     { return COMMA;      }
"="                     { return ASSIGN;     }
"?"                     { return QUESTION;   }
":"                     { return COLON;      }

{INT_CONST}             { 
	                        yylval.intval = atoi(yytext);
							return INTEGER_CONSTANT; 
                        }
{CHAR_CONST}            { 
	                        yylval.char_value = yytext;
							return CHARACTER_CONSTANT; 
						}

{IDENTIFIER}            { 
							id = yytext;
							return IDENTIFIER;
						}

{STRING}                { 
	                        yylval.char_value = yytext;
							return STRING_LITERAL; 
						}

{WS}                    { /*White-space Rule*/ }

{NEWLINE}               { /* ++line; */ }

%%