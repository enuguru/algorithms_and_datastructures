// Extra Program
// output-restricted deque program using array

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
		void addqatbeg ( int item ) ;
		void addqatend ( int item ) ;
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

void dqueue :: addqatbeg ( int item )
{
	if ( front == 0 && rear == MAX )
	{
	   cout << endl << "Queue is full" << endl ;
	   return ;
	}

	if ( front == -1 && rear == -1 )
	{
		front = rear = 0 ;
		arr[ front ] = item ;
		return ;
	}

	if ( rear != MAX )
	{
		int c = count( ) ;
		int k = rear ;
		for ( int i = 1 ; i <= c ; i++ )
		{
			arr[ k ] = arr[ k - 1 ] ;
			k-- ;
		}
		arr[ k ] = item ;
		front = k ;
		rear++ ;
	}
	else
	{
		front-- ;
		arr[ front ] = item ;
	}
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
		int c = count( ) ;
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
	cout << " <- rear " ;
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
	a.addqatbeg ( 10 ) ;
	a.addqatend ( 12 ) ;
	a.addqatbeg ( 9 ) ;
	a.addqatend ( 13 ) ;
	a.addqatbeg ( 8 ) ;
	a.addqatend ( 14 ) ;
	a.addqatbeg ( 7 ) ;
	a.addqatend ( 15 ) ;
	a.addqatbeg ( 6 ) ;
	a.addqatend ( 16 ) ;
	a.addqatbeg ( 5 ) ;

	a.display( ) ;

	int n = a.count( ) ;
	cout << endl << "Total elements " << n ;

	int i = a.delqatend( ) ;
	cout << "\nItem extracted = " << i ;

	i = a.delqatend( ) ;
	cout << "\nItem extracted = " << i ;

	i = a.delqatend( ) ;
	cout << "\nItem extracted = " << i ;

	i =	 a.delqatend( ) ;
	cout << "\nItem extracted = " << i ;

	n = a.count( ) ;
	cout << endl << "Elements Left " << n ;
	a.display( ) ;

	a.addqatbeg ( 5 ) ;
	a.addqatbeg ( 4 ) ;
	a.addqatbeg ( 3 ) ;
	a.addqatbeg ( 2 ) ;
	a.display( ) ;
}


