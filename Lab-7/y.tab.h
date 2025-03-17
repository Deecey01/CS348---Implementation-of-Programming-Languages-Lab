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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER_CONSTANT = 259,        /* INTEGER_CONSTANT  */
    FLOATING_CONSTANT = 260,       /* FLOATING_CONSTANT  */
    CHARACTER_CONSTANT = 261,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    RETURN = 263,                  /* RETURN  */
    VOID = 264,                    /* VOID  */
    FLOAT = 265,                   /* FLOAT  */
    INTEGER = 266,                 /* INTEGER  */
    CHAR = 267,                    /* CHAR  */
    FOR = 268,                     /* FOR  */
    CONST = 269,                   /* CONST  */
    WHILE = 270,                   /* WHILE  */
    BOOL = 271,                    /* BOOL  */
    IF = 272,                      /* IF  */
    DO = 273,                      /* DO  */
    ELSE = 274,                    /* ELSE  */
    BEGIN_BLOCK = 275,             /* BEGIN_BLOCK  */
    END_BLOCK = 276,               /* END_BLOCK  */
    ARROW = 277,                   /* ARROW  */
    INC = 278,                     /* INC  */
    DEC = 279,                     /* DEC  */
    LEFT_SHIFT = 280,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 281,             /* RIGHT_SHIFT  */
    LE_OP = 282,                   /* LE_OP  */
    GE_OP = 283,                   /* GE_OP  */
    EQ_OP = 284,                   /* EQ_OP  */
    NE_OP = 285,                   /* NE_OP  */
    AND_OP = 286,                  /* AND_OP  */
    OR_OP = 287,                   /* OR_OP  */
    UMINUS = 288,                  /* UMINUS  */
    UPLUS = 289,                   /* UPLUS  */
    DEREF = 290                    /* DEREF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INTEGER_CONSTANT 259
#define FLOATING_CONSTANT 260
#define CHARACTER_CONSTANT 261
#define STRING_LITERAL 262
#define RETURN 263
#define VOID 264
#define FLOAT 265
#define INTEGER 266
#define CHAR 267
#define FOR 268
#define CONST 269
#define WHILE 270
#define BOOL 271
#define IF 272
#define DO 273
#define ELSE 274
#define BEGIN_BLOCK 275
#define END_BLOCK 276
#define ARROW 277
#define INC 278
#define DEC 279
#define LEFT_SHIFT 280
#define RIGHT_SHIFT 281
#define LE_OP 282
#define GE_OP 283
#define EQ_OP 284
#define NE_OP 285
#define AND_OP 286
#define OR_OP 287
#define UMINUS 288
#define UPLUS 289
#define DEREF 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "a7_220101039.y"

    int ival;
    float fval;
    char cval;
    char *sval;

#line 144 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
