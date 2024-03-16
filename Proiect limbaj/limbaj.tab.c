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
#line 1 "limbaj.y"

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include "UserDefinedClasses.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
using namespace std;
ofstream fout("symboltable");
void yyerror(const char * s);
int ind=0;
int isClass=0;
char buffer[5000];
char domain[50]="global";
char aux[50]="global";
class IdList ids;
class UserDefinedClasses cls;
class UserFunctions fnc;

#line 95 "limbaj.tab.c"

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

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_FLOAT_NR = 6,                   /* FLOAT_NR  */
  YYSYMBOL_NR = 7,                         /* NR  */
  YYSYMBOL_BOOL_TRUE = 8,                  /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 9,                 /* BOOL_FALSE  */
  YYSYMBOL_CHARACTER = 10,                 /* CHARACTER  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_TYPE = 12,                      /* TYPE  */
  YYSYMBOL_STRING_TYPE = 13,               /* STRING_TYPE  */
  YYSYMBOL_STRING_TEXT = 14,               /* STRING_TEXT  */
  YYSYMBOL_CLASS = 15,                     /* CLASS  */
  YYSYMBOL_BOOL_TYPE = 16,                 /* BOOL_TYPE  */
  YYSYMBOL_ENTRY_POINT = 17,               /* ENTRY_POINT  */
  YYSYMBOL_LOGIC_OR = 18,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_AND = 19,                 /* LOGIC_AND  */
  YYSYMBOL_CHAR_TYPE = 20,                 /* CHAR_TYPE  */
  YYSYMBOL_IF_START = 21,                  /* IF_START  */
  YYSYMBOL_WHILE_START = 22,               /* WHILE_START  */
  YYSYMBOL_FOR_START = 23,                 /* FOR_START  */
  YYSYMBOL_DEC = 24,                       /* DEC  */
  YYSYMBOL_INC = 25,                       /* INC  */
  YYSYMBOL_DO = 26,                        /* DO  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_CONST = 28,                     /* CONST  */
  YYSYMBOL_EVAL = 29,                      /* EVAL  */
  YYSYMBOL_BOOL_LT = 30,                   /* BOOL_LT  */
  YYSYMBOL_BOOL_LTE = 31,                  /* BOOL_LTE  */
  YYSYMBOL_BOOL_GT = 32,                   /* BOOL_GT  */
  YYSYMBOL_BOOL_GTE = 33,                  /* BOOL_GTE  */
  YYSYMBOL_BOOL_E = 34,                    /* BOOL_E  */
  YYSYMBOL_BOOL_NE = 35,                   /* BOOL_NE  */
  YYSYMBOL_TYPEOF = 36,                    /* TYPEOF  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_progr = 50,                     /* progr  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_58_8 = 58,                      /* $@8  */
  YYSYMBOL_typeoffunc = 59,                /* typeoffunc  */
  YYSYMBOL_evalFunc = 60,                  /* evalFunc  */
  YYSYMBOL_evalForType = 61,               /* evalForType  */
  YYSYMBOL_evalAritFuncFT = 62,            /* evalAritFuncFT  */
  YYSYMBOL_evalAritFunc = 63,              /* evalAritFunc  */
  YYSYMBOL_e = 64,                         /* e  */
  YYSYMBOL_list_param_inner = 65,          /* list_param_inner  */
  YYSYMBOL_param = 66,                     /* param  */
  YYSYMBOL_functions = 67,                 /* functions  */
  YYSYMBOL_function = 68,                  /* function  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_70_10 = 70,                     /* $@10  */
  YYSYMBOL_71_11 = 71,                     /* $@11  */
  YYSYMBOL_72_12 = 72,                     /* $@12  */
  YYSYMBOL_73_13 = 73,                     /* $@13  */
  YYSYMBOL_74_14 = 74,                     /* $@14  */
  YYSYMBOL_75_15 = 75,                     /* $@15  */
  YYSYMBOL_76_16 = 76,                     /* $@16  */
  YYSYMBOL_77_17 = 77,                     /* $@17  */
  YYSYMBOL_78_18 = 78,                     /* $@18  */
  YYSYMBOL_79_19 = 79,                     /* $@19  */
  YYSYMBOL_80_20 = 80,                     /* $@20  */
  YYSYMBOL_81_21 = 81,                     /* $@21  */
  YYSYMBOL_82_22 = 82,                     /* $@22  */
  YYSYMBOL_83_23 = 83,                     /* $@23  */
  YYSYMBOL_84_24 = 84,                     /* $@24  */
  YYSYMBOL_85_25 = 85,                     /* $@25  */
  YYSYMBOL_86_26 = 86,                     /* $@26  */
  YYSYMBOL_87_27 = 87,                     /* $@27  */
  YYSYMBOL_88_28 = 88,                     /* $@28  */
  YYSYMBOL_conditionalBlock = 89,          /* conditionalBlock  */
  YYSYMBOL_forFirst = 90,                  /* forFirst  */
  YYSYMBOL_forSecond = 91,                 /* forSecond  */
  YYSYMBOL_bExp = 92,                      /* bExp  */
  YYSYMBOL_bExpForm = 93,                  /* bExpForm  */
  YYSYMBOL_declarations = 94,              /* declarations  */
  YYSYMBOL_classLineGroup = 95,            /* classLineGroup  */
  YYSYMBOL_classLine = 96,                 /* classLine  */
  YYSYMBOL_declarationBlockForClass = 97,  /* declarationBlockForClass  */
  YYSYMBOL_classDeclaration = 98,          /* classDeclaration  */
  YYSYMBOL_99_29 = 99,                     /* $@29  */
  YYSYMBOL_userDefinedDeclarations = 100,  /* userDefinedDeclarations  */
  YYSYMBOL_decl = 101,                     /* decl  */
  YYSYMBOL_block = 102,                    /* block  */
  YYSYMBOL_list = 103,                     /* list  */
  YYSYMBOL_idVar = 104,                    /* idVar  */
  YYSYMBOL_statement = 105,                /* statement  */
  YYSYMBOL_onlyExp = 106,                  /* onlyExp  */
  YYSYMBOL_call_list = 107                 /* call_list  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1024

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  518

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,    48,     2,     2,     2,     2,     2,     2,
      41,    42,    39,    37,    46,    38,    45,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    67,    68,
      69,    70,    71,    74,    77,    80,    81,    82,    83,    84,
      85,    86,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   108,   118,   130,   139,   161,   162,   165,   166,
     167,   168,   169,   170,   171,   172,   174,   184,   174,   185,
     194,   185,   195,   202,   195,   203,   211,   203,   212,   218,
     212,   219,   227,   219,   228,   236,   228,   237,   245,   237,
     246,   255,   246,   256,   263,   256,   266,   267,   268,   269,
     270,   271,   272,   274,   276,   279,   280,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     309,   310,   312,   313,   314,   315,   316,   317,   319,   319,
     327,   328,   331,   342,   353,   364,   375,   386,   396,   405,
     414,   424,   434,   443,   453,   462,   480,   497,   514,   532,
     541,   551,   561,   571,   581,   591,   601,   621,   622,   626,
     627,   628,   629,   632,   638,   645,   651,   652,   677,   711,
     749,   768,   795,   822,   849,   877,   896,   921,   940,   959,
     982,  1012,  1038,  1047,  1056,  1078,  1079,  1080,  1094,  1108,
    1122,  1136,  1150,  1171,  1192,  1213,  1242,  1270,  1288,  1311,
    1312,  1313,  1314,  1315,  1316,  1317,  1318,  1321,  1329,  1340,
    1353,  1364,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1399,  1412,  1423
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
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END",
  "ASSIGN", "FLOAT_NR", "NR", "BOOL_TRUE", "BOOL_FALSE", "CHARACTER", "ID",
  "TYPE", "STRING_TYPE", "STRING_TEXT", "CLASS", "BOOL_TYPE",
  "ENTRY_POINT", "LOGIC_OR", "LOGIC_AND", "CHAR_TYPE", "IF_START",
  "WHILE_START", "FOR_START", "DEC", "INC", "DO", "ELSE", "CONST", "EVAL",
  "BOOL_LT", "BOOL_LTE", "BOOL_GT", "BOOL_GTE", "BOOL_E", "BOOL_NE",
  "TYPEOF", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'['", "']'", "'.'",
  "','", "';'", "'!'", "$accept", "progr", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "typeoffunc", "evalFunc", "evalForType",
  "evalAritFuncFT", "evalAritFunc", "e", "list_param_inner", "param",
  "functions", "function", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23",
  "$@24", "$@25", "$@26", "$@27", "$@28", "conditionalBlock", "forFirst",
  "forSecond", "bExp", "bExpForm", "declarations", "classLineGroup",
  "classLine", "declarationBlockForClass", "classDeclaration", "$@29",
  "userDefinedDeclarations", "decl", "block", "list", "idVar", "statement",
  "onlyExp", "call_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-272)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-226)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     496,     8,    21,    33,    64,    73,    82,   202,    86,   649,
    -272,   667,    53,   661,    62,    87,     2,    99,     6,  -272,
       7,    12,   158,   167,   197,  -272,   222,    41,   229,   238,
     247,  -272,    43,   752,   213,  -272,   136,   758,   680,   230,
    -272,   290,   200,   322,   200,   286,   275,   611,   200,   334,
      22,   622,   200,   221,   628,   200,    29,   346,   370,    87,
     336,   347,   353,   364,   405,   415,   163,  -272,   416,   261,
     310,   764,  -272,   444,   458,   464,   478,   487,  -272,    75,
    -272,  -272,  -272,   641,   108,   375,  -272,   144,   526,  -272,
    -272,  -272,   294,   754,   438,  -272,  -272,  -272,  -272,   306,
     762,  -272,   474,  -272,  -272,   332,   771,   200,   200,   300,
     307,   476,   477,   490,   492,   502,   510,   333,  -272,   509,
    -272,  -272,  -272,  -272,  -272,   770,   228,   200,   550,   200,
     920,   200,   200,   200,   200,  -272,  -272,   531,   570,  -272,
    -272,   532,  -272,   579,  -272,   643,  -272,   534,  -272,  -272,
     563,   380,  -272,  -272,   564,   375,   779,  -272,  -272,  -272,
     566,  -272,  -272,   549,  -272,   555,   557,   575,   581,   570,
    -272,  -272,   173,   215,  -272,  -272,  -272,   356,  -272,    72,
    -272,   103,   711,  -272,   311,  -272,   453,   787,   585,   926,
    -272,   384,   384,  -272,  -272,   570,  -272,   200,   556,  -272,
     570,  -272,   200,  -272,  -272,  -272,   570,  -272,   200,   592,
     602,   570,  -272,   200,  -272,   200,   570,   570,  -272,   570,
    -272,  -272,   609,  -272,  -272,   570,   245,   200,   646,   200,
      95,   685,   610,  -272,  -272,   400,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   456,   465,  -272,    15,
    -272,   420,  -272,  -272,   570,   795,  -272,   127,   647,   655,
     656,   657,   634,   644,   660,   570,   662,   668,  -272,  -272,
    -272,  -272,   582,   663,  -272,   570,   803,  -272,   570,   811,
    -272,  -272,  -272,   570,   819,   827,  -272,  -272,   570,  -272,
     570,   570,  -272,  -272,   486,   586,   835,   672,   932,   698,
     541,   414,   150,   722,   205,   375,   375,   375,   375,   375,
     375,   483,   665,   554,   573,    95,  -272,    95,  -272,  -272,
     934,  -272,  -272,  -272,   648,  -272,  -272,   530,  -272,   257,
     200,   677,    30,    31,    34,    56,   473,   473,   686,   699,
     479,  -272,  -272,   429,  -272,  -272,  -272,   679,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,   570,
     743,   761,   305,   603,   485,   494,   400,   400,   400,  -272,
     692,   697,   348,   200,   736,  -272,  -272,  -272,  -272,   895,
    -272,   124,   984,  -272,  -272,   953,   843,    23,   716,   724,
      16,   116,   720,   768,   738,   946,   745,   746,   753,   951,
     755,   763,   772,  -272,  -272,  -272,   955,    95,  -272,    95,
    -272,   778,   780,   786,  -272,  -272,   956,   958,   851,   788,
     228,   200,   785,   944,  -272,   799,   539,   362,   570,   570,
    -272,   601,   765,  -272,   200,   473,  -272,   200,  -272,  -272,
    -272,  -272,   200,   802,  -272,  -272,  -272,   961,   794,   796,
    -272,  -272,   963,   964,   411,   966,   859,   142,   548,  -272,
    -272,  -272,   902,  -272,  -272,  -272,   969,   810,  -272,   570,
     804,  -272,   244,   812,   867,   875,   403,  -272,  -272,  -272,
     971,   170,   250,  -272,  -272,  -272,   909,  -272,  -272,   200,
     833,  -272,   360,  -272,   570,  -272,   774,   818,   820,  -272,
     972,   228,   200,   834,   883,   203,  -272,  -272,  -272,  -272,
    -272,  -272,   974,   891,   319,   338,   436,   468
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,   156,   136,     0,   149,   128,
     151,   142,     0,     0,     0,     1,     0,     0,     0,     0,
       0,    55,     0,     0,     0,   130,     0,     0,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,     0,   131,     0,     0,     0,     0,     0,    83,     0,
      46,    38,    39,    40,     0,   137,    71,     0,     0,    16,
     150,    77,     0,     0,     0,   129,   152,   153,    74,     0,
       0,   139,   165,   140,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    48,
      50,    52,    51,    84,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    56,   148,     0,    78,
      62,   145,   127,     0,   125,     0,   122,     0,    75,    59,
     146,     0,    81,    65,   147,   138,     0,   154,   155,   143,
       0,    14,    10,     0,     8,     0,     0,     0,     0,     0,
      69,    47,    38,    39,   116,   118,   216,    40,   214,     0,
      43,     0,     0,   215,    98,   207,     0,     0,    44,     0,
      36,    32,    34,    33,    35,     0,    57,     0,     0,    17,
       0,    63,     0,   126,   123,   124,     0,    60,     0,     0,
       0,     0,    66,     0,   144,     0,     0,     0,    12,     0,
       4,     6,     0,    49,    85,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
      41,     0,    37,    73,     0,     0,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   185,
     160,   166,     0,     0,    79,     0,     0,    76,     0,     0,
     163,   164,    82,     0,     0,     0,    15,    11,     0,     9,
       0,     0,     2,    70,    43,     0,     0,    44,     0,     0,
      36,    97,     0,     0,     0,   114,   111,   115,   112,   110,
     113,    32,    34,    33,    35,     0,    99,     0,   100,   222,
      40,   220,   221,   219,     0,    58,   132,     0,   156,     0,
       0,     0,   136,   149,   151,   142,     0,     0,     0,     0,
       0,    25,    27,     0,    18,   157,   161,     0,   159,    64,
     133,    61,   135,    67,   134,   141,    13,     5,     7,     0,
      42,    41,     0,    37,     0,     0,     0,     0,     0,   109,
       0,     0,     0,     0,     0,    45,   177,   178,   170,    40,
     179,     0,     0,   175,   183,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,    40,     0,     0,     0,    40,
       0,     0,     0,   162,     3,   211,     0,     0,   104,     0,
     103,     0,     0,     0,   106,   105,    43,     0,     0,    44,
       0,     0,     0,     0,   182,     0,     0,     0,     0,     0,
      96,     0,     0,    93,     0,     0,    30,     0,    26,    29,
      20,    22,     0,     0,    21,    19,    28,    45,     0,     0,
     101,   102,    42,    41,     0,     0,     0,    44,     0,   190,
     191,   189,    40,   188,   187,   198,     0,    86,    89,     0,
       0,    95,     0,     0,     0,     0,    44,   107,   108,   226,
       0,    42,    41,   171,   172,   174,    40,   173,   167,     0,
       0,   197,     0,    92,     0,    94,     0,    41,    41,    24,
      45,     0,     0,     0,     0,    44,    87,    88,    91,    90,
      31,    23,     0,     0,    44,    41,    42,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,   -42,   253,   705,   139,     0,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -271,  -272,  -272,  -161,  -139,   839,  -272,   708,  -272,   848,
    -272,  -272,     3,  -149,  -272,  -146,  -264,  -245,  -211
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     8,   359,   290,   291,   219,   217,   288,   216,   138,
     268,   269,   341,   344,   342,   182,    79,    80,     9,    10,
     196,   254,   207,   278,   201,   275,   212,   283,   170,   225,
     135,   195,   148,   206,   139,   200,   152,   211,   123,   169,
     270,   391,   431,   183,   184,    11,   145,   146,    95,    12,
      49,    13,   271,   199,   272,   103,   273,   185,   186
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   346,    88,    14,   323,   210,    93,    42,   347,    31,
     100,    46,    50,   106,    34,   295,    14,    53,   232,    15,
     224,   172,   173,   174,   175,   319,   320,   328,   426,   321,
      96,    97,    16,    31,   107,    42,    46,    31,    17,    50,
     324,    34,   130,    43,    18,    44,   253,    47,    51,    48,
      52,   274,    60,    54,    16,    55,   179,   277,    61,   151,
      65,    53,   282,   181,   427,   155,   156,   286,   287,   232,
     289,    31,   108,    44,    48,    19,   293,    52,    81,    82,
     174,   175,   383,    83,    20,   187,    25,   189,   322,   191,
     192,   193,   194,    21,   144,   397,   304,   147,   402,    55,
      35,    81,    82,   174,   175,   325,    83,   316,   318,    40,
     229,   233,   234,   230,    81,    82,   339,   124,   385,    83,
     181,   125,    81,    82,   174,   175,   349,    83,    41,   351,
      81,    82,   327,   129,   353,    83,   230,   231,   328,   356,
      45,   357,   358,   181,   235,   144,   129,    16,   147,    84,
      33,   406,    37,    68,   370,   255,   371,   230,   233,   234,
     276,   417,   229,   430,   181,    84,   279,   470,   329,    56,
     330,   284,   331,   285,    60,   388,   389,    71,    57,   396,
     113,   464,   401,   251,  -195,   296,   136,   298,   299,  -195,
     125,   366,   393,   303,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   303,   303,    81,    82,    58,   455,
     404,    83,  -180,   488,    22,  -205,   466,  -180,    23,  -205,
    -205,   506,    24,   367,   368,   408,   410,   411,   412,   413,
     432,   101,   102,    59,   172,   173,   174,   175,   176,   177,
      62,    84,   178,   480,   251,  -194,   448,   369,   449,    63,
    -194,   172,   173,   174,   175,   176,   177,  -206,    64,   178,
      67,  -206,  -206,   172,   173,   174,   175,   176,   177,   179,
     180,   178,    60,   299,   473,   299,   181,    72,   115,   467,
     468,   131,   132,   133,   134,   382,   179,   294,   386,    90,
     512,   495,  -184,   181,   303,   303,    87,  -184,   179,   384,
      92,    73,    74,    75,    99,   181,    76,   105,   157,   158,
      77,   172,   173,   174,   175,   176,   177,   159,   160,   178,
     493,    16,   303,   303,   303,   303,   303,   116,    89,   246,
     247,   418,    78,    73,    74,    75,   140,    94,    76,   423,
     125,   392,    77,   507,    60,   508,   179,   405,   149,   303,
     167,   109,   125,   181,   172,   173,   174,   175,   176,   177,
     251,  -196,   178,   198,    86,   299,  -196,   299,   172,   173,
     174,   175,   176,   177,   153,   110,   178,    43,   125,   456,
    -193,   262,   263,   264,   382,  -193,   265,   209,   111,   179,
     416,   102,   472,   303,    47,   474,   181,   226,  -212,   227,
     475,   228,  -212,   179,   465,    51,    81,    82,   174,   175,
     181,    83,   131,   132,   133,   134,   382,   172,   173,   174,
     175,   176,   177,   133,   134,   178,   172,   173,   174,   175,
     176,   177,   364,   365,   178,   172,   173,   174,   175,   398,
     399,    84,   142,   400,   251,   499,    54,   504,   302,     1,
     143,     3,   179,   479,     5,   118,   112,   114,     6,   181,
     513,   179,    81,    82,   174,   175,     7,    83,   181,   119,
     179,    81,    82,   174,   175,   120,    83,   181,  -181,    81,
      82,   174,   175,  -181,    83,   172,   173,   174,   175,   121,
     395,    81,    82,   174,   175,   248,    83,   315,   122,   249,
      81,    82,   174,   175,   302,    83,   317,     1,     2,     3,
    -169,     4,     5,   302,   230,  -169,     6,   151,   161,   162,
     179,   181,   133,   134,     7,  -199,   407,   181,  -209,  -199,
    -199,   163,  -209,   302,   164,   409,   172,   173,   376,   377,
     378,   379,   302,   165,   380,   172,   173,   459,   460,   461,
     462,   166,   168,   463,   172,   173,   483,   484,   485,   486,
     256,   188,   487,   131,   132,   133,   134,   257,   258,   259,
     137,   381,   260,   198,   197,   202,   261,   262,   263,   264,
     381,   205,   265,  -203,     7,   266,   345,  -203,  -203,   381,
      16,   218,   267,   257,   258,   259,  -200,   220,   260,   221,
    -200,  -200,   261,   262,   263,   264,   208,   213,   265,   215,
       7,   266,   257,   258,   259,  -202,   222,   260,   267,  -202,
    -202,   261,    73,    74,    75,   223,   251,    76,   360,     7,
     266,    77,   249,    73,    74,    75,   280,   267,    76,    73,
      74,    75,    77,   469,    76,  -204,   281,   203,    77,  -204,
    -204,   292,   301,    91,     1,   143,     3,   297,   332,     5,
      26,    27,    28,     6,    98,    29,   333,   334,   335,    30,
     104,     7,     1,    36,     3,   336,     4,     5,     1,    32,
       3,     6,   126,     5,   127,   337,   128,     6,   387,     7,
     375,     1,    70,     3,   249,     7,     5,   390,   258,   259,
       6,   338,   260,   340,   133,   134,   261,  -201,     7,   343,
     348,  -201,  -201,   362,     7,   236,   237,   238,   239,   240,
     241,   394,   131,   132,   133,   134,   403,   300,   236,   237,
     238,   239,   240,   241,   414,   131,   132,   133,   134,   415,
     190,   236,   237,   238,   239,   240,   241,   419,   242,   243,
     244,   245,   236,   237,   238,   239,   240,   241,   428,   131,
     132,   133,   134,    26,    66,    28,   429,   433,    29,    26,
      69,    28,    30,   434,    29,    26,   117,    28,    30,   435,
      29,    73,    74,    75,    30,  -208,    76,   438,   439,  -208,
      77,   131,   132,   133,   134,   440,   457,   444,   141,   131,
     132,   133,   134,  -213,   458,   445,   150,  -213,   131,   132,
     133,   134,   471,   476,   446,   154,   131,   132,   133,   134,
     369,   509,   450,   214,   131,   132,   133,   134,   451,   454,
     171,   250,   131,   132,   133,   134,   477,   492,   478,   326,
     131,   132,   133,   134,   505,   514,   494,   350,   131,   132,
     133,   134,    38,   204,   496,   352,   131,   132,   133,   134,
     510,    39,   511,   354,   131,   132,   133,   134,     0,     0,
       0,   355,   131,   132,   133,   134,     0,     0,     0,   361,
     131,   132,   133,   134,     0,     0,     0,   425,   131,   132,
     133,   134,     0,     0,     0,   453,   131,   132,   133,   134,
       0,     0,     0,   482,   131,   132,   133,   134,     0,     0,
       0,   497,   131,   132,   133,   134,     0,     0,     0,   498,
     131,   132,   133,   134,     0,     0,     0,   515,   131,   132,
     133,   134,     0,     0,     0,   517,   420,  -176,   421,     0,
     422,     0,  -176,   126,  -192,   489,     0,   490,     0,  -192,
     501,  -168,   502,     0,   503,     0,  -168,   131,   132,   133,
     134,     0,   190,   131,   132,   133,   134,     0,   252,   131,
     132,   133,   134,     0,   363,   372,  -218,   373,     0,   374,
    -218,   131,   132,   133,   134,     0,   300,   126,   436,   437,
       0,   128,   126,   441,   442,   424,   443,   447,  -224,   249,
     452,   249,  -224,  -210,   249,  -223,  -217,  -210,   481,  -223,
    -217,   491,   249,   500,  -225,   249,   516,   249,  -225,     0,
     249,   242,   243,   244,   245
};

static const yytype_int16 yycheck[] =
{
      42,   272,    44,     0,   249,   151,    48,     5,   272,     9,
      52,     5,     5,    55,    11,   226,    13,     5,   179,    11,
     169,     6,     7,     8,     9,    10,    11,    11,     5,    14,
       8,     9,    11,    33,     5,     5,     5,    37,    17,     5,
     251,    38,    84,    41,    11,    43,   195,    41,    41,    43,
      43,   200,    11,    41,    11,    43,    41,   206,    17,    43,
      17,     5,   211,    48,    41,   107,   108,   216,   217,   230,
     219,    71,    43,    43,    43,    11,   225,    43,     6,     7,
       8,     9,   327,    11,    11,   127,     0,   129,   249,   131,
     132,   133,   134,    11,    94,   340,   235,    94,   343,    43,
      47,     6,     7,     8,     9,   254,    11,   246,   247,    47,
      38,     8,     9,    41,     6,     7,   265,    42,   329,    11,
      48,    46,     6,     7,     8,     9,   275,    11,    41,   278,
       6,     7,     5,    38,   283,    11,    41,   179,    11,   288,
      41,   290,   291,    48,    41,   145,    38,    11,   145,    41,
      11,   362,    13,    17,   315,   197,   317,    41,     8,     9,
     202,   372,    38,    47,    48,    41,   208,   431,    41,    11,
      43,   213,    45,   215,    11,   336,   337,    38,    11,   340,
      17,   426,   343,    41,    42,   227,    42,   229,   230,    47,
      46,    41,   338,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     6,     7,    11,   420,
     359,    11,    42,   458,    12,    42,   427,    47,    16,    46,
      47,   492,    20,    18,    19,   364,   365,   366,   367,   368,
     391,    10,    11,    11,     6,     7,     8,     9,    10,    11,
      11,    41,    14,   454,    41,    42,   407,    42,   409,    11,
      47,     6,     7,     8,     9,    10,    11,    42,    11,    14,
      47,    46,    47,     6,     7,     8,     9,    10,    11,    41,
      42,    14,    11,   315,   435,   317,    48,    47,    17,   428,
     429,    37,    38,    39,    40,   327,    41,    42,   330,    14,
     501,    47,    42,    48,   336,   337,    43,    47,    41,    42,
      47,    11,    12,    13,    51,    48,    16,    54,     8,     9,
      20,     6,     7,     8,     9,    10,    11,    10,    11,    14,
     469,    11,   364,   365,   366,   367,   368,    17,    42,    18,
      19,   373,    42,    11,    12,    13,    42,     3,    16,   381,
      46,   338,    20,   492,    11,   494,    41,    42,    42,   391,
      17,     5,    46,    48,     6,     7,     8,     9,    10,    11,
      41,    42,    14,     3,    42,   407,    47,   409,     6,     7,
       8,     9,    10,    11,    42,     5,    14,    41,    46,   421,
      42,    21,    22,    23,   426,    47,    26,     7,    41,    41,
      42,    11,   434,   435,    41,   437,    48,    41,    42,    43,
     442,    45,    46,    41,    42,    41,     6,     7,     8,     9,
      48,    11,    37,    38,    39,    40,   458,     6,     7,     8,
       9,    10,    11,    39,    40,    14,     6,     7,     8,     9,
      10,    11,    18,    19,    14,     6,     7,     8,     9,    10,
      11,    41,     4,    14,    41,    42,    41,   489,    48,    11,
      12,    13,    41,    42,    16,    11,    41,    41,    20,    48,
     502,    41,     6,     7,     8,     9,    28,    11,    48,    11,
      41,     6,     7,     8,     9,    11,    11,    48,    42,     6,
       7,     8,     9,    47,    11,     6,     7,     8,     9,    11,
      11,     6,     7,     8,     9,    42,    11,    41,    11,    46,
       6,     7,     8,     9,    48,    11,    41,    11,    12,    13,
      42,    15,    16,    48,    41,    47,    20,    43,    42,    42,
      41,    48,    39,    40,    28,    42,    41,    48,    42,    46,
      47,    41,    46,    48,    42,    41,     6,     7,     8,     9,
      10,    11,    48,    41,    14,     6,     7,     8,     9,    10,
      11,    41,    43,    14,     6,     7,     8,     9,    10,    11,
       4,    11,    14,    37,    38,    39,    40,    11,    12,    13,
      44,    41,    16,     3,    43,    43,    20,    21,    22,    23,
      41,    47,    26,    42,    28,    29,     4,    46,    47,    41,
      11,    42,    36,    11,    12,    13,    42,    42,    16,    42,
      46,    47,    20,    21,    22,    23,    43,    43,    26,    43,
      28,    29,    11,    12,    13,    42,    41,    16,    36,    46,
      47,    20,    11,    12,    13,    44,    41,    16,    42,    28,
      29,    20,    46,    11,    12,    13,    44,    36,    16,    11,
      12,    13,    20,    42,    16,    42,    44,     4,    20,    46,
      47,    42,    42,    42,    11,    12,    13,    11,    11,    16,
      11,    12,    13,    20,    42,    16,    11,    11,    11,    20,
      42,    28,    11,    12,    13,    41,    15,    16,    11,    12,
      13,    20,    41,    16,    43,    41,    45,    20,    11,    28,
      42,    11,    12,    13,    46,    28,    16,    11,    12,    13,
      20,    41,    16,    41,    39,    40,    20,    42,    28,    41,
      47,    46,    47,    41,    28,    30,    31,    32,    33,    34,
      35,    22,    37,    38,    39,    40,    47,    42,    30,    31,
      32,    33,    34,    35,    42,    37,    38,    39,    40,    42,
      42,    30,    31,    32,    33,    34,    35,    11,    37,    38,
      39,    40,    30,    31,    32,    33,    34,    35,    42,    37,
      38,    39,    40,    11,    12,    13,    42,    47,    16,    11,
      12,    13,    20,     5,    16,    11,    12,    13,    20,    41,
      16,    11,    12,    13,    20,    42,    16,    42,    42,    46,
      20,    37,    38,    39,    40,    42,    11,    42,    44,    37,
      38,    39,    40,    42,     5,    42,    44,    46,    37,    38,
      39,    40,    47,    11,    42,    44,    37,    38,    39,    40,
      42,    47,    42,    44,    37,    38,    39,    40,    42,    41,
     125,    44,    37,    38,    39,    40,    42,    27,    42,    44,
      37,    38,    39,    40,    11,    11,    42,    44,    37,    38,
      39,    40,    13,   145,    42,    44,    37,    38,    39,    40,
      42,    13,    42,    44,    37,    38,    39,    40,    -1,    -1,
      -1,    44,    37,    38,    39,    40,    -1,    -1,    -1,    44,
      37,    38,    39,    40,    -1,    -1,    -1,    44,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    37,    38,    39,    40,
      -1,    -1,    -1,    44,    37,    38,    39,    40,    -1,    -1,
      -1,    44,    37,    38,    39,    40,    -1,    -1,    -1,    44,
      37,    38,    39,    40,    -1,    -1,    -1,    44,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    41,    42,    43,    -1,
      45,    -1,    47,    41,    42,    43,    -1,    45,    -1,    47,
      41,    42,    43,    -1,    45,    -1,    47,    37,    38,    39,
      40,    -1,    42,    37,    38,    39,    40,    -1,    42,    37,
      38,    39,    40,    -1,    42,    41,    42,    43,    -1,    45,
      46,    37,    38,    39,    40,    -1,    42,    41,    42,    43,
      -1,    45,    41,    42,    43,    42,    45,    42,    42,    46,
      42,    46,    46,    42,    46,    42,    42,    46,    42,    46,
      46,    42,    46,    42,    42,    46,    42,    46,    46,    -1,
      46,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    13,    15,    16,    20,    28,    50,    67,
      68,    94,    98,   100,   101,    11,    11,    17,    11,    11,
      11,    11,    12,    16,    20,     0,    11,    12,    13,    16,
      20,    68,    12,    67,   101,    47,    12,    67,    94,    98,
      47,    41,     5,    41,    43,    41,     5,    41,    43,    99,
       5,    41,    43,     5,    41,    43,    11,    11,    11,    11,
      11,    17,    11,    11,    11,    17,    12,    47,    17,    12,
      12,    67,    47,    11,    12,    13,    16,    20,    42,    65,
      66,     6,     7,    11,    41,    64,    42,    65,    64,    42,
      14,    42,    65,    64,     3,    97,     8,     9,    42,    65,
      64,    10,    11,   104,    42,    65,    64,     5,    43,     5,
       5,    41,    41,    17,    41,    17,    17,    12,    11,    11,
      11,    11,    11,    87,    42,    46,    41,    43,    45,    38,
      64,    37,    38,    39,    40,    79,    42,    44,    58,    83,
      42,    44,     4,    12,    68,    95,    96,   101,    81,    42,
      44,    43,    85,    42,    44,    64,    64,     8,     9,    10,
      11,    42,    42,    41,    42,    41,    41,    17,    43,    88,
      77,    66,     6,     7,     8,     9,    10,    11,    14,    41,
      42,    48,    64,    92,    93,   106,   107,    64,    11,    64,
      42,    64,    64,    64,    64,    80,    69,    43,     3,   102,
      84,    73,    43,     4,    96,    47,    82,    71,    43,     7,
     104,    86,    75,    43,    44,    43,    57,    55,    42,    54,
      42,    42,    41,    44,   102,    78,    41,    43,    45,    38,
      41,    64,    92,     8,     9,    41,    30,    31,    32,    33,
      34,    35,    37,    38,    39,    40,    18,    19,    42,    46,
      44,    41,    42,   102,    70,    64,     4,    11,    12,    13,
      16,    20,    21,    22,    23,    26,    29,    36,    59,    60,
      89,   101,   103,   105,   102,    74,    64,   102,    72,    64,
      44,    44,   102,    76,    64,    64,   102,   102,    56,   102,
      52,    53,    42,   102,    42,   107,    64,    11,    64,    64,
      42,    42,    48,    64,    93,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    41,    93,    41,    93,    10,
      11,    14,    92,   106,   107,   102,    44,     5,    11,    41,
      43,    45,    11,    11,    11,    11,    41,    41,    41,   102,
      41,    61,    63,    41,    62,     4,    89,   105,    47,   102,
      44,   102,    44,   102,    44,    44,   102,   102,   102,    51,
      42,    44,    41,    42,    18,    19,    41,    18,    19,    42,
      92,    92,    41,    43,    45,    42,     8,     9,    10,    11,
      14,    41,    64,   106,    42,   107,    64,    11,    92,    92,
      11,    90,   101,   104,    22,    11,    92,   106,    10,    11,
      14,    92,   106,    47,   102,    42,   107,    41,    93,    41,
      93,    93,    93,    93,    42,    42,    42,   107,    64,    11,
      41,    43,    45,    64,    42,    44,     5,    41,    42,    42,
      47,    91,    92,    47,     5,    41,    42,    43,    42,    42,
      42,    42,    43,    45,    42,    42,    42,    42,    92,    92,
      42,    42,    42,    44,    41,   107,    64,    11,     5,     8,
       9,    10,    11,    14,   106,    42,   107,   102,   102,    42,
     105,    47,    64,    92,    64,    64,    11,    42,    42,    42,
     107,    42,    44,     8,     9,    10,    11,    14,   106,    43,
      45,    42,    27,   102,    42,    47,    42,    44,    44,    42,
      42,    41,    43,    45,    64,    11,    89,   102,   102,    47,
      42,    42,   107,    64,    11,    44,    42,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    51,    50,    52,    50,    53,    50,    54,    50,
      55,    50,    56,    50,    57,    50,    58,    50,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    61,    62,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    67,    67,    69,    70,    68,    71,
      72,    68,    73,    74,    68,    75,    76,    68,    77,    78,
      68,    79,    80,    68,    81,    82,    68,    83,    84,    68,
      85,    86,    68,    87,    88,    68,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    99,    98,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   102,   102,   103,
     103,   103,   103,   104,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     0,     8,     0,     8,     0,     7,
       0,     7,     0,     8,     0,     7,     0,     6,     2,     4,
       4,     4,     4,     7,     6,     2,     4,     1,     3,     3,
       3,     6,     3,     3,     3,     3,     3,     4,     1,     1,
       1,     4,     4,     3,     3,     6,     1,     3,     2,     4,
       2,     2,     2,     2,     1,     2,     0,     0,     8,     0,
       0,     8,     0,     0,     8,     0,     0,     8,     0,     0,
       8,     0,     0,     7,     0,     0,     7,     0,     0,     7,
       0,     0,     7,     0,     0,     7,     5,     7,     7,     5,
       7,     7,     6,     2,     4,     2,     1,     3,     1,     3,
       3,     6,     6,     5,     5,     5,     5,     7,     7,     4,
       3,     3,     3,     3,     3,     3,     1,     2,     1,     2,
       2,     3,     1,     2,     2,     1,     3,     2,     0,     4,
       2,     3,     8,     8,     8,     8,     2,     4,     5,     4,
       4,     8,     2,     5,     6,     5,     5,     5,     5,     2,
       4,     2,     4,     4,     5,     5,     2,     3,     2,     2,
       1,     2,     3,     4,     4,     1,     1,     6,     6,     9,
       3,     6,     6,     6,     6,     3,     3,     3,     3,     3,
       6,     9,     4,     3,     6,     1,     1,     5,     5,     5,
       5,     5,     5,     8,     7,     5,     8,     6,     5,     3,
       3,     3,     3,     3,     4,     1,     1,     1,     4,     3,
       6,     5,     1,     4,     1,     1,     1,     6,     3,     3,
       3,     3,     3,     6,     5,     8,     7
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
  case 2: /* $@1: %empty  */
