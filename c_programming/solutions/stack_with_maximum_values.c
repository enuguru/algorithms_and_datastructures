#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    int max;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int isFull(Stack* stack) {
    return stack->size == MAX_SIZE;
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->max = isEmpty(stack) ? data : (data > stack->top->max ? data : stack->top->max);
    newNode->next = stack->top;

    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return INT_MIN;
    }

    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    stack->size--;

    free(temp);
    return popped;
}

int getMax(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->top->max;
}

void printStackAndMax(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    Node* temp = stack->top;
    while (temp != NULL) {
        printf("Value: %d, Max: %d\n", temp->data, temp->max);
        temp = temp->next;
    }
}

int main() {
    Stack* stack = createStack();

    push(stack, 3);
    push(stack, 5);
    push(stack, 2);
    push(stack, 1);
    push(stack, 4);

    printStackAndMax(stack);

    return 0;
}
