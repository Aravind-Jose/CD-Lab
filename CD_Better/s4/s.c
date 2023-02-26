#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char lhs[20];
char rhs[20][10];
char st[10];
char ip[10];
int stlen=0;
char buf[20];
int co=0,ind=0;
void main(){
    FILE *fp;
    printf("f scssfd");

    fp=fopen("grammer.txt","r");
    //printf("fsfd");
    fscanf(fp,"%s",buf);
    lhs[co]=buf[0];
    while (!feof(fp))
    {
        lhs[co]=buf[0];
        printf("d %s\n",buf);
        for (int i = 3; i < strlen(buf); i++)
        {
            if(buf[i]!='|'){
                rhs[co][ind]=buf[i];
                ind++;
            }
            else{
                rhs[co][ind]='\0';
                ind=0;
                co++;
                lhs[co]=buf[0];

            }
        }
        printf("ss %c- %s\n",lhs[co],rhs[co]);
        rhs[co][ind]='\0';
        ind=0;
        co++;        
        fscanf(fp,"%s",buf);
        
    }
    for (int i = 0; i < co; i++)
    {
        printf("%c->%s\n",lhs[i],rhs[i]);
    }
    printf("String\n");
    scanf("%s",ip);
    int fl=0;
    printf("Stack\tInput\tAction\n");
    while (strlen(ip)>0 |stlen>0)
    {
        fl=0;
        for (int i = 0; i < co; i++)
        {
            fl=0;
            int l1=strlen(rhs[i]);
            printf("\nrhs %s %i\n",rhs[i],l1);
            if (stlen>=l1)
            {
                fl=-1;
                printf("\n\nst %s rhs %s\n",st,rhs[i]);
                for (int j = 0; j < l1; j++)
                {
                    if(rhs[i][l1-1-j]!=st[stlen-1-j]){
                        fl=1;
                        break;
                    }
                }
                
            }
            if(fl==-1){
                stlen-=l1;
                st[stlen]=lhs[i];
                st[++stlen]='\0';
                printf("\n\n stt %s %i\n",st,stlen);
                printf("$%s\t%s$\tReduce %c->%s\n",st,ip,lhs[i],rhs[i]);
                break;
            }
            
        }
        if(strlen(ip)==0){
            if(fl!=-1){
                printf("Not acc\n");
                return 0;
            }
            else if(fl==-1 && st[0]==lhs[0]){
                printf("Acc\n");
                return 0;
            }
        }
        if(fl!=-1){
            st[stlen]=ip[0];
            for (int i = 0; i < strlen(ip); i++)
            {
                ip[i]=ip[i+1];
            }
            stlen++;
            st[stlen]='\0';
            printf("$%s\t%s$\tshift %c\n",st,ip,st[stlen-1]);
        }
        
    }
    
    
}