#line 57 "limbaj.y"
                                                                               {strcpy(domain,"main");}
#line 1627 "limbaj.tab.c"
    break;

  case 3: /* progr: userDefinedDeclarations declarations functions TYPE ENTRY_POINT '(' ')' $@1 block  */
#line 57 "limbaj.y"
                                                                                                             {printf("End\n"); }
#line 1633 "limbaj.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 58 "limbaj.y"
                                                                   {strcpy(domain,"main");}
#line 1639 "limbaj.tab.c"
    break;

  case 5: /* progr: userDefinedDeclarations functions TYPE ENTRY_POINT '(' ')' $@2 block  */
#line 58 "limbaj.y"
                                                                                                  {printf("End\n");}
#line 1645 "limbaj.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 59 "limbaj.y"
                                                                     {strcpy(domain,"main");}
#line 1651 "limbaj.tab.c"
    break;

  case 7: /* progr: userDefinedDeclarations declarations TYPE ENTRY_POINT '(' ')' $@3 block  */
#line 59 "limbaj.y"
                                                                                                    {printf("End\n");}
#line 1657 "limbaj.tab.c"
    break;

  case 8: /* $@4: %empty  */
#line 60 "limbaj.y"
                                                       {strcpy(domain,"main");}
#line 1663 "limbaj.tab.c"
    break;

  case 9: /* progr: userDefinedDeclarations TYPE ENTRY_POINT '(' ')' $@4 block  */
