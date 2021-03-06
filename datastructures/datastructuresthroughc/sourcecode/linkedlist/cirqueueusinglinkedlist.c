
/* Program to implement a circular queue as a linked list. */

#include <stdio.h>
#include <malloc.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node * link ;
} ;

void addcirq ( struct node **, struct node **, int ) ;
int delcirq ( struct node **, struct node ** ) ;
void cirq_display ( struct node * ) ;

void main( )
{
	struct node *front, *rear ;

	front = rear = NULL ;

	addcirq ( &front, &rear, 10 ) ;
	addcirq ( &front, &rear, 17 ) ;
	addcirq ( &front, &rear, 18 ) ;
	addcirq ( &front, &rear, 5 ) ;
	addcirq ( &front, &rear, 30 ) ;
	addcirq ( &front, &rear, 15 ) ;

	printf ( "Before deletion:\n" ) ;
	cirq_display ( front ) ;

	delcirq ( &front, &rear ) ;
	delcirq ( &front, &rear ) ;
	delcirq ( &front, &rear ) ;

	printf ( "\n\nAfter deletion:\n" ) ;
	cirq_display ( front ) ;
}

/* adds a new element at the end of queue */
void addcirq ( struct node **f, struct node **r, int item )
{
	struct node *q ;

	/* create new node */
	q = malloc ( sizeof ( struct node ) ) ;
	q -> data = item ;

	/* if the queue is empty */
	if ( *f == NULL )
		*f = q ;
	else
		( *r ) -> link = q ;

	*r = q ;
	( *r ) -> link = *f ;
}

/* removes an element from front of queue */
int delcirq ( struct node **f, struct node **r )
{
	struct node *q ;
	int item ;

	/* if queue is empty */
	if ( *f == NULL )
		printf ( "queue is empty" ) ;
	else
	{
		if ( *f == *r )
		{
			item = ( *f ) -> data ;
			free ( *f ) ;
			*f = NULL ;
			*r = NULL ;
		}
		else
		{
			/* delete the node */
			q = *f ;
			item = q -> data ;
			*f = ( *f ) -> link ;
			( *r ) -> link = *f ;
			free ( q ) ;
		}
		return ( item ) ;
	}
	return 0 ;
}

/* displays whole of the queue */
void cirq_display ( struct node *f )
{
	struct node *q = f, *p = NULL ;

	/* traverse the entire linked list */
	while ( q != p )
	{
		printf ( "%d\t", q -> data ) ;

		q = q -> link ;
		p = f ;
	}
}
