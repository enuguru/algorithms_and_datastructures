// Program Ch04pr03
// Program to reverse a linked list

#include <iostream.h>

class linklist
{
	private :

		// structure containing a data part and link part */
		struct node
		{
			int data ;
			node *link ;
		} *p;

	public :

		linklist( ) ;
		void addatbeg ( int num ) ;
		void reverse( ) ;
		void display( ) ;
		int count( ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	p = NULL ;
}

// adds a new node at the beginning of the linked list
void linklist :: addatbeg ( int num )
{
	node *temp ;

	// add new node
	temp = new node ;
	temp -> data = num ;
	temp -> link = p ;
	p = temp ;
}

// reverses the linked list
void linklist :: reverse( )
{
	node *q, *r, *s ;

	q = p ;
	r = NULL ;

	// traverse the entire linked list
	while ( q != NULL )
	{
		s = r ;
		r = q ;
		q = q -> link ;
		r -> link = s ;
	}

	p = r ;
}

// displays the contents of the linked list
void linklist :: display( )
{
	node *temp = p ;

	cout << endl ;
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
	node *temp = p ;
	int c = 0 ;

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
	linklist l ;

	l.addatbeg ( 7 ) ;
	l.addatbeg ( 43 ) ;
	l.addatbeg ( 17 ) ;
	l.addatbeg ( 3 ) ;
	l.addatbeg ( 23 ) ;
	l.addatbeg ( 5 ) ;

	cout << "\nElements in the linked list before reversing: " ;
	l.display( ) ;
	cout << "\nNo. of elements in the linked list: " << l.count( ) ;

	l.reverse( ) ;
	cout << "\n\nElements in the linked list after reversing: " ;
	l.display( ) ;
	cout << "\nNo. of elements in the linked list: " << l.count( ) ;
}

