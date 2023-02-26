#include <stdio.h>
void main(){
    FILE *fp;
    fp=fopen("code.txt","r");
    char buf[20];
    fgets(buf,20,fp);
    while (!feof(fp))
    {
        printf("%s\n",buf);
        fgets(buf,20,fp);
    }
    
}