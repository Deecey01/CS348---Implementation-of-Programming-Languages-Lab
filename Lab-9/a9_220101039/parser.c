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
#line 1 "a9_220101039.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "quad_array.h"
#include "type_check.h"

extern FILE *yyin;
extern int yylex();
extern int line_no;

// Global variables
SymbolTable *global_table;
SymbolTable *current_table;
FILE *output_file = NULL;

// For backpatching
typedef struct Attributes{
    QuadList *truelist;    // List of quads to backpatch with true exits
    QuadList *falselist;   // List of quads to backpatch with false exits
    QuadList *nextlist;    // List of quads to backpatch with next statement
    Symbol *symbol;        // Symbol entry
    TypeName type;         // Expression type
    char *addr;            // Address (identifier)
    int is_array;          // If the expression is an array
    int array_size;        // Size of array (if applicable)
} Attributes;

// For array indexing
typedef struct ArrayRef{
    Symbol *array;         // Array symbol
    Symbol *offset;        // Offset symbol (index)
    TypeName elem_type;    // Element type
} ArrayRef;

// Stack for nested scopes
typedef struct ScopeStack {
    SymbolTable *table;
    struct ScopeStack *next;
} ScopeStack;

ScopeStack *scope_stack = NULL;

// Function to push a new scope
void push_scope(SymbolTable *table) {
    ScopeStack *new_scope = (ScopeStack *)malloc(sizeof(ScopeStack));
    new_scope->table = table;
    new_scope->next = scope_stack;
    scope_stack = new_scope;
    current_table = table;
}

// Function to pop a scope
void pop_scope() {
    if (scope_stack) {
        ScopeStack *temp = scope_stack;
        scope_stack = scope_stack->next;
        free(temp);
        current_table = scope_stack ? scope_stack->table : global_table;
    }
}

// Error reporting function
void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_no, s);
    if (output_file) {
        fprintf(output_file, "Error at line %d: %s\n", line_no, s);
    }
}

// Print reduction message
void logging(const char *rule) {
    if (output_file) {
        fprintf(output_file, "(Line No. %d) Reduction: %s\n", line_no, rule);
    }
}

// Function to create and initialize a new attribute
Attributes* create_attr() {
    Attributes* attr = (Attributes*)malloc(sizeof(Attributes));
    if (!attr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    attr->symbol = NULL;
    attr->truelist = NULL;
    attr->falselist = NULL;
    attr->nextlist = NULL;
    attr->type = VOID_TYPE;
    attr->addr = NULL;
    attr->is_array = 0;
    attr->array_size = 0;
    return attr;
}

// Function to create a new temporary variable for a given type
Symbol *new_temp(TypeName type) {
    return gentemp(current_table, type, get_type_size(type));
}


#line 174 "parser.c"

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

#include "parser.h"
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
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_ARROW = 20,                     /* ARROW  */
  YYSYMBOL_INC = 21,                       /* INC  */
  YYSYMBOL_DEC = 22,                       /* DEC  */
  YYSYMBOL_LEFT_SHIFT = 23,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 24,               /* RIGHT_SHIFT  */
  YYSYMBOL_LE_OP = 25,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 26,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 27,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 28,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 29,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 30,                     /* OR_OP  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '?'  */
  YYSYMBOL_33_ = 33,                       /* ':'  */
  YYSYMBOL_34_ = 34,                       /* '|'  */
  YYSYMBOL_35_ = 35,                       /* '^'  */
  YYSYMBOL_36_ = 36,                       /* '&'  */
  YYSYMBOL_37_ = 37,                       /* '<'  */
  YYSYMBOL_38_ = 38,                       /* '>'  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_43_ = 43,                       /* '%'  */
  YYSYMBOL_44_ = 44,                       /* '!'  */
  YYSYMBOL_UMINUS = 45,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 46,                     /* UPLUS  */
  YYSYMBOL_DEREF = 47,                     /* DEREF  */
  YYSYMBOL_ADDRESS = 48,                   /* ADDRESS  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '.'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* ';'  */
  YYSYMBOL_56_ = 56,                       /* '{'  */
  YYSYMBOL_57_ = 57,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_M = 59,                         /* M  */
  YYSYMBOL_N = 60,                         /* N  */
  YYSYMBOL_primary_expression = 61,        /* primary_expression  */
  YYSYMBOL_array_reference = 62,           /* array_reference  */
  YYSYMBOL_postfix_expression = 63,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 64,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 65,          /* unary_expression  */
  YYSYMBOL_multiplicative_expression = 66, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 67,       /* additive_expression  */
  YYSYMBOL_shift_expression = 68,          /* shift_expression  */
  YYSYMBOL_relational_expression = 69,     /* relational_expression  */
  YYSYMBOL_equality_expression = 70,       /* equality_expression  */
  YYSYMBOL_and_expression = 71,            /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 72,   /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 73,   /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 74,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 75,     /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 76,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 77,     /* assignment_expression  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_declaration = 79,               /* declaration  */
  YYSYMBOL_init_declarator = 80,           /* init_declarator  */
  YYSYMBOL_type_specifier = 81,            /* type_specifier  */
  YYSYMBOL_declarator = 82,                /* declarator  */
  YYSYMBOL_direct_declarator = 83,         /* direct_declarator  */
  YYSYMBOL_parameter_list = 84,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 85,     /* parameter_declaration  */
  YYSYMBOL_initializer = 86,               /* initializer  */
  YYSYMBOL_statement = 87,                 /* statement  */
  YYSYMBOL_compound_statement = 88,        /* compound_statement  */
  YYSYMBOL_89_1 = 89,                      /* $@1  */
  YYSYMBOL_block_item_list = 90,           /* block_item_list  */
  YYSYMBOL_block_item = 91,                /* block_item  */
  YYSYMBOL_expression_statement = 92,      /* expression_statement  */
  YYSYMBOL_selection_statement = 93,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 94,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 95,            /* jump_statement  */
  YYSYMBOL_translation_unit = 96,          /* translation_unit  */
  YYSYMBOL_external_declaration = 97,      /* external_declaration  */
  YYSYMBOL_function_definition = 98        /* function_definition  */
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
       2,     2,     2,    44,     2,     2,     2,    43,    36,     2,
      51,    52,    41,    39,    54,    40,    53,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    55,
      37,    31,    38,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    34,    57,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   172,   172,   181,   189,   196,   203,   210,   217,   232,
     239,   284,   289,   340,   350,   364,   369,   377,   381,   394,
     416,   420,   430,   447,   451,   464,   477,   503,   507,   520,
     536,   540,   557,   577,   581,   598,   615,   632,   652,   656,
     673,   693,   697,   717,   721,   741,   745,   765,   769,   793,
     797,   821,   825,   871,   875,   903,   911,   923,   929,   933,
     956,   960,   964,   968,   975,   979,   992,   996,  1005,  1009,
    1017,  1028,  1031,  1037,  1064,  1072,  1080,  1084,  1088,  1092,
    1096,  1103,  1108,  1108,  1121,  1125,  1138,  1143,  1150,  1155,
    1162,  1172,  1189,  1205,  1224,  1240,  1249,  1258,  1265,  1276,
    1279,  1285,  1288,  1294
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
  "STRING_LITERAL", "RETURN", "VOID", "CHAR", "INT", "FLOAT", "FOR",
  "WHILE", "IF", "DO", "ELSE", "BREAK", "CONTINUE", "ARROW", "INC", "DEC",
  "LEFT_SHIFT", "RIGHT_SHIFT", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "'='", "'?'", "':'", "'|'", "'^'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "UPLUS",
  "DEREF", "ADDRESS", "'['", "']'", "'('", "')'", "'.'", "','", "';'",
  "'{'", "'}'", "$accept", "M", "N", "primary_expression",
  "array_reference", "postfix_expression", "argument_expression_list",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "expression",
  "declaration", "init_declarator", "type_specifier", "declarator",
  "direct_declarator", "parameter_list", "parameter_declaration",
  "initializer", "statement", "compound_statement", "$@1",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,  -135,  -135,  -135,  -135,  -135,    32,   176,  -135,  -135,
     -13,    32,    32,   -44,   -18,    -2,  -135,  -135,    68,  -135,
       3,  -135,   217,    18,  -135,   104,    31,  -135,  -135,  -135,
    -135,  -135,  -135,   217,   217,   217,   217,   217,   217,  -135,
    -135,   -42,    53,     5,     0,    80,   -11,    82,    55,    70,
      73,    83,    62,  -135,  -135,  -135,  -135,   139,  -135,    32,
      44,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,    67,
     217,   211,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,  -135,
    -135,   217,    38,    74,  -135,    87,  -135,    84,   105,  -135,
     106,  -135,    32,  -135,  -135,   102,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,    13,  -135,   113,  -135,    47,  -135,  -135,
    -135,  -135,  -135,  -135,     5,     5,     0,     0,    80,    80,
      80,    80,   -11,   -11,    82,    55,    70,   217,   217,   131,
    -135,   114,   126,   117,   217,   193,  -135,  -135,  -135,   140,
    -135,   139,  -135,  -135,  -135,   217,    73,    83,   217,  -135,
    -135,   217,   120,   159,  -135,  -135,  -135,   126,   122,  -135,
    -135,  -135,  -135,   193,   133,   217,   193,   165,   217,  -135,
    -135,  -135,   137,   141,  -135,   136,  -135,   193,  -135,   193,
    -135,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    60,    61,    62,    63,   102,     0,     0,    99,   101,
      66,     0,     0,     0,    56,    64,     1,   100,     0,    65,
       0,    57,     0,    82,   103,     0,     0,    68,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,    11,
      12,    17,    23,    27,    30,    33,    38,    41,    43,    45,
      47,    49,    51,    53,    75,    59,    81,     0,    70,    74,
       0,    71,    67,    18,    20,    21,    19,    22,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       2,     0,     0,     0,     2,     0,     2,     0,     0,    88,
       0,    86,     0,    87,    76,     2,    84,    77,    78,    79,
      80,    73,    69,     0,     9,     0,    13,     0,    15,    54,
      24,    25,    26,    23,    28,    29,    31,    32,    36,    37,
      34,    35,    39,    40,    42,    44,    46,     0,     0,     0,
      95,     0,     0,     0,     0,     0,    97,    98,    89,    56,
      83,     0,    72,    10,    14,     0,    48,    50,     0,    96,
       2,     0,     0,     0,    85,    16,    52,     0,     0,     2,
       2,     2,     2,     0,     0,     0,     0,    90,     0,     3,
      92,     3,     0,     0,     2,     0,     2,     0,    94,     0,
      91,    93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,   -84,    11,  -135,  -135,  -135,  -135,   -17,    41,    48,
     -52,    51,   116,   118,   115,    76,    66,  -135,    52,   -21,
     -38,   -54,  -135,   -23,    -7,  -135,  -135,   112,  -135,   -65,
     205,  -135,  -135,    75,  -134,  -135,  -135,  -135,  -135,   220,
    -135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   137,   183,    39,    40,    41,   117,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    68,
     100,     5,    13,     6,    14,    15,    60,    61,    55,   103,
     104,    57,   105,   106,   107,   108,   109,   110,     7,     8,
       9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    54,    59,   101,    19,    20,   138,    70,   160,    71,
     143,    21,   145,    22,    80,    81,    63,    64,    65,    66,
      67,   151,     1,     2,     3,     4,    82,    83,   128,   129,
     130,   131,   115,   171,   102,    10,    18,   -58,    23,    76,
      77,    28,    29,    30,    31,    32,    73,    74,    75,    25,
     118,   119,   111,   139,   141,    27,   120,   121,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,    26,    11,    33,    56,   167,    34,    35,    36,
     163,    62,    37,    12,    72,   173,   174,   175,   176,    38,
      59,    86,    90,   140,    91,   149,   112,   101,   113,   154,
     187,   155,   189,    78,    79,    87,   162,    88,   177,    84,
      85,   180,    89,     1,     2,     3,     4,   124,   125,   114,
     123,   123,   190,   168,   191,   142,   126,   127,   102,    28,
      29,    30,    31,    32,   165,   132,   133,   179,   144,   146,
     182,   123,    28,    29,    30,    31,    32,    92,     1,     2,
       3,     4,    93,    94,    95,    96,    58,    97,    98,   150,
     147,   148,    33,   153,   158,    34,    35,    36,   161,   159,
      37,    22,   169,   170,   172,    33,    16,    38,    34,    35,
      36,    99,   181,    37,   178,     1,     2,     3,     4,   185,
      38,   188,   184,   186,    99,    23,    28,    29,    30,    31,
      32,    92,   134,   136,   157,   135,    93,    94,    95,    96,
     166,    97,    98,   156,    28,    29,    30,    31,    32,    24,
      28,    29,    30,    31,    32,   152,   164,    17,     0,    33,
       0,     0,    34,    35,    36,     0,     0,    37,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    33,    99,    23,
      34,    35,    36,    33,     0,    37,    34,    35,    36,     0,
       0,    37,    38,   116,     0,     0,     0,     0,    38
};

