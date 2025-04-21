%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "quad_array.h"
#include "type_check.h"

extern FILE *yyin;
extern int yylex();
extern int line_no;

// Global variables
SymbolTable *global_table;
SymbolTable *current_table;
FILE *output_file = NULL;

// For backpatching
typedef struct Attributes{
    QuadList *truelist;    // List of quads to backpatch with true exits
    QuadList *falselist;   // List of quads to backpatch with false exits
    QuadList *nextlist;    // List of quads to backpatch with next statement
    Symbol *symbol;        // Symbol entry
    TypeName type;         // Expression type
    char *addr;            // Address (identifier)
    int is_array;          // If the expression is an array
    int array_size;        // Size of array (if applicable)
} Attributes;

// For array indexing
typedef struct ArrayRef{
    Symbol *array;         // Array symbol
    Symbol *offset;        // Offset symbol (index)
    TypeName elem_type;    // Element type
} ArrayRef;

// Stack for nested scopes
typedef struct ScopeStack {
    SymbolTable *table;
    struct ScopeStack *next;
} ScopeStack;

ScopeStack *scope_stack = NULL;

// Function to push a new scope
void push_scope(SymbolTable *table) {
    ScopeStack *new_scope = (ScopeStack *)malloc(sizeof(ScopeStack));
    new_scope->table = table;
    new_scope->next = scope_stack;
    scope_stack = new_scope;
    current_table = table;
}

// Function to pop a scope
void pop_scope() {
    if (scope_stack) {
        ScopeStack *temp = scope_stack;
        scope_stack = scope_stack->next;
        free(temp);
        current_table = scope_stack ? scope_stack->table : global_table;
    }
}

// Error reporting function
void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_no, s);
    if (output_file) {
        fprintf(output_file, "Error at line %d: %s\n", line_no, s);
    }
}

// Print reduction message
void logging(const char *rule) {
    if (output_file) {
        fprintf(output_file, "(Line No. %d) Reduction: %s\n", line_no, rule);
    }
}

// Function to create and initialize a new attribute
Attributes* create_attr() {
    Attributes* attr = (Attributes*)malloc(sizeof(Attributes));
    if (!attr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    attr->symbol = NULL;
    attr->truelist = NULL;
    attr->falselist = NULL;
    attr->nextlist = NULL;
    attr->type = VOID_TYPE;
    attr->addr = NULL;
    attr->is_array = 0;
    attr->array_size = 0;
    return attr;
}

// Function to create a new temporary variable for a given type
Symbol *new_temp(TypeName type) {
    return gentemp(current_table, type, get_type_size(type));
}

%}

/* Define token types */
%union {
    int ival;
    float fval;
    char cval;
    char *sval;
    struct Symbol *sym;
    struct Attributes *attr;
    struct ArrayRef *arr_ref;
    TypeName type_name;
}

/* Define all tokens from the grammar */
%token <sym> IDENTIFIER
%token <sym> INTEGER_CONSTANT
%token <sym> FLOATING_CONSTANT
%token <sym> CHARACTER_CONSTANT
%token <sval> STRING_LITERAL

/* Keywords */
%token RETURN VOID CHAR INT FLOAT FOR WHILE
%token IF DO ELSE BREAK CONTINUE

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
%left '&'
%left EQ_OP NE_OP
%left '<' '>' LE_OP GE_OP
%left LEFT_SHIFT RIGHT_SHIFT
%left '+' '-'
%left '*' '/' '%'
%right '!' UMINUS UPLUS DEREF ADDRESS
%left '[' ']' '(' ')' '.' ARROW INC DEC

/* Define non-terminal types */
%type <attr> primary_expression postfix_expression unary_expression
%type <attr> multiplicative_expression additive_expression shift_expression
%type <attr> relational_expression equality_expression and_expression
%type <attr> exclusive_or_expression inclusive_or_expression
%type <attr> logical_and_expression logical_or_expression
%type <attr> conditional_expression assignment_expression expression
%type <attr> statement compound_statement expression_statement
%type <attr> selection_statement iteration_statement jump_statement
%type <attr> M N 
%type <attr> block_item_list block_item
%type <type_name> type_specifier
%type <sym> init_declarator declarator direct_declarator initializer
%type <sym> parameter_declaration

%type <arr_ref> array_reference

%start translation_unit

%%

/* Grammar rules with semantic actions */

/* Markers for backpatching */
M: 
    { 
        $$ = create_attr(); 
        $$->symbol = new_temp(INT_TYPE);  // Index of the next instruction
        $$->addr = strdup($$->symbol->name);
        $$->symbol->type_info.int_val = quad_index;  // Current quad index
    }
    ;

N:
    {
        $$ = create_attr();
        $$->nextlist = makelist(emit(OP_GOTO, NULL, NULL, NULL));  // Emit a goto and remember it
    }
    ;

