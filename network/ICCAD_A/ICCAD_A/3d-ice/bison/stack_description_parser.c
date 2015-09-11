
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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         stack_description_parse
#define yylex           stack_description_lex
#define yyerror         stack_description_error
#define yylval          stack_description_lval
#define yychar          stack_description_char
#define yydebug         stack_description_debug
#define yynerrs         stack_description_nerrs


/* Copy the first part of user declarations.  */


/* Line 189 of yacc.c  */
#line 81 "stack_description_parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 40 "stack_description_parser.y"

    #include "types.h"

    #include "material.h"
    #include "die.h"
    #include "stack_element.h"
    #include "inspection_point.h"
    #include "analysis.h"
    #include "output.h"
    #include "stack_description.h"



/* Line 209 of yacc.c  */
#line 119 "stack_description_parser.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _2RM = 258,
     _4RM = 259,
     AMBIENT = 260,
     AREA = 261,
     AVERAGE = 262,
     BOTTOM = 263,
     CAPACITY = 264,
     CELL = 265,
     CHANNEL = 266,
     CHIP = 267,
     COEFFICIENT = 268,
     CONDUCTIVITY = 269,
     CONNECTION = 270,
     COOLANT = 271,
     DARCY = 272,
     DIAMETER = 273,
     DIE = 274,
     DIMENSIONS = 275,
     DISTRIBUTION = 276,
     FINAL = 277,
     FIRST = 278,
     FLOORPLAN = 279,
     FLOW = 280,
     HEAT = 281,
     HEIGHT = 282,
     INCOMING = 283,
     INITIAL_ = 284,
     INLINE = 285,
     LAST = 286,
     LAYER = 287,
     LENGTH = 288,
     MATERIAL = 289,
     MAXIMUM = 290,
     MICROCHANNEL = 291,
     MINIMUM = 292,
     OUTPUT = 293,
     PIN = 294,
     PINFIN = 295,
     PITCH = 296,
     PMAP = 297,
     RATE = 298,
     SIDE = 299,
     SINK = 300,
     SLOT = 301,
     SOLVER = 302,
     SOURCE = 303,
     SPREADER = 304,
     STACK = 305,
     STAGGERED = 306,
     STATE = 307,
     STEADY = 308,
     STEP = 309,
     TCELL = 310,
     TCOOLANT = 311,
     TEMPERATURE = 312,
     TFLP = 313,
     TFLPEL = 314,
     THERMAL = 315,
     TMAP = 316,
     TO = 317,
     TOP = 318,
     TRANSFER = 319,
     TRANSIENT = 320,
     VELOCITY = 321,
     VOLUMETRIC = 322,
     WALL = 323,
     WIDTH = 324,
     DVALUE = 325,
     IDENTIFIER = 326,
     PATH = 327
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 55 "stack_description_parser.y"

    double                double_v ;
    String_t              string ;
    Material_t           *material_p ;
    Coolant_t             coolant_v ;
    ChannelModel_t        channel_model_v ;
    Die_t                *die_p ;
    Layer_t              *layer_p ;
    StackElement_t       *stack_element_p ;
    InspectionPoint_t    *inspection_point_p ;
    OutputInstant_t       output_instant_v ;
    OutputQuantity_t      output_quantity_v ;



/* Line 214 of yacc.c  */
#line 224 "stack_description_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 236 "stack_description_parser.c"
/* Unqualified %code blocks.  */

/* Line 265 of yacc.c  */
#line 70 "stack_description_parser.y"

    #include <math.h>

    #include "channel.h"
    #include "heat_sink.h"
    #include "dimensions.h"
    #include "floorplan_element.h"
    #include "floorplan.h"
    #include "layer_list.h"
    #include "material_list.h"
    #include "die_list.h"
    #include "macros.h"

    #include "../flex/stack_description_scanner.h"

    void stack_description_error

        (StackDescription_t *stack, Analysis_t *analysis, Output_t *output,
         yyscan_t scanner, const char *message) ;

    #define STKERROR(m) stack_description_error (stkd, analysis, output, scanner, m)

    static char error_message [100] ;

    static CellDimension_t first_wall_length ;
    static CellDimension_t last_wall_length ;
    static CellDimension_t wall_length ;
    static CellDimension_t channel_length ;
    static Quantity_t      num_channels ;
    static Quantity_t      num_dies ;

    static Quantity_t  source_layer_offset ;
    static LayerList_t dielayers ;



