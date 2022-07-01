// Prgram Ch04pr11
// Program to copy one linked list into another using recursion

#include <iostream.h>

class linklist
{
	private :


		// structure containing a data part and link part */
		struct node
		{
			int data ;
			node *link ;
		} *p ;

	public :

		linklist( ) ;
		void append ( int num ) ;
		void fun ( linklist &l ) ;
		static void copy ( node *ptr1, node **ptr2 ) ;
		void display( ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	p = NULL ;
}

// adds a node at the end of the linked list
void linklist :: append ( int num )
{
	node *temp ;
	temp = p ;

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

// call copy to copy a linked list into another
void linklist :: fun ( linklist &l )
{
	copy ( l.p, &p ) ;
}


// copies a linked list into another
void linklist :: copy ( node *ptr1, node **ptr2 )
{
	if ( ptr1 != NULL )
	{
		*ptr2 = new node ;

		(*ptr2) -> data = ptr1 -> data ;
		(*ptr2) -> link = NULL ;

		copy ( ptr1 -> link, &( ( *ptr2 ) -> link ) ) ;
	}
}

// displays the contents of the linked list
void linklist :: display( )
{
	cout << endl ;
	node *temp = p ;

	// traverse the entire linked list
	while ( temp != NULL )
	{
		cout << temp -> data  << "  " ;
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
	linklist l1 ;

	l1.append ( 1 ) ;
	l1.append ( 2 ) ;
	l1.append ( 3 ) ;
	l1.append ( 4 ) ;
	l1.append ( 5 ) ;
	l1.append ( 6 ) ;
	l1.append ( 7 ) ;

	cout << "\nElements in first linked list: " ;
	l1.display( ) ;

	linklist l2 ;
	l2.fun ( l1 ) ;

	cout << "\nElements in second linked list: " ;
	l2.display( ) ;
}

