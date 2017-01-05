%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[26];
%}

%token NUM LETTER IF THEN GE EE LE ID WHILE LT GT
%left '+'
%left '-'
%left GE NE EE LE LT GT
%left '*'
%left '/'
%right UMINUS

%%
list:	
	|list	stmt '\n'	
	|list error	'\n'	{yyerror("Re-enter"); yyerrok;}
	;

stmt:expr			{printf("%d\n",$$);}
	|ifstmt	{puts("if-else");}
	|whlstmt		{puts("While");}
	|expr ';'		{printf("%d\n",$$);}
	|LETTER '=' expr 	{arr[$1]=$3;}
	;

ifstmt:IF '(' expr ')' THEN  stmt
	 ;


whlstmt:WHILE'('expr')'  stmt 
	  ;

expr:	 expr '+' expr	{$$=$1+$3;}
	|expr '-' expr	{$$=$1-$3;}
	|expr '*' expr	{$$=$1*$3;}
	|expr '/' expr	{$$=$1/$3;}
	|'(' expr ')'	{$$=$2;}
	|'-' expr %prec UMINUS {$$=-$2;}
	|LETTER	{$$=arr[$1];}
	|expr GT expr
	|expr LT expr
	|expr LE expr
	|expr EE expr
	|expr GE expr
	|NUM
	|ID
	;

%%

#include "lex.yy.c"

void yyerror(const char *str){
	fprintf(stderr,"error: %s\n",str);
}

int main(){
	yyparse();
}
