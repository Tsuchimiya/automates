#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "yacc.y"
  #include "y.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include "symboles.h"
  #include "operations.h"
  #include "instr.h"
  #include "fonctions.h"

  /* R23 Save du return*/
  /* R22 Décalage VD initialement = 0*/
  /* R21 adresse retour*/
  int prof=0;
  int save;
  void yyerror (char const *s);
  
#line 18 "yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char *var;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 44 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tmin 257
#define tplus 258
#define tmul 259
#define tdiv 260
#define tif 261
#define telse 262
#define twhile 263
#define tao 264
#define taf 265
#define tpo 266
#define tpf 267
#define tv 268
#define tpv 269
#define teq 270
#define teqeq 271
#define tret 272
#define tint 273
#define tstring 274
#define tet 275
#define tou 276
#define tinclude 277
#define tdefine 278
#define tconst 279
#define tmain 280
#define tinf 281
#define tinfeq 282
#define tsup 283
#define tsupeq 284
#define terror 285
#define tprintf 286
#define tnb 287
#define tid 288
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
   11,    0,   10,   10,   13,    9,   14,   12,   12,   15,
    4,    4,   16,    5,    5,   19,   17,   20,    8,   18,
   18,   18,   18,   18,   18,   25,   26,   24,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,   27,   28,   23,   29,   30,    2,
    6,    6,    7,    7,   21,   21,   31,   31,   22,   32,
   32,
};
static const short yylen[] = {                            2,
    0,    2,    2,    1,    0,    7,    0,    7,    0,    0,
    4,    0,    0,    5,    0,    0,    4,    0,    7,    3,
    3,    3,    2,    2,    0,    0,    0,    8,    2,    1,
    1,    3,    3,    3,    3,    3,    3,    3,    1,    3,
    3,    3,    3,    3,    0,    0,    7,    0,    0,    6,
    2,    0,    3,    0,    3,    0,    1,    3,    3,    3,
    0,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    2,    4,    0,    0,    3,    7,
    5,    0,    0,    0,    0,    0,   10,    0,    0,    0,
   18,    8,    6,    0,   11,    0,    0,    0,   45,    0,
    0,    0,    0,    0,    0,    0,    0,   13,    0,    0,
    0,    0,   48,    0,    0,    0,    0,    0,   23,   24,
    0,    0,   31,    0,    0,   39,    0,    0,    0,   59,
    0,    0,   22,    0,   20,   21,   14,    0,    0,    0,
    0,    0,   26,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,    0,   40,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   35,   46,
   60,    0,   51,    0,   19,   16,   27,    0,    0,   50,
    0,    0,   47,   53,    0,    0,   28,   17,   29,
};
static const short yydgoto[] = {                          1,
   55,   56,  117,   15,   25,   85,  103,   22,    4,    5,
    2,    6,   13,   12,   20,   51,  107,   33,  111,   26,
   34,   35,   36,   37,   92,  112,   40,  108,   61,  104,
   42,   60,
};
static const short yysindex[] = {                         0,
    0, -250, -263, -250,    0,    0, -221, -212,    0,    0,
    0, -217, -217, -227, -195, -188,    0, -174, -174, -173,
    0,    0,    0, -159,    0, -208, -167, -143,    0, -149,
 -204, -132, -130, -128, -126, -208, -208,    0, -196, -112,
 -115, -110,    0, -196, -208, -196, -208, -208,    0,    0,
 -173, -196,    0, -109, -171,    0, -196, -196, -149,    0,
 -196,  -71,    0, -151,    0,    0,    0, -131, -196, -196,
 -196, -196,    0, -196, -196, -196, -196, -196, -196, -196,
 -111,  -71, -110,  -91,    0, -127,    0,   70, -244,  -51,
  -36, -105,   74, -275,  -87, -185, -220, -123,    0,    0,
    0, -196,    0, -104,    0,    0,    0, -105,  -91,    0,
 -208, -100,    0,    0,  -90, -105,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,  174,    0,  174,    0,    0,    0,    0,    0,    0,
    0,  -89,  -89,    0,    0,    0,    0,    0,    0,  -86,
    0,    0,    0,    0,    0, -267,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -150, -150,    0,    0,    0,
 -152,  -93,    0,    0, -150,    0, -150, -150,    0,    0,
  -86,    0,    0, -200,    0,    0,    0,    0,    0,    0,
  -85,  -70,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -134,  -93,  -84,    0,    0,    0,  -41,   29, -233,
 -166,    0,   69,   64,   44,   24,    4,  -16,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -84,    0,
 -192,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -28,  -26,    0,  166,  147,    0,   92,  183,    0,  199,
    0,    0,    0,    0,    0,    0,  -88,  -33,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  149,  131,
};
#define YYTABLESIZE 358
static const short yytable[] = {                         32,
   76,   56,   49,   50,   25,   77,   78,   79,   80,   32,
   32,   63,   69,   65,   66,   62,    7,   64,   32,  113,
   32,   32,    3,   68,    8,   43,   74,  119,   81,   82,
   75,   76,   84,   43,   43,   43,   77,   78,   79,   80,
   88,   89,   90,   91,   10,   93,   94,   95,   96,   97,
   98,   99,   28,   11,   29,   14,   30,   30,   30,   30,
   17,   43,   79,   80,   30,   44,   30,   30,   30,   52,
   30,   18,   25,  109,   30,   30,   56,  115,   19,   31,
   30,   30,   30,   30,   32,   69,   70,   71,   72,   21,
   53,   54,   44,   44,   24,   73,   78,   79,   80,   74,
   44,   44,   44,   75,   76,   69,   70,   71,   72,   77,
   78,   79,   80,   27,   25,   57,   57,   86,   56,   74,
   38,   25,   39,   75,   76,   69,   70,   71,   72,   77,
   78,   79,   80,   58,   58,   87,   45,  105,   41,   74,
   47,   46,   48,   75,   76,   69,   70,   71,   72,   77,
   78,   79,   80,   57,   58,  100,   43,   59,  106,   74,
   80,  116,  110,   75,   76,   69,   70,   71,   72,   77,
   78,   79,   80,    9,  118,   61,  102,   12,   16,   74,
   15,   52,   54,   75,   76,   69,   70,   71,   72,   77,
   78,   79,   80,   77,   78,   79,   80,   67,   55,   74,
  114,   23,    9,   75,   76,   69,   70,   83,   72,   77,
   78,   79,   80,  101,    0,   42,   42,   42,   42,   74,
   69,   70,    0,   75,   76,   42,   42,   42,    0,   77,
   78,   79,   80,    0,   74,    0,    0,    0,   75,   76,
   34,   34,   34,   34,   77,   78,   79,   80,    0,    0,
   34,   34,   34,    0,   34,    0,    0,    0,   34,   34,
   33,   33,   33,   33,   34,   34,   34,    0,    0,    0,
   33,   33,   33,    0,   33,    0,    0,    0,   33,   33,
   32,   32,   32,   32,   33,   33,   41,   41,   41,    0,
   32,   32,   32,    0,   32,   41,   41,   41,   32,   32,
   38,   38,   38,   38,   32,    0,    0,    0,    0,    0,
   38,   38,   38,    0,   38,    0,    0,    0,   38,   38,
   37,   37,   37,   37,    0,   36,   36,   36,   36,    0,
   37,   37,   37,    0,   37,   36,   36,   36,   37,   36,
   74,    0,    0,    0,   75,   76,    0,    0,   75,   76,
   77,   78,   79,   80,   77,   78,   79,   80,
};
static const short yycheck[] = {                         26,
  276,  269,   36,   37,  272,  281,  282,  283,  284,   36,
   37,   45,  257,   47,   48,   44,  280,   46,   45,  108,
   47,   48,  273,   52,  288,  259,  271,  116,   57,   58,
  275,  276,   61,  267,  268,  269,  281,  282,  283,  284,
   69,   70,   71,   72,  266,   74,   75,   76,   77,   78,
   79,   80,  261,  266,  263,  273,  257,  258,  259,  260,
  288,  266,  283,  284,  273,  270,  267,  268,  269,  266,
  271,  267,  265,  102,  275,  276,  269,  111,  267,  288,
  281,  282,  283,  284,  111,  257,  258,  259,  260,  264,
  287,  288,  259,  260,  268,  267,  282,  283,  284,  271,
  267,  268,  269,  275,  276,  257,  258,  259,  260,  281,
  282,  283,  284,  273,  265,  268,  269,  269,  269,  271,
  288,  272,  266,  275,  276,  257,  258,  259,  260,  281,
  282,  283,  284,  268,  269,  267,  269,  265,  288,  271,
  269,  272,  269,  275,  276,  257,  258,  259,  260,  281,
  282,  283,  284,  266,  270,  267,  266,  268,  264,  271,
  284,  262,  267,  275,  276,  257,  258,  259,  260,  281,
  282,  283,  284,    0,  265,  269,  268,  267,   13,  271,
  267,  267,  267,  275,  276,  257,  258,  259,  260,  281,
  282,  283,  284,  281,  282,  283,  284,   51,  269,  271,
  109,   19,    4,  275,  276,  257,  258,   59,  260,  281,
  282,  283,  284,   83,   -1,  257,  258,  259,  260,  271,
  257,  258,   -1,  275,  276,  267,  268,  269,   -1,  281,
  282,  283,  284,   -1,  271,   -1,   -1,   -1,  275,  276,
  257,  258,  259,  260,  281,  282,  283,  284,   -1,   -1,
  267,  268,  269,   -1,  271,   -1,   -1,   -1,  275,  276,
  257,  258,  259,  260,  281,  282,  283,   -1,   -1,   -1,
  267,  268,  269,   -1,  271,   -1,   -1,   -1,  275,  276,
  257,  258,  259,  260,  281,  282,  258,  259,  260,   -1,
  267,  268,  269,   -1,  271,  267,  268,  269,  275,  276,
  257,  258,  259,  260,  281,   -1,   -1,   -1,   -1,   -1,
  267,  268,  269,   -1,  271,   -1,   -1,   -1,  275,  276,
  257,  258,  259,  260,   -1,  257,  258,  259,  260,   -1,
  267,  268,  269,   -1,  271,  267,  268,  269,  275,  271,
  271,   -1,   -1,   -1,  275,  276,   -1,   -1,  275,  276,
  281,  282,  283,  284,  281,  282,  283,  284,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 288
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tmin","tplus","tmul","tdiv",
"tif","telse","twhile","tao","taf","tpo","tpf","tv","tpv","teq","teqeq","tret",
"tint","tstring","tet","tou","tinclude","tdefine","tconst","tmain","tinf",
"tinfeq","tsup","tsupeq","terror","tprintf","tnb","tid","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : Prog",
"$$1 :",
"Prog : $$1 Fonctions",
"Fonctions : Fonction Fonctions",
"Fonctions : Main",
"$$2 :",
"Fonction : tint tid tpo $$2 Args tpf BodyFct",
"$$3 :",
"Main : tint tmain tpo $$3 Args tpf BodyFct",
"Main :",
"$$4 :",
"Args : tint tid $$4 ArgsN",
"Args :",
"$$5 :",
"ArgsN : tv tint tid $$5 ArgsN",
"ArgsN :",
"$$6 :",
"Body : tao $$6 Instrs taf",
"$$7 :",
"BodyFct : tao $$7 Instrs tret E tpv taf",
"Instrs : Aff tpv Instrs",
"Instrs : Decl tpv Instrs",
"Instrs : Invoc tpv Instrs",
"Instrs : While Instrs",
"Instrs : If Instrs",
"Instrs :",
"$$8 :",
"$$9 :",
"If : tif tpo E tpf $$8 Body $$9 Else",
"Else : telse Body",
"E : tid",
"E : tnb",
"E : E tinf E",
"E : E tinfeq E",
"E : E tsup E",
"E : E tsupeq E",
"E : E teqeq E",
"E : E tet E",
"E : E tou E",
"E : Invoc",
"E : tpo E tpf",
"E : E tplus E",
"E : E tmin E",
"E : E tmul E",
"E : E tdiv E",
"$$10 :",
"$$11 :",
"While : twhile $$10 tpo E tpf $$11 Body",
"$$12 :",
"$$13 :",
"Invoc : tid tpo $$12 Params $$13 tpf",
"Params : E ParamsN",
"Params :",
"ParamsN : tv E ParamsN",
"ParamsN :",
"Aff : tid teq E",
"Aff :",
"Decl1 : tid",
"Decl1 : tid teq E",
"Decl : tint Decl1 Decln",
"Decln : tv Decl1 Decln",
"Decln :",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 326 "yacc.y"

  void yyerror (char const *s) {
   extern int yylineno;
  fprintf(stderr, "At line %d: %s\n", yylineno, s);
 }

main ()
{
  return yyparse() ;
}

#line 390 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 51 "yacc.y"
	{
     ajout_instr(AFC,R21,0,VIDE);
   ajout_instr(AFC,R22,0,VIDE);
   ajout_instr(AFC,R23,0,VIDE);
ajout_instr(JMP,0,VIDE,VIDE);
}
break;
case 2:
#line 56 "yacc.y"
	{printf("prog\n");}
break;
case 4:
#line 61 "yacc.y"
	{printf("affiche instr\n");affiche_instr();printf("INDEX TAB: %d INDEX TMP: %d \n",i_tab(),i_tmp());}
break;
case 5:
#line 64 "yacc.y"
	{
   ajout_fct(yystack.l_mark[-1].var,indice_tab(),0);
   
 }
break;
case 6:
#line 67 "yacc.y"
	{printf("fct\n");
   /*printf("Adresse body fct : %d, adresse tmp : %d\n",$7,$$);*/
   ajout_instr(LOAD,R23,yystack.l_mark[0].nb,VIDE);
   /*   ajout_instr(STORE,$$,R5,VIDE);*/
   ajout_instr(JMPR,R21,VIDE,VIDE);
   reset_symb();
  
 }
break;
case 7:
#line 76 "yacc.y"
	{instr[3][1]=indice_tab()-1;}
break;
case 8:
#line 76 "yacc.y"
	{printf("main\n");}
break;
case 10:
#line 79 "yacc.y"
	{ajout(yystack.l_mark[0].var,0,prof);}
break;
case 12:
#line 81 "yacc.y"
	{printf("args\n");}
break;
case 13:
#line 83 "yacc.y"
	{ajout(yystack.l_mark[0].var,0,prof);}
break;
case 15:
#line 85 "yacc.y"
	{printf("aargsn\n");}
break;
case 16:
#line 87 "yacc.y"
	{prof++;}
break;
case 17:
#line 88 "yacc.y"
	{printf("Body %d\n",prof);enlever(prof);prof--;}
break;
case 18:
#line 90 "yacc.y"
	{printf("Body fct\n");prof++;}
break;
case 19:
#line 90 "yacc.y"
	{yyval.nb=yystack.l_mark[-2].nb;printf("Body fct%d\n",prof);enlever(prof);prof--;}
break;
case 25:
#line 100 "yacc.y"
	{printf("instrs\n");}
break;
case 26:
#line 102 "yacc.y"
	{ 
  ajout_instr(LOAD,R0,yystack.l_mark[-1].nb,VIDE);
  ajout_instr(AFC,R1,0,VIDE);
  ajout_instr(EQU,R0,R0,R1);
  yystack.l_mark[-2].nb=indice_tab();
  ajout_instr(JMPC,0,R0,VIDE);
       }
break;
case 27:
#line 109 "yacc.y"
	{ printf("if\n");  instr[yystack.l_mark[-4].nb][1]=indice_tab()+1;
  ajout_instr(LOAD,R0,yystack.l_mark[-3].nb,VIDE);
  yystack.l_mark[-4].nb=indice_tab(); 
  ajout_instr(JMPC,0,R0,VIDE);

}
break;
case 28:
#line 114 "yacc.y"
	{instr[yystack.l_mark[-6].nb][1]=yystack.l_mark[0].nb;}
break;
case 29:
#line 116 "yacc.y"
	{yyval.nb=indice_tab();}
break;
case 30:
#line 120 "yacc.y"
	{printf("tid arithm\n"); 
   if (adresse(yystack.l_mark[0].var)!=-1) 
     {printf("%d \n",adresse(yystack.l_mark[0].var));yyval.nb=ajout_tmp();
       ajout_instr(LOAD,R0,adresse(yystack.l_mark[0].var),VIDE);
       ajout_instr(STORE,yyval.nb,R0,VIDE);} 
   else printf("erreur var non declaree %s\n", yystack.l_mark[0].var);}
break;
case 31:
#line 127 "yacc.y"
	{printf("nombre : %d\n", yystack.l_mark[0].nb); 
        ajout_instr(AFC,R0,yystack.l_mark[0].nb,VIDE); 
	yyval.nb=ajout_tmp(); 
	ajout_instr(STORE,yyval.nb,R0,VIDE);
        }
break;
case 32:
#line 133 "yacc.y"
	{ ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE);
            ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	    ajout_instr(INF,R0,R0,R1);
	    free_last_tmp(); /* grossissement pile ? */
	    free_last_tmp();
	    yyval.nb=ajout_tmp();
	    ajout_instr(STORE,yyval.nb,R0,VIDE);
}
break;
case 33:
#line 142 "yacc.y"
	{ ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE);
            ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	    ajout_instr(INFE,R0,R0,R1);
	    free_last_tmp();
	    free_last_tmp(); /* grossissement pile ? */
	    yyval.nb=ajout_tmp();
	    ajout_instr(STORE,yyval.nb,R0,VIDE);
}
break;
case 34:
#line 151 "yacc.y"
	{ ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE);
            ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	    ajout_instr(SUP,R0,R0,R1);
	    free_last_tmp(); /* grossissement pile ? */
	    yyval.nb=ajout_tmp();
	    ajout_instr(STORE,yyval.nb,R0,VIDE);
}
break;
case 35:
#line 159 "yacc.y"
	{ ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE);
            ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	    ajout_instr(SUPE,R0,R0,R1);
	    free_last_tmp();
	    free_last_tmp(); /* grossissement pile ? */
	    yyval.nb=ajout_tmp();
	    ajout_instr(STORE,yyval.nb,R0,VIDE);
}
break;
case 36:
#line 168 "yacc.y"
	{  ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE); /* MARCHE PAS*/
            ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	    ajout_instr(EQU,R0,R0,R1);
	    free_last_tmp();
	    free_last_tmp(); 
	    yyval.nb=ajout_tmp();
	    ajout_instr(STORE,yyval.nb,R0,VIDE);
    }
