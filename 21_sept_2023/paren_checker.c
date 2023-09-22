#include<stdio.h>


#define MAX 200
int stack[MAX];
int top=-1;

char pop();
void push(char);

void main()
{
 char exp[MAX]; int temp,i,flag=1;
 

 printf("\n Enter an expression : ");
 scanf("%s",exp);


 for(i=0;exp[i]!='\0';i++)
   {

      if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
       
        push(exp[i]);

      if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
      {

         if(top==-1)
            flag=0;

         else
         {
             temp=pop();

             if(exp[i]==')' && (temp=='{' || temp=='['))
             flag=0;

             if(exp[i]=='}' && (temp=='(' || temp=='['))
             flag=0;

             if(exp[i]==']' && (temp=='(' || temp=='{'))
             flag=0;

         }

      }
   }


   if(top>=0)
    flag=0;

   if(flag==1)
    printf("\n This is a Valid expression\n\n");

   else
   printf("\n This is an Invalid expression\n\n"); 
 
}


void push(char x)
{
  if(top==(MAX-1))
   printf("\nStack Overflow\n\n");

   else
   {
    top++;
    stack[top]=x;
   }
}

char pop()
{
  char x;
  if(top==-1)
   printf("\nStack Underflow\n\n");
  
  else
  x=stack[top];
   top--; 
  return x;
}