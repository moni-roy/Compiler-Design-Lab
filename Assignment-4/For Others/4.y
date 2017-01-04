%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
extern FILE *fp;
int yyerror(char *s);
int yylex();

%}

%token INT FLOAT CHAR DOUBLE VOID
%token FOR WHILE 
%token IF ELSE PRINTF
%token NUM ID
%token DOT

%right '='
%left AND OR
%left '<' '>' LE GE EQ NE LT GT
%%

line:	func
	| declare
	;

declare: Type assign ';' 
	| assign ';' 
	;
func: Type ID '(' ')' bracket 
	;


Type:  INT 
	| FLOAT
	| DOUBLE
	;

assign:	 ID '=' assign
	| ID ',' assign
	| ID '+' assign
	| ID '-' assign
	| NUM '+' assign
	| NUM '-' assign
	| NUM
	| ID
	;
			
bracket: '{' StmtList '}'
	;

StmtList: StmtList Stmt
	| 
	;

Stmt: 	  WhileStmt
	| declare
	| ForStmt
	| IfStmt
	| ';'
	;


WhileStmt: WHILE '(' Expr ')' bracket 
	;

ForStmt:  FOR '(' Expr ';' Expr ';' Expr ')' bracket 
	;

IfStmt : IF '(' Expr ')' bracket 
	| IF '(' Expr ')' bracket ElseStmt
	;

ElseStmt: ELSE Stmt
	| ELSE bracket
	;

Expr: 		  	 
	| Expr LE Expr 
	| Expr GE Expr
	| Expr NE Expr
	| Expr EQ Expr
	| Expr GT Expr
	| Expr LT Expr
	| 
	;
%%
#include"lex.yy.c"
#include<ctype.h>


int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	
	if(yyparse()==0)
		printf("\nCompilation complete\n");
	else
		printf("\nCompilation error\n");
	
	fclose(yyin);
	return 0;
}
         
int yyerror(char *s) {
	printf("%d : %s %s\n", yylineno, s, yytext );
}