break;
case 37:
#line 176 "yacc.y"
	{ajout_instr(AFC,R0,0,VIDE);
           ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	   ajout_instr(LOAD,R2,yystack.l_mark[-2].nb,VIDE);
	   ajout_instr(MUL,R1,R1,R2);
	   ajout_instr(SUP,R0,R1,R0);
    free_last_tmp();
	   free_last_tmp();
	   yyval.nb=ajout_tmp();
	   ajout_instr(STORE,yyval.nb,R0,VIDE);
    }
break;
case 38:
#line 187 "yacc.y"
	{ajout_instr(AFC,R0,0,VIDE);
           ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	   ajout_instr(LOAD,R2,yystack.l_mark[-2].nb,VIDE);
	   ajout_instr(ADD,R1,R1,R2);
	   ajout_instr(SUP,R0,R1,R0);
    free_last_tmp();
	   free_last_tmp();
	   yyval.nb=ajout_tmp();
	   ajout_instr(STORE,yyval.nb,R0,VIDE);

	   }
break;
case 39:
#line 198 "yacc.y"
	{yyval.nb=yystack.l_mark[0].nb; }
break;
case 40:
#line 199 "yacc.y"
	{yyval.nb=yystack.l_mark[-1].nb;}
break;
case 41:
#line 200 "yacc.y"
	{printf("ajout\n");
               ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE);
               ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	       ajout_instr(ADD,R0,R1,R0);
	       free_last_tmp();free_last_tmp();
	       yyval.nb=ajout_tmp(); 
               ajout_instr(STORE,yyval.nb,R0,VIDE);
               }