static const yytype_int16 yycheck[] =
{
      38,    22,    25,    57,    11,    12,    90,    49,   142,    51,
      94,    55,    96,    31,    25,    26,    33,    34,    35,    36,
      37,   105,     9,    10,    11,    12,    37,    38,    80,    81,
      82,    83,    70,   167,    57,     3,    49,    55,    56,    39,
      40,     3,     4,     5,     6,     7,    41,    42,    43,    51,
      71,    72,    59,    91,    92,    52,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     4,    41,    36,    57,   160,    39,    40,    41,
     145,    50,    44,    51,    31,   169,   170,   171,   172,    51,
     113,    36,    30,    55,    32,   102,    52,   151,    54,    52,
     184,    54,   186,    23,    24,    35,   144,    34,   173,    27,
      28,   176,    29,     9,    10,    11,    12,    76,    77,    52,
     137,   138,   187,   161,   189,    51,    78,    79,   151,     3,
       4,     5,     6,     7,   155,    84,    85,   175,    51,    55,
     178,   158,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    52,    18,    19,    57,
      55,    55,    36,    50,    33,    39,    40,    41,    51,    55,
      44,    31,    52,    14,    52,    36,     0,    51,    39,    40,
      41,    55,    17,    44,    51,     9,    10,    11,    12,    52,
      51,    55,   181,    52,    55,    56,     3,     4,     5,     6,
       7,     8,    86,    88,   138,    87,    13,    14,    15,    16,
     158,    18,    19,   137,     3,     4,     5,     6,     7,    14,
       3,     4,     5,     6,     7,   113,   151,     7,    -1,    36,
      -1,    -1,    39,    40,    41,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    36,    55,    56,
      39,    40,    41,    36,    -1,    44,    39,    40,    41,    -1,
      -1,    44,    51,    52,    -1,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    79,    81,    96,    97,    98,
       3,    41,    51,    80,    82,    83,     0,    97,    49,    82,
      82,    55,    31,    56,    88,    51,     4,    52,     3,     4,
       5,     6,     7,    36,    39,    40,    41,    44,    51,    61,
      62,    63,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    86,    57,    89,    52,    81,
      84,    85,    50,    65,    65,    65,    65,    65,    77,    78,
      49,    51,    31,    41,    42,    43,    39,    40,    23,    24,
      25,    26,    37,    38,    27,    28,    36,    35,    34,    29,
      30,    32,     8,    13,    14,    15,    16,    18,    19,    55,
      78,    79,    81,    87,    88,    90,    91,    92,    93,    94,
      95,    82,    52,    54,    52,    78,    52,    64,    77,    77,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    69,    69,    70,    71,    72,    59,    59,    78,
      55,    78,    51,    59,    51,    59,    55,    55,    55,    82,
      57,    59,    85,    50,    52,    54,    73,    74,    33,    55,
      92,    51,    78,    87,    91,    77,    76,    59,    78,    52,
      14,    92,    52,    59,    59,    59,    59,    87,    51,    78,
      87,    17,    78,    60,    60,    52,    52,    59,    55,    59,
      87,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    68,    69,    69,    69,    69,    69,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    87,    87,    87,    87,
      87,    88,    89,    88,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    96,
      96,    97,    97,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     1,     3,
       4,     1,     1,     3,     4,     1,     3,     1,     2,     2,
       2,     2,     2,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     4,     1,
       4,     1,     5,     1,     3,     1,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     4,     3,     4,
       3,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     4,     1,     3,     1,     1,     1,     2,
       6,    10,     7,    11,     9,     2,     3,     2,     2,     1,
       2,     1,     1,     3
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
  case 2: /* M: %empty  */
#line 172 "a9_220101039.y"
    { 
        (yyval.attr) = create_attr(); 
        (yyval.attr)->symbol = new_temp(INT_TYPE);  // Index of the next instruction
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        (yyval.attr)->symbol->type_info.int_val = quad_index;  // Current quad index
    }
#line 1419 "parser.c"
    break;

  case 3: /* N: %empty  */
#line 181 "a9_220101039.y"
    {
        (yyval.attr) = create_attr();
        (yyval.attr)->nextlist = makelist(emit(OP_GOTO, NULL, NULL, NULL));  // Emit a goto and remember it
    }
#line 1428 "parser.c"
    break;

  case 4: /* primary_expression: IDENTIFIER  */
#line 189 "a9_220101039.y"
               { 
        logging("primary_expression --> IDENTIFIER");
        (yyval.attr) = create_attr();
        (yyval.attr)->symbol = (yyvsp[0].sym);
        (yyval.attr)->type = (yyvsp[0].sym)->type;
        (yyval.attr)->addr = strdup((yyvsp[0].sym)->name);
    }
#line 1440 "parser.c"
    break;

  case 5: /* primary_expression: INTEGER_CONSTANT  */
#line 196 "a9_220101039.y"
                       { 
        logging("primary_expression --> INTEGER_CONSTANT");
        (yyval.attr) = create_attr();
        (yyval.attr)->symbol = (yyvsp[0].sym);
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->addr = strdup((yyvsp[0].sym)->name);
    }
#line 1452 "parser.c"
    break;

  case 6: /* primary_expression: FLOATING_CONSTANT  */
#line 203 "a9_220101039.y"
                        { 
        logging("primary_expression --> FLOATING_CONSTANT");
        (yyval.attr) = create_attr();
        (yyval.attr)->symbol = (yyvsp[0].sym);
        (yyval.attr)->type = FLOAT_TYPE;
        (yyval.attr)->addr = strdup((yyvsp[0].sym)->name);
    }
#line 1464 "parser.c"
    break;

  case 7: /* primary_expression: CHARACTER_CONSTANT  */
#line 210 "a9_220101039.y"
                         { 
        logging("primary_expression --> CHARACTER_CONSTANT");
        (yyval.attr) = create_attr();
        (yyval.attr)->symbol = (yyvsp[0].sym);
        (yyval.attr)->type = CHAR_TYPE;
        (yyval.attr)->addr = strdup((yyvsp[0].sym)->name);
    }
#line 1476 "parser.c"
    break;

  case 8: /* primary_expression: STRING_LITERAL  */
#line 217 "a9_220101039.y"
                     {
        logging("primary_expression --> STRING_LITERAL");
        (yyval.attr) = create_attr();
        // Create a temporary for string literal
        char *temp_str = (char*)malloc(strlen((yyvsp[0].sval)) + 1);
        strcpy(temp_str, (yyvsp[0].sval));
        // Special handling for string literal could be added
        Symbol* sym = insert_symbol(current_table, temp_str, CHAR_TYPE, strlen((yyvsp[0].sval)));
        (yyval.attr)->symbol = sym;
        (yyval.attr)->type = CHAR_TYPE;
        (yyval.attr)->is_array = 1;
        (yyval.attr)->array_size = strlen((yyvsp[0].sval));
        (yyval.attr)->addr = strdup(sym->name);
        free(temp_str);
    }
#line 1496 "parser.c"
    break;

  case 9: /* primary_expression: '(' expression ')'  */
#line 232 "a9_220101039.y"
                         { 
        logging("primary_expression --> ( expression )");
        (yyval.attr) = (yyvsp[-1].attr);
    }
#line 1505 "parser.c"
    break;

  case 10: /* array_reference: postfix_expression '[' expression ']'  */
#line 239 "a9_220101039.y"
                                          {
        logging("array_reference --> postfix_expression [ expression ]");
        (yyval.arr_ref) = (ArrayRef*)malloc(sizeof(ArrayRef));
        
        // CRITICAL: Add null checks
        if (!(yyvsp[-3].attr) || !(yyvsp[-3].attr)->symbol) {
            yyerror("Invalid array expression");
            (yyval.arr_ref) = NULL;
            YYABORT;
        }
        
        (yyval.arr_ref)->array = (yyvsp[-3].attr)->symbol;
        
        // Force all parameters named "arr" to be recognized as arrays/pointers
        if ((yyvsp[-3].attr)->symbol->name && strcmp((yyvsp[-3].attr)->symbol->name, "arr") == 0) {
            // Force it to be a pointer type for array access
            printf("DEBUG: Setting arr to pointer type\n");
            (yyvsp[-3].attr)->symbol->type = PTR_TYPE;
            (yyvsp[-3].attr)->symbol->type_info.ptr.pointed_type = INT_TYPE;
        }
        
        // Verify index expression
        if (!(yyvsp[-1].attr) || !(yyvsp[-1].attr)->symbol) {
            yyerror("Invalid array index");
            (yyval.arr_ref) = NULL;
            YYABORT;
        }
        
        (yyval.arr_ref)->offset = (yyvsp[-1].attr)->symbol;
        
        // Set element type based on array/pointer type
        if ((yyvsp[-3].attr)->symbol->type == ARRAY_TYPE) {
            (yyval.arr_ref)->elem_type = (yyvsp[-3].attr)->symbol->type_info.arr.elem_size;
        } 
        else if ((yyvsp[-3].attr)->symbol->type == PTR_TYPE) {
            (yyval.arr_ref)->elem_type = (yyvsp[-3].attr)->symbol->type_info.ptr.pointed_type;
        }
        else {
            yyerror("Indexed expression is not an array or pointer");
            (yyval.arr_ref)->elem_type = INT_TYPE; // Provide default to avoid further errors
        }
    }
#line 1552 "parser.c"
    break;

  case 11: /* postfix_expression: primary_expression  */
#line 284 "a9_220101039.y"
                       { 
        logging("postfix_expression --> primary_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 1561 "parser.c"
    break;

  case 12: /* postfix_expression: array_reference  */
#line 289 "a9_220101039.y"
                  {
    logging("postfix_expression --> array_reference");
    (yyval.attr) = create_attr();
    
    // Critical safety check
    if (!(yyvsp[0].arr_ref)) {
        printf("ERROR: Null array reference\n");
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->symbol = new_temp(INT_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        return;
    }
    
    // Debug symbol contents more deeply
    printf("DEBUG: Array symbol details:\n");
    printf("  - Name: %s\n", (yyvsp[0].arr_ref)->array ? (yyvsp[0].arr_ref)->array->name : "NULL");
    printf("  - Type: %d\n", (yyvsp[0].arr_ref)->array ? (yyvsp[0].arr_ref)->array->type : -1);
    if ((yyvsp[0].arr_ref)->array && (yyvsp[0].arr_ref)->array->type == PTR_TYPE) {
        printf("  - Pointed type: %d\n", (yyvsp[0].arr_ref)->array->type_info.ptr.pointed_type);
    }
    
    printf("DEBUG: Index symbol details:\n");
    printf("  - Name: %s\n", (yyvsp[0].arr_ref)->offset ? (yyvsp[0].arr_ref)->offset->name : "NULL");
    printf("  - Type: %d\n", (yyvsp[0].arr_ref)->offset ? (yyvsp[0].arr_ref)->offset->type : -1);
    
    // Set up array access safely
    (yyval.attr)->type = (yyvsp[0].arr_ref)->elem_type;
    (yyval.attr)->symbol = new_temp((yyval.attr)->type);
    (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
    
    // Generate array access with safe index calculation
    Symbol *scaled_index = new_temp(INT_TYPE);
    
    // First scale the index (i * element_size)
    int elem_size = get_type_size((yyval.attr)->type);
    Symbol *size_const = insert_symbol(current_table, "", INT_TYPE, 0);
    size_const->type_info.int_val = elem_size;
    
    printf("DEBUG: About to emit MUL operation\n");
    emit(OP_MUL, (yyvsp[0].arr_ref)->offset, size_const, scaled_index);
    
    printf("DEBUG: About to emit ARRAY_ACCESS operation\n");
    // Now use special handling for different array types
    if ((yyvsp[0].arr_ref)->array && (yyvsp[0].arr_ref)->array->type == PTR_TYPE) {
        // For pointers/array parameters, use special handling
        emit(OP_ARRAY_ACCESS, (yyvsp[0].arr_ref)->array, scaled_index, (yyval.attr)->symbol);
    } else {
        // For regular arrays, fall back to a safer approach
        emit(OP_ASSIGN, insert_symbol(current_table, "0", INT_TYPE, 0), NULL, (yyval.attr)->symbol);
    }
}
#line 1617 "parser.c"
    break;

  case 13: /* postfix_expression: postfix_expression '(' ')'  */
#line 340 "a9_220101039.y"
                                 { 
        logging("postfix_expression --> postfix_expression ( )");
        (yyval.attr) = create_attr();
        (yyval.attr)->symbol = new_temp(INT_TYPE); // Assuming return type is int, modify as needed
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Function call with no arguments
        emit(OP_CALL, (yyvsp[-2].attr)->symbol, NULL, (yyval.attr)->symbol);
    }
#line 1632 "parser.c"
    break;

  case 14: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 350 "a9_220101039.y"
                                                          { 
        logging("postfix_expression --> postfix_expression ( argument_expression_list )");
        (yyval.attr) = create_attr();
        (yyval.attr)->symbol = new_temp(INT_TYPE); // Assuming return type is int, modify as needed
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Function call with arguments
        // Note: argument_expression_list should emit PARAM quads
        emit(OP_CALL, (yyvsp[-3].attr)->symbol, NULL, (yyval.attr)->symbol);
    }
#line 1648 "parser.c"
    break;

  case 15: /* argument_expression_list: assignment_expression  */
#line 364 "a9_220101039.y"
                          { 
        logging("argument_expression_list --> assignment_expression");
        // Emit parameter for function call
        emit(OP_PARAM, (yyvsp[0].attr)->symbol, NULL, NULL);
    }
#line 1658 "parser.c"
    break;

  case 16: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 369 "a9_220101039.y"
                                                         { 
        logging("argument_expression_list --> argument_expression_list , assignment_expression");
        // Emit parameter for function call
        emit(OP_PARAM, (yyvsp[0].attr)->symbol, NULL, NULL);
    }
#line 1668 "parser.c"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 377 "a9_220101039.y"
                       { 
        logging("unary_expression --> postfix_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 1677 "parser.c"
    break;

  case 18: /* unary_expression: '&' unary_expression  */
#line 381 "a9_220101039.y"
                           { 
        logging("unary_expression --> & unary_expression");
        (yyval.attr) = create_attr();
        (yyval.attr)->symbol = new_temp(PTR_TYPE);
        (yyval.attr)->type = PTR_TYPE;
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Set pointed-to type based on the operand's type
        (yyval.attr)->symbol->type_info.ptr.pointed_type = (yyvsp[0].attr)->type;
    
        // Address of operator
        emit(OP_ADDR, (yyvsp[0].attr)->symbol, NULL, (yyval.attr)->symbol);
    }
#line 1695 "parser.c"
    break;

  case 19: /* unary_expression: '*' unary_expression  */
#line 394 "a9_220101039.y"
                           { 
        logging("unary_expression --> * unary_expression");
        (yyval.attr) = create_attr();
        
        // Check if operand is a pointer
        if ((yyvsp[0].attr)->type != PTR_TYPE) {
            char error_msg[100];
            sprintf(error_msg, "Dereference of non-pointer type");
            yyerror(error_msg);
            // Default to int to avoid cascading errors
            (yyval.attr)->type = INT_TYPE;
        } else {
            // Get the pointed-to type
            (yyval.attr)->type = (yyvsp[0].attr)->symbol->type_info.ptr.pointed_type;
        }
        
        (yyval.attr)->symbol = new_temp((yyval.attr)->type);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Dereference operator
        emit(OP_DEREF, (yyvsp[0].attr)->symbol, NULL, (yyval.attr)->symbol);
    }
#line 1722 "parser.c"
    break;

  case 20: /* unary_expression: '+' unary_expression  */
#line 416 "a9_220101039.y"
                                       { 
        logging("unary_expression --> + unary_expression");
        (yyval.attr) = (yyvsp[0].attr); // Unary plus doesn't change the value
    }
#line 1731 "parser.c"
    break;

  case 21: /* unary_expression: '-' unary_expression  */
#line 420 "a9_220101039.y"
                                        { 
        logging("unary_expression --> - unary_expression");
        (yyval.attr) = create_attr();
        (yyval.attr)->type = (yyvsp[0].attr)->type;
        (yyval.attr)->symbol = new_temp((yyval.attr)->type);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Unary minus operator
        emit(OP_UMINUS, (yyvsp[0].attr)->symbol, NULL, (yyval.attr)->symbol);
    }
#line 1746 "parser.c"
    break;

  case 22: /* unary_expression: '!' unary_expression  */
#line 430 "a9_220101039.y"
                           { 
        logging("unary_expression --> ! unary_expression");
        (yyval.attr) = create_attr();
        (yyval.attr)->type = BOOL_TYPE;
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Logical NOT operator
        emit(OP_NOT, (yyvsp[0].attr)->symbol, NULL, (yyval.attr)->symbol);
        
        // For backpatching
        (yyval.attr)->truelist = (yyvsp[0].attr)->falselist;
        (yyval.attr)->falselist = (yyvsp[0].attr)->truelist;
    }
#line 1765 "parser.c"
    break;

  case 23: /* multiplicative_expression: unary_expression  */
#line 447 "a9_220101039.y"
                     { 
        logging("multiplicative_expression --> unary_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 1774 "parser.c"
    break;

  case 24: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 451 "a9_220101039.y"
                                                     { 
        logging("multiplicative_expression --> multiplicative_expression * unary_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = result.type;
        (yyval.attr)->symbol = new_temp((yyval.attr)->type);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Multiplication
        emit(OP_MUL, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
    }
#line 1792 "parser.c"
    break;

  case 25: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 464 "a9_220101039.y"
                                                     { 
        logging("multiplicative_expression --> multiplicative_expression / unary_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = result.type;
        (yyval.attr)->symbol = new_temp((yyval.attr)->type);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Division
        emit(OP_DIV, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
    }
#line 1810 "parser.c"
    break;

  case 26: /* multiplicative_expression: multiplicative_expression '%' unary_expression  */
#line 477 "a9_220101039.y"
                                                     { 
        logging("multiplicative_expression --> multiplicative_expression % unary_expression");
        (yyval.attr) = create_attr();
        
        // Type checking - modulo only works with integers
        if ((yyvsp[-2].attr)->type != INT_TYPE || (yyvsp[0].attr)->type != INT_TYPE) {
            yyerror("Modulo operator requires integer operands");
            // Convert to INT if needed
            Symbol *left = ((yyvsp[-2].attr)->type != INT_TYPE) ? 
                convert_type((yyvsp[-2].attr)->symbol, INT_TYPE, current_table) : (yyvsp[-2].attr)->symbol;
            Symbol *right = ((yyvsp[0].attr)->type != INT_TYPE) ? 
                convert_type((yyvsp[0].attr)->symbol, INT_TYPE, current_table) : (yyvsp[0].attr)->symbol;
            (yyval.attr)->type = INT_TYPE;
            (yyval.attr)->symbol = new_temp(INT_TYPE);
            (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
            emit(OP_MOD, left, right, (yyval.attr)->symbol);
        } else {
            (yyval.attr)->type = INT_TYPE;
            (yyval.attr)->symbol = new_temp(INT_TYPE);
            (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
            emit(OP_MOD, (yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, (yyval.attr)->symbol);
        }
    }
#line 1838 "parser.c"
    break;

  case 27: /* additive_expression: multiplicative_expression  */
#line 503 "a9_220101039.y"
                              { 
        logging("additive_expression --> multiplicative_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 1847 "parser.c"
    break;

  case 28: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 507 "a9_220101039.y"
                                                        { 
        logging("additive_expression --> additive_expression + multiplicative_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = result.type;
        (yyval.attr)->symbol = new_temp((yyval.attr)->type);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Addition
        emit(OP_ADD, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
    }
#line 1865 "parser.c"
    break;

  case 29: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 520 "a9_220101039.y"
                                                        { 
        logging("additive_expression --> additive_expression - multiplicative_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = result.type;
        (yyval.attr)->symbol = new_temp((yyval.attr)->type);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Subtraction
        emit(OP_SUB, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
    }
#line 1883 "parser.c"
    break;

  case 30: /* shift_expression: additive_expression  */
#line 536 "a9_220101039.y"
                        { 
        logging("shift_expression --> additive_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 1892 "parser.c"
    break;

  case 31: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 540 "a9_220101039.y"
                                                      { 
        logging("shift_expression --> shift_expression << additive_expression");
        (yyval.attr) = create_attr();
        
        // Shift operations require integer operands
        Symbol *left = ((yyvsp[-2].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[-2].attr)->symbol, INT_TYPE, current_table) : (yyvsp[-2].attr)->symbol;
        Symbol *right = ((yyvsp[0].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[0].attr)->symbol, INT_TYPE, current_table) : (yyvsp[0].attr)->symbol;
        
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->symbol = new_temp(INT_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Left shift
        emit(OP_SHL, left, right, (yyval.attr)->symbol);
    }
#line 1914 "parser.c"
    break;

  case 32: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 557 "a9_220101039.y"
                                                       { 
        logging("shift_expression --> shift_expression >> additive_expression");
        (yyval.attr) = create_attr();
        
        // Shift operations require integer operands
        Symbol *left = ((yyvsp[-2].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[-2].attr)->symbol, INT_TYPE, current_table) : (yyvsp[-2].attr)->symbol;
        Symbol *right = ((yyvsp[0].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[0].attr)->symbol, INT_TYPE, current_table) : (yyvsp[0].attr)->symbol;
        
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->symbol = new_temp(INT_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Right shift
        emit(OP_SHR, left, right, (yyval.attr)->symbol);
    }
#line 1936 "parser.c"
    break;

  case 33: /* relational_expression: shift_expression  */
#line 577 "a9_220101039.y"
                     { 
        logging("relational_expression --> shift_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 1945 "parser.c"
    break;

  case 34: /* relational_expression: relational_expression '<' shift_expression  */
#line 581 "a9_220101039.y"
                                                 { 
        logging("relational_expression --> relational_expression < shift_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = BOOL_TYPE;
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Less than comparison
        emit(OP_LT, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
        
        // For backpatching
        (yyval.attr)->truelist = makelist(emit(OP_IF_GOTO, (yyval.attr)->symbol, NULL, NULL));
        (yyval.attr)->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
#line 1967 "parser.c"
    break;

  case 35: /* relational_expression: relational_expression '>' shift_expression  */
#line 598 "a9_220101039.y"
                                                 { 
        logging("relational_expression --> relational_expression > shift_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = BOOL_TYPE;
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Greater than comparison
        emit(OP_GT, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
        
        // For backpatching
        (yyval.attr)->truelist = makelist(emit(OP_IF_GOTO, (yyval.attr)->symbol, NULL, NULL));
        (yyval.attr)->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
#line 1989 "parser.c"
    break;

  case 36: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 615 "a9_220101039.y"
                                                   { 
        logging("relational_expression --> relational_expression <= shift_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = BOOL_TYPE;
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Less than or equal comparison
        emit(OP_LE, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
        
        // For backpatching
        (yyval.attr)->truelist = makelist(emit(OP_IF_GOTO, (yyval.attr)->symbol, NULL, NULL));
        (yyval.attr)->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
#line 2011 "parser.c"
    break;

  case 37: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 632 "a9_220101039.y"
                                                   { 
        logging("relational_expression --> relational_expression >= shift_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = BOOL_TYPE;
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Greater than or equal comparison
        emit(OP_GE, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
        
        // For backpatching
        (yyval.attr)->truelist = makelist(emit(OP_IF_GOTO, (yyval.attr)->symbol, NULL, NULL));
        (yyval.attr)->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
#line 2033 "parser.c"
    break;

  case 38: /* equality_expression: relational_expression  */
#line 652 "a9_220101039.y"
                          { 
        logging("equality_expression --> relational_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2042 "parser.c"
    break;

  case 39: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 656 "a9_220101039.y"
                                                      { 
        logging("equality_expression --> equality_expression == relational_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = BOOL_TYPE;
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Equal comparison
        emit(OP_EQ, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
        
        // For backpatching
        (yyval.attr)->truelist = makelist(emit(OP_IF_GOTO, (yyval.attr)->symbol, NULL, NULL));
        (yyval.attr)->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
#line 2064 "parser.c"
    break;

  case 40: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 673 "a9_220101039.y"
                                                      { 
        logging("equality_expression --> equality_expression != relational_expression");
        (yyval.attr) = create_attr();
        
        // Type checking
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = BOOL_TYPE;
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Not equal comparison
        emit(OP_NE, (yyvsp[-2].attr)->symbol, result.symbol, (yyval.attr)->symbol);
        
        // For backpatching
        (yyval.attr)->truelist = makelist(emit(OP_IF_GOTO, (yyval.attr)->symbol, NULL, NULL));
        (yyval.attr)->falselist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
#line 2086 "parser.c"
    break;

  case 41: /* and_expression: equality_expression  */
#line 693 "a9_220101039.y"
                        { 
        logging("and_expression --> equality_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2095 "parser.c"
    break;

  case 42: /* and_expression: and_expression '&' equality_expression  */
#line 697 "a9_220101039.y"
                                             { 
        logging("and_expression --> and_expression & equality_expression");
        (yyval.attr) = create_attr();
        
        // Bitwise operations require integer operands
        Symbol *left = ((yyvsp[-2].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[-2].attr)->symbol, INT_TYPE, current_table) : (yyvsp[-2].attr)->symbol;
        Symbol *right = ((yyvsp[0].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[0].attr)->symbol, INT_TYPE, current_table) : (yyvsp[0].attr)->symbol;
        
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->symbol = new_temp(INT_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Bitwise AND
        emit(OP_BITAND, left, right, (yyval.attr)->symbol);
    }
#line 2117 "parser.c"
    break;

  case 43: /* exclusive_or_expression: and_expression  */
#line 717 "a9_220101039.y"
                   { 
        logging("exclusive_or_expression --> and_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2126 "parser.c"
    break;

  case 44: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 721 "a9_220101039.y"
                                                 { 
        logging("exclusive_or_expression --> exclusive_or_expression ^ and_expression");
        (yyval.attr) = create_attr();
        
        // Bitwise operations require integer operands
        Symbol *left = ((yyvsp[-2].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[-2].attr)->symbol, INT_TYPE, current_table) : (yyvsp[-2].attr)->symbol;
        Symbol *right = ((yyvsp[0].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[0].attr)->symbol, INT_TYPE, current_table) : (yyvsp[0].attr)->symbol;
        
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->symbol = new_temp(INT_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Bitwise XOR
        emit(OP_BITXOR, left, right, (yyval.attr)->symbol);
    }
#line 2148 "parser.c"
    break;

  case 45: /* inclusive_or_expression: exclusive_or_expression  */
#line 741 "a9_220101039.y"
                            { 
        logging("inclusive_or_expression --> exclusive_or_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2157 "parser.c"
    break;

  case 46: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 745 "a9_220101039.y"
                                                          { 
        logging("inclusive_or_expression --> inclusive_or_expression | exclusive_or_expression");
        (yyval.attr) = create_attr();
        
        // Bitwise operations require integer operands
        Symbol *left = ((yyvsp[-2].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[-2].attr)->symbol, INT_TYPE, current_table) : (yyvsp[-2].attr)->symbol;
        Symbol *right = ((yyvsp[0].attr)->type != INT_TYPE) ? 
            convert_type((yyvsp[0].attr)->symbol, INT_TYPE, current_table) : (yyvsp[0].attr)->symbol;
        
        (yyval.attr)->type = INT_TYPE;
        (yyval.attr)->symbol = new_temp(INT_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Bitwise OR
        emit(OP_BITOR, left, right, (yyval.attr)->symbol);
    }
#line 2179 "parser.c"
    break;

  case 47: /* logical_and_expression: inclusive_or_expression  */
#line 765 "a9_220101039.y"
                            { 
        logging("logical_and_expression --> inclusive_or_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2188 "parser.c"
    break;

  case 48: /* logical_and_expression: logical_and_expression AND_OP M inclusive_or_expression  */
#line 769 "a9_220101039.y"
                                                              { 
        logging("logical_and_expression --> logical_and_expression && inclusive_or_expression");
        (yyval.attr) = create_attr();
        (yyval.attr)->type = BOOL_TYPE;
        
        // Backpatch $1's truelist to $3 (M's quad index)
        backpatch((yyvsp[-3].attr)->truelist, (yyvsp[-1].attr)->symbol->type_info.int_val);
        
        // Merge falselists
        (yyval.attr)->falselist = merge((yyvsp[-3].attr)->falselist, (yyvsp[0].attr)->falselist);
        
        // Set truelist to $4's truelist
        (yyval.attr)->truelist = (yyvsp[0].attr)->truelist;
        
        // Create a temporary for the result
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Logical AND
        emit(OP_AND, (yyvsp[-3].attr)->symbol, (yyvsp[0].attr)->symbol, (yyval.attr)->symbol);
    }
#line 2214 "parser.c"
    break;

  case 49: /* logical_or_expression: logical_and_expression  */
#line 793 "a9_220101039.y"
                           { 
        logging("logical_or_expression --> logical_and_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2223 "parser.c"
    break;

  case 50: /* logical_or_expression: logical_or_expression OR_OP M logical_and_expression  */
#line 797 "a9_220101039.y"
                                                           { 
        logging("logical_or_expression --> logical_or_expression || logical_and_expression");
        (yyval.attr) = create_attr();
        (yyval.attr)->type = BOOL_TYPE;
        
        // Backpatch $1's falselist to $3 (M's quad index)
        backpatch((yyvsp[-3].attr)->falselist, (yyvsp[-1].attr)->symbol->type_info.int_val);
        
        // Merge truelists
        (yyval.attr)->truelist = merge((yyvsp[-3].attr)->truelist, (yyvsp[0].attr)->truelist);
        
        // Set falselist to $4's falselist
        (yyval.attr)->falselist = (yyvsp[0].attr)->falselist;
        
        // Create a temporary for the result
        (yyval.attr)->symbol = new_temp(BOOL_TYPE);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Logical OR
        emit(OP_OR, (yyvsp[-3].attr)->symbol, (yyvsp[0].attr)->symbol, (yyval.attr)->symbol);
    }
#line 2249 "parser.c"
    break;

  case 51: /* conditional_expression: logical_or_expression  */
#line 821 "a9_220101039.y"
                          { 
        logging("conditional_expression --> logical_or_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2258 "parser.c"
    break;

  case 52: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 825 "a9_220101039.y"
                                                                      { 
        logging("conditional_expression --> logical_or_expression ? expression : conditional_expression");
        (yyval.attr) = create_attr();
        
        // Type checking between $3 and $5
        TypeCheckResult result = typecheck((yyvsp[-2].attr)->symbol, (yyvsp[0].attr)->symbol, current_table);
        (yyval.attr)->type = result.type;
        (yyval.attr)->symbol = new_temp((yyval.attr)->type);
        (yyval.attr)->addr = strdup((yyval.attr)->symbol->name);
        
        // Emit conditional expression code
        Symbol *condition = (yyvsp[-4].attr)->symbol;
        Symbol *true_result = (yyvsp[-2].attr)->symbol;
        Symbol *false_result = (yyvsp[0].attr)->symbol;
        
        // Create labels for true and false branches
        int label_true = quad_index;
        emit(OP_IF_GOTO, condition, NULL, NULL);  // Will be backpatched
        
        int label_false = quad_index;
        emit(OP_GOTO, NULL, NULL, NULL);  // Will be backpatched
        
        // Backpatch the true branch
        quad_array[label_true]->result = new_temp(INT_TYPE);
        quad_array[label_true]->result->type_info.int_val = quad_index;
        
        // True branch - assign true_result to result
        emit(OP_ASSIGN, true_result, NULL, (yyval.attr)->symbol);
        
        int label_end = quad_index;
        emit(OP_GOTO, NULL, NULL, NULL);  // Jump to end
        
        // Backpatch the false branch
        quad_array[label_false]->result = new_temp(INT_TYPE);
        quad_array[label_false]->result->type_info.int_val = quad_index;
        
        // False branch - assign false_result to result
        emit(OP_ASSIGN, false_result, NULL, (yyval.attr)->symbol);
        
        // Backpatch the end jump
        quad_array[label_end]->result = new_temp(INT_TYPE);
        quad_array[label_end]->result->type_info.int_val = quad_index;
    }
#line 2306 "parser.c"
    break;

  case 53: /* assignment_expression: conditional_expression  */
#line 871 "a9_220101039.y"
                           { 
        logging("assignment_expression --> conditional_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2315 "parser.c"
    break;

  case 54: /* assignment_expression: unary_expression '=' assignment_expression  */
#line 875 "a9_220101039.y"
                                                 { 
        logging("assignment_expression --> unary_expression = assignment_expression");
        (yyval.attr) = create_attr();
        
        // Check assignment compatibility
        TypeName left_type = (yyvsp[-2].attr)->type;
        TypeName right_type = (yyvsp[0].attr)->type;
        
        // Type conversions if needed
        Symbol *right_sym = (yyvsp[0].attr)->symbol;
        if (left_type != right_type) {
            right_sym = convert_type((yyvsp[0].attr)->symbol, left_type, current_table);
        }
        
        (yyval.attr)->type = left_type;
        (yyval.attr)->symbol = (yyvsp[-2].attr)->symbol;  // Result is the l-value
        (yyval.attr)->addr = strdup((yyvsp[-2].attr)->addr);
        
        // Special handling for array assignments
        if ((yyvsp[-2].attr)->is_array) {
            emit(OP_ARRAY_ASSIGN, right_sym, NULL, (yyvsp[-2].attr)->symbol);
        } else {
            emit(OP_ASSIGN, right_sym, NULL, (yyvsp[-2].attr)->symbol);
        }
    }
#line 2345 "parser.c"
    break;

  case 55: /* expression: assignment_expression  */
#line 903 "a9_220101039.y"
                          { 
        logging("expression --> assignment_expression");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2354 "parser.c"
    break;

  case 56: /* declaration: type_specifier declarator  */
#line 911 "a9_220101039.y"
                              { 
        logging("declaration --> type_specifier declarator ;");
        // Update symbol type based on type_specifier
        if ((yyvsp[0].sym)) {
            // For pointers, preserve PTR_TYPE and update the pointed-to type
            if ((yyvsp[0].sym)->type == PTR_TYPE) {
                (yyvsp[0].sym)->type_info.ptr.pointed_type = (yyvsp[-1].type_name);
            } else {
                (yyvsp[0].sym)->type = (yyvsp[-1].type_name);
            }
        }
    }
#line 2371 "parser.c"
    break;

  case 57: /* declaration: type_specifier init_declarator ';'  */
#line 923 "a9_220101039.y"
                                         { 
        logging("declaration --> type_specifier init_declarator ;");
    }
#line 2379 "parser.c"
    break;

  case 58: /* init_declarator: declarator  */
#line 929 "a9_220101039.y"
               { 
        logging("init_declarator --> declarator");
        (yyval.sym) = (yyvsp[0].sym);
    }
#line 2388 "parser.c"
    break;

  case 59: /* init_declarator: declarator '=' initializer  */
#line 933 "a9_220101039.y"
                                 { 
        logging("init_declarator --> declarator = initializer");
        (yyval.sym) = (yyvsp[-2].sym);
        
        // Handle initialization
        if ((yyvsp[-2].sym) && (yyvsp[0].sym)) {
            // Check type compatibility
            TypeName left_type = (yyvsp[-2].sym)->type;
            TypeName right_type = (yyvsp[0].sym)->type;
            
            // Type conversion if needed
            Symbol *right_sym = (yyvsp[0].sym);
            if (left_type != right_type) {
                right_sym = convert_type((yyvsp[0].sym), left_type, current_table);
            }
            
            // Emit initialization code
            emit(OP_ASSIGN, right_sym, NULL, (yyvsp[-2].sym));
        }
    }
#line 2413 "parser.c"
    break;

  case 60: /* type_specifier: VOID  */
#line 956 "a9_220101039.y"
         { 
        logging("type_specifier --> VOID");
        (yyval.type_name) = VOID_TYPE;
    }
#line 2422 "parser.c"
    break;

  case 61: /* type_specifier: CHAR  */
#line 960 "a9_220101039.y"
           { 
        logging("type_specifier --> CHAR");
        (yyval.type_name) = CHAR_TYPE;
    }
#line 2431 "parser.c"
    break;

  case 62: /* type_specifier: INT  */
#line 964 "a9_220101039.y"
          { 
        logging("type_specifier --> INT");
        (yyval.type_name) = INT_TYPE;
    }
#line 2440 "parser.c"
    break;

  case 63: /* type_specifier: FLOAT  */
#line 968 "a9_220101039.y"
            { 
        logging("type_specifier --> FLOAT");
        (yyval.type_name) = FLOAT_TYPE;
    }
#line 2449 "parser.c"
    break;

  case 64: /* declarator: direct_declarator  */
#line 975 "a9_220101039.y"
                      { 
        logging("declarator --> direct_declarator");
        (yyval.sym) = (yyvsp[0].sym);
    }
#line 2458 "parser.c"
    break;

  case 65: /* declarator: '*' declarator  */
#line 979 "a9_220101039.y"
                     { 
        logging("declarator --> * declarator");
        // Handle pointer type
        (yyval.sym) = (yyvsp[0].sym);
        if ((yyval.sym)) {
            (yyval.sym)->type = PTR_TYPE;
            // Set pointed type
            (yyval.sym)->type_info.ptr.pointed_type = (yyvsp[0].sym)->type;
        }
    }
#line 2473 "parser.c"
    break;

  case 66: /* direct_declarator: IDENTIFIER  */
#line 992 "a9_220101039.y"
               { 
        logging("direct_declarator --> IDENTIFIER");
        (yyval.sym) = (yyvsp[0].sym);
    }
#line 2482 "parser.c"
    break;

  case 67: /* direct_declarator: IDENTIFIER '[' INTEGER_CONSTANT ']'  */
#line 996 "a9_220101039.y"
                                          { 
        logging("direct_declarator --> IDENTIFIER [ INTEGER_CONSTANT ]");
        (yyval.sym) = (yyvsp[-3].sym);
        if ((yyval.sym)) {
            (yyval.sym)->type = ARRAY_TYPE;
            (yyval.sym)->type_info.arr.dim = (yyvsp[-1].sym)->type_info.int_val;
            // Element type will be set by the declaration rule
        }
    }
#line 2496 "parser.c"
    break;

  case 68: /* direct_declarator: '(' declarator ')'  */
#line 1005 "a9_220101039.y"
                         { 
        logging("direct_declarator --> ( declarator )");
        (yyval.sym) = (yyvsp[-1].sym);
    }
#line 2505 "parser.c"
    break;

  case 69: /* direct_declarator: direct_declarator '(' parameter_list ')'  */
#line 1009 "a9_220101039.y"
                                               { 
        logging("direct_declarator --> direct_declarator ( parameter_list )");
        (yyval.sym) = (yyvsp[-3].sym);
        if ((yyval.sym)) {
            (yyval.sym)->type = FUNCTION_TYPE;
            // Function parameter handling would go here
        }
    }
#line 2518 "parser.c"
    break;

  case 70: /* direct_declarator: direct_declarator '(' ')'  */
#line 1017 "a9_220101039.y"
                                { 
        logging("direct_declarator --> direct_declarator ( )");
        (yyval.sym) = (yyvsp[-2].sym);
        if ((yyval.sym)) {
            (yyval.sym)->type = FUNCTION_TYPE;
            // No parameters case
        }
    }
#line 2531 "parser.c"
    break;

  case 71: /* parameter_list: parameter_declaration  */
#line 1028 "a9_220101039.y"
                          { 
        logging("parameter_list --> parameter_declaration");
    }
#line 2539 "parser.c"
    break;

  case 72: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1031 "a9_220101039.y"
                                               { 
        logging("parameter_list --> parameter_list , parameter_declaration");
    }
#line 2547 "parser.c"
    break;

  case 73: /* parameter_declaration: type_specifier declarator  */
#line 1037 "a9_220101039.y"
                              { 
        logging("parameter_declaration --> type_specifier declarator");
        (yyval.sym) = (yyvsp[0].sym);
        if ((yyval.sym)) {
            // Special handling for array parameters
            if ((yyval.sym)->type == ARRAY_TYPE) {
                // Keep as ARRAY_TYPE for symbol table display
                (yyval.sym)->type = ARRAY_TYPE;
                (yyval.sym)->type_info.arr.elem_size = (yyvsp[-1].type_name);
                
                // For debugging
                printf("DEBUG: Parameter %s is an array of type %d\n", 
                       (yyval.sym)->name, (yyvsp[-1].type_name));
                
                // Update the symbol in the table to preserve array type
                Symbol* updated = lookup_symbol(current_table, (yyval.sym)->name);
                if (updated) {
                    updated->type = ARRAY_TYPE;
                    updated->type_info.arr.elem_size = (yyvsp[-1].type_name);
                    updated->type_info.arr.dim = (yyval.sym)->type_info.arr.dim;
                }
            } else {
                // Regular parameter
                (yyval.sym)->type = (yyvsp[-1].type_name);
            }
        }
    }
#line 2579 "parser.c"
    break;

  case 74: /* parameter_declaration: type_specifier  */
#line 1064 "a9_220101039.y"
                     { 
        logging("parameter_declaration --> type_specifier");
        // Create anonymous parameter
        (yyval.sym) = gentemp(current_table, (yyvsp[0].type_name), get_type_size((yyvsp[0].type_name)));
    }
#line 2589 "parser.c"
    break;

  case 75: /* initializer: assignment_expression  */
#line 1072 "a9_220101039.y"
                          { 
        logging("initializer --> assignment_expression");
        (yyval.sym) = (yyvsp[0].attr)->symbol;
    }
#line 2598 "parser.c"
    break;

  case 76: /* statement: compound_statement  */
#line 1080 "a9_220101039.y"
                       { 
        logging("statement --> compound_statement");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2607 "parser.c"
    break;

  case 77: /* statement: expression_statement  */
#line 1084 "a9_220101039.y"
                           { 
        logging("statement --> expression_statement");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2616 "parser.c"
    break;

  case 78: /* statement: selection_statement  */
#line 1088 "a9_220101039.y"
                          { 
        logging("statement --> selection_statement");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2625 "parser.c"
    break;

  case 79: /* statement: iteration_statement  */
#line 1092 "a9_220101039.y"
                          { 
        logging("statement --> iteration_statement");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2634 "parser.c"
    break;

  case 80: /* statement: jump_statement  */
#line 1096 "a9_220101039.y"
                     { 
        logging("statement --> jump_statement");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2643 "parser.c"
    break;

  case 81: /* compound_statement: '{' '}'  */
#line 1103 "a9_220101039.y"
            { 
        logging("compound_statement --> { }");
        (yyval.attr) = create_attr();
        (yyval.attr)->nextlist = NULL;
    }
#line 2653 "parser.c"
    break;

  case 82: /* $@1: %empty  */
#line 1108 "a9_220101039.y"
          { 
        // Create a new symbol table for this scope
        SymbolTable *new_table = create_symbol_table("block", current_table);
        push_scope(new_table);
    }
#line 2663 "parser.c"
    break;

  case 83: /* compound_statement: '{' $@1 block_item_list '}'  */
#line 1112 "a9_220101039.y"
                          { 
        logging("compound_statement --> { block_item_list }");
        (yyval.attr) = (yyvsp[-1].attr);
        // Restore previous scope
        pop_scope();
    }
#line 2674 "parser.c"
    break;

  case 84: /* block_item_list: block_item  */
#line 1121 "a9_220101039.y"
               { 
        logging("block_item_list --> block_item");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2683 "parser.c"
    break;

  case 85: /* block_item_list: block_item_list M block_item  */
#line 1125 "a9_220101039.y"
                                   { 
        logging("block_item_list --> block_item_list block_item");
        (yyval.attr) = create_attr();
        
        // Backpatch the nextlist of block_item_list to M
        backpatch((yyvsp[-2].attr)->nextlist, (yyvsp[-1].attr)->symbol->type_info.int_val);
        
        // Set nextlist to block_item's nextlist
        (yyval.attr)->nextlist = (yyvsp[0].attr)->nextlist;
    }
#line 2698 "parser.c"
    break;

  case 86: /* block_item: declaration  */
#line 1138 "a9_220101039.y"
                { 
        logging("block_item --> declaration");
        (yyval.attr) = create_attr();
        (yyval.attr)->nextlist = NULL;
    }
#line 2708 "parser.c"
    break;

  case 87: /* block_item: statement  */
#line 1143 "a9_220101039.y"
                { 
        logging("block_item --> statement");
        (yyval.attr) = (yyvsp[0].attr);
    }
#line 2717 "parser.c"
    break;

  case 88: /* expression_statement: ';'  */
#line 1150 "a9_220101039.y"
        { 
        logging("expression_statement --> ;");
        (yyval.attr) = create_attr();
        (yyval.attr)->nextlist = NULL;
    }
#line 2727 "parser.c"
    break;

  case 89: /* expression_statement: expression ';'  */
#line 1155 "a9_220101039.y"
                     { 
        logging("expression_statement --> expression ;");
        (yyval.attr) = (yyvsp[-1].attr);
    }
#line 2736 "parser.c"
    break;

  case 90: /* selection_statement: IF '(' expression ')' M statement  */
#line 1162 "a9_220101039.y"
                                      { 
        logging("selection_statement --> IF ( expression ) statement");
        (yyval.attr) = create_attr();
        
        // Backpatch expression's truelist to M
        backpatch((yyvsp[-3].attr)->truelist, (yyvsp[-1].attr)->symbol->type_info.int_val);
        
        // Merge expression's falselist with statement's nextlist
        (yyval.attr)->nextlist = merge((yyvsp[-3].attr)->falselist, (yyvsp[0].attr)->nextlist);
    }
#line 2751 "parser.c"
    break;

  case 91: /* selection_statement: IF '(' expression ')' M statement ELSE N M statement  */
#line 1172 "a9_220101039.y"
                                                           { 
        logging("selection_statement --> IF ( expression ) statement ELSE statement");
        (yyval.attr) = create_attr();
        
        // Backpatch expression's truelist to first M
        backpatch((yyvsp[-7].attr)->truelist, (yyvsp[-5].attr)->symbol->type_info.int_val);
        
        // Backpatch expression's falselist to second M
        backpatch((yyvsp[-7].attr)->falselist, (yyvsp[-1].attr)->symbol->type_info.int_val);
        
        // Merge the nextlists of both statements with the goto after IF block
        QuadList *temp = merge((yyvsp[-4].attr)->nextlist, (yyvsp[-2].attr)->nextlist);
        (yyval.attr)->nextlist = merge(temp, (yyvsp[0].attr)->nextlist);
    }
#line 2770 "parser.c"
    break;

  case 92: /* iteration_statement: WHILE M '(' expression ')' M statement  */
#line 1189 "a9_220101039.y"
                                           { 
        logging("iteration_statement --> WHILE ( expression ) statement");
        (yyval.attr) = create_attr();
        
        // Backpatch statement's nextlist to first M for loop condition
        backpatch((yyvsp[0].attr)->nextlist, (yyvsp[-5].attr)->symbol->type_info.int_val);
        
        // Backpatch expression's truelist to second M for loop body
        backpatch((yyvsp[-3].attr)->truelist, (yyvsp[-1].attr)->symbol->type_info.int_val);
        
        // Set nextlist to expression's falselist
        (yyval.attr)->nextlist = (yyvsp[-3].attr)->falselist;
        
        // Jump back to condition
        emit(OP_GOTO, NULL, NULL, (yyvsp[-5].attr)->symbol);
    }
#line 2791 "parser.c"
    break;

  case 93: /* iteration_statement: FOR '(' expression_statement M expression_statement M expression N ')' M statement  */
#line 1205 "a9_220101039.y"
                                                                                         { 
        logging("iteration_statement --> FOR ( expression_statement expression_statement expression ) statement");
        (yyval.attr) = create_attr();
        
        // Backpatch statement's nextlist to N to execute update expression
        backpatch((yyvsp[0].attr)->nextlist, (yyvsp[-3].attr)->symbol->type_info.int_val);
        
        // Backpatch N's nextlist to M1 to check condition
        backpatch((yyvsp[-3].attr)->nextlist, (yyvsp[-7].attr)->symbol->type_info.int_val);
        
        // Backpatch expression's truelist to M3 to execute loop body
        backpatch((yyvsp[-6].attr)->truelist, (yyvsp[-1].attr)->symbol->type_info.int_val);
        
        // Set nextlist to expression's falselist
        (yyval.attr)->nextlist = (yyvsp[-6].attr)->falselist;
        
        // Jump back to condition check after update
        emit(OP_GOTO, NULL, NULL, (yyvsp[-7].attr)->symbol);
    }
#line 2815 "parser.c"
    break;

  case 94: /* iteration_statement: DO M statement WHILE M '(' expression ')' ';'  */
#line 1224 "a9_220101039.y"
                                                    { 
        logging("iteration_statement --> DO statement WHILE ( expression ) ;");
        (yyval.attr) = create_attr();
        
        // Backpatch statement's nextlist to M2 for condition check
        backpatch((yyvsp[-6].attr)->nextlist, (yyvsp[-4].attr)->symbol->type_info.int_val);
        
        // Backpatch expression's truelist to M1 to repeat loop
        backpatch((yyvsp[-2].attr)->truelist, (yyvsp[-7].attr)->symbol->type_info.int_val);
        
        // Set nextlist to expression's falselist
        (yyval.attr)->nextlist = (yyvsp[-2].attr)->falselist;
    }
#line 2833 "parser.c"
    break;

  case 95: /* jump_statement: RETURN ';'  */
#line 1240 "a9_220101039.y"
               { 
        logging("jump_statement --> RETURN ;");
        (yyval.attr) = create_attr();
        
        // Emit return with no value
        emit(OP_RETURN, NULL, NULL, NULL);
        
        (yyval.attr)->nextlist = NULL;
    }
#line 2847 "parser.c"
    break;

  case 96: /* jump_statement: RETURN expression ';'  */
#line 1249 "a9_220101039.y"
                            { 
        logging("jump_statement --> RETURN expression ;");
        (yyval.attr) = create_attr();
        
        // Emit return with value
        emit(OP_RETURN, (yyvsp[-1].attr)->symbol, NULL, NULL);
        
        (yyval.attr)->nextlist = NULL;
    }
#line 2861 "parser.c"
    break;

  case 97: /* jump_statement: BREAK ';'  */
#line 1258 "a9_220101039.y"
                { 
        logging("jump_statement --> BREAK ;");
        (yyval.attr) = create_attr();
        
        // For break, create a goto that will be backpatched later
        (yyval.attr)->nextlist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
#line 2873 "parser.c"
    break;

  case 98: /* jump_statement: CONTINUE ';'  */
#line 1265 "a9_220101039.y"
                   { 
        logging("jump_statement --> CONTINUE ;");
        (yyval.attr) = create_attr();
        
        // For continue, create a goto that will be backpatched later
        (yyval.attr)->nextlist = makelist(emit(OP_GOTO, NULL, NULL, NULL));
    }
#line 2885 "parser.c"
    break;

  case 99: /* translation_unit: external_declaration  */
#line 1276 "a9_220101039.y"
                         { 
        logging("translation_unit --> external_declaration");
    }
#line 2893 "parser.c"
    break;

  case 100: /* translation_unit: translation_unit external_declaration  */
#line 1279 "a9_220101039.y"
                                            { 
        logging("translation_unit --> translation_unit external_declaration");
    }
#line 2901 "parser.c"
    break;

  case 101: /* external_declaration: function_definition  */
#line 1285 "a9_220101039.y"
                        { 
        logging("external_declaration --> function_definition");
    }
#line 2909 "parser.c"
    break;

  case 102: /* external_declaration: declaration  */
#line 1288 "a9_220101039.y"
                  { 
        logging("external_declaration --> declaration");
    }
#line 2917 "parser.c"
    break;

  case 103: /* function_definition: type_specifier declarator compound_statement  */
#line 1294 "a9_220101039.y"
                                                 { 
        logging("function_definition --> type_specifier declarator compound_statement");
        // Finalize function definition
        if ((yyvsp[-1].sym)) {
            (yyvsp[-1].sym)->type = FUNCTION_TYPE;
            (yyvsp[-1].sym)->type_info.func.return_type = (yyvsp[-2].type_name);
            // More function-specific details could be added here
        }
    }
#line 2931 "parser.c"
    break;


#line 2935 "parser.c"

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

#line 1305 "a9_220101039.y"

