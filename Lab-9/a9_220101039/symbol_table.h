/* symbol_table.h */
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    VOID_TYPE,
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    BOOL_TYPE,
    PTR_TYPE,
    ARRAY_TYPE,
    FUNCTION_TYPE
} TypeName;

struct SymbolTable;

typedef struct Symbol {
    char *name;            // Name of the symbol
    TypeName type;         // Basic type
    int size;              // Size of the variable
    int offset;            // Offset in memory
    union {
        int int_val;       // For int constants
        float float_val;   // For float constants
        char char_val;     // For char constants
        int bool_val;      // For bool constants
        struct {           // For arrays
            int elem_size;
            int dim;
        } arr;
        struct {           // For pointers
            TypeName pointed_type;
        } ptr;
        struct {           // For functions
            struct SymbolTable *param_table;
            TypeName return_type;
        } func;
    } type_info;
    struct SymbolTable *nested_table;  // For nested scope or function parameters
    struct Symbol *next;               // For chaining in symbol table
} Symbol;

typedef struct SymbolTable {
    Symbol *symbols;            // Linked list of symbols
    char *name;                 // Name of the table (e.g., function name)
    int temp_count;             // Count of temporary variables
    struct SymbolTable *parent; // Parent symbol table
} SymbolTable;

// Create a new symbol table
SymbolTable* create_symbol_table(char *name, SymbolTable *parent);

// Insert a symbol into the symbol table
Symbol* insert_symbol(SymbolTable *table, char *name, TypeName type, int size);

// Update symbol's information
void update_symbol(Symbol *symbol, TypeName type, int size, int offset);

// Lookup a symbol in the table and parent tables
Symbol* lookup_symbol(SymbolTable *table, char *name);

// Generate a new temporary variable and insert it into the symbol table
Symbol* gentemp(SymbolTable *table, TypeName type, int size);

// Print the symbol table
void print_symbol_table(SymbolTable *table, FILE *fp);

// Get the size of a type
int get_type_size(TypeName type);

// Get string representation of a type
const char* get_type_string(TypeName type);

#endif /* SYMBOL_TABLE_H */
