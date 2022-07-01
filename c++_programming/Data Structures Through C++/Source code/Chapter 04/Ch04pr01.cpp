// Program Ch04pr01
// Program to maintain a linked list

#include <iostream.h>

class linklist
{
	private :

		// structure containing a data part and link part
		struct node
		{
			int data ;
			node * link ;
		} *p ;

	public :

		linklist( ) ;
		void append ( int num ) ;
		void addatbeg ( int num ) ;
		void addafter ( int loc, int num ) ;
		void display( ) ;
		int count( ) ;
		void del ( int num ) ;
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
	node *temp, *r ;

    // if the list is empty, create first node
	if ( p == NULL )
	{
		p = new node ;
		p -> data = num ;
		p -> link = NULL ;
	}
	else
	{
		// go to last node
		temp = p ;
		while ( temp -> link != NULL )
			temp = temp -> link ;

		// add node at the end
		r = new node ;
		r -> data = num ;
		r -> link = NULL ;
		temp -> link = r ;
	}
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

// adds a new node after the specified number of nodes
void linklist :: addafter ( int loc, int num )
{
	node *temp, *r ;
	temp = p ;

	// skip to desired portion
	for ( int i = 0 ; i < loc ; i++ )
	{
		temp = temp -> link ;

		// if end of linked list is encountered
		if ( temp == NULL )
		{
			cout << "\nThere are less than " << loc << " elements in list" << endl ;
			return ;
		}
	}

	// insert new node
	r = new node ;
	r -> data = num ;
	r -> link = temp -> link ;
	temp -> link = r ;
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

// deletes the specified node from the linked list
void linklist :: del ( int num )
{
	node *old, *temp ;

	temp = p ;

	while ( temp != NULL )
	{
		if ( temp -> data == num )
		{
			// if node to be deleted is the
			// first node in the linked list
			if ( temp == p )
				p = temp -> link ;

			// deletes the intermediate nodes in the linked list
			else
				old -> link = temp -> link ;

			// free the memory occupied by the node
			delete temp ;
			return ;
		}

		// traverse the linked list till the last node is reached
		else
		{
            // old points to the previous node
			old = temp ;

            // go to the next node
			temp = temp -> link ;
		}
	}

	cout << "\n\nElement " << num << " not found" ;
}

// deallocates memory
linklist :: ~linklist( )
{
	node *q ;

    while ( p != NULL )
    {
        q = p -> link ;
        delete p ;
    	p = q  ;
    }
}

void main( )
{
    linklist l ;

	l.append ( 14 ) ;
	l.append ( 30 ) ;
	l.append ( 25 ) ;
	l.append ( 42 ) ;
	l.append ( 17 ) ;

    cout << "\nElements in the linked list: " ;
	l.display( ) ;

	l.addatbeg ( 999 ) ;
	l.addatbeg ( 888 ) ;
	l.addatbeg ( 777 ) ;

    cout << "\n\nElements in the linked list after addition at the beginning: " ;
	l.display( ) ;

	l.addafter ( 7, 0 ) ;
	l.addafter ( 2, 1 ) ;
	l.addafter ( 5, 99 ) ;

    cout << "\n\nElements in the linked list after addition at given position: " ;
	l.display( ) ;
	cout << "\nNo. of elements in the linked list " << l.count( ) ;

	l.del ( 99 ) ;
	l.del ( 1 ) ;
	l.del ( 10 ) ;

    cout << "\n\nElements in the linked list after deletion: " ;
	l.display( ) ;
	cout << "\nNo. of elements in the linked list: " << l.count( ) ;
}