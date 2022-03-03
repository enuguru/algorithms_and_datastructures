
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
   int data;
   struct node *next;
}NODE;

NODE *front = NULL;
NODE *rear = NULL;


int main()
{
    NODE *temp;
    void addqueue(NODE *,int,int);
    void DisplayQueue();
    void delqueue(int);
    temp = (NODE *)malloc(sizeof(NODE));
    addqueue(temp, 1, 100); 
    temp = (NODE *)malloc(sizeof(NODE));
    addqueue(temp, 0, 200); 
    temp = (NODE *)malloc(sizeof(NODE));
    addqueue(temp, 1, 22); 
    temp = (NODE *)malloc(sizeof(NODE));
    addqueue(temp, 1, 33); 
    temp = (NODE *)malloc(sizeof(NODE));
    addqueue(temp, 0, 5); 
    DisplayQueue();
    delqueue(1);
    DisplayQueue();
    delqueue(0);
    DisplayQueue();
    return 0;
}


void addqueue(NODE *local,int flag, int x)
{
    if(front == NULL && rear == NULL)
    {
        local -> next = NULL;
        local -> data = x;
        front = local;
        rear = local;
    }
    else
    {
        if(flag == 1)
        {
            rear -> next = local;
            local -> data = x;
            local -> next = NULL;
            rear = local;
        }
        else
        {
            local -> next = front;
            local -> data = x;
            front = local;
        }
     }
}

void delqueue(int flag)
{
     NODE *traceptr = front;
     NODE *temp;
     if(front == NULL && rear == NULL)
          printf("The queue is empty, enqueue some elements\n");
     else
     {
          if(flag == 1)
          {
             while(traceptr -> next != NULL)
             {
                  temp = traceptr;
                  traceptr = traceptr -> next;
             }
             free(rear);
             rear = temp;
             rear -> next = NULL;
          }
          else
          {
              temp = front;
              front = front -> next;
              free(temp);
          }
      }
} 
                  
                                    

 
void DisplayQueue()
{
     NODE *traceptr = front;
     while(traceptr != NULL)
     {
         printf(" %d ",traceptr -> data);
         traceptr = traceptr -> next;
     }
     printf("\n");
} 
