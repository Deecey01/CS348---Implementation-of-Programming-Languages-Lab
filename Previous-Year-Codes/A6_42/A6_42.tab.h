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

#ifndef YY_YY_A6_42_TAB_H_INCLUDED
# define YY_YY_A6_42_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    BEGIN = 258,                   /* BEGIN  */
    END = 259,                     /* END  */
    CONST = 260,                   /* CONST  */
    ELSE = 261,                    /* ELSE  */
    FOR = 262,                     /* FOR  */
    IF = 263,                      /* IF  */
    ADDRESS = 264,                 /* ADDRESS  */
    INTTYPE = 265,                 /* INTTYPE  */
    RETURN = 266,                  /* RETURN  */
    INVALID_TOKEN = 267,           /* INVALID_TOKEN  */
    VOIDTYPE = 268,                /* VOIDTYPE  */
    IDENTIFIER = 269,              /* IDENTIFIER  */
    INTEGER_CONSTANT = 270,        /* INTEGER_CONSTANT  */
    CHARACTER_CONSTANT = 271,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 272,          /* STRING_LITERAL  */
    LEFT_SQUARE_BRACKET = 273,     /* LEFT_SQUARE_BRACKET  */
    SLASH = 274,                   /* SLASH  */
    QUESTION_MARK = 275,           /* QUESTION_MARK  */
    ASSIGNMENT = 276,              /* ASSIGNMENT  */
    COMMA = 277,                   /* COMMA  */
    RIGHT_SQUARE_BRACKET = 278,    /* RIGHT_SQUARE_BRACKET  */
    LEFT_PARENTHESES = 279,        /* LEFT_PARENTHESES  */
    LEFT_CURLY_BRACKET = 280,      /* LEFT_CURLY_BRACKET  */
    RIGHT_CURLY_BRACKET = 281,     /* RIGHT_CURLY_BRACKET  */
    ARROW = 282,                   /* ARROW  */
    ASTERISK = 283,                /* ASTERISK  */
    PLUS = 284,                    /* PLUS  */
    MINUS = 285,                   /* MINUS  */
    EXCLAMATION = 286,             /* EXCLAMATION  */
    MODULO = 287,                  /* MODULO  */
    LESS_THAN = 288,               /* LESS_THAN  */
    GREATER_THAN = 289,            /* GREATER_THAN  */
    LESS_EQUAL_THAN = 290,         /* LESS_EQUAL_THAN  */
    GREATER_EQUAL_THAN = 291,      /* GREATER_EQUAL_THAN  */
    COLON = 292,                   /* COLON  */
    SEMI_COLON = 293,              /* SEMI_COLON  */
    RIGHT_PARENTHESES = 294,       /* RIGHT_PARENTHESES  */
    EQUALS = 295,                  /* EQUALS  */
    LOGICAL_AND = 296,             /* LOGICAL_AND  */
    LOGICAL_OR = 297,              /* LOGICAL_OR  */
    NOT_EQUALS = 298,              /* NOT_EQUALS  */
    THEN = 299                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "A6_42.y"

    int intVal;
    char *charVal;
    char *stringVal;
    char *identifierVal;
    char *unaryOperator;
    int instructionNumber;
    int parameterCount;
    Expression *expression;
    Statement *statement;
    Array *array;
    SymbolType *symbolType;
    Symbol *symbol;

#line 123 "A6_42.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_A6_42_TAB_H_INCLUDED  */
