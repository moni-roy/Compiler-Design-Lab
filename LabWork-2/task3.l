%{
int id = 0;
int key = 0;
int other = 0;
%}

DIGIT [0-9]
LETTER [a-zA-Z]

NEWLINE \n
SPACE [ \t]
NULLC \0

IF if
ELSE else
FOR for
WHILE while
DO do
EndFile EOF

PRINTF printf
SCANF sacnf
GETS gets
PUTS puts

LONG long
CHAR char
STRING string
INT int
FLOAT float
DOUBLE double

RETURN return


%%

{IF}|{ELSE}|{INT}|{FLOAT}|{FOR}|{PRINTF}|{SCANF}|{WHILE}|{GETS}|{PUTS}|{EndFile}|{LONG}|{DOUBLE}|{RETURN}|{STRING} { key++;}
{LETTER}({LETTER}|{DIGIT})* {id++;}
. {other++;}

%%

int main()
{
	while(yylex()>0){};
	printf("Number of Id = %d\n",id);
	printf("Number of KeyWords = %d\n",key);
}
	
