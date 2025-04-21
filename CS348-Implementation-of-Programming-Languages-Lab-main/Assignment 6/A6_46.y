%{
	#include "A6_46_translator.h"
	void yyerror(const char*);
	extern "C" int yylex(void);
	using namespace std;
	symbol* temp_s;
%}


%union{
	int _int_value;   //to hold the value of integer constant
	char _char_value; //to hold the value of character constant
	float _float_value; //to hold the value of floating constant
	string* _string_literal; // to hold the value of string literal
	declarator _declarator;   //to define the declarators
	identifier _identifier;    // to define the type for Identifier
	argList _paramList; //to define the argumnets list
	int _instruction;  // to defin the type used by M->(epsilon)
	expression _expression;   // to define the structure of expression
	list *_nextlist;  //to define the _nextlist type for N->(epsilon)
}

//All tokens
%token ELSE FOR  IF  INT RETURN VOID
%token GREATER_THAN_EQUAL LESS_THAN_EQUAL NOT_EQUAL EQUALITY OR AND 
%token WHITESPACE COMMENT

%token <_int_value> INTEGER_CONSTANT
%token <_string_literal> STRING_LITERAL

// Non-terminals of type expression (denoting expressions)
%type <_expression>
	primary_expression 
	postfix_expression 
	unary_expression 
	multiplicative_expression
	additive_expression 
	relational_expression 
	equality_expression 
	logical_AND_expression 
	logical_OR_expression
	conditional_expression 
	assignment_expression 
	expression
	expression_statement 
	expression_opt 
	declarator 
	direct_declarator 
	initializer 
	declaration 
	init_declarator
	condition
    and_helper
    or_helper
    if_helper

%type <_nextlist>
	block_item_list 
	block_item statement 
	compound_statement 
	selection_statement
	iteration_statement 
	jump_statement 
	block_item_list_opt

%type <_paramList> argument_expression_list argument_expression_list_opt
%token <_identifier> IDENTIFIER
%type <_declarator> type_specifier  pointer pointer_opt 

// Auxiliary non-terminal M of type instr to help in backpatching
%type <_instruction> M

// Auxiliary non-terminal N of type stmt to help in control flow statements
%type <_nextlist>    N

%type <_char_value> unary_operator

%start translation_unit

// precendence and association
%left '+' '-'
%left '*' '/' '%'
%nonassoc UNARY
%nonassoc IF_CONFLICT
%nonassoc ELSE

%%
M:
{
	$$ = nextInstruction;
};

N:
{
	$$ = makelist(nextInstruction);
	globalQuadArray.emit(Q_GOTO, -1);
};

/*Expressions*/
primary_expression: IDENTIFIER {
		//Check whether its a function
		symbol * check_func = globalSymbolTable->search(*$1.name);
		
		if(check_func == NULL)
		{
			$$.symTPtr  =  currentSymbolTable->globalLookup(*$1.name);
			if($$.symTPtr->type != NULL && $$.symTPtr->type->type == tp_arr)
			{
				//If array
				$$.arr = $$.symTPtr;
				$$.type = $$.arr->type;
				$$.poss_array = $$.arr;
			}
			else
			{
				// If not an array
				$$.type = $$.symTPtr->type;
				$$.arr = NULL;
				$$.isPointer = false;
			}
		}
		else
		{
				$$.symTPtr = check_func;
				if($$.symTPtr->type != NULL && $$.symTPtr->type->type == tp_arr)
				{
					//If array
					$$.arr = $$.symTPtr;
					$$.type = $$.arr->type;
					$$.poss_array = $$.arr;
				}
				else
				{
					// If not an array
					$$.type = $$.symTPtr->type;
					$$.arr = NULL;
					$$.isPointer = false;
				}

		}
	} |
	INTEGER_CONSTANT {
		// Declare and initialize the value of the temporary variable with the integer
		$$.symTPtr  = currentSymbolTable->gentemp(new symbolType(tp_int));
		$$.type = $$.symTPtr->type;
		$$.symTPtr->_init_val._INT_INITVAL = $1;
		$$.symTPtr->isInitialized = true;
		$$.arr = NULL;
		globalQuadArray.emit(Q_ASSIGN, $1, $$.symTPtr->name);
	} |
	STRING_LITERAL {
		_string_labels.push_back(*$1);
		$$.symTPtr = NULL;
		$$.isString = true;
		$$.ind_str = _string_labels.size()-1;
		$$.arr = NULL;
		$$.isPointer = false;
	} |
	'(' expression ')' {
		$$ = $2;
	};

