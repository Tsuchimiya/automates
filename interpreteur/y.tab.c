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

#line 2 "interp.y"
  #include "y.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include "instr.h"
  #define TAILLE 256
  int regs[39];
  int memory[TAILLE];
  void yyerror (char const *s);
  
#line 11 "interp.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char *var;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 38 "y.tab.c"

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

#define tadd 257
#define tmul 258
#define tsou 259
#define tdiv 260
#define tcop 261
#define tafc 262
#define tload 263
#define tstore 264
#define tjmp 265
#define tinf 266
#define tinfe 267
#define tsup 268
#define tsupe 269
#define tjmpc 270
#define tjmpr 271
#define tequ 272
#define terror 273
#define treg 274
#define tnb 275
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,
};
static const short yylen[] = {                            2,
    1,    2,    0,    7,    7,    7,    7,    5,    4,    4,
    4,    7,    7,    7,    7,    7,    2,    4,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   17,    0,    0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   19,
    0,    0,    0,    0,    0,    0,   11,    9,   10,    0,
    0,    0,    0,   18,    0,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    4,    5,    7,    6,   13,   14,
   15,   16,   12,
};
static const short yydgoto[] = {                         17,
   18,   19,
};
static const short yysindex[] = {                      -257,
 -258, -256, -255, -254, -253, -252, -251, -250, -249, -247,
 -246, -245, -244, -243, -241, -240,    0,    0, -257, -239,
 -238, -237, -236, -235, -234, -233, -231,    0, -230, -229,
 -228, -227, -225, -224, -223,    0, -221, -220, -219, -218,
 -217, -216, -215, -214, -212, -211, -210, -209, -208,    0,
 -206, -205, -204, -203, -202, -201,    0,    0,    0, -200,
 -199, -198, -197,    0, -196, -194, -193, -192, -191,    0,
 -190, -189, -188, -187, -186, -185, -184, -183, -182, -181,
 -180, -179, -178, -177,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const short yyrindex[] = {                        17,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   17,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
    5,    0,
};
#define YYTABLESIZE 98
static const short yytable[] = {                          1,
    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   20,    3,   21,   22,   23,
   24,   25,   26,   36,   27,   28,   29,   30,   31,   32,
    0,   33,   34,   35,    0,   37,   38,   39,   40,   41,
   42,   43,   44,    0,   45,   46,   47,   48,   49,    0,
   50,   51,   52,   53,   54,   55,   56,    0,   57,   58,
   59,   60,   61,   62,   63,    0,   64,   65,    0,   66,
   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
   77,   78,   79,   80,   81,   82,   83,   84,    0,   85,
   86,   87,   88,   89,   90,   91,   92,   93,
};
static const short yycheck[] = {                        257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  274,    0,  274,  274,  274,
  274,  274,  274,   19,  275,  275,  274,  274,  274,  274,
   -1,  275,  274,  274,   -1,  275,  275,  275,  275,  275,
  275,  275,  274,   -1,  275,  275,  275,  275,  274,   -1,
  275,  275,  274,  274,  274,  274,  274,   -1,  275,  275,
  275,  274,  274,  274,  274,   -1,  275,  274,   -1,  275,
  275,  275,  275,  275,  275,  275,  275,  275,  275,  274,
  274,  274,  274,  274,  274,  274,  274,  274,   -1,  275,
  275,  275,  275,  275,  275,  275,  275,  275,
};
#define YYFINAL 17
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 275
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tadd","tmul","tsou","tdiv",
"tcop","tafc","tload","tstore","tjmp","tinf","tinfe","tsup","tsupe","tjmpc",
"tjmpr","tequ","terror","treg","tnb","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : Asm",
"Asm : Instructions",
"Instructions : Instruction Instructions",
"Instructions :",
"Instruction : tadd treg tnb treg tnb treg tnb",
"Instruction : tmul treg tnb treg tnb treg tnb",
"Instruction : tdiv treg tnb treg tnb treg tnb",
"Instruction : tsou treg tnb treg tnb treg tnb",
"Instruction : tcop treg tnb treg tnb",
"Instruction : tload treg tnb tnb",
"Instruction : tstore tnb treg tnb",
"Instruction : tafc treg tnb tnb",
"Instruction : tequ treg tnb treg tnb treg tnb",
"Instruction : tinf treg tnb treg tnb treg tnb",
"Instruction : tinfe treg tnb treg tnb treg tnb",
"Instruction : tsup treg tnb treg tnb treg tnb",
"Instruction : tsupe treg tnb treg tnb treg tnb",
"Instruction : tjmp tnb",
"Instruction : tjmpc tnb treg tnb",
"Instruction : tjmpr treg tnb",

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
#line 102 "interp.y"
 void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

main ()
{
  return yyparse() ;
}
#line 251 "y.tab.c"

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
case 3:
#line 24 "interp.y"
	{int i=0; for (i=0;i<indice_tab();i++){
     switch (instr[i][0]){
       case ADD: regs[instr[i][1]]=regs[instr[i][2]]+regs[instr[i][3]];break;

       case MUL:regs[instr[i][1]]=regs[instr[i][2]]*regs[instr[i][3]];break;

       case DIV:regs[instr[i][1]]=regs[instr[i][2]]/regs[instr[i][3]];break;

       case SOU:regs[instr[i][1]]=regs[instr[i][2]]-regs[instr[i][3]];break;

       case COP:regs[instr[i][1]]=regs[instr[i][2]];break;

     case LOAD: 
	 
         printf("LOAD: adresse : R%d  %d R22=%d\n",instr[i][1],memory[instr[i][2]+regs[22]],regs[22]);
	 regs[instr[i][1]]=memory[instr[i][2]+regs[22]];
	 break;
		/* A CHANGER, temporaire*/
     case STORE:
		  printf("STORE: adresse : %d valeur : %d R22=%d\n",instr[i][1]+regs[22],regs[instr[i][2]],regs[22]);
		  memory[instr[i][1]+regs[22]]= regs[instr[i][2]]; 
        
      
	     break;

       case AFC:  regs[instr[i][1]]= instr[i][2];break;
	
       case EQU:  regs[instr[i][1]]=regs[instr[i][2]]==regs[instr[i][3]];break;

       case INF:  regs[instr[i][1]]=regs[instr[i][2]]<regs[instr[i][3]];break;

       case INFE:  regs[instr[i][1]]=regs[instr[i][2]]<=regs[instr[i][3]];break;

     case SUP:  regs[instr[i][1]]=(regs[instr[i][2]]>regs[instr[i][3]]);break;

       case SUPE:  regs[instr[i][1]]=regs[instr[i][2]]>=regs[instr[i][3]];break;

     case JMP: i=instr[i][1];break;

     case JMPC: if (regs[instr[i][2]]!=0 )
		   i=instr[i][1];break;

     case JMPR: i=regs[instr[i][1]];break;
     }

	      }


for (i=0;i<20;i++){
   
     printf("mem %d : %d\n",i,memory[i]);
     /* printf("tmp %d : %d\n",i,tmp[i]);
	printf("reg %d: %d\n",i,regs[i]);*/
   }
 printf("R23 : %d\n",regs[23]);
 }
break;
case 4:
#line 81 "interp.y"
	{ajout_instr(ADD,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 5:
#line 82 "interp.y"
	{ ajout_instr(MUL,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 6:
#line 83 "interp.y"
	{ ajout_instr(DIV,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 7:
#line 84 "interp.y"
	{ ajout_instr(SOU,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 8:
#line 85 "interp.y"
	{ajout_instr(COP,yystack.l_mark[-2].nb,yystack.l_mark[0].nb, VIDE);}
break;
case 9:
#line 87 "interp.y"
	{ajout_instr(LOAD,yystack.l_mark[-1].nb,yystack.l_mark[0].nb,VIDE);}
break;
case 10:
#line 88 "interp.y"
	{ajout_instr(STORE,yystack.l_mark[-2].nb,yystack.l_mark[0].nb,VIDE);}
break;
case 11:
#line 89 "interp.y"
	{ajout_instr(AFC,yystack.l_mark[-1].nb,yystack.l_mark[0].nb, VIDE);}
break;
case 12:
#line 90 "interp.y"
	{ajout_instr(EQU,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 13:
#line 91 "interp.y"
	{ajout_instr(INF,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 14:
#line 92 "interp.y"
	{ajout_instr(INFE,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 15:
#line 93 "interp.y"
	{ajout_instr(SUP,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 16:
#line 94 "interp.y"
	{ajout_instr(SUPE,yystack.l_mark[-4].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);}
break;
case 17:
#line 95 "interp.y"
	{ajout_instr(JMP,yystack.l_mark[0].nb,VIDE,VIDE);}
break;
case 18:
#line 96 "interp.y"
	{ajout_instr(JMPC,yystack.l_mark[-2].nb,yystack.l_mark[0].nb,VIDE);}
break;
case 19:
#line 97 "interp.y"
	{ajout_instr(JMPR,yystack.l_mark[0].nb,VIDE,VIDE);}
break;
#line 576 "y.tab.c"
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
