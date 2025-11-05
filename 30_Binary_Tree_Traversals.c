#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;	
};

struct Node* createNode(int x)
{
    struct Node *newnode = ((struct Node*) malloc(sizeof(struct Node)));
    if (newnode == NULL) {
        printf("Tree Overflow! Memory not available.\n");
        exit(1);
    }
    newnode->data=x;
	newnode->left = NULL;
	newnode->right = NULL;    
    return newnode;
}

struct Node* insert(struct Node **root, int x){
	if (*root == NULL)
	{
		return *root = createNode(x);
	}
	else
	{
		if (((*root)->data) > x)
			return insert(&((*root)->left), x);
		else
			return insert(&((*root)->right), x);
	}
}



void inorderRecursive(struct Node *node){
	if (node != NULL){
		inorderRecursive(node->left);
		printf("%d ",(node->data));
		inorderRecursive(node->right);				
	}
}

void preorderRecursive(struct Node *node){
	if (node != NULL){
		printf("%d ",(node->data));
		preorderRecursive(node->left);
		preorderRecursive(node->right);				
	}
}

void postorderRecursive(struct Node *node){
	if (node != NULL){
		postorderRecursive(node->left);
		postorderRecursive(node->right);
		printf("%d ",(node->data));
						
	}
}


void inorderIterative(struct Node *node){
	struct Node* stack[100];
	int top = -1;
	struct Node *pointer = node;
	while(pointer != NULL || top!=-1)
	{
		while(pointer != NULL)
		{	
			stack[++top] = pointer;
			pointer = pointer->left;
		}
		pointer = stack[top--];
		printf("%d ", pointer->data);
		pointer = pointer->right;
	}
}


void preorderIterative(struct Node *node){
	struct Node* stack[100];
	int top = -1;
	struct Node *pointer = node;
	while(pointer != NULL || top!=-1)
	{
		
		while(pointer != NULL)
		{	
			printf("%d ", pointer->data);
			stack[++top] = pointer;
			pointer = pointer->left;
		}
		pointer = stack[top--];
		pointer = pointer->right;
	}
}

void postorderIterative(struct Node* root){
	struct Node* stack1[100], *stack2[100];
	int top1=-1, top2=-1;
	stack1[++top1] = root;
	while(top1!=-1){
		struct Node* node = stack1[top1--];
		stack2[++top2] = node;
		if (((node)->left)!=NULL)
			stack1[++top1]=node->left;
		if ((node->right)!=NULL)
			stack1[++top1]=node->right;
	}
	while(top2 !=-1)
		printf("%d ",(stack2[top2--])->data);
}



void freeTree(struct Node *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}




int main ()
{
	struct Node *head = NULL;
	printf("[TREE TRAVERSAL]\n");
	printf("Create your BINARY TREE:\n");
	while (1)
	{
		int x;
		printf("Enter Node to insert to tree (0 to STOP): ");
		scanf("%d", &x);
		if (x == 0)
			break;		
		insert(&head, x);
	}
	printf("BINARY TREE CREATED!\n");
	while(getchar()!='\n');
	printf("\nINORDER RECURSIVE TRAVERSAL : \n");
	inorderRecursive(head);
	
	printf("\nPREORDER RECURSIVE TRAVERSAL : \n");
	preorderRecursive(head);
	
	printf("\nPOSTORDER RECURSIVE TRAVERSAL : \n");
	postorderRecursive(head);
	printf("\n");
	printf("\nINORDER ITERATIVE TRAVERSAL : \n");
	inorderIterative(head);
	
	printf("\nPREORDER ITERATIVE TRAVERSAL : \n");
	preorderIterative(head);
	
	printf("\nPOSTORDER ITERATIVE TRAVERSAL : \n");
	postorderIterative(head);
	printf("\n");
	freeTree(head);	
}
