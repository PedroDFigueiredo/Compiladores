/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sintatica.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include "TabelaTipos.h"

#define YYSTYPE atributos

using namespace std;



struct atributos
{
    string label;
    string operador;
    string traducao;
    string tipo;
    string nomeTemp;
    int valor;
    vector<string> colLabels;
    vector<int> dimensao;
    vector<string> dimensaoString;
    
};

class VarNode{
    public: 
        string nomeTKid; //a, b;
        string nomeTemp; //Var0, Var2;
        string tipo;
        int tamString;
        int tamVetor;
        vector<int> dimensoes;
        VarNode(string , string, string, int);
};
VarNode::VarNode(string a, string b, string c, int d = 0){
    nomeTemp = a;
    tipo = b;
    nomeTKid = c;
    tamString = d;
    tamVetor = 0;
};
VarNode* getVar(string nomeTemp);
typedef map<string, VarNode*> MapVarNode;
pair<string,string> geraLabelEscopo();

class Escopo{
    public:
        int nivel;
        int profundidade;
        bool isCondicional;
        string labelInicio;
        string labelFim;
        MapVarNode tkIdTable;
        MapVarNode varTable;
        vector<Escopo*> list_escopo;
        Escopo *escopoPai;
        Escopo(int);
        Escopo(int, int);

};


Escopo::Escopo(int n){
    nivel = n;
};
Escopo::Escopo(int a, int b){
    nivel = a;
    profundidade = b;

    pair<string,string> p = geraLabelEscopo();
    labelInicio = p.first;
    labelFim = p.second;
};

//vector< Escopo*> list_escopo;
Escopo *EscopoGlobal = new Escopo(0, 0);
Escopo *EscopoAtual = EscopoGlobal;


//Contagem para tabela de variaveis
//criar por escopo
int varCount=0;
int nivel_escopo = 0;
int profu_escopo = 1;
int labelCount = 1;
string switch_var;
string condicional_label;

void iniEscopoIf();
void iniEscopo();
void fimEscopo();


void criaTabelaTipos();
void addNewVarToTable(string nomeTemp, string tipo);

//string verificaTipo(string tipoA, string operador, string tipoB);
string verificaTipo(atributos *a, atributos *b,string operador, atributos *c);
string verificaTipoRelacional(atributos *a, atributos *b,string operador, atributos *c);
pair<string, string> verificaTipoRelacional(string a, string operador, string b);
string verificaTipoAtribuicao(string label1, string operador, string label2);
string buscaTipoTabela(string tipoA, string operador, string tipoB);
string verificaTipoLogico(atributos *a, atributos *b,string operador, atributos *c);
string geraVarString(atributos *a, int flagCin);
string geraVarSubrescritaString(string a, string b);

string to_string(int i);
string addNewVar();
string geraVar(string tipo);
string geraVar(string tipo, string tkid);
string decl = "";



//busca variaveis dentro do escopo
pair<bool, VarNode*> varByTkid(string tkid);
pair<bool, VarNode*> varByNameTemp(string nomeTemp);


//prints declarações variáveis...
void printDeclarations();

//Matrizes
int auxVetor = 0;
vector<int> dimensaoMatrizOriginal;
vector<string> indexProcuradoMatriz;
void PegaDimensoesMatrizOriginal(string nomeTKid);
void PegaDimensaoIndexTemporario(atributos *a);
string CalculaIndexMatriz();
void ResetMatriz();
string retornoTraducao;

pair<string,string> geraLabelEscopo();
VarNode* getVar(string nomeTemp);
VarNode* getLabel(string label);

int yylex(void);
void yyerror(string);


#line 214 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MAIS = 258,
    TK_MENOS = 259,
    TK_MULT = 260,
    TK_RAZAO = 261,
    TK_POTENCIA = 262,
    TK_CONCAT = 263,
    TK_AND = 264,
    TK_OR = 265,
    TK_MAIOR = 266,
    TK_MENOR = 267,
    TK_DIFERENTE = 268,
    TK_IGUAL = 269,
    TK_MAIOR_IGUAL = 270,
    TK_MENOR_IGUAL = 271,
    TK_ATRIBUICAO = 272,
    TK_VAR = 273,
    TK_GLOBAL = 274,
    TK_TIPO_STRING = 275,
    TK_TIPO_FLOAT = 276,
    TK_TIPO_CHAR = 277,
    TK_TIPO_BOOL = 278,
    TK_TIPO_INT = 279,
    TK_INT = 280,
    TK_FLOAT = 281,
    TK_CHAR = 282,
    TK_BOOL = 283,
    TK_STRING = 284,
    TK_WHILE = 285,
    TK_FOR = 286,
    TK_SWITCH = 287,
    TK_CASE = 288,
    TK_IF = 289,
    TK_ELSE = 290,
    TK_ELIF = 291,
    TK_BREAK = 292,
    TK_CONTINUE = 293,
    TK_DO = 294,
    TK_DEFAULT = 295,
    TK_ABRE = 296,
    TK_FECHA = 297,
    TK_FUNC = 298,
    TK_RETORNA = 299,
    TK_RETURN = 300,
    TK_READ = 301,
    TK_WRITE = 302,
    TK_SUPER = 303,
    TK_MAIN = 304,
    TK_ID = 305,
    TK_FIM = 306,
    TK_ERROR = 307,
    TK_END_E = 308,
    TK_FIMLINHA = 309,
    TK_DIVISAO = 310
  };
