// Program Ch07pr04
// Program that implements deque uasin an array

#include <iostream.h>

const int MAX = 10 ;

class dque
{
	private :

		int arr[MAX] ;
		int front, rear ;

	public :

		dque( ) ;
		void addqatbeg ( int item ) ;
		void addqatend ( int item ) ;
		int delqatbeg( ) ;
		int delqatend( ) ;
		void display( ) ;
		int count( ) ;
} ;

// initialises data members
dque :: dque( )
{
	front = rear = -1 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[i] = 0 ;
}

// adds an element at the beginning of a deque
void dque::addqatbeg ( int item )
{
	if ( front == 0 && rear == MAX - 1 )
	{
		cout << "\nDeque is full" << endl ;
		return ;
	}

	if ( front == -1 )
	{
		front = rear = 0 ;
		arr[front] = item ;
		return ;
	}

	if ( rear != MAX - 1 )
	{
		int c = count( ) ;
		int k = rear + 1 ;
		for ( int i = 1 ; i <= c ; i++ )
		{
			arr[k] = arr[k - 1] ;
			k-- ;
		}
		arr[k] = item ;
		front = k ;
		rear++ ;
	}
	else
	{
		front-- ;
		arr[front] = item ;
	}
}

// adds an element at the end of a deque
void dque :: addqatend ( int item )
{
	if ( front == 0 && rear == MAX - 1 )
	{
		cout << "\nDeque is full" << endl ;
		return ;
	}

	if ( front == -1 )
	{
		rear = front = 0 ;
		arr[rear] = item ;
		return ;
	}

	if ( rear == MAX - 1 )
	{
		int k = front - 1 ;
		for ( int i = front - 1 ; i < rear ; i++ )
		{
			k = i ;
			if ( k == MAX - 1 )
				arr[k] = 0 ;
			else
				arr[k] = arr[i + 1] ;
		}
		rear-- ;
		front-- ;
	}
	rear++ ;
	arr[rear] = item ;
}

// removes an element from the front end of deque
int dque :: delqatbeg( )
{
	if ( front == -1 )
	{
		cout << "\nDeque is empty" << endl ;
		return 0 ;
	}

	int item = arr[front] ;
	arr[front] = 0 ;

	if ( front == rear )
		front = rear = -1 ;
	else
		front++ ;

	return item ;
}

// removes an element from the rear end of the deque
int dque :: delqatend( )
{
	if ( front == -1 )
	{
		cout << "\nDeque is empty" << endl ;
		return 0 ;
	}

	int item = arr[rear] ;
	arr[rear] = 0 ;
	rear-- ;
	if ( rear == -1 )
		front = -1 ;
	return item ;
}

// displays elements of a deque
void dque :: display( )
{
	cout << endl << "front->";
	for ( int i = 0 ; i < MAX ; i++ )
		cout << "  " << arr[i] ;
	cout << " <-rear" ;
}

// counts the total number of elements in deque
int dque :: count( )
{
	int c = 0 ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		if ( arr[i] != 0 )
			c++ ;
	}
	return c ;
}

void main( )
{
	dque a ;

	a.addqatend ( 17 ) ;
	a.addqatbeg ( 10 ) ;
	a.addqatend ( 8 ) ;
	a.addqatbeg ( -9 ) ;
	a.addqatend ( 13 ) ;
	a.addqatbeg ( 28 ) ;
	a.addqatend ( 14 ) ;
	a.addqatbeg ( 5 ) ;
	a.addqatend ( 25 ) ;
	a.addqatbeg ( 6 ) ;
	a.addqatend ( 21 ) ;
	a.addqatbeg ( 11 ) ;

	cout << "\nElements in a deque: " ;
	a.display( ) ;

	int n = a.count( ) ;
	cout << "\nTotal number of elements in deque: " << n ;

	int i = a.delqatbeg( ) ;
	cout << "\nItem extracted: " << i ;

	i = a.delqatbeg( ) ;
	cout << "\nItem extracted: " << i ;

	i = a.delqatbeg( ) ;
	cout << "\nItem extracted: " << i ;

	i = a.delqatbeg( ) ;
	cout << "\nItem extracted: " << i ;

	cout << "\nElements in a deque after deletion: " ;
	a.display( ) ;

	a.addqatend ( 16 ) ;
	a.addqatend ( 7 ) ;

	cout << "\nElements in a deque after addition: " ;
	a.display( ) ;

	i = a.delqatend( ) ;
	cout << "\nItem extracted: " << i ;

	i = a.delqatend( ) ;
	cout << "\nItem extracted: " << i ;

	cout << "\nElements in a deque after deletion: " ;
	a.display( ) ;

	n = a.count( ) ;
	cout << "\nTotal number of elements in deque: " << n ;
}
