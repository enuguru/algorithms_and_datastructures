// Program: ch09pr09
// Program that sorts an array using Heap Sort method

#include <iostream.h>

const int MAX = 10 ;

class array
{
	private :

		int arr[MAX] ;
		int count ;

	public :

		array( ) ;
 		void add ( int num ) ;
		void makeheap( ) ;
		void heapsort( ) ;
		void display( ) ;
} ;

// initialises data member
array :: array( )
{
	count = 0 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[MAX] = 0 ;
}

// adds element to an array
void array :: add ( int num )
{
	if ( count < MAX )
	{
		arr[count] = num ;
		count++ ;
	}
	else
		cout << "\nArray is full" << endl ;
}

// creates heap from the tree
void array :: makeheap( )
{
	for ( int i = 1 ; i < count ; i++ )
	{
		int val = arr[i] ;
		int s = i ;
		int f = ( s - 1 ) / 2 ;
		while ( s > 0 && arr[f] < val )
		{
			arr[s] = arr[f] ;
			s = f ;
			f = ( s - 1 ) / 2 ;
		}
		arr[s] = val ;
	}
}

// sorts heap
void array :: heapsort( )
{
	for ( int i = count - 1 ; i > 0 ; i-- )
	{
		int ivalue = arr[i] ;
		arr[i] = arr[0] ;
		int f = 0 ;

		int s ;
		if ( i == 1 )
			s = -1 ;
		else
			s = 1 ;

		if ( i > 2 && arr[2] > arr[1] )
			s = 2 ;

		while ( s >= 0 && ivalue < arr[s] )
		{
			arr[f] = arr[s] ;
			f = s ;
			s = 2 * f + 1 ;

			if ( s + 1 <= i - 1 && arr[s] < arr[s + 1] )
				s++ ;
			if ( s > i - 1 )
				s = -1 ;
		}
		arr[f] = ivalue ;
	}
}

// displays contents
void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
    		cout << arr[i] << "\t" ;
	cout << endl ;
}

void main( )
{
	array a ;

	a.add ( 11 ) ;
	a.add ( 2 ) ;
	a.add ( 9 ) ;
	a.add ( 13 ) ;
	a.add ( 57 ) ;
	a.add ( 25 ) ;
	a.add ( 17 ) ;
	a.add ( 1 ) ;
	a.add ( 90 ) ;
	a.add ( 3  ) ;

	a.makeheap( ) ;

	cout << "\nHeap Sort.\n" ;
	cout << "\nBefore Sorting:\n"  ;
	a.display( ) ;

	a.heapsort( ) ;

	cout << "\nAfter Sorting:\n" ;
	a.display( ) ;
}

