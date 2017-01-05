%{
#include<bits/stdc++.h>
using namespace std;
%}

DIGIT	[0-9]
ALPHA	[a-zA-Z]
ID	{ALPHA}({ALPHA}|{DIGIT})*
INT	int
IF	if
ELSE	else


%%
{DIGIT} { printf("digit"); }
{ID} { printf("id"); }
{INT} { printf("INT"); }
{IF} { printf("IF"); }
{ELSE} { printf("ELSE"); }

%%

int main()
{
	yyFlexLexer lexer;
	lexer.yylex();
}
