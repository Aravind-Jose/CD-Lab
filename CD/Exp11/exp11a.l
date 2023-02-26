%{
#include <stdio.h>
int no=0;
int lno=0;
int cno=0;
%}
%%
" " {no++; }
"\n" {lno++;no++;}
. {cno++; }

%%
int main()
{
	yyin=fopen("input.txt","r");
	yylex();
	printf("Word count : %i\n",no);
	printf("Line count : %i\n",lno);
	printf("Character count : %i\n",cno);
}
