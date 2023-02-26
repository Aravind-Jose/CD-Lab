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


int main()
{
printf("\nSHIFT REDUCE PARSER\n\n\n");
printf("Enter the number of derivations in your grammer...\n");
scanf("%d",&lcount);
printf("\nEnter your Grammer....\n");
for(int i=0;i<lcount;i++)
{
	scanf("%s",buffer);
	grams[count]=buffer[0];
	ind=0;
	for(int i=3;i<strlen(buffer);i++)
	{
	
		if(buffer[i]=='|')
		{
			rhs[count][ind]='\0';
			count++;
			grams[count]=buffer[0];
			ind=0;
			
		}
		else
		{
			rhs[count][ind]=buffer[i];
			ind++;
		}
		
	}
	rhs[count][ind]='\0';
	count++;
	
}


printf("\nEnter your Input....\n");
scanf("%s",input);
ind=0;
printf("\nStack\t\tInput\t\tAction\n");
while(strlen(input)>0||stacklen>0)
{
	bool canreduce=false;
	for(int i=0;i<count;i++)
	{
		int l1=strlen(rhs[i]);
		// if(stacklen<l1)
		// 	{
		// 	canreduce=false;
		// 	continue;
		// 	}
		canreduce=false;
		printf("\ni %i\n",i);
		if(l1<=stacklen){
			canreduce=true;
			for(int j=0;j<l1;j++)
		{
			if(rhs[i][l1-j-1]!=stack[stacklen-j-1])
				{
					canreduce=false;
					break;
				}
		}
		if(canreduce)
		{
			stacklen-=l1;
			stack[stacklen]=grams[i];
			stacklen++;
			stack[stacklen]='\0';
			printf("$%s\t\t%s$\t\tReduce %s to %c\n",stack,input,rhs[i],grams[i]);
			break;
		}
		}
	}
	
	if(strlen(input)==0)
	{
		if(!canreduce)
		{
			printf("\t\t\t\tNot Accepted!\n\n");
			break;
		}
		else if(stacklen==1&&stack[0]==grams[0])
		{
			printf("\t\t\t\tAccepted!\n\n");
			break;
		}
	}
	if(!canreduce)
	{
		stack[stacklen]=input[0];
		
		for(int i=0;i<strlen(input);i++)
		{
		input[i]=input[i+1];
		}
		stacklen++;
		stack[stacklen]='\0';
		printf("$%s\t\t%s$\t\tShift %c\n",stack,input,stack[stacklen-1]);
	}
	
	
}



}
