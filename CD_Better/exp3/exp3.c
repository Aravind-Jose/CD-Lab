#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

char buffer[100];
int ind=0;
int E();
int Edash();
int T();
int Tdash();
int F();

int Error()
{
printf("Not Accepted\n\n");
exit(0);
}

int Tdash()
{
if(buffer[ind]!='*')
return 0;
else
ind++;
F();
Tdash();

}

int T()
{
F();
Tdash();
}

int Edash()
{
if(buffer[ind]!='+')
return 0;
else
ind++;
T();
Edash();

}

int E()
{
T();
Edash();
}

int F()
{
if(buffer[ind]=='(')
{
ind++;
E();
if(buffer[ind]!=')')
Error();
else
ind++;
}
else if(buffer[ind]>='a'&&buffer[ind]<='z')
{
ind++;
}
else
Error();
}

int main()
{
printf("RECURSIVE DESCENT PARSER\n\n");
printf("Enter your input: ");
scanf("%s",buffer);
E();
printf("Input is Accepted!\n\n");
}