postfix_expression :    primary_expression {
		$$ = $1;
	} |
	postfix_expression '[' expression ']' {
		//Explanation of Array handling

		$$.symTPtr = currentSymbolTable->gentemp(new symbolType(tp_int));
		char temp[10];
		sprintf(temp,"%d",$1.type->next->sizeOfType());
		globalQuadArray.emit(Q_MULT,$3.symTPtr->name,temp,$$.symTPtr->name);
		// the new size will be calculated and the temporary variable storing the size will be passed on a $$.symTPtr
		//$$.arr <= base pointer
		$$.arr = $1.arr;
		//$$.type <= type(arr)
		$$.type = $1.type->next;
		$$.poss_array = NULL;
		//$$.arr->type has the full type of the arr which will be used for size calculations
	} |
	postfix_expression '(' argument_expression_list_opt ')' {
		//Explanation of Function Handling
		if(!$1.isPointer && !$1.isString && ($1.type) && ($1.type->type==tp_void))
		{
			
		}
		else
			$$.symTPtr = currentSymbolTable->gentemp(CopyType($1.type));
		//temporary is created
		char str[10];
		if($3.args == NULL)
		{
			
			//No function Parameters
			sprintf(str,"0");
			
			if($1.type->type!=tp_void)
				globalQuadArray.emit(Q_CALL,$1.symTPtr->name,str,$$.symTPtr->name);
			else
				globalQuadArray.emitG(Q_CALL,$1.symTPtr->name,str);
		}
		else
		{
			if((*$3.args)[0]->isString)
			{
				str[0] = '_';
				
				sprintf(str+1,"%d",(*$3.args)[0]->ind_str);
				globalQuadArray.emit(Q_PARAM,str);
				
				globalQuadArray.emit(Q_CALL,$1.symTPtr->name,"1",$$.symTPtr->name);
			}
			else
			{
				for(int i=0;i<$3.args->size();i++)
				{
					// To print the parameters
					
					if((*$3.args)[i]->poss_array != NULL && $1.symTPtr->name != "printInt")
						globalQuadArray.emit(Q_PARAM,(*$3.args)[i]->poss_array->name);
					else
						globalQuadArray.emit(Q_PARAM,(*$3.args)[i]->symTPtr->name);

				}
				sprintf(str,"%ld",$3.args->size());
				//printf("function %s-->%d\n",$1.symTPtr->name.c_str(),$1.type->type);
				if($1.type->type!=tp_void) {
					globalQuadArray.emit(Q_CALL,$1.symTPtr->name,str,$$.symTPtr->name);
					
				}
				else
					globalQuadArray.emitG(Q_CALL,$1.symTPtr->name,str);
			}
		}

		$$.arr = NULL;
		$$.type = $$.symTPtr->type;
	};

argument_expression_list:       assignment_expression {
		$$.args = new vector<expression*>;
		
		expression * tex = new expression($1);
		
		$$.args->push_back(tex);
		//printf("name2-->%s\n",tex->symTPtr->name.c_str());
	}|
	argument_expression_list ',' assignment_expression {
		expression * tex = new expression($3);
		$$.args->push_back(tex);
	};

argument_expression_list_opt:   argument_expression_list {
	$$ = $1;
	}|
	/*epsilon*/ {
		$$.args = NULL;		
	};

