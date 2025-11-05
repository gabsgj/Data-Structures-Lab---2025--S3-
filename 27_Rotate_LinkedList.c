#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int x)
{
    struct Node* newNode = ((struct Node*) malloc(sizeof(struct Node)));
    if (newNode == NULL) {
        printf("List Overflow! Memory not available.\n");
        exit(1);
    }
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

void addNode(struct Node **head, int x)
{
    struct Node* Node = createNode(x);
    if (*head == NULL)
    {
        *head = Node;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = Node;
}

struct Node* rotate(struct Node* head, int k){
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    int n=1;
    struct Node *len = head;
    while( len->next != NULL){
        len = len->next;
        n++;
    }
    k=k%n;
    if (k==0)
        return head;
    
    struct Node *newHead, *newTail = head;
    for (int i = 0; i < k-1;i++){
        newTail = newTail->next;
    }

    newHead = newTail->next;
    len->next = head;
    newTail->next = NULL;
    return newHead;
}

void display(struct Node *head)
{
    struct Node *temp = head;
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
    struct Node* head = NULL;
    while(on)
    {
        printf("\nEnter choice:\n1.Add element\n2.Rotate List\n3.Display List\n4.Quit\nChoice = ");
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
            int k;
            printf("Enter number of positions to rotate to (left) : ");
            scanf("%d", &k);
            head = rotate(head,k);
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
        struct Node* temp = head;
        head = temp->next;
        free(temp);
    }
}