/* Line 265 of yacc.c  */
#line 278 "stack_description_parser.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  371

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      76,    77,     2,     2,    75,     2,    78,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    73,    74,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    13,    15,    18,    31,    32,    65,    79,
      80,   118,   154,   191,   198,   212,   219,   230,   231,   237,
     238,   244,   246,   248,   249,   251,   253,   256,   266,   267,
     270,   271,   274,   277,   280,   284,   286,   289,   296,   313,
     317,   319,   322,   327,   331,   338,   347,   361,   362,   366,
     368,   371,   384,   395,   408,   417,   426,   437,   439,   441,
     443,   444,   447,   450
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      80,     0,    -1,    81,    83,    84,    90,    98,   100,   101,
     104,   105,    -1,    82,    -1,    81,    82,    -1,    34,    71,
      73,    60,    14,    70,    74,    67,    26,     9,    70,    74,
      -1,    -1,    26,    45,    73,    45,    27,    70,    75,     6,
      70,    75,    34,    71,    74,    49,    27,    70,    75,     6,
      70,    75,    34,    71,    74,    26,    64,    13,    70,    74,
       5,    57,    70,    74,    -1,    15,    62,     5,    73,    26,
      64,    13,    70,    74,     5,    57,    70,    74,    -1,    -1,
      36,     4,    73,    27,    70,    74,    11,    33,    70,    74,
      68,    33,    70,    74,    87,    88,    68,    34,    71,    74,
      16,    25,    43,    70,    74,    85,    16,    67,    26,     9,
      70,    74,    16,    28,    57,    70,    74,    -1,    36,     3,
      73,    27,    70,    74,    11,    33,    70,    74,    68,    33,
      70,    74,    68,    34,    71,    74,    16,    25,    43,    70,
      74,    86,    16,    67,    26,     9,    70,    74,    16,    28,
      57,    70,    74,    -1,    40,    73,    27,    70,    74,    39,
      18,    70,    74,    39,    41,    70,    74,    39,    21,    89,
      74,    39,    34,    71,    74,    17,    66,    70,    74,    16,
      67,    26,     9,    70,    74,    16,    28,    57,    70,    74,
      -1,    16,    26,    64,    13,    70,    74,    -1,    16,    26,
      64,    13,    44,    70,    75,    63,    70,    75,     8,    70,
      74,    -1,    16,    26,    64,    13,    70,    74,    -1,    16,
      26,    64,    13,    63,    70,    75,     8,    70,    74,    -1,
      -1,    23,    68,    33,    70,    74,    -1,    -1,    31,    68,
      33,    70,    74,    -1,    30,    -1,    51,    -1,    -1,    91,
      -1,    92,    -1,    91,    92,    -1,    32,    71,    73,    27,
      70,    74,    34,    71,    74,    -1,    -1,    93,    95,    -1,
      -1,    94,    95,    -1,    32,    97,    -1,    48,    97,    -1,
      70,    71,    74,    -1,    99,    -1,    98,    99,    -1,    19,
      71,    73,    93,    96,    94,    -1,    20,    73,    12,    33,
      70,    75,    69,    70,    74,    10,    33,    70,    75,    69,
      70,    74,    -1,    50,    73,   102,    -1,   103,    -1,   102,
     103,    -1,    32,    71,    71,    74,    -1,    11,    71,    74,
      -1,    19,    71,    71,    24,    72,    74,    -1,    47,    73,
      53,    74,    29,    57,    70,    74,    -1,    47,    73,    65,
      54,    70,    75,    46,    70,    74,    29,    57,    70,    74,
      -1,    -1,    38,    73,   106,    -1,   107,    -1,   106,   107,
      -1,    55,    76,    71,    75,    70,    75,    70,    75,    72,
     109,    77,    74,    -1,    58,    76,    71,    75,    72,    75,
     108,   109,    77,    74,    -1,    59,    76,    71,    78,    71,
      75,    72,    75,   108,   109,    77,    74,    -1,    61,    76,
      71,    75,    72,   109,    77,    74,    -1,    42,    76,    71,
      75,    72,   109,    77,    74,    -1,    56,    76,    71,    75,
      72,    75,   108,   109,    77,    74,    -1,    35,    -1,    37,
      -1,     7,    -1,    -1,    75,    54,    -1,    75,    46,    -1,
      75,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   232,   232,   249,   255,   277,   302,   306,   407,   432,
     436,   492,   544,   598,   604,   616,   622,   632,   633,   637,
     638,   642,   643,   650,   654,   660,   666,   691,   733,   737,
     745,   749,   761,   769,   779,   819,   825,   847,   884,   980,
    1172,  1187,  1220,  1274,  1302,  1383,  1399,  1456,  1460,  1466,
    1473,  1483,  1535,  1599,  1684,  1733,  1782,  1849,  1850,  1851,
    1857,  1858,  1859,  1860
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"keyword 2rm\"", "\"keyword 4rm\"",
  "\"keyword ambient\"", "\"keyword area\"", "\"keyword average\"",
  "\"keyword bottom\"", "\"keyword capacity\"", "\"keyword cell\"",
  "\"keyword channel\"", "\"keyword chip\"", "\"keyword coefficient\"",
  "\"keyword conductivity\"", "\"keyword connection\"",
  "\"keyword coolant\"", "\"keyword darcy\"", "\"keyword diameter\"",
  "\"keyword die\"", "\"keyword dimensions\"", "\"keyword distribution\"",
  "\"keyword final\"", "\"keyword first\"", "\"keyword floorplan\"",
  "\"keyword flow\"", "\"keyword heat\"", "\"keyword height\"",
  "\"keyword incoming\"", "\"keyword initial\"", "\"keyword inline\"",
  "\"keyword last\"", "\"keyword layer\"", "\"keyword length\"",
  "\"keyword material\"", "\"keyword maximum\"",
  "\"keyword microchannel\"", "\"keyword minimum\"", "\"keyword output\"",
  "\"keyword pin\"", "\"keyword pinfin\"", "\"keyword pitch\"",
  "\"keyword Pmap\"", "\"keyword rate\"", "\"keyword side\"",
  "\"keywork sink\"", "\"keyword slot\"", "\"keyword solver\"",
  "\"keyword source\"", "\"keyword spreader\"", "\"keyword stack\"",
  "\"keyword staggered\"", "\"keyword state\"", "\"keyword steady\"",
  "\"keyword step\"", "\"keyword T\"", "\"keyword Tcoolant\"",
  "\"keyword temperature\"", "\"keyword Tflp\"", "\"keyword Tflpel\"",
  "\"keyword thermal\"", "\"keyword Tmap\"", "\"keyword to\"",
  "\"keyword top\"", "\"keyword transfer\"", "\"keyword transient\"",
  "\"keyword velocity\"", "\"keywork volumetric\"", "\"keyword wall\"",
  "\"keyword width\"", "\"double value\"", "\"identifier\"",
  "\"path to file\"", "':'", "';'", "','", "'('", "')'", "'.'", "$accept",
  "stack_description_file", "materials_list", "material", "heat_sink_opt",
  "microchannel_opt", "coolant_heat_transfer_coefficients_4rm",
  "coolant_heat_transfer_coefficients_2rm", "first_wall_length",
  "last_wall_length", "distribution", "layers_list_opt", "layers_list",
  "layer", "die_top_layers_list", "die_bottom_layers_list", "die_layer",
  "die_source_layer", "die_layer_content", "dies_list", "die",
  "dimensions", "stack", "stack_elements", "stack_element", "solver",
  "inspection_points", "inspection_points_list", "inspection_point",
  "maxminavg", "when", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,    58,    59,    44,    40,    41,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    82,    83,    83,    83,    84,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    94,    95,    96,    97,    98,    98,    99,   100,   101,
     102,   102,   103,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   107,   108,   108,   108,
     109,   109,   109,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     1,     2,    12,     0,    32,    13,     0,
      37,    35,    36,     6,    13,     6,    10,     0,     5,     0,
       5,     1,     1,     0,     1,     1,     2,     9,     0,     2,
       0,     2,     2,     2,     3,     1,     2,     6,    16,     3,
       1,     2,     4,     3,     6,     8,    13,     0,     3,     1,
       2,    12,    10,    12,     8,     8,    10,     1,     1,     1,
       0,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     3,     0,     1,     0,     0,     4,
       9,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,     0,     0,     0,     0,    39,    40,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    37,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     5,     0,     0,     0,     0,     0,
      27,    34,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,    60,     0,     0,     0,     0,    60,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,    63,    62,    61,
       0,     0,    59,    57,    58,    60,    60,     0,     0,     0,
       0,     0,     0,     0,    21,    22,     0,     0,     0,    55,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,    46,     0,    56,    52,     0,     0,
       0,    18,     0,     0,     0,    38,     0,     0,     0,     0,
      20,     0,     0,    51,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,    12,     0,    10,
      14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    16,   311,   299,   213,   233,
     236,    24,    25,    26,    67,   102,    81,    82,   100,    35,
      36,    48,    59,    87,    88,    71,    91,   132,   133,   225,
     204
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -207
static const yytype_int16 yypact[] =
{
     -24,   -57,    17,     1,  -207,   -31,  -207,   -19,    -1,  -207,
     -27,   -15,    41,   -26,    35,   -25,    18,    37,   -21,     4,
     -18,   -17,    26,   -13,    40,    18,  -207,   -16,    36,    34,
      38,    39,    -6,   -10,    -3,    21,  -207,  -207,    -5,     3,
       0,     2,     5,     6,    44,     8,     9,  -207,    23,     7,
      63,    10,    12,    13,    45,    19,  -207,    65,    15,    31,
      53,    20,    77,    80,    81,    75,    22,   -12,    61,    -7,
      24,    57,    89,    25,    30,    68,    69,    33,    70,    42,
      42,  -207,  -207,    43,    46,    47,    48,    -7,  -207,   -42,
      32,  -207,    50,   101,    49,    51,    52,    54,    55,    56,
    -207,  -207,    76,    58,    60,    59,    64,  -207,    62,    71,
     -37,    66,    72,    73,    67,    74,    84,    78,    79,  -207,
      82,  -207,    85,    83,    86,    88,    87,    90,    91,    92,
      93,    94,   -37,  -207,  -207,    95,   100,    96,   104,    97,
    -207,  -207,   103,   102,  -207,    98,   105,   106,   107,   108,
     110,   111,   112,  -207,   113,   114,    99,   109,   115,   116,
     117,   119,   129,   118,   120,   121,   122,   123,   124,  -207,
     127,   128,   130,   131,   133,  -207,   132,   134,   135,   138,
     137,   139,   141,   142,   157,   136,   143,   147,   126,  -207,
     144,   140,   145,   146,   148,   149,   140,   152,   151,   169,
     125,   155,   165,   -20,   150,   156,    -4,    -4,   158,   154,
     153,   168,   161,   172,   -23,   159,   175,  -207,  -207,  -207,
     162,   160,  -207,  -207,  -207,   140,   140,   163,   166,   207,
     170,   183,   171,   174,  -207,  -207,   173,   164,   167,  -207,
     176,   177,   178,    -4,  -207,   179,   182,   180,   210,   211,
     205,   181,   184,   140,   185,   186,   140,   187,   230,   189,
     191,   193,   218,   192,  -207,   188,  -207,  -207,   190,   219,
     232,  -207,   194,   195,   199,  -207,   197,   198,   202,   231,
    -207,   259,   203,  -207,  -207,   204,   206,   254,   263,   255,
     208,   240,   220,   221,   268,   217,   222,   275,   264,   273,
     223,   224,   225,   227,   226,   278,   280,   228,   286,   274,
     277,   285,   237,   300,   -55,   297,   243,   241,   283,   253,
     242,   239,   244,   298,   289,   307,   247,   245,  -207,   248,
     -38,   309,   249,   250,   313,   310,   257,   251,   258,   256,
    -207,   261,   295,   260,  -207,   262,   316,   265,   272,   270,
     318,   312,  -207,   267,   271,   314,   281,   269,   276,   287,
     279,  -207,   337,   282,   284,   290,   288,  -207,   291,  -207,
    -207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,   343,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,   322,  -207,  -207,    14,  -207,   292,  -207,
     315,  -207,  -207,  -207,    27,  -207,  -207,  -207,   -22,  -206,
    -196
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     209,   226,   217,   222,    84,   126,   336,   234,   320,    14,
       1,   108,    85,    15,     5,   321,     7,     6,   127,   128,
      79,   129,   130,   109,   131,    86,   218,     8,   235,   241,
     242,   223,   337,   224,   219,     1,    80,   256,    20,    21,
      34,    46,    11,    12,    13,    17,    18,    19,    22,    29,
      23,    27,    28,    32,    38,    30,    31,   265,    33,    34,
     268,    40,    39,    44,    43,    41,    42,    50,    45,    49,
      51,    55,    52,    58,    60,    53,    61,    68,    70,    72,
      54,    56,    57,    74,    65,    62,    63,    64,    69,    66,
      73,    75,    76,    77,    83,    90,    78,    89,    92,    93,
      94,    95,    96,    97,    98,   110,   112,   136,    79,   143,
     153,     0,    99,   103,   107,   145,   119,   104,   105,   106,
     111,   114,   115,   139,   113,   125,   117,   118,   116,   135,
     122,     0,   171,   120,   121,   123,   124,     0,   158,     0,
     134,   137,   172,   188,     0,     0,   214,     0,   138,     0,
       0,   142,   140,   141,     0,   161,     0,   144,   146,   201,
       0,     0,     0,   147,   156,   154,   148,   149,   150,   151,
     152,   155,   157,   159,   160,   177,   184,   163,   164,   165,
     162,   166,   167,   168,   197,   173,   200,   169,   170,   176,
     174,   175,   212,   178,   216,   179,   180,   181,   185,   183,
     186,   182,   230,   232,   190,   187,   189,   191,   192,   193,
     198,   194,   195,   245,   196,   203,   247,   199,   202,   211,
     205,   206,   210,   207,   208,   215,   221,   220,   229,   231,
     227,   228,   238,   251,   237,   240,   239,   252,   243,   248,
     244,   246,   249,   260,   262,   261,   270,   250,   253,   257,
     259,   263,   274,   278,   254,   255,   258,   279,   264,   266,
     267,   272,   269,   271,   273,   276,   275,   277,   280,   281,
     282,   283,   284,   285,   286,   287,   290,   288,   289,   291,
     292,   293,   294,   295,   298,   297,   296,   300,   302,   304,
     303,   308,   301,   309,   310,   307,   312,   305,   306,   314,
     315,   317,   313,   316,   318,   319,   322,   323,   324,   325,
     326,   330,   327,   328,   329,   331,   332,   333,   338,   339,
     334,   341,   335,   348,   340,   344,   342,   343,   345,   353,
     346,   347,   351,   354,   355,   349,   350,   357,   360,   352,
     356,   358,   359,   361,   363,   365,     9,    37,     0,   364,
      47,   362,   366,     0,     0,     0,     0,     0,   367,     0,
     368,     0,   369,     0,     0,   370,     0,     0,     0,     0,
       0,     0,   101
};

