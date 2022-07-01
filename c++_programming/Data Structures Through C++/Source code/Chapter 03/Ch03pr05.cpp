// Program Example Ch03pr05
// Pattern matching program using Brute Force Algorithm

#include <iostream.h>
#include <string.h>

const int MAX = 20 ;

class string
{
	private :

		char str[MAX] ;

	public :

		string( ) ;
		string ( char *s ) ;
		static int xstrsearch ( string &s1, string &s2 ) ;
		void show( ) ;
} ;

// initializes data
string :: string( )
{
}

// initializes data
string :: string ( char *s )
{
	strcpy ( str, s ) ;
}

// searches for the given pattern s2 into the string s1
int string :: xstrsearch ( string &s1, string &s2 )
{
	char *src = s1.str ;
	char *trg = s2.str ;

	int l1 = strlen ( src ) ;
	int l2 = strlen ( trg ) ;

   	for ( int i = 0, j, k ; i <= l1 - l2 ; i++ )
	{
		j = 0 ;
		k = i ;
		while ( ( src[k] == trg[j] ) && ( j < l2 ) )
		{
			k++ ;
			j++ ;
		}
		if ( j == l2 )
			return i ;
	}
	return -1 ;
}

// displays the string
void string :: show( )
{
	cout << str << endl ;
}

void main( )
{
    // create object and display string
	string s1 ( "NagpurKicit" ) ;
	s1.show( ) ;
	string s2 ( "Kicit" ) ;
	s2.show( ) ;

    // search if s2 is present in s1
	int pos = string :: xstrsearch ( s1, s2 ) ;
	cout << "\nThe pattern string is found at position: " << pos << endl ;
}