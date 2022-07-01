// Program ch09pr06
// Program to sort array using quick sort

#include <iostream.h>

const int MAX = 10 ;

class array
{
	private :

		int arr[MAX] ;
		int count ;

	public :

		array( ) ;
		void add ( int item ) ;
		int getcount( ) ;
		static int split ( int *, int, int ) ;
		void quiksort ( int lower, int upper ) ;
		void display( ) ;
} ;

// initialises data member
array :: array( )
{
	count = 0 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[i] = 0 ;
}

// adds a new element to the array
void array :: add ( int item )
{
	if ( count < MAX )
	{
		arr[count] = item ;
		count++ ;
	}
	else
		cout << "\nArray is full" << endl ;
}

// returns total number of elements
int array :: getcount( )
{
	return count ;
}

// calls split to arrange array
void array :: quiksort ( int lower, int upper )
{
	if ( upper > lower )
	{
		int i = split ( arr, lower, upper ) ;
		quiksort ( lower, i - 1 ) ;
		quiksort ( i + 1, upper ) ;
	}
}

// sorts array using quick sort
int array :: split ( int *a, int lower, int upper )
{
	int i, p, q, t ;

	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;

	while ( q >= p )
	{
		while ( a[p] < i )
			p++ ;

		while ( a[q] > i )
			q-- ;

		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}

	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;

	return q ;
}

// displays elements of array
void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "  " ;
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
	a.add ( 3 ) ;

	cout << "\nQuik sort.\n" ;
	cout << "\nArray before sorting:" << endl ;
	a.display( ) ;

	int c = a.getcount( ) ;

	a.quiksort ( 0, c - 1 ) ;
	cout << "\nArray after quick sorting:" << endl ;
	a.display( ) ;
}