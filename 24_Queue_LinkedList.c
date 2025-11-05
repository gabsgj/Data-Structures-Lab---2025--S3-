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
        printf("Queue Overflow! Memory not available.\n");
        exit(1);
    }
    return newnode;
}

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node* new = createNode();
    new->data = x;
    new->next = NULL;
    if (rear == NULL) {
        front = rear = new;
    } else {
        rear->next = new;
        rear = new;
    }
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is Empty!");
        return -1;
    }
    struct node* temp = front;
    int val = temp->data;
    front = temp->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return val;
}

int peek()
{
    if (front == NULL)
    {
        printf("Queue is Empty!");
        return -1;
    }
    return front->data;
}

void display()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("Stack is Empty!");
        return;
    }
    printf("The Queue: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    int a=1;
    while(a==1)
    {
        int choice = 0;
        printf("\nEnter Choice : \n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Quit\n\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1 :
                int num;
                printf("Enter number to Enqueue : ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2 :
                printf("%d\n", dequeue());
                break;
            case 3 : 
                display();
                break;
            case 4 :
                printf("%d\n",peek());
                break;
            case 5 :
                a=0;
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
