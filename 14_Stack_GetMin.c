#include <stdio.h>
#define SIZE 20

typedef struct Stack {
    int top;
    int arr[SIZE];
    int minElement;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return (s->top == SIZE - 1);
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Cannot Push: Stack is Full.\n");
        return;
    }

    if (isEmpty(s)) {
        s->arr[++(s->top)] = x;
        s->minElement = x;
    } else if (x >= s->minElement) {
        s->arr[++(s->top)] = x;
    } else {

        int encoded = 2 * x - s->minElement;
        s->arr[++(s->top)] = encoded;
        s->minElement = x;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Cannot Pop: Stack is Empty.\n");
        return -1;
    }

    int topVal = s->arr[s->top--];
    if (topVal >= s->minElement) {
        return topVal;
    } else {

        int realValue = s->minElement;
        s->minElement = 2 * s->minElement - topVal;
        return realValue;
    }
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
        return -1;
    }

    int topVal = s->arr[s->top];
    if (topVal >= s->minElement) {
        return topVal;
    } else {
        return s->minElement;
    }
}

int getMin(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty. No Min.\n");
        return -1;
    }
    return s->minElement;
}

int main() {
    Stack stack;
    int choice;
    int on = 1;

    initialize(&stack);

    while (on) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Get Min\n5. Quit\nEnter Choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num;
                printf("Enter element to Push: ");
                scanf("%d", &num);
                push(&stack, num);
                break;
            }
            case 2:
                printf("Popped: %d\n", pop(&stack));
                break;
            case 3:
                printf("Top Element: %d\n", peek(&stack));
                break;
            case 4:
                printf("Minimum Element: %d\n", getMin(&stack));
                break;
            case 5:
                on = 0;
                break;
            default:
                printf("Invalid Choice!!\n");
        }
    }

    return 0;
}

