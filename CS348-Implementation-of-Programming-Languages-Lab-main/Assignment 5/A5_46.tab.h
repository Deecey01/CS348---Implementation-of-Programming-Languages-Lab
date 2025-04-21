/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_A5_46_TAB_H_INCLUDED
# define YY_YY_A5_46_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    IF = 261,                      /* IF  */
    INT = 262,                     /* INT  */
    RETURN = 263,                  /* RETURN  */
    VOID = 264,                    /* VOID  */
    IDENTIFIER = 265,              /* IDENTIFIER  */
    STRING_LITERAL = 266,          /* STRING_LITERAL  */
    SQUARE_BRACKET_OPEN = 267,     /* SQUARE_BRACKET_OPEN  */
    SQUARE_BRACKET_CLOSE = 268,    /* SQUARE_BRACKET_CLOSE  */
    ROUND_BRACKET_OPEN = 269,      /* ROUND_BRACKET_OPEN  */
    ROUND_BRACKET_CLOSE = 270,     /* ROUND_BRACKET_CLOSE  */
    CURLY_BRACKET_OPEN = 271,      /* CURLY_BRACKET_OPEN  */
    CURLY_BRACKET_CLOSE = 272,     /* CURLY_BRACKET_CLOSE  */
    BITWISE_AND = 273,             /* BITWISE_AND  */
    MUL = 274,                     /* MUL  */
    ADD = 275,                     /* ADD  */
    SUB = 276,                     /* SUB  */
    EXCLAIM = 277,                 /* EXCLAIM  */
    DIV = 278,                     /* DIV  */
    MOD = 279,                     /* MOD  */
    BIT_SL = 280,                  /* BIT_SL  */
    BIT_SR = 281,                  /* BIT_SR  */
    LTE = 282,                     /* LTE  */
    GTE = 283,                     /* GTE  */
    EQ = 284,                      /* EQ  */
    NEQ = 285,                     /* NEQ  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    QUESTION = 288,                /* QUESTION  */
    COLON = 289,                   /* COLON  */
    SEMICOLON = 290,               /* SEMICOLON  */
    ASSIGN = 291,                  /* ASSIGN  */
    COMMA = 292,                   /* COMMA  */
    THEN = 293,                    /* THEN  */
    INTEGER_CONSTANT = 294,        /* INTEGER_CONSTANT  */
    CHARACTER_CONSTANT = 295       /* CHARACTER_CONSTANT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "A5_46.y"

    // types for terminals
    char unaryOp; // unary operation type
    char* char_value; // for characters and strings
    int intval; // for integers
    int instr_number; // for instruction numbers used in backpatching
    int num_params; // for number of parameters in a function call

    // types for nonterminals
    Expression* expr;
    Statement* stat;
    SymbolType* sym_type;
    Symbol* symp;
    Array* A;

#line 120 "A5_46.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_A5_46_TAB_H_INCLUDED  */