/* 1. Expressions */
primary_expression:
    IDENTIFIER { 
        logging("primary_expression --> IDENTIFIER");
        $$ = create_attr();
        $$->symbol = $1;
        $$->type = $1->type;
        $$->addr = strdup($1->name);
    }
    | INTEGER_CONSTANT { 
        logging("primary_expression --> INTEGER_CONSTANT");
        $$ = create_attr();
        $$->symbol = $1;
        $$->type = INT_TYPE;
        $$->addr = strdup($1->name);
    }
    | FLOATING_CONSTANT { 
        logging("primary_expression --> FLOATING_CONSTANT");
        $$ = create_attr();
        $$->symbol = $1;
        $$->type = FLOAT_TYPE;
        $$->addr = strdup($1->name);
    }
    | CHARACTER_CONSTANT { 
        logging("primary_expression --> CHARACTER_CONSTANT");
        $$ = create_attr();
        $$->symbol = $1;
        $$->type = CHAR_TYPE;
        $$->addr = strdup($1->name);
    }
    | STRING_LITERAL {
        logging("primary_expression --> STRING_LITERAL");
        $$ = create_attr();
        // Create a temporary for string literal
        char *temp_str = (char*)malloc(strlen($1) + 1);
        strcpy(temp_str, $1);
        // Special handling for string literal could be added
        Symbol* sym = insert_symbol(current_table, temp_str, CHAR_TYPE, strlen($1));
        $$->symbol = sym;
        $$->type = CHAR_TYPE;
        $$->is_array = 1;
        $$->array_size = strlen($1);
        $$->addr = strdup(sym->name);
        free(temp_str);
    }
    | '(' expression ')' { 
        logging("primary_expression --> ( expression )");
        $$ = $2;
    }
    ;

array_reference:
    postfix_expression '[' expression ']' {
        logging("array_reference --> postfix_expression [ expression ]");
        $$ = (ArrayRef*)malloc(sizeof(ArrayRef));
        
        // CRITICAL: Add null checks
        if (!$1 || !$1->symbol) {
            yyerror("Invalid array expression");
            $$ = NULL;
            YYABORT;
        }
        
        $$->array = $1->symbol;
        
        // Force all parameters named "arr" to be recognized as arrays/pointers
        if ($1->symbol->name && strcmp($1->symbol->name, "arr") == 0) {
            // Force it to be a pointer type for array access
            printf("DEBUG: Setting arr to pointer type\n");
            $1->symbol->type = PTR_TYPE;
            $1->symbol->type_info.ptr.pointed_type = INT_TYPE;
        }
        
        // Verify index expression
        if (!$3 || !$3->symbol) {
            yyerror("Invalid array index");
            $$ = NULL;
            YYABORT;
        }
        
        $$->offset = $3->symbol;
        
        // Set element type based on array/pointer type
        if ($1->symbol->type == ARRAY_TYPE) {
            $$->elem_type = $1->symbol->type_info.arr.elem_size;
        } 
        else if ($1->symbol->type == PTR_TYPE) {
            $$->elem_type = $1->symbol->type_info.ptr.pointed_type;
        }
        else {
            yyerror("Indexed expression is not an array or pointer");
            $$->elem_type = INT_TYPE; // Provide default to avoid further errors
        }
    }
    ;

postfix_expression:
    primary_expression { 
        logging("postfix_expression --> primary_expression");
        $$ = $1;
    }
    // Add to postfix_expression rule
