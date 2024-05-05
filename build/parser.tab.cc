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
#line 34 "src/files/frontend/parser.y"

#include "parser.tab.hh"

  extern int yylex(void);
  void yyerror(const char *s);
  void save_to_dot(FILE *);
  int trav_and_write(FILE *, node *);

  std::vector<std::string> varNames;
  bool isPrint = false;

  AST ast("TestMod");

  auto main_func = ast.AddFunction("main", std::make_unique<VarTypeSimple>(VarTypeSimple::VoidType), ASTFunctionParameters()); 
  
  // hard define print function

#line 89 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"

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

#include "parser.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NAME = 3,                       /* NAME  */
  YYSYMBOL_NEWLINE = 4,                    /* NEWLINE  */
  YYSYMBOL_INDENT = 5,                     /* INDENT  */
  YYSYMBOL_DEDENT = 6,                     /* DEDENT  */
  YYSYMBOL_COLON = 7,                      /* COLON  */
  YYSYMBOL_PRINT = 8,                      /* PRINT  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_ID = 10,                        /* ID  */
  YYSYMBOL_BOOL_TYPE = 11,                 /* BOOL_TYPE  */
  YYSYMBOL_INT_TYPE = 12,                  /* INT_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 13,                /* FLOAT_TYPE  */
  YYSYMBOL_STRING_TYPE = 14,               /* STRING_TYPE  */
  YYSYMBOL_VOID_TYPE = 15,                 /* VOID_TYPE  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 17,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 18,                    /* RPAREN  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELIF = 23,                      /* ELIF  */
  YYSYMBOL_ASSIGNMENT = 24,                /* ASSIGNMENT  */
  YYSYMBOL_TAB = 25,                       /* TAB  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_EQUALS_SIGN = 30,               /* EQUALS_SIGN  */
  YYSYMBOL_LOGICAL_OR = 31,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 32,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_NOT = 33,               /* LOGICAL_NOT  */
  YYSYMBOL_RELOP_GT = 34,                  /* RELOP_GT  */
  YYSYMBOL_RELOP_LT = 35,                  /* RELOP_LT  */
  YYSYMBOL_RELOP_GE = 36,                  /* RELOP_GE  */
  YYSYMBOL_RELOP_LE = 37,                  /* RELOP_LE  */
  YYSYMBOL_RELOP_EQ = 38,                  /* RELOP_EQ  */
  YYSYMBOL_RELOP_NE = 39,                  /* RELOP_NE  */
  YYSYMBOL_ARITH_PLUS = 40,                /* ARITH_PLUS  */
  YYSYMBOL_ARITH_MINUS = 41,               /* ARITH_MINUS  */
  YYSYMBOL_ARITH_MULT = 42,                /* ARITH_MULT  */
  YYSYMBOL_ARITH_DIV = 43,                 /* ARITH_DIV  */
  YYSYMBOL_ARITH_MOD = 44,                 /* ARITH_MOD  */
  YYSYMBOL_VARIADIC = 45,                  /* VARIADIC  */
  YYSYMBOL_BOOL_LITERAL = 46,              /* BOOL_LITERAL  */
  YYSYMBOL_INT_LITERAL = 47,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 48,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 49,            /* STRING_LITERAL  */
  YYSYMBOL_EOL = 50,                       /* EOL  */
  YYSYMBOL_DEF = 51,                       /* DEF  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program = 53,                   /* program  */
  YYSYMBOL_dec = 54,                       /* dec  */
  YYSYMBOL_funDef = 55,                    /* funDef  */
  YYSYMBOL_stmts = 56,                     /* stmts  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_exprStmt = 58,                  /* exprStmt  */
  YYSYMBOL_selStmt = 59,                   /* selStmt  */
  YYSYMBOL_maybeElse = 60,                 /* maybeElse  */
  YYSYMBOL_iterStmt = 61,                  /* iterStmt  */
  YYSYMBOL_expr = 62,                      /* expr  */
  YYSYMBOL_orExpr = 63,                    /* orExpr  */
  YYSYMBOL_andExpr = 64,                   /* andExpr  */
  YYSYMBOL_unaryRelExpr = 65,              /* unaryRelExpr  */
  YYSYMBOL_relExpr = 66,                   /* relExpr  */
  YYSYMBOL_relop = 67,                     /* relop  */
  YYSYMBOL_term = 68,                      /* term  */
  YYSYMBOL_factor = 69,                    /* factor  */
  YYSYMBOL_primary = 70,                   /* primary  */
  YYSYMBOL_constant = 71,                  /* constant  */
  YYSYMBOL_int_lit = 72,                   /* int_lit  */
  YYSYMBOL_flt_lit = 73                    /* flt_lit  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,   102,   104,   107,   115,   119,   124,   124,
     124,   131,   131,   174,   189,   192,   197,   209,   209,   242,
     279,   279,   282,   282,   285,   287,   288,   290,   291,   293,
     295,   297,   299,   301,   304,   304,   306,   309,   309,   311,
     313,   316,   318,   320,   324,   324,   325,   326,   330,   330,
     331,   331
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
  "\"end of file\"", "error", "\"invalid token\"", "NAME", "NEWLINE",
  "INDENT", "DEDENT", "COLON", "PRINT", "FOR", "ID", "BOOL_TYPE",
  "INT_TYPE", "FLOAT_TYPE", "STRING_TYPE", "VOID_TYPE", "SEMICOLON",
  "LPAREN", "RPAREN", "COMMA", "LBRACE", "RBRACE", "IF", "ELIF",
  "ASSIGNMENT", "TAB", "ELSE", "WHILE", "BREAK", "RETURN", "EQUALS_SIGN",
  "LOGICAL_OR", "LOGICAL_AND", "LOGICAL_NOT", "RELOP_GT", "RELOP_LT",
  "RELOP_GE", "RELOP_LE", "RELOP_EQ", "RELOP_NE", "ARITH_PLUS",
  "ARITH_MINUS", "ARITH_MULT", "ARITH_DIV", "ARITH_MOD", "VARIADIC",
  "BOOL_LITERAL", "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "EOL",
  "DEF", "$accept", "program", "dec", "funDef", "stmts", "stmt",
  "exprStmt", "selStmt", "maybeElse", "iterStmt", "expr", "orExpr",
  "andExpr", "unaryRelExpr", "relExpr", "relop", "term", "factor",
  "primary", "constant", "int_lit", "flt_lit", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -29,     7,    42,   -69,   -69,    83,    26,   -69,   -69,    33,
     -69,    73,    73,    73,   101,   -34,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,     4,    31,    32,   -69,   -69,   132,
      13,   -69,   -69,   -69,   -69,    40,    73,    -6,     8,    11,
     -69,   -69,   -69,   -69,   101,   101,   101,   -69,   -69,   -69,
     -69,   -69,   -69,   116,   116,   116,   116,   116,   116,    59,
       9,   -69,    63,    66,    31,    32,   -69,    13,    13,   -21,
     -69,   -69,   -69,    67,   -69,    74,    75,    79,   -69,   -69,
      73,    -1,    27,     0,    52,   -69,   -69,    78,   -69,    82,
      84,   -69,    55,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     3,     4,     2,     0,     1,    12,     0,
      41,     0,     0,     0,     0,     0,    47,    48,    50,    46,
       6,     8,     9,    10,     0,    17,    20,    22,    25,    27,
      34,    37,    43,    44,    45,     0,     0,     0,     0,     0,
      24,    49,    51,    11,     0,     0,     0,    28,    29,    30,
      31,    32,    33,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    18,    21,    23,    35,    36,    26,
      38,    39,    40,     0,    19,     0,     0,     0,     7,     7,
       0,     0,     0,     0,    15,    16,     5,     0,    13,     0,
       0,     7,     0,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,   -69,   -68,   -69,   -69,   -69,   -69,   -69,
     -11,    48,    49,   -10,   -69,   -69,    43,   -25,    -5,   -69,
     -69,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    20,    21,    22,    88,    23,
      24,    25,    26,    27,    28,    55,    29,    30,    31,    32,
      33,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    38,    39,     8,    40,    84,    86,     9,    43,    10,
      81,    82,    61,    41,    42,    62,    11,     6,    63,    53,
      54,    12,     1,    92,    44,    60,    13,    74,    67,    68,
      44,     8,    14,    85,    44,     9,    66,    10,    44,    44,
      15,    44,     7,    35,    11,    16,    17,    18,    19,    12,
      36,    70,    71,    72,    13,    56,    57,    58,    59,     8,
      14,    93,    45,     9,    46,    10,    73,    75,    15,    83,
      76,    77,    11,    16,    17,    18,    19,    12,    87,    78,
      79,     9,    13,    10,    80,    89,    90,     8,    14,    91,
      11,     9,    64,    10,    65,     0,    15,     0,    69,     0,
      11,    16,    17,    18,    19,    12,    14,     0,     0,     0,
      13,    10,     0,     0,    15,     0,    14,     0,    11,    16,
      17,    18,    19,     0,    15,     0,    10,     0,     0,    16,
      17,    18,    19,    11,    14,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    16,    17,    18,    19,    47,    48,    49,    50,
      51,    52,    53,    54
};

static const yytype_int8 yycheck[] =
{
      11,    12,    13,     4,    14,     6,     6,     8,     4,    10,
      78,    79,    18,    47,    48,     7,    17,    10,     7,    40,
      41,    22,    51,    91,    30,    36,    27,    18,    53,    54,
      30,     4,    33,     6,    30,     8,    46,    10,    30,    30,
      41,    30,     0,    17,    17,    46,    47,    48,    49,    22,
      17,    56,    57,    58,    27,    42,    43,    44,    18,     4,
      33,     6,    31,     8,    32,    10,     7,     4,    41,    80,
       4,     4,    17,    46,    47,    48,    49,    22,    26,     5,
       5,     8,    27,    10,     5,     7,     4,     4,    33,     5,
      17,     8,    44,    10,    45,    -1,    41,    -1,    55,    -1,
      17,    46,    47,    48,    49,    22,    33,    -1,    -1,    -1,
      27,    10,    -1,    -1,    41,    -1,    33,    -1,    17,    46,
      47,    48,    49,    -1,    41,    -1,    10,    -1,    -1,    46,
      47,    48,    49,    17,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    34,    35,    36,    37,
      38,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    53,    54,    55,    56,    10,     0,     4,     8,
      10,    17,    22,    27,    33,    41,    46,    47,    48,    49,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    68,
      69,    70,    71,    72,    73,    17,    17,    62,    62,    62,
      65,    47,    48,     4,    30,    31,    32,    34,    35,    36,
      37,    38,    39,    40,    41,    67,    42,    43,    44,    18,
      62,    18,     7,     7,    63,    64,    65,    69,    69,    68,
      70,    70,    70,     7,    18,     4,     4,     4,     5,     5,
       5,    56,    56,    62,     6,     6,     6,    26,    60,     7,
       4,     5,    56,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    54,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    60,    60,    61,    62,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    71,    72,    72,
      73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     9,     2,     0,     1,     1,
       1,     2,     1,     8,     6,     0,     7,     1,     3,     4,
       1,     3,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     2
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
  case 2: /* program: stmts  */
