
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "synt.y"

       #include <stdio.h>
       #include<stdlib.h>
       #include<string.h>
       int nb_ligne=1, col=1,ts;
       extern FILE *yyin;
       char* saveType;
       char *filename;


/* Line 189 of yacc.c  */
#line 84 "synt.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_program = 258,
     mc_routine = 259,
     mc_entier = 260,
     string = 261,
     mc_true = 262,
     mc_false = 263,
     mc_real = 264,
     mc_logical = 265,
     mc_character = 266,
     mc_dimension = 267,
     mc_read = 268,
     mc_write = 269,
     mc_if = 270,
     mc_then = 271,
     mc_else = 272,
     mc_endif = 273,
     mc_dowhile = 274,
     mc_enddo = 275,
     mc_or = 276,
     mc_and = 277,
     mc_gt = 278,
     mc_ge = 279,
     mc_eq = 280,
     mc_ne = 281,
     mc_le = 282,
     mc_lt = 283,
     mc_call = 284,
     mc_endr = 285,
     mc_end = 286,
     IDF = 287,
     integr = 288,
     floatt = 289,
     add = 290,
     sub = 291,
     mul = 292,
     divv = 293,
     pvg = 294,
     vrg = 295,
     aff = 296,
     po = 297,
     pf = 298,
     mc_equivalence = 299,
     point = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 11 "synt.y"

         int     entier;
         char*   str;
         float reel;




