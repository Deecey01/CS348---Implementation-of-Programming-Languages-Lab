%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    TOKEN_KEYWORD = 1,
    TOKEN_IDENTIFIER = 2,
    TOKEN_INTEGER_LITERAL = 3,
    TOKEN_FLOATING_POINT = 4,
    TOKEN_CHAR_LITERAL = 5,
    TOKEN_STRING_CONST = 6,
    TOKEN_OPERATOR_OR_PUNCTUATOR = 7,
    TOKEN_COMMENT_BLOCK = 8
} TokenCategory;

typedef struct SymbolNode {
    char lexeme[64];
    TokenCategory token_class;
    int source_line;
    char description[128];
} SymbolNode;

SymbolNode mc_symbol_registry[1500];
int registry_entry_count = 0;
int source_code_line_counter = 1;
FILE *lexical_analysis_output;
FILE *symbol_registry_output;
char timestamp_buffer[64];

void generate_timestamp() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(timestamp_buffer, sizeof(timestamp_buffer), 
             "/* MicroC Lexer - Generated: %Y-%m-%d %H:%M:%S */", t);
}

void register_symbol(char* token_text, TokenCategory category, int line_position) {
    /* First search if symbol already exists */
    for (int idx = 0; idx < registry_entry_count; idx++) {
        if (strcmp(mc_symbol_registry[idx].lexeme, token_text) == 0) {
            /* Token already present in registry */
            return;
        }
    }
    
    /* Create new symbol registry entry with additional metadata */
    strcpy(mc_symbol_registry[registry_entry_count].lexeme, token_text);
    mc_symbol_registry[registry_entry_count].token_class = category;
    mc_symbol_registry[registry_entry_count].source_line = line_position;
    
    switch(category) {
        case TOKEN_KEYWORD:
            strcpy(mc_symbol_registry[registry_entry_count].description, "Language keyword");
            break;
        case TOKEN_IDENTIFIER:
            strcpy(mc_symbol_registry[registry_entry_count].description, "User-defined identifier");
            break;
        case TOKEN_INTEGER_LITERAL:
            strcpy(mc_symbol_registry[registry_entry_count].description, "Integer numeric constant");
            break;
        case TOKEN_FLOATING_POINT:
            strcpy(mc_symbol_registry[registry_entry_count].description, "Floating-point numeric value");
            break;
        case TOKEN_CHAR_LITERAL:
            strcpy(mc_symbol_registry[registry_entry_count].description, "Character literal");
            break;
        case TOKEN_STRING_CONST:
            strcpy(mc_symbol_registry[registry_entry_count].description, "String constant");
            break;
        default:
            strcpy(mc_symbol_registry[registry_entry_count].description, "Other token");
    }
    
    registry_entry_count++;
}

void dump_symbol_registry() {
    fprintf(symbol_registry_output, "%s\n", timestamp_buffer);
    fprintf(symbol_registry_output, "=== MicroC Compiler Symbol Registry ===\n\n");
    fprintf(symbol_registry_output, "%-20s%-20s%-15s%-30s\n", 
           "Token", "Category", "Line", "Description");
    fprintf(symbol_registry_output, "%-20s%-20s%-15s%-30s\n", 
           "--------------------", "--------------------", "---------------", "------------------------------");
    
    for (int idx = 0; idx < registry_entry_count; idx++) {
        fprintf(symbol_registry_output, "%-20s%-20d%-15d%-30s\n", 
               mc_symbol_registry[idx].lexeme, 
               mc_symbol_registry[idx].token_class, 
               mc_symbol_registry[idx].source_line,
               mc_symbol_registry[idx].description);
    }
    
    /* Add additional statistics */
    fprintf(symbol_registry_output, "\n=== Registry Statistics ===\n");
    fprintf(symbol_registry_output, "Total symbols: %d\n", registry_entry_count);
    
    /* Count by category */
    int category_counts[9] = {0};
    for (int idx = 0; idx < registry_entry_count; idx++) {
        category_counts[mc_symbol_registry[idx].token_class]++;
    }
    
    fprintf(symbol_registry_output, "Keywords: %d\n", category_counts[TOKEN_KEYWORD]);
    fprintf(symbol_registry_output, "Identifiers: %d\n", category_counts[TOKEN_IDENTIFIER]);
    fprintf(symbol_registry_output, "Integer literals: %d\n", category_counts[TOKEN_INTEGER_LITERAL]);
    fprintf(symbol_registry_output, "Floating-point literals: %d\n", category_counts[TOKEN_FLOATING_POINT]);
    fprintf(symbol_registry_output, "Character literals: %d\n", category_counts[TOKEN_CHAR_LITERAL]);
    fprintf(symbol_registry_output, "String literals: %d\n", category_counts[TOKEN_STRING_CONST]);
}

%}

%option noyywrap

MC_KEYWORD (return|void|float|integer|char|for|const|while|bool|if|do|else|begin|end)

ID_START [a-zA-Z_]
ID_CONTINUE [a-zA-Z0-9_]
MC_IDENTIFIER {ID_START}{ID_CONTINUE}*

DECIMAL_DIGIT [0-9]
NON_ZERO_DIGIT [1-9]
MC_INTEGER {NON_ZERO_DIGIT}{DECIMAL_DIGIT}*|0

SIGN [+-]
DIGIT_SEQ {DECIMAL_DIGIT}+
EXP_PART [eE]{SIGN}?{DIGIT_SEQ}
FRACTION_CONST ({DIGIT_SEQ}?\.{DIGIT_SEQ})|({DIGIT_SEQ}\.)
MC_FLOAT ({FRACTION_CONST}{EXP_PART}?)|({DIGIT_SEQ}{EXP_PART})