unary_expression:   postfix_expression {
		$$ = $1;
	}|
	unary_operator unary_expression
	{
		symbolType * temp_type;
		switch($1)
		{
			case '&':
				//create a temporary type store the type
				temp_type = new symbolType(tp_ptr,1,$2.type);
				
				$$.symTPtr = currentSymbolTable->gentemp(CopyType(temp_type));
				$$.type = $$.symTPtr->type;
				
				globalQuadArray.emit(Q_ADDR,$2.symTPtr->name,$$.symTPtr->name);
				$$.arr = NULL;
				break;
			case '*':
				$$.isPointer = true;
				$$.type = $2.symTPtr->type->next;
				$$.symTPtr = $2.symTPtr;
				
				$$.arr = NULL;
				break;
			case '+':
				$$.symTPtr = currentSymbolTable->gentemp(CopyType($2.type));
				$$.type = $$.symTPtr->type;
				
				globalQuadArray.emit(Q_ASSIGN,$2.symTPtr->name,$$.symTPtr->name);
				break;
			case '-':
				$$.symTPtr = currentSymbolTable->gentemp(CopyType($2.type));
				$$.type = $$.symTPtr->type;
				
				globalQuadArray.emit(Q_UNARY_MINUS,$2.symTPtr->name,$$.symTPtr->name);
				break;
			case '!':
				$$.symTPtr = currentSymbolTable->gentemp(CopyType($2.type));
				$$.type = $$.symTPtr->type;
				
				$$.truelist = $2.falselist;
				$$.falselist = $2.truelist;
				break;
			default:
				break;
		}
	};

unary_operator  :   '&' {
		$$ = '&';
	}|
	'*' {
		$$ = '*';
	}|
	'+' {
		$$ = '+';
	}|
	'-' {
		$$ = '-';
	}|
	'!' {
		$$ = '!';
	};

multiplicative_expression:      unary_expression {
		$$ = $1;
		if($1.isPointer)
		{
			$$.symTPtr = currentSymbolTable->gentemp($1.type);
			globalQuadArray.emit(Q_RDEREF, $1.symTPtr->name, $$.symTPtr->name);
		}if($1.arr != NULL)
		{
			$$.symTPtr = currentSymbolTable->gentemp($1.type);
			globalQuadArray.emit(Q_RINDEX,$1.arr->name,$1.symTPtr->name,$$.symTPtr->name);
		}
	}|
	multiplicative_expression '*' unary_expression {
		if($3.isPointer)
		{
			temp_s = currentSymbolTable->gentemp($3.type);
			globalQuadArray.emit(Q_RDEREF, $3.symTPtr->name, temp_s->name);
		}
		else if($3.arr != NULL)
		{
			temp_s = currentSymbolTable->gentemp($3.type);
			globalQuadArray.emit(Q_RINDEX,$3.arr->name,$3.symTPtr->name,temp_s->name);
		}
		else
		{
			temp_s = $3.symTPtr;
		}
		$$.symTPtr = currentSymbolTable->gentemp($1.type);
		$$.type = $$.symTPtr->type;
		
		globalQuadArray.emit(Q_MULT,$1.symTPtr->name,temp_s->name,$$.symTPtr->name);
	}|
	multiplicative_expression '/' unary_expression {
		if($3.isPointer)
		{
			temp_s = currentSymbolTable->gentemp($3.type);
			globalQuadArray.emit(Q_RDEREF, $3.symTPtr->name, temp_s->name);
		}
		else if($3.arr != NULL)
		{
			temp_s = currentSymbolTable->gentemp($3.type);
			globalQuadArray.emit(Q_RINDEX,$3.arr->name,$3.symTPtr->name,temp_s->name);
		}
		else
		{
			temp_s = $3.symTPtr;
		}
		typecheck(&$1,&$3);
		$$.symTPtr = currentSymbolTable->gentemp($1.type);
		$$.type = $$.symTPtr->type;
		
		globalQuadArray.emit(Q_DIVIDE,$1.symTPtr->name,temp_s->name,$$.symTPtr->name);
	}|
	multiplicative_expression '%' unary_expression{
		if($3.isPointer)
		{
			temp_s = currentSymbolTable->gentemp($3.type);
			globalQuadArray.emit(Q_RDEREF, $3.symTPtr->name, temp_s->name);
		}
		else if($3.arr != NULL)
		{
			temp_s = currentSymbolTable->gentemp($3.type);
			globalQuadArray.emit(Q_RINDEX,$3.arr->name,$3.symTPtr->name,temp_s->name);
		}
		else
		{
			temp_s = $3.symTPtr;
		}
		typecheck(&$1,&$3);
		
		$$.symTPtr = currentSymbolTable->gentemp($1.type);
		$$.type = $$.symTPtr->type;
		
		globalQuadArray.emit(Q_MODULO,$1.symTPtr->name,temp_s->name,$$.symTPtr->name);
	};

