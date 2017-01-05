%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int yylex();
int yyerror(const char *s);
%}

%token DIGIT

%%
line	: line expr '\n' {printf("%d\n",$2);}
		| line '\n'
		| 
		;
expr 	: expr '+' expr {$$ = $1 + $3; }
		| expr '-' expr {$$ = $1 - $3; }
		| expr '*' expr {$$ = $1 * $3; }
		| expr '/' expr {$$ = $1 / $3; }
		| '(' expr ')' {$$ = $2; }
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
int main(void) {
    yyparse();
}

int yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}
