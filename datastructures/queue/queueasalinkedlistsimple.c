
/*  Program that implements queue as a linked list. */

#include <stdio.h>
#include <malloc.h>
//#include <conio.h>

struct node
{
	int data ;
	struct node *next ;
};


struct node *front = NULL;
struct node *rear = NULL;
void addq(struct node *,int);
void dequeue();
void printqueue();
int searchqueue(int);



void main( )
{
	struct node *a ;
	int i,mydata,value ;
        printf("\n Please give the data for the first node\n");
        scanf("%d",&mydata);
        a = (struct node *)malloc(sizeof(struct node));
	addq ( a, mydata ) ;
        printf("\n Please give the data for the second node\n");
        scanf("%d",&mydata);
        a = (struct node *)malloc(sizeof(struct node));
	addq ( a, mydata ) ;
        a = (struct node *)malloc(sizeof(struct node));
	addq ( a, 23 ) ;
        a = (struct node *)malloc(sizeof(struct node));
	addq ( a, 19 ) ;
        a = (struct node *)malloc(sizeof(struct node));
	addq ( a, 15 ) ;
        a = (struct node *)malloc(sizeof(struct node));
	addq ( a, 16 ) ;
        a = (struct node *)malloc(sizeof(struct node));
	addq ( a, 28 ) ;
        printqueue();
        dequeue();
        printqueue();
        dequeue();
        printqueue();
	value = searchqueue(16);
        if(value == 1)
            printf("\nThe value is found\n");
}


/* adds an element to the queue */
void addq ( struct node *local, int item )
{
	struct node *traceptr;
        traceptr = local;
        if(front == NULL && rear == NULL)
        {
             local -> next = NULL;
             local -> data = item;
             front = local;
             rear = local;
        }
        else
        {
            local -> data = item;
            local -> next = NULL;
            rear -> next = local;
            rear = local;
        }
}


/* deletes an element from the queue */

void dequeue()
{
	struct node *temp;
	if(front == NULL && rear == NULL)
	    printf("\n The queue is empty,please enqueue elements to dequeue\n");
        else
        {
            temp = front;
            front = front -> next;
            free(temp);
        }
}

/* print the elements of queue */

void printqueue()
{
   struct node *traceptr = front;
   printf("\n");
   while(traceptr != NULL)
   {
      printf(" %d ",traceptr -> data);
      traceptr = traceptr -> next;
   }
   printf("\n");
}

/* To search the elements of queue */

int searchqueue(int x)
{
	struct node *traceptr = front;
	while(traceptr != NULL)
	{
	if(traceptr->data == x)
		return 1;
	traceptr = traceptr->next;
	}
		return 0;
}
