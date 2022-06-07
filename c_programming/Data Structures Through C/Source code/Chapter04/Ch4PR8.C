/* CH4PR8.C: Program to concatenate one linked list at end of another and
 than to erase all nodes present in the linked list	*/

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int data ;
	struct node *link ;
} ;

void append ( struct node **, int ) ;
void concat ( struct node **, struct node ** ) ;
void display ( struct node * ) ;
int count ( struct node * ) ;
struct node * erase ( struct node * ) ;

void main( )
{
	struct node *first, *second ;

	first = second = NULL ;  /* empty linked lists */

	append ( &first, 1 ) ;
	append ( &first, 2 ) ;
	append ( &first, 3 ) ;
	append ( &first, 4 ) ;

	clrscr( ) ;
	printf ( "\nFirst List : " ) ;
	display ( first ) ;
	printf ( "\nNo. of elements in the first Linked List = %d",
			count ( first ) ) ;

	append ( &second, 5 ) ;
	append ( &second, 6 ) ;
	append ( &second, 7 ) ;
	append ( &second, 8 ) ;

	printf ( "\n\nSecond List : " ) ;
	display ( second ) ;
	printf ( "\nNo. of elements in the second Linked List = %d",
			count ( second ) ) ;

	/* the result obtained after concatenation is in the first list */
	concat ( &first, &second ) ;

	printf ( "\n\nConcatenated List : " ) ;
	display ( first ) ;

	printf ( "\n\nNo. of elements in Linked List before erasing = %d",
			count ( first ) ) ;

	first = erase ( first ) ;
	printf ( "\nNo. of elements in Linked List after erasing = %d",
			count ( first ) ) ;
}

/* adds a node at the end of a linked list */
void append ( struct node **q, int num )
{
	struct node *temp ;
	temp = *q ;

	if ( *q == NULL )  /* if the list is empty, create first node */
	{
		*q = malloc ( sizeof ( struct node ) ) ;
		temp = *q ;
	}
	else
	{
		/* go to last node */
		while ( temp -> link != NULL )
			temp = temp -> link ;

		/* add node at the end */
		temp -> link = malloc ( sizeof ( struct node ) ) ;
		temp = temp -> link ;
	}

	/* assign data to the last node */
	temp -> data = num ;
	temp -> link = NULL ;
}

/* concatenates two linked lists */
void concat ( struct node **p, struct node **q )
{
	struct node *temp ;

	/* if the first linked list is empty */
	if ( *p == NULL )
		*p = *q ;
	else
	{
		/* if both linked lists are non-empty */
		if ( *q != NULL )
		{
			temp = *p ;  /* points to the starting of the first list */

			/* traverse the entire first linked list */
			while ( temp -> link != NULL )
				temp = temp -> link ;

			temp -> link = *q ;  /* concatenate the second list after the
								 first */
		}
	}
}

/* displays the contents of the linked list */
void display ( struct node *q )
{
	printf ( "\n" ) ;

	/* traverse the entire linked list */
	while ( q != NULL )
	{
		printf ( "%d ", q -> data ) ;
		q = q -> link ;
	}
}

/* counts the number of nodes present in the linked list */
int count ( struct node *q )
{
	int c = 0 ;

	/* traverse the entire linked list */
	while ( q != NULL )
	{
		q = q -> link ;
		c++ ;
	}

	return c ;
}

/* erases all the nodes from a linked list */
struct node * erase ( struct node *q )
{
	struct node *temp ;

	/* traverse till the end erasing each node */
	while ( q != NULL )
	{
		temp = q ;
		q = q -> link ;
		free ( temp ) ;  /* free the memory occupied by the node */
	}

	return NULL ;
}



