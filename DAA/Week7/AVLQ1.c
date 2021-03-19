#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *left, *right;
	int balance;
}NODE;

int max(int a, int b)
{
	return (a>b)?a:b;
}

int height(NODE* ptr)
{
	if(ptr == NULL)
		return 0;
	return max(height(ptr->left), height(ptr->right))+1;
}
NODE* rightRotate(NODE* ptr)
{
	NODE* x = ptr->left;
	NODE* T2 = ptr->right;
	x->right = ptr;
	ptr->left = T2;
	ptr->balance = max(height(ptr->left), height(ptr->right))+1;
	x->balance = max(height(x->left), height(x->right))+1;
	return x;
}

NODE* leftRotate(NODE* ptr)
{
	NODE* x = ptr->right;
	NODE* T2 = ptr->left;
	x->left = ptr;
	ptr->right = T2;
	ptr->balance = max(height(ptr->left), height(ptr->right))+1;
	x->balance = max(height(x->left), height(x->right))+1;
	return x;
}

NODE* create(NODE* bnode, int x)
{
	NODE* getnode;
	if(bnode == NULL)
	{
		bnode = (NODE*)malloc(sizeof(NODE));
		bnode->info = x;
		bnode->left = bnode->right = NULL;
		bnode->balance = 0;
	}

	else if(x>bnode->info)
	{
		bnode->balance--;
		if(bnode->balance < -1 && x > bnode->right->info) //RR Case
			bnode = leftRotate(bnode);
		if(bnode->balance > 1 && x > bnode->left->info) //LR Case
		{
			bnode->left = leftRotate(bnode->left);
			bnode = rightRotate(bnode);
		}
		bnode->right=create(bnode->right,x);
	}	
	else if(x<bnode->info)
	{
		bnode->balance++;
		if(bnode->balance > 1 && x < bnode->left->info) //LL Case
			bnode = rightRotate(bnode);
		if(bnode->balance < -1 && x < bnode->right->info) //RL Case
		{
			bnode->right = rightRotate(bnode->left);
			bnode = leftRotate(bnode);
		}
		bnode->left=create(bnode->left,x);
	}
	else
	{
		printf("Duplicate node\n");
		exit(0);
	}
	return(bnode);
}



void inorder(NODE* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("Key:%d Balance Factor:%d\n",ptr->info, ptr->balance);
		inorder(ptr->right);
	}
}

void postorder(NODE* ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("Key:%d Balance Factor:%d\n",ptr->info, ptr->balance);
	}
}

void preorder(NODE* ptr)
{
	if(ptr!=NULL)
	{
		printf("Key:%d Balance Factor:%d\n",ptr->info, ptr->balance);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

int main()
{
	int n, x, ch, i;
	NODE* root;
	root=NULL;
	while(1)
	{
		printf("1.Insert\n2.Traversals\n3.Exit\nChoice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter node: ");
					scanf("%d", &x);
					root = create(root,x);
					break;
			case 2: printf("Inorder Traversal:\n");
					inorder(root);
					printf("\nPreorder Traversal:\n");
					preorder(root);
					printf("\nPostorder Traversal:\n");
					postorder(root);
					break;
			case 3: exit(0);
		}
		printf("\n********************\n");
	}
	return 0;
}