break;
case 42:
#line 209 "yacc.y"
	{printf("soustraction\n");
               ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE);
               ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	       ajout_instr(SOU,R0,R0,R1);
	       free_last_tmp();free_last_tmp();
	       yyval.nb=ajout_tmp(); 
               ajout_instr(STORE,yyval.nb,R0,VIDE);}
break;
case 43:
#line 217 "yacc.y"
	{printf("mult\n");
               ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE);
               ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	       ajout_instr(MUL,R0,R1,R0);
	       free_last_tmp();free_last_tmp();
	       yyval.nb=ajout_tmp(); 
               ajout_instr(STORE,yyval.nb,R0,VIDE);}
break;
case 44:
#line 225 "yacc.y"
	{printf("div\n");
                ajout_instr(LOAD,R0,yystack.l_mark[-2].nb,VIDE);
               ajout_instr(LOAD,R1,yystack.l_mark[0].nb,VIDE);
	       ajout_instr(DIV,R0,R0,R1);
	       free_last_tmp();free_last_tmp();
	       yyval.nb=ajout_tmp(); 
               ajout_instr(STORE,yyval.nb,R0,VIDE);}
break;
case 45:
#line 233 "yacc.y"
	{yystack.l_mark[0].nb=indice_tab();}
break;
case 46:
#line 235 "yacc.y"
	{
			 ajout_instr(LOAD,R0,yystack.l_mark[-1].nb,VIDE);
                         ajout_instr(AFC,R1,0,VIDE);
			 ajout_instr(EQU,R0,R0,R1);
			 yystack.l_mark[-2].nb=indice_tab();
			 ajout_instr(JMPC,0,R0,VIDE);
              }
