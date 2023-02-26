#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char s[3][10]={"main","int","if"};
int iskeyword(char *f){
	for(int i=0;i<3;i++){
		if(strcmp(f,s[i])==0){
			return 1;
		}
	}
	return 0;
}
int isident(char *f){
	if(isdigit(f[0])==1){
		printf("Error\n");
		exit(0);
	}
	return 1;
}
struct syta{
char *na;
int val;
}systab[8];
void main(){
int syind=0;
char *needvar;
FILE *fp;
int lineno=1;
fp=fopen("code.txt","r");
if(fp==NULL){
	printf("Error\n");
} 
char buffer[10];
int buptr=0;
//char c=fgetc(fp);
while(!feof(fp)){
	char c=fgetc(fp);
	buffer[buptr]=c;
	buptr++;
	//printf("\nbuff %s\n",buffer);
	if(c==' '){
		buffer[--buptr]='\0';
		//printf("\nff %s\n",buffer);
		int k=iskeyword(buffer);
		buptr=0;
		//printf("\n k=%i\n",k);
		if(k==1){
			printf("%s\tKeyword\t\t%i\n",buffer,lineno);
			//printf("%s\t\t%i\n",lineno);
		}
		//k=isident(buffer);
	}
	else if(c=='<'||c=='>'||c=='='){
		char c2=fgetc(fp);
		buffer[--buptr]='\0';
		
			int k=iskeyword(buffer);
			//int j=isident(buffer);
			if(k==1){
				printf("%s\tKeyword\t%i\n",buffer,lineno);
			//printf("%s\t\t%i\n",lineno);
			}
			else{
			int fl=0;
				for(int g=0;g<buptr;g++){
					if(!isdigit(buffer[g])){
						fl=1;
					}
				}
				
				if(fl==1){
				printf("%s\tIdenifier\t%i\n",buffer,lineno);
				int flg=0;
				for(int u=0;u<syind;u++){
				 if(strcmp(systab[u].na,buffer)==0){
				 	flg=1;
				 	break;
				 }
				}
				if(flg==0){
					strcpy(systab[syind].na,buffer);
					syind++;
				}
				}
				
				else{
				printf("%s\tliteral\t%i\n",buffer,lineno);
				}
			}
			buptr=0;
		if(c2=='='){
			printf("%c=\tRelop\t%i\n",c,lineno);
		}
		else if(isalnum(c2)){
			
			
			if(c=='='){
				printf("%c\tArith Oper\t%i\n",c,lineno);
			}
			else{printf("%c=\tRelop\t%i\n",c,lineno);}
			buffer[buptr]=c2;
			buptr++;
			//printf("\nfk =%c\n",c);			
			
		}
		
	}
	else if(c=='+'||c=='-'||c=='*'||c=='/'){
		buffer[--buptr]='\0';
		int k=iskeyword(buffer);
		
		if(k==1){
			printf("%s\tKeyword\t%i\n",buffer,lineno);
			//printf("%s\t\t%i\n",lineno);
		}
		else if(buptr!=1){
			int fl=0;
				for(int g=0;g<buptr;g++){
					if(!isdigit(buffer[g])){
						fl=1;
					}
				}
				if(fl==1){
				printf("%s\tIdenifier\t%i\n",buffer,lineno);
				int flg=0;
				for(int u=0;u<syind;u++){
				 if(strcmp(systab[u].na,buffer)==0){
				 	flg=1;
				 	break;
				 }
				}
				if(flg==0){
					strcpy(systab[syind].na,buffer);
					syind++;
				}
				}
				else{
				printf("%s\tliteral\t%i\n",buffer,lineno);
				}
		}
		printf("%c\tArith Oper\t%i\n",c,lineno);
		buptr=0;
		
	}
	
	else if(c=='{'||c=='}'||c==';'||c=='('||c==')'){
		if(c==';'||c=='('||c==')'){
			buffer[--buptr]='\0';
			int k=iskeyword(buffer);
						
			int fl=0;
				for(int g=0;g<buptr;g++){
					if(!isdigit(buffer[g])){
						fl=1;
					}
				}
				if(fl==1){
				printf("%s\tIdenifier\t%i\n",buffer,lineno);
				int flg=0;
				for(int u=0;u<syind;u++){
				 if(strcmp(systab[u].na,buffer)==0){
				 	flg=1;
				 	break;
				 }
				}
				if(flg==0){
					strcpy(systab[syind].na,buffer);
					syind++;
				}
				}
				else{
				printf("%s\tliteral\t%i\n",buffer,lineno);
				}
		}
		buptr=0;
		printf("%c\tDelimiter\t%i\n",c,lineno);
	}
	if(c=='\n'){
		//printf(" %i",lineno);
		lineno++;
		buptr=0;
		
	}
	
	//printf("%c",c);
}
for (int yy=0;yy<syind;yy++){

}
}
