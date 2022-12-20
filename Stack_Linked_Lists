/*Implementation of Stack using Linked Lists*/
#include<stdio.h>

#include<stdlib.h>

void push();                                                         //Push Function Declaration
void pop();                                                           //Pop Function Declaration
void display();                                                      //Display Function Declaration

struct node 
{                                                                             //Initializing Global Variables
    int val;
    struct node * next;
};
struct node * head;                                           

void push()                                                        //Push Function
   {                       
        int val;
        struct node * ptr = (struct node * ) malloc(sizeof(struct node));    //Alloting Size using Malloc
         if (ptr == NULL)  
            {
                printf("Not able to push the element");
            }  
         else 
           {
              printf("Enter the value\n");                                           //Value Input
              scanf("%d", & val);
              if (head == NULL)
             {
            ptr -> val = val;
            ptr -> next = NULL;
            head = ptr;
            }
             Else
            {
            ptr -> val = val;
            ptr -> next = head;
            head = ptr;
            }
        printf("Item pushed\n");
    }
}

void pop()                                                              //Pop Function
{
    int item;
    struct node * ptr;
    if (head == NULL) 
    {
        printf("Underflow\n");
    } 
     else 
    {
        item = head -> val;
        ptr = head;
        head = head -> next;
        free(ptr);
        printf("Item popped %d\n", item);
    }
}

void display()                                                   //Display Function
{
    int i;
    struct node * ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Stack is empty\n");
     }
      Else
      {
        printf("printing stack elements\n");      //Printing Stack
        while (ptr != NULL)
         {
            printf("%d\t", ptr -> val);
            printf("\n");
            ptr = ptr -> next;
        }
    }
}

int main()                                                                //Main Function
{
    int choice;
    while (1) 
      {
        printf("Select the operation\n");
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d", & choice);
        switch (choice)                                             //Switch Case
          {
            case 1:
                push();                                //Calling push Function
                break;
            case 2:
               pop();                                  //Calling Pop Function
               break;
            case 3:
               display();                             //Calling Display Function
               break;
            case 4:
               exit(0);                               //Exit the Switck Case
            default:
                printf("Invalid choice\n");
          }
    }
}
