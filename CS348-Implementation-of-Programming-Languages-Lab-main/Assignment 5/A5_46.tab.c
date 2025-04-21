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
#line 1 "A5_46.y"

    #include "A5_46_translator.h"
    #include <bits/stdc++.h>
    #include <sstream>

    using namespace std;
    
    extern "C" int yylex();
    
    //var_type for last encountered type
    extern string var_type;
    extern vector<Label> label_table;

    void yyerror(string s);
    Expression* temp_rel;

#line 88 "A5_46.tab.c"

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

#include "A5_46.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_IDENTIFIER = 10,                /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 11,            /* STRING_LITERAL  */
  YYSYMBOL_SQUARE_BRACKET_OPEN = 12,       /* SQUARE_BRACKET_OPEN  */
  YYSYMBOL_SQUARE_BRACKET_CLOSE = 13,      /* SQUARE_BRACKET_CLOSE  */
  YYSYMBOL_ROUND_BRACKET_OPEN = 14,        /* ROUND_BRACKET_OPEN  */
  YYSYMBOL_ROUND_BRACKET_CLOSE = 15,       /* ROUND_BRACKET_CLOSE  */
  YYSYMBOL_CURLY_BRACKET_OPEN = 16,        /* CURLY_BRACKET_OPEN  */
  YYSYMBOL_CURLY_BRACKET_CLOSE = 17,       /* CURLY_BRACKET_CLOSE  */
  YYSYMBOL_BITWISE_AND = 18,               /* BITWISE_AND  */
  YYSYMBOL_MUL = 19,                       /* MUL  */
  YYSYMBOL_ADD = 20,                       /* ADD  */
  YYSYMBOL_SUB = 21,                       /* SUB  */
  YYSYMBOL_EXCLAIM = 22,                   /* EXCLAIM  */
  YYSYMBOL_DIV = 23,                       /* DIV  */
  YYSYMBOL_MOD = 24,                       /* MOD  */
  YYSYMBOL_BIT_SL = 25,                    /* BIT_SL  */
  YYSYMBOL_BIT_SR = 26,                    /* BIT_SR  */
  YYSYMBOL_LTE = 27,                       /* LTE  */
  YYSYMBOL_GTE = 28,                       /* GTE  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NEQ = 30,                       /* NEQ  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_QUESTION = 33,                  /* QUESTION  */
  YYSYMBOL_COLON = 34,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_ASSIGN = 36,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_THEN = 38,                      /* THEN  */
  YYSYMBOL_INTEGER_CONSTANT = 39,          /* INTEGER_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 40,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_M = 42,                         /* M  */
  YYSYMBOL_N = 43,                         /* N  */
  YYSYMBOL_changetable = 44,               /* changetable  */
  YYSYMBOL_primary_expression = 45,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 46,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 47, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 48,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 49,          /* unary_expression  */
  YYSYMBOL_unary_operator = 50,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 51, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 52,       /* additive_expression  */
  YYSYMBOL_relational_expression = 53,     /* relational_expression  */
  YYSYMBOL_equality_expression = 54,       /* equality_expression  */
  YYSYMBOL_and_helper = 55,                /* and_helper  */
  YYSYMBOL_logical_and_expression = 56,    /* logical_and_expression  */
  YYSYMBOL_or_helper = 57,                 /* or_helper  */
  YYSYMBOL_logical_or_expression = 58,     /* logical_or_expression  */
  YYSYMBOL_condition = 59,                 /* condition  */
  YYSYMBOL_conditional_expression = 60,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 61,     /* assignment_expression  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_declaration = 63,               /* declaration  */
  YYSYMBOL_init_declarator = 64,           /* init_declarator  */
  YYSYMBOL_type_specifier = 65,            /* type_specifier  */
  YYSYMBOL_declarator = 66,                /* declarator  */
  YYSYMBOL_declarator_helper = 67,         /* declarator_helper  */
  YYSYMBOL_direct_declarator = 68,         /* direct_declarator  */
  YYSYMBOL_pointer = 69,                   /* pointer  */
  YYSYMBOL_parameter_list_opt = 70,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 71,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 72,     /* parameter_declaration  */
  YYSYMBOL_initializer = 73,               /* initializer  */
  YYSYMBOL_statement = 74,                 /* statement  */
  YYSYMBOL_compound_statement = 75,        /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 76,       /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 77,           /* block_item_list  */
  YYSYMBOL_block_item = 78,                /* block_item  */
  YYSYMBOL_expression_statement = 79,      /* expression_statement  */
  YYSYMBOL_if_helper = 80,                 /* if_helper  */
  YYSYMBOL_selection_statement = 81,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 82,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 83,            /* jump_statement  */
  YYSYMBOL_translation_unit = 84,          /* translation_unit  */
  YYSYMBOL_external_declaration = 85,      /* external_declaration  */
  YYSYMBOL_function_definition = 86        /* function_definition  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   106,   116,   131,   138,   145,   151,   157,
     171,   190,   209,   219,   223,   229,   235,   243,   244,   293,
     295,   297,   299,   301,   305,   332,   359,   384,   410,   411,
     418,   427,   429,   442,   452,   462,   474,   475,   497,   519,
     526,   528,   541,   547,   549,   562,   568,   570,   592,   593,
     617,   621,   625,   626,   635,   636,   637,   641,   649,   654,
     665,   673,   683,   698,   719,   725,   726,   729,   730,   733,
     734,   738,   742,   743,   748,   749,   750,   753,   759,   760,
     765,   766,   773,   774,   777,   778,   782,   789,   797,   810,
     830,   835,   843,   844,   847,   848,   851
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "ELSE", "FOR",
  "IF", "INT", "RETURN", "VOID", "IDENTIFIER", "STRING_LITERAL",
  "SQUARE_BRACKET_OPEN", "SQUARE_BRACKET_CLOSE", "ROUND_BRACKET_OPEN",
  "ROUND_BRACKET_CLOSE", "CURLY_BRACKET_OPEN", "CURLY_BRACKET_CLOSE",
  "BITWISE_AND", "MUL", "ADD", "SUB", "EXCLAIM", "DIV", "MOD", "BIT_SL",
  "BIT_SR", "LTE", "GTE", "EQ", "NEQ", "AND", "OR", "QUESTION", "COLON",
  "SEMICOLON", "ASSIGN", "COMMA", "THEN", "INTEGER_CONSTANT",
  "CHARACTER_CONSTANT", "$accept", "M", "N", "changetable",
  "primary_expression", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "and_helper", "logical_and_expression", "or_helper",
  "logical_or_expression", "condition", "conditional_expression",
  "assignment_expression", "expression", "declaration", "init_declarator",
  "type_specifier", "declarator", "declarator_helper", "direct_declarator",
  "pointer", "parameter_list_opt", "parameter_list",
  "parameter_declaration", "initializer", "statement",
  "compound_statement", "block_item_list_opt", "block_item_list",
  "block_item", "expression_statement", "if_helper", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,  -141,  -141,  -141,  -141,     8,    91,  -141,  -141,    35,
    -141,   -19,   -30,  -141,  -141,    14,  -141,  -141,     0,  -141,
    -141,   160,    12,    41,  -141,  -141,    20,  -141,  -141,   160,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,    54,    10,
     160,    90,    59,   112,   131,  -141,     6,  -141,   130,  -141,
    -141,  -141,  -141,    67,     8,    39,    28,  -141,  -141,  -141,
      56,   160,   160,   160,  -141,   160,   160,   160,   160,   160,
     160,   160,   160,   160,  -141,  -141,   160,  -141,   160,  -141,
    -141,   160,    68,    70,     1,    67,  -141,    55,  -141,     8,
    -141,  -141,    75,    78,  -141,  -141,    82,  -141,  -141,  -141,
    -141,  -141,    41,  -141,    86,    88,    81,  -141,  -141,  -141,
    -141,  -141,  -141,    90,    90,    59,    59,    59,    59,   160,
     160,   131,     6,  -141,   137,   160,  -141,    80,   106,  -141,
      69,  -141,    67,  -141,  -141,  -141,  -141,   160,   112,   112,
      93,  -141,  -141,  -141,  -141,  -141,   114,  -141,  -141,   137,
     125,   160,  -141,   127,  -141,   160,  -141,  -141,   114,   126,
    -141,  -141,   114,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    55,    56,    54,    95,     0,     0,    92,    94,    60,
      64,     0,     4,     4,    58,     0,     1,    93,     0,    59,
      51,     0,     0,    66,    57,    62,     0,     5,     8,     0,
      19,    20,    21,    22,    23,     6,     7,    10,    17,    24,
       0,    28,    31,    36,    40,     2,    43,     2,    46,     2,
      48,    71,    53,    78,    70,     0,    65,    67,    61,    50,
       0,     0,    14,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     2,     0,    39,     0,    42,
      45,     0,     0,     0,     0,    78,    85,     0,    82,     0,
      83,    72,     0,     2,    80,    73,     0,    74,    75,    76,
      69,    63,     0,     9,     0,     0,    13,    15,    49,    25,
      26,    27,    24,    29,    30,    32,    33,    34,    35,     0,
       0,    41,    44,     3,     0,     0,    91,     0,     0,    84,
      52,    96,     0,     2,    68,    11,    12,     0,    37,    38,
       0,     2,    86,    90,    77,    81,     0,    16,     2,     0,
      87,     0,     2,     0,    47,     0,     2,     3,     0,     0,
      88,     2,     0,    89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,   -40,  -140,   139,  -141,  -141,  -141,  -141,    -9,  -141,
      96,    73,    47,    74,  -141,    95,  -141,  -141,  -141,    17,
     -20,   -29,    45,  -141,     2,   -51,  -141,   154,  -141,  -141,
    -141,    83,  -141,  -132,  -141,    98,  -141,    43,  -120,  -141,
    -141,  -141,  -141,  -141,   178,  -141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    76,   140,    22,    37,    38,   105,   106,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      59,    87,    88,    11,    89,    12,    13,    14,    15,    55,
      56,    57,    52,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     6,     7,     8
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    51,     5,   100,   141,   -52,    21,    78,     5,    81,
     153,    27,    28,    25,   150,    29,    20,   159,     9,    30,
      31,    32,    33,    34,     9,    54,   160,    10,    53,   152,
     163,    64,   104,    58,   119,   120,   126,    77,   130,    26,
      35,    36,   107,   108,     1,     4,    63,    18,     2,    19,
       3,     4,   123,   132,   101,   127,   109,   110,   111,   112,
     112,   112,   112,   112,   112,   102,    61,   112,    62,   112,
       1,   103,    82,    83,     2,    84,     3,    27,    28,    68,
      69,    29,   124,    85,   125,    30,    31,    32,    33,    34,
     129,    16,   131,   146,     1,   -79,   142,   133,     2,   135,
       3,   149,    86,   136,    54,    21,    35,    36,   151,    65,
     112,   112,   155,    66,    67,   143,   158,   147,   137,    82,
      83,   162,    84,   144,    27,    28,   157,   148,    29,    -3,
      85,   156,    30,    31,    32,    33,    34,    70,    71,    72,
      73,   161,   112,   115,   116,   117,   118,    27,    28,    86,
     121,    29,    23,    35,    36,    30,    31,    32,    33,    34,
      74,    75,    79,    80,   113,   114,   138,   139,   154,    24,
      27,    28,    86,   122,    29,   145,    35,    36,    30,    31,
      32,    33,    34,   128,    17,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36
};

static const yytype_int16 yycheck[] =
{
      29,    21,     0,    54,   124,    35,    36,    47,     6,    49,
     150,    10,    11,    13,   146,    14,    35,   157,    10,    18,
      19,    20,    21,    22,    10,    23,   158,    19,    16,   149,
     162,    40,    61,    13,    74,    75,    35,    31,    89,    39,
      39,    40,    62,    63,     3,     0,    36,    12,     7,    14,
       9,     6,    81,    93,    15,    84,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    37,    12,    76,    14,    78,
       3,    15,     5,     6,     7,     8,     9,    10,    11,    20,
      21,    14,    14,    16,    14,    18,    19,    20,    21,    22,
      35,     0,    17,   133,     3,    17,   125,    15,     7,    13,
       9,   141,    35,    15,   102,    36,    39,    40,   148,    19,
     119,   120,   152,    23,    24,    35,   156,   137,    37,     5,
       6,   161,     8,    17,    10,    11,   155,    34,    14,     4,
      16,     4,    18,    19,    20,    21,    22,    25,    26,    27,
      28,    15,   151,    70,    71,    72,    73,    10,    11,    35,
      76,    14,    13,    39,    40,    18,    19,    20,    21,    22,
      29,    30,    32,    33,    68,    69,   119,   120,   151,    15,
      10,    11,    35,    78,    14,   132,    39,    40,    18,    19,
      20,    21,    22,    85,     6,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,     9,    63,    65,    84,    85,    86,    10,
      19,    64,    66,    67,    68,    69,     0,    85,    12,    14,
      35,    36,    44,    44,    68,    13,    39,    10,    11,    14,
      18,    19,    20,    21,    22,    39,    40,    45,    46,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    73,    16,    65,    70,    71,    72,    13,    61,
      62,    12,    14,    36,    49,    19,    23,    24,    20,    21,
      25,    26,    27,    28,    29,    30,    42,    31,    42,    32,
      33,    42,     5,     6,     8,    16,    35,    62,    63,    65,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      66,    15,    37,    15,    62,    47,    48,    61,    61,    49,
      49,    49,    49,    51,    51,    52,    52,    52,    52,    42,
      42,    54,    56,    62,    14,    14,    35,    62,    76,    35,
      66,    17,    42,    15,    72,    13,    15,    37,    53,    53,
      43,    79,    62,    35,    17,    78,    42,    61,    34,    42,
      74,    42,    79,    43,    60,    42,     4,    62,    42,    43,
      74,    15,    42,    74
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    45,    45,    45,    45,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    52,    52,
      52,    53,    53,    53,    53,    53,    54,    54,    54,    55,
      56,    56,    57,    58,    58,    59,    60,    60,    61,    61,
      62,    63,    64,    64,    65,    65,    65,    66,    66,    67,
      68,    68,    68,    68,    69,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    74,    74,    74,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    82,
      83,    83,    84,    84,    85,    85,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     1,     1,     1,     1,     3,
       1,     4,     4,     1,     0,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     4,     4,     2,
       1,     3,     2,     1,     3,     2,     1,     7,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     1,     2,
       1,     4,     3,     4,     1,     1,     0,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     3,     1,     1,     2,     1,     3,     4,     8,    11,
       3,     2,     1,     2,     1,     1,     6
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* M: %empty  */
#line 98 "A5_46.y"
    {
        //mainly used in backpatching, stores the next quad 
        (yyval.instr_number) = nextinstr();
    }