#line 93 "src/files/frontend/parser.y"
               { 
  auto stmtBlock = std::make_unique<ASTStatementBlock>();
  for(auto s : *(yyvsp[0].stmtVec)) {
    stmtBlock->statements.push_back(std::unique_ptr<ASTStatement>(s));  
  }

  (yyval.stmtVec) = (yyvsp[0].stmtVec);
  main_func->Define(std::move(stmtBlock));

  }
#line 1510 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 5: /* funDef: DEF ID LPAREN RPAREN COLON NEWLINE INDENT expr DEDENT  */
#line 107 "src/files/frontend/parser.y"
                                                              {
   printf("Function definition\n");
   printf("Function name: %s\n", (yyvsp[-7].strval));
  }
#line 1519 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 6: /* stmts: stmts stmt  */
#line 115 "src/files/frontend/parser.y"
                  {
  printf("Found Statement\n");
  (yyval.stmtVec) = (yyvsp[-1].stmtVec);
  (yyval.stmtVec)->push_back((yyvsp[0].stmt));
}
#line 1529 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 7: /* stmts: %empty  */
#line 119 "src/files/frontend/parser.y"
    {
  printf("No statements\n");
  (yyval.stmtVec) = new std::vector<ASTStatement *>();
}
#line 1538 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 8: /* stmt: exprStmt  */
#line 124 "src/files/frontend/parser.y"
               { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1544 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 9: /* stmt: selStmt  */
#line 124 "src/files/frontend/parser.y"
                                        {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1550 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 10: /* stmt: iterStmt  */
#line 124 "src/files/frontend/parser.y"
                                                              {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1556 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 11: /* exprStmt: expr NEWLINE  */
#line 131 "src/files/frontend/parser.y"
                       { (yyval.stmt) = (yyvsp[-1].exp); }
#line 1562 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 12: /* exprStmt: NEWLINE  */
#line 131 "src/files/frontend/parser.y"
                                              { (yyval.stmt) = new ASTStatementBlock(); //empty statement = empty block
 }
#line 1569 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 13: /* selStmt: IF expr COLON NEWLINE INDENT stmts DEDENT maybeElse  */
#line 174 "src/files/frontend/parser.y"
                                                             {
  printf("If statement\n");
  printf("Expression: %s\n", (yyvsp[-6].exp)->ToString("").c_str());
  auto stmtBlock = std::make_unique<ASTStatementBlock>();
  for(auto s : *(yyvsp[-2].stmtVec)) {
    stmtBlock->statements.push_back(std::unique_ptr<ASTStatement>(s));  
  }

  // auto elseStmtBlock = std::make_unique<ASTStatementBlock>();
  // for(auto s : $8) {
  //   elseStmtBlock->statements.push_back(std::unique_ptr<ASTStatement>(s));  
  // }
  (yyval.stmt) = new ASTStatementIf(std::unique_ptr<ASTExpression>((yyvsp[-6].exp)), std::move(stmtBlock), std::unique_ptr<ASTStatementBlock>(nullptr));
 }
#line 1588 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 14: /* maybeElse: ELSE COLON NEWLINE INDENT stmts DEDENT  */
#line 189 "src/files/frontend/parser.y"
                                                  { 
  printf("Else statement\n");
  (yyval.stmtBlock) = new ASTStatementBlock();
}
#line 1597 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 15: /* maybeElse: %empty  */
#line 192 "src/files/frontend/parser.y"
    { 
  printf("No else statement\n");
  (yyval.stmtBlock) = new ASTStatementBlock();
}
#line 1606 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 16: /* iterStmt: WHILE expr COLON NEWLINE INDENT stmts DEDENT  */
#line 197 "src/files/frontend/parser.y"
                                                       {
  auto stmtBlock = std::make_unique<ASTStatementBlock>();
  for(auto s : *(yyvsp[-1].stmtVec)) {
    stmtBlock->statements.push_back(std::unique_ptr<ASTStatement>(s));  
  }
  (yyval.stmt) = new ASTStatementWhile(std::unique_ptr<ASTExpression>((yyvsp[-5].exp)), std::move(stmtBlock));
}
#line 1618 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 17: /* expr: orExpr  */
#line 209 "src/files/frontend/parser.y"
             {(yyval.exp) = (yyvsp[0].exp);}
#line 1624 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 18: /* expr: expr EQUALS_SIGN orExpr  */
#line 209 "src/files/frontend/parser.y"
                                                  {
  printf("Assignment\n");
  std::string value = (yyvsp[0].exp)->ToString("");
  std::string varName = (yyvsp[-2].exp)->ToString("");


  varName.erase(std::remove(varName.begin(), varName.end(), ' '), varName.end());
  value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
  varName.erase(std::remove(varName.begin(), varName.end(), '\t'), varName.end());
  value.erase(std::remove(value.begin(), value.end(), '\t'), value.end());
  varName.erase(std::remove(varName.begin(), varName.end(), '\n'), varName.end());
  value.erase(std::remove(value.begin(), value.end(), '\n'), value.end());
  varName.erase(std::remove(varName.begin(), varName.end(), '\r'), varName.end());

  // printf("Variable name: %s\n", varName.c_str());
  printf("Value: %s\n", value.c_str());

   // check if variable is already in the main function
  if (std::find(varNames.begin(), varNames.end(), varName) == varNames.end()) {
    auto r = (yyvsp[0].exp)->ReturnType(*main_func);
   if (r->Equals(&VarTypeSimple::IntType)) {
     main_func->AddStackVar(ASTFunctionParameter(VarTypeSimple::IntType.Copy(), varName));
   } else if (r->Equals(&VarTypeSimple::FloatType)) {
     main_func->AddStackVar(ASTFunctionParameter(VarTypeSimple::FloatType.Copy(), varName));
   } else if (r->Equals(&VarTypeSimple::StringType)) {
     main_func->AddStackVar(ASTFunctionParameter(VarTypeSimple::StringType.Copy(), varName));
   } else if (r->Equals(&VarTypeSimple::BoolType)) {
     main_func->AddStackVar(ASTFunctionParameter(VarTypeSimple::BoolType.Copy(), varName));
   }
  }  
  varNames.push_back(varName);
  (yyval.exp) = new ASTExpressionAssignment(std::unique_ptr<ASTExpression>((yyvsp[-2].exp)), std::unique_ptr<ASTExpression>((yyvsp[0].exp)));

}
#line 1663 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 19: /* expr: PRINT LPAREN expr RPAREN  */
#line 242 "src/files/frontend/parser.y"
                              {
  printf("Print statement\n");
  std::string value = (yyvsp[-1].exp)->ToString("");
  printf("Value: %s\n", value.c_str());

   if (!isPrint) {
    auto parameters = ASTFunctionParameters();
    parameters.push_back(ASTFunctionParameter(VarTypeSimple::StringType.Copy(), "str"));
    ast.AddFunction("printf", VarTypeSimple::IntType.Copy(), std::move(parameters), true);
    isPrint = true;
  }

 

  auto argVec = std::vector<std::unique_ptr<ASTExpression>>();
 if ((yyvsp[-1].exp)->ReturnType(*main_func)->Equals(&VarTypeSimple::IntType)) {
    argVec.push_back(std::unique_ptr<ASTExpression>(new ASTExpressionString("%d\n")));
  } else if ((yyvsp[-1].exp)->ReturnType(*main_func)->Equals(&VarTypeSimple::FloatType)) {
    argVec.push_back(std::unique_ptr<ASTExpression>(new ASTExpressionString("%f\n")));
  } else if ((yyvsp[-1].exp)->ReturnType(*main_func)->Equals(&VarTypeSimple::StringType)) {
    argVec.push_back(std::unique_ptr<ASTExpression>(new ASTExpressionString("%s\n")));
  } else if ((yyvsp[-1].exp)->ReturnType(*main_func)->Equals(&VarTypeSimple::BoolType)) {
    // auto v = ast.scopeTable.GetVariableValue("a");
    // bool a = main_func->getLLVMValue(v);
    // printf("Bool value: %d\n", a);
    argVec.push_back(std::unique_ptr<ASTExpression>(new ASTExpressionString("%d\n")));
  }




  
  argVec.push_back(std::unique_ptr<ASTExpression>((yyvsp[-1].exp)));
  
  (yyval.exp) = new ASTExpressionCall(ASTExpressionVariable::Create("printf"), std::move(argVec));
}
#line 1704 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 20: /* orExpr: andExpr  */
#line 279 "src/files/frontend/parser.y"
                {(yyval.exp) = (yyvsp[0].exp);}
#line 1710 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 21: /* orExpr: orExpr LOGICAL_OR andExpr  */
#line 279 "src/files/frontend/parser.y"
                                                       {
  (yyval.exp) = new ASTExpressionOr(std::unique_ptr<ASTExpression>((yyvsp[-2].exp)), std::unique_ptr<ASTExpression>((yyvsp[0].exp)));
 }
#line 1718 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 22: /* andExpr: unaryRelExpr  */
#line 282 "src/files/frontend/parser.y"
                      {(yyval.exp) = (yyvsp[0].exp);}
#line 1724 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 23: /* andExpr: andExpr LOGICAL_AND unaryRelExpr  */
#line 282 "src/files/frontend/parser.y"
                                                                    {
  (yyval.exp) = new ASTExpressionAnd(std::unique_ptr<ASTExpression>((yyvsp[-2].exp)), std::unique_ptr<ASTExpression>((yyvsp[0].exp)));
 }
#line 1732 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 24: /* unaryRelExpr: LOGICAL_NOT unaryRelExpr  */
#line 285 "src/files/frontend/parser.y"
                                       {
  (yyval.exp) = (yyvsp[0].exp);
 }
#line 1740 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 25: /* unaryRelExpr: relExpr  */
#line 287 "src/files/frontend/parser.y"
             {(yyval.exp) = (yyvsp[0].exp);}
#line 1746 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 26: /* relExpr: term relop term  */
#line 288 "src/files/frontend/parser.y"
                         {
  (yyval.exp) = new ASTExpressionComparison((yyvsp[-1].rel), std::unique_ptr<ASTExpression>((yyvsp[-2].exp)), std::unique_ptr<ASTExpression>((yyvsp[0].exp)));
 }
#line 1754 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 27: /* relExpr: term  */
#line 290 "src/files/frontend/parser.y"
          {(yyval.exp) = (yyvsp[0].exp);}
#line 1760 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 28: /* relop: RELOP_GT  */
#line 291 "src/files/frontend/parser.y"
                {
  (yyval.rel) = ASTExpressionComparisonType::GreaterThan;
 }
#line 1768 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 29: /* relop: RELOP_LT  */
#line 293 "src/files/frontend/parser.y"
             {
  (yyval.rel) = ASTExpressionComparisonType::LessThan;
 }
#line 1776 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 30: /* relop: RELOP_GE  */
#line 295 "src/files/frontend/parser.y"
             {
  (yyval.rel) = ASTExpressionComparisonType::GreaterThanOrEqual;
 }
#line 1784 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 31: /* relop: RELOP_LE  */
#line 297 "src/files/frontend/parser.y"
             {
  (yyval.rel) = ASTExpressionComparisonType::LessThanOrEqual;
 }
#line 1792 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 32: /* relop: RELOP_EQ  */
#line 299 "src/files/frontend/parser.y"
             {
  (yyval.rel) = ASTExpressionComparisonType::Equal;
 }
#line 1800 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 33: /* relop: RELOP_NE  */
#line 301 "src/files/frontend/parser.y"
             {
  (yyval.rel) = ASTExpressionComparisonType::NotEqual;
 }
#line 1808 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 34: /* term: factor  */
#line 304 "src/files/frontend/parser.y"
             {(yyval.exp) = (yyvsp[0].exp);}
#line 1814 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 35: /* term: term ARITH_PLUS factor  */
#line 304 "src/files/frontend/parser.y"
                                                {
  (yyval.exp) = new ASTExpressionAddition(std::unique_ptr<ASTExpression>((yyvsp[-2].exp)), std::unique_ptr<ASTExpression>((yyvsp[0].exp)));
 }
#line 1822 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 36: /* term: term ARITH_MINUS factor  */
#line 306 "src/files/frontend/parser.y"
                            {
  (yyval.exp) = new ASTExpressionSubtraction(std::unique_ptr<ASTExpression>((yyvsp[-2].exp)), std::unique_ptr<ASTExpression>((yyvsp[0].exp)));
 }
#line 1830 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 37: /* factor: primary  */
#line 309 "src/files/frontend/parser.y"
                {(yyval.exp) = (yyvsp[0].exp);}
#line 1836 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 38: /* factor: factor ARITH_MULT primary  */
#line 309 "src/files/frontend/parser.y"
                                                       {
  (yyval.exp) = new ASTExpressionMultiplication(std::unique_ptr<ASTExpression>((yyvsp[-2].exp)), std::unique_ptr<ASTExpression>((yyvsp[0].exp)));
 }
#line 1844 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 39: /* factor: factor ARITH_DIV primary  */
#line 311 "src/files/frontend/parser.y"
                             {
  (yyval.exp) = new ASTExpressionDivision(std::unique_ptr<ASTExpression>((yyvsp[-2].exp)), std::unique_ptr<ASTExpression>((yyvsp[0].exp)));
 }
#line 1852 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 40: /* factor: factor ARITH_MOD primary  */
#line 313 "src/files/frontend/parser.y"
                             {
  (yyval.exp) = (yyvsp[-2].exp);
 }
#line 1860 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 41: /* primary: ID  */
#line 316 "src/files/frontend/parser.y"
            {
  (yyval.exp) = new ASTExpressionVariable((yyvsp[0].strval));
 }
#line 1868 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 42: /* primary: LPAREN expr RPAREN  */
#line 318 "src/files/frontend/parser.y"
                       {
  (yyval.exp) = (yyvsp[-1].exp);
 }
#line 1876 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 43: /* primary: constant  */
#line 320 "src/files/frontend/parser.y"
              {
  (yyval.exp) = (yyvsp[0].exp);
 }
#line 1884 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 44: /* constant: int_lit  */
#line 324 "src/files/frontend/parser.y"
                  { (yyval.exp) = new ASTExpressionInt((yyvsp[0].intval)); }
#line 1890 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 45: /* constant: flt_lit  */
#line 324 "src/files/frontend/parser.y"
                                                               {(yyval.exp) = new ASTExpressionFloat((yyvsp[0].fltval));}
#line 1896 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 46: /* constant: STRING_LITERAL  */
#line 325 "src/files/frontend/parser.y"
               {  (yyval.exp) = new ASTExpressionString((yyvsp[0].strval)); }
#line 1902 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 47: /* constant: BOOL_LITERAL  */
#line 326 "src/files/frontend/parser.y"
             {
    printf("Bool Literal\n");
   (yyval.exp) = new ASTExpressionBool((yyvsp[0].boolval));
   }
#line 1911 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 49: /* int_lit: ARITH_MINUS INT_LITERAL  */
#line 330 "src/files/frontend/parser.y"
                                               {(yyval.intval) = -1 * (yyvsp[0].intval);}
#line 1917 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;

  case 51: /* flt_lit: ARITH_MINUS FLOAT_LITERAL  */
#line 331 "src/files/frontend/parser.y"
                                                   {(yyval.fltval) = -1 * (yyvsp[0].fltval);}
#line 1923 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"
    break;


#line 1927 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.cc"

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

#line 333 "src/files/frontend/parser.y"

int main(int argc, char **argv) {


  // Arg flags:
  bool showHelp = false; // Show the help and exit.
  std::string openFile = ""; // File to open. Nothing for standard in.
  std::string outFile = ""; // File to write to. Nothing for standard out.
  int outputFormat = 3; // 0 - LLVM Assembly. 1 - LLVM Bitcode. 2 - Object (TODO). 3 - AST tree.
  bool printAST = true; // If to print the AST to console.

  // Read the arguments. Don't count the first which is the executable name.
  for (int i = 1; i < argc; i++)
  {
    bool hasNextArg = i + 1 < argc;
    std::string arg(argv[i]);
    if (arg == "-i" && hasNextArg)
    {
      i++;
      openFile = argv[i];
    }
    else if (arg == "-o" && hasNextArg)
    {
      i++;
      outFile = argv[i];
    }
    else if (arg == "-nPrint")
    {
      printAST = false;
    }
    else if (arg == "-fAsm")
    {
      outputFormat = 0;
    }
    else if (arg == "-fBc")
    {
      outputFormat = 1;
    }
    else if (arg == "-fObj")
    {
      outputFormat = 2;
    }
    else if (arg == "-fAst")
    {
      outputFormat = 3;
    }
    else
    {
      showHelp = true;
    }
  }
  printAST &= outputFormat != 3 && outFile != ""; // Always print AST by default in addition to whatever is being output.

  // Show help if needed.
  if (showHelp)
  {
    printf("Usage: LLVM-Lab [options]\n");
    printf("\nOptions:\n\n");
    printf("-h              Show this help screen.\n");
    printf("-i [input]      Read from an input file (reads from console by default).\n");
    printf("-o [output]     Write to an output file (writes to console by default).\n");
    printf("-nPrint         If to not print the AST to the console.\n");
    printf("-fAsm           Output format is in LLVM assembly.\n");
    printf("-fAst           Output format is an abstract syntax tree.\n");
    printf("-fBc            Output format is in LLVM bitcode.\n");
    printf("-fObj           Output format is an object file.\n");
    return 1;
  }

  // Fetch input.
  if (openFile != "")
  {
    yyin = fopen(openFile.c_str(), "r");
  }

  if (yyparse() == 1)
  {
    printf("Irrecoverable error state, aborting\n");
    return 1;
  }

  // Close input if needed.
  if (openFile != "")
  {
    fclose(yyin);
  }

  // Do the compilation.
  ast.Compile();

  // Print AST if needed.
  if (printAST) std::cout << ast.ToString() << std::endl;

  // Export data.
  if (outputFormat == 0)
  {
    ast.WriteLLVMAssemblyToFile(outFile);
  }
  else if (outputFormat == 1)
  {
    ast.WriteLLVMBitcodeToFile(outFile);
  }
  else if (outputFormat == 2)
  {
    std::cout << "OBJ exporting not supported yet." << std::endl;
  }
  else
  {
    std::cout << ast.ToString() << std::endl;
  }
  return 0;
}

void yyerror(const char *s)
{
  fprintf(stderr, "error: %s\n", s);
}
