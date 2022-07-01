// Program Ch04pr05
// Program to sort a linked list by swapping data.

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
		void getdata( ) ;
		void append ( int num ) ;
		void display( ) ;
		int count( ) ;
		void selection_sort ( int num ) ;
		void bubble_sort ( int num ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	p = NULL ;
}

// accepts data
void linklist :: getdata( )
{
	int val ;
	char ch ;

	do
	{
		cout << "\nEnter a value: "  ;
		cin >> val ;

		append ( val ) ;

		cout << "\nAny More Nodes (Y/N): " ;
		cin >> ch ;
	} while ( ch == 'y' || ch == 'Y' ) ;
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

// displays the contents of the linked list
void linklist :: display( )
{
	node *temp = p ;

	cout << endl ;
	// traverse the entire linked list
	while ( temp != NULL )
	{
		cout << temp -> data << "  ";
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

// sorts list using selection sort
void linklist :: selection_sort ( int n )
{
	int temp ;
	node *q, *r ;

	q = p ;
	for ( int i = 0 ; i < n - 1 ; i++ )
	{
		r = q -> link ;

		for ( int j = i + 1 ; j < n ; j++ )
		{
			if ( q -> data > r -> data )
			{
				temp = q -> data ;
				q -> data = r -> data ;
				r -> data = temp ;
			}
			r = r -> link ;
		}
		q = q -> link ;
	}
}

// sort list using bubble sort
void linklist :: bubble_sort ( int n )
{
	int k, temp ;
	node *q, *r ;

	k = n ;
	for ( int i = 0 ; i < n - 1 ; i++, k-- )
	{
		q = p ;
		r = q -> link ;

		for ( int j = 1 ; j < k ; j++ )
		{
			if ( q -> data > r -> data )
			{
				temp = q -> data ;
				q -> data = r -> data ;
				r -> data = temp ;
			}
			q = q -> link ;
			r = r -> link ;
		}
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
	l1.getdata( ) ;

	cout << "\nElements in first linked list before sorting: "  ;
	l1.display( ) ;

	int n = l1.count( ) ;

	l1.selection_sort( n ) ;
	cout << "\nElements in first linked list after selection sorting: "  ;
	l1.display( ) ;

	linklist l2 ;
	l2.getdata( ) ;

	cout << "\n\nElements in second linked list before sorting: " ;
	l2.display( ) ;

	n = l2.count( ) ;

	l2.bubble_sort( n ) ;
	cout << "\nElements in second linked list after bubble sorting: " ;
	l2.display( ) ;
}

