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
printf("\nINTERMEDIATE CODE GENERATION\n\n");
printf("\nEnter your Input Expression....\n");
scanf("%s",input);
ind=0;
postFix();
printf("Postfix Expression: %s\n",buffer);
int ln=1;
int tind=ind;
char tempb[50];
strcpy(tempb,buffer);

printf("\n3-Address Form");

while(ind>1)
{
for(int i=0;i<ind;i++)
{
if(!isalpha(buffer[i])&&!isdigit(buffer[i]))
{
	printf("\nt%d = \t",ln);
	if(isupper(buffer[i-2]))
	printf("t%d \t",(int)(buffer[i-2]-'A'));
	else
	printf("%c \t",buffer[i-2]);
	
	printf("%c \t",buffer[i]);
	if(isupper(buffer[i-1]))
	printf("t%d ",(int)(buffer[i-1]-'A'));
	else
	printf("%c ",buffer[i-1]);
	
	buffer[i-2]=('A'+ln);
	for(int j=i+1;j<ind;j++)
	{
		buffer[j-2]=buffer[j];
	}
	ind-=2;
	ln++;
	break;
}
}
}


strcpy(buffer,tempb);
ind=tind;
ln=1;
printf("\n\nTriple");
printf("\n\tOptr\tOp1\tOp2");

while(ind>1)
{
for(int i=0;i<ind;i++)
{
if(!isalpha(buffer[i])&&!isdigit(buffer[i]))
{
	printf("\n(%d)\t",ln);
	printf("%c\t",buffer[i]);
	if(isupper(buffer[i-2]))
	printf("(%d)\t",(int)(buffer[i-2]-'A'));
	else
	printf("%c\t",buffer[i-2]);
	if(isupper(buffer[i-1]))
	printf("(%d)",(int)(buffer[i-1]-'A'));
	else
	printf("%c",buffer[i-1]);
	
	buffer[i-2]=('A'+ln);
	for(int j=i+1;j<ind;j++)
	{
		buffer[j-2]=buffer[j];
	}
	ind-=2;
	ln++;
	break;
}
}
}
printf("\n");

printf("\nQuadraple");

printf("\n\tOptr\tOp1\tOp2");


strcpy(buffer,tempb);
ind=tind;
ln=1;
while(ind>1)
{
for(int i=0;i<ind;i++)
{
if(!isalpha(buffer[i])&&!isdigit(buffer[i]))
{
	
	printf("\nt%d\t",ln);
	printf("%c\t",buffer[i]);
	if(isupper(buffer[i-2]))
	printf("t%d\t",(int)(buffer[i-2]-'A'));
	else
	printf("%c\t",buffer[i-2]);
	if(isupper(buffer[i-1]))
	printf("t%d",(int)(buffer[i-1]-'A'));
	else
	printf("%c",buffer[i-1]);
	
	buffer[i-2]=('A'+ln);
	for(int j=i+1;j<ind;j++)
	{
		buffer[j-2]=buffer[j];
	}
	ind-=2;
	ln++;
	break;
}
}
}
printf("\n");

printf("\nIndirect");
printf("\n\tOptr\tOp1\tOp2");


strcpy(buffer,tempb);
ind=tind;
ln=1;
while(ind>1)
{
for(int i=0;i<ind;i++)
{
if(!isalpha(buffer[i])&&!isdigit(buffer[i]))
{
	printf("\n(%d)\t",ln);
	printf("%c\t",buffer[i]);
	if(isupper(buffer[i-2]))
	printf("(%d)\t",(int)(buffer[i-2]-'A'));
	else
	printf("%c\t",buffer[i-2]);
	if(isupper(buffer[i-1]))
	printf("(%d)",(int)(buffer[i-1]-'A'));
	else
	printf("%c",buffer[i-1]);
	
	buffer[i-2]=('A'+ln);
	for(int j=i+1;j<ind;j++)
	{
		buffer[j-2]=buffer[j];
	}
	ind-=2;
	ln++;
	break;
}
}
}
printf("\n  Table:\n");
for(int i=1;i<ln;i++)
{
printf("  (%d)  =>  (%d)\n",999+i,i);
}


printf("\n");


}
