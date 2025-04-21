// include the necessary header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

// extern the lex methods and variables (will be obtained from lex.yy.c)
extern int yylex();
extern char* yytext;
extern int yylineno;
extern int yylen;
extern FILE* yyin;
extern FILE* yyout;

int main(int argc, char* argv[]){
    
    // Check if the command-line arguments are in the correct format
    if(argc != 2){
        printf("Usage: ./a.out <test_file.nc>\n");
        return 1;
    }

    // Open the file name mentioned for testing the lexical analysis
    char* file_name = argv[1];
    yyin = fopen(file_name, "r");   
    
    // Get tokens one-by-one
    int token;
    token = yylex();

    // The loop runs till there are tokens available
    while(token){
        switch (token)
        {
        case KEYWORD:
            printf("<KEYWORD, %s>\n", yytext);
            break;

        case IDENTIFIER:
            printf("<IDENTIFIER, %s>\n", yytext);
            break;
        
        case INT_CONSTANT:
            printf("<INT_CONSTANT, %s>\n", yytext);
            break;

        case CHAR_CONSTANT:
            printf("<CHAR_CONSTANT, %s>\n", yytext);
            break;

        case STRING_LITERAL: ;
            // Code to remove the double quotes from the string literal while printing
            int length = strlen(yytext);
            char* result = malloc(length);
            int i = 0, j = 0;
            if(yytext[0]!='"'){
                result[0] = yytext[0];
            }
            while(i < length){
                if(yytext[i] == '"' && yytext[i-1]!='\\')
                {
                    i++;
                    continue;
                }
                result[j++] = yytext[i];
                i++;
            }
            printf("<STRING_LITERAL, %s>\n", result);
            break;

        case PUNCTUATOR:
            printf("<PUNCTUATOR, %s>\n", yytext);
            break;

        case SINGLE_LINE_COMMENT:
            printf("<SINGLE_LINE_COMMENT at line number %d>\n", yylineno);
            break;
        
        case MULTI_LINE_COMMENT:
            printf("<MULTI_LINE_COMMENT at line number %d>\n", yylineno);
            break;

        default:
            // Case when the token is none of the types we have handled.
            printf("<UNEXPECTED TOKEN at line number %d: %s>\n", yylineno, yytext);
            break;
        }

        // get the next token
        token = yylex();
    }

    return 0;
}