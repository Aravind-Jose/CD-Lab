
%{
#include<stdio.h>
int word=0;
int line=0;
int charc=0;
%}

%%

" " {word++;}
"\n" {line++;word++;}
. {charc++;}

%%
int main()
{
yyin=fopen("input.txt","r");
yylex();
printf("Word Count: %d\nLine Count: %d\nCharacter count: %d\n",word,line,charc);
}