#line 60 "limbaj.y"
                                                                                      {printf("End\n");}
#line 1669 "limbaj.tab.c"
    break;

  case 10: /* $@5: %empty  */
#line 61 "limbaj.y"
                                             {strcpy(domain,"main");}
#line 1675 "limbaj.tab.c"
    break;

  case 11: /* progr: declarations TYPE ENTRY_POINT '(' ')' $@5 block  */
#line 61 "limbaj.y"
                                                                             {printf("End\n");}
#line 1681 "limbaj.tab.c"
    break;

  case 12: /* $@6: %empty  */
#line 62 "limbaj.y"
                                                       {strcpy(domain,"main");}
#line 1687 "limbaj.tab.c"
    break;

  case 13: /* progr: declarations functions TYPE ENTRY_POINT '(' ')' $@6 block  */
#line 62 "limbaj.y"
                                                                                      {printf("End\n");}
#line 1693 "limbaj.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 63 "limbaj.y"
                                         {strcpy(domain,"main");}
#line 1699 "limbaj.tab.c"
    break;

  case 15: /* progr: functions TYPE ENTRY_POINT '(' ')' $@7 block  */
#line 63 "limbaj.y"
                                                                          {printf("End\n");}
#line 1705 "limbaj.tab.c"
    break;

  case 16: /* $@8: %empty  */
#line 64 "limbaj.y"
                               {strcpy(domain,"main");}
#line 1711 "limbaj.tab.c"
    break;

  case 17: /* progr: TYPE ENTRY_POINT '(' ')' $@8 block  */
#line 64 "limbaj.y"
                                                               {printf("End\n");}
#line 1717 "limbaj.tab.c"
    break;

  case 18: /* typeoffunc: TYPEOF evalAritFuncFT  */
#line 67 "limbaj.y"
                                   {cout <<"Arithmetic expression"; if((yyvsp[0].floatValue)==(int)(yyvsp[0].floatValue))cout<<" of type int"<<endl; else cout<<" of type float"<<endl;}
#line 1723 "limbaj.tab.c"
    break;

  case 19: /* typeoffunc: TYPEOF '(' bExp ')'  */
