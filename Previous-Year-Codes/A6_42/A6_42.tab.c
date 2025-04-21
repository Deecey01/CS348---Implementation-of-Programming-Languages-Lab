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
  YYSYMBOL_BEGIN = 3,                      /* BEGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ADDRESS = 9,                    /* ADDRESS  */
  YYSYMBOL_INTTYPE = 10,                   /* INTTYPE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_INVALID_TOKEN = 12,             /* INVALID_TOKEN  */
  YYSYMBOL_VOIDTYPE = 13,                  /* VOIDTYPE  */
  YYSYMBOL_IDENTIFIER = 14,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 15,          /* INTEGER_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 16,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 17,            /* STRING_LITERAL  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 18,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_SLASH = 19,                     /* SLASH  */
  YYSYMBOL_QUESTION_MARK = 20,             /* QUESTION_MARK  */
  YYSYMBOL_ASSIGNMENT = 21,                /* ASSIGNMENT  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 23,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_LEFT_PARENTHESES = 24,          /* LEFT_PARENTHESES  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 25,        /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 26,       /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_ARROW = 27,                     /* ARROW  */
  YYSYMBOL_ASTERISK = 28,                  /* ASTERISK  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MINUS = 30,                     /* MINUS  */
  YYSYMBOL_EXCLAMATION = 31,               /* EXCLAMATION  */
  YYSYMBOL_MODULO = 32,                    /* MODULO  */
  YYSYMBOL_LESS_THAN = 33,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 34,              /* GREATER_THAN  */
  YYSYMBOL_LESS_EQUAL_THAN = 35,           /* LESS_EQUAL_THAN  */
  YYSYMBOL_GREATER_EQUAL_THAN = 36,        /* GREATER_EQUAL_THAN  */
  YYSYMBOL_COLON = 37,                     /* COLON  */
  YYSYMBOL_SEMI_COLON = 38,                /* SEMI_COLON  */
  YYSYMBOL_RIGHT_PARENTHESES = 39,         /* RIGHT_PARENTHESES  */
  YYSYMBOL_EQUALS = 40,                    /* EQUALS  */
  YYSYMBOL_LOGICAL_AND = 41,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 42,                /* LOGICAL_OR  */
  YYSYMBOL_NOT_EQUALS = 43,                /* NOT_EQUALS  */
  YYSYMBOL_THEN = 44,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_primary_expression = 46,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 47,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 48, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 49,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 50,          /* unary_expression  */
  YYSYMBOL_unary_operator = 51,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 52, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 53,       /* additive_expression  */
  YYSYMBOL_relational_expression = 54,     /* relational_expression  */
  YYSYMBOL_equality_expression = 55,       /* equality_expression  */
  YYSYMBOL_M = 56,                         /* M  */
  YYSYMBOL_N = 57,                         /* N  */
  YYSYMBOL_logical_AND_expression = 58,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 59,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 60,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 61,     /* assignment_expression  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_constant_expression = 63,       /* constant_expression  */
  YYSYMBOL_declaration = 64,               /* declaration  */
  YYSYMBOL_init_declarator_list_opt = 65,  /* init_declarator_list_opt  */
  YYSYMBOL_declaration_specifiers = 66,    /* declaration_specifiers  */
  YYSYMBOL_declaration_specifiers_opt = 67, /* declaration_specifiers_opt  */
  YYSYMBOL_init_declarator_list = 68,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 69,           /* init_declarator  */
  YYSYMBOL_type_specifier = 70,            /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 71,  /* specifier_qualifier_list  */
  YYSYMBOL_specifier_qualifier_list_opt = 72, /* specifier_qualifier_list_opt  */
  YYSYMBOL_type_qualifier = 73,            /* type_qualifier  */
  YYSYMBOL_declarator = 74,                /* declarator  */
  YYSYMBOL_change_scope = 75,              /* change_scope  */
  YYSYMBOL_direct_declarator = 76,         /* direct_declarator  */
  YYSYMBOL_type_qualifier_list_opt = 77,   /* type_qualifier_list_opt  */
  YYSYMBOL_pointer = 78,                   /* pointer  */
  YYSYMBOL_type_qualifier_list = 79,       /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 80,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 81,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 82,     /* parameter_declaration  */
  YYSYMBOL_identifier_list = 83,           /* identifier_list  */
  YYSYMBOL_type_name = 84,                 /* type_name  */
  YYSYMBOL_initialiser = 85,               /* initialiser  */
  YYSYMBOL_initialiser_list = 86,          /* initialiser_list  */
  YYSYMBOL_designation_opt = 87,           /* designation_opt  */
  YYSYMBOL_designation = 88,               /* designation  */
  YYSYMBOL_designator_list = 89,           /* designator_list  */
  YYSYMBOL_designator = 90,                /* designator  */
  YYSYMBOL_statement = 91,                 /* statement  */
  YYSYMBOL_compound_statement = 92,        /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 93,       /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 94,           /* block_item_list  */
  YYSYMBOL_block_item = 95,                /* block_item  */
  YYSYMBOL_expression_statement = 96,      /* expression_statement  */
  YYSYMBOL_expression_opt = 97,            /* expression_opt  */
  YYSYMBOL_selection_statement = 98,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 99,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 100,           /* jump_statement  */
  YYSYMBOL_translation_unit = 101,         /* translation_unit  */
  YYSYMBOL_external_declaration = 102,     /* external_declaration  */
  YYSYMBOL_function_definition = 103,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 104,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 105          /* declaration_list  */
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
#define YYLAST   321

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   141,   149,   156,   165,   173,   182,   202,
     211,   215,   219,   228,   234,   242,   249,   259,   264,   293,
     298,   303,   308,   313,   324,   340,   363,   386,   412,   417,
     428,   446,   451,   465,   479,   493,   510,   515,   531,   552,
     559,   570,   575,   589,   594,   608,   613,   633,   638,   661,
     666,   673,   682,   689,   694,   700,   704,   711,   716,   722,
     726,   733,   738,   752,   757,   765,   769,   776,   781,   789,
     798,   807,   814,   827,   833,   838,   842,   846,   862,   879,
     883,   887,   903,   907,   926,   931,   939,   945,   954,   958,
     965,   973,   977,   984,   990,   997,  1001,  1008,  1015,  1020,
    1024,  1031,  1035,  1042,  1047,  1053,  1060,  1064,  1071,  1081,
    1086,  1092,  1097,  1102,  1113,  1121,  1127,  1134,  1139,  1149,
    1154,  1162,  1170,  1176,  1185,  1193,  1207,  1218,  1225,  1240,
    1244,  1251,  1255,  1262,  1275,  1280,  1286,  1290
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
  "\"end of file\"", "error", "\"invalid token\"", "BEGIN", "END",
  "CONST", "ELSE", "FOR", "IF", "ADDRESS", "INTTYPE", "RETURN",
  "INVALID_TOKEN", "VOIDTYPE", "IDENTIFIER", "INTEGER_CONSTANT",
  "CHARACTER_CONSTANT", "STRING_LITERAL", "LEFT_SQUARE_BRACKET", "SLASH",
  "QUESTION_MARK", "ASSIGNMENT", "COMMA", "RIGHT_SQUARE_BRACKET",
  "LEFT_PARENTHESES", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET", "ARROW",
  "ASTERISK", "PLUS", "MINUS", "EXCLAMATION", "MODULO", "LESS_THAN",
  "GREATER_THAN", "LESS_EQUAL_THAN", "GREATER_EQUAL_THAN", "COLON",
  "SEMI_COLON", "RIGHT_PARENTHESES", "EQUALS", "LOGICAL_AND", "LOGICAL_OR",
  "NOT_EQUALS", "THEN", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list_opt",
  "argument_expression_list", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "M", "N",
  "logical_AND_expression", "logical_OR_expression",
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
      87,  -146,  -146,  -146,  -146,   111,    87,    87,   280,  -146,
    -146,  -146,   111,    23,    -4,    14,  -146,    60,     6,     7,
    -146,  -146,  -146,  -146,  -146,    19,  -146,    36,    23,  -146,
     111,    99,  -146,   111,  -146,    87,   245,    65,     6,  -146,
    -146,  -146,  -146,    70,  -146,  -146,  -146,  -146,  -146,   128,
      68,  -146,  -146,  -146,  -146,  -146,    -2,    77,   290,   136,
     119,    85,    64,    93,     9,  -146,  -146,  -146,    80,  -146,
    -146,   123,   131,   272,  -146,    10,    44,  -146,    67,    87,
    -146,    87,   133,   290,   125,    99,  -146,   149,  -146,   290,
     290,   148,   290,  -146,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,  -146,  -146,   164,   166,  -146,
    -146,  -146,   170,   177,  -146,   111,   163,   188,  -146,   204,
    -146,   290,  -146,  -146,  -146,  -146,   194,  -146,  -146,   197,
      42,  -146,  -146,  -146,  -146,   169,   182,   201,  -146,  -146,
    -146,  -146,  -146,  -146,   136,   136,   119,   119,   119,   119,
      85,    85,   290,   290,  -146,   166,   200,   207,   290,   203,
    -146,  -146,  -146,   206,    28,  -146,  -146,   195,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,    87,  -146,  -146,    68,  -146,
    -146,    99,  -146,  -146,   290,    64,    93,   290,   233,   128,
     290,   202,  -146,   198,  -146,  -146,   139,  -146,  -146,   203,
    -146,   290,   208,    72,  -146,  -146,   114,  -146,   210,   211,
    -146,  -146,  -146,  -146,   290,   290,   227,   290,   209,   214,
    -146,  -146,   227,  -146,   239,  -146,   290,  -146,  -146,   227,
     224,  -146,  -146,   227,  -146
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
      37,    38,     0,     0,    39,   116,     0,     0,   123,   122,
     119,   120,   109,     0,    39,   117,   110,     0,   111,   112,
     113,    79,    75,    93,    81,     0,    96,    50,   104,   108,
     100,     0,     8,     9,     0,    42,    44,     0,     0,   123,
       0,     0,   133,   123,   121,    92,     0,   102,    16,    40,
     114,   123,     0,     0,   128,   118,   104,    11,     0,     0,
      39,    39,    12,    39,   123,   123,   123,     0,     0,     0,
      40,    46,   123,    39,   124,   127,   123,    39,    40,   123,
       0,   125,    39,   123,   126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,  -146,   -57,  -146,   101,    86,   113,
     112,  -101,  -138,   100,  -146,   -81,   -18,   -37,  -146,     0,
    -146,     3,   232,  -146,   235,   -22,   217,   186,    20,     2,
     234,   251,  -146,   252,   236,  -146,  -146,   103,  -146,  -146,
     -79,   104,  -126,  -146,  -146,   196,  -145,  -146,   129,  -146,
      98,  -146,  -139,  -146,  -146,  -146,  -146,   284,  -146,  -146,
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
      20,     5,    78,    66,    25,     1,    89,    32,    72,   191,
       2,    11,    90,     3,    36,    91,   127,    79,     1,   -40,
      37,    12,  -115,    26,    29,    69,    30,   141,   142,   143,
     127,   127,   127,   127,   127,   127,   127,   127,    41,   114,
     202,   106,   135,   187,  -115,   113,    26,    79,    39,    79,
      83,   208,   209,   193,    13,     1,   119,    66,   180,    81,
       2,   220,   138,     3,   140,   218,   219,   225,   115,    74,
     181,    31,   224,   120,   231,  -135,    83,   228,   234,   121,
     230,    31,     1,    41,   121,   127,   127,     2,    92,    81,
       3,    81,   197,   177,   103,   108,   122,   104,    44,   215,
     216,   211,   217,    45,    46,    47,    48,   173,    99,   100,
     101,   102,   226,    49,    50,    11,   229,    51,    52,    53,
      54,   233,    83,     1,   105,    12,   221,    44,     2,    13,
     212,     3,    45,    46,    47,    48,   109,   130,    97,    98,
     199,   131,    49,   203,   110,    94,    51,    52,    53,    54,
     127,   206,   139,    66,    95,   207,   198,    83,    96,   155,
     133,     1,   126,   156,   157,    44,     2,   158,   115,     3,
      45,    46,    47,    48,   154,   146,   147,   148,   149,   201,
      49,   121,   182,   171,    51,    52,    53,    54,   144,   145,
     172,   155,   174,     1,  -123,   156,   157,    44,     2,   158,
     175,     3,    45,    46,    47,    48,   150,   151,   176,   178,
     179,   183,    49,   184,   189,   121,    51,    52,    53,    54,
     155,   190,   192,   194,   156,   157,    44,   200,   158,    22,
     204,    45,    46,    47,    48,   227,   210,   213,   222,   214,
       1,    49,   223,   186,    44,    51,    52,    53,    54,    45,
      46,    47,    48,   232,   185,    42,    80,   125,    70,    49,
      38,    75,    73,    71,    52,    53,    54,     1,   195,    40,
      23,    44,   196,   134,   188,     1,    45,    46,    47,    48,
       2,   205,    24,     3,     0,   111,    49,     0,     0,    44,
     112,    52,    53,    54,    45,    46,    47,    48,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,    51,    52,
      53,    54
};

