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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char *var;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