#endif
/* Tokens.  */
#define TK_MAIS 258
#define TK_MENOS 259
#define TK_MULT 260
#define TK_RAZAO 261
#define TK_POTENCIA 262
#define TK_CONCAT 263
#define TK_AND 264
#define TK_OR 265
#define TK_MAIOR 266
#define TK_MENOR 267
#define TK_DIFERENTE 268
#define TK_IGUAL 269
#define TK_MAIOR_IGUAL 270
#define TK_MENOR_IGUAL 271
#define TK_ATRIBUICAO 272
#define TK_VAR 273
#define TK_GLOBAL 274
#define TK_TIPO_STRING 275
#define TK_TIPO_FLOAT 276
#define TK_TIPO_CHAR 277
#define TK_TIPO_BOOL 278
#define TK_TIPO_INT 279
#define TK_INT 280
#define TK_FLOAT 281
#define TK_CHAR 282
#define TK_BOOL 283
#define TK_STRING 284
#define TK_WHILE 285
#define TK_FOR 286
#define TK_SWITCH 287
#define TK_CASE 288
#define TK_IF 289
#define TK_ELSE 290
#define TK_ELIF 291
#define TK_BREAK 292
#define TK_CONTINUE 293
#define TK_DO 294
#define TK_DEFAULT 295
#define TK_ABRE 296
#define TK_FECHA 297
#define TK_FUNC 298
#define TK_RETORNA 299
#define TK_RETURN 300
#define TK_READ 301
#define TK_WRITE 302
#define TK_SUPER 303
#define TK_MAIN 304
#define TK_ID 305
#define TK_FIM 306
#define TK_ERROR 307
#define TK_END_E 308
#define TK_FIMLINHA 309
#define TK_DIVISAO 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 375 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      56,    57,     2,     2,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    58,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   181,   181,   190,   195,   199,   205,   210,   214,   221,
     226,   230,   236,   240,   245,   248,   251,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   270,
     274,   275,   276,   277,   280,   286,   287,   296,   302,   305,
     309,   310,   316,   321,   322,   325,   327,   331,   334,   334,
     340,   342,   342,   344,   344,   344,   344,   344,   344,   346,
     347,   348,   349,   351,   352,   357,   366,   371,   396,   414,
     435,   454,   455,   456,   459,   487,   503,   520,   525,   534,
     551,   552,   553,   554,   555,   557,   565,   571,   577,   584,
     592,   601,   621,   627,   633,   642,   648,   671,   679,   685,
     698,   704,   707,   718,   724,   735,   746,   754,   761,   764,
     779,   794,   804,   818,   831,   843,   858,   875
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIS", "TK_MENOS", "TK_MULT",
  "TK_RAZAO", "TK_POTENCIA", "TK_CONCAT", "TK_AND", "TK_OR", "TK_MAIOR",
  "TK_MENOR", "TK_DIFERENTE", "TK_IGUAL", "TK_MAIOR_IGUAL",
  "TK_MENOR_IGUAL", "TK_ATRIBUICAO", "TK_VAR", "TK_GLOBAL",
  "TK_TIPO_STRING", "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL",
  "TK_TIPO_INT", "TK_INT", "TK_FLOAT", "TK_CHAR", "TK_BOOL", "TK_STRING",
  "TK_WHILE", "TK_FOR", "TK_SWITCH", "TK_CASE", "TK_IF", "TK_ELSE",
  "TK_ELIF", "TK_BREAK", "TK_CONTINUE", "TK_DO", "TK_DEFAULT", "TK_ABRE",
  "TK_FECHA", "TK_FUNC", "TK_RETORNA", "TK_RETURN", "TK_READ", "TK_WRITE",
  "TK_SUPER", "TK_MAIN", "TK_ID", "TK_FIM", "TK_ERROR", "TK_END_E",
  "TK_FIMLINHA", "TK_DIVISAO", "'('", "')'", "';'", "'['", "']'", "','",
  "':'", "$accept", "S", "BLOCO", "BLOCO_IF", "BLOCO_SE", "COMANDOS",
  "INI_ESCOPO_IF", "INI_ESCOPO", "FIM_ESCOPO", "COMANDO", "BLOCO_",
  "OPERACAO", "ARITMETICO", "ARITMETICO2", "ARITs", "RELACIONAL", "RELs",
  "LOGICO", "LOGs", "OP_CONCAT", "OP_LOGICO", "OP_RELACIONAL",
  "OP_ARITMETICO", "OP_ARITMETICO2", "DECLARA", "DECLARA_VETOR",
  "DIMENCAO", "ATRIBUICAO", "ATRIB_VETOR", "INDEX", "INCREMENTAL",
  "DECLARA_E_ATRIBUI", "TIPO", "NUMEROS", "CONCATENACAO", "IDs", "OPs",
  "CONDICIONAL", "IF", "ELSEs", "ELSE", "SWITCHCASE", "SWITCH", "CASEs",
  "CASE", "DEFAULT", "BREAK", "CONTINUE", "LOOP", "CMD_CIN", "CMD_COUT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    40,    41,    59,    91,
      93,    44,    58
};
# endif

#define YYPACT_NINF -160

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-160)))

