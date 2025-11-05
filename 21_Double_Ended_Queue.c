#include <stdio.h>
#define SIZE 5

int QUEUE[SIZE];
int front=-1, rear=-1;

int isFull(){
	return ((rear + 1)%SIZE == front);	
}

int isEmpty(){
	return (front==-1);
}

void insertFront(int value){
	if(isFull())
	{
		printf("THE QUEUE IS FULL!!\n");
		return;
	}
	if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    QUEUE[front] = value;
}

void insertRear(int value){
	if(isFull())
	{
		printf("THE QUEUE IS FULL!!\n");
		return;
	}
	if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    QUEUE[rear] = value;
}

int deleteFront(){
	if(isEmpty())
	{
		printf("THE QUEUE IS EMPTY!!\n");
		return;
	}
	int value = QUEUE[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return value;
}

int deleteRear(){
	if(isEmpty())
	{
		printf("THE QUEUE IS EMPTY!!\n");
		return;
	}
	int value = QUEUE[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
    return value;
}

void display(){
	if (isEmpty()){
		printf("The QUEUE is EMPTY! NOTHING to DISPLAY!!\n");
		return;
	}
	printf("DEQUE elements are : ");
	for(int i = (front)%SIZE;i != (rear+1)%SIZE; i = (i+1)%SIZE)
    {
        printf("%d ",QUEUE[i]);
    }
    printf("\n");
}

int main(){
	int a=1;
    while(a==1)
    {
        int choice = 0;
        printf("Enter Choice : \n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Quit\n\nEnter Choice : ");
        scanf("%d", &choice);
        int num;
        switch (choice)
        {
            case 1 :
                printf("Enter number to Insert at Front : ");
                scanf("%d", &num);
                insertFront(num);
                break;
            case 2 :
                printf("Enter number to Insert at Rear : ");
                scanf("%d", &num);
                insertRear(num);
                break;
            case 3 :
                printf("%d\n", deleteFront());
                break;
            case 4 : 
                printf("%d\n", deleteRear());
                break;
            case 5 :
                display();
                break;
            case 6 :
                a=0;
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
}



























/*
#include <stdio.h>

#define MAX 100

int deque[MAX] ;
int front = 0, rear = 0 ;

int isEmpty (){
    return front == rear ;
}

int isFull(){
    return ( rear + 1 ) % MAX == front ;
}

void insertRear(int value){
    if (isFull()){
        printf("Deque is full\n") ;
        return;
    }
    deque[rear = (rear + 1) % MAX] = value ;
}

void insertFront(int value){
    if(isFull()){
        printf( "Deque is full\n");
        return;
    }
    deque[front] = value ;
    front=(front-1+MAX)%MAX;
}


int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    front = (front + 1) % MAX;
    return deque[front];
}

int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = deque[rear];
    rear = (rear - 1 + MAX) % MAX;
    return value;
}

int peekFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[(front + 1) % MAX];
}

int peekRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[rear];
}
*/
