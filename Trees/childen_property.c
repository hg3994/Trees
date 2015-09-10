/*
Check for Children Sum Property in a Binary Tree.

Given a binary tree, write a function that returns true if the tree satisfies below property.

For every node, data value must be equal to sum of data values in left and right children. Consider data value as 0 for NULL children.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

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

void check(struct node *node)
{
	if(node==NULL) 
		return;
	if(node->left!= NULL && node->right!=NULL){
		if((node->data)==(node->left->data)+(node->right->data))
		{
			check(node->left);
			check(node->right);
		}
		else
		{
			printf("Not a ChildrenSum Binary Tree\n");
			exit(0);
		}
	}
}

int main(void)
{
	struct node *root = newNode(10);
	root->left        = newNode(4);
	root->right       = newNode(6);
	//root->left->left  = newNode(4);
	root->left->right = newNode(3);
	//root->right->right = newNode(2);
	root->right->left = newNode(6);
	check(root);
	printf("It's a Children Sum Binary Tree\n");
}