#line 1567 "A5_46.tab.c"
    break;

  case 3: /* N: %empty  */
#line 107 "A5_46.y"
    {
        //For backpatching, guard fall through
        (yyval.stat) = new Statement();
        (yyval.stat)->nextlist=makelist(nextinstr());
        emit("goto","");
    }
#line 1578 "A5_46.tab.c"
    break;

  case 4: /* changetable: %empty  */
#line 117 "A5_46.y"
    {    
        parST = ST;
        if(currSymbolPtr->nested==NULL) 
        {
            changeTable(new SymbolTable(""));    
        }
        else 
        {
            changeTable(currSymbolPtr ->nested);                        
            emit("Label", ST->name);
        }
    }
#line 1595 "A5_46.tab.c"
    break;

  case 5: /* primary_expression: IDENTIFIER  */
#line 132 "A5_46.y"
    {
        // create new expression and store pointer to ST entry in the location
        (yyval.expr)=new Expression();
        (yyval.expr)->loc=ST->lookupIdentifier(id);
    }
#line 1605 "A5_46.tab.c"
    break;

  case 6: /* primary_expression: INTEGER_CONSTANT  */
#line 139 "A5_46.y"
    { 
        (yyval.expr)=new Expression();    
        string p=convertIntToString((yyvsp[0].intval));
        (yyval.expr)->loc=gentemp(new SymbolType("int"),p);
        emit("=",(yyval.expr)->loc->name,p);
    }
