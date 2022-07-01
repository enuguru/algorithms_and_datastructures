// Program Ch03pr02
// Program to manage a 2-D array

#include <iostream.h>
#include <string.h>

const int MAX1 = 6 ;
const int MAX2 = 10 ;

class string
{
	private :

		char masterlist[MAX1][MAX2] ;
		int count ;

	public :

		string( ) ;
		int add ( char *s ) ;
		int find ( char *s ) ;

} ;

// initialises the data
string :: string( )
{
    count = 0 ;
}

int string :: add ( char *s )
{
   if ( count < MAX1 )
   {
		if ( strlen ( s ) < MAX2 )
		{
			strcpy ( &masterlist[count][0], s ) ;
			count++ ;
			return 1 ;
		}
   }

   return 0 ;
}

// finds the given string
int string :: find ( char *s )
{
	int flag = 0 ;

	for ( int i = 0 ; i < count ; i++ )
	{
		if ( strcmp ( &masterlist[i][0], s ) == 0 )
		{
			flag = 1 ;
			break ;
		}
	}

	return flag ;
}

void main( )
{
	string s1 ;
    int flag ;

	flag = s1.add ( "akshay" ) ;
    if ( flag == 0 )
    	cout << "\nUnable to add string" ;

	s1.add ( "parag" ) ;
    if ( flag == 0 )
    	cout << "\nUnable to add string" ;

    s1.add ( "raman" ) ;
    if ( flag == 0 )
    	cout << "\nUnable to add string" ;

    s1.add ( "srinivas" ) ;
    if ( flag == 0 )
    	cout << "\nUnable to add string" ;

    s1.add ( "gopal" ) ;
    if ( flag == 0 )
    	cout << "\nUnable to add string" ;

    s1.add ( "rajesh" ) ;
    if ( flag == 0 )
    	cout << "\nUnable to add string" ;

	char yourname[MAX2] ;
	cout << "Enter your name: " ;
	cin >> yourname ;
	int f = s1.find ( yourname ) ;
	if ( f == 1 )
		cout << "Welcome, you can enter the palace" << endl ;
	else
		cout << "Sorry, you are a trespasser"  ;
}

