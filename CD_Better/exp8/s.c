#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
char hasep[20],sta[20],sym[20];
char eind=0;
int isfin[20];
char table[20][20][20];
int ns,nl;
char ecls[20];
int ecllen=0;
void eclosure(char a){
    for (int i = 0; i < ns; i++)
    {
        for (int j = 0; j < nl; j++)
        {
            
        }
        
    }
    
}
void main(){
    scanf("%i",&ns);
    scanf("%i",&nl);
    getchar();
    for (int i = 0; i < ns; i++)
    {
        sta[i]=getchar();
        getchar();
    }
    printf("\nsds\n");
    for (int i = 0; i < nl; i++)
    {
        sym[i]=getchar();
        getchar();
    }
    printf("dsfdf\n");
    for (int i = 0; i < ns; i++)
    {
        printf("%c ",sta[i]);
    }
    for (int i = 0; i < nl; i++)
    {
        printf("%c",sym[i]);
    }
    for (int i = 0; i < ns; i++)
    {
        for (int j = 0; j < nl+2; j++)
        {
            scanf("%s",table[i][j]);
            if(j==nl){
                hasep[eind]=sta[i];
                eind++;
            }
            if(j==nl+1){
                if(strcmp(table[i][j],"y")==0){
                    isfin[i]=1;
                }
                else{
                    isfin[i]=0;
                }
            }
        }
        
    }
    for (int i = 0; i < eind; i++)
    {
        ecllen=0;
        ecls[ecllen]='\0';
        eclosure(hasep[i]);
    }
    
    
    
    
}