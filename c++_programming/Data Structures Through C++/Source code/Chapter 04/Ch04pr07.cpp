// Program Ch04pr07
// Program to implement a circular queue as a linked list.

#include <iostream.h>

class linklist
{
	private :

		// structure containing a data part and link part
		struct node
		{
			int data ;
			node * link ;
		} *front, *rear ;

	public :

		linklist( ) ;
		void addcirq ( int item ) ;
		int delcirq( ) ;
		void cirq_display( ) ;
		~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	front = rear = NULL ;
}

// adds a new element at the end of queue
void linklist :: addcirq ( int item )
{
	node *q ;

	// create new node
	q = new node ;
	q -> data = item ;

	// if the queue is empty
	if ( front == NULL )
		front = q ;
	else
		rear -> link = q ;

	rear = q ;
	rear -> link = front ;
}

// removes an element from front of queue
int linklist :: delcirq( )
{
	node *q ;
	int item ;

	// if queue is empty
	if ( front == NULL )
		cout << "\nqueue is empty" ;
	else
	{
		if ( front == rear )
		{
			item = front -> data ;
			delete front ;
			front = NULL ;
			rear = NULL ;
		}
		else
		{
			// delete the node
			q = front ;
			item = q -> data ;
			front = front -> link ;
			rear -> link = front ;
			delete q ;
		}
		return ( item ) ;
	}
	return NULL ;
}

// displays whole of the queue
void linklist :: cirq_display( )
{
	node *q, *p ;
	q = front ;
	p = NULL ;

	cout << endl ;
	// traverse the entire linked list
	while ( q != p )
	{
		cout << q -> data << "  "  ;
		q = q -> link ;
		p = front ;
	}
}

// deallocates memory
linklist :: ~linklist( )
{
	node *q ;

	while ( front != rear )
	{
		q = front -> link ;
		delete front ;
		front = q ;
	}
	delete rear ;
}

void main( )
{
	linklist l ;

	l.addcirq ( 10 ) ;
	l.addcirq ( 17 ) ;
	l.addcirq ( 18 ) ;
	l.addcirq ( 5 ) ;
	l.addcirq ( 30 ) ;
	l.addcirq ( 15 ) ;

	cout << "\nElements in linked list before deletion: " ;
	l.cirq_display( ) ;

	l.delcirq( ) ;
	l.delcirq( ) ;
	l.delcirq( ) ;

	cout << "\nElements in linked list after deletion: " ;
	l.cirq_display ( ) ;
}

