#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int a[10];
int top=-1;
void push(int *a,int data)
{
	top++;
	a[top]=data;
}

void pop(int *a)
{
	a[top]='\0';
	top--;
}

void display(int *a)
{
	int i;
	for(i=0;i<=top;i++)
		printf("%d  ",a[i]);
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

void ancestor(struct node* node,int k)
{
	if(node==NULL)
		return;
	if(node->data==k)
	{
		push(a,node->data);
		display(a);
	}
	else
	{
		push(a,node->data);
		ancestor(node->left,k);
		ancestor(node->right,k);
		pop(a);
	}
		
}
/* Driver program to test above functions*/
int main()
{ int k;
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(7);
 
  printf("Enter the value of node \n");
  scanf("%d",&k);
  ancestor(root,k);
  if(top==-1)
	printf("Not Found\n");
 

  return 0;
}
