#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;	
};

void inorderRecursive(struct Node *node){
	if (node != NULL){
		inorderRecursive(node->left);
		printf("%d ",(node->data));
		inorderRecursive(node->right);				
	}
}


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

struct Node* delete(struct Node *root, int x){
	if (root == NULL)
        return NULL;

    if (x < root->data) {
        root->left = delete(root->left, x);
    } else if (x > root->data) {
        root->right = delete(root->right, x);
    } else {
		if (root -> left == NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		else{
			struct Node* temp = root->right;
			while(temp->left!=NULL)
				temp = temp->left;
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}
	return root;
}

struct Node* search(struct Node* root, int key){
	if (root == NULL) return NULL;
	if ((root)->data == key)
		return root;
	else if (root->data > key)
		return search(root->left, key);
	else if (root->data < key)
		return search(root->right, key);
	else
		return NULL;
}

struct Node* findMin(struct Node* root){
	if (root->left == NULL)
		return root;
	else 
		return findMin(root->left);
}

struct Node* findMax(struct Node* root){
	if (root->right == NULL)
		return root;
	return findMax(root->right);
}

int countNodes(struct Node* root){
	if (root == NULL)
		return 0;
	return 1+countNodes(root->left)+countNodes(root->right);
}

int findHeight(struct Node* root){
	if (root == NULL)
		return 0;
	return 1+((findHeight(root->left)>findHeight(root->right))?findHeight(root->left):findHeight(root->right));
}

int countLeafNodes(struct Node* root){
	if (root == NULL)
        return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return countLeafNodes(root->left)+countLeafNodes(root->right);
}

void freeTree(struct Node *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main()
{
	int on = 1;
	int choice;
	struct Node* root = NULL;
	int num;

	while (on) {
		num = 0;
		printf("\n--- BINARY SEARCH TREE ---\n");
		printf("1. Insert element\n");
		printf("2. Delete element\n");
		printf("3. Search element\n");
		printf("4. Count nodes\n");
		printf("5. Count leaf nodes\n");
		printf("6. Height of tree\n");
		printf("7. Find min\n");
		printf("8. Find max\n");
		printf("9. INORDER TRAVERSAL\n");
		printf("10. Quit\n");
		printf("Choice = ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: 
				printf("Enter number to insert: ");
				scanf("%d", &num);
				insert(&root, num);
				printf("Inserted %d\n", num);
				break;
			case 2: 
				printf("Enter number to delete: ");
				scanf("%d", &num);
				root = delete(root, num);
				printf("Deleted (if existed) %d\n", num);
				break;
			case 3: 
				printf("Enter number to search: ");
				scanf("%d", &num);
				struct Node* found = search(root, num);
				if (found)
					printf("Found node with data = %d\n", found->data);
				else
					printf("Value %d not found in tree.\n", num);			
				break;
			case 4:
				printf("Total nodes: %d\n", countNodes(root));
				break;
			case 5:
				printf("Leaf nodes: %d\n", countLeafNodes(root));
				break;
			case 6:
				printf("Height: %d\n", findHeight(root));
				break;
			case 7:
				if (root == NULL) printf("Tree is empty.\n"); else printf("Min: %d\n", findMin(root)->data);
				break;
			case 8:
				if (root == NULL) printf("Tree is empty.\n"); else printf("Max: %d\n", findMax(root)->data);
				break;
			case 9:
				inorderRecursive(root);
				break;
			case 10:
				freeTree(root);
				root = NULL;
				on = 0;
				break;
			default:
				printf("Invalid Choice!!\n");
				break;
		}
	}
}
