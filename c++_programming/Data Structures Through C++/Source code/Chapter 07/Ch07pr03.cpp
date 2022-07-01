// Program Ch07pr03
// Program that implements circular queue as an array

#include <iostream.h>

const int MAX = 10 ;

class queue
{
	private :

		int arr[MAX] ;
		int front, rear ;

	public :

		queue( ) ;
		void addq ( int item ) ;
		int delq( ) ;
		void display( ) ;
} ;

// initialises data member
queue :: queue( )
{
	front = rear = -1 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[i] = 0 ;
}

// adds an element to the queue
void queue :: addq ( int item )
{
	if ( ( rear == MAX - 1 && front == 0 ) || (  rear + 1 == front ) )
	{
		cout << "\nQueue is full" ;
		return ;
	}

	if ( rear == MAX - 1 )
		rear = 0 ;
	else
		rear++ ;

	arr[rear] = item ;

	if ( front == -1 )
		front = 0 ;
}

// removes an element from the queue
int queue :: delq( )
{
	int data ;

	if ( front == -1 )
	{
		cout << "\nQueue is empty" ;
		return NULL ;
	}

	data = arr[front] ;
	arr[front] = 0 ;

	if ( front == rear )
	{
		front = -1 ;
		rear = -1 ;
	}
	else
	{
		if ( front == MAX - 1 )
			front = 0 ;
		else
			front++ ;
	}
	return data ;
}

// displays element in a queue
void queue :: display( )
{
	cout << endl ;
	for ( int i = 0 ; i < MAX ; i++ )
		cout << arr[i] << "  " ;
	cout << endl ;
}

void main( )
{
	queue a ;

	a.addq ( 14 ) ;
	a.addq ( 22 ) ;
	a.addq ( 13 ) ;
	a.addq ( -6 ) ;
	a.addq ( 25 ) ;

	cout << "\nElements in the circular queue: " ;
	a.display( ) ;

	int i = a.delq( ) ;
	cout << "Item deleted: " << i ;

	i = a.delq( ) ;
	cout << "\nItem deleted: " << i ;

	cout << "\nElements in the circular queue after deletion: " ;
	a.display( ) ;

	a.addq ( 21 ) ;
	a.addq ( 17 ) ;
	a.addq ( 18 ) ;
	a.addq ( 9 ) ;
	a.addq ( 20 ) ;

	cout << "Elements in the circular queue after addition: " ;
	a.display( ) ;

	a.addq ( 32 ) ;

	cout << "Elements in the circular queue after addition: " ;
	a.display( ) ;
}
