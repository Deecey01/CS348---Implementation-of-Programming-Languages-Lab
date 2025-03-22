/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "a7_220101039.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern int yylex();
extern void print_symbol_table(FILE *output);

int line_no = 1;
FILE *output_file = NULL;

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_no, s);
    if (output_file) {
        fprintf(output_file, "Error at line %d: %s\n", line_no, s);
    }
}

/* Print function for grammar reductions */
void logging(const char *rule) {
    if (output_file) {
        fprintf(output_file, "(Line No. %d) Reduction: %s\n",line_no, rule);
    }
}


#line 99 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 229 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 4,           /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOATING_CONSTANT = 5,          /* FLOATING_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 6,         /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_FLOAT = 10,                     /* FLOAT  */
  YYSYMBOL_INTEGER = 11,                   /* INTEGER  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_CONST = 14,                     /* CONST  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_BOOL = 16,                      /* BOOL  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_BEGIN_BLOCK = 20,               /* BEGIN_BLOCK  */
  YYSYMBOL_END_BLOCK = 21,                 /* END_BLOCK  */
  YYSYMBOL_ARROW = 22,                     /* ARROW  */
  YYSYMBOL_INC = 23,                       /* INC  */
  YYSYMBOL_DEC = 24,                       /* DEC  */
  YYSYMBOL_LEFT_SHIFT = 25,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 26,               /* RIGHT_SHIFT  */
  YYSYMBOL_LE_OP = 27,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 28,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 29,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 30,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 31,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 32,                     /* OR_OP  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_34_ = 34,                       /* '?'  */
  YYSYMBOL_35_ = 35,                       /* ':'  */
  YYSYMBOL_36_ = 36,                       /* '|'  */
  YYSYMBOL_37_ = 37,                       /* '^'  */
  YYSYMBOL_38_ = 38,                       /* '<'  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_UMINUS = 46,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 47,                     /* UPLUS  */
  YYSYMBOL_48_ = 48,                       /* '&'  */
  YYSYMBOL_DEREF = 49,                     /* DEREF  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_primary_expression = 57,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 58,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 59,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 60,          /* unary_expression  */
  YYSYMBOL_multiplicative_expression = 61, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 62,       /* additive_expression  */
  YYSYMBOL_relational_expression = 63,     /* relational_expression  */
  YYSYMBOL_equality_expression = 64,       /* equality_expression  */
  YYSYMBOL_logical_and_expression = 65,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 66,     /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 67,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 68,     /* assignment_expression  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_declaration = 70,               /* declaration  */
  YYSYMBOL_init_declarator = 71,           /* init_declarator  */
  YYSYMBOL_type_specifier = 72,            /* type_specifier  */
  YYSYMBOL_declarator = 73,                /* declarator  */
  YYSYMBOL_direct_declarator = 74,         /* direct_declarator  */
  YYSYMBOL_function_declarator = 75,       /* function_declarator  */
  YYSYMBOL_pointer = 76,                   /* pointer  */
  YYSYMBOL_parameter_list = 77,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 78,     /* parameter_declaration  */
  YYSYMBOL_initializer = 79,               /* initializer  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_compound_statement = 81,        /* compound_statement  */
  YYSYMBOL_block_item_list = 82,           /* block_item_list  */
  YYSYMBOL_block_item = 83,                /* block_item  */
  YYSYMBOL_expression_statement = 84,      /* expression_statement  */
  YYSYMBOL_selection_statement = 85,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 86,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 87,            /* jump_statement  */
  YYSYMBOL_translation_unit = 88,          /* translation_unit  */
  YYSYMBOL_function_definition = 89,       /* function_definition  */
  YYSYMBOL_declaration_list = 90           /* declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,    44,    48,     2,
      52,    53,    42,    40,    54,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    55,
      38,    33,    39,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    46,    47,
      49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    87,    88,    89,    90,    91,    95,    96,
      97,    98,    99,   103,   104,   108,   109,   110,   111,   112,
     113,   117,   118,   119,   120,   124,   125,   126,   130,   131,
     132,   133,   134,   138,   139,   140,   144,   145,   149,   150,
     154,   155,   159,   160,   164,   169,   173,   174,   178,   179,
     180,   181,   182,   186,   187,   191,   192,   196,   197,   201,
     205,   206,   210,   211,   212,   213,   217,   222,   223,   224,
     225,   226,   230,   231,   235,   236,   240,   241,   245,   246,
     250,   251,   255,   256,   257,   258,   261,   262,   267,   268,
     269,   270,   274,   275,   279,   280
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER_CONSTANT", "FLOATING_CONSTANT", "CHARACTER_CONSTANT",
  "STRING_LITERAL", "RETURN", "VOID", "FLOAT", "INTEGER", "CHAR", "FOR",
  "CONST", "WHILE", "BOOL", "IF", "DO", "ELSE", "BEGIN_BLOCK", "END_BLOCK",
  "ARROW", "INC", "DEC", "LEFT_SHIFT", "RIGHT_SHIFT", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "'='", "'?'", "':'", "'|'", "'^'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS",
  "UPLUS", "'&'", "DEREF", "'['", "']'", "'('", "')'", "','", "';'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "expression", "declaration", "init_declarator",
  "type_specifier", "declarator", "direct_declarator",
  "function_declarator", "pointer", "parameter_list",
  "parameter_declaration", "initializer", "statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "function_definition",
  "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     265,  -100,  -100,  -100,  -100,  -100,  -100,     6,    92,  -100,
      28,  -100,   -42,    -2,  -100,   137,    47,  -100,  -100,  -100,
      49,    14,  -100,   266,   123,  -100,     7,  -100,   137,    21,
    -100,    26,  -100,     9,   -36,  -100,  -100,  -100,  -100,  -100,
    -100,   266,   266,   266,   266,   266,   266,  -100,    -8,    48,
      41,    -5,    -6,    16,    62,    56,  -100,  -100,  -100,    34,
      35,    46,    55,   195,  -100,  -100,  -100,    45,  -100,  -100,
    -100,   176,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,   107,  -100,   265,  -100,  -100,  -100,  -100,  -100,    69,
     120,   266,   248,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,  -100,    82,
     114,   266,   266,   109,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,    91,  -100,    43,  -100,  -100,  -100,  -100,  -100,  -100,
      41,    41,    -5,    -5,    -5,    -5,    -6,    -6,    16,    62,
     110,  -100,   114,    97,    98,   100,  -100,  -100,   266,   266,
     257,   195,   195,   266,  -100,  -100,   195,   108,  -100,   139,
     117,  -100,   195,   195,   112,  -100,  -100,  -100
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    48,    51,    50,    49,    52,    89,     0,     0,    88,
      55,    59,     0,    46,    54,     0,     0,     1,    91,    90,
       0,     0,    45,     0,     0,    94,     0,    92,     0,    55,
      53,     0,    58,    64,     0,    60,     2,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     8,    15,    21,
      25,    28,    33,    36,    38,    40,    42,    66,    47,     0,
       0,     0,     0,     0,    72,    78,    44,     0,    76,    77,
      67,     0,    74,    68,    69,    70,    71,    95,    93,    56,
      62,    65,    57,     0,    18,    19,    17,    20,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,    79,    73,    75,    63,    61,     7,
      12,     0,    10,     0,    13,    43,    22,    23,    24,    21,
      26,    27,    31,    32,    29,    30,    34,    35,    37,    39,
       0,    87,     0,     0,     0,     0,     9,    11,     0,     0,
       0,     0,     0,     0,    14,    41,     0,     0,    84,    80,
       0,    83,     0,     0,     0,    82,    81,    85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,  -100,   -40,    15,   105,    12,    67,    54,
    -100,    24,   -23,   -39,    19,  -100,     8,  -100,   158,  -100,
     143,  -100,    94,  -100,   -57,     0,  -100,   119,   -99,  -100,
    -100,  -100,  -100,   187,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    47,    48,   123,    49,    50,    51,    52,    53,    54,
      55,    56,    66,    67,    68,    12,    26,    13,    14,    15,
      16,    34,    35,    58,    69,    70,    71,    72,    73,    74,
      75,    76,     8,     9,    28
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    84,    85,    86,    87,    88,   113,    89,     7,    10,
      29,   142,    80,    22,    90,    27,     7,    82,    83,     6,
     109,    99,   100,     1,     2,     3,     4,    18,    78,    33,
       5,    23,   101,   102,    25,    97,    98,    36,    37,    38,
      39,    40,    91,   150,    92,   103,   104,    77,    11,    11,
      29,    11,   121,    31,   126,   127,   128,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,    32,   140,   124,
     125,    20,   143,   144,    41,    42,    43,    79,    20,    44,
      21,    93,    45,    94,    95,    96,    46,   110,   106,   108,
     107,    33,    17,   105,   158,   159,   147,   148,   111,   161,
     114,     1,     2,     3,     4,   165,   166,   112,     5,   129,
     117,   157,   130,   131,   160,   136,   137,    36,    37,    38,
      39,    40,   119,   120,   145,   154,    36,    37,    38,    39,
      40,    59,     1,     2,     3,     4,    60,   141,    61,     5,
      62,    63,   146,    24,    64,   149,     1,     2,     3,     4,
     151,   152,   153,     5,    41,    42,    43,    24,   163,    44,
     139,   162,    45,    41,    42,    43,    46,   167,    44,    65,
     164,    45,   138,   155,    30,    46,    81,   118,    65,    36,
      37,    38,    39,    40,    59,     1,     2,     3,     4,    60,
     116,    61,     5,    62,    63,    19,    24,   115,    36,    37,
      38,    39,    40,    59,   132,   133,   134,   135,    60,     0,
      61,     0,    62,    63,     0,    24,    41,    42,    43,     0,
       0,    44,     0,     0,    45,     0,     0,     0,    46,     0,
       0,    65,     0,     0,     0,    41,    42,    43,     0,     0,
      44,     0,     0,    45,     0,     0,     0,    46,     0,     0,
      65,    36,    37,    38,    39,    40,     0,     0,     0,     0,
      36,    37,    38,    39,    40,     0,     0,     0,     0,    36,
      37,    38,    39,    40,     1,     2,     3,     4,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,    41,    42,
      43,     0,     0,    44,     0,     0,    45,    41,    42,    43,
      46,   122,    44,     0,     0,    45,    41,    42,    43,    46,
     156,    44,     0,     0,    45,     0,     0,     0,    46
};

static const yytype_int16 yycheck[] =
{
      23,    41,    42,    43,    44,    45,    63,    46,     0,     3,
       3,   110,     3,    55,    22,    15,     8,    53,    54,     0,
      59,    27,    28,     9,    10,    11,    12,     8,    28,    21,
      16,    33,    38,    39,    15,    40,    41,     3,     4,     5,
       6,     7,    50,   142,    52,    29,    30,    28,    42,    42,
       3,    42,    91,     4,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    53,   107,    92,
      93,    50,   111,   112,    40,    41,    42,    51,    50,    45,
      52,    33,    48,    42,    43,    44,    52,    52,    32,    55,
      34,    83,     0,    31,   151,   152,    53,    54,    52,   156,
      55,     9,    10,    11,    12,   162,   163,    52,    16,   149,
       3,   150,    97,    98,   153,   103,   104,     3,     4,     5,
       6,     7,    53,     3,    15,   148,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    55,    15,    16,
      17,    18,    51,    20,    21,    35,     9,    10,    11,    12,
      53,    53,    52,    16,    40,    41,    42,    20,    19,    45,
     106,    53,    48,    40,    41,    42,    52,    55,    45,    55,
      53,    48,   105,   149,    16,    52,    33,    83,    55,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      71,    15,    16,    17,    18,     8,    20,    21,     3,     4,
       5,     6,     7,     8,    99,   100,   101,   102,    13,    -1,
      15,    -1,    17,    18,    -1,    20,    40,    41,    42,    -1,
      -1,    45,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,
      -1,    55,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      45,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,
      55,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     9,    10,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    45,    -1,    -1,    48,    40,    41,    42,
      52,    53,    45,    -1,    -1,    48,    40,    41,    42,    52,
      53,    45,    -1,    -1,    48,    -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    16,    70,    72,    88,    89,
       3,    42,    71,    73,    74,    75,    76,     0,    70,    89,
      50,    52,    55,    33,    20,    70,    72,    81,    90,     3,
      74,     4,    53,    72,    77,    78,     3,     4,     5,     6,
       7,    40,    41,    42,    45,    48,    52,    57,    58,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    79,     8,
      13,    15,    17,    18,    21,    55,    68,    69,    70,    80,
      81,    82,    83,    84,    85,    86,    87,    70,    81,    51,
       3,    76,    53,    54,    60,    60,    60,    60,    60,    69,
      22,    50,    52,    33,    42,    43,    44,    40,    41,    27,
      28,    38,    39,    29,    30,    31,    32,    34,    55,    69,
      52,    52,    52,    80,    55,    21,    83,     3,    78,    53,
       3,    69,    53,    59,    68,    68,    60,    60,    60,    60,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    65,
      69,    55,    84,    69,    69,    15,    51,    53,    54,    35,
      84,    53,    53,    52,    68,    67,    53,    69,    80,    80,
      69,    80,    53,    19,    53,    80,    80,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      77,    77,    78,    78,    78,    78,    79,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    87,    87,    88,    88,
      88,    88,    89,    89,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     3,     1,     3,     1,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     4,     4,     3,     1,
       1,     3,     2,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     2,     1,     1,     1,     2,
       5,     7,     7,     6,     5,     7,     2,     3,     1,     1,
       2,     2,     3,     4,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 86 "a7_220101039.y"
                                { logging("primary_expression --> IDENTIFIER (An identifier reference)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1450 "y.tab.c"
    break;

  case 3: /* primary_expression: INTEGER_CONSTANT  */
