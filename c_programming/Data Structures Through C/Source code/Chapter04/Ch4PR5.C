/* CH4PR5.C: Program to sort a linked list by swapping data.*/

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node *link ;
} *newnode, *start, *visit ;

void getdata( ) ;
void append ( struct node **, int ) ;
void displaylist( ) ;
int count ( struct node * ) ;
void selection_sort ( int ) ;
void bubble_sort ( int ) ;

void main( )
{
	int n ;

	getdata( ) ;

	clrscr( ) ;
	printf ( "Linked List Before Sorting: " ) ;
	displaylist( ) ;

	n = count ( start ) ;

	selection_sort ( n ) ;
	printf ( "\nLinked List After Selection Sorting: " ) ;
	displaylist( ) ;
	getch( ) ;

	getdata( ) ;
	clrscr( ) ;
	printf ( "Linked List Before Sorting: " ) ;
	displaylist( ) ;

	n = count ( start ) ;

	bubble_sort ( n ) ;
	printf ( "\nLinked List After Bubble Sorting: " ) ;
	displaylist( ) ;
	getch( ) ;
}

void getdata( )
{
	int val, n ;
	char ch ;
	struct node *new ;

	clrscr( ) ;

	new = NULL ;
	do
	{
		printf ( "\nEnter a value: " ) ;
		scanf ( "%d", &val ) ;

		append ( &new, val ) ;

		printf ( "\nAny More Nodes (Y/N): " ) ;
		ch = getche( ) ;
	} while ( ch == 'y' || ch == 'Y' ) ;

	start = new ;
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

void selection_sort ( int n )
{
	int i, j, k, temp ;
	struct node *p, *q ;

	p = start ;
	for ( i = 0 ; i < n - 1 ; i++ )
	{
		q = p -> link ;

		for ( j = i + 1 ; j < n ; j++ )
		{
			if ( p -> data > q -> data )
			{
				temp = p -> data ;
				p -> data = q -> data ;
				q -> data = temp ;
			}
			q = q -> link ;
		}
		p = p -> link ;
	}
}

void bubble_sort ( int n )
{
	int i, j, k, temp ;
	struct node *p, *q ;

	k = n ;
	for ( i = 0 ; i < n - 1 ; i++, k-- )
	{
		p = start ;
		q = p -> link ;

		for ( j = 1 ; j < k ; j++ )
		{
			if ( p -> data > q -> data )
			{
				temp = p -> data ;
				p -> data = q -> data ;
				q -> data = temp ;
			}
			p = p -> link ;
			q = q -> link ;
		}
	}
}