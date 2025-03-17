%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern int yylex();
extern void print_symbol_table(FILE *output);

int line_no = 1;
FILE *output_file = NULL;

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_no, s);
    if (output_file) {
        fprintf(output_file, "Error at line %d: %s\n", line_no, s);
    }
}

/* Print function for grammar reductions */
void print_reduction(const char *rule) {
    if (output_file) {
        fprintf(output_file, "Reduction: %s\n", rule);
    }
}

%}

/* Define token types */
%union {
    int ival;
    float fval;
    char cval;
    char *sval;
}

/* Define all tokens from the grammar */
%token <sval> IDENTIFIER
%token <ival> INTEGER_CONSTANT
%token <fval> FLOATING_CONSTANT
%token <cval> CHARACTER_CONSTANT
%token <sval> STRING_LITERAL

/* Keywords */
%token RETURN VOID FLOAT INTEGER CHAR FOR CONST WHILE
%token BOOL IF DO ELSE BEGIN_BLOCK END_BLOCK

/* Operators and punctuators */
%token ARROW INC DEC LEFT_SHIFT RIGHT_SHIFT LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP

/* Operator precedence (from lowest to highest) */
%right '='
%right '?' ':'
%left OR_OP
%left AND_OP
%left '|'
%left '^'
%left EQ_OP NE_OP
%left '<' '>' LE_OP GE_OP
%left LEFT_SHIFT RIGHT_SHIFT
%left '+' '-'
%left '*' '/' '%'
%right '!' UMINUS UPLUS '&' DEREF
%left '[' ']' '(' ')' ARROW INC DEC

/* Define non-terminal types if needed */
%type <sval> primary_expression postfix_expression unary_expression
%type <sval> multiplicative_expression additive_expression relational_expression
%type <sval> equality_expression logical_and_expression logical_or_expression
%type <sval> conditional_expression assignment_expression expression
%type <sval> declaration init_declarator type_specifier declarator direct_declarator
%type <sval> pointer parameter_list parameter_declaration initializer
%type <sval> statement compound_statement block_item_list block_item
%type <sval> expression_statement selection_statement iteration_statement jump_statement
%type <sval> function_definition declaration_list translation_unit

%start translation_unit

%%

/* Grammar rules start here */

/* 1. Expressions */
primary_expression:
    IDENTIFIER                  { print_reduction("primary_expression -> IDENTIFIER (An identifier reference)"); $$ = $1; }
    | INTEGER_CONSTANT          { print_reduction("primary_expression -> INTEGER_CONSTANT (An integer literal)"); $$ = "int_const"; }
    | FLOATING_CONSTANT         { print_reduction("primary_expression -> FLOATING_CONSTANT (A floating-point literal)"); $$ = "float_const"; }
    | CHARACTER_CONSTANT        { print_reduction("primary_expression -> CHARACTER_CONSTANT (A character literal)"); $$ = "char_const"; }
    | STRING_LITERAL            { print_reduction("primary_expression -> STRING_LITERAL (A string literal)"); $$ = "string_literal"; }
    | '(' expression ')'        { print_reduction("primary_expression -> ( expression ) (Expression in parentheses)"); $$ = $2; }
    ;

postfix_expression:
    primary_expression                          { print_reduction("postfix_expression -> primary_expression (A simple expression)"); $$ = $1; }
    | postfix_expression '[' expression ']'     { print_reduction("postfix_expression -> postfix_expression [ expression ] (Array access)"); $$ = "array_access"; }
    | postfix_expression '(' ')'                { print_reduction("postfix_expression -> postfix_expression ( ) (Function call with no arguments)"); $$ = "function_call"; }
    | postfix_expression '(' argument_expression_list ')' { print_reduction("postfix_expression -> postfix_expression ( argument_expression_list ) (Function call with arguments)"); $$ = "function_call_with_args"; }
    | postfix_expression ARROW IDENTIFIER       { print_reduction("postfix_expression -> postfix_expression -> IDENTIFIER (Pointer-to-member access)"); $$ = "pointer_access"; }
    ;

