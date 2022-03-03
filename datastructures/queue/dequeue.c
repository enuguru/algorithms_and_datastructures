
typedef struct node
{
   int data;
   struct node *next;
}NODE;

NODE *front = NULL;
NODE *rear = NULL;

void enqueue(NODE *temp,int x)
{
       if(front == NULL && rear == NULL)
       {
             temp->data = x;
             temp->next = NULL;
             front = temp;
             rear = front;
             return;
       }
       temp->data = x;
       rear->next = temp;
       temp->next = NULL;
       rear = temp;
}
   
     
int dequeue()
{
       NODE *temp = (NODE *)malloc(sizeof(NODE));
       int x;
       if(front == rear == NULL)
       {
             printf("the queue is empty\n");
             return 0;
       }
       if((front = rear) && front->next == NULL)
       {
             x = front->data;
             temp = front;
             front = front ->next;
             free(temp);
             rear = NULL;:q

             return x;
       }
        x = front->data;
        temp = front;
       	front = front ->next;
        free(temp);
        return x;
}
