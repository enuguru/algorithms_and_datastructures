/* CH4PR6.C: Program to sort a linked list by readjusting the links. */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node *link ;
} *start, *visit ;

void getdata( ) ;
void append ( struct node **q, int num ) ;
void displaylist( ) ;
void selection_sort( ) ;
void bubble_sort( ) ;

void main( )
{
	getdata( ) ;
	clrscr( ) ;
	printf ( "\nLinked List Before Sorting:\n" ) ;
	displaylist( ) ;

	selection_sort( ) ;
	printf ( "\nLinked List After Selection Sorting:\n" ) ;
	displaylist( ) ;
	getch( ) ;

	getdata( ) ;
	clrscr( ) ;
	printf ( "\nLinked List Before Sorting:\n" ) ;
	displaylist( ) ;

	bubble_sort( ) ;
	printf ( "\nLinked List After Bubble Sorting:\n" ) ;
	displaylist( ) ;
	getch( ) ;
}

void getdata( )
{
	int val, n ;
	char ch ;
	struct node *newnode;

	clrscr( ) ;

	newnode = NULL ;
	do
	{
		printf ( "\nEnter a value: " ) ;
		scanf ( "%d", &val ) ;

		append ( &newnode, val ) ;

		printf ( "\nAny More Nodes (Y/N): " ) ;
		ch = getche( ) ;
	} while ( ch == 'y' || ch == 'Y' ) ;

	start =  newnode ;
}

/* adds a node at the end of a linked list */
void append ( struct node **q, int num )
{
	struct node *temp ;
	temp = *q ;

	if ( *q == NULL ) /* if the list is empty, create first node */
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

/* displays the contents of the linked list */
void displaylist( )
{
	visit = start ;

	/* traverse the entire linked list */
	while ( visit != NULL )
	{
		printf ( "%d ", visit -> data ) ;
		visit = visit -> link ;
	}
}

void selection_sort( )
{
	struct node *p, *q, *r, *s, *temp ;

	p = r = start ;
	while ( p -> link != NULL )
	{
		s = q = p -> link ;
		while ( q != NULL )
		{
			if ( p -> data > q -> data )
			{
				if ( p -> link == q ) /* Adjacent Nodes */
				{
					if ( p == start )
					{
						p -> link = q -> link ;
						q -> link = p ;

						temp = p ;
						p = q ;
						q = temp ;

						start = p ;
						r = p ;
						s = q ;
						q = q -> link ;
					}
					else
					{
						p -> link = q -> link ;
						q -> link = p ;
						r -> link = q ;

						temp = p ;
						p = q ;
						q = temp ;

						s = q ;
						q = q -> link ;
					}
				}
				else
				{
					if ( p == start )
					{
						temp = q -> link ;
						q -> link = p -> link ;
						p -> link = temp ;

						s -> link = p ;

						temp = p ;
						p = q ;
						q = temp ;

						s = q ;
						q = q -> link ;
						start = p ;
					}
					else
					{
						temp = q -> link ;
						q -> link = p -> link ;
						p -> link = temp ;

						r -> link = q ;
						s -> link = p ;

						temp = p ;
						p = q ;
						q = temp ;

						s = q ;
						q = q -> link ;
					}
				}
			}
			else
			{
				s = q ;
				q = q -> link ;
			}
		}
		r = p ;
		p = p -> link ;
	}
}

void bubble_sort( )
{
	struct node *p, *q, *r, *s, *temp ;
	s = NULL ;

	/* r precedes p and s points to the node up to which comparisons are to be made */
	while ( s != start -> link )
	{
		r = p = start ;
		q = p -> link ;

		while ( p != s )
		{
			if ( p -> data > q -> data )
			{
				if ( p == start )
				{
					temp = q -> link ;
					q -> link = p ;
					p -> link = temp ;

					start = q ;
					r = q ;
				}
				else
				{
					temp = q -> link ;
					q -> link = p ;
					p -> link = temp ;

					r -> link = q ;
					r = q ;
				}
			}
			else
			{
				r = p ;
				p = p -> link ;
			}
			q = p -> link ;
			if ( q == s )
				s = p ;
		}
	}
}
