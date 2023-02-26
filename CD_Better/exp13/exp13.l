/*
%{
#include<stdio.h>
extern int num=0;
%}


%%
([0-9]+) {num=atoi(yytext);
	  return NUMBER;}

%%

*/


%{
/* Definition section */
#include<stdio.h>
#include "y.tab.c"
extern int yylval;
%}

/* Rule Section */
%%
[0-9]+ {
		yylval=atoi(yytext);
		return NUMBER;

	}
[\t] ;

[\n] return 0;

. return yytext[0];

%%

int yywrap()
{
return 1;
}

