
/* Program that implements queue as a linked list. */

#include <stdio.h>
#include <malloc.h>

struct node
{
	int data ;
	struct node *link ;
} ;

struct queue
{
	struct node *front ;
	struct node *rear ;
} ;

void initqueue ( struct queue * ) ;
void addq ( struct queue *, int ) ;
int delq ( struct queue * ) ;
void delqueue ( struct queue * ) ;

void main( )
{
	struct queue a ;
	int i ;

	initqueue ( &a ) ;

	addq ( &a, 11 ) ;
	addq ( &a, -8 ) ;
	addq ( &a, 23 ) ;
	addq ( &a, 19 ) ;
	addq ( &a, 15 ) ;
	addq ( &a, 16 ) ;
	addq ( &a, 28 ) ;

	i = delq ( &a ) ;
	printf ( "\nItem extracted: %d", i ) ;

	i = delq ( &a ) ;
	printf ( "\nItem extracted: %d", i ) ;

	i = delq ( &a ) ;
	printf ( "\nItem extracted: %d", i ) ;

	delqueue ( &a ) ;
}

/* initialises data member */
void initqueue ( struct queue *q )
{
	q -> front = q -> rear = NULL ;
}

/* adds an element to the queue */
void addq ( struct queue *q, int item )
{
	struct node *temp ;

	temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	if ( temp == NULL )
		printf ( "\nQueue is empty." ) ;

	temp -> data = item ;
	temp -> link = NULL ;

	if ( q -> front == NULL )
	{
                //  q->rear = temp;  q->front = temp;
		q -> rear = q -> front = temp ;
		return ;
	}

	q -> rear -> link = temp ;
	q -> rear = q -> rear -> link ;
}

/* removes an element from the queue */
int delq ( struct queue * q )
{
	struct node *temp ;
	int item ;

	if ( q -> front == NULL )
	{
		printf ( "\nQueue is empty." ) ;
		return 0 ;
	}

	item = q -> front  -> data ;
	temp = q -> front ;
	q -> front = q -> front -> link ;
	free ( temp ) ;
	return item ;
}

/* deallocates memory */
void delqueue ( struct queue *q )
{
	struct node *temp ;

	if ( q -> front == NULL )
		return ;

	while ( q -> front != NULL )
	{
		temp = q -> front ;
		q -> front = q -> front -> link ;
		free ( temp ) ;
	}
}