#line 68 "limbaj.y"
                                 {cout <<"boolean"<<endl;}
#line 1729 "limbaj.tab.c"
    break;

  case 20: /* typeoffunc: TYPEOF '(' CHARACTER ')'  */
#line 69 "limbaj.y"
                                      {cout <<"char"<<endl;}
#line 1735 "limbaj.tab.c"
    break;

  case 21: /* typeoffunc: TYPEOF '(' STRING_TEXT ')'  */
#line 70 "limbaj.y"
                                        {cout <<"string"<<endl;}
#line 1741 "limbaj.tab.c"
    break;

  case 22: /* typeoffunc: TYPEOF '(' ID ')'  */
#line 71 "limbaj.y"
                               {if(!ids.existsVar((yyvsp[-1].string)))yyerror("variable does not exist");
                                   cout<<ids.getType((yyvsp[-1].string))<<endl;
                                   }
#line 1749 "limbaj.tab.c"
    break;

  case 23: /* typeoffunc: TYPEOF '(' ID '[' e ']' ')'  */
#line 74 "limbaj.y"
                                      {if(!ids.existsVar((yyvsp[-4].string)))yyerror("variable does not exist");
                                   cout<<ids.getType((yyvsp[-4].string))<<endl;
                                   }
#line 1757 "limbaj.tab.c"
    break;

  case 24: /* typeoffunc: TYPEOF '(' ID '.' ID ')'  */
#line 77 "limbaj.y"
                                     {if(!ids.existsVar((yyvsp[-1].string)))yyerror("variable does not exist");
                                   cout<<ids.getType((yyvsp[-1].string))<<endl;
                                   }
#line 1765 "limbaj.tab.c"
    break;

  case 26: /* evalFunc: EVAL '(' bExp ')'  */
#line 81 "limbaj.y"
                             {cout <<"Valoarea expresiei:" <<boolalpha<< (yyvsp[-1].boolValue) << endl;}
#line 1771 "limbaj.tab.c"
    break;

  case 27: /* evalForType: evalAritFunc  */
#line 82 "limbaj.y"
                           {(yyval.floatValue)=(yyvsp[0].floatValue);  cout <<"Valoarea expresiei:" << (yyval.floatValue) << endl;}
#line 1777 "limbaj.tab.c"
    break;

  case 28: /* evalAritFuncFT: '(' onlyExp ')'  */
#line 83 "limbaj.y"
                                {(yyval.floatValue)=(yyvsp[-1].floatValue);}
#line 1783 "limbaj.tab.c"
    break;

  case 29: /* evalAritFunc: '(' onlyExp ')'  */
#line 84 "limbaj.y"
                              {(yyval.floatValue)=(yyvsp[-1].floatValue);}
#line 1789 "limbaj.tab.c"
    break;

  case 30: /* evalAritFunc: '(' ID ')'  */
#line 85 "limbaj.y"
                         {(yyval.floatValue)=ids.getValueFloat((yyvsp[-1].string)); }
#line 1795 "limbaj.tab.c"
    break;

  case 31: /* evalAritFunc: '(' ID '[' e ']' ')'  */
#line 86 "limbaj.y"
                                    {     string val=ids.getValueIndex((yyvsp[-4].string),(yyvsp[-2].floatValue)); 
                          (yyval.floatValue)=stof(val);
                         if(!ids.existsVar((yyvsp[-4].string)))
                         {yyerror("variable is not declared in this scope");}
                         
                    }
#line 1806 "limbaj.tab.c"
    break;

  case 32: /* e: e '+' e  */
#line 92 "limbaj.y"
              {(yyval.floatValue)=(yyvsp[-2].floatValue)+(yyvsp[0].floatValue);}
#line 1812 "limbaj.tab.c"
    break;

  case 33: /* e: e '*' e  */
#line 93 "limbaj.y"
              {(yyval.floatValue)=(yyvsp[-2].floatValue)*(yyvsp[0].floatValue);}
#line 1818 "limbaj.tab.c"
    break;

  case 34: /* e: e '-' e  */
#line 94 "limbaj.y"
              {(yyval.floatValue)=(yyvsp[-2].floatValue)-(yyvsp[0].floatValue);}
#line 1824 "limbaj.tab.c"
    break;

  case 35: /* e: e '/' e  */
#line 95 "limbaj.y"
              {(yyval.floatValue)=(yyvsp[-2].floatValue)/(yyvsp[0].floatValue);}
#line 1830 "limbaj.tab.c"
    break;

  case 36: /* e: '(' e ')'  */
#line 96 "limbaj.y"
             {(yyval.floatValue)= (yyvsp[-1].floatValue);}
#line 1836 "limbaj.tab.c"
    break;

  case 37: /* e: '(' '-' e ')'  */
#line 97 "limbaj.y"
                 {(yyval.floatValue)= -(yyvsp[-1].floatValue);}
#line 1842 "limbaj.tab.c"
    break;

  case 38: /* e: FLOAT_NR  */
#line 98 "limbaj.y"
             {(yyval.floatValue)=(yyvsp[0].floatValue);}
#line 1848 "limbaj.tab.c"
    break;

  case 39: /* e: NR  */
#line 99 "limbaj.y"
       {(yyval.floatValue)=(yyvsp[0].floatValue);}
#line 1854 "limbaj.tab.c"
    break;

  case 40: /* e: ID  */
#line 100 "limbaj.y"
       {(yyval.floatValue)=ids.getValueFloat((yyvsp[0].string)); }
#line 1860 "limbaj.tab.c"
    break;

  case 41: /* e: ID '[' e ']'  */
#line 101 "limbaj.y"
                 {     string val=ids.getValueIndex((yyvsp[-3].string),(yyvsp[-1].floatValue)); 
                         if(val == "")yyerror("No value on that position");
                          (yyval.floatValue)=stof(val);
                         if(!ids.existsVar((yyvsp[-3].string)))
                         {yyerror("variable is not declared in this scope");}
                         
                    }
#line 1872 "limbaj.tab.c"
    break;

  case 42: /* e: ID '(' call_list ')'  */
#line 108 "limbaj.y"
                        { 
                                   (yyval.floatValue)=0;
                                   if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                   }
                                   
                               }
#line 1887 "limbaj.tab.c"
    break;

  case 43: /* e: ID '(' ')'  */
#line 118 "limbaj.y"
                   { 
                                   (yyval.floatValue)=0;
                                   if(!fnc.existFunction((yyvsp[-2].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam((yyvsp[-2].string))==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                   }
                                   
                               }
#line 1904 "limbaj.tab.c"
    break;

  case 44: /* e: ID '.' ID  */
#line 130 "limbaj.y"
                {
          
          int i=ids.getIndex((yyvsp[0].string));
          string v=ids.getValueIndex((yyvsp[-2].string),i);
          if(stoi(v) || stof(v))
          {
               (yyval.floatValue)=stof(v);
          }
     }
#line 1918 "limbaj.tab.c"
    break;

  case 45: /* e: ID '.' ID '(' call_list ')'  */
#line 139 "limbaj.y"
                                   {
                                  
                                   if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        string funcDomain= fnc.getDomain((yyvsp[-3].string));
                                        if(!(ids.getType((yyvsp[-5].string)) == funcDomain))
                                        {
                                             yyerror("syntax error");
                                        }
                                   }
                                   if(!cls.existsClass(ids.getType((yyvsp[-5].string)).c_str()))
                                   {
                                        yyerror("class does not exist");
                                   }
                                    (yyval.floatValue)=0;
                               }
#line 1942 "limbaj.tab.c"
    break;

  case 46: /* list_param_inner: param  */
#line 161 "limbaj.y"
                         {(yyval.string)=(yyvsp[0].string);}
#line 1948 "limbaj.tab.c"
    break;

  case 47: /* list_param_inner: list_param_inner ',' param  */
#line 162 "limbaj.y"
                                          {strcat((yyval.string),(yyvsp[0].string));}
#line 1954 "limbaj.tab.c"
    break;

  case 48: /* param: TYPE ID  */
#line 165 "limbaj.y"
                {sprintf((yyval.string),"%s %s ", (yyvsp[-1].string), (yyvsp[0].string));}
#line 1960 "limbaj.tab.c"
    break;

  case 49: /* param: TYPE ID '[' ']'  */
#line 166 "limbaj.y"
                        {sprintf((yyval.string),"%s %s ", (yyvsp[-3].string), (yyvsp[-2].string));}
#line 1966 "limbaj.tab.c"
    break;

  case 50: /* param: STRING_TYPE ID  */
#line 167 "limbaj.y"
                       {sprintf((yyval.string),"%s %s ", (yyvsp[-1].string), (yyvsp[0].string));}
#line 1972 "limbaj.tab.c"
    break;

  case 51: /* param: CHAR_TYPE ID  */
#line 168 "limbaj.y"
                     {sprintf((yyval.string),"%s %s ", (yyvsp[-1].string), (yyvsp[0].string));}
#line 1978 "limbaj.tab.c"
    break;

  case 52: /* param: BOOL_TYPE ID  */
#line 169 "limbaj.y"
                     {sprintf((yyval.string),"%s %s ", (yyvsp[-1].string), (yyvsp[0].string));}
#line 1984 "limbaj.tab.c"
    break;

  case 53: /* param: ID ID  */
#line 170 "limbaj.y"
              {sprintf((yyval.string),"%s %s ", (yyvsp[-1].string), (yyvsp[0].string)); if(!cls.existsClass((yyvsp[-1].string)))yyerror("unknown variable type");}
#line 1990 "limbaj.tab.c"
    break;

  case 56: /* $@9: %empty  */
#line 174 "limbaj.y"
                                           {
                                       
                                   if(!fnc.existFunction((yyvsp[-3].string)))
                                    {
                                        fnc.addFunction((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-1].string));
                                      
                                        fnc.addDomain((yyvsp[-3].string), string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                   
                                   }
#line 2006 "limbaj.tab.c"
    break;

  case 57: /* $@10: %empty  */
#line 184 "limbaj.y"
                                     {strcpy(domain,(yyvsp[-4].string));}
#line 2012 "limbaj.tab.c"
    break;

  case 58: /* function: TYPE ID '(' list_param_inner ')' $@9 $@10 block  */
#line 184 "limbaj.y"
                                                                {strcpy(domain,"global");}
#line 2018 "limbaj.tab.c"
    break;

  case 59: /* $@11: %empty  */
#line 185 "limbaj.y"
                                                {
                                 
                                   if(!fnc.existFunction((yyvsp[-3].string)))
                                    {
                                        fnc.addFunction((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-1].string));
                                         fnc.addDomain((yyvsp[-3].string), string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                    
                                   }
#line 2033 "limbaj.tab.c"
    break;

  case 60: /* $@12: %empty  */
#line 194 "limbaj.y"
                                     {strcpy(domain,(yyvsp[-4].string));}
#line 2039 "limbaj.tab.c"
    break;

  case 61: /* function: BOOL_TYPE ID '(' list_param_inner ')' $@11 $@12 block  */
#line 194 "limbaj.y"
                                                                 {strcpy(domain,"global");}
#line 2045 "limbaj.tab.c"
    break;

  case 62: /* $@13: %empty  */
#line 195 "limbaj.y"
                                                    {
                                 
                                   if(!fnc.existFunction((yyvsp[-3].string)))
                                    {
                                        fnc.addFunction((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-1].string));
                                        fnc.addDomain((yyvsp[-3].string), string(domain));
                                    }else yyerror("function with this name already exists");
                                   }
#line 2058 "limbaj.tab.c"
    break;

  case 63: /* $@14: %empty  */
#line 202 "limbaj.y"
                                    {strcpy(domain,(yyvsp[-4].string));}
#line 2064 "limbaj.tab.c"
    break;

  case 64: /* function: STRING_TYPE ID '(' list_param_inner ')' $@13 $@14 block  */
#line 202 "limbaj.y"
                                                                {strcpy(domain,"global");}
#line 2070 "limbaj.tab.c"
    break;

  case 65: /* $@15: %empty  */
#line 203 "limbaj.y"
                                                    { 
                                                   if(!fnc.existFunction((yyvsp[-3].string)))
                                                   {
                                                      fnc.addFunction((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-1].string));
                                                       fnc.addDomain((yyvsp[-3].string), string(domain));
                                        
                                                    }else yyerror("function with this name already exists");
                                   
                                             }
#line 2084 "limbaj.tab.c"
    break;

  case 66: /* $@16: %empty  */
#line 211 "limbaj.y"
                                              {strcpy(domain,(yyvsp[-4].string));}
#line 2090 "limbaj.tab.c"
    break;

  case 67: /* function: CHAR_TYPE ID '(' list_param_inner ')' $@15 $@16 block  */
#line 211 "limbaj.y"
                                                                           {strcpy(domain,"global");}
#line 2096 "limbaj.tab.c"
    break;

  case 68: /* $@17: %empty  */
#line 212 "limbaj.y"
                                         {if(!cls.existsClass((yyvsp[-3].string)))yyerror("unknown variable type");
                                                        if(!fnc.existFunction((yyvsp[-3].string)))
                                                   {
                                                      fnc.addFunction((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-1].string));
                                                      fnc.addDomain((yyvsp[-3].string), string(domain));
                                                    }else yyerror("function with this name already exists");
                                                  }
#line 2108 "limbaj.tab.c"
    break;

  case 69: /* $@18: %empty  */
#line 218 "limbaj.y"
                                                    {strcpy(domain,(yyvsp[-4].string));}
#line 2114 "limbaj.tab.c"
    break;

  case 70: /* function: ID ID '(' list_param_inner ')' $@17 $@18 block  */
#line 218 "limbaj.y"
                                                                                  {strcpy(domain,"global");}
#line 2120 "limbaj.tab.c"
    break;

  case 71: /* $@19: %empty  */
