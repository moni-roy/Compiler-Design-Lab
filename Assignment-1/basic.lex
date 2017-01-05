%{
#include "define.h"
#include <bits/stdc++.h>
using namespace std;
vector<string> Ans[10];
%}

%option noyywrap

DIGIT  		[0-9]
LETTER 		[a-zA-Z]

NEWLINE 	\n
SPACE 		[ \t]

WS 			[SPACE|NEWLINE]+


PLUS		[+]
MINUS		[-]
ASSIGN		[=]
GT			[>]
LT			[<]


EXP 		[eE]
DOT 		.

AUTO		auto
BREAK		break
CASE		case
CHAR		char
CONST		const
CONTINUE	continue
DEFAULT		default
DO			do
DOUBLE		double
ELSE		else
ENUM		enum
EXTERN		extern
FLOAT		float
FOR			for
GOTO		goto
IF			if
INT			int
LONG		long
REGISTER	register
RETURN		return
SHORT		short
SIGNED		signed
SIZEOF		sizeof
STATIC		static
STRUCT		struct
SWITCH		switch
TYPEDEF		typedef
UNION		union
UNSIGNED	unsigned
VOID		void
VOLATILe	volatile
WHILE		while

%%


"/*"    			{	int c;    
						while((c = yyinput()) != 0)
                    	{
                    		if(c == '*')
                    	    {
                    	    	if((c = yyinput()) == '/')
                    	        	break;
                    	     }
                    	}
                	}


"//"				{   int c;
						while((c = yyinput()) != 0)
                    	{
                    		if(c == '\n')
                    	    {
                    	        break;
                    	    }
                    	}
					}

{AUTO}				{Ans[KEY].push_back(YYText());}
{BREAK}				{Ans[KEY].push_back(YYText());}
{CASE}				{Ans[KEY].push_back(YYText());}
{CHAR}				{Ans[KEY].push_back(YYText());}
{CONST}				{Ans[KEY].push_back(YYText());}
{CONTINUE}			{Ans[KEY].push_back(YYText());}
{DEFAULT}			{Ans[KEY].push_back(YYText());}
{DO}				{Ans[KEY].push_back(YYText());}
{DOUBLE}			{Ans[KEY].push_back(YYText());}
{ELSE}				{Ans[KEY].push_back(YYText());}
{ENUM}				{Ans[KEY].push_back(YYText());}
{EXTERN}			{Ans[KEY].push_back(YYText());}
{FLOAT}				{Ans[KEY].push_back(YYText());}
{FOR}				{Ans[KEY].push_back(YYText());}
{GOTO}				{Ans[KEY].push_back(YYText());}
{IF}				{Ans[KEY].push_back(YYText());}
{INT}				{Ans[KEY].push_back(YYText());}
{LONG}				{Ans[KEY].push_back(YYText());}
{REGISTER}			{Ans[KEY].push_back(YYText());}
{RETURN}			{Ans[KEY].push_back(YYText());}
{SHORT}				{Ans[KEY].push_back(YYText());}
{SIGNED}			{Ans[KEY].push_back(YYText());}
{SIZEOF}			{Ans[KEY].push_back(YYText());}
{STATIC}			{Ans[KEY].push_back(YYText());}
{STRUCT}			{Ans[KEY].push_back(YYText());}
{SWITCH}			{Ans[KEY].push_back(YYText());}
{TYPEDEF}			{Ans[KEY].push_back(YYText());}
{UNION}				{Ans[KEY].push_back(YYText());}
{UNSIGNED}			{Ans[KEY].push_back(YYText());}
{VOID}				{Ans[KEY].push_back(YYText());}
{VOLATILe}			{Ans[KEY].push_back(YYText());}
{WHILE}				{Ans[KEY].push_back(YYText());}

{LETTER}({LETTER}|{DIGIT})* {Ans[ID].push_back(YYText());}

{PLUS} 				{Ans[MATH].push_back(YYText());}
{MINUS} 			{Ans[MATH].push_back(YYText());}
{PLUS}{PLUS}		{Ans[MATH].push_back(YYText());}
{MINUS}{MINUS}		{Ans[MATH].push_back(YYText());}
{ASSIGN}			{Ans[MATH].push_back(YYText());}
{ASSIGN}{ASSIGN}	{Ans[LOGIC].push_back(YYText());}
{LT} 				{Ans[LOGIC].push_back(YYText());}
{GT} 				{Ans[LOGIC].push_back(YYText());}
{GT}{ASSIGN} 		{Ans[LOGIC].push_back(YYText());}
{LT}{ASSIGN} 		{Ans[LOGIC].push_back(YYText());}

{DIGIT}+({DOT}{DIGIT}+)?(EXP(PLUS|MINUS)?{DIGIT}+)? {Ans[NUMBER].push_back(YYText());}

{SPACE}+ {;}
{NEWLINE}+ {;}
. {Ans[OTHER].push_back(YYText());}

%%

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	yyFlexLexer lexer;
	while(lexer.yylex()){}

	string names[]={"NULL","Keywords","Identifiers","Math Operators","Logical Operators","Numerical Values","Others"};
	map<string,int>mp;
	for(int i=1;i<=6;i++){
		cout<<names[i]<<" : ";
		int sz = (int)Ans[i].size();
		for(int j=0;j<sz;j++){
			if(i==5){
				if(j!=sz-1) cout<<Ans[i][j]<<", ";
				else cout<<Ans[i][j];
			}
			else if(i==6){
				if(mp[Ans[i][j]]==0){
					cout<<Ans[i][j];
				}
				mp[Ans[i][j]]=1;
			}
			else{
				if(mp[Ans[i][j]]==0){
					if(j==0) cout<<Ans[i][j];
					else cout<<", "<<Ans[i][j];
				}
				mp[Ans[i][j]]=1;
			}
		}	
		cout<<endl;
	}
	return 0;
}
