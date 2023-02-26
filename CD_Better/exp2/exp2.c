#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>


char firsts[10][100];
char grams[10];
int fcount[10]={0,0,0,0,0,0,0,0,0,0};
int dcount=0;
/*
void removeLR(){

FILE *fp,*inm;
char buffer[100];
fp = fopen( "grammer.txt","r");
inm = fopen( "intermediate.txt","w");
if(fp==NULL)
{
  	printf("File could not be opened!\n");
  	exit(0);
}	
if(inm==NULL)
{
  	printf("File could not be opened!\n");
  	exit(0);
}
fscanf(fp,"%s",buffer);
	
while(!feof(fp))
{
	char rhs[10][10],adRhs[10][10],aRhs[10][10];
	
	char lhs=buffer[0];
	int count=0,ind=0,lrCount=0,aCount=0;;
	for(int i=3;i<strlen(buffer);i++)
	{
	
		if(buffer[i]=='|')
		{
			rhs[count][ind]='\0';
			count++;
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
	char aDash[2];
	aDash[0]=(char)('Z'-(buffer[0]-'A'));
	aDash[1]='\0';
	for(int i=0;i<count;i++)
	{
		if(rhs[i][0]==buffer[0])
		{
			strncpy(adRhs[lrCount],rhs[i]+1,strlen(rhs[i])-1);
			strcat(adRhs[lrCount],aDash);
			lrCount++;
		}
		else
		{
			strcpy(aRhs[aCount],rhs[i]);
			strcat(aRhs[aCount],aDash);
			aCount++;
		}
	}
	char aDer[100],adDer[100];
	aDer[0]=buffer[0];
	aDer[1]='\0';
	strcat(aDer,"->");
	for(int i=0;i<aCount;i++)
	{
		strcat(aDer,aRhs[i]);
		if(i!=aCount-1)
			strcat(aDer,"|");
	}
	if(lrCount>0)
	{
		adDer[0]='\0';
		strcat(adDer,aDash);
		strcat(adDer,"->");
		for(int i=0;i<lrCount;i++)
		{
			strcat(adDer,adRhs[i]);
			strcat(adDer,"|");
		}
		strcat(adDer,"$");
		fprintf(inm,"%s\n",aDer);
		fprintf(inm,"%s\n",adDer);
	
	}
	else
		fprintf(inm,"%s\n",buffer);
	fscanf(fp,"%s",buffer);
	
}

fclose(inm);
fclose(fp);
}

*/
void findFirst(){

FILE *fp,*inm;
char buffer[100];
inm = fopen( "grammer.txt","r");
fp = fopen( "first.txt","w");
if(fp==NULL)
{
  	printf("File could not be opened!\n");
  	exit(0);
}	
if(inm==NULL)
{
  	printf("File could not be opened!\n");
  	exit(0);
}

fscanf(inm,"%s",buffer);
	
while(!feof(inm))
{//printf("\n\nLine Read: %s\n",buffer);
	char rhs[10][10];
	int fc=0;
	char lhs=buffer[0];
	int count=0,ind=0,lrCount=0,aCount=0;;
	for(int i=3;i<strlen(buffer);i++)
	{
	
		if(buffer[i]=='|')
		{
			rhs[count][ind]='\0';
			count++;
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
	grams[dcount]=buffer[0];
	
	for(int i=0;i<count;i++)
	{
		firsts[dcount][fcount[dcount]]=rhs[i][0];
		fcount[dcount]++;
	}
	for(int i=0;i<dcount;i++)
	{
		for(int j=0;j<fcount[i];j++)
		{
			if(firsts[i][j]==lhs) //Left recursion
			{
				for(int k=0;k<fcount[dcount];k++)
				{
					firsts[i][fcount[i]]=firsts[dcount][k];
					//printf("\nAssigned %c to first of %c in rec, ",firsts[dcount][k],grams[i]);
					fcount[i]++;
				}
				break;
			}
		}
	}
	
	
	
	dcount++;
	
	fscanf(inm,"%s",buffer);
}
for(int i=0;i<dcount;i++)
	{
	for(int m=i+1;m<dcount;m++)
	{
		for(int j=0;j<fcount[m];j++)
		{
			if(firsts[m][j]==grams[i])
			{
				for(int k=0;k<fcount[i];k++)
				{
					firsts[m][fcount[m]]=firsts[i][k];
					//printf("\nAssigned %c to first of %c in rec2, ",firsts[i][k],grams[m]);
					fcount[m]++;
				}
				break;
			}
		}
	}
}
printf("The firsts are:");
for(int i=0;i<dcount;i++)
	{
		printf("\nFIRST(%c): ",grams[i]);
	
		for(int j=0;j<fcount[i];j++)
		{
		if(firsts[i][j]<'A'||firsts[i][j]>'Z')
		{
			if(firsts[i][j]=='$')
			printf("e,");
			printf("%c,",firsts[i][j]);
			}
		}
	}
fclose(inm);
fclose(fp);
}



void findFollow(){

FILE *fp,*inm;
char buffer[100];
inm = fopen( "grammer.txt","r");
fp = fopen( "first.txt","w");
if(fp==NULL)
{
  	printf("File could not be opened!\n");
  	exit(0);
}	
if(inm==NULL)
{
  	printf("File could not be opened!\n");
  	exit(0);
}

char follow[10][100];
char fgrams[10];
int focount[10]={0,0,0,0,0,0,0,0,0,0};
int fodcount=0;
fscanf(inm,"%s",buffer);
	
while(!feof(inm))
{
	char rhs[10][10];
	int fc=0;
	char lhs=buffer[0];
	int count=0,ind=0,lrCount=0,aCount=0;;
	for(int i=3;i<strlen(buffer);i++)
	{
	
		if(buffer[i]=='|')
		{
			rhs[count][ind]='\0';
			count++;
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
	fgrams[dcount]=buffer[0];
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<strlen(rhs[i]);j++)
		{
			if(rhs[i][j]>='A'&&rhs[i][j]<='Z')
			{
			int tind=fodcount; 
			for(int k=0;k<fodcount;k++)
			{
				if(fgrams[k]==rhs[i][j])
				{	
					tind=k;
					break;
				}
			}
			if(tind==fodcount)fodcount++;
			fgrams[tind]=rhs[i][j];
			int inc=0;
			repeat:
			if(j+inc<strlen(rhs[i])-1)
			{	
				follow[tind][focount[tind]]=rhs[i][j+inc+1];
			
				focount[tind]++;
				if(rhs[i][j+inc+1]>='A' && rhs[i][j+inc+1]<='Z')
				for(int k=0;k<dcount;k++)
				{
					if(grams[k]==rhs[i][j+inc+1])
					for(int m=0;m<fcount[k];m++)
					{
						if(firsts[k][m]=='$')
						{
							inc++;
							//printf("incremented j to %d .. ",inc+j);
							goto repeat;
						}
					}
				}
			
			}
			else if(grams[tind]!=buffer[0])
			{
				follow[tind][focount[tind]]=0-buffer[0];
				//printf("\nAssigned %d to follow of %c, ",(int)follow[tind][focount[tind]],fgrams[tind]);
			
				focount[tind]++;
			
			}
			}
		}
		
	}
	

	fscanf(inm,"%s",buffer);
}
for(int i=0;i<fodcount;i++)
	{
		if(fgrams[i]==grams[0])
			{follow[i][focount[i]]='@';
			focount[i]++;}
	}

for(int i=0;i<fodcount;i++)
	{
		for(int j=0;j<focount[i];j++)
		{  	if(follow[i][j]<0)
			{
			follow[i][j]=0-follow[i][j];
			        if(follow[i][j]<'A'||follow[i][j]>'Z')
			         continue;
			//printf("Finding follow of %c for %c, on first",follow[i][j],fgrams[i]);
			//printf("   >%c\n",follow[i][j]);
		
				for(int k=0;k<fodcount;k++)
				{
					//printf("        >%c\n",fgrams[k]);
					if(fgrams[k]==follow[i][j])
					{
						for(int m=0;m<focount[k];m++)
						{
							//printf("                  >%c\n",follow[k][m]);
							int found=0;
							for(int n=0;n<focount[i];n++)
							{
								if(follow[k][m]==follow[i][n])
								{ //printf("                             Checking %c and %c.,,,,\n",follow[k][m],follow[i][n]);
									found=1;
									break;
								}
							}
							if(!found)
							{
							//printf("                                    not found!!\n");
							follow[i][focount[i]]=follow[k][m];
							focount[i]++;}
						}
					}
					
				}
			}
			else if(follow[i][j]>='A'&&follow[i][j]<='Z' && follow[i][j]!=fgrams[i])
			{
	/*		        
printf("   >%c\n",follow[i][j]);
		
				for(int k=0;k<dcount;k++)
				{printf("        '>%c\n",grams[k]);
					
					if(grams[k]==follow[i][j])
					{
						for(int m=0;m<fcount[k];m++)
						{printf("                  '>%c\n,",firsts[k][m]);
								
							int found=0;
							for(int n=0;n<focount[i];n++)
							{
								if(firsts[k][m]==follow[i][n])
								{
									found=1;
									break;
								}
							}
							if(!found && firsts[k][m]!='$')
							{
							follow[i][focount[i]]=firsts[k][m];
							focount[i]++;
							}
						}
					}
					
				}*/
			}
		}
	}
	
	printf("The follow are:");
for(int i=0;i<fodcount;i++)
	{
		printf("\nFOLLOW(%c): ",fgrams[i]);
	
		for(int j=0;j<focount[i];j++)
		{
		if(follow[i][j]<'A'||follow[i][j]>'Z')
			{
				if(follow[i][j]=='@')
					printf("$,");
				else
					printf("%c,",follow[i][j]);
			}
			
		}
	}
	printf("\n");
fclose(inm);
fclose(fp);
}


int main()
{
	printf("FIRST AND FOLLOW\n\n");
	
	printf("\nFinding First...\n\n");
	findFirst();
	printf("\n\nFinding Follow...\n\n");
	findFollow();

}