#define YYTABLE_NINF -93

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -15,    37,   -17,  -160,   -10,    13,  -160,  -160,   310,
     199,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,     1,    24,  -160,  -160,    13,    45,    58,    32,   149,
    -160,    34,   347,  -160,  -160,    30,    28,  -160,     9,    90,
     515,    57,    83,    59,  -160,    63,  -160,  -160,  -160,    65,
      12,   108,  -160,  -160,    81,    67,    68,  -160,    72,    73,
      86,    91,   236,   157,   149,    93,    87,   149,   133,   136,
     149,   496,     4,  -160,    14,    85,    17,    96,  -160,    88,
      70,    94,  -160,  -160,  -160,  -160,  -160,   484,  -160,  -160,
     491,  -160,  -160,  -160,  -160,  -160,  -160,   157,  -160,  -160,
     149,  -160,  -160,    50,    11,  -160,  -160,   496,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,   157,    41,    97,    99,
     152,   110,   112,   114,  -160,  -160,  -160,   107,   149,   113,
    -160,  -160,  -160,  -160,   157,    13,   117,  -160,    70,   230,
     484,    41,   484,  -160,     9,  -160,   515,   101,  -160,    83,
     496,   120,   149,   130,  -160,   108,   154,   131,    13,  -160,
     157,  -160,  -160,  -160,  -160,   132,  -160,   157,  -160,    32,
     135,   141,    14,    47,   134,   120,  -160,   143,  -160,   149,
      -2,   154,  -160,   138,   155,   140,   157,  -160,  -160,  -160,
     149,   144,   146,  -160,   170,  -160,   174,  -160,  -160,   310,
     155,   175,  -160,    13,    13,  -160,  -160,   199,  -160,  -160,
     230,  -160,  -160,   173,   192,   178,  -160,  -160,   384,   421,
    -160,  -160,   197,   273,   200,  -160,   458,  -160
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    15,    15,     2,    14,
      14,    80,    81,    82,    83,    84,    85,    87,    86,    90,
      89,     0,     0,   111,   112,    15,     0,     0,    88,     0,
      29,     0,    14,     5,    21,     0,    44,    35,     0,    45,
       0,    31,     0,     0,    66,     0,    73,    72,    71,     0,
      39,    33,    22,    28,     0,     0,     0,    23,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    44,    35,    45,    48,    39,     0,
      98,     0,    17,    59,    60,    62,    61,     0,    64,    63,
       0,    56,    55,    53,    54,    57,    58,     0,    51,    52,
       0,    19,    20,    94,     0,    18,    50,     0,    15,    27,
      26,    25,    24,     3,     4,    12,     0,    44,    45,     0,
      39,     0,     0,     0,    78,    77,    70,     0,     0,    76,
      36,    38,    43,    47,     0,    15,     0,    97,   101,     0,
       0,    34,     0,    40,    37,    45,    42,    45,    48,    46,
       0,    67,     0,     0,    92,    91,     0,    45,    15,   106,
       0,   116,   117,    75,    74,    45,   103,     0,   100,     0,
       0,     0,     0,     0,     0,    69,    96,    79,    93,     0,
       0,   108,   113,    45,    14,    45,     0,    94,    41,    68,
       0,     0,     0,   104,     0,   107,     0,    14,    99,    14,
      14,    45,    95,    15,    15,   105,   115,    14,     8,   102,
       0,   109,   110,     0,     0,     0,     6,     7,    14,    15,
     114,    11,     0,    14,     0,     9,     5,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,    -3,    43,  -160,   -58,  -141,    -1,  -159,    -7,
    -160,   -55,   -22,   -13,   158,   -21,   147,   -19,   169,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,   168,  -128,  -160,   -42,
    -160,  -160,  -126,    -9,   165,  -160,  -160,  -160,  -160,   109,
    -160,  -160,  -160,    95,  -160,  -160,  -160,  -160,  -160,  -160,
    -160
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    30,   198,   220,    60,    31,    32,    61,    62,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   107,
     100,    97,    87,    90,    43,    44,   175,    45,    46,    72,
      47,    48,    49,    78,    51,   104,   177,    52,    80,   137,
     138,    53,    54,   180,   181,   194,    55,    56,    57,    58,
      59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    50,    33,     8,   115,     9,    10,    74,    76,   119,
      77,   170,   123,   171,    88,   126,    75,    83,    84,    85,
     -92,   128,    65,    50,     9,    33,   -49,   -49,   152,     1,
     129,    83,    84,    85,     3,    68,    69,     4,   192,     5,
     193,   117,   118,   199,    83,    84,    85,     6,   214,    70,
      83,    84,    85,    50,     7,   120,   207,    63,   120,   199,
     224,   120,   127,    71,    89,   141,   -48,   -48,    79,    86,
     105,   130,   153,   164,   132,   117,   145,   143,   117,   147,
      64,   148,   215,    86,   171,   -30,   -30,   129,    82,   -30,
     -30,    71,    98,    99,    74,   157,    86,   176,   154,   -49,
     -49,    66,    86,    75,   188,   135,   136,   156,   -65,   150,
     -49,   -49,   117,   165,    67,   103,   106,   101,   172,   120,
     173,   102,   108,   121,   191,   109,   110,    75,   113,    75,
     111,   112,   166,   114,     9,   202,   124,   122,   117,   183,
     125,   174,   131,   120,   134,   117,   185,   -32,   -32,   213,
     139,   -32,   -32,   133,   158,   182,   159,     9,   -49,   -49,
     -92,   222,   -49,   -49,   117,   201,   160,   163,   115,   161,
     120,   162,    71,   167,    16,    17,    18,    19,    20,   150,
     178,   120,    16,    17,    18,    19,    20,   179,   132,   184,
      50,   187,   208,   186,   189,   196,   197,   200,    50,    73,
     211,   212,     9,     9,   190,    29,   203,    73,   204,    50,
      50,   221,   205,   116,    50,   216,   226,    50,   223,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     -15,    22,   206,   210,   217,   218,    23,    24,    25,   225,
       7,   -16,   227,   209,   146,    26,    27,   168,   144,    28,
      11,    12,    13,    14,    15,    29,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   -15,    22,   149,
     -14,   151,   155,    23,    24,    25,   195,     7,     0,     0,
     169,     0,    26,    27,     0,     0,    28,     0,     0,     0,
       0,     0,    29,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    81,    22,     0,     0,     0,     0,
      23,    24,    25,     0,     7,   -16,     0,     0,     0,    26,
      27,     0,     0,    28,     0,     0,     0,     0,     0,    29,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   -15,    22,     0,     0,     0,     0,    23,    24,    25,
       0,     7,     0,     0,     0,     0,    26,    27,     0,     0,
      28,     0,     0,     0,     0,     0,    29,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    81,    22,
       0,     0,     0,     0,    23,    24,    25,     0,     7,     0,
       0,     0,     0,    26,    27,     0,     0,    28,     0,     0,
       0,     0,     0,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   -15,    22,     0,     0,     0,
       0,    23,    24,    25,     0,   219,     0,     0,     0,     0,
      26,    27,     0,     0,    28,     0,     0,     0,     0,     0,
      29,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,    22,     0,   -14,     0,     0,    23,    24,
      25,     0,     7,     0,     0,     0,     0,    26,    27,     0,
       0,    28,     0,     0,     0,     0,     0,    29,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,     0,     0,     0,     0,    23,    24,    25,     0,     7,
       0,     0,     0,     0,    26,    27,     0,     0,    28,    16,
      17,    18,    19,    20,    29,     0,    16,    17,    18,    19,
      20,    16,    17,    18,    19,    20,    91,    92,    93,    94,
      95,    96,     0,     0,    73,     0,     0,     0,     0,     0,
     140,    73,     0,     0,     0,     0,    73,   142
};

