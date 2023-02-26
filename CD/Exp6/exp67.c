/*
quad
*/

/*
#include<stdio.h>
#include<string.h>

main()
{

 char line[20];
int s[20];
int t=1;

int i=0;
printf("Enter string..  :");
gets(line);
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



getch();
}
*/

/*
infix->postfix
*/


#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

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
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}

/*
Expresion evaluation

*/
/*
#include<stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}
*/
/*
7
*/
/*#include <stdio.h>

#include <stdio.h>

#include<conio.h>

#include <string.h>
void main() {

char icode[10][30], str[20], opr[10];

int i = 0;

clrscr();

printf("\n Enter the set of intermediate code (terminated by exit)\n");



do
{


scanf("%s", icode[i]);

} while (strcmp(icode[i++], "exit") != 0);
printf("\n target code generation");
printf("\n************************");

i = 0;

do {

strcpy(str, icode[i]);
 switch (str[3]) {

case '+':

strcpy(opr, "ADD");

break;
case '-':

strcpy(opr, "SUB");
break;

case '*':

strcpy(opr, "MUL");

break;
case '/':

strcpy(opr, "DIV");
break;
}



printf("\n\tMov %c,R%d", str[2], i);
printf("\n \t%s%c,R%d", opr, str[4], i);
printf("\n\tMov R%d, %c", i, str[0]);
} while (strcmp(icode[++i], "exit") != 0); 
getch();
}
*/
/*
Implement the back end of the compiler which takes the three address code and produces 
the 8086 assembly language instructions that can be assembled and run using an 8086 
assembler. The target assembly instructions can be simple move, add, sub, jump etc
*/