break;
case 47:
#line 242 "yacc.y"
	{              
		      ajout_instr(JMP,yystack.l_mark[-6].nb,VIDE,VIDE);
		      instr[yystack.l_mark[-4].nb][1]=indice_tab();
		      printf("while\n"); 
		     
		}
break;
case 48:
#line 254 "yacc.y"
	{
  ajout_instr(STORE,ajout_tmp(),R22,VIDE);
  ajout_instr(STORE,ajout_tmp(),R21,VIDE);
  
  yystack.l_mark[0].nb=i_tab();
  
       }
break;
case 49:
#line 260 "yacc.y"
	{ /* save=ajout_tmp();*/
	           printf("ajout tmp retour %d\n",save);
	           printf("nb de parametres de la fct %d\n",yystack.l_mark[0].nb); 
	           ajout_instr(AFC,R0,i_tab(),VIDE);
	           ajout_instr(ADD,R22,R22,R0);
	           ajout_instr(AFC,R0,yystack.l_mark[0].nb,VIDE); /* +1 avec la save*/
		   ajout_instr(SOU,R22,R22,R0);
reset_symb();  ajout_instr(AFC,R21,indice_tab()+1,VIDE);
ajout_instr(JMP,adresse_fct(yystack.l_mark[-3].var)-1,VIDE,VIDE);
   }
