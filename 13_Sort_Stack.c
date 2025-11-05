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
	Stack temp;
	int on=1;
	initialize(&stack);
	initialize(&temp);
	printf("Enter the original Stack : \n");
	while(1)
	{	
		int num;
		printf("Enter element to Push(0 to STOP) : ");
		scanf("%d",&num);
		if (num == 0)
			break;
		push(&stack,num);
	}
	printf("\n\n\n");
	
	
	while(!isEmpty(&stack))
	{
		int t = pop(&stack);
		while(!isEmpty(&temp) && peek(&temp) > t)
		{
			push(&stack,pop(&temp));			
		}
		push(&temp, t);
	}
	
	while(!isEmpty(&temp))
	{
		push(&stack, pop(&temp));
	}
	
	printf("The final Sorted Stack : \n");
	while(!isEmpty(&stack))
	{
		printf("%d ",pop(&stack));
	}
	printf("\n");
}
