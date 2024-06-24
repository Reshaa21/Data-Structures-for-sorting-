#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 


struct Stack {
    int items[MAX_SIZE];
    int top;
};


void initialize(struct Stack *s) {
    s->top = -1; 
}


int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow: Cannot push element %d, stack is full.\n", value);
        return;
    }
    s->items[++s->top] = value; 
    printf("%d pushed to stack\n", value);
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1; 
    }
    return s->items[s->top--]; 
}
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1; 
    }
    return s->items[s->top];
}
void printStack(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; ++i) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack); 
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    
    printStack(&stack);
    
    printf("Top element: %d\n", peek(&stack));
    
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    
    printStack(&stack);
    
    return 0;
}

