#include <iostream.h>
#include <stdio.h>
#include <alloc.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 10 ;

class dque
{
	private :

		int queue[ MAX ] ;
		int stack[ MAX ] ;
		int front, rear, top ;

	public :

		dque( ) ;
		void addqatbeg ( int carno ) ;
		void addqatend ( int carno ) ;
		void delq ( int pos ) ;
		int count( ) ;
		int search ( int carno ) ;
		void display( ) ;
		void push ( int carno ) ;
		int pop( ) ;
} ;

dque :: dque( )
{
	front = rear = top = -1 ;
	for ( int i = 0 ; i < 10 ; i++ )
			queue[ i ] = stack[ i ] = 0 ;
}

void dque :: addqatbeg ( int carno )
{
	if ( front == 0 && rear == MAX - 1 )
	{
	   cout << endl << "No slot available to park car" << endl ;
	   return ;
	}

	if ( front == -1 && rear == -1 )
	{
		front = rear = 0 ;
		queue[ front ] = carno ;
		return ;
	}

	if ( rear != MAX - 1 )
	{
		int c = count( ) ;
		int k = rear + 1 ;
		for ( int i = 1 ; i <= c ; i++ )
		{
			queue[ k ] = queue[ k - 1 ] ;
			k-- ;
		}
		queue[ k ] = carno ;
		front = k ;
		rear++ ;
	}
	else
	{
		front-- ;
		queue[ front ] = carno ;
	}
}

void dque :: addqatend ( int carno )
{
	if ( front == 0 && rear == MAX - 1 )
	{
	   cout << endl << "No slot available to park car" << endl ;
	   return ;
	}

	if ( rear == -1 && front == -1 )
	{
		rear = front = 0 ;
		queue[ rear ] = carno ;
		return ;
	}

	if ( rear == MAX - 1 )
	{
		int k = front - 1 ;
		for ( int i = front - 1 ; i < rear ; i++ )
		{
			k = i ;
			if ( k == MAX - 1 )
				queue[ k ] = 0 ;
			else
				queue[ k ] = queue[ i + 1 ] ;
		}
		rear-- ;
		front-- ;
	}
	rear++ ;
	queue[ rear ] = carno ;
}

void dque :: delq ( int pos )
{
	int item ;
	for ( int i = rear i >= front ; i-- )
	{
		if ( i == pos )
		{
			queue[ i ] = 0 ;
			continue ;
		}
		item = queue[ i ] ;
		push ( item ) ;
		queue[ i ] = 0 ;
	}
	rear-- ;

	for ( i = front ; i <= rear ; i++ )
	{
		item = pop( ) ;
		queue[ i ] = item ;
	}
}

void dque :: display( )
{
	cout << endl << "slot" ;
	int c = count( ) ;
	for ( int i = 0 ; i < c ; i++ )
		cout << "      " << i ;
	cout << endl << "         " ;
	for ( i = 0 ; i < MAX ; i++ )
	{
		if ( queue[ i ] != 0 )
			cout <<  queue[ i ] << "     " ;
	}
	cout << endl ;
}

int dque :: count ( )
{
	int c = 0 ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		if ( queue[ i ] != 0 )
			c++ ;
	}
	return c ;
}

int dque :: search ( int carno )
{
	int pos = -1 ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		if ( queue[ i ] == carno )
		{
			pos = i ;
			break ;
		}
	}
	return pos ;
}

void dque :: push ( int item )
{
	if ( top == MAX - 1 )
		top = -1 ;
	top++ ;
	stack[ top ] = item ;
}

int dque :: pop( )
{
	int item = stack[ top ] ;
	top-- ;
	return item ;
}

void main( )
{
	char ad ;
	int s, min, carno ;
	dque q ;

	while ( 1 )
	{
		cout << endl ;
		cout << "Arrival/Departure/Display/Quit? (A/D/S/Q) : " ;
		cin >> ad ;
		ad = toupper ( ad ) ;

		if ( ad == 'Q' )
			exit ( 1 ) ;

		if ( ad != 'S' )
		{
			cout << "Enter license plate number : " ;
			cin >> carno ;
		}

		switch ( ad )
		{

			case 'A' :

					// arrival of car
					min = 10 ;
					s = q.count( ) ;
					if ( s == 10 )
						cout << endl << "No slot available to park car" << endl ;
					else
					{
						if ( s < min )
						min = s ;
						int no = rand( ) % 10 ;
						if ( no % 2 == 0 )
							q.addqatbeg ( carno ) ;
						else
							q.addqatend ( carno ) ;

						cout << "Car parked at slot " << s << endl ;
					 }
					 break ;

			case 'D' :

					// departure of car
					s = q.search ( carno ) ;
					if ( s != -1 )
					{
						cout << "car found at slot " << s << endl ;
						q.delq ( s ) ;
					}
					else
						cout << endl << "No such car parked yet" << endl ;
					break ;

			case 'S' :
					//display
					q.display( ) ;
					break ;

			case 'Q' :

					// quit program
					exit ( 1 ) ;
					break ;
		}
	}
}