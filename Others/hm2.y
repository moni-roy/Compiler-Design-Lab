%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
extern int yylex();
int yyerror(const char *s);
%}

%token DIGIT
%left '+' '-'
%left '|'
%left '&'

%%
line 	: line E '\n' {}
	| line '\n'
	|
	;
E 	: E '|' E {if($1==1 || $3==1) printf("YES\n"); else printf("NO\n");}
	| E '&' E {if($1==1 && $3==1) printf("YES\n"); else printf("NO\n");}
	| DIGIT
	;
%%

int yylex(){
	char c;
	c = getchar();
	if(c=='0' || c=='1'){
		yylval = c-'0';
		return DIGIT;
	}
	return c;
}
int yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void) {
printf("1 as true and 0 as false\n");
    yyparse();
}