static const yytype_int16 yycheck[] =
{
       0,    58,    83,     0,   130,   106,    85,     5,     8,     6,
       7,     8,    49,    31,    12,     5,    18,    17,    36,   158,
      10,    14,    24,    13,    18,    27,    83,    49,     5,    20,
      24,    24,     4,    13,    38,    35,    22,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    28,    39,
     189,    42,    89,   154,    26,    73,    36,    79,    39,    81,
      18,   199,   201,   164,    28,     5,    22,    85,    26,    49,
      10,   216,    90,    13,    92,   214,   215,   222,    75,    14,
     206,    21,   220,    39,   229,    25,    18,   226,   233,    22,
     228,    21,     5,    73,    22,   152,   153,    10,    21,    79,
      13,    81,   181,   121,    40,    25,    39,    43,     9,   210,
     211,    39,   213,    14,    15,    16,    17,   115,    33,    34,
      35,    36,   223,    24,    25,    14,   227,    28,    29,    30,
      31,   232,    18,     5,    41,    24,   217,     9,    10,    28,
      26,    13,    14,    15,    16,    17,    23,    22,    29,    30,
     187,    26,    24,   190,    23,    19,    28,    29,    30,    31,
     217,    22,    14,   181,    28,    26,   184,    18,    32,     3,
      21,     5,    39,     7,     8,     9,    10,    11,   175,    13,
      14,    15,    16,    17,    20,    99,   100,   101,   102,   189,
      24,    22,    23,    23,    28,    29,    30,    31,    97,    98,
      23,     3,    39,     5,    38,     7,     8,     9,    10,    11,
      22,    13,    14,    15,    16,    17,   103,   104,    14,    25,
      23,    39,    24,    22,    24,    22,    28,    29,    30,    31,
       3,    24,    26,    38,     7,     8,     9,     4,    11,     7,
      38,    14,    15,    16,    17,     6,    38,    37,    39,    38,
       5,    24,    38,   153,     9,    28,    29,    30,    31,    14,
      15,    16,    17,    39,   152,    30,    49,    81,    23,    24,
      19,    37,    36,    28,    29,    30,    31,     5,   175,    27,
       0,     9,   178,    87,   155,     5,    14,    15,    16,    17,
      10,   193,     8,    13,    -1,    23,    24,    -1,    -1,     9,
      28,    29,    30,    31,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,
      30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    10,    13,    64,    66,    70,    73,   101,   102,
     103,    14,    24,    28,    65,    68,    69,    74,    76,    78,
      66,    67,    67,     0,   102,    74,    73,    77,    79,    38,
      22,    21,    64,    66,   104,   105,    18,    24,    76,    39,
      78,    73,    69,    74,     9,    14,    15,    16,    17,    24,
      25,    28,    29,    30,    31,    46,    47,    50,    51,    52,
      53,    54,    55,    58,    59,    60,    61,    85,    75,    64,
      23,    28,    61,    79,    14,    75,    83,    61,    62,    70,
      71,    73,    84,    18,    86,    87,    88,    89,    90,    18,
      24,    27,    21,    50,    19,    28,    32,    29,    30,    33,
      34,    35,    36,    40,    43,    41,    42,    57,    25,    23,
      23,    23,    28,    61,    39,    66,    80,    81,    82,    22,
      39,    22,    39,    71,    72,    72,    39,    50,    60,    63,
      22,    26,    85,    21,    90,    62,    48,    49,    61,    14,
      61,    50,    50,    50,    52,    52,    53,    53,    53,    53,
      54,    54,    56,    56,    20,     3,     7,     8,    11,    62,
      64,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    23,    23,    74,    39,    22,    14,    61,    25,    23,
      26,    87,    23,    39,    22,    55,    58,    56,    93,    24,
      24,    97,    26,    56,    38,    82,    86,    85,    61,    62,
       4,    64,    97,    62,    38,    95,    22,    26,    57,    97,
      38,    39,    26,    37,    38,    56,    56,    56,    97,    97,
      91,    60,    39,    38,    57,    91,    56,     6,    97,    56,
      57,    91,    39,    56,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    53,    53,
      53,    54,    54,    54,    54,    54,    55,    55,    55,    56,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    81,    81,    82,    82,    83,    83,    84,    85,    85,
      85,    86,    86,    87,    87,    88,    89,    89,    90,    91,
      91,    91,    91,    91,    92,    93,    93,    94,    94,    95,
      95,    96,    97,    97,    98,    98,    99,    99,   100,   101,
     101,   102,   102,   103,   104,   104,   105,   105
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
#line 135 "A6_42.y"
                        { 
                            yyinfo("primary_expression => IDENTIFIER");
                            (yyval.expression) = new Expression(); 
                            (yyval.expression)->symbol = (yyvsp[0].symbol);
                            (yyval.expression)->type = Expression::NONBOOLEAN; 
                        }
#line 1378 "A6_42.tab.c"
    break;

  case 3: /* primary_expression: INTEGER_CONSTANT  */
#line 142 "A6_42.y"
                        { 
                            yyinfo("primary_expression => INTEGER_CONSTANT"); 
                            (yyval.expression) = new Expression();
                            (yyval.expression)->symbol = gentemp(SymbolType::INT, toString((yyvsp[0].intVal)));
                            emit("=", (yyval.expression)->symbol->name, (yyvsp[0].intVal));
                        }
#line 1389 "A6_42.tab.c"
    break;

  case 4: /* primary_expression: CHARACTER_CONSTANT  */
#line 150 "A6_42.y"
                        { 
                            yyinfo("primary_expression => CHARACTER_CONSTANT"); 
                            (yyval.expression) = new Expression();
                            (yyval.expression)->symbol = gentemp(SymbolType::CHAR, (yyvsp[0].charVal));
                            emit("=", (yyval.expression)->symbol->name, (yyvsp[0].charVal));
                        }
#line 1400 "A6_42.tab.c"
    break;

  case 5: /* primary_expression: STRING_LITERAL  */
#line 157 "A6_42.y"
                        { 
                            yyinfo("primary_expression => STRING_LITERAL"); 
                            (yyval.expression) = new Expression();
		                    (yyval.expression)->symbol = gentemp(SymbolType::POINTER, (yyvsp[0].stringVal));
		                    (yyval.expression)->symbol->type->arrayType = new SymbolType(SymbolType::CHAR);
                            emit("=str", (yyval.expression)->symbol->name, stringLiterals.size());
                            stringLiterals.push_back((yyvsp[0].stringVal));
                        }
#line 1413 "A6_42.tab.c"
    break;

  case 6: /* primary_expression: LEFT_PARENTHESES expression RIGHT_PARENTHESES  */
#line 166 "A6_42.y"
                        { 
                            yyinfo("primary_expression => ( expression )"); 
                            (yyval.expression) = (yyvsp[-1].expression);
                        }
#line 1422 "A6_42.tab.c"
    break;

  case 7: /* postfix_expression: primary_expression  */
#line 174 "A6_42.y"
                        { 
                        
                            yyinfo("postfix_expression => primary_expression"); 
                            (yyval.array) = new Array();
                            (yyval.array)->symbol = (yyvsp[0].expression)->symbol;
                            (yyval.array)->temp = (yyval.array)->symbol;
                            (yyval.array)->subArrayType = (yyvsp[0].expression)->symbol->type;
                        }
#line 1435 "A6_42.tab.c"
    break;

  case 8: /* postfix_expression: postfix_expression LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET  */
#line 183 "A6_42.y"
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
#line 1459 "A6_42.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression LEFT_PARENTHESES argument_expression_list_opt RIGHT_PARENTHESES  */
#line 203 "A6_42.y"
                        { 

                            yyinfo("postfix_expression => postfix_expression ( argument_expression_list_opt )"); 
                            (yyval.array) = new Array();
                            (yyval.array)->symbol = gentemp((yyvsp[-3].array)->symbol->type->type);
                            (yyval.array)->symbol->type->arrayType = (yyvsp[-3].array)->symbol->type->arrayType;
                            emit("call", (yyval.array)->symbol->name, (yyvsp[-3].array)->symbol->name, toString((yyvsp[-1].parameterCount)));
                        }
#line 1472 "A6_42.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 212 "A6_42.y"
                        { 
                            yyinfo("postfix_expression => postfix_expression -> IDENTIFIER"); 
                        }
#line 1480 "A6_42.tab.c"
    break;

  case 11: /* postfix_expression: LEFT_PARENTHESES type_name RIGHT_PARENTHESES LEFT_CURLY_BRACKET initialiser_list RIGHT_CURLY_BRACKET  */
#line 216 "A6_42.y"
                        { 
                            yyinfo("postfix_expression => ( type_name ) { initialiser_list }"); 
                        }
#line 1488 "A6_42.tab.c"
    break;

  case 12: /* postfix_expression: LEFT_PARENTHESES type_name RIGHT_PARENTHESES LEFT_CURLY_BRACKET initialiser_list COMMA RIGHT_CURLY_BRACKET  */
#line 220 "A6_42.y"
                        { 
                            yyinfo("postfix_expression => ( type_name ) { initialiser_list , }"); 
                        }
#line 1496 "A6_42.tab.c"
    break;

  case 13: /* argument_expression_list_opt: argument_expression_list  */
#line 229 "A6_42.y"
                                    { 
                                        yyinfo("argument_expression_list_opt => argument_expression_list"); 
                                        (yyval.parameterCount) = (yyvsp[0].parameterCount);
                                    }
#line 1505 "A6_42.tab.c"
    break;

  case 14: /* argument_expression_list_opt: %empty  */
#line 234 "A6_42.y"
                                    { 

                                        yyinfo("argument_expression_list_opt => epsilon");
                                        (yyval.parameterCount) = 0;
                                    }
#line 1515 "A6_42.tab.c"
    break;

  case 15: /* argument_expression_list: assignment_expression  */
#line 243 "A6_42.y"
                                { 

                                    yyinfo("argument_expression_list => assignment_expression"); 
                                    emit("param", (yyvsp[0].expression)->symbol->name);
                                    (yyval.parameterCount) = 1;
                                }
#line 1526 "A6_42.tab.c"
    break;

  case 16: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 250 "A6_42.y"
                                { 

                                    yyinfo("argument_expression_list => argument_expression_list , assignment_expression");
                                    emit("param", (yyvsp[0].expression)->symbol->name);
                                    (yyval.parameterCount) = (yyvsp[-2].parameterCount) + 1; 
                                }
#line 1537 "A6_42.tab.c"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 260 "A6_42.y"
                        { 
                            yyinfo("unary_expression => postfix_expression"); 
                            (yyval.array) = (yyvsp[0].array);
                        }
#line 1546 "A6_42.tab.c"
    break;

  case 18: /* unary_expression: unary_operator unary_expression  */
#line 265 "A6_42.y"
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
#line 1574 "A6_42.tab.c"
    break;

  case 19: /* unary_operator: ASTERISK  */
#line 294 "A6_42.y"
                    { 
                        yyinfo("unary_operator => *"); 
                        (yyval.unaryOperator) = strdup("*"); 
                    }
#line 1583 "A6_42.tab.c"
    break;

  case 20: /* unary_operator: PLUS  */
#line 299 "A6_42.y"
                    { 
                        yyinfo("unary_operator => +"); 
                        (yyval.unaryOperator) = strdup("+"); 
                    }
#line 1592 "A6_42.tab.c"
    break;

  case 21: /* unary_operator: MINUS  */
#line 304 "A6_42.y"
                    { 
                        yyinfo("unary_operator => -"); 
                        (yyval.unaryOperator) = strdup("=-"); 
                    }
#line 1601 "A6_42.tab.c"
    break;

  case 22: /* unary_operator: EXCLAMATION  */
#line 309 "A6_42.y"
                    { 
                        yyinfo("unary_operator => !"); 
                        (yyval.unaryOperator) = strdup("!"); 
                    }
#line 1610 "A6_42.tab.c"
    break;

  case 23: /* unary_operator: ADDRESS  */
#line 314 "A6_42.y"
                     {
                     yyinfo("unary_operator => &"); 
                                        (yyval.unaryOperator) = strdup("&");
                                    }
#line 1619 "A6_42.tab.c"
    break;

  case 24: /* multiplicative_expression: unary_expression  */
#line 325 "A6_42.y"
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
#line 1639 "A6_42.tab.c"
    break;

  case 25: /* multiplicative_expression: multiplicative_expression ASTERISK unary_expression  */
#line 341 "A6_42.y"
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
#line 1666 "A6_42.tab.c"
    break;

  case 26: /* multiplicative_expression: multiplicative_expression SLASH unary_expression  */
#line 364 "A6_42.y"
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
#line 1693 "A6_42.tab.c"
    break;

  case 27: /* multiplicative_expression: multiplicative_expression MODULO unary_expression  */
#line 387 "A6_42.y"
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
#line 1720 "A6_42.tab.c"
    break;

  case 28: /* additive_expression: multiplicative_expression  */
#line 413 "A6_42.y"
                        { 
                            yyinfo("additive_expression => multiplicative_expression"); 
                            (yyval.expression) = (yyvsp[0].expression);
                        }
#line 1729 "A6_42.tab.c"
    break;

  case 29: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 418 "A6_42.y"
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
#line 1744 "A6_42.tab.c"
    break;

  case 30: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 429 "A6_42.y"
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
#line 1759 "A6_42.tab.c"
    break;

  case 31: /* relational_expression: additive_expression  */
#line 447 "A6_42.y"
                            { 
                                yyinfo("relational_expression => additive_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1768 "A6_42.tab.c"
    break;

  case 32: /* relational_expression: relational_expression LESS_THAN additive_expression  */
#line 452 "A6_42.y"
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
#line 1786 "A6_42.tab.c"
    break;

  case 33: /* relational_expression: relational_expression GREATER_THAN additive_expression  */
#line 466 "A6_42.y"
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
#line 1804 "A6_42.tab.c"
    break;

  case 34: /* relational_expression: relational_expression LESS_EQUAL_THAN additive_expression  */
#line 480 "A6_42.y"
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
#line 1822 "A6_42.tab.c"
    break;

  case 35: /* relational_expression: relational_expression GREATER_EQUAL_THAN additive_expression  */
#line 494 "A6_42.y"
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
#line 1840 "A6_42.tab.c"
    break;

  case 36: /* equality_expression: relational_expression  */
#line 511 "A6_42.y"
                        { 
                            yyinfo("equality_expression => relational_expression"); 
                            (yyval.expression) = (yyvsp[0].expression);
                        }
#line 1849 "A6_42.tab.c"
    break;

  case 37: /* equality_expression: equality_expression EQUALS relational_expression  */
#line 516 "A6_42.y"
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
#line 1869 "A6_42.tab.c"
    break;

  case 38: /* equality_expression: equality_expression NOT_EQUALS relational_expression  */
#line 532 "A6_42.y"
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
#line 1889 "A6_42.tab.c"
    break;

  case 39: /* M: %empty  */
#line 552 "A6_42.y"
        {
            yyinfo("M => epsilon");
            (yyval.instructionNumber) = nextInstruction();
        }
#line 1898 "A6_42.tab.c"
    break;

  case 40: /* N: %empty  */
#line 559 "A6_42.y"
        {
            yyinfo("N => epsilon");
            (yyval.statement) = new Statement();
            (yyval.statement)->nextList = makeList(nextInstruction());
            emit("goto", "");
        }
#line 1909 "A6_42.tab.c"
    break;

  case 41: /* logical_AND_expression: equality_expression  */
#line 571 "A6_42.y"
                            { 
                                yyinfo("logical_AND_expression => equality_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1918 "A6_42.tab.c"
    break;

  case 42: /* logical_AND_expression: logical_AND_expression LOGICAL_AND M equality_expression  */
#line 576 "A6_42.y"
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
#line 1933 "A6_42.tab.c"
    break;

  case 43: /* logical_OR_expression: logical_AND_expression  */
#line 590 "A6_42.y"
                            { 
                                yyinfo("logical_OR_expression => logical_AND_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1942 "A6_42.tab.c"
    break;

  case 44: /* logical_OR_expression: logical_OR_expression LOGICAL_OR M logical_AND_expression  */
#line 595 "A6_42.y"
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
#line 1957 "A6_42.tab.c"
    break;

  case 45: /* conditional_expression: logical_OR_expression  */
#line 609 "A6_42.y"
                            { 
                                yyinfo("conditional_expression => logical_OR_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1966 "A6_42.tab.c"
    break;

  case 46: /* conditional_expression: logical_OR_expression N QUESTION_MARK M expression N COLON M conditional_expression  */
#line 614 "A6_42.y"
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
#line 1987 "A6_42.tab.c"
    break;

  case 47: /* assignment_expression: conditional_expression  */
#line 634 "A6_42.y"
                            { 
                                yyinfo("assignment_expression => conditional_expression"); 
                                (yyval.expression) = (yyvsp[0].expression);
                            }
#line 1996 "A6_42.tab.c"
    break;

  case 48: /* assignment_expression: unary_expression ASSIGNMENT assignment_expression  */
#line 639 "A6_42.y"
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
#line 2018 "A6_42.tab.c"
    break;

  case 49: /* expression: assignment_expression  */
#line 662 "A6_42.y"
                { 
                    yyinfo("expression => assignment_expression"); 
                    (yyval.expression) = (yyvsp[0].expression);
                }
#line 2027 "A6_42.tab.c"
    break;

  case 50: /* expression: expression COMMA assignment_expression  */
#line 667 "A6_42.y"
                {
                     yyinfo("expression => expression , assignment_expression"); 
                }
#line 2035 "A6_42.tab.c"
    break;

  case 51: /* constant_expression: conditional_expression  */
#line 674 "A6_42.y"
                        {
                             yyinfo("constant_expression => conditional_expression"); 
                        }
#line 2043 "A6_42.tab.c"
    break;

  case 52: /* declaration: declaration_specifiers init_declarator_list_opt SEMI_COLON  */
#line 683 "A6_42.y"
                {
                     yyinfo("declaration => declaration_specifiers init_declarator_list_opt ;"); 
                }
#line 2051 "A6_42.tab.c"
    break;

  case 53: /* init_declarator_list_opt: init_declarator_list  */
#line 690 "A6_42.y"
                                {
                                     yyinfo("init_declarator_list_opt => init_declarator_list"); 
                                }
#line 2059 "A6_42.tab.c"
    break;

  case 54: /* init_declarator_list_opt: %empty  */
#line 694 "A6_42.y"
                                {
                                     yyinfo("init_declarator_list_opt => epsilon"); 
                                }
#line 2067 "A6_42.tab.c"
    break;

  case 55: /* declaration_specifiers: type_specifier declaration_specifiers_opt  */
#line 701 "A6_42.y"
                            {
                                 yyinfo("declaration_specifiers => type_specifier declaration_specifiers_opt"); 
                            }
#line 2075 "A6_42.tab.c"
    break;

  case 56: /* declaration_specifiers: type_qualifier declaration_specifiers_opt  */
#line 705 "A6_42.y"
                            {
                                 yyinfo("declaration_specifiers => type_qualifier declaration_specifiers_opt"); 
                            }
#line 2083 "A6_42.tab.c"
    break;

  case 57: /* declaration_specifiers_opt: declaration_specifiers  */
#line 712 "A6_42.y"
                                {
                                     yyinfo("declaration_specifiers_opt => declaration_specifiers"); 
                                }
#line 2091 "A6_42.tab.c"
    break;

  case 58: /* declaration_specifiers_opt: %empty  */
#line 716 "A6_42.y"
                                {
                                     yyinfo("declaration_specifiers_opt => epsilon "); 
                                }
#line 2099 "A6_42.tab.c"
    break;

  case 59: /* init_declarator_list: init_declarator  */
#line 723 "A6_42.y"
                            {
                                 yyinfo("init_declarator_list => init_declarator"); 
                            }
#line 2107 "A6_42.tab.c"
    break;

  case 60: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 727 "A6_42.y"
                            {
                                 yyinfo("init_declarator_list => init_declarator_list , init_declarator"); 
                            }
#line 2115 "A6_42.tab.c"
    break;

  case 61: /* init_declarator: declarator  */
#line 734 "A6_42.y"
                    { 
                        yyinfo("init_declarator => declarator"); 
                        (yyval.symbol) = (yyvsp[0].symbol);
                    }
#line 2124 "A6_42.tab.c"
    break;

  case 62: /* init_declarator: declarator ASSIGNMENT initialiser  */
#line 739 "A6_42.y"
                    { 
                        yyinfo("init_declarator => declarator = initialiser");
                       
                        if((yyvsp[0].symbol)->initialValue != "") 
                            (yyvsp[-2].symbol)->initialValue = (yyvsp[0].symbol)->initialValue;
             
		                emit("=", (yyvsp[-2].symbol)->name, (yyvsp[0].symbol)->name);
                    }
#line 2137 "A6_42.tab.c"
    break;

  case 63: /* type_specifier: VOIDTYPE  */
#line 753 "A6_42.y"
                    { 
                        yyinfo("type_specifier => void");
                        currentType = SymbolType::VOID;
                    }
#line 2146 "A6_42.tab.c"
    break;

  case 64: /* type_specifier: INTTYPE  */
#line 758 "A6_42.y"
                    { 
                        yyinfo("type_specifier => int"); 
                        currentType = SymbolType::INT;
                    }
#line 2155 "A6_42.tab.c"
    break;

  case 65: /* specifier_qualifier_list: type_specifier specifier_qualifier_list_opt  */
#line 766 "A6_42.y"
                                { 
                                    yyinfo("specifier_qualifier_list => type_specifier specifier_qualifier_list_opt"); 
                                }
#line 2163 "A6_42.tab.c"
    break;

  case 66: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list_opt  */
#line 770 "A6_42.y"
                                { 
                                    yyinfo("specifier_qualifier_list => type_qualifier specifier_qualifier_list_opt"); 
                                }
#line 2171 "A6_42.tab.c"
    break;

  case 67: /* specifier_qualifier_list_opt: specifier_qualifier_list  */
#line 777 "A6_42.y"
                                    { 
                                        yyinfo("specifier_qualifier_list_opt => specifier_qualifier_list"); 
                                    }
#line 2179 "A6_42.tab.c"
    break;

  case 68: /* specifier_qualifier_list_opt: %empty  */
#line 781 "A6_42.y"
                                    { 
                                        yyinfo("specifier_qualifier_list_opt => epsilon"); 
                                    }
#line 2187 "A6_42.tab.c"
    break;

  case 69: /* type_qualifier: CONST  */
#line 790 "A6_42.y"
                    { 
                        yyinfo("type_qualifier => const"); 
                    }
#line 2195 "A6_42.tab.c"
    break;

  case 70: /* declarator: pointer direct_declarator  */
#line 799 "A6_42.y"
                { 
                    yyinfo("declarator => pointer direct_declarator"); 
                    SymbolType *it = (yyvsp[-1].symbolType);
                    while(it->arrayType != NULL) 
                        it = it->arrayType;
                    it->arrayType = (yyvsp[0].symbol)->type;
                    (yyval.symbol) = (yyvsp[0].symbol)->update((yyvsp[-1].symbolType));
                }
#line 2208 "A6_42.tab.c"
    break;

  case 71: /* declarator: direct_declarator  */
#line 808 "A6_42.y"
                { 
                    yyinfo("declarator => direct_declarator"); 
                }
#line 2216 "A6_42.tab.c"
    break;

  case 72: /* change_scope: %empty  */
#line 814 "A6_42.y"
                    {
                        if(currentSymbol->nestedTable == NULL) {
                            changeTable(new SymbolTable(""));
                        }
                        else {
                            changeTable(currentSymbol->nestedTable);
                            emit("label", currentTable->name);
                        }
                    }
#line 2230 "A6_42.tab.c"
    break;

  case 73: /* direct_declarator: IDENTIFIER  */
#line 828 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => IDENTIFIER"); 
                            (yyval.symbol) = (yyvsp[0].symbol)->update(new SymbolType(currentType)); 
                            currentSymbol = (yyval.symbol);
                        }
#line 2240 "A6_42.tab.c"
    break;

  case 74: /* direct_declarator: LEFT_PARENTHESES declarator RIGHT_PARENTHESES  */
#line 834 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => ( declarator )"); 
                            (yyval.symbol) = (yyvsp[-1].symbol);
                        }
#line 2249 "A6_42.tab.c"
    break;

  case 75: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list assignment_expression RIGHT_SQUARE_BRACKET  */
#line 839 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ type_qualifier_list assignment_expression ]"); 
                        }
#line 2257 "A6_42.tab.c"
    break;

  case 76: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list RIGHT_SQUARE_BRACKET  */
#line 843 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ type_qualifier_list ]"); 
                        }
#line 2265 "A6_42.tab.c"
    break;

  case 77: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET assignment_expression RIGHT_SQUARE_BRACKET  */
#line 847 "A6_42.y"
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
#line 2285 "A6_42.tab.c"
    break;

  case 78: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET  */
#line 863 "A6_42.y"
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
#line 2306 "A6_42.tab.c"
    break;

  case 79: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list ASTERISK RIGHT_SQUARE_BRACKET  */
#line 880 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ type_qualifier_list * ]"); 
                        }
#line 2314 "A6_42.tab.c"
    break;

  case 80: /* direct_declarator: direct_declarator LEFT_SQUARE_BRACKET ASTERISK RIGHT_SQUARE_BRACKET  */
#line 884 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator [ * ]"); 
                        }
#line 2322 "A6_42.tab.c"
    break;

  case 81: /* direct_declarator: direct_declarator LEFT_PARENTHESES change_scope parameter_type_list RIGHT_PARENTHESES  */
#line 888 "A6_42.y"
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
#line 2342 "A6_42.tab.c"
    break;

  case 82: /* direct_declarator: direct_declarator LEFT_PARENTHESES identifier_list RIGHT_PARENTHESES  */
#line 904 "A6_42.y"
                        { 
                            yyinfo("direct_declarator => direct_declarator ( identifier_list )"); 
                        }
#line 2350 "A6_42.tab.c"
    break;

  case 83: /* direct_declarator: direct_declarator LEFT_PARENTHESES change_scope RIGHT_PARENTHESES  */
#line 908 "A6_42.y"
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
#line 2370 "A6_42.tab.c"
    break;

  case 84: /* type_qualifier_list_opt: type_qualifier_list  */
#line 927 "A6_42.y"
                            { 
                                yyinfo("type_qualifier_list_opt => type_qualifier_list"); 
                            }
#line 2378 "A6_42.tab.c"
    break;

  case 85: /* type_qualifier_list_opt: %empty  */
#line 931 "A6_42.y"
                            { 
                                yyinfo("type_qualifier_list_opt => epsilon"); 
                            }
#line 2386 "A6_42.tab.c"
    break;

  case 86: /* pointer: ASTERISK type_qualifier_list_opt  */
#line 940 "A6_42.y"
            { 
                yyinfo("pointer => * type_qualifier_list_opt"); 
              
                (yyval.symbolType) = new SymbolType(SymbolType::POINTER);
            }
#line 2396 "A6_42.tab.c"
    break;

  case 87: /* pointer: ASTERISK type_qualifier_list_opt pointer  */
#line 946 "A6_42.y"
            { 
                yyinfo("pointer => * type_qualifier_list_opt pointer"); 
              
                (yyval.symbolType) = new SymbolType(SymbolType::POINTER, (yyvsp[0].symbolType));
            }
#line 2406 "A6_42.tab.c"
    break;

  case 88: /* type_qualifier_list: type_qualifier  */
#line 955 "A6_42.y"
                        { 
                            yyinfo("type_qualifier_list => type_qualifier"); 
                        }
#line 2414 "A6_42.tab.c"
    break;

  case 89: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 959 "A6_42.y"
                        { 
                            yyinfo("type_qualifier_list => type_qualifier_list type_qualifier"); 
                        }
#line 2422 "A6_42.tab.c"
    break;

  case 90: /* parameter_type_list: parameter_list  */
#line 966 "A6_42.y"
                        { 
                            yyinfo("parameter_type_list => parameter_list"); 
                        }
#line 2430 "A6_42.tab.c"
    break;

  case 91: /* parameter_list: parameter_declaration  */
#line 974 "A6_42.y"
                    { 
                        yyinfo("parameter_list => parameter_declaration"); 
                    }
#line 2438 "A6_42.tab.c"
    break;

  case 92: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 978 "A6_42.y"
                    { 
                        yyinfo("parameter_list => parameter_list , parameter_declaration"); 
                    }
#line 2446 "A6_42.tab.c"
    break;

  case 93: /* parameter_declaration: declaration_specifiers declarator  */
#line 985 "A6_42.y"
                            { 
                                yyinfo("parameter_declaration => declaration_specifiers declarator");
                                (yyvsp[0].symbol)->category = Symbol::PARAMETER; 
                                currentTable->parameters.push_back((yyvsp[0].symbol)->name);
                            }
#line 2456 "A6_42.tab.c"
    break;

  case 94: /* parameter_declaration: declaration_specifiers  */
#line 991 "A6_42.y"
                            { 
                                yyinfo("parameter_declaration => declaration_specifiers"); 
                            }
#line 2464 "A6_42.tab.c"
    break;

  case 95: /* identifier_list: IDENTIFIER  */
#line 998 "A6_42.y"
                    { 
                        yyinfo("identifier_list => IDENTIFIER"); 
                    }
#line 2472 "A6_42.tab.c"
    break;

  case 96: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 1002 "A6_42.y"
                    { 
                        yyinfo("identifier_list => identifier_list , IDENTIFIER"); 
                    }
#line 2480 "A6_42.tab.c"
    break;

  case 97: /* type_name: specifier_qualifier_list  */
#line 1009 "A6_42.y"
                { 
                    yyinfo("type_name => specifier_qualifier_list"); 
                }
#line 2488 "A6_42.tab.c"
    break;

  case 98: /* initialiser: assignment_expression  */
#line 1016 "A6_42.y"
                { 
                    yyinfo("initialiser => assignment_expression"); 
                    (yyval.symbol) = (yyvsp[0].expression)->symbol;
                }
#line 2497 "A6_42.tab.c"
    break;

  case 99: /* initialiser: LEFT_CURLY_BRACKET initialiser_list RIGHT_CURLY_BRACKET  */
#line 1021 "A6_42.y"
                { 
                    yyinfo("initialiser => { initialiser_list }"); 
                }
#line 2505 "A6_42.tab.c"
    break;

  case 100: /* initialiser: LEFT_CURLY_BRACKET initialiser_list COMMA RIGHT_CURLY_BRACKET  */
#line 1025 "A6_42.y"
                { 
                    yyinfo("initialiser => { initialiser_list , }"); 
                }
#line 2513 "A6_42.tab.c"
    break;

  case 101: /* initialiser_list: designation_opt initialiser  */
#line 1032 "A6_42.y"
                        { 
                            yyinfo("initialiser_list => designation_opt initialiser"); 
                        }
#line 2521 "A6_42.tab.c"
    break;

  case 102: /* initialiser_list: initialiser_list COMMA designation_opt initialiser  */
#line 1036 "A6_42.y"
                        { 
                            yyinfo("initialiser_list => initialiser_list , designation_opt initialiser"); 
                        }
#line 2529 "A6_42.tab.c"
    break;

  case 103: /* designation_opt: designation  */
#line 1043 "A6_42.y"
                    { 
                        yyinfo("designation_opt => designation"); 
                    }
#line 2537 "A6_42.tab.c"
    break;

  case 104: /* designation_opt: %empty  */
#line 1047 "A6_42.y"
                    { 
                        yyinfo("designation_opt => epsilon"); 
                    }
#line 2545 "A6_42.tab.c"
    break;

  case 105: /* designation: designator_list ASSIGNMENT  */
#line 1054 "A6_42.y"
                { 
                    yyinfo("designation => designator_list ="); 
                }
#line 2553 "A6_42.tab.c"
    break;

  case 106: /* designator_list: designator  */
#line 1061 "A6_42.y"
                    { 
                        yyinfo("designator_list => designator"); 
                    }
#line 2561 "A6_42.tab.c"
    break;

  case 107: /* designator_list: designator_list designator  */
#line 1065 "A6_42.y"
                    { 
                        yyinfo("designator_list => designator_list designator"); 
                    }
#line 2569 "A6_42.tab.c"
    break;

  case 108: /* designator: LEFT_SQUARE_BRACKET constant_expression RIGHT_SQUARE_BRACKET  */
#line 1072 "A6_42.y"
                { 
                    yyinfo("designator => [ constant_expression ]"); 
                }
#line 2577 "A6_42.tab.c"
    break;

  case 109: /* statement: compound_statement  */
#line 1082 "A6_42.y"
                { 
                    yyinfo("statement => compound_statement");
                    (yyval.statement) = (yyvsp[0].statement); 
                }
#line 2586 "A6_42.tab.c"
    break;

  case 110: /* statement: expression_statement  */
#line 1087 "A6_42.y"
                { 
                    yyinfo("statement => expression_statement"); 
                    (yyval.statement) = new Statement();
                    (yyval.statement)->nextList = (yyvsp[0].expression)->nextList;
                }
#line 2596 "A6_42.tab.c"
    break;

  case 111: /* statement: selection_statement  */
#line 1093 "A6_42.y"
                { 
                    yyinfo("statement => selection_statement"); 
                    (yyval.statement) = (yyvsp[0].statement);
                }
#line 2605 "A6_42.tab.c"
    break;

  case 112: /* statement: iteration_statement  */
#line 1098 "A6_42.y"
                { 
                    yyinfo("statement => iteration_statement"); 
                    (yyval.statement) = (yyvsp[0].statement);
                }
#line 2614 "A6_42.tab.c"
    break;

  case 113: /* statement: jump_statement  */
#line 1103 "A6_42.y"
                { 
                    yyinfo("statement => jump_statement"); 
                    (yyval.statement) = (yyvsp[0].statement);
                }
#line 2623 "A6_42.tab.c"
    break;

  case 114: /* compound_statement: BEGIN block_item_list_opt END  */
#line 1114 "A6_42.y"
                        { 
                            yyinfo("compound_statement => BEGIN block_item_list_opt END"); 
                            (yyval.statement) = (yyvsp[-1].statement);
                        }
#line 2632 "A6_42.tab.c"
    break;

  case 115: /* block_item_list_opt: block_item_list  */
#line 1122 "A6_42.y"
                        { 
                            yyinfo("block_item_list_opt => block_item_list"); 
                            (yyval.statement) = (yyvsp[0].statement);
                        }
#line 2641 "A6_42.tab.c"
    break;

  case 116: /* block_item_list_opt: %empty  */
#line 1127 "A6_42.y"
                        { 
                            yyinfo("block_item_list_opt => epsilon"); 
                            (yyval.statement) = new Statement();
                        }
#line 2650 "A6_42.tab.c"
    break;

  case 117: /* block_item_list: block_item  */
#line 1135 "A6_42.y"
                    {
                        yyinfo("block_item_list => block_item"); 
                        (yyval.statement) = (yyvsp[0].statement);
                    }
#line 2659 "A6_42.tab.c"
    break;

  case 118: /* block_item_list: block_item_list M block_item  */
#line 1140 "A6_42.y"
                    { 
                        yyinfo("block_item_list => block_item_list block_item"); 
                        (yyval.statement) = (yyvsp[0].statement);
                        
                        backpatch((yyvsp[-2].statement)->nextList,(yyvsp[-1].instructionNumber));
                    }
#line 2670 "A6_42.tab.c"
    break;

  case 119: /* block_item: declaration  */
#line 1150 "A6_42.y"
                { 
                    yyinfo("block_item => declaration"); 
                    (yyval.statement) = new Statement();
                }
#line 2679 "A6_42.tab.c"
    break;

  case 120: /* block_item: statement  */
#line 1155 "A6_42.y"
                { 
                    yyinfo("block_item => statement"); 
                    (yyval.statement) = (yyvsp[0].statement);
                }
#line 2688 "A6_42.tab.c"
    break;

  case 121: /* expression_statement: expression_opt SEMI_COLON  */
#line 1163 "A6_42.y"
                            { 
                                yyinfo("expression_statement => expression_opt ;"); 
                                (yyval.expression) = (yyvsp[-1].expression);
                            }
#line 2697 "A6_42.tab.c"
    break;

  case 122: /* expression_opt: expression  */
#line 1171 "A6_42.y"
                    { 
                        yyinfo("expression_opt => expression"); 
                        (yyval.expression) = (yyvsp[0].expression);
                    }
#line 2706 "A6_42.tab.c"
    break;

  case 123: /* expression_opt: %empty  */
#line 1176 "A6_42.y"
                    { 
                        yyinfo("expression_opt => epsilon"); 
                        (yyval.expression) = new Expression();
                    }
#line 2715 "A6_42.tab.c"
    break;

  case 124: /* selection_statement: IF LEFT_PARENTHESES expression RIGHT_PARENTHESES M statement N  */
#line 1186 "A6_42.y"
                        { 
                            yyinfo("selection_statement => if ( expression ) statement"); 
                            (yyval.statement) = new Statement();
                            (yyvsp[-4].expression)->toBool();
                            backpatch((yyvsp[-4].expression)->trueList, (yyvsp[-2].instructionNumber)); 
                            (yyval.statement)->nextList = merge((yyvsp[-4].expression)->falseList, merge((yyvsp[-1].statement)->nextList, (yyvsp[0].statement)->nextList)); 
                        }
#line 2727 "A6_42.tab.c"
    break;

  case 125: /* selection_statement: IF LEFT_PARENTHESES expression RIGHT_PARENTHESES M statement N ELSE M statement  */
#line 1194 "A6_42.y"
                        { 
                            yyinfo("selection_statement => if ( expression ) statement else statement"); 
                            (yyval.statement) = new Statement();
                            (yyvsp[-7].expression)->toBool();
                            backpatch((yyvsp[-7].expression)->trueList, (yyvsp[-5].instructionNumber)); 
                            backpatch((yyvsp[-7].expression)->falseList, (yyvsp[-1].instructionNumber)); 
                            (yyval.statement)->nextList = merge((yyvsp[0].statement)->nextList, merge((yyvsp[-4].statement)->nextList, (yyvsp[-3].statement)->nextList)); 
                        }
#line 2740 "A6_42.tab.c"
    break;

  case 126: /* iteration_statement: FOR LEFT_PARENTHESES expression_opt SEMI_COLON M expression_opt SEMI_COLON M expression_opt N RIGHT_PARENTHESES M statement  */
#line 1208 "A6_42.y"
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
#line 2755 "A6_42.tab.c"
    break;

  case 127: /* iteration_statement: FOR LEFT_PARENTHESES declaration expression_opt SEMI_COLON expression_opt RIGHT_PARENTHESES statement  */
#line 1219 "A6_42.y"
                        { 
                            yyinfo("iteration_statement => for ( declaration expression_opt ; expression_opt ) statement"); 
                        }
#line 2763 "A6_42.tab.c"
    break;

  case 128: /* jump_statement: RETURN expression_opt SEMI_COLON  */
#line 1226 "A6_42.y"
                    { 
                        yyinfo("jump_statement => return expression_opt ;"); 
                        (yyval.statement) = new Statement();
                        if((yyvsp[-1].expression)->symbol != NULL) {
                            emit("return", (yyvsp[-1].expression)->symbol->name); 
                        } else {
                            emit("return", "");
                        }
                    }
#line 2777 "A6_42.tab.c"
    break;

  case 129: /* translation_unit: external_declaration  */
#line 1241 "A6_42.y"
                        { 
                            yyinfo("translation_unit => external_declaration"); 
                        }
#line 2785 "A6_42.tab.c"
    break;

  case 130: /* translation_unit: translation_unit external_declaration  */
#line 1245 "A6_42.y"
                        { 
                            yyinfo("translation_unit => translation_unit external_declaration"); 
                        }
#line 2793 "A6_42.tab.c"
    break;

  case 131: /* external_declaration: function_definition  */
#line 1252 "A6_42.y"
                            { 
                                yyinfo("external_declaration => function_definition"); 
                            }
#line 2801 "A6_42.tab.c"
    break;

  case 132: /* external_declaration: declaration  */
#line 1256 "A6_42.y"
                            { 
                                yyinfo("external_declaration => declaration"); 
                            }
#line 2809 "A6_42.tab.c"
    break;

  case 133: /* function_definition: declaration_specifiers declarator declaration_list_opt change_scope LEFT_CURLY_BRACKET block_item_list_opt RIGHT_CURLY_BRACKET  */
#line 1263 "A6_42.y"
                        { 
                            yyinfo("function_definition => declaration_specifiers declarator declaration_list_opt compound_statement"); 
                            tableCount = 0;
                            emit("labelend", (yyvsp[-5].symbol)->name);
                            if((yyvsp[-5].symbol)->type->type != SymbolType::VOID) {
                                currentTable->lookup("return")->update((yyvsp[-5].symbol)->type);
                            }
                            changeTable(globalTable);
                        }
#line 2823 "A6_42.tab.c"
    break;

  case 134: /* declaration_list_opt: declaration_list  */
#line 1276 "A6_42.y"
                            { 
                                yyinfo("declaration_list_opt => declaration_list"); 
                            }
#line 2831 "A6_42.tab.c"
    break;

  case 135: /* declaration_list_opt: %empty  */
#line 1280 "A6_42.y"
                            { 
                                yyinfo("declaration_list_opt => epsilon"); 
                            }
#line 2839 "A6_42.tab.c"
    break;

  case 136: /* declaration_list: declaration  */
#line 1287 "A6_42.y"
                        { 
                            yyinfo("declaration_list => declaration"); 
                        }
#line 2847 "A6_42.tab.c"
    break;

  case 137: /* declaration_list: declaration_list declaration  */
#line 1291 "A6_42.y"
                        { 
                            yyinfo("declaration_list => declaration_list declaration"); 
                        }
#line 2855 "A6_42.tab.c"
    break;


#line 2859 "A6_42.tab.c"

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

#line 1296 "A6_42.y"


void yyerror(string s) {
    printf("ERROR [Line %d] : %s\n", lineCount, s.c_str());
}

void yyinfo(string s) {
    #ifdef _DEBUG
        printf("INFO [Line %d] : %s\n", lineCount, s.c_str());
    #endif
}
