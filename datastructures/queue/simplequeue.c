
/* created by Gururajan 7-6-2020 */

/* there was a fatal error while using malloc.h, so i changed */
/* so i changed the include file to #include <stdlib.h>, and it worked */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int data;
   struct node *next;
}NODE;

NODE *front = NULL;
NODE *rear = NULL;

int main()
{
     int val;
     void printqueue();
     void enqueue(NODE *,int);
     int deque();
     int count;
     NODE *tempptr;
     for(count = 0; count < 10; count++)
     {
         tempptr = (NODE *)malloc(sizeof(NODE));
         enqueue(tempptr,(count+10));
     }
     val = deque();
     val = deque();
     printqueue();
}

void enqueue(NODE *localptr, int x)
{
     if(front == NULL && rear == NULL)
     {
        localptr->next = NULL;
        localptr->data = x;
        front = localptr;
        rear = localptr;
     }
     else
     {
        localptr->next = NULL;
        localptr->data = x;
        rear->next = localptr;
        rear = localptr;
     }
}

int deque()
{
    int value;
    NODE *localptr;
    if(front == NULL && rear == NULL)
        return -1;
    localptr = front;
    front = front->next;
    value = localptr->data;
    free(localptr);
    if(front==NULL)
       rear = NULL;
    return value;
} 
   
void printqueue()
{
     NODE *traceptr = front; 
     if(traceptr == NULL)
        return;   
     while(traceptr->next != NULL)
     {
        printf("%d \n",traceptr->data);
        traceptr = traceptr->next;
     }
}      
