// Program Ch07pr02
// Program that implements queue as a linked list

#include <iostream.h>

class queue
{
	private :

		struct node
		{
			int data ;
			node *link ;
		} *front, *rear ;

	public :

		queue( ) ;
		void addq ( int item ) ;
		int delq( ) ;
		~queue( ) ;
} ;

// initialises data member
queue :: queue( )
{
	front = rear = NULL ;
}

// adds an element to the queue
void queue :: addq ( int item )
{
	node *temp ;

	temp = new node ;
	if ( temp == NULL )
		cout << "\nQueue is full" ;

	temp -> data = item ;
	temp -> link = NULL ;

	if ( front == NULL )
	{
		rear = front = temp ;
		return ;
	}

	rear -> link = temp ;
	rear = rear -> link ;
}

// removes an element from the queue
int queue :: delq( )
{
	if ( front == NULL )
	{
		cout << "\nQueue is empty" ;
		return NULL ;
	}

	node *temp ;
	int item ;

	item = front  -> data ;
	temp = front ;
	front = front -> link ;
	delete temp ;
	return item ;
}

// deallocates memory
queue :: ~queue( )
{
	if ( front == NULL )
		return ;
	node *temp ;
	while ( front != NULL )
	{
		temp = front ;
		front = front -> link ;
		delete temp ;
	}
}

void main( )
{
	queue a ;

	a.addq ( 11 ) ;
	a.addq ( -8 ) ;
	a.addq ( 23 ) ;
	a.addq ( 19 ) ;
	a.addq ( 15 ) ;
	a.addq ( 16 ) ;
	a.addq ( 28 ) ;

	int i = a.delq( ) ;
	cout << "\nItem extracted: " << i ;

	i = a.delq( ) ;
	cout << "\nItem extracted: " << i ;

	i = a.delq( ) ;
	cout << "\nItem extracted: " << i ;
}
