
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
       int nb_ligne=1, col=1,tss=0;
       extern FILE *yyin;
       char* saveType;
       char *returnedType;
       char typeval[25];
       char *filename;
       float idfValue;
       char idfNewValue[20];
       int qc=0;
       int resultI;
       float resultF;
       
       int jj=0;
       int kk=0;
       int c=0;
       int nb11=0,nb22=0,nb33=0,nb44=0;
       int i=0;
       float idfNewValue1;
       int idfNewValue2;
       int zz=0 ;
       int xx1=0;
       int bb = 0 ;
       int vv=0;
       int vv1=0;
       char xx[20] ;
       char chaine1[20];
       int intIdfNewValue;


	int err = 0;
	int h = 0;
	int Fin_if=0,Fin_while=0, Deb_while=0,OP = 0,and_b=0,and_f=0,or_b=0,or_f=0,debu=0,deb_for=0;
	char L[25],Q[25];
	char temp1[25] = "TEMP";
	char opera[5]; 
	char saveOP[25];
	char saveOpLo[25];
	char tmp[25];
	char med[25];
	char med2[25];
	char op1[25];
	char op2[25];
	char medOp[25];
	char tempMul[25];
	char resultL[25];
	char s[25];
	char medType[25];
    int fin_if[10];
	int i_if=0;
    int deb_else[10];
	int i_else=0;	
	int lol = 0;
	int Cond = 0;
	int medL=0;
	int indentation = 0;
	int mustBe = 0;
	int mull=0;
	int x=0;
	int AND_or_OR = 0;
	int only_one = 0;
	int first =0;
	int teemp = 0;
	int p = 0;
	int o = 0;
	int a = 0;
        int value2,value1;	
	char saveCst[25];
	char sauvIdf1[25];
	char sauvIdf[2][10] = {};	
        int nbLigne=1; 
        int nbCol=1; //declaraction du cpt de nombre de colonne
        int callIndex=-1;
        int nbParams=0;


/* Line 189 of yacc.c  */
#line 153 "synt.tab.c"

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
     booleen = 262,
     mc_real = 263,
     mc_logical = 264,
     mc_character = 265,
     mc_dimension = 266,
     mc_read = 267,
     mc_write = 268,
     mc_if = 269,
     mc_then = 270,
     mc_else = 271,
     mc_endif = 272,
     mc_dowhile = 273,
     mc_enddo = 274,
     mc_or = 275,
     mc_and = 276,
     mc_gt = 277,
     mc_ge = 278,
     mc_eq = 279,
     mc_ne = 280,
     mc_le = 281,
     mc_lt = 282,
     mc_call = 283,
     mc_endr = 284,
     mc_end = 285,
     IDF = 286,
     integr = 287,
     floatt = 288,
     add = 289,
     sub = 290,
     mul = 291,
     divv = 292,
     pvg = 293,
     vrg = 294,
     aff = 295,
     po = 296,
     pf = 297,
     mc_equivalence = 298,
     point = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 80 "synt.y"

         int     entier;
         char*   str;
         float reel;




