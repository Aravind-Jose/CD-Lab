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
    e = exp;

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
    //char line[20];
    printf("\n");
int s[20];
int t=1;

int i=0;
/*printf("Enter string..  :");
gets(line);*/
for(i=0;i<20;i++)s[i]=0;
printf("op\ta1\ta2\tres\n");
for(i=2;line[i]!='\0';i++)
{
if(line[i]=='/' || line[i]=='*')
{
                printf("\n");
if(s[i]==0)
{
if(s[i+1]==0)
{
printf(":=\t%c\t\t t%d\n",line[i+1],t);
s[i+1]=t++;
}
printf("%c\t",line[i]);
(s[i-1]==0)?printf("%c\t",line[i-1]):printf("t%d\t",s[i-1]);
printf("t%d \t t%d",s[i+1],t);
s[i-1]=s[i+1]=t++;
s[i]=1;
}
}
}

for(i=2;line[i]!='\0';i++)
{
if(line[i]=='+' || line[i]=='-')
{
                printf("\n");
if(s[i]==0)
{
if(s[i+1]==0)
{
printf(":=\t%c\t\t t%d\n",line[i+1],t);
s[i+1]=t++;
}
printf("%c\t",line[i]);
(s[i-1]==0)?printf("%c\t",line[i-1]):printf("t%d\t",s[i-1]);
printf("t%d \t t%d",s[i+1],t);
s[i-1]=s[i+1]=t++;
s[i]=1;
}
}
}
printf("\n:=\tt%d\t\t%c",t-1,line[0]);

    return 0;

}