argument_expression_list:
    assignment_expression                               { print_reduction("argument_expression_list -> assignment_expression (First argument in function call)"); }
    | argument_expression_list ',' assignment_expression { print_reduction("argument_expression_list -> argument_expression_list , assignment_expression (Additional argument in function call)"); }
    ;

unary_expression:
    postfix_expression                  { print_reduction("unary_expression -> postfix_expression (Expression without unary operator)"); $$ = $1; }
    | '&' unary_expression              { print_reduction("unary_expression -> & unary_expression (Address-of operator)"); $$ = "addr_of"; }
    | '*' unary_expression %prec DEREF  { print_reduction("unary_expression -> * unary_expression (Dereference operator)"); $$ = "deref"; }
    | '+' unary_expression %prec UPLUS  { print_reduction("unary_expression -> + unary_expression (Unary plus operator)"); $$ = "uplus"; }
    | '-' unary_expression %prec UMINUS { print_reduction("unary_expression -> - unary_expression (Unary minus operator)"); $$ = "uminus"; }
    | '!' unary_expression              { print_reduction("unary_expression -> ! unary_expression (Logical NOT operator)"); $$ = "not"; }
    ;

multiplicative_expression:
    unary_expression                                  { print_reduction("multiplicative_expression -> unary_expression (Expression without multiplication)"); $$ = $1; }
    | multiplicative_expression '*' unary_expression  { print_reduction("multiplicative_expression -> multiplicative_expression * unary_expression (Multiplication operation)"); $$ = "mult"; }
    | multiplicative_expression '/' unary_expression  { print_reduction("multiplicative_expression -> multiplicative_expression / unary_expression (Division operation)"); $$ = "div"; }
    | multiplicative_expression '%' unary_expression  { print_reduction("multiplicative_expression -> multiplicative_expression % unary_expression (Modulo operation)"); $$ = "mod"; }
    ;

additive_expression:
    multiplicative_expression                               { print_reduction("additive_expression -> multiplicative_expression (Expression without addition/subtraction)"); $$ = $1; }
    | additive_expression '+' multiplicative_expression     { print_reduction("additive_expression -> additive_expression + multiplicative_expression (Addition operation)"); $$ = "add"; }
    | additive_expression '-' multiplicative_expression     { print_reduction("additive_expression -> additive_expression - multiplicative_expression (Subtraction operation)"); $$ = "sub"; }
    ;

relational_expression:
    additive_expression                                  { print_reduction("relational_expression -> additive_expression (Expression without comparison)"); $$ = $1; }
    | relational_expression '<' additive_expression      { print_reduction("relational_expression -> relational_expression < additive_expression (Less than comparison)"); $$ = "lt"; }
    | relational_expression '>' additive_expression      { print_reduction("relational_expression -> relational_expression > additive_expression (Greater than comparison)"); $$ = "gt"; }
    | relational_expression LE_OP additive_expression    { print_reduction("relational_expression -> relational_expression <= additive_expression (Less than or equal comparison)"); $$ = "le"; }
    | relational_expression GE_OP additive_expression    { print_reduction("relational_expression -> relational_expression >= additive_expression (Greater than or equal comparison)"); $$ = "ge"; }
    ;

equality_expression:
    relational_expression                                { print_reduction("equality_expression -> relational_expression (Expression without equality check)"); $$ = $1; }
    | equality_expression EQ_OP relational_expression    { print_reduction("equality_expression -> equality_expression == relational_expression (Equality comparison)"); $$ = "eq"; }
    | equality_expression NE_OP relational_expression    { print_reduction("equality_expression -> equality_expression != relational_expression (Inequality comparison)"); $$ = "ne"; }
    ;

logical_and_expression:
    equality_expression                                   { print_reduction("logical_and_expression -> equality_expression (Expression without logical AND)"); $$ = $1; }
    | logical_and_expression AND_OP equality_expression   { print_reduction("logical_and_expression -> logical_and_expression && equality_expression (Logical AND operation)"); $$ = "and"; }
    ;