additive_expression :   multiplicative_expression {
		$$ = $1;
	}|
	additive_expression '+' multiplicative_expression {
		typecheck(&$1,&$3);
		
		$$.symTPtr = currentSymbolTable->gentemp($1.type);
		$$.type = $$.symTPtr->type;
		
		globalQuadArray.emit(Q_PLUS,$1.symTPtr->name,$3.symTPtr->name,$$.symTPtr->name);
	}|
	additive_expression '-' multiplicative_expression {
		typecheck(&$1,&$3);
		
		$$.symTPtr = currentSymbolTable->gentemp($1.type);
		$$.type = $$.symTPtr->type;
		
		globalQuadArray.emit(Q_MINUS,$1.symTPtr->name,$3.symTPtr->name,$$.symTPtr->name);
	};


relational_expression:  additive_expression {
		$$ = $1;
	}|
	relational_expression '<' additive_expression {
		typecheck(&$1,&$3);
		$$.type = new symbolType(tp_bool);
		$$.truelist = makelist(nextInstruction);
		$$.falselist = makelist(nextInstruction+1);
		globalQuadArray.emit(Q_IF_LESS,$1.symTPtr->name,$3.symTPtr->name,"-1");
		globalQuadArray.emit(Q_GOTO,"-1");
	}|
	relational_expression '>' additive_expression {
		typecheck(&$1,&$3);
		$$.type = new symbolType(tp_bool);
		$$.truelist = makelist(nextInstruction);
		$$.falselist = makelist(nextInstruction+1);
		globalQuadArray.emit(Q_IF_GREATER,$1.symTPtr->name,$3.symTPtr->name,"-1");
		globalQuadArray.emit(Q_GOTO,"-1");
	}|
	relational_expression LESS_THAN_EQUAL additive_expression {
		typecheck(&$1,&$3);
		$$.type = new symbolType(tp_bool);
		
		$$.truelist = makelist(nextInstruction);
		
		$$.falselist = makelist(nextInstruction+1);
		globalQuadArray.emit(Q_IF_LESS_OR_EQUAL,$1.symTPtr->name,$3.symTPtr->name,"-1");
		globalQuadArray.emit(Q_GOTO,"-1");
	}|
	relational_expression GREATER_THAN_EQUAL additive_expression {
		typecheck(&$1,&$3);

		$$.type = new symbolType(tp_bool);
		$$.truelist = makelist(nextInstruction);
		
		$$.falselist = makelist(nextInstruction+1);
		globalQuadArray.emit(Q_IF_GREATER_OR_EQUAL,$1.symTPtr->name,$3.symTPtr->name,"-1");
		globalQuadArray.emit(Q_GOTO,"-1");
	};

equality_expression:    relational_expression {
		$$ = $1;
	}|
	equality_expression EQUALITY relational_expression {
		typecheck(&$1,&$3);
		$$.type = new symbolType(tp_bool);
		$$.truelist = makelist(nextInstruction);
		
		$$.falselist = makelist(nextInstruction+1);
		globalQuadArray.emit(Q_IF_EQUAL,$1.symTPtr->name,$3.symTPtr->name,"-1");
		globalQuadArray.emit(Q_GOTO,"-1");
		
	}|
	equality_expression NOT_EQUAL relational_expression {
		typecheck(&$1,&$3);
		$$.type = new symbolType(tp_bool);
		
		$$.truelist = makelist(nextInstruction);
		$$.falselist = makelist(nextInstruction+1);

		globalQuadArray.emit(Q_IF_NOT_EQUAL,$1.symTPtr->name,$3.symTPtr->name,"-1");
		globalQuadArray.emit(Q_GOTO,"-1");
	};

