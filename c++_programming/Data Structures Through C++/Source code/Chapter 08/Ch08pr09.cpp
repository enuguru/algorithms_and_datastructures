// Program: ch08pr10
// Program to maintain a heap

#include <iostream.h>

const int MAX = 20 ;

class heap
{
	private :

		int arr[MAX] ;
		int count ;

	public :

		heap( ) ;
		void insert ( int num ) ;
		void makeheap( ) ;
		int add ( int val ) ;
		void display( ) ;
		void restoreup ( int pos ) ;
		void restoredown ( int pos ) ;
		int replace ( int pos ) ;
		int del( ) ;
} ;

// initialises data member
heap :: heap( )
{
	for ( int i = 0 ; i < MAX ; i++ )
		arr[i] = 0 ;
	count = 0 ;
}


// initialises array
void heap :: insert ( int num )
{
	if ( count < MAX )
	{
		arr[count] = num ;
		count++ ;
	}
	else
		cout << "\nArray is full.\n" ;
}

// creates heap from given data
void heap :: makeheap( )
{
	count-- ;
	for ( int i = count / 2 ; i >= 1 ; i-- )
		restoredown( i ) ;
}

// adds an element to the heap
int heap :: add ( int val )
{
	if ( count < MAX )
	{
		count++ ;
		arr[count] = val ;
		restoreup ( count ) ;
		return 1 ;
	}
	else
		return 0 ;
}

// displays element in heap
void heap :: display( )
{
	for ( int i = 1 ; i <= count ; i++ )
		cout << arr[i] << "\t" ;
	cout << endl ;
}

// rearranges heap
void heap :: restoreup ( int pos )
{
	int val = arr[pos] ;

	while ( arr[pos / 2] <= val )
	{
		arr[pos] = arr[pos / 2] ;
		pos = pos / 2 ;
	}
	arr[pos] = val ;
}

// rearranges heap
void heap :: restoredown ( int pos )
{
	int val = arr[pos] ;

	int i ;
	while ( pos <= count/2 )
	{
		i = 2 * pos ;
		if ( ( i < count ) && ( arr[i] < arr[i + 1] ) )
			i++ ;
		if ( val >= arr[i] )
			break ;
		arr [pos] = arr[i] ;
		pos = i ;
	}
	arr[pos] = val ;
}

// replaces an element at given position
int heap :: replace( int pos )
{
	int r = arr[1] ;
	arr[1] = pos ;
	for ( pos = count / 2 ; pos >= 1 ; pos-- )
		restoredown ( pos ) ;
	return r ;
}

// deletes an element from given position
int heap :: del( )
{
	int val ;
	val = arr[1] ;
	arr[1] = arr[count] ;
	count-- ;
	restoredown( 1 ) ;
	return val ;
}

void main( )
{
	int ar[ ] = { 1000, 7, 10, 25, 17, 23, 27,
				  16, 19, 37, 42, 4, 33, 1, 5, 11 } ;

	heap hp ;

	int sz = sizeof ( ar ) / sizeof ( int ) ;

	for ( int i = 0 ; i < sz ; i++ )
		hp.insert ( ar[i] ) ;

	hp.makeheap( ) ;

	cout << "Heap:" << endl ;
	hp.display( ) ;

	i = 24 ;
	int result = hp.add ( i ) ;
	if ( result == 0 )
		cout << "cannot add element" << endl ;
	else
	{
		cout << "\nElement added: " << i << endl ;
		cout << "\nHeap after addition of an element:" << endl;
		hp.display( ) ;
	}

	i = hp.replace ( 2 ) ;
	cout << "\nElement replaced: " << i << endl ;
	cout << "\nHeap after replacement of an element:" << endl ;
	hp.display( ) ;

	i = hp.del( ) ;
	cout << "\nElement deleted: " << i << endl ;
	cout << "\nHeap after deletion of an element:" << endl ;
	hp.display( ) ;
}

