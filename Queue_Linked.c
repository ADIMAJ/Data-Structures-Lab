//Implementation of queue using Linked List
#include<stdio.h>
#include<stdlib.h>                 //Header Files
#define max 5
void insert();                     //Function Declaration
void delete();
void display();
int queue[max];
struct node                        //Stucture Declaration
{
  int data;
  struct node *next;
};  
struct node *front ,*rear;

void insert()                       //Insert Function
{   
   struct node *ptr;
   int item;
   ptr=(struct node *)malloc(sizeof(struct node));   //Assigning Size
   if (ptr == NULL)
   {
      printf("Overflow\n");                          
      return;
   }   
   else
   {  printf("Enter the Element :\n");             //Input the element
      scanf("%d",&item);
      ptr->data=item;
      if (front == NULL)
      {  
        front=rear=ptr;
        front -> next=NULL;
        rear -> next=NULL;
      }
      else
      {
        rear -> next=ptr;
        rear=ptr;
        rear -> next=NULL;
      } 
   }
}         
void delete()                                   //Delete Function
{  
   struct node *ptr=(struct node *)malloc(sizeof(struct node));
   if(front==NULL)
   { 
      printf("UnderFlow\n");
      return;
   }
   else
   {
      ptr=front;
      printf("Deleted Element %d\n",ptr->data);
      front=front->next;
      free(ptr);
   }
}         
void display()                            //Display Function
{
   struct node *ptr;
   ptr=front;
   if(ptr==NULL)
   {
     printf("UnderFlow\n");
     return;
   }
   else
   {
     printf("Printing Elements:\n");
     while(ptr!=NULL)
     {
       printf("%d\n",ptr->data);
       ptr=ptr->next;
     }    
   }  
}   
int main()                                //main Function
{
   int choice;
   while(1)
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
