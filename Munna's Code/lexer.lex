%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}

%option noyywrap

IF	if
THEN	then
WHILE	while
DO	do
LETTER	[a-z]
DIGIT	[0-9]
EE	==
GE	>=
LE	<=
LT	<
GT	>
NUM	{DIGIT}+
ID	{LETTER}+
AOP	"+"|"-"|"*"|"/"|"="|"\n"
WS	[ \t]+
P1	[(]
P2	[)]
%%

{IF}		{return (IF);}
{THEN}		{return (THEN);}
{WHILE}		{return (WHILE);}
{EE}		{return (EE);}
{LE}		{return (LE);}
{GE}		{return (GE);}
{LT}		{return (LT);}
{GT}		{return (GT);}
{LETTER}	{yylval=yytext[0]-'a'; return (LETTER);}
{ID}		{return (ID);}
{NUM}		{yylval=atoi(yytext); return (NUM);}
{AOP}		{return yytext[0];}
{P1}		{return yytext[0];}
{P2}		{return yytext[0];}
{WS}		{}
%%


