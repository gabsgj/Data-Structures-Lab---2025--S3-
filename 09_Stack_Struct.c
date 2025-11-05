#include <stdio.h>
	
#define SIZE 20

typedef struct Stack{
	int top;
	int arr[SIZE];
}Stack;

void initialize(Stack *s){
	s->top = -1;
}

int isFull(Stack *s){
	return (s->top==SIZE-1);
}

int isEmpty(Stack *s){
	return (s->top==-1);
}

void push(Stack *s, int x){
	if (isFull(s))
		printf("CannotPush : Stack is Full.\n");
	else
		s->arr[++(s->top)] = x;
}

int pop(Stack *s){
	if (isEmpty(s))
		printf("CannotPop : Stack is Empty.\n");
	else
		return(s->arr[(s->top)--]);
	
}

int peek(Stack *s){
	return(s->arr[s->top]);
}


int main()
{
	int choice;
	Stack stack;
	int on=1;
	initialize(&stack);
	while(on)
	{
		printf("\n\n1. Push\n2. Pop\n3. Peek\n4. Quit\nEnter Choice(1-4) : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 : 
				int num;
				printf("Enter element to Push : ");
				scanf("%d",&num);
				push(&stack,num);
				break;
			case 2 :
				printf("%d\n",pop(&stack));
				break;
			case 3 :
				printf("%d\n",peek(&stack));
				break;
			case 4 :
				on=0;
				break;
			default: 
				printf("Invalid Choice!!\n\n");
		}
	}
}
