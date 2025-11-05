#include <stdio.h>
#define SIZE 25

typedef struct {
    int top;
    int value[SIZE];
}stack;
stack stack1, stack2;

void initialize()
{
    stack1.top = -1;
    stack2.top = -1;
}

int isEmpty()
{
    return stack1.top==-1 && stack2.top==-1;
}

int isFull()
{
    return (stack1.top+stack2.top+2==SIZE);
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("The QUEUE is FULL.\n");
        return;
    }
    stack1.value[++stack1.top] = value;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("The QUEUE is EMPTY.\n");
        return -1;
    }
    if (stack2.top == -1)
        while(stack1.top != -1)
        {
            stack2.value[++stack2.top] = stack1.value[stack1.top--];
        }
    return stack2.value[stack2.top--];
}

void display(){
	printf("Queue elements are : ");
    if (isEmpty())
    {
        printf("Queue is Empty.\n");
        return;
    }
    if (stack2.top != -1)
        for(int i = (stack2.top) ; i >= 0 ; i--)
        {
            printf("%d ",stack2.value[i]);
        }
    for(int i = 0 ; i <= stack1.top ; i++)
    {
        printf("%d ",stack1.value[i]);
    }

    printf("\n");
}

int main()
{
    initialize();
    int a=1;
    while(a==1)
    {
        int choice = 0;
        printf("\nEnter Choice : \n1.Enqueue\n2.Dequeue\n3.Display(Quit)\n\nEnter Choice : ");
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
                a=0;
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
}