/* Line 214 of yacc.c  */
#line 174 "synt.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 186 "synt.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    14,    21,    23,    25,
      27,    29,    31,    35,    40,    46,    49,    50,    51,    59,
      60,    64,    69,    76,    79,    80,    82,    86,    91,    95,
      99,   102,   106,   110,   114,   115,   120,   125,   130,   132,
     136,   142,   146,   149,   151,   153,   157,   159,   161,   163,
     165,   167,   169,   171,   173,   175,   180,   185,   191,   193,
     203,   205,   209,   211,   219,   223,   225,   227,   229,   231,
     233,   235,   237,   239,   246,   254
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    59,    -1,    -1,    50,    53,
      30,    49,    47,    -1,    51,     4,    32,    42,    52,    43,
      -1,     5,    -1,     9,    -1,    10,    -1,    11,    -1,    32,
      -1,    32,    40,    52,    -1,    32,    42,    58,    43,    -1,
      32,    42,    58,    43,    52,    -1,    54,    60,    -1,    -1,
      -1,    51,    32,    55,    57,    39,    56,    54,    -1,    -1,
      40,    32,    57,    -1,    12,    42,    58,    43,    -1,    12,
      42,    58,    43,    40,    57,    -1,    37,    33,    -1,    -1,
      33,    -1,    33,    40,    33,    -1,     3,    32,    53,    31,
      -1,    61,    39,    60,    -1,    69,    39,    60,    -1,    71,
      60,    -1,    75,    39,    60,    -1,    76,    39,    60,    -1,
      77,    39,    60,    -1,    -1,    32,    41,    62,    60,    -1,
      32,    41,    67,    60,    -1,    32,    41,    68,    60,    -1,
      63,    -1,    63,    66,    62,    -1,    42,    62,    43,    66,
      62,    -1,    42,    62,    43,    -1,    32,    64,    -1,    65,
      -1,    32,    -1,    42,    58,    43,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,     6,
      -1,     7,    -1,     8,    -1,    13,    42,    32,    43,    -1,
      14,    42,    70,    43,    -1,    67,    40,    32,    40,    67,
      -1,    67,    -1,    15,    42,    72,    43,    16,    60,    17,
      60,    18,    -1,    62,    -1,    62,    73,    72,    -1,    68,
      -1,    42,    72,    43,    73,    42,    72,    43,    -1,    45,
      74,    45,    -1,    25,    -1,    26,    -1,    24,    -1,    23,
      -1,    27,    -1,    28,    -1,    22,    -1,    21,    -1,    19,
      42,    72,    43,    60,    20,    -1,    32,    41,    29,    32,
      42,    52,    43,    -1,    44,    42,    52,    43,    40,    42,
      52,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    35,    38,    38,    41,    44,    45,    46,
      47,    50,    51,    52,    53,    59,    62,    62,    62,    63,
      67,    68,    69,    70,    71,    75,    76,    81,    85,    86,
      87,    88,    89,    90,    91,    96,    97,    98,   101,   102,
     103,   104,   107,   108,   109,   112,   115,   115,   118,   118,
     118,   118,   121,   124,   124,   127,   128,   131,   132,   135,
     138,   139,   140,   141,   144,   146,   147,   148,   149,   150,
     151,   152,   153,   156,   159,   162
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_program", "mc_routine", "mc_entier",
  "string", "mc_true", "mc_false", "mc_real", "mc_logical", "mc_character",
  "mc_dimension", "mc_read", "mc_write", "mc_if", "mc_then", "mc_else",
  "mc_endif", "mc_dowhile", "mc_enddo", "mc_or", "mc_and", "mc_gt",
  "mc_ge", "mc_eq", "mc_ne", "mc_le", "mc_lt", "mc_call", "mc_endr",
  "mc_end", "IDF", "integr", "floatt", "add", "sub", "mul", "divv", "pvg",
  "vrg", "aff", "po", "pf", "mc_equivalence", "point", "$accept", "S",
  "FUNCTION", "$@1", "HEADER", "TYPE", "PARAMETRE", "BODY", "DEC", "$@2",
  "$@3", "ListIDF", "TAILLE", "PROGRAM", "INST", "AFFECTATION",
  "EXPRESSION", "VALEUR", "TAB", "NUMBER", "OPERATION", "CHAINE",
  "LOGICAL", "ES", "STRING", "CONDITON", "EXPCDTT", "CDTT", "CDT", "LOOP",
  "CALLING", "EQUIV", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    49,    48,    50,    51,    51,    51,
      51,    52,    52,    52,    52,    53,    55,    56,    54,    54,
      57,    57,    57,    57,    57,    58,    58,    59,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    62,    62,
      62,    62,    63,    63,    63,    64,    65,    65,    66,    66,
      66,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    72,    72,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    76,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     5,     6,     1,     1,     1,
       1,     1,     3,     4,     5,     2,     0,     0,     7,     0,
       3,     4,     6,     2,     0,     1,     3,     4,     3,     3,
       2,     3,     3,     3,     0,     4,     4,     4,     1,     3,
       5,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     1,     9,
       1,     3,     1,     7,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     7,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     7,     8,     9,    10,     0,     2,    19,     0,
       3,    19,     1,     0,     0,    34,     0,     0,    16,     4,
       0,     0,     0,     0,     0,     0,    15,     0,     0,    34,
       0,     0,     0,     0,    27,    24,     0,     0,     0,     0,
       0,     0,     0,    34,    34,    30,    34,    34,    34,     0,
       0,     0,     0,     0,     5,     0,    52,    58,     0,    53,
      54,    44,    46,    47,     0,    60,    38,    43,    62,     0,
       0,     0,     0,    34,    34,    34,    11,     0,    28,    29,
      31,    32,    33,     0,     0,    23,    24,    17,    55,     0,
      56,     0,    42,     0,     0,     0,     0,    48,    49,    50,
      51,     0,     0,    34,     0,     0,    35,    36,    37,     0,
       0,     0,     6,    25,     0,    20,    19,     0,     0,    41,
       0,    72,    71,    68,    67,    65,    66,    69,    70,     0,
      61,    39,    34,     0,     0,    12,     0,     0,     0,    21,
      18,     0,    45,     0,     0,    64,     0,    73,     0,    13,
       0,    26,    24,    57,    40,     0,    34,    74,    14,     0,
      22,     0,     0,    75,    63,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    36,     8,    13,    77,    14,    15,    35,
     116,    53,   114,    10,    26,    27,    65,    66,    92,    67,
     101,    57,    68,    28,    58,    29,    69,    96,   129,    30,
      31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -85
