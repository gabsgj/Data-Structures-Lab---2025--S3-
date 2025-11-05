#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
	
#define SIZE 25

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
	if (isEmpty(s)){
		printf("CannotPop : Stack is Empty.\n");
		return '\0';
	}
	else
		return(s->arr[(s->top)--]);
	
}

char peek(Stack *s){
	return(s->arr[s->top]);
}

int precedence(char op){
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0; 
}

void infixToPostfix(char* infix, char* postfix){

    Stack s;
	initialize(&s);

    while(*infix!='\0')
	{
        if (isalnum(*infix))
        {
            (*postfix++)=*infix;
        }else if(*infix == '('){
            push(&s, *infix);
        }else if(*infix == ')'){
        	while (!isEmpty(&s) && peek(&s) != '(') {
        		*postfix++ = pop(&s);
    		}
    		if (!isEmpty(&s))
		        pop(&s);
    		else {
    		    printf("Error: Mismatched parentheses\n");
    		    return; 
    		}
        }else if((*infix == '+') || (*infix == '-') || (*infix == '*') || (*infix == '/') || (*infix == '^')){
            if ((*infix)=='^') {
                while (!isEmpty(&s) && precedence(peek(&s)) > precedence(*infix)) {
                    *postfix++ = pop(&s);
                }
            } else {
                while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(*infix)) {
                    *postfix++ = pop(&s);
                }
            }
            push(&s, *infix);
        }
        
        infix++;
    }
    
    
    while (!isEmpty(&s)) {
    *postfix++ = pop(&s);
    }
    *postfix = '\0';
}

int main()
{	
	char expression[25];
    char postfix[25];
	printf("Enter the infix expression : \n");
	scanf("%25s",expression);

	infixToPostfix(expression, postfix);
	while(getchar()!='\n');
	printf("Final Postfix Expression = \n%s\n",postfix);
}
