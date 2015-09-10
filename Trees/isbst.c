
//Check if a Binary tree is a BST or not?

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

isBST(node *root){
	return isBSTutil(root,INT_MIN,INT_MAX);
}

isBSTutil(node *root,int min,int max){
	if (root==NULL)
		return 1;
	if(root->data < min || root->data >max)
		return 0;
	return (isBSTutil(root->left,min,(root)->data-1) && isBSTutil(root->right,(root)->data+1,max));
}

node *newNode(int key){
	node *temp=(node *) malloc(sizeof(node*));
	temp->data= key;
	temp->left=temp->right=NULL;
	return temp;
}

int main(){
	struct node *root = newNode(4);
  	root->left        = newNode(2);
  	root->right       = newNode(5);
  	root->left->left  = newNode(1);
  	root->left->right = newNode(3); 
 
  	if(isBST(root))
    	printf("Is BST\n\n");
  	else
    	printf("Not a BST\n\n");
    return 0;
}