and_helper: logical_AND_expression AND
    {
		if($1.type->type != tp_bool)
			CONV2BOOL(&$1);
        $$ = $1;
    }


logical_AND_expression:     equality_expression {
		$$ = $1;
	}|
	and_helper M equality_expression {
		if($3.type->type != tp_bool)
			CONV2BOOL(&$3);
		backpatch($1.truelist,$2);
		$$.type = new symbolType(tp_bool);
		
		$$.falselist = merge($1.falselist,$3.falselist);
		$$.truelist = $3.truelist;
	};

or_helper: logical_OR_expression OR
    {
        if($1.type->type != tp_bool)
			CONV2BOOL(&$1);
        $$ = $1;
    }

logical_OR_expression:      logical_AND_expression {
		$$ = $1;
	}|
	or_helper M logical_AND_expression   {
		if($3.type->type != tp_bool)
			CONV2BOOL(&$3);
		backpatch($1.falselist,$2);
		$$.type = new symbolType(tp_bool);
		
		$$.truelist = merge($1.truelist,$3.truelist);
		$$.falselist = $3.falselist;
	};


condition: logical_OR_expression '?' 
    {
        if($1.type->type != tp_bool)
			CONV2BOOL(&$1);
        $$ = $1;
    }

/*It is assumed that type of expression and conditional expression are same*/
conditional_expression:         logical_OR_expression {
		$$ = $1;
	}|
	condition M expression N ':' M conditional_expression {
		$$.symTPtr = currentSymbolTable->gentemp($3.type);
		$$.type = $$.symTPtr->type;
		globalQuadArray.emit(Q_ASSIGN,$7.symTPtr->name,$$.symTPtr->name);
		list* TEMP_LIST = makelist(nextInstruction);
		globalQuadArray.emit(Q_GOTO,"-1");
		
		backpatch($4,nextInstruction);
		globalQuadArray.emit(Q_ASSIGN,$3.symTPtr->name,$$.symTPtr->name);
		TEMP_LIST = merge(TEMP_LIST,makelist(nextInstruction));
		globalQuadArray.emit(Q_GOTO,"-1");
		backpatch($1.truelist,$2);
		backpatch($1.falselist,$6);
		backpatch(TEMP_LIST,nextInstruction);
	};


assignment_expression:      conditional_expression {
		$$ = $1;
	}|
	unary_expression '=' assignment_expression {
		if($1.isPointer)
		{
			
			globalQuadArray.emit(Q_LDEREF,$3.symTPtr->name,$1.symTPtr->name);
		}
		typecheck(&$1,&$3,true);
		if($1.arr != NULL)
		{
			
			globalQuadArray.emit(Q_LINDEX,$1.symTPtr->name,$3.symTPtr->name,$1.arr->name);
		}
		else if(!$1.isPointer)
			globalQuadArray.emit(Q_ASSIGN,$3.symTPtr->name,$1.symTPtr->name);
		$$.symTPtr = $3.symTPtr;
		$$.type = $$.symTPtr->type;
	};

expression :    assignment_expression {
		$$ = $1;
	};

/*Declarations*/

declaration:     type_specifier init_declarator';' {
		if($2.symTPtr != NULL && $2.type != NULL && $2.type->type == tp_func)
		{
			/*Delete currentSymbolTable*/
			
			currentSymbolTable = new symbolTable();
		}
	};


init_declarator:    declarator {
		/*Nothing to be done here*/
		if($1.type != NULL && $1.type->type == tp_func)
		{
			$$ = $1;
		}
	}|
	declarator '=' initializer {
		//initializations of declarators
		if($3.type!=NULL)
		{
			if($3.type->type==tp_int)
			{
				$1.symTPtr->_init_val._INT_INITVAL= $3.symTPtr->_init_val._INT_INITVAL;
				$1.symTPtr->isInitialized = true;
				
				symbol *temp_ver=currentSymbolTable->search($1.symTPtr->name);
				if(temp_ver!=NULL)
				{
				temp_ver->_init_val._INT_INITVAL= $3.symTPtr->_init_val._INT_INITVAL;
				
				temp_ver->isInitialized = true;
				}
			}
		}
		globalQuadArray.emit(Q_ASSIGN,$3.symTPtr->name,$1.symTPtr->name);
	};


