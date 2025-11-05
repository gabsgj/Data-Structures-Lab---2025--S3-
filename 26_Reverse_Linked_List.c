#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createNode(int x)
{
    Node *newnode = ((Node*) malloc(sizeof( Node)));
    if (newnode == NULL) {
        printf("Stack Overflow! Memory not available.\n");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void addNode(Node **head, int x)
{
    Node* node = createNode(x);
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

Node* reverseList(Node* head)
{
    Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;
    }
    return prev;
}


void display(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty!");
        return;
    }
    printf("The List: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    int on = 1;
    int choice;
    Node* head = NULL;
    while(on)
    {
        printf("\nEnter choice:\n1.Add element\n2.Reverse List\n3.Display List\n4.Quit\nChoice = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int num;
            printf("Enter number to add to list : ");
            scanf("%d", &num);
            addNode(&head, num);
            break;
        case 2:
            if (head == NULL)
            {
                printf("NULL\n");
                break;
            }
            head = reverseList(head);
            display(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            on = 0;
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    while(head!=NULL){
        Node* temp = head;
        head = temp->next;
        free(temp);
    }
}