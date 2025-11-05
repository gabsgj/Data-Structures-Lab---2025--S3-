#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* createNode(int x)
{
    struct node* newnode = ((struct node*) malloc(sizeof(struct node)));
    if (newnode == NULL) {
        printf("Stack Overflow! Memory not available.\n");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

struct node* head = NULL;

void addNode(int x)
{
    struct node* node = createNode(x);
    if (head == NULL)
    {
        head = node;
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

int middleNode()
{
    struct node *slow = head, *fast=head;
    while(fast!=NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;;
}

void display()
{
    struct node *temp = head;
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
    while(on)
    {
        printf("\nEnter choice:\n1.Add element\n2.Find Middle\n3.Display List\n4.Quit\nChoice = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int num;
            printf("Enter number to add to list : ");
            scanf("%d", &num);
            addNode(num);
            break;
        case 2:
            if (head == NULL)
            {
                printf("List is Empty!\n");
                break;
            }
            printf("Middle elemenet : %d\n", middleNode());
            break;
        case 3:
            display();
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
        struct node* temp = head;
        head = temp->next;
        free(temp);
    }
}