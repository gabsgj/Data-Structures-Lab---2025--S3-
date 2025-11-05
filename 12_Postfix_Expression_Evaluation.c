#include <stdio.h>
	
#define SIZE 20

typedef struct Stack{
	int top;
	double arr[SIZE];
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

void push(Stack *s, double x){
	if (isFull(s))
		printf("CannotPush : Stack is Full.\n");
	else
		s->arr[++(s->top)] = x;
}

double pop(Stack *s){
	if (isEmpty(s))
		printf("CannotPop : Stack is Empty.\n");
	else
		return(s->arr[(s->top)--]);
	
}

double peek(Stack *s){
	return(s->arr[s->top]);
}



int main()
{	
	Stack operands;
	initialize(&operands);
	char expression[25];
	printf("Enter the postfix expression : \n");
	scanf("%[^\n]",expression);
	char *ptr = expression;
	while(*ptr!='\0')
	{
		double result;
		if ((*ptr == '+') || (*ptr == '-') || (*ptr == '*') || (*ptr == '/'))
		{
			double op2 = pop(&operands);
			double op1 = pop(&operands);
			
			switch(*ptr)
			{
				case '+':
					result = op1 + op2;
					break;
				case '-':
					result = op1 - op2;					
					break;
				case '*':
					result = op1 * op2;				
					break;
				case '/':
					result = op1 / op2;
					break;
			}
			push(&operands,result);
			
		}else{
 			push(&operands, (double)(*ptr - '0'));
		}
		ptr++;
	}
	printf("Final Result = %lf\n\n",peek(&operands));
}
