#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char* word;
	char* meaning;
	struct Node *left;
	struct Node *right;	
};

struct Node* createNode(char* word, char* meaning)
{
    struct Node *newnode = ((struct Node*) malloc(sizeof(struct Node)));

    if (newnode == NULL) {
        printf("Tree Overflow! Memory not available.\n");
        exit(1);
    }
    newnode->word=strdup(word);
	newnode->meaning=strdup(meaning);
	newnode->left = NULL;
	newnode->right = NULL;    
    return newnode;
}

struct Node* insert(struct Node **root, char* word, char* meaning){
	if (*root == NULL)
	{
		return *root = createNode(word, meaning);
	}
	else
	{
		if (strcmp(((*root)->word) , word)>0)
			return insert(&((*root)->left), word, meaning);
		else
			return insert(&((*root)->right), word, meaning);
	}
}

struct Node* deleteNode(struct Node *root, char* word){
	if (root == NULL)
        return NULL;

    if (strcmp(word , (root->word))<0) {
        root->left = deleteNode(root->left, word);
    } else if (strcmp(word , (root->word))>0) {
        root->right = deleteNode(root->right, word);
    } else {
		if (root -> left == NULL){
			struct Node* temp = root->right;
            free(root->word);
            free(root->meaning); 
			free(root);
			return temp;
		}
		else if (root->right == NULL){
			struct Node* temp = root->left;
            free(root->word);
            free(root->meaning); 
			free(root);
			return temp;
		}
		else{
			struct Node* temp = root->right;
			while(temp->left!=NULL)
				temp = temp->left;
			root->word = temp->word;
			root->meaning = temp->meaning;
			root->right = deleteNode(root->right, temp->word);
		}
	}
	return root;
}

struct Node* search(struct Node* root, char* key){
	if (root == NULL) return NULL;
	if (strcmp(((root)->word),key)==0)
		return root;
	else if (strcmp(((root)->word), key)<0)
		return search(root->right, key);
	else if (strcmp(((root)->word), key)>0)
		return search(root->left, key);
	else
		return NULL;
}


void updateMeaning(struct Node* root, char* word, char* newMeaning){
    if (root == NULL) return;
	if (strcmp(((root)->word),word)>0)
		updateMeaning(root->left, word, newMeaning);
	else if (strcmp(((root)->word), word)<0)
		updateMeaning(root->right, word, newMeaning);
	else{
		free(root->meaning); root->meaning = strdup(newMeaning);
	}
}

void inorderTraversal(struct Node* root){
	if (root != NULL){
		inorderTraversal(root->left);
		printf("%s : %s\n", root->word, root->meaning);
		inorderTraversal(root->right);				
	}
}


void freeTree(struct Node *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node->word);
        free(node->meaning);
        free(node);
    }
}

int main()
{
	int on = 1;
	int choice;
	struct Node* root = NULL;
	char *word = malloc(sizeof(char)*50);
	char *meaning = malloc(sizeof(char)*50);

	while (on) {
		printf("\n--- DICTIONARY ---\n");
		printf("1. Insert WORD\n");
		printf("2. Delete WORD\n");
		printf("3. Search WORD\n");
		printf("4. Update meaning\n");
		printf("5. Inorder Traversal\n");
		printf("6. Quit\n");
		printf("Choice = ");
		scanf("%d", &choice);
        while(getchar()!='\n');
		switch (choice) {
			case 1: 
				printf("Enter word to insert: ");
				scanf("%[^\n]", word);
                while(getchar()!='\n');
                printf("Enter meaning of word: ");
				scanf("%[^\n]", meaning);
                while(getchar()!='\n');
				insert(&root, word, meaning);
				printf("Inserted %s\n", word);
				break;
			case 2: 
				printf("Enter word to delete: ");
				scanf("%[^\n]", word);
                while(getchar()!='\n');
				root = deleteNode(root, word);
				printf("Deleted (if existed) %s\n", word);
				break;
			case 3: 
				printf("Enter word to search: ");
				scanf("%[^\n]", word);
                while(getchar()!='\n');
				struct Node* found = search(root, word);
				if (found)
					printf("Found node with data = %s\nMeaning = %s\n", (found->word), (found->meaning));
				else
					printf("Value %s not found in tree.\n", word);			
				break;
			case 4:
				printf("Enter word to update meaning: ");
				scanf("%[^\n]", word);
                while(getchar()!='\n');
                printf("Enter new meaning of word: ");
				scanf("%[^\n]", meaning);
                while(getchar()!='\n');
				updateMeaning(root, word, meaning);
				printf("Updated %s meaning.\nNew Meaning: %s\n", word, meaning);
				break;
			case 5:
                inorderTraversal(root);
				break;
			case 6:
				freeTree(root);
				root = NULL;
				on = 0;
				break;
			default:
				printf("Invalid Choice!!\n");
				break;
		}
	}
    free(word);
    free(meaning);
}
