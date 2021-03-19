#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 

struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
}

int inorder(struct node *root)
{
	static int count = 0;
	struct node *temp = root;
	if(temp != NULL)
	{
		inorder(temp->left);
		count++;
		inorder(temp->right);
	}
	return count;
}

int main()
{
	struct node *root = newNode(1); 
  	root->left        = newNode(2); 
  	root->right       = newNode(3); 
  	root->left->left  = newNode(4); 
  	root->left->right = newNode(5); 
  	root->left->right->left = newNode(7); 
  	root->left->right->right = newNode(8); 
  	root->right->right = newNode(6);
  	root->right->right->right = newNode(9);
  	root->right->right->right->right = newNode(11);
  	root->right->right->right->left = newNode(10);
  	root->right->right->right->left->left = newNode(12);
  	root->right->right->right->left->right = newNode(13);

  	int c = inorder(root);
  	printf("The number of nodes are: %d\n", c);
  	return 0;
}