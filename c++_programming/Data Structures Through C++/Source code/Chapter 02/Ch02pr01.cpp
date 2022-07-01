// Program Ch02pr01
// Program to implement an array.

#include <iostream.h>

const int MAX = 5 ;

class array
{
	private :

		int arr[MAX] ;

	public :

		void insert ( int pos, int num ) ;
		void del ( int pos ) ;
		void reverse( ) ;
		void display( ) ;
		void search ( int num ) ;
} ;

// inserts an element num at given position pos
void array :: insert ( int pos, int num )
{
	// shift elements to right
	for ( int i = MAX - 1 ; i >= pos ; i-- )
		arr[i] = arr[i - 1] ;
	arr[i] = num ;
}

// deletes an element from the given position pos
void array :: del ( int pos )
{
	// skip to the desired position
	for ( int i = pos ; i < MAX ; i++ )
		arr[i - 1] = arr[i] ;
	arr[i - 1] = 0 ;
}

// reverses the entire array
void array :: reverse( )
{
	for ( int i = 0 ; i < MAX / 2 ; i++ )
	{
		int temp = arr[i] ;
		arr[i] = arr[MAX - 1 - i] ;
		arr[MAX - 1 - i] = temp ;
	}
}

// searches array for a given element num
void array :: search ( int num )
{
	// Traverse the array
	for ( int i = 0 ; i < MAX ; i++ )
	{
		if ( arr[i] == num )
		{
			cout << "\n\nThe element " << num << " is present at "<< ( i + 1 ) << "th position" ;
			return ;
		}
	}

	if ( i == MAX )
		cout << "\n\nThe element " << num << " is not present in the array" ;
}

// displays the contents of a array
void array :: display( )
{
	cout<< endl ;
	// traverse the entire array
	for ( int i = 0 ; i < MAX ; i++ )
		cout << "  " << arr[i] ;
}

void main( )
{
	array a ;

	a.insert ( 1,11 ) ;
	a.insert ( 2,12 ) ;
	a.insert ( 3,13 ) ;
	a.insert ( 4,14 ) ;
	a.insert ( 5,15 ) ;

	cout << "\nElements of Array: " ;
	a.display( ) ;

	a.del ( 5 ) ;
   	a.del ( 2 ) ;
	cout << "\n\nAfter deletion: " ;
	a.display( ) ;

	a.insert ( 2, 222 ) ;
	a.insert ( 5, 555 ) ;
	cout << "\n\nAfter insertion: " ;
	a.display( ) ;

	a.reverse( ) ;
	cout << "\n\nAfter reversing: " ;
	a.display( ) ;

	a.search ( 222 ) ;
	a.search ( 666 ) ;
}