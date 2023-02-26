#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    char pos[10];
    FILE *fp;
    fp=fopen("input.txt","r");
    fscanf(fp,"%s",pos);
    char res[10],ope[10];
    int ind=0,fl1=0,fl2=0,j=0;
    char reg[4][10]={"AX","BX","CX","DX"};
    while (!feof(fp))
    {
        fl1=fl2=-1;
        res[ind++]=pos[3];
        switch (pos[0])
        {
        case '/':
            strcpy(ope,"DIV");
            break;
        case '*':
            strcpy(ope,"MUL");
            break;
        case '-':
            strcpy(ope,"SUB");
            break;
        case '+':
            strcpy(ope,"ADD");
            break;
        default:
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            if(res[i]==pos[1]){
                fl1=i;
            }
            if(res[i]==pos[2]){
                fl2=i;
            }
        }
        if(fl1==-1){
            printf("MOV %s,[%c]\n",reg[j],pos[1]);
        }
        else{
            printf("MOV %s,%s\n",reg[j],reg[fl1]);
        }
        if(fl2==-1){
            printf("%s %s,[%c]\n",ope,reg[j],pos[2]);
        }
        else{
            printf("%s %s,%s\n",ope,reg[j],reg[fl2]);
        }
        printf("MOV [%c],%s\n",pos[3],reg[j]);
        j++;
        fscanf(fp,"%s",pos);
    }
    
}