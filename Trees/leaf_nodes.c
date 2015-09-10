//Program to count leaf nodes in a binary tree

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int c=0;

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

count_leaf(struct node* node)
{

	if(node->left ==NULL && node->right==NULL)
	{
		c++;
	}
	else
	{
		count_leaf(node->left);
		count_leaf(node->right);
	}
}
int main(void)
{
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(5);
	root->right->left = newNode(5);
	count_leaf(root);
	printf("%d \n",c);
}
