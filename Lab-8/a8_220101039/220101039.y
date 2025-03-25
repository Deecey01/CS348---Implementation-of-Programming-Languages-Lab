%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void yyerror(const char *s);
int yylex(void);
int binaryToDecimal(const char *binary);
char* binaryToHex(const char *binary);
char* hexToBinary(const char *hex);
int hexToDecimal(const char *hex);
%}

%union {
    int ival;
    char sval[100];
}

%token <ival> NUMBER
%token <sval> BINARY HEXNUM
%token EXPR BINTODEC BINTOHEX HEXTOBIN HEXTODEC
%token PLUS MINUS MULTIPLY DIVIDE POWER
%token LPAREN RPAREN

%type <ival> expr
%type <ival> conversion_dec
%type <sval> conversion_hex
%type <sval> conversion_bin

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right POWER

%%

program:
    | program statement
;

statement: 
    EXPR LPAREN expr RPAREN    { printf("%d\n", $3); }
    | BINTODEC LPAREN BINARY RPAREN { 
        int result = binaryToDecimal($3);
        printf("%d\n", result); 
    }
    | BINTOHEX LPAREN BINARY RPAREN { 
        char *result = binaryToHex($3);
        printf("%s\n", result);
        free(result);
    }
    | HEXTOBIN LPAREN HEXNUM RPAREN { 
        char *result = hexToBinary($3);
        printf("%s\n", result);
        free(result);
    }
    | HEXTODEC LPAREN HEXNUM RPAREN { 
        int result = hexToDecimal($3);
        printf("%d\n", result); 
    }
;

expr: 
    NUMBER                     { $$ = $1; }
    | expr PLUS expr            { $$ = $1 + $3; }
    | expr MINUS expr           { $$ = $1 - $3; }
    | expr MULTIPLY expr        { $$ = $1 * $3; }
    | expr DIVIDE expr          { 
        if($3==0){
            yyerror("Division by zero");
            $$=0;
        }
        $$ = $1 / $3; }
    | expr POWER expr           { $$ = pow($1, $3); }
    | LPAREN expr RPAREN        { $$ = $2; }
;

%%

// Binary to Decimal conversion
int binaryToDecimal(const char *binary) {
    int dec = 0, power = 0;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            dec += pow(2, power);
        }
        power++;
    }
    return dec;
}

// Binary to Hexadecimal conversion
char* binaryToHex(const char *binary) {
    int dec = binaryToDecimal(binary);
    char *hex = malloc(20 * sizeof(char));
    sprintf(hex, "%X", dec);
    return hex;
}

// Hexadecimal to Binary conversion
char* hexToBinary(const char *hex) {
    int dec = hexToDecimal(hex);
    char *binary = malloc(33 * sizeof(char));
    binary[0] = '\0';
    
    for (int i = 31; i >= 0; i--) {
        binary[31-i] = ((dec >> i) & 1) + '0';
    }
    binary[32] = '\0';
    
    // Trim leading zeros
    char *stripped = binary;
    while (*stripped == '0' && *(stripped + 1) != '\0') {
        stripped++;
    }
    
    return strdup(stripped);
}

// Hexadecimal to Decimal conversion
int hexToDecimal(const char *hex) {
    return (int)strtol(hex, NULL, 16);
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Calculator Ready. Enter expressions:\n");
    yyparse();
    return 0;
}