#line 219 "limbaj.y"
                            {
                                   char sp[2]=" ";
                                   if(!fnc.existFunction((yyvsp[-2].string)))
                                    {
                                        fnc.addFunction((yyvsp[-3].string), (yyvsp[-2].string), sp);
                                         fnc.addDomain((yyvsp[-2].string), string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                   }
#line 2134 "limbaj.tab.c"
    break;

  case 72: /* $@20: %empty  */
#line 227 "limbaj.y"
                                    {strcpy(domain,(yyvsp[-3].string));}
#line 2140 "limbaj.tab.c"
    break;

  case 73: /* function: TYPE ID '(' ')' $@19 $@20 block  */
#line 227 "limbaj.y"
                                                                 {strcpy(domain,"global");}
#line 2146 "limbaj.tab.c"
    break;

  case 74: /* $@21: %empty  */
#line 228 "limbaj.y"
                               {
                                   char sp[2]=" ";
                                   if(!fnc.existFunction((yyvsp[-2].string)))
                                    {
                                        fnc.addFunction((yyvsp[-3].string), (yyvsp[-2].string), sp);
                                         fnc.addDomain((yyvsp[-2].string), string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                   }
#line 2160 "limbaj.tab.c"
    break;

  case 75: /* $@22: %empty  */
#line 236 "limbaj.y"
                                    {strcpy(domain,(yyvsp[-3].string));}
#line 2166 "limbaj.tab.c"
    break;

  case 76: /* function: BOOL_TYPE ID '(' ')' $@21 $@22 block  */
#line 236 "limbaj.y"
                                                                  {strcpy(domain,"global");}
#line 2172 "limbaj.tab.c"
    break;

  case 77: /* $@23: %empty  */
#line 237 "limbaj.y"
                                  {
                                   char sp[2]=" ";
                                   if(!fnc.existFunction((yyvsp[-2].string)))
                                    {
                                        fnc.addFunction((yyvsp[-3].string), (yyvsp[-2].string), sp);
                                        fnc.addDomain((yyvsp[-2].string), string(domain));
                                        
                                    }else yyerror("function with this name already exists");
                                   }
#line 2186 "limbaj.tab.c"
    break;

  case 78: /* $@24: %empty  */
#line 245 "limbaj.y"
                                    {strcpy(domain,(yyvsp[-3].string));}
#line 2192 "limbaj.tab.c"
    break;

  case 79: /* function: STRING_TYPE ID '(' ')' $@23 $@24 block  */
#line 245 "limbaj.y"
                                                                  {strcpy(domain,"global");}
#line 2198 "limbaj.tab.c"
    break;

  case 80: /* $@25: %empty  */
#line 246 "limbaj.y"
                               { 
                                        char sp[2]=" ";
                                                   if(!fnc.existFunction((yyvsp[-2].string)))
                                                   {
                                                      fnc.addFunction((yyvsp[-3].string), (yyvsp[-2].string), sp);
                                                      fnc.addDomain((yyvsp[-2].string), string(domain));
                                        
                                                    }else yyerror("function with this name already exists");
                                   
                                             }
#line 2213 "limbaj.tab.c"
    break;

  case 81: /* $@26: %empty  */
#line 255 "limbaj.y"
                                              {strcpy(domain,(yyvsp[-3].string));}
#line 2219 "limbaj.tab.c"
    break;

  case 82: /* function: CHAR_TYPE ID '(' ')' $@25 $@26 block  */
#line 255 "limbaj.y"
                                                                               {strcpy(domain,"global");}
#line 2225 "limbaj.tab.c"
    break;

  case 83: /* $@27: %empty  */
#line 256 "limbaj.y"
                         {if(!cls.existsClass((yyvsp[-2].string)))yyerror("unknown variable type");
                                             char sp[2]=" ";
                                                        if(!fnc.existFunction((yyvsp[-2].string)))
                                                   {
                                                      fnc.addFunction((yyvsp[-3].string), (yyvsp[-2].string), sp);
                                                       fnc.addDomain((yyvsp[-2].string), string(domain));
                                                    }else yyerror("function with this name already exists");
                                                  }
#line 2238 "limbaj.tab.c"
    break;

  case 84: /* $@28: %empty  */
#line 263 "limbaj.y"
                                                   {strcpy(domain,(yyvsp[-3].string));}
#line 2244 "limbaj.tab.c"
    break;

  case 85: /* function: ID ID '(' ')' $@27 $@28 block  */
#line 263 "limbaj.y"
                                                                               {strcpy(domain,"global");}
#line 2250 "limbaj.tab.c"
    break;

  case 97: /* bExp: '(' bExp ')'  */
#line 282 "limbaj.y"
                    {(yyval.boolValue)=(yyvsp[-1].boolValue);}
#line 2256 "limbaj.tab.c"
    break;

  case 98: /* bExp: bExpForm  */
#line 283 "limbaj.y"
                {if((yyvsp[0].boolValue)==0)(yyval.boolValue)=false; else (yyval.boolValue)=true;}
#line 2262 "limbaj.tab.c"
    break;

  case 99: /* bExp: bExpForm LOGIC_OR bExpForm  */
#line 284 "limbaj.y"
                                  {if((yyvsp[-2].boolValue) || (yyvsp[0].boolValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2268 "limbaj.tab.c"
    break;

  case 100: /* bExp: bExpForm LOGIC_AND bExpForm  */
#line 285 "limbaj.y"
                                  {if((yyvsp[-2].boolValue) && (yyvsp[0].boolValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2274 "limbaj.tab.c"
    break;

  case 101: /* bExp: '!' '(' bExpForm LOGIC_OR bExpForm ')'  */
#line 286 "limbaj.y"
                                            {if((yyvsp[-3].boolValue)||(yyvsp[-1].boolValue))(yyval.boolValue)=false; else (yyval.boolValue)=true;}
#line 2280 "limbaj.tab.c"
    break;

  case 102: /* bExp: '!' '(' bExpForm LOGIC_AND bExpForm ')'  */
#line 287 "limbaj.y"
                                             {if((yyvsp[-3].boolValue)&&(yyvsp[-1].boolValue))(yyval.boolValue)=false; else (yyval.boolValue)=true;}
#line 2286 "limbaj.tab.c"
    break;

  case 103: /* bExp: '(' bExp ')' LOGIC_AND bExpForm  */
#line 288 "limbaj.y"
                                       {if((yyvsp[-3].boolValue) && (yyvsp[0].boolValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2292 "limbaj.tab.c"
    break;

  case 104: /* bExp: '(' bExp ')' LOGIC_OR bExpForm  */
#line 289 "limbaj.y"
                                      {if((yyvsp[-3].boolValue) || (yyvsp[0].boolValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2298 "limbaj.tab.c"
    break;

  case 105: /* bExp: bExpForm LOGIC_AND '(' bExp ')'  */
#line 290 "limbaj.y"
                                       {if((yyvsp[-4].boolValue) && (yyvsp[-1].boolValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2304 "limbaj.tab.c"
    break;

  case 106: /* bExp: bExpForm LOGIC_OR '(' bExp ')'  */
#line 291 "limbaj.y"
                                       {if((yyvsp[-4].boolValue) || (yyvsp[-1].boolValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2310 "limbaj.tab.c"
    break;

  case 107: /* bExp: '(' bExp ')' LOGIC_OR '(' bExp ')'  */
#line 292 "limbaj.y"
                                          {if((yyvsp[-5].boolValue) || (yyvsp[-1].boolValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2316 "limbaj.tab.c"
    break;

  case 108: /* bExp: '(' bExp ')' LOGIC_AND '(' bExp ')'  */
#line 293 "limbaj.y"
                                           {if((yyvsp[-5].boolValue) && (yyvsp[-1].boolValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2322 "limbaj.tab.c"
    break;

  case 109: /* bExpForm: '!' '(' bExpForm ')'  */
#line 296 "limbaj.y"
                                     {if((yyvsp[-1].boolValue)==0)(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2328 "limbaj.tab.c"
    break;

  case 110: /* bExpForm: e BOOL_E e  */
#line 297 "limbaj.y"
                               {if((yyvsp[-2].floatValue)==(yyvsp[0].floatValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2334 "limbaj.tab.c"
    break;

  case 111: /* bExpForm: e BOOL_LTE e  */
#line 298 "limbaj.y"
                                 {if((yyvsp[-2].floatValue)<=(yyvsp[0].floatValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2340 "limbaj.tab.c"
    break;

  case 112: /* bExpForm: e BOOL_GTE e  */
#line 299 "limbaj.y"
                                 {if((yyvsp[-2].floatValue)>=(yyvsp[0].floatValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2346 "limbaj.tab.c"
    break;

  case 113: /* bExpForm: e BOOL_NE e  */
#line 300 "limbaj.y"
                                {if((yyvsp[-2].floatValue)!=(yyvsp[0].floatValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2352 "limbaj.tab.c"
    break;

  case 114: /* bExpForm: e BOOL_LT e  */
#line 301 "limbaj.y"
                                {if((yyvsp[-2].floatValue)<(yyvsp[0].floatValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2358 "limbaj.tab.c"
    break;

  case 115: /* bExpForm: e BOOL_GT e  */
#line 302 "limbaj.y"
                                {if((yyvsp[-2].floatValue)>(yyvsp[0].floatValue))(yyval.boolValue)=true; else (yyval.boolValue)=false;}
#line 2364 "limbaj.tab.c"
    break;

  case 116: /* bExpForm: BOOL_TRUE  */
#line 303 "limbaj.y"
                              {(yyval.boolValue)=true;}
#line 2370 "limbaj.tab.c"
    break;

  case 117: /* bExpForm: '!' BOOL_FALSE  */
#line 304 "limbaj.y"
                                   {(yyval.boolValue)=true;}
#line 2376 "limbaj.tab.c"
    break;

  case 118: /* bExpForm: BOOL_FALSE  */
#line 305 "limbaj.y"
                               {(yyval.boolValue)=false;}
#line 2382 "limbaj.tab.c"
    break;

  case 119: /* bExpForm: '!' BOOL_TRUE  */
#line 306 "limbaj.y"
                                  {(yyval.boolValue)=false;}
#line 2388 "limbaj.tab.c"
    break;

  case 124: /* classLine: decl ';'  */
#line 314 "limbaj.y"
                     {ind=ind+1;}
#line 2394 "limbaj.tab.c"
    break;

  case 128: /* $@29: %empty  */
#line 319 "limbaj.y"
                            {strcpy(domain,(yyvsp[0].string)); isClass=1; ind=0;}
#line 2400 "limbaj.tab.c"
    break;

  case 129: /* classDeclaration: CLASS ID $@29 declarationBlockForClass  */
#line 319 "limbaj.y"
                                                                                            {
                         cls.addNewClass((yyvsp[-2].string));
                         cls.setSize((yyvsp[-2].string), ind);
                         ind=0;
                         isClass=0;
                         strcpy(domain,"global");
                    }
#line 2412 "limbaj.tab.c"
    break;

  case 132: /* decl: TYPE ID '[' e ']' '[' e ']'  */
#line 331 "limbaj.y"
                                    { string s1=(yyvsp[-6].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-6].string))) {
                          ids.addVar((yyvsp[-7].string),(yyvsp[-6].string),false);
                          ids.addDomain((yyvsp[-6].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-6].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
#line 2428 "limbaj.tab.c"
    break;

  case 133: /* decl: STRING_TYPE ID '[' e ']' '[' e ']'  */
#line 342 "limbaj.y"
                                         { string s1=(yyvsp[-6].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-6].string))) {
                          ids.addVar((yyvsp[-7].string),(yyvsp[-6].string),false);
                          ids.addDomain((yyvsp[-6].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-6].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
#line 2444 "limbaj.tab.c"
    break;

  case 134: /* decl: CHAR_TYPE ID '[' e ']' '[' e ']'  */
#line 353 "limbaj.y"
                                       { string s1=(yyvsp[-6].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-6].string))) {
                          ids.addVar((yyvsp[-7].string),(yyvsp[-6].string),false);
                          ids.addDomain((yyvsp[-6].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-6].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
#line 2460 "limbaj.tab.c"
    break;

  case 135: /* decl: BOOL_TYPE ID '[' e ']' '[' e ']'  */
#line 364 "limbaj.y"
                                       { string s1=(yyvsp[-6].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-6].string))) {
                          ids.addVar((yyvsp[-7].string),(yyvsp[-6].string),false);
                          ids.addDomain((yyvsp[-6].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-6].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
#line 2476 "limbaj.tab.c"
    break;

  case 136: /* decl: TYPE ID  */
#line 375 "limbaj.y"
                   { string s1=(yyvsp[0].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[0].string))) {
                          ids.addVar((yyvsp[-1].string),(yyvsp[0].string),false);
                          ids.addDomain((yyvsp[0].string), domain);
                          if(isClass)ids.setIndex((yyvsp[0].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                     
                    }
#line 2492 "limbaj.tab.c"
    break;

  case 137: /* decl: TYPE ID ASSIGN e  */
#line 386 "limbaj.y"
                              { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                 
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),false, to_string((yyvsp[0].floatValue)).c_str());
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}

                    }
#line 2507 "limbaj.tab.c"
    break;

  case 138: /* decl: CONST TYPE ID ASSIGN e  */
#line 396 "limbaj.y"
                                   { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),true, to_string((yyvsp[0].floatValue)).c_str());
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2521 "limbaj.tab.c"
    break;

  case 139: /* decl: CHAR_TYPE ID ASSIGN CHARACTER  */
#line 405 "limbaj.y"
                                           { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),false, (yyvsp[0].string));
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2535 "limbaj.tab.c"
    break;

  case 140: /* decl: CHAR_TYPE ID ASSIGN idVar  */
#line 414 "limbaj.y"
                                       { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                         if(ids.haveSameTypeWithVar((yyvsp[-3].string),(yyvsp[0].string)))
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),false, (yyvsp[0].string));
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2550 "limbaj.tab.c"
    break;

  case 141: /* decl: CONST CHAR_TYPE ID ASSIGN ID '[' e ']'  */
#line 424 "limbaj.y"
                                                     { string s1=(yyvsp[-6].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-5].string))) {
                         if(ids.haveSameTypeWithVar((yyvsp[-6].string),(yyvsp[-3].string)))
                          ids.addVar((yyvsp[-6].string),(yyvsp[-5].string),true, ids.getValueIndex((yyvsp[-3].string),(yyvsp[-1].floatValue)).c_str());
                          ids.addDomain((yyvsp[-5].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-5].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2565 "limbaj.tab.c"
    break;

  case 142: /* decl: CHAR_TYPE ID  */
#line 434 "limbaj.y"
                           { string s1=(yyvsp[0].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[0].string))) {
                          ids.addVar((yyvsp[-1].string),(yyvsp[0].string),false);
                          ids.addDomain((yyvsp[0].string), domain);
                          if(isClass)ids.setIndex((yyvsp[0].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2579 "limbaj.tab.c"
    break;

  case 143: /* decl: CONST CHAR_TYPE ID ASSIGN CHARACTER  */
#line 443 "limbaj.y"
                                                { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),true, (yyvsp[0].string));
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2593 "limbaj.tab.c"
    break;

  case 144: /* decl: CONST TYPE ID '[' e ']'  */
#line 453 "limbaj.y"
                                    { string s1=(yyvsp[-3].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-3].string))) {
                          ids.addVar((yyvsp[-4].string),(yyvsp[-3].string),false);
                          ids.addDomain((yyvsp[-3].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-3].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2607 "limbaj.tab.c"
    break;

  case 145: /* decl: STRING_TYPE ID '[' e ']'  */
#line 463 "limbaj.y"
           { string s1=(yyvsp[-3].string); 
                      float size=(yyvsp[-1].floatValue);
                     
                        string s2="declared existing variable ";
                         string s3="no such variable as ";
                        
                          if((int)(yyvsp[-1].floatValue) != (yyvsp[-1].floatValue))
                         {
                              yyerror("not of int type");
                         }
                         if(!ids.existsVar((yyvsp[-3].string))) {
                          ids.addVar((yyvsp[-4].string),(yyvsp[-3].string),false,(int)(yyvsp[-1].floatValue));
                          ids.addDomain((yyvsp[-3].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-3].string), ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
     
                    }
#line 2629 "limbaj.tab.c"
    break;

  case 146: /* decl: BOOL_TYPE ID '[' e ']'  */
#line 480 "limbaj.y"
                                   { string s1=(yyvsp[-3].string); 
                      float size=(yyvsp[-1].floatValue);
                     
                        string s2="declared existing variable ";
                         string s3="no such variable as ";
                        
                          if((int)(yyvsp[-1].floatValue) != (yyvsp[-1].floatValue))
                         {
                              yyerror("not of int type");
                         }
                         if(!ids.existsVar((yyvsp[-3].string))) {
                          ids.addVar((yyvsp[-4].string),(yyvsp[-3].string),false,(int)(yyvsp[-1].floatValue));
                          ids.addDomain((yyvsp[-3].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-3].string), ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
     
                    }
#line 2651 "limbaj.tab.c"
    break;

  case 147: /* decl: CHAR_TYPE ID '[' e ']'  */
#line 497 "limbaj.y"
                                   { string s1=(yyvsp[-3].string); 
                      float size=(yyvsp[-1].floatValue);
                     
                        string s2="declared existing variable ";
                         string s3="no such variable as ";
                        
                          if((int)(yyvsp[-1].floatValue) != (yyvsp[-1].floatValue))
                         {
                              yyerror("not of int type");
                         }
                         if(!ids.existsVar((yyvsp[-3].string))) {
                          ids.addVar((yyvsp[-4].string),(yyvsp[-3].string),false,(int)(yyvsp[-1].floatValue));
                          ids.addDomain((yyvsp[-3].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-3].string), ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
     
                    }
#line 2673 "limbaj.tab.c"
    break;

  case 148: /* decl: TYPE ID '[' e ']'  */
#line 515 "limbaj.y"
                    { string s1=(yyvsp[-3].string); 
                      float size=(yyvsp[-1].floatValue);
                     
                        string s2="declared existing variable ";
                         string s3="no such variable as ";
                        
                          if((int)(yyvsp[-1].floatValue) != (yyvsp[-1].floatValue))
                         {
                              yyerror("not of int type");
                         }
                         if(!ids.existsVar((yyvsp[-3].string))) {
                          ids.addVar((yyvsp[-4].string),(yyvsp[-3].string),false,(int)(yyvsp[-1].floatValue));
                          ids.addDomain((yyvsp[-3].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-3].string), ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
     
                    }
#line 2695 "limbaj.tab.c"
    break;

  case 149: /* decl: STRING_TYPE ID  */
#line 532 "limbaj.y"
                           { string s1=(yyvsp[0].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[0].string))) {
                          ids.addVar((yyvsp[-1].string),(yyvsp[0].string),false);
                          ids.addDomain((yyvsp[0].string), domain);
                          if(isClass)ids.setIndex((yyvsp[0].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2709 "limbaj.tab.c"
    break;

  case 150: /* decl: STRING_TYPE ID ASSIGN STRING_TEXT  */
#line 542 "limbaj.y"
                    { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),false, (yyvsp[0].string));
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2723 "limbaj.tab.c"
    break;

  case 151: /* decl: BOOL_TYPE ID  */
#line 552 "limbaj.y"
                    { string s1=(yyvsp[0].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[0].string))) {
                          ids.addVar((yyvsp[-1].string),(yyvsp[0].string),false);
                          ids.addDomain((yyvsp[0].string), domain);
                          if(isClass)ids.setIndex((yyvsp[0].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2737 "limbaj.tab.c"
    break;

  case 152: /* decl: BOOL_TYPE ID ASSIGN BOOL_TRUE  */
#line 562 "limbaj.y"
                    { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),false,"true");
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2751 "limbaj.tab.c"
    break;

  case 153: /* decl: BOOL_TYPE ID ASSIGN BOOL_FALSE  */
#line 572 "limbaj.y"
                    { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),false,"false");
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2765 "limbaj.tab.c"
    break;

  case 154: /* decl: CONST BOOL_TYPE ID ASSIGN BOOL_TRUE  */
#line 582 "limbaj.y"
                    { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),true,"true");
                          ids.addDomain((yyvsp[-2].string), domain);
                          if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2779 "limbaj.tab.c"
    break;

  case 155: /* decl: CONST BOOL_TYPE ID ASSIGN BOOL_FALSE  */
#line 592 "limbaj.y"
                    { string s1=(yyvsp[-2].string); 
                        string s2="declared existing variable ";
                    
                         if(!ids.existsVar((yyvsp[-2].string))) {
                          ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),true,"false");
                          ids.addDomain((yyvsp[-2].string), domain);
                           if(isClass)ids.setIndex((yyvsp[-2].string), ind);
                     }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }
#line 2793 "limbaj.tab.c"
    break;

  case 156: /* decl: ID ID  */
#line 602 "limbaj.y"
               {
                    string s1=(yyvsp[0].string); 
                    string s2="declared existing variable";
                    string s3="declared variable of unexpected type";
                    if(cls.existsClass((yyvsp[-1].string)))
                    {
                         if(!ids.existsVar((yyvsp[0].string)))
                         {
                              ids.addVar((yyvsp[-1].string),(yyvsp[0].string),false);
                              ids.addDomain((yyvsp[0].string), domain);
                              ids.setSize((yyvsp[0].string), cls.getSize((yyvsp[-1].string)));
                               if(isClass)ids.setIndex((yyvsp[0].string), ind);
                         }else {yyerror((s2+"'"+s1+"'").c_str());}
                    }else {yyerror("declared variable of unexpected type");}
               }
#line 2813 "limbaj.tab.c"
    break;

  case 163: /* idVar: ID '[' NR ']'  */
#line 632 "limbaj.y"
                      {string val=ids.getValueIndex((yyvsp[-3].string),(yyvsp[-1].floatValue)); 
                         strcpy((yyval.string), val.c_str());
                         if(!ids.existsVar((yyvsp[-3].string)))
                         {yyerror("variable is not declared in this scope");}
                         
                         }
#line 2824 "limbaj.tab.c"
    break;

  case 164: /* idVar: ID '[' idVar ']'  */
#line 638 "limbaj.y"
                         { 
                    int v=stoi((yyvsp[-1].string));
                    string val=ids.getValueIndex((yyvsp[-3].string),v); 
                         strcpy((yyval.string), val.c_str());
                    if(!ids.existsVar((yyvsp[-3].string))){yyerror("variable is not declared in this scope");}
                     if((yyvsp[-3].string)==(yyvsp[-1].string))yyerror("you can't have an array as a size of the same array");
          }
#line 2836 "limbaj.tab.c"
    break;

  case 165: /* idVar: ID  */
#line 645 "limbaj.y"
          {    
               (yyval.string)=(yyvsp[0].string);
               if(!ids.existsVar((yyvsp[0].string))){yyerror("variable is not declared in this scope");}
           
           }
#line 2846 "limbaj.tab.c"
    break;

  case 167: /* statement: ID '[' e ']' ASSIGN onlyExp  */
#line 652 "limbaj.y"
                                        {if(!ids.existsVar((yyvsp[-5].string))){yyerror("variable is not declared in this scope");}
                                              else if(ids.isConstant((yyvsp[-5].string))){yyerror("attempted to modify constant variable");}
                                   if((yyvsp[-3].floatValue)>=ids.getSize((yyvsp[-5].string)) || (yyvsp[-3].floatValue)<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-5].string))=="global" || ids.getDomain((yyvsp[-5].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-5].string))!="main" && ids.getDomain((yyvsp[-5].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= to_string((yyvsp[0].floatValue));
                                        int i= (yyvsp[-3].floatValue);
                                        if(strcmp(domain,"main")==0)
                                        ids.populate((yyvsp[-5].string),i,x);
                                   }
                            }
#line 2876 "limbaj.tab.c"
    break;

  case 168: /* statement: ID '[' e ']' ASSIGN ID  */
#line 677 "limbaj.y"
                                   {if(!ids.existsVar((yyvsp[-5].string))){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant((yyvsp[-5].string))){yyerror("attempted to modify constant variable");}
                                   if((yyvsp[-3].floatValue)>=ids.getSize((yyvsp[-5].string)) || (yyvsp[-3].floatValue)<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-5].string))=="global" || ids.getDomain((yyvsp[-5].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                        if(!(ids.getDomain((yyvsp[0].string))=="global" || ids.getDomain((yyvsp[0].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && ((ids.getDomain((yyvsp[-5].string))!="main" && ids.getDomain((yyvsp[-5].string))!="global")
                                        ||(ids.getDomain((yyvsp[0].string))!="main" && ids.getDomain((yyvsp[0].string))!="global")))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= ids.getValue((yyvsp[0].string));
                                        int i= (yyvsp[-3].floatValue);
                                        if(strcmp(domain,"main")==0)
                                        ids.populate((yyvsp[-5].string),i,x);
                                   }
                                        
                                              
                                       
                                   
                            }
#line 2915 "limbaj.tab.c"
    break;

  case 169: /* statement: ID '[' e ']' ASSIGN ID '[' e ']'  */
#line 711 "limbaj.y"
                                             {if(!ids.existsVar((yyvsp[-8].string))){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant((yyvsp[-8].string))){yyerror("attempted to modify constant variable");}
                                   if((yyvsp[-6].floatValue)>=ids.getSize((yyvsp[-8].string)) || (yyvsp[-6].floatValue)<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                    
                                   
                                        if(!ids.haveSameType((yyvsp[-8].string),(yyvsp[-3].string)))
                                        {
                                             yyerror("variables do not have the same type");
                                        }
                                        else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-8].string))=="global" || ids.getDomain((yyvsp[-8].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                        if(!(ids.getDomain((yyvsp[-3].string))=="global" || ids.getDomain((yyvsp[-3].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && ((ids.getDomain((yyvsp[-8].string))!="main" && ids.getDomain((yyvsp[-8].string))!="global")
                                        ||(ids.getDomain((yyvsp[-3].string))!="main" && ids.getDomain((yyvsp[-3].string))!="global")))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                        else
                                        {

                                             string x= ids.getValueIndex((yyvsp[-3].string),(yyvsp[-1].floatValue));
                                             int i= (yyvsp[-6].floatValue);
                                             if(strcmp(domain,"main")==0)
                                             ids.populate((yyvsp[-8].string),i,x);
                                        }
                                   
                            }
#line 2958 "limbaj.tab.c"
    break;

  case 170: /* statement: ID ASSIGN CHARACTER  */
#line 749 "limbaj.y"
                              {if(!ids.existsVar((yyvsp[-2].string))){yyerror("variable is not declared in this scope");} 
                            else if(ids.isConstant((yyvsp[-2].string))){yyerror("attempted to modify constant variable");}
                              else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-2].string))=="global" || ids.getDomain((yyvsp[-2].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-2].string))!="main" && ids.getDomain((yyvsp[-2].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                              
                              else if(!ids.modifyValue((yyvsp[-2].string),(yyvsp[0].string)))
                              {
                                   yyerror("casting is not supported");
                              }
                            }
#line 2982 "limbaj.tab.c"
    break;

  case 171: /* statement: ID '[' e ']' ASSIGN BOOL_TRUE  */
#line 768 "limbaj.y"
                                          {
                                   if(!ids.existsVar((yyvsp[-5].string))){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant((yyvsp[-5].string))){yyerror("attempted to modify constant variable");}
                                   if(!ids.isBool((yyvsp[-5].string))){yyerror("attempted to assign a bool to a non bool");}
                                   if((yyvsp[-3].floatValue)>=ids.getSize((yyvsp[-5].string)) || (yyvsp[-3].floatValue)<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-5].string))=="global" || ids.getDomain((yyvsp[-5].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-5].string))!="main" && ids.getDomain((yyvsp[-5].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= "true";
                                        int i= (yyvsp[-3].floatValue);
                                        if(strcmp(domain,"main")==0)
                                        ids.populate((yyvsp[-5].string),i,x);
                                   }
                            }
#line 3014 "limbaj.tab.c"
    break;

  case 172: /* statement: ID '[' e ']' ASSIGN BOOL_FALSE  */
#line 795 "limbaj.y"
                                         {
                                   if(!ids.existsVar((yyvsp[-5].string))){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant((yyvsp[-5].string))){yyerror("attempted to modify constant variable");}
                                   if(!ids.isBool((yyvsp[-5].string))){yyerror("attempted to assign a bool to a non bool");}
                                   if((yyvsp[-3].floatValue)>=ids.getSize((yyvsp[-5].string)) || (yyvsp[-3].floatValue)<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-5].string))=="global" || ids.getDomain((yyvsp[-5].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-5].string))!="main" && ids.getDomain((yyvsp[-5].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= "false";
                                        int i= (yyvsp[-3].floatValue);
                                        if(strcmp(domain,"main")==0)
                                        ids.populate((yyvsp[-5].string),i,x);
                                   }
                            }
#line 3046 "limbaj.tab.c"
    break;

  case 173: /* statement: ID '[' e ']' ASSIGN STRING_TEXT  */
#line 822 "limbaj.y"
                                          {
                                   if(!ids.existsVar((yyvsp[-5].string))){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant((yyvsp[-5].string))){yyerror("attempted to modify constant variable");}
                                   if(!ids.isString((yyvsp[-5].string))){yyerror("attempted to assign a string to a non string");}
                                   if((yyvsp[-3].floatValue)>=ids.getSize((yyvsp[-5].string)) || (yyvsp[-3].floatValue)<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-5].string))=="global" || ids.getDomain((yyvsp[-5].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-5].string))!="main" && ids.getDomain((yyvsp[-5].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= (yyvsp[0].string);
                                        int i= (yyvsp[-3].floatValue);
                                        if(strcmp(domain,"main")==0)
                                        ids.populate((yyvsp[-5].string),i,x);
                                   }
                            }
#line 3078 "limbaj.tab.c"
    break;

  case 174: /* statement: ID '[' e ']' ASSIGN CHARACTER  */
#line 849 "limbaj.y"
                                         {
                                   if(!ids.existsVar((yyvsp[-5].string))){yyerror("variable is not declared in this scope");}
                              else if(ids.isConstant((yyvsp[-5].string))){yyerror("attempted to modify constant variable");}
                                   if(!ids.isChar((yyvsp[-5].string))){yyerror("attempted to assign a char to a non char");}
                                   if((yyvsp[-3].floatValue)>=ids.getSize((yyvsp[-5].string)) || (yyvsp[-3].floatValue)<0)
                                   {
                                        yyerror("index out of bounds");
                                   }
                                   else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-5].string))=="global" || ids.getDomain((yyvsp[-5].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-5].string))!="main" && ids.getDomain((yyvsp[-5].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                   else
                                   {
                                        string x= (yyvsp[0].string);
                                        int i= (yyvsp[-3].floatValue);
                                        if(strcmp(domain,"main")==0)
                                        ids.populate((yyvsp[-5].string),i,x);
                                   }
                            }
#line 3110 "limbaj.tab.c"
    break;

  case 175: /* statement: ID ASSIGN onlyExp  */
#line 877 "limbaj.y"
                             {if(!ids.existsVar((yyvsp[-2].string))){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant((yyvsp[-2].string))){yyerror("attempted to modify constant variable");}
                            else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-2].string))=="global" || ids.getDomain((yyvsp[-2].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-2].string))!="main" && ids.getDomain((yyvsp[-2].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                            else if(!ids.modifyValue((yyvsp[-2].string),to_string((yyvsp[0].floatValue))))
                              {
                                   yyerror("casting is not supported");
                              }
                             
                            }
#line 3134 "limbaj.tab.c"
    break;

  case 176: /* statement: ID ASSIGN ID  */
#line 896 "limbaj.y"
                         {if(!ids.existsVar((yyvsp[-2].string))){yyerror("variable is not declared in this scope");}
                            else if(ids.isConstant((yyvsp[-2].string))){yyerror("attempted to modify constant variable");}
                           
                             else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-2].string))=="global" || ids.getDomain((yyvsp[-2].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                        if(!(ids.getDomain((yyvsp[0].string))=="global" || ids.getDomain((yyvsp[0].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && ((ids.getDomain((yyvsp[-2].string))!="main" && ids.getDomain((yyvsp[-2].string))!="global")
                                        ||(ids.getDomain((yyvsp[0].string))!="main" && ids.getDomain((yyvsp[0].string))!="global")))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                            else if(!ids.modifyValueByVar((yyvsp[-2].string),(yyvsp[0].string)))
                              {
                                   yyerror("casting is not supported");
                              }
                            }
#line 3163 "limbaj.tab.c"
    break;

  case 177: /* statement: ID ASSIGN BOOL_TRUE  */
#line 921 "limbaj.y"
                               {
                                  if(!ids.existsVar((yyvsp[-2].string))){yyerror("variable is not declared in this scope");}
                                  if(!ids.isBool((yyvsp[-2].string))){yyerror("variable is not of type 'bool'");}
                                  else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-2].string))=="global" || ids.getDomain((yyvsp[-2].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-2].string))!="main" && ids.getDomain((yyvsp[-2].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                  else if(!ids.modifyValue((yyvsp[-2].string),to_string((yyvsp[0].boolValue))))
                                   {
                                   yyerror("casting is not supported");
                                    }
                               }
#line 3187 "limbaj.tab.c"
    break;

  case 178: /* statement: ID ASSIGN BOOL_FALSE  */
#line 940 "limbaj.y"
                                {
                                  if(!ids.existsVar((yyvsp[-2].string))){yyerror("variable is not declared in this scope");}
                                  if(!ids.isBool((yyvsp[-2].string))){yyerror("variable is not of type 'bool'");}
                                  else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-2].string))=="global" || ids.getDomain((yyvsp[-2].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-2].string))!="main" && ids.getDomain((yyvsp[-2].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                  else if(!ids.modifyValue((yyvsp[-2].string),to_string((yyvsp[0].boolValue))))
                              {
                                   yyerror("casting is not supported");
                              }
                               }
#line 3211 "limbaj.tab.c"
    break;

  case 179: /* statement: ID ASSIGN STRING_TEXT  */
#line 959 "limbaj.y"
                                 {
                    string s1=(yyvsp[-2].string);
               if(!ids.isString((yyvsp[-2].string)))
               {
                    yyerror("attept of assigning a string to a non-string type");
                        
               }
                else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-2].string))=="global" || ids.getDomain((yyvsp[-2].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-2].string))!="main" && ids.getDomain((yyvsp[-2].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                      else if(!ids.modifyValue((yyvsp[-2].string),(yyvsp[0].string)))
                              {
                                   yyerror("casting is not supported");
                              }
         }
#line 3239 "limbaj.tab.c"
    break;

  case 180: /* statement: ID ASSIGN ID '(' call_list ')'  */
#line 982 "limbaj.y"
                                          {
                    if(!ids.existsVar((yyvsp[-5].string)))yyerror("variable is not declared in this scope");
                         if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                   }
                              if(fnc.getType((yyvsp[-3].string)) != ids.getType((yyvsp[-5].string)))
                         {
                              yyerror("variable does not have the same type as the function");
                         }
                          else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-5].string))=="global" || ids.getDomain((yyvsp[-5].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-5].string))!="main" && ids.getDomain((yyvsp[-5].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                else  if(!ids.modifyValue((yyvsp[-5].string),(yyvsp[-3].string)))
                              {
                                   yyerror("casting is not supported");
                              }
                        
                         
                     }
#line 3274 "limbaj.tab.c"
    break;

  case 181: /* statement: ID '[' e ']' ASSIGN ID '(' call_list ')'  */
#line 1012 "limbaj.y"
                                                     {
                    if(!ids.existsVar((yyvsp[-8].string)))yyerror("variable is not declared in this scope");
                         if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                   }
                         
                         if(fnc.getType((yyvsp[-3].string)) != ids.getType((yyvsp[-8].string)))
                         {
                              yyerror("variable does not have the same type as the function");
                         }
                           else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-8].string))=="global" || ids.getDomain((yyvsp[-8].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-8].string))!="main" && ids.getDomain((yyvsp[-8].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                         
                     }
#line 3305 "limbaj.tab.c"
    break;

  case 182: /* statement: ID '(' call_list ')'  */
#line 1038 "limbaj.y"
                                {
                                  
                                   if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                   }
                               }
#line 3319 "limbaj.tab.c"
    break;

  case 183: /* statement: ID '(' ')'  */
#line 1047 "limbaj.y"
                       {if(!fnc.existFunction((yyvsp[-2].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam((yyvsp[-2].string))==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                   }
                               }
#line 3333 "limbaj.tab.c"
    break;

  case 184: /* statement: ID ASSIGN ID '[' e ']'  */
#line 1056 "limbaj.y"
                                  {if(!ids.haveSameType((yyvsp[-5].string),(yyvsp[-3].string)))yyerror("variables have different types");
                                          else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-5].string))=="global" || ids.getDomain((yyvsp[-5].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                        if(!(ids.getDomain((yyvsp[-3].string))=="global" || ids.getDomain((yyvsp[-3].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && ((ids.getDomain((yyvsp[-5].string))!="main" && ids.getDomain((yyvsp[-5].string))!="global")
                                        ||(ids.getDomain((yyvsp[-3].string))!="main" && ids.getDomain((yyvsp[-3].string))!="global")))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                        string val= ids.getValueIndex((yyvsp[-3].string), (yyvsp[-1].floatValue));
                                       
                                        
                                        ids.modifyValue((yyvsp[-5].string), val);
                                   }
#line 3360 "limbaj.tab.c"
    break;

  case 187: /* statement: ID '.' ID ASSIGN onlyExp  */
#line 1080 "limbaj.y"
                                    {
                                        if(!cls.existsClass(ids.getType((yyvsp[-4].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType((yyvsp[-4].string))==ids.getDomain((yyvsp[-2].string)))
                                        {
                                            
                                             string v=to_string((yyvsp[0].floatValue));
                                             ids.populate((yyvsp[-4].string), ids.getIndex((yyvsp[-2].string)), v);
                                        }
                                        else  yyerror("hopa");
                                    }
#line 3379 "limbaj.tab.c"
    break;

  case 188: /* statement: ID '.' ID ASSIGN STRING_TEXT  */
#line 1094 "limbaj.y"
                                         {
                                        if(!cls.existsClass(ids.getType((yyvsp[-4].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType((yyvsp[-4].string))==ids.getDomain((yyvsp[-2].string)))
                                        {
                                            if(ids.isString((yyvsp[-2].string)))
                                             {
                                             ids.populate((yyvsp[-4].string), ids.getIndex((yyvsp[-2].string)), (yyvsp[0].string));}
                                                  }
                                        else  yyerror("hopa");
                                    }
#line 3398 "limbaj.tab.c"
    break;

  case 189: /* statement: ID '.' ID ASSIGN CHARACTER  */
#line 1108 "limbaj.y"
                                      {
                                        if(!cls.existsClass(ids.getType((yyvsp[-4].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType((yyvsp[-4].string))==ids.getDomain((yyvsp[-2].string)))
                                        {
                                            if(ids.isChar((yyvsp[-2].string)))
                                             {
                                             ids.populate((yyvsp[-4].string), ids.getIndex((yyvsp[-2].string)), (yyvsp[0].string));}
                                                  }
                                        else  yyerror("hopa");
                                    }
#line 3417 "limbaj.tab.c"
    break;

  case 190: /* statement: ID '.' ID ASSIGN BOOL_TRUE  */
#line 1122 "limbaj.y"
                                      {
                                        if(!cls.existsClass(ids.getType((yyvsp[-4].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType((yyvsp[-4].string))==ids.getDomain((yyvsp[-2].string)))
                                        {
                                            if(ids.isBool((yyvsp[-2].string)))
                                             {
                                             ids.populate((yyvsp[-4].string), ids.getIndex((yyvsp[-2].string)), "true");}
                                                  }
                                        else  yyerror("hopa");
                                    }
#line 3436 "limbaj.tab.c"
    break;

  case 191: /* statement: ID '.' ID ASSIGN BOOL_FALSE  */
#line 1136 "limbaj.y"
                                       {
                                        if(!cls.existsClass(ids.getType((yyvsp[-4].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(string(domain)=="main")
                                        if(ids.getType((yyvsp[-4].string))==ids.getDomain((yyvsp[-2].string)))
                                        {
                                            if(ids.isBool((yyvsp[-2].string)))
                                             {
                                             ids.populate((yyvsp[-4].string), ids.getIndex((yyvsp[-2].string)), "false");}
                                                  }
                                        else  yyerror("hopa");
                                    }
#line 3455 "limbaj.tab.c"
    break;

  case 192: /* statement: ID '.' ID ASSIGN ID  */
#line 1150 "limbaj.y"
                                {
                                        if(!cls.existsClass(ids.getType((yyvsp[-4].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(!(ids.getDomain((yyvsp[0].string))=="main" || ids.getDomain((yyvsp[0].string))=="global"))
                                        {
                                             yyerror("variable was not declared in this scope");
                                        }
                                        else if(!ids.haveSameType((yyvsp[-2].string),(yyvsp[0].string)))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                        else if(ids.getType((yyvsp[-4].string))==ids.getDomain((yyvsp[-2].string)) && string(domain)=="main")
                                        {
                                            
                                             string v=ids.getValue((yyvsp[0].string));
                                             ids.populate((yyvsp[-4].string), ids.getIndex((yyvsp[-2].string)), v);
                                        }
                                        else  yyerror("hopa");
                                    }
#line 3481 "limbaj.tab.c"
    break;

  case 193: /* statement: ID '.' ID ASSIGN ID '[' e ']'  */
#line 1171 "limbaj.y"
                                       {
                                        if(!cls.existsClass(ids.getType((yyvsp[-7].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        if(!(ids.getDomain((yyvsp[-3].string))=="main" || ids.getDomain((yyvsp[-3].string))=="global"))
                                        {
                                             yyerror("variable was not declared in this scope");
                                        }
                                        else if(!ids.haveSameType((yyvsp[-5].string),(yyvsp[-3].string)))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                        else if(ids.getType((yyvsp[-7].string))==ids.getDomain((yyvsp[-5].string)) && string(domain)=="main")
                                        {
                                            
                                             string v=ids.getValueIndex((yyvsp[-3].string),(yyvsp[-1].floatValue));
                                             ids.populate((yyvsp[-7].string), ids.getIndex((yyvsp[-5].string)), v);
                                        }
                                        else  yyerror("hopa");
                                    }
#line 3507 "limbaj.tab.c"
    break;

  case 194: /* statement: ID '.' ID ASSIGN ID '.' ID  */
#line 1192 "limbaj.y"
                                         {
                                        if(!cls.existsClass(ids.getType((yyvsp[-6].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        else if(!cls.existsClass(ids.getType((yyvsp[-2].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        else if(!ids.haveSameType((yyvsp[-4].string),(yyvsp[0].string)))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                        else if(ids.getType((yyvsp[-6].string))==ids.getDomain((yyvsp[-4].string)) && string(domain)=="main")
                                        {
                                             int i=ids.getIndex((yyvsp[0].string));
                                             string v=ids.getValueIndex((yyvsp[-2].string),i);
                                             ids.populate((yyvsp[-6].string), ids.getIndex((yyvsp[-4].string)), v);
                                        }
                                        else  yyerror("hopa");
                                    }
#line 3533 "limbaj.tab.c"
    break;

  case 195: /* statement: ID ASSIGN ID '.' ID  */
#line 1213 "limbaj.y"
                               {
                                   
                                        if(!cls.existsClass(ids.getType((yyvsp[-2].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        else if(!ids.haveSameType((yyvsp[-4].string),(yyvsp[0].string)))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                         else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-4].string))=="global" || ids.getDomain((yyvsp[-4].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-4].string))!="main" && ids.getDomain((yyvsp[-4].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                        else 
                                        {
                                             int i=ids.getIndex((yyvsp[0].string));
                                             string v=ids.getValueIndex((yyvsp[-2].string),i);
                                             ids.modifyValue((yyvsp[-4].string), v);
                                        }
                                        
                                    }
#line 3567 "limbaj.tab.c"
    break;

  case 196: /* statement: ID '[' e ']' ASSIGN ID '.' ID  */
#line 1242 "limbaj.y"
                                       {
                                        if(!cls.existsClass(ids.getType((yyvsp[-2].string)).c_str()))
                                        {
                                             yyerror("class does not exist");
                                        }
                                        else if(!ids.haveSameType((yyvsp[-7].string),(yyvsp[0].string)))
                                        {
                                              yyerror("casting is not supported");
                                        }
                                         else if(string(domain)!="main" && string(domain)!="global")
                                   {
                                        if(!(ids.getDomain((yyvsp[-7].string))=="global" || ids.getDomain((yyvsp[-7].string))==string(domain)))
                                        {
                                             yyerror("variable is not declared in this scope");
                                        }
                                   }
                                   else if(string(domain)=="main" && (ids.getDomain((yyvsp[-7].string))!="main" && ids.getDomain((yyvsp[-7].string))!="global"))
                                   {
                                             yyerror("variable is not declared in this scope");
                                   }
                                        else 
                                        {
                                             int i=ids.getIndex((yyvsp[0].string));
                                             string v=ids.getValueIndex((yyvsp[-2].string),i);
                                             ids.populate((yyvsp[-7].string), (yyvsp[-5].floatValue), v);
                                        }
                                     
                                    }
#line 3600 "limbaj.tab.c"
    break;

  case 197: /* statement: ID '.' ID '(' call_list ')'  */
#line 1270 "limbaj.y"
                                        {
                                  
                                   if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        string funcDomain= fnc.getDomain((yyvsp[-3].string));
                                        if(!(ids.getType((yyvsp[-5].string)) == funcDomain))
                                        {
                                             yyerror("syntax error");
                                        }
                                   }
                                   if(!cls.existsClass(ids.getType((yyvsp[-5].string)).c_str()))
                                   {
                                        yyerror("class does not exist");
                                   }
                               }
#line 3623 "limbaj.tab.c"
    break;

  case 198: /* statement: ID '.' ID '(' ')'  */
#line 1288 "limbaj.y"
                              {if(!fnc.existFunction((yyvsp[-2].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam((yyvsp[-2].string))==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        string funcDomain= fnc.getDomain((yyvsp[-2].string));
                                        if(!(ids.getType((yyvsp[-4].string)) == funcDomain))
                                        {
                                             yyerror("syntax error");
                                        }
                                   }
                                   if(!cls.existsClass(ids.getType((yyvsp[-4].string)).c_str()))
                                   {
                                        yyerror("class does not exist");
                                   }
                                   
                               }
#line 3647 "limbaj.tab.c"
    break;

  case 199: /* onlyExp: e '+' e  */
#line 1311 "limbaj.y"
                     {(yyval.floatValue)=(yyvsp[-2].floatValue)+(yyvsp[0].floatValue);}
#line 3653 "limbaj.tab.c"
    break;

  case 200: /* onlyExp: e '*' e  */
#line 1312 "limbaj.y"
              {(yyval.floatValue)=(yyvsp[-2].floatValue)*(yyvsp[0].floatValue);}
#line 3659 "limbaj.tab.c"
    break;

  case 201: /* onlyExp: e '-' e  */
#line 1313 "limbaj.y"
              {(yyval.floatValue)=(yyvsp[-2].floatValue)-(yyvsp[0].floatValue);}
#line 3665 "limbaj.tab.c"
    break;

  case 202: /* onlyExp: e '/' e  */
#line 1314 "limbaj.y"
              {(yyval.floatValue)=(yyvsp[-2].floatValue)/(yyvsp[0].floatValue);}
#line 3671 "limbaj.tab.c"
    break;

  case 203: /* onlyExp: '(' e ')'  */
#line 1315 "limbaj.y"
             {(yyval.floatValue)= (yyvsp[-1].floatValue);}
#line 3677 "limbaj.tab.c"
    break;

  case 204: /* onlyExp: '(' '-' e ')'  */
#line 1316 "limbaj.y"
                 {(yyval.floatValue)= -(yyvsp[-1].floatValue);}
#line 3683 "limbaj.tab.c"
    break;

  case 205: /* onlyExp: FLOAT_NR  */
#line 1317 "limbaj.y"
             {(yyval.floatValue)=(yyvsp[0].floatValue);}
#line 3689 "limbaj.tab.c"
    break;

  case 206: /* onlyExp: NR  */
#line 1318 "limbaj.y"
       {(yyval.floatValue)=(yyvsp[0].floatValue);}
#line 3695 "limbaj.tab.c"
    break;

  case 207: /* call_list: onlyExp  */
#line 1321 "limbaj.y"
                   {
                       
     
                      char in[20]="int ";
                      char fl[20]="float ";
                      if((yyvsp[0].floatValue)=(int)(yyvsp[0].floatValue)){(yyval.string)=in;;}else (yyval.string)=fl;
                      
               }
#line 3708 "limbaj.tab.c"
    break;

  case 208: /* call_list: ID '(' call_list ')'  */
#line 1329 "limbaj.y"
                                 { 
                                   
                                   if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        else{ string type=fnc.getType((yyvsp[-3].string))+ " "; strcpy((yyval.string),type.c_str());}
                                   }
                                   
                               }
#line 3724 "limbaj.tab.c"
    break;

  case 209: /* call_list: ID '(' ')'  */
#line 1340 "limbaj.y"
                        { 
                                   
                                   if(!fnc.existFunction((yyvsp[-2].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam((yyvsp[-2].string))==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        else {string type=fnc.getType((yyvsp[-2].string))+ " "; strcpy((yyval.string),type.c_str());}
                                   }
                                   
                               }
#line 3742 "limbaj.tab.c"
    break;

  case 210: /* call_list: ID '.' ID '(' call_list ')'  */
#line 1353 "limbaj.y"
                                        { 
                                   
                                   if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        else{ string type=fnc.getType((yyvsp[-3].string))+ " "; strcpy((yyval.string),type.c_str());}
                                   }
                                   
                               }
#line 3758 "limbaj.tab.c"
    break;

  case 211: /* call_list: ID '.' ID '(' ')'  */
#line 1364 "limbaj.y"
                              { 
                                   
                                   if(!fnc.existFunction((yyvsp[-2].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam((yyvsp[-2].string))==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        else {string type=fnc.getType((yyvsp[-2].string))+ " "; strcpy((yyval.string),type.c_str());}
                                   }
                                   
                               }
#line 3776 "limbaj.tab.c"
    break;

  case 212: /* call_list: ID  */
#line 1377 "limbaj.y"
                {string type=ids.getType((yyvsp[0].string))+ " "; strcpy((yyval.string),type.c_str()); }
#line 3782 "limbaj.tab.c"
    break;

  case 213: /* call_list: ID '[' e ']'  */
#line 1378 "limbaj.y"
                         {string type=ids.getType((yyvsp[-3].string))+ " "; strcpy((yyval.string),type.c_str()); }
#line 3788 "limbaj.tab.c"
    break;

  case 214: /* call_list: STRING_TEXT  */
#line 1379 "limbaj.y"
                         {strcpy((yyval.string),"string ");}
#line 3794 "limbaj.tab.c"
    break;

  case 215: /* call_list: bExp  */
#line 1380 "limbaj.y"
                  { strcpy((yyval.string),"bool ");}
#line 3800 "limbaj.tab.c"
    break;

  case 216: /* call_list: CHARACTER  */
#line 1381 "limbaj.y"
                       {strcpy((yyval.string), "char ");}
#line 3806 "limbaj.tab.c"
    break;

  case 217: /* call_list: call_list ',' ID '[' e ']'  */
#line 1382 "limbaj.y"
                                        {string type=ids.getType((yyvsp[-3].string)); strcat((yyval.string),type.c_str()); strcat((yyval.string)," "); }
#line 3812 "limbaj.tab.c"
    break;

  case 218: /* call_list: call_list ',' ID  */
#line 1383 "limbaj.y"
                              {string type=ids.getType((yyvsp[0].string)); strcat((yyval.string),type.c_str()); strcat((yyval.string)," "); }
#line 3818 "limbaj.tab.c"
    break;

  case 219: /* call_list: call_list ',' onlyExp  */
#line 1384 "limbaj.y"
                                   {if((yyvsp[0].floatValue)=(int)(yyvsp[0].floatValue)){strcat((yyval.string),"int ");}else strcat((yyval.string),"float ");}
#line 3824 "limbaj.tab.c"
    break;

  case 220: /* call_list: call_list ',' STRING_TEXT  */
#line 1385 "limbaj.y"
                                       {strcat((yyval.string)," "); strcat((yyval.string), "string ");}
#line 3830 "limbaj.tab.c"
    break;

  case 221: /* call_list: call_list ',' bExp  */
#line 1386 "limbaj.y"
                                {strcat((yyval.string)," "); strcat((yyval.string), "bool ");}
#line 3836 "limbaj.tab.c"
    break;

  case 222: /* call_list: call_list ',' CHARACTER  */
#line 1387 "limbaj.y"
                                      {strcat((yyval.string)," "); strcat((yyval.string), "char ");}
#line 3842 "limbaj.tab.c"
    break;

  case 223: /* call_list: call_list ',' ID '(' call_list ')'  */
#line 1388 "limbaj.y"
                                                { 
                                   
                                   if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        else{ string type=fnc.getType((yyvsp[-3].string))+ " "; strcat((yyval.string),type.c_str());}
                                   }
                                   
                               }
#line 3858 "limbaj.tab.c"
    break;

  case 224: /* call_list: call_list ',' ID '(' ')'  */
#line 1399 "limbaj.y"
                                       { 
                                   
                                   if(!fnc.existFunction((yyvsp[-2].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam((yyvsp[-2].string))==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        else {string type=fnc.getType((yyvsp[-2].string))+ " "; strcat((yyval.string),type.c_str());}
                                   }
                                   
                               }
#line 3876 "limbaj.tab.c"
    break;

  case 225: /* call_list: call_list ',' ID '.' ID '(' call_list ')'  */
#line 1412 "limbaj.y"
                                                      { 
                                   
                                   if(!fnc.existFunction((yyvsp[-3].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!fnc.checkParam((yyvsp[-3].string),string((yyvsp[-1].string))))
                                        {yyerror("incorrect or insufficient parameters passed to function");}
                                        else{ string type=fnc.getType((yyvsp[-3].string))+ " "; strcat((yyval.string),type.c_str());}
                                   }
                                   
                               }
#line 3892 "limbaj.tab.c"
    break;

  case 226: /* call_list: call_list ',' ID '.' ID '(' ')'  */
#line 1423 "limbaj.y"
                                            { 
                                   
                                   if(!fnc.existFunction((yyvsp[-2].string))){yyerror("function is not declared in this scope");}
                                   else
                                   {
                                        if(!(fnc.numParam((yyvsp[-2].string))==0))
                                        {
                                             yyerror("incorrect or insufficient parameters passed to function");
                                        }
                                        else {string type=fnc.getType((yyvsp[-2].string))+ " "; strcat((yyval.string),type.c_str());}
                                   }
                                   
                               }
#line 3910 "limbaj.tab.c"
    break;


#line 3914 "limbaj.tab.c"

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

#line 1437 "limbaj.y"

void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     strcpy(buffer,"\n");
     ids.printVars(buffer);
     fnc.printFuncs(buffer);
     fout<<buffer;
     
     
} 
