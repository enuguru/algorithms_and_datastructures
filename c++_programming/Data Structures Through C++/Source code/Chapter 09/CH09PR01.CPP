// Program: ch09pr01
// Program that searches for a given number using 
// linear search method in a unsorted array

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
		int search ( int item ) ;
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

// finds for given element in an array
int array :: search ( int num )
{
	for ( int i = 0 ; i < count ; i++ )
	{
		if ( arr[i] == num )
			break ;
	}

	if ( i == count )
		return -1 ;
	else
		return i ;
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

	int num ;
	cout << "\nEnter number to search: "  ;
	cin >> num ;

	int i = a.search ( num ) ;

	if ( i == -1 )
		cout << "\nNumber is not present in the array." ;
	else
		cout << "\nThe number is at position " << i << " in the array." ;
}
