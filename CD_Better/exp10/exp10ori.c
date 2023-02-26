#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char ta[10][10],fin[10];
    int row,col;
    
    scanf("%i",&row);
    scanf("%i",&col);
    //printf("FDF\n");
    for (int i = 0; i < row; i++)
    {
        for(int j=0;j<col;j++){
            getchar();
           ta[i][j]=getchar();
           
           //printf("ff %c\n",ta[i][j]);
        }
    }
    //printf("\n");
    int fl=-1;
    for (int i = 0; i < row; i++)
    {
        char c;
        getchar();
        c=getchar();
        
        if(c=='y'){
           if(fl<0){
             fl=i;
           }
        }
    }
    printf("ff %i\n",fl);
    for (int i = 0; i < row; i++)
    {
        ta[i][col]='-';
    }
    int flg;
    for (int i = fl-1; i >= 0; i--)
    {
       for(int k=0;k<i;k++){
        flg=col;
        for(int j=0;j<col;j++){
           if(ta[i][j]==ta[k][j]){
            flg--;
           } 
        }
        if(flg==0){
            ta[i][col]='A'+k;
        }
       }
    }
    for (int i = row; i >= fl; i--)
    {
       for(int k=fl;k<i;k++){
        flg=col;
        for(int j=0;j<col;j++){
           if(ta[i][j]==ta[k][j]){
            flg--;
           } 
        }
        if(flg==0){
            ta[i][col]='A'+k;
        }
       }
    }
    for (int i = 0; i < row; i++)
    {
        if(ta[i][col]=='-'){
            for(int j=0;j<col;j++){
                if(ta[(ta[i][j]-'A')][col]!='-'){
                    printf("%c ",ta[(ta[i][j]-'A')][col]);
                }
                else{
                     printf("%c ",ta[i][j]);
                }
            }
            printf("\n");
        }
        
    }
    
    return 0;
}
/*
5
2
B
C
B
D
B
C
B
E
B
C
n
n
n
n
y
*/