type_specifier:     VOID {
		globalType = new symbolType(tp_void);
	}|
	INT {
		globalType = new symbolType(tp_int);
	};



declarator :    pointer_opt direct_declarator {
		if($1.type == NULL)
		{
			/*--------------*/
			
		}
		else
		{
			if($2.symTPtr->type->type != tp_ptr)
			{
				symbolType * test = $1.type;

				
				while(test->next != NULL)
				{
					test = test->next;
				}
				test->next = $2.symTPtr->type;
				$2.symTPtr->type = $1.type;
			}
		}

		if($2.type != NULL && $2.type->type == tp_func)
		{
			$$ = $2;
		}
		else
		{
			//its not a function
			$2.symTPtr->width = $2.symTPtr->type->sizeOfType();
			
			$2.symTPtr->offset = currentSymbolTable->offset;
			currentSymbolTable->offset += $2.symTPtr->width;
			
			$$ = $2;
			$$.type = $$.symTPtr->type;
		}
	};

pointer_opt:    pointer {
		$$ = $1;
	}|
	/*epsilon*/ {
			$$.type = NULL;
	};

direct_declarator:      IDENTIFIER {
		$$.symTPtr = currentSymbolTable->lookup(*$1.name);

		if($$.symTPtr->var_type == "")
		{
			//Type initialization
			$$.symTPtr->var_type = "local";
			$$.symTPtr->type = new symbolType(globalType->type);
		}
		$$.type = $$.symTPtr->type;
	}|
	direct_declarator '[' INTEGER_CONSTANT ']' {
		
		//add the type of array to list
		$1.type = new symbolType(tp_arr,$3,$1.type);
	
		$$ = $1;
		$$.symTPtr->type = $$.type;
	}|
	direct_declarator '(' parameter_list_opt ')' {
		int params_no=currentSymbolTable->emptyArgList;
		currentSymbolTable->emptyArgList=0;
		int dec_params=0;
		
		int over_params=params_no;
		for(int i=currentSymbolTable->symbolTabList.size()-1;i>=0;i--)
		{
		}
		for(int i=currentSymbolTable->symbolTabList.size()-1;i>=0;i--)
		{
			string detect=currentSymbolTable->symbolTabList[i]->name;
			if(over_params==0)
			{
				break;
			}
			if(detect.size()==4)
			{
				if(detect[0]=='t')
				{
					
					if('0'<=detect[1]&&detect[1]<='9')
					{
						if('0'<=detect[2]&&detect[2]<='9')
						{
							if('0'<=detect[3]&&detect[3]<='9')
								dec_params++;
						}
					}
				}
			}
			else
				over_params--;
		}
		params_no+=dec_params;
		int temp_i=currentSymbolTable->symbolTabList.size()-params_no;
		symbol * new_func = globalSymbolTable->search(currentSymbolTable->symbolTabList[temp_i-1]->name);
	
		if(new_func == NULL)
		{
			new_func = globalSymbolTable->lookup(currentSymbolTable->symbolTabList[temp_i-1]->name);
			$$.symTPtr = currentSymbolTable->symbolTabList[temp_i-1];
			
			for(int i=0;i<(temp_i-1);i++)
			{
				currentSymbolTable->symbolTabList[i]->isValid=false;
				if(currentSymbolTable->symbolTabList[i]->var_type=="local"||currentSymbolTable->symbolTabList[i]->var_type=="temp")
				{
					symbol *glob_var=globalSymbolTable->search(currentSymbolTable->symbolTabList[i]->name);
					if(glob_var==NULL)
					{
						
						glob_var=globalSymbolTable->lookup(currentSymbolTable->symbolTabList[i]->name);
						int t_size=currentSymbolTable->symbolTabList[i]->type->sizeOfType();
						glob_var->offset=globalSymbolTable->offset;
						glob_var->width=t_size;
						globalSymbolTable->offset+=t_size;
					
						glob_var->nested=globalSymbolTable;
						glob_var->var_type=currentSymbolTable->symbolTabList[i]->var_type;
						glob_var->type=currentSymbolTable->symbolTabList[i]->type;
						if(currentSymbolTable->symbolTabList[i]->isInitialized)
						{
							glob_var->isInitialized=currentSymbolTable->symbolTabList[i]->isInitialized;
							glob_var->_init_val=currentSymbolTable->symbolTabList[i]->_init_val;
						}

					}
				}
			}
			if(new_func->var_type == "")
			{
				// Declaration of the function for the first time
				new_func->type = CopyType(currentSymbolTable->symbolTabList[temp_i-1]->type);

				new_func->var_type = "func";
				new_func->isInitialized = false;
				new_func->nested = currentSymbolTable;
				
				currentSymbolTable->name = currentSymbolTable->symbolTabList[temp_i-1]->name;
			
				currentSymbolTable->symbolTabList[temp_i-1]->name = "retVal";
				currentSymbolTable->symbolTabList[temp_i-1]->var_type = "return";
				currentSymbolTable->symbolTabList[temp_i-1]->width = currentSymbolTable->symbolTabList[temp_i-1]->type->sizeOfType();
				currentSymbolTable->symbolTabList[temp_i-1]->offset = 0;
				currentSymbolTable->offset = 16;
				int count=0;
				for(int i=(currentSymbolTable->symbolTabList.size())-params_no;i<currentSymbolTable->symbolTabList.size();i++)
				{
					currentSymbolTable->symbolTabList[i]->var_type = "param";
					currentSymbolTable->symbolTabList[i]->offset = count- currentSymbolTable->symbolTabList[i]->width;
					count=count-currentSymbolTable->symbolTabList[i]->width;
				}
			}
		}
		else
		{
			currentSymbolTable = new_func->nested;
			
		}
		currentSymbolTable->initQuad = nextInstruction;
		$$.symTPtr = new_func;
		$$.type = new symbolType(tp_func);
	};


