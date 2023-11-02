#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

void push(struct Queue* queue, int x) {
    int s = queue->size;
    enqueue(queue, x);

    for (int i = 0; i < s; i++) {
        int temp = dequeue(queue);
        enqueue(queue, temp);
    }
}

void pop(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Stack is Empty\n");
        return;
    }
  
    printf("Popped element: %d\n", dequeue(queue));
}

int top(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
  
    return front(queue);
}

int main() {
    struct Queue* queue = createQueue(100);
  
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
  
    printf("Top element is %d\n", top(queue));
    pop(queue);
    printf("Top element is %d\n", top(queue));
    pop(queue);
    printf("Top element is %d\n", top(queue));
    pop(queue);
    pop(queue);  // This should print "Stack is Empty"
  
    return 0;
}
