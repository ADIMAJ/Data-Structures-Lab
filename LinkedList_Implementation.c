
//Linked List Implementation
#include<stdio.h>                              //Header Files
#include<stdlib.h>

struct node                                      //node Creation
{
   int data;
   struct node *next;
};
struct node *head;

void begin_insert()  // Function to insert the element in the beginning
{
  struct node *ptr;
  int item;
  ptr=(struct node *)malloc(sizeof(struct node *));
  if(ptr==NULL)
  {
   printf("Overflow\n");
  }
  else
  {
   printf("Enter Value:");               //user Input
   scanf("%d",&item);
   ptr->data=item;
   ptr->next=head;
   head=ptr;
   printf("Node Inserted\n");
  }
}

void last_insert()   // Function to insert the element in the last
{
        struct node *ptr,*temp;
        int item;
        ptr=(struct node *)malloc(sizeof(struct node *));
        if(ptr==NULL)
        {
          printf("OverFlow\n");
        }
        else
        {
          printf("Enter Value:");        //User Input
          scanf("%d",&item);
          ptr->data=item;
          if(head==NULL)
          {
            ptr->next=NULL;
            head=ptr;
            printf("Node Inserted\n");
          }
          else
          {
            temp=head;
            while(temp->next!=NULL)
            {
              temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("Node Inserted\n");
          }  
        }
}      
void random_insert() // Function to insert the element at random loc
{
   struct node *ptr,*temp;
   int item,loc,i;
   ptr=(struct node *)malloc(sizeof(struct node *));  
   if(ptr==NULL)
   {
     printf("Overflow");
   }
   else
   {
    printf("Enter Value:");             //User Input
    scanf("%d",&item);
    ptr->data=item;
    printf("\nEnter the loc after which you want to insert\n");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<loc;i++)
    {
      temp=temp->next;
      if(temp==NULL)
      {
        printf("Cant Insert\n");
        return;
      }    
    }
    ptr->next=temp->next;
    temp->next=ptr;
    printf("Node inserted\n");
   };     
}

//Deletion 

void begin_delete()   // Function to delete the element in the beginning
{
  struct node *ptr,*ptr1;
  if(head==NULL)
  {
    printf("List is Empty\n");
  }
  else
  {
    ptr=head;
    head=ptr->next;
    free(ptr);
    printf("Node Deleted from beginning\n");  //Node Deleted
  }
}

void last_delete()    // Function to delete the element in the last
  struct node *ptr,*ptr1;
  if(head==NULL)
  {
    printf("List is Empty\n");
  }
  else if(head->next==NULL)
  {
     head=NULL;
     free(head);
     printf("Only Node of the list deleted\n");   //node deleted
  }
  else
  {
    ptr=head;
    while(ptr->next!=NULL)
    {
       ptr1=ptr;
       ptr=ptr->next;
    }
    ptr1->next=NULL;
    free(ptr);
    printf("Deleted node from the last\n");
  }       
}    

void delete_random()   // Function to delete the element at random
{
struct node *ptr,*ptr1;
int loc,i;
printf("Enter the location of the node after which it has to be deleted\n");                         //Enter Loc
scanf("%d",&loc);
ptr=head;
for(i=0;i<loc;i++)
{
  ptr1=ptr;
  ptr=ptr->next;
  if(ptr==NULL)
  {
    printf("Cant Delete\n");
    return;
  }
}
ptr1->next=ptr->next;
free(ptr);
printf("Delete Node %d ",loc+1);                   //node deleted
}

void display()                           //Display Function
{
	if(head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
        printf("LinkedList: ");
	struct node* ptr = head;
	while(ptr!=NULL) // start from first node
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
    printf("\n");
}

int main()                            //Main Function
{
   int choice;
   while(1)
   {
      printf("Operation performed by Linked Lists:\n");
      printf("1.Insert at Begin\n2.Insert at Last\n3.Insert at Random\n4.Delete at Begin\n5.Delete at Last\n6.Delete at random\n7.Display\n8.Exit\n");
      printf("Enter Your Choice\n");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1: begin_insert();
                 break;
         case 2: last_insert();
                 break;
         case 3: random_insert();
                 break;                
         case 4: begin_delete();
                 break;
         case 5: last_delete();
                 break;
         case 6: delete_random();
                 break;                
         case 7: display();
                 break;
         case 8: exit(0);
         default: printf("Invalid Choice\n");
      }
   }                             
}             
