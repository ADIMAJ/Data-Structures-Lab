//Conversion of Infix to prefix Expression
#include<stdio.h>                                              //Preprocessor Statements

#include<stdlib.h>

#include<ctype.h>

#include<string.h>

#define max 100                                               //Defining Size of array
int top = -1, a[max];                                         //Global Variable declaration
void push(char x)   			                                    //Push Function
{
    a[++top] = x;
}
char pop()                                                     //Pop Function
{
    if (top == -1)
        return -1;
    else
        return a[top--];
}

int prcd(char c)                                                  //Precedence Function
{
    if (c == ')')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
}
void strrev(char * exp)                                       //String Reverse Function
{
    char temp[50];
    int size = strlen(exp);
    temp[size--] = '\0';
    int i = 0;
    while (exp[i] != '\0') 
    {
        temp[size] = exp[i];
        i++;
        size--;
    }
    strcpy(exp, temp);
}
void infixtoprefix(char infix[max], char prefix[max])                 //InFix to Prefix Function
{
    char temp, x;
    int i = 0, j = 0;
    strrev(infix);                                                                                  //Reversing the infix string
    while (infix[i] != '\0') 
    {
        temp = infix[i];
        if (isalnum(temp)) 
        {
            prefix[j++] = temp;
        } else if (temp == ')')
            push(temp);
        else if (temp == '(') 
        {
            while ((x = pop()) != ')') 
            {
                prefix[j++] = x;
            }
        } else {
            while (prcd(a[top]) >= prcd(temp)) 
            {
                prefix[j++] = pop();
            }
            push(temp);
        }
        i++;
    }
    while (top != -1)                                                      //Check for Condition
        prefix[j++] = pop();
    prefix[j] = '\0';
    strrev(prefix);
}
int main()                                                                     //Main Function
{
    char infix[max], prefix[max];
    printf("Enter the infix expression\n");              //Input of the Expression
    scanf("%s", infix);
    printf("The infix expression is %s\n", infix);
    infixtoprefix(infix, prefix);
    printf("The prefix expression is %s\n", prefix);        //The prefix Expression 
   return 0;
}
