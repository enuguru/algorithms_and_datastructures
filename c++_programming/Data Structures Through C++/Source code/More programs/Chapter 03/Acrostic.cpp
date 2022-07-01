// program to check if given strings form an acrostic

#include <string.h>
#include <iostream.h>

const int MAX1 = 5 ;
const int MAX2 = 6 ;

class string
{

	private :

		char str[MAX1][MAX2] ;
		int count ;

	public :

		string( ) ;
		void add ( char *s ) ;
		int check( ) ;
		void display( ) ;
} ;

// initialises data member
string :: string( )
{
	for ( int i = 0 ; i < MAX1 ; i++ )
		strcpy ( str[i], "" ) ;
	count = 0 ;
}

// adds a string to the array
void string :: add ( char *s )
{
	if ( count < MAX1 )
	{
		strcpy ( str[count], s ) ;
		count++ ;
	}
	else
		cout << "cannot add string\n" ;
}

// checks if forms an acrostic
int string :: check( )
{
	char *s = str[0] ;
	int j = ( MAX1 * MAX2 ) - 2 ;

	for ( int i = 0 ; i < 15 ; i++, j-- )
	{
		if ( * ( s + i ) == * ( s + j ) )
			continue ;
		else
			break ;
	}

	if ( i == 15 )
		return 1 ;
	else
		return 0 ;
}

// displays strings
void string :: display( )
{
	for ( int i = 0 ; i < MAX1 ; i++ )
		cout << str[i] << endl ;
}

void main( )
{
	string s ;
	
	s.add ( "ROTAS" ) ;
	s.add ( "OPERA" ) ;
	s.add ( "TENET" ) ;
	s.add ( "AREPO" ) ;
	s.add ( "SATOR" ) ;

	cout << "\nThe strings are:\n" ;
	s.display( ) ;

	int i = s.check( ) ;

	if ( i == 1 )
		cout << "The given string forms an acrostic\n" ;
	else
		cout << "The given string do not form an acrostic\n" ;
}