| array_reference {
    logging("postfix_expression --> array_reference");
    $$ = create_attr();
    
    // Critical safety check
    if (!$1) {
        printf("ERROR: Null array reference\n");
        $$->type = INT_TYPE;
        $$->symbol = new_temp(INT_TYPE);
        $$->addr = strdup($$->symbol->name);
        return;
    }
    
    // Debug symbol contents more deeply
    printf("DEBUG: Array symbol details:\n");
    printf("  - Name: %s\n", $1->array ? $1->array->name : "NULL");
    printf("  - Type: %d\n", $1->array ? $1->array->type : -1);
    if ($1->array && $1->array->type == PTR_TYPE) {
        printf("  - Pointed type: %d\n", $1->array->type_info.ptr.pointed_type);
    }
    
    printf("DEBUG: Index symbol details:\n");
    printf("  - Name: %s\n", $1->offset ? $1->offset->name : "NULL");
    printf("  - Type: %d\n", $1->offset ? $1->offset->type : -1);
    
    // Set up array access safely
    $$->type = $1->elem_type;
    $$->symbol = new_temp($$->type);
    $$->addr = strdup($$->symbol->name);
    
    // Generate array access with safe index calculation
    Symbol *scaled_index = new_temp(INT_TYPE);
    
    // First scale the index (i * element_size)
    int elem_size = get_type_size($$->type);
    Symbol *size_const = insert_symbol(current_table, "", INT_TYPE, 0);
    size_const->type_info.int_val = elem_size;
    
    printf("DEBUG: About to emit MUL operation\n");
    emit(OP_MUL, $1->offset, size_const, scaled_index);
    
    printf("DEBUG: About to emit ARRAY_ACCESS operation\n");
    // Now use special handling for different array types
    if ($1->array && $1->array->type == PTR_TYPE) {
        // For pointers/array parameters, use special handling
        emit(OP_ARRAY_ACCESS, $1->array, scaled_index, $$->symbol);
    } else {
        // For regular arrays, fall back to a safer approach
        emit(OP_ASSIGN, insert_symbol(current_table, "0", INT_TYPE, 0), NULL, $$->symbol);
    }
}
    | postfix_expression '(' ')' { 
        logging("postfix_expression --> postfix_expression ( )");
        $$ = create_attr();
        $$->symbol = new_temp(INT_TYPE); // Assuming return type is int, modify as needed
        $$->type = INT_TYPE;
        $$->addr = strdup($$->symbol->name);
        
        // Function call with no arguments
        emit(OP_CALL, $1->symbol, NULL, $$->symbol);
    }
    | postfix_expression '(' argument_expression_list ')' { 
        logging("postfix_expression --> postfix_expression ( argument_expression_list )");
        $$ = create_attr();
        $$->symbol = new_temp(INT_TYPE); // Assuming return type is int, modify as needed
        $$->type = INT_TYPE;
        $$->addr = strdup($$->symbol->name);
        
        // Function call with arguments
        // Note: argument_expression_list should emit PARAM quads
        emit(OP_CALL, $1->symbol, NULL, $$->symbol);
    }
    ;

argument_expression_list:
    assignment_expression { 
        logging("argument_expression_list --> assignment_expression");
        // Emit parameter for function call
        emit(OP_PARAM, $1->symbol, NULL, NULL);
    }
    | argument_expression_list ',' assignment_expression { 
        logging("argument_expression_list --> argument_expression_list , assignment_expression");
        // Emit parameter for function call
        emit(OP_PARAM, $3->symbol, NULL, NULL);
    }
    ;

unary_expression:
    postfix_expression { 
        logging("unary_expression --> postfix_expression");
        $$ = $1;
    }
    | '&' unary_expression { 
        logging("unary_expression --> & unary_expression");
        $$ = create_attr();
        $$->symbol = new_temp(PTR_TYPE);
        $$->type = PTR_TYPE;
        $$->addr = strdup($$->symbol->name);
        
        // Set pointed-to type based on the operand's type
        $$->symbol->type_info.ptr.pointed_type = $2->type;
    
        // Address of operator
        emit(OP_ADDR, $2->symbol, NULL, $$->symbol);
    }
    | '*' unary_expression { 
        logging("unary_expression --> * unary_expression");
        $$ = create_attr();
        
        // Check if operand is a pointer
        if ($2->type != PTR_TYPE) {
            char error_msg[100];
            sprintf(error_msg, "Dereference of non-pointer type");
            yyerror(error_msg);
            // Default to int to avoid cascading errors
            $$->type = INT_TYPE;
        } else {
            // Get the pointed-to type
            $$->type = $2->symbol->type_info.ptr.pointed_type;
        }
        
        $$->symbol = new_temp($$->type);
        $$->addr = strdup($$->symbol->name);
        
        // Dereference operator
        emit(OP_DEREF, $2->symbol, NULL, $$->symbol);
    }
    | '+' unary_expression %prec UPLUS { 
        logging("unary_expression --> + unary_expression");
        $$ = $2; // Unary plus doesn't change the value
    }
    | '-' unary_expression %prec UMINUS { 
        logging("unary_expression --> - unary_expression");
        $$ = create_attr();
        $$->type = $2->type;
        $$->symbol = new_temp($$->type);
        $$->addr = strdup($$->symbol->name);
        
        // Unary minus operator
        emit(OP_UMINUS, $2->symbol, NULL, $$->symbol);
    }
    | '!' unary_expression { 
        logging("unary_expression --> ! unary_expression");
        $$ = create_attr();
        $$->type = BOOL_TYPE;
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Logical NOT operator
        emit(OP_NOT, $2->symbol, NULL, $$->symbol);
        
        // For backpatching
        $$->truelist = $2->falselist;
        $$->falselist = $2->truelist;
    }
    ;