static const yytype_int16 yycheck[] =
{
     196,   207,    22,     7,    11,    42,    44,    30,    63,    36,
      34,    53,    19,    40,    71,    70,    15,     0,    55,    56,
      32,    58,    59,    65,    61,    32,    46,    26,    51,   225,
     226,    35,    70,    37,    54,    34,    48,   243,     3,     4,
      19,    20,    73,    62,    45,    60,     5,    73,    73,    45,
      32,    14,    73,    27,    70,    73,    73,   253,    71,    19,
     256,    27,    26,    73,    70,    27,    27,    64,    71,    74,
      70,    27,    70,    50,    67,    70,    13,    12,    47,    26,
      74,    73,    73,     6,    39,    75,    74,    74,    73,    70,
      70,    11,    11,    18,    33,    38,    74,    73,     9,    74,
      70,    33,    33,    70,    34,    73,     5,    34,    32,    24,
     132,    -1,    70,    70,    87,    29,   102,    71,    71,    71,
      70,    70,    70,    39,    75,    54,    71,    71,    74,    57,
      71,    -1,    33,    75,    74,    71,    74,    -1,    41,    -1,
      74,    74,    33,    10,    -1,    -1,    21,    -1,    74,    -1,
      -1,    69,    74,    74,    -1,    57,    -1,    74,    70,    33,
      -1,    -1,    -1,    76,    68,    70,    76,    76,    76,    76,
      76,    71,    68,    70,    72,    46,    49,    71,    71,    71,
      75,    71,    71,    71,    27,    70,    39,    74,    74,    70,
      74,    74,    23,    75,    29,    75,    75,    75,    70,    75,
      70,    78,    34,    31,    70,    74,    74,    72,    70,    72,
      74,    72,    71,     6,    72,    75,    33,    74,    74,    68,
      75,    75,    70,    75,    75,    70,    70,    77,    75,    68,
      72,    77,    57,    69,    75,    75,    74,    70,    75,    68,
      74,    71,    68,    33,    39,    34,    16,    74,    72,    70,
      70,    70,    34,    34,    77,    77,    74,    25,    74,    74,
      74,    70,    75,    74,    71,    77,    74,    77,    74,    74,
      71,    74,    74,    71,    43,    16,    70,    74,    74,    25,
      17,    26,    74,    43,    16,    64,    66,    70,    13,    16,
      26,    64,    70,    67,    16,    70,    16,    74,    74,    13,
      26,    16,    74,    26,    67,     5,     9,    64,    67,    26,
      57,    13,    70,    74,    70,    26,     9,    70,     9,    70,
      75,     8,    74,    28,    74,    74,    16,    70,    70,    57,
      74,    70,    16,    63,    16,    75,    74,    70,    57,    74,
      28,    70,    28,    74,    57,     8,     3,    25,    -1,    70,
      35,    75,    70,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      70,    -1,    74,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    80
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    80,    81,    82,    71,     0,    15,    26,    82,
      83,    73,    62,    45,    36,    40,    84,    60,     5,    73,
       3,     4,    73,    32,    90,    91,    92,    14,    73,    45,
      73,    73,    27,    71,    19,    98,    99,    92,    70,    26,
      27,    27,    27,    70,    73,    71,    20,    99,   100,    74,
      64,    70,    70,    70,    74,    27,    73,    73,    50,   101,
      67,    13,    75,    74,    74,    39,    70,    93,    12,    73,
      47,   104,    26,    70,     6,    11,    11,    18,    74,    32,
      48,    95,    96,    33,    11,    19,    32,   102,   103,    73,
      38,   105,     9,    74,    70,    33,    33,    70,    34,    70,
      97,    97,    94,    70,    71,    71,    71,   103,    53,    65,
      73,    70,     5,    75,    70,    70,    74,    71,    71,    95,
      75,    74,    71,    71,    74,    54,    42,    55,    56,    58,
      59,    61,   106,   107,    74,    57,    34,    74,    74,    39,
      74,    74,    69,    24,    74,    29,    70,    76,    76,    76,
      76,    76,    76,   107,    70,    71,    68,    68,    41,    70,
      72,    57,    75,    71,    71,    71,    71,    71,    71,    74,
      74,    33,    33,    70,    74,    74,    70,    46,    75,    75,
      75,    75,    78,    75,    49,    70,    70,    74,    10,    74,
      70,    72,    70,    72,    72,    71,    72,    27,    74,    74,
      39,    33,    74,    75,   109,    75,    75,    75,    75,   109,
      70,    68,    23,    87,    21,    70,    29,    22,    46,    54,
      77,    70,     7,    35,    37,   108,   108,    72,    77,    75,
      34,    68,    31,    88,    30,    51,    89,    75,    57,    74,
      75,   109,   109,    75,    74,     6,    71,    33,    68,    68,
      74,    69,    70,    72,    77,    77,   108,    70,    74,    70,
      33,    34,    39,    70,    74,   109,    74,    74,   109,    75,
      16,    74,    70,    71,    34,    74,    77,    77,    34,    25,
      74,    74,    71,    74,    74,    71,    43,    16,    74,    74,
      70,    25,    17,    26,    74,    43,    66,    64,    16,    86,
      70,    70,    13,    26,    16,    74,    74,    70,    64,    67,
      16,    85,    16,    74,    13,    26,    26,    16,    67,     5,
      63,    70,     9,    64,    67,    26,    57,    70,    74,    70,
      13,    26,     9,    70,    75,    74,    44,    70,     9,    70,
      74,     8,    16,    70,    74,    70,    74,    70,    28,    75,
      74,    16,    74,    57,    63,    16,    28,    70,    70,    28,
      57,    74,    75,    57,    70,     8,    70,    74,    70,    74,
      74
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
      yyerror (stkd, analysis, output, scanner, YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, scanner)
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
		  Type, Value, stkd, analysis, output, scanner); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, StackDescription_t *stkd, Analysis_t         *analysis, Output_t           *output, yyscan_t            scanner)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, stkd, analysis, output, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    StackDescription_t *stkd;
    Analysis_t         *analysis;
    Output_t           *output;
    yyscan_t            scanner;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (stkd);
  YYUSE (analysis);
  YYUSE (output);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, StackDescription_t *stkd, Analysis_t         *analysis, Output_t           *output, yyscan_t            scanner)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, stkd, analysis, output, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    StackDescription_t *stkd;
    Analysis_t         *analysis;
    Output_t           *output;
    yyscan_t            scanner;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, stkd, analysis, output, scanner);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, StackDescription_t *stkd, Analysis_t         *analysis, Output_t           *output, yyscan_t            scanner)
#else
static void
yy_reduce_print (yyvsp, yyrule, stkd, analysis, output, scanner)
    YYSTYPE *yyvsp;
    int yyrule;
    StackDescription_t *stkd;
    Analysis_t         *analysis;
    Output_t           *output;
    yyscan_t            scanner;
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
		       		       , stkd, analysis, output, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, stkd, analysis, output, scanner); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, StackDescription_t *stkd, Analysis_t         *analysis, Output_t           *output, yyscan_t            scanner)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, stkd, analysis, output, scanner)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    StackDescription_t *stkd;
    Analysis_t         *analysis;
    Output_t           *output;
    yyscan_t            scanner;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (stkd);
  YYUSE (analysis);
  YYUSE (output);
  YYUSE (scanner);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 71: /* "\"identifier\"" */

/* Line 1000 of yacc.c  */
#line 192 "stack_description_parser.y"
	{ free       ((yyvaluep->string)) ; };

/* Line 1000 of yacc.c  */
#line 1489 "stack_description_parser.c"
	break;
      case 72: /* "\"path to file\"" */

/* Line 1000 of yacc.c  */
#line 192 "stack_description_parser.y"
	{ free       ((yyvaluep->string)) ; };

/* Line 1000 of yacc.c  */
#line 1498 "stack_description_parser.c"
	break;
      case 92: /* "layer" */

/* Line 1000 of yacc.c  */
#line 193 "stack_description_parser.y"
	{ layer_free ((yyvaluep->layer_p)) ; };

/* Line 1000 of yacc.c  */
#line 1507 "stack_description_parser.c"
	break;
      case 95: /* "die_layer" */

/* Line 1000 of yacc.c  */
#line 193 "stack_description_parser.y"
	{ layer_free ((yyvaluep->layer_p)) ; };

/* Line 1000 of yacc.c  */
#line 1516 "stack_description_parser.c"
	break;
      case 97: /* "die_layer_content" */

/* Line 1000 of yacc.c  */
#line 193 "stack_description_parser.y"
	{ layer_free ((yyvaluep->layer_p)) ; };

/* Line 1000 of yacc.c  */
#line 1525 "stack_description_parser.c"
	break;

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
int yyparse (StackDescription_t *stkd, Analysis_t         *analysis, Output_t           *output, yyscan_t            scanner);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





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
yyparse (StackDescription_t *stkd, Analysis_t         *analysis, Output_t           *output, yyscan_t            scanner)
#else
int
yyparse (stkd, analysis, output, scanner)
    StackDescription_t *stkd;
    Analysis_t         *analysis;
    Output_t           *output;
    yyscan_t            scanner;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

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

