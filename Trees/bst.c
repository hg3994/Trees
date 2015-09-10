#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};

struct node* newnode(int key){
	struct node *temp;
	temp= (struct node *) malloc(sizeof(struct node));
	temp->data=key;
	temp->left=temp->right=NULL;
	return temp;
}

struct node* insert(struct node *node, int key){
	if (node==NULL)
		return newnode(key); //creation of a new node here
	if(key >node->data)
		node->right= insert(node->right,key);
	if(key< node->data)
		node->left= insert(node->left,key);
	
	return node;
}

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    
    // Key is greater than root's key
    if (root->data< key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

void traverse(struct node* node){
	if(node!=NULL){
		traverse(node->left);
		printf("%d ",node->data);
		traverse(node->right);
	}
}

struct node *delete(struct node *root, int key){
	if(root==NULL)
	    return root;
	if(root->data > key)
		root->left= delete(root->left,key);
	else if(root->data< key)
		root->right= delete(root->right,key);
	else{
		if(root->left==NULL){
			struct node *temp= (struct node *)malloc(sizeof(struct node *));
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
				struct node *temp= (struct node *)malloc(sizeof(struct node *));
				temp=root->left;
				free(root);
				return temp;
			}
			else{
				struct node *temp= (struct node *)malloc(sizeof(struct node *));
				temp=root->right;
				while(temp->left!=NULL)
					temp=temp->left;
				root->data=temp->data;
				root->right= delete(root->right,temp->data);
			}
	}
	return root;
}

void minvalue(struct node * root){
	struct node * temp;
	temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	printf("%d is the minimum value in the BST\n\n",temp->data);
}

/*void predsucc(struct node *root,struct node && pred,struct node && succ,int key){
	if (root==NULL)
		return;
	if(root->data==key){
		struct node *temp= (struct node*)malloc(sizeof(struct node *));
		
		if(root->right!=NULL){
			temp=root->right;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			succ=temp;
		}

		if(root->left!=NULL){
			temp=root->left;
			while(temp->right!=NULL){
				temp=temp->right;
			}
			pred=temp;
		}
		//printf("The value of pred is %d and succ is %d\n",pred->data,succ->data);
		return ;
	}
	if(root->data > key){
		succ=root;
		predsucc(root->left,pred,succ,key);
	}
	else{
		pred=root-;
		predsucc(root->right,pred,succ,key);
	}
}*/

int main(void){
	int i,n=1,key,first=1;
	struct node *root=NULL;
	while(n){
		printf("Enter 1 to Enter a Node in the BST\n");
		printf("Enter 2 to Search a Node in the BST\n");
		printf("Enter 3 to Traverse the BST\n");
		printf("Enter 4 to delete a node\n");
		printf("Enter 5 to know the minimum value\n");
		printf("Enter 6 to know the predecessor and successor of a node\n");
		printf("Enter 0 to EXIT!\n");
		scanf("%d",&n);
		switch(n){
			case 1: printf("Enter the value of the Node\n");
				if(first==1){
					scanf("%d",&key);
					root=insert(root,key);
					first=0;
				}
				else{
					scanf("%d",&key);
					insert(root,key);
				}
				break;
			case 2: printf("Enter the value to be searched\n");
				struct node *x;
				scanf("%d",&key);
				x=search(root,key);
				if(x==0) printf("Not Found\n");
				else printf("Found\n");
				break;
			case 3: traverse(root);
					printf("\n");
				break;
			case 4: printf("Enter the value you want to delete\n");
				scanf("%d",&key);
				root=delete(root,key);
				break;
			case 5: minvalue(root);
				break;
			/*case 6: printf("Enter the value \n");
					scanf("%d",&key);
					struct node *pred=NULL,*succ=NULL;
					predsucc(root,&pred,&succ,key);
					break;*/
		}
	}
	return 0;
}