static const yytype_int8 yypact[] =
{
      28,   -23,   -85,   -85,   -85,   -85,    13,   -85,    62,    12,
     -85,    62,   -85,   -11,    -8,    46,     4,    21,   -85,   -85,
       1,    11,    20,    27,     6,    34,   -85,    31,    48,    46,
      49,    50,    59,    54,   -85,    -5,    28,    65,    93,    16,
      16,    22,    68,    46,    46,   -85,    46,    46,    46,    68,
      60,    75,    69,    70,   -85,    67,   -85,    71,    72,   -85,
     -85,    76,   -85,   -85,    16,    74,    57,   -85,   -85,    77,
      78,    80,   -22,    46,    46,    46,     0,    79,   -85,   -85,
     -85,   -85,   -85,    81,    84,   -85,    -5,   -85,   -85,    82,
     -85,    84,   -85,    32,    83,    58,    16,   -85,   -85,   -85,
     -85,   -22,    97,    46,    86,    87,   -85,   -85,   -85,    68,
      84,    85,   -85,    89,    88,   -85,    62,    92,    90,    57,
      74,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,    91,
     -85,   -85,    46,   103,    68,   -85,    94,    96,   101,    95,
     -85,    93,   -85,   -22,    98,   -85,   122,   -85,    99,    68,
      68,   -85,    -5,   -85,   -85,    16,    46,   -85,   -85,   100,
     -85,   102,   123,   -85,   -85,   -85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   108,   -85,   -85,   -85,     5,   -43,   135,    33,   -85,
     -85,   -84,   -83,   -85,   -29,   -85,   -38,   -85,   -85,   -85,
      29,   -37,   106,   -85,   -85,   -85,   -39,    30,   -85,   -85,
     -85,   -85
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      45,    70,   115,    73,    74,     9,    83,    50,   118,    11,
      61,    62,    63,    12,    78,    79,    16,    80,    81,    82,
      72,    18,    19,    59,    60,    94,    93,   136,    56,    59,
      60,     1,    51,     2,   105,    52,    33,     3,     4,     5,
     109,     9,   110,    37,   106,   107,   108,    41,    61,    62,
      63,    71,    34,    38,    61,    62,    63,   130,    64,    20,
      21,    22,    39,   131,    72,    23,   135,     2,   160,    40,
      43,     3,     4,     5,   133,   119,    42,    95,    24,   121,
     122,   123,   124,   125,   126,   127,   128,    44,    46,    47,
      25,   148,    97,    98,    99,   100,    49,    55,    48,    56,
      76,    86,    84,   146,   153,   154,   158,   159,    85,    87,
      88,    89,   104,   132,   117,    90,   161,   113,    91,    95,
     102,   103,   111,   147,   112,   137,   120,   162,   134,   138,
     119,   139,   141,   142,   151,   152,   145,   149,   150,   156,
     155,   165,   157,   163,    54,   164,    17,    75,   143,   140,
     144
};

