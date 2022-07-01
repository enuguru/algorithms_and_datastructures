// Program Ch04pr06
// Program to sort a linked list by readjusting the links.

#include <iostream.h>

class linklist
{
	private :

		// structure containing a data part and link part
		struct node
		{
			int data ;
			node *link ;
		} *start ;

	public :

		linklist( ) ;
		void getdata( ) ;
		void append ( int num ) ;
		void display( ) ;
		void selection_sort( ) ;
		void bubble_sort( ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	start = NULL ;
}

// accepts data
void linklist :: getdata( )
{
	int val, n ;
	char ch ;
	do
	{
		cout << "\nEnter a value: " ;
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
	temp = start ;

	// if the list is empty, create first node
	if ( temp == NULL )
	{
		temp = new node ;
		start = temp ;
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
	node *temp = start ;

	cout << endl ;
   	// traverse the entire linked list
	while ( temp != NULL )
	{
		cout << temp -> data << "  " ;
		temp = temp -> link ;
	}
}

// sorts list using selection sort method
void linklist :: selection_sort( )
{
	node *p, *q, *r, *s, *temp ;

	p = r = start ;

	while ( p -> link != NULL )
	{
		s = q = p -> link ;
  		while ( q != NULL )
		{
 			if ( p -> data > q -> data )
			{
				if ( p -> link == q )
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

// sorts list using bubble sort method
void linklist :: bubble_sort( )
{
	node *p, *q, *r, *s, *temp ;
	s = NULL ;

	// r precedes p and s points to the node up to
	// which comparisons are to be made
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

// deallocates memory
linklist :: ~linklist( )
{
	node *q ;

	while ( start != NULL )
	{
		q = start -> link ;
		delete start ;
		start = q ;
	}
}

void main( )
{
	linklist l1 ;

	l1.getdata( ) ;

	cout << "\nElements in first linked list before sorting: " ;
	l1.display( ) ;

	l1.selection_sort( ) ;
	cout << "\nElements in first linked list after selection sorting: " ;
	l1.display( ) ;

	linklist l2 ;
	l2.getdata( ) ;
	cout << "\n\nElements in second linked list before sorting: " ;
	l2.display( ) ;

	l2.bubble_sort( ) ;
	cout << "\nElements in second linked list after bubble sorting: " ;
	l2.display( ) ;
}