logical_or_expression:
    logical_and_expression                                  { print_reduction("logical_or_expression -> logical_and_expression (Expression without logical OR)"); $$ = $1; }
    | logical_or_expression OR_OP logical_and_expression    { print_reduction("logical_or_expression -> logical_or_expression || logical_and_expression (Logical OR operation)"); $$ = "or"; }
    ;

conditional_expression:
    logical_or_expression                                                   { print_reduction("conditional_expression -> logical_or_expression (Expression without conditional operator)"); $$ = $1; }
    | logical_or_expression '?' expression ':' conditional_expression       { print_reduction("conditional_expression -> logical_or_expression ? expression : conditional_expression (Conditional/ternary operation)"); $$ = "cond"; }
    ;

assignment_expression:
    conditional_expression                                { print_reduction("assignment_expression -> conditional_expression (Expression without assignment)"); $$ = $1; }
    | unary_expression '=' assignment_expression          { print_reduction("assignment_expression -> unary_expression = assignment_expression (Assignment operation)"); $$ = "assign"; }
    ;

expression:
    assignment_expression    { print_reduction("expression -> assignment_expression (Complete expression)"); $$ = $1; }
    ;

/* 2. Declarations */
declaration:
    type_specifier init_declarator ';'    { print_reduction("declaration -> type_specifier init_declarator ; (Variable or function declaration)"); }
    ;

init_declarator:
    declarator                      { print_reduction("init_declarator -> declarator (Declaration without initialization)"); }
    | declarator '=' initializer    { print_reduction("init_declarator -> declarator = initializer (Declaration with initialization)"); }
    ;

type_specifier:
    VOID        { print_reduction("type_specifier -> void (Void type)"); $$ = "void"; }
    | CHAR      { print_reduction("type_specifier -> char (Character type)"); $$ = "char"; }
    | INTEGER   { print_reduction("type_specifier -> integer (Integer type)"); $$ = "integer"; }
    | FLOAT     { print_reduction("type_specifier -> float (Float type)"); $$ = "float"; }
    | BOOL      { print_reduction("type_specifier -> bool (Boolean type)"); $$ = "bool"; }
    ;

declarator:
    pointer direct_declarator    { print_reduction("declarator -> pointer direct_declarator (Pointer declarator)"); }
    | direct_declarator          { print_reduction("declarator -> direct_declarator (Non-pointer declarator)"); }
    ;

direct_declarator:
    IDENTIFIER                                  { print_reduction("direct_declarator -> IDENTIFIER (Simple identifier)"); }
    | IDENTIFIER '[' INTEGER_CONSTANT ']'       { print_reduction("direct_declarator -> IDENTIFIER [ INTEGER_CONSTANT ] (Array declarator)"); }
    | IDENTIFIER '(' parameter_list ')'         { print_reduction("direct_declarator -> IDENTIFIER ( parameter_list ) (Function declarator with parameters)"); }
    | IDENTIFIER '(' ')'                        { print_reduction("direct_declarator -> IDENTIFIER ( ) (Function declarator without parameters)"); }
    ;

pointer:
    '*'    { print_reduction("pointer -> * (Pointer symbol)"); }
    ;

parameter_list:
    parameter_declaration                        { print_reduction("parameter_list -> parameter_declaration (First parameter in function)"); }
    | parameter_list ',' parameter_declaration   { print_reduction("parameter_list -> parameter_list , parameter_declaration (Additional parameter in function)"); }
    ;

parameter_declaration:
    type_specifier IDENTIFIER          { print_reduction("parameter_declaration -> type_specifier IDENTIFIER (Parameter with type and name)"); }
    | type_specifier pointer IDENTIFIER { print_reduction("parameter_declaration -> type_specifier pointer IDENTIFIER (Pointer parameter with type and name)"); }
    | type_specifier                   { print_reduction("parameter_declaration -> type_specifier (Parameter with type only)"); }
    | type_specifier pointer           { print_reduction("parameter_declaration -> type_specifier pointer (Pointer parameter with type only)"); }
    ;

initializer:
    assignment_expression    { print_reduction("initializer -> assignment_expression (Initializer expression)"); }
    ;