static const yytype_int16 yycheck[] =
{
       9,    10,     9,     6,    62,     6,     7,    29,    29,    64,
      29,   139,    67,   139,     5,    70,    29,     3,     4,     5,
       8,    17,    25,    32,    25,    32,     9,    10,    17,    24,
      72,     3,     4,     5,    49,     3,     4,     0,    40,    56,
      42,    63,    63,   184,     3,     4,     5,    57,   207,    17,
       3,     4,     5,    62,    41,    64,   197,    56,    67,   200,
     219,    70,    71,    59,    55,    87,     9,    10,    34,    55,
      58,    57,    61,   128,    57,    97,    97,    90,   100,   100,
      56,   100,   210,    55,   210,    57,    58,   129,    58,    61,
      62,    59,     9,    10,   116,   116,    55,   152,   107,     9,
      10,    56,    55,   116,    57,    35,    36,   108,    58,    59,
       9,    10,   134,   134,    56,    50,     8,    58,   140,   128,
     142,    58,    41,    30,   179,    58,    58,   140,    42,   142,
      58,    58,   135,    42,   135,   190,     3,    50,   160,   160,
       4,   150,    57,   152,    56,   167,   167,    57,    58,   207,
      56,    61,    62,    57,    57,   158,    57,   158,    57,    58,
       8,   219,    61,    62,   186,   186,    56,    60,   226,    57,
     179,    57,    59,    56,    25,    26,    27,    28,    29,    59,
      50,   190,    25,    26,    27,    28,    29,    33,    57,    57,
     199,    50,   199,    58,    60,    57,    41,    57,   207,    50,
     203,   204,   203,   204,    61,    56,    62,    50,    62,   218,
     219,   218,    42,    56,   223,    42,   223,   226,   219,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    58,    58,    42,    57,    37,    38,    39,    42,
      41,    42,    42,   200,    97,    46,    47,   138,    90,    50,
      20,    21,    22,    23,    24,    56,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   100,
      34,   103,   107,    37,    38,    39,   181,    41,    -1,    -1,
      50,    -1,    46,    47,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    56,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    -1,    -1,    46,
      47,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    56,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      56,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    -1,    34,    -1,    -1,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    50,    25,
      26,    27,    28,    29,    56,    -1,    25,    26,    27,    28,
      29,    25,    26,    27,    28,    29,    11,    12,    13,    14,
      15,    16,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      56,    50,    -1,    -1,    -1,    -1,    50,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    64,    49,     0,    56,    57,    41,    65,    70,
      70,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    32,    37,    38,    39,    46,    47,    50,    56,
      65,    69,    70,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    87,    88,    90,    91,    93,    94,    95,
      96,    97,   100,   104,   105,   109,   110,   111,   112,   113,
      68,    71,    72,    56,    56,    65,    56,    56,     3,     4,
      17,    59,    92,    50,    75,    76,    78,    80,    96,    34,
     101,    31,    58,     3,     4,     5,    55,    85,     5,    55,
      86,    11,    12,    13,    14,    15,    16,    84,     9,    10,
      83,    58,    58,    50,    98,    58,     8,    82,    41,    58,
      58,    58,    58,    42,    42,    68,    56,    75,    78,    74,
      96,    30,    50,    74,     3,     4,    74,    96,    17,    92,
      57,    57,    57,    57,    56,    35,    36,   102,   103,    56,
      56,    75,    56,    76,    77,    78,    79,    78,    80,    81,
      59,    89,    17,    61,    96,    97,    70,    78,    57,    57,
      56,    57,    57,    60,    74,    78,    65,    56,   102,    50,
      90,    95,    75,    75,    96,    89,    74,    99,    50,    33,
     106,   107,    65,    78,    57,    78,    58,    50,    57,    60,
      61,    74,    40,    42,   108,   106,    57,    41,    66,    69,
      57,    78,    74,    62,    62,    42,    58,    69,    72,    66,
      58,    65,    65,    68,    71,    90,    42,    42,    57,    41,
      67,    72,    68,    70,    71,    42,    72,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    66,    66,    66,    67,
      67,    67,    68,    68,    69,    70,    71,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    76,
      77,    77,    78,    78,    78,    79,    80,    80,    81,    81,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    86,    86,    87,    87,    88,    89,    89,
      90,    90,    90,    90,    91,    92,    92,    93,    93,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     102,   102,   103,   103,   104,   104,   105,   106,   106,   107,
     108,   109,   110,   111,   111,   111,   112,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     2,     4,     4,     2,     3,
       3,     1,     2,     1,     0,     0,     0,     2,     2,     2,
       2,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     3,     3,     1,
       1,     3,     3,     3,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     3,     2,
       3,     1,     1,     1,     4,     3,     2,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     5,
       2,     1,     5,     2,     5,     6,     4,     2,     1,     4,
       3,     1,     1,     5,    10,     7,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 182 "sintatica.y" /* yacc.c:1646  */
    {

                cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing namespace std;\nint main(void)\n{\n";
                printDeclarations();
                cout <<"\n\n"<< (yyvsp[0]).traducao << "\treturn 0;\n}" << endl; 
            }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 191 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao;

            }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 196 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "";
            }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 200 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 206 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao;

            }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 211 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "";
            }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 215 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 222 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao;

            }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 227 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "";
            }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 231 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 237 "sintatica.y" /* yacc.c:1646  */
    { 
                (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;        
            }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 241 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 245 "sintatica.y" /* yacc.c:1646  */
    { 
                iniEscopoIf();
            }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 248 "sintatica.y" /* yacc.c:1646  */
    { 
                iniEscopo();
            }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 251 "sintatica.y" /* yacc.c:1646  */
    { 
                fimEscopo();
            }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 270 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                fimEscopo();
            }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 281 "sintatica.y" /* yacc.c:1646  */
    { 

                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + verificaTipo(&(yyval), &(yyvsp[-2]), (yyvsp[-1]).traducao, &(yyvsp[0]));
                
            }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 287 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label; (yyval).tipo = (yyvsp[-1]).tipo;
            }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 297 "sintatica.y" /* yacc.c:1646  */
    {
                
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + verificaTipo(&(yyval), &(yyvsp[-2]), (yyvsp[-1]).traducao, &(yyvsp[0]));
                
            }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 302 "sintatica.y" /* yacc.c:1646  */
    { 
                
                (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label; (yyval).tipo = (yyvsp[-1]).tipo;}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 310 "sintatica.y" /* yacc.c:1646  */
    {
            
                (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label;}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 317 "sintatica.y" /* yacc.c:1646  */
    {    
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + verificaTipoRelacional(&(yyval), &(yyvsp[-2]), (yyvsp[-1]).traducao, &(yyvsp[0]));
			
			}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 321 "sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label; (yyval).tipo = (yyvsp[-1]).tipo; }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 328 "sintatica.y" /* yacc.c:1646  */
    { 
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + verificaTipoLogico(&(yyval), &(yyvsp[-2]), (yyvsp[-1]).traducao, &(yyvsp[0]));
			}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 331 "sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label; (yyval).tipo = (yyvsp[-1]).tipo;  }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 358 "sintatica.y" /* yacc.c:1646  */
    {
                addNewVarToTable((yyvsp[0]).traducao, (yyvsp[0]).tipo);

                VarNode *var = getVar((yyvsp[0]).traducao);

                (yyval).traducao = "";
                
            }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 372 "sintatica.y" /* yacc.c:1646  */
    {
 			    addNewVarToTable((yyvsp[-1]).traducao, (yyvsp[-1]).tipo);
 			    
 			    (yyval).traducao = "";//$3.traducao;
 			    
 			    VarNode *a = getVar((yyvsp[-1]).traducao);
 			    
 			    
 			    for (int i = 0 ; i < (yyvsp[0]).dimensao.size(); i++)
				{
				   if(i == 0){
				        a->tamVetor = (yyvsp[0]).dimensao[i];
				   }else{
				        a->tamVetor = a->tamVetor * (yyvsp[0]).dimensao[i];
				   }
				  
				   //std::cout << $3.dimensao[i] << std::endl; 
				   a->dimensoes.push_back((yyvsp[0]).dimensao[i]);
				}
 			    
 		
 			}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 397 "sintatica.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[-1]).tipo	== "int")
 			 	{
 			 		(yyval).traducao = (yyvsp[-1]).traducao;
 			 		//std::cout << $2.valor << std::endl;
 			 	    
 			 		
 			 		(yyval).dimensao.push_back((yyvsp[-1]).valor);
 			 	
 			// 		$$.label = $2.label;
 			 	}
 			 	else
 			 	{
 			 		yyerror("Esse tipo não é aceito para um vetor");
 			 	}
 			
			}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 415 "sintatica.y" /* yacc.c:1646  */
    {
			    (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			    //$$.label = 
				// $$.label = nova_temp_var("int");
				// $$.traducao = $1.traducao; 
				// $$.traducao += $2.traducao + "\t"+ $$.label +" = "+ $1.label +" * " + $2.label+";\n" ;

			
				 for (int i = 0 ; i < (yyvsp[0]).dimensao.size(); i++)
				 {
				 	(yyvsp[-1]).dimensao.push_back((yyvsp[0]).dimensao[i]);
				 }
				 (yyval).dimensao = (yyvsp[-1]).dimensao;
			}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 435 "sintatica.y" /* yacc.c:1646  */
    {
            //Para pegar a variável do tk_id TK_ID
            //std::cout << "$1 " << getVar($1.traducao)->nomeTemp << "  $Operacao " << $3.label << std::endl; //verfica se mome da variavel já foi declarado e retorna nome temporário
            
            string aux = "";
                //$$.traducao = $3.traducao + "\t"+ $1.label + " "+ $2.label + " " +$3.label + "\n";
                if((yyvsp[0]).label != ""){ //Caso não tenha nenhuma operação antes
                    aux = verificaTipoAtribuicao(getVar((yyvsp[-2]).traducao)->nomeTemp, (yyvsp[-1]).traducao, (yyvsp[0]).label);
                    
                    (yyval).traducao = (yyvsp[0]).traducao + aux;
                }
                else{
                    aux = verificaTipoAtribuicao(getVar((yyvsp[-2]).traducao)->nomeTemp, (yyvsp[-1]).traducao, (yyvsp[0]).traducao);
                    
                    (yyval).traducao = (yyvsp[0]).traducao + aux;
                    (yyval).traducao = "\t"+getVar((yyvsp[-2]).traducao)->nomeTemp +" "+(yyvsp[-1]).traducao+" "+getVar((yyvsp[0]).traducao)->nomeTemp+";\n";
                }

            }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 460 "sintatica.y" /* yacc.c:1646  */
    {
			
                //$$.traducao = $3.traducao + "\t"+ $1.label + " "+ $2.label + " " +$3.label + "\n";
                // if($3.label != ""){ //Caso não tenha nenhuma operação antes
                //     aux = verificaTipoAtribuicao(getVar($1.traducao)->nomeTemp, $3.traducao, $4.label);
                    
                //     $$.traducao = $4.traducao + aux;
                // }
                // else{
                    string index = "";
				    
				    PegaDimensoesMatrizOriginal((yyvsp[-3]).traducao);
                    PegaDimensaoIndexTemporario(&(yyvsp[-2]));
                      
                    
				    index = CalculaIndexMatriz(); //Calcula o indice da matriz no codigo de 3 endereços
				    
				    
                   
                    (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao  + retornoTraducao +
                    "\t"+getVar((yyvsp[-3]).traducao)->nomeTemp + "[" + index + "]" + " = " + (yyvsp[0]).label + ";\n ";
                    ResetMatriz(); //Reseta os vectors das matrizes
                    
                // }
			}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 488 "sintatica.y" /* yacc.c:1646  */
    {
			    
			    if ((yyvsp[-1]).tipo	== "int")
 			  	{
 			  	    std::cout << (yyvsp[-1]).nomeTemp << std::endl;
     			  	(yyval).dimensaoString.push_back((yyvsp[-1]).label);
    			    //auxVetor = auxVetor *  $2.valor;
    			    (yyval).traducao = (yyvsp[-1]).traducao;
 			   }
 			   else
 			   {
 			 		yyerror("Esse tipo não é aceito como index de um vetor");
 		       }
 			
			}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 504 "sintatica.y" /* yacc.c:1646  */
    {
			    (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			    //$$.label = 
				// $$.label = nova_temp_var("int");
				// $$.traducao = $1.traducao; 
				// $$.traducao += $2.traducao + "\t"+ $$.label +" = "+ $1.label +" * " + $2.label+";\n" ;

			
				  for (int i = 0 ; i < (yyvsp[0]).dimensaoString.size(); i++)
				  {
				  	(yyvsp[-1]).dimensaoString.push_back((yyvsp[0]).dimensaoString[i]);
				  }
				  (yyval).dimensaoString = (yyvsp[-1]).dimensaoString;
			}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 520 "sintatica.y" /* yacc.c:1646  */
    {
                VarNode *var = getVar((yyvsp[-2]).traducao); 

                (yyval).traducao = "\t" + var->nomeTemp + " = " + var->nomeTemp + " " + (yyvsp[-1]).traducao +" 1;\n";
            }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 525 "sintatica.y" /* yacc.c:1646  */
    {
                VarNode *var = getVar((yyvsp[-2]).traducao); 

                (yyval).traducao = "\t" + var->nomeTemp + " = " + var->nomeTemp + " " + (yyvsp[-1]).traducao +" 1;\n";
            }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 535 "sintatica.y" /* yacc.c:1646  */
    {
                string aux = "";

                for (int i = 0; (i < (yyvsp[-2]).colLabels.size()) && (i < (yyvsp[0]).colLabels.size()); i++){

                    addNewVarToTable((yyvsp[-2]).colLabels[i], (yyvsp[-2]).tipo);
                    //não será necessário essa parte assim que a partede scopo for criada, 'geraVar' irá inseri a declaração para ser impressa no escopo  qual pertence
                    //aux += "\t"+getVar($2.colLabels[i])->tipo+" "+getVar($2.colLabels[i])->nomeTemp +";\n"; // DECLARA 
                    aux += verificaTipoAtribuicao(getVar((yyvsp[-2]).colLabels[i])->nomeTemp, (yyvsp[-1]).traducao, (yyvsp[0]).colLabels[i]);
                }

                (yyval).traducao = (yyvsp[0]).traducao  + aux;
            }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 558 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = geraVar((yyvsp[0]).tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";
                (yyval).valor = atoi((yyvsp[0]).traducao.c_str()); //pega o valor para utilizar no vetor
                (yyval).traducao = "\t" + (yyval).label +" = " + (yyvsp[0]).traducao + ";\n";    
                
            }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 566 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = geraVar((yyvsp[0]).tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                (yyval).traducao = "\t" + (yyval).label +" = " + (yyvsp[0]).traducao + ";\n";    
            }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 572 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = geraVar((yyvsp[0]).tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                (yyval).traducao = "\t" + (yyval).label +" = " + (yyvsp[0]).traducao + ";\n";    
            }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 578 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = getVar((yyvsp[0]).traducao)->nomeTemp; //verfica se mome da variavel já foi declarado e retorna nome temporário
                (yyval).tipo = getVar((yyvsp[0]).traducao)->tipo; //verfica se mome da variavel já foi declarado e retorna tipo
                (yyval).traducao = "";

            }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 585 "sintatica.y" /* yacc.c:1646  */
    {
			    //$1.tamString = $$.traducao.length()-1; //Pega o tamanho da string menos 1;
			    (yyval).label = geraVarString(&(yyvsp[0]), 0); // 0 pois não é do cin
			    //std::cout << "Teste: " << $1.traducao << $$.label << std::endl;
			    (yyval).traducao = "\tstrcpy (" + (yyval).label + "," + (yyvsp[0]).traducao + ");\n";
			    
			}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 593 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = geraVar((yyvsp[0]).tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                (yyval).traducao = "\t" + (yyval).label +" = " + (yyvsp[0]).traducao + ";\n";    
						
			}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 602 "sintatica.y" /* yacc.c:1646  */
    {
			    string aux = "";
			    VarNode *a = getLabel((yyvsp[-2]).label);
			    VarNode *b = getLabel((yyvsp[0]).label);
			    
			    (yyval).label = geraVarString(&(yyvsp[-2]), 0); // 0 pois não é do cin
			    aux  = "\n\tstrcpy("+(yyval).label+",\"\");";
			    
			    VarNode *c = getLabel((yyval).label);
			    
			    if((yyvsp[-2]).tipo == "string" & (yyvsp[0]).tipo == "string"){
			        
                    c->tamString = a->tamString + b->tamString;
                    
			        (yyval).traducao = aux + (yyvsp[-2]).traducao + (yyvsp[0]).traducao +"\n\tstrcat("+(yyval).label+","+(yyvsp[-2]).label+");\n\tstrcat("+(yyval).label+","+(yyvsp[0]).label+");\n"; 
			    }else{
			       	yyerror("Concatenação permitida apenas com strings");
			    }
			}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 628 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).colLabels = (yyvsp[-2]).colLabels;

                (yyval).colLabels.push_back((yyvsp[0]).traducao);
            }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 634 "sintatica.y" /* yacc.c:1646  */
    { 


                vector<string> e;
                (yyval).colLabels = e;
                (yyval).colLabels.push_back((yyvsp[0]).traducao); 
            }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 643 "sintatica.y" /* yacc.c:1646  */
    {   
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
                (yyval).colLabels = (yyvsp[-2]).colLabels;
                (yyval).colLabels.push_back((yyvsp[0]).label);
            }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 649 "sintatica.y" /* yacc.c:1646  */
    {   

                vector<string> e;
                (yyval).colLabels = e;
                if ((yyvsp[0]).label != "")
                    (yyval).colLabels.push_back((yyval).label);
                else{
                    if((yyvsp[0]).colLabels.size() > 0){
                        for (int i = 0; i < (yyvsp[0]).colLabels.size(); i++)
                        {
                            (yyval).colLabels.push_back((yyvsp[0]).colLabels[i]);
                        }
                    }
                    else
                        yyerror("ERRO");
                }
            }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 671 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao;
                (yyval).traducao += "\tgoto " + EscopoAtual->labelFim+";\n"; 
                (yyval).traducao += (yyvsp[-1]).label +":\n";
                (yyval).traducao += (yyvsp[0]).traducao + "\n" + EscopoAtual->labelFim +":\n\n";
                fimEscopo();

            }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 679 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao + (yyvsp[0]).label + ":\n//fim_if\n\n";
                fimEscopo();

            }
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 685 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label  = EscopoAtual->labelFim;

                (yyval).traducao = "\n//ini_if\n" + (yyvsp[-2]).traducao;
                (yyval).traducao += "\n\tif (!("+ (yyvsp[-2]).label +")) goto " + EscopoAtual->labelFim +";"; 
                (yyval).traducao += "\n" + (yyvsp[0]).traducao +"\n";
                /*$$.traducao += "\tgoto " + EscopoAtual->escopoPai->labelFim+":\n"; 
                $$.traducao += EscopoAtual->labelFim +":\n\n";*/

                fimEscopo();
            }
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 699 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;

            }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 707 "sintatica.y" /* yacc.c:1646  */
    {

                
                (yyval).traducao = "\n//ini_elif\n" +(yyvsp[-2]).traducao;
                (yyval).traducao += "\n\tif (!("+ (yyvsp[-2]).label +")) goto " + EscopoAtual->labelFim +";"; 
                (yyval).traducao += "\n" + (yyvsp[0]).traducao ;
                (yyval).traducao += "\ngoto " + EscopoAtual->escopoPai->labelFim +";\n"; 
                (yyval).traducao += "\n" + EscopoAtual->labelFim+":";
                fimEscopo();

            }
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 718 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = "\n//ini_else\n" +(yyvsp[0]).traducao ;
                fimEscopo();
            }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 725 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-1]).label;
                (yyval).traducao += "\ngoto "+EscopoAtual->labelFim +";\n\n";
                (yyval).traducao += (yyvsp[-1]).traducao;
                (yyval).traducao += "//fim_switch_case\n"+ EscopoAtual->labelFim +":\n\n";
                fimEscopo();


            }
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 736 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[-5]).traducao + (yyvsp[-2]).label + (yyvsp[-1]).label;
                (yyval).traducao += "\ngoto "+EscopoAtual->labelFim +";\n\n";
                (yyval).traducao += (yyvsp[-2]).traducao + (yyvsp[-1]).traducao;
                (yyval).traducao += "//fim_switch_case\n"+ EscopoAtual->labelFim +":\n\n";
                fimEscopo();

            }
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 747 "sintatica.y" /* yacc.c:1646  */
    {
                switch_var = (yyvsp[-1]).label;
                (yyval).traducao = (yyvsp[-1]).traducao;


            }
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 755 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;

            }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 765 "sintatica.y" /* yacc.c:1646  */
    {
                pair<string, string> rtn = verificaTipoRelacional(switch_var, "==", (yyvsp[-2]).label);
                (yyval).label = "\n//ini_case\n";
                (yyval).label += (yyvsp[-2]).traducao;
                (yyval).label += rtn.second;
                (yyval).label += "\n\tif ("+ rtn.first +") goto " + EscopoAtual->labelInicio +";\n"; 
                (yyval).traducao = EscopoAtual->labelInicio+ ":\n";
                (yyval).traducao += (yyvsp[0]).traducao ;
                (yyval).traducao += "//fim_case\n\n";
               // $$.traducao += EscopoAtual->labelFim+":\n\n";
                fimEscopo();


            }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 780 "sintatica.y" /* yacc.c:1646  */
    {
                pair<string, string> label = geraLabelEscopo();

                (yyval).label = "\n//ini_defalut";
                (yyval).label += "\n\tgoto " + EscopoAtual->labelInicio +";\n"; 
                (yyval).traducao = EscopoAtual->labelInicio + ":\n";
                (yyval).traducao += (yyvsp[0]).traducao ;
                (yyval).traducao += "//fim_default\n\n";

                fimEscopo();


            }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 794 "sintatica.y" /* yacc.c:1646  */
    {

                Escopo *e = EscopoAtual->escopoPai;
                while(e->escopoPai != 0 && e->isCondicional){
                    e = e->escopoPai;
                }
                (yyval).traducao = "\tgoto "+e->labelFim + ";//break\n";

            }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 804 "sintatica.y" /* yacc.c:1646  */
    {

                Escopo *e = EscopoAtual;
                while(e->escopoPai != 0 && e->isCondicional){
                    e = e->escopoPai;
                }
                (yyval).traducao = "\tgoto "+e->labelInicio + ";//continue\n";

            }
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 818 "sintatica.y" /* yacc.c:1646  */
    {

            pair<string, string> label = geraLabelEscopo();

            (yyval).traducao = "//ini_while\n"+ EscopoAtual->labelInicio + ":\n";    
            (yyval).traducao += (yyvsp[-2]).traducao;
            (yyval).traducao += "\n\tif (!("+ (yyvsp[-2]).label +")) goto " + EscopoAtual->labelFim +";"; 
            (yyval).traducao += "\n" + (yyvsp[0]).traducao ;
            (yyval).traducao += "\n\tgoto " + EscopoAtual->labelInicio +";\n";
            (yyval).traducao += "\n" + EscopoAtual->labelFim +":\n//fim_while\n\n";
            fimEscopo();

        }
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 831 "sintatica.y" /* yacc.c:1646  */
    {
            
            (yyval).traducao = "//ini_for\n"+(yyvsp[-6]).traducao;
            (yyval).traducao += "\n"+ EscopoAtual->labelInicio + "_l:\n"; 
            (yyval).traducao += (yyvsp[-4]).traducao ;
            (yyval).traducao += "\n\tif (!("+ (yyvsp[-4]).label +")) goto " + EscopoAtual->labelFim +";"; 
            (yyval).traducao += "\n" + (yyvsp[0]).traducao +"\n";
            (yyval).traducao +=  EscopoAtual->labelInicio +":\n"+ (yyvsp[-2]).traducao;
            (yyval).traducao += "\n\tgoto " + EscopoAtual->labelInicio +"_l;\n" + EscopoAtual->labelFim +":\n//fim_for\n\n";

            fimEscopo();
        }
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 843 "sintatica.y" /* yacc.c:1646  */
    {

            (yyval).traducao = "\n//ini_do_while\n"+ EscopoAtual->labelInicio + ":\n"; 
            (yyval).traducao += (yyvsp[-5]).traducao;

            (yyval).traducao += (yyvsp[-2]).traducao ;
            (yyval).traducao += "\n\tif ("+ (yyvsp[-2]).label +") goto " + EscopoAtual->labelInicio +";\n";
            (yyval).traducao += EscopoAtual->labelFim+": //fim_do_while\n\n"; 

            fimEscopo();
            //$$.traducao += "\n goto " + label.first +";\n\n" + label.second +":\n";
        }
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 859 "sintatica.y" /* yacc.c:1646  */
    {
                 if((yyvsp[-1]).tipo == "string"){
                    (yyval).label = geraVarString(&(yyvsp[-3]), 1);
                    VarNode *a = getVar((yyvsp[-1]).traducao);
                    a->tamString = 1024;
                    
    			    (yyval).traducao = "\tcin >> " + (yyval).label  + " ;\n\tstrcpy (" + a->nomeTemp + "," + (yyval).label + ");\n";
                 }
                 else{
                     
                  (yyval).traducao = "\tcin >> " + getVar((yyvsp[-1]).traducao)->nomeTemp + " ;\n"; //getVar verifica se a variavel foi declarada
                 }
            }
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 876 "sintatica.y" /* yacc.c:1646  */
    {	
				(yyval).traducao = (yyvsp[-1]).traducao;
				(yyval).traducao += "\tcout << " + (yyvsp[-1]).label + " <<\"\\n\";\n";
			}
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2523 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 881 "sintatica.y" /* yacc.c:1906  */



