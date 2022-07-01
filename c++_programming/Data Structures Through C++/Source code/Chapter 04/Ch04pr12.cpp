// Program Ch04pr12
// Program to add a new node at the end of linked list using recursion

#include <iostream.h>

class linklist
{
	private :

		// structure containing data part and link part
		struct node
		{
			int data ;
			node *link ;
		} *p ;

	public :

		linklist( ) ;
		void add ( int num ) ;
		static void addatend ( node **ptr, int num ) ;
		void display( ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	p = NULL ;
}

// calls addatend
void linklist :: add ( int num )
{
	addatend ( &p, num ) ;
}

// adds a new node at the end of the linked list
void linklist :: addatend ( node **ptr, int num )
{
	if ( *ptr == NULL )
	{
		(*ptr) = new node ;
		(*ptr) -> data = num ;
		(*ptr) -> link = NULL ;
	}
	else
		addatend ( &( ( *ptr ) -> link ), num ) ;
}

// displays the contents of the linked list
void linklist :: display( )
{
	cout << endl ;
	node *temp = p ;

	// traverse the entire linked list
	while ( temp != NULL )
	{
		cout << temp -> data << "  " ;
		temp = temp -> link ;
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

	l.add ( 1 ) ;
	l.add ( 2 ) ;
	l.add ( 3 ) ;
	l.add ( 4 ) ;
	l.add ( 5 ) ;
	l.add ( 6 ) ;
	l.add ( 10 ) ;

	cout << "\nElements in the linked list: " ;
	l.display( ) ;
}

