#include<stdio.h>
#include<ctype.h>
#include <string.h>
char st[100];
char *e;
int top=-1;
void push(char a){
    st[++top]=a;
}
char pop(){
    return st[top--];
}
int pri(char r){
    if(r=='+' || r=='-'){
        return 1;
    }
    else if (r=='*' || r=='/' )
    {
        return 2;
    }
    else if (r==')' || r=='(')
    {
        return 0;
    }
    
    
}
void main(){
    char exp[10],pos[10],x,ind=0;
    printf("Enter the exp\n");
    scanf("%s",exp);
    e=exp;
    while (*e!='\0')
    {
        printf("St %s\n",st);
        if(isalnum(*e)){
             pos[ind++]=*e;
        }
        else if(*e=='('){
           push(*e); 
        }
        else if(*e==')'){
            while((x=pop())!='('){
                pos[ind++]=x;
            }
        }
        else{
            while (pri(st[top]) >= pri(*e))
            {
                x=pop();
                pos[ind++]=x;
            }
            push(*e);
        }
        e++;
    }
    while (top!=-1)
    {
        x=pop();
        pos[ind++]=x;
    }
    
    pos[ind]='\0';
    printf("Post\t%s\n",pos);
    int teind=1;
    char n1,n2;
    e=pos;
    printf("quad\n");
    while (*e!='\0')
    {
        char n11=NULL,n22=NULL;
        if(isalnum(*e)){
            push(*e);
        }
        else{
            n2=pop();
            n1=pop();
            if(isdigit(n1)){
                n11='t';
            }
            if(isdigit(n2)){
                n22='t';
            }
            printf("t%i\t%c\t%c%c\t%c%c\n",teind,*e,n11,n1,n22,n2);
            push(teind+'0');
            teind++;
        }
        e++;
    }
    
}
