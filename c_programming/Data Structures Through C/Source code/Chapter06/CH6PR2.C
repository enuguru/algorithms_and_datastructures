/*  CH6PR2.C: Program implements linked list as a stack. */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

/* structure containing data part and linkpart */
struct node
{
	int data ;
	struct node *link ;
} ;

void push ( struct node **, int ) ;
int pop ( struct node ** ) ;
void delstack ( struct node ** ) ;

void main( )
{
	struct node *s = NULL ;
	int i ;

	clrscr( ) ;

	push ( &s, 14 ) ;
	push ( &s, -3 ) ;
	push ( &s, 18 ) ;
	push ( &s, 29 ) ;
	push ( &s, 31 ) ;
	push ( &s, 16 ) ;

	i = pop ( &s ) ;
	printf ( "\nItem popped: %d", i ) ;

	i = pop ( &s ) ;
	 printf ( "\nItem popped: %d", i ) ;

	i = pop ( &s ) ;
	printf ( "\nItem popped: %d", i ) ;

	delstack ( &s ) ;

	getch( ) ;
}

/* adds a new node to the stack as linked list */
void push ( struct node **top, int item )
{
	struct node *temp ;
	temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;

	if ( temp == NULL )
		printf ( "\nStack is full." ) ;

	temp -> data = item ;
	temp -> link = *top ;
	*top = temp ;
}

/* pops an element from the stack */
int pop ( struct node **top )
{
	struct node *temp ;
	int item ;

	if ( *top == NULL )
	{
		printf ( "\nStack is empty." ) ;
		return NULL ;
	}

	temp = *top ;
	item = temp -> data ;
	*top = ( *top ) -> link ;

	free ( temp ) ;
	return item ;
}

/* deallocates memory */
void delstack ( struct node **top )
{
	struct node *temp ;

	if ( *top == NULL )
		return ;

	while ( *top != NULL )
	{
		temp = *top ;
		*top = ( *top ) -> link ;
		free ( temp ) ;
	}
}