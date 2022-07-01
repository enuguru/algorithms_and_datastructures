// Program to sorting dates using bubble sort. 

#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 5 ;
class mydate 
{

	private :

		char dates[MAX][12] ; 
		long int arr[MAX], t ;
		int d, m ;
		long int y ;

	public :

		void getdates( ) ;
		int isvalid ( ) ;
		int isleap ( long int y ) ;
		long int getnum ( char *date ) ;
		void sortdates( ) ;
		void display( ) ;
} ;

// accepts dates entered by the user
void mydate :: getdates( )
{
	cout << "Enter any five dates (dd\\mm\\yyyy) :-\n" ;
	for ( int i = 0 ; i < MAX ; i++ )
	{
		cout << i + 1 ;
		cin >> dates[i] ;

		// converts date in string to equivalent integer values.
		arr[i] = getnum ( dates[i] ) ;

		// checks for valid date.
		int valid = isvalid( ) ;

		if ( !valid )
		{
			cout << "This date does not exists. " ;
			cout << "Enter any other date.\n" ;
			i-- ;
		}
	}
}

// checks whether given date is valid or not.
int mydate :: isvalid ( )
{
	if ( y <= 0 || m <= 0 || d <= 0 || m > 12 || y > 16384 ||
		 ( m == 2 && !isleap ( y ) && d > 28 ) ||
		 ( m == 2 && isleap ( y ) && d > 29 ) ||
		 ( ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10
		  || m == 12 ) && d > 31 ) || ( ( m == 4 || m == 6 || m == 9 ||
			 m == 11 ) && d > 30 ) )
		return 0 ;
	else
		return 1 ;
}

// checks if given year is a leap year
int mydate :: isleap ( long int y )
{
	return ( y % 4 == 0 ) ^ ( y % 100 == 0 ) ^ ( y % 400 == 0 ) ;
}

// converts dates in string into equivalent integer values
long int mydate :: getnum ( char *date )
{
	char *p, str[15] ;
	long int num = 0 ;

	strcpy ( str, date ) ;

	d = m = y = 0 ;
	p = strtok ( str, "\\" ) ;
	if ( p != NULL )
		d = num = atoi ( p )  ;

	p = strtok ( NULL, "\\");
	if ( p != NULL )
		m = atoi ( p ) ;
	num += m * 32 ;

	p = strtok ( NULL, "\\");
	if ( p != NULL )
		y = atol ( p ) ;
	num += y * 512L ;

	return num ;
}

// sorts dates using Bubble sort method
void mydate :: sortdates( )
{
	char temp[12] ;
	for ( int i = 0 ; i <= MAX - 2 ; i++ )
	{
		for ( int j = 0 ; j <= ( MAX - 2 ) - i ; j++ )
		{
			if ( arr[j] > arr[j + 1] )
			{
				t = arr[j] ;
				arr[j] = arr[j + 1] ;
				arr[j + 1 ] = t ;

				strcpy ( temp, dates[j] ) ;
				strcpy ( dates[j], dates[j + 1] ) ;
				strcpy ( dates[j + 1], temp ) ;
			}
		}
	}
}

// displays dates
void mydate :: display( )
{
	cout << "Dates in sorted order are :- \n" ;
	for ( int i = 0 ; i < MAX ; i++ )
		cout << "\n" << dates[i] ;
}


void main( )
{
	mydate d ;
	d.getdates( ) ;
	d.sortdates( ) ;
	d.display( ) ;
}

