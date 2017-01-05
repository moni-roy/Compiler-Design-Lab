%{
	int countWord = 0;
%}
letter [a-zA-Z]
%%

{letter}+ {countWord++;}

%%
int main(){
	while(yylex()>0){};
	printf("No of words = %d\n",countWord);
	return 0;
}
  