#line 1616 "A5_46.tab.c"
    break;

  case 7: /* primary_expression: CHARACTER_CONSTANT  */
#line 146 "A5_46.y"
    {
        (yyval.expr)=new Expression();
        (yyval.expr)->loc=gentemp(new SymbolType("char"),(yyvsp[0].char_value));
        emit("=",(yyval.expr)->loc->name,string((yyvsp[0].char_value)));
    }
#line 1626 "A5_46.tab.c"
    break;

  case 8: /* primary_expression: STRING_LITERAL  */
#line 152 "A5_46.y"
    {
        (yyval.expr)=new Expression();
        (yyval.expr)->loc=gentemp(new SymbolType("ptr"),(yyvsp[0].char_value));
        (yyval.expr)->loc->type->arrtype=new SymbolType("char");
    }
#line 1636 "A5_46.tab.c"
    break;

  case 9: /* primary_expression: ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE  */
#line 158 "A5_46.y"
    {
        // simply equal to expression
        (yyval.expr)=(yyvsp[-1].expr);

        // if the expression is a boolean expression, then we need to store the result in it
        if((yyvsp[-1].expr)->type == "bool")
        {
            temp_rel = (yyvsp[-1].expr);
        }
    }
#line 1651 "A5_46.tab.c"
    break;

  case 10: /* postfix_expression: primary_expression  */
#line 172 "A5_46.y"
    {
        //create new Array and store the location of primary expression in it
        (yyval.A)=new Array();   

        // if the primary expression is not a boolean expression, then we can store the location in the array
        if((yyvsp[0].expr)->type != "bool")
        {
            (yyval.A)->Array=(yyvsp[0].expr)->loc;    
            (yyval.A)->type=(yyvsp[0].expr)->loc->type;    
            (yyval.A)->loc=(yyval.A)->Array;
        } 
        else
        {
            // if the primary expression is a boolean expression, then we need to store the information in Array
            (yyval.A)->atype = "bool_pass";
        }

    }
#line 1674 "A5_46.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression SQUARE_BRACKET_OPEN expression SQUARE_BRACKET_CLOSE  */
#line 191 "A5_46.y"
    {     
        // In the array access rule
        if((yyvsp[-3].A)->type->isArrayParam || (yyvsp[-3].A)->type->type == "ptr") {
            // Handle both regular pointers and array parameters
            (yyval.A)->type = (yyvsp[-3].A)->type->arrtype;
            (yyval.A)->Array = (yyvsp[-3].A)->Array;
            (yyval.A)->loc = gentemp(new SymbolType("int"));
            (yyval.A)->atype = "arr";
            // No need to multiply by element size for array parameters
            if((yyvsp[-3].A)->type->isArrayParam) {
                emit("=", (yyval.A)->loc->name, (yyvsp[-1].expr)->loc->name);  // Direct indexing 
            } else {
                int p = computeSize((yyval.A)->type);
                string str = convertIntToString(p);
                emit("*", (yyval.A)->loc->name, (yyvsp[-1].expr)->loc->name, str);
            }
        }
    }
#line 1697 "A5_46.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression ROUND_BRACKET_OPEN argument_expression_list_opt ROUND_BRACKET_CLOSE  */
#line 210 "A5_46.y"
    {
        // create new temporary and store the return value of the function in it
        (yyval.A)=new Array();    
        (yyval.A)->Array=gentemp((yyvsp[-3].A)->type);
        string str=convertIntToString((yyvsp[-1].num_params));
        emit("call",(yyval.A)->Array->name,(yyvsp[-3].A)->Array->name,str);
    }
#line 1709 "A5_46.tab.c"
    break;

  case 13: /* argument_expression_list_opt: argument_expression_list  */
