/* type_check.h */
#ifndef TYPE_CHECK_H
#define TYPE_CHECK_H

#include "symbol_table.h"
#include "quad_array.h"

// Type checking and conversion result structure
typedef struct {
    Symbol *symbol;    // Resulting symbol
    TypeName type;     // Resulting type
} TypeCheckResult;

// Check if two types are compatible
int are_types_compatible(TypeName type1, TypeName type2);

// Type check and potentially convert types
TypeCheckResult typecheck(Symbol *s1, Symbol *s2, SymbolTable *table);

// Convert a symbol from one type to another
Symbol* convert_type(Symbol *s, TypeName target_type, SymbolTable *table);

#endif /* TYPE_CHECK_H */

