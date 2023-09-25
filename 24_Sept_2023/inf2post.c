#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

#define MAX 15
char stack[MAX];
int top = -1;
char pop(char[]);
void push(char[], char);
int priority(char);
void inf2post(char[], char[]);

int main()
{
    // Enter CoDe
    char infix[100], postfix[100];
    printf("\nEnter your expression: ");
    scanf("%s", infix);

    strcpy(postfix, "");
    inf2post(infix, postfix);

    printf("\n The Corresponding Postfix Expression is: \n");
    puts(postfix);

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
}

// Making the Infix Expression to Postfix
void inf2post(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");

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
                exit(1);
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
            exit(1);
        }
    }
    while((top!=-1) && (stack[top]!='('))
    {

      target[j]=pop(stack);
      j++;
    
    }
    target[j]='\0';
}