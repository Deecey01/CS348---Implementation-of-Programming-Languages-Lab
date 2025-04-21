/* quad_array.c */
#include "quad_array.h"

// Global quad array
Quad **quad_array = NULL;
int quad_index = 0;
int quad_capacity = 0;

// Initialize the quad array
void init_quad_array() {
    quad_capacity = 1000;  // Initial capacity
    quad_array = (Quad**)malloc(quad_capacity * sizeof(Quad*));
    if (!quad_array) {
        fprintf(stderr, "Failed to allocate quad array\n");
        exit(1);
    }
    
    for (int i = 0; i < quad_capacity; i++) {
        quad_array[i] = NULL;  // Initialize all pointers to NULL
    }
    
    quad_index = 0;
    printf("Quad array initialized with capacity %d\n", quad_capacity);
}

// Emit a quad and add it to the quad array
int emit(OpCode op, Symbol *arg1, Symbol *arg2, Symbol *result) {
    // If quad array is not initialized, initialize it
    if (!quad_array) {
        init_quad_array();
    }
    
    // If the array is full, resize it
    if (quad_index >= quad_capacity) {
        quad_capacity *= 2;
        quad_array = (Quad**) realloc(quad_array, quad_capacity * sizeof(Quad*));
    }
    
    // Create a new quad
    Quad *q = (Quad*) malloc(sizeof(Quad));
    q->op = op;
    q->arg1 = arg1;
    q->arg2 = arg2;
    q->result = result;
    q->label = -1;  // No label yet
    q->next = NULL;
    
    // Add it to the array
    quad_array[quad_index] = q;
    
    return quad_index++;
}

// Get the quad at a specific index
Quad* get_quad(int index) {
    if (index < 0 || index >= quad_index)
        return NULL;
    return quad_array[index];
}

// Create a new list containing only i
QuadList* makelist(int i) {
    QuadList *list = (QuadList*) malloc(sizeof(QuadList));
    list->index = i;
    list->next = NULL;
    return list;
}

// Concatenate two lists and return the head of the concatenated list
QuadList* merge(QuadList *p1, QuadList *p2) {
    if (!p1) return p2;
    if (!p2) return p1;
    
    QuadList *temp = p1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = p2;
    
    return p1;
}

// Insert i as the target label for each quad in the list
void backpatch(QuadList *p, int i) {
    QuadList *temp = p;
    while (temp) {
        Quad *q = get_quad(temp->index);
        if (q) {
            q->label = i;
        }
        temp = temp->next;
    }
}

// Print the quad array
void print_quad_array(FILE *fp) {
    fprintf(fp, "\nQuad Array:\n");
    fprintf(fp, "----------------------------------------\n");
    fprintf(fp, "%-5s %-15s %-10s %-10s %-10s\n", 
            "Index", "Operation", "Arg1", "Arg2", "Result");
    fprintf(fp, "----------------------------------------\n");
    
    for (int i = 0; i < quad_index; i++) {
        Quad *q = quad_array[i];
        fprintf(fp, "%-5d %-15s ", i, get_op_string(q->op));
        
        // Print arg1
        if (q->arg1) {
            fprintf(fp, "%-10s ", q->arg1->name);
        } else {
            fprintf(fp, "%-10s ", "-");
        }
        
        // Print arg2
        if (q->arg2) {
            fprintf(fp, "%-10s ", q->arg2->name);
        } else {
            fprintf(fp, "%-10s ", "-");
        }
        
        // Print result
        if (q->result) {
            fprintf(fp, "%-10s", q->result->name);
        } else if (q->label != -1) {
            fprintf(fp, "L%-9d", q->label);
        } else {
            fprintf(fp, "%-10s", "-");
        }
        
        fprintf(fp, "\n");
    }
    fprintf(fp, "----------------------------------------\n");
}

// Get the string representation of an op code
const char* get_op_string(OpCode op) {
    switch (op) {
        case OP_ADD: return "ADD";
        case OP_SUB: return "SUB";
        case OP_MUL: return "MUL";
        case OP_DIV: return "DIV";
        case OP_MOD: return "MOD";
        case OP_LT: return "LT";
        case OP_GT: return "GT";
        case OP_LE: return "LE";
        case OP_GE: return "GE";
        case OP_EQ: return "EQ";
        case OP_NE: return "NE";
        case OP_AND: return "AND";
        case OP_OR: return "OR";
        case OP_BITAND: return "BITAND";
        case OP_BITOR: return "BITOR";
        case OP_BITXOR: return "BITXOR";
        case OP_SHL: return "SHL";
        case OP_SHR: return "SHR";
        case OP_UMINUS: return "UMINUS";
        case OP_UPLUS: return "UPLUS";
        case OP_NOT: return "NOT";
        case OP_DEREF: return "DEREF";
        case OP_ADDR: return "ADDR";
        case OP_ASSIGN: return "ASSIGN";
        case OP_COPY: return "COPY";
        case OP_ARRAY_ACCESS: return "ARRAY_ACCESS";
        case OP_ARRAY_ASSIGN: return "ARRAY_ASSIGN";
        case OP_GOTO: return "GOTO";
        case OP_IF_GOTO: return "IF_GOTO";
        case OP_IF_FALSE_GOTO: return "IF_FALSE_GOTO";
        case OP_PARAM: return "PARAM";
        case OP_CALL: return "CALL";
        case OP_RETURN: return "RETURN";
        case OP_CONV_INT_TO_FLOAT: return "INT_TO_FLOAT";
        case OP_CONV_FLOAT_TO_INT: return "FLOAT_TO_INT";
        case OP_CONV_CHAR_TO_INT: return "CHAR_TO_INT";
        case OP_CONV_INT_TO_CHAR: return "INT_TO_CHAR";
        case OP_LABEL: return "LABEL";
        default: return "UNKNOWN";
    }
}
