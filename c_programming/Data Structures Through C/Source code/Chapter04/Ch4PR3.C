/* CH4PR3.C: Program to reverse a linked list */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node *link ;
} ;

void addatbeg ( struct node **, int ) ;
void reverse ( struct node ** ) ;
void display ( struct node * ) ;
int count ( struct node * ) ;

void main( )
{
	struct node *p ;
	p = NULL ;  /* empty linked list */

	addatbeg ( &p, 7 ) ;
	addatbeg ( &p, 43 ) ;
	addatbeg ( &p, 17 ) ;
	addatbeg ( &p, 3 ) ;
	addatbeg ( &p, 23 ) ;
	addatbeg ( &p, 5 ) ;

	clrscr( ) ;
	display ( p ) ;
	printf ( "\nNo. of elements in the linked list = %d", count ( p ) ) ;

	reverse ( &p ) ;
	display ( p ) ;
	printf ( "\nNo. of elements in the linked list = %d", count ( p ) ) ;
}

/* adds a new node at the beginning of the linked list */
void addatbeg ( struct node **q, int num )
{
	struct node *temp ;

	/* add new node */
	temp = malloc ( sizeof ( struct node ) ) ;
	temp -> data = num ;
	temp -> link = *q ;
	*q = temp ;
}

void reverse ( struct node **x )
{
	struct node *q, *r, *s ;

	q = *x ;
	r = NULL ;

	/* traverse the entire linked list */
	while ( q != NULL )
	{
		s = r ;
		r = q ;
		q = q -> link ;
		r -> link = s ;
	}

	*x = r ;
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
