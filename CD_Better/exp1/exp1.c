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
	buf[l]=c;
	l++;
}
for(int i=0;i<l/2;i++)
{
	char c=buf[i];
	buf[i]=buf[l-1-i];
	buf[l-1-i]=c;
}
}



int main()
{

char symbols[100][2][20]={};

int symbc=0;//symbol count
char keywords[40][20]={
	"void","int","char","exit","for","while","return","if","else"
};
char dtypes[40][20]={"int","char"};

printf("LEXICAL ANALYSER\n\n");
FILE *fp,*symtab;
fp = fopen( "code.c","r");
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
bool defining=false;
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
	else if(!isStringLiteral && !isalnum(c) && c!='_' && bp!=0) // ' ', ( , ), , ,
	{
		printf("\nsa %c\n",c);
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
 		for(int i=0;i<40;i++)
 		{
 			if(strcmp(dtypes[i],buffer)==0)
 			{
 				defining=true;
 				break;
 			}
 		}
 		if(isk)
 			printf("%s\tKeyword\t\t\t%d\n",buffer,ln);
 		else if(isd)
 		{
 			strcpy(idstack[idtop],buffer);
 			idtop++;
 			//printf("%s\tLiteral\t\t\t%d\n",buffer,ln);
 			//strcpy(buffer,idf);
 		}
 		else if(strcmp(buffer,"main")==0) 
 		{
 			printf("%s\tFunction\t\t%d\n",buffer,ln);
 		}
 		else
 		{
 			strcpy(idstack[idtop],buffer);
 			idtop++;
 			strcpy(idf,buffer);
 			int targetInd=symbc;
		
		int j=0;
			for(j=0;j<symbc;j++)
					{
					if(strcmp(symbols[j][0],idf)==0)
					{
					targetInd=j;
					break;
					}
					}
 			printf("%s\tIdentifier %d\t\t%d\n",buffer,targetInd+1,ln);
 		}
 		bp=0;
 		buffer[bp]='\0';
 		isd=false;
	}
	if(c=='"')
	{	
		if(isStringLiteral)
			{//printf("%s\tLiteral\t\t%d\n",buffer,ln);bp=0;
		buffer[bp]='\0';
			}
		isStringLiteral=!isStringLiteral;
		
	}
	else if(c=='+'||c=='-'||c=='*'||c=='/')
	{
 		if(c=='+')
			printf("%c\tArithmetic Operator (AD)\t%d\n",c,ln);
		if(c=='-')
			printf("%c\tArithmetic Operator (MI)\t%d\n",c,ln);
		if(c=='*')
			printf("%c\tArithmetic Operator (ML)\t%d\n",c,ln);
		if(c=='/')
			printf("%c\tArithmetic Operator (DV)\t%d\n",c,ln);
 		
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
		if(c=='<')
 			printf("%c=\tRelational Operator (LE)\t%d\n",c,ln);
		if(c=='>')
 			printf("%c=\tRelational Operator (GE)\t%d\n",c,ln);
		if(c=='=')
 			printf("%c=\tRelational Operator (EQ)\t%d\n",c,ln);
		if(c=='!')
 			printf("%c=\tRelational Operator (NE)\t%d\n",c,ln);
			
		}
		else if(c=='!')
		{
			showError(ln,buffer,c,6);
			c=c2;
			continue;
		}
		else if(c!='=')
		{
			if(c=='>')printf("%c\tRelational Operator(GT)\t%d\n",c,ln);
 			else
 			printf("%c\tRelational Operator (LT)\t%d\n",c,ln);
 			c=c2;
 			expecting =true;
 			continue;
		}
		else 
		{
			printf("%c\tAssignment Operator (EQ)\t%d\n",c,ln);
 			c=c2;
 			idtop=0;
 			
 			strcpy(idf2,idf);
 			expecting=true;
 			continue;
		}
	}
	else if(c==';'||c==',')
	{
		if(expecting)
		{
		while(idtop>1)
		{
		 	
				idtop--;
				char operand[30];//printf("Got Operand 2: ");
				
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
							if(strcmp(symbols[i][1],"-")==0)
								op1=0;
							else
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
						{	if(strcmp(symbols[i][1],"-")==0)
								op1=0;
							else
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
		int targetInd=symbc;
		if(!defining)
		{
		int j=0;
			for(j=0;j<symbc;j++)
					{
					if(strcmp(symbols[j][0],idf2)==0)
					{
					targetInd=j;
					break;
					}
					}
		}
		strcpy(symbols[targetInd][0],idf2);
		
		if(isalpha(idstack[0][0]))
		{
			//printf("for target %d",targetInd);
		
			int i=0;
					if(strcmp(symbols[targetInd][0],idf2)==0)
					{
					for(i=0;i<symbc;i++)
					{
					
						
						if(strcmp(symbols[i][0],idstack[0])==0)
						{
							
							strcpy(symbols[targetInd][1],symbols[i][1]);
							break;
						}
						
					}
					if(i==symbc)
					{
						showError(ln,buffer,c,12);
					}
					}
					
					
		}
		else
		{
			int j=0;
			
			strcpy(symbols[targetInd][1],idstack[0]);
					
							
		}
		//printf("Stored %s with value %s to Symbol Table...\n",symbols[targetInd][0],symbols[targetInd][1]);
		
		if(defining)
		{symbc++;//printf("now");
		}
		if(c==';')
		defining=false;
		}
		else if(defining)
		{
		strcpy(symbols[symbc][0],idf);
		strcpy(symbols[symbc][1],"-");
		symbc++;//printf("and now");
		if(c==';')
		defining=false;
		}
		expecting=false;
		
	}
	else if(c=='{'||c=='}'||c=='('||c==')'||c=='['||c==']')
	{
	//	printf("%c\tSeparator\t\t%d\n",c,ln);
	}
	else if(c=='\n')
	{
		ln++;
	}
	
	else if(c!=' '&&c!='\t')

	{
		showError(ln,buffer,c,10);
	}
	c=fgetc(fp);
}
for(int j=0;j<symbc;j++)
					{char toStore[80];
		
					
			
		strcpy(toStore,"");
		strcat(toStore,symbols[j][0]);
		strcat(toStore," : ");
		strcat(toStore,symbols[j][1]);
					
		
		strcat(toStore,"\n\0");
		fprintf(symtab,"%s",toStore);
					}

fclose(symtab);
fclose(fp);
return 0;
}
