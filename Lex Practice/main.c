#include <stdio.h>
#include "myscan.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL,"dp_type","dp_name","dp_table_prfix","dp_port"};

int main()
{
	int ntoken,vtoken;
	
	ntoken = yylex();
	while(ntoken){
		printf("%d\n",ntoken);
		if(yylex() != COLON){
			printf("Syntex error int line %d,Expected a ':' but found %s\n",yylineno,yytext);
			return 1;
		}
		vtoken = yylex();
		switch(ntoken){
			case TYPE:
			case NAME:
			case TABLE_PREFIX:
				if(vtoken != IDENTIFIER){
					printf("Syntex error int line %d,Expected an identifier but found %s\n",yylineno,yytext);
					return 1;
				}
				printf("%s is set to %s\n",names[ntoken],yytext);
				break;
			case PORT:
				if(vtoken != INTEGER) {
					printf("Syntex error int line %d,Expected an integer but found %s\n",yylineno,yytext);
					return 1;
				}
				printf("%s is set to %s\n",names[ntoken],yytext);
				break;
			default:
				printf("Syntex error in line %d\n",yylineno);
		}
		ntoken = yylex();
	}
	return 0;
}
