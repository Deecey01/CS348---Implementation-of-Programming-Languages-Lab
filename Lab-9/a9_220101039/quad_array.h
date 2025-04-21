/* quad_array.h */
#ifndef QUAD_ARRAY_H
#define QUAD_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

// Operation codes
typedef enum {
    // Binary operations
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
    OP_LT, OP_GT, OP_LE, OP_GE, OP_EQ, OP_NE,
    OP_AND, OP_OR, OP_BITAND, OP_BITOR, OP_BITXOR,
    OP_SHL, OP_SHR,
    
    // Unary operations
    OP_UMINUS, OP_UPLUS, OP_NOT, OP_DEREF, OP_ADDR,
    
    // Assignment and copy
    OP_ASSIGN, OP_COPY,
    
    // Indexed operations
    OP_ARRAY_ACCESS, OP_ARRAY_ASSIGN,
    
    // Jumps
    OP_GOTO, OP_IF_GOTO, OP_IF_FALSE_GOTO,
    
    // Function calls
    OP_PARAM, OP_CALL, OP_RETURN,
    
    // Type conversion
    OP_CONV_INT_TO_FLOAT, OP_CONV_FLOAT_TO_INT,
    OP_CONV_CHAR_TO_INT, OP_CONV_INT_TO_CHAR,
    
    // Special
    OP_LABEL
} OpCode;

// Quad structure
typedef struct Quad {
    OpCode op;        // Operation code
    Symbol *arg1;     // First argument
    Symbol *arg2;     // Second argument (optional)
    Symbol *result;   // Result
    int label;        // Label number (for jumps)
    struct Quad *next;// For chaining quads
} Quad;

// List of quads (for backpatching)
typedef struct QuadList {
    int index;               // Index of the quad in the array
    struct QuadList *next;   // Next quad in the list
} QuadList;

// Emit a quad and add it to the quad array
int emit(OpCode op, Symbol *arg1, Symbol *arg2, Symbol *result);

// Get the quad at a specific index
Quad* get_quad(int index);

// Create a new list containing only i
QuadList* makelist(int i);

// Concatenate two lists and return the head of the concatenated list
QuadList* merge(QuadList *p1, QuadList *p2);

// Insert i as the target label for each quad in the list
void backpatch(QuadList *p, int i);

// Print the quad array
void print_quad_array(FILE *fp);

// Get the string representation of an op code
const char* get_op_string(OpCode op);

// Global quad array
extern Quad **quad_array;
extern int quad_index;

#endif /* QUAD_ARRAY_H */