ESCAPE_SEQ \\['"?\\abfnrtv]
C_CHAR [^'\\\n]|{ESCAPE_SEQ}
C_CHAR_SEQ {C_CHAR}+
MC_CHAR \'{C_CHAR_SEQ}\'

S_CHAR [^"\\\n]|{ESCAPE_SEQ}
S_CHAR_SEQ {S_CHAR}*
MC_STRING \"{S_CHAR_SEQ}\"

MC_PUNCTUATOR (\[|\]|\(|\)|\->|\+\+|--|&|\*|\+|-|!|\/|%|<<|>>|<|>|<=|>=|==|!=|\^|\||&&|\|\||[?:;=,])

SINGLE_LINE_COMMENT_START \/\/
SINGLE_LINE_COMMENT {SINGLE_LINE_COMMENT_START}.*

MULTI_LINE_COMMENT_START \/\*
MULTI_LINE_COMMENT_END \*\/
MULTI_LINE_COMMENT {MULTI_LINE_COMMENT_START}([^*]|\*+[^*/])*\*+\/

%%

{MC_KEYWORD} {
    return TOKEN_KEYWORD;
}

{MC_IDENTIFIER} {
    return TOKEN_IDENTIFIER;
}

{MC_INTEGER} {
    return TOKEN_INTEGER_LITERAL;
}

{MC_FLOAT} {
    return TOKEN_FLOATING_POINT;
}

{MC_CHAR} {
    return TOKEN_CHAR_LITERAL;
}

{MC_STRING} {
    return TOKEN_STRING_CONST;
}

{MC_PUNCTUATOR} {
    return TOKEN_OPERATOR_OR_PUNCTUATOR;
}

{SINGLE_LINE_COMMENT} {
}

{MULTI_LINE_COMMENT} {
    /* Count newlines in multi-line comments */
    for(int i = 0; i < yyleng; i++) {
        if(yytext[i] == '\n') source_code_line_counter++;
    }
}

\n { 
    source_code_line_counter++; 
}

[ \t\r] { 
}

. { 
    return -1;
    // fprintf(lexical_analysis_output, "<UNRECOGNIZED_TOKEN, %s, line %d>\n", yytext, source_code_line_counter); 
}

%%

int main(int argc, char *argv[]) {
    generate_timestamp();
    
    lexical_analysis_output = fopen("a6it_tokens.txt", "w");
    symbol_registry_output = fopen("a6it_symbol_table.txt", "w");
    
    if (!lexical_analysis_output || !symbol_registry_output) {
        fprintf(stderr, "ERROR: Failed to open output files for lexical analysis\n");
        return EXIT_FAILURE;
    }
    
    fprintf(lexical_analysis_output, "%s\n\n", timestamp_buffer);
    fprintf(lexical_analysis_output, "=== MicroC Lexical Analysis Results ===\n\n");
    
    fprintf(stderr, "MicroC Lexical Analyzer - Processing input...\n");
    
    int current_token;
    int token_count = 0;
    
    while ((current_token = yylex())) {
        token_count++;
        switch(current_token) {
            case TOKEN_KEYWORD:
                fprintf(lexical_analysis_output, "<KEYWORD, %s, line %d>\n", yytext, source_code_line_counter);
                register_symbol(yytext, TOKEN_KEYWORD, source_code_line_counter);
                break;
            case TOKEN_IDENTIFIER:
                fprintf(lexical_analysis_output, "<IDENTIFIER, %s, line %d>\n", yytext, source_code_line_counter);
                register_symbol(yytext, TOKEN_IDENTIFIER, source_code_line_counter);
                break;
            case TOKEN_INTEGER_LITERAL:
                fprintf(lexical_analysis_output, "<INTEGER_CONSTANT, %s, line %d>\n", yytext, source_code_line_counter);
                register_symbol(yytext, TOKEN_INTEGER_LITERAL, source_code_line_counter);
                break;
            case TOKEN_FLOATING_POINT:
                fprintf(lexical_analysis_output, "<FLOAT_CONSTANT, %s, line %d>\n", yytext, source_code_line_counter);
                register_symbol(yytext, TOKEN_FLOATING_POINT, source_code_line_counter);
                break;
            case TOKEN_CHAR_LITERAL:
                fprintf(lexical_analysis_output, "<CHARACTER_CONSTANT, %s, line %d>\n", yytext, source_code_line_counter);
                register_symbol(yytext, TOKEN_CHAR_LITERAL, source_code_line_counter);
                break;
            case TOKEN_STRING_CONST:
                fprintf(lexical_analysis_output, "<STRING_LITERAL, %s, line %d>\n", yytext, source_code_line_counter);
                register_symbol(yytext, TOKEN_STRING_CONST, source_code_line_counter);
                break;
            case TOKEN_OPERATOR_OR_PUNCTUATOR:
                fprintf(lexical_analysis_output, "<PUNCTUATOR, %s, line %d>\n", yytext, source_code_line_counter);
                break;
            default:
                fprintf(lexical_analysis_output, "<UNRECOGNIZED_TOKEN, %s, line %d>\n", yytext, source_code_line_counter);
                break;
        }
    }
    /* Generate full symbol registry */
    dump_symbol_registry();
    
    /* Add summary footer to token output */
    fprintf(lexical_analysis_output, "\nLexical analysis complete.\n");
    fprintf(lexical_analysis_output, "Total tokens processed: %d\n", token_count);
    fprintf(lexical_analysis_output, "Total lines scanned: %d\n", source_code_line_counter - 1);
    
    /* Clean up resources */
    fclose(lexical_analysis_output);
    fclose(symbol_registry_output);
    
    fprintf(stderr, "MicroC Lexical Analysis complete. Results written to output files.\n");
    
    return EXIT_SUCCESS;
}