break;
case 50:
#line 269 "yacc.y"
	{ 
	 
/* restauration ctxt   */
    
     /*  ajout_instr(LOAD,R6,0,VIDE); // BIZARRE*/
     ajout_instr(LOAD,R21,-1,VIDE);
     ajout_instr(LOAD,R22,-2,VIDE);
     restauration_symb(yystack.l_mark[-4].nb-2,255);
     yyval.nb=ajout_tmp();
     ajout_instr(STORE,yyval.nb,R23,VIDE);
  printf("STORING retour à %d\n",yyval.nb);
     
     printf("ici c'est valeur de table des symboles  de invoc : %d\n",yystack.l_mark[-4].nb-2);
     
	 
printf("invoc\n");}
break;
case 51:
#line 288 "yacc.y"
	{yyval.nb=yystack.l_mark[0].nb+1;printf(" PARAM = %d\n" , yystack.l_mark[-1].nb);
	 /*	 ajout_instr(LOAD,R0,$1,VIDE);*/
         
	 /*	 ajout_instr(STORE,ajout("",1,prof),R0,VIDE);*/
 }
break;
case 52:
#line 293 "yacc.y"
	{printf("param\n");}
break;
case 53:
#line 295 "yacc.y"
	{yyval.nb=yystack.l_mark[0].nb+1; /*ajout_instr(LOAD,R0,$2,VIDE);*/
	 /*ajout_instr(STORE,ajout("",1,prof),R0,VIDE);*/
       }
