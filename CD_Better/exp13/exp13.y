%{

    #include<stdio.h>

    int flag=0;
    

   

%}

%token NUMBER

%left '*' '/' '%'

%right '+' '-'



%left '(' ')'

%%

ArithmeticExpression: E{

         printf("\nAnswer = %d",$$);

         return 0;

        };

E:E'+'E {$$=$1+$3;}

 |E'-'E {$$=$1-$3;}

 |E'*'E {$$=$1*$3;}

 |E'/'E {$$=$1/$3;}

 |E'%'E {$$=$1%$3;}

 |'('E')' {$$=$2;}

 | NUMBER {$$=$1;}
 ;

%%



void main()

{

   printf("\nEnter your Expression: ");

   yyparse();
  if(flag==0)

   printf("\nYour arithmetic expression is Valid!\n\n");

 

}

void yyerror()

{

   printf("\nYour arithmetic expression is Invalid\n\n");

   flag=1;

}