/* Line 214 of yacc.c  */
#line 242 "synt.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 254 "synt.tab.c"

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
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    14,    21,    23,    25,
      27,    29,    31,    35,    40,    46,    49,    50,    51,    59,
      60,    64,    69,    76,    79,    80,    82,    86,    91,    95,
      99,   102,   106,   110,   114,   115,   120,   125,   130,   132,
     133,   134,   135,   142,   143,   150,   154,   157,   159,   161,
     162,   166,   168,   170,   172,   174,   176,   178,   180,   182,
     187,   192,   198,   200,   201,   202,   214,   216,   217,   222,
     224,   232,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   253,   254,   263,   271,   280,   282,   286,   291
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    58,    -1,    -1,    49,    52,
      29,    48,    46,    -1,    50,     4,    31,    41,    51,    42,
      -1,     5,    -1,     8,    -1,     9,    -1,    10,    -1,    31,
      -1,    31,    39,    51,    -1,    31,    41,    57,    42,    -1,
      31,    41,    57,    42,    51,    -1,    53,    59,    -1,    -1,
      -1,    50,    31,    54,    56,    38,    55,    53,    -1,    -1,
      39,    31,    56,    -1,    11,    41,    57,    42,    -1,    11,
      41,    57,    42,    39,    56,    -1,    36,    32,    -1,    -1,
      32,    -1,    32,    39,    32,    -1,     3,    31,    52,    30,
      -1,    60,    38,    59,    -1,    73,    38,    59,    -1,    75,
      59,    -1,    82,    38,    59,    -1,    85,    38,    59,    -1,
      86,    38,    59,    -1,    -1,    31,    40,    61,    59,    -1,
      31,    40,    71,    59,    -1,    31,    40,    72,    59,    -1,
      66,    -1,    -1,    -1,    -1,    66,    62,    63,    70,    64,
      61,    -1,    -1,    41,    61,    42,    70,    61,    65,    -1,
      41,    61,    42,    -1,    31,    67,    -1,    69,    -1,    68,
      -1,    -1,    41,    57,    42,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    37,    -1,     6,    -1,
       7,    -1,    12,    41,    31,    42,    -1,    13,    41,    74,
      42,    -1,    71,    39,    31,    39,    71,    -1,    71,    -1,
      -1,    -1,    14,    41,    78,    76,    42,    15,    59,    16,
      77,    59,    17,    -1,    61,    -1,    -1,    61,    79,    80,
      78,    -1,    72,    -1,    41,    78,    42,    80,    41,    78,
      42,    -1,    44,    81,    44,    -1,    24,    -1,    25,    -1,
      23,    -1,    22,    -1,    26,    -1,    27,    -1,    21,    -1,
      20,    -1,    -1,    -1,    18,    41,    83,    78,    84,    42,
      59,    19,    -1,    31,    40,    28,    31,    41,    87,    42,
      -1,    43,    41,    87,    42,    39,    41,    87,    42,    -1,
      31,    -1,    31,    39,    87,    -1,    31,    41,    57,    42,
      -1,    31,    41,    57,    42,    87,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   106,   109,   109,   112,   123,   124,   125,
     126,   129,   130,   131,   132,   137,   140,   140,   140,   141,
     145,   146,   147,   148,   149,   154,   155,   160,   164,   165,
     166,   167,   168,   169,   170,   175,   186,   198,   213,   323,
     323,   323,   323,   397,   397,   398,   401,   432,   435,   435,
     438,   441,   494,   514,   514,   514,   514,   517,   523,   533,
     534,   537,   538,   541,   548,   541,   571,   598,   598,   637,
     638,   641,   644,   645,   646,   647,   648,   649,   650,   651,
     654,   654,   654,   671,   682,   685,   686,   687,   688
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_program", "mc_routine", "mc_entier",
  "string", "booleen", "mc_real", "mc_logical", "mc_character",
  "mc_dimension", "mc_read", "mc_write", "mc_if", "mc_then", "mc_else",
  "mc_endif", "mc_dowhile", "mc_enddo", "mc_or", "mc_and", "mc_gt",
  "mc_ge", "mc_eq", "mc_ne", "mc_le", "mc_lt", "mc_call", "mc_endr",
  "mc_end", "IDF", "integr", "floatt", "add", "sub", "mul", "divv", "pvg",
  "vrg", "aff", "po", "pf", "mc_equivalence", "point", "$accept", "S",
  "FUNCTION", "$@1", "HEADER", "TYPE", "PARAMETRE", "BODY", "DEC", "$@2",
  "$@3", "ListIDF", "TAILLE", "PROGRAM", "INST", "AFFECTATION",
  "EXPRESSION", "$@4", "$@5", "$@6", "$@7", "VALEUR", "TABL", "TAB",
  "NUMBER", "OPERATION", "CHAINE", "LOGICAL", "ES", "STRING", "CONDITON",
  "$@8", "$@9", "EXPCDTT", "$@10", "CDTT", "CDT", "LOOP", "$@11", "$@12",
  "CALLING", "EQUIV", "PARAMETRE1", 0
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
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    48,    47,    49,    50,    50,    50,
      50,    51,    51,    51,    51,    52,    54,    55,    53,    53,
      56,    56,    56,    56,    56,    57,    57,    58,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    61,    62,
      63,    64,    61,    65,    61,    61,    66,    66,    67,    67,
      68,    69,    69,    70,    70,    70,    70,    71,    72,    73,
      73,    74,    74,    76,    77,    75,    78,    79,    78,    78,
      78,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      83,    84,    82,    85,    86,    87,    87,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     5,     6,     1,     1,     1,
       1,     1,     3,     4,     5,     2,     0,     0,     7,     0,
       3,     4,     6,     2,     0,     1,     3,     4,     3,     3,
       2,     3,     3,     3,     0,     4,     4,     4,     1,     0,
       0,     0,     6,     0,     6,     3,     2,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     5,     1,     0,     0,    11,     1,     0,     4,     1,
       7,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     8,     7,     8,     1,     3,     4,     5
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
      80,     0,     0,    34,    34,    30,    34,    34,    34,     0,
       0,     0,     0,     0,     5,     0,    57,    62,     0,    58,
      49,    51,    52,     0,    66,    38,    47,    69,    63,     0,
       0,     0,    34,    34,    34,    85,     0,    28,    29,    31,
      32,    33,    11,     0,     0,    23,    24,    17,    59,     0,
      60,     0,    46,    48,    67,     0,     0,    40,     0,    81,
       0,     0,    35,    36,    37,     0,     0,     0,     0,     0,
       6,    25,     0,    20,    19,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,    12,     0,
       0,    21,    18,     0,    50,    53,    54,    55,    56,     0,
       0,    79,    78,    75,    74,    72,    73,    76,    77,     0,
      68,    41,    34,    34,     0,    87,     0,    13,    26,    24,
      61,    43,     0,    71,     0,     0,     0,    83,    88,     0,
      14,    22,    44,     0,    42,    64,    82,    84,    70,    34,
       0,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    36,     8,    13,    83,    14,    15,    35,
     114,    53,   112,    10,    26,    27,    64,    97,   121,   164,
     172,    65,    92,    93,    66,   139,    57,    67,    28,    58,
      29,    98,   179,    68,    96,   120,   149,    30,    69,   123,
      31,    32,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int8 yypact[] =
{
      73,   -24,  -104,  -104,  -104,  -104,    23,  -104,    43,    24,
    -104,    43,  -104,    -4,     2,    49,     4,    19,  -104,  -104,
      14,    17,    18,    38,    57,    58,  -104,    27,    60,    49,
      63,    65,    66,    64,  -104,    -3,    73,    75,    89,     9,
    -104,     6,    76,    49,    49,  -104,    49,    49,    49,    77,
      68,    78,    80,    74,  -104,    71,  -104,    79,    72,  -104,
      81,  -104,  -104,     9,    82,    50,  -104,  -104,  -104,     9,
      84,   -11,    49,    49,    49,    25,    85,  -104,  -104,  -104,
    -104,  -104,    55,    86,    87,  -104,    -3,  -104,  -104,    90,
    -104,    87,  -104,  -104,    88,    91,    92,  -104,    93,  -104,
      96,    88,  -104,  -104,  -104,    76,    87,    95,    77,    87,
    -104,    99,    97,  -104,    43,   101,   100,    54,    92,    48,
       9,    54,   102,   103,    76,  -104,   104,   106,  -104,   107,
     109,   105,  -104,    89,  -104,  -104,  -104,  -104,  -104,   -11,
     110,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,   108,
    -104,  -104,    49,    49,   111,    76,    76,    77,  -104,    -3,
    -104,  -104,     9,  -104,   -11,   113,   112,  -104,  -104,   114,
    -104,  -104,  -104,   115,  -104,  -104,  -104,  -104,  -104,    49,
     126,  -104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,   118,  -104,  -104,  -104,    10,  -103,   121,    34,  -104,
    -104,   -82,   -80,  -104,   -29,  -104,   -39,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,    -5,   -40,   117,  -104,  -104,
    -104,  -104,  -104,   -60,  -104,    37,  -104,  -104,  -104,  -104,
    -104,  -104,   -99
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -68
static const yytype_int16 yytable[] =
{
      45,    73,    72,    95,   113,   128,   125,    11,    50,    99,
       9,   116,    56,    59,    77,    78,    59,    79,    80,    81,
      60,    61,    62,    12,    94,   154,   126,    18,    16,   129,
      71,    19,   101,    51,    70,    33,    52,    60,    61,    62,
      60,    61,    62,   102,   103,   104,     9,    71,     2,    34,
      63,     3,     4,     5,   170,    37,   168,   169,    38,    39,
     150,    20,    21,    22,   105,    43,   106,    23,   141,   142,
     143,   144,   145,   146,   147,   148,     1,   171,     2,    40,
      24,     3,     4,     5,   -39,   -39,   -39,   -39,   135,   136,
     137,   138,    25,   160,   108,    56,   109,    41,    44,    42,
     161,    46,   173,    47,    48,    49,    55,    75,    82,    84,
      85,    86,    87,    88,    90,   100,   151,   152,    89,   111,
       0,   115,    91,   165,   166,   174,   -67,   107,   110,   175,
     117,   176,    17,   118,   127,   122,   119,   124,   130,   131,
     133,   158,   134,   181,   159,   153,   155,   156,   132,   157,
     180,   162,   163,   167,    54,   140,   177,   178,    74
};

static const yytype_int16 yycheck[] =
{
      29,    41,    41,    63,    86,   108,   105,    31,    11,    69,
       0,    91,     6,     7,    43,    44,     7,    46,    47,    48,
      31,    32,    33,     0,    63,   124,   106,    31,     4,   109,
      41,    29,    71,    36,    28,    31,    39,    31,    32,    33,
      31,    32,    33,    72,    73,    74,    36,    41,     5,    30,
      41,     8,     9,    10,   157,    41,   155,   156,    41,    41,
     120,    12,    13,    14,    39,    38,    41,    18,    20,    21,
      22,    23,    24,    25,    26,    27,     3,   159,     5,    41,
      31,     8,     9,    10,    34,    35,    36,    37,    34,    35,
      36,    37,    43,   133,    39,     6,    41,    40,    38,    41,
     139,    38,   162,    38,    38,    41,    31,    31,    31,    41,
      32,    31,    38,    42,    42,    31,   121,    15,    39,    32,
      -1,    31,    41,   152,   153,   164,    44,    42,    42,    16,
      42,    19,    11,    42,    39,    42,    44,    41,    39,    42,
      39,    32,    42,    17,    39,    42,    42,    41,   114,    42,
     179,    41,    44,    42,    36,   118,    42,    42,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     8,     9,    10,    46,    47,    49,    50,
      58,    31,     0,    50,    52,    53,     4,    52,    31,    29,
      12,    13,    14,    18,    31,    43,    59,    60,    73,    75,
      82,    85,    86,    31,    30,    54,    48,    41,    41,    41,
      41,    40,    41,    38,    38,    59,    38,    38,    38,    41,
      11,    36,    39,    56,    46,    31,     6,    71,    74,     7,
      31,    32,    33,    41,    61,    66,    69,    72,    78,    83,
      28,    41,    61,    71,    72,    31,    87,    59,    59,    59,
      59,    59,    31,    51,    41,    32,    31,    38,    42,    39,
      42,    41,    67,    68,    61,    78,    79,    62,    76,    78,
      31,    61,    59,    59,    59,    39,    41,    42,    39,    41,
      42,    32,    57,    56,    55,    31,    57,    42,    42,    44,
      80,    63,    42,    84,    41,    87,    57,    39,    51,    57,
      39,    42,    53,    39,    42,    34,    35,    36,    37,    70,
      80,    20,    21,    22,    23,    24,    25,    26,    27,    81,
      78,    70,    15,    42,    87,    42,    41,    42,    32,    39,
      71,    61,    41,    44,    64,    59,    59,    42,    87,    87,
      51,    56,    65,    78,    61,    16,    19,    42,    42,    77,
      59,    17
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
#line 106 "synt.y"
    {printf("prog syntaxiquement correct"); YYACCEPT;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 109 "synt.y"
    {rechercher ((yyvsp[(3) - (3)].str),"Mot cle ","","0", 1,tss);tss++; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 112 "synt.y"
    { 
        callIndex++; 
        initializeCall(callIndex,(yyvsp[(3) - (6)].str),3);
        rechercher ((yyvsp[(2) - (6)].str),"Mot cle ","","0", 1,tss); 
        rechercher ((yyvsp[(3) - (6)].str),"IDF","Identifier","0", 0,tss);
        modifyType((yyvsp[(3) - (6)].str),saveType,tss); 
        rechercher ((yyvsp[(4) - (6)].str),"Separateur","0","0", 2,tss); 
        rechercher ((yyvsp[(6) - (6)].str),"Separateur","0","0", 2,tss);
;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 123 "synt.y"
    {saveType=(yyvsp[(1) - (1)].str);rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 124 "synt.y"
    {saveType=(yyvsp[(1) - (1)].str);rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 125 "synt.y"
    {saveType=(yyvsp[(1) - (1)].str);rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 126 "synt.y"
    {saveType=(yyvsp[(1) - (1)].str);rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 129 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"IDF","Identifier","0", 0,tss); nbParams++;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 130 "synt.y"
    {rechercher ((yyvsp[(1) - (3)].str),"IDF","Identifier","0", 0,tss); rechercher ((yyvsp[(2) - (3)].str),"Separateur","0","0", 2,tss); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 131 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"IDF","Identifier","0", 0,tss);rechercher ((yyvsp[(2) - (4)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(4) - (4)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 132 "synt.y"
    {rechercher ((yyvsp[(1) - (5)].str),"IDF","Identifier","0", 0,tss);rechercher ((yyvsp[(2) - (5)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(4) - (5)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 140 "synt.y"
    {rechercher ((yyvsp[(2) - (2)].str),"IDF","Identifier","0", 0,tss); modifyType((yyvsp[(2) - (2)].str),saveType,tss);  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 140 "synt.y"
    {rechercher ((yyvsp[(5) - (5)].str),"Separateur","0","0", 2,tss);sprintf(chaine1, "%d",(int)idfNewValue1);if(zz == 1)Misajour((yyvsp[(2) - (5)].str),(int)tss,chaine1) ;if(kk == 1)modmat((yyvsp[(2) - (5)].str),nb11,nb22,i);kk=0;if(bb == 1)i++;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 145 "synt.y"
    { rechercher ((yyvsp[(1) - (3)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(2) - (3)].str),"IDF","Identifier","0", 0,tss); modifyType((yyvsp[(2) - (3)].str),saveType,tss); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 146 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"Mot cle ","","0", 1,tss);rechercher ((yyvsp[(2) - (4)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(4) - (4)].str),"Separateur","0","0", 2,tss);zz=1;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 147 "synt.y"
    {rechercher ((yyvsp[(1) - (6)].str),"Mot cle ","","0", 1,tss);rechercher ((yyvsp[(2) - (6)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(4) - (6)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(5) - (6)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 148 "synt.y"
    {rechercher ((yyvsp[(1) - (2)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 154 "synt.y"
    {strcpy(typeval,"INTEGER");  if((yyvsp[(1) - (1)].entier)<0 ){printf("Erreur semantique : Indice Negatif %d,%d\n",nb_ligne,nbCol);exit(EXIT_FAILURE);}intIdfNewValue = (yyvsp[(1) - (1)].entier) ;idfNewValue1 = (int)intIdfNewValue;;intIdfNewValue = (yyvsp[(1) - (1)].entier) ;idfNewValue2 = (int)intIdfNewValue;vv1=1;bb=0;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 155 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur","0","0", 2,tss);if((yyvsp[(1) - (3)].entier)<0 || (yyvsp[(3) - (3)].entier)<0) {printf("Erreur semantique : Indice Negatif %d,%d\n",nb_ligne,nbCol); exit(EXIT_FAILURE); }intIdfNewValue = (yyvsp[(1) - (3)].entier) ;nb11 = (int)intIdfNewValue; intIdfNewValue = (yyvsp[(3) - (3)].entier) ;nb22 = (int)intIdfNewValue;vv1=0;if(c==1)bb=1;c=1;kk=1;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 160 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"Mot cle ","","0", 1,tss); rechercher ((yyvsp[(2) - (4)].str),"IDF","Identifier","0", 0,tss); rechercher ((yyvsp[(4) - (4)].str),"Mot cle ","","0", 1,tss); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 164 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 165 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 167 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 168 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 169 "synt.y"
    {rechercher ((yyvsp[(2) - (3)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 175 "synt.y"
    {
                rechercher1 ((yyvsp[(1) - (4)].str),"IDF","Identifier","0", 0,tss); 
                if (incompatibiliteDeType((yyvsp[(1) - (4)].str),typeval,tss) == 1) {
                        printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); 
                        exit(EXIT_FAILURE);
                }
                       
                rechercher ((yyvsp[(2) - (4)].str),"Separateur","0","0", 2,tss); 
                Misajour((yyvsp[(1) - (4)].str),(int)tss,idfNewValue); 
                quadr("=",saveCst,"",(yyvsp[(1) - (4)].str));
            ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 186 "synt.y"
    {
                rechercher1 ((yyvsp[(1) - (4)].str),"IDF","Identifier","0", 0,tss); 
                printf("%s \t %s \n",(yyvsp[(1) - (4)].str),typeval);
                if (incompatibiliteDeType((yyvsp[(1) - (4)].str),typeval,tss) == 1) {
                        printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); 
                        exit(EXIT_FAILURE);
                }
                rechercher ((yyvsp[(2) - (4)].str),"Separateur","0","0", 2,tss);
                Misajour((yyvsp[(1) - (4)].str),(int)tss,idfNewValue);
                strcpy(saveCst,idfNewValue);
                quadr("=",saveCst,"",(yyvsp[(1) - (4)].str));
                ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 198 "synt.y"
    {
                rechercher1 ((yyvsp[(1) - (4)].str),"IDF","Identifier","0", 0,tss);  
                printf("%s \t %s \n",(yyvsp[(1) - (4)].str),typeval);
                if (incompatibiliteDeType((yyvsp[(1) - (4)].str),typeval,tss) == 1) {
                        printf("Erreur semantique: Incompatibilite de type a la ligne %d colonne %d\n", nb_ligne, col); 
                        exit(EXIT_FAILURE);
                }
                        
                rechercher ((yyvsp[(2) - (4)].str),"Separateur","0","0", 2,tss);
                Misajour((yyvsp[(1) - (4)].str),(int)tss,idfNewValue); 
                strcpy(saveCst,idfNewValue);
                quadr("=",saveCst,"",(yyvsp[(1) - (4)].str));
                ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 213 "synt.y"
    {
                        if(only_one == 0 ){
                                if(strcmp(op1,"")==0 && !h){
                                        strcpy(saveCst,op1);}else{if(h){h=0;}}
                        }else{
                                if(!mull){
                                        if(x==1){
                                                if(p){
                                                value2=atoi((char*)getValueOfIDF(op1,tss));
                                                        if (strcmp(saveOP, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(saveOP, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(saveOP, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(saveOP, "/") == 0) {
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; // Exit with an error code
                                                        }}                                      

                                                quadr(medOp,op1,"TEMP",temp1);
                                                strcpy(saveCst,temp1);
                                                sprintf(idfNewValue,"%d",resultI);
                                                }else{
                                                        value2=resultI;
                                                        if (strcmp(saveOP, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(saveOP, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(saveOP, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(saveOP, "/") == 0) {
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; // Exit with an error code
                                                        }}                                      
                                                        quadr(saveOP,temp1,op1,temp1);strcpy(saveCst,temp1);sprintf(idfNewValue,"%d",resultI);}
                                        }else{  
                                                value2=atoi((char*)getValueOfIDF(med,tss));
                                                        if (strcmp(saveOP, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(saveOP, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(saveOP, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(saveOP, "/") == 0) {
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; // Exit with an error code
                                                        }}                                      
                                                quadr(saveOP,op1,med,temp1);
                                                strcpy(saveCst,temp1);sprintf(idfNewValue,"%d",resultI);
                                        }
                                }else{
                                        if (lol){
                                                value2=resultI;
                                                        if (strcmp(medOp, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(medOp, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(medOp, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(medOp, "/") == 0) {
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; // Exit with an error code
                                                        }}                                      
                                                quadr(medOp,temp1,tempMul,temp1);lol=0;strcpy(saveCst,temp1);
                                                sprintf(idfNewValue,"%d",resultI);
                                        }
                                        if(strcmp(tempMul,"")!=0){
                                                if(strcmp(med2,"")!=0){if(a){
                                                        value2=resultI;
                                                        if(strcmp((char*)getCodeOfEntity(med2,tss),"IDF")==0)
                                                        value1=atoi((char*)getValueOfIDF(med2));
                                                        else value1=atoi(med2);
                                                                if (strcmp(medOp, "+") == 0) {
                                                                resultI = value2 + value1;
                                                        } else if (strcmp(medOp, "-") == 0) {
                                                                resultI = value2 - value1;
                                                        } else if (strcmp(medOp, "*") == 0) {
                                                                resultI = value2 * value1;
                                                        } else if (strcmp(medOp, "/") == 0) {
                                                                if (value1 != 0) {
                                                                resultI = value2 / value1;
                                                                } else {
                                                                printf("Error: Division by zero.\n");
                                                                exit(EXIT_FAILURE);
                                                                err=1; // Exit with an error code
                                                                }}                                      
                                                         quadr(medOp,med2,tempMul,temp1);
                                                         strcpy(saveCst,temp1);}}
                                                        sprintf(idfNewValue,"%d",resultI);
                                        }
                                }
                        }
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 323 "synt.y"
    {strcpy(medType,saveType);strcpy(med,op1);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 323 "synt.y"
    {only_one = 1;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 323 "synt.y"
    {if(strcmp(saveOP,"+")==0 ||strcmp(saveOP,"-")==0){
                                                                                                if(!mull){printf("");
                                                                                                if(strcmp(med2,"")!=0){
                                                                                                        if(x){
                                                                                                                value2=resultI;
                                                                                                                        if (strcmp(saveOP, "+") == 0) {
                                                                                                                        resultI = value2 + value1;
                                                                                                                } else if (strcmp(saveOP, "-") == 0) {
                                                                                                                        resultI = value2 - value1;
                                                                                                                } else if (strcmp(saveOP, "*") == 0) {
                                                                                                                        resultI = value2 * value1;
                                                                                                                } else if (strcmp(saveOP, "/") == 0) {
                                                                                                                        if (value1 != 0) {
                                                                                                                        resultI = value2 / value1;
                                                                                                                        } else {
                                                                                                                        printf("Error: Division by zero.\n");
                                                                                                                        exit(EXIT_FAILURE);
                                                                                                                        err=1; // Exit with an error code
                                                                                                                        }}                                      
                                                                                                                quadr(medOp,temp1,med,temp1);
                                                                                                        }else{
                                                                                                                value2=atoi((char*)getValueOfIDF(med2,tss));
                                                                                                                        if (strcmp(saveOP, "+") == 0) {
                                                                                                                        resultI = value2 + value1;
                                                                                                                } else if (strcmp(saveOP, "-") == 0) {
                                                                                                                        resultI = value2 - value1;
                                                                                                                } else if (strcmp(saveOP, "*") == 0) {
                                                                                                                        resultI = value2 * value1;
                                                                                                                } else if (strcmp(saveOP, "/") == 0) {
                                                                                                                        if (value1 != 0) {
                                                                                                                        resultI = value2 / value1;
                                                                                                                        } else {
                                                                                                                        printf("Error: Division by zero.\n");
                                                                                                                        exit(EXIT_FAILURE);
                                                                                                                        err=1; // Exit with an error code
                                                                                                                        }}                                      
                                                                                                                quadr(medOp,med2,med,temp1);x=1;
                                                                                                        }
                                                                                                        lol = 1;
                                                                                                }
                                                                                                else{
                                                                                                        strcpy(med2,med);
                                                                                                }}
                                                                                                else{ 
                                                                                                        if(strcmp(med2,"")!=0){
                                                                                                                        value2=atoi((char*)getValueOfIDF(med2,tss));
                                                                                                                                if (strcmp(saveOP, "+") == 0) {
                                                                                                                                resultI = value2 + value1;
                                                                                                                        } else if (strcmp(saveOP, "-") == 0) {
                                                                                                                                resultI = value2 - value1;
                                                                                                                        } else if (strcmp(saveOP, "*") == 0) {
                                                                                                                                resultI = value2 * value1;
                                                                                                                        } else if (strcmp(saveOP, "/") == 0) {
                                                                                                                                // Ensure value2 is not zero before performing division
                                                                                                                                if (value1 != 0) {
                                                                                                                                resultI = value2 / value1;
                                                                                                                                } else {
                                                                                                                                printf("Error: Division by zero.\n");
                                                                                                                                exit(EXIT_FAILURE);
                                                                                                                                err=1; // Exit with an error code
                                                                                                                                }}                                      
                                                                                                                        quadr(medOp,med2,"TEMP",temp1);
                                                                                                                        
                                                                                                                        strcpy(med2,"TEMP");
                                                                                                                }else{
                                                                                                                        strcpy(med2,"TEMP");p=1;
                                                                                                                        }mull=0;x=1;strcpy(tempMul,"");
                                                                                                }strcpy(medOp,saveOP);a=0;
                                                                                                }
                                                                                                if(strcmp(saveOP,"*")==0 || strcmp(saveOP,"/")==0){
                                                                                                                mull = 1;a=1;

                                                                                                        }
                                                                			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 396 "synt.y"
    {strcpy(saveOP,"");strcpy(medOp,"");strcpy(med2,"");strcpy(med,"");strcpy(tempMul,"");strcpy(op1,"");lol=0;mull=0;x=0;a=0;p=0;only_one = 0;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 397 "synt.y"
    {rechercher ((yyvsp[(1) - (5)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(3) - (5)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 397 "synt.y"
    {strcpy(saveOP,"");strcpy(medOp,"");strcpy(med2,"");strcpy(med,"");strcpy(tempMul,"");strcpy(op1,"");lol=0;mull=0;x=0;a=0;p=0;only_one = 0;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 398 "synt.y"
    {rechercher ((yyvsp[(1) - (3)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(3) - (3)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 401 "synt.y"
    {
                rechercher1 ((yyvsp[(1) - (2)].str),"IDF","Identifier","0", 0,tss);  
                strcpy(typeval,(char*)printTypeOfIDF((yyvsp[(1) - (2)].str))); 
                strcpy(idfNewValue, (char*)getValueOfIDF((yyvsp[(1) - (2)].str), tss));
                strcpy(saveCst,(yyvsp[(1) - (2)].str));
                strcpy(op1,saveCst);
                value1=atoi(idfNewValue);
                
                if(mull==1){printf("");
                if(strcmp((char*)getCodeOfEntity(med,tss),"IDF")==0)
                {value2=atoi((char*)getValueOfIDF(med,tss));}
                else {value2=atoi(med);}
                        if (strcmp(saveOP, "+") == 0) {
                        resultI = value2 + value1;
                } else if (strcmp(saveOP, "-") == 0) {
                        resultI = value2 - value1;
                } else if (strcmp(saveOP, "*") == 0) {
                        resultI = value2 * value1;
                } else if (strcmp(saveOP, "/") == 0) {
                        if (value1 != 0) {
                        resultI = value2 / value1;
                        } else {
                        printf("Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                        err=1; 
                        }}                                      
                quadr(saveOP,med,op1,"TEMP");
                strcpy(tempMul,"TEMP");strcpy(saveCst,op1);
                sprintf(idfNewValue,"%d",resultI);
             } ;strcpy(xx, (char*)getValueOfIDF((yyvsp[(1) - (2)].str), tss));xx1=atoi(xx) ;printf("");if( vv1 ==1 && idfNewValue2 > xx1) {printf("Erreur symantique : indice hors intervale\n");exit(EXIT_FAILURE);}   vv1=0;jj=nbb2((yyvsp[(1) - (2)].str));if (bb == 1  && (nb11 > nbb1((yyvsp[(1) - (2)].str)) || nb22 > nbb2((yyvsp[(1) - (2)].str))))printf("\nerreur dans la matrice la taille non disponible\n");bb=0;
                ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 438 "synt.y"
    {rechercher ((yyvsp[(1) - (3)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(3) - (3)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 441 "synt.y"
    {    
                        strcpy(typeval, "INTEGER");
                        sprintf(idfNewValue, "%d", (yyvsp[(1) - (1)].entier));
                        sprintf(saveCst,"%d",(yyvsp[(1) - (1)].entier));
                        strcpy(op1,saveCst);
                        value1=(yyvsp[(1) - (1)].entier);
                        if(strcmp(saveOP,"")!=0){
                                if(strcmp(saveType,medType)!=0){
                                printf("error at %d %d,types error\n",nbLigne-1,nbCol);err=1;
                                }
                        }
                        if(mull==1){
                                if(strcmp(tempMul,"")==0){ 
                                        value2=atoi((char*)getValueOfIDF(med,tss));
                                        if (strcmp(saveOP, "+") == 0) {
                                        resultI = value2 + value1;
                                        } else if (strcmp(saveOP, "-") == 0) {
                                        resultI = value2 - value1;
                                        } else if (strcmp(saveOP, "*") == 0) {
                                        resultI = value2 * value1;
                                        } else if (strcmp(saveOP, "/") == 0) {
                                        // Ensure value2 is not zero before performing division
                                                if (value1 != 0) {
                                                resultI = value2 / value1;
                                                } else {
                                                printf("Error: Division by zero.\n");
                                                exit(EXIT_FAILURE);
                                                err=1; 
                                                }}                                      
                                        quadr(saveOP,med,op1,"TEMP");
                                        strcpy(tempMul,"TEMP");strcpy(saveCst,op1);
                                        sprintf(idfNewValue,"%d",resultI);
                                }else{          
                                                value2=resultI;
                                                        if (strcmp(saveOP, "+") == 0) {
                                                        resultI = value2 + value1;
                                                } else if (strcmp(saveOP, "-") == 0) {
                                                        resultI = value2 - value1;
                                                } else if (strcmp(saveOP, "*") == 0) {
                                                        resultI = value2 * value1;
                                                } else if (strcmp(saveOP, "/") == 0) {
                                                   
                                                        if (value1 != 0) {
                                                        resultI = value2 / value1;
                                                        } else {
                                                        printf("Error: Division by zero.\n");
                                                        exit(EXIT_FAILURE);
                                                        err=1; 
                                                        }}                                      
                                                quadr(saveOP,tempMul,op1,"TEMP"); printf("%s\t %s \t %s\n",tempMul,saveOP,op1);strcpy(saveCst,op1);
                                        }
                        }
                ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 494 "synt.y"
    {
                        strcpy(typeval, "REAL");
                        sprintf(idfNewValue, "%f", (yyvsp[(1) - (1)].reel));
                        sprintf(saveCst,"%f",(yyvsp[(1) - (1)].reel));
                        strcpy(op1,saveCst);
                        if(strcmp(saveOP,"")!=0){
                                if(strcmp(saveType,medType)!=0){
                                }
                        }
                        if(mull==1){
                                if(strcmp(tempMul,"")==0){
                                        quadr(saveOP,med,op1,"TEMP");
                                        strcpy(tempMul,"TEMP");
                        }else{
                                        quadr(saveOP,tempMul,op1,"TEMP");
                                }
                        }
                ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 514 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Separateur","0","0", 2,tss); strcpy(saveOP,(yyvsp[(1) - (1)].str));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 514 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Separateur","0","0", 2,tss); strcpy(saveOP,(yyvsp[(1) - (1)].str));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 514 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Separateur","0","0", 2,tss); strcpy(saveOP,(yyvsp[(1) - (1)].str));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 514 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Separateur","0","0", 2,tss); strcpy(saveOP,(yyvsp[(1) - (1)].str));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 517 "synt.y"
    {
                        strcpy(typeval,"CHARACTER");
                        sprintf(idfNewValue, "%s", (yyvsp[(1) - (1)].str));
                ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 523 "synt.y"
    {strcpy(typeval,"LOGICAL");
        sprintf(idfNewValue, "%s", (yyvsp[(1) - (1)].str));
        
        if(strcmp(idfNewValue,"TRUE")==0)
                strcpy(saveCst,"1");
        else
                strcpy(saveCst,"0");
        h=1;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 533 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"Mot cle ","","0", 1,tss); rechercher ((yyvsp[(2) - (4)].str),"Separateur","0","0", 2,tss);rechercher1 ((yyvsp[(3) - (4)].str),"IDF","Identifier","0", 0,tss); rechercher ((yyvsp[(4) - (4)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 534 "synt.y"
    {rechercher ((yyvsp[(1) - (4)].str),"Mot cle ","","0", 1,tss); rechercher ((yyvsp[(2) - (4)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(4) - (4)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 537 "synt.y"
    {rechercher ((yyvsp[(2) - (5)].str),"Separateur","0","0", 2,tss);rechercher1 ((yyvsp[(3) - (5)].str),"IDF","Identifier","0", 0,tss); rechercher ((yyvsp[(4) - (5)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 541 "synt.y"
    {deb_else[i_else]=qc;
                                        i_else++;
                                        quadr("BZ","",saveCst,"");
                                        sprintf(tmp,"%d",qc);
                                        ajour_quad(or_b,1,tmp);
                                        ajour_quad(or_b+1,1,tmp);
                                        ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 548 "synt.y"
    {
                                        fin_if[i_if]=qc;
                                        i_if++;
                                        quadr("BR","","","");
                                        sprintf(tmp,"%d",qc);
                                        ajour_quad(deb_else[i_else-1],1,tmp);
                                        i_else--;
                                        AND_or_OR=0;
                                        ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 557 "synt.y"
    {
                                        rechercher ((yyvsp[(1) - (11)].str),"Mot cle ","","0", 1,tss); 
                                        rechercher ((yyvsp[(2) - (11)].str),"Separateur","0","0", 2,tss);
                                        rechercher ((yyvsp[(5) - (11)].str),"Separateur","0","0", 2,tss);
                                        rechercher ((yyvsp[(6) - (11)].str),"Mot cle ","","0", 1,tss);
                                        rechercher ((yyvsp[(8) - (11)].str),"Mot cle ","","0", 1,tss);
                                        rechercher ((yyvsp[(11) - (11)].str),"Mot cle ","","0", 1,tss);
                                        sprintf(tmp,"%d",qc);  
                                        ajour_quad(fin_if[i_if-1],1,tmp);
                                        i_if--;
                                        AND_or_OR=0;
                                        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 571 "synt.y"
    {
                                        if(AND_or_OR!=0){
                                                if(AND_or_OR==1){
                                                        and_b=qc;
                                                        quadr("BZ","",saveCst);
                                                        quadr("=","1","","TEMP");
                                                        and_f=qc;
                                                        quadr("BR","","","");
                                                        sprintf(tmp,"%d",qc);
                                                        ajour_quad(and_b,1,tmp);
                                                        ajour_quad(and_b+1,1,tmp);
                                                        quadr("=","0","","TEMP");
                                                        sprintf(tmp,"%d",qc);
                                                        ajour_quad(and_f,1,tmp);
                                                }else{
                                                        or_b=qc;
 //                                                       quadr("BNZ","",s,"");
                                                        quadr("BNZ","",saveCst);
                                                        quadr("=","0","","TEMP");
                                                        or_f=qc;
                                                        quadr("BR","","","");
                                                        sprintf(tmp,"%d",qc);ajour_quad(or_b,1,tmp);ajour_quad(or_b+1,1,tmp);
                                                        quadr("=","1","","TEMP");sprintf(tmp,"%d",qc);
                                                        ajour_quad(or_f,1,tmp);
                                                }
                                        }
                                        ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 598 "synt.y"
    {if(strcmp(saveCst,"TEMP")==0){
                                                ajour_quad(qc-1,3,"TEMP2");
                                                strcpy(s,"TEMP2");
                                        } else{
                                                strcpy(s,saveCst);
                                                }
                                                if(AND_or_OR!=0){
                                                        if(AND_or_OR==1){
                                                                and_b=qc;
//                                                                quadr("BZ","",s,"");
                                                                quadr("BZ","",saveCst,"");
                                                                quadr("=","1","","TEMP");
                                                                and_f=qc;
                                                                quadr("BR","","","");
                                                                sprintf(tmp,"%d",qc);
                                                                ajour_quad(and_b,1,tmp);
                                                                ajour_quad(and_b+1,1,tmp);
                                                                quadr("=","0","","TEMP");
                                                                sprintf(tmp,"%d",qc);
                                                                ajour_quad(and_f,1,tmp);
                                                        }else{
                                                                strcpy(saveCst,"TEMP");
                                                                or_b=qc;
                                                                printf("%s\n",s);
                                                                quadr("BNZ","",saveCst,"");
                                                                quadr("BNZ","",saveCst,"");
                                                        }
                                                }if(o){strcpy(saveCst,"TEMP");ajour_quad(qc-3,3,"TEMP2");printf("\n\n\n\nyaaaaaaaaaaaaaaa");}
                                                o = 1;
                                                ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 628 "synt.y"
    {
                                                if(strcmp(saveOpLo,"GT")==0){quadr(">",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"GE")==0){quadr(">=",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"LT")==0){quadr("<",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"LE")==0){quadr("<=",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"EQ")==0){quadr("==",s,saveCst,"TEMP");}
                                                if(strcmp(saveOpLo,"NE")==0){quadr("!=",s,saveCst,"TEMP");}
                                                strcpy(saveCst,"TEMP");o=0;
                                                ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 638 "synt.y"
    {rechercher ((yyvsp[(1) - (7)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(3) - (7)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(5) - (7)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(7) - (7)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 641 "synt.y"
    {rechercher ((yyvsp[(1) - (3)].str),"Separateur","0","0", 2,tss); rechercher ((yyvsp[(3) - (3)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 644 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);strcpy(saveOpLo,(yyvsp[(1) - (1)].str));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 645 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);strcpy(saveOpLo,(yyvsp[(1) - (1)].str));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 646 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);strcpy(saveOpLo,(yyvsp[(1) - (1)].str));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 647 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);strcpy(saveOpLo,(yyvsp[(1) - (1)].str));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 648 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);strcpy(saveOpLo,(yyvsp[(1) - (1)].str));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 649 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);strcpy(saveOpLo,(yyvsp[(1) - (1)].str));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 650 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);strcpy(saveOpLo,(yyvsp[(1) - (1)].str));AND_or_OR=1;;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 651 "synt.y"
    {rechercher ((yyvsp[(1) - (1)].str),"Mot cle ","","0", 1,tss);strcpy(saveOpLo,(yyvsp[(1) - (1)].str));AND_or_OR=-1;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 654 "synt.y"
    {Deb_while=qc;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 654 "synt.y"
    {
                                        Fin_while=qc;
                                        quadr("BZ","",saveCst,"");
                                                ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 658 "synt.y"
    {
                                                                        rechercher ((yyvsp[(1) - (8)].str),"Mot cle ","","0", 1,tss);
                                                                        rechercher ((yyvsp[(2) - (8)].str),"Separateur","0","0", 2,tss);
                                                                        rechercher ((yyvsp[(6) - (8)].str),"Separateur","0","0", 2,tss);
                                                                        rechercher ((yyvsp[(8) - (8)].str),"Mot cle ","","0", 1,tss);
                                                                        sprintf(tmp,"%d",Deb_while);
                                                                        quadr("BR",tmp,"","");
                                                                        sprintf(tmp,"%d",qc);
                                                                        ajour_quad(Fin_while,1,tmp);

                                                                ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 671 "synt.y"
    {
                if(functionExists((yyvsp[(4) - (7)].str),nbParams)==0) {printf("Erreur semantique : Fonction non declarer %d,%d\n",nb_ligne,nbCol); exit(EXIT_FAILURE);};
                if(functionExists((yyvsp[(4) - (7)].str),nbParams)==2) {printf("Erreur semantique : Nombre de parametre %d,%d\n",nb_ligne,nbCol); exit(EXIT_FAILURE);};
                rechercher1 ((yyvsp[(1) - (7)].str),"IDF","Identifier","0", 0,tss); 
                rechercher ((yyvsp[(2) - (7)].str),"Separateur","0","0", 2,tss);
                rechercher ((yyvsp[(3) - (7)].str),"Mot cle ","","0", 1,tss);
                rechercher ((yyvsp[(5) - (7)].str),"Separateur","0","0", 2,tss);
                rechercher ((yyvsp[(7) - (7)].str),"Separateur","0","0", 2,tss);
        ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 682 "synt.y"
    {rechercher ((yyvsp[(1) - (8)].str),"Mot cle ","","0", 1,tss);rechercher ((yyvsp[(4) - (8)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(5) - (8)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(6) - (8)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(8) - (8)].str),"Separateur","0","0", 2,tss);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 685 "synt.y"
    {rechercher1 ((yyvsp[(1) - (1)].str),"IDF","Identifier","0", 0,tss); nbParams=1;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 686 "synt.y"
    {rechercher1 ((yyvsp[(1) - (3)].str),"IDF","Identifier","0", 0,tss); rechercher ((yyvsp[(2) - (3)].str),"Separateur","0","0", 2,tss);  nbParams++;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 687 "synt.y"
    {rechercher1 ((yyvsp[(1) - (4)].str),"IDF","Identifier","0", 0,tss);rechercher ((yyvsp[(2) - (4)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(4) - (4)].str),"Separateur","0","0", 2,tss); ;strcpy(xx, (char*)getValueOfIDF((yyvsp[(1) - (4)].str), tss));xx1=atoi(xx) ;printf("l");if( vv1 ==1 && idfNewValue2 > xx1) printf("erreur symantique car la taile non disponible\n");vv1=0;jj=nbb2((yyvsp[(1) - (4)].str));if(bb == 1  && (nb11 > nbb1((yyvsp[(1) - (4)].str)) || nb22 > nbb2((yyvsp[(1) - (4)].str))))printf("erreur dans la matrice la taille non disponible");bb=0;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 688 "synt.y"
    {rechercher1 ((yyvsp[(1) - (5)].str),"IDF","Identifier","0", 0,tss);rechercher ((yyvsp[(2) - (5)].str),"Separateur","0","0", 2,tss);rechercher ((yyvsp[(4) - (5)].str),"Separateur","0","0", 2,tss);;strcpy(xx, (char*)getValueOfIDF((yyvsp[(1) - (5)].str), tss));xx1=atoi(xx) ;printf("l");if( vv1 ==1 && idfNewValue2 > xx1) printf("erreur symantique car la taile non disponible\n");vv1=0; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2562 "synt.tab.c"
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
#line 691 "synt.y"

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
                afficher_qdr();
                executer(tss);
   

    
    return 0;
}
yywrap ()
{}
int yyerror ( char*  msg )  
{
       printf ("Erreur Syntaxique : fichier %s , ligne %d , colonne %d \n", filename,nb_ligne,col);
       exit(EXIT_FAILURE);
}


