/* symbol_table.c */
#include "symbol_table.h"

// Initialize a new symbol table
SymbolTable* create_symbol_table(char *name, SymbolTable *parent) {
    SymbolTable *table = (SymbolTable*) malloc(sizeof(SymbolTable));
    table->symbols = NULL;
    table->name = strdup(name);
    table->temp_count = 0;
    table->parent = parent;
    return table;
}

// Insert a symbol into the symbol table
Symbol* insert_symbol(SymbolTable *table, char *name, TypeName type, int size) {
    Symbol *sym = (Symbol*) malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->size = size;
    sym->offset = 0;  // Will be updated later
    sym->nested_table = NULL;
    sym->next = table->symbols;
    table->symbols = sym;
    return sym;
}

// Update symbol's information
void update_symbol(Symbol *symbol, TypeName type, int size, int offset) {
    symbol->type = type;
    symbol->size = size;
    symbol->offset = offset;
}

// Lookup a symbol in the table and parent tables
Symbol* lookup_symbol(SymbolTable *table, char *name) {
    if (!table) return NULL;
    
    // Search in current table
    Symbol *sym = table->symbols;
    while (sym) {
        if (strcmp(sym->name, name) == 0)
            return sym;
        sym = sym->next;
    }
    
    // If not found and has parent, search in parent table
    if (table->parent)
        return lookup_symbol(table->parent, name);
    
    return NULL;
}

// Generate a new temporary variable and insert it into the symbol table
Symbol* gentemp(SymbolTable *table, TypeName type, int size) {
    char temp_name[20];
    sprintf(temp_name, "t%d", table->temp_count++);
    return insert_symbol(table, temp_name, type, size);
}

// Print the symbol table
void print_symbol_table(SymbolTable *table, FILE *fp) {
    if (!table) return;
    
    fprintf(fp, "\nSymbol Table: %s\n", table->name);
    fprintf(fp, "----------------------------------------\n");
    fprintf(fp, "%-10s %-10s %-8s %-10s %-10s\n", 
            "Name", "Type", "Size", "Offset", "Initial Value");
    fprintf(fp, "----------------------------------------\n");
    
    Symbol *sym = table->symbols;
    while (sym) {
        fprintf(fp, "%-10s %-10s %-8d %-10d ", 
                sym->name, get_type_string(sym->type), sym->size, sym->offset);
        
        // Print initial value if available
        switch (sym->type) {
            case INT_TYPE:
                fprintf(fp, "%d", sym->type_info.int_val);
                break;
            case FLOAT_TYPE:
                fprintf(fp, "%f", sym->type_info.float_val);
                break;
            case CHAR_TYPE:
                fprintf(fp, "'%c'", sym->type_info.char_val);
                break;
            case BOOL_TYPE:
                fprintf(fp, "%s", sym->type_info.bool_val ? "true" : "false");
                break;
            default:
                fprintf(fp, "-");
        }
        fprintf(fp, "\n");
        
        // Print nested symbol table if exists
        if (sym->nested_table) {
            print_symbol_table(sym->nested_table, fp);
        }
        
        sym = sym->next;
    }
    fprintf(fp, "----------------------------------------\n");
}

// Get the size of a type (in bytes)
int get_type_size(TypeName type) {
    switch (type) {
        case VOID_TYPE:
            return 0;
        case CHAR_TYPE:
            return 1;
        case INT_TYPE:
        case BOOL_TYPE:
            return 4;
        case FLOAT_TYPE:
            return 8;
        case PTR_TYPE:
            return 4;  // All pointers have same size
        default:
            return 0;  // For array and function types
    }
}

// Get string representation of a type
const char* get_type_string(TypeName type) {
    switch (type) {
        case VOID_TYPE:
            return "void";
        case CHAR_TYPE:
            return "char";
        case INT_TYPE:
            return "int";
        case FLOAT_TYPE:
            return "float";
        case BOOL_TYPE:
            return "bool";
        case PTR_TYPE:
            return "ptr";
        case ARRAY_TYPE:
            return "array";
        case FUNCTION_TYPE:
            return "function";
        default:
            return "unknown";
    }
}