/* 3. Statements */
statement:
    compound_statement       { print_reduction("statement -> compound_statement (Block statement)"); }
    | expression_statement   { print_reduction("statement -> expression_statement (Expression statement)"); }
    | selection_statement    { print_reduction("statement -> selection_statement (Selection/if statement)"); }
    | iteration_statement    { print_reduction("statement -> iteration_statement (Loop statement)"); }
    | jump_statement         { print_reduction("statement -> jump_statement (Jump/return statement)"); }
    ;

compound_statement:
    BEGIN_BLOCK END_BLOCK                    { print_reduction("compound_statement -> begin end (Empty block)"); }
    | BEGIN_BLOCK block_item_list END_BLOCK  { print_reduction("compound_statement -> begin block_item_list end (Block with items)"); }
    ;

block_item_list:
    block_item                     { print_reduction("block_item_list -> block_item (First item in block)"); }
    | block_item_list block_item   { print_reduction("block_item_list -> block_item_list block_item (Additional item in block)"); }
    ;

block_item:
    declaration    { print_reduction("block_item -> declaration (Declaration in block)"); }
    | statement    { print_reduction("block_item -> statement (Statement in block)"); }
    ;

expression_statement:
    ';'             { print_reduction("expression_statement -> ; (Empty statement)"); }
    | expression ';' { print_reduction("expression_statement -> expression ; (Expression statement)"); }
    ;

selection_statement:
    IF '(' expression ')' statement                    { print_reduction("selection_statement -> if ( expression ) statement (If statement)"); }
    | IF '(' expression ')' statement ELSE statement   { print_reduction("selection_statement -> if ( expression ) statement else statement (If-else statement)"); }
    ;

iteration_statement:
    FOR '(' expression_statement expression_statement expression ')' statement    { print_reduction("iteration_statement -> for ( expression_statement expression_statement expression ) statement (For loop with update)"); }
    | FOR '(' expression_statement expression_statement ')' statement             { print_reduction("iteration_statement -> for ( expression_statement expression_statement ) statement (For loop without update)"); }
    | WHILE '(' expression ')' statement                                         { print_reduction("iteration_statement -> while ( expression ) statement (While loop)"); }
    | DO statement WHILE '(' expression ')' ';'                                  { print_reduction("iteration_statement -> do statement while ( expression ) ; (Do-while loop)"); }

jump_statement:
    RETURN ';'             { print_reduction("jump_statement -> return ;"); }
    | RETURN expression ';' { print_reduction("jump_statement -> return expression ;"); }
    ;

/* 4. Translation Unit */
translation_unit:
    function_definition                  { print_reduction("translation_unit -> function_definition"); }
    | declaration                        { print_reduction("translation_unit -> declaration"); }
    | translation_unit function_definition { print_reduction("translation_unit -> translation_unit function_definition"); }
    | translation_unit declaration       { print_reduction("translation_unit -> translation_unit declaration"); }
    ;

function_definition:
    type_specifier declarator compound_statement                    { print_reduction("function_definition -> type_specifier declarator compound_statement"); }
    | type_specifier declarator declaration_list compound_statement { print_reduction("function_definition -> type_specifier declarator declaration_list compound_statement"); }
    ;

declaration_list:
    declaration                      { print_reduction("declaration_list -> declaration"); }
    | declaration_list declaration   { print_reduction("declaration_list -> declaration_list declaration"); }
    ;

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open file %s\n", argv[1], "r");
            return 1;
        }
        yyin = file;
        
        // Create output file with .output extension
        char output_filename[256];
        strcpy(output_filename, "output.txt");
        output_file = fopen(output_filename, "w");
        if (!output_file) {
            fprintf(stderr, "Cannot create output file %s\n", output_filename);
            fclose(file);
            return 1;
        }
    }

    printf("Parsing...\n");
    fprintf(output_file, "Parsing...\n");
    int result = yyparse();
    
    if (result == 0) {
        printf("Parsing completed successfully.\n");
        fprintf(output_file, "Parsing completed successfully.\n");
        print_symbol_table(output_file);
    } else {
        printf("Parsing failed.\n");
        fprintf(output_file, "Parsing failed.\n");
    }

    if (output_file) {
        fclose(output_file);
    }
    return result;
}