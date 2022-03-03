
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
   int data;
   struct node *next;
}NODE;

NODE *top = NULL;

int main()
{
    int count, value;
    void displaystack();
    void push(NODE *,int);
    int pop();
    NODE *temp = NULL;
    for(count = 0; count < 10; count++)
    {
       temp = (struct node *)malloc(sizeof(struct node));
       push(temp,(count+10));
    }
    displaystack();
    value = pop();
    value = pop();
    displaystack();
}


void push(struct node *local,int x)
{
      if(top == NULL)
      {
           local -> data = x;
           local -> next = NULL;
           top = local;
      }
      else
      {
          local -> data = x;
          local -> next = top;
          top = local;
      }
}
 
          
int pop()
{
    int value;
    NODE *temp;
    if(top == NULL)
        printf("\nThe stack is empty, put some elements in to the stack\n");
    else
    {
        temp = top;
        value = temp -> data;
        top = top -> next;
        free(temp);
        return value;
    }
}
 
void displaystack()
{
   NODE *traceptr = top;
   printf("\n");
   while(traceptr != NULL)
   {
      printf(" %d ", traceptr -> data);
      traceptr = traceptr -> next;
   }
   printf("\n");
}
