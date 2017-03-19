%{  //définitions
  #include <stdio.h>
#include <stdlib.h>
  #include "y.tab.h"

%}

%% 

[ \t]+     ;
"<=" {printf("tinf\n");return tinfeq;}
">=" {printf("tinf\n");return tsupeq;}
"<" {printf("tinf\n");return tinf;}
">" {printf("tinf\n");return tsup;}

"*"        { printf("tmul\n");return tmul; }
"/"        { printf("div\n");return tdiv; }
"-"        {printf("tminus\n"); return tmin; }
"+"        {printf("tplus\n"); return tplus; }
"main"     {printf("MAIN\n"); return tmain; }
"if"       {printf("tif\n"); return tif; }
\n         ;
 "else"    {printf("telse\n"); return telse; }
 "while"   {printf("twhile\n"); return twhile; }
 "{"       {printf("tao\n"); return tao; }
 "}"       {printf("taf\n"); return taf; }
 "("       {printf("tpo\n"); return tpo; }
 ")"       {printf("tpf\n"); return tpf; }
 ","       {printf("tv\n"); return tv; }
 ";"       {printf("tpv\n"); return tpv; }
 "="       {printf("teq\n"); return teq; }
 "=="      {printf("teqeq\n"); return teqeq; }
 "return"  {printf("treturn\n"); return tret; }
 "int"     {printf("tint\n"); return tint; }
"printf"   {printf("tprintf\n"); return tprintf;}
 "&&"      {printf("tet\n"); return tet; }
 "||"      {printf("tou\n"); return tou; }
 "#include" {printf("tinclude\n"); return tinclude; }
 "#define" {printf("tdefine\n"); return tdefine; }
 "const"   {printf("tconst\n"); return tconst; }
[0-9]+([.][0-9]+)?(e[0-9]+)?   {printf("tnb\n");  yylval.nb=atoi(yytext); return tnb;}
[a-zA-Z]+  {printf("tid\n");
           yylval.var=malloc(sizeof(yytext));
           strcpy(yylval.var,yytext); return tid;}
.         {printf("terror\n"); return terror;}
%%
