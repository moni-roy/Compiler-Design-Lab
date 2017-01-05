%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int yylex();
int yyerror(const char *s);
%}

%left '+' '-'
%left '*' '/'
%union 	{
		char s[20];
	}
%token <s> NUM
%type <s> E T

%%
line 	: line E '\n' {printf("%s\n",$1);}
	| line '\n'
	|
	;

E:  E '+' E 	{	strcat($1,$3);
			strcat($1,"+");
			strcpy($$,$1);
		}
    |   E '-' E {	strcat($1,$3);
			strcat($1,"-");
			strcpy($$,$1);
		}
    |   T 	{	strcpy($$,$1);
		}
    ;
T:  NUM     	{	strcpy($$,$1);
		}
    ;
%%
int yylex(){
	char c;
	c = getchar();
	if(isdigit(c)){
		char ss[20];
		ss[0]=c;
		ss[1]='\0';
		yylval = ss;
		return NUM;
	}
	return c;
}

int main(void) {
    yyparse();
}

int yyerror (const char *s) {
    return printf ("error : %s\n", s);
}