#line 87 "a7_220101039.y"
                                { logging("primary_expression --> INTEGER_CONSTANT (An integer literal)"); (yyval.sval) = "int_const"; }
#line 1456 "y.tab.c"
    break;

  case 4: /* primary_expression: FLOATING_CONSTANT  */
#line 88 "a7_220101039.y"
                                { logging("primary_expression --> FLOATING_CONSTANT (A floating-point literal)"); (yyval.sval) = "float_const"; }
#line 1462 "y.tab.c"
    break;

  case 5: /* primary_expression: CHARACTER_CONSTANT  */
#line 89 "a7_220101039.y"
                                { logging("primary_expression --> CHARACTER_CONSTANT (A character literal)"); (yyval.sval) = "char_const"; }
#line 1468 "y.tab.c"
    break;

  case 6: /* primary_expression: STRING_LITERAL  */
#line 90 "a7_220101039.y"
                                { logging("primary_expression --> STRING_LITERAL (A string literal)"); (yyval.sval) = "string_literal"; }
#line 1474 "y.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 91 "a7_220101039.y"
                                { logging("primary_expression --> ( expression ) (Expression in parentheses)"); (yyval.sval) = (yyvsp[-1].sval); }
#line 1480 "y.tab.c"
    break;

  case 8: /* postfix_expression: primary_expression  */
