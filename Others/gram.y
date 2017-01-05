%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
extern int yylex();
int yyerror(const char *s);
%}

%token DIGIT

%%
line	: line expr '\n' {printf("%d\n",$2);}
		| line '\n'
		|
		;
expr 	: expr '+' term {$$ = $1 + $3; }
		| term
		;
term 	: term '*' factor { $$ = $1 * $3; }
		| factor
		;
factor 	: '(' expr ')' { $$ = $2; }
		| DIGIT
		;
%%

int yylex(){
	int c;
	c = getchar();
	if(isdigit(c))
	{
		yylval = c - '0';
		return DIGIT;
	}
	return c;
}
int yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}
