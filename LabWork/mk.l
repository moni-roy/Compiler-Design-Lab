%{
#include<stdio.h>
#include "y.tab.h"
%}
%%
[+*-/]   { return yytext[0];}
[0-9]    { return yytext[0];}
[\n]     { return 0;}
"("|")"  { return yytext[0];}
.        {;}
%%
