#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int key; 
    struct node *left;
    struct node *right; 
}; 
 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
 
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    if(key == node->key)
        printf("Duplicate entry. Please try again!\n");
    /* Otherwise, recur down the tree */
    else if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

//traversals
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 

void preorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d \n", root->key);
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

void postorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d \n", root->key); 
    } 
} 

//driver function
int main() 
{ 
    struct node *root = NULL;
    int key, choice; 
    printf("Insert root: ");
    scanf(" %d", &key);
    root = insert(root, key); 
    do{
        printf("1.Insert\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n");
        scanf(" %d", &choice);
        switch(choice)
        {
            case 1: printf("Enter key:");
                    scanf(" %d", &key);
                    insert(root, key);
                    break; 
            
            case 2: printf("\nPreorder Traversal:\n");
                    preorder(root);
                    break;
            
            case 3: printf("Inorder Traversal:\n");
                    inorder(root);
                    break;

            case 4: printf("\nPostorder Traversal:\n");
                    postorder(root);
                    break;
        }
    }while(choice < 5 && choice > 0);   
    return 0; 
} 