#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>


char buf[30];
void showError(int ln,char buffer[], char c, int code){
printf("Error at Line Number %d in the lexeme %s%c\nTerminating Program! Error Code: %d\n",ln,buffer,c,code);
exit(0);
}

char* toString(int a)
{
int l=0;
while(a>0)
{
	char c='0'+(a%10);
	a=a/10;
	buf[l]='0';
	l++;
}
for(int i=0;i<l/2;i++)
{
	char c=buf[i];
	buf[i]=buf[l-1-i];
	buf[l-1-i]=buf[i];
}
}



int main()
{

char symbols[100][2][20]={
	
};

int symbc=0;//symbol count
char keywords[40][20]={
	"void","int","char","exit","for","while","printf","return"
};

printf("LEXICAL ANALYSER\n\n");
FILE *fp,*symtab;
fp = fopen( "code.txt","r");
symtab = fopen( "symtab.txt","w");
if(fp==NULL)
{
  	printf("File could not be opened!\n");
  	exit(0);
}	
if(symtab==NULL)
{
  	printf("Symbol Table could not be opened!\n");
  	exit(0);
}
 printf("Lexeme\tToken\t\tLine Number\n------------------------------------------------\n");
char buffer[30],idf[30],idf2[30];
char idstack[30][20],opstack[30];// For arithmetic calculation
int idtop=0,optop=0;
int ln=1;//line number
bool isd=false;//is buffer a literal
bool expecting=false;// whether expecting a literal
bool isStringLiteral=false;
int sp=0,cp=0,bp=0;//start pointer, current pointer, buffer pointer
char c=fgetc(fp);
while(!feof(fp))
{
	if(isStringLiteral && c!='"')
	{
		buffer[bp]=c;
		bp++;
		c=fgetc(fp);
		continue;
		
	}
	else if(!isStringLiteral && !isalnum(c)&&c!='_'&&bp!=0)
	{
 		buffer[bp]='\0';
 		bool isk=false;
 		for(int i=0;i<40;i++)
 		{
 			if(strcmp(keywords[i],buffer)==0)
 			{
 				isk=true;
 				break;
 			}
 		}
 		if(isk)
 			printf("%s\tKeyword\t\t\t%d\n",buffer,ln);
 		else if(isd)
 		{
 			strcpy(idstack[idtop],buffer);
 			idtop++;
 			printf("%s\tLiteral\t\t\t%d\n",buffer,ln);
 			//strcpy(buffer,idf);
 		}
 		else
 		{
 			strcpy(idstack[idtop],buffer);
 			idtop++;
 			strcpy(idf,buffer);
 			printf("%s\tIdentifier\t\t%d\n",buffer,ln);
 		}
 		bp=0;
 		buffer[bp]='\0';
 		isd=false;
	}
	if(c=='"')
	{	
		if(isStringLiteral)
			{printf("%s\tLiteral\t\t%d\n",buffer,ln);bp=0;
		buffer[bp]='\0';
			}
		isStringLiteral=!isStringLiteral;
		
	}
	else if(c=='+'||c=='-'||c=='*'||c=='/')
	{
 		printf("%c\tArithmetic Operator\t%d\n",c,ln);
 		
		if(optop>0)
		{
			if((opstack[optop-1]=='*'||opstack[optop-1]=='/')&&(c=='+'||c=='-'))
			{
			        if(idtop<2)
				{
					showError(ln,buffer,c,1);
				}
				idtop--;
				char operand[30];
				strcpy(operand,idstack[idtop]);
				
				int op1=0,op2=0;
				if(isdigit(operand[0]))
				{
					op1=atoi(operand);
				}
				else
				{
					int i=0;
					for(i=0;i<symbc;i++)
					{
						if(strcmp(symbols[i][0],operand)==0)
						{
							op1=atoi(symbols[i][1]);
							break;
						}
					}
					if(i==symbc)
					{
						showError(ln,buffer,c,2);
					}
				}
				idtop--;
				strcpy(operand,idstack[idtop]);
				if(isdigit(operand[0]))
				{
					op2=atoi(operand);
				}
				else
				{
					int i=0;
					for(i=0;i<symbc;i++)
					{
						if(strcmp(symbols[i][0],operand)==0)
						{
							op2=atoi(symbols[i][1]);
							break;
						}
					}
					if(i==symbc)
					{
						showError(ln,buffer,c,3);
					}
				}
				int ans=0;
				if(opstack[optop-1]=='*')
				{
					ans=op1*op2;
				}
				else if(opstack[optop-1]=='/')
				{
					ans=op2/op1;
				}
				toString(ans);
				strcpy(idstack[idtop],buf) ;
				idtop++;
				optop--;
			}
		}
		opstack[optop]=c;
 		optop++;
	}
	else if(isalpha(c))
	{
		if(isd)
		{
			showError(ln,buffer,c,4);
		}
		buffer[bp]=c;
		bp++; 
		if(bp==1)
		{
			isd=false;
		}
	}
	else if(isdigit(c))
	{

		buffer[bp]=c;
		bp++;
		if(bp==1)
		{
			isd=true;
		}
	}
	else if(c=='_')
	{
		if(bp!=0)
		{
			buffer[bp]=c;
			bp++;  
		}
		else
		{
			showError(ln,buffer,c,5);
		}
	}
	else if(c=='<'||c=='>'||c=='='||c=='!'){
		char c2=fgetc(fp);
		if(c2=='=')
		{
 			printf("%c=\tRelational Operator\t%d\n",c,ln);
			
		}
		else if(c=='!')
		{
			showError(ln,buffer,c,6);
			c=c2;
			continue;
		}
		else if(c!='=')
		{
			
 			printf("%c\tRelational Operator\t%d\n",c,ln);
 			c=c2;
 			continue;
		}
		else 
		{
			printf("%c\tAssignment Operator\t%d\n",c,ln);
 			c=c2;
 			idtop=0;
 			
 			strcpy(idf2,idf);
 			expecting=true;
 			continue;
		}
	}
	else if(c==';'||c==',')
	{
		printf("%c\tDelimiter\t\t%d\n",c,ln);
		while(idtop>1)
		{
		 	
				idtop--;
				char operand[30];printf("Got Operand 2: ");
				
				strcpy(operand,idstack[idtop]);
				
				int op1=0,op2=0;
				if(isdigit(operand[0]))
				{
					op1=atoi(operand);
				}
				else
				{
					int i=0;
					for(i=0;i<symbc;i++)
					{
						if(strcmp(symbols[i][0],operand)==0)
						{
							op1=atoi(symbols[i][1]);
							break;
						}
					}
					if(i==symbc)
					{
						showError(ln,buffer,c,7);
					}
				}
				idtop--;
				strcpy(operand,idstack[idtop]);
				if(isdigit(operand[0]))
				{
					op2=atoi(operand);
				}
				else
				{
					int i=0;
					for(i=0;i<symbc;i++)
					{
						if(strcmp(symbols[i][0],operand)==0)
						{
							op2=atoi(symbols[i][1]);
							break;
						}
					}
					if(i==symbc)
					{
						showError(ln,buffer,c,8);
					}
				}
				int ans=0;
				if(opstack[optop-1]=='*')
				{
					ans=op1*op2;
				}
				else if(opstack[optop-1]=='/')
				{
					ans=op2/op1;
				}
				else if(opstack[optop-1]=='+')
				{
					ans=op1+op2;
				}
				else if(opstack[optop-1]=='-')
				{
					ans=op2-op1;
				}
				toString(ans);
				strcpy(idstack[idtop],buf) ;
				idtop++;
				optop--;
		}
		strcpy(symbols[symbc][0],idf2);
		if(isalpha(idstack[0][0]))
		{
			int i=0;
			printf("Searching");
					for(i=0;i<symbc;i++)
					{
						if(strcmp(symbols[i][0],idstack[0])==0)
						{
							
							strcpy(symbols[symbc][1],symbols[i][1]);
							break;
						}
					}
					if(i==symbc)
					{
						showError(ln,buffer,c,9);
					}
		}
		else
		{
			strcpy(symbols[symbc][1],idstack[0]);
							
		}
		
		printf("Stored %s with value %s to Symbol Table...\n",idf2,symbols[symbc][1]);
		char toStore[80];
		strcat(toStore,idf2);
		strcat(toStore," : ");
		strcat(toStore,symbols[symbc][1]);
		strcat(toStore,"\n\0");
		fseek(symtab,0,SEEK_SET);
		fprintf(symtab,"%s",toStore);
		symbc++;
		
	}
	else if(c=='{'||c=='}'||c=='('||c==')'||c=='['||c==']')
	{
		printf("%c\tSeparator\t\t%d\n",c,ln);
	}
	else if(c=='\n')
	{
		ln++;
	}
	
	else if(c!=' ')

	{
		showError(ln,buffer,c,10);
	}
	c=fgetc(fp);
}
fclose(fp);
return 0;
}

