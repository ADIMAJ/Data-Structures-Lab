//Evaluation of Postfix Expression
#include<stdio.h>                          //Preprocessor Statements
#include<ctype.h>
int stack[20];                                   //Global Variable Declaration
int top = -1;      

void push(int x )                              //Push Function
{
    stack[++top] = x;
}

int pop()                                             //Pop Function
{
    return stack[top--];
}

int main()                                           //Main Function
 {
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("Enter the expression :: ");   //Input of Expression
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')                              //Check Condition
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
            switch(*e)                              //Switch Case
            {
            case '+':
            {
                n3 = n1 + n2;                    //Addition Operation
                break;
            }
            case '-':
            {
                n3 = n2 - n1;                    //Subtration Operation
                break;
            }
            case '*':
            {
                n3 = n1 * n2;                  //Multiplication operation
                break;
            }
            case '/':
            {
                n3 = n2 / n1;                   //Division Operation   
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());     //print Result
    return 0;
}
