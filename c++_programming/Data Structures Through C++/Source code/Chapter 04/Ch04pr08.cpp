// Program Ch04pr08
// Program to concatenate one linked list at end of another and
// then to erase all nodes present in the linked list

#include <iostream.h>

class linklist
{
	private :

    	// structure containing a data part and a link part
		struct node
		{
			int data ;
			node *link ;
		} *p ;

	public :

		linklist( ) ;
		void append ( int num ) ;
		void concat ( linklist &l ) ;
		void display( ) ;
		int count( ) ;
		~linklist( ) ;
} ;

// initializes data members
linklist :: linklist( )
{
	p = NULL ;
}

// adds a node at the end of a linked list
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

// concatenates two linked lists
void linklist :: concat ( linklist &l )
{
	node *temp ;

	// if the first linked list is empty
	if ( p == NULL )
		p = l.p ;

	else
	{
		// if both linked lists are non-empty
		if ( l.p != NULL )
		{
			// points to the starting of the first list
			temp = p ;

			// traverse the entire first linked list
			while ( temp -> link != NULL )
				temp = temp -> link ;

			// concatenate the second list after the first
			temp -> link = l.p ;
		}
	}
    l.p = NULL ;
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

// counts the number of nodes present in the linked list
int linklist :: count( )
{
	int c = 0 ;
	node *temp = p ;

	// traverse the entire linked list
	while ( temp != NULL )
	{
		temp = temp -> link ;
		c++ ;
	}

	return c ;
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

	cout << "\nElements in first linked list: " ;
	l1.display( ) ;
	cout << "\nNo. of elements in first linked list: " << l1.count( ) ;

	linklist l2 ;
	l2.append ( 5 ) ;
	l2.append ( 6 ) ;
	l2.append ( 7 ) ;
	l2.append ( 8 ) ;

	cout << "\n\nElements in second linked list: "  ;
	l2.display( ) ;
	cout << "\nNo. of elements in second linked list: " << l2.count( ) ;

	// the result obtained after concatenation is in the first list
	l1.concat ( l2 ) ;

	cout << "\n\nElements in first linked list after concatenation: " ;
	l1.display( ) ;
}

