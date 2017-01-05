%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int yylex();
int yyerror(const char *s);
%}

%token NUM ID

%%
line 	: line E '\n' {printf("\n");}
	| line '\n'
	|
	;
E:  	E '+' T 	{	printf("+");}
    	|  E '-' T 	{	printf("-");}
    	| T
    	;
	
T: 	T '*' F		{	printf("*");}
	| T '/' F	{	printf("/");}
	| F
	;
F:	NUM     	{	printf("%d", yylval);}
    	|  ID		{ 	printf("%c", yylval);}
    	;
%%

int yylex(){
	int c;
	c = getchar();
	if(isdigit(c))
	{
		yylval = c - '0';
		return NUM;
	}
	if(isalpha(c)){
		yylval = c;
		return ID;
	}
	return c;
}

int yyerror (char const *s)
{
	fprintf (stderr, "%s\n", s);
}

int main(void) {
	yyparse();
	return 1;
}
