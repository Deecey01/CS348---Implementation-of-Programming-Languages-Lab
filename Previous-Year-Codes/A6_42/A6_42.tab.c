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
#line 1 "A6_42.y"

    #include "A6_42_translator.h"
    extern int yylex();
    extern int lineCount;
    void yyerror(string);
    void yyinfo(string);

#line 79 "A6_42.tab.c"

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

#include "A6_42.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ADDRESS = 7,                    /* ADDRESS  */
  YYSYMBOL_INTTYPE = 8,                    /* INTTYPE  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_INVALID_TOKEN = 10,             /* INVALID_TOKEN  */
  YYSYMBOL_VOIDTYPE = 11,                  /* VOIDTYPE  */
  YYSYMBOL_IDENTIFIER = 12,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 13,          /* INTEGER_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 14,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 15,            /* STRING_LITERAL  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 16,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_SLASH = 17,                     /* SLASH  */
  YYSYMBOL_QUESTION_MARK = 18,             /* QUESTION_MARK  */
  YYSYMBOL_ASSIGNMENT = 19,                /* ASSIGNMENT  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 21,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_LEFT_PARENTHESES = 22,          /* LEFT_PARENTHESES  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 23,        /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 24,       /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_ARROW = 25,                     /* ARROW  */
  YYSYMBOL_ASTERISK = 26,                  /* ASTERISK  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_EXCLAMATION = 29,               /* EXCLAMATION  */
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_LESS_THAN = 31,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 32,              /* GREATER_THAN  */
  YYSYMBOL_LESS_EQUAL_THAN = 33,           /* LESS_EQUAL_THAN  */
  YYSYMBOL_GREATER_EQUAL_THAN = 34,        /* GREATER_EQUAL_THAN  */
  YYSYMBOL_COLON = 35,                     /* COLON  */
  YYSYMBOL_SEMI_COLON = 36,                /* SEMI_COLON  */
  YYSYMBOL_RIGHT_PARENTHESES = 37,         /* RIGHT_PARENTHESES  */
  YYSYMBOL_EQUALS = 38,                    /* EQUALS  */
  YYSYMBOL_LOGICAL_AND = 39,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 40,                /* LOGICAL_OR  */
  YYSYMBOL_NOT_EQUALS = 41,                /* NOT_EQUALS  */
  YYSYMBOL_THEN = 42,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_primary_expression = 44,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 45,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 46, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 47,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 48,          /* unary_expression  */
  YYSYMBOL_unary_operator = 49,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 50, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 51,       /* additive_expression  */
  YYSYMBOL_relational_expression = 52,     /* relational_expression  */
  YYSYMBOL_equality_expression = 53,       /* equality_expression  */
  YYSYMBOL_M = 54,                         /* M  */
  YYSYMBOL_N = 55,                         /* N  */
  YYSYMBOL_logical_AND_expression = 56,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 57,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 58,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 59,     /* assignment_expression  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_constant_expression = 61,       /* constant_expression  */
  YYSYMBOL_declaration = 62,               /* declaration  */
  YYSYMBOL_init_declarator_list_opt = 63,  /* init_declarator_list_opt  */
  YYSYMBOL_declaration_specifiers = 64,    /* declaration_specifiers  */
  YYSYMBOL_declaration_specifiers_opt = 65, /* declaration_specifiers_opt  */
  YYSYMBOL_init_declarator_list = 66,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 67,           /* init_declarator  */
  YYSYMBOL_type_specifier = 68,            /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 69,  /* specifier_qualifier_list  */
  YYSYMBOL_specifier_qualifier_list_opt = 70, /* specifier_qualifier_list_opt  */
  YYSYMBOL_type_qualifier = 71,            /* type_qualifier  */
  YYSYMBOL_declarator = 72,                /* declarator  */
  YYSYMBOL_change_scope = 73,              /* change_scope  */
  YYSYMBOL_direct_declarator = 74,         /* direct_declarator  */
  YYSYMBOL_type_qualifier_list_opt = 75,   /* type_qualifier_list_opt  */
  YYSYMBOL_pointer = 76,                   /* pointer  */
  YYSYMBOL_type_qualifier_list = 77,       /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 78,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 79,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 80,     /* parameter_declaration  */
  YYSYMBOL_identifier_list = 81,           /* identifier_list  */
  YYSYMBOL_type_name = 82,                 /* type_name  */
  YYSYMBOL_initialiser = 83,               /* initialiser  */
  YYSYMBOL_initialiser_list = 84,          /* initialiser_list  */
  YYSYMBOL_designation_opt = 85,           /* designation_opt  */
  YYSYMBOL_designation = 86,               /* designation  */
  YYSYMBOL_designator_list = 87,           /* designator_list  */
  YYSYMBOL_designator = 88,                /* designator  */
  YYSYMBOL_statement = 89,                 /* statement  */
  YYSYMBOL_compound_statement = 90,        /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 91,       /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 92,           /* block_item_list  */
  YYSYMBOL_block_item = 93,                /* block_item  */
  YYSYMBOL_expression_statement = 94,      /* expression_statement  */
  YYSYMBOL_expression_opt = 95,            /* expression_opt  */
  YYSYMBOL_selection_statement = 96,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 97,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 98,            /* jump_statement  */
  YYSYMBOL_translation_unit = 99,          /* translation_unit  */
  YYSYMBOL_external_declaration = 100,     /* external_declaration  */
  YYSYMBOL_function_definition = 101,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 102,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 103          /* declaration_list  */
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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   140,   148,   155,   164,   172,   181,   201,
     210,   214,   218,   227,   233,   241,   248,   258,   263,   292,
     297,   302,   307,   312,   323,   339,   362,   385,   411,   416,
     427,   445,   450,   464,   478,   492,   509,   514,   530,   551,
     558,   569,   574,   588,   593,   607,   612,   632,   637,   660,
     665,   672,   681,   688,   693,   699,   703,   710,   715,   721,
     725,   732,   737,   751,   756,   764,   768,   775,   780,   788,
     797,   806,   813,   826,   832,   837,   841,   845,   861,   878,
     882,   886,   902,   906,   925,   930,   938,   944,   953,   957,
     964,   972,   976,   983,   989,   996,  1000,  1007,  1014,  1019,
    1023,  1030,  1034,  1041,  1046,  1052,  1059,  1063,  1070,  1080,
    1085,  1091,  1096,  1101,  1112,  1120,  1126,  1133,  1138,  1148,
    1153,  1161,  1169,  1175,  1184,  1192,  1206,  1217,  1224,  1239,
    1243,  1250,  1254,  1261,  1274,  1279,  1285,  1289
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
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "ELSE", "FOR",
  "IF", "ADDRESS", "INTTYPE", "RETURN", "INVALID_TOKEN", "VOIDTYPE",
  "IDENTIFIER", "INTEGER_CONSTANT", "CHARACTER_CONSTANT", "STRING_LITERAL",
  "LEFT_SQUARE_BRACKET", "SLASH", "QUESTION_MARK", "ASSIGNMENT", "COMMA",
  "RIGHT_SQUARE_BRACKET", "LEFT_PARENTHESES", "LEFT_CURLY_BRACKET",
  "RIGHT_CURLY_BRACKET", "ARROW", "ASTERISK", "PLUS", "MINUS",
  "EXCLAMATION", "MODULO", "LESS_THAN", "GREATER_THAN", "LESS_EQUAL_THAN",
  "GREATER_EQUAL_THAN", "COLON", "SEMI_COLON", "RIGHT_PARENTHESES",
  "EQUALS", "LOGICAL_AND", "LOGICAL_OR", "NOT_EQUALS", "THEN", "$accept",
  "primary_expression", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "M", "N", "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "expression",
  "constant_expression", "declaration", "init_declarator_list_opt",
  "declaration_specifiers", "declaration_specifiers_opt",
  "init_declarator_list", "init_declarator", "type_specifier",
  "specifier_qualifier_list", "specifier_qualifier_list_opt",
  "type_qualifier", "declarator", "change_scope", "direct_declarator",
  "type_qualifier_list_opt", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "initialiser", "initialiser_list",
  "designation_opt", "designation", "designator_list", "designator",
  "statement", "compound_statement", "block_item_list_opt",
  "block_item_list", "block_item", "expression_statement",
  "expression_opt", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list_opt", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-136)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     103,  -146,  -146,  -146,  -146,    72,   103,   103,   105,  -146,
    -146,  -146,    72,    22,    24,    67,  -146,    13,    99,    49,
    -146,  -146,  -146,  -146,  -146,    33,  -146,    66,    22,  -146,
      72,   288,  -146,    72,  -146,   103,   218,    95,    99,  -146,
    -146,  -146,  -146,   104,  -146,  -146,  -146,  -146,  -146,   127,
     111,  -146,  -146,  -146,  -146,  -146,     6,   114,   306,    74,
      91,   112,    87,    98,    11,  -146,  -146,  -146,   128,  -146,
    -146,   138,   143,   245,  -146,    12,    44,  -146,    45,   103,
    -146,   103,   135,   306,    10,   288,  -146,   113,  -146,   306,
     306,   153,   306,  -146,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,  -146,  -146,   166,   168,  -146,
    -146,  -146,   164,   165,  -146,    72,   150,   169,  -146,   180,
    -146,   306,  -146,  -146,  -146,  -146,   170,  -146,  -146,   177,
      42,  -146,  -146,  -146,  -146,   137,   162,   181,  -146,  -146,
    -146,  -146,  -146,  -146,    74,    74,    91,    91,    91,    91,
     112,   112,   306,   306,  -146,   178,   188,   306,   168,   182,
    -146,  -146,  -146,   192,   193,  -146,  -146,   183,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,   103,  -146,  -146,   111,  -146,
    -146,   288,  -146,  -146,   306,    87,    98,   306,   127,   306,
     184,   194,  -146,   200,  -146,  -146,   100,  -146,  -146,   182,
     306,   198,    48,  -146,  -146,  -146,    73,  -146,   189,   199,
    -146,  -146,  -146,  -146,   306,   306,   270,   306,   201,   205,
    -146,  -146,   270,  -146,   232,  -146,   306,  -146,  -146,   270,
     206,  -146,  -146,   270,  -146
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    69,    64,    63,   132,    54,    58,    58,     0,   129,
     131,    73,     0,    85,     0,    53,    59,    61,    71,     0,
      57,    55,    56,     1,   130,     0,    88,    86,    84,    52,
       0,     0,   136,    54,    72,   134,     0,    72,    70,    74,
      87,    89,    60,    61,    23,     2,     3,     4,     5,     0,
     104,    19,    20,    21,    22,     7,    17,    24,     0,    28,
      31,    36,    41,    43,    45,    47,    98,    62,     0,   137,
      78,    19,     0,     0,    95,     0,     0,    49,     0,    68,
      97,    68,     0,     0,     0,     0,   103,     0,   106,     0,
      14,     0,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    39,     0,   116,    80,
      77,    76,    19,     0,    83,    94,     0,    90,    91,     0,
      82,     0,     6,    67,    65,    66,     0,    24,    51,     0,
     104,    99,   101,   105,   107,     0,     0,    13,    15,    10,
      48,    26,    25,    27,    29,    30,    32,    33,    34,    35,
      37,    38,     0,     0,    39,     0,     0,   123,   116,   122,
     119,   120,   109,     0,    39,   117,   110,     0,   111,   112,
     113,    79,    75,    93,    81,     0,    96,    50,   104,   108,
     100,     0,     8,     9,     0,    42,    44,     0,   123,     0,
       0,     0,   133,   123,   121,    92,     0,   102,    16,    40,
     123,     0,     0,   128,   114,   118,   104,    11,     0,     0,
      39,    39,    12,    39,   123,   123,   123,     0,     0,     0,
      40,    46,   123,    39,   124,   127,   123,    39,    40,   123,
       0,   125,    39,   123,   126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,  -146,   -57,  -146,    50,    68,    58,
      85,  -101,  -145,    89,  -146,   -81,   -18,   -37,  -146,     0,
    -146,     3,   242,  -146,   220,   -22,   202,   172,    20,     2,
     217,   236,  -146,   229,   225,  -146,  -146,    88,  -146,  -146,
     -79,    84,  -126,  -146,  -146,   191,  -143,  -146,   106,  -146,
      75,  -146,  -138,  -146,  -146,  -146,  -146,   257,  -146,  -146,
    -146
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    55,    56,   136,   137,    57,    58,    59,    60,    61,
      62,   152,   107,    63,    64,    65,    77,   159,   129,   160,
      14,    33,    21,    15,    16,     6,   123,   124,     7,    43,
      68,    18,    27,    19,    28,   116,   117,   118,    76,    82,
      67,    84,    85,    86,    87,    88,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,     8,     9,    10,    34,
      35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    93,   128,     5,   181,   153,   132,    17,     4,    20,
      20,     5,    78,    66,    25,     1,     1,    32,    72,   190,
       2,     2,    89,     3,     3,     1,   127,    79,    90,   -40,
     130,    91,    31,    26,   131,    69,  -135,   141,   142,   143,
     127,   127,   127,   127,   127,   127,   127,   127,    41,   114,
     201,   106,   135,   187,   208,   113,    26,    79,    83,    79,
      29,    11,   209,   193,   119,   121,   180,    66,   121,    81,
      39,    12,   138,   220,   140,   224,   218,   219,   115,   225,
     181,   120,   122,   230,    11,   211,   231,    30,   228,    83,
     234,    94,    13,    41,    12,   127,   127,   212,    13,    81,
      95,    81,   197,   177,    96,    23,     1,    74,     1,   215,
     216,     2,   217,     2,     3,    36,     3,   173,    97,    98,
     206,    37,   226,    31,   207,   103,   229,    83,   104,    83,
       1,   233,   133,    92,    44,     2,   221,   105,     3,    45,
      46,    47,    48,    99,   100,   101,   102,   144,   145,    49,
     199,   108,   202,    51,    52,    53,    54,   121,   182,   109,
     127,   150,   151,    66,   110,   139,   198,   146,   147,   148,
     149,     1,   126,   155,   156,    44,     2,   157,   115,     3,
      45,    46,    47,    48,   154,   171,   172,   174,   200,   175,
      49,   158,   176,   178,    51,    52,    53,    54,   179,   183,
     188,   184,   121,     1,  -123,   155,   156,    44,     2,   157,
     189,     3,    45,    46,    47,    48,   192,  -115,   204,   194,
     203,     1,    49,   158,   213,    44,    51,    52,    53,    54,
      45,    46,    47,    48,   210,   214,   227,   185,   222,    70,
      49,   223,   186,   232,    71,    52,    53,    54,     1,    22,
      42,    80,    44,   125,    75,    38,    40,    45,    46,    47,
      48,    73,   196,   195,   191,    24,   111,    49,   205,     0,
       0,   112,    52,    53,    54,   155,   156,    44,   134,   157,
       0,     0,    45,    46,    47,    48,     0,     0,     0,     0,
       0,     0,    49,   158,     0,    44,    51,    52,    53,    54,
      45,    46,    47,    48,     0,     0,     0,     0,     0,     0,
      49,    50,     0,    44,    51,    52,    53,    54,    45,    46,
      47,    48,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,    51,    52,    53,    54
};

