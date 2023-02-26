#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ip[10];
int ind=0;
void ed();
void t();
void td();
void f();
void e(){
    printf("e %c\n",ip[ind]);
    t();
    ed();
}
void ed(){
    printf("ed %c\n",ip[ind]);
    if(ip[ind]=='+'){ 
        ind++;       
        t();
        ed();
    }
}
void t(){
    printf("t %c\n",ip[ind]);
    f();
    td();
}
void td(){
    printf("td %c\n",ip[ind]);
    if(ip[ind]=='*'){
        ind++;
        f();
        td();
    }
}
void f(){
    printf("f %c\n",ip[ind]);
    if(ip[ind]=='('){
        printf("Ha %c",ip[ind]);
        ind++;
        e();
        if(ip[ind]!=')'){
            ind++;
            printf("Reject\n");
            exit(0);
        }
    }
    else if(ip[ind]<='z' && ip[ind]>='a'){
       ind++;
    }
    else{
        printf("Reject\n");
        exit(0);
    }
}
void main(){
    scanf("%s",ip);
    e();
    printf("Accept");
}