// Program: Ch03pr03
// Program with the use of array of pointers to strings

#include <iostream.h>
#include <string.h>

const int MAX = 6 ;

class string
{
	private :

		char *names[MAX] ;
		int count ;

	public :

		string( ) ;
		int add ( char *s ) ;
		void swap ( int i, int j ) ;
		void show( ) ;
} ;

// initialises the data
string :: string( )
{
	count = 0 ;
}

// adds given string
int string :: add ( char *s )
{
	if ( count < MAX )
	{
		names[count] = s ;
		count++ ;
		return 1 ;
	}
	else
		return 0 ;
}

// swaps the names at given two positions
void string :: swap ( int i, int j )
{
	char *temp ;
	temp = names[i] ;
	names[i] = names[j] ;
	names[j] = temp ;
}

// displays the elements
void string :: show( )
{
	cout << endl ;
	for ( int i = 0 ; i < count ; i++ )
		cout << names[i] << "  " ;
	cout << endl ;
}

void main( )
{
	string s ;
    int flag ;

	flag = s.add ( "akshay" ) ;
	if ( flag == 0 )
		cout << "Unable to add string" ;

	flag = s.add ( "parag" ) ;
	if ( flag == 0 )
		cout << "Unable to add string" ;

	flag = s.add ( "raman" ) ;
	if ( flag == 0 )
		cout << "Unable to add string" ;

	flag = s.add ( "srinivas" ) ;
	if ( flag == 0 )
		cout << "Unable to add string" ;

	flag = s.add ( "gopal" ) ;
	if ( flag == 0 )
		cout << "Unable to add string" ;

    flag = s.add ( "rajesh" ) ;
	if ( flag == 0 )
		cout << "Unable to add string" ;

	cout << "\nNames before swapping: " ;
	s.show( ) ;

	s.swap( 2, 3 ) ;
	cout << "\nNames after swapping: " ;
	s.show( ) ;
}
