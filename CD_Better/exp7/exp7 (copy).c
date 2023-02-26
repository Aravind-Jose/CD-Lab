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

void postFix()
{
	int l=strlen(input);

	int stc=0;
	for(int i=0;i<l;i++)
	{
		if(isalpha(input[i]))
		{
			buffer[ind]=input[i];
			ind++;
		}
		else if(input[i]==')')
		{
			
				while(stack[stc-1]!='(')
				{
					stc--;
					buffer[ind]=stack[stc];
					ind++;
					
				}
				stc--;
				
		}
		else if(input[i]=='+'||input[i]=='-')
		{
			if(stc==0)
			{
				stack[stc]=input[i];
				stc++;
			}
			else
			{
				while(stack[stc-1]=='*'||stack[stc-1]=='/')
				{
					stc--;
					buffer[ind]=stack[stc];
					ind++;
					
				}
				if(stc==0)
				{
					stack[stc]=input[i];
					stc++;
				}
				else if(stack[stc-1]=='+'||stack[stc-1]=='-')
				{
					stc--;	
					buffer[ind]=stack[stc];
					ind++;
					stack[stc]=input[i];
					stc++;
				}
				else
				{
					stack[stc]=input[i];
					stc++;
				}
			}
		}
		else if(input[i]=='*'||input[i]=='/')
		{
			if(stc==0)
			{
				stack[stc]=input[i];
				stc++;
			}
			else
			{
				
				if(stack[stc-1]=='*'||stack[stc-1]=='/')
				{
					stc--;	
					buffer[ind]=stack[stc];
					ind++;
					stack[stc]=input[i];
					stc++;
				}
				else
				{
					stack[stc]=input[i];
					stc++;
				}
			}
		}
		else if(input[i]=='=')
		{
			stack[stc]=input[i];
			stc++;
		}
		else if(input[i]=='(')
		{
			stack[stc]=input[i];
			stc++;
		}
		
	}
	while(stc>0)
				{
					stc--;
					buffer[ind]=stack[stc];
					ind++;
					
				}
}

int main()
{

printf("\nEnter your Input Expression....\n");
scanf("%s",input);
ind=0;
postFix();
printf("Postfix Expression: %s\n",buffer);
int ln=0;
int tind=ind;
char tempb[50];
strcpy(tempb,buffer);


while(ind>1)
{
for(int i=0;i<ind;i++)
{
if(!isalpha(buffer[i])&&!isdigit(buffer[i]))
{
	
	if(buffer[i]=='*')
	{
		if(isdigit(buffer[i-2]))
		printf("MOV R%c,R%d\n",buffer[i-2],ln);
		else
		printf("MOV [%c],R%d\n",buffer[i-2],ln);
		if(isdigit(buffer[i-1]))
		printf("MUL R%d,R%c",ln,buffer[i-1]);
		else printf("MUL R%d,[%c]",ln,buffer[i-1]);
	}
	else if(buffer[i]=='/')
	{
		if(isdigit(buffer[i-2]))
		printf("MOV R%c,R%d\n",buffer[i-2],ln);
		else
		printf("MOV [%c],R%d\n",buffer[i-2],ln);
		if(isdigit(buffer[i-1]))
		printf("DIV R%d,R%c",ln,buffer[i-1]);
		else printf("DIV R%d,[%c]",ln,buffer[i-1]);
	}
	else if(buffer[i]=='+')
	{
		if(isdigit(buffer[i-2]))
		printf("MOV R%c,R%d\n",buffer[i-2],ln);
		else
		printf("MOV [%c],R%d\n",buffer[i-2],ln);
		if(isdigit(buffer[i-1]))
		printf("ADD R%d,R%c",ln,buffer[i-1]);
		else printf("ADD R%d,[%c]",ln,buffer[i-1]);
	}
	else if(buffer[i]=='-')
	{
		if(isdigit(buffer[i-2]))
		printf("MOV R%c,R%d\n",buffer[i-2],ln);
		else
		printf("MOV [%c],R%d\n",buffer[i-2],ln);
		if(isdigit(buffer[i-1]))
		printf("SUB R%d,R%c",ln,buffer[i-1]);
		else printf("SUB R%d,[%c]",ln,buffer[i-1]);
	}
	else if(buffer[i]=='=')
	{
		printf("MOV ");
		if(isdigit(buffer[i-1]))
		printf("R");
		else
		printf("[");
		printf("%c,",buffer[i-1]);
		if(isalpha(buffer[i-1]))
		printf("]");
		if(isdigit(buffer[i-2]))
		printf("R");else
		printf("[");
		printf("%c",buffer[i-2]);
		if(isalpha(buffer[i-2]))
		printf("]");
	}
	printf("\n");
	//printf("Before: %s %d\n",buffer,i);
	buffer[i-2]=(char)(ln+'0');
	for(int j=i+1;j<ind;j++)
	{
		//printf("%c moving to %d\n",buffer[j],j-2);
		buffer[j-2]=buffer[j];
	}
	//printf("Buffer: %s\n",buffer);
	ind-=2;
	ln++;
	break;
}
}
}



printf("\n");


}
