// Program Ch04pr10
// Program to compare two linked lists using recursion

#include <iostream.h>

class linklist
{
	private :

		// structure containg data part and link part
		struct node
		{
			int data ;
			node *link ;
		} *p ;

	public :

		linklist( ) ;
		void append ( int num ) ;
		int operator == ( linklist &l ) ;
		static int compare ( node *ptr1, node *ptr2 ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	p = NULL ;
}

// adds a node at the end of a linked list
void linklist :: append ( int num )
{
	node *temp = p ;

	// if the list is empty, create first node
	if ( temp == NULL )
	{
		temp = new node ;
		p = temp ;
	}
	else
	{
		// go to last node
		while ( temp -> link != NULL )
			temp = temp -> link ;

		// add node at the end
		temp -> link = new node ;
		temp = temp -> link ;
	}

	// assign data to the last node
	temp -> data = num ;
	temp -> link = NULL ;
}

// calls compare
int linklist :: operator == ( linklist &l )
{
	return compare ( p, l.p ) ;
}

// comapres 2 linked lists and returns 1 if
// linked lists are equal and 0 if unequal
int linklist :: compare ( node *q, node *r )
{
	static int flag ;

	if ( q == NULL  &&  r == NULL  )
		flag = 1  ;
	else
	{
		if ( q == NULL || r == NULL )
			flag = 0  ;

		if ( q -> data != r -> data )
			flag = 0 ;
		else
			compare ( q -> link, r -> link ) ;
	}
	return ( flag ) ;
}

// deallocates memory
linklist :: ~linklist( )
{
	node *q ;

	while ( p != NULL )
	{
		q = p -> link ;
		delete p ;
		p = q ;
	}
}

void main( )
{
	linklist l1 ;

	l1.append ( 1 ) ;
	l1.append ( 2 ) ;
	l1.append ( 3 ) ;

	linklist l2 ;
	l2.append ( 1 ) ;
	l2.append ( 2 ) ;
	l2.append ( 3 ) ;

	if ( l1 == l2 )
		cout << "\nBoth linked lists are equal" ;
	else
		cout << "\nBoth linked lists are different"  ;
}

