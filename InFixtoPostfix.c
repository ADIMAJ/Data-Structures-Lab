/*Convert Infix to Postfix*/ 
#include<stdlib.h>                       //Preprocessor Statements

#include<stdio.h>

#include<ctype.h>

char stack[30];                       		//Declaring array size
int top = -1;                             //Global Variable Declaration       
void push(char x)                         //Push Function 
{
    stack[++top] = x;
}
char pop()                                                      //Pop Function    
{
    if (top == -1)
        return 1;
    else
        return stack[top--];
}
int priority(char x)                                       //Priority Precedence Function
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
int main()                                                     //Main Function
{
    char exp[20];
    char * e, x;
    printf("Enter the Expression");                             //Input Of Expression
    scanf("%s", exp);
    e = exp;
    while ( * e != '\0')                                        //Check for Condition
    {
        if (isalnum( * e))
            printf("%c", * e);
        else if ( * e == '(')
            push( * e);
        else if ( * e == ')') 
        {
            while ((x = pop()) != '(')                          //Check for Condition
                printf("%c", x);
        } else 
        {
            while (priority(stack[top]) >= priority( * e))           //Check Precedence
                printf("%c", pop());
            push( * e);
        }
        e++;
    }
    while (top != -1)                                           //Check for Condition
    {
        printf("%c", pop());
    }
    return 0;
    printf("/n");                      
}
