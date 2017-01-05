%{
    #include <stdio.h>
    void yyerror(char *);
    int yylex(void);

    int sym[26];
%}

%token INTEGER VARIABLE
%left '|'
%left '&'

%%

pro:
        pro st '\n' | ;

st:
        ex      { printf("%d\n", $1); }  | VARIABLE '=' ex    { sym[$1] = $3; } ;

ex:
        INTEGER  | VARIABLE { $$ = sym[$1]; } | ex '|' ex { $$ = $1 | $3; } | ex '&' ex     { $$ = $1 &$3; } ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
}


/*
Commands are given below:
flex hw_1.l
bison hw_1.y
gcc lex.yy.c y.tab.c -ly -lfl
*/
