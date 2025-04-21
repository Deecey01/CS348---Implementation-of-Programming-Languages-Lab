%{
	
	#include<stdio.h>

	#include "A6_46_translator.h"
	#include "y.tab.h"

	extern "C" int yylex(void);

	extern void yyerror(const char *);
	static void comment(void);
%}

%option noyywrap

/* These regexes will be used to build other regexes */
ZERO                    "0"
DOT                     "."
DIGIT                   [0-9]
NON_DIGIT               [a-zA-Z_]
NON_ZERO_DIGIT          [1-9]
SIGN                    [+-]
WHITESPACE              [ \t]
NEWLINE                 [\n]

IDENTIFIER              ({NON_DIGIT}({NON_DIGIT}|{DIGIT})*)
INTEGER_CONSTANT        (({NON_ZERO_DIGIT}{DIGIT}*)|{ZERO}+)
DIGIT_SEQUENCE          {DIGIT}+
ESCAPE_SEQUENCE         ([\\][\'\"\?\\abfnrtv])
CHARACTER               ([^\'\\\n']|{ESCAPE_SEQUENCE})
CHARACTER_SEQUENCE      ({CHARACTER}+)
CHARACTER_CONSTANT      ([\']{CHARACTER_SEQUENCE}[\'])
STRING_CHARARCTER       {CHARACTER}
STRING_CHAR_SEQUENCE    ({STRING_CHARARCTER}+)
STRING_LITERAL          ([\"]{STRING_CHAR_SEQUENCE}?[\"])

/* Regex for comment matching */
SINGLELINE_COMMENT      [/][/].*
MULTILINE_START         [/][\*]+
MULTILINE_END           [\*]+[/]
MULTILINE_COMMENT       ({MULTILINE_START}([^\*]|([\*]+[^/\*]))*{MULTILINE_END})
COMMENT                 {MULTILINE_COMMENT}|{SINGLELINE_COMMENT}

%%

"else"              	{ return ELSE;     }
"for"               	{ return FOR;      }
"if"                	{ return IF;       }
"int"               	{ return INT;      }
"return"            	{ return RETURN;   }
"void"              	{ return VOID;     }

"["                 {return '[';  }
"]"                 { return ']'; }
"("                 { return '('; }
")"                 { return ')'; }
"{"                 { return '{'; }
"}"                 { return '}'; }
"."                 { return '.'; }
"&"                 { return '&'; }
"*"                 { return '*'; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"!"                 { return '!'; }
"/"                 { return '/'; }
"%"                 { return '%'; }
"<"                 { return '<'; }
">"                 { return '>'; }
"^"                 { return '^'; }
"|"                 { return '|'; }
"?"                 { return '?'; }
":"                 { return ':'; }
";"                 { return ';'; }
"="                 { return '='; }
","                 { return ','; }
"#"                 { return '#'; }

">="					{ return GREATER_THAN_EQUAL;  }
"<="					{ return LESS_THAN_EQUAL;     }
"!="					{ return NOT_EQUAL;           }
"=="					{ return EQUALITY;            }
"||"					{ return OR;                  }
"&&"					{ return AND;                 }

{NEWLINE}               { ;                                                                      }
{WHITESPACE}        	{ ;                 		                                             }
{COMMENT}				{ ;                  		                                             }
{INTEGER_CONSTANT}      { yylval._int_value=atoi(yytext); 			   return INTEGER_CONSTANT;  }
{STRING_LITERAL}    	{ yylval._string_literal = new string(yytext); return STRING_LITERAL;	 }
{IDENTIFIER}            { yylval._identifier.name=new string(yytext);  return IDENTIFIER;		 }
%%