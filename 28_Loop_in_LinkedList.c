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

void createLoop(struct Node* head, int pos) {
    if (head == NULL)
        return;
    struct Node *temp = head, *loopNode = NULL;
    int count = 1;
    while (temp->next != NULL) {
        if (count == pos) loopNode = temp;
        temp = temp->next;
        count++;
    }
    if (loopNode != NULL)
        temp->next = loopNode;
}

int detectLoop(struct Node* head){
    struct Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow==fast)
            return 1;
    }
    return 0;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty!\n");
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
        printf("\nEnter choice:\n1.Add element\n2.Create Loop\n3.Detect Loop\n4.Quit\nChoice = ");
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
            int pos;
            printf("Enter position to loop the list to : ");
            scanf("%d", &pos);
            createLoop(head,pos);
            printf("LOOP created successfully!.\n");
            break;
        case 3:
            if (head == NULL)
            {
                printf("The list is NULL!\n");
                break;
            }
            int det = detectLoop(head);
            
            if (det==1)
                printf("LOOP EXISTS!!\n");
            else{
                display(head);
                printf("LOOP DOES NOT EXIST!!\n");
            }
            on=0;
            break;
        case 4:
            on = 0;
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    while(head!=NULL && !detectLoop(head)){
        struct Node* temp = head;
        head = temp->next;
        free(temp);
    }
}
