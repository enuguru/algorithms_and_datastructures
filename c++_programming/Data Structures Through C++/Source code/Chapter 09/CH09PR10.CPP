// Program ch09pr10
// Program that sorts an array using merge sort

#include <iostream.h>

const int MAX = 5 ;

class array
{

	private :

		int *arr ;
		int size ;
		int count ;

	public :

		array( ) ;
		array ( int sz ) ;
		void add ( int num ) ;
		void display( ) ;
		static void sort ( int *a, int sz ) ;
		void merge ( array &a, array &b ) ;
		~array( ) ;
} ;

// initializes data member
array :: array( )
{
	count = size = 0 ;
	arr = NULL ;
}

// initialises data member
array :: array( int sz )
{
	count = 0 ;
	size = sz ;
	arr = new int[sz] ;
}

// adds a new element to the array
void array :: add ( int num )
{
	if ( count < size )
	{
		arr[count] = num ;
		count++ ;
	}
	else
		cout << "\nArray is full" << endl ;
}

// displays elements in an array
void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "\t" ;
	cout << endl ;
}

// merges two arrays
void array :: merge ( array &a, array &b )
{
	sort ( a.arr, a.size ) ;
	sort ( b.arr, b.size ) ;

	size = a.count + b.count ;
	arr = new int[size] ;

	int i, j, k ;
	for ( i = j = k = 0 ; j < a.count || k < b.count ; )
	{
		if ( a.arr[j] <= b.arr[k] )
			arr[i++] = a.arr[j++] ;
		else
			arr[i++] = b.arr[k++] ;
		count++ ;

		if ( j == a.count || k == b.count )
			break ;
	}

	for ( ; j < a.count ; )
	{
		arr[i++] = a.arr[j++] ;
		count++ ;
	}

	for ( ; k < b.count ; )
	{
		arr[i++] = b.arr[k++] ;
		count++ ;
	}
}

// sorts an array
void array :: sort ( int *a, int sz )
{
	int temp ;
	for ( int i = 0 ; i <= sz - 2 ; i++ )
	{
		for ( int j = i + 1 ; j <= sz - 1 ; j++ )
		{
			if ( a[i] > a[j] )
			{
				temp = a[i] ;
				a[i] = a[j] ;
				a[j] = temp ;
			}
		}
	}
}

// deallocates memory
array :: ~array( )
{
	delete arr ;
}

void main( )
{
	array a ( MAX ) ;

	a.add ( 11 ) ;
	a.add ( 2 ) ;
	a.add ( 9 ) ;
	a.add ( 13 ) ;
	a.add ( 57 ) ;

	cout << "\nMerge sort.\n" ;
	cout << "\nFirst array: " << endl ;
	a.display( ) ;

	array b ( MAX ) ;

	b.add ( 25 ) ;
	b.add ( 17 ) ;
	b.add ( 1 ) ;
	b.add ( 90 ) ;
	b.add ( 3 ) ;


	cout << "\nSecond array: " << endl ;
	b.display( ) ;

	array c ;
	c.merge ( a, b ) ;

	cout << "\nArray after sorting: " << endl ;
	c.display( ) ;
}