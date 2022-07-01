// Program Ch07pr01
// Program that implements queue as an array

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
} ;

// initialises data members
queue :: queue( )
{
	front = -1 ;
	rear = -1 ;
}

// adds an element to the queue
void queue :: addq ( int item )
{
	if ( rear == MAX - 1 )
	{
		cout << "\nQueue is full" ;
		return ;
	}

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
		cout << "\nQueue is Empty" ;
		return NULL ;
	}

	data = arr[front] ;
	arr[front] = 0 ;
	if ( front == rear )
		 front = rear = -1 ;
	else
		 front++ ;

	return  data ;
}

void main( )
{
	queue a ;

	a.addq ( 23 ) ;
	a.addq ( 9 ) ;
	a.addq ( 11 ) ;
	a.addq ( -10 ) ;
	a.addq ( 25 ) ;
	a.addq ( 16 ) ;
	a.addq ( 17 ) ;
	a.addq ( 22 ) ;
	a.addq ( 19 ) ;
	a.addq ( 30 ) ;
	a.addq ( 32 ) ;

	int i = a.delq( ) ;
	cout << "\nItem deleted: " << i ;

	i = a.delq( ) ;
	cout << "\nItem deleted: " << i ;

	i = a.delq( ) ;
	cout << "\nItem deleted: " << i ;
}
