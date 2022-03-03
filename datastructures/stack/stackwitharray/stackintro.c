
#define MAX 10    // macro definition or macro substitution
#include <stdio.h>

int stack[MAX];
int top = -1;

int main()
{
    int count;
    int p;
    void push(int);
    void print();
    int pop();
    for(count = 0; count < 10; count++)
    {
        push(count+1);
    }
/*    p = pop();
    p = pop();
    p = pop();
    p = pop();
*/
    print();

    return 0;
}

void push(int x)
{
    int count;
    if(top == (MAX-1))
    {
        printf("\n The array is full\n");
        return;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}


int pop()
{
    int temp;
    if( (top == -1))
    {
        printf("\n The stack is empty\n");
    }
    else
    {
        temp = stack[top];
        top--;
        return temp;
    }
}


void print()
{
    int count;
    for(count = 0; count<=(top); count++)
    {
        printf(" \n%d",stack[count]);
    }
    printf("\n");
}



