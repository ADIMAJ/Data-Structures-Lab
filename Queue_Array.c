//Implementation of queue using Array
#include<stdio.h>                   //Header Files
#include<stdlib.h>
#define max 5                       //Initialising
void insert();                      //Function Declarations
void delete();
void display();
int front=-1,rear=-1;
int queue[max];

void insert()                        //Insert Function
{ 
   int item; 
   printf("Enter the element:\n");        //Input from User
   scanf("%d",&item);
   if (rear==max-1)
   { 
      printf("OverFlow\n");               //Overflow Condition
      return;
   }  
   if (front==-1 && rear==-1)
   {
      front=0;
      rear=0;
   }
   else
   {
      rear=rear+1;
   }
   queue[rear]= item;
   printf("Value Inserted\n");
}
void delete()                        //Delete Function
{
  int item;
  if(front==-1 || front>rear)
  {
    printf("UnderFlow\n");             //Underflow Condition
    return;
  }
  else
  {
    item = queue[front];
    if(front==rear)
    { 
      front = -1;
      rear = -1;
    }
    else
    {
      front=front+1;
    }
    printf("Value Deleted\n");
  }           
}         
void display()                  //Display Function
{
  int i;
  if (rear==-1)
  {
    printf("Empty Queue \n");
  }
  else
  {
    printf("Printing Values:\n");        //Printing the Queue
    for(i=front;i<=rear;i++)
    {
       printf("%d\n",queue[i]);
    }
  }
}         
int main()                           //Main Function
{
   int choice;
   while(1)                         //While Loop
   {
      printf("Operation performed by Queue:\n");
      printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
      printf("Enter Your Choice\n");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1: insert();
                 break;
         case 2: delete();
                 break;
         case 3: display();
                 break;
         case 4: exit(0);
         default: printf("Invalid Choice\n");
      }
   }                             
}    
