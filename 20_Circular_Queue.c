#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0;

int isEmpty()
{
    return front == rear;
}
int isFull()
{
    return (rear + 1)% SIZE == front;
}


void enqueue(int x){
	if (isFull())
		printf("CannotEnqueue : Queue is Full.\n");
	else
		queue[rear=(rear+1)%SIZE] = x;
}

int dequeue(){
	if (isEmpty())
		printf("CannotDequeue : Dequeue is Empty.\n");
	else
		return(queue[front=(front+1)%SIZE]);
}

void display(){
	printf("Queue elements are : ");
    if (front == rear)
    {
        printf("Queue is Empty.\n");
        return;
    }
    for(int i = (front+1)%SIZE;i != (rear+1)%SIZE; i = (i+1)%SIZE)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main()
{
    int a=1;
    while(a==1)
    {
        int choice = 0;
        printf("Enter Choice : \n1.Enqueue\n2.Dequeue\n3.Display(Quit)\n\nEnter Choice : ");
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
                printf("%d", dequeue());
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
