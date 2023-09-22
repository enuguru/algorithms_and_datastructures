#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YES "YES"
#define NO "NO"

typedef struct Stack {
    int top;
    unsigned capacity;
    char* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) return '-';
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    if (isEmpty(stack)) return '-';
    return stack->array[stack->top];
}

int isMatchingPair(char character1, char character2) {
    return (character1 == '(' && character2 == ')') || 
           (character1 == '{' && character2 == '}') || 
           (character1 == '[' && character2 == ']');
}

char* areBracesBalanced(char* expr) {
    int length = strlen(expr);
    Stack* stack = createStack(length);
    
    for (int i = 0; i < length; i++) {
        if (expr[i] == '{' || expr[i] == '(' || expr[i] == '[') {
            push(stack, expr[i]);
        } else if (expr[i] == '}' || expr[i] == ')' || expr[i] == ']') {
            if (isEmpty(stack) || !isMatchingPair(peek(stack), expr[i])) {
                return NO;
            } else {
                pop(stack);
            }
        }
    }
    
    if (isEmpty(stack)) {
        free(stack->array);
        free(stack);
        return YES;
    } else {
        free(stack->array);
        free(stack);
        return NO;
    }
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char inputStrings[n][100];
    printf("Enter the strings of braces:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", inputStrings[i]);
        char* result = areBracesBalanced(inputStrings[i]);
        printf("%s\n", result);
    }
    return 0;
}