break;
case 54:
#line 299 "yacc.y"
	{printf("paramN\n");}
break;
case 55:
#line 301 "yacc.y"
	{if (adresse(yystack.l_mark[-2].var)==-1) printf("erreur_declaration\n"); 
   else{ ajout_instr(LOAD,R0,yystack.l_mark[0].nb,VIDE);
     ajout_instr(STORE,adresse(yystack.l_mark[-2].var),R0,VIDE);
     free_last_tmp();
   }
          }
break;
case 56:
#line 308 "yacc.y"
	{printf("aff\n");}
break;
case 57:
#line 310 "yacc.y"
	{ajout(yystack.l_mark[0].var,0,prof);}
break;
case 58:
#line 311 "yacc.y"
	{
            printf("Id : %s\n",yystack.l_mark[-2].var); 
	    ajout_instr(LOAD,R0,yystack.l_mark[0].nb,VIDE);
	    free_last_tmp();
	    ajout_instr(STORE,ajout(yystack.l_mark[-2].var,1,prof),R0,VIDE);
	    printf("affichage \n");
	    afficher(tab,i_tab());}
break;
case 59:
#line 320 "yacc.y"
	{printf("decl\n");}
break;
case 61:
#line 324 "yacc.y"
	{printf("Decln\n");}
break;
#line 967 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