static const yytype_int16 yycheck[] =
{
       0,    58,    83,     0,   130,   106,    85,     5,     8,     6,
       7,     8,    49,    31,    12,     3,     3,    17,    36,   157,
       8,     8,    16,    11,    11,     3,    83,    49,    22,    18,
      20,    25,    19,    13,    24,    35,    23,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    28,    37,
     188,    40,    89,   154,   199,    73,    36,    79,    16,    81,
      36,    12,   200,   164,    20,    20,    24,    85,    20,    49,
      37,    22,    90,   216,    92,   220,   214,   215,    75,   222,
     206,    37,    37,   228,    12,    37,   229,    20,   226,    16,
     233,    17,    26,    73,    22,   152,   153,    24,    26,    79,
      26,    81,   181,   121,    30,     0,     3,    12,     3,   210,
     211,     8,   213,     8,    11,    16,    11,   115,    27,    28,
      20,    22,   223,    19,    24,    38,   227,    16,    41,    16,
       3,   232,    19,    19,     7,     8,   217,    39,    11,    12,
      13,    14,    15,    31,    32,    33,    34,    97,    98,    22,
     187,    23,   189,    26,    27,    28,    29,    20,    21,    21,
     217,   103,   104,   181,    21,    12,   184,    99,   100,   101,
     102,     3,    37,     5,     6,     7,     8,     9,   175,    11,
      12,    13,    14,    15,    18,    21,    21,    37,   188,    20,
      22,    23,    12,    23,    26,    27,    28,    29,    21,    37,
      22,    20,    20,     3,    36,     5,     6,     7,     8,     9,
      22,    11,    12,    13,    14,    15,    24,    24,    24,    36,
      36,     3,    22,    23,    35,     7,    26,    27,    28,    29,
      12,    13,    14,    15,    36,    36,     4,   152,    37,    21,
      22,    36,   153,    37,    26,    27,    28,    29,     3,     7,
      30,    49,     7,    81,    37,    19,    27,    12,    13,    14,
      15,    36,   178,   175,   158,     8,    21,    22,   193,    -1,
      -1,    26,    27,    28,    29,     5,     6,     7,    87,     9,
      -1,    -1,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    -1,     7,    26,    27,    28,    29,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,     7,    26,    27,    28,    29,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     8,    11,    62,    64,    68,    71,    99,   100,
     101,    12,    22,    26,    63,    66,    67,    72,    74,    76,
      64,    65,    65,     0,   100,    72,    71,    75,    77,    36,
      20,    19,    62,    64,   102,   103,    16,    22,    74,    37,
      76,    71,    67,    72,     7,    12,    13,    14,    15,    22,
      23,    26,    27,    28,    29,    44,    45,    48,    49,    50,
      51,    52,    53,    56,    57,    58,    59,    83,    73,    62,
      21,    26,    59,    77,    12,    73,    81,    59,    60,    68,
      69,    71,    82,    16,    84,    85,    86,    87,    88,    16,
      22,    25,    19,    48,    17,    26,    30,    27,    28,    31,
      32,    33,    34,    38,    41,    39,    40,    55,    23,    21,
      21,    21,    26,    59,    37,    64,    78,    79,    80,    20,
      37,    20,    37,    69,    70,    70,    37,    48,    58,    61,
      20,    24,    83,    19,    88,    60,    46,    47,    59,    12,
      59,    48,    48,    48,    50,    50,    51,    51,    51,    51,
      52,    52,    54,    54,    18,     5,     6,     9,    23,    60,
      62,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    21,    21,    72,    37,    20,    12,    59,    23,    21,
      24,    85,    21,    37,    20,    53,    56,    54,    22,    22,
      95,    91,    24,    54,    36,    80,    84,    83,    59,    60,
      62,    95,    60,    36,    24,    93,    20,    24,    55,    95,
      36,    37,    24,    35,    36,    54,    54,    54,    95,    95,
      89,    58,    37,    36,    55,    89,    54,     4,    95,    54,
      55,    89,    37,    54,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    44,    45,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    49,    49,    50,    50,    50,    50,    51,    51,
      51,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    79,    79,    80,    80,    81,    81,    82,    83,    83,
      83,    84,    84,    85,    85,    86,    87,    87,    88,    89,
      89,    89,    89,    89,    90,    91,    91,    92,    92,    93,
      93,    94,    95,    95,    96,    96,    97,    97,    98,    99,
      99,   100,   100,   101,   102,   102,   103,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     4,
       3,     6,     7,     1,     0,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     0,
       0,     1,     4,     1,     4,     1,     9,     1,     3,     1,
       3,     1,     3,     1,     0,     2,     2,     1,     0,     1,
       3,     1,     3,     1,     1,     2,     2,     1,     0,     1,
       2,     1,     0,     1,     3,     5,     4,     4,     3,     5,
       4,     5,     4,     4,     1,     0,     2,     3,     1,     2,
       1,     1,     3,     2,     1,     1,     3,     1,     1,     3,
       4,     2,     4,     1,     0,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     1,     3,     1,
       1,     2,     1,     0,     7,    10,    13,     8,     3,     1,
       2,     1,     1,     7,     1,     0,     1,     2
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
#line 134 "A6_42.y"
                        { 
                            yyinfo("primary_expression => IDENTIFIER");
                            (yyval.expression) = new Expression(); 
                            (yyval.expression)->symbol = (yyvsp[0].symbol);
                            (yyval.expression)->type = Expression::NONBOOLEAN; 
                        }
#line 1377 "A6_42.tab.c"
    break;

  case 3: /* primary_expression: INTEGER_CONSTANT  */
#line 141 "A6_42.y"
                        { 
                            yyinfo("primary_expression => INTEGER_CONSTANT"); 
                            (yyval.expression) = new Expression();
                            (yyval.expression)->symbol = gentemp(SymbolType::INT, toString((yyvsp[0].intVal)));
                            emit("=", (yyval.expression)->symbol->name, (yyvsp[0].intVal));
                        }
#line 1388 "A6_42.tab.c"
    break;

  case 4: /* primary_expression: CHARACTER_CONSTANT  */
#line 149 "A6_42.y"
                        { 
                            yyinfo("primary_expression => CHARACTER_CONSTANT"); 
                            (yyval.expression) = new Expression();
                            (yyval.expression)->symbol = gentemp(SymbolType::CHAR, (yyvsp[0].charVal));
                            emit("=", (yyval.expression)->symbol->name, (yyvsp[0].charVal));
                        }
#line 1399 "A6_42.tab.c"
    break;

  case 5: /* primary_expression: STRING_LITERAL  */
#line 156 "A6_42.y"
                        { 
                            yyinfo("primary_expression => STRING_LITERAL"); 
                            (yyval.expression) = new Expression();
		                    (yyval.expression)->symbol = gentemp(SymbolType::POINTER, (yyvsp[0].stringVal));
		                    (yyval.expression)->symbol->type->arrayType = new SymbolType(SymbolType::CHAR);
                            emit("=str", (yyval.expression)->symbol->name, stringLiterals.size());
                            stringLiterals.push_back((yyvsp[0].stringVal));
                        }
#line 1412 "A6_42.tab.c"
    break;

  case 6: /* primary_expression: LEFT_PARENTHESES expression RIGHT_PARENTHESES  */
#line 165 "A6_42.y"
                        { 
                            yyinfo("primary_expression => ( expression )"); 
                            (yyval.expression) = (yyvsp[-1].expression);
                        }
#line 1421 "A6_42.tab.c"
    break;

  case 7: /* postfix_expression: primary_expression  */
#line 173 "A6_42.y"
                        { 
                        
                            yyinfo("postfix_expression => primary_expression"); 
                            (yyval.array) = new Array();
                            (yyval.array)->symbol = (yyvsp[0].expression)->symbol;
                            (yyval.array)->temp = (yyval.array)->symbol;
                            (yyval.array)->subArrayType = (yyvsp[0].expression)->symbol->type;
                        }
#line 1434 "A6_42.tab.c"
    break;

  case 8: /* postfix_expression: postfix_expression LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET  */
#line 182 "A6_42.y"
                        { 
                    
                            yyinfo("postfix_expression => postfix_expression [ expression ]"); 
                            (yyval.array) = new Array();
                            (yyval.array)->symbol = (yyvsp[-3].array)->symbol;    
                            (yyval.array)->subArrayType = (yyvsp[-3].array)->subArrayType->arrayType; 
                            (yyval.array)->temp = gentemp(SymbolType::INT); 
                            (yyval.array)->type = Array::ARRAY;    

                            if((yyvsp[-3].array)->type == Array::ARRAY) {

                                Symbol *sym = gentemp(SymbolType::INT);
                                emit("*", sym->name, (yyvsp[-1].expression)->symbol->name, toString((yyval.array)->subArrayType->getSize()));
                                emit("+", (yyval.array)->temp->name, (yyvsp[-3].array)->temp->name, sym->name);
                            } else {
                                emit("*", (yyval.array)->temp->name, (yyvsp[-1].expression)->symbol->name, toString((yyval.array)->subArrayType->getSize()));
                            }

                        }
#line 1458 "A6_42.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression LEFT_PARENTHESES argument_expression_list_opt RIGHT_PARENTHESES  */
#line 202 "A6_42.y"
                        { 

                            yyinfo("postfix_expression => postfix_expression ( argument_expression_list_opt )"); 
                            (yyval.array) = new Array();
                            (yyval.array)->symbol = gentemp((yyvsp[-3].array)->symbol->type->type);
                            (yyval.array)->symbol->type->arrayType = (yyvsp[-3].array)->symbol->type->arrayType;
                            emit("call", (yyval.array)->symbol->name, (yyvsp[-3].array)->symbol->name, toString((yyvsp[-1].parameterCount)));
                        }
#line 1471 "A6_42.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 211 "A6_42.y"
                        { 
                            yyinfo("postfix_expression => postfix_expression -> IDENTIFIER"); 
                        }
#line 1479 "A6_42.tab.c"
    break;

  case 11: /* postfix_expression: LEFT_PARENTHESES type_name RIGHT_PARENTHESES LEFT_CURLY_BRACKET initialiser_list RIGHT_CURLY_BRACKET  */
#line 215 "A6_42.y"
                        { 
                            yyinfo("postfix_expression => ( type_name ) { initialiser_list }"); 
                        }
#line 1487 "A6_42.tab.c"
    break;

  case 12: /* postfix_expression: LEFT_PARENTHESES type_name RIGHT_PARENTHESES LEFT_CURLY_BRACKET initialiser_list COMMA RIGHT_CURLY_BRACKET  */
#line 219 "A6_42.y"
                        { 
                            yyinfo("postfix_expression => ( type_name ) { initialiser_list , }"); 
                        }
#line 1495 "A6_42.tab.c"
    break;

  case 13: /* argument_expression_list_opt: argument_expression_list  */
#line 228 "A6_42.y"
                                    { 
                                        yyinfo("argument_expression_list_opt => argument_expression_list"); 
                                        (yyval.parameterCount) = (yyvsp[0].parameterCount);
                                    }
#line 1504 "A6_42.tab.c"
    break;

  case 14: /* argument_expression_list_opt: %empty  */
#line 233 "A6_42.y"
                                    { 

                                        yyinfo("argument_expression_list_opt => epsilon");
                                        (yyval.parameterCount) = 0;
                                    }
#line 1514 "A6_42.tab.c"
    break;

  case 15: /* argument_expression_list: assignment_expression  */
#line 242 "A6_42.y"
                                { 

                                    yyinfo("argument_expression_list => assignment_expression"); 
                                    emit("param", (yyvsp[0].expression)->symbol->name);
                                    (yyval.parameterCount) = 1;
                                }
#line 1525 "A6_42.tab.c"
    break;

  case 16: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 249 "A6_42.y"
                                { 

                                    yyinfo("argument_expression_list => argument_expression_list , assignment_expression");
                                    emit("param", (yyvsp[0].expression)->symbol->name);
                                    (yyval.parameterCount) = (yyvsp[-2].parameterCount) + 1; 
                                }
#line 1536 "A6_42.tab.c"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 259 "A6_42.y"
                        { 
                            yyinfo("unary_expression => postfix_expression"); 
                            (yyval.array) = (yyvsp[0].array);
                        }
#line 1545 "A6_42.tab.c"
    break;

  case 18: /* unary_expression: unary_operator unary_expression  */
#line 264 "A6_42.y"
                        { 
                            yyinfo("unary_expression => unary_operator unary_expression");
                            if(strcmp((yyvsp[-1].unaryOperator), "&") == 0) {

                                (yyval.array) = new Array();
                                (yyval.array)->symbol = gentemp(SymbolType::POINTER);
                                (yyval.array)->symbol->type->arrayType = (yyvsp[0].array)->symbol->type;
                                emit("=&", (yyval.array)->symbol->name, (yyvsp[0].array)->symbol->name);
                            } else if(strcmp((yyvsp[-1].unaryOperator), "*") == 0) {
                                (yyval.array) = new Array();
                                (yyval.array)->symbol = (yyvsp[0].array)->symbol;
                                (yyval.array)->temp = gentemp((yyvsp[0].array)->temp->type->arrayType->type);
                                (yyval.array)->temp->type->arrayType = (yyvsp[0].array)->temp->type->arrayType->arrayType;
                                (yyval.array)->type = Array::POINTER;
                                emit("=*", (yyval.array)->temp->name, (yyvsp[0].array)->temp->name);
                            } else if(strcmp((yyvsp[-1].unaryOperator), "+") == 0) {
                                (yyval.array) = (yyvsp[0].array);
                            } else { 
                                (yyval.array) = new Array();
                                (yyval.array)->symbol = gentemp((yyvsp[0].array)->symbol->type->type);
                                emit((yyvsp[-1].unaryOperator), (yyval.array)->symbol->name, (yyvsp[0].array)->symbol->name);
                            }
                        }
#line 1573 "A6_42.tab.c"
    break;

  case 19: /* unary_operator: ASTERISK  */
#line 293 "A6_42.y"
                    { 
                        yyinfo("unary_operator => *"); 
                        (yyval.unaryOperator) = strdup("*"); 
                    }
#line 1582 "A6_42.tab.c"
    break;

  case 20: /* unary_operator: PLUS  */
#line 298 "A6_42.y"
                    { 
                        yyinfo("unary_operator => +"); 
                        (yyval.unaryOperator) = strdup("+"); 
                    }
#line 1591 "A6_42.tab.c"
    break;

  case 21: /* unary_operator: MINUS  */
#line 303 "A6_42.y"
                    { 
                        yyinfo("unary_operator => -"); 
                        (yyval.unaryOperator) = strdup("=-"); 
                    }
#line 1600 "A6_42.tab.c"
    break;

  case 22: /* unary_operator: EXCLAMATION  */
#line 308 "A6_42.y"
                    { 
                        yyinfo("unary_operator => !"); 
                        (yyval.unaryOperator) = strdup("!"); 
                    }
#line 1609 "A6_42.tab.c"
    break;

  case 23: /* unary_operator: ADDRESS  */
#line 313 "A6_42.y"
                     {
                     yyinfo("unary_operator => &"); 
                                        (yyval.unaryOperator) = strdup("&");
                                    }
#line 1618 "A6_42.tab.c"
    break;

  case 24: /* multiplicative_expression: unary_expression  */
#line 324 "A6_42.y"
                                { 
                                    SymbolType *baseType = (yyvsp[0].array)->symbol->type;
                                    while(baseType->arrayType)
                                        baseType = baseType->arrayType;
                                    yyinfo("multiplicative_expression => unary_expression"); 
                                    (yyval.expression) = new Expression();
                                    if((yyvsp[0].array)->type == Array::ARRAY) {
                                        (yyval.expression)->symbol = gentemp(baseType->type);
                                        emit("=[]", (yyval.expression)->symbol->name, (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->temp->name);
                                    } else if((yyvsp[0].array)->type == Array::POINTER) {
                                        (yyval.expression)->symbol = (yyvsp[0].array)->temp;
                                    } else {
                                        (yyval.expression)->symbol = (yyvsp[0].array)->symbol;
                                    }
                                }
#line 1638 "A6_42.tab.c"
    break;

  case 25: /* multiplicative_expression: multiplicative_expression ASTERISK unary_expression  */
#line 340 "A6_42.y"
                                { 
                                    SymbolType *baseType = (yyvsp[0].array)->symbol->type;
                                    while(baseType->arrayType)
                                        baseType = baseType->arrayType;
                                    Symbol *temp;
                                    if((yyvsp[0].array)->type == Array::ARRAY) {
                                        temp = gentemp(baseType->type);
                                        emit("=[]", temp->name, (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->temp->name);
                                    } else if((yyvsp[0].array)->type == Array::POINTER) {
                                        temp = (yyvsp[0].array)->temp;
                                    } else {
                                        temp = (yyvsp[0].array)->symbol;
                                    }
                                    yyinfo("multiplicative_expression => multiplicative_expression * unary_expression"); 
                                    if(typeCheck((yyvsp[-2].expression)->symbol, temp)) {
                                        (yyval.expression) = new Expression();
                                        (yyval.expression)->symbol = gentemp((yyvsp[-2].expression)->symbol->type->type);
                                        emit("*", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, temp->name);
                                    } else {
                                        yyerror("Type error.");
                                    }
                                }
#line 1665 "A6_42.tab.c"
    break;

  case 26: /* multiplicative_expression: multiplicative_expression SLASH unary_expression  */
#line 363 "A6_42.y"
                                { 
                                    SymbolType *baseType = (yyvsp[0].array)->symbol->type;
                                    while(baseType->arrayType)
                                        baseType = baseType->arrayType;
                                    Symbol *temp;
                                    if((yyvsp[0].array)->type == Array::ARRAY) {
                                        temp = gentemp(baseType->type);
                                        emit("=[]", temp->name, (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->temp->name);
                                    } else if((yyvsp[0].array)->type == Array::POINTER) {
                                        temp = (yyvsp[0].array)->temp;
                                    } else {
                                        temp = (yyvsp[0].array)->symbol;
                                    }
                                    yyinfo("multiplicative_expression => multiplicative_expression / unary_expression");
                                    if(typeCheck((yyvsp[-2].expression)->symbol, temp)) {
                                        (yyval.expression) = new Expression();
                                        (yyval.expression)->symbol = gentemp((yyvsp[-2].expression)->symbol->type->type);
                                        emit("/", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, temp->name);
                                    } else {
                                        yyerror("Type error.");
                                    }
                                }
#line 1692 "A6_42.tab.c"
    break;

  case 27: /* multiplicative_expression: multiplicative_expression MODULO unary_expression  */
#line 386 "A6_42.y"
                                { 
                                    SymbolType *baseType = (yyvsp[0].array)->symbol->type;
                                    while(baseType->arrayType)
                                        baseType = baseType->arrayType;
                                    Symbol *temp;
                                    if((yyvsp[0].array)->type == Array::ARRAY) {
                                        temp = gentemp(baseType->type);
                                        emit("=[]", temp->name, (yyvsp[0].array)->symbol->name, (yyvsp[0].array)->temp->name);
                                    } else if((yyvsp[0].array)->type == Array::POINTER) {
                                        temp = (yyvsp[0].array)->temp;
                                    } else {
                                        temp = (yyvsp[0].array)->symbol;
                                    }
                                    yyinfo("multiplicative_expression => multiplicative_expression % unary_expression"); 
                                    if(typeCheck((yyvsp[-2].expression)->symbol, temp)) {
                                        (yyval.expression) = new Expression();
                                        (yyval.expression)->symbol = gentemp((yyvsp[-2].expression)->symbol->type->type);
                                        emit("%", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, temp->name);
                                    } else {
                                        yyerror("Type error.");
                                    }
                                }
#line 1719 "A6_42.tab.c"
    break;

  case 28: /* additive_expression: multiplicative_expression  */
#line 412 "A6_42.y"
                        { 
                            yyinfo("additive_expression => multiplicative_expression"); 
                            (yyval.expression) = (yyvsp[0].expression);
                        }
#line 1728 "A6_42.tab.c"
    break;

  case 29: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 417 "A6_42.y"
                        { 
                            yyinfo("additive_expression => additive_expression + multiplicative_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->symbol = gentemp((yyvsp[-2].expression)->symbol->type->type);
                                emit("+", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                            } else {
                                yyerror("Type error.");
                            }
                        }
#line 1743 "A6_42.tab.c"
    break;

  case 30: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 428 "A6_42.y"
                        { 
                            yyinfo("additive_expression => additive_expression - multiplicative_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyval.expression) = new Expression();
                                (yyval.expression)->symbol = gentemp((yyvsp[-2].expression)->symbol->type->type);
                                emit("-", (yyval.expression)->symbol->name, (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                            } else {
                                yyerror("Type error.");
                            }
                        }
#line 1758 "A6_42.tab.c"
    break;

  case 31: /* relational_expression: additive_expression  */
#line 446 "A6_42.y"
                            { 
                                yyinfo("relational_expression => additive_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1767 "A6_42.tab.c"
    break;

  case 32: /* relational_expression: relational_expression LESS_THAN additive_expression  */
#line 451 "A6_42.y"
                            { 
                                yyinfo("relational_expression => relational_expression < additive_expression"); 
                                if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                    (yyval.expression) = new Expression();
                                    (yyval.expression)->type = Expression::BOOLEAN;
                                    (yyval.expression)->trueList = makeList(nextInstruction());
			                        (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                    emit("<", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                    emit("goto", "");
                                } else {
                                    yyerror("Type error.");
                                }
                            }
#line 1785 "A6_42.tab.c"
    break;

  case 33: /* relational_expression: relational_expression GREATER_THAN additive_expression  */
#line 465 "A6_42.y"
                            { 
                                yyinfo("relational_expression => relational_expression > additive_expression"); 
                                if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                    (yyval.expression) = new Expression();
                                    (yyval.expression)->type = Expression::BOOLEAN;
                                    (yyval.expression)->trueList = makeList(nextInstruction());
			                        (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                    emit(">", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                    emit("goto", "");
                                } else {
                                    yyerror("Type error.");
                                }
                            }
#line 1803 "A6_42.tab.c"
    break;

  case 34: /* relational_expression: relational_expression LESS_EQUAL_THAN additive_expression  */
#line 479 "A6_42.y"
                            { 
                                yyinfo("relational_expression => relational_expression <= additive_expression"); 
                                if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                    (yyval.expression) = new Expression();
                                    (yyval.expression)->type = Expression::BOOLEAN;
                                    (yyval.expression)->trueList = makeList(nextInstruction());
			                        (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                    emit("<=", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                    emit("goto", "");
                                } else {
                                    yyerror("Type error.");
                                }
                            }
#line 1821 "A6_42.tab.c"
    break;

  case 35: /* relational_expression: relational_expression GREATER_EQUAL_THAN additive_expression  */
#line 493 "A6_42.y"
                            { 
                                yyinfo("relational_expression => relational_expression >= additive_expression"); 
                                if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                    (yyval.expression) = new Expression();
                                    (yyval.expression)->type = Expression::BOOLEAN;
                                    (yyval.expression)->trueList = makeList(nextInstruction());
			                        (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                    emit(">=", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                    emit("goto", "");
                                } else {
                                    yyerror("Type error.");
                                }
                            }
#line 1839 "A6_42.tab.c"
    break;

  case 36: /* equality_expression: relational_expression  */
#line 510 "A6_42.y"
                        { 
                            yyinfo("equality_expression => relational_expression"); 
                            (yyval.expression) = (yyvsp[0].expression);
                        }
#line 1848 "A6_42.tab.c"
    break;

  case 37: /* equality_expression: equality_expression EQUALS relational_expression  */
#line 515 "A6_42.y"
                        { 
                            yyinfo("equality_expression => equality_expression == relational_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyvsp[-2].expression)->toInt();
                                (yyvsp[0].expression)->toInt();
                                (yyval.expression) = new Expression();
                                (yyval.expression)->type = Expression::BOOLEAN;
                                (yyval.expression)->trueList = makeList(nextInstruction());
			                    (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                emit("==", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                emit("goto", "");
                            } else {
                                yyerror("Type error.");
                            }
                        }
#line 1868 "A6_42.tab.c"
    break;

  case 38: /* equality_expression: equality_expression NOT_EQUALS relational_expression  */
#line 531 "A6_42.y"
                        { 
                            yyinfo("equality_expression => equality_expression != relational_expression"); 
                            if(typeCheck((yyvsp[-2].expression)->symbol, (yyvsp[0].expression)->symbol)) {
                                (yyvsp[-2].expression)->toInt();
                                (yyvsp[0].expression)->toInt();
                                (yyval.expression) = new Expression();
                                (yyval.expression)->type = Expression::BOOLEAN;
                                (yyval.expression)->trueList = makeList(nextInstruction());
			                    (yyval.expression)->falseList = makeList(nextInstruction() + 1);
                                emit("!=", "", (yyvsp[-2].expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                emit("goto", "");
                            } else {
                                yyerror("Type error.");
                            }
                        }
#line 1888 "A6_42.tab.c"
    break;

  case 39: /* M: %empty  */
#line 551 "A6_42.y"
        {
            yyinfo("M => epsilon");
            (yyval.instructionNumber) = nextInstruction();
        }
#line 1897 "A6_42.tab.c"
    break;

  case 40: /* N: %empty  */
#line 558 "A6_42.y"
        {
            yyinfo("N => epsilon");
            (yyval.statement) = new Statement();
            (yyval.statement)->nextList = makeList(nextInstruction());
            emit("goto", "");
        }
#line 1908 "A6_42.tab.c"
    break;

  case 41: /* logical_AND_expression: equality_expression  */
#line 570 "A6_42.y"
                            { 
                                yyinfo("logical_AND_expression => equality_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1917 "A6_42.tab.c"
    break;

  case 42: /* logical_AND_expression: logical_AND_expression LOGICAL_AND M equality_expression  */
#line 575 "A6_42.y"
                            { 
                                yyinfo("logical_AND_expression => logical_AND_expression && equality_expression");
                                (yyvsp[-3].expression)->toBool();
                                (yyvsp[0].expression)->toBool();
                                (yyval.expression) = new Expression();
                                (yyval.expression)->type = Expression::BOOLEAN;
                                backpatch((yyvsp[-3].expression)->trueList, (yyvsp[-1].instructionNumber));
                                (yyval.expression)->trueList = (yyvsp[0].expression)->trueList;
                                (yyval.expression)->falseList = merge((yyvsp[-3].expression)->falseList, (yyvsp[0].expression)->falseList);
                            }
#line 1932 "A6_42.tab.c"
    break;

  case 43: /* logical_OR_expression: logical_AND_expression  */
#line 589 "A6_42.y"
                            { 
                                yyinfo("logical_OR_expression => logical_AND_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1941 "A6_42.tab.c"
    break;

  case 44: /* logical_OR_expression: logical_OR_expression LOGICAL_OR M logical_AND_expression  */
#line 594 "A6_42.y"
                            { 
                                yyinfo("logical_OR_expression => logical_OR_expression || logical_AND_expression"); 
                                (yyvsp[-3].expression)->toBool();
                                (yyvsp[0].expression)->toBool();
                                (yyval.expression) = new Expression();
                                (yyval.expression)->type = Expression::BOOLEAN;
                                backpatch((yyvsp[-3].expression)->falseList, (yyvsp[-1].instructionNumber));
                                (yyval.expression)->trueList = merge((yyvsp[-3].expression)->trueList, (yyvsp[0].expression)->trueList);
                                (yyval.expression)->falseList = (yyvsp[0].expression)->falseList;
                            }
#line 1956 "A6_42.tab.c"
    break;

  case 45: /* conditional_expression: logical_OR_expression  */
#line 608 "A6_42.y"
                            { 
                                yyinfo("conditional_expression => logical_OR_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1965 "A6_42.tab.c"
    break;

  case 46: /* conditional_expression: logical_OR_expression N QUESTION_MARK M expression N COLON M conditional_expression  */
#line 613 "A6_42.y"
                            { 
                                yyinfo("conditional_expression => logical_OR_expression ? expression : conditional_expression"); 
                                (yyval.expression)->symbol = gentemp((yyvsp[-4].expression)->symbol->type->type);
                                emit("=", (yyval.expression)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                list<int> l = makeList(nextInstruction());
                                emit("goto", "");
                                backpatch((yyvsp[-3].statement)->nextList, nextInstruction());
                                emit("=", (yyval.expression)->symbol->name, (yyvsp[-4].expression)->symbol->name);
                                l = merge(l, makeList(nextInstruction()));
                                emit("goto", "");
                                backpatch((yyvsp[-7].statement)->nextList, nextInstruction());
                                (yyvsp[-8].expression)->toBool();
                                backpatch((yyvsp[-8].expression)->trueList, (yyvsp[-5].instructionNumber));
                                backpatch((yyvsp[-8].expression)->falseList, (yyvsp[-1].instructionNumber));
                                backpatch(l, nextInstruction());
                            }
#line 1986 "A6_42.tab.c"
    break;

  case 47: /* assignment_expression: conditional_expression  */
#line 633 "A6_42.y"
                            { 
                                yyinfo("assignment_expression => conditional_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1995 "A6_42.tab.c"
    break;

  case 48: /* assignment_expression: unary_expression ASSIGNMENT assignment_expression  */
#line 638 "A6_42.y"
                            { 
                                yyinfo("assignment_expression => unary_expression assignment_operator assignment_expression"); 
                                if((yyvsp[-2].array)->type == Array::ARRAY) {

                                    (yyvsp[0].expression)->symbol = (yyvsp[0].expression)->symbol->convert((yyvsp[-2].array)->subArrayType->type);
                                    emit("[]=", (yyvsp[-2].array)->symbol->name, (yyvsp[-2].array)->temp->name, (yyvsp[0].expression)->symbol->name);
                                } else if((yyvsp[-2].array)->type == Array::POINTER) {

                                    (yyvsp[0].expression)->symbol = (yyvsp[0].expression)->symbol->convert((yyvsp[-2].array)->temp->type->type);
                                    emit("*=", (yyvsp[-2].array)->temp->name, (yyvsp[0].expression)->symbol->name);
                                } else {

                                    (yyvsp[0].expression)->symbol = (yyvsp[0].expression)->symbol->convert((yyvsp[-2].array)->symbol->type->type);
			                        emit("=", (yyvsp[-2].array)->symbol->name, (yyvsp[0].expression)->symbol->name);
                                }
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 2017 "A6_42.tab.c"
    break;

  case 49: /* expression: assignment_expression  */
#line 661 "A6_42.y"
                { 
                    yyinfo("expression => assignment_expression"); 
                    (yyval.expression) = (yyvsp[0].expression);
                }
#line 2026 "A6_42.tab.c"
    break;

  case 50: /* expression: expression COMMA assignment_expression  */
#line 666 "A6_42.y"
                {
                     yyinfo("expression => expression , assignment_expression"); 
                }
#line 2034 "A6_42.tab.c"
    break;

  case 51: /* constant_expression: conditional_expression  */
#line 673 "A6_42.y"
                        {
                             yyinfo("constant_expression => conditional_expression"); 
                        }
#line 2042 "A6_42.tab.c"
    break;

  case 52: /* declaration: declaration_specifiers init_declarator_list_opt SEMI_COLON  */
#line 682 "A6_42.y"
                {
                     yyinfo("declaration => declaration_specifiers init_declarator_list_opt ;"); 
                }
#line 2050 "A6_42.tab.c"
    break;

  case 53: /* init_declarator_list_opt: init_declarator_list  */
#line 689 "A6_42.y"
                                {
                                     yyinfo("init_declarator_list_opt => init_declarator_list"); 
                                }
#line 2058 "A6_42.tab.c"
    break;

  case 54: /* init_declarator_list_opt: %empty  */
#line 693 "A6_42.y"
                                {
                                     yyinfo("init_declarator_list_opt => epsilon"); 
                                }
#line 2066 "A6_42.tab.c"
    break;

  case 55: /* declaration_specifiers: type_specifier declaration_specifiers_opt  */
#line 700 "A6_42.y"
                            {
                                 yyinfo("declaration_specifiers => type_specifier declaration_specifiers_opt"); 
                            }
#line 2074 "A6_42.tab.c"
    break;

  case 56: /* declaration_specifiers: type_qualifier declaration_specifiers_opt  */
#line 704 "A6_42.y"
                            {
                                 yyinfo("declaration_specifiers => type_qualifier declaration_specifiers_opt"); 
                            }
#line 2082 "A6_42.tab.c"
    break;

  case 57: /* declaration_specifiers_opt: declaration_specifiers  */
#line 711 "A6_42.y"
                                {
                                     yyinfo("declaration_specifiers_opt => declaration_specifiers"); 
                                }
#line 2090 "A6_42.tab.c"
    break;

  case 58: /* declaration_specifiers_opt: %empty  */
#line 715 "A6_42.y"
                                {
                                     yyinfo("declaration_specifiers_opt => epsilon "); 
                                }
#line 2098 "A6_42.tab.c"
    break;

  case 59: /* init_declarator_list: init_declarator  */
#line 722 "A6_42.y"
                            {
                                 yyinfo("init_declarator_list => init_declarator"); 
                            }
#line 2106 "A6_42.tab.c"
    break;

  case 60: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 726 "A6_42.y"
                            {
                                 yyinfo("init_declarator_list => init_declarator_list , init_declarator"); 
                            }
#line 2114 "A6_42.tab.c"
    break;

  case 61: /* init_declarator: declarator  */
#line 733 "A6_42.y"
                    { 
                        yyinfo("init_declarator => declarator"); 
                        (yyval.symbol) = (yyvsp[0].symbol);
                    }
#line 2123 "A6_42.tab.c"
    break;

  case 62: /* init_declarator: declarator ASSIGNMENT initialiser  */
#line 738 "A6_42.y"
                    { 
                        yyinfo("init_declarator => declarator = initialiser");
                       
                        if((yyvsp[0].symbol)->initialValue != "") 
                            (yyvsp[-2].symbol)->initialValue = (yyvsp[0].symbol)->initialValue;
             
		                emit("=", (yyvsp[-2].symbol)->name, (yyvsp[0].symbol)->name);
                    }
#line 2136 "A6_42.tab.c"
    break;

  case 63: /* type_specifier: VOIDTYPE  */
#line 752 "A6_42.y"
                    { 
                        yyinfo("type_specifier => void");
                        currentType = SymbolType::VOID;
                    }
#line 2145 "A6_42.tab.c"
    break;

  case 64: /* type_specifier: INTTYPE  */
#line 757 "A6_42.y"
                    { 
                        yyinfo("type_specifier => int"); 
                        currentType = SymbolType::INT;
                    }
#line 2154 "A6_42.tab.c"
    break;

  case 65: /* specifier_qualifier_list: type_specifier specifier_qualifier_list_opt  */
#line 765 "A6_42.y"
                                { 
                                    yyinfo("specifier_qualifier_list => type_specifier specifier_qualifier_list_opt"); 
                                }
#line 2162 "A6_42.tab.c"
    break;

  case 66: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list_opt  */
#line 769 "A6_42.y"
                                { 
                                    yyinfo("specifier_qualifier_list => type_qualifier specifier_qualifier_list_opt"); 
                                }
#line 2170 "A6_42.tab.c"
    break;

  case 67: /* specifier_qualifier_list_opt: specifier_qualifier_list  */
#line 776 "A6_42.y"
                                    { 
                                        yyinfo("specifier_qualifier_list_opt => specifier_qualifier_list"); 
                                    }
#line 2178 "A6_42.tab.c"
    break;

  case 68: /* specifier_qualifier_list_opt: %empty  */
#line 780 "A6_42.y"
                                    { 
                                        yyinfo("specifier_qualifier_list_opt => epsilon"); 
                                    }
#line 2186 "A6_42.tab.c"
    break;

  case 69: /* type_qualifier: CONST  */
#line 789 "A6_42.y"
                    { 
                        yyinfo("type_qualifier => const"); 
                    }
#line 2194 "A6_42.tab.c"
    break;

  case 70: /* declarator: pointer direct_declarator  */
#line 798 "A6_42.y"
                { 
                    yyinfo("declarator => pointer direct_declarator"); 
                    SymbolType *it = (yyvsp[-1].symbolType);
                    while(it->arrayType != NULL) 
                        it = it->arrayType;
                    it->arrayType = (yyvsp[0].symbol)->type;
                    (yyval.symbol) = (yyvsp[0].symbol)->update((yyvsp[-1].symbolType));
                }
#line 2207 "A6_42.tab.c"
    break;

  case 71: /* declarator: direct_declarator  */
#line 807 "A6_42.y"
                { 
                    yyinfo("declarator => direct_declarator"); 
                }
#line 2215 "A6_42.tab.c"
    break;

  case 72: /* change_scope: %empty  */
#line 813 "A6_42.y"
                    {
                        if(currentSymbol->nestedTable == NULL) {
                            changeTable(new SymbolTable(""));
                        }
                        else {
                            changeTable(currentSymbol->nestedTable);
                            emit("label", currentTable->name);
                        }
                    }
#line 2229 "A6_42.tab.c"
    break;

  case 73: /* direct_declarator: IDENTIFIER  */
#line 827 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => IDENTIFIER"); 
                            (yyval.symbol) = (yyvsp[0].symbol)->update(new SymbolType(currentType)); 
                            currentSymbol = (yyval.symbol);
                        }
#line 2239 "A6_42.tab.c"
    break;

  case 74: /* direct_declarator: LEFT_PARENTHESES declarator RIGHT_PARENTHESES  */
#line 833 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => ( declarator )"); 
                            (yyval.symbol) = (yyvsp[-1].symbol);
                        }
#line 2248 "A6_42.tab.c"
    break;

  case 75: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list assignment_expression RIGHT_SQUARE_BRACKET  */
#line 838 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ type_qualifier_list assignment_expression ]"); 
                        }
#line 2256 "A6_42.tab.c"
    break;

  case 76: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list RIGHT_SQUARE_BRACKET  */
#line 842 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ type_qualifier_list ]"); 
                        }
#line 2264 "A6_42.tab.c"
    break;

  case 77: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET assignment_expression RIGHT_SQUARE_BRACKET  */
#line 846 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ assignment_expression ]"); 
                            SymbolType *it1 = (yyvsp[-3].symbol)->type, *it2 = NULL;
                            while(it1->type == SymbolType::ARRAY) { 
                                it2 = it1;
                                it1 = it1->arrayType;
                            }
                            if(it2 != NULL) { 
                                it2->arrayType =  new SymbolType(SymbolType::ARRAY, it1, atoi((yyvsp[-1].expression)->symbol->initialValue.c_str()));	
                                (yyval.symbol) = (yyvsp[-3].symbol)->update((yyvsp[-3].symbol)->type);
                            }
                            else {
                                (yyval.symbol) = (yyvsp[-3].symbol)->update(new SymbolType(SymbolType::ARRAY, (yyvsp[-3].symbol)->type, atoi((yyvsp[-1].expression)->symbol->initialValue.c_str())));
                            }
                        }
#line 2284 "A6_42.tab.c"
    break;

  case 78: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET  */
#line 862 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ ]"); 
                          
                            SymbolType *it1 = (yyvsp[-2].symbol)->type, *it2 = NULL;
                            while(it1->type == SymbolType::ARRAY) { 
                                it2 = it1;
                                it1 = it1->arrayType;
                            }
                            if(it2 != NULL) {
                                it2->arrayType =  new SymbolType(SymbolType::ARRAY, it1, 0);	
                                (yyval.symbol) = (yyvsp[-2].symbol)->update((yyvsp[-2].symbol)->type);
                            }
                            else { 
                                (yyval.symbol) = (yyvsp[-2].symbol)->update(new SymbolType(SymbolType::ARRAY, (yyvsp[-2].symbol)->type, 0));
                            }
                        }
#line 2305 "A6_42.tab.c"
    break;

  case 79: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list ASTERISK RIGHT_SQUARE_BRACKET  */
#line 879 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ type_qualifier_list * ]"); 
                        }
#line 2313 "A6_42.tab.c"
    break;

  case 80: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET ASTERISK RIGHT_SQUARE_BRACKET  */
#line 883 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ * ]"); 
                        }
#line 2321 "A6_42.tab.c"
    break;

  case 81: /* direct_declarator: direct_declarator LEFT_PARENTHESES change_scope parameter_type_list RIGHT_PARENTHESES  */
#line 887 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator ( parameter_type_list )"); 

                            currentTable->name = (yyvsp[-4].symbol)->name;
                            if((yyvsp[-4].symbol)->type->type != SymbolType::VOID) {

                                currentTable->lookup("return")->update((yyvsp[-4].symbol)->type);
                            }

                            (yyvsp[-4].symbol)->nestedTable = currentTable;
                            (yyvsp[-4].symbol)->category = Symbol::FUNCTION;
                            currentTable->parent = globalTable;
                            changeTable(globalTable);
                            currentSymbol = (yyval.symbol);
                        }
#line 2341 "A6_42.tab.c"
    break;

  case 82: /* direct_declarator: direct_declarator LEFT_PARENTHESES identifier_list RIGHT_PARENTHESES  */
#line 903 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator ( identifier_list )"); 
                        }
#line 2349 "A6_42.tab.c"
    break;

  case 83: /* direct_declarator: direct_declarator LEFT_PARENTHESES change_scope RIGHT_PARENTHESES  */
#line 907 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator ( )"); 
                         
                            currentTable->name = (yyvsp[-3].symbol)->name;
                            if((yyvsp[-3].symbol)->type->type != SymbolType::VOID) {
                             
                                currentTable->lookup("return")->update((yyvsp[-3].symbol)->type);
                            }
                            
                            (yyvsp[-3].symbol)->nestedTable = currentTable;
                            (yyvsp[-3].symbol)->category = Symbol::FUNCTION;
                            currentTable->parent = globalTable;
                            changeTable(globalTable);
                            currentSymbol = (yyval.symbol);
                        }
#line 2369 "A6_42.tab.c"
    break;

  case 84: /* type_qualifier_list_opt: type_qualifier_list  */
#line 926 "A6_42.y"
                            { 
                                yyinfo("type_qualifier_list_opt => type_qualifier_list"); 
                            }
#line 2377 "A6_42.tab.c"
    break;

  case 85: /* type_qualifier_list_opt: %empty  */
#line 930 "A6_42.y"
                            { 
                                yyinfo("type_qualifier_list_opt => epsilon"); 
                            }
#line 2385 "A6_42.tab.c"
    break;

  case 86: /* pointer: ASTERISK type_qualifier_list_opt  */
#line 939 "A6_42.y"
            { 
                yyinfo("pointer => * type_qualifier_list_opt"); 
              
                (yyval.symbolType) = new SymbolType(SymbolType::POINTER);
            }
#line 2395 "A6_42.tab.c"
    break;

  case 87: /* pointer: ASTERISK type_qualifier_list_opt pointer  */
#line 945 "A6_42.y"
            { 
                yyinfo("pointer => * type_qualifier_list_opt pointer"); 
              
                (yyval.symbolType) = new SymbolType(SymbolType::POINTER, (yyvsp[0].symbolType));
            }
#line 2405 "A6_42.tab.c"
    break;

  case 88: /* type_qualifier_list: type_qualifier  */
#line 954 "A6_42.y"
                        { 
                            yyinfo("type_qualifier_list => type_qualifier"); 
                        }
#line 2413 "A6_42.tab.c"
    break;

  case 89: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 958 "A6_42.y"
                        { 
                            yyinfo("type_qualifier_list => type_qualifier_list type_qualifier"); 
                        }
#line 2421 "A6_42.tab.c"
    break;

  case 90: /* parameter_type_list: parameter_list  */
#line 965 "A6_42.y"
                        { 
                            yyinfo("parameter_type_list => parameter_list"); 
                        }
#line 2429 "A6_42.tab.c"
    break;

  case 91: /* parameter_list: parameter_declaration  */
#line 973 "A6_42.y"
                    { 
                        yyinfo("parameter_list => parameter_declaration"); 
                    }
#line 2437 "A6_42.tab.c"
    break;

  case 92: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 977 "A6_42.y"
                    { 
                        yyinfo("parameter_list => parameter_list , parameter_declaration"); 
                    }
#line 2445 "A6_42.tab.c"
    break;

  case 93: /* parameter_declaration: declaration_specifiers declarator  */
#line 984 "A6_42.y"
                            { 
                                yyinfo("parameter_declaration => declaration_specifiers declarator");
                                (yyvsp[0].symbol)->category = Symbol::PARAMETER; 
                                currentTable->parameters.push_back((yyvsp[0].symbol)->name);
                            }
#line 2455 "A6_42.tab.c"
    break;

  case 94: /* parameter_declaration: declaration_specifiers  */
#line 990 "A6_42.y"
                            { 
                                yyinfo("parameter_declaration => declaration_specifiers"); 
                            }
#line 2463 "A6_42.tab.c"
    break;

  case 95: /* identifier_list: IDENTIFIER  */
#line 997 "A6_42.y"
                    { 
                        yyinfo("identifier_list => IDENTIFIER"); 
                    }
#line 2471 "A6_42.tab.c"
    break;

  case 96: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 1001 "A6_42.y"
                    { 
                        yyinfo("identifier_list => identifier_list , IDENTIFIER"); 
                    }
#line 2479 "A6_42.tab.c"
    break;

  case 97: /* type_name: specifier_qualifier_list  */
#line 1008 "A6_42.y"
                { 
                    yyinfo("type_name => specifier_qualifier_list"); 
                }
#line 2487 "A6_42.tab.c"
    break;

  case 98: /* initialiser: assignment_expression  */
#line 1015 "A6_42.y"
                { 
                    yyinfo("initialiser => assignment_expression"); 
                    (yyval.symbol) = (yyvsp[0].expression)->symbol;
                }
#line 2496 "A6_42.tab.c"
    break;

  case 99: /* initialiser: LEFT_CURLY_BRACKET initialiser_list RIGHT_CURLY_BRACKET  */
#line 1020 "A6_42.y"
                { 
                    yyinfo("initialiser => { initialiser_list }"); 
                }
#line 2504 "A6_42.tab.c"
    break;

  case 100: /* initialiser: LEFT_CURLY_BRACKET initialiser_list COMMA RIGHT_CURLY_BRACKET  */
#line 1024 "A6_42.y"
                { 
                    yyinfo("initialiser => { initialiser_list , }"); 
                }
#line 2512 "A6_42.tab.c"
    break;

  case 101: /* initialiser_list: designation_opt initialiser  */
#line 1031 "A6_42.y"
                        { 
                            yyinfo("initialiser_list => designation_opt initialiser"); 
                        }
#line 2520 "A6_42.tab.c"
    break;

  case 102: /* initialiser_list: initialiser_list COMMA designation_opt initialiser  */
#line 1035 "A6_42.y"
                        { 
                            yyinfo("initialiser_list => initialiser_list , designation_opt initialiser"); 
                        }
#line 2528 "A6_42.tab.c"
    break;

  case 103: /* designation_opt: designation  */
#line 1042 "A6_42.y"
                    { 
                        yyinfo("designation_opt => designation"); 
                    }
#line 2536 "A6_42.tab.c"
    break;

  case 104: /* designation_opt: %empty  */
#line 1046 "A6_42.y"
                    { 
                        yyinfo("designation_opt => epsilon"); 
                    }
#line 2544 "A6_42.tab.c"
    break;

  case 105: /* designation: designator_list ASSIGNMENT  */
#line 1053 "A6_42.y"
                { 
                    yyinfo("designation => designator_list ="); 
                }
#line 2552 "A6_42.tab.c"
    break;

  case 106: /* designator_list: designator  */
#line 1060 "A6_42.y"
                    { 
                        yyinfo("designator_list => designator"); 
                    }
#line 2560 "A6_42.tab.c"
    break;

  case 107: /* designator_list: designator_list designator  */
#line 1064 "A6_42.y"
                    { 
                        yyinfo("designator_list => designator_list designator"); 
                    }
#line 2568 "A6_42.tab.c"
    break;

  case 108: /* designator: LEFT_SQUARE_BRACKET constant_expression RIGHT_SQUARE_BRACKET  */
#line 1071 "A6_42.y"
                { 
                    yyinfo("designator => [ constant_expression ]"); 
                }
#line 2576 "A6_42.tab.c"
    break;

  case 109: /* statement: compound_statement  */
#line 1081 "A6_42.y"
                { 
                    yyinfo("statement => compound_statement");
                    (yyval.statement) = (yyvsp[0].statement); 
                }
#line 2585 "A6_42.tab.c"
    break;

  case 110: /* statement: expression_statement  */
#line 1086 "A6_42.y"
                { 
                    yyinfo("statement => expression_statement"); 
                    (yyval.statement) = new Statement();
                    (yyval.statement)->nextList = (yyvsp[0].expression)->nextList;
                }
#line 2595 "A6_42.tab.c"
    break;

  case 111: /* statement: selection_statement  */
#line 1092 "A6_42.y"
                { 
                    yyinfo("statement => selection_statement"); 
                    (yyval.statement) = (yyvsp[0].statement);
                }
#line 2604 "A6_42.tab.c"
    break;

  case 112: /* statement: iteration_statement  */
#line 1097 "A6_42.y"
                { 
                    yyinfo("statement => iteration_statement"); 
                    (yyval.statement) = (yyvsp[0].statement);
                }
#line 2613 "A6_42.tab.c"
    break;

  case 113: /* statement: jump_statement  */
#line 1102 "A6_42.y"
                { 
                    yyinfo("statement => jump_statement"); 
                    (yyval.statement) = (yyvsp[0].statement);
                }
#line 2622 "A6_42.tab.c"
    break;

  case 114: /* compound_statement: LEFT_CURLY_BRACKET block_item_list_opt RIGHT_CURLY_BRACKET  */
#line 1113 "A6_42.y"
                        { 
                            yyinfo("compound_statement => { block_item_list_opt }"); 
                            (yyval.statement) = (yyvsp[-1].statement);
                        }
#line 2631 "A6_42.tab.c"
    break;

  case 115: /* block_item_list_opt: block_item_list  */
#line 1121 "A6_42.y"
                        { 
                            yyinfo("block_item_list_opt => block_item_list"); 
                            (yyval.statement) = (yyvsp[0].statement);
                        }
#line 2640 "A6_42.tab.c"
    break;

  case 116: /* block_item_list_opt: %empty  */
#line 1126 "A6_42.y"
                        { 
                            yyinfo("block_item_list_opt => epsilon"); 
                            (yyval.statement) = new Statement();
                        }
#line 2649 "A6_42.tab.c"
    break;

  case 117: /* block_item_list: block_item  */
#line 1134 "A6_42.y"
                    {
                        yyinfo("block_item_list => block_item"); 
                        (yyval.statement) = (yyvsp[0].statement);
                    }
#line 2658 "A6_42.tab.c"
    break;

  case 118: /* block_item_list: block_item_list M block_item  */
#line 1139 "A6_42.y"
                    { 
                        yyinfo("block_item_list => block_item_list block_item"); 
                        (yyval.statement) = (yyvsp[0].statement);
                        
                        backpatch((yyvsp[-2].statement)->nextList,(yyvsp[-1].instructionNumber));
                    }
#line 2669 "A6_42.tab.c"
    break;

  case 119: /* block_item: declaration  */
#line 1149 "A6_42.y"
                { 
                    yyinfo("block_item => declaration"); 
                    (yyval.statement) = new Statement();
                }
#line 2678 "A6_42.tab.c"
    break;

  case 120: /* block_item: statement  */
#line 1154 "A6_42.y"
                { 
                    yyinfo("block_item => statement"); 
                    (yyval.statement) = (yyvsp[0].statement);
                }
#line 2687 "A6_42.tab.c"
    break;

  case 121: /* expression_statement: expression_opt SEMI_COLON  */
#line 1162 "A6_42.y"
                            { 
                                yyinfo("expression_statement => expression_opt ;"); 
                                (yyval.expression) = (yyvsp[-1].expression);
                            }
#line 2696 "A6_42.tab.c"
    break;

  case 122: /* expression_opt: expression  */
#line 1170 "A6_42.y"
                    { 
                        yyinfo("expression_opt => expression"); 
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2705 "A6_42.tab.c"
    break;

  case 123: /* expression_opt: %empty  */
#line 1175 "A6_42.y"
                    { 
                        yyinfo("expression_opt => epsilon"); 
                        (yyval.expression) = new Expression();
                    }
#line 2714 "A6_42.tab.c"
    break;

  case 124: /* selection_statement: IF LEFT_PARENTHESES expression RIGHT_PARENTHESES M statement N  */
#line 1185 "A6_42.y"
                        { 
                            yyinfo("selection_statement => if ( expression ) statement"); 
                            (yyval.statement) = new Statement();
                            (yyvsp[-4].expression)->toBool();
                            backpatch((yyvsp[-4].expression)->trueList, (yyvsp[-2].instructionNumber)); 
                            (yyval.statement)->nextList = merge((yyvsp[-4].expression)->falseList, merge((yyvsp[-1].statement)->nextList, (yyvsp[0].statement)->nextList)); 
                        }
#line 2726 "A6_42.tab.c"
    break;

  case 125: /* selection_statement: IF LEFT_PARENTHESES expression RIGHT_PARENTHESES M statement N ELSE M statement  */
#line 1193 "A6_42.y"
                        { 
                            yyinfo("selection_statement => if ( expression ) statement else statement"); 
                            (yyval.statement) = new Statement();
                            (yyvsp[-7].expression)->toBool();
                            backpatch((yyvsp[-7].expression)->trueList, (yyvsp[-5].instructionNumber)); 
                            backpatch((yyvsp[-7].expression)->falseList, (yyvsp[-1].instructionNumber)); 
                            (yyval.statement)->nextList = merge((yyvsp[0].statement)->nextList, merge((yyvsp[-4].statement)->nextList, (yyvsp[-3].statement)->nextList)); 
                        }
#line 2739 "A6_42.tab.c"
    break;

  case 126: /* iteration_statement: FOR LEFT_PARENTHESES expression_opt SEMI_COLON M expression_opt SEMI_COLON M expression_opt N RIGHT_PARENTHESES M statement  */
#line 1207 "A6_42.y"
                        { 
                            yyinfo("iteration_statement => for ( expression_opt ; expression_opt ; expression_opt ) statement"); 
                            (yyval.statement) = new Statement();
                            (yyvsp[-7].expression)->toBool();
                            backpatch((yyvsp[-7].expression)->trueList, (yyvsp[-1].instructionNumber)); 
                            backpatch((yyvsp[-3].statement)->nextList, (yyvsp[-8].instructionNumber)); 
                            backpatch((yyvsp[0].statement)->nextList, (yyvsp[-5].instructionNumber));
                            emit("goto", toString((yyvsp[-5].instructionNumber)));
                            (yyval.statement)->nextList = (yyvsp[-7].expression)->falseList;
                        }
#line 2754 "A6_42.tab.c"
    break;

  case 127: /* iteration_statement: FOR LEFT_PARENTHESES declaration expression_opt SEMI_COLON expression_opt RIGHT_PARENTHESES statement  */
#line 1218 "A6_42.y"
                        { 
                            yyinfo("iteration_statement => for ( declaration expression_opt ; expression_opt ) statement"); 
                        }
#line 2762 "A6_42.tab.c"
    break;

  case 128: /* jump_statement: RETURN expression_opt SEMI_COLON  */
#line 1225 "A6_42.y"
                    { 
                        yyinfo("jump_statement => return expression_opt ;"); 
                        (yyval.statement) = new Statement();
                        if((yyvsp[-1].expression)->symbol != NULL) {
                            emit("return", (yyvsp[-1].expression)->symbol->name); 
                        } else {
                            emit("return", "");
                        }
                    }
#line 2776 "A6_42.tab.c"
    break;

  case 129: /* translation_unit: external_declaration  */
#line 1240 "A6_42.y"
                        { 
                            yyinfo("translation_unit => external_declaration"); 
                        }
#line 2784 "A6_42.tab.c"
    break;

  case 130: /* translation_unit: translation_unit external_declaration  */
#line 1244 "A6_42.y"
                        { 
                            yyinfo("translation_unit => translation_unit external_declaration"); 
                        }
#line 2792 "A6_42.tab.c"
    break;

  case 131: /* external_declaration: function_definition  */
#line 1251 "A6_42.y"
                            { 
                                yyinfo("external_declaration => function_definition"); 
                            }
#line 2800 "A6_42.tab.c"
    break;

  case 132: /* external_declaration: declaration  */
#line 1255 "A6_42.y"
                            { 
                                yyinfo("external_declaration => declaration"); 
                            }
#line 2808 "A6_42.tab.c"
    break;

  case 133: /* function_definition: declaration_specifiers declarator declaration_list_opt change_scope LEFT_CURLY_BRACKET block_item_list_opt RIGHT_CURLY_BRACKET  */
#line 1262 "A6_42.y"
                        { 
                            yyinfo("function_definition => declaration_specifiers declarator declaration_list_opt compound_statement"); 
                            tableCount = 0;
                            emit("labelend", (yyvsp[-5].symbol)->name);
                            if((yyvsp[-5].symbol)->type->type != SymbolType::VOID) {
                                currentTable->lookup("return")->update((yyvsp[-5].symbol)->type);
                            }
                            changeTable(globalTable);
                        }
#line 2822 "A6_42.tab.c"
    break;

  case 134: /* declaration_list_opt: declaration_list  */
#line 1275 "A6_42.y"
                            { 
                                yyinfo("declaration_list_opt => declaration_list"); 
                            }
#line 2830 "A6_42.tab.c"
    break;

  case 135: /* declaration_list_opt: %empty  */
#line 1279 "A6_42.y"
                            { 
                                yyinfo("declaration_list_opt => epsilon"); 
                            }
#line 2838 "A6_42.tab.c"
    break;

  case 136: /* declaration_list: declaration  */
#line 1286 "A6_42.y"
                        { 
                            yyinfo("declaration_list => declaration"); 
                        }
#line 2846 "A6_42.tab.c"
    break;

  case 137: /* declaration_list: declaration_list declaration  */
#line 1290 "A6_42.y"
                        { 
                            yyinfo("declaration_list => declaration_list declaration"); 
                        }
#line 2854 "A6_42.tab.c"
    break;


#line 2858 "A6_42.tab.c"

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

#line 1295 "A6_42.y"


void yyerror(string s) {
    printf("ERROR [Line %d] : %s\n", lineCount, s.c_str());
}

void yyinfo(string s) {
    #ifdef _DEBUG
        printf("INFO [Line %d] : %s\n", lineCount, s.c_str());
    #endif
}
