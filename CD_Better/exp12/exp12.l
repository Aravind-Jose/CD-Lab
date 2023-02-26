
%{
#include<stdio.h>
int line=1;
%}
chars [a-zA-Z]
digits [0-9]
idf [a-zA-Z][a-zA-Z0-9_]*
inv [0-9]+[a-zA-Z]+
newline \n
keyword int|void|char|if|else
literal [0-9]
arithop [\+\*\-\/]
relop <=|==|>=|!=|<|>
strlit \"(.)*\"


%%
{keyword} {printf("%s\t%d\tKeyword\n",yytext,line);}
"main" {printf("%s\t%d\tFunction\n",yytext,line);}
{inv} {printf("Invalid\t%d\tInvalid\n",line);}
{idf} {printf("%s\t%d\tIdentifier\n",yytext,line);}
{arithop} {
	if(strcmp(yytext,"+")==0)
	printf("%s\t%d\tArithmetic Operator ADD\n",yytext,line);
	if(strcmp(yytext,"-")==0)
	printf("%s\t%d\tArithmetic Operator SUB\n",yytext,line);
	if(strcmp(yytext,"*")==0)
	printf("%s\t%d\tArithmetic Operator MUL\n",yytext,line);
	if(strcmp(yytext,"/")==0)
	printf("%s\t%d\tArithmetic Operator DIV\n",yytext,line);
	}
= {printf("%s\t%d\tAssignment Operator EQ\n",yytext,line);}
{relop} {
	if(strcmp(yytext,"<=")==0)
	printf("%s\t%d\tRelational Operator LE\n",yytext,line);
	if(strcmp(yytext,">=")==0)
	printf("%s\t%d\tRelational Operator GE\n",yytext,line);
	if(strcmp(yytext,"==")==0)
	printf("%s\t%d\tRelational Operator EQ\n",yytext,line);
	if(strcmp(yytext,"!=")==0)
	printf("%s\t%d\tRelational Operator NE\n",yytext,line);
	if(strcmp(yytext,"<")==0)
	printf("%s\t%d\tRelational Operator LT\n",yytext,line);
	if(strcmp(yytext,">")==0)
	printf("%s\t%d\tRelational Operator GT\n",yytext,line);
	}
{literal} {	printf("%s\t%d\tLiteral\n",yytext,line);}
{strlit} {	printf("%s\t%d\tString Literal\n",yytext,line);}
"\n" {line++;}
. {}
%%
int main()
{
yyin=fopen("input.txt","r");
printf("Lexeme\tLine\tToken\n");
yylex();
}

