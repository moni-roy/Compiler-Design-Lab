%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
extern FILE *fp;
int yyerror(char *s);
int yylex();
%}

%token INT FLOAT CHAR DOUBLE VOID FOR WHILE IF ELSE PRINTF STRUCT NUM ID INCLUDE DOT TRUE FALSE

%right '='
%left AND OR NOT
%left '<' '>' LE GE EQ NE LT GT

%%

start:			  Function 
			| Declaration
			;

Declaration:		  Type Assignment ';' 
			| Assignment ';' 
			;

Assignment:	 	  ID '=' Assignment
			| ID ',' Assignment
			| ID '+' Assignment
			| ID '-' Assignment
			| ID '*' Assignment
			| ID '/' Assignment	
			| NUM '+' Assignment
			| NUM '-' Assignment
			| NUM '*' Assignment
			| NUM '/' Assignment
			| '\'' Assignment '\''	
			| '(' Assignment ')'
			| '-' '(' Assignment ')'
			| '-' NUM
			| '-' ID
			| NUM
			| ID
			;
			
Function:		  Type ID '(' ArgListOpt ')' CompoundStmt 
			;

ArgListOpt:		  ArgList
			|
			;

ArgList:		  ArgList ',' Arg
			| Arg
			;

Arg:			  Type ID
			;

CompoundStmt: 		  '{' StmtList '}'
			;

StmtList:	  	  StmtList Stmt
			| 
			;

Stmt:		  	  WhileStmt
			| Declaration
			| ForStmt
			| IfStmt
			| ';'
			;

Type:		  	  INT 
			| FLOAT
			| CHAR
			| DOUBLE
			| VOID 
			;

WhileStmt: 	  	  WHILE '(' Expr ')' Stmt  
			| WHILE '(' Expr ')' CompoundStmt 
			;

ForStmt: 	  	  FOR '(' Expr ';' Expr ';' Expr ')' Stmt 
			| FOR '(' Expr ';' Expr ';' Expr ')' CompoundStmt 
			| FOR '(' Expr ')' Stmt 
			| FOR '(' Expr ')' CompoundStmt 
			;

IfStmt : 	  	  IF '(' Expr ')' Stmt 
			| IF '(' Expr ')' Stmt ElseStmt
			| IF '(' Expr ')' CompoundStmt 
			| IF '(' Expr ')' CompoundStmt ElseStmt
			;

ElseStmt: 	  	  ELSE Stmt
			| ELSE CompoundStmt
			;

Expr: 		  	 
			| Expr LE Expr 
			| Expr GE Expr
			| Expr NE Expr
			| Expr EQ Expr
			| Expr GT Expr
			| Expr LT Expr
			| Expr OR Expr
			| Expr AND Expr
			| NOT Expr
			| '(' Expr ')'
			| Assignment
			;

%%

#include"lex.yy.c"
#include<ctype.h>


int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	
	if(!yyparse()){
		printf("Compiled Successfully\n\n");
	}
	else{
		printf("Compilation Error\n\n");
	}
	fclose(yyin);

	return 0;
}
         
int yyerror(char *s) {
	printf("%d : %s %s\n", yylineno, s, yytext );
}         

