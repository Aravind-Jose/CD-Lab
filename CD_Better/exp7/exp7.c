#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

char buffer[100],input[50],stack[50];
int ind=0,stacklen=0;
char grams[20];
char rhs[20][50];
int count=0;
int lcount=0;

char regs[4][10]={"AX","BX","DX"};
char q[10],w[10],e[10],r[10];
int main()
{
int num;
printf("\nEnter number of quadraples....\n");
scanf("%d",&num);
for(int i=0;i<num;i++)
{
	printf("\nEnter quadraple %d\n",i+1);
	char temq[3],temw[3],teme[3],temr[3];
	printf("Operator: ");
	scanf("%s",temq);
	printf("Operand 1: ");
	scanf("%s",temw);
	printf("Operand 2: ");
	scanf("%s",teme);
	printf("Result: ");
	scanf("%s",temr);
	if(temr[0]=='t')
	r[i]=temr[1]-1;
	else
	r[i]=temr[0];
	q[i]=temq[0];
	if(temw[0]=='t')
	w[i]=temw[1]-1;
	else
	w[i]=temw[0];
	if(teme[0]=='t')
	e[i]=teme[1]-1;
	else
	e[i]=teme[0];
}

printf("\n\n8086 CODE\n");
for(int i=0;i<num;i++)
{

	
	if(q[i]=='*')
	{
		if(isdigit(w[i]))
		printf("MOV %s,%s\n",regs[r[i]-'0'],regs[w[i]-'0']);
		else
		printf("MOV %s,[%c]\n",regs[r[i]-'0'],w[i]);
		if(isdigit(e[i]))
		printf("MUL %s,%s",regs[r[i]-'0'],regs[e[i]-'0']);
		else printf("MUL %s,[%c]",regs[r[i]-'0'],e[i]);
	}
	else if(q[i]=='/')
	{
		if(isdigit(w[i]))
		printf("MOV %s,%s\n",regs[r[i]-'0'],regs[w[i]-'0']);
		else
		printf("MOV %s,[%c]\n",regs[r[i]-'0'],w[i]);
		if(isdigit(e[i]))
		printf("DIV %s,%s",regs[r[i]-'0'],regs[e[i]-'0']);
		else printf("DIV %s,[%c]",regs[r[i]-'0'],e[i]);
	}
	else if(q[i]=='+')
	{
		if(isdigit(w[i]))
		printf("MOV %s,%s\n",regs[r[i]-'0'],regs[w[i]-'0']);
		else
		printf("MOV %s,[%c]\n",regs[r[i]-'0'],w[i]);
		if(isdigit(e[i]))
		printf("ADD %s,%s",regs[r[i]-'0'],regs[e[i]-'0']);
		else printf("ADD %s,[%c]",regs[r[i]-'0'],e[i]);
	}
	else if(q[i]=='-')
	{
		if(isdigit(w[i]))
		printf("MOV %s,%s\n",regs[r[i]-'0'],regs[w[i]-'0']);
		else
		printf("MOV %s,[%c]\n",regs[r[i]-'0'],w[i]);
		if(isdigit(e[i]))
		printf("SUB %s,%s",regs[r[i]-'0'],regs[e[i]-'0']);
		else printf("SUB %s,[%c]",regs[r[i]-'0'],e[i]);
	}
	else if(q[i]=='=')
	{
		printf("MOV ");
		if(isdigit(r[i]))
		printf("%s,",regs[r[i]-'0']);
		else
		printf("[%c],",r[i]);
		if(isdigit(w[i]))
		printf("%s",regs[w[i]-'0']);
		else
		printf("[%c]",w[i]);
		
	}
	printf("\n");
	
}



printf("\n");


}
