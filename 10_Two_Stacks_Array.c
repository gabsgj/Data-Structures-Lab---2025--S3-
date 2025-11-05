#include <stdio.h>
	
#define SIZE 20

int arrstack[SIZE];
int top1,top2;


int isFull(){
	return (top1+1==top2);
}

int isEmpty1(){
	return (top1==-1);
}

int isEmpty2(){
	return (top2==SIZE);
}

void push1(int x){
	if (isFull())
		printf("CannotPush : Stack is Full.\n");
	else
		arrstack[++(top1)] = x;
}


void push2(int x){
	if (isFull())
		printf("CannotPush : Stack is Full.\n");
	else
		arrstack[--(top2)] = x;
}


int pop1(){
	if (isEmpty1())
		printf("CannotPop : Stack is Empty.\n");
	else
		return(arrstack[(top1)--]);
}


int pop2(){
	if (isEmpty2())
		printf("CannotPop : Stack is Empty.\n");
	else
		return(arrstack[(top2)++]);
}

int main()
{
	int choice;
	int on=1;

	while(on)
	{
		printf("\n\n1. Push Stack 1\n2. Push Stack 2\n3. Pop Stack 1\n4. Pop Stack 2\n5. Quit\nEnter Choice(1-5) : ");
		scanf("%d",&choice);
		int num;
		switch(choice)
		{
			case 1 : 
				
				printf("Enter element to Push : ");
				scanf("%d",&num);
				push1(num);
				break;
			case 2 :
				
				printf("Enter element to Push : ");
				scanf("%d",&num);
				push2(num);
				break;
				
			case 3 :
				printf("%d\n",pop1());
				break;
				
			case 4 :
				printf("%d\n",pop2());
				break;
	
			case 5 :
				on=0;
				break;
			default: 
				printf("Invalid Choice!!\n\n");
		}
	}
}
