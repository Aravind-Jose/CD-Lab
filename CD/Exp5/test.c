#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
void main(){
	FILE *fp,*symtab,*fp2,*fp3;
	char c,buf[30];
	float g;
	//fp = fopen( "input.txt","r");
	fp2=fopen("con.txt","w");
	fp3 = fopen( "con.txt","r");
	fprintf(fp2,"%f\n",3.1456);
	fclose(fp2);
	/*c=fgetc(fp3);
	while(c!='\n'){
	printf("%c\n",c);
	c=fgetc(fp3);
	}*/
	fscanf(fp3,"%s",buf);
	//fgets(buf,30,fp3);
	printf("%s \n",buf);
}