#line 95 "a7_220101039.y"
                                                { logging("postfix_expression --> primary_expression (A simple expression)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1486 "y.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 96 "a7_220101039.y"
                                                { logging("postfix_expression --> postfix_expression [ expression ] (Array access)"); (yyval.sval) = "array_access"; }
#line 1492 "y.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression '(' ')'  */
#line 97 "a7_220101039.y"
                                                { logging("postfix_expression --> postfix_expression ( ) (Function call with no arguments)"); (yyval.sval) = "function_call"; }
#line 1498 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 98 "a7_220101039.y"
                                                          { logging("postfix_expression --> postfix_expression ( argument_expression_list ) (Function call with arguments)"); (yyval.sval) = "function_call_with_args"; }
#line 1504 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 99 "a7_220101039.y"
                                                { logging("postfix_expression --> postfix_expression --> IDENTIFIER (Pointer-to-member access)"); (yyval.sval) = "pointer_access"; }
#line 1510 "y.tab.c"
    break;

  case 13: /* argument_expression_list: assignment_expression  */
#line 103 "a7_220101039.y"
                                                        { logging("argument_expression_list --> assignment_expression (First argument in function call)"); }
#line 1516 "y.tab.c"
    break;

  case 14: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 104 "a7_220101039.y"
                                                         { logging("argument_expression_list --> argument_expression_list , assignment_expression (Additional argument in function call)"); }
#line 1522 "y.tab.c"
    break;

  case 15: /* unary_expression: postfix_expression  */
#line 108 "a7_220101039.y"
                                        { logging("unary_expression --> postfix_expression (Expression without unary operator)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1528 "y.tab.c"
    break;

  case 16: /* unary_expression: '&' unary_expression  */
#line 109 "a7_220101039.y"
                                        { logging("unary_expression --> & unary_expression (Address-of operator)"); (yyval.sval) = "addr_of"; }
#line 1534 "y.tab.c"
    break;

  case 17: /* unary_expression: '*' unary_expression  */
#line 110 "a7_220101039.y"
                                        { logging("unary_expression --> * unary_expression (Dereference operator)"); (yyval.sval) = "deref"; }
#line 1540 "y.tab.c"
    break;

  case 18: /* unary_expression: '+' unary_expression  */
#line 111 "a7_220101039.y"
                                        { logging("unary_expression --> + unary_expression (Unary plus operator)"); (yyval.sval) = "uplus"; }
#line 1546 "y.tab.c"
    break;

  case 19: /* unary_expression: '-' unary_expression  */
#line 112 "a7_220101039.y"
                                        { logging("unary_expression --> - unary_expression (Unary minus operator)"); (yyval.sval) = "uminus"; }
#line 1552 "y.tab.c"
    break;

  case 20: /* unary_expression: '!' unary_expression  */
#line 113 "a7_220101039.y"
                                        { logging("unary_expression --> ! unary_expression (Logical NOT operator)"); (yyval.sval) = "not"; }
#line 1558 "y.tab.c"
    break;

  case 21: /* multiplicative_expression: unary_expression  */
#line 117 "a7_220101039.y"
                                                      { logging("multiplicative_expression --> unary_expression (Expression without multiplication)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1564 "y.tab.c"
    break;

  case 22: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 118 "a7_220101039.y"
                                                      { logging("multiplicative_expression --> multiplicative_expression * unary_expression (Multiplication operation)"); (yyval.sval) = "mult"; }
#line 1570 "y.tab.c"
    break;

  case 23: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 119 "a7_220101039.y"
                                                      { logging("multiplicative_expression --> multiplicative_expression / unary_expression (Division operation)"); (yyval.sval) = "div"; }
#line 1576 "y.tab.c"
    break;

  case 24: /* multiplicative_expression: multiplicative_expression '%' unary_expression  */
#line 120 "a7_220101039.y"
                                                      { logging("multiplicative_expression --> multiplicative_expression % unary_expression (Modulo operation)"); (yyval.sval) = "mod"; }
#line 1582 "y.tab.c"
    break;

  case 25: /* additive_expression: multiplicative_expression  */
#line 124 "a7_220101039.y"
                                                            { logging("additive_expression --> multiplicative_expression (Expression without addition/subtraction)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1588 "y.tab.c"
    break;

  case 26: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 125 "a7_220101039.y"
                                                            { logging("additive_expression --> additive_expression + multiplicative_expression (Addition operation)"); (yyval.sval) = "add"; }
#line 1594 "y.tab.c"
    break;

  case 27: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 126 "a7_220101039.y"
                                                            { logging("additive_expression --> additive_expression - multiplicative_expression (Subtraction operation)"); (yyval.sval) = "sub"; }
#line 1600 "y.tab.c"
    break;

  case 28: /* relational_expression: additive_expression  */
#line 130 "a7_220101039.y"
                                                         { logging("relational_expression --> additive_expression (Expression without comparison)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1606 "y.tab.c"
    break;

  case 29: /* relational_expression: relational_expression '<' additive_expression  */
#line 131 "a7_220101039.y"
                                                         { logging("relational_expression --> relational_expression < additive_expression (Less than comparison)"); (yyval.sval) = "lt"; }
#line 1612 "y.tab.c"
    break;

  case 30: /* relational_expression: relational_expression '>' additive_expression  */
#line 132 "a7_220101039.y"
                                                         { logging("relational_expression --> relational_expression > additive_expression (Greater than comparison)"); (yyval.sval) = "gt"; }
#line 1618 "y.tab.c"
    break;

  case 31: /* relational_expression: relational_expression LE_OP additive_expression  */
#line 133 "a7_220101039.y"
                                                         { logging("relational_expression --> relational_expression <= additive_expression (Less than or equal comparison)"); (yyval.sval) = "le"; }
#line 1624 "y.tab.c"
    break;

  case 32: /* relational_expression: relational_expression GE_OP additive_expression  */
#line 134 "a7_220101039.y"
                                                         { logging("relational_expression --> relational_expression >= additive_expression (Greater than or equal comparison)"); (yyval.sval) = "ge"; }
#line 1630 "y.tab.c"
    break;

  case 33: /* equality_expression: relational_expression  */
#line 138 "a7_220101039.y"
                                                         { logging("equality_expression --> relational_expression (Expression without equality check)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1636 "y.tab.c"
    break;

  case 34: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 139 "a7_220101039.y"
                                                         { logging("equality_expression --> equality_expression == relational_expression (Equality comparison)"); (yyval.sval) = "eq"; }
#line 1642 "y.tab.c"
    break;

  case 35: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 140 "a7_220101039.y"
                                                         { logging("equality_expression --> equality_expression != relational_expression (Inequality comparison)"); (yyval.sval) = "ne"; }
#line 1648 "y.tab.c"
    break;

  case 36: /* logical_and_expression: equality_expression  */
#line 144 "a7_220101039.y"
                                                          { logging("logical_and_expression --> equality_expression (Expression without logical AND)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1654 "y.tab.c"
    break;

  case 37: /* logical_and_expression: logical_and_expression AND_OP equality_expression  */
#line 145 "a7_220101039.y"
                                                          { logging("logical_and_expression --> logical_and_expression && equality_expression (Logical AND operation)"); (yyval.sval) = "and"; }
#line 1660 "y.tab.c"
    break;

  case 38: /* logical_or_expression: logical_and_expression  */
#line 149 "a7_220101039.y"
                                                            { logging("logical_or_expression --> logical_and_expression (Expression without logical OR)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1666 "y.tab.c"
    break;

  case 39: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 150 "a7_220101039.y"
                                                            { logging("logical_or_expression --> logical_or_expression || logical_and_expression (Logical OR operation)"); (yyval.sval) = "or"; }
#line 1672 "y.tab.c"
    break;

  case 40: /* conditional_expression: logical_or_expression  */
#line 154 "a7_220101039.y"
                                                                            { logging("conditional_expression --> logical_or_expression (Expression without conditional operator)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1678 "y.tab.c"
    break;

  case 41: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 155 "a7_220101039.y"
                                                                            { logging("conditional_expression --> logical_or_expression ? expression : conditional_expression (Conditional/ternary operation)"); (yyval.sval) = "cond"; }
#line 1684 "y.tab.c"
    break;

  case 42: /* assignment_expression: conditional_expression  */
#line 159 "a7_220101039.y"
                                                          { logging("assignment_expression --> conditional_expression (Expression without assignment)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1690 "y.tab.c"
    break;

  case 43: /* assignment_expression: unary_expression '=' assignment_expression  */
#line 160 "a7_220101039.y"
                                                          { logging("assignment_expression --> unary_expression = assignment_expression (Assignment operation)"); (yyval.sval) = "assign"; }
#line 1696 "y.tab.c"
    break;

  case 44: /* expression: assignment_expression  */
#line 164 "a7_220101039.y"
                             { logging("expression --> assignment_expression (Complete expression)"); (yyval.sval) = (yyvsp[0].sval); }
#line 1702 "y.tab.c"
    break;

  case 45: /* declaration: type_specifier init_declarator ';'  */
#line 169 "a7_220101039.y"
                                          { logging("declaration --> type_specifier init_declarator ; (Variable or function declaration)"); }
#line 1708 "y.tab.c"
    break;

  case 46: /* init_declarator: declarator  */
#line 173 "a7_220101039.y"
                                    { logging("init_declarator --> declarator (Declaration without initialization)"); }
#line 1714 "y.tab.c"
    break;

  case 47: /* init_declarator: declarator '=' initializer  */
#line 174 "a7_220101039.y"
                                    { logging("init_declarator --> declarator = initializer (Declaration with initialization)"); }
#line 1720 "y.tab.c"
    break;

  case 48: /* type_specifier: VOID  */
#line 178 "a7_220101039.y"
                { logging("type_specifier --> void (Void type)"); (yyval.sval) = "void"; }
#line 1726 "y.tab.c"
    break;

  case 49: /* type_specifier: CHAR  */
#line 179 "a7_220101039.y"
                { logging("type_specifier --> char (Character type)"); (yyval.sval) = "char"; }
#line 1732 "y.tab.c"
    break;

  case 50: /* type_specifier: INTEGER  */
#line 180 "a7_220101039.y"
                { logging("type_specifier --> integer (Integer type)"); (yyval.sval) = "integer"; }
#line 1738 "y.tab.c"
    break;

  case 51: /* type_specifier: FLOAT  */
#line 181 "a7_220101039.y"
                { logging("type_specifier --> float (Float type)"); (yyval.sval) = "float"; }
#line 1744 "y.tab.c"
    break;

  case 52: /* type_specifier: BOOL  */
#line 182 "a7_220101039.y"
                { logging("type_specifier --> bool (Boolean type)"); (yyval.sval) = "bool"; }
#line 1750 "y.tab.c"
    break;

  case 53: /* declarator: pointer direct_declarator  */
#line 186 "a7_220101039.y"
                                 { logging("declarator --> pointer direct_declarator (Pointer declarator)"); }
#line 1756 "y.tab.c"
    break;

  case 54: /* declarator: direct_declarator  */
#line 187 "a7_220101039.y"
                                 { logging("declarator --> direct_declarator (Non-pointer declarator)"); }
#line 1762 "y.tab.c"
    break;

  case 55: /* direct_declarator: IDENTIFIER  */
#line 191 "a7_220101039.y"
                                                { logging("direct_declarator --> IDENTIFIER (Simple identifier)"); }
#line 1768 "y.tab.c"
    break;

  case 56: /* direct_declarator: IDENTIFIER '[' INTEGER_CONSTANT ']'  */
#line 192 "a7_220101039.y"
                                                { logging("direct_declarator --> IDENTIFIER [ INTEGER_CONSTANT ] (Array declarator)"); }
#line 1774 "y.tab.c"
    break;

  case 57: /* function_declarator: IDENTIFIER '(' parameter_list ')'  */
#line 196 "a7_220101039.y"
                                              { logging("function_declarator --> IDENTIFIER ( parameter_list ) (Function declarator with parameters)"); }
#line 1780 "y.tab.c"
    break;

  case 58: /* function_declarator: IDENTIFIER '(' ')'  */
#line 197 "a7_220101039.y"
                                                { logging("function_declarator --> IDENTIFIER ( ) (Function declarator without parameters)"); }
#line 1786 "y.tab.c"
    break;

  case 59: /* pointer: '*'  */
#line 201 "a7_220101039.y"
           { logging("pointer --> * (Pointer symbol)"); }
#line 1792 "y.tab.c"
    break;

  case 60: /* parameter_list: parameter_declaration  */
#line 205 "a7_220101039.y"
                                                 { logging("parameter_list --> parameter_declaration (First parameter in function)"); }
#line 1798 "y.tab.c"
    break;

  case 61: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 206 "a7_220101039.y"
                                                 { logging("parameter_list --> parameter_list , parameter_declaration (Additional parameter in function)"); }
#line 1804 "y.tab.c"
    break;

  case 62: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 210 "a7_220101039.y"
                                       { logging("parameter_declaration --> type_specifier IDENTIFIER (Parameter with type and name)"); }
#line 1810 "y.tab.c"
    break;

  case 63: /* parameter_declaration: type_specifier pointer IDENTIFIER  */
#line 211 "a7_220101039.y"
                                        { logging("parameter_declaration --> type_specifier pointer IDENTIFIER (Pointer parameter with type and name)"); }
#line 1816 "y.tab.c"
    break;

  case 64: /* parameter_declaration: type_specifier  */
#line 212 "a7_220101039.y"
                                       { logging("parameter_declaration --> type_specifier (Parameter with type only)"); }
#line 1822 "y.tab.c"
    break;

  case 65: /* parameter_declaration: type_specifier pointer  */
#line 213 "a7_220101039.y"
                                       { logging("parameter_declaration --> type_specifier pointer (Pointer parameter with type only)"); }
#line 1828 "y.tab.c"
    break;

  case 66: /* initializer: assignment_expression  */
#line 217 "a7_220101039.y"
                             { logging("initializer --> assignment_expression (Initializer expression)"); }
#line 1834 "y.tab.c"
    break;

  case 67: /* statement: compound_statement  */
#line 222 "a7_220101039.y"
                             { logging("statement --> compound_statement (Block statement)"); }
#line 1840 "y.tab.c"
    break;

  case 68: /* statement: expression_statement  */
#line 223 "a7_220101039.y"
                             { logging("statement --> expression_statement (Expression statement)"); }
#line 1846 "y.tab.c"
    break;

  case 69: /* statement: selection_statement  */
#line 224 "a7_220101039.y"
                             { logging("statement --> selection_statement (Selection/if statement)"); }
#line 1852 "y.tab.c"
    break;

  case 70: /* statement: iteration_statement  */
#line 225 "a7_220101039.y"
                             { logging("statement --> iteration_statement (Loop statement)"); }
#line 1858 "y.tab.c"
    break;

  case 71: /* statement: jump_statement  */
#line 226 "a7_220101039.y"
                             { logging("statement --> jump_statement (Jump/return statement)"); }
#line 1864 "y.tab.c"
    break;

  case 72: /* compound_statement: BEGIN_BLOCK END_BLOCK  */
#line 230 "a7_220101039.y"
                                             { logging("compound_statement --> begin end (Empty block)"); }
#line 1870 "y.tab.c"
    break;

  case 73: /* compound_statement: BEGIN_BLOCK block_item_list END_BLOCK  */
#line 231 "a7_220101039.y"
                                             { logging("compound_statement --> begin block_item_list end (Block with items)"); }
#line 1876 "y.tab.c"
    break;

  case 74: /* block_item_list: block_item  */
#line 235 "a7_220101039.y"
                                   { logging("block_item_list --> block_item (First item in block)"); }
#line 1882 "y.tab.c"
    break;

  case 75: /* block_item_list: block_item_list block_item  */
#line 236 "a7_220101039.y"
                                   { logging("block_item_list --> block_item_list block_item (Additional item in block)"); }
#line 1888 "y.tab.c"
    break;

  case 76: /* block_item: declaration  */
#line 240 "a7_220101039.y"
                   { logging("block_item --> declaration (Declaration in block)"); }
#line 1894 "y.tab.c"
    break;

  case 77: /* block_item: statement  */
#line 241 "a7_220101039.y"
                   { logging("block_item --> statement (Statement in block)"); }
#line 1900 "y.tab.c"
    break;

  case 78: /* expression_statement: ';'  */
#line 245 "a7_220101039.y"
                    { logging("expression_statement --> ; (Empty statement)"); }
#line 1906 "y.tab.c"
    break;

  case 79: /* expression_statement: expression ';'  */
#line 246 "a7_220101039.y"
                     { logging("expression_statement --> expression ; (Expression statement)"); }
#line 1912 "y.tab.c"
    break;

  case 80: /* selection_statement: IF '(' expression ')' statement  */
#line 250 "a7_220101039.y"
                                                       { logging("selection_statement --> if ( expression ) statement (If statement)"); }
#line 1918 "y.tab.c"
    break;

  case 81: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 251 "a7_220101039.y"
                                                       { logging("selection_statement --> if ( expression ) statement else statement (If-else statement)"); }
#line 1924 "y.tab.c"
    break;

  case 82: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 255 "a7_220101039.y"
                                                                                  { logging("iteration_statement --> for ( expression_statement expression_statement expression ) statement (For loop with update)"); }
#line 1930 "y.tab.c"
    break;

  case 83: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 256 "a7_220101039.y"
                                                                                  { logging("iteration_statement --> for ( expression_statement expression_statement ) statement (For loop without update)"); }
#line 1936 "y.tab.c"
    break;

  case 84: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 257 "a7_220101039.y"
                                                                                 { logging("iteration_statement --> while ( expression ) statement (While loop)"); }
#line 1942 "y.tab.c"
    break;

  case 85: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 258 "a7_220101039.y"
                                                                                 { logging("iteration_statement --> do statement while ( expression ) ; (Do-while loop)"); }
#line 1948 "y.tab.c"
    break;

  case 86: /* jump_statement: RETURN ';'  */
#line 261 "a7_220101039.y"
                           { logging("jump_statement --> return ;"); }
#line 1954 "y.tab.c"
    break;

  case 87: /* jump_statement: RETURN expression ';'  */
#line 262 "a7_220101039.y"
                            { logging("jump_statement --> return expression ;"); }
#line 1960 "y.tab.c"
    break;

  case 88: /* translation_unit: function_definition  */
#line 267 "a7_220101039.y"
                                         { logging("translation_unit --> function_definition"); }
#line 1966 "y.tab.c"
    break;

  case 89: /* translation_unit: declaration  */
#line 268 "a7_220101039.y"
                                         { logging("translation_unit --> declaration"); }
#line 1972 "y.tab.c"
    break;

  case 90: /* translation_unit: translation_unit function_definition  */
#line 269 "a7_220101039.y"
                                           { logging("translation_unit --> translation_unit function_definition"); }
#line 1978 "y.tab.c"
    break;

  case 91: /* translation_unit: translation_unit declaration  */
#line 270 "a7_220101039.y"
                                         { logging("translation_unit --> translation_unit declaration"); }
#line 1984 "y.tab.c"
    break;

  case 92: /* function_definition: type_specifier function_declarator compound_statement  */
#line 274 "a7_220101039.y"
                                                                             { logging("function_definition --> type_specifier function_declarator compound_statement"); }
#line 1990 "y.tab.c"
    break;

  case 93: /* function_definition: type_specifier function_declarator declaration_list compound_statement  */
#line 275 "a7_220101039.y"
                                                                             { logging("function_definition --> type_specifier function_declarator declaration_list compound_statement"); }
#line 1996 "y.tab.c"
    break;

  case 94: /* declaration_list: declaration  */
#line 279 "a7_220101039.y"
                                     { logging("declaration_list --> declaration"); }
#line 2002 "y.tab.c"
    break;

  case 95: /* declaration_list: declaration_list declaration  */
#line 280 "a7_220101039.y"
                                     { logging("declaration_list --> declaration_list declaration"); }
#line 2008 "y.tab.c"
    break;


#line 2012 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 283 "a7_220101039.y"


int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
        
        // Create output file with .output extension
        char output_filename[256];
        strcpy(output_filename, "output.txt");
        output_file = fopen(output_filename, "w");
        if (!output_file) {
            fprintf(stderr, "Cannot create output file %s\n", output_filename);
            fclose(file);
            return 1;
        }
    }

    printf("Parsing...\n");
    fprintf(output_file, "Parsing...\n");
    int result = yyparse();
    
    if (result == 0) {
        printf("Parsing completed successfully.\n");
        fprintf(output_file, "Parsing completed successfully.\n");
        print_symbol_table(output_file);
    } else {
        printf("Parsing failed.\n");
        fprintf(output_file, "Parsing failed.\n");
    }

    if (output_file) {
        fclose(output_file);
    }
    return result;
}
