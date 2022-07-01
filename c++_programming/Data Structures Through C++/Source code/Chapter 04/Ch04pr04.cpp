// Program Ch04pr04
// Program to merge two linked list, restricting commomn elements
// to occur only once

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
		void add ( int num ) ;
		void display( ) ;
		int count( ) ;
		void merge( linklist &l1, linklist &l2 ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	p = NULL ;
}

// adds node to an ascending order linked list
void linklist :: add ( int num )
{
	node *r, *temp ;
	temp = p ;

	r = new node ;
	r -> data = num ;

	// if list is empty or if new node is to be
	// inserted before the first node
	if ( p == NULL || p -> data > num )
	{
		p = r ;
		p -> link = temp ;
	}
	else
	{
		// traverse the entire linked list to search
		// the position to insert the new node
		while ( temp != NULL )
		{
			if ( temp -> data < num && ( temp -> link -> data > num ||
				temp -> link == NULL ))
			{
				r -> link = temp -> link ;
				temp -> link = r ;
				return ;
			}

			//go to next node
			temp = temp -> link ;
		}

		r -> link = NULL ;
		temp -> link = r ;
	}
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

// merges two linked lists, restricting the common
// elements to occur only once in the final list
void linklist :: merge ( linklist &l1, linklist&l2 )
{
	node *z ;

	z = NULL ;

	// if both lists are empty
	if ( l1.p == NULL && l2.p == NULL )
		return ;

	// traverse both linked lists till the end.
	// If end of any one list is reached loop is terminated
	while ( l1.p != NULL && l2.p != NULL )
	{
		// if node being added is the first node
		if ( p == NULL )
		{
			p = new node ;
			z = p ;
		}
		else
		{
			z -> link = new node ;
			z = z -> link ;
		}

		if ( l1.p -> data < l2.p -> data )
		{
			z -> data = l1.p -> data ;
			l1.p = l1.p -> link ;
		}
		else
		{
			if ( l2.p -> data < l1.p -> data )
			{
				z -> data = l2.p -> data ;
				l2.p = l2.p -> link ;
			}
			else
			{
				if ( l1.p -> data == l2.p -> data )
				{
					z -> data = l2.p -> data ;
					l1.p = l1.p -> link ;
					l2.p = l2.p -> link ;
				}
			}
		}
	}

	// if end of first list has not been reached
	while ( l1.p != NULL )
	{
		z -> link = new node ;
		z = z -> link ;
		z -> data = l1.p -> data ;
		l1.p = l1.p -> link ;
	}

	// if end of second list has been reached
	while ( l2.p != NULL )
	{
		z -> link = new node ;
		z = z -> link ;
		z -> data = l2.p -> data ;
		l2.p = l2.p -> link ;
	}
	z -> link = NULL ;
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

	l1.add ( 9 ) ;
	l1.add ( 12 ) ;
	l1.add ( 14 ) ;
	l1.add ( 17 ) ;
	l1.add ( 35 ) ;
	l1.add ( 61 ) ;
	l1.add ( 79 ) ;

	cout << "\nElements in first linked list: " ;
	l1.display( ) ;
	cout << "\nNo. of elements in linked list: " << l1.count( ) ;

	linklist l2 ;

	l2.add ( 12 ) ;
	l2.add ( 17 ) ;
	l2.add ( 24 ) ;
	l2.add ( 36 ) ;
	l2.add ( 59 ) ;
	l2.add ( 64 ) ;
	l2.add ( 87 ) ;

	cout << "\n\nElements in second linked list: " ;
	l2.display( ) ;
	cout << "\nNo. of elements in linked list: " << l2.count( ) ;

	linklist l3 ;
	l3.merge ( l1, l2 ) ;

	cout << "\n\nThe merged list: " ;
	l3.display( ) ;
	cout << "\nNo. of elements in the merged linked list: " << l3.count( ) ;
}

