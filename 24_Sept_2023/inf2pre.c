#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 15
char stack[MAX];
int top = -1;
char pop(char[]);
void push(char[], char);
int priority(char);
void inf2pre(char[], char[]);
void rev(char[]);

int main()
{
    // Enter CoDe
    char infix[100], prefix[100];

    printf("\nEnter your expression: ");
    gets(infix);
    rev(infix);
    strcpy(prefix, "");
    inf2pre(infix, prefix);
    rev(prefix);
    printf("\n The Corresponding Prefix Expression is: \n");
    puts(prefix);

    return 0;
}

// Pop Function
char pop(char stack[])
{
    char val = ' ';
    if (top == -1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        val = stack[top];
        top--;
    }

    return val;
}

// Push Function
void push(char stack[], char val)
{
    if (top == (MAX - 1))
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

// To get the priority of the operators
int priority(char operator)
{
    if (operator== '/' || operator== '*' || operator== '%')
    {
        return 1;
    }
    else if (operator== '+' || operator== '-')
    {
        return 0;
    }
    return -1;
}

// Reversing the Infix Expression
void rev(char infix[])
{
    char prefix[100];
    int j=0,i;
    for(i=strlen(infix)-1;i>=0;i--)
    {
        prefix[j]=infix[i];
        if(prefix[j]=='(')
        {
            prefix[j]=')';
        }
        if(prefix[j]==')')
        {
            prefix[j]='(';
        }
        j++;
    }prefix[j+1]='\0';
    strcpy(infix, prefix);
}

// Making the Infix Expression to Postfix
void inf2pre(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target,"");

    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(stack, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (stack[top] != '('))
            {
                target[j] = pop(stack);
                j++;
            }
            if (top == -1)
            {
                printf("\n INCORRECT EXPRESSION");
            }
            temp = pop(stack);
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (stack[top] != '(') && (priority(stack[top]) > priority(source[i])))

            {
                target[j] = pop(stack);
                j++;
            }
            push(stack, source[i]);
            i++;
        }
        else
        {
            printf("\n INCORRECT ELEMENT IN THE EXPRESSION");
        }
    }
    while((top!=-1) && (stack[top]!='('))
    {

      target[j]=pop(stack);
      j++;
    
    }
    target[j]='\0';
}