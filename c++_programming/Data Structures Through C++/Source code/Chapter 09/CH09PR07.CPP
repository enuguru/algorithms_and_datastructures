// Program:ch09pr07
// Program to sort array using insertion sort

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
		void sort( ) ;
		void display( ) ;
} ;

// initalises data member
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

// sorts array using insertion sort method
void array :: sort( )
{
	int temp ;
	for ( int i = 1 ; i <= count - 1 ; i++ )
	{
		for ( int j = 0 ; j < i ; j++ )
		{
			if ( arr[j] > arr[i] )
			{
				temp = arr[j] ;
				arr[j] = arr[i] ;

				for ( int k = i ; k > j ; k-- )
					arr[k] = arr[k - 1] ;

				arr[k + 1] = temp ;
			}
		}
	}
}

// displays elements of array
void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "\t" ;
	cout << endl ;
}

void main( )
{
	array a ;

	a.add ( 25 ) ;
	a.add ( 17 ) ;
	a.add ( 31 ) ;
	a.add ( 13 ) ;
	a.add ( 2 ) ;

	cout << "\nInsertion sort.\n" ;
	cout << "\nArray before sorting:" << endl ;
	a.display( ) ;

	a.sort( ) ;
	cout << "\nArray after insertion sorting:" << endl ;
	a.display( ) ;
}
