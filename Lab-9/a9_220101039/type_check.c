/* type_check.c */
#include "type_check.h"

// Check if two types are compatible
int are_types_compatible(TypeName type1, TypeName type2) {
    // Same types are always compatible
    if (type1 == type2) {
        return 1;
    }
    
    // Check conversion possibilities
    if ((type1 == INT_TYPE && type2 == FLOAT_TYPE) ||
        (type1 == FLOAT_TYPE && type2 == INT_TYPE) ||
        (type1 == CHAR_TYPE && type2 == INT_TYPE) ||
        (type1 == INT_TYPE && type2 == CHAR_TYPE) ||
        (type1 == BOOL_TYPE && type2 == INT_TYPE) ||
        (type1 == INT_TYPE && type2 == BOOL_TYPE)) {
        return 1;
    }
    
    return 0;
}

// Type check and potentially convert types
TypeCheckResult typecheck(Symbol *s1, Symbol *s2, SymbolTable *table) {
    TypeCheckResult result;
    
    // If types are already the same, no need for conversion
    if (s1->type == s2->type) {
        result.symbol = s2;
        result.type = s2->type;
        return result;
    }
    
    // Check if types are compatible
    if (!are_types_compatible(s1->type, s2->type)) {
        fprintf(stderr, "Type error: Incompatible types for operation\n");
        // Return s2 as default but mark as error
        result.symbol = s2;
        result.type = s2->type;
        return result;
    }
    
    // Decide which conversion to apply
    if (s1->type == FLOAT_TYPE && s2->type == INT_TYPE) {
        // Convert s2 to float
        result.symbol = convert_type(s2, FLOAT_TYPE, table);
        result.type = FLOAT_TYPE;
    } else if (s1->type == INT_TYPE && s2->type == FLOAT_TYPE) {
        // Convert s1 to float
        result.symbol = s2;
        result.type = FLOAT_TYPE;
    } else if (s1->type == INT_TYPE && s2->type == CHAR_TYPE) {
        // Convert s2 to int
        result.symbol = convert_type(s2, INT_TYPE, table);
        result.type = INT_TYPE;
    } else if (s1->type == CHAR_TYPE && s2->type == INT_TYPE) {
        // Convert s1 to int
        result.symbol = s2;
        result.type = INT_TYPE;
    } else {
        // Default case
        result.symbol = s2;
        result.type = s2->type;
    }
    
    return result;
}

// Convert a symbol from one type to another
Symbol* convert_type(Symbol *s, TypeName target_type, SymbolTable *table) {
    // Generate a new temporary of the target type
    Symbol *temp = gentemp(table, target_type, get_type_size(target_type));
    
    // Emit appropriate conversion operation
    if (s->type == INT_TYPE && target_type == FLOAT_TYPE) {
        emit(OP_CONV_INT_TO_FLOAT, s, NULL, temp);
    } else if (s->type == FLOAT_TYPE && target_type == INT_TYPE) {
        emit(OP_CONV_FLOAT_TO_INT, s, NULL, temp);
    } else if (s->type == CHAR_TYPE && target_type == INT_TYPE) {
        emit(OP_CONV_CHAR_TO_INT, s, NULL, temp);
    } else if (s->type == INT_TYPE && target_type == CHAR_TYPE) {
        emit(OP_CONV_INT_TO_CHAR, s, NULL, temp);
    } else {
        // No conversion needed, just copy
        emit(OP_COPY, s, NULL, temp);
    }
    
    return temp;
}
