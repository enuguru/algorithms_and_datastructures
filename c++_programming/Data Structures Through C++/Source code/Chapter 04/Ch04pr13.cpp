// Program Ch04pr13
// Program to maintain a doubly linked list

#include <iostream.h>

class linklist
{
	private :

		// structure representing a node of the doubly linked list
		struct dnode
		{
			dnode *prev ;
			int data ;
			dnode * next ;
		} *p ;

	public :

		linklist( ) ;
		void d_append ( int num ) ;
		void d_addatbeg ( int num ) ;
		void d_addafter ( int loc, int num ) ;
		void d_display( ) ;
		int d_count( ) ;
		void d_delete( int i ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	p = NULL ;
}

// adds a new node at the end of the doubly linked list
void linklist :: d_append ( int num )
{
	dnode *r, *q ;
	q = p ;

	// if the linked list is empty
	if ( q == NULL )
	{
		//create a new node
		q = new dnode ;
		q -> prev = NULL ;
		q -> data = num ;
		q -> next = NULL ;
		p = q ;
	}
	else
	{
		// traverse the linked list till the last node is reached

		while ( q -> next != NULL )
			q = q -> next ;

		// add a new node at the end
		r = new dnode ;
		r -> data = num ;
		r -> next = NULL ;
		r -> prev = q ;
		q -> next = r ;
	}
}

// adds a new node at the begining of the linked list
void linklist :: d_addatbeg ( int num )
{
	dnode *q ;

	// create a new node
	q = new dnode ;

	// assign data and pointer to the new node
	q -> prev = NULL ;
	q -> data = num ;
	q -> next = p ;

	// make new node the head node
	p -> prev = q ;
	p = q ;
}

// adds a new node after the specified number of nodes
void linklist :: d_addafter ( int loc, int num )
{
	dnode *q ;
	q = p ;

	// skip to desired portion
	for ( int i = 0 ; i < loc ; i++ )
	{
		q = q -> next ;
		// if end of linked list is encountered
		if ( q == NULL )
		{
			cout << "\nThere are less than " << loc << " elements" ;
			return ;
		}
	}

	// insert new node
	q = q -> prev ;
	dnode *temp = new dnode ;
	temp -> data = num ;
	temp -> prev = q ;
	temp -> next = q -> next ;
	temp -> next -> prev = temp ;
	q -> next = temp ;
}

// displays the contents of the linked list
void linklist :: d_display( )
{
	dnode *temp = p ;

	cout << endl ;
	// traverse the entire linked list
	while ( temp != NULL )
	{
		cout << temp -> data << "  " ;
		temp = temp -> next ;
	}
}

// counts the number of nodes present in the linked list
int linklist :: d_count( )
{
	int c = 0 ;
	dnode *temp = p ;

	// traverse the entire linked list
	while ( temp != NULL )
	{
		temp = temp -> next ;
		c++ ;
	}

	return c ;
}

// deletes the specified node from the doubly linked list
void linklist :: d_delete ( int num )
{
	dnode *q = p ;

	// traverse the entire linked list
	while ( q != NULL )
	{
		// if node to be deleted is found
		if ( q -> data == num )
		{
			// if node to be deleted is the first node
			if ( q == p )
			{
				p = p -> next ;
				p -> prev = NULL ;
			}
			else
			{
				// if node to be deleted is the last node
				if ( q -> next == NULL )
					q -> prev -> next = NULL ;
				else
				// if node to be deleted is any intermediate node
				{
					q -> prev -> next = q -> next ;
					q -> next -> prev = q -> prev ;
				}
				delete q ;
			}

			// return back after deletion
			return ;
		}

		// go to next node
		q = q -> next ;
	}
	cout << "\n" << num << " not found." ;
}

// deallocates memory
linklist :: ~linklist( )
{
	dnode *q ;

	while ( q -> next != NULL )
	{
		q = p -> next ;
		delete p ;
		p = q ;
	}
}

void main( )
{
	linklist l ;

	l.d_append ( 11 ) ;
	l.d_append (  2 ) ;
	l.d_append ( 14 ) ;
	l.d_append ( 17 ) ;
	l.d_append ( 99 ) ;

	cout << "\nElements in doubly linked list: " ;
	l.d_display( ) ;
	cout <<  "\nNo. of elements in the doubly linked list: " << l.d_count( ) ;

	l.d_addatbeg ( 33 ) ;
	l.d_addatbeg ( 55 ) ;

	cout << "\n\nElements in doubly linked list after addition at the beginning: " ;
	l.d_display( ) ;
	cout << "\nNo. of elements in the doubly linked list: " << l.d_count( ) ;

	l.d_addafter ( 4, 66 ) ;
	l.d_addafter ( 2, 96 ) ;

	cout <<  "\n\nElements in doubly linked list after addition at the given position: " ;
	l.d_display( ) ;
	cout <<  "\nNo. of elements in the doubly linked list: " << l.d_count( ) ;

	l.d_delete ( 55 ) ;
	l.d_delete ( 2 ) ;
	l.d_delete ( 99 ) ;

	cout <<  "\n\nElements in doubly linked list after deletion: " ;
	l.d_display( ) ;
	cout << "\nNo. of elements in the doubly linked list: " << l.d_count( ) ;
}