#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{   
   

    yyparse();
    //for (map<string,VarNode*>::iterator it=tkIdTable.begin(); it!=tkIdTable.end(); ++it)

    return 0;
}

void yyerror( string MSG )
{
    cout<<"ERROR:\n"<<MSG<<"\n";
    exit (1);
}   

std::string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string geraVar(string tipo){
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++));

    VarNode *varnode = new VarNode(var, tipo, "");

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;

    return var; 
}

string geraVarString(atributos *a, int flagCin){
   // std::cout << a->tamString << std::endl;
    //strcpy(dest, src);
    int tamString;
    
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++) );
    if(flagCin == 1){ //Se a string veio de um cin 
        tamString = 1024;
    }
    else{
        tamString = a->traducao.length()-1; //Pega o tamanho da string menos 1;
    }
    
    //std::cout <<  tamString << std::endl;
    //string varTamVetor = var + "[" + to_string(a->tamString) + "]";

    VarNode *varnode = new VarNode(var, "string", "", tamString);

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;

    return var; 
}




string geraVar(string tipo, string tkid){
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++));

    VarNode *varnode = new VarNode(var, tipo, tkid);

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;
    EscopoAtual->tkIdTable[var] = varnode;

    return var; 
}

pair<bool, VarNode*> getVarByNameTemp(string nomeTemp){
    Escopo * e = EscopoAtual;
    
    pair<bool, VarNode*> rtn;
        
    while(e->escopoPai != 0){

        if(e->varTable.find(nomeTemp)!=e->varTable.end()){
            rtn.first = true;
            rtn.second = e->varTable[nomeTemp];
            return rtn;
        }
        e = e->escopoPai;
    }
    rtn.first = false;

    return rtn;
}
pair<bool, VarNode*> getVarByTkid(string tkid){
    Escopo * e = EscopoAtual;
    
    pair<bool, VarNode*> rtn;
    while(e->escopoPai != 0){

        if(e->tkIdTable.find(tkid)!=e->tkIdTable.end()){
            rtn.first = true;
            rtn.second = e->tkIdTable[tkid];
            return rtn;
        }
        e = e->escopoPai;
    }
    rtn.first = false;

    return rtn;
}

