/*Implementation of stack using Array*/
#include<stdio.h>

#include<stdlib.h>

#define size 4
int top = -1, inp_arr[size];  // Global Variable Initialization
void push();                          //Function Declaration
void pop();
void show();
int main() {                           //Main Function
   int choice;
   while (1) 
   {
      printf("Op performed by stack\n");
      printf("1.Push\n");
      printf("2.Pop\n");
      printf("3.Show\n");
      printf("4.Exit\n");
      scanf("%d", & choice);
      switch (choice) {                     //Switch Case 
      case 1:
         push();                                  //Calling Push Function
         break;
      case 2:
         pop();                                     //Calling Pop Function
         break;
      case 3:
         show();                                  //Calling Show Function
         break;
      case 4:
         exit(0);                                    //Exit Switch Case
      default:
         printf("Invalid Choice\n");
      }
   }
}
void push()                                            //Push Operation Function
{
   int x;
   if (top == size - 1) {
      printf("Overflow\n");
   } else {
      printf("Enter the value to be inserted\n");
      scanf("%d", & x);
      top = top + 1;
      inp_arr[top] = x;
   }
}
void pop()                                       //Pop Operation Function
{
   int x;
   if (top == -1) {
      printf("Underflow\n");
   } else {
      printf("The value removed is:%d\n", inp_arr[top]);
      top--;
   }
}
void show()                                    //Show Operation Function
{
   int i;
   printf("The elements in the stack are:\n");
   for (i = 0; i <= top; top++) {
      printf("%d\n", inp_arr[i]);
   }
}
