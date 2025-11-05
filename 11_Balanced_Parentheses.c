#include <stdio.h>
	
#define SIZE 20

typedef struct Stack{
	int top;
	char arr[SIZE];
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

void push(Stack *s, char x){
	if (isFull(s))
		printf("CannotPush : Stack is Full.\n");
	else
		s->arr[++(s->top)] = x;
}

char pop(Stack *s){
	if (isEmpty(s))
		printf("CannotPop : Stack is Empty.\n");
	else
		return(s->arr[(s->top)--]);
	
}

char peek(Stack *s){
	return(s->arr[s->top]);
}

int isMatchingPair(char open, char close){
	return ((open=='{' && close =='}') || (open=='(' && close ==')')|| (open=='[' && close ==']'));
	
}

int isBalanced(char *expr){
	Stack s;
	initialize(&s);
	char *ptr = expr;
	while(*ptr!='\0')
	{
		
		if ((*ptr == '(') || (*ptr == '{') || (*ptr == '['))
		{
			push(&s,*ptr);
			
		}else{
 			if(isEmpty(&s) || !isMatchingPair(peek(&s),*ptr))
 			{
 				return 0;
 			}else{
				pop(&s);
 			}
		}
		ptr++;
	}
	
	return (isEmpty(&s));
}

int main()
{
	char expression[25];
	printf("Enter the expression : \n");
	scanf("%[^\n]",expression);
	if(isBalanced(expression))
 	{
 		printf("THE GIVEN EXPRESSION IS BALANCED!\n\n");
 	}else{
 		printf("THE GIVEN EXPRESSION IS NOT BALANCED!\n\n");
 	}
	
}
