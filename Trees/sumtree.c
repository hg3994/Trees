#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int data){
	struct Node *temp= (struct Node *) malloc(sizeof(struct Node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int tosumtree(struct Node *root){
	if(root==NULL)
		return 0;
	int old_value=root->data;
	root->data=tosumtree(root->left)+tosumtree(root->right);
	return (old_value+root->data);
}

void printinorder(struct Node* root){
	if(root==NULL)
		return;
	printinorder(root->left);
	printf("%d\n",root->data);
	printinorder(root->right);
}

int main(){
 	struct Node *root = NULL;
  	int x;
 
  /* Constructing tree given in the above figure */
	root = newNode(10);
	root->left = newNode(-2);
	root->right = newNode(6);
	root->left->left = newNode(8);
	root->left->right = newNode(-4);
	root->right->left = newNode(7);
	root->right->right = newNode(5);
 
	tosumtree(root);
	printinorder(root);
	return 0;
}
