// Program Ch03pr04
// Program to manage array of pointers to strings

#include <iostream.h>
#include <string.h>

const int MAX1 = 6 ;
const int MAX2 = 10 ;

class string
{
	private :

		char *names[MAX1] ;
		int count ;

	public :

		string( ) ;
		int add( ) ;
		void show( ) ;
	        ~string( ) ;
} ;

// allocates the memory
string :: string( )
{
    count = 0 ;
}

// accepts strings
int string :: add( )
{
	if ( count < MAX1 )
	{
		cout << "\nEnter string: " << endl ;
		names[count] = new char[MAX2] ;
		cin >> names[count] ;
		count++ ;
	}

	return 0 ;
}

// displays the strings
void string :: show( )
{
	cout << "\nThe strings are: " << endl ;
	for ( int i = 0 ; i < count ; i++ )
		cout << names[i] << "  " ;
	cout << endl ;
}

// deallocates memory
string :: ~string( )
{
	for ( int i = 0 ; i < count ; i++ )
    	delete names[i] ;
}

void main( )
{
    string s ;

    s.add( ) ;
    s.add( ) ;
    s.add( ) ;
    s.add( ) ;

    s.show( ) ;
}
