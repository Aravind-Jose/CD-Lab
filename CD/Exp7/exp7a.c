#include<stdio.h>
#include<ctype.h>
#include <string.h>
char stack[100];
int top = -1,ptrp=0;
char post[100];
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100],line[20];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",line);
    strncpy(exp,line+2,strlen(line));
    printf("\n");
    printf("Postfix expression: ");
    e = line;

    while(*e != '\0')
    {
        if(isalnum(*e))
            {
            printf("%c",*e);
            post[ptrp++]=*e;
            }
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                {
                printf("%c", x);
                post[ptrp++]=x;
                }
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                {
                post[ptrp++]=pop();
                printf("%c",post[ptrp-1]);
                }
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
    	post[ptrp++]=pop();
        printf("%c",post[ptrp-1]);
    }
    printf("\n\n3 Address\n");
    char n1,n2,num,tempind=1;
    strcpy(exp,post);
    e = post;
    
    while(*e != '\0')
    {
        if(isalpha(*e))
        {
            push(*e);
        }
        else
        {
            n2 = pop();
            n1 = pop();
            char n11=NULL,n22=NULL;
            if(isdigit(n1)){
            
            	n11='t';
            }
            if(isdigit(n2)){
            	n22='t';
            }
            //printf("%c\t%c%c\t%c%c\tt%i\n",*e,n11,n1,n22,n2,tempind);
            printf("t%i=%c%c%c%c%c\n",tempind,n11,n1,*e,n22,n2);
            char a='0'+tempind;  
            tempind++;          
            push(a);
        }
        e++;
    }
    printf("\n\nQuadruple\n");
    tempind=1;
    //char exp[20];
    
    strcpy(exp,post);
    e = post;
    
    while(*e != '\0')
    {
        if(isalpha(*e))
        {
            push(*e);
        }
        else
        {
            n2 = pop();
            n1 = pop();
            char n11=NULL,n22=NULL,m1=m12=NULL,m2=m22=NULL,vv[20];
            if(isdigit(n1)==0){
            	m1='[';
            	m12=']';
            }
            if(isdigit(n2)==0){
            	m2='[';
            	m22=']';
            }
            switch(*e){
            case '+':strcpy(vv,"ADD");
            		break;
            case '-':strcpy(vv,"SUB");
            		break;
            case '*':strcpy(vv,"MUL");
            		break;
            case '/':strcpy(vv,"DIV");
            		break;
            }
            if(m1=='[' && m2=='['){
            	printf("MOV %c%c%c,R%i\n",m1,n1,m12,tempind++);
            	printf("MOV %c%c%c,R%c\n",m2,n2,m22,tempind++);
            	printf("%s R%i,R%i",vv,tempind-2,tempind-1);
            }
            else if(m1=='[' && m2!='['){
            	
            	printf("%s %c%c%c,R%i\n",vv,m1,n1,m12,tempind-1);
            }
            else if()
            //,m2,n2,m22
            switch(*e){
            case '+': printf("ADD %c,");
            }
            //printf("%c\t%c%c\t%c%c\tt%i\n",*e,n11,n1,n22,n2,tempind);
            char a='0'+tempind;  
            tempind++;          
            push(a);
        }
        e++;
    }
    
    
    //printf("%c\t%c\tt%c\n",'=',line[0],pop());
    printf("\nTriple\n");
    tempind=1;
    e = post;
    while(*e != '\0')
    {
    char t,y,u,i;
        if(isalpha(*e))
        {
            push(*e);
        }
        
        else
        {
            n2 = pop();
            n1 = pop();
            
            t=y=u=i=' ';
            if(isdigit(n1)){
            t='(';
            y=')';
            }
            if(isdigit(n2)){
            u='(';
            i=')';
            }
            printf("(%i)\t%c\t%c%c%c\t%c%c%c\n",tempind,*e,t,n1,y,u,n2,i);
            char a='0'+tempind;  
            tempind++;          
            push(a);
        }
        e++;
    }
	n1 = pop();
	//printf("(%i)\t=\t%c\t(%c)\n",tempind++,line[0],n1);
    
    printf("\nIndirect Triple\n");
    tempind=1;
    e = post;
    while(*e != '\0')
    {
        if(isalpha(*e))
        {
            push(*e);
        }
        
        else
        {
            n2 = pop();
            n1 = pop();
            char t,y,u,i;
            t=y=u=i=' ';
            if(isdigit(n1)){
            t='(';
            y=')';
            }
            if(isdigit(n2)){
            u='(';
            i=')';
            }
            printf("(%i)\t%c\t%c%c%c\t%c%c%c\n",tempind,*e,t,n1,y,u,n2,i);
            char a='0'+tempind;  
            tempind++;          
            push(a);
        }
        e++;
    }
     		n1 = pop();                        
            
    //printf("(%i)\t=\t%c\t(%c)\n",tempind++,line[0],n1);
    printf("\nTable\n\n");
    for(int yy=1;yy<tempind;yy++){
    	printf("(%i)=>(%i)\n",yy+1000,yy);
    }
    //printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    
    return 0;
}
