// Program Ch04pr09
// Program to find the number of nodes in the linked list using recursion

#include <iostream.h>

class linklist
{
	private :

		// structure containing a data part and link part
		struct node
		{
			int data ;
			node *link ;
		} *p ;

	public :

		linklist( ) ;
		void append ( int num ) ;
		int length( ) ;
		static int getlength( node *ptr ) ;
		~linklist( ) ;
} ;

// initializes data memebr
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

// calls getlength
int linklist :: length( )
{
    return getlength( p ) ;
}

// counts the number of nodes in a linked list
int linklist :: getlength ( node *ptr )
{
	static int l ;

	// if list is empty or if NULL is encountered
	if ( ptr == NULL )
		return ( 0 ) ;
	else
	{
		// go to next node
		l = 1 + getlength ( ptr -> link ) ;
		return ( l ) ;
	}
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
	linklist l ;

	l.append ( 1 ) ;
	l.append ( 2 ) ;
	l.append ( 3 ) ;
	l.append ( 4 ) ;
	l.append ( 5 ) ;

	cout << "\nLength of linked list: " << l.length( ) ;
}

