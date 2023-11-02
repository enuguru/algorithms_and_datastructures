#include <stdio.h>
#include <stdlib.h>

struct Stack {
    unsigned capacity;
    int top;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

void enqueue(struct Stack* s1, struct Stack* s2, int x) {
    push(s1, x);
}

void dequeue(struct Stack* s1, struct Stack* s2) {
    if (isEmpty(s1) && isEmpty(s2)) {
        printf("Queue is Empty\n");
        return;
    }
  
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }
  
    printf("Dequeued element: %d\n", pop(s2));
}

int main() {
    struct Stack* s1 = createStack(100);
    struct Stack* s2 = createStack(100);
  
    enqueue(s1, s2, 1);
    enqueue(s1, s2, 2);
    enqueue(s1, s2, 3);
  
    dequeue(s1, s2);
    dequeue(s1, s2);
    dequeue(s1, s2);
    dequeue(s1, s2);  // This should print "Queue is Empty"
  
    return 0;
}