static const yytype_uint8 yycheck[] =
{
      29,    40,    86,    41,    41,     0,    49,    12,    91,    32,
      32,    33,    34,     0,    43,    44,     4,    46,    47,    48,
      42,    32,    30,     7,     8,    64,    64,   110,     6,     7,
       8,     3,    37,     5,    72,    40,    32,     9,    10,    11,
      40,    36,    42,    42,    73,    74,    75,    41,    32,    33,
      34,    29,    31,    42,    32,    33,    34,    96,    42,    13,
      14,    15,    42,   101,    42,    19,   109,     5,   152,    42,
      39,     9,    10,    11,   103,    43,    42,    45,    32,    21,
      22,    23,    24,    25,    26,    27,    28,    39,    39,    39,
      44,   134,    35,    36,    37,    38,    42,    32,    39,     6,
      32,    32,    42,   132,   141,   143,   149,   150,    33,    39,
      43,    40,    32,    16,    32,    43,   155,    33,    42,    45,
      43,    43,    43,    20,    43,    40,    43,   156,    42,    40,
      43,    43,    40,    43,    33,    40,    45,    43,    42,    17,
      42,    18,    43,    43,    36,    43,    11,    41,   119,   116,
     120
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     9,    10,    11,    47,    48,    50,    51,
      59,    32,     0,    51,    53,    54,     4,    53,    32,    30,
      13,    14,    15,    19,    32,    44,    60,    61,    69,    71,
      75,    76,    77,    32,    31,    55,    49,    42,    42,    42,
      42,    41,    42,    39,    39,    60,    39,    39,    39,    42,
      12,    37,    40,    57,    47,    32,     6,    67,    70,     7,
       8,    32,    33,    34,    42,    62,    63,    65,    68,    72,
      72,    29,    42,    62,    67,    68,    32,    52,    60,    60,
      60,    60,    60,    52,    42,    33,    32,    39,    43,    40,
      43,    42,    64,    62,    72,    45,    73,    35,    36,    37,
      38,    66,    43,    43,    32,    62,    60,    60,    60,    40,
      42,    43,    43,    33,    58,    57,    56,    32,    58,    43,
      43,    21,    22,    23,    24,    25,    26,    27,    28,    74,
      72,    62,    16,    60,    42,    52,    58,    40,    40,    43,
      54,    40,    43,    66,    73,    45,    60,    20,    52,    43,
      42,    33,    40,    67,    62,    42,    17,    43,    52,    52,
      57,    72,    60,    43,    43,    18
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 35 "synt.y"
    {printf("prog syntaxiquement correct"); YYACCEPT;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 38 "synt.y"
    {rechercher ((yyvsp[(3) - (3)].str),"Mot cle ","",0, 1,ts); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 41 "synt.y"
    { rechercher ((yyvsp[(2) - (6)].str),"Mot cle ","",0, 1,ts); rechercher ((yyvsp[(3) - (6)].str),"IDF","Identifier",0 , 0,ts);modifyType((yyvsp[(3) - (6)].str),saveType,ts); rechercher ((yyvsp[(4) - (6)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(6) - (6)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 44 "synt.y"
    {saveType=(yyvsp[(1) - (1)].str);rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 45 "synt.y"
    {saveType=(yyvsp[(1) - (1)].str);rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 46 "synt.y"
    {saveType=(yyvsp[(1) - (1)].str);rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 47 "synt.y"
    {saveType=(yyvsp[(1) - (1)].str);rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 50 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"IDF","Identifier",0 , 0,ts);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 51 "synt.y"
    {rechercher ((yyvsp[(1) - (3)].str),"IDF","Identifier",0 , 0,ts); rechercher ((yyvsp[(2) - (3)].str),"Separateur",0,0, 2,ts); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 52 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"IDF","Identifier",0 , 0,ts);rechercher ((yyvsp[(2) - (4)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(4) - (4)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 53 "synt.y"
    {rechercher ((yyvsp[(1) - (5)].str),"IDF","Identifier",0 , 0,ts);rechercher ((yyvsp[(2) - (5)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(4) - (5)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 62 "synt.y"
    {rechercher ((yyvsp[(2) - (2)].str),"IDF","Identifier",0 , 0,ts); modifyType((yyvsp[(2) - (2)].str),saveType,ts);printf("%dttttttttt\n",ts); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 62 "synt.y"
    {rechercher ((yyvsp[(5) - (5)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 67 "synt.y"
    { rechercher ((yyvsp[(1) - (3)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(2) - (3)].str),"IDF","Identifier",0 , 0,ts); modifyType((yyvsp[(2) - (3)].str),saveType,ts); printf("%dttttttttt\n",ts);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 68 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"Mot cle ","",0, 1,ts);rechercher ((yyvsp[(2) - (4)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(4) - (4)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 69 "synt.y"
    {rechercher ((yyvsp[(1) - (6)].str),"Mot cle ","",0, 1,ts);rechercher ((yyvsp[(2) - (6)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(4) - (6)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(5) - (6)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 70 "synt.y"
    {rechercher ((yyvsp[(1) - (2)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 76 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 81 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"Mot cle ","",0, 1,ts); rechercher ((yyvsp[(2) - (4)].str),"IDF","Identifier",0 , 0,ts); rechercher ((yyvsp[(4) - (4)].str),"Mot cle ","",0, 1,ts); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 85 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 86 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 88 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 89 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 90 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 96 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"IDF","Identifier",0 , 0,ts);  rechercher ((yyvsp[(2) - (4)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 97 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"IDF","Identifier",0 , 0,ts); rechercher ((yyvsp[(2) - (4)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 98 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"IDF","Identifier",0 , 0,ts); rechercher ((yyvsp[(2) - (4)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 103 "synt.y"
    {rechercher ((yyvsp[(1) - (5)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(3) - (5)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 104 "synt.y"
    {rechercher ((yyvsp[(1) - (3)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(3) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 107 "synt.y"
    {rechercher ((yyvsp[(1) - (2)].str),"IDF","Identifier",0 , 0,ts); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 109 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"IDF","Identifier",0 , 0,ts); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 112 "synt.y"
    {rechercher ((yyvsp[(1) - (3)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(3) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 118 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 118 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 118 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 118 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 124 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 124 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 127 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"Mot cle ","",0, 1,ts); rechercher ((yyvsp[(2) - (4)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(3) - (4)].str),"IDF","Identifier",0 , 0,ts); rechercher ((yyvsp[(4) - (4)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 128 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"Mot cle ","",0, 1,ts); rechercher ((yyvsp[(2) - (4)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(4) - (4)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 131 "synt.y"
    {rechercher ((yyvsp[(2) - (5)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(3) - (5)].str),"IDF","Identifier",0 , 0,ts); rechercher ((yyvsp[(4) - (5)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 135 "synt.y"
    {rechercher ((yyvsp[(1) - (9)].str),"Mot cle ","",0, 1,ts); rechercher ((yyvsp[(2) - (9)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(4) - (9)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(5) - (9)].str),"Mot cle ","",0, 1,ts);rechercher ((yyvsp[(7) - (9)].str),"Mot cle ","",0, 1,ts);rechercher ((yyvsp[(9) - (9)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 141 "synt.y"
    {rechercher ((yyvsp[(1) - (7)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(3) - (7)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(5) - (7)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(7) - (7)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 144 "synt.y"
    {rechercher ((yyvsp[(1) - (3)].str),"Separateur",0,0, 2,ts); rechercher ((yyvsp[(3) - (3)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 146 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 147 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 148 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 149 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 150 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 151 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 152 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 153 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 156 "synt.y"
    {rechercher ((yyvsp[(1) - (6)].str),"Mot cle ","",0, 1,ts); rechercher ((yyvsp[(2) - (6)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(4) - (6)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(6) - (6)].str),"Mot cle ","",0, 1,ts);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 159 "synt.y"
    {rechercher ((yyvsp[(1) - (7)].str),"IDF","Identifier",0 , 0,ts); rechercher ((yyvsp[(2) - (7)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(3) - (7)].str),"Mot cle ","",0, 1,ts);rechercher ((yyvsp[(5) - (7)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(7) - (7)].str),"Separateur",0,0, 2,ts);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 162 "synt.y"
    {rechercher ((yyvsp[(1) - (8)].str),"Mot cle ","",0, 1,ts);rechercher ((yyvsp[(4) - (8)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(5) - (8)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(6) - (8)].str),"Separateur",0,0, 2,ts);rechercher ((yyvsp[(8) - (8)].str),"Separateur",0,0, 2,ts);;}
    break;



/* Line 1455 of yacc.c  */
#line 1905 "synt.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 165 "synt.y"

int main(int argc, char **argv) {
    if (argc > 0) {
        yyin = fopen(argv[1], "r");
        filename = argv[1];
    } else {
        printf("Aucun fichier à compiler\n");
        return 1;
    }


    

    yyparse();
    fclose(yyin);
    afficher();
    
    return 0;
}
yywrap ()
{}
int yyerror ( char*  msg )  
{
       printf ("Erreur Syntaxique : fichier %s , ligne %d , colonne %d \n", filename,nb_ligne,col);
}

