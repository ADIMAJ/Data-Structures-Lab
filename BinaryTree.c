#include <stdio.h>                             //Headers
#include <stdlib.h>
struct node{                                                   //Node Declaration
int data ;
struct node *left ;
struct node *right ;
};
struct node* maketree(){                            //Function to create Tree
struct node *p ;
int info ;
printf("Enter the info or -1 for null\n");                     //input for root
scanf("%d", &info) ;
if(info == -1) return NULL ;
p = (struct node *)malloc(sizeof(struct node)) ;
p->data = info ;
printf("Enter the left child of %d\n",info );                      //Input for Left
p->left = maketree() ;
printf("Enter the right child of %d\n",info );                   //Input for Right
p->right = maketree() ;
return p ;
}
void preorder(struct node *t){                                         //Preorder Traversal Function
if(t!=NULL){
printf("%d->", t->data) ;
preorder(t->left) ;
preorder(t->right) ;
}
}
void postorder(struct node *t){                                          //Postorder Traversal Function
if(t!=NULL){
postorder(t->left) ;
postorder(t->right) ;
printf("%d->", t->data) ;
}
}
void inorder(struct node *t){                                                         //Inorder Traversal Function
if(t!=NULL){
inorder(t->left) ;
printf("%d->", t->data) ;
inorder(t->right) ;
}
}
int main(){                                                            //Main Function
struct node *root ;
root = maketree();
printf("Preorder: ");
preorder(root) ;
printf("\n Postorder :");
postorder(root) ;
printf("\n Inorder");
inorder(root) ;
return 0 ;
}
