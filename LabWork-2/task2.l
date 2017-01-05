%{
	int countChar = 0;
	int countLine = 0;
%}
letter [a-zA-Z0-9]
%%
. {countChar++;}
\n {countLine++;}
%%
int main(){
	while(yylex()>0){};
	printf("No of Chars = %d\n",countChar);
	printf("No of Lines = %d\n",countLine);
	return 0;
}
  
