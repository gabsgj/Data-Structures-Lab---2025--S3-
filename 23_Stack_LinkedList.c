#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* createNode()
{
    struct node* newnode = ((struct node*) malloc(sizeof(struct node)));
    if (newnode == NULL) {
        printf("Stack Overflow! Memory not available.\n");
        exit(1);
    }
    return newnode;
}

struct node* top = NULL;

void push(int x)
{
    struct node* new = createNode();
    new->data = x;
    new->next = top;
    top = new;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is Empty!");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = temp->next;
    free(temp);
    return val;
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack is Empty!");
        return -1;
    }
    return top->data;
}

void display()
{
    struct node* temp = top;
    if (top == NULL)
    {
        printf("Stack is Empty!");
        return;
    }
    printf("The Stack: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
	int choice;
	int on=1;
	while(on)
	{
		printf("\n\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. QUIT\nEnter Choice(1-4) : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 : 
				int num;
				printf("Enter element to Push : ");
				scanf("%d",&num);
				push(num);
				break;
			case 2 :
				printf("%d\n",pop());
				break;
			case 3 :
				display();
				break;
			case 4 :
				printf("%d\n",peek());
                break;
            case 5 :
				on=0;
				break;
			default: 
				printf("Invalid Choice!!\n\n");
		}
	}
}

















// void addNode(struct node *head, struct node *node, int x)
// {
//     node->data = x;
//     node->next = NULL;
//     if (head == NULL)
//     {
//         head = node;
//         return;
//     }
//     struct node *temp = head;
//     while(temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = node;
// }
