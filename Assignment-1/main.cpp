#include <bits/stdc++.h>
#include <FlexLexer.h> 
using namespace std;

#include "define.h"

extern int yylex();
extern int yylineno;
extern char* YYText;

vector<string> Ans[10];

string names[]={NULL,"KeyWords","Identifiers","Math operators","Logical operators","Numerical Values","Others"};

int main()
{
	yyFlexLexer lexer;
	int tocken;
	tocken = lexer.yylex();
	while(tocken){
		Ans[tocken].push_back(YYText);
		tocken = lexer.yylex();
	}
	for(int i=1;i<=6;i++){
		cout<<names[i]<<" : ";
		for(int j=0;j<(int)Ans[i].size();i++){
			cout<<Ans[i][j]<<" ";
		}	
		cout<<endl;
	}
	return 0;
}
