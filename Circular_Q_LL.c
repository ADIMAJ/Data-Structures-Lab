//Implementation of circular queue using linkedlists
#include<stdio.h>                            //header files
#include<stdlib.h>

struct node                                //Declaring Variable
{
  int data;
  struct node *next;
};
struct node *front=-1;
struct node *rear=-1;  

void enqueue(int x)                       //Enqueue Function
{
   struct node *newnode;
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=x;
   newnode->next=0;
   if(rear==-1)
   {
   front=rear=newnode;
   rear->next=front;
   }
   else
   {
   rear->next=newnode;
   rear=newnode;
   rear->next=front;
   }
}   
void dequeue()                               //Dequeue Function
{
  struct node *temp;
  temp=front;
  if((front==-1)&&(rear==-1))
  {
    printf("Queue is empty");                  //Queue is Empty
  }
  else if(front==rear)
  {
     front=rear=-1;
     free(temp);
  }
  else
  {
     front=front->next;
     rear->next=front;
     free(temp);
  }
}
void display()                        //Display Function
{
struct node* t;
t = front;
if((front==NULL)&&(rear==NULL))
printf("\nQueue is Empty");
else{
do{
printf("\n%d",t->data);
t = t->next;
}while(t != front);
} 
}
int main()                                  //Main Function
{
  int choice,n,i,data;
  while(1)
  {
    printf("\nSelect the operation\n");
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n"); 
    scanf("%d",&choice);
    switch(choice)                           //Switch Case
    {
      case 1: printf("\nEnter the number of data:");     //user Input
	      scanf("%d",&n);
	      printf("\nEnter your data");
              i=0;
		while(i<n){
		scanf("%d",&data);
		enqueue(data);
	        i++;
		}
		break;
      case 2: dequeue();
              break;
      case 3: display();
              break;
      case 4: exit(0);
      default: printf("Invalid choice");
              break;
     }   
   }
  return 0;
  
}           