void addNewVarToTable(string nomeTemp, string tipo){
 
    if(EscopoAtual->tkIdTable.find(nomeTemp)==EscopoAtual->tkIdTable.end()){
        //verifica se variavel existe noescopo atual
        EscopoAtual->tkIdTable[nomeTemp] = EscopoAtual->varTable[geraVar(tipo, nomeTemp)];
    }else{
        //verifica se a nova variavel está na tabela
        pair<bool, VarNode*> p = getVarByTkid(nomeTemp);
        if(p.first){
            yyerror("error: redeclaração da variavel '"+tipo+" "+nomeTemp+ "'\n");
        }else{
            EscopoAtual->tkIdTable[nomeTemp] = EscopoAtual->varTable[geraVar(tipo, nomeTemp)];
        }
    }
}


//busca variavel por tkid
VarNode* getVar(string nomeTemp){
    pair<bool, VarNode*> p = getVarByTkid(nomeTemp);
    if(!p.first){
        yyerror("error: variavel não foi declarada '"+nomeTemp+ "'\n");
    }

    return p.second;
}
//busca variavel por label
VarNode* getLabel(string label){
    pair<bool, VarNode*> p = getVarByNameTemp(label);
    if(!p.first){
        yyerror("error: variavel temporária inexistente '"+label+ "'\n");
    }

    return p.second;
}