#line 220 "A5_46.y"
    { 
        (yyval.num_params)=(yyvsp[0].num_params);
    }
#line 1717 "A5_46.tab.c"
    break;

  case 14: /* argument_expression_list_opt: %empty  */
#line 224 "A5_46.y"
    { 
        (yyval.num_params)=0;
    }
#line 1725 "A5_46.tab.c"
    break;

  case 15: /* argument_expression_list: assignment_expression  */
#line 230 "A5_46.y"
    {
        //one argument and emit param
        (yyval.num_params)=1;
        emit("param",(yyvsp[0].expr)->loc->name);    
    }
#line 1735 "A5_46.tab.c"
    break;

  case 16: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 236 "A5_46.y"
    {
        // add one to the number of arguments and emit param quad
        (yyval.num_params)=(yyvsp[-2].num_params)+1;
        emit("param",(yyvsp[0].expr)->loc->name);
    }
#line 1745 "A5_46.tab.c"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 243 "A5_46.y"
                                     { (yyval.A)=(yyvsp[0].A);}
#line 1751 "A5_46.tab.c"
    break;

  case 18: /* unary_expression: unary_operator unary_expression  */
#line 245 "A5_46.y"
    {
        (yyval.A)=new Array();
        switch((yyvsp[-1].unaryOp))
        {      
            //generate a new temporary and store the address of the expression in it and emit the quad
            case '&':
                (yyval.A)->Array=gentemp(new SymbolType("ptr"));
                (yyval.A)->Array->type->arrtype=(yyvsp[0].A)->Array->type; 
                emit("=&",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
                break;
            // change the type of the expression to pointer and emit the quad
            case '*':
                (yyval.A)->atype="ptr";
                (yyval.A)->Array=(yyvsp[0].A)->Array;
                break;
            // Similar case with + -  !
            case '+':  
                (yyval.A)=(yyvsp[0].A);
                break;
            case '-':                
                (yyval.A)->Array=gentemp(new SymbolType((yyvsp[0].A)->Array->type->type));
                emit("uminus",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
                break;
            case '~':
                (yyval.A)->Array=gentemp(new SymbolType((yyvsp[0].A)->Array->type->type));
                emit("~",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
                break;
            case '!': 
                if((yyvsp[0].A)->atype == "bool_pass")
                {
                    // if the expression is a boolean expression, then we need to change the truelist and falselist
                    list<int> l = temp_rel->truelist;
                    temp_rel->truelist = temp_rel->falselist;
                    temp_rel->falselist = l;
                    (yyval.A)->atype = "bool_pass";
                }               
                else
                {
                    // if the expression is not a boolean expression, then we need to store the value of the opposite of the expression in it
                    (yyval.A)->Array=gentemp(new SymbolType((yyvsp[0].A)->Array->type->type));
                    emit("!",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
                }

                break;
        }
    }
#line 1802 "A5_46.tab.c"
    break;

  case 19: /* unary_operator: BITWISE_AND  */
#line 294 "A5_46.y"
    { (yyval.unaryOp)='&'; }
#line 1808 "A5_46.tab.c"
    break;

  case 20: /* unary_operator: MUL  */
#line 296 "A5_46.y"
    {(yyval.unaryOp)='*'; }
#line 1814 "A5_46.tab.c"
    break;

  case 21: /* unary_operator: ADD  */
#line 298 "A5_46.y"
    { (yyval.unaryOp)='+'; }
#line 1820 "A5_46.tab.c"
    break;

  case 22: /* unary_operator: SUB  */
#line 300 "A5_46.y"
    { (yyval.unaryOp)='-'; }
#line 1826 "A5_46.tab.c"
    break;

  case 23: /* unary_operator: EXCLAIM  */
#line 302 "A5_46.y"
    {(yyval.unaryOp)='!'; }
#line 1832 "A5_46.tab.c"
    break;

  case 24: /* multiplicative_expression: unary_expression  */
#line 306 "A5_46.y"
    {
        // convert array indexes and pointers to temporary variables
        (yyval.expr) = new Expression();
        if((yyvsp[0].A)->atype=="arr")             
        {
            // dereference the array and store the value in a temporary variable
            (yyval.expr)->loc = gentemp((yyvsp[0].A)->Array->type->arrtype);    
            emit("=[]", (yyval.expr)->loc->name, (yyvsp[0].A)->Array->name, (yyvsp[0].A)->loc->name);
        }
        else if((yyvsp[0].A)->atype=="ptr")
        { 
            // dereference the pointer and store the value in a temporary variable
            Symbol* temp_s=gentemp((yyvsp[0].A)->Array->type->arrtype);
            emit("=*",temp_s->name,(yyvsp[0].A)->Array->name);
            (yyval.expr)->loc = temp_s;
        }
        else if((yyvsp[0].A)->atype == "bool_pass")
        {
            // if the expression is a boolean expression, then we need to store the value of the expression in a temporary variable
            (yyval.expr) = temp_rel;
        }
        else
        {
            (yyval.expr)->loc = (yyvsp[0].A)->Array;
        }
    }
#line 1863 "A5_46.tab.c"
    break;

  case 25: /* multiplicative_expression: multiplicative_expression MUL unary_expression  */
#line 333 "A5_46.y"
    { 
    // error in program, type conflict                       
        (yyval.expr) = new Expression(); 
        Symbol* temp_s; 


        if((yyvsp[0].A)->atype == "arr")
        {
            // dereference the array and store the value in a temporary variable
            temp_s = gentemp((yyvsp[0].A)->Array->type->arrtype);    
            emit("=[]", temp_s->name, (yyvsp[0].A)->Array->name, (yyvsp[0].A)->loc->name);
        } 
        else if((yyvsp[0].A)->atype == "ptr")
        {
            // dereference the pointer and store the value in a temporary variable
            temp_s = gentemp((yyvsp[0].A)->Array->type->arrtype);
            emit("=*",temp_s->name,(yyvsp[0].A)->Array->name);
        }
        else
        {
            temp_s = (yyvsp[0].A)->Array;
        }
        // multiply the two expressions and store the value in a temporary variable
        (yyval.expr)->loc = gentemp(new SymbolType((yyvsp[-2].expr)->loc->type->type));
        emit("*", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, temp_s->name);
    }
#line 1894 "A5_46.tab.c"
    break;

  case 26: /* multiplicative_expression: multiplicative_expression DIV unary_expression  */
#line 360 "A5_46.y"
    {       
        (yyval.expr) = new Expression(); 
        Symbol* temp_s;  

        if((yyvsp[0].A)->atype == "arr")
        {
            // dereference the array and store the value in a temporary variable
            temp_s = gentemp((yyvsp[0].A)->Array->type->arrtype);    
            emit("=[]", temp_s->name, (yyvsp[0].A)->Array->name, (yyvsp[0].A)->loc->name);
        } 
        else if((yyvsp[0].A)->atype == "ptr")
        {
            // dereference the pointer and store the value in a temporary variable
            temp_s = gentemp((yyvsp[0].A)->Array->type->arrtype);
            emit("=*",temp_s->name,(yyvsp[0].A)->Array->name);
        }
        else
        {
            temp_s = (yyvsp[0].A)->Array;
        }
        // divide the two expressions and store the value in a temporary variable
        (yyval.expr)->loc = gentemp(new SymbolType((yyvsp[-2].expr)->loc->type->type));
        emit("/", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, temp_s->name);
    }
#line 1923 "A5_46.tab.c"
    break;

  case 27: /* multiplicative_expression: multiplicative_expression MOD unary_expression  */
#line 385 "A5_46.y"
    {
        (yyval.expr) = new Expression(); 
        Symbol* temp_s;  
        if((yyvsp[0].A)->atype == "arr")
        {
            // dereference the array and store the value in a temporary variable
            temp_s = gentemp((yyvsp[0].A)->Array->type->arrtype);    
            emit("=[]", temp_s->name, (yyvsp[0].A)->Array->name, (yyvsp[0].A)->loc->name);
        } 
        else if((yyvsp[0].A)->atype == "ptr")
        {
            // dereference the pointer and store the value in a temporary variable
            temp_s = gentemp((yyvsp[0].A)->Array->type->arrtype);
            emit("=*",temp_s->name,(yyvsp[0].A)->Array->name);
        }
        else
        {
            temp_s = (yyvsp[0].A)->Array;
        }
        // modulo the two expressions and store the value in a temporary variable
        (yyval.expr)->loc = gentemp(new SymbolType((yyvsp[-2].expr)->loc->type->type));
        emit("%", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, temp_s->name);  
    }
#line 1951 "A5_46.tab.c"
    break;

  case 28: /* additive_expression: multiplicative_expression  */
#line 410 "A5_46.y"
                                                 { (yyval.expr)=(yyvsp[0].expr); }
#line 1957 "A5_46.tab.c"
    break;

  case 29: /* additive_expression: additive_expression ADD multiplicative_expression  */
#line 412 "A5_46.y"
    {
        // add the two expressions and store the value in a temporary variable
        (yyval.expr) = new Expression();    
        (yyval.expr)->loc = gentemp(new SymbolType((yyvsp[-2].expr)->loc->type->type));
        emit("+", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
    }
#line 1968 "A5_46.tab.c"
    break;

  case 30: /* additive_expression: additive_expression SUB multiplicative_expression  */
#line 419 "A5_46.y"
    { 
        // subtract the two expressions and store the value in a temporary variable
        (yyval.expr) = new Expression();    
        (yyval.expr)->loc = gentemp(new SymbolType((yyvsp[-2].expr)->loc->type->type));
        emit("-", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
    }
#line 1979 "A5_46.tab.c"
    break;

  case 31: /* relational_expression: additive_expression  */
#line 427 "A5_46.y"
                                             { (yyval.expr)=(yyvsp[0].expr); }
#line 1985 "A5_46.tab.c"
    break;

  case 32: /* relational_expression: relational_expression BIT_SL additive_expression  */
#line 430 "A5_46.y"
    {
        // change the relational expression to an if statement
        // saves the truelist and falselist of the relational expression to patch later
        // truelist is the list of instructions to be executed if the condition is true
        // falselist is the list of instructions to be executed if the condition is false
        (yyval.expr) = new Expression();
        (yyval.expr)->type = "bool";
        (yyval.expr)->truelist = makelist(nextinstr());
        (yyval.expr)->falselist = makelist(nextinstr()+1);
        emit("<", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        emit("goto", "");    
    }
#line 2002 "A5_46.tab.c"
    break;

  case 33: /* relational_expression: relational_expression BIT_SR additive_expression  */
#line 443 "A5_46.y"
    {   
        //change the relational expression to an if statement and save the truelist and falselist of the relational expression to patch later
        (yyval.expr) = new Expression();        
        (yyval.expr)->type = "bool";
        (yyval.expr)->truelist = makelist(nextinstr());
        (yyval.expr)->falselist = makelist(nextinstr()+1);
        emit(">", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        emit("goto", "");
    }
#line 2016 "A5_46.tab.c"
    break;

  case 34: /* relational_expression: relational_expression LTE additive_expression  */
#line 453 "A5_46.y"
    {   
         //change the relational expression to an if statement and save the truelist and falselist of the relational expression to patch later       
        (yyval.expr) = new Expression();        
        (yyval.expr)->type = "bool";
        (yyval.expr)->truelist = makelist(nextinstr());
        (yyval.expr)->falselist = makelist(nextinstr()+1);
        emit("<=", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        emit("goto", "");
    }
#line 2030 "A5_46.tab.c"
    break;

  case 35: /* relational_expression: relational_expression GTE additive_expression  */
#line 463 "A5_46.y"
    {  
         //change the relational expression to an if statement and save the truelist and falselist of the relational expression to patch later
        (yyval.expr) = new Expression();    
        (yyval.expr)->type = "bool";
        (yyval.expr)->truelist = makelist(nextinstr());
        (yyval.expr)->falselist = makelist(nextinstr()+1);
        emit(">=", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        emit("goto", "");
    }
#line 2044 "A5_46.tab.c"
    break;

  case 36: /* equality_expression: relational_expression  */
#line 474 "A5_46.y"
                                            { (yyval.expr)=(yyvsp[0].expr); }
#line 2050 "A5_46.tab.c"
    break;

  case 37: /* equality_expression: equality_expression EQ M relational_expression  */
#line 476 "A5_46.y"
    {
        // if the type of equality expression is bool, convert it to an integer and save 1 if true and 0 if false
        // patch the nextlist of the gotos created in conversion to int to the address of the next expression
        if(convertBoolToInt((yyvsp[-3].expr)) == 1)
        {
            backpatch((yyvsp[-3].expr)->nextlist, (yyvsp[-1].instr_number));
        }

        // if the type of relational expression is bool, convert it to an integer and save 1 if true and 0 if false
        // patch the nextlist of the gotos created in conversion to int to the address of the next expression
        if(convertBoolToInt((yyvsp[0].expr)) == 1)
        {
            backpatch((yyvsp[0].expr)->nextlist, nextinstr());
        }
        (yyval.expr) = new Expression();
        (yyval.expr)->type = "bool";
        (yyval.expr)->truelist = makelist(nextinstr());
        (yyval.expr)->falselist = makelist(nextinstr()+1); 
        emit("==", "", (yyvsp[-3].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        emit("goto", "");                
    }
#line 2076 "A5_46.tab.c"
    break;

  case 38: /* equality_expression: equality_expression NEQ M relational_expression  */
#line 498 "A5_46.y"
    {       
        // same as the above case    
        if(convertBoolToInt((yyvsp[-3].expr)) == 1)
        {
            backpatch((yyvsp[-3].expr)->nextlist, (yyvsp[-1].instr_number));
        }
        if(convertBoolToInt((yyvsp[0].expr)) == 1)
        {
            backpatch((yyvsp[0].expr)->nextlist, nextinstr());
        }
        (yyval.expr) = new Expression();
        (yyval.expr)->type = "bool";
        (yyval.expr)->truelist = makelist(nextinstr());
        (yyval.expr)->falselist = makelist(nextinstr()+1); 
        emit("!=", "", (yyvsp[-3].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        emit("goto", "");
    }
#line 2098 "A5_46.tab.c"
    break;

  case 39: /* and_helper: logical_and_expression AND  */
#line 520 "A5_46.y"
    {
        convertIntToBool((yyvsp[-1].expr));
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2107 "A5_46.tab.c"
    break;

  case 40: /* logical_and_expression: equality_expression  */
#line 526 "A5_46.y"
                                             { (yyval.expr)=(yyvsp[0].expr); }
#line 2113 "A5_46.tab.c"
    break;

  case 41: /* logical_and_expression: and_helper M equality_expression  */
#line 529 "A5_46.y"
    { 
        convertIntToBool((yyvsp[0].expr)); // convert the equality expression to bool
        (yyval.expr) = new Expression();
        (yyval.expr)->type = "bool";
        backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-1].instr_number)); // patch the truelist of the logical and expression to the address of the equality expression
        (yyval.expr)->truelist = (yyvsp[0].expr)->truelist; // save the truelist of the equality expression to the truelist of the logical and expression
        (yyval.expr)->falselist = merge((yyvsp[-2].expr)->falselist, (yyvsp[0].expr)->falselist); // save the falselist of the first expression and the falselist of the second expression to the falselist of the logical and expression
    }
#line 2126 "A5_46.tab.c"
    break;

  case 42: /* or_helper: logical_or_expression OR  */
#line 542 "A5_46.y"
    {
        convertIntToBool((yyvsp[-1].expr));
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2135 "A5_46.tab.c"
    break;

  case 43: /* logical_or_expression: logical_and_expression  */
#line 547 "A5_46.y"
                                                { (yyval.expr)=(yyvsp[0].expr); }
#line 2141 "A5_46.tab.c"
    break;

  case 44: /* logical_or_expression: or_helper M logical_and_expression  */
#line 550 "A5_46.y"
    { 
        convertIntToBool((yyvsp[0].expr));            
        (yyval.expr) = new Expression();            
        (yyval.expr)->type = "bool";
        backpatch((yyvsp[-2].expr)->falselist, (yyvsp[-1].instr_number));  // patch the falselist of the logical or expression to the address of the logical and expression   
        (yyval.expr)->truelist = merge((yyvsp[-2].expr)->truelist, (yyvsp[0].expr)->truelist);  // save the truelist of the first expression and the truelist of the second expression to the truelist of the logical or expression
        (yyval.expr)->falselist = (yyvsp[0].expr)->falselist;  // save the falselist of the logical and expression to the falselist of the logical or expression           
    }
#line 2154 "A5_46.tab.c"
    break;

  case 45: /* condition: logical_or_expression QUESTION  */
#line 563 "A5_46.y"
    {
        convertIntToBool((yyvsp[-1].expr));
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2163 "A5_46.tab.c"
    break;

  case 46: /* conditional_expression: logical_or_expression  */
#line 568 "A5_46.y"
                                              {(yyval.expr)=(yyvsp[0].expr);}
#line 2169 "A5_46.tab.c"
    break;

  case 47: /* conditional_expression: condition M expression N COLON M conditional_expression  */
#line 571 "A5_46.y"
    {
        // Generate temporary variable and then emit accordingly
        // convert the conditional expression to the correct format and handle backpatching
        // if the condition is true. then the result of the expression is saved in the temporary variable
        // if the condition is false, then the result of the conditional expression is saved in the temporary variable
        (yyval.expr)->loc = gentemp((yyvsp[-4].expr)->loc->type);
        (yyval.expr)->loc->update((yyvsp[-4].expr)->loc->type);
        emit("=", (yyval.expr)->loc->name, (yyvsp[0].expr)->loc->name);
        list<int> l = makelist(nextinstr());
        emit("goto", "");
        backpatch((yyvsp[-3].stat)->nextlist, nextinstr());
        emit("=", (yyval.expr)->loc->name, (yyvsp[-4].expr)->loc->name);
        list<int> m = makelist(nextinstr());
        l = merge(l, m);                        
        emit("goto", "");
        backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-5].instr_number));
        backpatch((yyvsp[-6].expr)->falselist, (yyvsp[-1].instr_number));
        backpatch(l, nextinstr());
    }
#line 2193 "A5_46.tab.c"
    break;

  case 48: /* assignment_expression: conditional_expression  */
#line 592 "A5_46.y"
                                              {(yyval.expr)=(yyvsp[0].expr);}
#line 2199 "A5_46.tab.c"
    break;

  case 49: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 594 "A5_46.y"
     {
        // different types of assignment expressions
        // array assignment expression
        if((yyvsp[-2].A)->atype=="arr")
        {
            (yyvsp[0].expr)->loc = convertType((yyvsp[0].expr)->loc, (yyvsp[-2].A)->type->type);
            emit("[]=", (yyvsp[-2].A)->Array->name, (yyvsp[-2].A)->loc->name, (yyvsp[0].expr)->loc->name);        
        }
        // pointer assignment expression
        else if((yyvsp[-2].A)->atype=="ptr")
        {
            emit("*=", (yyvsp[-2].A)->Array->name, (yyvsp[0].expr)->loc->name);    
        }
        // direct assignment expression
        else
        {
            (yyvsp[0].expr)->loc = convertType((yyvsp[0].expr)->loc, (yyvsp[-2].A)->Array->type->type);
            emit("=", (yyvsp[-2].A)->Array->name, (yyvsp[0].expr)->loc->name);
        }
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2225 "A5_46.tab.c"
    break;

  case 50: /* expression: assignment_expression  */
#line 617 "A5_46.y"
                                  {  (yyval.expr)=(yyvsp[0].expr);  }
#line 2231 "A5_46.tab.c"
    break;

  case 51: /* declaration: type_specifier init_declarator SEMICOLON  */
#line 621 "A5_46.y"
                                                      {    }
#line 2237 "A5_46.tab.c"
    break;

  case 52: /* init_declarator: declarator  */
#line 625 "A5_46.y"
                            {(yyval.symp)=(yyvsp[0].symp);}
#line 2243 "A5_46.tab.c"
    break;

  case 53: /* init_declarator: declarator ASSIGN initializer  */
#line 627 "A5_46.y"
    {
        // if the initializer is a constant, then the value of the constant is saved in the declarator
        if((yyvsp[0].symp)->val!="") (yyvsp[-2].symp)->val=(yyvsp[0].symp)->val;
        emit("=", (yyvsp[-2].symp)->name, (yyvsp[0].symp)->name);    
    }
#line 2253 "A5_46.tab.c"
    break;

  case 54: /* type_specifier: VOID  */
#line 635 "A5_46.y"
                       { var_type="void"; }
#line 2259 "A5_46.tab.c"
    break;

  case 55: /* type_specifier: CHAR  */
#line 636 "A5_46.y"
             { var_type="char"; }
#line 2265 "A5_46.tab.c"
    break;

  case 56: /* type_specifier: INT  */
#line 637 "A5_46.y"
            { var_type="int"; }
#line 2271 "A5_46.tab.c"
    break;

  case 57: /* declarator: pointer direct_declarator  */
#line 642 "A5_46.y"
    {
        // Pointer declarator
        SymbolType *t = (yyvsp[-1].sym_type);
        while(t->arrtype!=NULL) t = t->arrtype;
        t->arrtype = (yyvsp[0].symp)->type;
        (yyval.symp) = (yyvsp[0].symp)->update((yyvsp[-1].sym_type));
    }
#line 2283 "A5_46.tab.c"
    break;

  case 58: /* declarator: direct_declarator  */
#line 649 "A5_46.y"
                        {   }
#line 2289 "A5_46.tab.c"
    break;

  case 59: /* declarator_helper: IDENTIFIER ROUND_BRACKET_OPEN  */
#line 655 "A5_46.y"
{   

    Symbol* tem = ST->lookupIdentifier(id);
    if (tem == nullptr){
        tem = ST->lookupDeclarator(id);
    }
    (yyval.symp) = tem->update(new SymbolType(var_type));
    currSymbolPtr = (yyval.symp); 
}
#line 2303 "A5_46.tab.c"
    break;

  case 60: /* direct_declarator: IDENTIFIER  */
#line 666 "A5_46.y"
    {
        // assignment to different identifier
        Symbol* tem = ST->lookupDeclarator(id);
        // type of the identifier is saved in the global variable var_type
        (yyval.symp) = tem->update(new SymbolType(var_type));
        currSymbolPtr = (yyval.symp);    
    }
#line 2315 "A5_46.tab.c"
    break;

  case 61: /* direct_declarator: IDENTIFIER SQUARE_BRACKET_OPEN INTEGER_CONSTANT SQUARE_BRACKET_CLOSE  */
#line 674 "A5_46.y"
    {
        // array declarator
        // size of the array is saved in the symbol table
        Symbol *tem = ST->lookupDeclarator(id);
        (yyval.symp) = tem->update(new SymbolType(var_type));
        currSymbolPtr = (yyval.symp);    
        SymbolType* s = new SymbolType("arr", tem->type, (yyvsp[-1].intval));
        (yyval.symp) = tem->update(s);
    }
#line 2329 "A5_46.tab.c"
    break;

  case 62: /* direct_declarator: IDENTIFIER SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE  */
#line 684 "A5_46.y"
    {
        // Array parameter with empty brackets (e.g., arr[])
        Symbol *tem = ST->lookupDeclarator(id);
        (yyval.symp) = tem->update(new SymbolType(var_type));
        currSymbolPtr = (yyval.symp);    
        
        // Create array type but with special handling for parameters
        SymbolType* s = new SymbolType("ptr", tem->type);  // Use ptr instead of arr
        s->isArrayParam = true;  // Add this field to your SymbolType class
        (yyval.symp) = tem->update(s);
        
        // Debug output
        cout << "Debug: Array parameter " << id << " declared as pointer" << endl;
    }
#line 2348 "A5_46.tab.c"
    break;

  case 63: /* direct_declarator: declarator_helper changetable parameter_list_opt ROUND_BRACKET_CLOSE  */
#line 699 "A5_46.y"
    {
        // function declarator
        // return type of the function is saved in the symbol table
        // parameters of the function are saved in the symbol table
        ST->name = (yyvsp[-3].symp)->name;    
        if((yyvsp[-3].symp)->type->type !="void") 
        {
            Symbol *s = ST->lookupIdentifier("return");
            if (s==nullptr){
                s = ST->lookupDeclarator("return");
            }
            s->update((yyvsp[-3].symp)->type);        
        }
        (yyvsp[-3].symp)->nested=ST;       
        ST->parent = globalST;
        changeTable(globalST);                
        currSymbolPtr = (yyval.symp);
    }
#line 2371 "A5_46.tab.c"
    break;

  case 64: /* pointer: MUL  */
#line 720 "A5_46.y"
    { 
        (yyval.sym_type) = new SymbolType("ptr");
    }
#line 2379 "A5_46.tab.c"
    break;

  case 65: /* parameter_list_opt: parameter_list  */
#line 725 "A5_46.y"
                                   { }
#line 2385 "A5_46.tab.c"
    break;

  case 67: /* parameter_list: parameter_declaration  */
#line 729 "A5_46.y"
                                        {  }
#line 2391 "A5_46.tab.c"
    break;

  case 68: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 730 "A5_46.y"
                                                    {  }
#line 2397 "A5_46.tab.c"
    break;

  case 69: /* parameter_declaration: type_specifier declarator  */
#line 733 "A5_46.y"
                                                   {  }
#line 2403 "A5_46.tab.c"
    break;

  case 70: /* parameter_declaration: type_specifier  */
#line 734 "A5_46.y"
                        {  }
#line 2409 "A5_46.tab.c"
    break;

  case 71: /* initializer: assignment_expression  */
#line 738 "A5_46.y"
                                     { (yyval.symp)=(yyvsp[0].expr)->loc; }
#line 2415 "A5_46.tab.c"
    break;

  case 72: /* statement: compound_statement  */
#line 742 "A5_46.y"
                                { (yyval.stat)=(yyvsp[0].stat); }
#line 2421 "A5_46.tab.c"
    break;

  case 73: /* statement: expression_statement  */
#line 744 "A5_46.y"
    { 
        (yyval.stat)=new Statement();
        (yyval.stat)->nextlist=(yyvsp[0].expr)->nextlist; 
    }
#line 2430 "A5_46.tab.c"
    break;

  case 74: /* statement: selection_statement  */
#line 748 "A5_46.y"
                            { (yyval.stat)=(yyvsp[0].stat); }
#line 2436 "A5_46.tab.c"
    break;

  case 75: /* statement: iteration_statement  */
#line 749 "A5_46.y"
                            { (yyval.stat)=(yyvsp[0].stat); }
#line 2442 "A5_46.tab.c"
    break;

  case 76: /* statement: jump_statement  */
#line 750 "A5_46.y"
                       { (yyval.stat)=(yyvsp[0].stat); }
#line 2448 "A5_46.tab.c"
    break;

  case 77: /* compound_statement: CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE  */
#line 754 "A5_46.y"
    { 
        (yyval.stat)=(yyvsp[-1].stat); 
    }
#line 2456 "A5_46.tab.c"
    break;

  case 78: /* block_item_list_opt: %empty  */
#line 759 "A5_46.y"
                             { (yyval.stat)=new Statement(); }
#line 2462 "A5_46.tab.c"
    break;

  case 79: /* block_item_list_opt: block_item_list  */
#line 760 "A5_46.y"
                        { (yyval.stat)=(yyvsp[0].stat); }
#line 2468 "A5_46.tab.c"
    break;

  case 80: /* block_item_list: block_item  */
#line 765 "A5_46.y"
                              { (yyval.stat)=(yyvsp[0].stat); }
#line 2474 "A5_46.tab.c"
    break;

  case 81: /* block_item_list: block_item_list M block_item  */
#line 767 "A5_46.y"
    { 
        (yyval.stat)=(yyvsp[0].stat);
        backpatch((yyvsp[-2].stat)->nextlist,(yyvsp[-1].instr_number));
    }
#line 2483 "A5_46.tab.c"
    break;

  case 82: /* block_item: declaration  */
#line 773 "A5_46.y"
                          { (yyval.stat)=new Statement(); }
#line 2489 "A5_46.tab.c"
    break;

  case 83: /* block_item: statement  */
#line 774 "A5_46.y"
                  { (yyval.stat)=(yyvsp[0].stat); }
#line 2495 "A5_46.tab.c"
    break;

  case 84: /* expression_statement: expression SEMICOLON  */
#line 777 "A5_46.y"
                                           {(yyval.expr)=(yyvsp[-1].expr);}
#line 2501 "A5_46.tab.c"
    break;

  case 85: /* expression_statement: SEMICOLON  */
#line 778 "A5_46.y"
                {(yyval.expr) = new Expression();}
#line 2507 "A5_46.tab.c"
    break;

  case 86: /* if_helper: IF ROUND_BRACKET_OPEN expression  */
#line 783 "A5_46.y"
    {
        convertIntToBool((yyvsp[0].expr));
        (yyval.expr) = (yyvsp[0].expr);   
    }
#line 2516 "A5_46.tab.c"
    break;

  case 87: /* selection_statement: if_helper ROUND_BRACKET_CLOSE M statement  */
#line 790 "A5_46.y"
    {
        // if the expression is true, then the statement is executed
        (yyval.stat) = new Statement();
        backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].instr_number));
        // if the expression is false, then the next statement is executed
        (yyval.stat)->nextlist = merge((yyvsp[-3].expr)->falselist, (yyvsp[0].stat)->nextlist);
    }
#line 2528 "A5_46.tab.c"
    break;

  case 88: /* selection_statement: if_helper ROUND_BRACKET_CLOSE M statement N ELSE M statement  */
#line 798 "A5_46.y"
    {   
        // if the expression is true, then the first statement is executed
        // if the expression is false, then the second statement is executed
        (yyval.stat) = new Statement();
        backpatch((yyvsp[-7].expr)->truelist, (yyvsp[-5].instr_number));
        backpatch((yyvsp[-7].expr)->falselist, (yyvsp[-1].instr_number));
        // the nextlist is the nextlist of the first statement and the second statement
        list<int> temp = merge((yyvsp[-4].stat)->nextlist, (yyvsp[-3].stat)->nextlist);
        (yyval.stat)->nextlist = merge((yyvsp[0].stat)->nextlist,temp);    
    }
#line 2543 "A5_46.tab.c"
    break;

  case 89: /* iteration_statement: FOR ROUND_BRACKET_OPEN expression_statement M expression_statement M expression N ROUND_BRACKET_CLOSE M statement  */
#line 811 "A5_46.y"
    {
        // the first expression is executed
        // if the expression is true, then the statement is executed
        // the third expression is executed
        // the second expression is executed
        // if the expression is true, then the statement is executed
        // else the next statement is executed
        (yyval.stat) = new Statement();        
        convertIntToBool((yyvsp[-6].expr));
        backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].instr_number));    
        backpatch((yyvsp[-3].stat)->nextlist, (yyvsp[-7].instr_number));    
        backpatch((yyvsp[0].stat)->nextlist, (yyvsp[-5].instr_number));    
        string str=convertIntToString((yyvsp[-5].instr_number));
        emit("goto", str);                
        (yyval.stat)->nextlist = (yyvsp[-6].expr)->falselist;
    }
#line 2564 "A5_46.tab.c"
    break;

  case 90: /* jump_statement: RETURN expression SEMICOLON  */
#line 831 "A5_46.y"
    {
        (yyval.stat) = new Statement();    
        emit("return",(yyvsp[-1].expr)->loc->name);
    }
#line 2573 "A5_46.tab.c"
    break;

  case 91: /* jump_statement: RETURN SEMICOLON  */
#line 836 "A5_46.y"
    {
        (yyval.stat) = new Statement();    
        emit("return","");                         
    }
#line 2582 "A5_46.tab.c"
    break;

  case 92: /* translation_unit: external_declaration  */
#line 843 "A5_46.y"
                                       { }
#line 2588 "A5_46.tab.c"
    break;

  case 93: /* translation_unit: translation_unit external_declaration  */
#line 844 "A5_46.y"
                                            { }
#line 2594 "A5_46.tab.c"
    break;

  case 94: /* external_declaration: function_definition  */
#line 847 "A5_46.y"
                                          {  }
#line 2600 "A5_46.tab.c"
    break;

  case 95: /* external_declaration: declaration  */
#line 848 "A5_46.y"
                    {  }
#line 2606 "A5_46.tab.c"
    break;

  case 96: /* function_definition: type_specifier declarator changetable CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE  */
#line 852 "A5_46.y"
    {
        // function definition
        // the function name is saved in the symbol table
        // the return type of the function is saved in the symbol table
        int next_instr=0;         
        ST->parent=globalST;
        table_count = 0;
        label_table.clear();
        changeTable(globalST);
    }
#line 2621 "A5_46.tab.c"
    break;


#line 2625 "A5_46.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 864 "A5_46.y"


void yyerror(string s) {
    cout<<s<<endl;
}
