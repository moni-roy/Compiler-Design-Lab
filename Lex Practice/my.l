%{
#include "myscan.h"
%}
%%
: return COLON;
"db_type" return TYPE;
"db_name" return NAME;
"dp_table_prefix" return TABLE_PREFIX;
"dp_port" return PORT;

[a-zA-Z][_a-zA-Z0-9]* return IDENTIFIER;
[1-9][0-9]* return INTEGER;
[ \t\n] ;
. printf("unexpected character\n");

%%

int yywrap(void){
	return 1;
}