string verificaTipo(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = buscaTipoTabela(b->tipo, operador, c->tipo);
    string var = "", rtn = "";

    if(b->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ b->label +";\n";
        b->label = var;
    }

    if(c->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ c->label +";\n";
        c->label = var;
    }
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}

string verificaTipoRelacional(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = buscaTipoTabela(b->tipo, operador, c->tipo); 
    string var = "", rtn = "";
/*
    if(b->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ b->label +";\n";
        b->label = var;
    }

    if(c->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ c->label +";\n";
        c->label = var;
    }
*/
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}
pair<string, string> verificaTipoRelacional(string a, string operador, string b){
    string tipo = buscaTipoTabela(getLabel(a)->tipo, operador, getLabel(b)->tipo);

    string var = geraVar(tipo);
 
    pair<string, string> rtn;
    rtn.second = "\t" +  var +" = "+a+" "+operador + " "+b+";\n";
    rtn.first = var;
    return rtn ;

}


string verificaTipoLogico(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = "bool"; //buscaTipoTabela(b->tipo, operador, c->tipo); 
  
    string var = "", rtn = "";
    
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}


string verificaTipoAtribuicao(string label1, string operador, string label2){
    VarNode *a = getLabel(label1);
    VarNode *b = getLabel(label2);
    string tipo = buscaTipoTabela(a->tipo, operador, b->tipo);
    //std::cout << "tipo: " <<tipo << std::endl;
    string var = "", rtn = "";

    if(b->tipo != tipo) {
        var = geraVar(tipo);
        //rtn += "\t" + tipo + " " + var +" = " + "("+ tipo +") "+ b->nomeTemp +";\n";
        rtn += "\t" + var +" = " + "("+ tipo +") "+ b->nomeTemp +";\n";
        rtn += "\t" + a->nomeTemp +" = " + var + ";\n";
    } 
    else{
         //rtn += "\t" + tipo + " " + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
         if(a->tipo == "string") //caso seja string é necessário utilizar o strcpy;
         { 
             geraVarSubrescritaString(a->nomeTemp, b->nomeTemp);
             rtn += "\tstrcpy (" + a->nomeTemp + "," + b->nomeTemp  + ");\n";
         }
         else
         {
             rtn += "\t" + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
         }
         

    }
    return rtn;
}

