// Extra programs
// Input-restricted deque program using array

#include <iostream.h>
#include <alloc.h>

const int MAX = 10 ;

class dqueue
{
	private :

		int arr[ MAX ] ;
		int front, rear ;

	public :

		dqueue( ) ;
		void addqatend ( int item ) ;
		int delqatbeg( ) ;
		int delqatend( ) ;
		void display( ) ;
		int count( ) ;
} ;

dqueue :: dqueue( )
{
	front = rear = -1 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[ i ] = 0 ;
}

void dqueue :: addqatend ( int item )
{
	if ( front == 0 && rear == MAX )
	{
	   cout << endl << "Queue is full" << endl ;
	   return ;
	}

	if ( rear == -1 && front == -1 )
	{
		rear = front = 0 ;
		arr[ rear ] = item ;
		rear++ ;
		return ;
	}

	if ( rear == MAX )
	{
		int k = front - 1 ;
		for ( int i = front - 1 ; i < rear ; i++ )
		{
			k = i ;
			if ( k == MAX - 1 )
				arr[ k ] = 0 ;
			else
				arr[ k ] = arr[ i + 1 ] ;
		}
		rear-- ;
		front-- ;
	}
	arr[ rear ] = item ;
	rear++ ;
}

int dqueue :: delqatbeg( )
{
	if ( front == -1 && rear == -1 )
	{
		cout << endl << "Queue is empty" << endl ;
		return 0 ;
	}
	int item = arr[ front ] ;
	arr[ front ] = 0 ;
	front++ ;
	if ( front == MAX )
		front = -1 ;
	return item ;
}

int dqueue :: delqatend( )
{
	if ( front == -1 && rear == -1 )
	{
		cout << endl << "Queue is empty" << endl ;
		return 0 ;
	}

	rear-- ;
	int item = arr[ rear ] ;
	arr[ rear ] = 0 ;
	if ( rear == 0 )
		rear = -1 ;
	return item ;
}

void dqueue :: display( )
{
	cout << endl << " front -> ";
	for ( int i = 0 ; i < MAX ; i++ )
		cout << "  " << arr[ i ] ;
	cout << " <- rear" ;
}

int dqueue :: count( )
{
	int c = 0 ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		if ( arr[ i ] != 0 )
			c++ ;
	}
	return c ;
}

void main( )
{
	dqueue a ;

	a.addqatend ( 11 ) ;
	a.addqatend ( 12 ) ;
	a.addqatend ( 13 ) ;
	a.addqatend ( 14 ) ;
	a.addqatend ( 15 ) ;
	a.addqatend ( 16 ) ;
	a.addqatend ( 17 ) ;
	a.addqatend ( 18 ) ;
	a.addqatend ( 19 ) ;
	a.addqatend ( 20 ) ;

	a.display( ) ;

	int n = a.count( ) ;
	cout << endl << "Total elements " << n ;

	int i = a.delqatbeg( ) ;
	cout << "\nItem extracted = " << i ;

	i = a.delqatbeg( ) ;
	cout << "\nItem extracted = " << i ;

	i = a.delqatend( ) ;
	cout << "\nItem extracted = " << i ;

	i =	 a.delqatend( ) ;
	cout << "\nItem extracted = " << i ;

	n = a.count( ) ;
	cout << endl << "Elements Left " << n ;
	a.display( ) ;

	a.addqatend ( 19 ) ;
	a.addqatend ( 20 ) ;
	a.addqatend ( 21 ) ;
	a.addqatend ( 22 ) ;
	a.addqatend ( 23 ) ;
	a.addqatend ( 24 ) ;
	a.display( ) ;
}


