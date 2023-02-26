#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
int i=0;

void F(char exp[]);
void TT(char exp[]);
void T(char exp[]);
void EE(char exp[]);
void E(char exp[]);


void F(char exp[])
{
	if(exp[i]=='(')
	{
		i++;
		E(exp);
		if(exp[i]==')')
		{
			i++;
		}
		else
		{
			printf("Not Accepted\n");
			exit(0);
		}
	}
	else if(isalnum(exp[i]))
	{
		i++;
	}
	else
	{
		printf("Not Accepted\n");
		exit(0);
	}
}

void TT(char exp[])
{
	if(exp[i]=='*')
	{
		i++;
		F(exp);
		TT(exp);
		
	}
	else if(exp[i]=='\0')
	{
		printf("Accepted\n");
		exit(0);
	}
}

void T(char exp[])
{
	F(exp);
	TT(exp);
}

void EE(char exp[])
{
	if(exp[i]=='+')
	{
		i++;
		T(exp);
		EE(exp);
		
	}
	else if(exp[i]=='\0')
	{
		printf("Accepted\n");
		exit(0);
	}
}

void E(char exp[])
{
	T(exp);
	EE(exp);
}


int main()
{
	char exp[100];
	printf("Input the string to parse\n");
	scanf("%s",exp);
	E(exp);
	printf("Not Accepted\n");
}

