/* Program to merge two linked list, restricting commomn elements to occur only once */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node *link ;
} ;

void add ( struct node **, int ) ;
void display ( struct node * ) ;
int count ( struct node * ) ;
void merge ( struct node *, struct node *, struct node ** ) ;

void main( )
{
	struct node *first, *second, *third ;
	first = second = third = NULL ;  /* empty linked lists */

	add ( &first, 9 ) ;
	add ( &first, 12 ) ;
	add ( &first, 14 ) ;
	add ( &first, 17 ) ;
	add ( &first, 35 ) ;
	add ( &first, 61 ) ;
	add ( &first, 79 ) ;

	clrscr( ) ;
	printf ( "First linked list : " ) ;
	display ( first ) ;
	printf ( "\nNo. of elements in Linked List : %d" , count ( first ) ) ;

	add ( &second, 12 ) ;
	add ( &second, 17 ) ;
	add ( &second, 24 ) ;
	add ( &second, 36 ) ;
	add ( &second, 59 ) ;
	add ( &second, 64 ) ;
	add ( &second, 87 ) ;

	printf ( "\n\nSecond linked list : " ) ;
	display ( second ) ;
	printf ( "\nNo. of elements in Linked List : %d" , count ( second ) ) ;

	merge ( first, second, &third ) ;

	printf ( "\n\nThe merged list : " ) ;
	display ( third ) ;
	printf ( "\nNo. of elements in Linked List : %d", count ( third ) ) ;
}

/* adds node to an ascending order linked list */
void add ( struct node **q, int num )
{
	struct node *r, *temp = *q ;

	r = malloc ( sizeof ( struct node ) ) ;
	r -> data = num ;

	/* if list is empty or if new node is to be inserted before the first node */
	if ( *q == NULL || ( *q ) -> data > num )
	{
		*q = r ;
		( *q ) -> link = temp ;
	}
	else
	{
		/* traverse the entire linked list to search the position to insert the new node */
		while ( temp != NULL )
		{
			if ( temp -> data < num && ( temp -> link -> data > num ||
				temp -> link == NULL ))
			{
				r -> link = temp -> link ;
				temp -> link = r ;
				return ;
			}
			temp = temp -> link ;  /*go to next node */
		}

		r -> link = NULL ;
		temp -> link = r ;
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
int count ( struct node * q )
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

/* merges the two linked lists, restricting the common elements to occur only once in the final list */
void merge ( struct node *p, struct node *q, struct node **s )
{
	struct node *z ;

	z = NULL ;

	/* if both lists are empty */
	if ( p == NULL && q == NULL )
		return ;

	/* traverse both linked lists till the end. If end of any one list is reached loop is terminated */
	while ( p != NULL && q != NULL )
	{
		/* if node being added in the first node */
		if ( *s == NULL )
		{
			*s = malloc ( sizeof ( struct node ) ) ;
			z = *s ;
		}
		else
		{
			z -> link = malloc ( sizeof ( struct node ) ) ;
			z = z -> link ;
		}

		if ( p -> data < q -> data )
		{
			z -> data = p -> data ;
			p = p -> link ;
		}
		else
		{
			if ( q -> data < p -> data )
			{
				z -> data = q -> data ;
				q = q -> link ;
			}
			else
			{
				if ( p -> data == q -> data )
				{
					z -> data = q -> data ;
					p = p -> link ;
					q = q -> link ;
				}
			}
		}
	}

	/* if end of first list has not been reached */
	while ( p != NULL )
	{
		z -> link = malloc ( sizeof ( struct node ) ) ;
		z = z -> link ;
		z -> data = p -> data ;
		p = p -> link ;
	}

	/* if end of second list has been reached */
	while ( q != NULL )
	{
		z -> link = malloc ( sizeof ( struct node ) ) ;
		z = z -> link ;
		z -> data = q -> data ;
		q = q -> link ;
	}
	z -> link = NULL ;
}
