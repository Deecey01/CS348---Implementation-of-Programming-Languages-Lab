#ifndef __PARSER_H
#define __PARSER_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define _VOID_SIZE 0
#define _FUNC_SIZE 0
#define _CHAR_SIZE 1
#define _INT_SIZE 4
#define _POINT_SIZE 4
#define _FLOAT_SIZE 8

extern char* yytext;
extern int yyparse();
//Class Declarations

class Symbol;
class Label; 
class SymbolTable;                                                                                                                                        
     
class quad;                                                                       
class quadArray;

class SymbolType;                                                                          
class Expression;                                                                         

typedef Symbol s;
typedef SymbolType symtyp;
typedef Expression* Exps;

// external global variables
// current Symbol Table
extern SymbolTable* ST;                
// Global Symbol Table                                                       
extern SymbolTable* globalST;      
// Parent of the current Symbol Table                                                           
extern SymbolTable* parST;                  
// latest encountered symbol                                                  
extern s* currSymbolPtr;                                                                  
extern quadArray Q;                                                                        
// count of nested tables                                                             
extern long long int table_count;                                                          
extern bool debug_on;                                                                      
extern string loop_name;             
// table to store the labels                                                      
extern vector<Label>label_table;          
extern string id;
// Label symbol used in new tables and GOTO statements
class Label                                                                                
{
public:
    int addr;                                                                          
    list<int> nextlist; 
    string name;   

    Label(string _name, int _addr = -1);                                               
};


// Structure of any element of the symbol table
class Symbol 
{                                                                                          
public:
    int size;                                                                          
    int offset; 
    string name;                                                                       
    SymbolType *type;                                                                                                                                         
    SymbolTable* nested;  // points to the symbol table of the function      
    // initial value if given                                                          
    string val;   // initial value if given  
    Symbol* update(SymbolType*);                                                               
      
    Symbol (string , string t="int", SymbolType* ptr = NULL, int width = 0);                                                             
};

//symbol type class
// stores symbol type and size of array if found
// also used for storing complex data types like arrays and pointers
class SymbolType 
{                                                                                           
public:
    string type;              
    // size of Array if found else 1 by default                                                          
    int width;          
    bool isArrayParam = false;                                                                
    SymbolType* arrtype;                                                               
    SymbolType(string , SymbolType* ptr = NULL, int width = 1);                         
};


// The actual Symbol Table

class SymbolTable 
{                                                                                           
public:
    string name;           
    //count of temps                                                            
    int count;                                                                          
    list<Symbol> table;                                                                    
    SymbolTable* parent;      // pointer to the parent symbol table                                                              
    
    SymbolTable (string name="NULL");                                                      
    s* lookupIdentifier (string); // search for a symbol in the symbol table, returns null if not found
    s* lookupDeclarator (string);   //  creates a new symbol table entry if not found                                                   
    void print();                                                                      
    void update();                                                                      
};

//  structure of quad element

class quad 
{                                                                                            
public:
    string res;                                                                         
    string op;                                                                           
    string arg1;                                                                         
    string arg2;                                                                           
    //constructors                  
    quad (string , string , string op = "=", string arg2 = "");         
    quad (string , int , string op = "=", string arg2 = "");                
    quad (string , float , string op = "=", string arg2 = "");  
    //for printing
    void print();	
    void print_generic_tac();                                                                       
    void print_if_jump_tac();                                                                        
};

// Definition of the quad array type
class quadArray 
{                                                                                            
public:
    vector<quad> Array;                                                                 
    void print();                                                                        
};

//  expression type
struct Expression {
    // pointer to the symbol table entry
    s* loc;                                                                                  
    string type;                                                                            
    list<int> truelist;  // the line number to go if the expression evaluates to true                                                                  
    list<int> falselist; // the line number to go if the expression evaluates to false      
    list<int> nextlist; // the line number to go to next       
};

//  array type
struct Array {
    //either ptr or array
    string atype;        
    // Location used to compute address of Array                                                                    
    s* loc;      
    // pointer to the symbol table entry                                                                            
    s* Array;                                                                               
    SymbolType* type;                                                                        
};

struct Statement {
    list<int> nextlist;                                                                     
};

//Type checking and conversion
string convertIntToString(int);                                                              
string convertFloatToString(float);                                                          
Exps convertIntToBool(Exps);                                                                 
int convertBoolToInt(Exps);  

// Emit is used to create a new quad element and add it to the quad array
//Overloaded emit functions
void emit(string , string , string arg1="", string arg2 = "");  
void emit(string , string , int, string arg2 = "");		  
void emit(string , string , float , string arg2 = "");   

//generates a temporary variable in a symbol table and return a pointer to it
s* gentemp (SymbolType* , string init = "");

//  Backpatching
// sets the result of all the GOTOs in the lists to the given label
void backpatch (list <int> , int );                                                           
list<int> makelist (int );                                                              
// merges two lists and returns the merged list     
list<int> merge (list<int> &l1, list <int> &l2);                                             

//  Other helper functions required for TAC generation
string printType(SymbolType *);                                                              
void generateSpaces(int);

Label* find_label(string name);                                

// type conversion
s* convertType(Symbol*, string);            
//calculate size of symbol type                                                    
int computeSize (SymbolType *);                                                             
// change current table
void changeTable (SymbolTable* );      

bool compareSymbolType(Symbol* &s1, Symbol* &s2);                                                 
bool compareSymbolType(SymbolType*, SymbolType*);                                          

int nextinstr();                                                                             

#endif