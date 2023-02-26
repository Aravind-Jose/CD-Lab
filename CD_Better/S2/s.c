#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct gr{
    char lhs;
    char rhs[10][10];
    int count;
}gra[10];
int proco=0;
char firs[10][10];
void fir(){
    for (int i = 0; i < proco; i++)
    {
        
    }
    
}
void main(){
    FILE *fp;
    int co=0,leco=0;
    fp=fopen("grammer.txt","r");
    char buf[20];
    fscanf(fp,"%s",buf);
    while(!feof(fp)){
        printf("%s\n",buf);
        gra[proco].lhs=buf[0];
        gra[proco].count=0;
        for (int i = 3; i < strlen(buf); i++)
        {
            if(buf[i]!='|'){
                gra[proco].rhs[co][leco]=buf[i];
                leco++;
            }
            else{
                 gra[proco].count++;
                 gra[proco].rhs[co][leco]='\0';
                 leco=0;
                 co++;
            }
        }
        gra[proco].rhs[co][leco]='\0';
        gra[proco].count++;
        co=0;
        leco=0;
        proco++;
        fscanf(fp,"%s",buf);
    }

    // for (int i = 0; i < proco; i++)
    // {
    //     printf("%c->",gra[i].lhs);
    //     for (int j = 0; j < gra[i].count; j++)
    //     {
    //         printf("%s|",gra[i].rhs[j]);
    //     }
    //     printf("\n");
        
    // }
    
}
