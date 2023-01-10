/*Design a program to demonstrate the working of Towers of Hanoi*/
#include<stdio.h>
void towers(int num,char frompeg,char topeg,char auxpeg);           //Declaring Function
int main()                                                          //Main Function
   {
     int num;
     printf("Enter the Number of disks:#");                         //Input the Number of disks
     scanf("%d",&num);                       
     printf("The Size of moves involved\n");                           
     towers(num,'A','C','B');                                       //Function Call
     return 0;
    }
void towers(int num,char frompeg,char topeg,char auxpeg)           //Towers Function
    {
      if(num==1)                                                   
      {
        printf("Move Disk 1 from peg %c to peg %c\n",frompeg,topeg);  //Steps Involved
        return;
      } 
      towers(num-1,frompeg,auxpeg,topeg);                            //Function Call
      printf("Move Disk %d from peg %c to peg %c\n",num,frompeg,topeg);   
      towers(num-1,auxpeg,topeg,frompeg);                            //Function Call
    }  
