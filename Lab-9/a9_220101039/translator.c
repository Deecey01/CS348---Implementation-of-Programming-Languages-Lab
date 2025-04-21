// translator.c
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "quad_array.h"
#include "type_check.h"

extern FILE *yyin;
extern int yyparse();
extern SymbolTable *global_table;
extern SymbolTable *current_table;
extern int line_no;

int main(int argc, char **argv) {
    FILE *output_file = NULL;
    
    printf("Starting compiler...\n");
    
    if (argc > 1) {
        printf("Parsing file: %s\n", argv[1]);
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
        
        // Create output file if specified
        if (argc > 2) {
            output_file = fopen(argv[2], "w");
            if (!output_file) {
                fprintf(stderr, "Cannot create output file %s\n", argv[2]);
                fclose(file);
                return 1;
            }
        }
    }

    // Initialize global symbol table
    printf("Initializing symbol table...\n");
    global_table = create_symbol_table("global", NULL);
    if (!global_table) {
        fprintf(stderr, "Failed to create global symbol table\n");
        return 1;
    }
    current_table = global_table;
    
    // Initialize quad array - THIS IS CRITICAL
    printf("Initializing quad array...\n");
    init_quad_array();

    // Parse the input
    int result = yyparse();
    
    if (result == 0) {
        printf("Parsing completed successfully.\n");
        if (output_file) {
            fprintf(output_file, "Parsing completed successfully.\n");
            
            // Print symbol table
            fprintf(output_file, "\n--- Symbol Table ---\n");
            print_symbol_table(global_table, output_file);
            
            // Print generated quads
            fprintf(output_file, "\n--- Generated Quads ---\n");
            print_quad_array(output_file);
        }
    } else {
        printf("Parsing failed.\n");
        if (output_file) {
            fprintf(output_file, "Parsing failed.\n");
        }
    }

    // Clean up
    if (yyin != stdin) {
        fclose(yyin);
    }
    if (output_file) {
        fclose(output_file);
    }
    
    return result;
}