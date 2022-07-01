// Program: ch09pr05
// Program to sort array using Selection sort

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

// sorts array using selection sort method
void array :: sort( )
{
	int temp ;
	for ( int i = 0 ; i <= count - 2 ; i++ )
	{
		for ( int j = i + 1 ; j <= count - 1 ; j++ )
		{
			if ( arr[i] > arr[j] )
			{
				temp = arr[i] ;
				arr[i] = arr[j] ;
				arr[j] = temp ;
			}
		}
	}
}

// displays elements in an array
void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "  " ;
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

	cout << "\nSelection sort.\n" ;
	cout << "\nArray before sorting:" << endl ;
	a.display( ) ;

	a.sort( ) ;
	cout << "\nArray after selection sorting:" << endl ;
	a.display( ) ;
}