pointer:    '*' {
		$$.type = new symbolType(tp_ptr);
	}

parameter_list_opt:
	parameter_list{}|
	;


parameter_list:     parameter_declaration {
		/*---------*/
		(currentSymbolTable->emptyArgList)++;
	}|
	parameter_list ',' parameter_declaration {
		/*------------*/
		(currentSymbolTable->emptyArgList)++;
	};

parameter_declaration:  type_specifier declarator {
		/*The parameter is already added to the current Symbol Table*/
	}|
	type_specifier {};


initializer:        assignment_expression {
		$$ = $1;
	};

/*Statements*/
statement:      compound_statement {
		$$ = $1;
	}|
	expression_statement {
		$$ = NULL;
	}|
	selection_statement {
		$$ = $1;
	}|
	iteration_statement {
		$$ = $1;
	}|
	jump_statement {
		$$ = $1;
	};


compound_statement:    '{' block_item_list_opt '}' {
		$$ = $2;
	};

block_item_list_opt:    block_item_list {
			$$ = $1;
		}|
	/*Epslion*/ {
		$$ = NULL;	
	};

block_item_list:     block_item {
		$$ = $1;
	}|
	block_item_list M block_item {
		backpatch($1,$2);
		$$ = $3;
	};

block_item:    declaration {
		$$ = NULL;
	}|
	statement {
		$$ = $1;
	};

expression_statement:   expression_opt ';'{
		$$ = $1;
	};

expression_opt:     expression {
		$$ = $1;
	}|
	/*Epslion*/ {
		/*Initialize Expression to NULL*/
		$$.symTPtr = NULL;
	};

if_helper: IF '(' expression
    {
        CONV2BOOL(&$3);
        $$ = $3;   
    }

