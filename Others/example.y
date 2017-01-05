%{
#include <stdio.h>
#include <string.h>
extern int yylex();
int ar[26];
%}

%token DIGIT LETTER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

list	: 
	| list stmnt '\n'
	| list error '\n' { yyerror("something wrong");
			    yyerrok;
			  }
	;
stmnt 	: expr { printf("%d\n",$1);}
	| LETTER '=' expr { ar[$1]=$3;}
	| 
	;

expr	: '(' expr ')' { $$=$1;}
	| expr '+' expr { $$ = $1 + $3;}
	| expr '-' expr { $$ = $1 - $3;}
	| '-' expr { $$ = -$2;}
	| LETTER {$$=ar[$2];}
	| number
	;
number	: DIGIT { $$ = $1;}
	| number DIGIT {$$ = $1*10+$2;}
	;

%%
#include"lex.yy.c"
#include<ctype.h>

int main()
{
	yyparse();
	return 0;
}
int yywrap(){
	return 1;
}