// string AtribuicaoEntradaCin(string label1){
//     VarNode *a = getLabel(label1);
   
   
//     string var = "", rtn = "";
    
    
//     if(a->tipo == "string") //caso seja string é necessário utilizar o strcpy;
//     { 
//         geraVarSubrescritaString(a->nomeTemp, b->nomeTemp);
//         rtn += "\tstrcpy (" + a->nomeTemp + "," + b->nomeTemp  + ");\n";
//     }
//     else
//     {
//         rtn += "\t" + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
//     }
         

//     }
//     return rtn;
// }

string geraVarSubrescritaString(string varA, string varB){
    VarNode *a = getLabel(varA);
    VarNode *b = getLabel(varB);
 
    int tamString = b->tamString; //Pega o tamanho da string menos 1;
     
    //std::cout << b->tamString << std::endl;
    //string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++) );
    //string varTamVetor = var + "[" + to_string(tamString) + "]";
    a->tamString = tamString;
    
    //a->nomeTemp = var;

    //VarNode *varnode = new VarNode(var, "string", "", tamString);

    //INCLUI EM BLOCO do ESCOPO atual
    //EscopoAtual->labelTable[var] = varnode;

    return "nada"; 
}

//busca na tabela tipo resultante de uma operação
string buscaTipoTabela(string tipoA, string operador, string tipoB){
    if(TabelaTipos.empty()){
        criaTabelaTipos();
    }
    string busca = tipoA+operador+tipoB;
    string retorno  = TabelaTipos.find(busca)->second;
    if(retorno == "ERRO")
        yyerror("ERRO");
    
    //TabelaTipos[busca]
    return retorno;
}
void iniEscopoIf(){
    iniEscopo();
    EscopoAtual->isCondicional = true;   
}
void iniEscopo(){
        
    nivel_escopo++;

    Escopo *e = new Escopo(nivel_escopo);

    pair<string,string> p = geraLabelEscopo();

    e->isCondicional = false;
    e->labelInicio = p.first;
    e->labelFim = p.second;

    e->profundidade = profu_escopo;
    profu_escopo++;
    
    EscopoAtual->list_escopo.push_back(e);
    e->escopoPai = EscopoAtual;
    EscopoAtual = e;

}
void fimEscopo(){
    nivel_escopo--;
    EscopoAtual = EscopoAtual->escopoPai;
}
void printDeclarations(Escopo *esc){
    string temp = "";

    for (int i = 0; i< esc->list_escopo.size(); ++i){
        temp="";

        for( MapVarNode::const_iterator it = esc->list_escopo[i]->varTable.begin(); it != esc->list_escopo[i]->varTable.end(); ++it ){
            temp += "\t"
                    + (it->second->tipo != "string" ? it->second->tipo : "char") +" " //Se tipo for string é necessário transformar para char na declaração
                    + it->second->nomeTemp
                    + (it->second->tamString > 0 ? "[" + to_string(it->second->tamString) + "]" : "") //verifica se é string, se for define o tamanho
                    + (it->second->tamVetor > 0 ? "[" + to_string(it->second->tamVetor) + "]" : "") //verifica se é vetor, se for define o tamanho
                    + "; "+(it->second->nomeTKid == "" ? "" : " //variavel: "+it->second->nomeTKid) +"\n";
        }
        cout<<temp;
        printDeclarations(esc->list_escopo[i]);
        
    }


}
void printDeclarations(){
    
    printDeclarations(EscopoGlobal);
   
}

pair<string,string> geraLabelEscopo(){
    pair<string, string> r;
    r.first = "INI_"+to_string(profu_escopo);
    r.second = "FIM_"+to_string(profu_escopo);

    return r;
}
string getLabelEscopoFim(){
    return EscopoAtual->labelFim;
}


void PegaDimensoesMatrizOriginal(string nomeTKid){ //pegar dimensões da matriz original e guarda no vector global dimensaoMatrizOriginal do ultimo elemento para o primeiro

    VarNode *a = getVar(nomeTKid);
    for (int i = a->dimensoes.size()-1 ; i >= 0; i--)
    {
        //index = $2.dimensao[i]-1 *  
        dimensaoMatrizOriginal.push_back(a->dimensoes[i]);
        //std::cout << "dimensoes " << a->dimensoes[i] << std::endl;
 	    //$1.dimensao.push_back($2.dimensao[i]);
    }
}


void PegaDimensaoIndexTemporario(atributos *a){
    //pegar dimensão do index da matriz que está sendo inserido
    for (int i = 0 ; i < a->dimensaoString.size(); i++)
    {
        string var = geraVar("int");
        
        //index = $2.dimensao[i]-1 *  
        //std::cout << "index " << a->dimensaoString[i] << std::endl;
        
        indexProcuradoMatriz.push_back(a->dimensaoString[i]);
        //$1.dimensao.push_back($2.dimensao[i]);
    }
}

// int CalculaIndexMatriz(){
//     int index = 0;
    
    
//     for (int i = 0 ; i < dimensaoMatrizOriginal.size()-1; i++){ //Faz o calculo da posição do index
//         std::cout << "index: " << indexProcuradoMatriz[i] << " coluna: " << dimensaoMatrizOriginal[i] << std::endl;
//         index += indexProcuradoMatriz[i]*dimensaoMatrizOriginal[i];
//         std::cout << "dim" << indexProcuradoMatriz[i]*dimensaoMatrizOriginal[i]  << std::endl;
//     }
//     index = index + indexProcuradoMatriz.back(); //Adiciona a coluna final ao calculo
//     std::cout <<  "indexProcuradoMatriz " << indexProcuradoMatriz.back() << std::endl;
    
    
//     std::cout << "Final " << index << std::endl;
    
//     return index;
// }

string CalculaIndexMatriz(){
    string var = geraVar("int");
    string index = "\t" + var + " = 0;\n";
    
    
    //std::cout << "var" << var << std::endl;
    
    for (int i = 0 ; i < dimensaoMatrizOriginal.size()-1; i++){ //Faz o calculo da posição do index
         //std::cout << "index: " << indexProcuradoMatriz[i] << " coluna: " << dimensaoMatrizOriginal[i] << std::endl;
         index += "\t" + var + " = "  + var +  " + " + indexProcuradoMatriz[i] + ";\n";
         index += "\t" + var + " = " + var + " * " + to_string(dimensaoMatrizOriginal[i]) + ";\n";
        
    //     std::cout << "dim" << indexProcuradoMatriz[i]*dimensaoMatrizOriginal[i]  << std::endl;
    }
     index +=  "\t" + var + " = " + var + " + " + indexProcuradoMatriz.back() + ";\n";; //Adiciona a coluna final ao calculo
     retornoTraducao = index;
     
    // std::cout << index << std::endl;
    // std::cout <<  "indexProcuradoMatriz " << indexProcuradoMatriz.back() << std::endl;
    // std::cout << "Final " << index << std::endl;
    
     return var;
}

void ResetMatriz(){
    dimensaoMatrizOriginal.clear();
    indexProcuradoMatriz.clear();
    retornoTraducao = "";
}