/* User initialization code.  */

/* Line 1242 of yacc.c  */
#line 209 "stack_description_parser.y"
{
    first_wall_length = 0.0 ;
    last_wall_length  = 0.0 ;
    wall_length       = 0.0 ;
    channel_length    = 0.0 ;
    num_channels      = 0u ;
    num_dies          = 0u ;

    source_layer_offset = 0u ;

    layer_list_init (&dielayers) ;
}

/* Line 1242 of yacc.c  */
#line 1671 "stack_description_parser.c"

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
#line 250 "stack_description_parser.y"
    {
        material_list_insert_end (&stkd->Materials, (yyvsp[(1) - (1)].material_p)) ;

        material_free ((yyvsp[(1) - (1)].material_p)) ;
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 257 "stack_description_parser.y"
    {
        if (material_list_find (&stkd->Materials, (yyvsp[(2) - (2)].material_p)) != NULL)
        {
            sprintf (error_message, "Material %s already declared", (yyvsp[(2) - (2)].material_p)->Id) ;

            material_free ((yyvsp[(2) - (2)].material_p)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        material_list_insert_end (&stkd->Materials, (yyvsp[(2) - (2)].material_p)) ;

        material_free ((yyvsp[(2) - (2)].material_p)) ;
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 280 "stack_description_parser.y"
    {
        Material_t *material = (yyval.material_p) = material_calloc () ;

        if (material == NULL)
        {
            free ((yyvsp[(2) - (12)].string)) ;

            STKERROR ("Malloc material failed") ;

            YYABORT ;
        }

        material->Id                     = (yyvsp[(2) - (12)].string) ;
        material->ThermalConductivity    = (SolidTC_t) (yyvsp[(6) - (12)].double_v) ;
        material->VolumetricHeatCapacity = (SolidVHC_t) (yyvsp[(11) - (12)].double_v) ;
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 315 "stack_description_parser.y"
    {
        stkd->HeatSink = heat_sink_calloc () ;

        if (stkd->HeatSink == NULL)
        {
            STKERROR ("Malloc heat sink failed") ;

            YYABORT ;
        }

        stkd->HeatSink->SinkModel           = TDICE_HEATSINK_MODEL_TRADITIONAL ;
        stkd->HeatSink->NLayers             = NUM_LAYERS_HEATSINK_TRADITIONAL ;
        stkd->HeatSink->SourceLayerOffset   = SOURCE_OFFSET_HEATSINK_TRADITIONAL ;
        stkd->HeatSink->SinkHeight          = (yyvsp[(6) - (32)].double_v) ;
        stkd->HeatSink->SinkArea            = (yyvsp[(9) - (32)].double_v) ;
        stkd->HeatSink->SinkMaterial.Id     = (yyvsp[(12) - (32)].string) ;
        stkd->HeatSink->SpreaderHeight      = (yyvsp[(16) - (32)].double_v) ;
        stkd->HeatSink->SpreaderArea        = (yyvsp[(19) - (32)].double_v) ;
        stkd->HeatSink->SpreaderMaterial.Id = (yyvsp[(22) - (32)].string) ;
        stkd->HeatSink->AmbientHTC          = (AmbientHTC_t) (yyvsp[(27) - (32)].double_v) ;
        stkd->HeatSink->AmbientTemperature  = (yyvsp[(31) - (32)].double_v) ;

        if (stkd->HeatSink->SinkArea <= 0)
        {
            sprintf (error_message,
                "Error: the area of the sink must be a positive value!") ;

            free ((yyvsp[(12) - (32)].string)) ;
            free ((yyvsp[(22) - (32)].string)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        if (stkd->HeatSink->SpreaderArea <= 0)
        {
            sprintf (error_message,
                "Error: the area of the spreader must be a positive value!") ;

            free ((yyvsp[(12) - (32)].string)) ;
            free ((yyvsp[(22) - (32)].string)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        if (stkd->HeatSink->SinkArea < stkd->HeatSink->SpreaderArea)
        {
            sprintf (error_message,
                "Error: the area of the spreader must be greater (or equal) than the sink") ;

            free ((yyvsp[(12) - (32)].string)) ;
            free ((yyvsp[(22) - (32)].string)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        Material_t *tmp = material_list_find

            (&stkd->Materials, &stkd->HeatSink->SinkMaterial) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown sink material %s", (yyvsp[(12) - (32)].string)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        material_copy (&stkd->HeatSink->SinkMaterial, tmp) ;

        tmp = material_list_find

            (&stkd->Materials, &stkd->HeatSink->SpreaderMaterial) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown spreader material %s", (yyvsp[(22) - (32)].string)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        material_copy (&stkd->HeatSink->SpreaderMaterial, tmp) ;
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 410 "stack_description_parser.y"
    {
        stkd->HeatSink = heat_sink_calloc () ;

        if (stkd->HeatSink == NULL)
        {
            STKERROR ("Malloc heat sink failed") ;

            YYABORT ;
        }

        stkd->HeatSink->SinkModel          = TDICE_HEATSINK_MODEL_CONNECTION_TO_AMBIENT ;
        stkd->HeatSink->NLayers            = NUM_LAYERS_HEATSINK_CONNECTION_TO_AMBIENT ;
        stkd->HeatSink->SourceLayerOffset  = SOURCE_OFFSET_HEATSINK_CONNECTION_TO_AMBIENT ;
        stkd->HeatSink->AmbientHTC         = (AmbientHTC_t) (yyvsp[(8) - (13)].double_v) ;
        stkd->HeatSink->AmbientTemperature = (yyvsp[(12) - (13)].double_v) ;
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 447 "stack_description_parser.y"
    {
        stkd->Channel = channel_calloc () ;

        if (stkd->Channel == NULL)
        {
            free ((yyvsp[(19) - (37)].string)) ;

            STKERROR ("Malloc channel failed") ;

            YYABORT ;
        }

        channel_length    = (yyvsp[(9) - (37)].double_v) ;
        wall_length       = (yyvsp[(13) - (37)].double_v) ;
        first_wall_length = ((yyvsp[(15) - (37)].double_v) != 0.0) ? (yyvsp[(15) - (37)].double_v) : (yyvsp[(13) - (37)].double_v) ;
        last_wall_length  = ((yyvsp[(16) - (37)].double_v) != 0.0) ? (yyvsp[(16) - (37)].double_v) : (yyvsp[(13) - (37)].double_v) ;

        stkd->Channel->ChannelModel      = TDICE_CHANNEL_MODEL_MC_4RM ;
        stkd->Channel->NLayers           = NUM_LAYERS_CHANNEL_4RM ;
        stkd->Channel->SourceLayerOffset = SOURCE_OFFSET_CHANNEL_4RM ;
        stkd->Channel->Height            = (yyvsp[(5) - (37)].double_v) ;
        stkd->Channel->WallMaterial.Id   = (yyvsp[(19) - (37)].string) ;
        stkd->Channel->Coolant.FlowRate  = FLOW_RATE_FROM_MLMIN_TO_UM3SEC ((yyvsp[(24) - (37)].double_v)) ;
        stkd->Channel->Coolant.HTCSide   = (yyvsp[(26) - (37)].coolant_v).HTCSide ;
        stkd->Channel->Coolant.HTCTop    = (yyvsp[(26) - (37)].coolant_v).HTCTop ;
        stkd->Channel->Coolant.HTCBottom = (yyvsp[(26) - (37)].coolant_v).HTCBottom ;
        stkd->Channel->Coolant.VHC       = (yyvsp[(31) - (37)].double_v) ;
        stkd->Channel->Coolant.TIn       = (yyvsp[(36) - (37)].double_v) ;

        Material_t *tmp = material_list_find

            (&stkd->Materials, &stkd->Channel->WallMaterial) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown material %s", (yyvsp[(19) - (37)].string)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        material_copy (&stkd->Channel->WallMaterial, tmp) ;
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 501 "stack_description_parser.y"
    {
        stkd->Channel = channel_calloc () ;

        if (stkd->Channel == NULL)
        {
            free ((yyvsp[(17) - (35)].string)) ;

            STKERROR ("Malloc channel failed") ;

            YYABORT ;
        }

        stkd->Channel->ChannelModel      = TDICE_CHANNEL_MODEL_MC_2RM ;
        stkd->Channel->NLayers           = NUM_LAYERS_CHANNEL_2RM ;
        stkd->Channel->SourceLayerOffset = SOURCE_OFFSET_CHANNEL_2RM ;
        stkd->Channel->Height            = (yyvsp[(5) - (35)].double_v) ;
        stkd->Channel->Length            = (yyvsp[(9) - (35)].double_v) ;
        stkd->Channel->Pitch             = (yyvsp[(13) - (35)].double_v) + (yyvsp[(9) - (35)].double_v) ;
        stkd->Channel->Porosity          = stkd->Channel->Length / stkd->Channel->Pitch ;
        stkd->Channel->WallMaterial.Id   = (yyvsp[(17) - (35)].string) ;
        stkd->Channel->Coolant.FlowRate  = FLOW_RATE_FROM_MLMIN_TO_UM3SEC ((yyvsp[(22) - (35)].double_v)) ;
        stkd->Channel->Coolant.HTCSide   = (yyvsp[(24) - (35)].coolant_v).HTCSide ;
        stkd->Channel->Coolant.HTCTop    = (yyvsp[(24) - (35)].coolant_v).HTCTop ;
        stkd->Channel->Coolant.HTCBottom = (yyvsp[(24) - (35)].coolant_v).HTCBottom ;
        stkd->Channel->Coolant.VHC       = (yyvsp[(29) - (35)].double_v) ;
        stkd->Channel->Coolant.TIn       = (yyvsp[(34) - (35)].double_v) ;

        Material_t *tmp = material_list_find

            (&stkd->Materials, &stkd->Channel->WallMaterial) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown material %s", (yyvsp[(17) - (35)].string)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        material_copy (&stkd->Channel->WallMaterial, tmp) ;
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 553 "stack_description_parser.y"
    {
        stkd->Channel = channel_calloc () ;

        if (stkd->Channel == NULL)
        {
            free ((yyvsp[(20) - (36)].string)) ;

            STKERROR ("Malloc channel failed") ;

            YYABORT ;
        }

        stkd->Channel->Height                = (yyvsp[(4) - (36)].double_v) ;
        stkd->Channel->Porosity              = POROSITY ((yyvsp[(8) - (36)].double_v), (yyvsp[(12) - (36)].double_v)) ;
        stkd->Channel->Pitch                 = (yyvsp[(12) - (36)].double_v) ;
        stkd->Channel->ChannelModel          = (yyvsp[(16) - (36)].channel_model_v) ;
        stkd->Channel->NLayers               = NUM_LAYERS_CHANNEL_2RM ;
        stkd->Channel->SourceLayerOffset     = SOURCE_OFFSET_CHANNEL_2RM ;
        stkd->Channel->WallMaterial.Id       = (yyvsp[(20) - (36)].string) ;
        stkd->Channel->Coolant.DarcyVelocity = (yyvsp[(24) - (36)].double_v) ;
        stkd->Channel->Coolant.HTCSide       = 0.0 ;
        stkd->Channel->Coolant.HTCTop        = 0.0 ;
        stkd->Channel->Coolant.HTCBottom     = 0.0 ;
        stkd->Channel->Coolant.VHC           = (yyvsp[(30) - (36)].double_v) ;
        stkd->Channel->Coolant.TIn           = (yyvsp[(35) - (36)].double_v) ;

        Material_t *tmp = material_list_find

            (&stkd->Materials, &stkd->Channel->WallMaterial) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown material %s", (yyvsp[(20) - (36)].string)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        material_copy (&stkd->Channel->WallMaterial, tmp) ;
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 599 "stack_description_parser.y"
    {
        (yyval.coolant_v).HTCSide   = (yyvsp[(5) - (6)].double_v) ;
        (yyval.coolant_v).HTCTop    = (yyvsp[(5) - (6)].double_v) ;
        (yyval.coolant_v).HTCBottom = (yyvsp[(5) - (6)].double_v) ;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 607 "stack_description_parser.y"
    {
        (yyval.coolant_v).HTCSide   = (yyvsp[(6) - (13)].double_v) ;
        (yyval.coolant_v).HTCTop    = (yyvsp[(9) - (13)].double_v) ;
        (yyval.coolant_v).HTCBottom = (yyvsp[(12) - (13)].double_v) ;
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 617 "stack_description_parser.y"
    {
        (yyval.coolant_v).HTCSide   = 0.0 ;
        (yyval.coolant_v).HTCTop    = (yyvsp[(5) - (6)].double_v) ;
        (yyval.coolant_v).HTCBottom = (yyvsp[(5) - (6)].double_v) ;
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 624 "stack_description_parser.y"
    {
        (yyval.coolant_v).HTCSide   = 0.0 ;
        (yyval.coolant_v).HTCTop    = (yyvsp[(6) - (10)].double_v) ;
        (yyval.coolant_v).HTCBottom = (yyvsp[(9) - (10)].double_v) ;
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 632 "stack_description_parser.y"
    { (yyval.double_v) = 0.0 ; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 633 "stack_description_parser.y"
    { (yyval.double_v) = (yyvsp[(4) - (5)].double_v) ;  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 637 "stack_description_parser.y"
    { (yyval.double_v) = 0.0 ; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 638 "stack_description_parser.y"
    { (yyval.double_v) = (yyvsp[(4) - (5)].double_v) ;  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 642 "stack_description_parser.y"
    { (yyval.channel_model_v) = TDICE_CHANNEL_MODEL_PF_INLINE ;    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 643 "stack_description_parser.y"
    { (yyval.channel_model_v) = TDICE_CHANNEL_MODEL_PF_STAGGERED ; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 661 "stack_description_parser.y"
    {
        layer_list_insert_end (&stkd->Layers, (yyvsp[(1) - (1)].layer_p)) ;

        layer_free ((yyvsp[(1) - (1)].layer_p)) ;
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 668 "stack_description_parser.y"
    {

        // checks if layer id already exist

        if (layer_list_find (&stkd->Layers, (yyvsp[(2) - (2)].layer_p)) != NULL)
        {
            sprintf (error_message, "Layer %s already declared", (yyvsp[(2) - (2)].layer_p)->Id) ;

            layer_free ((yyvsp[(2) - (2)].layer_p)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        layer_list_insert_end (&stkd->Layers, (yyvsp[(2) - (2)].layer_p)) ;

        layer_free ((yyvsp[(2) - (2)].layer_p)) ;
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 694 "stack_description_parser.y"
    {
        Layer_t *layer = (yyval.layer_p) = layer_calloc () ;

        if (layer == NULL)
        {
            free ((yyvsp[(2) - (9)].string)) ;
            free ((yyvsp[(8) - (9)].string)) ;

            STKERROR ("Malloc layer failed") ;

            YYABORT ;
        }

        layer->Height      = (yyvsp[(5) - (9)].double_v) ;
        layer->Id          = (yyvsp[(2) - (9)].string) ;
        layer->Material.Id = (yyvsp[(8) - (9)].string) ;

        Material_t *tmp = material_list_find

            (&stkd->Materials, &layer->Material) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown material %s", (yyvsp[(8) - (9)].string)) ;

            layer_free (layer) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        material_copy (&layer->Material, tmp) ;
  ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 738 "stack_description_parser.y"
    {
        layer_list_insert_end (&dielayers, (yyvsp[(2) - (2)].layer_p)) ;

        layer_free ((yyvsp[(2) - (2)].layer_p)) ;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 750 "stack_description_parser.y"
    {
        layer_list_insert_end (&dielayers, (yyvsp[(2) - (2)].layer_p)) ;

        source_layer_offset ++ ;

        layer_free ((yyvsp[(2) - (2)].layer_p)) ;
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 762 "stack_description_parser.y"
    {
        (yyval.layer_p) = (yyvsp[(2) - (2)].layer_p) ;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 770 "stack_description_parser.y"
    {
        layer_list_insert_end (&dielayers, (yyvsp[(2) - (2)].layer_p)) ;

        layer_free ((yyvsp[(2) - (2)].layer_p)) ;
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 780 "stack_description_parser.y"
    {
        Layer_t *layer = (yyval.layer_p) = layer_calloc () ;

        if (layer == NULL)
        {
            free ((yyvsp[(2) - (3)].string)) ;

            layer_list_destroy (&dielayers) ;

            STKERROR ("Malloc layer failed") ;

            YYABORT ;
        }

        layer->Height      = (yyvsp[(1) - (3)].double_v) ;
        layer->Id          = NULL ;
        layer->Material.Id = (yyvsp[(2) - (3)].string) ;

        Material_t *tmp = material_list_find (&stkd->Materials, &layer->Material) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown material %s", (yyvsp[(2) - (3)].string)) ;

            layer_list_destroy (&dielayers) ;

            layer_free (layer) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        material_copy (&layer->Material, tmp) ;
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 820 "stack_description_parser.y"
    {
        die_list_insert_end (&stkd->Dies, (yyvsp[(1) - (1)].die_p)) ;

        die_free ((yyvsp[(1) - (1)].die_p)) ;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 827 "stack_description_parser.y"
    {
        if (die_list_find (&stkd->Dies, (yyvsp[(2) - (2)].die_p)) != NULL)
        {
            sprintf (error_message, "Die %s already declared", (yyvsp[(2) - (2)].die_p)->Id) ;

            die_free ((yyvsp[(2) - (2)].die_p)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        die_list_insert_end (&stkd->Dies, (yyvsp[(2) - (2)].die_p)) ;

        die_free ((yyvsp[(2) - (2)].die_p)) ;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 851 "stack_description_parser.y"
    {
        Die_t *die = (yyval.die_p) = die_calloc () ;

        if (die == NULL)
        {
            free ((yyvsp[(2) - (6)].string)) ;

            layer_list_destroy (&dielayers) ;

            STKERROR ("Malloc die failed") ;

            YYABORT ;
        }

        die->Id                = (yyvsp[(2) - (6)].string) ;
        die->NLayers           = dielayers.Size ;
        die->SourceLayerOffset = source_layer_offset ;

        layer_list_copy (&die->Layers, &dielayers) ;

        layer_list_destroy (&dielayers) ;
        layer_list_init    (&dielayers) ;

        source_layer_offset = 0u ;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 887 "stack_description_parser.y"
    {
        stkd->Dimensions = dimensions_calloc () ;

        if (stkd->Dimensions == NULL)
        {
            STKERROR ("Malloc dimensions failed") ;

            YYABORT ;
        }

        stkd->Dimensions->Chip.Length = (yyvsp[(5) - (16)].double_v) ;
        stkd->Dimensions->Chip.Width  = (yyvsp[(8) - (16)].double_v) ;

        stkd->Dimensions->Cell.ChannelLength   = (yyvsp[(12) - (16)].double_v) ;
        stkd->Dimensions->Cell.FirstWallLength = (yyvsp[(12) - (16)].double_v) ;
        stkd->Dimensions->Cell.LastWallLength  = (yyvsp[(12) - (16)].double_v) ;
        stkd->Dimensions->Cell.WallLength      = (yyvsp[(12) - (16)].double_v) ;

        stkd->Dimensions->Cell.Width  = (yyvsp[(15) - (16)].double_v) ;

        stkd->Dimensions->Grid.NRows    = ((yyvsp[(8) - (16)].double_v) / (yyvsp[(15) - (16)].double_v)) ;
        stkd->Dimensions->Grid.NColumns = ((yyvsp[(5) - (16)].double_v) / (yyvsp[(12) - (16)].double_v)) ;


        if (stkd->Channel != NULL)
        {
            if (stkd->Channel->ChannelModel == TDICE_CHANNEL_MODEL_MC_4RM)
            {
                stkd->Dimensions->Cell.ChannelLength   = channel_length ;
                stkd->Dimensions->Cell.FirstWallLength = first_wall_length ;
                stkd->Dimensions->Cell.LastWallLength  = last_wall_length ;
                stkd->Dimensions->Cell.WallLength      = wall_length ;

                CellDimension_t ratio
                    = ((yyvsp[(5) - (16)].double_v) - first_wall_length - last_wall_length -channel_length)
                    /
                    (channel_length + wall_length) ;

                if ( ratio - (int) ratio != 0)
                {
                    STKERROR ("Error: cell dimensions does not fit the chip length correctly") ;

                    YYABORT ;
                }

                stkd->Dimensions->Grid.NColumns = 2 * ratio + 3 ;

                if ((stkd->Dimensions->Grid.NColumns & 1) == 0)
                {
                    STKERROR ("Error: column number must be odd") ;

                    YYABORT ;
                }

                // Check the number of columns

                if (stkd->Dimensions->Grid.NColumns < 3)
                {
                    STKERROR ("Error: not enough columns") ;

                    YYABORT ;
                }

                stkd->Channel->NChannels = ((stkd->Dimensions->Grid.NColumns - 1 )  / 2) ;
            }
            else if (stkd->Channel->ChannelModel == TDICE_CHANNEL_MODEL_MC_2RM)
            {
                stkd->Channel->NChannels = (((yyvsp[(5) - (16)].double_v) / stkd->Channel->Pitch) + 0.5) ; // round function
            }
        }

        // Check if the spreader is larger than the chip

        if (   stkd->HeatSink != NULL
            && stkd->HeatSink->SinkModel == TDICE_HEATSINK_MODEL_TRADITIONAL
            && stkd->HeatSink->SpreaderArea < get_chip_area (stkd->Dimensions))
        {
            sprintf (error_message,
                "Error: the area of the spreader must be smaller than the chip") ;

            STKERROR (error_message) ;

            YYABORT ;
        }
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 982 "stack_description_parser.y"
    {
        if (num_dies == 0u)
        {
            STKERROR ("Error: stack must contain at least one die") ;

            YYABORT ;
        }

        StackElement_t *bmost = stack_element_list_data (stack_element_list_end   (&stkd->StackElements)) ;
        StackElement_t *tmost = stack_element_list_data (stack_element_list_begin (&stkd->StackElements)) ;

        if (bmost->Type == TDICE_STACK_ELEMENT_CHANNEL)
        {
            STKERROR ("Error: cannot declare a channel as bottom-most stack element") ;

            YYABORT ;
        }

        if (stkd->HeatSink == NULL && stkd->Channel == NULL)

            fprintf (stderr, "Warning: neither heat sink nor channel has been declared\n") ;

        if (stkd->HeatSink != NULL)
        {
            if (stkd->HeatSink->SinkModel == TDICE_HEATSINK_MODEL_CONNECTION_TO_AMBIENT)
            {
                if (tmost->Type == TDICE_STACK_ELEMENT_LAYER)
                {
                    material_copy (
                         &stkd->HeatSink->SinkMaterial,
                         &tmost->Pointer.Layer->Material) ;
                }
                else
                {
                    material_copy (
                        &stkd->HeatSink->SinkMaterial,
                        &layer_list_data (layer_list_begin (&tmost->Pointer.Die->Layers))->Material) ;
                }
            }

            // Creates an extra stack element to be add in the 3d stack

            StackElement_t stack_element ;

            stack_element_init (&stack_element) ;

            stack_element.Id               = strdup ("Ambient") ;
            stack_element.Type             = TDICE_STACK_ELEMENT_HEATSINK ;
            stack_element.Pointer.HeatSink = stkd->HeatSink ;
            stack_element.NLayers          = stkd->HeatSink->NLayers ;

            stack_element_list_insert_begin (&stkd->StackElements, &stack_element) ;

            stack_element_destroy (&stack_element) ;
        }

        // Counts the number of layers and fix the layer offset starting from
        // the bottom most element in the stack. This operation can be done only
        // here since the parser processes elements in the stack from the top most.

        CellIndex_t layer_index = 0u ;

        StackElementListNode_t *stkeln ;

        for (stkeln  = stack_element_list_end (&stkd->StackElements) ;
             stkeln != NULL ;
             stkeln  = stack_element_list_prev (stkeln))
        {
            StackElement_t *stk_el = stack_element_list_data (stkeln) ;

            stk_el->Offset = layer_index ;
            layer_index   += stk_el->NLayers ;
        }

        tmost = stack_element_list_data (stack_element_list_begin (&stkd->StackElements)) ;

        if (   tmost->Type == TDICE_STACK_ELEMENT_HEATSINK
            && stkd->HeatSink->SinkModel == TDICE_HEATSINK_MODEL_CONNECTION_TO_AMBIENT)

            tmost->Offset-- ;

        stkd->Dimensions->Grid.NLayers = layer_index ;

        // Stores the vertical profile of cell heights

        stkd->Dimensions->Cell.NHeights = layer_index ;
        stkd->Dimensions->Cell.Heights =

            (CellDimension_t *) malloc (layer_index * sizeof (CellDimension_t)) ;

        if (stkd->Dimensions->Cell.Heights == NULL)
        {
            STKERROR ("Malloc heights failed") ;

            YYABORT ;
        }

        layer_index  = 0u ;

        for (stkeln  = stack_element_list_end (&stkd->StackElements) ;
             stkeln != NULL ;
             stkeln  = stack_element_list_prev (stkeln))
        {
            StackElement_t *stk_el_ = stack_element_list_data (stkeln) ;

            if (stk_el_->Type == TDICE_STACK_ELEMENT_CHANNEL)
            {
                CellIndex_t tmp ;

                for (tmp = 0u ; tmp != stk_el_->Pointer.Channel->NLayers ; tmp++)

                    stkd->Dimensions->Cell.Heights [ layer_index++ ]

                        = stk_el_->Pointer.Channel->Height ;
            }
            else if (stk_el_->Type == TDICE_STACK_ELEMENT_LAYER)
            {
                stkd->Dimensions->Cell.Heights [ layer_index++ ]

                    = stk_el_->Pointer.Layer->Height ;
            }
            else if (stk_el_->Type == TDICE_STACK_ELEMENT_DIE)
            {
                LayerListNode_t *lnd ;

                for (lnd  = layer_list_end(&stk_el_->Pointer.Die->Layers) ;
                     lnd != NULL ;
                     lnd = layer_list_prev (lnd))
                {
                    stkd->Dimensions->Cell.Heights [ layer_index++ ] = layer_list_data(lnd)->Height ;
                }
            }
            else if (stk_el_->Type == TDICE_STACK_ELEMENT_HEATSINK)
            {
                if (stkd->HeatSink->SinkModel == TDICE_HEATSINK_MODEL_TRADITIONAL)
                {
                    stkd->Dimensions->Cell.Heights [ layer_index++ ]

                        = stkd->HeatSink->SpreaderHeight ;

                    stkd->Dimensions->Cell.Heights [ layer_index++ ]

                        = stkd->HeatSink->SinkHeight ;
                }
            }
            else
            {
                sprintf (error_message, "Unknown stack type %d", stk_el_->Type) ;

                STKERROR (error_message) ;

                YYABORT ;
            }
        }

        // Evaluate the number of cells and nonzero elements

        uint64_t ncells =   (uint64_t) get_number_of_layers (stkd->Dimensions)
                          * (uint64_t) get_number_of_rows (stkd->Dimensions)
                          * (uint64_t) get_number_of_columns (stkd->Dimensions) ;

        if (ncells > INT32_MAX)
        {
            sprintf (error_message,
                "%lu are too many cells ... (SuperLU uses 'int')",
                ncells) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        stkd->Dimensions->Grid.NCells = (CellIndex_t) ncells ;

        ChannelModel_t cm =  stkd->Channel == NULL       ?
                             TDICE_CHANNEL_MODEL_NONE    :
                             stkd->Channel->ChannelModel ;

        HeatSinkModel_t hm = stkd->HeatSink == NULL    ?
                             TDICE_HEATSINK_MODEL_NONE :
                             stkd->HeatSink->SinkModel ;

        compute_number_of_connections

            (stkd->Dimensions, num_channels, cm, hm) ;
   ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1173 "stack_description_parser.y"
    {
        if (   stkd->StackElements.Size == 0

            && (yyvsp[(1) - (1)].stack_element_p)->Type == TDICE_STACK_ELEMENT_CHANNEL)
        {
            STKERROR ("Error: cannot declare a channel as top-most stack element") ;

            YYABORT ;
        }

        stack_element_list_insert_end (&stkd->StackElements, (yyvsp[(1) - (1)].stack_element_p)) ;

        stack_element_free ((yyvsp[(1) - (1)].stack_element_p)) ;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1188 "stack_description_parser.y"
    {
        if (stack_element_list_find (&stkd->StackElements, (yyvsp[(2) - (2)].stack_element_p)) != NULL)
        {
            sprintf (error_message, "Stack element %s already declared", (yyvsp[(2) - (2)].stack_element_p)->Id) ;

            stack_element_free ((yyvsp[(2) - (2)].stack_element_p)) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        StackElement_t *stkel = stack_element_list_data

            (stack_element_list_begin (&stkd->StackElements)) ;

        if (   stkel->Type == TDICE_STACK_ELEMENT_CHANNEL
            &&    (yyvsp[(2) - (2)].stack_element_p)->Type == TDICE_STACK_ELEMENT_CHANNEL)
        {
            STKERROR ("Error: cannot declare two consecutive channels") ;

            YYABORT ;
        }

        stack_element_list_insert_end (&stkd->StackElements, (yyvsp[(2) - (2)].stack_element_p)) ;

        stack_element_free ((yyvsp[(2) - (2)].stack_element_p)) ;
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1222 "stack_description_parser.y"
    {
        StackElement_t *stack_element = (yyval.stack_element_p) = stack_element_calloc () ;

        if (stack_element == NULL)
        {
            free ((yyvsp[(2) - (4)].string)) ;
            free ((yyvsp[(3) - (4)].string)) ;

            STKERROR ("Malloc stack element failed") ;

            YYABORT ;
        }

        Layer_t *layer = layer_calloc ( ) ;

        if (layer == NULL)
        {
            free ((yyvsp[(2) - (4)].string)) ;
            free ((yyvsp[(3) - (4)].string)) ;

            STKERROR ("Malloc layer for stack element failed") ;

            YYABORT ;
        }

        layer->Id = (yyvsp[(3) - (4)].string) ;

        Layer_t *tmp = layer_list_find (&stkd->Layers, layer) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown layer %s", (yyvsp[(3) - (4)].string)) ;

            layer_free (layer) ;

            free ((yyvsp[(2) - (4)].string)) ;

            stack_element_free (stack_element) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        layer_copy (layer, tmp) ;

        stack_element->Type          = TDICE_STACK_ELEMENT_LAYER ;
        stack_element->Pointer.Layer = layer ;
        stack_element->Id            = (yyvsp[(2) - (4)].string) ;
        stack_element->NLayers       = 1 ;
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1275 "stack_description_parser.y"
    {
        num_channels++ ;

        if (stkd->Channel == NULL)
        {
            STKERROR ("Error: channel used in stack but not declared") ;

            YYABORT ;
        }

        StackElement_t *stack_element = (yyval.stack_element_p) = stack_element_calloc () ;

        if (stack_element == NULL)
        {
            free ((yyvsp[(2) - (3)].string)) ;

            STKERROR ("Malloc stack element failed") ;

            YYABORT ;
        }

        stack_element->Type            = TDICE_STACK_ELEMENT_CHANNEL ;
        stack_element->Pointer.Channel = stkd->Channel ; // This might be NULL !!!
        stack_element->Id              = (yyvsp[(2) - (3)].string) ;
        stack_element->NLayers         = stkd->Channel->NLayers ;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1305 "stack_description_parser.y"
    {
        num_dies++ ;

        StackElement_t *stack_element = (yyval.stack_element_p) = stack_element_calloc () ;

        if (stack_element == NULL)
        {
            free ((yyvsp[(2) - (6)].string)) ;
            free ((yyvsp[(3) - (6)].string)) ;
            free ((yyvsp[(5) - (6)].string)) ;

            STKERROR ("Malloc stack element failed") ;

            YYABORT ;
        }

        Die_t *die = die_calloc ( ) ;

        if (die == NULL)
        {
            free ((yyvsp[(2) - (6)].string)) ;
            free ((yyvsp[(3) - (6)].string)) ;
            free ((yyvsp[(5) - (6)].string)) ;

            stack_element_free (stack_element) ;

            STKERROR ("Malloc die for stack element failed") ;

            YYABORT ;
        }

        die->Id = (yyvsp[(3) - (6)].string) ;

        Die_t *tmp = die_list_find (&stkd->Dies, die) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown die %s", (yyvsp[(3) - (6)].string)) ;

            die_free (die) ;

            free ((yyvsp[(2) - (6)].string)) ;
            free ((yyvsp[(5) - (6)].string)) ;

            stack_element_free (stack_element) ;

            STKERROR (error_message) ;

            YYABORT ;
        }

        die_copy (die, tmp) ;

        if (   fill_floorplan (&die->Floorplan, stkd->Dimensions, (yyvsp[(5) - (6)].string))
            == TDICE_FAILURE)
        {
            free ((yyvsp[(5) - (6)].string)) ;

            stack_description_destroy (stkd) ;

            YYABORT ; // CHECKME error messages printed in this case ....
        }

        free ((yyvsp[(5) - (6)].string)) ;

        stack_element->Type        = TDICE_STACK_ELEMENT_DIE ;
        stack_element->Id          = (yyvsp[(2) - (6)].string) ;
        stack_element->Pointer.Die = die ;
        stack_element->NLayers     = stack_element->Pointer.Die->NLayers ;
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1387 "stack_description_parser.y"
    {
        // StepTime is set to 1 to avoid division by zero when computing
        // the capacitance of a thermal cell

        analysis->AnalysisType = TDICE_ANALYSIS_TYPE_STEADY ;
        analysis->StepTime     = (Time_t) 1.0 ;
        analysis->SlotTime     = (Time_t) 0.0 ;
        analysis->SlotLength   = 1u ; // CHECKME

        analysis->InitialTemperature = (Temperature_t) (yyvsp[(7) - (8)].double_v);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1403 "stack_description_parser.y"
    {
        if ((yyvsp[(8) - (13)].double_v) < (yyvsp[(5) - (13)].double_v))
        {
            STKERROR ("Slot time must be higher than StepTime") ;

            YYABORT ;
        }

        if ((yyvsp[(5) - (13)].double_v) <= 0.0)
        {
            STKERROR ("StepTime must be a positive value") ;

            YYABORT ;
        }

        if ((yyvsp[(8) - (13)].double_v) <= 0.0)
        {
            STKERROR ("SlotTime must be a positive value") ;

            YYABORT ;
        }

        analysis->AnalysisType       = TDICE_ANALYSIS_TYPE_TRANSIENT ;
        analysis->StepTime           = (Time_t) (yyvsp[(5) - (13)].double_v) ;
        analysis->SlotTime           = (Time_t) (yyvsp[(8) - (13)].double_v) ;
        analysis->InitialTemperature = (Temperature_t) (yyvsp[(12) - (13)].double_v) ;

        // Execute correct division Slot / Step avoiding floating point issues
        // i.e. both slot and step are mutiplied by 10 until the decimal part
        // is removed. Then run division ...

        Time_t sl_int, sl_dec, sl = analysis->SlotTime ;
        Time_t st_int, st_dec, st = analysis->StepTime ;

        sl_dec = modf (sl, &sl_int) ;
        st_dec = modf (st, &st_int) ;

        while (sl_dec != 0.0 || st_dec != 0.0)
        {
            sl *= 10.0 ; st *= 10.0 ;

            sl_dec = modf (sl, &sl_int) ;
            st_dec = modf (st, &st_int) ;
        }

        analysis->SlotLength   = (Quantity_t) sl_int / (Quantity_t) st_int ;
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1467 "stack_description_parser.y"
    {
        add_inspection_point (output, (yyvsp[(1) - (1)].inspection_point_p)) ;

        inspection_point_free ((yyvsp[(1) - (1)].inspection_point_p)) ;
     ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1474 "stack_description_parser.y"
    {
        add_inspection_point (output, (yyvsp[(2) - (2)].inspection_point_p)) ;

        inspection_point_free ((yyvsp[(2) - (2)].inspection_point_p)) ;
     ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1490 "stack_description_parser.y"
    {
        StackElement_t stack_element ;

        stack_element_init (&stack_element) ;

        stack_element.Id = (yyvsp[(3) - (12)].string) ;

        StackElement_t *tmp = stack_element_list_find

            (&stkd->StackElements, &stack_element) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown stack element %s", (yyvsp[(3) - (12)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(9) - (12)].string)) ;

            YYABORT ;
        }

        stack_element_destroy (&stack_element) ;

        InspectionPoint_t *ipoint = (yyval.inspection_point_p) = inspection_point_calloc () ;

        if (ipoint == NULL)
        {
            free ((yyvsp[(9) - (12)].string)) ;

            STKERROR ("Malloc inspection point failed") ;

            YYABORT ;
        }

        ipoint->Type          = TDICE_OUTPUT_TYPE_TCELL ;
        ipoint->Instant       = (yyvsp[(10) - (12)].output_instant_v) ;
        ipoint->FileName      = (yyvsp[(9) - (12)].string) ;
        ipoint->StackElement  = tmp ;

        align_tcell (ipoint, (yyvsp[(5) - (12)].double_v), (yyvsp[(7) - (12)].double_v), stkd->Dimensions) ;
     ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1542 "stack_description_parser.y"
    {
        StackElement_t stack_element ;

        stack_element_init (&stack_element) ;

        stack_element.Id = (yyvsp[(3) - (10)].string) ;

        StackElement_t *tmp = stack_element_list_find

            (&stkd->StackElements, &stack_element) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown stack element %s", (yyvsp[(3) - (10)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(5) - (10)].string)) ;

            YYABORT ;
        }

        if (tmp->Type != TDICE_STACK_ELEMENT_DIE)
        {
            sprintf (error_message, "The stack element %s must be a die", (yyvsp[(3) - (10)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(5) - (10)].string)) ;

            YYABORT ;
        }

        stack_element_destroy (&stack_element) ;

        InspectionPoint_t *ipoint = (yyval.inspection_point_p) = inspection_point_calloc () ;

        if (ipoint == NULL)
        {
            free ((yyvsp[(5) - (10)].string)) ;

            STKERROR ("Malloc inspection point failed") ;

            YYABORT ;
        }

        ipoint->Type         = TDICE_OUTPUT_TYPE_TFLP ;
        ipoint->FileName     = (yyvsp[(5) - (10)].string) ;
        ipoint->Quantity     = (yyvsp[(7) - (10)].output_quantity_v) ;
        ipoint->Instant      = (yyvsp[(8) - (10)].output_instant_v) ;
        ipoint->StackElement = tmp ;
     ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1607 "stack_description_parser.y"
    {
        StackElement_t stack_element ;

        stack_element_init (&stack_element) ;

        stack_element.Id = (yyvsp[(3) - (12)].string) ;

        StackElement_t *tmp = stack_element_list_find

            (&stkd->StackElements, &stack_element) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown stack element %s", (yyvsp[(3) - (12)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(5) - (12)].string)) ;
            free ((yyvsp[(7) - (12)].string)) ;

            YYABORT ;
        }

        if (tmp->Type != TDICE_STACK_ELEMENT_DIE)
        {
            sprintf (error_message, "The stack element %s must be a die", (yyvsp[(3) - (12)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(5) - (12)].string)) ;
            free ((yyvsp[(7) - (12)].string)) ;

            YYABORT ;
        }

        stack_element_destroy (&stack_element) ;

        FloorplanElement_t *flpel = get_floorplan_element (&tmp->Pointer.Die->Floorplan, (yyvsp[(5) - (12)].string)) ;

        if (flpel == NULL)
        {
            sprintf (error_message, "Unknown floorplan element %s", (yyvsp[(5) - (12)].string)) ;

            STKERROR (error_message) ;

            free ((yyvsp[(5) - (12)].string)) ;
            free ((yyvsp[(7) - (12)].string)) ;

            YYABORT ;
        }

        InspectionPoint_t *ipoint = (yyval.inspection_point_p) = inspection_point_calloc () ;

        if (ipoint == NULL)
        {
            free ((yyvsp[(5) - (12)].string)) ;
            free ((yyvsp[(7) - (12)].string)) ;

            STKERROR ("Malloc inspection point failed") ;

            YYABORT ;
        }

        ipoint->Type             = TDICE_OUTPUT_TYPE_TFLPEL ;
        ipoint->FloorplanElement = flpel ;
        ipoint->FileName         = (yyvsp[(7) - (12)].string) ;
        ipoint->Quantity         = (yyvsp[(9) - (12)].output_quantity_v) ;
        ipoint->Instant          = (yyvsp[(10) - (12)].output_instant_v) ;
        ipoint->StackElement     = tmp ;

        free ((yyvsp[(5) - (12)].string)) ;
     ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1690 "stack_description_parser.y"
    {
        StackElement_t stack_element ;

        stack_element_init (&stack_element) ;

        stack_element.Id = (yyvsp[(3) - (8)].string) ;

        StackElement_t *tmp = stack_element_list_find

            (&stkd->StackElements, &stack_element) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown stack element %s", (yyvsp[(3) - (8)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(5) - (8)].string)) ;

            YYABORT ;
        }

        stack_element_destroy (&stack_element) ;

        InspectionPoint_t *ipoint = (yyval.inspection_point_p) = inspection_point_calloc () ;

        if (ipoint == NULL)
        {
            free ((yyvsp[(5) - (8)].string)) ;

            STKERROR ("Malloc inspection point failed") ;

            YYABORT ;
        }

        ipoint->Type         = TDICE_OUTPUT_TYPE_TMAP ;
        ipoint->Instant      = (yyvsp[(6) - (8)].output_instant_v) ;
        ipoint->FileName     = (yyvsp[(5) - (8)].string) ;
        ipoint->StackElement = tmp ;
     ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1739 "stack_description_parser.y"
    {
        StackElement_t stack_element ;

        stack_element_init (&stack_element) ;

        stack_element.Id = (yyvsp[(3) - (8)].string) ;

        StackElement_t *tmp = stack_element_list_find

            (&stkd->StackElements, &stack_element) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown stack element %s", (yyvsp[(3) - (8)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(5) - (8)].string)) ;

            YYABORT ;
        }

        stack_element_destroy (&stack_element) ;

        InspectionPoint_t *ipoint = (yyval.inspection_point_p) = inspection_point_calloc () ;

        if (ipoint == NULL)
        {
            free ((yyvsp[(5) - (8)].string)) ;

            STKERROR ("Malloc inspection point failed") ;

            YYABORT ;
        }

        ipoint->Type         = TDICE_OUTPUT_TYPE_PMAP ;
        ipoint->Instant      = (yyvsp[(6) - (8)].output_instant_v) ;
        ipoint->FileName     = (yyvsp[(5) - (8)].string) ;
        ipoint->StackElement = tmp ;
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1789 "stack_description_parser.y"
    {
        StackElement_t stack_element ;

        stack_element_init (&stack_element) ;

        stack_element.Id = (yyvsp[(3) - (10)].string) ;

        StackElement_t *tmp = stack_element_list_find

            (&stkd->StackElements, &stack_element) ;

        if (tmp == NULL)
        {
            sprintf (error_message, "Unknown stack element %s", (yyvsp[(3) - (10)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(5) - (10)].string)) ;

            YYABORT ;
        }

        if (tmp->Type != TDICE_STACK_ELEMENT_CHANNEL)
        {
            sprintf (error_message, "The stack element %s must be a channel", (yyvsp[(3) - (10)].string)) ;

            STKERROR (error_message) ;

            stack_element_destroy (&stack_element) ;

            free ((yyvsp[(5) - (10)].string)) ;

            YYABORT ;
        }

        stack_element_destroy (&stack_element) ;

        InspectionPoint_t *ipoint = (yyval.inspection_point_p) = inspection_point_calloc () ;

        if (ipoint == NULL)
        {
            free ((yyvsp[(5) - (10)].string)) ;

            STKERROR ("Malloc inspection point failed") ;

            YYABORT ;
        }

        ipoint->Type         = TDICE_OUTPUT_TYPE_TCOOLANT ;
        ipoint->FileName     = (yyvsp[(5) - (10)].string) ;
        ipoint->Quantity     = (yyvsp[(7) - (10)].output_quantity_v) ;
        ipoint->Instant      = (yyvsp[(8) - (10)].output_instant_v) ;
        ipoint->StackElement = tmp ;
     ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1849 "stack_description_parser.y"
    { (yyval.output_quantity_v) =  TDICE_OUTPUT_QUANTITY_MAXIMUM ; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1850 "stack_description_parser.y"
    { (yyval.output_quantity_v) =  TDICE_OUTPUT_QUANTITY_MINIMUM ; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1851 "stack_description_parser.y"
    { (yyval.output_quantity_v) =  TDICE_OUTPUT_QUANTITY_AVERAGE ; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1857 "stack_description_parser.y"
    { (yyval.output_instant_v) =  TDICE_OUTPUT_INSTANT_FINAL ; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1858 "stack_description_parser.y"
    { (yyval.output_instant_v) =  TDICE_OUTPUT_INSTANT_STEP ;  ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1859 "stack_description_parser.y"
    { (yyval.output_instant_v) =  TDICE_OUTPUT_INSTANT_SLOT ;  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1860 "stack_description_parser.y"
    { (yyval.output_instant_v) =  TDICE_OUTPUT_INSTANT_FINAL ; ;}
    break;



/* Line 1455 of yacc.c  */
#line 3477 "stack_description_parser.c"
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
      yyerror (stkd, analysis, output, scanner, YY_("syntax error"));
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
	    yyerror (stkd, analysis, output, scanner, yymsg);
	  }
	else
	  {
	    yyerror (stkd, analysis, output, scanner, YY_("syntax error"));
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
		      yytoken, &yylval, stkd, analysis, output, scanner);
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
		  yystos[yystate], yyvsp, stkd, analysis, output, scanner);
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
  yyerror (stkd, analysis, output, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, stkd, analysis, output, scanner);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, stkd, analysis, output, scanner);
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
#line 1863 "stack_description_parser.y"


/******************************************************************************/

void stack_description_error
(
    StackDescription_t *stkd,
    Analysis_t         *analysis,
    Output_t           *output,
    yyscan_t            scanner,
    const char         *message
)
{
    fprintf (stack_description_get_out (scanner),
             "%s:%d: %s\n",
            stkd->FileName, stack_description_get_lineno (scanner), message) ;

    stack_description_destroy (stkd) ;
    analysis_destroy          (analysis) ;
    output_destroy            (output) ;
}

/******************************************************************************/