selection_statement:    if_helper ')' M statement N ELSE M statement {
		/*N1 is used for falselist of expression, M1 is used for truelist of expression, N2 is used to prevent fall through, M2 is used for falselist of expression*/
		$4 = merge($4,$5);
		backpatch($1.truelist,$3);
		backpatch($1.falselist,$7);
		$$ = merge($4,$8);
	}|
	if_helper ')' M statement %prec IF_CONFLICT{
		/*N is used for the falselist of expression to skip the block and M is used for truelist of expression*/

		backpatch($1.truelist,$3);
		$$ = merge($4,$1.falselist);
	};

iteration_statement:    FOR '(' expression_opt ';' M expression_opt N ';' M expression_opt N ')' M statement {
		/*M1 is used for coming back to check the epression at every iteration. N1 is used  for generating the goto which will be used for exit conditions. M2 is used for _nextlist of statement and N2 is used for jump to check the expression and M3 is used for the truelist of expression*/
		backpatch($11,$5);          /*N2._nextlist to M1._instruction*/
		backpatch($14,$9);          /*S._nextlist to M2._instruction*/
		globalQuadArray.emit(Q_GOTO,$9);
		
		backpatch($7,nextInstruction);    /*N1._nextlist to nextInstruction*/
		CONV2BOOL(&$6);
		
		backpatch($6.truelist,$13);
		$$ = $6.falselist;
	};

jump_statement:     RETURN expression_opt ';' {
		if($2.symTPtr == NULL)
			globalQuadArray.emit(Q_RETURN);
		else
		{
			globalQuadArray.emit(Q_RETURN,$2.symTPtr->name);
		}
		$$=NULL;
	};

/*External Definitions*/
translation_unit:               external_declaration   |
	translation_unit external_declaration;

external_declaration:       function_definition  |
	declaration      {
		for(int i=0;i<currentSymbolTable->symbolTabList.size();i++)
		{
			if(currentSymbolTable->symbolTabList[i]->nested==NULL)
			{
				
				if(currentSymbolTable->symbolTabList[i]->var_type=="local"||currentSymbolTable->symbolTabList[i]->var_type=="temp")
				{
					symbol *glob_var=globalSymbolTable->search(currentSymbolTable->symbolTabList[i]->name);
					if(glob_var==NULL)
					{
						glob_var=globalSymbolTable->lookup(currentSymbolTable->symbolTabList[i]->name);
						int t_size=currentSymbolTable->symbolTabList[i]->type->sizeOfType();
						glob_var->offset=globalSymbolTable->offset;
						
						glob_var->width=t_size;
						globalSymbolTable->offset+=t_size;
						glob_var->nested=globalSymbolTable;
						
						glob_var->var_type=currentSymbolTable->symbolTabList[i]->var_type;
						glob_var->type=currentSymbolTable->symbolTabList[i]->type;
						if(currentSymbolTable->symbolTabList[i]->isInitialized)
						{
							glob_var->isInitialized=currentSymbolTable->symbolTabList[i]->isInitialized;
							glob_var->_init_val=currentSymbolTable->symbolTabList[i]->_init_val;
						}
					}
				}
			}
		}
		currentSymbolTable = new symbolTable();
	};

function_definition:    type_specifier declarator compound_statement {
		symbol * func = globalSymbolTable->lookup($2.symTPtr->name);
		func->nested->symbolTabList[0]->type = CopyType(func->type);
		func->nested->symbolTabList[0]->name = "retVal";
		
		func->nested->symbolTabList[0]->offset = 0;
		//If return type is pointer then change the offset
		if(func->nested->symbolTabList[0]->type->type == tp_ptr)
		{
			int diff = __POINTER_SIZE - func->nested->symbolTabList[0]->width;
			func->nested->symbolTabList[0]->width = __POINTER_SIZE;
			for(int i=1;i<func->nested->symbolTabList.size();i++)
			{
				func->nested->symbolTabList[i]->offset += diff;
			}
		}
		func->nested->lastQuad = nextInstruction-1;
		//Create a new Current Symbol Table
		currentSymbolTable = new symbolTable();
};

%%
void yyerror(const char*s)
{
	printf("%s",s);
}