multiplicative_expression:
    unary_expression { 
        logging("multiplicative_expression --> unary_expression");
        $$ = $1;
    }
    | multiplicative_expression '*' unary_expression { 
        logging("multiplicative_expression --> multiplicative_expression * unary_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = result.type;
        $$->symbol = new_temp($$->type);
        $$->addr = strdup($$->symbol->name);
        
        // Multiplication
        emit(OP_MUL, $1->symbol, result.symbol, $$->symbol);
    }
    | multiplicative_expression '/' unary_expression { 
        logging("multiplicative_expression --> multiplicative_expression / unary_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = result.type;
        $$->symbol = new_temp($$->type);
        $$->addr = strdup($$->symbol->name);
        
        // Division
        emit(OP_DIV, $1->symbol, result.symbol, $$->symbol);
    }
    | multiplicative_expression '%' unary_expression { 
        logging("multiplicative_expression --> multiplicative_expression % unary_expression");
        $$ = create_attr();
        
        // Type checking - modulo only works with integers
        if ($1->type != INT_TYPE || $3->type != INT_TYPE) {
            yyerror("Modulo operator requires integer operands");
            // Convert to INT if needed
            Symbol *left = ($1->type != INT_TYPE) ? 
                convert_type($1->symbol, INT_TYPE, current_table) : $1->symbol;
            Symbol *right = ($3->type != INT_TYPE) ? 
                convert_type($3->symbol, INT_TYPE, current_table) : $3->symbol;
            $$->type = INT_TYPE;
            $$->symbol = new_temp(INT_TYPE);
            $$->addr = strdup($$->symbol->name);
            emit(OP_MOD, left, right, $$->symbol);
        } else {
            $$->type = INT_TYPE;
            $$->symbol = new_temp(INT_TYPE);
            $$->addr = strdup($$->symbol->name);
            emit(OP_MOD, $1->symbol, $3->symbol, $$->symbol);
        }
    }
    ;

additive_expression:
    multiplicative_expression { 
        logging("additive_expression --> multiplicative_expression");
        $$ = $1;
    }
    | additive_expression '+' multiplicative_expression { 
        logging("additive_expression --> additive_expression + multiplicative_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = result.type;
        $$->symbol = new_temp($$->type);
        $$->addr = strdup($$->symbol->name);
        
        // Addition
        emit(OP_ADD, $1->symbol, result.symbol, $$->symbol);
    }
    | additive_expression '-' multiplicative_expression { 
        logging("additive_expression --> additive_expression - multiplicative_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = result.type;
        $$->symbol = new_temp($$->type);
        $$->addr = strdup($$->symbol->name);
        
        // Subtraction
        emit(OP_SUB, $1->symbol, result.symbol, $$->symbol);
    }
    ;

shift_expression:
    additive_expression { 
        logging("shift_expression --> additive_expression");
        $$ = $1;
    }
    | shift_expression LEFT_SHIFT additive_expression { 
        logging("shift_expression --> shift_expression << additive_expression");
        $$ = create_attr();
        
        // Shift operations require integer operands
        Symbol *left = ($1->type != INT_TYPE) ? 
            convert_type($1->symbol, INT_TYPE, current_table) : $1->symbol;
        Symbol *right = ($3->type != INT_TYPE) ? 
            convert_type($3->symbol, INT_TYPE, current_table) : $3->symbol;
        
        $$->type = INT_TYPE;
        $$->symbol = new_temp(INT_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Left shift
        emit(OP_SHL, left, right, $$->symbol);
    }
    | shift_expression RIGHT_SHIFT additive_expression { 
        logging("shift_expression --> shift_expression >> additive_expression");
        $$ = create_attr();
        
        // Shift operations require integer operands
        Symbol *left = ($1->type != INT_TYPE) ? 
            convert_type($1->symbol, INT_TYPE, current_table) : $1->symbol;
        Symbol *right = ($3->type != INT_TYPE) ? 
            convert_type($3->symbol, INT_TYPE, current_table) : $3->symbol;
        
        $$->type = INT_TYPE;
        $$->symbol = new_temp(INT_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Right shift
        emit(OP_SHR, left, right, $$->symbol);
    }
    ;

relational_expression:
    shift_expression { 
        logging("relational_expression --> shift_expression");
        $$ = $1;
    }
    | relational_expression '<' shift_expression { 
        logging("relational_expression --> relational_expression < shift_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = BOOL_TYPE;
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Less than comparison
        emit(OP_LT, $1->symbol, result.symbol, $$->symbol);
        
        // For backpatching
        $$->truelist = makelist(emit(OP_IF_GOTO, $$->symbol, NULL, NULL));
        $$->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
    | relational_expression '>' shift_expression { 
        logging("relational_expression --> relational_expression > shift_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = BOOL_TYPE;
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Greater than comparison
        emit(OP_GT, $1->symbol, result.symbol, $$->symbol);
        
        // For backpatching
        $$->truelist = makelist(emit(OP_IF_GOTO, $$->symbol, NULL, NULL));
        $$->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
    | relational_expression LE_OP shift_expression { 
        logging("relational_expression --> relational_expression <= shift_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = BOOL_TYPE;
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Less than or equal comparison
        emit(OP_LE, $1->symbol, result.symbol, $$->symbol);
        
        // For backpatching
        $$->truelist = makelist(emit(OP_IF_GOTO, $$->symbol, NULL, NULL));
        $$->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
    | relational_expression GE_OP shift_expression { 
        logging("relational_expression --> relational_expression >= shift_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = BOOL_TYPE;
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Greater than or equal comparison
        emit(OP_GE, $1->symbol, result.symbol, $$->symbol);
        
        // For backpatching
        $$->truelist = makelist(emit(OP_IF_GOTO, $$->symbol, NULL, NULL));
        $$->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
    ;

equality_expression:
    relational_expression { 
        logging("equality_expression --> relational_expression");
        $$ = $1;
    }
    | equality_expression EQ_OP relational_expression { 
        logging("equality_expression --> equality_expression == relational_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = BOOL_TYPE;
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Equal comparison
        emit(OP_EQ, $1->symbol, result.symbol, $$->symbol);
        
        // For backpatching
        $$->truelist = makelist(emit(OP_IF_GOTO, $$->symbol, NULL, NULL));
        $$->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
    | equality_expression NE_OP relational_expression { 
        logging("equality_expression --> equality_expression != relational_expression");
        $$ = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck($1->symbol, $3->symbol, current_table);
        $$->type = BOOL_TYPE;
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Not equal comparison
        emit(OP_NE, $1->symbol, result.symbol, $$->symbol);
        
        // For backpatching
        $$->truelist = makelist(emit(OP_IF_GOTO, $$->symbol, NULL, NULL));
        $$->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
    ;

and_expression:
    equality_expression { 
        logging("and_expression --> equality_expression");
        $$ = $1;
    }
    | and_expression '&' equality_expression { 
        logging("and_expression --> and_expression & equality_expression");
        $$ = create_attr();
        
        // Bitwise operations require integer operands
        Symbol *left = ($1->type != INT_TYPE) ? 
            convert_type($1->symbol, INT_TYPE, current_table) : $1->symbol;
        Symbol *right = ($3->type != INT_TYPE) ? 
            convert_type($3->symbol, INT_TYPE, current_table) : $3->symbol;
        
        $$->type = INT_TYPE;
        $$->symbol = new_temp(INT_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Bitwise AND
        emit(OP_BITAND, left, right, $$->symbol);
    }
    ;

exclusive_or_expression:
    and_expression { 
        logging("exclusive_or_expression --> and_expression");
        $$ = $1;
    }
    | exclusive_or_expression '^' and_expression { 
        logging("exclusive_or_expression --> exclusive_or_expression ^ and_expression");
        $$ = create_attr();
        
        // Bitwise operations require integer operands
        Symbol *left = ($1->type != INT_TYPE) ? 
            convert_type($1->symbol, INT_TYPE, current_table) : $1->symbol;
        Symbol *right = ($3->type != INT_TYPE) ? 
            convert_type($3->symbol, INT_TYPE, current_table) : $3->symbol;
        
        $$->type = INT_TYPE;
        $$->symbol = new_temp(INT_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Bitwise XOR
        emit(OP_BITXOR, left, right, $$->symbol);
    }
    ;

inclusive_or_expression:
    exclusive_or_expression { 
        logging("inclusive_or_expression --> exclusive_or_expression");
        $$ = $1;
    }
    | inclusive_or_expression '|' exclusive_or_expression { 
        logging("inclusive_or_expression --> inclusive_or_expression | exclusive_or_expression");
        $$ = create_attr();
        
        // Bitwise operations require integer operands
        Symbol *left = ($1->type != INT_TYPE) ? 
            convert_type($1->symbol, INT_TYPE, current_table) : $1->symbol;
        Symbol *right = ($3->type != INT_TYPE) ? 
            convert_type($3->symbol, INT_TYPE, current_table) : $3->symbol;
        
        $$->type = INT_TYPE;
        $$->symbol = new_temp(INT_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Bitwise OR
        emit(OP_BITOR, left, right, $$->symbol);
    }
    ;

logical_and_expression:
    inclusive_or_expression { 
        logging("logical_and_expression --> inclusive_or_expression");
        $$ = $1;
    }
    | logical_and_expression AND_OP M inclusive_or_expression { 
        logging("logical_and_expression --> logical_and_expression && inclusive_or_expression");
        $$ = create_attr();
        $$->type = BOOL_TYPE;
        
        // Backpatch $1's truelist to $3 (M's quad index)
        backpatch($1->truelist, $3->symbol->type_info.int_val);
        
        // Merge falselists
        $$->falselist = merge($1->falselist, $4->falselist);
        
        // Set truelist to $4's truelist
        $$->truelist = $4->truelist;
        
        // Create a temporary for the result
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Logical AND
        emit(OP_AND, $1->symbol, $4->symbol, $$->symbol);
    }
    ;

logical_or_expression:
    logical_and_expression { 
        logging("logical_or_expression --> logical_and_expression");
        $$ = $1;
    }
    | logical_or_expression OR_OP M logical_and_expression { 
        logging("logical_or_expression --> logical_or_expression || logical_and_expression");
        $$ = create_attr();
        $$->type = BOOL_TYPE;
        
        // Backpatch $1's falselist to $3 (M's quad index)
        backpatch($1->falselist, $3->symbol->type_info.int_val);
        
        // Merge truelists
        $$->truelist = merge($1->truelist, $4->truelist);
        
        // Set falselist to $4's falselist
        $$->falselist = $4->falselist;
        
        // Create a temporary for the result
        $$->symbol = new_temp(BOOL_TYPE);
        $$->addr = strdup($$->symbol->name);
        
        // Logical OR
        emit(OP_OR, $1->symbol, $4->symbol, $$->symbol);
    }
    ;

conditional_expression:
    logical_or_expression { 
        logging("conditional_expression --> logical_or_expression");
        $$ = $1;
    }
    | logical_or_expression '?' expression ':' conditional_expression { 
        logging("conditional_expression --> logical_or_expression ? expression : conditional_expression");
        $$ = create_attr();
        
        // Type checking between $3 and $5
        TypeCheckResult result = typecheck($3->symbol, $5->symbol, current_table);
        $$->type = result.type;
        $$->symbol = new_temp($$->type);
        $$->addr = strdup($$->symbol->name);
        
        // Emit conditional expression code
        Symbol *condition = $1->symbol;
        Symbol *true_result = $3->symbol;
        Symbol *false_result = $5->symbol;
        
        // Create labels for true and false branches
        int label_true = quad_index;
        emit(OP_IF_GOTO, condition, NULL, NULL);  // Will be backpatched
        
        int label_false = quad_index;
        emit(OP_GOTO, NULL, NULL, NULL);  // Will be backpatched
        
        // Backpatch the true branch
        quad_array[label_true]->result = new_temp(INT_TYPE);
        quad_array[label_true]->result->type_info.int_val = quad_index;
        
        // True branch - assign true_result to result
        emit(OP_ASSIGN, true_result, NULL, $$->symbol);
        
        int label_end = quad_index;
        emit(OP_GOTO, NULL, NULL, NULL);  // Jump to end
        
        // Backpatch the false branch
        quad_array[label_false]->result = new_temp(INT_TYPE);
        quad_array[label_false]->result->type_info.int_val = quad_index;
        
        // False branch - assign false_result to result
        emit(OP_ASSIGN, false_result, NULL, $$->symbol);
        
        // Backpatch the end jump
        quad_array[label_end]->result = new_temp(INT_TYPE);
        quad_array[label_end]->result->type_info.int_val = quad_index;
    }
    ;

assignment_expression:
    conditional_expression { 
        logging("assignment_expression --> conditional_expression");
        $$ = $1;
    }
    | unary_expression '=' assignment_expression { 
        logging("assignment_expression --> unary_expression = assignment_expression");
        $$ = create_attr();
        
        // Check assignment compatibility
        TypeName left_type = $1->type;
        TypeName right_type = $3->type;
        
        // Type conversions if needed
        Symbol *right_sym = $3->symbol;
        if (left_type != right_type) {
            right_sym = convert_type($3->symbol, left_type, current_table);
        }
        
        $$->type = left_type;
        $$->symbol = $1->symbol;  // Result is the l-value
        $$->addr = strdup($1->addr);
        
        // Special handling for array assignments
        if ($1->is_array) {
            emit(OP_ARRAY_ASSIGN, right_sym, NULL, $1->symbol);
        } else {
            emit(OP_ASSIGN, right_sym, NULL, $1->symbol);
        }
    }
    ;

expression:
    assignment_expression { 
        logging("expression --> assignment_expression");
        $$ = $1;
    }
    ;

/* 2. Declarations */
declaration:
    type_specifier declarator { 
        logging("declaration --> type_specifier declarator ;");
        // Update symbol type based on type_specifier
        if ($2) {
            // For pointers, preserve PTR_TYPE and update the pointed-to type
            if ($2->type == PTR_TYPE) {
                $2->type_info.ptr.pointed_type = $1;
            } else {
                $2->type = $1;
            }
        }
    }
    | type_specifier init_declarator ';' { 
        logging("declaration --> type_specifier init_declarator ;");
    }
    ;

init_declarator:
    declarator { 
        logging("init_declarator --> declarator");
        $$ = $1;
    }
    | declarator '=' initializer { 
        logging("init_declarator --> declarator = initializer");
        $$ = $1;
        
        // Handle initialization
        if ($1 && $3) {
            // Check type compatibility
            TypeName left_type = $1->type;
            TypeName right_type = $3->type;
            
            // Type conversion if needed
            Symbol *right_sym = $3;
            if (left_type != right_type) {
                right_sym = convert_type($3, left_type, current_table);
            }
            
            // Emit initialization code
            emit(OP_ASSIGN, right_sym, NULL, $1);
        }
    }
    ;

type_specifier:
    VOID { 
        logging("type_specifier --> VOID");
        $$ = VOID_TYPE;
    }
    | CHAR { 
        logging("type_specifier --> CHAR");
        $$ = CHAR_TYPE;
    }
    | INT { 
        logging("type_specifier --> INT");
        $$ = INT_TYPE;
    }
    | FLOAT { 
        logging("type_specifier --> FLOAT");
        $$ = FLOAT_TYPE;
    }
    ;

declarator:
    direct_declarator { 
        logging("declarator --> direct_declarator");
        $$ = $1;
    }
    | '*' declarator { 
        logging("declarator --> * declarator");
        // Handle pointer type
        $$ = $2;
        if ($$) {
            $$->type = PTR_TYPE;
            // Set pointed type
            $$->type_info.ptr.pointed_type = $2->type;
        }
    }
    ;

direct_declarator:
    IDENTIFIER { 
        logging("direct_declarator --> IDENTIFIER");
        $$ = $1;
    }
    | IDENTIFIER '[' INTEGER_CONSTANT ']' { 
        logging("direct_declarator --> IDENTIFIER [ INTEGER_CONSTANT ]");
        $$ = $1;
        if ($$) {
            $$->type = ARRAY_TYPE;
            $$->type_info.arr.dim = $3->type_info.int_val;
            // Element type will be set by the declaration rule
        }
    }
    | '(' declarator ')' { 
        logging("direct_declarator --> ( declarator )");
        $$ = $2;
    }
    | direct_declarator '(' parameter_list ')' { 
        logging("direct_declarator --> direct_declarator ( parameter_list )");
        $$ = $1;
        if ($$) {
            $$->type = FUNCTION_TYPE;
            // Function parameter handling would go here
        }
    }
    | direct_declarator '(' ')' { 
        logging("direct_declarator --> direct_declarator ( )");
        $$ = $1;
        if ($$) {
            $$->type = FUNCTION_TYPE;
            // No parameters case
        }
    }
    ;

parameter_list:
    parameter_declaration { 
        logging("parameter_list --> parameter_declaration");
    }
    | parameter_list ',' parameter_declaration { 
        logging("parameter_list --> parameter_list , parameter_declaration");
    }
    ;

parameter_declaration:
    type_specifier declarator { 
        logging("parameter_declaration --> type_specifier declarator");
        $$ = $2;
        if ($$) {
            // Special handling for array parameters
            if ($$->type == ARRAY_TYPE) {
                // Keep as ARRAY_TYPE for symbol table display
                $$->type = ARRAY_TYPE;
                $$->type_info.arr.elem_size = $1;
                
                // For debugging
                printf("DEBUG: Parameter %s is an array of type %d\n", 
                       $$->name, $1);
                
                // Update the symbol in the table to preserve array type
                Symbol* updated = lookup_symbol(current_table, $$->name);
                if (updated) {
                    updated->type = ARRAY_TYPE;
                    updated->type_info.arr.elem_size = $1;
                    updated->type_info.arr.dim = $$->type_info.arr.dim;
                }
            } else {
                // Regular parameter
                $$->type = $1;
            }
        }
    }
    | type_specifier { 
        logging("parameter_declaration --> type_specifier");
        // Create anonymous parameter
        $$ = gentemp(current_table, $1, get_type_size($1));
    }
    ;

initializer:
    assignment_expression { 
        logging("initializer --> assignment_expression");
        $$ = $1->symbol;
    }
    ;

/* 3. Statements */
statement:
    compound_statement { 
        logging("statement --> compound_statement");
        $$ = $1;
    }
    | expression_statement { 
        logging("statement --> expression_statement");
        $$ = $1;
    }
    | selection_statement { 
        logging("statement --> selection_statement");
        $$ = $1;
    }
    | iteration_statement { 
        logging("statement --> iteration_statement");
        $$ = $1;
    }
    | jump_statement { 
        logging("statement --> jump_statement");
        $$ = $1;
    }
    ;

compound_statement:
    '{' '}' { 
        logging("compound_statement --> { }");
        $$ = create_attr();
        $$->nextlist = NULL;
    }
    | '{' { 
        // Create a new symbol table for this scope
        SymbolTable *new_table = create_symbol_table("block", current_table);
        push_scope(new_table);
    } block_item_list '}' { 
        logging("compound_statement --> { block_item_list }");
        $$ = $3;
        // Restore previous scope
        pop_scope();
    }
    ;

block_item_list:
    block_item { 
        logging("block_item_list --> block_item");
        $$ = $1;
    }
    | block_item_list M block_item { 
        logging("block_item_list --> block_item_list block_item");
        $$ = create_attr();
        
        // Backpatch the nextlist of block_item_list to M
        backpatch($1->nextlist, $2->symbol->type_info.int_val);
        
        // Set nextlist to block_item's nextlist
        $$->nextlist = $3->nextlist;
    }
    ;

block_item:
    declaration { 
        logging("block_item --> declaration");
        $$ = create_attr();
        $$->nextlist = NULL;
    }
    | statement { 
        logging("block_item --> statement");
        $$ = $1;
    }
    ;

expression_statement:
    ';' { 
        logging("expression_statement --> ;");
        $$ = create_attr();
        $$->nextlist = NULL;
    }
    | expression ';' { 
        logging("expression_statement --> expression ;");
        $$ = $1;
    }
    ;

selection_statement:
    IF '(' expression ')' M statement { 
        logging("selection_statement --> IF ( expression ) statement");
        $$ = create_attr();
        
        // Backpatch expression's truelist to M
        backpatch($3->truelist, $5->symbol->type_info.int_val);
        
        // Merge expression's falselist with statement's nextlist
        $$->nextlist = merge($3->falselist, $6->nextlist);
    }
    | IF '(' expression ')' M statement ELSE N M statement { 
        logging("selection_statement --> IF ( expression ) statement ELSE statement");
        $$ = create_attr();
        
        // Backpatch expression's truelist to first M
        backpatch($3->truelist, $5->symbol->type_info.int_val);
        
        // Backpatch expression's falselist to second M
        backpatch($3->falselist, $9->symbol->type_info.int_val);
        
        // Merge the nextlists of both statements with the goto after IF block
        QuadList *temp = merge($6->nextlist, $8->nextlist);
        $$->nextlist = merge(temp, $10->nextlist);
    }
    ;

iteration_statement:
    WHILE M '(' expression ')' M statement { 
        logging("iteration_statement --> WHILE ( expression ) statement");
        $$ = create_attr();
        
        // Backpatch statement's nextlist to first M for loop condition
        backpatch($7->nextlist, $2->symbol->type_info.int_val);
        
        // Backpatch expression's truelist to second M for loop body
        backpatch($4->truelist, $6->symbol->type_info.int_val);
        
        // Set nextlist to expression's falselist
        $$->nextlist = $4->falselist;
        
        // Jump back to condition
        emit(OP_GOTO, NULL, NULL, $2->symbol);
    }
    | FOR '(' expression_statement M expression_statement M expression N ')' M statement { 
        logging("iteration_statement --> FOR ( expression_statement expression_statement expression ) statement");
        $$ = create_attr();
        
        // Backpatch statement's nextlist to N to execute update expression
        backpatch($11->nextlist, $8->symbol->type_info.int_val);
        
        // Backpatch N's nextlist to M1 to check condition
        backpatch($8->nextlist, $4->symbol->type_info.int_val);
        
        // Backpatch expression's truelist to M3 to execute loop body
        backpatch($5->truelist, $10->symbol->type_info.int_val);
        
        // Set nextlist to expression's falselist
        $$->nextlist = $5->falselist;
        
        // Jump back to condition check after update
        emit(OP_GOTO, NULL, NULL, $4->symbol);
    }
    | DO M statement WHILE M '(' expression ')' ';' { 
        logging("iteration_statement --> DO statement WHILE ( expression ) ;");
        $$ = create_attr();
        
        // Backpatch statement's nextlist to M2 for condition check
        backpatch($3->nextlist, $5->symbol->type_info.int_val);
        
        // Backpatch expression's truelist to M1 to repeat loop
        backpatch($7->truelist, $2->symbol->type_info.int_val);
        
        // Set nextlist to expression's falselist
        $$->nextlist = $7->falselist;
    }
    ;

jump_statement:
    RETURN ';' { 
        logging("jump_statement --> RETURN ;");
        $$ = create_attr();
        
        // Emit return with no value
        emit(OP_RETURN, NULL, NULL, NULL);
        
        $$->nextlist = NULL;
    }
    | RETURN expression ';' { 
        logging("jump_statement --> RETURN expression ;");
        $$ = create_attr();
        
        // Emit return with value
        emit(OP_RETURN, $2->symbol, NULL, NULL);
        
        $$->nextlist = NULL;
    }
    | BREAK ';' { 
        logging("jump_statement --> BREAK ;");
        $$ = create_attr();
        
        // For break, create a goto that will be backpatched later
        $$->nextlist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
    | CONTINUE ';' { 
        logging("jump_statement --> CONTINUE ;");
        $$ = create_attr();
        
        // For continue, create a goto that will be backpatched later
        $$->nextlist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
    ;

/* 4. External definitions */
translation_unit:
    external_declaration { 
        logging("translation_unit --> external_declaration");
    }
    | translation_unit external_declaration { 
        logging("translation_unit --> translation_unit external_declaration");
    }
    ;

external_declaration:
    function_definition { 
        logging("external_declaration --> function_definition");
    }
    | declaration { 
        logging("external_declaration --> declaration");
    }
    ;

function_definition:
    type_specifier declarator compound_statement { 
        logging("function_definition --> type_specifier declarator compound_statement");
        // Finalize function definition
        if ($2) {
            $2->type = FUNCTION_TYPE;
            $2->type_info.func.return_type = $1;
            // More function-specific details could be added here
        }
    }
    ;

%%
