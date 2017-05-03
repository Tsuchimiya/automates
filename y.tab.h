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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char *var;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
