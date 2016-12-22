alpha [a-zA-Z]
digit [0-9]

%%
[ \t]				;
[ \n]   			{ yylineno = yylineno + 1;}
true				return TRUE;
false				return FALSE;
int				return INT;
float 				return FLOAT;
char 				return CHAR;
void 				return VOID;
double 				return DOUBLE;
for 				return FOR;
while				return WHILE;
if				return IF;
else				return ELSE;
printf  			return PRINTF;
^"#include ".+ 			;
{digit}+       			return NUM;
{alpha}({alpha}|{digit})* 	return ID;
"&&"				return AND;
"||"				return OR;
"<="    			return LE;
">="    			return GE;
"=="    			return EQ;
"!="    			return NE;
"!"	    			return NOT;
">"				return GT;
"<"				return LT;
"."     			return DOT;
\/\/.* 				;
\/\*(.*\n)*.*\*\/ 		;
.       			return yytext[0];
%%

